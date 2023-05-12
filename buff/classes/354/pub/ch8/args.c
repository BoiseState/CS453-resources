// gcc -Wall -o args args.c && ./args

#include <stdio.h>
#include <stdarg.h>

static void foo(char *s, ...) {
  char *a;
  va_list ap;
  for (va_start(ap,s),a=s; a; a=va_arg(ap,char *))
    printf("%s\n",a);
  va_end(ap);
}

int main() {
  foo("a","b","c",0);
  return 0;
}
