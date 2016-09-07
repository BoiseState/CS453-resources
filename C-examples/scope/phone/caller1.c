#include <stdio.h>
#include <unistd.h> /* sleep */
#include <stdbool.h>
#include "caller.h"
#include "phone.h"

#define DEBUG 1
// Or use -DDEBUG=1 to set during compile time.

int main(int argc, char *argv[])
{
	bool goAhead = true;

#if DEBUG == 2
	printf("debug: goAhead = %d\n", goAhead);
#endif

	if(goAhead == true) {
		makeSomeCalls();
	}
	return 0;
}

void makeSomeCalls()
{
	callMe("maybe");
	callMe("I just met you");
	callMe("maybe");

	forever {
#ifdef DEBUG
		printf("debug: Sleeping...");
#endif
		sleep(1);
		callMe("hello");
	}
}
