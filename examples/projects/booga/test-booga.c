
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



#define DEV_NAME_SIZE  20

static void run_read_test(char *device, int bufsize)
{    
	char *buf;
	int src;
	int in;

	src = open(device, O_RDONLY);
    if (src < 0) {
		perror("Open failed:");
		exit(1);
	}

	buf = (char *) malloc(sizeof(char)*(bufsize+1));
	in = read(src, buf, bufsize);
    if (in < 0) {
		perror("Read failed:");
		exit(2);
	} else {
		fprintf(stderr, " booga returned %d characters\n", in);
	}

	buf[bufsize]='\0';
	printf("%s\n",buf);
	free(buf);

	close(src);

}/* run_read_test */


static void run_write_test(char *device, int bufsize)
{
	char *buf;
	int src;
	int out;

	src = open(device, O_WRONLY);
    if (src < 0) {
		perror("Open for write failed:");
		exit(1);
	}
	buf = (char *) malloc(sizeof(char)*(bufsize+1));
	fprintf(stderr, "Attempting to write to booga device\n");
	out = write(src, buf, bufsize);
	fprintf(stderr, "Wrote %d bytes.\n", out);
	free(buf);
	close(src);

}/* run_write_test */

static void print_usage(char *program_name)
{
	fprintf(stderr,"Usage: %s <minor number> <buffersize> <read|write>\n",
					program_name);
	exit(1);
}

int main(int argc, char **argv)
{
	int bufsize; 
	char *device;
	int minor;

	if (argc < 4) {
		print_usage(argv[0]);
	}

	device = (char *)malloc(sizeof(char)*DEV_NAME_SIZE);
	strcpy(device, "/dev/booga");
	minor = atoi(argv[1]);
	if ((minor >= 0) && (minor < 4))
		strcat(device, argv[1]);
	else {
		fprintf(stderr,"%s: Invalid minor number: %d :0<= minor# < 4:\n", argv[0], minor);
		exit(1);
	}
	bufsize = atoi(argv[2]);
    if (bufsize < 0) {
		fprintf(stderr, "%s: bufsize must be positive!", argv[0]);
		exit(1);
    }

	if (strncmp(argv[3],"r",1)==0)
		run_read_test(device, bufsize);
	else if (strncmp(argv[3],"w",1)==0)
		run_write_test(device, bufsize);
	else
		print_usage(argv[0]);

    exit(0);
} /* main */

/* vim: set ts=4: */
