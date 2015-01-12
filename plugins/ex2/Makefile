CC=gcc
CFLAGS=-Wall -g  
OBJFLAGS= -g -c -fPIC
LIBFLAGS=-shared

All:  Loader Hello.so Goodbye.so

Loader: Loader.c Loader.h
	$(CC) $(CFLAGS) $(LOADERFLAGS) -o $@ $< -ldl

%.so: %.c
	$(CC) $(OBJFLAGS) $^
	$(CC) $(LIBFLAGS) -o $@ $*.o
	rm -f $*.o
	chmod a-x $@

.PHONY: clean
clean:
	rm -f *.o *.so *~ Loader $(OBJS)
