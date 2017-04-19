LIB     = lib
INCLUDE = include
CC      = gcc
CFLAGS  = -Wall -g -I$(INCLUDE)
LDFLAGS = -L$(LIB)
LDLIBS  = -lhello

all: hellolib main

main: main.o

hellolib:
	cd libsrc; make
	cp libsrc/libhello.so $(LIB)
	cp libsrc/hello.h $(INCLUDE)

clean:
	rm -f *.o main
	rm -f lib/*.so
	rm -f include/*.h
	cd libsrc; make clean
