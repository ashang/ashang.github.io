---
author: aaronshang
comments: true
date: 2011-10-10 05:54:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2011/10/10/transfer-big-file-to-fat32-fs-on-android-emmc/
slug: transfer-big-file-to-fat32-fs-on-android-emmc
title: Transfer big file to FAT32 fs on android eMMC
wordpress_id: 1041
---

  


Summary: 

 - Fat32 doesn’t support file size more than 4GiB; 

 - No crashes during transferring  big files to eMMC storage, 4.5GiB+ outsize; 2.5GiB+ OK in my test,  using “cp” and “adb push”);

 - I had NO idea for MTP mode in Linux. (Any hints?)

  
  


$ dd if=/dev/zero of=test-file-4.5g bs=1024 count=4500000

  


-rw-r--r--   1 root root 4608000000 2011-09-29 12:43 test-file-4.5g

  


/dev/sdb              11915392       960  11914432   1% /media/8780-09E2

  
  


$ time cp test-file-4.5g /media/8780-09E2/

cp: writing `/media/8780-09E2/test-file-4.5g': File too large

real    33m55.000s

user    0m0.050s

sys     0m12.500s

  


-rw-r--r-- 1 root root 4294967295 2011-10-08 16:29 /media/8780-09E2/test-file-4.5g

  


$ /bin/rm -fr /media/8780-09E2/test-file-4.5g 

  


$ time adb push /test-file-4.5g /mnt/sdcard/

failed to copy 'test-file-4.5g' to '/mnt/sdcard//test-file-4.5g': File too large

real    14m24.386s

user    0m0.150s

sys     0m10.370s

  


$ time dd if=/dev/zero of=test-file-2.5g bs=1024 count=2500000

2500000+0 records in

2500000+0 records out

2560000000 bytes (2.6 GB) copied, 63.4219 s, 40.4 MB/s

real    1m3.554s

user    0m0.260s

sys     0m7.420s

  


$ cp test-file-2.5g /media/8780-09E2/test1

  


Disconnect phone memory card;

$ adb push test-file-2.5g /mnt/sdcard/test2

  


  
Mount phone memory card; 

-rw-r--r-- 1 root root 2560000000 2011-10-09 13:01 test1

-rw-r--r-- 1 root root 2560000000 2011-10-09 04:00 test2

  


  


$ mount|\grep /dev/sdb

/dev/sdb on /media/8780-09E2 type vfat (rw,nosuid,nodev,uhelper=udisks,uid=0,gid=0,shortname=mixed,dmask=0077,utf8=1,showexec,flush)

  
  
Ref:

[http://en.wikipedia.org/wiki/Fat32](http://en.wikipedia.org/wiki/Fat32)

Limits Max file size[1]      4 GB minus 1 byte

  


  

