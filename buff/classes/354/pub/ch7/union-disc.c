// gcc -Wall -o union-disc union-disc.c && ./union-disc

#include <stdio.h>

typedef enum {Chr,Int} Kind;

typedef struct {
  Kind knd;			/* discriminant */
  union {
    char c;
    int i;
  } data;
} T;

int main() {
  T v;

  v.knd=Chr;
  v.data.c='a';
  // ...
  switch (v.knd) {
    case Chr: printf("v.data.c=%c\n",v.data.c); break;
    case Int: printf("v.data.i=%d\n",v.data.i); break;
  }
  return 0;
}
