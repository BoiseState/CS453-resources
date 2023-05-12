// gcc -Wall -o dangle-heap dangle-heap.c && ./dangle-heap

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *i=(int *)malloc(sizeof(*i));
  *i=123;
  free(i);
  *i=321;
  int *j=(int *)malloc(sizeof(*j));
  *j=777;
  printf("%d\n",*i);
  return 0;
}
