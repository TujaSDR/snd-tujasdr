PWD := $(shell pwd)

obj-m += tujasdr.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

install: all
	sudo cp tujasdr.ko /lib/modules/$(shell uname -r)
	sudo depmod -a
