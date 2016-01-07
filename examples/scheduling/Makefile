
CC=gcc
CFLAGS=  -Wall
PROGS=tcs srt

all: $(PROGS)

tcs: time-context-switches.o
	$(CC) $(CFLAGS) -o $@ $<

srt: soft-realtime-example.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f *.o $(PROGS)
