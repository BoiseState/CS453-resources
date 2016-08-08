
DEBUG=
CC=gcc
#CFLAGS=-g  -Wall  $(DEBUG) -MMD
CFLAGS=-O  -Wall  $(DEBUG) -MMD
LFLAGS=-lpthread

PROGS=TestAccount badTestAccount TestAccountWrapper

all: $(PROGS)

TestAccount: account.h account.o TestAccount.o
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS)
	
TestAccountWrapper: account.h accountWrapper.o TestAccount.o
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS)

badTestAccount: account.h account.c badTestAccount.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

-include *.d


clean:
	/bin/rm -f *.o *.d core a.out $(PROGS)
