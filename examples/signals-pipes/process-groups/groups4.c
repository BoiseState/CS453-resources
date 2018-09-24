/*
***************************************************************************

 This example illustrates how the group leader, once placed back in the
 foreground group can perform read from stdin. Processes in a
 process group separate from the foreground group cannot perform
 input from the stdin.

 Use tcsetpgrp/tcgetpgrp for better control of foreground/background groups.

 Note: If a process group is orphaned, then the process group gets a
       hangup signal (SIGHUP) followed by  stop signal. Any read then
       generates an error instead of a SIGTTIN/SIGTTOU signal.

****************************************************************************
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void onintr(int signo);

int main()
{
  	pid_t pid1;
  	int status;
  	pid_t grp;
  	int num=0;
  
  	grp = getpgrp();
  	printf("parent process id = %d, process group = %d \n",getpid(),grp);

  	if ((pid1 = fork()) == 0) /* first child process */
  	{
		signal(SIGTTIN, onintr);
		setpgid(0,0);
  		grp = getpgrp();
  		printf("child process id = %d, process group = %d \n",getpid(),grp);

		printf("\nThe child process will now try to read from the terminal\n");
		while (getchar() != EOF) num++;
		printf("number of characters read = %d\n",num);
   	}	

  	sleep(1);
  	/*parent waits for the child process to finish*/
  	waitpid(pid1, &status, 0);
	exit(0);
}

void onintr(int signo) 
{
  	pid_t grp;

	sleep(2);
	printf("\nAieeee!!! Got zapped by SIGTTIN signal\n");
	fflush(NULL);

	printf("\nResetting child process to foreground group\n");
	setpgid(0,getppid());
  	grp = getpgrp();
	printf("child process id = %d, process group = %d \n",getpid(),grp);
	fflush(NULL);
}
