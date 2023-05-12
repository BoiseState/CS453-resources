#include <stdio.h>
int main() {
  int x;
  x = 0;
  x = x;
  x = 1 + 2;
  printf("%g\n", (double)(1 + 2));
  y = x + 3;
  printf("%g\n", (double)(x + 3));
  return 0;
}
