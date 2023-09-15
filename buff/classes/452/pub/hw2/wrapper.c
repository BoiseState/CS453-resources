#include <string.h>

#include "balloc.h"

static Balloc bp=0;

#include <stdio.h>

extern void *malloc(size_t size) {
  bp=bp ? bp : bcreate(4096,4,12);
  return balloc(bp,size);
}

extern void free(void *ptr) {
  bfree(bp,ptr);
}

extern void *realloc(void *ptr, size_t size) {
  size_t min(size_t x, size_t y) { return x<y ? x : y; }
  void *new=malloc(size);
  if (!ptr)
    return new;
  memcpy(new,ptr,min(size,bsize(bp,ptr)));
  free(ptr);
  return new;
}
