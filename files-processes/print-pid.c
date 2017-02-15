
/* ch2/print-pid.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("print-pid: after exec pid=%d\n",getpid());
    sleep(5);
    printf("print-pid: finishing up\n");
    exit(EXIT_SUCCESS);
}
