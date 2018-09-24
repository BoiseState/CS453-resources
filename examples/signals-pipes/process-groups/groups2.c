/*
***************************************************************************

 This example illustrates how a parent process can change the group
 of a child process on the fly.

****************************************************************************
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
  pid_t pid1;
  int status;
  pid_t grp;
  
  grp = getpgrp();
  printf("process id = %d, process group = %d \n",getpid(),grp);

  if ((pid1 = fork()) == 0) /* first child process */
  {
  	grp = getpgrp();
  	printf("process id = %d, process group = %d \n",getpid(),grp);
	sleep(5);
	
  	grp = getpgrp();
  	printf("process id = %d, process group = %d \n",getpid(),grp);
	sleep(5);
	exit(0);
  }

  sleep(1);
  if (setpgid(pid1, pid1) < 0) {
		  perror("setpgid error");
  }		  
  /*parent waits for the child to finish*/
  waitpid(pid1, &status, 0);
  exit(0);
}
