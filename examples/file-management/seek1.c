
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>



int main(void)
{
 	int i;	
	char buf[100];
	int filedes;

	if ((filedes = open("junk.dat",O_RDWR|O_CREAT, S_IRUSR| S_IWUSR )) == -1 ) {
		perror("file open failed");
	}


	for (i=0; i<100; i++)
		buf[i] = 'e';

	write(filedes, buf, 100);

	lseek(filedes, 20, SEEK_SET);

	write(filedes, "O", 1);

	close(filedes);

	exit(0);
}
