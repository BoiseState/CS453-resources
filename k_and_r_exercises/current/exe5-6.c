#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000 /*assume max line is 1000*/

char* getlineWithPointers(char* s);

int main(int argc, char ** argv) {
	
	/*Testing getline()****************************/
	char* s = (char*) malloc(sizeof(char)*MAXLINE);
	s = getlineWithPointers(s);
	printf("I got this line: %s", s);
	free(s);
	/*********************************************/
	
	int expected = atoi("352");
	printf("Expected = %d\n", expected);
	return 0;
}

/**
* Get line into s.
* Returns s. 
* Note, it is reponsibility of a caller to this function to malloc and free
* memory.
*/
char* getlineWithPointers(char* s) 
{
	int c, i;
	char* temp;
	temp = s;
	
	i = 0;
	while ((c=getchar()) != EOF && c!= '\n') {
		*s = c;
		s++;
	}
	if (c == '\n') {
		*s = c;
	s++;
	}
	*s = '\0';
	s = temp;
	return s;
}


