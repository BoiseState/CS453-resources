#ifndef LAWNIMP_H
#define LAWNIMP_H

#ifndef LAWNIMP
#error Do not #include this file, directly.
#endif

#include <pthread.h>

#include "linkage.h"

typedef struct {
  int lawnsize;
  int molesize;
  void *window;
  pthread_t thread;
} *LawnRep;

typedef struct {
  int size;
  int x,y;
  int vim0,vim1,vim2;
  void *lawn;
  void *box;
} *MoleRep;

extern LINKAGE void* lawnimp_new(int lawnsize, int molesize);
extern LINKAGE void* lawnimp_run(LawnRep l);
extern LINKAGE void* lawnimp_mole(MoleRep m);
extern LINKAGE void  lawnimp_whack(MoleRep m);
extern LINKAGE void  lawnimp_free(void* w);

#endif
