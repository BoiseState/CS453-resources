#ifndef BALLOC_H
#define BALLOC_H

typedef void *Balloc;

extern Balloc bcreate(unsigned int size, int l, int u);
extern void   bdelete(Balloc pool);

extern void *balloc(Balloc pool, unsigned int size);
extern void  bfree(Balloc pool, void *mem);

extern unsigned int bsize(Balloc pool, void *mem);
extern void bprint(Balloc pool);

#endif
