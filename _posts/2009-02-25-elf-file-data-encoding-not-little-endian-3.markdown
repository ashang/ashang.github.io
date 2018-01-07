---
author: aaronshang
comments: true
date: 2009-02-25 08:20:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2009/02/25/elf-file-data-encoding-not-little-endian-3/
slug: elf-file-data-encoding-not-little-endian-3
title: ELF file data encoding not little-endian
wordpress_id: 1076
---

ELF file data encoding not little-endian  
  
$ man tar  
/usr/bin/gtbl: error while loading shared libraries: /lib/libstdc++.so.6: ELF file data encoding not little-endian  
  
$ file /usr/bin/gtbl   
/usr/bin/gtbl: symbolic link to `tbl'  
  
$ ldd /usr/bin/gtbl  
    linux-gate.so.1 =>  (0xb8095000)  
    libstdc++.so.6 => /usr/lib/libstdc++.so.6 (0xb7fa4000)  
    libm.so.6 => /lib/tls/i686/cmov/libm.so.6 (0xb7f7e000)  
    libgcc_s.so.1 => /lib/libgcc_s.so.1 (0xb7f6e000)  
    libc.so.6 => /lib/tls/i686/cmov/libc.so.6 (0xb7e0b000)  
    /lib/ld-linux.so.2 (0xb8096000)  
  
$ file /usr/bin/tbl   
/usr/bin/tbl: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.9, stripped  
  
$ ls -l /lib/libstdc++.so*  
lrwxrwxrwx 1 root root     18 2009-02-25 10:37 /lib/libstdc++.so -> libstdc++.so.6.0.4  
lrwxrwxrwx 1 root root     18 2009-02-25 10:37 /lib/libstdc++.so.6 -> libstdc++.so.6.0.4  
-rwxr-xr-x 1 root root 935932 2009-02-25 10:37 /lib/libstdc++.so.6.0.4  
  
$ file /lib/libstdc++.so*  
/lib/libstdc++.so:       symbolic link to `libstdc++.so.6.0.4'  
/lib/libstdc++.so.6:     symbolic link to `libstdc++.so.6.0.4'  
/lib/libstdc++.so.6.0.4: ELF 32-bit MSB shared object, PowerPC or cisco 4500, version 1 (SYSV), stripped  
   
  
$ readelf -h /lib/libstdc++.so.6.0.4   
ELF Header:  
  Magic:   7f 45 4c 46 01 02 01 00 00 00 00 00 00 00 00 00   
  Class:                             ELF32  
  Data:                              2's complement, big endian  
  Version:                           1 (current)  
  OS/ABI:                            UNIX - System V  
  ABI Version:                       0  
  Type:                              DYN (Shared object file)  
  Machine:                           PowerPC  
  Version:                           0x1  
  Entry point address:               0x3f0fc  
  Start of program headers:          52 (bytes into file)  
  Start of section headers:          934732 (bytes into file)  
  Flags:                             0x0  
  Size of this header:               52 (bytes)  
  Size of program headers:           32 (bytes)  
  Number of program headers:         5  
  Size of section headers:           40 (bytes)  
  Number of section headers:         30  
  Section header string table index: 29  
  
$ readelf -h /usr/lib/libstdc++.so.6.0.10   
ELF Header:  
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00   
  Class:                             ELF32  
  Data:                              2's complement, little endian  
  Version:                           1 (current)  
  OS/ABI:                            UNIX - System V  
  ABI Version:                       0  
  Type:                              DYN (Shared object file)  
  Machine:                           Intel 80386  
  Version:                           0x1  
  Entry point address:               0x44230  
  Start of program headers:          52 (bytes into file)  
  Start of section headers:          949224 (bytes into file)  
  Flags:                             0x0  
  Size of this header:               52 (bytes)  
  Size of program headers:           32 (bytes)  
  Number of program headers:         7  
  Size of section headers:           40 (bytes)  
  Number of section headers:         30  
  Section header string table index: 29  
  
  
  

