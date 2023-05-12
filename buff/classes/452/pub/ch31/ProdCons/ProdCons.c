#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#include "buffer.h"

static void produce(int *d) { *d=random()%100; /* mine a bitcoin */ }
static void consume(int *d) { printf("%d\n",*d); }

static void xput(int *d) { put(*d); }
static void xget(int *d) { *d=get(); }

typedef enum {Prod,Cons} Identity;

static sem_t mutex,putable,getable;

void *prod_cons(void *a) {
  Identity id=a ? Cons : Prod;
  void (*prod)(int *d)=id==Prod ? produce : 0;
  void (*cons)(int *d)=id==Prod ? 0 : consume;
  void (*xfer)(int *d)=id==Prod ? xput : xget;
  sem_t *wait_sem=id==Prod ? &putable : &getable;
  sem_t *post_sem=id==Prod ? &getable : &putable;
  while (1) {
    int data;
    if (prod) prod(&data);
    sem_wait(wait_sem);
    sem_wait(&mutex);
    xfer(&data);
    sem_post(&mutex);
    sem_post(post_sem);
    if (cons) cons(&data);
  }
  return 0;
}

int main() {
  sem_init(&mutex,0,1);		  // binary
  sem_init(&putable,0,max);	// general
  sem_init(&getable,0,0);	  // general
  const int threads=10;
  pthread_t tids[threads];
  for (int i=0; i<threads; i++)
    pthread_create(&tids[i],0,prod_cons,
      (void *)(long)(i&1));	// Identity
  for (int i=0; i<threads; i++)
    pthread_join(tids[i],0);
  sem_destroy(&mutex);
  sem_destroy(&getable);
  sem_destroy(&putable);
  return 0;
}
