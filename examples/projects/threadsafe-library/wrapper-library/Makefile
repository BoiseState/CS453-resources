
INSTALL=../
LIB=../../p0/lib
INCLUDE=../../p0/include
CC=gcc
CFLAGS=-Wall -MMD -g -O   -O -fPIC -I$(INCLUDE)
#CFLAGS=-Wall -O -fPIC -I. -I$(INCLUDE) 
LFLAGS=-L$(LIB) -lmylib


LIBOBJS= ThreadsafeBoundedList.o 

all: libs 

libs: libthreadsafe-mylib.so  libthreadsafe-mylib.a

libthreadsafe-mylib.so: $(LIBOBJS)
	$(LD) -shared -o $@  $(LIBOBJS)

libthreadsafe-mylib.a: $(LIBOBJS)
	$(AR)  rcv $@ $(LIBOBJS)
	ranlib $@

-include *.d

install: libs
	install --mode=444 -C ThreadsafeBoundedList.h $(INSTALL)/include
	install --mode=444 -C libthreadsafe-mylib.so $(INSTALL)/lib
	install --mode=444 -C libthreadsafe-mylib.a $(INSTALL)/lib


installclean:  clean
	rm --force $(INSTALL)/lib/libthreadsafe-mylib.so
	rm --force $(INSTALL)/lib/libthreadsafe-mylib.a
	rm --force $(INSTALL)/include/ThreadsafeBoundedList.h
	
clean:
	rm --force list *.o a.out core *.so *.a *.d
