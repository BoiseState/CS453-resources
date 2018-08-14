
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

void fun(int (*fn)(int x)) {
	int result;
	
	result = (*fn) (5);
	printf("result = %d\n", result);
}

int main(int argc, char **argv){
	int i;
	int count=0;
	int (*names[3])(int n);

	names[0] = foobar0;
	names[1] = foobar1;
	names[2] = foobar2;

	if (argc != 2) {
		fprintf(stderr,"Usage %s: <count>\n",argv[0]);
		exit(1);
	}
	count = atoi(argv[1]);

	for (i=0; i<count; i++) {
		fun(names[random()%3]);
	}

	exit(0);
}

