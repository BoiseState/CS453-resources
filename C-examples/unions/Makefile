
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
CFLAGS=-Wall -Wconversion -g  

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
all: union1

# Another rule below. This depends upon the rule hello.o but we don't
# have any such rule. However make recognizes the suffix .o and uses
# the .c.o rule above to locate the hello.c file and builds the hello.o
# using the .c.o rule.
union1: union1.o
	$(CC) $(CFLAGS) $< -o $@


# A rule that all Makefiles should have. This one removes
# any .o files and other undesirables that are  lying around and 
# the executable hello and leaves only the source. Useful for running 
# before submitting a program!
clean:
	/bin/rm -f *.o union1  a.out core
