#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "bitmap.h"
#include "utils.h"

static const int bitsperbyte=8;

static int divup(int n, int d) {
  return (n+d-1)/d;
}

static int mapsize(unsigned int size, int e) {
  int blocksize=e2size(e);
  int blocks=divup(size,blocksize);
  int buddies=divup(blocks,2);
  return divup(buddies,bitsperbyte);
}

static int bitaddr(void *base, void *mem, int e) {
  int addr=buddyclr(base,mem,e)-base;
  int blocksize=e2size(e);
  return addr/blocksize/2;
}

extern BitMap bitmapnew(unsigned int size, int e) {
  int ms=mapsize(size,e);
  BitMap b=mmalloc(ms);
  if ((long)b==-1)
    return 0;
  memset(b,0,ms);
  return b;
}

extern void bitmapset(BitMap b, void *base, void *mem, int e) {
  int offset=bitaddr(base,mem,e);
  bitset(((unsigned char *)b)+offset/bitsperbyte,offset%bitsperbyte);
}

extern void bitmapclr(BitMap b, void *base, void *mem, int e) {
  int offset=bitaddr(base,mem,e);
  bitclr(((unsigned char *)b)+offset/bitsperbyte,offset%bitsperbyte);
}

extern int bitmaptst(BitMap b, void *base, void *mem, int e) {
  int offset=bitaddr(base,mem,e);
  return bittst(((unsigned char *)b)+offset/bitsperbyte,offset%bitsperbyte);
}

extern void bitmapprint(BitMap b, unsigned int size, int e) {
  int ms=mapsize(size,e);
  int byte;
  for (byte=ms-1; byte>=0; byte--)
    printf("%02x%s",((unsigned char *)b)[byte],(byte ? " " : "\n"));
}
