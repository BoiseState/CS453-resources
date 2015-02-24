
CC=gcc
CFLAGS=-Wall -g -O -MMD

all: ListTest

ListTest: ListTest.o List.o Node.o
	$(CC) $(CFLAGS)  $^  -o $@

clean:
	/bin/rm -f *.o ListTest *.d
	/bin/rm -fr docs doxygen.log

-include *.d
