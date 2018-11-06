# TujaSDR ASoC Driver

This is an ALSA I2S driver for the TujaSDR Raspberry Pi / FPGA SDR transceiver.

This seems to be complicated stuff. Not super well documented.

## Building

```bash
# building the driver
# first install kernel tree
rpi-source --skip-gcc

# check makefile for details
make
make install
echo "dtoverlay=i2s-soundcard,master,alsaname=tujasdr" >> /boot/config.txt
```

## Good information regar

* https://www.raspberrypi.org/forums/viewtopic.php?t=173640
* https://www.kernel.org/doc/Documentation/devicetree/bindings/sound/simple-card.txt
* https://elinux.org/images/b/b5/Belloni-alsa-asoc.pdf
* https://opensourceforu.com/2017/01/regmap-reducing-redundancy-linux-code/
