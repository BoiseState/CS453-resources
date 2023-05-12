// C sum program

#include <stdio.h>

static int sum(int seq[], int n) {
  int s=0;
  for (int i=0; i<n; i++)
    s+=seq[i];
  return s;
}

int main() {
  auto int seq[]={5,6,1,8,3,7}; // stack allocation
  printf("%d\n",sum(seq,sizeof(seq)/sizeof(int)));
  return 0;
}
