---
date: 2016-11-13
title: udevadm provides udevinfo
---

# apt-get install --reinstall initramfs-tools  bootcd-mkinitramfs   
E: dpkg was interrupted, you must manually run 'sudo dpkg --configure -a' to correct the problem.   
  
# dpkg --configure -a  
Setting up initramfs-tools (XXX) ...  
update-initramfs: deferring update (trigger activated)  
  
Processing triggers for initramfs-tools ...  
update-initramfs: Generating /boot/initrd.img-XXX  
cpio: ./bin/udevinfo: Cannot stat: No such file or directory  
update-initramfs: failed for /boot/initrd.img-XXX  
dpkg: subprocess post-installation script returned error exit status 1  
  
  
googled udevinfo man page:  


udevinfo - query device information from the udev database   
udevinfo [-q query-type] [-a ] [-p device-path] [-n node-name] [-r] [-e] [-V] [-h]   
  
udevinfo queries the udev database for device information stored in the udev database. It can also query the properties of a device from its sysfs representation to help creating udev rules that match this device. 

  
 

$ apt-cache search udevinfo 

Oops, no results,  
  
$ dpkg -L udev | \grep bin  
/sbin  
/sbin/udevadm  
/sbin/udevd  
/sbin/vol_id  
  
$ man udevadm  
  


udevadm info [options]

  
<it was in udevadm>  
  
dirty for dirty's sake  
  
# cp /sbin/udevadm /bin/udevinfo

  
done.   

