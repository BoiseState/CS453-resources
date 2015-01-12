
/* C-examples/scope1.c */

#include <stdio.h>
#include <stdlib.h>

#include "ourhdr.h"

int total = 1;

static int f4(int); /* private function */

int f1(int x, double z)
{
	static int counter=0;

	counter++;
	printf("counter in f1() = %d\n", counter);
	x += f4((int) z);
	return (x*z);
}

static int f4(int x)
{
	return 2*x;
}

int subtotal = 0;

void f3()
{
	total += 10;
	subtotal = total;
	if (total < 100)
		total = f1(total, 1.5);
}



int main (int argc, char **argv)
{
	int m;
	double z;
	int x;

    if (argc != 3)
	{
		fprintf(stderr,"Usage: %s <int> <double> \n",argv[0]);
		exit(1); //exit and return unsuccessful status to the shell
	}
	m = atoi(argv[1]);
	z = atof(argv[2]);

	x = f1(m, z);
	f2(m);
	f3();
	x = x + f1(m,z);

	printf("total = %d\n",total);
	printf("subtotal = %d\n",subtotal);

	exit(0); // exit and return successful status back to the shell
}
