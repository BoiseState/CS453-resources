
/*
 * Create a file with a large hole in it. 
 *
 * Or use (for a 100 MB file)
 *
 *  dd if=/dev/zero of=pseudo-device.img bs=1024 count=1048576
 * 		
 * 	To run and check results:
 * 		create-empty-file <size in MB>
 */ 

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

int main(int argc, char **argv)
{
 	int size;	
	char buf[BUFSIZE];
	int filedes;
	struct stat statbuf;
	int i;


	if (argc != 2) {
		fprintf(stderr, "Usage: %s <size in MB>\n", argv[0]);
		exit(1);
	} 
	size = atoi(argv[1]) * 1024 * 1024; // size in bytes

	if ((filedes = creat("pseudo-device.img", S_IRUSR| S_IWUSR )) == -1 ) {
		perror("file open failed");
	}

	lseek(filedes, size , SEEK_SET);

	// write junk at the end to actually get file size set
	for (i = 0; i < BUFSIZE; i++) {
		buf[i] = '1' ;
	}
	write(filedes, buf, BUFSIZE);

    if (fstat(filedes, &statbuf) == -1) {
			perror("stat failed");
			exit(1);
	}
	printf("File size (in bytes) = %ld\n",statbuf.st_size);
	printf("No. of 1KB blocks allocated = %ld\n", statbuf.st_blocks/2);

	close(filedes);
	exit(0);
}
