
CC=gcc
CFLAGS=-Wall -MMD -g

PROGS=color pipe-talk fifo-talk fifo-client fifo-server hello-pipe\
	hello-pipe-two hello-fifo

all:  $(PROGS)

color: color.o error.o
	$(CC) $(CFLAGS) $^  -o $@

pipe-talk: pipe-talk.o error.o
	$(CC) $(CFLAGS) $^  -o $@

fifo-talk: fifo-talk.o error.o
	$(CC) $(CFLAGS) $^  -o $@

fifo-server: fifo-server.o error.o
	$(CC) $(CFLAGS) $^  -o $@

fifo-client: fifo-client.o error.o
	$(CC) $(CFLAGS) $^  -o $@

hello-pipe: hello-pipe.o error.o
	$(CC) $(CFLAGS) $^  -o $@

hello-pipe-two: hello-pipe-two.o error.o
	$(CC) $(CFLAGS) $^  -o $@

hello-fifo: hello-fifo.o error.o
	$(CC) $(CFLAGS) $^  -o $@

-include: *.d

clean:
	/bin/rm -f *.o $(PROGS) *.d
