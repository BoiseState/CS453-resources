
CC=g++
CPPFLAGS= -Wall -g  
#CPPFLAGS= -Wall -O

all:	testTokenizer

testTokenizer:	testTokenizer.o StringTokenizer.o
	$(CC) $(CPPFLAGS) -o testTokenizer testTokenizer.o StringTokenizer.o

clean:
	rm -f *.o testTokenizer
