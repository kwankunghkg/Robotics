  
BLOG_GitHub_JetsonXavierNxNotBooting_20231111.txt  
  https://github.com/kwankunghkg/Robotics/blob/main/Jetson/XavierNX/JetsonXavierNxNotBooting.md  
  
  
----------------------------------------  
  
updated  
last : 2023-11-11_21:01(UTC+8)  
prev : 2023-11-11_21:01(UTC+8)  
  
----------------------------------------  
  
##  Jetson Xavier NX Not Booting  
  
----------------------------------------  
  
Jetson Xavier NX Not Booting  
  https://forums.developer.nvidia.com/t/jetson-xavier-nx-not-booting/141070/27  
  
//  
WayneWWW / Moderator / Jul 09 '20  
  
Another workaround if you see the bash (initrd) console in UART after running OTA upgrade.  
  
1. reboot the device 7 times,  
2. the device should be able to boot up properly.  
3. edit the /boot/extlinux/extlinux.conf to do following changes:  
- APPEND ${cbootargs} quiet  
+ APPEND ${cbootargs} root=/dev/mmcblk0p1 rw rootwait rootfstype=ext4 console=ttyTCU0,115200n8 console=tty0 fbcon=map:0 net.ifnames=0  
4. Reboot the device, and run "dpkg-reconfigure nvidia-l4t-bootloader"  
5. reboot device.  
  
//  end  
  
  
//  
WayneWWW / Moderator / Jul 14 '20  
  
Hi,  
  
Let me briefly explain the issue.  
  
   After rel-32.4.3, we put the root=boot_device in extlinux.conf but not in device tree anymore.  
   However, the deb package forgets to update this. So your device is getting stuck in initrd bash console because it does not know where to load the rootfs.  
  
Thus, our solution is to ask you to add root=/dev/mmcblk0p1 in extlinux.conf manually and device will be able to boot rootfs now.  
  
However, in your case, you don’t put rootfs on /dev/mmcblk0p1 but on SSD, which I guess is something like /dev/sdb1…?  
  
As a result, please try to put the correct device as root device.  
  
//  end  
  
----------------------------------------  
  
#####  Boots into black screen with a blinking cursor after auto update  
  https://forums.developer.nvidia.com/t/boots-into-black-screen-with-a-blinking-cursor-after-auto-update/141256  
  
  
----------------------------------------  
  
#####  Recovering Xavier NX Dev Kit not booting anymore  
  https://forums.developer.nvidia.com/t/recovering-xavier-nx-dev-kit-not-booting-anymore/200779  
  
  
####  SDKM - SDK Manager  
  https://developer.nvidia.com/sdk-manager  
  https://docs.nvidia.com/sdk-manager/index.html  
  
  
----------------------------------------  
  
  
  
----------------------------------------  
  
  
  
----------------------------------------  
  
  
  
----------------------------------------  
  
  
  
----------------------------------------  
End of File.  
