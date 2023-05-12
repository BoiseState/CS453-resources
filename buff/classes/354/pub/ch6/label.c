// gcc -Wall -o label label.c && ./label

#include <stdio.h>

typedef struct {
  int curr;
  int next;
} Label;

Label label(Label old) {
  Label new;
  new.curr=old.next;
  new.next=new.curr+1;
  return new;
}

void doit(int cnt, Label lab) {
  if (cnt==0) return;
  Label new=label(lab);
  printf("label%d:\n",new.curr);
  doit(cnt-1,new);
}

int main() {
  Label lab={0,0};
  printf("label%d:\n",lab.curr);
  doit(5,lab);
  return 0;
}
