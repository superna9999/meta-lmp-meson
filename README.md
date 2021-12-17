# Linux microPlatform (LmP) integration for Amlogic based boards

Tested boards:

 - libretech-cc (SDCard)
 - khadas-vim3 (SDCard)
 - khadas-vim3l (SDCard)

Probably other boards supported by Mainline U-Boot & meta-meson should work fine.

Adding possibility to target eMMC instead of SDCard is missing.

Probable work needed:
 - Boards based on A113D (amlogic-s400), has no SDCard, only eMMC or USB
 - Boards based on S805X (libretech-ac, p241), has no SDCard, but USB and optionnaly eMMC, and already has mainline U-Boot on the SPI flash

Please report problems/success on meta-meson [#125](https://github.com/superna9999/meta-meson/issues/125) dedicated issue.

## Build

Download the source:

    $ mkdir lmp-meson
    $ cd lmp-meson
    $ repo init -u https://github.com/foundriesio/lmp-manifest
    $ repo sync

Setup environment

    $ MACHINE=libretech-cc source setup-environment

Enable meta-meson & meta-lmp-meson layers instead on meta-lmp-bsp

    $ git clone https://github.com/superna9999/meta-meson -b hardknott ../layers/meta-meson
    $ git clone https://github.com/superna9999/meta-lmp-meson -b hardknott ../layers/meta-lmp-meson
    $ sed -i '/meta-lmp-bsp/d' conf/bblayers-bsp.inc
    $ echo 'BSPLAYERS += " ${OEROOT}/layers/meta-meson"' >> conf/bblayers-bsp.inc
    $ echo 'BSPLAYERS += " ${OEROOT}/layers/meta-lmp-meson"' >> conf/bblayers-bsp.inc

Build

    $ bitbake lmp-base-console-image

Flash

Flash the `lmp-base-console-image-${MACHINE}.wic` file on an SDCard.
