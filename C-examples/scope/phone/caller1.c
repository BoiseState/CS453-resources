#include <stdio.h>
#include <unistd.h> /* sleep */
#include "phone.h"
#include "caller.h"

int main(int argc, char *argv[])
{
	enum boolean goAhead = TRUE;

#if DEBUG == 2
	printf("debug: goAhead = %d\n", goAhead);
#endif

	if(goAhead == TRUE) {
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
		sleep(1);
		callMe("hello");
	}
}
