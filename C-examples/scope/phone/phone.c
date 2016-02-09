#include <stdio.h>
#include <unistd.h> /* sleep */
#include "phone.h"

void callMe(char *message)
{
	static int count = 0;
	count++; /* Increment count every time I'm called */

	if(count <= MAX_CALLS) {
		printf("\twoohoo! I've been called %d times :D\n", count);
	} else {
		printf("\tOkay, I've been called %d times. You can stop now.\n", count);
	}

	printf("%s\n", message);
}
