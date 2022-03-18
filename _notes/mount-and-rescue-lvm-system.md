---
date: 2019-05-06
title: mount and rescue lvm system
---

  
  
  
**mount boot partition**  
  
# mount /dev/sda1 /opt  
  
# vi /opt/grub/grub.cfg  
  
menuentry  
  
search --no-floppy --fs-uuid --set $UUID_OF_BOOT_PARTITION  
linux /vmlinuz root=/dev/mapper/vg-root  
  
  
  
  
**mount root partition on lvm**  
   
# apt-get install lvm2  
  
# lvdisplay  
  
# lvchange -ay /dev/vg-label  
  
# mount /dev/mapper/vg-root /mnt  
  
# vi /mnt/etc/fstab  
  
UUID=$UUID_OF_BOOT_PARTITION /boot ext2 defaults 0 2  
 /dev/mapper/vg-root / ext4 defaults 0 2  
/dev/mapper/vg-home /home ext4 defaults 0 2  
  


![]()
