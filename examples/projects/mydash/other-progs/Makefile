
CC=gcc
CFLAGS= -g   -Wall  -MMD
LIBS=-lreadline -lncurses

PROGS=test-readline loop 

all: $(PROGS) 

loop: loop.o
	$(CC) $(CFLAGS) -o $@  $<

test-readline: test-readline.o
	$(CC) $(CFLAGS) -o $@  $< $(LIBS)


-include *.d

clean:
	/bin/rm -f *.o $(PROGS) a.out core  *.log *.d
