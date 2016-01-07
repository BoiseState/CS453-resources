

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



#define BUFSIZE 4096

int main() {
	char buffer[BUFSIZE];

	int fd = open("./README", O_RDONLY);

	/* read the first 80 characters */
	read(fd, buffer, 80);

	printf("%s\n", buffer);
	exit(0);
}
