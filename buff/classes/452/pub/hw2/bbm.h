// A baddr bitmap, for the Buddy System.

#ifndef BBM_H
#define BBM_H

#include <stdio.h>

typedef void *BBM;

extern BBM  bbmcreate(size_t size, int e);
extern void bbmdelete(BBM b);

extern void bbmset(BBM b, void *base, void *mem, int e);
extern void bbmclr(BBM b, void *base, void *mem, int e);
extern  int bbmtst(BBM b, void *base, void *mem, int e);

extern void bbmprt(BBM b);

extern void *baddrset(void *base, void *mem, int e);
extern void *baddrclr(void *base, void *mem, int e);
extern void *baddrinv(void *base, void *mem, int e);
extern int   baddrtst(void *base, void *mem, int e);

#endif
