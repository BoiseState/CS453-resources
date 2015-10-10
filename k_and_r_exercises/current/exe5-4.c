#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strend(char* s, char* t);

int main(int argc, char ** argv) {
	//printf("I execute");
	int result = strend(argv[1], argv[2]);
	printf("result is: %d\n", result);
	return 0;
}

/**
 * Returns 1 if the string t occurs at the end of the string s, and zero
 * otherwise.
 *
 */
int strend(char* s, char* t) {

//char endOfS = *(strlen(s) - strlen(t)); // s = "foobar", t = "bar";
//strlen(s) - strlen(t) = 6 - 3 = 3; s[3] = b.

//printf("I execute in the beginning %d", 1);

int result = 0;
char* endOfS = (char*) malloc(sizeof(char)*strlen(t));
char* tempOfS = endOfS;
char* tempOfT = t;
//printf("I execute in the middle.");
printf("Strlen(s) is: %d\n", strlen(s));
printf("Strlen(t) is: %d\n", strlen(t));

int i = 0;

while (*s != '\0') {
	//printf("I execute");
	printf("RHS = %c", *(s+strlen(s)-strlen(t)));
	*endOfS = *(s +(strlen(s) - strlen(t)) + i);
	endOfS++;
	s++;
	i ++;
}
endOfS = tempOfS;
int boolCount = 0;
while (*t != '\0') {
	printf("t = %c\n", *t);
	printf("endOfS = %c\n", *endOfS);
	if (*t == *endOfS) {
		boolCount++;
	}
	t++;
	endOfS++;
}
t = tempOfT;
printf("Strlen(t) is: %d\n", strlen(t));
printf("Boolean Count is: %d\n", boolCount);
if (boolCount == strlen(t)) {
	result = 1;
}
free(tempOfS);
return result;

}
