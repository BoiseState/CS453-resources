#include    "common.h"


int main(void)
{
    int fifo1, fifo2;
    char *request, *reply;
    int count, status;
    long int randvalue;


    request = (char *) malloc (sizeof(char)*PIPE_BUF); // PIPE_BUF defined in limits.h
    reply = (char *) malloc (sizeof(char)*PIPE_BUF); // PIPE_BUF defined in limits.h

    fifo1 = open("fifo-request", O_WRONLY);
    if (fifo1 < 0) {
        perror("fifo-client: cannot open fifo-request");
        fprintf(stderr, "fifo-client: is the fifo-server running?\n");
        exit(EXIT_FAILURE);
    }
    fifo2 = open("fifo-reply", O_RDONLY);
    if (fifo2 < 0) {
        perror("fifo-client: cannot open fifo-reply");
        fprintf(stderr, "fifo-client: is the fifo-server running?\n");
        exit(EXIT_FAILURE);
    }

    count = 0;
    for (;;) {
        randvalue = random() % 4;
        if (randvalue == 0)
            strcpy(request, "I need some money!");
        else
            strcpy(request, "Hello parent!");
        printf("%schild[%3d]: %s\n", red, count, request);
        status = write(fifo1, request, strlen(request));
        if (status == 0) break;
        memset(request, 0, PIPE_BUF);
        status = read(fifo2, reply, PIPE_BUF);
        printf("%sparent[%3d]: %s\n", blue, count, reply);
        if (status == 0) break;
        memset(reply, 0, PIPE_BUF);
        sleep(1);
        count++;
    }

    printf("%s", none);
    exit(EXIT_SUCCESS);
}
