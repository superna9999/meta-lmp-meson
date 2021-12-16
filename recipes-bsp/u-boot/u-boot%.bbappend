FILESEXTRAPATHS_prepend := "${THISDIR}/u-boot:"

SRC_URI_append_meson-gx = " \
	file://lmp-bootcmd.cfg \
	file://lmp-bootcmd-mmc${SDCARD_MMC_DEV}.cfg \
	file://lmp-bootenv-vfat.cfg \
	file://lmp-bootenv-mmc${SDCARD_MMC_DEV}.cfg \
	file://fw_env.config \
"
