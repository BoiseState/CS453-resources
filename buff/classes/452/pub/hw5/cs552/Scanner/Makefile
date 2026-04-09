PATH=/usr/bin:/bin:/sbin

name:=Scanner
module:=$(name).ko
obj-m:=$(name).o

KDIR :=/lib/modules/$(shell uname -r)/build

REGEXP9_DIR:=../regexp9
REGEXP9_OBJS:=$(shell cat $(PWD)/../regexp9Scanner/Objs)
REGEXP9_SRCS:=$(patsubst %.o,%.c,$(REGEXP9_OBJS))

$(name)-objs:=RegExp9Scanner.o
$(name)-objs+=$(notdir $(REGEXP9_OBJS))
$(name)-objs+=stdlib.o unistd.o setjmp.o

KBUILD_CFLAGS+=-DDEVNAME='"$(name)"'
KBUILD_CFLAGS+=-Wno-declaration-after-statement
KBUILD_CFLAGS+=$(addprefix -isystem , \
    $(PWD)/$(REGEXP9_DIR)/glue \
    $(PWD)/$(REGEXP9_DIR)/libutf \
    $(PWD)/$(REGEXP9_DIR)/libfmt \
    $(PWD)/$(REGEXP9_DIR)/libregexp \
)

all:
	ln -sf $(REGEXP9_SRCS) .
	ln -sf $(REGEXP9_DIR)/glue/*.c .
	cmp -s my-regexec.c regexec.c || ln -sf my-regexec.c regexec.c
	$(MAKE) modules

modules $(module) clean: ; $(MAKE) -C $(KDIR) M=$(PWD) $@

install: $(module)
	sudo rmmod $(module) || true
	sudo insmod $(module)
	sudo rm -f /dev/$(name) || true
	sudo mknod -m a+rw /dev/$(name) c $$(./getmaj $(name)) 0

uninstall:
	sudo rmmod $(module) || true
	sudo rm -f /dev/$(name) || true
	find -name "*.c" -type l | xargs -r rm

TryScanner: TryScanner.c
	gcc -o $@ $< -Wall -g

try: TryScanner
	./$< < /etc/passwd
