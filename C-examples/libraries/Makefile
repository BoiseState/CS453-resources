
CC=gcc
LIBFLAGS=-I. -Wall -shared -c
CFLAGS=-I. -Wall -fPIC
LIBS=-lmylib
ARFLAGS=rcv

all: libmylib.so libmylib.a  test1 test1.static

libmylib.so:	f1.o f2.o f3.o
	$(LD) -shared -o $@ $?

libmylib.a:	f1.o f2.o f3.o
	$(AR) $(ARFLAGS) $@ $?

test1: test1.c
	$(CC) -Wall -I. -L. test1.c -lmylib -o $@

test1.static: test1.c
	$(CC) -Wall -static -I. -L. test1.c -lmylib -o $@

clean:
	rm --force *.o libmylib.so libmylib.a a.out core test1 test1.static
