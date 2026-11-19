#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lawn.h"
#define LAWNIMP
#include "lawnimp.h"
#undef LAWNIMP
#include "error.h"

extern Lawn lawn_new(int lawnsize, int molesize) {
  if (!lawnsize) lawnsize=40;
  if (!molesize) molesize=15;
  LawnRep r=(LawnRep)malloc(sizeof *r);
  if (!r) ERROR("malloc() failed");
  r->lawnsize=lawnsize;
  r->molesize=molesize;
  r->window=lawnimp_new(lawnsize,molesize);
  return r;
}

extern void lawn_run(Lawn l) { lawnimp_run((LawnRep)l); }

extern void lawn_free(Lawn l) {
  LawnRep r=(LawnRep)l;
  lawnimp_free(r->window);
  free(r);
}
