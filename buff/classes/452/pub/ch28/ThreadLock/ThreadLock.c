#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "Lock.h"

static int counter=0;

static Lock lck;

static void *count(void *a) {
  while (1) {
    lock(lck);
    if (counter>9) {
      unlock(lck);
      break;
    }
    printf("%d\n",counter);
    counter=counter+1;
    unlock(lck);
  }
  return 0;
}

int main() {
  lck=locknew();
  const int threads=3;
  pthread_t tids[threads];
  for (int i=0; i<threads; i++)
    pthread_create(&tids[i],0,count,0);
  for (int i=0; i<threads; i++)
    pthread_join(tids[i],0);
  free(lck);
  return 0;
}
