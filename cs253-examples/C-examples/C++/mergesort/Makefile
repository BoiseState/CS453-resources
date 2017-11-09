
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
all: testms

testms: TimeMergeSort.o Utility.h MergeSort.h
	$(CC) $(CPPFLAGS) -o testms TimeMergeSort.o  


clean:
		rm -f  *.o 
		rm -f testms
