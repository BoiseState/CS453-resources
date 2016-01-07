
#include <stdio.h>
#include <stdlib.h>

static int A[10000];
static int flag;

int main(int argc, char *argv[])
{
	int i;

	flag = 7;
	printf("flag = %d\n",flag);
	for (i=0; i<10000; i++)
		A[i] = i;
	exit(0);
}
