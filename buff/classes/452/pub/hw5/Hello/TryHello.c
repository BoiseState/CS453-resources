#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERR(s) err(s,__FILE__,__LINE__)

static void err(char *s, char *file, int line) {
  fprintf(stderr,"%s:%d: %s\n",file,line,s);
  exit(1);
}

int main() {
  int fd=open("/dev/Hello",O_RDWR);
  if (fd<0)
    ERR("open() failed");
  enum { size=100 };
  char buf[size];
  for (int len; (len=read(fd,buf,size));) {
    buf[len]=0;
    printf("%s",buf);
  }
  close(fd);
  return 0;
}
