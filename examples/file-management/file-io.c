#include	<unistd.h>
#include	<sys/stat.h>
#include	<sys/mman.h>	/* mmap() */
#include	<fcntl.h>
#include	"ourhdr.h"

#define BUFSIZE 4096
#define ITERATIONS 10000000

int main(int argc, char *argv[])
{
	int			fdin;
	struct stat	statbuf;
	char *buf1, *buf2;
	long size;
	int i;

	if (argc != 2)
		err_quit("usage: %s <datafile> ", argv[0]);

	if ( (fdin = open(argv[1], O_RDWR)) < 0)
		err_sys("can't open %s for reading/writing", argv[1]);

	if (fstat(fdin, &statbuf) < 0)	/* need size of input file */
		err_sys("fstat error");


	size = statbuf.st_size;
	buf1 = (char *) malloc(sizeof(char)*BUFSIZE);
	buf2 = (char *) malloc(sizeof(char)*BUFSIZE);
	for (i=0; i<BUFSIZE-1; i++)
			buf2[i] = 'e';
	buf2[BUFSIZE-1] = '\n';

	for (i=0; i<ITERATIONS; i++)
	{
		long offset = random() %  (size - BUFSIZE);
		lseek(fdin, offset, SEEK_SET);
		read(fdin, buf1, BUFSIZE);
		write(fdin, buf2, BUFSIZE);
	}
	close(fdin);
	exit(0);
}
