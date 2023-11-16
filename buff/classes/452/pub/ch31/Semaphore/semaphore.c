// OSTEP implements their semaphores with pthread condition variables!
// We implement a semaphore with two of our homemade locks.

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

#include "semaphore.h"
#include "Atomic.h"
#include "Error.h"

typedef struct {
  int value;                    // resource count
  int mutex;                    // a homemade lock
  int hold;                     // a homemade lock
} *Semaphore;

extern void sem_init(sem_t *s, int flags, int value) {
  Semaphore r=(Semaphore)malloc(sizeof *r);
  if (!r) ERROR("malloc() failed");
  r->value=value;
  r->mutex=0;
  r->hold=1;
  *(Semaphore *)s=r;
}

extern void sem_wait(sem_t *s) {
  Semaphore r=*(Semaphore *)s;
  while (atomic_lock(&r->mutex));
  r->value--;
  if (r->value<0) {
    atomic_unlock(&r->mutex);
    while (atomic_lock(&r->hold))
      sched_yield();       // lock(hold) and yield core
  } else {
    atomic_unlock(&r->mutex);
  }
}

extern void sem_post(sem_t *s) {
  Semaphore r=*(Semaphore *)s;
  while (atomic_lock(&r->mutex));
  r->value++;
  if (r->value<=0) {
    // If there are waiters:
    //     1) spin until one does a lock(hold)/yield iteration
    //     2) unlock(hold) so exactly one can wake up
    while (!atomic_test(&r->hold));
    atomic_unlock(&r->hold);
  }
  atomic_unlock(&r->mutex);
}

extern void sem_destroy(sem_t *s) {
  free(s);
}
