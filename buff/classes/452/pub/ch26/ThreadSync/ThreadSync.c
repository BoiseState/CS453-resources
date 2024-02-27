#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static int done=0;

static void *count(void *a) {
  while (!done)
    printf("%ld\n",(long)a);
  return 0;
}

int main() {
  const int threads=3;
  pthread_t tids[threads];
  for (int i=0; i<threads; i++)
    pthread_create(&tids[i],0,count,(void *)(long)i);
  usleep(100); // 0.1ms
  done=1;
  for (int i=0; i<threads; i++)
    pthread_join(tids[i],0);
  return 0;
}
