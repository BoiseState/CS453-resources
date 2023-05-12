// C sum program

#include <stdio.h>
#include <stdlib.h>

static int sum(int *seq, int n) {
  int s=0;
  while (n--)
    s+=*seq++;
  return s;
}

int main() {
  const int n=6;
  int *seq=(int *)alloca(n*sizeof(int)); // stack allocation
  if (!seq) exit(1);
  seq[0]=5; seq[1]=6; seq[2]=1; seq[3]=8; seq[4]=3; seq[5]=7;
  printf("%d\n",sum(seq,n));
  return 0;
}
