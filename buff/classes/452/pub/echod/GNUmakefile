defines:= -DECHOD_PORT=$(shell ./port.sh) \
	  -DECHOD_TRIES=5 \
          -DECHOD_REAP=5 \
	  -DECHOD_ERRFILE=\"errfile\"

ldflags=-lpthread

include ../GNUmakefile
