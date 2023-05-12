// gcc -Wall -o goto1 goto1.c && ./goto1

#include <stdio.h>

int main() {
  int i=5;
 loop:
  printf("%d\n",i);
  {
    int j=0;
    j++;    
    if (--i>0)
      goto loop;
    printf("%d\n",j);
  }
  return 0;
}
