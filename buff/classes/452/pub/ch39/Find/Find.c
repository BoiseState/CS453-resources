#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#include "error.h"

static char *prog;

static int isdir(char *path, char *entry) {
  if (!strcmp(entry,".") ||
      !strcmp(entry,".."))
      return 0;
  struct stat buf;
  if (lstat(path,&buf)) ERROR(strerror(errno));
  return S_ISDIR(buf.st_mode);
}

static void find(char *dir) {
  DIR *dp=opendir(dir);
  if (!dp) ERROR(strerror(errno));
  struct dirent *dirp;
  while ((dirp=readdir(dp))) {
    char *path;
    asprintf(&path,"%s/%s",dir,dirp->d_name);
    printf("%s\n",path);
    if (isdir(path,dirp->d_name))
      find(path);
    free(path);
  }
  closedir(dp);
}

int main(int argc, char *argv[]) {
  prog=argv[0];
  char *dir=getcwd(0,0);
  if (!dir) ERROR(strerror(errno));
  find(dir);
  free(dir);
  return 0;
}
