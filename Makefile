obj-m+=tujasdr.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) modules
	dtc -@ -I dts -O dtb -o i2s-soundcard.dtbo i2s-soundcard-overlay.dts

install:
	# make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) modules_install
	sudo cp tujasdr.ko /lib/modules/$(shell uname -r)
	sudo depmod -a
	sudo cp i2s-soundcard.dtbo /boot/overlays

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) clean
	rm i2s-soundcard.dtbo
