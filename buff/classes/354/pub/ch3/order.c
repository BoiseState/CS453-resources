// gcc -Wall -o order order.c && ./order

#include <stdio.h>

int main() {
  int a=1;
  {
    int b=a;
    int a=2;
    int c=a;
    int d=b;
    printf("%d %d %d %d\n",a,b,c,d);
  }
  return 0;
}
