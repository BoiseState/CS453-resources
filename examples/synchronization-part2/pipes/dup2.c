

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;	

	if ((fd = open("log",O_WRONLY|O_CREAT, S_IRWXU)) == -1)
			printf("open failed\n");

	close(1); // close stdout
	dup(fd); // make stdout point to the file fd

	printf("I am redirected\n"); // goes to the file log
	fflush(stdout);

	if ((fd = open("/dev/tty",O_WRONLY|O_CREAT, S_IRWXU)) == -1)
			printf("open failed\n");

	close(1);
	dup(fd);
	// now the output goes to the controlling terminal 
	printf("huh! I am no longer redirected\n"); 
	exit(0);
}















