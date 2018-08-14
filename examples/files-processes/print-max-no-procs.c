
/* ch2/print-max-no-procs.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

struct rlimit rlim;

int main(void)
{
    getrlimit(RLIMIT_NPROC, &rlim);
    printf("Current number of processes = %d\n", (int) rlim.rlim_cur);
    printf("Maximum number of processes = %d\n", (int) rlim.rlim_max);
    exit(EXIT_SUCCESS);
}

