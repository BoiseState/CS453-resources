
DEBUG=
CC=gcc
#CFLAGS=-I. -g -Wall  $(DEBUG) -MMD
CFLAGS=-I. -O -Wall  $(DEBUG) -MMD
LFLAGS=-lpthread

PROGS=TestAccount

all: $(PROGS)

TestAccount: Account.o TestAccount.o
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS)
	
-include *.d

clean:
	/bin/rm -f *.o *.d core a.out $(PROGS)
