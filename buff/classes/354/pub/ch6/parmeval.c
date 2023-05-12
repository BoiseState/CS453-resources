// gcc -o parmeval -Wall parmeval.c && ./parmeval

#include <stdio.h>

int a() { printf("a\n"); return 10; }
int b() { printf("b\n"); return 3; }
int c() { printf("c\n"); return 4; }

int f(int x, int y, int z) { return x-(y+z); }

int main() {
  printf("%d\n", f(a(),b(),c()) );
  return 0;
}

