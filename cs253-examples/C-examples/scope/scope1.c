
/* C-examples/scope1.c */

#include <stdio.h>
#include <stdlib.h>

#include "ourhdr.h"

/* What happens if we make this static? */
int total = 1;

void setTotalToSum(int x, double z)
{
	static int counter = 0;

	counter++;
	printf("\ncounter in setTotalToSum() = %d\n", counter);

	total = (int) (x + z);
}

void addTenToTotal()
{
	total += 10;
}

int main (int argc, char **argv)
{
	int n;
	double z;

	if (argc != 3) {
		fprintf(stderr,"Usage: %s <int> <double> \n",argv[0]);
		return 1; //exit and return unsuccessful status to the shell
	}
	n = atoi(argv[1]);
	z = atof(argv[2]);

	printf("\nCalling setTotalToSum in scope1.c\n");
	setTotalToSum(n, z);
	printf("\ntotal in scope1.c = %d passing n = %d to addToTotal in scope2.c\n", total, n);
	addToTotal(n);
	printf("\ntotal in scope1.c after calling addToTotal from scope2.c = %d\n", total);
	addTenToTotal();
	printf("\ntotal in scope1.c = %d after calling addTenToTotal from scope1.c\n", total);
	printf("\nCalling setTotalToSum the second time in scope1.c\n");
	setTotalToSum(n, z);
	printf("\ntotal in scope1.c = %d after calling setTotalToSum the second time\n\n", total);

	return 0; // exit and return successful status back to the shell
}
