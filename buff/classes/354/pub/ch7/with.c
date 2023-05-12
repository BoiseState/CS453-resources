// gcc -Wall -o with with.c && ./with

#include <stdio.h>

typedef struct {
  struct {
    struct {
      char c1;
      char c2;
    } b;
  } a;
} T;

int main() {
  T v;
  v.a.b.c1='a';
  v.a.b.c2='b';
  printf("%c\n",v.a.b.c1);
  printf("%c\n",v.a.b.c2);
  return 0;
}
