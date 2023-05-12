// gcc -o seorder -Wall seorder.c && ./seorder

#include <stdio.h>

int x=1;

int a() { return x; }
int b() { return x++; }

int f(int i, int j) { return i+j; }

int main() {
  int i=f(a(),b());
  //int i=f(b(),a());
  printf("%d\n",i);
  return 0;
}
