prog=shell

ldflags:=-lreadline -lncurses

include ../GNUmakefile

try: $(objs) libdeq.so
	gcc -o $@ $(objs) $(ldflags) -L. -ldeq -Wl,-rpath=.

trytest: try
	Test/run

test: $(prog)
	Test/run
