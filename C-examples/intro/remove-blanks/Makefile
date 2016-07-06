CC = gcc
CFLAGS = -Wall -g

all: remove-blanks

remove-blanks: remove-blanks.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o remove-blanks
