CC=gcc
CFLAGS=-Wall -g
#CFLAGS=-Wall -g -DDEBUG=1
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
