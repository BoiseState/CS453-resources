#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

static int counter=0;
static const int max=5;		// min==-max

static sem_t mutex,decrable,incrable;

static void *count(void *a) {
  int chg=(long)a;		// -1 or +1
  sem_t *wait_sem=chg<0 ? &decrable : &incrable;
  sem_t *post_sem=chg<0 ? &incrable : &decrable;
  while (1) {
    sem_wait(wait_sem);
    sem_wait(&mutex);
    printf("%d\n",counter+=chg);
    sem_post(&mutex);
    sem_post(post_sem);
  }
  return 0;
}

int main() {
  sem_init(&mutex,0,1);		    // binary
  sem_init(&decrable,0,max);	// general
  sem_init(&incrable,0,max);	// general
  const int threads=10;
  pthread_t tids[threads];
  for (int i=0; i<threads; i++)
    pthread_create(&tids[i],0,count,
      (void *)(long)((i&1)<<1)-1);	// -1 or +1
  for (int i=0; i<threads; i++)
    pthread_join(tids[i],0);
  sem_destroy(&mutex);
  sem_destroy(&decrable);
  sem_destroy(&incrable);
  return 0;
}
