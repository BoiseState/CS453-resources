CC=gcc
CFLAGS=-Wall -g -O -I. -MMD
PROGS=parse-file
OBJS=parse-file.o Object.o

all: $(PROGS)

parse-file: parse-file.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

-include *.d

clean:
	/bin/rm -f *.o *.d $(PROGS)
