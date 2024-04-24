#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "error.h"
#include "fpp.h"

#include "cmd_process.h"
#include "cmd_single.h"
#include "cmd_thread.h"

/***************************************************************************
 * This function zeroes the newline at the end of a string, if             *
 * it exists.                                                              *
 ***************************************************************************/
static int rmnl(char *s, int l) {
  if (l>0 && s[l-1]=='\n')
    s[--l]=0;
  return l;
}

/***************************************************************************
 * This function opens, binds, and listens to a socket for                 *
 * servicing clients.                                                      *
 ***************************************************************************/
static int init() {
  struct sockaddr_in addr;
  int fd=socket(PF_INET,SOCK_STREAM,0);
  if (fd<0)
    ERROR("init(): socket() failed: %s",strerror(errno));
  int yes=1;
  if (setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes)))
    ERROR("init(): setsockopt() failed: %s",strerror(errno));
  bzero(&addr,sizeof(addr));
  addr.sin_family=AF_INET;
  addr.sin_addr.s_addr=htons(INADDR_ANY);
  addr.sin_port=htons(ECHOD_PORT);
  int tries=0;
  while (bind(fd,(struct sockaddr *)&addr,sizeof(addr))<0) {
    if (++tries>ECHOD_TRIES)
      ERROR("init(): bind() failed: %s",strerror(errno));
    sleep(1<<tries);
  }
  if (listen(fd,SOMAXCONN)<0)
    ERROR("init(): listen() failed: %s",strerror(errno));
  return fd;
}

/***************************************************************************
 * This is the command table.                                              *
 ***************************************************************************/

static void cmd_exit(FPP *fpp) { exit(1); }

typedef struct {
  char *name;
  void (*func)(FPP *fpp);
} Cmd;

static Cmd cmds[]={{"single", cmd_single},
                   {"thread", cmd_thread},
                   {"process",cmd_process},
                   {"exit",   cmd_exit},
                   {0,0}};

/***************************************************************************
 * This function opens read and write streams from/to the                  *
 * client, reads the command from the client, and performs it.             *
 ***************************************************************************/
static void serve(int fd) {
  FPP *fpp=fpp_open(fd);
  char *cmd=0;
  size_t n=0;
  ssize_t len=getline(&cmd,&n,fpp->r);
  len=rmnl(cmd,len);
  if (len>=0)
    for (Cmd *c=cmds; c->name; c++)
      if (!strcmp(cmd,c->name))
        c->func(fpp);
  free(cmd);
}

/***************************************************************************
 * This function repeatedly services client requests,                      *
 * periodically reaping exited children.                                   *
 ***************************************************************************/
static void server(int sfd) {
  while (1) {
    struct timeval timeout={ECHOD_REAP}; // seconds between reaps
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(sfd,&fds);
    int count=TEMP_FAILURE_RETRY(select(FD_SETSIZE,&fds,0,0,&timeout));
    if (count<0)
      ERROR("server(): select() failed: %s",strerror(errno));
    if (count==1 && FD_ISSET(sfd,&fds)) {
      int cfd=TEMP_FAILURE_RETRY(accept(sfd,0,0));
      if (cfd<0)
        ERROR("server(): accept() failed: %s",strerror(errno));
      serve(cfd);
    }
    while (waitpid(0,0,WNOHANG)>0)
      ; // reap exited children
  }
}

/***************************************************************************
 * This function opens the errfile, carefully.                             *
 ***************************************************************************/
static void open_stderr() {
  int fd=dup(2);
  stderr=freopen(ECHOD_ERRFILE,"w",stderr);
  if (!stderr) {
    stderr=fdopen(fd,"w");
    ERROR("main(): freopen() failed: %s",strerror(errno));
  }
  close(fd);
}

/***************************************************************************
 * This is the main function. It opens the errfile, does the               *
 * Unix server-isolation thing, opens the client/server socket,            *
 * and starts servicing client requests.                                   *
 ***************************************************************************/
int main() {
  signal(SIGHUP,SIG_IGN); // gdb will attach a terminal: ignore hang ups
  open_stderr();
  if (fork())
    exit(0); // parent exits
  setsid();  // child leads a new session and a new process group
  chdir("/");
  umask(0);
  close(0);
  close(1);
  server(init());
  return 0;
}
