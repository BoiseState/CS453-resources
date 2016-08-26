/* ch2/fork-hello-world.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

void print_message_function( void *ptr );
void err_sys(char *msg);

/* #define DEBUG 1 */

int main(void)
{
    pid_t   pid;
    char *message1 = "Goodbye";
    char *message2 = "World";

#if DEBUG
    printf("\n\nbefore fork\n");
#endif

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {  /* first child */
        print_message_function(message1);
#if DEBUG
        sleep(2);
#endif
        exit(EXIT_SUCCESS);
    }

#if DEBUG
    printf("Created child with pid %d\n",pid);
#endif

    /* parent continues and creates another child */
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {  /* second child */
        print_message_function(message2);
        printf("\n");
#if DEBUG
        sleep(2);
#endif
        exit(EXIT_SUCCESS);
    }
#if DEBUG
    printf("Created child with pid %d\n",pid);
    /*sleep(2);*/
#endif
    exit(EXIT_SUCCESS);
}

void print_message_function( void *ptr )
{
    char *message;
    message = (char *) ptr;
    printf("%s ", message);
    fflush(NULL);
}

void err_sys(char *msg)
{
    fprintf(stderr, msg);
    fflush(NULL); /* flush all output streams */
    exit(EXIT_FAILURE); /* exit abnormally */
}
