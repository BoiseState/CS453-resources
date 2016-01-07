
/*
 * Create a file with a large hole in it. Check to see if the
 * system actually stores the hole or not.
 * 
 * To compile:
 * 		make seek2
 * 		
 * 	To run and check results:
 * 		seek2
 */ 

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
	struct stat statbuf;

	if ((filedes = creat("hole.dat", S_IRUSR| S_IWUSR )) == -1 ) {
		perror("file open failed");
	}

	for (i=0; i<100; i++)
		buf[i] = 'e';

	write(filedes, buf, 100);

	lseek(filedes, 2000000, SEEK_SET);

	write(filedes, buf, 100);

    if (fstat(filedes, &statbuf) == -1) {
			perror("stat failed");
			exit(1);
	}
	printf("File size (in bytes) = %ld\n",statbuf.st_size);
	printf("No. of 1KB blocks allocated = %ld\n", statbuf.st_blocks/2);

	close(filedes);
	exit(0);
}
