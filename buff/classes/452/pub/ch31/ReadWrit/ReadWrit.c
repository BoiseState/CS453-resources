#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "mtsb.h"
#include "tsleep.h"

void *reader(void *a) {
  while (1) {
    char *data;
    if ((data=get())) {
      printf("%s\n",data);
      free(data);
    }
    tsleep((long)a+1);
  }
  return 0;
}

void *writer(void *a) {
  while (1) {
    char *data;
    FILE *f=popen("./randword","r");
    fscanf(f,"%ms\n",&data);
    pclose(f);
    put(data);
    free(data);
  }
  return 0;
}

int main() {
  const int readers=5,writers=3;
  const int threads=readers+writers;
  pthread_t tids[threads];
  init();
  for (int i=0; i<threads; i++)
    pthread_create(&tids[i],0,(i<readers?reader:writer),
      (void *)(long)i);
  for (int i=0; i<threads; i++)
    pthread_join(tids[i],0);
  fini();
  return 0;
}
