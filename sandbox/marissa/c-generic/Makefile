CC=gcc
CFLAGS=-Wall -g -O -I. -MMD
PROGS=SimpleTestList SimpleTestListTwo UnitTestList
OBJS=List.o Node.o

all: $(PROGS)

SimpleTestList: SimpleTestList.o $(OBJS) Object.o
	$(CC) $(CFLAGS) -o $@ $^

SimpleTestListTwo: SimpleTestListTwo.o $(OBJS) Dog.o
	$(CC) $(CFLAGS) -o $@ $^

UnitTestList: UnitTestList.o $(OBJS) Object.o
	$(CC) $(CFLAGS) -o $@ $^

-include *.d

clean:
	/bin/rm -f *.o *.d $(PROGS)
