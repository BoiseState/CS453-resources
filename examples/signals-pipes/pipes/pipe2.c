
/*
*
* Note that we can interchange what the child and the parent does...that is
* have the parent do ls and the child do sort and this example pipeline
* would still run. However now the pipeline would seem to run in the
* background.
*
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
	pid_t pid;
	int pipefd[2];

   /*  Assumes file descriptor 0 and 1 are open  */
   pipe (pipefd);

   if ((pid = fork()) > 0) /* check process id of child process */
   {
	  close(0); /* close stdin, normally fileno 0 */
      dup (pipefd[0]);
      /* point the parent's standard output to parent's standard input */
      close (pipefd[1]);
      execlp ("wc", "wc", (char *)0); /* parent process does sort */

   } else if (pid == 0) {
  		close(1);      /* close stdout, normally fileno 1 */
        dup(pipefd[1]); /* points pipefd at file descriptor */
        close (pipefd[0]);
        execlp ("ls", "ls", (char *)0);  /* child process does ls */
   }
	exit(0);
}

