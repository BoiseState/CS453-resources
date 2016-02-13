
CC=gcc
CFLAGS=-Wall -g -O -MMD

all: SimpleTest

SimpleTest: SimpleTest.o SinglyLinkedList.o
	$(CC) $(CFLAGS)  $^  -o $@

dox:
	echo "Generating documentation using doxygen..."
	doxygen doxygen-config >& doxygen.log
	echo "Use konqueror docs/html/index.html to see docs (or any other browser)"

clean:
	/bin/rm -f *.o SimpleTest *.d
	/bin/rm -fr docs doxygen.log

-include *.d
