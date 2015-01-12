#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define BUFSIZE 32

const int SEED = 1234;

int main(int argc, char **argv)
{
    struct random_data *rdata = (struct random_data *) malloc(sizeof(struct random_data));
    char *statebuf = (char*) malloc(sizeof(char) * BUFSIZE);

    int32_t value;

    initstate_r(SEED, statebuf, BUFSIZE, rdata);
    int status = random_r (rdata, &value);
    if(status != 0)
    {
        perror("random_r");
        exit(status);
    }

    printf("%d\n", value);
    exit(0);
}
