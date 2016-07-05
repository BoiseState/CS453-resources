/**
   ch2/ pow2Tester.c

   A times power of two test taking program for humans

   @author Jeff Cope

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void printUsage(char *progName);
void onAlarm(int signo);
void printStats();

int count, correct;

int main(int argc, char **argv)
{
    int maxLen = 33;
    char *sVal;
    int randVal;
    int seed = 0;
    int timeVal = 30;
    int modVal = 17;
    count = correct = 0;
    if (argc > 1) {
        timeVal = atoi(argv[1]);
        if (argc > 2) {
            seed = atoi(argv[2]);
            if (argc > 3)
                modVal = atoi(argv[3]);
        }
    } else {
        printUsage(argv[0]);
        exit(EXIT_FAILURE);
    }

    if (seed <= 0)
        seed = time(0);
    if (modVal <= 0 && modVal >= 32)
        modVal = 17;

    srandom(seed);
    sVal = (char *)malloc(maxLen*sizeof(char));
    randVal = (int)(random()%modVal);

    if (timeVal > 0) {
        if (signal(SIGALRM, onAlarm) == SIG_ERR) {
            fprintf(stderr, "Error setting up signal handler\n");
            exit(EXIT_FAILURE);
        }
        alarm(timeVal);
    }

    fprintf(stdout, "What is the value of 2^%d? > ", randVal);
    while (fgets(sVal, maxLen, stdin) && (atoi(sVal) != 0)) {
        fprintf(stdout, "You entered %s", sVal);
        if (1<<randVal != atoi(sVal)) {
            fprintf(stdout, "INCORRECT!\nActual value of 2^%d is %d\n", randVal, 1<<randVal);
        } else {
            correct++;
            fprintf(stdout, "CORRECT!\n");
        }
        count++;
        randVal = (int)(random()%modVal);
        fprintf(stdout, "What is the value of 2^%d? > ", randVal);
    }
    free(sVal);
    printStats();
    exit(EXIT_SUCCESS);
}

void printUsage(char *progName)
{
    fprintf(stdout, "%s usage: %s <test time> [seed value] [ending power range]\n", progName, progName);
    fprintf(stdout, "\ntest time == 0, no time limit\n");
    fprintf(stdout, "seed value < 1, random seed based on time of day\n");
    fprintf(stdout, "ending power range = n, value between 2^0 .. 2^(n-1)\n");
}

void onAlarm(int signo)
{
    fprintf(stdout, "\n\n------TIME UP! put down your pencils------\n");
    sleep(1);
    printStats();
    sleep(2);
    kill(getpid(), SIGINT);
}

void printStats()
{
    if (count > 0)
        fprintf(stdout, "\ncorrect answers: %d of %d for %d%%\n\n", correct, count, (int)(((float)correct/(float)count)*100));
    else
        fprintf(stdout, "\ncorrect answers: 0 of 0 for 0%%\n\n");
}
