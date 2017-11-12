
INCLUDE=$(INSTALL)/include -I.
CC=gcc
CFLAGS=-Wall -g  -I$(INCLUDE) -MMD

PROGS=RandomTestList SimpleTestList UnitTestList

all: $(PROGS)

RandomTestList: RandomTestList.o Node.o List.o 
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS)

SimpleTestList: SimpleTestList.o Node.o List.o
	$(CC) $(CFLAGS) -o $@ $^   $(LFLAGS)

UnitTestList: UnitTestList.o Node.o List.o
	$(CC) $(CFLAGS) -o $@ $^   $(LFLAGS)

-include *.d

clean:
	rm -f list *.o $(PROGS) *.d
