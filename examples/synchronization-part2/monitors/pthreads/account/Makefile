
DEBUG=
CC=gcc
#CFLAGS=-g  -Wall  $(DEBUG)
CFLAGS=-O  -Wall  $(DEBUG)
LFLAGS=-lpthread

PROGS=TestAccount badTestAccount TestAccountWrapper

all: $(PROGS)

TestAccount: account.h account.o TestAccount.o
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS)
	
TestAccountWrapper: account.h accountWrapper.o TestAccount.o
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS)

badTestAccount: account.h account.c badTestAccount.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)


clean:
	/bin/rm -f *.o core a.out $(PROGS)
