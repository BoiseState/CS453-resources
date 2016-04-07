
CC=gcc
CFLAGS= -g   -Wall
#CFLAGS= -O  -Wall

PROGS=sig-handler wake-up

all: $(PROGS)

sig-handler: sig-handler.o
	$(CC) $(CFLAGS) -o $@ $<

wake-up: wake-up.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f *.o $(PROGS) a.out
