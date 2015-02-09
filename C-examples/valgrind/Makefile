CC=gcc
CFLAGS=-Wall -Wconversion -g
.SUFFIXES: .o .c
.c.o:
	$(CC) $(CFLAGS) -c $<

sample: sample.o
	$(CC) $(CFLAGS) $< -o $@

clean:
	/bin/rm -f *.o sample a.out core
