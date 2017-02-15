#include    "common.h"

void cleanup(int) ;
void resume(int) ;

int main(void)
{
    int fifo1, fifo2;
    int status;
    char *request, *reply;
    int count;


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
        if (status == 0)  {
            fprintf(stderr, "parent: server lost the client connection\n");
            sleep(1); // used for simplicity, there are better ways of doing this!
            continue;
        }
        printf("%schild[%d]: %s\n", red, count, request); // see example color.c for the color stuff
        if (strstr(request, "money"))
            strcpy(reply, "Shoo away!"); //safer to use strncpy
        else
            strcpy(reply, "Hello child!"); //safer to use strncpy

        printf("%sparent[%d]: %s\n", blue, count, reply);
        status = write(fifo2, reply, strnlen(reply, PIPE_BUF)); //safer to use strnlen
        if (status == 0)  {
            fprintf(stderr, "parent: server lost the client connection\n");
            sleep(1); // used for simplicity, there are better ways of doing this!
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

