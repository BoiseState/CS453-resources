#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/* Snooze button */
static void onalarm(int signo);

/*
 * Demonstrates basic alarm usage.
 *
 * @author CS253 Instructors
 */
int main()
{
    signal(SIGALRM, onalarm);      // Timer/alarm
    alarm(5);                      // Set the timer for 5 secs

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
    printf("I'm awake!\n"); fflush(stdout);
    printf("I'm going to take another nap....\n"); fflush(stdout);
    alarm(5);
}
