
/* C-examples/objects/testAddress.c */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Address.h"

int main(int argc, char *argv[])
{
	Address addr1 = createAddress("Moo Shoo", "123 Main Street", "Boise", 
                                      "Idaho", 83701);
	
	//Address addr1 = createAddress("Moo Shoo", "123 Main Street", "Boise", 
        //                              "Idaho", 83701, printMultiLine);


	/* uses the default printMultiLine */
	printf("%s\n", (*addr1->toString)(addr1));
	/* alternate form in C99: printf("%s\n", addr1->toString(addr1));*/

	addr1->toString = printOneLine;

	printf("%s\n", (*addr1->toString)(addr1));

	return 0;
}
