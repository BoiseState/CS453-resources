#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static char *prog;

static void usage() {
  fprintf(stderr,"%s: <file>\n",prog);
  exit(1);
}

int main(int argc, char *argv[]) {
  prog=argv[0];
  if (argc!=2)
    usage();
  char *file=argv[1];
  if (unlink(file))
    perror(prog);
  return errno;
}
