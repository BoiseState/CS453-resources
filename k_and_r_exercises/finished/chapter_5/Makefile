CC = gcc
CFLAGS = -Wall -g -o
#You can add new exersices to progs variable
PROGS = exe5-3 exe5-4
OBJECTS = exe5-3.o exe5-4.o
#All target will take care of everything you specify under PROGS
all: $(PROGS)

#Whenever you want to add a new exercise, make sure to create a target 
#for it. 
exe5-3: exe5-3.o
	$(CC) $(CFLAGS) exe5-3 exe5-3.c

exe5-4: exe5-4.o
	$(CC) $(CFLAGS) exe5-4 exe5-4.c

make run: all
	./exe5-4 foo bar
	#Exe 5-4 takes in command line arguments as input. I don't 
	#know how to specify this in Makefile other than hardcoding.
	
make clean:
	rm -f *.o
	rm -f $(PROGS)
