// gcc -Wall -o pointercast pointercast.c && ./pointercast

#include <stdio.h>

int main() {
  char *s="foo";
  int *i=(int *)s;
  printf("char alignment ok:              %p\n",s);
  printf("int  alignment ok:              %p\n",i);
  s++;
  i++;
  printf("char alignment ok:              %p\n",s);
  printf("int  alignment ok:              %p\n",i);
  i=(int *)s;
  printf("int  alignment may cause error: %p\n",i);
  return 0;
}
