---
author: aaronshang
comments: true
date: 2012-09-18 06:21:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2012/09/18/adb-no-such-file/
slug: adb-no-such-file
title: adb no such file
wordpress_id: 1027
---

## **Common adb errors and solutions**

  


#### **No such file or directory**

  
/path/to/android-sdk-linux/platform-tools/adb: No such file or directory

  
Solution:  


$ sudo apt-get install ia32-libs

  
Links:  
[https://bugs.launchpad.net/ubuntu/+source/ia32-libs/+bug/852101](https://bugs.launchpad.net/ubuntu/+source/ia32-libs/+bug/852101)  
[http://askubuntu.com/questions/73491/no-such-file-or-directory-for-existing-executable](http://askubuntu.com/questions/73491/no-such-file-or-directory-for-existing-executable)  
[http://kenno.wordpress.com/2011/10/27/ubuntu-11-10-32-bit-applications-do-not-run-64-bit/](http://kenno.wordpress.com/2011/10/27/ubuntu-11-10-32-bit-applications-do-not-run-64-bit/)  
  
  
  


#### insufficient permissions for device

  
$ adb shell df  
error: insufficient permissions for device  
  
$ sudo adb kill-server  
[sudo] password for aaron:   
  
$ adb shell df  
* daemon not running. starting it now on port 5037 *  
* daemon started successfully *  
Filesystem               Size     Used     Free   Blksize  
/dev                   338.7M    64.0K   338.7M   4096  
/mnt/asec              338.7M     0.0K   338.7M   4096  
/mnt/obb               338.7M     0.0K   338.7M   4096  
/system               1007.9M   550.9M   457.0M   4096  
/data                    4.0G   172.8M     3.8G   4096  
/cache                 246.1M     4.1M   241.9M   4096  
/mnt/sdcard             21.2G   912.8M    20.3G   32768  
/mnt/secure/asec: Permission denied  
  
  
"adb start-server " is automatically run.  
  
$ adb kill-server ;  sudo adb start-server ; adb devices  
When to use "sudo" for adb? never needed?  
  
1  
  adb kill-server ;  sudo adb start-server ; adb shell df  
  
2  
 adb kill-server ;  adb start-server ; adb shell df  
  
3  
 adb kill-server ;  sudo adb shell df  
  
Result 1 equals 3  
  
2 will give  
 error: insufficient permissions for device  
  

