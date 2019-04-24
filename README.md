# TujaSDR ASoC Driver

This is an ALSA I2S driver for the TujaSDR Raspberry Pi / FPGA SDR transceiver.

This seems to be complicated stuff. Not super well documented.

## Building

I'm working on a dkms version. For now you need a linux kernel source installed, I suggest using `rpi-update` and `rpi_source`.

```bash
cd src && sudo make install
cd overlays && make install
```

You need to install both the kernel module and the overlay.

```bash
# put this line in /boot/config.txt
dtoverlay=tujasdr
```

## Good links regarding this stuff

* https://www.raspberrypi.org/forums/viewtopic.php?t=173640
* https://www.kernel.org/doc/Documentation/devicetree/bindings/sound/simple-card.txt
* https://elinux.org/images/b/b5/Belloni-alsa-asoc.pdf
* https://opensourceforu.com/2017/01/regmap-reducing-redundancy-linux-code/
