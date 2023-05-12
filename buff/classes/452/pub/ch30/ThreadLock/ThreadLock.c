#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static int counter=0;
static const int max=5;		// min==-max

static pthread_mutex_t mutex;
static pthread_cond_t decrable,incrable;

static void *count(void *a) {
  int chg=(long)a;		// -1 or +1
  pthread_cond_t *wait_cv=chg<0 ? &decrable : &incrable;
  pthread_cond_t *sign_cv=chg<0 ? &incrable : &decrable;
  while (1) {
    pthread_mutex_lock(&mutex);
    while (counter*chg>=max)
      pthread_cond_wait(wait_cv,&mutex);
    printf("%d\n",counter+=chg);
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(sign_cv);
  }
  return 0;
}

int main() {
  pthread_mutex_init(&mutex,0);
  pthread_cond_init(&decrable,0);
  pthread_cond_init(&incrable,0);
  const int threads=10;
  pthread_t tids[threads];
  for (int i=0; i<threads; i++)
    pthread_create(&tids[i],0,count,
      (void *)(long)((i&1)<<1)-1);	// -1 or +1
  for (int i=0; i<threads; i++)
    pthread_join(tids[i],0);
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&decrable);
  pthread_cond_destroy(&incrable);
  return 0;
}
