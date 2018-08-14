CC=gcc
CFLAGS=-g -std=gnu89 -Wall -Wpointer-arith -Wstrict-prototypes -MMD
OBJFLAGS=-c -fPIC
LIBFLAGS=-shared
LOADERFLAGS=-lpthread -rdynamic

All:  Loader Hello.so

Loader: Loader.c Loader.h
	$(CC) $(LOADERFLAGS) -o $@ $< -ldl

%.so: %.c
	$(CC) $(OBJFLAGS) $^
	$(CC) $(LIBFLAGS) -o $@ $*.o
	rm -f $*.o
	chmod a-x $@
	cp Hello.so CopyOfHello.so

.PHONY: clean
clean:
	rm -f *.o *.so *~ Loader $(OBJS)
