// gcc -Wall -o alloca alloca.c && ./alloca

#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>
#include <string.h>

void f() {
  char *s=alloca(1000);
  if (!s) exit(1);
  strcpy(s,"Hi!");
  printf("%s\n",s);
}

int main() {
  f();
  return 0;
}
