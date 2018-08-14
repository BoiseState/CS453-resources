
CC=gcc
CFLAGS= -g -Wall
CFLAGS=-g -std=gnu89 -Wall -Wpointer-arith -Wstrict-prototypes 
LFLAGS=-lpthread
JFLAGS=

# Recognize files with .class and .java extensions
.SUFFIXES: .class .java
.java.class:
	javac $(JFLAGS) $<

PROGS=mycp stdc-mycp fork-and-wait fork-hello-world fork-child-grandchild fork-and-exec\
	  fork-two-children  timeout fork-test simple-shell print-max-no-procs print-pid\
	  numcpus pow2Tester print-buffer-sizes skeleton fork-and-exec-xlogo\
	  sig-handler

all: $(PROGS)

mycp: mycp.o
	$(CC) $(CFLAGS) -o mycp mycp.o

stdc-mycp: stdc-mycp.o
	$(CC) $(CFLAGS) -o stdc-mycp stdc-mycp.o

fork-hello-world: fork-hello-world.o
	$(CC) $(CFLAGS) -o $@ fork-hello-world.o

fork-child-grandchild: fork-child-grandchild.o
	$(CC) $(CFLAGS) -o $@ fork-child-grandchild.o

fork-and-exec: fork-and-exec.o print-pid
	$(CC) $(CFLAGS) -o $@ fork-and-exec.o

print-pid: print-pid.o
	$(CC) $(CFLAGS) -o $@ print-pid.o

fork-and-wait: fork-and-wait.o
	$(CC) $(CFLAGS) -o $@ fork-and-wait.o

fork-two-children: fork-two-children.o
	$(CC) $(CFLAGS) -o $@ fork-two-children.o

timeout: timeout.o
	$(CC) $(CFLAGS) -o $@ timeout.o

fork-test: fork-test.o
	$(CC) $(CFLAGS) -o $@ fork-test.o

simple-shell: simple-shell.o error.o
	$(CC) $(CFLAGS) -o $@ simple-shell.o error.o

print-max-no-procs: print-max-no-procs.o
	$(CC) $(CFLAGS) -o $@ print-max-no-procs.o

numcpus: numcpus.o
	$(CC) $(CFLAGS) -o $@ $<

print-buffer-sizes: print-buffer-sizes.o error.o
	$(CC) $(CFLAGS) -o $@ print-buffer-sizes.o error.o

pow2Tester: pow2Tester.o
	$(CC) $(CFLAGS) -o $@ $<

skeleton: skeleton.o
	$(CC) $(CFLAGS) -o $@ $<

fork-and-exec-xlogo: fork-and-exec-xlogo.o
	$(CC) $(CFLAGS) -o $@ $<

sig-handler: sig-handler.o
	$(CC) $(CFLAGS) -o $@ $<
clean:
	/bin/rm -f *.o $(PROGS) a.out core *.class junk log logfile
