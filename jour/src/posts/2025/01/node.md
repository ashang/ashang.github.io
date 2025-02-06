npm config set prefix $HOME/.node_modules

/


# same Inode value?

see

    boot and mnt
    proc and sys 

same link numbers?



$ ls -lil
total 132
     12 lrwxrwxrwx   1 root     root    17 Aug 26 17:42 aaron -> /mnt/vghome/aaron
7602177 drwxr-xr-x   3 root     root  4096 Aug 20 11:34 bin
      2 drwxr-xr-x   5 root     root  4096 Aug 25 15:19 boot
   1025 drwxr-xr-x  19 root     root  4660 Aug 26 17:29 dev
 524289 drwxr-xr-x 165 root     root 12288 Aug 26 17:41 etc
6684673 drwxr-xr-x   4 root     root  4096 Jun 26 16:39 home
   4478 lrwxrwxrwx   1 root     root    33 Aug 19 08:04 initrd.img -> boot/initrd.img-3.16.0-46-generic
   6193 lrwxrwxrwx   1 root     root    33 Jul 28 07:49 initrd.img.old -> boot/initrd.img-3.16.0-45-generic
2228225 drwxr-xr-x  24 root     root  4096 Jul 16 13:48 lib
8126465 drwxr-xr-x   2 root     root  4096 Jun 26 16:30 lib32
4980737 drwxr-xr-x   2 root     root  4096 Jun 26 15:54 lib64
3014657 drwxr-xr-x   2 root     root  4096 Jun 26 16:30 libx32
     11 drwx------   2 root     root 16384 Jun 26 15:49 lost+found
4063233 drwxr-xr-x   3 root     root  4096 Jun 26 17:23 media
      2 drwxr-xr-x   7 28850410 root  4096 Aug 20 14:42 mnt
8257537 drwxr-xr-x  21 root     root  4096 Jul  4 00:33 opt
      1 dr-xr-xr-x 320 root     root     0 Aug 25 15:15 proc
1572865 drwx------   8 root     root  4096 Jul 21 17:39 root
  11296 drwxr-xr-x  28 root     root  1040 Aug 26 11:28 run
1703937 drwxr-xr-x   2 root     root 12288 Aug  7 17:23 sbin
2490369 drwxr-xr-x   2 root     root  4096 Jun 26 15:49 srv
      1 dr-xr-xr-x  13 root     root     0 Aug 26 17:34 sys
1966081 drwxrwxrwt   9 root     root 36864 Aug 26 17:42 tmp
5111809 drwxr-xr-x  12 root     root  4096 Jun 26 16:30 usr
2621441 drwxr-xr-x  14 root     root  4096 Jun 26 16:23 var
   4515 lrwxrwxrwx   1 root     root    30 Aug 19 08:04 vmlinuz -> boot/vmlinuz-3.16.0-46-generic
     13 lrwxrwxrwx   1 root     root    30 Jul 28 07:49 vmlinuz.old -> boot/vmlinuz-3.16.0-45-generic

$ stat boot
  File: ‘boot’
  Size: 4096        Blocks: 8          IO Block: 4096   directory
Device: 811h/2065d  Inode: 2           Links: 5
Access: (0755/drwxr-xr-x)  Uid: (    0/    root)   Gid: (    0/    root)
Access: 2015-08-26 16:01:32.383757535 +0800
Modify: 2015-08-25 15:19:36.098788747 +0800
Change: 2015-08-25 15:19:36.098788747 +0800
 Birth: -

$ stat mnt
  File: ‘mnt’
  Size: 4096        Blocks: 8          IO Block: 4096   directory
Device: fc06h/64518d  Inode: 2           Links: 7
Access: (0755/drwxr-xr-x)  Uid: (2060807067/28850410)   Gid: (    0/    root)
Access: 2015-07-17 12:05:49.179935786 +0800
Modify: 2015-08-20 14:42:57.542618441 +0800
Change: 2015-08-20 14:42:57.542618441 +0800
 Birth: -







