/* Compile using -E flag to see pre-processed output.
 *
 * gcc -E debug.c
 *
 * Now, pass in a DEBUG define flag to the compiler and compare the output.
 *
 * gcc -E -DDEBUG debug.c
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * The following debug macros are basic implementation of debugging and error
 * handling in C to be used for pre-processor demonstration.
 *
 * ... is used for variable argument lists (var args)
 * \ means continue on next line
 * __FILE__, __LINE__, ##__VA_ARGS__, and __func__ are magic constants
 */
#ifdef DEBUG
#define debug(M, ...) fprintf(stderr, "[DEBUG] %s:%d: " M "\n", __FILE__,\
			      __LINE__, ##__VA_ARGS__)
#else
#define debug(M, ...)
#endif

#define log_info(M, ...) fprintf(stderr, "[INFO] %s:%d: " M "\n", __FILE__,\
			     __LINE__, ##__VA_ARGS__)
#define log_error(M, ...) fprintf(stderr, "[ERROR] %s:%d: " M "\n", __FILE__,\
			      __LINE__, ##__VA_ARGS__)
void doSomething();

int main(int argc, char **argv)
{
	debug("file: %s", __FILE__);
	debug("line: %d", __LINE__);
	log_info("date compiled: %s", __DATE__);
	log_info("time compiled: %s", __TIME__);
	log_error("something is not right in: %s", __func__);

	doSomething(0);

	return 0;
}

void doSomething(int j)
{
	debug("we are doing something in: %s", __func__);

	int i = 0;
	if(i == j) {
		log_error("This wasn't supposed to happen (%d == %d)", i, j);
		exit(1);
	}
	log_info("Everything looks good here.");
}
