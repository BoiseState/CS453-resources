
/* ch2/sig-handler.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

void ourhandler(int signo);

int main() {
    printf("Try to stop me...I dare you!\n");
    fflush(stdout);

    signal(SIGTSTP, ourhandler); // CTRL+Z
    signal(SIGINT, ourhandler);  // CTRL+C

    while(1); // run forever

    exit(EXIT_SUCCESS);
}

/**
 * Ignores CTRL+C and CTRL+Z (and prints an annoying message).
 */
void ourhandler(int signo) {
    printf("Haha! You can't stop me with signal %s!!\n", strsignal(signo));
}
