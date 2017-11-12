
CC=gcc
CFLAGS=-Wall -MMD -g 

PROGS=color fifo-talk fifo-client fifo-server hello-fifo

all:  $(PROGS)

color: color.o error.o
	$(CC) $(CFLAGS) $^  -o $@

fifo-talk: fifo-talk.o error.o
	$(CC) $(CFLAGS) $^  -o $@

fifo-server: fifo-server.o error.o
	$(CC) $(CFLAGS) $^  -o $@

fifo-client: fifo-client.o error.o
	$(CC) $(CFLAGS) $^  -o $@

hello-fifo: hello-fifo.o error.o
	$(CC) $(CFLAGS) $^  -o $@

-include: *.d

clean:
	/bin/rm -f *.o $(PROGS) *.d
