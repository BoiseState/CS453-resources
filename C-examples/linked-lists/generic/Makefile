
CC=gcc
CFLAGS=-Wall -g -O -I. -MMD 
LFLAGS=

PROGS=SimpleTestList UnitTestList RandomTestList
OBJECTS=List.o Node.o 

all: $(PROGS) dox

SimpleTestList: SimpleTestList.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

UnitTestList: UnitTestList.o $(OBJECTS) Object.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

RandomTestList: RandomTestList.o $(OBJECTS) Object.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)


-include *.d

dox:
	echo "Generating documentation using doxygen..."
	doxygen doxygen-config >& doxygen.log
	echo "Use konqueror docs/html/index.html to see docs (or any other browser)"

clean:
	/bin/rm -f $(PROGS) *.o a.out  *.d
	/bin/rm -fr docs doxygen.log

