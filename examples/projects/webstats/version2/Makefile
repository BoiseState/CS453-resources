

CC=gcc
#CFLAGS= -g   -Wall 
CFLAGS= -O  -Wall  
LIBS=-lpthread
PROGS=webstats 

all: $(PROGS)

webstats: webstats.o error.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ webstats.o error.o

clean:
	/bin/rm -f *.o $(PROGS)
