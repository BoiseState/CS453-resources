#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

static void ourhandler(int signo);
static void onalarm(int signo);

/*
 * Demonstrates basic signal handler usage.
 *
 * Note: This is for demonstration purposes only. It is generally not a good
 * idea to call printf or getchar() from a signal handler because they are not
 * "safe functions". For a list of "safe functions", see man 7 signal section
 * Async-signal-safe functions.
 *
 * If you really want to kill this, try 'ps -a' to find the process id of this
 * program. Then, use 'kill <pid>' in another terminal to send the kill signal.
 *
 * @author CS253 Instructors
 */
int main()
{
    printf("Try to stop me...I dare you!\n");
    fflush(stdout);

    signal(SIGTSTP, ourhandler);   // CTRL+Z
    signal(SIGINT, ourhandler);    // CTRL+C
    signal(SIGKILL, ourhandler);   // kill <pid> ... try it. Does it do anything?
    signal(SIGALRM, onalarm);      // Timer/alarm
    alarm(5);                      // Set the timer for 5 secs

    while(1) {pause();} // run forever

    exit(EXIT_SUCCESS);
}

/**
 * Ignores CTRL+C and CTRL+Z (and prints an annoying message).
 * @param signo The id of the signal that caused this handler to be called.
 *     (kind of like event.getSource() in Java's ActionListeners)
 */
static void ourhandler(int signo)
{
    printf("Haha! You can't stop me with signal %s!!\n", strsignal(signo));
}

/**
 * Asks the user if they want to give up.
 */
static void onalarm(int signo)
{
    printf("Do you want to give up (y/n)? ");
    if(getchar() == 'y') {
        printf("Okay, goodbye!\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("Alright, try again. Good luck... (try kill -9 %d from another window)\n", 
		        getpid());
    }
}
