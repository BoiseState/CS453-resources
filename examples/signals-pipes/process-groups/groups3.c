/*
***************************************************************************

 This example illustrates how a parent process can change the group
 of a child process on the fly but not after a child does exec.

****************************************************************************
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
  pid_t pid1, pid2;
  int status;
  pid_t grp;
  
  grp = getpgrp();
  printf("parent process id = %d, process group = %d \n",getpid(),grp);

  if ((pid1 = fork()) == 0) /* first child process */
  {
	setpgid(0,0);
  	grp = getpgrp();
  	printf("child process id = %d, process group = %d \n",getpid(),grp);

  	if ((pid2 = fork()) == 0) /* second child process */
  	{
  		grp = getpgrp();
  		printf("before exec: grandchild process id = %d, process group = %d\n",getpid(),grp);
		fflush(NULL);
		execlp("print-gid","print-gid", (char *)0);
	} else {		
			
		sleep(2); /* give enough time for execl to happen */
		printf("After 2 secs: Parent trying to change process group for child after exec.\n");
		fflush(NULL);
		setpgid(pid2,pid2);
    }
   }	

  sleep(1);
  /*parent waits for the last process in the pipeline to finish*/
  waitpid(pid1, &status, 0);
  exit(0);

}
