
KERNEL_SOURCE=/lib/modules/`uname -r`/build
all:
	 make -C ${KERNEL_SOURCE} M=`pwd` modules

obj-m += hello.o

clean:
	/bin/rm -fr .hello* hello.o hello.mod.c hello.mod.o hello.ko hello.mod .tmp_versions/ \
				.Module.symvers.cmd .modules.order.cmd modules.order Module.symvers

