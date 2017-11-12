all: subdirs

subdirs:
	cd gdb; make
	cd valgrind; make
	cd ring-buffer; make

clean:
	cd gdb; make clean
	cd valgrind; make clean
	cd ring-buffer; make clean
