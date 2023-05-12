// gcc -o struct-align struct-align.c && ./struct-align

#include <stdio.h>

typedef struct {
  char c1;
  char c2;
  int i;
} T1;

typedef struct {
  char c1;
  int i;
  char c2;
} T2;

int main() {
  T1 v1={'a','b',1};
  T2 v2={'a',1,'b'};

  printf("sizeof(v1)=%d\n",sizeof(v1));
  printf("sizeof(v2)=%d\n",sizeof(v2));

  char *p1=&v1.c1+sizeof(v1.c1);
  char *p2=&v2.c1+sizeof(v2.c1)+sizeof(v2.i);
  printf("*p1=%c\n",*p1);
  printf("*p2=%c\n",*p2);

  return 0;
}
