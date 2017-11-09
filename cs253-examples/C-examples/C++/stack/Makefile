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
CPPFLAGS= -Wall -g  

# To satisfy the rule named all, we must have satisfied the rules
# named compile and doc (given later).
all: compile 

# To satisfy the rule named compile, we must have the  following 
# class files (with date no later than the source .java files).

compile: TestStack.o List.o Node.o Stack.o 
	$(CC) $(CPPFLAGS) -o TestStack TestStack.o List.o Node.o Stack.o

clean:
		rm -f  *.o 
		rm -f  TestStack
