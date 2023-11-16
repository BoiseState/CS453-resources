#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mtsb.h"
#include "semaphore.h"
#include "error.h"

typedef struct {
  char *s;
  int getters;
  sem_t getable,putable;
} *Buffer;

static Buffer b;

static void rd_lock() {
  sem_wait(&(b->getable));
  b->getters++;
  if (b->getters==1)
    sem_wait(&(b->putable));
  sem_post(&(b->getable));
}

static void rd_unlock() {
  sem_wait(&(b->getable));
  b->getters--;
  if (b->getters==0)
    sem_post(&(b->putable));
  sem_post(&(b->getable));
}

static void wr_lock()   { sem_wait(&(b->putable)); }
static void wr_unlock() { sem_post(&(b->putable)); }

extern void init() {
  if (!(b=(Buffer)malloc(sizeof *b)))
    ERROR("malloc() failed");
  b->s=0;
  b->getters=0;
  sem_init(&(b->getable),0,1);
  sem_init(&(b->putable),0,1);
}

extern char *get() {
  char *s=0;
  rd_lock();
  if (b->s) {
    s=strdup(b->s);
    if (!s) ERROR("strdup() failed");
  }
  rd_unlock();
  return s;
}

extern void put(char *s) {
  wr_lock();
  if (!(b->s=realloc(b->s,strlen(s)+1)))
    ERROR("realloc() failed");
  strcpy(b->s,s);
  wr_unlock();
}

extern void fini() {
  sem_destroy(&(b->getable));
  sem_destroy(&(b->putable));
  if (b->s) free(b->s);
  free(b);
}
