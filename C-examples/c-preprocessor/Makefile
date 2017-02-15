# define it from the make command line
# make "DEBUG=-DDEBUG=1"
CC=gcc
CFLAGS=-Wall -g $(DEBUG)
.SUFFIXES: .o .c

.c.o:
	$(CC) $(CFLAGS) -c $<

all: ex1 ex2 macro

ex1: ex1.o ex2.o
	$(CC) $(CFLAGS) $< -o $@

macro: macro.o
	$(CC) $(CFLAGS) $< -o $@

clean:
	/bin/rm -f *.o ex1 ex2 macro a.out core
