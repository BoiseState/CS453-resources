
CC=gcc
CFLAGS= -g   -Wall  -MMD
LIBS=-lreadline -lncurses

PROGS=test-readline loop 

all: $(PROGS) dox

loop: loop.o
	$(CC) $(CFLAGS) -o $@  $<

test-readline: test-readline.o
	$(CC) $(CFLAGS) -o $@  $< $(LIBS)


-include *.d

dox:
	echo "Generating documentation using doxygen..."
	doxygen doxygen-config >& doxygen.log
	echo "Use konqueror docs/html/index.html to see docs (or any other browser)"


clean:
	/bin/rm -f *.o $(PROGS) a.out core  *.log
	/bin/rm -fr docs
