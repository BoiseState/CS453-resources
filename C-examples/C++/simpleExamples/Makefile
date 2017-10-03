
#---------------------------------------------------------------
# Using this Makefile
#
#	To compile your c++ source 
#
#	make 
#
#	To clean up your directory (e.g. before submission)
#
#	make clean
#
#---------------------------------------------------------------

CC=g++
# Give all warnings during compilation
CPPFLAGS= -Wall

# To satisfy the rule named all, we must have satisfied the rules
# named compile and doc (given later).
all: hello demo1 demo2 demo3

hello: hello.o
	$(CC) $(CPPFLAGS) -o hello hello.o  

demo1: demo1.o
	$(CC) $(CPPFLAGS) -o demo1 demo1.o  

demo2: demo2.o
	$(CC) $(CPPFLAGS) -o demo2 demo2.o  

demo3: demo3.o
	$(CC) $(CPPFLAGS) -o demo3 demo3.o  

clean:
		rm -f  *.o 
		rm -f hello demo1 demo2 demo3
