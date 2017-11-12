#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>
#include "Exception.h"

#define STACK_SIZE 20

jmp_buf env_stack [STACK_SIZE];
int env_index=0;

#define try(Exception) if ((Exception->error=(char *)setjmp(push_env()))==0)
#define catch else

void *pop_env();
void *push_env();

/*****************************************************************************
 * NewException() */
Exception *NewException()
{
    Exception *e=(Exception *)malloc(sizeof(Exception));
    if (e == NULL) fatal("NewException(): out of memory.");
    return e;
}/*NewException()*/

/*****************************************************************************
 * PrintStackTrace() */
void PrintStackTrace(Exception *e)
{
    /* TODO: Really print the stack trace. */
    printf("%s\n", e->error);
}/*PrintStackTrace()*/

/*****************************************************************************
 * throw() */
void throw(char *errmsg)
{
    if (env_index == 0) {
        fprintf(stderr, "throw(%s)\n\t This exception is uncaught.\n", errmsg);
        exit(1);
    }
    longjmp(pop_env(), (int)errmsg);
}/*throw()*/

/*****************************************************************************
 * fatal() */
void fatal(char *msg)
{
    fprintf(stderr, msg);
    exit(1);
}/*fatal()*/

/*****************************************************************************
 * push_env() */
void *push_env()
{
    if (env_index >= STACK_SIZE)
        fatal("Exception: push_env(): stack overflow");
    return (void *)env_stack[env_index++];
}/*push_env()*/

/*****************************************************************************
 * pop_env() */
void *pop_env()
{
    if (env_index == 0)
        fatal("Exception: pop_env(): stack underflow");
    return (void *)env_stack[--env_index];
}/*pop_env()*/

/*****************************************************************************
 * main() */
int main(int argc, char **args)
{
    Exception *e1=NewException();
    Exception *e2=NewException();

    try(e1) {
        try(e2) {
            printf("\nThrowing inner exception...\n");
            throw("Error: BARF1!");
            printf("Shouldn't be here!\n");
        } catch {
            printf("Caught exception.\n");
            printf("%s\n\n", e2->error);
        }
        printf("Throwing next exception...\n");
        throw("Error: BARF2!");
        printf("Shouln't be here!\n");
    } catch {
        printf("Caught exception.\n");
        PrintStackTrace(e1);
    }
    return 0;
}
