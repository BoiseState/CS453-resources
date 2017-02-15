#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int count = 0;

	fprintf(stderr, "loop: starting up.\n");
    for(;;) {
		if (count % 100 == 0) {
            fprintf(stderr, "loop: hello, I am still alive.\n");
		}
		sleep(1);
		count++;
    }
}
