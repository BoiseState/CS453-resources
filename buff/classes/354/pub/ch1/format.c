// gcc -Wall -g -o format format.c && ./format

#include <stdio.h>

int main() {
  int i=123;
  double d=3.14;
  printf("%7d FOO %7.4f\n",i,d);
  return 0;
}
