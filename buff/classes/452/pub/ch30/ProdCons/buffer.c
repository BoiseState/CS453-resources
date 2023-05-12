#include "buffer.h"

static int buf[max];

static int cnt=0,beg=0,end=0;

static int f() { return cnt==max; }
static int e() { return cnt==0; }
Busy full=f;
Busy empt=e;

#define INC(x) x++, x%=max
// or, pass an address, and:
// int INC(int *x) { (*x)++; return (*x)%=max; }

extern void put(int data) { cnt++; buf[INC(beg)]=data; }
extern int  get()         { cnt--; return buf[INC(end)]; }
