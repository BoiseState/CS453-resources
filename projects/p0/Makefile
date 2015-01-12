#---------------------------------------------------------------
# Using this Makefile
#
#   To compile your C source and produce the executable for
#   all files listed in this Makefile
#
#   make
#
#   To clean up your directory (e.g. before submission)
#
#   make clean
#---------------------------------------------------------------

# The following are macros: a defintion on one line with an equal 
# to sign. The CC macro is used to define the C compiler and the 
# macro CFLAGS defines the default set of options or flags used 
# with the C compiler.
CC=gcc
CFLAGS=-Wall

# This is a rule to compile wordcount.c into the executable
# wordcount. The left hand side (wordcount) is the target 
# and the right hand side (wordcount.c) is the dependency.
# 
# The rule will only execute if the dependency (wordcount.c)
# has been modified since the last make.
# 
# $< evaluates to the dependency name (wordcount.c)
# $@ evaluates to the target name (wordcount)
wordcount: wordcount.c
	$(CC) $(CFLAGS) $< -o $@

# A rule most that all Makefiles should have. This one removes
# the executable (wordcount) and leaves only the source. Useful
# for running before submitting a program!
clean:
	/bin/rm -f wordcount
