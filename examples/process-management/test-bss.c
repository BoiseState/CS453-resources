#include <unistd.h>
#include <stdlib.h>

int a[100000000];

int main()
{
	int i;

	system("free");
	for (i=0; i<100000000; i++)
		a[i] = i*i;

	system("free");
	sleep(100);
	exit(0);
}
