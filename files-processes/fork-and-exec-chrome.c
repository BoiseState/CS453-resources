
/* files-processes/fork-and-exec-chrome.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

static char *build_query_url(char *term);

/**
 * Forks off a child process that will open google-chrome with the specified
 * query. Parent will wait for child to terminate before exiting.
 *
 * man 3 execlp
 */
int main(int argc, char *argv[])
{
    pid_t pid;
    int status;

    /* check command line args in parent */
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <\"search query\">\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(errno);
    } else if (pid == 0) {  /* child */
        char *url = build_query_url(argv[1]);
        execlp("google-chrome","google-chrome", "--new-window", url, (char *) NULL);
        /* if we get this far, something is not right */
        perror("exec failed");
        exit(errno);
    }

    /* parent continues concurrently with child */
    printf("Created child with pid %d\n",pid);

    /* wait for normal termination of child process */
    printf("Parent waiting for child to finish...\n");
    if (waitpid(pid, &status, 0) != pid) {
        perror("waitpid");
        exit(errno);
    } else if(WIFEXITED(status)) {
        printf("[%d] child [%d] exited with status %d\n",
               getpid(), pid, WEXITSTATUS(status));
    } else if(WIFSIGNALED(status)) {
        printf("[%d] child [%d] terminated by signal %s\n",
               getpid(), pid, strsignal(WTERMSIG(status)));
    }

    printf("Parent exiting\n");
    exit(EXIT_SUCCESS);
}

/**
 * Builds google search url to be passed as argument when launching
 * google-chrome.
 */
static char *build_query_url(char *term)
{
    char *searchUrl= "https://www.google.com/search?q=";
    char *query = malloc(sizeof(char) * (strlen(searchUrl)+1 + strlen(term)+1));
    strcpy(query, searchUrl);
    strcat(query, term);
    return query;
}
