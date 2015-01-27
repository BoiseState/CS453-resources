# Makefile for endian.c
#
# Author: Marissa Schmidt
#         Spring 2014
#-------------------------------------------------------------------------
CC=gcc
CFLAGS=-Wall
TESTEXE=test.sh

# This rule depends on the 'endian' rule. In other words, the 'endian'
# rule will be executed before this rule is executed.
all: endian

# A rule to build endian.c. Resulting executable will be called 'endian'.
endian: endian.c
	$(CC) $(CFLAGS) $< -o $@

# A rule to build the program and execute the test file. Depends on
# 'all' and 'execute' rules.
run: all execute
	./$(TESTEXE)

#Ensure that the test.sh script is executable.
execute:
	chmod +x $(TESTEXE)

# A rule that all Makefiles should have. This one removes
# any .o files and other undesirables that are  lying around and
# the executable endian and leaves only the source. Useful for
# running before submitting a program!
clean:
	/bin/rm -f *.o endian a.out core *.out *.diff
