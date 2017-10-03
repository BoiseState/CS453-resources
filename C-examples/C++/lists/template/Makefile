
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
all: testTemplate 

testTemplate: testTemplate.o 
	$(CC) $(CPPFLAGS) -o $@ $<

clean:
		rm -f  *.o  testTemplate
