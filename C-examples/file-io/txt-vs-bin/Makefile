
CC=gcc
CFLAGS=-Wall -g  
PROGS=gentxt genbin readbin readtxt

all: $(PROGS) 

gentxt: generate_text.o record.o record.h
	$(CC) $(CFLAGS)  -o $@ $^

genbin: generate_binary.o record.o record.h
	$(CC) $(CFLAGS)  -o $@ $^

readbin: read_binary.o record.o record.h
	$(CC) $(CFLAGS)  -o $@ $^

readtxt: read_text.o record.o record.h
	$(CC) $(CFLAGS)  -o $@ $^

clean:
	rm --force *.o a.out $(PROGS) data* read.bin read.txt 
