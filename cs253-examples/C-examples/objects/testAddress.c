
/* C-examples/objects/testAddress.c */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Address.h"

int main(int argc, char *argv[])
{
    Address addr1 = createAddress("Moo Shoo", "123 Main Street", "Boise",
                                  "Idaho", 83701, printOneLine);

    Address addr2 = createAddress("Hee Haw", "123 Main Street", "Boise",
                                  "Idaho", 83701, NULL);


    /* uses the default printMultiLine */
    printf("%s\n", (*addr1->toString)(addr1));

    printf("%s\n", (*addr2->toString)(addr2));

    return 0;
}
