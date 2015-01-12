
CC=gcc
CFLAGS=-Wall -g  


all: testAddress


testAddress: testAddress.o Address.o Address.h
	$(CC) $(CFLAGS) -o $@ testAddress.o Address.o

clean:
	rm --force testAddress *.o
