#ifndef UTILS_H
#define UTILS_H

extern void *mmalloc(size_t size);

extern unsigned int e2size(int e);
extern int size2e(unsigned int size);

extern void bitset(unsigned char *p, int bit);
extern void bitclr(unsigned char *p, int bit);
extern void bitinv(unsigned char *p, int bit);
extern int bittst(unsigned char *p, int bit);

extern void *buddyset(void *base, void *mem, int e);
extern void *buddyclr(void *base, void *mem, int e);
extern void *buddyinv(void *base, void *mem, int e);
extern int buddytst(void *base, void *mem, int e);

#endif
