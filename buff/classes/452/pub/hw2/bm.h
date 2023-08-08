// A general-purpose bitmap.

#ifndef BM_H
#define BM_H

#include <stdio.h>

typedef void *BM;

extern BM bmnew(size_t bits);

extern void bmset(BM b, size_t i);
extern void bmclr(BM b, size_t i);
extern int  bmtst(BM b, size_t i);

extern void bmprt(BM b);

#endif
