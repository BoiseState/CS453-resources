#include <stdio.h>
#include <unistd.h> /* sleep */

// Or use -DDEBUG=1 to set during compile time.
/* #define DEBUG 1 */

#define forever for(;;)
#define MAX_CALLS 5

#define boolean enum bool
enum bool { FALSE, TRUE };

void callMe(char *message);
void makeSomeCalls();

int isIt()
{
	return 0;
}

int main(int argc, char *argv[])
{
	boolean goAhead = 3;

#if DEBUG == 2
	printf("debug: goAhead = %d\n", goAhead);
#endif

	if(goAhead == TRUE) {
		makeSomeCalls();
	}
	if(isIt()) {
	}
    return 0;
}



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
