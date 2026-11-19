#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include "lawn.h"
#include "mole.h"
#include "error.h"
 
static Mole produce(Lawn l) { return mole_new(l,0,0); }
static void consume(Mole m) { mole_whack(m); }

static const int n=10;

static void *run(void *a) {
  void **arg=a;
  Lawn lawn=(Lawn)arg[0];
  for (int i=1; i<=n; i++)
    consume(produce(lawn));
  lawn_free(lawn);
  return 0;
}

int main() {
  srandom(time(0));
  Lawn lawn=lawn_new(0,0);
  void *arg[]={lawn};
  pthread_t tid;
  if (pthread_create(&tid,0,run,arg))
    ERROR("pthread_create() failed: %s",strerror(errno));
  lawn_run(lawn);
  if (pthread_join(tid,0))
    ERROR("pthread_join() failed: %s",strerror(errno));
}
