
#---------------------------------------------------------------
# Using this Makefile
#
#   To compile your C source and produce the executable for
#   all files listed in this Makefile
#
#   make
#
#   To compile and link only one file, e.g. hello, use
#
#	make  hello
#
#   To clean up your directory (e.g. before submission)
#
#   make clean
#
#---------------------------------------------------------------



# The following are macros: a defintion on one line with an equal
# to sign. The CC macro is used to define the C compiler and the
# macro CFLAGS defines the default set of options or flags used
# with the C compiler.
CC=gcc
CFLAGS=-Wall -g

# Recognize files with .c and .o extensions
.SUFFIXES: .o .c

# This is a rule to convert a file with .c extension
# into a file with a .o extension. The macro $< just
# supplies the name of the file (without the extension)
# that invoked this rule.
.c.o:
	$(CC) $(CFLAGS) -c $<

# The following is a dependency or a rule line. It has the
# name of the rule followed by a colon. After the colon are listed
# other rules that this rule depends upon. Following the rules line
# are one or more command lines that must start with a TAB character.
all: pointers1 pointers2 1d-arrays 2d-arrays pointer-types array-swap\
	array-bounds swap

# Another rule below. This depends upon the rule hello.o but we don't
# have any such rule. However make recognizes the suffix .o and uses
# the .c.o rule above to locate the hello.c file and builds the hello.o
# using the .c.o rule.
pointers1: pointers1.o
	$(CC) $(CFLAGS) $< -o $@

pointers2: pointers2.o
	$(CC) $(CFLAGS) $< -o $@

1d-arrays: 1d-arrays.o
	$(CC) $(CFLAGS) $< -o $@

2d-arrays: 2d-arrays.o
	$(CC) $(CFLAGS) $< -o $@

3d-arrays: 3d-arrays.o
	$(CC) $(CFLAGS) $< -o $@

pointer-types: pointer-types.o
	$(CC) $(CFLAGS) $< -o $@

array-swap: array-swap.o
	$(CC) $(CFLAGS) $< -o $@

array-bounds: array-bounds.o
	$(CC) $(CFLAGS) $< -o $@

swap: swap.o
	$(CC) $(CFLAGS) $< -o $@

overflow: overflow.o
	$(CC) $(CFLAGS) $< -o $@


# A rule most that all Makefiles should have. This one removes
# any .o files and other undesirables that are  lying around and
# the executable hello and leaves only the source. Useful for running
# before submitting a program!
clean:
	/bin/rm -f *.o pointers1 pointers2 1d-arrays 2d-arrays 3d-arrays pointer-types array-swap array-bounds a.out core swap overflow
