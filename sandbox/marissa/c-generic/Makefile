
CC=gcc
CFLAGS=-Wall -g -O -MMD

all: ListTest ListTestTwo UnitTestList

ListTest: ListTest.o List.o Node.o Object.o
	$(CC) $(CFLAGS)  $^  -o $@

ListTestTwo: ListTestTwo.o List.o Node.o Dog.o
	$(CC) $(CFLAGS)  $^  -o $@


UnitTestList: UnitTestList.o List.o Node.o Object.o
	$(CC) $(CFLAGS)  $^  -o $@

clean:
	/bin/rm -f *.o ListTest ListTestTwo UnitTestList *.d
	/bin/rm -fr docs doxygen.log

-include *.d
