
KERNEL_SOURCE=/lib/modules/`uname -r`/build
all:
	 make -C ${KERNEL_SOURCE} M=`pwd` modules

obj-m += jiffies.o

clean:
	/bin/rm -fr jiffies.o jiffies.mod.c jiffies.mod.o jiffies.ko .tmp_versions/ .jiffies* Module.symvers modules.order

