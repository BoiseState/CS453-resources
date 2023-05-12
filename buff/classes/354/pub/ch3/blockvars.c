// gcc -o blockvars -Wall blockvars.c && ./blockvars

#include <stdio.h>

int main() {
  // do some stuff
  {
    int a[1000];
    a[500]=a[501]=123;
    printf("&a[0]    =%p\n",&a[0]);
    printf("sizeof(a)=%lu\n",sizeof(a));
  }
  // do some stuff
  {
    double a[1000];
    a[500]=a[501]=1.23;
    printf("&a[0]    =%p\n",&a[0]);
    printf("sizeof(a)=%lu\n",sizeof(a));
  }
  return 0;
}
