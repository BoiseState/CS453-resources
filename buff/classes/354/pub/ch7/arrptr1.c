// gcc -Wall -Wno-sizeof-array-argument  -o arrptr1 arrptr1.c && ./arrptr1

#include <stdio.h>

#define P(F,A,B) printf("%s: "              \
                        "sizeof(%s)=%ld "   \
                        "sizeof(%s)=%ld\n", \
                        #F,                 \
                        #A,sizeof(A),       \
                        #B,sizeof(B))

void f1(int *a, int b[])   {           P(f1,a,b); }
void f2(int **a, int *b[]) {           P(f2,a,b); }
void f3(int a[4])          { int b[4]; P(f3,a,b); }

int main() {
  printf("sizeof(void *)=%ld sizeof(int)=%ld\n",sizeof(void *),sizeof(int));
  f1(0,0);
  f2(0,0);
  f3(0);
  return 0;
}
