#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  pid_t pid1, pid2;
  int pipefd[2];
  int status;
  char *argv[2];

  if ((pid1 = fork()) == (pid_t)0) /* first child process */
  {
     /* Assumes file descriptors 0 and 1 are open   */
     pipe (pipefd);

     if ((pid2 = fork()) == (pid_t) 0) { /* second child process */

         close(1);      /* close stdout, normally fileno 1 */
         dup(pipefd[1]); /* points pipefd at file descriptor */
         close (pipefd[0]);
		 argv[0] = (char *) malloc(strlen("ls")+1);
		 strcpy(argv[0], "ls");
		 argv[1]=0;
         execvp ("ls", argv);  /* child process does ls */

     } else {  

         close(0); /* close stdin, normally fileno 0 */
         dup(pipefd[0]);
         close (pipefd[1]);
		 argv[0] = (char *) malloc(strlen("sort")+1);
		 strcpy(argv[0], "sort");
		 argv[1]=0;
         execvp ("sort", argv); /* child does sort */
     }
   }
   /* parent waits for the last process in the pipeline to finish*/
   waitpid(pid1, &status, 0);
   exit(0);
}

