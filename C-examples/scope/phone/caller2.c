#include <stdio.h>
#include "caller.h"
#include "phone.h"

/* scope is limited to this file */
static long id = 987654;

/* what if I want to keep track of my total_calls too? */
/* what if I want to stop the phone from sleeping when I call too much? */

int main(int argc, char *argv[])
{
	whoami();
	make_calls(100);
	return 0;
}

void whoami()
{
	printf("Yo, what's up? I'm caller #%ld\n", id);
}

void make_calls(const int n)
{
	int i;
	for(i = 0; i < n; i++) {
		call("Hello from the other side.", i);
	}
}
