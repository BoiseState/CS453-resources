
KERNEL_SOURCE=/lib/modules/`uname -r`/build

all: booga test-booga

booga:
	 make -C ${KERNEL_SOURCE} M=`pwd` modules

obj-m += booga.o

test-booga: test-booga.o
	$(CC) $(CFLAGS) -o $@ $^
	

clean:
	/bin/rm -f test-booga test-booga.o
	/bin/rm -f .booga* booga.o booga.mod.c booga.mod.o booga.ko Modules.*
	/bin/rm -fr .tmp_versions/



