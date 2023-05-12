// gcc -o goto2 goto2.c && ./goto2

#include <stdio.h>

int main() {
  int i=1;
  goto label;
  {
    int j=2;
    j++;    
  label:
    printf("%d %d\n",i,j);
  }
  return 0;
}
