# U-boot MMC ordering depends if board has SDIO wifi module enabled.
# If yes (like khadas-vim1/2/3):
# 0: SDIO
# 1: SDCard
# 2: eMMC
SDCARD_MMC_DEV_meson_gx = "1"
# If not (like libretech-cc, libretech-ac, odroid-c2, odroid-n2, odroid-c4...)
# 0: SDCard
# 1: eMMC
SDCARD_MMC_DEV_libretech-cc = "0"
SDCARD_MMC_DEV_libretech-ac = "0"
SDCARD_MMC_DEV_hardkernel-odroidc2 = "0"
SDCARD_MMC_DEV_hardkernel-odroidn2 = "0"
SDCARD_MMC_DEV_hardkernel-odroidn2plus = "0"
SDCARD_MMC_DEV_hardkernel-odroidc4 = "0"
SDCARD_MMC_DEV_hardkernel-odroidhc2 = "0"

PREFERRED_PROVIDER_virtual/bootloader_meson-gx = "u-boot-meson-gx"
PREFERRED_PROVIDER_u-boot_meson-gx = "u-boot-meson-gx"

WKS_FILE_DEPENDS_append = " u-boot-default-script"
PREFERRED_PROVIDER_u-boot-default-script_meson-gx = "u-boot-ostree-scr-fit"
IMAGE_BOOT_FILES_append_meson-gx = " boot.itb"

OSTREE_KERNEL_meson-gx = "${KERNEL_IMAGETYPE}-${INITRAMFS_IMAGE}-${MACHINE}-${MACHINE}"
OSTREE_KERNEL_ARGS_meson-gx ?= "console=ttyAML0,115200n8 ${OSTREE_KERNEL_ARGS_COMMON}"

KERNEL_IMAGETYPE_meson-gx = "fitImage"
KERNEL_CLASSES_append_meson-gx = " kernel-lmp-fitimage "
KERNEL_CLASSES_remove_meson-gx = "kernel-fitimage"
KERNEL_BUILTIN_WIREGUARD_meson-gx = "1"

SOTA_CLIENT_FEATURES_append_meson-gx = " ubootenv"
