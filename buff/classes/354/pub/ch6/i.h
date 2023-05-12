#include <stdio.h>

int *f() {
  j++;				/* side effect */
  return &i;
}

#define i (*f())
