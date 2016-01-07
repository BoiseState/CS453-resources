CC=gcc
CFLAGS=-g  
LIBFLAGS=-fpic -shared
LIBS=-ldl

all:  runplug plugin1 plugin2

runplug: runplug.c  
	$(CC) $@.c $(CFLAGS) $(LIBS) -o $@

plugin%: plugin%.c
	$(CC) $(LIBFLAGS) $@.c -o $@.so

clean:
	rm -f *.o *.so *~ runplug 
