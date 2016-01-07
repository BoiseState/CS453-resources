
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {

	pid_t pid;
	int status;

	if ((pid=fork())==0) { /* child process */
		sleep(10);
		exit(127);
	} 
	/*
	 parent process continues here
	 try two examples:
	  (1) let the child process finish
	  (2) send a kill signal (kill -9 pid) to the child process
          from another window and see what output this program generates.
	*/

	printf("The pid of the child process is %d \n\n",pid);
	
	pid = waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status)) 
		printf("status of process %d is %d\n",pid,WEXITSTATUS(status)); 
	if (WIFSIGNALED(status))
		printf("child process %d got the signal %d\n",pid,WTERMSIG(status)); 

	
	exit(0);
}
