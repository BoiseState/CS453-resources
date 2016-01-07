
CC=gcc
CFLAGS=-Wall -I. -g 

all: udpclient1 udpserver1 udpclient2 udpserver2

udpserver1: udpserver1.o  error.o
	$(CC) $(CFLAGS) -o $@  udpserver1.o error.o

udpclient1: udpclient1.o  error.o sock_ntop.o
	$(CC) $(CFLAGS) -o $@  udpclient1.o error.o sock_ntop.o

udpserver2: udpserver2.o  error.o
	$(CC) $(CFLAGS) -o $@  udpserver2.o error.o

udpclient2: udpclient2.o  error.o
	$(CC) $(CFLAGS) -o $@  udpclient2.o error.o

clean:
	/bin/rm -f *.o core a.out udpserver1 udpclient1 udpserver2 udpclient2
