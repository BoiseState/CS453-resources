#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  struct stat buf;

  if (mkdir("foo",0777))                      perror(0);
  if (chdir("foo"))                           perror(0);

  if (link("../../stat.h","bar"))             perror(0);
  if (stat("bar",&buf))                       perror(0);
  printf(" stat size: %ld\n",buf.st_size);
  if (unlink("bar"))                          perror(0);
  if (symlink("../../stat.h","bar"))          perror(0);
  if (stat("bar",&buf))                       perror(0);
  printf(" stat size: %ld\n",buf.st_size);
  if (lstat("bar",&buf))                      perror(0);
  printf("lstat size: %ld\n",buf.st_size);
  if (unlink("bar"))                          perror(0);

  if (chdir(".."))                            perror(0);
  if (rmdir("foo"))                           perror(0);
  return 0;
}

