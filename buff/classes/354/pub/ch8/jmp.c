// gcc -Wall -o jmp jmp.c && ./jmp 1

#include <stdio.h>
#include <setjmp.h>

static jmp_buf env;		// setjmp/longjmp

static void foo(int i) {
  if (i<2)
    longjmp(env,123);           // setjmp will return 123
  // much more code
  printf("foo() done\n");
}

int main(int argc, char *argv[]) {
  if (!setjmp(env)) {		// nonzero means "exception"
    foo(argc);
    // much more code
    printf("ok\n");
  } else {
    printf("not ok\n");
  }
  return 0;  
}
