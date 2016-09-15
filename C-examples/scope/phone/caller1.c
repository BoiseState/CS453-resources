#include <stdio.h>
#include "caller.h"
#include "phone.h"

/* scope is limited to this file */
static long id = 123456;

/* what if I want to keep track of my total_calls too? */
/* int total_calls = 0; */

int main(int argc, char *argv[])
{
	whoami();
	make_calls(100);
	return 0;
}

void whoami()
{
	printf("I am caller #%ld\n", id);
}

void make_calls(const int n)
{
	int i;
	for(i = 0; i < n; i++) {
		call("Hey, I just met you.", i);
		/* what if I want to stop the phone from sleeping when I call too much?
		 * can I modify the phone's global variables?*/
	}
}
