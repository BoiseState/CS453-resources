#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int status;
	pid_t pid;

	for(;;){
		sleep(5); 
		pid=fork();
		if (pid == 0)
		{
			sleep(100);
			printf("hello\n");
			exit(0);
		}
		waitpid(pid, &status, 0);
	}
}
