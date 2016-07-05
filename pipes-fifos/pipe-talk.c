#include "common.h"

/**
 * A parent child talk session using a pipe. Feel free to expand on this program!
 * @author amit
 */


static void do_parent();
static void do_child();

int count = 0;
char *str1 = "hello child";
char *str2 = "hello parent";
char *responses[] = {"Please tell me more.",
                     "Are you sure?",
                     "Why do you think that?",
                     "Why do you feel like that?",
                     "I am not sure I understand. Please explain again.",
                     "I hope things will get better for you",
                     "Can't you be more positive?",
                     "Are such questions on your mind often?",
                     "Please don't repeat yourself!",
                     "Perhaps you don't want to.",
                     "Why not?",
                     "Do you dream often?",
                     "I see.",
                     "Tell me about your problems.",
                     "Tell me more.",
                     "What makes you think like that?",
                     "Do you often feel like this?",
                     "It is a pleasure to talk to you.",
                     "How are you?",
                     "I am fine.",
                     "Don't bother me."
                    };
const int RESPONSE_LENGTH = 21;
const int TALK_LENGTH = 10;
int pipe_parent[2], pipe_child[2];
char    line[MAXLINE];


int main(void)
{
    pid_t   pid;

    if (pipe(pipe_parent) < 0)
        err_sys("pipe error");
    if (pipe(pipe_child) < 0)
        err_sys("pipe error");

    if ((pid = fork()) < 0)
        err_sys("fork error");

    else if (pid > 0) {     /* parent */
        close(pipe_parent[0]); /* close read end of pipe */
        close(pipe_child[1]); /* close write end of pipe */
        do_parent();
    } else {                /* child */
        close(pipe_parent[1]); /* close write end of pipe */
        close(pipe_child[0]); /* close read end of pipe */
        do_child();
    }
    exit(EXIT_SUCCESS);
}


/**
 * The parent process for the chat session.
 */
static void do_parent()
{
    int index, i;
    srandom(getpid());
    while (TRUE) {
        sleep(1);
        if (count == 0) {
            write(pipe_parent[1], str1, strnlen(str1, MAXLINE));
        } else {
            index = random() % RESPONSE_LENGTH;
            write(pipe_parent[1], responses[index] , strnlen(responses[index], MAXLINE));
        }
        sleep(1);
        read(pipe_child[0], line, MAXLINE);
        printf("%schild[%d]: %s%s\n", blue, count, line, none);
        if (strcmp(line, "bye") == 0) {
            break;
        }
        count++;
        if (count == TALK_LENGTH) {
            printf("parent[%d]: My time is exhausted. Bye.\n", count);
            break;
        }
        for (i=0; i<MAXLINE; i++) line[i] = 0;
    }
}


/**
 * The child process for the chat session.
 */
static void do_child()
{
    int index, i;
    srandom(getpid());
    while (TRUE) {
        sleep(1);
        read(pipe_parent[0], line, MAXLINE);
        printf("%sparent[%d]: %s%s\n", red, count, line, none);
        sleep(1);
        if (strncmp(line, "bye", MAXLINE) == 0) {
            break;
        }
        count++;
        if (count == TALK_LENGTH) {
            printf("child[%d]: My friends are here. Bye.\n", count);
            write(pipe_child[1], "bye", 4);
            break;
        }
        for (i=0; i<MAXLINE; i++) line[i] = 0;
        if (count == 0) {
            write(pipe_parent[1], str2, strnlen(str2, MAXLINE));
        } else {
            index = random() % RESPONSE_LENGTH;
            write(pipe_child[1], responses[index], strnlen(responses[index], MAXLINE));
        }
    }
}
