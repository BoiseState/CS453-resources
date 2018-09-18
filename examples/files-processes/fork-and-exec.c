
/* ch2/fork-and-exec.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
void err_sys(char *msg);

/**
 * Builds google search url to be passed as argument when launching
 * google-chrome.
 */
char *buildQueryUrl(char *term)
{
    char *searchUrl= "https://www.google.com/search?q=";
    char *query = malloc(sizeof(char) * (strlen(searchUrl)+1 + strlen(term)+1));
    strcpy(query, searchUrl);
    strcat(query, term);
    return query;
}

int main(int argc, char *argv[])
{
    pid_t   pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {  /* child */
        if(argc == 1) {
            execlp("./print-pid","print-pid",(char *) NULL);
        } else if(argc == 2) {
            char *url = buildQueryUrl(argv[1]);
            //execlp("google-chrome","google-chrome", "--new-window", url, (char *) NULL);
            execlp("gvim","gvim", argv[1], (char *) NULL); 
        }
        err_sys("exec failed");
        exit(EXIT_FAILURE);
    }
    printf("Created child with pid %d\n",pid);

    /* parent continues concurrently with child */

    printf("Parent waiting for child to finish...\n");
    /* wait for normal termination of child process */
    if (waitpid(pid, NULL, 0) != pid) {
        err_sys("waitpid error");
    }
    printf("Parent exiting\n");
    exit(EXIT_SUCCESS);
}

void err_sys(char *msg)
{
    fprintf(stderr, msg);
    fflush(NULL); /* flush all output streams */
    exit(EXIT_FAILURE); /* exit abnormally */
}
