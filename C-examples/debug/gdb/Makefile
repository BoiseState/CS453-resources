CC=gcc
CFLAGS=-Wall -g

OBJS=arrays strings testlists faulty1 loop function overflow

all: $(OBJS)


faulty1: faulty1.o
	$(CC) $(CFLAGS) -o $@ $<

arrays: arrays.o
	$(CC) $(CFLAGS) -o $@ $<

strings: strings.o
	$(CC) $(CFLAGS) -o $@ $<


testlists: test-lists.o lists.o
	$(CC) $(CFLAGS) -o $@ test-lists.o lists.o

loop: loop.o
	$(CC) $(CFLAGS) -o $@ $<

function: function.o
	$(CC) $(CFLAGS) -o $@ $<

overflow: overflow.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o core a.out $(OBJS)
