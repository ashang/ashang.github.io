---
author: aaronshang
comments: true
date: 2011-06-29 04:39:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2011/06/29/mount-and-rescue-lvm-system-2/
slug: mount-and-rescue-lvm-system-2
title: mount and rescue lvm system
wordpress_id: 1042
---

  
  
  
**mount boot partition**  
  
sudo mount /dev/sda1 /opt  
  
sudo vi /opt/grub/grub.cfg  
  
menuentry  
  
search --no-floppy --fs-uuid --set $UUID_OF_BOOT_PARTITION  
linux /vmlinuz root=/dev/mapper/vg-root  
  
  
  
  
**mount root partition on lvm**  
   
sudo apt-get install lvm2  
  
sudo lvdisplay  
  
sudo lvchange -ay /dev/vg-label  
  
sudo mount /dev/mapper/vg-root /mnt  
  
sudo vi /mnt/etc/fstab  
  
UUID=$UUID_OF_BOOT_PARTITION /boot ext2 defaults 0 2  
 /dev/mapper/vg-root / ext4 defaults 0 2  
/dev/mapper/vg-home /home ext4 defaults 0 2  
  

