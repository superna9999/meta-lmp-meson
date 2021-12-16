# Linux microPlatform (LmP) integration for Amlogic based boards

Tested boards:

 - libretech-cc

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
