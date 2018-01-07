---
author: aaronshang
comments: true
date: 2011-03-21 09:21:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2011/03/21/compress-utilities-xz-7zip-gzip-zip-bzip2/
slug: compress-utilities-xz-7zip-gzip-zip-bzip2
title: compress utilities, xz, 7zip, gzip, zip, bzip2
wordpress_id: 1008
---

  
on same PC, using "best" compression.  
  
  
Result  
======================  
  
- speed: zip is best, near gzip, then bzip2, then 7z, then xz  
- compression: 7z, near xz, > bzip2 > gzip, near zip  
   
  
  
  
notes  
======================  
- you should give archive name for zip, and 7z; zip and 7z can add prefix, .zip, .7z, respectively.  
- if you issue "7z a archive", 7z will compress all files under current directory and generate an archive.7z.  
 - gzip, bzip2, doesn't package files, you should archive first if working for more than one files.  
- and '-r' for zip for recursive files.  
  
  
  
  
test output  
======================  
  
  
 $ cp mbox 01  
$ cp mbox 02  
$ cp mbox 03  
$ cp mbox 04  
$ cp mbox 05  
  
  
$ time xz -v -9 01  
01 (1/1)  
 100.0 %           2,086.5 KiB / 3,529.3 KiB = 0.591                     0:02  
  
real    0m2.926s  
 user    0m2.720s  
sys 0m0.120s  
  
  
$ time gzip -v -9 02  
02:  36.6% -- replaced with 02.gz  
  
real    0m0.509s  
user    0m0.470s  
sys 0m0.000s  
  
  
$ time bzip2 -v -9 03  
 03:       1.620:1,  4.938 bits/byte, 38.28% saved, 3613967 in, 2230651 out.  
   
real    0m1.580s  
user    0m1.540s  
sys 0m0.030s  
  
  
$ time zip -v -9 04.zip 04  
 adding: 04    (in=3613967) (out=2292926) (deflated 37%)  
total bytes=3613967, compressed=2292926 -> 37% savings  
  
 real    0m0.429s  
user    0m0.400s  
sys 0m0.020s  
  
  
$ time 7z -mx=9 a 05.7z 05  
  
7-Zip 9.13 beta  Copyright (c) 1999-2010 Igor Pavlov  2010-04-15  
p7zip Version 9.13 (locale=en_US.UTF-8,Utf16=on,HugeFiles=on,2 CPUs)  
 Scanning  
  
  
  
Creating archive 05.7z  
  
Compressing  05  
  
Everything is Ok  
  
real    0m1.987s  
user    0m2.870s  
sys 0m0.050s  
  
  
  
-rw------- 1 aaron aaron 2136600 Dec 14  2009 01.xz  
 -rw------- 1 aaron aaron 2292947 Dec 14  2009 02.gz  
-rw------- 1 aaron aaron 2230651 Dec 14  2009 03.bz2  
-rw------- 1 aaron aaron 3613967 Dec 14  2009 04  
-rw-rw-r-- 1 aaron aaron 2293080 Sep  9 20:09 04.zip  
-rw------- 1 aaron aaron 3613967 Dec 14  2009 05  
 -rw-rw-r-- 1 aaron aaron 2136083 Sep  9 20:07 05.7z  
-rw------- 1 aaron aaron 3613967 Dec 14  2009 mbox   
  
   
  
  
  
======================  
uncompromising  
  
$ bunzip2 XXX  
  
$ gunzip XXX  
  
$ unzip XXX  
  
$ 7z x XXX  
  
$ unxz FreeBSD-8.2-RELEASE-i386-dvd1.iso.xz  
  


![]()
