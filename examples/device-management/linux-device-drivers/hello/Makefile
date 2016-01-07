
KERNEL_SOURCE=/lib/modules/`uname -r`/build
all:
	 make -C ${KERNEL_SOURCE} M=`pwd` modules

obj-m += hello.o

clean:
	/bin/rm -fr hello.o hello.mod.c hello.mod.o hello.ko .tmp_versions/ .hello* Module.symvers modules.order

