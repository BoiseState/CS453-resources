
/* C-examples/function-pointers/fun-with-fns.c */
#include <stdio.h>
#include <stdlib.h>

int foobar0(int x) {
	printf("I have been invoked!!!! x=%d\n",x);
	return x;
}

int foobar1(int x) {
	printf("I have been invoked!!!! x=%d\n",x*2);
	return x;
}

int foobar2(int x) {
	printf("I have been invoked!!!! x=%d\n",x*3);
	return x;
}

void fun(int (*fn)(int)) {
	int result;
	
	result = (*fn) (5);
}


int main(int argc, char **argv)
{
	int i;
	int count=0;
	int seed;
	int (*names[3])(int);

	names[0] = foobar0;
	names[1] = foobar1;
	names[2] = foobar2;

	if (argc != 3) {
		fprintf(stderr,"Usage %s: <count> <seed> \n",argv[0]);
		exit(1);
	}
	count = atoi(argv[1]);
	seed = atoi(argv[2]);

	srandom(seed);
	for (i=0; i<count; i++) {
		fun(names[random()%3]);
	}

	exit(0);
}

