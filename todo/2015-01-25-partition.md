

# sda 1TiB

$ sudo fdisk -l

Disk /dev/sda: 698.7 GiB, 750156374016 bytes, 1465149168 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes
Disklabel type: dos
Disk identifier: 0x1460d26f

Device     Boot      Start        End    Sectors   Size Id Type
/dev/sda1             2048     616447     614400   300M  b W95 FAT32
/dev/sda2           616448  436454239  435837792 207.8G  7 HPFS/NTFS/exFAT
/dev/sda3  *    1464530944 1465145343     614400   300M  7 HPFS/NTFS/exFAT
/dev/sda4        436455422 1464530943 1028075522 490.2G  5 Extended
/dev/sda5       1448005632 1464530943   16525312   7.9G 82 Linux swap / Solaris
/dev/sda6        436455424 1448005631 1011550208 482.4G 83 Linux

Partition 5 does not start on physical sector boundary.



# 32GiB by dd from iso

Partition table entries are not in disk order.
Disk /dev/sdb: 30.1 GiB, 32327073792 bytes, 63138816 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0x15a8a090

Device     Boot Start     End Sectors  Size Id Type
/dev/sdb1  *       64 2004991 2004928  979M 17 Hidden HPFS/NTFS


# 4GiB by dd from iso

    Disk /dev/sdb: 3.8 GiB, 4038066176 bytes, 7886848 sectors
    Units: sectors of 1 * 512 = 512 bytes
    Sector size (logical/physical): 512 bytes / 512 bytes
    I/O size (minimum/optimal): 512 bytes / 512 bytes
    Disklabel type: dos
    Disk identifier: 0x15a8a090

    Device     Boot Start     End Sectors  Size Id Type
    /dev/sdb1  *       64 2004991 2004928  979M 17 Hidden HPFS/NTFS


    $ sudo mount -o rw /dev/sdb video/
    mount: /dev/sdb is write-protected, mounting read-only

    $ sudo cp git_cheat_sheet.pdf video/
    cp: cannot create regular file ‘video/git_cheat_sheet.pdf’: Read-only file system

    $ sudo mkfs.vfat /dev/sdb 
    mkfs.fat 3.0.26 (2014-03-07)
    mkfs.vfat: Device partition expected, not making filesystem on entire device '/dev/sdb' (use -I to override)

    $ sudo mkfs.vfat -I /dev/sdb 
    mkfs.fat 3.0.26 (2014-03-07)

    $ sudo fdisk -l /dev/sdb

    Disk /dev/sdb: 3.8 GiB, 4038066176 bytes, 7886848 sectors
    Units: sectors of 1 * 512 = 512 bytes
    Sector size (logical/physical): 512 bytes / 512 bytes
    I/O size (minimum/optimal): 512 bytes / 512 bytes
    Disklabel type: dos
    Disk identifier: 0x00000000



mount manually

    $ sudo mount /dev/sdb /mnt

    $ mount

    /dev/sdb on /mnt type vfat (rw,relatime,fmask=0022,dmask=0022,codepage=437,iocharset=iso8859-1,shortname=mixed,errors=remount-ro)

mount by clicking in file manager, nautilus/nemo

    $ mount

    /dev/sdb on /media/aaron/CD2A-DFD4 type vfat (rw,nosuid,nodev,relatime,uid=1000,gid=1000,fmask=0022,dmask=0077,codepage=437,iocharset=iso8859-1,shortname=mixed,showexec,utf8,flush,errors=remount-ro,uhelper=udisks2)



#MBP

    *** Report for internal hard disk ***

    Current GPT partition table:
     #      Start LBA      End LBA  Type
     1             40       409639  EFI System (FAT)
     2         409640    487127591  Mac OS X HFS+
     3      487127592    488397127  Mac OS X Boot

    Current MBR partition table:
     # A    Start LBA      End LBA  Type
     1              1    488397167  ee  EFI Protective

    MBR contents:
     Boot Code: Unknown, but bootable

    Partition at LBA 40:
     Boot Code: None (Non-system disk message)
     File System: FAT32
     Listed in GPT as partition 1, type EFI System (FAT)

    Partition at LBA 409640:
     Boot Code: None
     File System: HFS Extended (HFS+)
     Listed in GPT as partition 2, type Mac OS X HFS+

    Partition at LBA 487127592:
     Boot Code: None
     File System: HFS Extended (HFS+)
     Listed in GPT as partition 3, type Mac OS X Boot


## fdisk 

WARNING: GPT (GUID Partition Table) detected on '/dev/sda'! The util fdisk doesn't support GPT. Use GNU Parted.


Disk /dev/sda: 250.1 GB, 250059350016 bytes
255 heads, 63 sectors/track, 30401 cylinders, total 488397168 sectors
Units = sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disk identifier: 0x00006283

   Device Boot      Start         End      Blocks   Id  System
/dev/sda1               1     1050623      525311+  ee  GPT
/dev/sda2   *     1050624   431645305   215297341   83  Linux
/dev/sda3       431646720   488396799    28375040   83  Linux



### GPT

	sudo fdisk -l /dev/sdb

	WARNING: GPT (GUID Partition Table) detected on '/dev/sdb'! The util fdisk doesn't support GPT. Use GNU Parted.


	Disk /dev/sdb: 32.3 GB, 32327073792 bytes
	64 heads, 32 sectors/track, 30829 cylinders, total 63138816 sectors
	Units = sectors of 1 * 512 = 512 bytes
	Sector size (logical/physical): 512 bytes / 512 bytes
	I/O size (minimum/optimal): 512 bytes / 512 bytes
	Disk identifier: 0x3a456c00

	   Device Boot      Start         End      Blocks   Id  System
	/dev/sdb1   *           0     2245535     1122768    0  Empty
	/dev/sdb2         2203928     2208471        2272   ef  EFI (FAT-12/16/32)
	/dev/sdb3         2246656    63138815    30446080    b  W95 FAT32




	sudo parted -l /dev/sdb

	Model: ATA HGST HTS541075A9 (scsi)
	Disk /dev/sda: 750GB
	Sector size (logical/physical): 512B/4096B
	Partition Table: msdos

	Number  Start   End     Size    Type      File system  Flags
	 1      1049kB  1024MB  1023MB  primary   ext2         boot
	 2      1026MB  750GB   749GB   extended
	 5      1026MB  750GB   749GB   logical                lvm


	Warning: /dev/sdb contains GPT signatures, indicating that it has a GPT table.
	However, it does not have a valid fake msdos partition table, as it should.
	Perhaps it was corrupted -- possibly by a program that doesn't understand GPT
	partition tables.  Or perhaps you deleted the GPT table, and are now using an
	msdos partition table.  Is this a GPT partition table?
	Yes/No? y                                                                 
	Error: Both the primary and backup GPT tables are corrupt.  Try making a fresh table, and using Parted's rescue feature to recover partitions.

	Model: TOSHIBA External USB 3.0 (scsi)
	Disk /dev/sdc: 1000GB
	Sector size (logical/physical): 512B/512B
	Partition Table: msdos

	Number  Start   End     Size    Type     File system  Flags
	 1      1049kB  1000GB  1000GB  primary  ntfs         boot


	Model: Linux device-mapper (linear) (dm)
	Disk /dev/mapper/vg_local-root: 725GB
	Sector size (logical/physical): 512B/4096B
	Partition Table: loop

	Number  Start  End    Size   File system  Flags
	 1      0.00B  725GB  725GB  ext4


	Model: Linux device-mapper (linear) (dm)
	Disk /dev/mapper/vg_local-swap: 8464MB
	Sector size (logical/physical): 512B/4096B
	Partition Table: loop

	Number  Start  End     Size    File system     Flags
	 1      0.00B  8464MB  8464MB  linux-swap(v1)


	Model: Linux device-mapper (linear) (dm)
	Disk /dev/mapper/vg_local-log: 1023MB
	Sector size (logical/physical): 512B/4096B
	Partition Table: loop

	Number  Start  End     Size    File system  Flags
	 1      0.00B  1023MB  1023MB  ext4






