// gcc -Wall -o aliasing aliasing.c && ./aliasing

#include <stdio.h>

int main() {
  union {
    struct { int x,y,z; } s;
    int a[3];
  } u={{0,123,0}};
  u.a[1]++;
  printf("%d %d\n",u.a[1],u.s.y);

  int i=123;
  int *p=&i;
  (*p)++;
  printf("%d %d\n",i,*p);

  int a[100]={0,123};
  extern void f(int a[], int b[]);
  f(a,a);    
  printf("%d\n",a[1]);
}

void f(int a[], int b[]) { a[1]++; b[1]++; }
