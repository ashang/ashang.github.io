---
title: partions with fdisk/gdisk/parted
date: 2009-04-10
---

```
# parted -l
Error: /dev/sda: unrecognised disk label
Model: ATA TOSHIBA MQ01ABF0 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: unknown
Disk Flags:


Model: BC501 NVMe SK hynix 256GB (nvme)
Disk /dev/nvme0n1: 256GB
Sector size (logical/physical): 512B/512B
Partition Table: gpt
Disk Flags:

Number  Start   End    Size   File system  Name  Flags
 1      2097kB  317MB  315MB  fat32              boot, esp
 2      317MB   256GB  256GB

Model: SanDisk Cruzer Fit (scsi)
Disk /dev/sdb: 8003MB
Sector size (logical/physical): 512B/512B
Partition Table: loop
Disk Flags:

Number  Start  End     Size    File system  Flags
 1      0.00B  8003MB  8003MB  udf


$ partx --show /dev/sdb
partx: cannot open /dev/sdb: Permission denied

# partx --show /dev/sdb
NR START      END  SECTORS SIZE NAME   UUID
 1    34 15630302 15630269 7.5G mypart 81d4f17d-bdaf-48ac-bbf5-58fb14bd5e48

partx: telling the kernel about disk partitions

Sometimes it's necessary to logically remove (or hide) a device or some of its partitions from the kernel, without having to actually do it physically. The partx(8) program we have developed (although the original idea was written by Andries E. Brouwer) does exactly this, by using the BLKPG ioctl to add and remove partitions from the kernel's sight.

Note that this is not an fdisk-like program as it doesn't actually write anything to the disk layout, however, it can be used for listing on-disk partitions:

# partx --show /dev/sda
NR     START       END   SECTORS   SIZE NAME UUID
 1      2048 214843391 214841344 102.5G
 2 214845438 488396799 273551362 130.5G
 5 214845440 215093247    247808   121M
 6 215095296 468518911 253423616 120.9G
 7 468520960 488396799  19875840   9.5G

So, say we just inserted a SD card and we want to hide one of the partitions from the kernel with out really doing anything to the device - make sure that the device is actually unmounted:

# fdisk -l
Disk /dev/nvme0n1: 238.47 GiB, 256060514304 bytes, 500118192 sectors
Disk model: BC501 NVMe SK hynix 256GB
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: gpt
Disk identifier: 8AC21900-9255-EA4D-A0E0-47B1F773F806

Device          Start       End   Sectors   Size Type
/dev/nvme0n1p1   4096    618495    614400   300M EFI System
/dev/nvme0n1p2 618496 500103449 499484954 238.2G Linux filesystem


Disk /dev/sda: 465.76 GiB, 500107862016 bytes, 976773168 sectors
Disk model: TOSHIBA MQ01ABF0
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/mapper/luks-ff0fbd30-38f7-464b-9747-c45c103e9d2a: 238.17 GiB, 255734199296 bytes, 499480858 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/mapper/luks-74239f0d-c496-448e-8113-2d2ce0a79f3a: 465.75 GiB, 500091084800 bytes, 122092550 sectors
Units: sectors of 1 * 4096 = 4096 bytes
Sector size (logical/physical): 4096 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/sdb: 7.45 GiB, 8002732032 bytes, 15630336 sectors
Disk model: Cruzer Fit
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes

# parted -l
Model: ATA TOSHIBA MQ01ABF0 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End    Size   File system  Name    Flags
 1      17.4kB  500GB  500GB               mypart  msftdata

 $ sudo parted -l
Error: /dev/sda: unrecognised disk label
Model: ATA TOSHIBA MQ01ABF0 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: unknown
Disk Flags:


 $ sudo parted /dev/sda
GNU Parted 3.4
Using /dev/sda
Welcome to GNU Parted! Type 'help' to view a list of commands.
(parted) help
  align-check TYPE N                       check partition N for TYPE(min|opt) alignment
  help [COMMAND]                           print general help, or help on COMMAND
  mklabel,mktable LABEL-TYPE               create a new disklabel (partition table)
  mkpart PART-TYPE [FS-TYPE] START END     make a partition
  name NUMBER NAME                         name partition NUMBER as NAME
  print [devices|free|list,all|NUMBER]     display the partition table, available devices, free space, all found partitions, or a particular partition
  quit                                     exit program
  rescue START END                         rescue a lost partition near START and END
  resizepart NUMBER END                    resize partition NUMBER
  rm NUMBER                                delete partition NUMBER
  select DEVICE                            choose the device to edit
  disk_set FLAG STATE                      change the FLAG on selected device
  disk_toggle [FLAG]                       toggle the state of FLAG on selected device
  set NUMBER FLAG STATE                    change the FLAG on partition NUMBER
  toggle [NUMBER [FLAG]]                   toggle the state of FLAG on partition NUMBER
  unit UNIT                                set the default unit to UNIT
  version                                  display the version number and copyright information of GNU Parted
(parted) h
  align-check TYPE N                       check partition N for TYPE(min|opt) alignment
  help [COMMAND]                           print general help, or help on COMMAND
  mklabel,mktable LABEL-TYPE               create a new disklabel (partition table)
  mkpart PART-TYPE [FS-TYPE] START END     make a partition
  name NUMBER NAME                         name partition NUMBER as NAME
  print [devices|free|list,all|NUMBER]     display the partition table, available devices, free space, all found partitions, or a particular partition
  quit                                     exit program
  rescue START END                         rescue a lost partition near START and END
  resizepart NUMBER END                    resize partition NUMBER
  rm NUMBER                                delete partition NUMBER
  select DEVICE                            choose the device to edit
  disk_set FLAG STATE                      change the FLAG on selected device
  disk_toggle [FLAG]                       toggle the state of FLAG on selected device
  set NUMBER FLAG STATE                    change the FLAG on partition NUMBER
  toggle [NUMBER [FLAG]]                   toggle the state of FLAG on partition NUMBER
  unit UNIT                                set the default unit to UNIT
  version                                  display the version number and copyright information of GNU Parted
(parted) mklabel
New disk label type? gpt
(parted) h
  align-check TYPE N                       check partition N for TYPE(min|opt) alignment
  help [COMMAND]                           print general help, or help on COMMAND
  mklabel,mktable LABEL-TYPE               create a new disklabel (partition table)
  mkpart PART-TYPE [FS-TYPE] START END     make a partition
  name NUMBER NAME                         name partition NUMBER as NAME
  print [devices|free|list,all|NUMBER]     display the partition table, available devices, free space, all found partitions, or a particular partition
  quit                                     exit program
  rescue START END                         rescue a lost partition near START and END
  resizepart NUMBER END                    resize partition NUMBER
  rm NUMBER                                delete partition NUMBER
  select DEVICE                            choose the device to edit
  disk_set FLAG STATE                      change the FLAG on selected device
  disk_toggle [FLAG]                       toggle the state of FLAG on selected device
  set NUMBER FLAG STATE                    change the FLAG on partition NUMBER
  toggle [NUMBER [FLAG]]                   toggle the state of FLAG on partition NUMBER
  unit UNIT                                set the default unit to UNIT
  version                                  display the version number and copyright information of GNU Parted
(parted) p
Model: ATA TOSHIBA MQ01ABF0 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: gpt
Disk Flags:

Number  Start  End  Size  File system  Name  Flags

(parted) mkpart
Partition name?  []?
File system type?  [ext2]? vfat
parted: invalid token: vfat
File system type?  [ext2]? fat32
Start?
Start? 0
End? h
Error: Invalid number.
(parted) mkpart
Partition name?  []? 00
File system type?  [ext2]? fat32
Start? 0
End? +200M
Error: Invalid number.
(parted) mkpart
Partition name?  []? 21
File system type?  [ext2]? fat32
Start? 0
End? 555555
Error: The location 555555 is outside of the device /dev/sda.
(parted) mkpart
align-check  help         mktable      quit         resizepart   set          version
disk_set     mklabel      name         rescue       rm           toggle
disk_toggle  mkpart       print        resize       select       unit
(parted) mkpart 22
align-check  help         mktable      quit         resizepart   set          version
disk_set     mklabel      name         rescue       rm           toggle
disk_toggle  mkpart       print        resize       select       unit
(parted) mkpart 22 fat32
align-check  help         mktable      quit         resizepart   set          version
disk_set     mklabel      name         rescue       rm           toggle
disk_toggle  mkpart       print        resize       select       unit
(parted) mkpart 22 fat32
Start? 0
End? 444
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? i
(parted) p
Model: ATA TOSHIBA MQ01ABF0 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End    Size   File system  Name  Flags
 1      17.4kB  444MB  444MB  fat32        22

(parted) h
  align-check TYPE N                       check partition N for TYPE(min|opt) alignment
  help [COMMAND]                           print general help, or help on COMMAND
  mklabel,mktable LABEL-TYPE               create a new disklabel (partition table)
  mkpart PART-TYPE [FS-TYPE] START END     make a partition
  name NUMBER NAME                         name partition NUMBER as NAME
  print [devices|free|list,all|NUMBER]     display the partition table, available devices, free space, all found partitions, or a particular partition
  quit                                     exit program
  rescue START END                         rescue a lost partition near START and END
  resizepart NUMBER END                    resize partition NUMBER
  rm NUMBER                                delete partition NUMBER
  select DEVICE                            choose the device to edit
  disk_set FLAG STATE                      change the FLAG on selected device
  disk_toggle [FLAG]                       toggle the state of FLAG on selected device
  set NUMBER FLAG STATE                    change the FLAG on partition NUMBER
  toggle [NUMBER [FLAG]]                   toggle the state of FLAG on partition NUMBER
  unit UNIT                                set the default unit to UNIT
  version                                  display the version number and copyright information of GNU Parted
(parted) set 1 flag boot
parted: invalid token: flag
Flag to Invert?
Flag to Invert? boot
New state?  [on]/off? on
(parted) p
Model: ATA TOSHIBA MQ01ABF0 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End    Size   File system  Name  Flags
 1      17.4kB  444MB  444MB  fat32        22    boot, esp

(parted) mkpart 22 fat32 0 -1
Error: Unable to satisfy all constraints on the partition.
(parted) q
Information: You may need to update /etc/fstab.

 $ sudo parted /dev/sda
GNU Parted 3.4
Using /dev/sda
Welcome to GNU Parted! Type 'help' to view a list of commands.
(parted) p
Model: ATA TOSHIBA MQ01ABF0 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End    Size   File system  Name  Flags
 1      17.4kB  444MB  444MB               22    boot, esp

(parted) mklabel gpt
Warning: The existing disk label on /dev/sda will be destroyed and all data on this disk will be lost. Do you want to
continue?
Yes/No? yes
(parted) p
Model: ATA TOSHIBA MQ01ABF0 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: gpt
Disk Flags:

Number  Start  End  Size  File system  Name  Flags

(parted) mkpart mypart ntfs 0 -1
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? i
(parted) p
Model: ATA TOSHIBA MQ01ABF0 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End    Size   File system  Name    Flags
 1      17.4kB  500GB  500GB  ntfs         mypart

(parted) q
Information: You may need to update /etc/fstab.

 $ df
Filesystem      Size  Used Avail Use% Mounted on
dev             7.7G     0  7.7G   0% /dev
run             7.7G  1.7M  7.7G   1% /run
/dev/dm-0       234G  220G  2.4G  99% /
tmpfs           7.7G  865M  6.9G  11% /dev/shm
tmpfs           7.7G  177M  7.6G   3% /tmp
/dev/nvme0n1p1  300M  448K  299M   1% /boot/efi
tmpfs           1.6G   92K  1.6G   1% /run/user/1000


 $ sudo parted /dev/sdb
GNU Parted 3.4
Using /dev/sdb
Welcome to GNU Parted! Type 'help' to view a list of commands.
(parted) p
Model: SanDisk Cruzer Fit (scsi)
Disk /dev/sdb: 8003MB
Sector size (logical/physical): 512B/512B
Partition Table: loop
Disk Flags:

Number  Start  End     Size    File system  Flags
 1      0.00B  8003MB  8003MB  udf

(parted) mklabel gpt
Warning: The existing disk label on /dev/sdb will be destroyed and all data on this disk will be lost. Do you want to
continue?
Yes/No? yes
(parted) p
Model: SanDisk Cruzer Fit (scsi)
Disk /dev/sdb: 8003MB
Sector size (logical/physical): 512B/512B
Partition Table: gpt
Disk Flags:

Number  Start  End  Size  File system  Name  Flags

Model: SanDisk Cruzer Fit (scsi)
Disk /dev/sdb: 8003MB
Sector size (logical/physical): 512B/512B
Partition Table: gpt
Disk Flags:

Number  Start  End  Size  File system  Name  Flags

(parted) mkpart mypart ntfs 0 1222
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? c
(parted) mkpart mypart ntfs 0 1444
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? c
(parted) mkpart mypart ntfs 0 1999
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? c
(parted) mkpart mypart ntfs 0 333
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? c
(parted) mkpart mypart ntfs 0 3333
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? c
(parted) mkpart mypart ntfs 0 6666
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? c
(parted) mkpart mypart ntfs 0 8888
Error: The location 8888 is outside of the device /dev/sdb.
(parted) mkpart mypart ntfs 0 7777
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? c
(parted) mkpart mypart ntfs 0 8444
Error: The location 8444 is outside of the device /dev/sdb.
(parted) mkpart mypart ntfs 0 8333
Error: The location 8333 is outside of the device /dev/sdb.
(parted) mkpart mypart ntfs 0 8222
Error: The location 8222 is outside of the device /dev/sdb.
(parted) mkpart mypart ntfs 0 8111
Error: The location 8111 is outside of the device /dev/sdb.
(parted) mkpart mypart ntfs 0 8002
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? c
(parted) mkpart mypart ntfs 0 8008
Error: The location 8008 is outside of the device /dev/sdb.
(parted) mkpart mypart ntfs 0 8007
Error: The location 8007 is outside of the device /dev/sdb.
(parted) mkpart mypart ntfs 0 8006
Error: The location 8006 is outside of the device /dev/sdb.
(parted) mkpart mypart ntfs 0 8005
Error: The location 8005 is outside of the device /dev/sdb.
(parted) mkpart mypart ntfs 0 8004
Error: The location 8004 is outside of the device /dev/sdb.
(parted) mkpart mypart ntfs 0 8003
Warning: The resulting partition is not properly aligned for best performance: 34s % 2048s != 0s
Ignore/Cancel? i
(parted) p
Model: SanDisk Cruzer Fit (scsi)
Disk /dev/sdb: 8003MB
Sector size (logical/physical): 512B/512B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name    Flags
 1      17.4kB  8003MB  8003MB  ntfs         mypart

(parted) h
  align-check TYPE N                       check partition N for TYPE(min|opt) alignment
  help [COMMAND]                           print general help, or help on COMMAND
  mklabel,mktable LABEL-TYPE               create a new disklabel (partition table)
  mkpart PART-TYPE [FS-TYPE] START END     make a partition
  name NUMBER NAME                         name partition NUMBER as NAME
  print [devices|free|list,all|NUMBER]     display the partition table, available devices, free space, all found
        partitions, or a particular partition
  quit                                     exit program
  rescue START END                         rescue a lost partition near START and END
  resizepart NUMBER END                    resize partition NUMBER
  rm NUMBER                                delete partition NUMBER
  select DEVICE                            choose the device to edit
  disk_set FLAG STATE                      change the FLAG on selected device
  disk_toggle [FLAG]                       toggle the state of FLAG on selected device
  set NUMBER FLAG STATE                    change the FLAG on partition NUMBER
  toggle [NUMBER [FLAG]]                   toggle the state of FLAG on partition NUMBER
  unit UNIT                                set the default unit to UNIT
  version                                  display the version number and copyright information of GNU Parted
(parted) toggle 1 boot
(parted) p
Model: SanDisk Cruzer Fit (scsi)
Disk /dev/sdb: 8003MB
Sector size (logical/physical): 512B/512B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name    Flags
 1      17.4kB  8003MB  8003MB  ntfs         mypart  boot, esp

(parted) w
  align-check TYPE N                       check partition N for TYPE(min|opt) alignment
  help [COMMAND]                           print general help, or help on COMMAND
  mklabel,mktable LABEL-TYPE               create a new disklabel (partition table)
  mkpart PART-TYPE [FS-TYPE] START END     make a partition
  name NUMBER NAME                         name partition NUMBER as NAME
  print [devices|free|list,all|NUMBER]     display the partition table, available devices, free space, all found
        partitions, or a particular partition
  quit                                     exit program
  rescue START END                         rescue a lost partition near START and END
  resizepart NUMBER END                    resize partition NUMBER
  rm NUMBER                                delete partition NUMBER
  select DEVICE                            choose the device to edit
  disk_set FLAG STATE                      change the FLAG on selected device
  disk_toggle [FLAG]                       toggle the state of FLAG on selected device
  set NUMBER FLAG STATE                    change the FLAG on partition NUMBER
  toggle [NUMBER [FLAG]]                   toggle the state of FLAG on partition NUMBER
  unit UNIT                                set the default unit to UNIT
  version                                  display the version number and copyright information of GNU Parted
(parted) q
Information: You may need to update /etc/fstab.


## dmesg

...
[ 1422.031169] usb 2-1: SerialNumber: 20071114173400000
[ 1422.048421] scsi4 : usb-storage 2-1:1.0
[ 1423.050540] scsi 4:0:0:0: Direct-Access     Generic- Multi-Card       1.00 PQ: 0 ANSI: 0 CCS
[ 1423.054202] sd 4:0:0:0: Attached scsi generic sg2 type 0
[ 1423.709440] sd 4:0:0:0: [sdd] 31326208 512-byte logical blocks: (16.0 GB/14.9 GiB)
[ 1423.710170] sd 4:0:0:0: [sdd] Write Protect is off
[ 1423.710175] sd 4:0:0:0: [sdd] Mode Sense: 03 00 00 00
[ 1423.710920] sd 4:0:0:0: [sdd] No Caching mode page present
[ 1423.710925] sd 4:0:0:0: [sdd] Assuming drive cache: write through
[ 1423.715545] sd 4:0:0:0: [sdd] No Caching mode page present
[ 1423.715551] sd 4:0:0:0: [sdd] Assuming drive cache: write through
[ 1423.716589]  sdd: sdd1
...

```
# partx -d /dev/sdd1
```

Make sure we haven't screwed up and actually deleted the partition:
```
# parted -l /dev/sdd

Model: Generic- Multi-Card (scsi)
Disk /dev/sdd: 16.0GB
Sector size (logical/physical): 512B/512B
Partition Table: msdos
Number  Start   End     Size    Type     File system  Flags
 1      4194kB  16.0GB  16.0GB  primary  fat32        lba

Recently we also support adding loop devices, so if we have an image file with the contents, we can map it to a block device:

# partx --show dos+bsd.img
NR START   END SECTORS SIZE NAME UUID
 1    32  7679    7648 3.8M
 2  7680 16383    8704 4.3M
 5  7936 12799    4864 2.4M
 6 12544 16127    3584 1.8M

Add the first five partitions, note that these don't have to be sequential:

# partx -a -n 1:5 images-pt/dos+bsd.img

# ls /dev/loop0* -ltr
brw-rw---- 1 root disk 7, 0 2011-08-15 00:07 /dev/loop0
brw-rw---- 1 root disk 7, 5 2011-08-15 00:07 /dev/loop0p5
brw-rw---- 1 root disk 7, 2 2011-08-15 00:07 /dev/loop0p2
brw-rw---- 1 root disk 7, 1 2011-08-15 00:07 /dev/loop0p1
```

Because this program uses the libblkid library to identify block devices and their information, it is limited to the partition types supported by this library. Currently this covers nearly all the commonly used ones, like DOS, GPT, BSD, SOLARIS, AIX and MAC, among others.


```
sed -i "s|^date: .*|date: $(date -I -d @$(( 1251110000 + 322200000 - $(/bin/cat /dev/urandom | tr -dc '1-9' | fold -w 8 | head -n 1) )))|"
```
