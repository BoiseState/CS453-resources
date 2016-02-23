#include <stdio.h>
#include <unistd.h> /* sleep */
#include "caller.h"
#include "phone.h"

int main(int argc, char *argv[])
{
	makeSomeCalls();
    return 0;
}

void makeSomeCalls()
{
	callMe("hello");
}
