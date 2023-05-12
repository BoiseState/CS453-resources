// gcc -o opeval -Wall opeval.c && ./opeval

#include <stdio.h>

int a() { printf("a\n"); return 10; }
int b() { printf("b\n"); return 3; }
int c() { printf("c\n"); return 4; }

int main() {
  printf("%d\n", a()-(b()+c()) );
  return 0;
}

