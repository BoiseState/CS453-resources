# Locking (pick one)
atomic:=TestAndSet
#atomic:=CompareAndExchange
#atomic:=ExchangeAndAdd
#atomic:=LoadLinkedAndStoreConditional

# Blocking (pick one)
block:=Spin
#block:=Yield
#block:=Wait

defines:=-D$(atomic) -D$(block)

objs:=$(atomic).o
vpath %.c Lock/$(shell echo $(MAKE_HOST) | sed 's/[-_].*//')

ccflags:=-pthread
ldflags:=-pthread

sinclude ../../GNUmakefile
