PWD := $(shell pwd)

dtbo-y += tujasdr.dtbo
targets += $(dtbo-y)
always  := $(dtbo-y)

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD)

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

install: all
	sudo cp tujasdr.dtbo /boot/overlays/
