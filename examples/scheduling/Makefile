
CC=gcc
CFLAGS=-g -std=gnu89 -Wall -Wpointer-arith -Wstrict-prototypes
PROGS=tcs srt

all: $(PROGS)

tcs: time-context-switches.o
	$(CC) $(CFLAGS) -o $@ $<

srt: soft-realtime-example.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f *.o $(PROGS)
