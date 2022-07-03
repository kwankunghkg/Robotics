---------------------------------------------  
  
## procedure to copy (duplicate/ clone) Rpi boot image (micro-SDcard)  
1. open a terminal (Linux Command Shell)  
2. type "lsusb" to check USB devices  
3. type "lsblk" to check "sb*"  
4. insert SOURCE Rpi boot image (micro-SDcard) to USB port  
5. type "lsusb" to check newly inserted USB device  
6. type "lsblk" to check presence of "sda"  
7. insert BLANK (micro-SDcard)  
8. type "lsusb" to check newly inserted USB device  
9. type "lsblk" to check presence of "sdb"  
10. type and check carefully the following command before execution  
    "sudo dd if=/dev/sda of=/dev/sdb status=progress"  
11. after finished, type "df -h" to check mounted devices (e.g. /dev/sda & /dev/sdb)  
12. type "sudo umount /dev/sda"  
13. type "sudo umount /dev/sdb"  
14. now, 2 USB drives are safe to take out from USB port  
  
---------------------------------------------  
