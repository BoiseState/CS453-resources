CC=gcc
CFLAGS=-Wall -g


all: SimpleTestList RandomTestList


SimpleTestList: SimpleTestList.o List.o Node.o Job.o
	$(CC) $(CFLAGS) -o $@ $^

RandomTestList: RandomTestList.o List.o Node.o Job.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o RandomTestList SimpleTestList
