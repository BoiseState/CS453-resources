#include <stdio.h>
#include <stdlib.h>

#include "deq.h"

int main() {
  Deq q=deq_new();

  char *s=deq_str(q,0);
  printf("%s\n",s);
  free(s);

  deq_del(q,0);
  return 0;
}
