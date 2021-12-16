load ${devtype} ${devnum}:2 ${scriptaddr} /boot/loader/uEnv.txt
env import -t ${scriptaddr} ${filesize}

load ${devtype} ${devnum}:2 ${kernel_addr_r} "/boot"${kernel_image}

bootm ${kernel_addr_r}
