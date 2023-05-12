#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <X11/Xlib.h>   

#include "lawn.h"
#define LAWNIMP
#include "lawnimp.h"
#undef LAWNIMP
#include "error.h"

static void *run(void *l) {
  LawnRep r=(LawnRep)l;
  return lawnimp_run(r);
}

extern Lawn lawn_new(int lawnsize, int molesize) {
  if (!lawnsize) lawnsize=40;
  if (!molesize) molesize=15;

  XInitThreads();

  LawnRep lawn=(LawnRep)malloc(sizeof(*lawn));
  if (!lawn) ERROR("malloc() failed");
  lawn->lawnsize=lawnsize;
  lawn->molesize=molesize;
  lawn->window=lawnimp_new(lawnsize,molesize);
  if (pthread_create(&lawn->thread,0,run,lawn))
    ERROR("pthread_create() failed: %s",strerror(errno));
  return lawn;
}

extern void lawn_free(Lawn l) {
  LawnRep r=(LawnRep)l;
  lawnimp_free(r->window);
  if (pthread_join(r->thread,0))
      ERROR("pthread_join() failed: %s",strerror(errno));
  free(r);
}
