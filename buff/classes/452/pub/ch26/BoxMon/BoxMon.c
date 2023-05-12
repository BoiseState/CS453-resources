#include <stdio.h>
#include <pthread.h>

#include "Box.h"

static Box box;

static void *run(void *a) {
  putBox(box,a);
  printf("%s\n",getBox(box));
  return 0;
}

int main() {
  box=newBox();
  pthread_t t1,t2;
  pthread_create(&t1,0,run,"t1");
  pthread_create(&t2,0,run,"t2");
  pthread_join(t1,0);
  pthread_join(t2,0);
  return 0;
}
