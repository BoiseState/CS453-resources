
#---------------------------------------------------------------
# Using this Makefile
#
#   To compile your C source and produce the executable for
#   all files listed in this Makefile
#
#   make
#
#   To compile and link only one file, e.g. helloworld, use
#
#	make  helloworld
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
CFLAGS=-Wall -g -Wconversion

# Recognize files with .c and .o extensions
.SUFFIXES: .o .c

# This is a rule to convert a file with .c extension
# into a file with a .o extension. The macro $< just
# supplies the name of the file (without the extension)
# that invoked this rule.
.c.o: 
	$(CC) $(CFLAGS) -c $<

PROGS=helloworld wc1 wc2 wc3 cp1 cp2 cmdline width range count-digits\
	conv printtest static cmdline-str

# The following is a dependency or a rule line. It has the
# name of the rule followed by a colon. After the colon are listed
# other rules that this rule depends upon. Following the rules line 
# are one or more command lines that must start with a TAB character.
all: $(PROGS) subdirs

# Another rule below. This depends upon the rule helloworld.o but we don't
# have any such rule. However make recognizes the suffix .o and uses
# the .c.o rule above to locate the helloworld.c file and builds the
# helloworld.o using the .c.o suffix rule.
helloworld: helloworld.o
	$(CC) $(CFLAGS) $< -o $@

cp1: cp1.o
	$(CC) $(CFLAGS) $< -o $@

cp2: cp2.o
	$(CC) $(CFLAGS) $< -o $@

wc1: wc1.o
	$(CC) $(CFLAGS) $< -o $@

wc2: wc2.o
	$(CC) $(CFLAGS) $< -o $@

wc3: wc3.o
	$(CC) $(CFLAGS) $< -o $@

cmdline: cmdline.o
	$(CC) $(CFLAGS) $< -o $@

width: width.o
	$(CC) $(CFLAGS) $< -o $@

range: range.o
	$(CC) $(CFLAGS) $< -o $@

count-digits: count-digits.o
	$(CC) $(CFLAGS) $< -o $@

conv: conv.o
	$(CC) $(CFLAGS) $< -o $@

printtest: printtest.o
	$(CC) $(CFLAGS) $< -o $@

static: static.o
	$(CC) $(CFLAGS) $< -o $@

cmdline-str: cmdline-str.o
	$(CC) $(CFLAGS) $< -o $@

subdirs:
	cd remove-blanks/; make

# A rule most Makefiles should have. This one removes
# any .o files and other unwanted files that are lying around and 
# the executables and leaves only the source. Useful for running 
# before submitting a program!
clean:
	/bin/rm -f *.o $(PROGS) a.out core
	cd remove-blanks/; make clean
