#include    "common.h"


int main(void)
{
    pid_t pid;
    int fifo1, fifo2;
    int status;
    char *request, *reply;


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

    if ((pid = fork()) < 0)
        err_sys("fork error");

    else if (pid > 0) {     /* parent */
        fifo1 = open("fifo-request", O_RDONLY);
        fifo2 = open("fifo-reply", O_WRONLY);
        read(fifo1, request, PIPE_BUF);
        printf("parent read: %s\n", request);
        if (strstr(request, "money"))
            strcpy(reply, "Shoo away!");
        else
            strcpy(reply, "Hello child!");
        write(fifo2, reply, strlen(reply));

    } else {                /* child */
        fifo1 = open("fifo-request", O_WRONLY);
        fifo2 = open("fifo-reply", O_RDONLY);
        strcpy(request, "I need some money!");
        write(fifo1, request, strlen(request));
        read(fifo2, reply, PIPE_BUF);
        printf("child read: %s\n", reply);
    }

    unlink("fifo-request");
    unlink("fifo-reply");
    exit(EXIT_SUCCESS);
}
