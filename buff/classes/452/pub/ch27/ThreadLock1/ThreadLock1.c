#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static int counter=0;

static pthread_mutex_t lock;

static void *count(void *a) {
  while (counter<10) {
    pthread_mutex_lock(&lock);
    printf("%d\n",counter);
    counter=counter+1;
    pthread_mutex_unlock(&lock);
  }
  return 0;
}

int main() {
  const int threads=3;
  pthread_mutex_init(&lock,0);
  pthread_t tids[threads];
  for (int i=0; i<threads; i++)
    pthread_create(&tids[i],0,count,0);
  for (int i=0; i<threads; i++)
    pthread_join(tids[i],0);
  pthread_mutex_destroy(&lock);
  return 0;
}
