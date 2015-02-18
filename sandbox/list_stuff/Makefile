CFLAGS= -std=c99 -Wall

%.o : %.c
	$(CC) $(CFLAGS) -c $<

list: list.o

clean:
	rm -f a.out list *.o
