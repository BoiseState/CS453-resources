
CC=gcc
CFLAGS=-g  -MMD -Wall
LIBS=

PROGS=simple-malloc-random-test simple-malloc-test

all: $(PROGS)

simple-malloc-test: simple-malloc-test.o simple-malloc.o
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS); ./validate_refactor.sh

simple-malloc-random-test: simple-malloc-random-test.o simple-malloc.o
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

-include: *.d

clean:
	/bin/rm -f *.o a.out  $(PROGS)
