#include <unistd.h>
#include <stdio.h>
int main()
{
	for(;;){
		sleep(1); 
		printf("I am alive!\n");
	}
}
