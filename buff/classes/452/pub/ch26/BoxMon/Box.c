#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "Box.h"

typedef struct {
  pthread_mutex_t mutex;
  pthread_cond_t condv;
  char *msg;
} *BoxRep;

#define ERR(s) err(s,__FILE__,__LINE__)

static void err(char *s, char *file, int line) {
  fprintf(stderr,"%s:%d: %s\n",file,line,s);
  exit(1);
}

extern Box newBox() {
  BoxRep r=(BoxRep)malloc(sizeof *r);
  if (!r)
    ERR("malloc() failed");
  pthread_mutex_init(&r->mutex,0);
  pthread_cond_init(&r->condv,0);
  r->msg=0;
  return r;
}

extern char *getBox(Box box) {
  BoxRep r=(BoxRep)box;
  pthread_mutex_lock(&r->mutex);
  while (!r->msg)
    pthread_cond_wait(&r->condv,&r->mutex);
  char *msg=r->msg;
  r->msg=0;
  pthread_mutex_unlock(&r->mutex);
  pthread_cond_signal(&r->condv);
  return msg;
}

extern void putBox(Box box, char *msg) {
  BoxRep r=(BoxRep)box;
  pthread_mutex_lock(&r->mutex);
  while (r->msg)
    pthread_cond_wait(&r->condv,&r->mutex);
  r->msg=msg;
  pthread_mutex_unlock(&r->mutex);
  pthread_cond_signal(&r->condv);
}
