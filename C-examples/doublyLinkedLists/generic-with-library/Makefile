

all: library testcode

library:	
	cd libsrc; make install

testcode:
	cd testsuite; make


dox:
	echo "Generating documentation using doxygen..."
	doxygen doxygen-config >& doxygen.log
	echo "Use konqueror docs/html/index.html to see docs (or any other browser)"

clean:
	cd libsrc; make installclean
	cd testsuite; make clean
	/bin/rm -fr docs doxygen.log

