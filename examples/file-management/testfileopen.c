
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(void) 
{
	char file[1024];
	FILE *fd;
	long max;
	int i;

	max = sysconf(_SC_OPEN_MAX);
	printf("max open files/user = %ld\n", max);

	for (i=0; i<max*2; i++){
		sprintf(file, "testfiles/%d",i);
		fd = fopen(file,"rb");
		if (!fd) {
			printf("%s\n",strerror(errno));
			break;
		}
		printf("opened file number %d \n", i);
		if (fclose(fd)) printf("close file %s\n",strerror(errno));
	}
	exit(0);
	
}
