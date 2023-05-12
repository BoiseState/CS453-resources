#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static char *prog;

static void usage() {
  fprintf(stderr,"%s: <src> <dst>\n",prog);
  exit(1);
}

int main(int argc, char *argv[]) {
  prog=argv[0];
  if (argc!=3)
    usage();
  char *src=argv[1];
  char *dst=argv[2];
  if (rename(src,dst))
    perror(prog);
  return errno;
}
