// gcc -Wall -o label label.c && ./label

#include <stdio.h>

int label() {
  static int n=0;
  return ++n;
}

int main() {
  printf("label()=%d\n",label());
  printf("label()=%d\n",label());
  return 0;
}
