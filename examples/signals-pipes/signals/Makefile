
CC=gcc
CFLAGS=-g -Wall -MMD

PROGS=sig1 sig2 sig3 sig4 sig5 sig6

all: $(PROGS)

sig1: signal-ex1.o error.o
	$(CC) $(CFLAGS) -o $@ $^

sig2: signal-ex2.o error.o
	$(CC) $(CFLAGS) -o $@ $^

sig3: signal-ex3.o error.o
	$(CC) $(CFLAGS) -o $@ $^

sig4: signal-ex4.o error.o
	$(CC) $(CFLAGS) -o $@ $^

sig5: signal-ex5.o error.o
	$(CC) $(CFLAGS) -o $@ $^

sig6: signal-ex6.o error.o
	$(CC) $(CFLAGS) -o $@ $^

-include: *.d

clean:
	/bin/rm -f *.o *.d  $(PROGS)
