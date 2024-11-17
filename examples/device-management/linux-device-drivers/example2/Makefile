
KERNEL_SOURCE=/lib/modules/`uname -r`/build
all:
	 make -C ${KERNEL_SOURCE} M=`pwd` modules

obj-m += example.o

clean:
	/bin/rm --force .example* example.o example.mod.c example.mod.o example.ko example.mod \
					.Module.symvers.cmd .modules.order.cmd
	/bin/rm -fr .tmp_versions/
	/bin/rm -fr test-example



