
CC=gcc
CFLAGS=-Wall -I.

all: tcpclient tcpserver timeserver timeclient

tcpclient: tcpclient.o error.o
	$(CC) $(CFLAGS) -o $@  tcpclient.o error.o

tcpserver: tcpserver.o error.o
	$(CC) $(CFLAGS) -o $@  tcpserver.o error.o

timeclient: timeclient.o error.o
	$(CC) $(CFLAGS) -o $@  timeclient.o error.o

timeserver: timeserver.o error.o
	$(CC) $(CFLAGS) -o $@  timeserver.o error.o

clean:
	/bin/rm -f *.o core a.out timeserver timeclient tcpclient tcpserver
