
/* C-examples/scope1.c */

#include <stdio.h>
#include <stdlib.h>

#include "ourhdr.h"

int total = 1;

void f1(int x, double z)
{
    static int counter=0;

    counter++;
    printf("\ncounter in f1() = %d\n", counter);
	total = x + z;
}

void f3()
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

	printf("\nCalling f1 in scope1.c\n");
    f1(n, z);
	printf("\ntotal in scope1.c = %d passing n = %d to f2 in scope2.c\n", total, n);
    f2(n);
	printf("\ntotal in scope1.c after calling f2 from scope2.c = %d\n", total);
    f3();
	printf("\ntotal in scope1.c = %d after calling f3 from scope1.c\n", total);
	printf("\nCalling f1 the second time in scope1.c\n");
    f1(n, z);
	printf("\ntotal in scope1.c = %d after calling f1 the second time\n\n", total);

    return 0; // exit and return successful status back to the shell
}
