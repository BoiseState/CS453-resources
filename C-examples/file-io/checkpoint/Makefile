
CC=gcc
CFLAGS=-Wall -g  -I. -MMD


all: SaveList RestoreList 


SaveList: SaveList.o List.o Node.o Job.o
	$(CC) $(CFLAGS) -o $@ $^

RestoreList: RestoreList.o List.o Node.o Job.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm --force *.o SaveList RestoreList  *.d list.bin
