
CC=gcc
CFLAGS= -g   -Wall
#CFLAGS= -O  -Wall

PROGS=sig-handler timeout

all: $(PROGS)

sig-handler: sig-handler.o
	$(CC) $(CFLAGS) -o $@ $<

repeat: repeat.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f *.o $(PROGS) a.out
