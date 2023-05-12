// gcc -w -o dangle-stack dangle-stack.c && ./dangle-stack

#include <stdio.h>

int *f() {
  int i=123;
  return &i;
}

void g(int *i) {
  printf("%d\n",*i);
}

int main() {
  g(f());
  return 0;
}
