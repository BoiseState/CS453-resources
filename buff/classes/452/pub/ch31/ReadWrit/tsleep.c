#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

extern void tsleep(int secs) {
  pthread_mutex_t mutex;
  pthread_cond_t cv;
  pthread_mutex_init(&mutex,0);
  pthread_cond_init(&cv,0);

  struct timespec t;
  clock_gettime(CLOCK_REALTIME,&t);
  t.tv_sec+=secs;
  pthread_mutex_lock(&mutex);
  pthread_cond_timedwait(&cv,&mutex,&t);
  pthread_mutex_unlock(&mutex);

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cv);
}

