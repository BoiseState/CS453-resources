CC      = gcc
LDFLAGS = -shared -fPIC
CFLAGS  = -Wall -I. -g $(LDFLAGS)

all: libhello.so

libhello.so: hello.o
	$(LD) $(LDFLAGS) -o $@ $^

hello.o: hello.c hello.h

clean:
	rm -f *.o *.so
