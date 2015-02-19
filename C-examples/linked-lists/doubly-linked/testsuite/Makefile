
INSTALL=..
INCLUDE=$(INSTALL)/include -I.
LIBS=$(INSTALL)/lib
LFLAGS=-L$(LIBS) -lmylib
CC=gcc
CFLAGS=-Wall -g  -I$(INCLUDE)

PROGS=RandomTestList SimpleTestList UnitTestList

all: $(PROGS)


RandomTestList: RandomTestList.o Object.o
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS)

SimpleTestList: SimpleTestList.o
	$(CC) $(CFLAGS) -o $@ SimpleTestList.o   $(LFLAGS)

UnitTestList: UnitTestList.o Object.o
	$(CC) $(CFLAGS) -o $@ $^   $(LFLAGS)

clean:
	rm -f list *.o $(PROGS)
