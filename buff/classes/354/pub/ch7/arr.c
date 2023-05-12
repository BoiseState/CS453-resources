// gcc -Wall -o arr arr.c && ./arr

#include <stdio.h>

void f(int a[][3]) {
  printf("%d\n",a[1][2]);
}

// 11 12 13
// 21 22 23

int main() {
  int a[2][3]={{11,12,13},{21,22,23}};
  f(a);
  return 0;
}
