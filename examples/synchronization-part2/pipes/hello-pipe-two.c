#include "common.h"
#include <sys/wait.h>

int main(void)
{
	int	  n, fd[2], i, status;
	pid_t pid;
	char  line[MAXLINE];

	if (pipe(fd) < 0)
		err_sys("pipe error");

	/* parent creates child 1 */
	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	if (pid == 0) /* child 1 */
	{
		close(fd[0]); /* close read end of pipe */
		write(fd[1], "goodbye world ", 14);
		printf("child 1 wrote 14 characters to the parent in the pipe: goodbye world\n");
		exit(EXIT_SUCCESS);
	}

	/* parent creates child 2 */
	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	if (pid == 0) /* child 2 */
	{
		close(fd[0]); /* close read end of pipe */
		write(fd[1], "hello world ", 12);
		printf("child 2 wrote 12 characters to the parent in the pipe: hello world\n");
		exit(EXIT_SUCCESS);
	}

	/* wait for both children to finish before reading */
	for(i = 0; i < 2; i++)
		waitpid(-1, &status, 0);

	/* parent reads from pipe */
	close(fd[1]); /* close write end of pipe */
	n = read(fd[0], line, MAXLINE);
	printf("parent read %d characters from the parent in the pipe: %s\n", n, line);

	exit(EXIT_SUCCESS);
}
