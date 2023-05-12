#ifndef BITMAP_H
#define BITMAP_H

typedef void *BitMap;

extern BitMap bitmapnew(unsigned int size, int e);

extern void bitmapset(BitMap b, void *base, void *mem, int e);
extern void bitmapclr(BitMap b, void *base, void *mem, int e);
extern int bitmaptst(BitMap b, void *base, void *mem, int e);

extern void bitmapprint(BitMap b, unsigned int size, int e);

#endif
