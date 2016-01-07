

CC=gcc
CFLAGS=-Wall 

all: printwhoami overflow self

printwhoami: printwhoami.o
	$(CC) $(CFLAGS) -o $@ $^

overflow: overflow.o 
	$(CC) $(CFLAGS) -o $@ $^

self: self_reproducing.o
	$(CC) $(CFLAGS) -o $@ $<
	

clean:
	/bin/rm -f *.o printwhoami overflow a.out core self test junk tt
