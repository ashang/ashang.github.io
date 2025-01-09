

$ mkdir ~/initramfs && cd ~/initramfs
$ cat /boot/initramfs-linux.img | gunzip -c | cpio -i --no-absolute-filenames

This will unpack the initramfs image under the ~/initramfs directory.  Browsing the ~/initramfs/bin directory it became clear that the copy of setfont was a symlink to the busybox executable and hence the busybox implementation.

The problem can be solved by adding setfont to the BINARIES array in mkinitcpio.conf and rebuilding the initramfs image.  This will copy the version of setfont provided by the kbd package into the initramfs image instead of relying on the busybox version of setfont which would otherwise be used by default.

```sh
update-initramfs: deferring update (trigger activated)
Processing triggers for initramfs-tools (0.140ubuntu13) ...
update-initramfs: Generating /boot/initrd.img-5.17.15-76051715-generic
kernelstub.Config    : INFO     Looking for configuration...
kernelstub           : INFO     System information: ###################################################################
    OS:..................Pop!_OS 22.04
    Root partition:....../dev/sdh2
    Root FS UUID:........8dd90615-c5ef-4115-b2d3-8385d1a2061e
    ESP Path:............/boot/efi
    ESP Partition:......./dev/sdh1
    ESP Partition #:.....1
    NVRAM entry #:.......-1
    Boot Variable #:.....0000
    Kernel Boot Options:.quiet loglevel=0 systemd.show_status=false splash
    Kernel Image Path:.../boot/vmlinuz-5.17.15-76051715-generic
    Initrd Image Path:.../boot/initrd.img-5.17.15-76051715-generic
    Force-overwrite:.....False

kernelstub.Installer : INFO     Copying Kernel into ESP
kernelstub.Installer : INFO     Copying initrd.img into ESP
kernelstub.Installer : INFO     Setting up loader.conf configuration
kernelstub.Installer : INFO     Making entry file for Pop!_OS
kernelstub.Installer : INFO     Backing up old kernel
kernelstub.Installer : INFO     No old kernel found, skipping
```

```

$ sudo apt install nvidia-dkms-390
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
The following additional packages will be installed:
  nvidia-kernel-common-390 nvidia-kernel-source-390
The following NEW packages will be installed:
  nvidia-dkms-390 nvidia-kernel-common-390 nvidia-kernel-source-390
0 upgraded, 3 newly installed, 0 to remove and 134 not upgraded.
Need to get 10.1 MB of archives.
After this operation, 28.7 MB of additional disk space will be used.
Do you want to continue? [Y/n]
Get:1 http://mirrors.ustc.edu.cn/ubuntu jammy-security/restricted amd64 nvidia-kernel-source-390 amd64 390.151-0ubuntu0.22.04.1 [10.1 MB]
Get:2 http://mirrors.ustc.edu.cn/ubuntu jammy-security/restricted amd64 nvidia-kernel-common-390 amd64 390.151-0ubuntu0.22.04.1 [9796 B]
Get:3 http://mirrors.ustc.edu.cn/ubuntu jammy-security/restricted amd64 nvidia-dkms-390 amd64 390.151-0ubuntu0.22.04.1 [38.5 kB]
Fetched 10.1 MB in 1s (8464 kB/s)
Selecting previously unselected package nvidia-kernel-source-390.
(Reading database ... 385690 files and directories currently installed.)
Preparing to unpack .../nvidia-kernel-source-390_390.151-0ubuntu0.22.04.1_amd64.deb ...
Unpacking nvidia-kernel-source-390 (390.151-0ubuntu0.22.04.1) ...
Selecting previously unselected package nvidia-kernel-common-390.
Preparing to unpack .../nvidia-kernel-common-390_390.151-0ubuntu0.22.04.1_amd64.deb ...
Unpacking nvidia-kernel-common-390 (390.151-0ubuntu0.22.04.1) ...
Selecting previously unselected package nvidia-dkms-390.
Preparing to unpack .../nvidia-dkms-390_390.151-0ubuntu0.22.04.1_amd64.deb ...
Unpacking nvidia-dkms-390 (390.151-0ubuntu0.22.04.1) ...
Setting up nvidia-kernel-common-390 (390.151-0ubuntu0.22.04.1) ...
update-initramfs: deferring update (trigger activated)
update-initramfs: Generating /boot/initrd.img-5.16.19-76051619-generic
cat: /var/tmp/mkinitramfs_Y6lrcr/lib/modules/5.16.19-76051619-generic/modules.builtin: No such file or directory
W: Can't find modules.builtin.modinfo (for locating built-in drivers' firmware, supported in Linux >=5.2)
depmod: WARNING: could not open modules.order at /var/tmp/mkinitramfs_Y6lrcr/lib/modules/5.16.19-76051619-generic: No such file or directory
depmod: WARNING: could not open modules.builtin at /var/tmp/mkinitramfs_Y6lrcr/lib/modules/5.16.19-76051619-generic: No such file or directory
kernelstub.Config    : INFO     Looking for configuration...
kernelstub           : INFO     System information:

    OS:..................Pop!_OS 22.04
    Root partition:....../dev/sdh2
    Root FS UUID:........8dd90615-c5ef-4115-b2d3-8385d1a2061e
    ESP Path:............/boot/efi
    ESP Partition:......./dev/sdh1
    ESP Partition #:.....1
    NVRAM entry #:.......-1
    Boot Variable #:.....0000
    Kernel Boot Options:.quiet loglevel=0 systemd.show_status=false splash
    Kernel Image Path:.../boot/vmlinuz-5.17.15-76051715-generic
    Initrd Image Path:.../boot/initrd.img-5.17.15-76051715-generic
    Force-overwrite:.....False

kernelstub.Installer : INFO     Copying Kernel into ESP
kernelstub.Installer : INFO     Copying initrd.img into ESP
kernelstub.Installer : INFO     Setting up loader.conf configuration
kernelstub.Installer : INFO     Making entry file for Pop!_OS
kernelstub.Installer : INFO     Backing up old kernel
kernelstub.Installer : INFO     No old kernel found, skipping
Setting up nvidia-kernel-source-390 (390.151-0ubuntu0.22.04.1) ...
Setting up nvidia-dkms-390 (390.151-0ubuntu0.22.04.1) ...
update-initramfs: deferring update (trigger activated)
update-initramfs: Generating /boot/initrd.img-5.16.19-76051619-generic
cat: /var/tmp/mkinitramfs_LQwPru/lib/modules/5.16.19-76051619-generic/modules.builtin: No such file or directory
W: Can't find modules.builtin.modinfo (for locating built-in drivers' firmware, supported in Linux >=5.2)
depmod: WARNING: could not open modules.order at /var/tmp/mkinitramfs_LQwPru/lib/modules/5.16.19-76051619-generic: No such file or directory
depmod: WARNING: could not open modules.builtin at /var/tmp/mkinitramfs_LQwPru/lib/modules/5.16.19-76051619-generic: No such file or directory

Progress: [ 85%] [##################################################################################...............]

kernelstub.Config    : INFO     Looking for configuration...
kernelstub           : INFO     System information:

    OS:..................Pop!_OS 22.04
    Root partition:....../dev/sdh2
    Root FS UUID:........8dd90615-c5ef-4115-b2d3-8385d1a2061e
    ESP Path:............/boot/efi
    ESP Partition:......./dev/sdh1
    ESP Partition #:.....1
    NVRAM entry #:.......-1
    Boot Variable #:.....0000
    Kernel Boot Options:.quiet loglevel=0 systemd.show_status=false splash
    Kernel Image Path:.../boot/vmlinuz-5.17.15-76051715-generic
    Initrd Image Path:.../boot/initrd.img-5.17.15-76051715-generic
    Force-overwrite:.....False

kernelstub.Installer : INFO     Copying Kernel into ESP
kernelstub.Installer : INFO     Copying initrd.img into ESP
kernelstub.Installer : INFO     Setting up loader.conf configuration
kernelstub.Installer : INFO     Making entry file for Pop!_OS
kernelstub.Installer : INFO     Backing up old kernel
kernelstub.Installer : INFO     No old kernel found, skipping
INFO:Enable nvidia
DEBUG:Parsing /usr/share/ubuntu-drivers-common/quirks/dell_latitude
DEBUG:Parsing /usr/share/ubuntu-drivers-common/quirks/lenovo_thinkpad
DEBUG:Parsing /usr/share/ubuntu-drivers-common/quirks/put_your_quirks_here
Loading new nvidia-390.151 DKMS files...
Building for 5.16.19-76051619-generic 5.17.15-76051715-generic
Building for architecture x86_64
Module build for kernel 5.16.19-76051619-generic was skipped since the
kernel headers for this kernel does not seem to be installed.
Building initial module for 5.17.15-76051715-generic
Done.

nvidia.ko:
Running module version sanity check.
 - Original module
   - No original module exists within this kernel
 - Installation
   - Installing to /lib/modules/5.17.15-76051715-generic/kernel/drivers/char/drm/

nvidia-modeset.ko:
Running module version sanity check.
 - Original module
   - No original module exists within this kernel
 - Installation
   - Installing to /lib/modules/5.17.15-76051715-generic/kernel/drivers/char/drm/

nvidia-drm.ko:
Running module version sanity check.
 - Original module
   - No original module exists within this kernel
 - Installation
   - Installing to /lib/modules/5.17.15-76051715-generic/kernel/drivers/char/drm/

depmod...
Processing triggers for initramfs-tools (0.140ubuntu13) ...
update-initramfs: Generating /boot/initrd.img-5.17.15-76051715-generic
kernelstub.Config    : INFO     Looking for configuration...
kernelstub           : INFO     System information:

    OS:..................Pop!_OS 22.04
    Root partition:....../dev/sdh2
    Root FS UUID:........8dd90615-c5ef-4115-b2d3-8385d1a2061e
    ESP Path:............/boot/efi
    ESP Partition:......./dev/sdh1
    ESP Partition #:.....1
    NVRAM entry #:.......-1
    Boot Variable #:.....0000
    Kernel Boot Options:.quiet loglevel=0 systemd.show_status=false splash
    Kernel Image Path:.../boot/vmlinuz-5.17.15-76051715-generic
    Initrd Image Path:.../boot/initrd.img-5.17.15-76051715-generic
    Force-overwrite:.....False

kernelstub.Installer : INFO     Copying Kernel into ESP
kernelstub.Installer : INFO     Copying initrd.img into ESP
kernelstub.Installer : INFO     Setting up loader.conf configuration
kernelstub.Installer : INFO     Making entry file for Pop!_OS
kernelstub.Installer : INFO     Backing up old kernel
kernelstub.Installer : INFO     No old kernel found, skipping

```
