#include "bbm.h"
#include "bm.h"
#include "utils.h"

static size_t mapsize(size_t size, int e) {
  size_t blocksize=e2size(e);
  size_t blocks=divup(size,blocksize);
  size_t buddies=divup(blocks,2);
  return buddies;
}

static size_t bitaddr(void *base, void *mem, int e) {
  size_t addr=baddrclr(base,mem,e)-base;
  size_t blocksize=e2size(e);
  return addr/blocksize/2;
}

extern BBM bbmcreate(size_t size, int e) {
  return bmcreate(mapsize(size,e));
}

extern void bbmdelete(BBM b) {
  bmdelete(b);
}

extern void bbmset(BBM b, void *base, void *mem, int e) {
  bmset(b,bitaddr(base,mem,e));
}

extern void bbmclr(BBM b, void *base, void *mem, int e) {
  bmclr(b,bitaddr(base,mem,e));
}

extern int bbmtst(BBM b, void *base, void *mem, int e) {
  return bmtst(b,bitaddr(base,mem,e));
}

extern void bbmprt(BBM b) { bmprt(b); }

extern void *baddrset(void *base, void *mem, int e) {
  unsigned int mask=1<<e;
  return base+((mem-base)|mask);
}

extern void *baddrclr(void *base, void *mem, int e) {
  unsigned int mask=~(1<<e);
  return base+((mem-base)&mask);
}

extern void *baddrinv(void *base, void *mem, int e) {
  unsigned int mask=1<<e;
  return base+((mem-base)^mask);
}

extern int baddrtst(void *base, void *mem, int e) {
  unsigned int mask=1<<e;
  return (mem-base)&mask;
}
