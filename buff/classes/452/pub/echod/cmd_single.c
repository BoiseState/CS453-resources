#include <stdio.h>
#include <string.h>

#include "cmd_single.h"
#include "error.h"

static int echo(FPP *fpp, char *s) {
  fprintf(fpp->w,"%s\n",s?s:"");
  return 0;
}

static int quit(FPP *fpp, char *line) { return 1; }

/***************************************************************************
 * This is the command table.                                              *
 ***************************************************************************/

typedef struct {
  char *name;
  int (*func)(FPP *fpp, char *s);
} Cmd;

static Cmd cmds[]={{"echo",echo}, {"quit",quit}, {0,0}};

/***************************************************************************
 * This function services a client.  It repeatedly reads and               *
 * performs a command from the client.                                     *
 *                                                                         *
 * Arguments:                                                              *
 *     - fpp: file-pointer pair                                            *
 ***************************************************************************/
extern void cmd_single(FPP *fpp) {
  int done=0;
  while (!done) {
    char *line=0;
    size_t n=0;
    ssize_t len=getline(&line,&n,fpp->r);
    if (len>=0) {
      char *cmd=strdup(strtok(line," \n"));
      char *args=strtok(0,"\n");
      done=1;
      for (Cmd *c=cmds; c->name; c++)
        if (!strcmp(cmd,c->name))
          done=c->func(fpp,args);
      free(cmd);
      free(line);
    }
  }
  fpp_close(fpp);
}
