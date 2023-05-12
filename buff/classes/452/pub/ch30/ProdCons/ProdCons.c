#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "buffer.h"

static void produce(int *d) { *d=random()%100; /* mine a bitcoin */ }
static void consume(int *d) { printf("%d\n",*d); }

static void xput(int *d) { put(*d); }
static void xget(int *d) { *d=get(); }

typedef enum {Prod,Cons} Identity;

static pthread_mutex_t mutex;
static pthread_cond_t getable,putable;

static void *prod_cons(void *a) {
  Identity id=a ? Cons : Prod;
  void (*prod)(int *d)=id==Prod ? produce : 0;
  void (*cons)(int *d)=id==Prod ? 0 : consume;
  void (*xfer)(int *d)=id==Prod ? xput : xget;
  pthread_cond_t *wait_cv=id==Prod ? &putable : &getable;
  pthread_cond_t *sign_cv=id==Prod ? &getable : &putable;
  Busy busy=id==Prod ? full : empt;
  while (1) {
    int data;
    if (prod) prod(&data);
    pthread_mutex_lock(&mutex);
    while (busy())
      pthread_cond_wait(wait_cv,&mutex);
    xfer(&data);
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(sign_cv);
    if (cons) cons(&data);
  }
  return 0;
}

int main() {
  pthread_mutex_init(&mutex,0);
  pthread_cond_init(&getable,0);
  pthread_cond_init(&putable,0);
  const int threads=10;
  pthread_t tids[threads];
  for (int i=0; i<threads; i++)
    pthread_create(&tids[i],0,prod_cons,
        (void *)(long)(i&1));	// Identity
  for (int i=0; i<threads; i++)
    pthread_join(tids[i],0);
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&getable);
  pthread_cond_destroy(&putable);
  return 0;
}
