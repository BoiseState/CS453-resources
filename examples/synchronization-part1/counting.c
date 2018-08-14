
/*
 Example for the Bakery problem illustrating the time taken to
 count up to the limit for an unsigned int.
*/

#include <stdio.h>

unsigned int MAX=4294967295U;

int main(void)
{
		unsigned int  i = 0;
		printf("MAX = %u\n",MAX);
		/*for (i=0; i<MAX; i++) {*/
		while(1) {
			   i++;
              if (i % 1000000 == 0)
              	printf("%10u\r",i);
		}
		return 0;
}
