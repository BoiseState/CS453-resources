CFLAGS= -std=c99 -Wall

%.o : %.c
	$(CC) $(CFLAGS) -c $<

all: list glist

list: list.o

glist: listg.o

clean:
	rm -f a.out list *.o
