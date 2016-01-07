
CC=gcc
LIBFLAGS=-shared -fPIC
CFLAGS=-Wall -fPIC
LIBS=-lread1 -lread2 -ldl
LIB1OBJS=read-v1.o
LIB2OBJS=read-v2.o

all: libread1.so libread2.so  test-read

libread1.so: $(LIB1OBJS)
	$(LD) $(LIBFLAGS) -o $@ $?

libread2.so: $(LIB2OBJS)
	$(LD) $(LIBFLAGS) -o $@ $? -ldl

test-read: test-read.o
	$(CC) -Wall -o $@ $<  


clean:
	/bin/rm -f *.o libread1.so libread2.so a.out core test-read
