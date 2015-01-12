CC=gcc
CPP=g++
OBJFLAGS=-c -fPIC
LIBFLAGS=-shared
LOADERFLAGS=-rdynamic

All:  Hello.so Goodbye.so Loader

Loader: Loader.c Loader.h
	$(CC) $(LOADERFLAGS) -o $@ $< -ldl
	cp Hello.so temp.so

%.so: %.c
	$(CC) $(OBJFLAGS) $^
	$(CC) $(LIBFLAGS) -o $@ $*.o
	rm -f $*.o
	chmod a-x $@

.PHONY: clean
clean:
	rm -f *.o *.so *~ Loader $(OBJS)
