#include <stdio.h>
#include <unistd.h> /* sleep */
#include "phone.h"

/* global scope. available in all files */
int total_calls = 0;

/**
 * Private helper function. Tells the user how excited we are to be receiving
 * a call.
 */
static void handle_call() {
	printf("\twoohoo! I've been called %d times :D\n", total_calls);
}

/**
 * Private helper function. Prevents call overload by putting the
 * phone to sleep.
 */
static void handle_call_overload() {
	printf("\tI've been called %d times. You can stop now.\n", total_calls);

	long phone_sleep_time = SLEEP_TIME;
	while(phone_sleep_time > 0) {
		sleep(1);
		phone_sleep_time--;
	}
}

void call(const char *message, const int id)
{
	printf("[%d] %s\n", id, message);

	total_calls++;

	if(total_calls <= MAX_CALLS) {
		handle_call();
	} else {
		handle_call_overload();
	}
}
