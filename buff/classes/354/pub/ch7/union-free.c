// gcc -o union-free union-free.c && ./union-free

#include <stdio.h>

typedef union {
  char c;
  int i;
} T;

int main() {
  T v;
  printf("&v.c=%x\n",&v.c);
  printf("&v.i=%x\n",&v.i);

  v.c='a';
  printf("v.c=%c\n",v.c);
  v.i=123;
  printf("v.i=%d\n",v.i);

  return 0;
}
