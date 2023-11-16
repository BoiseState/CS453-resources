#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

static char *prog;

static void usage() {
  fprintf(stderr,"%s: <input>\n",prog);
  exit(1);
}

enum {MaxName=16,MaxAbbr=8,MaxCode=2,STATES=50};
typedef struct {
  char name[MaxName];
  char abbr[MaxAbbr];
  char code[MaxCode];
  char newl;
} State;
typedef State States[STATES];

int main(int argc, char *argv[]) {
  prog=argv[0];
  if (argc!=2)
    usage();
  int ifd=open(argv[1],O_RDONLY);
  if (ifd<0) usage();

  States *states=(States *)mmap(0,sizeof *states,
				PROT_READ,MAP_PRIVATE,
				ifd,0);
  close(ifd);
  for (int i=0; i<STATES; i++)
    printf("%.*s\n",MaxAbbr,(*states)[i].abbr);
  munmap(states,sizeof *states);

  return 0;
}
