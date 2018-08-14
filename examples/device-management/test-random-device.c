

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char **argv) {

	int fd;
	int i, iterations;
	int count;
	unsigned int randomvalue;
	
	if (argc != 2) {
		printf("Usage: %s <n> \n",argv[0]);
		printf("        where <n> is the number of random values desired\n");
		exit(1);
	}
                
	iterations = atoi(argv[1]);

	// The device /dev/urandom will always give back as many bytes
	// as we ask for but they are not as random as /dev/random
	/*fd = open("/dev/urandom",O_RDONLY);*/
	
	/*for (i=0; i<iterations; i++) {*/
		/*count = read(fd, &randomvalue, sizeof(unsigned int));*/
		/*printf("read %d bytes, random value = %u\n", count, randomvalue);*/
	/*}*/
	printf("----------------------------------------------------\n");
 

	// /dev/random will stop after giving as many bytes as it has accumulated...so 
	// if there isn't enough entropy in the system, then we may not get back as many 
	// bytes as we want.
	fd = open("/dev/random",O_RDONLY);

	for (i=0; i<iterations; i++) {
		count = read(fd, &randomvalue, sizeof(unsigned int));
		printf("read %d bytes, random value = %u\n", count, randomvalue);
	}
	printf("----------------------------------------------------\n");
	exit(0);
}
 
