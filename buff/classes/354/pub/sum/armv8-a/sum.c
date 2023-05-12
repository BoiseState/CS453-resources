/* C sum program */

#include <stdio.h>

static int sum(int seq[], int n) {
  int s=0;
  int i;
  for (i=0; i<n; i++)
    s+=seq[i];
  return s;
}

int main() {
  const int n=6;
  int seq[]={5,6,1,8,3,7};
  printf("%d\n",sum(seq,n));
  return 0;
}
