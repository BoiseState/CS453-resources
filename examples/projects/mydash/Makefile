# This Makefile will not build unless you first update the line 
# below to point to your linked list code from p0
LISTINSTALL=../../../../p0/grader/solutions/amit/
export LISTINSTALL

all: mydash-project dox

mydash-project: lib
	cd mydash-src; make
	cp $(LISTINSTALL)/lib/libmylib.so .

lib:
	cd $(LISTINSTALL); make 

dox:
	echo "Generating documentation using doxygen..."
	doxygen doxygen-config > doxygen.log 
	echo "Use konqueror docs/html/index.html to see docs (or any other browser)"

clean:
	echo "You need to implement this rule"


