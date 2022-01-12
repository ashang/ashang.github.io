

menuentry "TITLE" {
  iso_path=PATH
  export iso_path
  search --set=root --file $iso_path
  loopback loop $iso_path
  root=(loop)
  configfile /boot/grub/loopback.cfg
  loopback --delete loop
}


menuentry "Ubuntu 10.04 loopback" {
  linux  /casper/vmlinuz boot=casper iso-scan/filename=$iso_path quiet splash --
  initrd /casper/initrd.lz 
}




+if [ ${iso_path} ] ; then
+    set loopback="findiso=${iso_path}"
+fi




+    linux   /boot/%SHORT_NAME%/linux26 apm=power-off quiet boot=live bootid=%BOOTID% "${loopback}" nomce 


# my /etc/grub.d/40_custom file...

#!/bin/sh
exec tail -n +3 $0
# This file provides an easy way to add custom menu entries.  Simply type the
# menu entries you want to add after this comment.  Be careful not to change
# the 'exec tail' line above.

menuentry "Install" {
    rmmod tpm
    set isofile="/ubuntu.iso"
    loopback loop (hd0,2)$isofile
    linux (loop)/casper/vmlinuz boot=casper iso-scan/filename=$isofile noprompt noeject
    initrd (loop)/casper/initrd
}
Remember to update grub after making the change.

sudo update-grub




menuentry "Focal Live ISO" {
set isofile="/ISO/focal-desktop-amd64.iso"
loopback loop (hd0,1)$isofile
    linux (loop)/casper/vmlinuz boot=casper iso-scan/filename=$isofile toram noeject
    initrd (loop)/casper/initrd
}



