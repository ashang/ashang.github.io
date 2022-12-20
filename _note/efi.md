---
title: uefi notes
date: 2012-07-09T16:04:56+08:00
---

Installing for x86_64-efi platform
EFI variables are not supported on this system.
EFI variables are not supported on this system.
grub-install: error: efibootmgr failed to registry the boot entry: No such file or directory.

For UEFI boot, the system partition must be located on a primary partition formatted with a fat fs, and c
ontained on a MBR or GPT labeled drive.
Further details can be found in the UEFI specifications (section 13.3) located at uefi.org.
The current version of the UEFI spec PDF (at time of writing the article) is available at: https://uefi.or
g/sites/default/files/resources/UEFI_Spec_2_8_final.pdf
Cause
Reason for the failure mentioned above was an attempt to install where /boot/efi was located on a logical
partition (/dev/sda5). This violates the UEFI specification.

    ssh root@172.16.0.131 "tar vcf - -C / root/v" | xz > EFI.tar.xz

efi/boot/bootia32.efi: PE32 executable (EFI application) Intel 80386 (stripped to external PDB), for MS Windows
efi/boot/bootx64.efi:  PE32+ executable (EFI application) x86-64 (stripped to external PDB), for MS Windows

efi.img: DOS/MBR boot sector, code offset 0x3c+2, OEM-ID "mkfs.fat", sectors/cluster 4, root entries 512, sectors 640 (volumes <=32 MB) , Media descriptor 0xf8, sectors/FAT 1, sectors/track 32, heads 64, serial number 0x1493d9e, unlabeled, FAT (12 bit)

UEFI is the commonly agreed on name for both the EFI & UEFI stand-
ards which merged. It does not include the old EFI v1, or Apple’s own
non-standard version of EFI.

Some newer hardware do not use the well-known BIOS to manage
boot options. Instead, a new one named UEFI (Unified Extensible
Firmware Interface) is used. It still has BIOS-like menus and often
has a legacy mode, which uses BIOS. UEFI often goes hand in hand
with the infamous Secure Boot option that makes it more difficult
to boot operating systems.

ensure that your machine does not
have Secure Boot enabled. Only a very limited number of operat-
ing systems will boot with this enabled. You must disable Secure
Boot in your BIOS before proceeding

# /boot/efi


choose /boot/efi as the
mount point. The contents of
the partition will be access-
ible from this directory



##


```
# MBR, Master Boot Record
* 只允许4个主分区，或3个主分区+1个扩展分区
* 在扩展分区中可以分任意多个逻辑分区
* 在扩展分区中以链表形式存储逻辑分区信息
* 用1字节来表示分区类型
* 用32位二进制数表示分区地址，块大小通常为512字节
 * 2^32*512=2TiB，即，不支持2TiB以上的分区

# BIOS, Basic Input-Output System

启动过程：
* 上电，开机自检
* BIOS初始化必要硬件（磁盘、键盘等等）
* BIOS读取第一块硬盘的前440字节并执行
* MBR从BIOS获取控制权并调用boot loader的第二部分
* 引导真正的操作系统

# GPT, GUID Partition Table
* 64位地址，最大支持8ZiB分区
* 任意多个分区
* 用16字节GUID表示分区类型
* 尾部备份
```


# ESP

# GPT

GPT 分区表。为了安装 grub 以便启动，最好在开头分配 2M 空间给 grub 使用。

记得给这个分区 bios_grub 标志



# MBR to GPT

Linux下使用gdisk可以无损转换
只要用gdisk打开MBR设备，按w保存，即可
如果磁盘末尾被占用，需要事先缩减分区大小 34*512Byte
分区编号可能会有变动，需要调节/etc/fstab


# UEFI, Unified Extensible Firmware Interface
* 由Intel设计最初用于Itanium计算机
* 1.0的时候叫EFI，2.0的时候叫UEFI，最新版UEFI 2.4
* 从EFI分区中载入引导程序
 * 内核版本>3.3支持EFI BOOT STUB (不用boot loader直接启动)
 * Windows要求EFI分区是分区表中的第一个分区
 * Windows只有64位支持UEFI+GPT


# EFI

* 含有EFI文件夹的FAT 分区
* 在MBR中的代号是0xEF
* GPT中的GUID C12A7328-F81F-11D2-BA4B-00A0C93EC93B
* 通过cfdisk 或 cgdisk 来选择分区格式
* 移动设备只要格式化成FAT12 FAT16 FAT32即可作为EFI分区
* 默认执行/EFI/Boot/bootx64.efi

# UEFI 启动U盘

* 复制Archlinux安装光盘上的所有文件到U盘
* 复制Ubuntu除/EFI/Boot/BOOTX64.EFI之外的所有文件到U盘
* 复制Windows光盘除/EFI/Boot/bootx64.efi之外的文件到U盘
* 把光盘的/EFI/Boot/bootx64.efi复制到/EFI/Microsoft/Boot/下面

写菜单：
* /loader/entries/windows.conf:
	title Windows 8 Installer
	efi /EFI/Microsoft/Boot/bootx64.efi
* /loader/entries/ubuntu.conf:
	title Ubuntu Grub Menu
	efi /EFI/Boot/grubX64.EFI

## gummiboot


# sudo dpkg-reconfigure grub-efi-amd64

    Configuring grub-efi-amd64

    Some EFI-based systems are buggy and do not handle new bootloaders correctly. If you force an extra installation of GRUB to the EFI removable media path, this should ensure that this system will boot

    Debian correctly despite such a problem. However, it may remove the ability to boot any other operating systems that also depend on this path. If so, you will need to make sure that GRUB is configured
    successfully to be able to boot any other OS installations correctly.

    Force extra installation to the EFI removable media path?

    <Yes>

    Generating grub configuration file ...
    Found background image: /usr/share/images/desktop-base/desktop-grub.png
    Found linux image: /boot/vmlinuz-3.16.0-4-amd64
    Found initrd image: /boot/initrd.img-3.16.0-4-amd64
    done

## Dump fw using flashrom

    sudo ./flashrom -p internal -r mbp-late-2013.bin

    flashrom v0.9.8-r1888 on Darwin 14.4.0 (x86_64)
    flashrom is free software, get the source code at http://www.flashrom.org

    Calibrating delay loop... OK.
    No DMI table found.
    Found chipset "Intel Lynx Point LP Premium".
    This chipset is marked as untested. If you are using an up-to-date version
    of flashrom *and* were (not) able to successfully update your firmware with it,
    then please email a report to flashrom@flashrom.org including a verbose (-V) log.
    Thank you!
    Enabling flash write... Warning: SPI Configuration Lockdown activated.
    FREG0: Warning: Flash Descriptor region (0x00000000-0x00000fff) is read-only.
    FREG2: Warning: Management Engine region (0x00002000-0x0018ffff) is read-only.
    FREG4: Warning: Platform Data region (0x00001000-0x00001fff) is read-only.
    Not all flash regions are freely accessible by flashrom. This is most likely
    due to an active ME. Please see http://flashrom.org/ME for details.
    PR0: Warning: 0x00000000-0x00001fff is read-only.
    PR1: Warning: 0x00190000-0x0060ffff is read-only.
    PR2: Warning: 0x00632000-0x01ffffff is read-only.
    Writes have been disabled for safety reasons. You can enforce write
    support with the ich_spi_force programmer option, but you will most likely
    harm your hardware! If you force flashrom you will get no support if
    something breaks. On a few mainboards it is possible to enable write
    access by setting a jumper (see its documentation or the board itself).
    OK.
    Found Macronix flash chip "MX25L6405" (8192 kB, SPI) mapped at physical address 0x00000000ff800000.
    Found Macronix flash chip "MX25L6405D" (8192 kB, SPI) mapped at physical address 0x00000000ff800000.
    Found Macronix flash chip "MX25L6406E/MX25L6408E" (8192 kB, SPI) mapped at physical address 0x00000000ff800000.
    Found Macronix flash chip "MX25L6436E/MX25L6445E/MX25L6465E/MX25L6473E" (8192 kB, SPI) mapped at physical address 0x00000000ff800000.
    Multiple flash chip definitions match the detected chip(s): "MX25L6405", "MX25L6405D", "MX25L6406E/MX25L6408E", "MX25L6436E/MX25L6445E/MX25L6465E/MX25L6473E"
    Please specify which chip definition to use with the -c <chipname> option.

    $ sudo ./flashrom  -p internal -r mbp-late-2013.bin -c MX25L6405
    flashrom v0.9.8-r1888 on Darwin 14.4.0 (x86_64)
    flashrom is free software, get the source code at http://www.flashrom.org

    Calibrating delay loop... OK.
    No DMI table found.
    Found chipset "Intel Lynx Point LP Premium".
    This chipset is marked as untested. If you are using an up-to-date version
    of flashrom *and* were (not) able to successfully update your firmware with it,
    then please email a report to flashrom@flashrom.org including a verbose (-V) log.
    Thank you!
    Enabling flash write... Warning: SPI Configuration Lockdown activated.
    FREG0: Warning: Flash Descriptor region (0x00000000-0x00000fff) is read-only.
    FREG2: Warning: Management Engine region (0x00002000-0x0018ffff) is read-only.
    FREG4: Warning: Platform Data region (0x00001000-0x00001fff) is read-only.
    Not all flash regions are freely accessible by flashrom. This is most likely
    due to an active ME. Please see http://flashrom.org/ME for details.
    PR0: Warning: 0x00000000-0x00001fff is read-only.
    PR1: Warning: 0x00190000-0x0060ffff is read-only.
    PR2: Warning: 0x00632000-0x01ffffff is read-only.
    Writes have been disabled for safety reasons. You can enforce write
    support with the ich_spi_force programmer option, but you will most likely
    harm your hardware! If you force flashrom you will get no support if
    something breaks. On a few mainboards it is possible to enable write
    access by setting a jumper (see its documentation or the board itself).
    OK.
    Found Macronix flash chip "MX25L6405" (8192 kB, SPI) mapped at physical address 0x00000000ff800000.
    Reading flash... done.
```

## efivars

## efibootmgr

efibootmgr is a user-space application to modify the Extensible
     Firmware Interface (EFI) Boot Manager configuration.

`efibootmgr` can create and destroy boot entries, change the boot order, change the next running boot option.

Note: efibootmgr requires that the kernel module efivars be loaded prior
     to use. 'modprobe efivars' should do the trick if it does not
     automatically load.

efibootmgr is not a must for grub.

### efibootmgr to add a new boot entry

```sh
# efibootmgr -c -d /dev/sdb -p 1 -w -L debian -l '\EFI\debian\grubx64.efi'
```

```sh
$ efibootmgr
BootCurrent: 0000
Timeout: 0 seconds
BootOrder: 0000,0001,0002,0003,0004,000B,000C,000D
Boot0000* ubuntu
Boot0001* Diskette Drive
Boot0002* USB Storage Device
Boot0003* CD/DVD/CD-RW Drive
Boot0004* Onboard NIC
Boot000B* UEFI: BC501 NVMe SK hynix 256GB, Partition 1
Boot000C* UEFI: SanDisk
Boot000D* UEFI: SanDisk, Partition 2

$ efibootmgr -v
BootCurrent: 0000
Timeout: 0 seconds
BootOrder: 0000,0001,0002,0003,0004,000B,000C,000D
Boot0000* ubuntu	HD(1,GPT,8f5c5c70-5022-446c-b942-43624ed4f438,0x800,0x100000)/File(\EFI\ubuntu\grubx64.efi)
Boot0001* Diskette Drive	BBS(Floppy,Diskette Drive,0x0)..BO
Boot0002* USB Storage Device	BBS(USB,SanDisk,0x0)..BO
Boot0003* CD/DVD/CD-RW Drive	BBS(CDROM,CD/DVD/CD-RW Drive,0x0)..BO
Boot0004* Onboard NIC	BBS(Network,Onboard NIC,0x0)..BO
Boot000B* UEFI: BC501 NVMe SK hynix 256GB, Partition 1	HD(1,GPT,8f5c5c70-5022-446c-b942-43624ed4f438,0x800,0x100000)/File(\EFI\Boot\BootX64.efi)..BO
Boot000C* UEFI: SanDisk	PciRoot(0x0)/Pci(0x14,0x0)/USB(2,0)/CDROM(1,0x1bac,0x1700)..BO
Boot000D* UEFI: SanDisk, Partition 2	PciRoot(0x0)/Pci(0x14,0x0)/USB(2,0)/HD(2,MBR,0x48a59faf,0x865038,0x5c0)..BO
```

```sh
$ efibootmgr -v
BootCurrent: 000C
Timeout: 0 seconds
BootOrder: 0000,0001,0002,0003,0004,000B,000C
Boot0000* ubuntu        HD(1,MBR,0x6f20736b,0x800,0x1dff800)/File(\EFI\ubuntu\shimx64.efi)
Boot0001* Diskette Drive        BBS(Floppy,Diskette Drive,0x0)..BO
Boot0002* USB Storage Device    BBS(USB,General UDisk 5.00,0x0)..BO
Boot0003* CD/DVD/CD-RW Drive    BBS(CDROM,CD/DVD/CD-RW Drive,0x0)..BO
Boot0004* Onboard NIC   BBS(Network,Onboard NIC,0x0)..BO
Boot000B* UEFI: BC501 NVMe SK hynix 256GB, Partition 1  HD(1,GPT,8f5c5c70-5022-446c-b942-43624ed4f438,0x800,0x100000)/File(\EFI\Boot\BootX64.efi)..BO
Boot000C* UEFI: General UDisk 5.00, Partition 1 PciRoot(0x0)/Pci(0x14,0x0)/USB(1,0)/HD(1,MBR,0x6f20736b,0x800,0x1dff800)..BO
```

```sh
$ efibootmgr
BootCurrent: 0008
Timeout: 0 seconds
BootOrder: 0004,0002,0003,0001,0008,0009,000A
Boot0001* Diskette Drive
Boot0002* USB Storage Device
Boot0003* CD/DVD/CD-RW Drive
Boot0004* Onboard NIC
Boot0008* UEFI: General UDisk 5.00, Partition 1
Boot0009* UEFI: KingstonDataTraveler 3.0, Partition 1
Boot000A* UEFI: BC501 NVMe SK hynix 256GB, Partition 1
```

```sh
$ efibootmgr -h
efibootmgr version 17
usage: efibootmgr [options]
        -a | --active         sets bootnum active
        -A | --inactive       sets bootnum inactive
        -b | --bootnum XXXX   modify BootXXXX (hex)
        -B | --delete-bootnum delete bootnum
        -c | --create         create new variable bootnum and add to bootorder
        -C | --create-only      create new variable bootnum and do not add to bootorder
        -D | --remove-dups      remove duplicate values from BootOrder
        -d | --disk disk       (defaults to /dev/sda) containing loader
        -r | --driver         Operate on Driver variables, not Boot Variables.
        -e | --edd [1|3|-1]   force EDD 1.0 or 3.0 creation variables, or guess
        -E | --device num      EDD 1.0 device number (defaults to 0x80)
        -g | --gpt            force disk with invalid PMBR to be treated as GPT
        -i | --iface name     create a netboot entry for the named interface
        -l | --loader name     (defaults to "\EFI\debian\grub.efi")
        -L | --label label     Boot manager display label (defaults to "Linux")
        -m | --mirror-below-4G t|f mirror memory below 4GB
        -M | --mirror-above-4G X percentage memory to mirror above 4GB
        -n | --bootnext XXXX   set BootNext to XXXX (hex)
        -N | --delete-bootnext delete BootNext
        -o | --bootorder XXXX,YYYY,ZZZZ,...     explicitly set BootOrder (hex)
        -O | --delete-bootorder delete BootOrder
        -p | --part part        partition containing loader (defaults to 1 on partitioned devices)
        -q | --quiet            be quiet
        -t | --timeout seconds  set boot manager timeout waiting for user input.
        -T | --delete-timeout   delete Timeout.
        -u | --unicode | --UCS-2  handle extra args as UCS-2 (default is ASCII)
        -v | --verbose          print additional information
        -V | --version          return version and exit
        -w | --write-signature  write unique sig to MBR if needed
        -y | --sysprep          Operate on SysPrep variables, not Boot Variables.
        -@ | --append-binary-args file  append extra args from file (use "-" for stdin)
        -h | --help             show help/usage
```

HD（1,200,100600, 3a92c3e7-adc5-4fcc-8197-ac21b84b601d）

- 1 : partition number
- 200 : partition offset
- 100600 : partition size
- 3a92c3e7-adc5-4fcc-8197-ac21b84b601d : partition GUID

```
$ blkid
/dev/nvme0n1p1: UUID="A788-19DA" BLOCK_SIZE="512" TYPE="vfat" PARTLABEL="EFI System Partition" PARTUUID="8f5c5c70-5022-446c-b942-43624ed4f438"
/dev/nvme0n1p2: UUID="485b34be-0630-4139-b447-3c1f955730c1" BLOCK_SIZE="4096" TYPE="ext4" PARTUUID="16928b9b-c35c-4b6e-bafe-788536ab7927"
/dev/nvme0n1p3: UUID="1031b196-23ee-4714-b3b7-4fccf7e353c9" TYPE="crypto_LUKS" PARTUUID="9d99ca99-f8bd-4501-8b27-18b674b8577c"
/dev/mapper/nvme0n1p3_crypt: UUID="Z1G7sh-X9Mb-GBfF-JFpO-pcsR-0oHY-dXONKx" TYPE="LVM2_member"
/dev/mapper/vgubuntu-root: UUID="614ff63e-5d8a-4997-a0f7-f6d4564a235d" BLOCK_SIZE="4096" TYPE="ext4"
/dev/mapper/vgubuntu-swap_1: UUID="ace11117-6a37-43cc-b352-b9b7bb291571" TYPE="swap"
```

## Fallback Path

Weak EFI implementation only recognizes the fallback bootloader
某些比较脆弱的EFI实现，并不能认识我们的bootloader，导致启动的时候，他会查找默认的回退路径。

UEFI 规范定义了一种“回退”路径 (Fallback path)，用于启动此类启动管理器项，其工作原理类似于 BIOS 驱动器启动：它会在标准位置查找某些启动装载程序代码。但是其中的细节和 BIOS 不同。

当尝试以这种方式启动时，固件真正执行的操作相当简单。固件会遍历磁盘上的每个 EFI 系统分区（按照磁盘上的分区顺序）。在 ESP 内，固件将查找位于特定位置的具有特定名称的文件。在 x86-64 PC 上，固件会查找文件 \EFI\BOOT\BOOTx64.EFI。固件实际查找的是 \EFI\BOOT\BOOT{计算机类型简称}.EFI，其中，“x64”是 x86-64 PC 的“计算机类型简称”。文件名还有可能是 BOOTIA32.EFI (x86-32)、BOOTIA64.EFI (Itanium)、BOOTARM.EFI（AArch32，即32位ARM）和 BOOTAA64.EFI（AArch64，即64位ARM）。然后，固件将执行找到的第一个有效文件（当然，文件需要符合UEFI规范中定义的可执行格式）。


### 创建新的启动项
–create (-c) 表示要创建条目
–part (-p) 用于提供ESP所在的分区号
–disk (-d) 用于提供ESP所在的磁盘名称
–label (-L) 用于提供条目名称
–loader (-l) 用于提供要加载的EFI image

### 删除某启动项

       -b | --bootnum XXXX
              Modify BootXXXX (hex)
       -B | --delete-bootnum
              Delete bootnum

### 改变启动顺序

-o | --bootorder XXXX,YYYY,ZZZZ
Explicitly set BootOrder (hex).  Any value from 0 to FFFF is accepted so long as it corresponds to an existing Boot#### variable, and zero padding is not required.

出现在前面的启动项，启动优先级要高。

启用禁用启动项：
efibootmgr -a -b X  ==> 启用标号为X的启动项
efibootmgr -A -b X  ==> 禁用标号为X的启动项

https://blog.uncooperative.org/blog/2014/02/06/the-efi-system-partition/#fnref:3
https://blog.woodelf.org/2014/05/28/uefi-boot-how-it-works.html
http://www.rodsbooks.com/efi-bootloaders/installation.html#accessing
https://lockless.github.io/2018/05/13/UEFI-tool/


```
EFI/BOOT/vmlinuz
EFI/BOOT/elilo.conf
EFI/BOOT/MokManager.efi
EFI/BOOT/full.cz
EFI/BOOT/icons
EFI/BOOT/icons/os_unknown.icns
EFI/BOOT/icons/func_exit.icns
EFI/BOOT/icons/tool_shell.icns
EFI/BOOT/icons/func_reset.icns
EFI/BOOT/icons/func_shutdown.icns
EFI/BOOT/icons/vol_optical.icns
EFI/BOOT/icons/tool_part.icns
EFI/BOOT/icons/func_firmware.icns
EFI/BOOT/icons/vol_internal.icns
EFI/BOOT/icons/func_about.icns
EFI/BOOT/icons/vol_external.icns
EFI/BOOT/elilo.efi
EFI/BOOT/refind.conf
EFI/BOOT/grubx64.efi
EFI/BOOT/bootx64.efi
```


# kernel UEFI interface

The Linux kernel gives access to the UEFI configuration variables via a set of files under /sys, using two different interfaces.

The older interface was showing files under /sys/firmware/efi/vars.

The new interface is efivarfs, which will expose things in a slightly different format under /sys/firmware/efi/efivars.

This is the new preferred way of using UEFI configuration variables.

To make efivarfs available via manual mount.

```
# mount -t efivarfs efivarfs /sys/firmware/efi/efivars
```

Then efibootmgr and further tools relying on efivars should work again.


# Kernel changes

```
commit a9499fa7cd3fd4824a7202d00c766b269fa3bda6
Author: Tom Gundersen teg@jklm.no
Date: Fri Feb 8 15:37:06 2013 +0000

efi: split efisubsystem from efivars

This registers /sys/firmware/efi/{,systab,efivars/} whenever EFI is enabled
and the system is booted with EFI.

This allows
*) userspace to check for the existence of /sys/firmware/efi as a way
to determine whether or it is running on an EFI system.
*) 'mount -t efivarfs none /sys/firmware/efi/efivars' without manually
loading any modules.

[ Also, move the efivar API into vars.c and unconditionally compile it.
This allows us to move efivars.c, which now only contains the sysfs
variable code, into the firmware/efi directory. Note that the efivars.c
filename is kept to maintain backwards compatability with the old
efivars.ko module. With this patch it is now possible for efivarfs
to be built without CONFIG_EFI_VARS - Matt ]
```


```
commit d68772b7c83f4b518be15ae96f4827c8ed02f684
Author: Matt Fleming matt.fleming@intel.com
Date: Fri Feb 8 16:27:24 2013 +0000

efivarfs: Move to fs/efivarfs

Now that efivarfs uses the efivar API, move it out of efivars.c and
into fs/efivarfs where it belongs. This move will eventually allow us
to enable the efivarfs code without having to also enable
CONFIG_EFI_VARS built, and vice versa.

Furthermore, things like,

mount -t efivarfs none /sys/firmware/efi/efivars

will now work if efivarfs is built as a module without requiring the
use of MODULE_ALIAS(), which would have been necessary when the
efivarfs code was part of efivars.c.
```

# Links

- https://wiki.debian.org/UEFI
