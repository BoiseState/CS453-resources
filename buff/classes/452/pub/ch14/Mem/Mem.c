#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

static int x=1; // static
int y=2;        // static

extern int foo(int a) { // stack
  auto int x=11;        // stack
  int y=12;             // stack
  static int z=3;       // static
  return x+y+z;         // stack
}

int main() {
  int *p=(int *)malloc(sizeof *p); // p: stack; *p: heap
  *p=foo(x+y);                     // copy from stack to heap
  free(p);

  int *q=mmap(0,sizeof *q, // q: stack; *q: ???
              PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
  *q=foo(x+y); // copy from stack to ???
  munmap(q,sizeof *q);

  return 0;
}
