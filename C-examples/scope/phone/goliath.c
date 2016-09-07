#include <stdio.h>
#include <unistd.h> /* sleep */

#define DEBUG 1
// Or use -DDEBUG=1 to set during compile time.

#define forever for(;;)
#define MAX_CALLS 5

/* define a new bool type (or we can include stdbool.h since C'11) */
typedef enum boolean bool;
enum boolean { FALSE, TRUE };

/*
 * Send the specified message to the phone. Keeps track of the total number
 * of calls received.
 * @param message The message to send to the phone.
 */
void callMe(char *message);
void makeSomeCalls();

int main(int argc, char *argv[])
{
	bool goAhead = TRUE;

#if DEBUG == 2
	printf("debug: goAhead = %d\n", goAhead);
#endif

	if(goAhead == TRUE) {
		makeSomeCalls();
	}

	return 0;
}

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
