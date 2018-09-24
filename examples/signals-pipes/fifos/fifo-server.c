#include	"common.h"

void cleanup(int) ;
void resume(int) ;

int main(int argc, char **argv)
{
	int fifo1, fifo2;
	int status;
	char *request, *reply;
	int count;
	int debug = 0;

	if (argc > 1) {
		if (strncmp(argv[1],"debug", 5) == 0) {
			debug = 1;
		}
	}

	request = (char *) malloc (sizeof(char)*PIPE_BUF); // PIPE_BUF defined in limits.h
	reply = (char *) malloc (sizeof(char)*PIPE_BUF); // PIPE_BUF defined in limits.h

	status = mkfifo("fifo-request", 0600); // read/write by user's processes
	if (status < 0) {
		perror("hello-fifo");
	}
	status = mkfifo("fifo-reply", 0600); // read/write by user's processes
	if (status < 0) {
		perror("hello-fifo");
	}
	signal(SIGINT, cleanup); // call cleanup if user kills us
	signal(SIGPIPE, resume);

	fifo1 = open("fifo-request", O_RDONLY);
	fifo2 = open("fifo-reply", O_WRONLY);

	count = 0;
	for (;;) {
		memset(request, 0, PIPE_BUF);
		status = read(fifo1, request, PIPE_BUF);
		printf("server: received request from a client\n");
		if (status == 0)  {
			fprintf(stderr, "server: server lost the client connection\n");
			sleep(2); // used for simplicity, there are better ways of doing this!
			continue;
		}
		if (debug) {
			printf("%sclient[%d]: %s\n", red, count, request); // see example color.c for the color stuff
			printf("%s", none);
		}

		if (strstr(request, "money"))
			strcpy(reply, "Shoo away!"); //safer to use strncpy
		else 
			strcpy(reply, "Hello child!"); //safer to use strncpy


		if (debug) {
			printf("%sserver[%d]: %s\n", blue, count, reply);
			printf("%s", none);
		}
		status = write(fifo2, reply, strnlen(reply, PIPE_BUF)); //safer to use strnlen
		printf("server: sent reply to client\n");
		if (status == 0)  {
			fprintf(stderr, "server: server lost the client connection\n");
			sleep(2); // used for simplicity, there are better ways of doing this!
			continue;
		}
		memset(reply, 0, PIPE_BUF);
		count++;
	}

	printf("%s", none);
	unlink("fifo-request");
	unlink("fifo-reply");
	exit(EXIT_SUCCESS);
}


void cleanup(int signo) 
{
	printf("\nfifo-server: cleaning up....\n");
	unlink("fifo-request");
	unlink("fifo-reply");
	exit(EXIT_SUCCESS);
}


void resume(int signo)
{
	printf("Caught SIGPIPE!\n");
}
	
