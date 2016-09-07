#include <stdio.h>
#include <unistd.h> /* sleep */
#include <stdbool.h> /* sleep */
#include "phone.h"

void callMe(char *message)
{
	static int count = 0; /* only initialized on first function call */

	count++; /* increment count every time I'm called */

	printf("%s\n", message);

	if(count <= MAX_CALLS) {
		printf("\twoohoo! I've been called %d times :D\n", count);
	} else {
		printf("\tOkay, I've been called %d times. You can stop now.\n",
		       count);
	}
}
