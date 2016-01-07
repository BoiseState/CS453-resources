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
	char		*src;
	struct stat	statbuf;
	char *buf1, *buf2;
	long size;
	int i;

	if (argc != 2)
		err_quit("usage: %s.out <datafile> ", argv[0]);

	if ( (fdin = open(argv[1], O_RDWR)) < 0)
		err_sys("can't open %s for reading/writing", argv[1]);

	if (fstat(fdin, &statbuf) < 0)	/* need size of input file */
		err_sys("fstat error");


	if ( (src = mmap(0, statbuf.st_size, PROT_READ | PROT_WRITE,
					 MAP_FILE | MAP_SHARED, fdin, 0)) == (caddr_t) -1)
		err_sys("mmap error for input");

	size = statbuf.st_size;
	buf1 = (char *) malloc(sizeof(char)*BUFSIZE);
	buf2 = (char *) malloc(sizeof(char)*BUFSIZE);
	for (i=0; i<BUFSIZE-1; i++)
			buf2[i] = 'e';
	buf2[BUFSIZE-1] = '\n';

	for (i=0; i<ITERATIONS; i++)
	{
		long offset = random() %  (size - BUFSIZE);
		memcpy(buf1, src+offset, BUFSIZE);
		memcpy(src+offset, buf2, BUFSIZE);
	}

	/*Call mysnc() to force flushing data to disk */
	msync(src, size, MS_SYNC);

	exit(0);

}
