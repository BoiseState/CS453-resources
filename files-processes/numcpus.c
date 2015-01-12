
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() 
{
	printf("number of CPUs = %ld\n", sysconf(_SC_NPROCESSORS_CONF));
	exit(EXIT_SUCCESS);
}
