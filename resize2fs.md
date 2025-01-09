[garuda@garuda-sway ~]$ df
Filesystem         1K-blocks    Used Available Use% Mounted on
dev                165001548       0 165001548   0% /dev
run                165058580   18292 165040288   1% /run
/dev/mapper/ventoy   2319610 2319610         0 100% /run/miso/bootmnt
cowspace              262144       0    262144   0% /run/miso/cowspace
overlay_root       247587876   23080 247564796   1% /run/miso/overlay_root
/dev/loop0             30720   30720         0 100% /run/miso/sfs/livefs
/dev/loop1            365568  365568         0 100% /run/miso/sfs/mhwdfs
/dev/loop2           1088512 1088512         0 100% /run/miso/sfs/desktopfs
/dev/loop3            705536  705536         0 100% /run/miso/sfs/rootfs
overlay            247587876   23080 247564796   1% /
tmpfs              165058580     528 165058052   1% /dev/shm
tmpfs              165058584  463512 164595072   1% /tmp
tmpfs               33011716   15612  32996104   1% /run/user/1000
/dev/sda2             183060       0    183060   0% /boot/efi
[garuda@garuda-sway ~]$ sudo umount /boot/efi
[garuda@garuda-sway ~]$ sudo fdisk /dev/sda

Welcome to fdisk (util-linux 2.38.1).
Changes will remain in memory only, until you decide to write them.
Be careful before using the write command.


Command (m for help): p
Disk /dev/sda: 6 TiB, 6595056500736 bytes, 12880969728 sectors
Disk model: PERC H310
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: gpt
Disk identifier: 71B326E3-64A5-2D49-A547-6D994EA14368

Device           Start         End     Sectors  Size Type
/dev/sda1         2048 12880600000 12880597953    6T Linux filesystem
/dev/sda2  12880601088 12880967679      366592  179M EFI System

Command (m for help): d
Partition number (1,2, default 2): 3
Value out of range.
Partition number (1,2, default 2):
Command (m for help): q

[garuda@garuda-sway ~]$ sudo fsc /dev/sda
fsck           fsck.exfat     fsck.ext4      fsck.jfs       fsck.reiserfs  fscrypt
fsck.btrfs     fsck.ext2      fsck.f2fs      fsck.minix     fsck.vfat
fsck.cramfs    fsck.ext3      fsck.fat       fsck.msdos     fsck.xfs
[garuda@garuda-sway ~]$ sudo fsc /dev/sda
fsck           fsck.exfat     fsck.ext4      fsck.jfs       fsck.reiserfs  fscrypt
fsck.btrfs     fsck.ext2      fsck.f2fs      fsck.minix     fsck.vfat
fsck.cramfs    fsck.ext3      fsck.fat       fsck.msdos     fsck.xfs
[garuda@garuda-sway ~]$ sudo fsck /dev/sda1
fsck from util-linux 2.38.1
e2fsck 1.46.5 (30-Dec-2021)
/dev/sda1: recovering journal
Clearing orphaned inode 9833026 (uid=0, gid=0, mode=0100644, size=3053680)
Clearing orphaned inode 9830479 (uid=0, gid=0, mode=0100644, size=18344)
Clearing orphaned inode 9835431 (uid=0, gid=0, mode=0100755, size=4081448)
Clearing orphaned inode 9835187 (uid=0, gid=0, mode=0100644, size=3865168)
Clearing orphaned inode 9831651 (uid=0, gid=0, mode=0100644, size=763816)
Clearing orphaned inode 9833529 (uid=0, gid=0, mode=0100644, size=2197240)
Clearing orphaned inode 9839549 (uid=0, gid=0, mode=0100644, size=67576)
Clearing orphaned inode 9830409 (uid=0, gid=0, mode=0100644, size=1062968)
Clearing orphaned inode 10096465 (uid=0, gid=0, mode=0100644, size=3360)
Clearing orphaned inode 10096464 (uid=0, gid=0, mode=0100644, size=47)
Clearing orphaned inode 10096463 (uid=0, gid=0, mode=0100644, size=34)
Clearing orphaned inode 10096456 (uid=0, gid=0, mode=0100644, size=50)
Clearing orphaned inode 10096454 (uid=0, gid=0, mode=0100644, size=62)
Clearing orphaned inode 10096453 (uid=0, gid=0, mode=0100644, size=270)
Clearing orphaned inode 10096452 (uid=0, gid=0, mode=0100644, size=48)
Clearing orphaned inode 10096451 (uid=0, gid=0, mode=0100644, size=23)
Clearing orphaned inode 10096450 (uid=0, gid=0, mode=0100644, size=258)
Clearing orphaned inode 10096448 (uid=0, gid=0, mode=0100644, size=353616)
Clearing orphaned inode 10096447 (uid=0, gid=0, mode=0100644, size=1406)
Clearing orphaned inode 10092867 (uid=0, gid=0, mode=0100644, size=127)
Clearing orphaned inode 9848510 (uid=0, gid=0, mode=0100644, size=27028)
Clearing orphaned inode 9835440 (uid=0, gid=0, mode=0100644, size=14640)
Clearing orphaned inode 9835401 (uid=0, gid=0, mode=0100644, size=60328)
Clearing orphaned inode 9835374 (uid=0, gid=0, mode=0100644, size=14480)
Clearing orphaned inode 9835232 (uid=0, gid=0, mode=0100644, size=907784)
Clearing orphaned inode 9835175 (uid=0, gid=0, mode=0100644, size=14480)
Clearing orphaned inode 9831624 (uid=0, gid=0, mode=0100755, size=1922136)
Clearing orphaned inode 9831524 (uid=0, gid=0, mode=0100755, size=210968)
Clearing orphaned inode 16532944 (uid=0, gid=0, mode=040755, size=20480)
Clearing orphaned inode 16532961 (uid=0, gid=0, mode=0100755, size=24862720)
Clearing orphaned inode 16533024 (uid=0, gid=0, mode=0100755, size=178523294)
Clearing orphaned inode 16533034 (uid=0, gid=0, mode=0100755, size=13054821)
Clearing orphaned inode 16533038 (uid=0, gid=0, mode=0100755, size=39307906)
Clearing orphaned inode 16533044 (uid=0, gid=0, mode=0100755, size=46824658)
Clearing orphaned inode 16533106 (uid=0, gid=0, mode=0100755, size=13430784)
Clearing orphaned inode 16533132 (uid=0, gid=0, mode=0100755, size=10604544)
Clearing orphaned inode 16533136 (uid=0, gid=0, mode=0100755, size=80994304)
Clearing orphaned inode 16533156 (uid=0, gid=0, mode=0100755, size=14492288)
Clearing orphaned inode 16533157 (uid=0, gid=0, mode=0100755, size=8945664)
Clearing orphaned inode 16533186 (uid=0, gid=0, mode=0100755, size=19448)
Clearing orphaned inode 16533194 (uid=0, gid=0, mode=0100755, size=31200)
Clearing orphaned inode 16533214 (uid=0, gid=0, mode=0100755, size=47648)
Clearing orphaned inode 3292246 (uid=0, gid=0, mode=040755, size=12288)
Clearing orphaned inode 3292257 (uid=0, gid=0, mode=0100755, size=3338640)
Clearing orphaned inode 3292283 (uid=0, gid=0, mode=0100755, size=10752120)
Clearing orphaned inode 3292302 (uid=0, gid=0, mode=0100755, size=292744)
Clearing orphaned inode 3292311 (uid=0, gid=0, mode=0100755, size=12274080)
Clearing orphaned inode 3292312 (uid=0, gid=0, mode=0100755, size=683600)
Clearing orphaned inode 3292323 (uid=0, gid=0, mode=0100755, size=147576)
Clearing orphaned inode 3292324 (uid=0, gid=0, mode=0100755, size=125952)
Clearing orphaned inode 3932878 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3932879 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3934030 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3934031 (uid=0, gid=0, mode=0100755, size=273480)
Clearing orphaned inode 3934032 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3934033 (uid=0, gid=0, mode=0100755, size=38056)
Clearing orphaned inode 3934036 (uid=0, gid=0, mode=0100755, size=745296)
Clearing orphaned inode 3934037 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3934039 (uid=0, gid=0, mode=0100755, size=24272)
Clearing orphaned inode 3934041 (uid=0, gid=0, mode=0100755, size=28648)
Clearing orphaned inode 3934042 (uid=0, gid=0, mode=0100755, size=38560)
Clearing orphaned inode 3934043 (uid=0, gid=0, mode=0100755, size=48784)
Clearing orphaned inode 3934044 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3934049 (uid=0, gid=0, mode=0100755, size=19240)
Clearing orphaned inode 3934074 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3934093 (uid=0, gid=0, mode=0100755, size=22976)
Clearing orphaned inode 3934107 (uid=0, gid=0, mode=0100755, size=62712)
Clearing orphaned inode 3934109 (uid=0, gid=0, mode=0100755, size=16904)
Clearing orphaned inode 3934111 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3934113 (uid=0, gid=0, mode=0100755, size=23864)
Clearing orphaned inode 3934114 (uid=0, gid=0, mode=0100755, size=28640)
Clearing orphaned inode 3934119 (uid=0, gid=0, mode=0100755, size=28976)
Clearing orphaned inode 3934122 (uid=0, gid=0, mode=0100755, size=1112680)
Clearing orphaned inode 3934123 (uid=0, gid=0, mode=0100755, size=102960)
Clearing orphaned inode 3934124 (uid=0, gid=0, mode=0100755, size=88904)
Clearing orphaned inode 3934132 (uid=0, gid=0, mode=0100755, size=535472)
Clearing orphaned inode 3934133 (uid=0, gid=0, mode=0100755, size=108728)
Clearing orphaned inode 3934134 (uid=0, gid=0, mode=0100755, size=93336)
Clearing orphaned inode 3934136 (uid=0, gid=0, mode=0100755, size=226400)
Clearing orphaned inode 3934141 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3934142 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3934344 (uid=0, gid=0, mode=040755, size=28672)
Clearing orphaned inode 4460680 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 4460708 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 4460709 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 4460726 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 4460727 (uid=0, gid=0, mode=0100755, size=136448)
Clearing orphaned inode 4460728 (uid=0, gid=0, mode=0100755, size=76344)
Clearing orphaned inode 4464946 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 4464970 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 4464984 (uid=0, gid=0, mode=0100755, size=627440)
Clearing orphaned inode 3292385 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3293164 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3293165 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3293195 (uid=0, gid=0, mode=0100755, size=9528976)
Clearing orphaned inode 3293200 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3293233 (uid=0, gid=0, mode=0100755, size=358800)
Clearing orphaned inode 3421728 (uid=0, gid=0, mode=040755, size=4096)
Clearing orphaned inode 3421746 (uid=0, gid=0, mode=0100755, size=6771896)
Clearing orphaned inode 2240209 (uid=0, gid=0, mode=010600, size=0)
Clearing orphaned inode 1449254 (uid=0, gid=0, mode=010600, size=0)
Clearing orphaned inode 9832944 (uid=0, gid=0, mode=0100644, size=14256)
Clearing orphaned inode 9835969 (uid=0, gid=0, mode=0100644, size=219152)
Clearing orphaned inode 9831074 (uid=0, gid=0, mode=0100644, size=350608)
Clearing orphaned inode 9832055 (uid=0, gid=0, mode=0100644, size=183048)
Clearing orphaned inode 9831927 (uid=0, gid=0, mode=0100644, size=52224)
Clearing orphaned inode 9830630 (uid=0, gid=0, mode=0100644, size=888080)
Clearing orphaned inode 9830626 (uid=0, gid=0, mode=0100644, size=334584)
Clearing orphaned inode 9831307 (uid=0, gid=0, mode=0100644, size=840632)
Clearing orphaned inode 10093327 (uid=0, gid=0, mode=0100644, size=3331720)
Clearing orphaned inode 10093303 (uid=0, gid=0, mode=0100644, size=2054568)
Clearing orphaned inode 10097155 (uid=0, gid=0, mode=0100755, size=281096)
Clearing orphaned inode 10097137 (uid=0, gid=0, mode=0100755, size=92544)
Clearing orphaned inode 4456450 (uid=0, gid=0, mode=0100644, size=476048)
Clearing orphaned inode 9836497 (uid=0, gid=0, mode=0100644, size=404096)
Clearing orphaned inode 9832653 (uid=0, gid=0, mode=0100644, size=355328)
Setting free inodes count to 16164148 (was 16068958)
Setting free blocks count to 40722873 (was 55565855)
/dev/sda1: clean, 1841868/18006016 files, 31298375/72021248 blocks
[garuda@garuda-sway ~]$ sudo fsck /dev/sda1
fsck from util-linux 2.38.1
e2fsck 1.46.5 (30-Dec-2021)
/dev/sda1: clean, 1841868/18006016 files, 31298375/72021248 blocks
[garuda@garuda-sway ~]$ sudo mount /dev/sda1 /mnt
[garuda@garuda-sway ~]$ df
Filesystem         1K-blocks      Used Available Use% Mounted on
dev                165001548         0 165001548   0% /dev
run                165058580     18292 165040288   1% /run
/dev/mapper/ventoy   2319610   2319610         0 100% /run/miso/bootmnt
cowspace              262144         0    262144   0% /run/miso/cowspace
overlay_root       247587876     23752 247564124   1% /run/miso/overlay_root
/dev/loop0             30720     30720         0 100% /run/miso/sfs/livefs
/dev/loop1            365568    365568         0 100% /run/miso/sfs/mhwdfs
/dev/loop2           1088512   1088512         0 100% /run/miso/sfs/desktopfs
/dev/loop3            705536    705536         0 100% /run/miso/sfs/rootfs
overlay            247587876     23752 247564124   1% /
tmpfs              165058580       528 165058052   1% /dev/shm
tmpfs              165058584    463512 164595072   1% /tmp
tmpfs               33011716     15612  32996104   1% /run/user/1000
/dev/sda1          283369232 120477740 148470860  45% /mnt
[garuda@garuda-sway ~]$ cd /mnt/
[garuda@garuda-sway mnt]$ ls -la
total 104
drwxr-xr-x  16 root root    4096 Apr 24 17:20 .
drwxr-xr-x   1 root root     160 Apr 27 06:55 ..
lrwxrwxrwx   1 root root       7 Nov 18 07:42 bin -> usr/bin
drwxr-xr-x   3 root root    4096 Apr 24 17:21 boot
drwxr-xr-x   3 root root    4096 Aug 21  2013 dev
drwxr-xr-x 144 1002 garuda 12288 Apr 24 17:20 etc
drwxr-xr-x   2 root root    4096 Aug 21  2013 home
lrwxrwxrwx   1 root root      32 Apr 24 17:20 initrd.img -> boot/initrd.img-6.1.0-7-rt-amd64
lrwxrwxrwx   1 root root      33 Mar 31  2022 initrd.img.old -> boot/initrd.img-5.11.0-38-generic
-rw-r--r--   1 root root    1721 Nov 22  2011 inputrc
lrwxrwxrwx   1 root root       7 Nov 18 07:42 lib -> usr/lib
lrwxrwxrwx   1 root root       9 Nov 18 07:42 lib32 -> usr/lib32
lrwxrwxrwx   1 root root       9 Nov 18 07:42 lib64 -> usr/lib64
lrwxrwxrwx   1 root root      10 Nov 18 07:42 libx32 -> usr/libx32
drwxr-xr-x   2 root root    4096 Apr 20  2021 mnt
drwxr-xr-x  16 root root    4096 Apr  3 02:41 opt
drwxr-xr-x   2 root root    4096 Jan 25  2013 proc
drwx------   7 root root    4096 Apr 25 10:45 root
drwxr-xr-x   2 root root    4096 Aug 21  2013 run
lrwxrwxrwx   1 root root       8 Nov 18 07:42 sbin -> usr/sbin
drwxr-xr-x   2 root root    4096 Oct 18  2020 srv
drwxr-xr-x   2 root root    4096 Jul 26  2012 sys
drwxrwxrwt  29 root root   32768 Apr 27 09:59 tmp
drwxr-xr-x  16 1002 garuda  4096 Mar 29 08:31 usr
drwxr-xr-x  15 1002 garuda  4096 Mar 29 08:31 var
lrwxrwxrwx   1 root root      29 Apr 24 17:20 vmlinuz -> boot/vmlinuz-6.1.0-7-rt-amd64
lrwxrwxrwx   1 root root      30 Mar 31  2022 vmlinuz.old -> boot/vmlinuz-5.11.0-38-generic
[garuda@garuda-sway mnt]$ fd
-bash: fd: command not found
[garuda@garuda-sway mnt]$ df
Filesystem         1K-blocks      Used Available Use% Mounted on
dev                165001548         0 165001548   0% /dev
run                165058580     18292 165040288   1% /run
/dev/mapper/ventoy   2319610   2319610         0 100% /run/miso/bootmnt
cowspace              262144         0    262144   0% /run/miso/cowspace
overlay_root       247587876     23916 247563960   1% /run/miso/overlay_root
/dev/loop0             30720     30720         0 100% /run/miso/sfs/livefs
/dev/loop1            365568    365568         0 100% /run/miso/sfs/mhwdfs
/dev/loop2           1088512   1088512         0 100% /run/miso/sfs/desktopfs
/dev/loop3            705536    705536         0 100% /run/miso/sfs/rootfs
overlay            247587876     23916 247563960   1% /
tmpfs              165058580       528 165058052   1% /dev/shm
tmpfs              165058584    463512 164595072   1% /tmp
tmpfs               33011716     15612  32996104   1% /run/user/1000
/dev/sda1          283369232 121035444 147913156  46% /mnt
[garuda@garuda-sway mnt]$ df -h
Filesystem          Size  Used Avail Use% Mounted on
dev                 158G     0  158G   0% /dev
run                 158G   18M  158G   1% /run
/dev/mapper/ventoy  2.3G  2.3G     0 100% /run/miso/bootmnt
cowspace            256M     0  256M   0% /run/miso/cowspace
overlay_root        237G   24M  237G   1% /run/miso/overlay_root
/dev/loop0           30M   30M     0 100% /run/miso/sfs/livefs
/dev/loop1          357M  357M     0 100% /run/miso/sfs/mhwdfs
/dev/loop2          1.1G  1.1G     0 100% /run/miso/sfs/desktopfs
/dev/loop3          689M  689M     0 100% /run/miso/sfs/rootfs
overlay             237G   24M  237G   1% /
tmpfs               158G  528K  158G   1% /dev/shm
tmpfs               158G  453M  157G   1% /tmp
tmpfs                32G   16M   32G   1% /run/user/1000
/dev/sda1           271G  116G  142G  46% /mnt
[garuda@garuda-sway mnt]$ df
Filesystem         1K-blocks      Used Available Use% Mounted on
dev                165001548         0 165001548   0% /dev
run                165058580     18292 165040288   1% /run
/dev/mapper/ventoy   2319610   2319610         0 100% /run/miso/bootmnt
cowspace              262144         0    262144   0% /run/miso/cowspace
overlay_root       247587876     24028 247563848   1% /run/miso/overlay_root
/dev/loop0             30720     30720         0 100% /run/miso/sfs/livefs
/dev/loop1            365568    365568         0 100% /run/miso/sfs/mhwdfs
/dev/loop2           1088512   1088512         0 100% /run/miso/sfs/desktopfs
/dev/loop3            705536    705536         0 100% /run/miso/sfs/rootfs
overlay            247587876     24028 247563848   1% /
tmpfs              165058580       528 165058052   1% /dev/shm
tmpfs              165058584    463512 164595072   1% /tmp
tmpfs               33011716     15612  32996104   1% /run/user/1000
/dev/sda1          283369232 121035444 147913156  46% /mnt
[garuda@garuda-sway mnt]$ ls
bin   dev  home        initrd.img.old  lib    lib64   mnt  proc  run   srv  tmp  var      vmlinuz.old
boot  etc  initrd.img  inputrc         lib32  libx32  opt  root  sbin  sys  usr  vmlinuz
[garuda@garuda-sway mnt]$ cd
[garuda@garuda-sway ~]$ sudo umount /mnt
[garuda@garuda-sway ~]$ sudo fdisk -l /dev/sda
Disk /dev/sda: 6 TiB, 6595056500736 bytes, 12880969728 sectors
Disk model: PERC H310
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: gpt
Disk identifier: 71B326E3-64A5-2D49-A547-6D994EA14368

Device           Start         End     Sectors  Size Type
/dev/sda1         2048 12880600000 12880597953    6T Linux filesystem
/dev/sda2  12880601088 12880967679      366592  179M EFI System
[garuda@garuda-sway ~]$ sudo resize
resize2fs        resizecons       resize.f2fs      resizepart       resize_reiserfs
[garuda@garuda-sway ~]$ sudo resize2fs /dev/sda1
resize2fs 1.46.5 (30-Dec-2021)
Please run 'e2fsck -f /dev/sda1' first.

[garuda@garuda-sway ~]$ sudo fsck -f /dev/sda1
fsck from util-linux 2.38.1
e2fsck 1.46.5 (30-Dec-2021)
Pass 1: Checking inodes, blocks, and sizes
Inode 14680851 extent tree (at level 1) could be shorter.  Optimize<y>? yes

Inode 14681401 extent tree (at level 1) could be shorter.  Optimize<y>? yes
Inode 14681585 extent tree (at level 1) could be shorter.  Optimize<y>? yes

Inode 14681947 extent tree (at level 1) could be shorter.  Optimize<y>? yes
Inode 14681969 extent tree (at level 1) could be shorter.  Optimize<y>?
/dev/sda1: e2fsck canceled.

/dev/sda1: ********** WARNING: Filesystem still has errors **********

[garuda@garuda-sway ~]$ sudo fsck -ff /dev/sda1
fsck from util-linux 2.38.1
e2fsck 1.46.5 (30-Dec-2021)
Pass 1: Checking inodes, blocks, and sizes
^C/dev/sda1: e2fsck canceled.

/dev/sda1: ********** WARNING: Filesystem still has errors **********

[garuda@garuda-sway ~]$ sudo fsck -yf /dev/sda1
fsck from util-linux 2.38.1
e2fsck 1.46.5 (30-Dec-2021)
Pass 1: Checking inodes, blocks, and sizes
Inode 14680851 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14681401 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14681585 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14681947 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14681969 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14682034 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14682113 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14682227 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14682314 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14682618 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14683898 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14684118, end of extent exceeds allowed value
        (logical block 8334, physical block 61364599, len 1)
Clear? yes

Inode 14685363 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685371 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685603 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685631 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685721 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685757 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685798 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685812 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685843 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685869 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685943 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685945 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14685987 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14686040, end of extent exceeds allowed value
        (logical block 8407, physical block 71859953, len 1)
Clear? yes

Inode 14851806, end of extent exceeds allowed value
        (logical block 16, physical block 29658688, len 57)
Clear? yes

Inode 14851806, i_blocks is 536, should be 136.  Fix? yes

Inode 14851830 has an invalid extent node (blk 59283294, lblk 0)
Clear? yes

Inode 14851830 extent tree (at level 1) could be shorter.  Optimize? yes

Inode 14851830, i_blocks is 10832, should be 0.  Fix? yes

Pass 1E: Optimizing extent trees
Pass 2: Checking directory structure
Directory inode 15611261, block #0, offset 0: directory corrupted
Salvage? yes

Missing '.' in directory inode 15611261.
Fix? yes

Missing '..' in directory inode 15611261.
Fix? yes

Pass 3: Checking directory connectivity
'..' in /var/opt/gitlab/postgresql/data/pg_stat_tmp (15611261) is <The NULL inode> (0), should be /var/opt/gitlab/postgresql/data (15611047).
Fix? yes

/lost+found not found.  Create? yes

Pass 4: Checking reference counts
Inode 2 ref count is 16, should be 17.  Fix? yes

Inode 15611047 ref count is 20, should be 19.  Fix? yes

Unattached inode 15612685
Connect to /lost+found? yes

Inode 15612685 ref count is 2, should be 1.  Fix? yes

Unattached inode 15612697
Connect to /lost+found? yes

Inode 15612697 ref count is 2, should be 1.  Fix? yes

Unattached inode 15612698
Connect to /lost+found? yes

Inode 15612698 ref count is 2, should be 1.  Fix? yes

Unattached inode 15612701
Connect to /lost+found? yes

Inode 15612701 ref count is 2, should be 1.  Fix? yes

Unattached inode 15612702
Connect to /lost+found? yes

Inode 15612702 ref count is 2, should be 1.  Fix? yes

Pass 5: Checking group summary information
Block bitmap differences:  -28605601 -28616699 +28618591 -(28619907--28619908) -28634859 -28635555 -(28635557--28635558) -28635859 -28637183 -28637231 +(28638703--28638704) -28639093 +(28651062--28651063) -(28656125--28656126) -28656582 -(28656638--28656639) -28657662 -(28658520--28658521) -(28661457--28661458) -(29304720--29304831) -(29507584--29508808) -(29509632--29510956) -(29643264--29643643) -(29643648--29643719) -(29658688--29658735) +(29669376--29670683) -(29792256--29793582) +(29823488--29823868) +(29823872--29823943) +(29982720--29984331) +(29984352--29984383) +(29984768--29986085) +(29986112--29986367) -(29987328--29987903) -(29990816--29990847) +(29998848--29999103) -(29999271--29999750) -(30000640--30001019) +(30117888--30118091) +(30310912--30311292) +(30320640--30324564) +(30797824--30797857) +(30799872--30800383) -(30900992--30901055) -(30901312--30901759) -(30923264--30930279) -(31049728--31051001) -(31496704--31497082) -59283294 -61364599 +(62914560--62914565) +62914570 +(62914574--62914575) +(62914577--62914578) +(62914582--62914586) +(62914589--62914590) +(62914592--62914615) +(62914617--62914623) +(62914626--62914631) +(62914633--62914639) +62914641 +(62914643--62914645) +(62914647--62914651) +62914654 +(62914658--62914666) +(62914668--62914670) +62914672 +62914674 +(62914676--62914679) +(62914684--62914849) +(62914851--62914858) +(62914860--62914863) +(62914865--62914872) +(62914875--62914876) +(62914880--62914904) +(62914906--62914968) +(62914970--62914977) +(62914979--62914986) +(62914988--62914999) +(62915001--62915032) +(62915034--62915041) +(62915043--62915047) +(62915049--62915051) +(62915053--62915055) +(62915057--62915063) +(62915068--62915069) +(62915071--62915096) +(62915098--62915105) +(62915107--62915114) +(62915116--62915121) +(62915123--62915129) +(62915132--62915160) +(62915162--62915169) +(62915171--62915178) +(62915180--62915183) +(62915185--62915191) +(62915195--62915196) +(62915200--62915224) +(62915226--62915255) +(62915257--62915259) +(62915261--62915288) +(62915290--62915297) +(62915299--62915306) +(62915308--62915323) +(62915325--62915352) +(62915354--62915359) +(62915362--62915374) +(62915376--62915384) +62915387 +62915390 +(62915392--62915416) +(62915418--62915423) +(62915426--62915434) +62915438 +(62915440--62915447) +(62915449--62915451) +(62915453--62915480) +(62915482--62915511) +(62915516--62915544) +(62915546--62915551) +(62915554--62915562) +62915566 +(62915570--62915575) +(62915577--62915579) +62915581 +(62915584--62915608) +(62915610--62915615) +(62915618--62915626) +62915630 +(62915634--62915639) +62915643 +(62915647--62915672) +(62915674--62915679) +(62915682--62915690) +62915694 +62915696 +(62915698--62915700) +(62915702--62915703) +62915707 +(62915709--62915710) +(62915712--62915736) +(62915738--62915743) +(62915746--62915757) +(62915760--62915800) +(62915802--62915835) +(62915837--62915864) +(62915866--62915871) +(62915874--62915882) +62915886 +(62915890--62915899) +62915901 +(62915904--62915928) +(62915930--62915935) +(62915937--62915949) +(62915952--62915961) +(62915963--62915992) +(62915994--62916026) +(62916028--62916056) +(62916058--62916063) +(62916066--62916074) +(62916076--62916078) +62916083 +(62916085--62916086) +62916088 +62916093 +(62916095--62916120) +(62916122--62916127) +(62916130--62916142) +(62916144--62916151) +(62916153--62916154) +(62916156--62916157) +(62916159--62916184) +62916186 +(62916188--62926975) +(62927040--62927071) +(62927104--62927273) +(62927276--62927279) +(62927344--62927348) +(62927351--62927487) +(62927576--62928573) +(62928620--62928657) +(62928664--62928687) +(62929033--62936956) +(62937174--62937390) +(62943232--62944118) +(62944120--62944124) +(62944126--62944159) +62944161 +(62944163--62945278) +(62945318--62945320) +(62945322--62945452) +(62945473--62945496) +(62945756--62945761) +(62945763--62945766) +62945801 +(62945845--62945850) +(62946328--62946375) -71859953
Fix? yes

Free blocks count wrong for group #872 (22323, counted=22324).
Fix? yes

Free blocks count wrong for group #873 (31166, counted=31175).
Fix? yes

Free blocks count wrong for group #874 (30587, counted=30595).
Fix? yes

Free blocks count wrong for group #894 (30070, counted=30182).
Fix? yes

Free blocks count wrong for group #900 (30170, counted=32720).
Fix? yes

Free blocks count wrong for group #904 (28579, counted=28959).
Fix? yes

Free blocks count wrong for group #905 (19994, counted=20044).
Fix? yes

Free blocks count wrong for group #909 (26973, counted=28300).
Fix? yes

Free blocks count wrong for group #915 (19713, counted=17707).
Fix? yes

Free blocks count wrong for group #919 (32764, counted=32560).
Fix? yes

Free blocks count wrong for group #925 (28351, counted=24045).
Fix? yes

Free blocks count wrong for group #939 (32764, counted=32218).
Fix? yes

Free blocks count wrong for group #947 (19392, counted=20666).
Fix? yes

Free blocks count wrong for group #961 (32348, counted=32727).
Fix? yes

Free blocks count wrong for group #1792 (15603, counted=15605).
Fix? yes

Free blocks count wrong for group #1808 (4824, counted=4820).
Fix? yes

Free blocks count wrong for group #1809 (2424, counted=2425).
Fix? yes

Free blocks count wrong for group #1824 (7398, counted=7394).
Fix? yes

Free blocks count wrong for group #1872 (5772, counted=5769).
Fix? yes

Free blocks count wrong for group #2192 (274, counted=271).
Fix? yes

Free blocks count wrong (40583470, counted=40721913).
Fix? yes

Free inodes count wrong for group #1345 (60, counted=62).
Fix? yes

Free inodes count wrong for group #1792 (101, counted=106).
Fix? yes

Directories count wrong for group #1792 (202, counted=200).
Fix? yes

Free inodes count wrong (16164147, counted=16164154).
Fix? yes


/dev/sda1: ***** FILE SYSTEM WAS MODIFIED *****
/dev/sda1: 1841862/18006016 files (0.1% non-contiguous), 31299335/72021248 blocks
[garuda@garuda-sway ~]$ sudo resize2fs /dev/sda1
resize2fs 1.46.5 (30-Dec-2021)
Resizing the filesystem on /dev/sda1 to 1610074744 (4k) blocks.
The filesystem on /dev/sda1 is now 1610074744 (4k) blocks long.

[garuda@garuda-sway ~]$

