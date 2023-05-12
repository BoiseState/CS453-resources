#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
  char *cmd;
  char *inp;
  scanf("%ms\n",&cmd);
  scanf("%ms",&inp);
  if (!fork()) {
    int fd=open(inp,O_RDONLY);
    if (fd<0)
      exit(1);
    dup2(fd,fileno(stdin));
    execlp(cmd,cmd,NULL);
  }
  free(cmd);
  free(inp);
  wait(0);
  char *bye;
  scanf("%ms",&bye);
  printf("%s\n",bye);
  free(bye);
  return 0;
}
