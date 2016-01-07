

DEBUG=
CC=gcc
CFLAGS=-Wall  $(DEBUG)
LFLAGS=-lpthread

all: producers-consumers

producers-consumers: producers-consumers.o
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)


clean:
	/bin/rm -f *.o core a.out producers-consumers 
