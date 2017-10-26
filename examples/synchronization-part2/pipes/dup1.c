

/* 
   Note that we can also get redirection to work by first closing stdout,
   which has file descriptor 1, and then opening a new file so that 
   the new file descriptor is 1 (without using dup system call).

	close(1); // close stdout
	if ((fd = open("log",O_WRONLY|O_CREAT, S_IRUSR|S_IRWUSR)) == -1)
			printf("open failed\n");
	printf("I am redirected\n"); // goes to the file log

	But then if the open failed, the printf for the error message
    would also fail. 

*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;	

	if ((fd = open("log",O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR)) == -1)
			printf("open failed\n");

	close(1); // close stdout
	dup(fd); // make stdout point to the file fd

	printf("I am redirected\n"); // goes to the file log
	exit(0);
}















