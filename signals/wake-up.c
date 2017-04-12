#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/* Snooze button */
static void onalarm(int signo);

static const int SNOOZE = 3;

/**
 * Demonstrates basic alarm usage.
 */
int main()
{
    signal(SIGALRM, onalarm);      // Timer/alarm handler
    alarm(SNOOZE);                      // Set the timer for n secs

    while(1) {
        printf("Goodnight, sleep tight..zzZZZZZzzz\n");
        fflush(stdout); // force output to display on console
        pause(); //suspend this thread until a signal is received.
                 //sleep() is a bad idea because sleep and alarm use the same
                 //timer (see man 3 sleep)
    }

    exit(EXIT_SUCCESS);
}

static void onalarm(int signo)
{
    printf("I'm awake! I'm going to take another nap....\n");
    fflush(stdout);
    signal(SIGALRM, onalarm);      // reset signal handler
    alarm(SNOOZE); /* reset timer so it will go off again */
}
