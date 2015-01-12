
CC=gcc
CFLAGS=-Wall -g  


all: subdirs 

zipfile: clean
	cd ..; zip -r C-examples.zip C-examples/

subdirs:	
	cd intro; make
	cd c-preprocessor; make 
	cd scope; make 
	cd pointers-and-arrays; make
	cd strings; make
	cd singlyLinkedLists; make
	cd doublyLinkedLists; make
	cd file-io; make
	cd libraries; make
	cd objects; make
	cd function-pointers; make
	cd varargs; make
	cd exception; make
	cd gdb; make
	cd unions; make
	cd using-C++-compiler-for-C-programs; make

clean:
	cd intro; make clean
	cd c-preprocessor; make clean
	cd scope; make clean
	cd pointers-and-arrays; make clean
	cd strings; make clean
	cd singlyLinkedLists; make clean
	cd doublyLinkedLists; make clean
	cd file-io; make clean
	cd libraries; make clean
	cd objects; make clean
	cd function-pointers; make clean
	cd varargs; make clean
	cd exception; make clean
	cd gdb; make clean
	cd unions; make clean
	cd using-C++-compiler-for-C-programs; make clean
	cd bitwise-operators; make clean
