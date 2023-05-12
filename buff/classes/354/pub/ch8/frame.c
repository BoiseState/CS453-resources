// gcc -g -Wall -o frame frame.c && ./frame | sort -ur

#include <stdio.h>

#define PRNT(V,T,K) printf("%p - %p (%ld) %s\n", \
                          (char*)V+sizeof(T)-1,V,sizeof(T),#K)

typedef struct { int i; } T;

T foo(int a, int b, int c, int d, int e, int f, int g, int h) {
  int x=0xcccc;
  int y=0xdddd;
  PRNT(&a,int,formal a);
  PRNT(&b,int,formal b);
  PRNT(&c,int,formal c);
  PRNT(&d,int,formal d);
  PRNT(&e,int,formal e);
  PRNT(&f,int,formal f);
  PRNT(&g,int,formal g);
  PRNT(&h,int,formal h);
  PRNT(&x,int,local x);
  PRNT(&y,int,local y);
  T t={0xeeee};
  return t;
}

#define FIND(T,P,V) T* P; for (P=sp+16; *P!=(T)V; P--)

int main() {
  register void* sp asm ("sp");
  printf("%p = sp\n",sp);
  register void* bp asm ("bp");
  printf("%p = fp\n",bp);

  T retval=foo(1,2,3,4,5,6,7,8);
  FIND(int,p1,retval.i);
  PRNT(p1,int,retval);

  foo(1,2,3,4,5,6,7,8);
 label:;
  FIND(long,p2,&&label);
  PRNT(p2,long*,retadr);

  foo(1,2,3,4,5,6,7,8);
  FIND(long,p3,bp);
  PRNT(p3,long*,fp);

  return 0;
}
