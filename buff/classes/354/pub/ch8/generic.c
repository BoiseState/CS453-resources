// gcc -Wall -o generic generic.c && ./generic

#include <stdio.h>

void *foo(void *a) {
  a++;
  a--;
  return a;
}

int main() {
  double d=3.14;
  double *dp=&d;
  dp=foo(dp);
  printf("%f\n",*dp);
  return 0;
}
