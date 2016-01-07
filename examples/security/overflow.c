/*
 * Author: Dan Crow (modified by Amit Jain)
 * 
 * File:    overflow.c
 * Purpose: an example of buffer overflow
 * Compile: gcc Wall -o overflow overflow.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char msg[16];
	int pass=0;

	printf("&pass=%p &msg=%p \n", &pass, &msg);
	printf("Enter password: ");
	scanf("%s", msg);
	if (strcmp(msg, "mrh898") == 0) pass=1;

	if (pass)
		printf("You pass!\n");
	else 
		printf("You fail!\n");

	exit(0);
}
