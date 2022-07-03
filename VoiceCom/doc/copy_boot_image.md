---------------------------------------------  
  
## procedure to copy (duplicate/ clone) Rpi boot image (micro-SDcard)  
1. open a terminal (Linux Command Shell)  
2. type "lsusb" to check USB devices  
3. type "lsblk" to check "sb*"  
4. insert SOURCE Rpi boot image (micro-SDcard) to USB port  
5. type "lsusb" to check newly inserted USB device  
6. type "lsblk" to check presence of "sda"  
7. insert BLANK micro-SDcard to USB port  
8. type "lsusb" to check newly inserted USB device  
9. type "lsblk" to check presence of "sdb"  
10. type "df -h" to check mounted devices (e.g. /dev/sda & /dev/sdb)  
11. type and check carefully the following command before execution  
    "sudo dd if=/dev/sda of=/dev/sdb status=progress"  
12. it takes several minutes to copy
14. after finished, type "df -h" to check mounted devices 
15. type "sudo umount /dev/sda"  
16. type "sudo umount /dev/sdb"  
17. now, 2 USB drives are safe to take out from USB port  
  
---------------------------------------------  
end of file
