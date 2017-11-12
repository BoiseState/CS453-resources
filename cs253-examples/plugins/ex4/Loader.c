#include <dlfcn.h>
#include <stdio.h>
#include <pthread.h>
#include "Loader.h"

void *load_library(void *);

int main()
{
    char *hHello = "./Hello.so";
    char *hCopyOfHello = "./CopyOfHello.so";

    /* Create threads with with different library references. */
    pthread_t tHello, tCopyOfHello;
    pthread_create(&tHello, NULL, load_library, (void*) hHello);
    pthread_create(&tCopyOfHello, NULL, load_library, (void*) hCopyOfHello);

    pthread_join(tHello, NULL);
    pthread_join(tCopyOfHello, NULL);
}

void* load_library(void *libRef)
{
    int exitcode = 0, i;
    fMessage fMsg[NMESSAGES];

    /* Open the desired library. */
    HANDLE hHello = dlopen(libRef, RTLD_LAZY);

    /* Check that the library opened. */
    if (!hHello) {
        fprintf(stderr, "[%X] Open: %s\n",pthread_self(), dlerror());
        exitcode = -1;
        goto LABEL_EXIT;
    }

    /* Announce self and library pointer*/
    printf("threadId:%X libraryPtr:%x \n", pthread_self(), hHello);

    /* Load symbols from library. */
    fMsg[0] = (fMessage)dlsym(hHello, "message1");
    fMsg[1] = (fMessage)dlsym(hHello, "message2");
    fMsg[2] = (fMessage)dlsym(hHello, "message3");

    /* Check that the symbols loaded. */
    for(i = 0; i < NMESSAGES; i++) {
        if (!fMsg[i]) {
            fprintf(stderr, "[%X] Msg%i: %s\n",pthread_self(), i, dlerror());
            exitcode = i;
            goto LABEL_EXIT;
        }
    }

    /* Print message pointers. */
    printf("[%X] message1 ptr: %x\n", pthread_self(), &fMsg[0]);
    printf("[%X] message2 ptr: %x\n", pthread_self(), &fMsg[1]);
    printf("[%X] message3 ptr: %x\n", pthread_self(), &fMsg[2]);

    /* Print messages*/
    fMsg[0]();  // Hello World!
    fMsg[1]();  // I can count to three! 1 2
    fMsg[2]();  // and 3!!

LABEL_EXIT:
    /* clean up the library handle. */
    if (hHello)
        dlclose(hHello);

    pthread_exit(NULL);
}
