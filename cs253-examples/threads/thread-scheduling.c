
/* To compile this program under Linux
 *
 * gcc threads-hello-world.c -lpthread -lm
 *
 * Creates two threads that compute for a long time. Good way
 * to check how threads are scheduled on a two-cpu machine.
 *
*/

#include <pthread.h>
#include <math.h>


main()
{
    pthread_t thread1, thread2;
    void compute_until_hell_freezes();

    pthread_create( &thread1, NULL,
                    (void*)&compute_until_hell_freezes, NULL);
    pthread_create(&thread2, NULL,
                   (void*)&compute_until_hell_freezes, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    exit(0);
}

void compute_until_hell_freezes()
{
    int i;
    double tmp;

    for (i=0; i<90000000; i++) {
        tmp = sqrt((double) i);
    }
}
