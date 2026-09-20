#ifndef BALLOC_H
#define BALLOC_H

typedef void *Balloc;

extern Balloc bcreate(unsigned int size, int l, int u);
extern void   bdelete(Balloc ba);

extern void *balloc(Balloc ba, unsigned int size);
extern void  bfree(Balloc ba, void *mem);

extern unsigned int bsize(Balloc ba, void *mem);
extern void bprint(Balloc ba);

#endif
