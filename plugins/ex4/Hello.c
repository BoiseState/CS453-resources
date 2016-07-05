/* Hello.c
 * Modified by Marissa Hollingsworth to demonstrate independent
 * thread access of global variables when each thread loads a
 * copy of the same library.
 *
 * The global variable x is modified with calls to message2()
 * and message3().
 */

#include <stdio.h>
#include <pthread.h>

int x = 1;

void message1()
{
    printf("[%X] Hello World! \n", pthread_self());
}

/* message2 and 3 demonstrate that */
void message2()
{
    printf("[%X] I can count to three!! %d", pthread_self(),x);
    x++;
    printf(" %d\n", x);
}

void message3()
{
    x++;
    printf("[%X] and %d!!\n", pthread_self(),x);
}

