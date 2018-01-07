---
author: aaronshang
comments: true
date: 2008-11-12 09:33:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2008/11/12/vboxdrv-kernel-module-re-build/
slug: vboxdrv-kernel-module-re-build
title: vboxdrv kernel module re-build
wordpress_id: 7
---

Error occurred when running VirtualBox, some box popped out.


[![](http://aaronshang.files.wordpress.com/2008/11/virtualbox-wrong-0-707608.png?w=300)](http://aaronshang.files.wordpress.com/2008/11/virtualbox-wrong-0-707608.png)




[![](http://aaronshang.files.wordpress.com/2008/11/virtualbox-wrong-1-710027.png?w=286)](http://aaronshang.files.wordpress.com/2008/11/virtualbox-wrong-1-710027.png)




[![](http://aaronshang.files.wordpress.com/2008/11/virtualbox-wrong-2-710687.png?w=300)](http://aaronshang.files.wordpress.com/2008/11/virtualbox-wrong-2-710687.png)


$ VirtualBox
WARNING: The vboxdrv kernel module is not loaded. Either there is no module
available for the current kernel (2.6.24-21-386) or it failed to
load. Please recompile the kernel module and install it by

sudo /etc/init.d/vboxdrv setup

You will not be able to start VMs until this problem is fixed.
WARNING: The compilation of the vboxdrv.ko kernel module failed during the
installation for some reason. Starting a VM will not be possible.
Please consult the User Manual for build instructions.

$ sudo /etc/init.d/vboxdrv setup
* Stopping VirtualBox kernel module                                                                                                                                                   *  done.
* Recompiling VirtualBox kernel module
* Look at /var/log/vbox-install.log to find out what went wrong

$ tail /var/log/vbox-install.log
Makefile:142: *** Error: unable to find the sources of your current Linux kernel. Specify KERN_DIR= and run Make again.  Stop.

$ sudo KERN_DIR=/usr/src/linux-source-2.6.24   /etc/init.d/vboxdrv setup
* Stopping VirtualBox kernel module                                                                                                                                                   *  done.
* Recompiling VirtualBox kernel module                                                                                                                                                *  done.
* Starting VirtualBox kernel module                                                                                                                                                   *  done.

OK, it works.

$ dpkg -s virtualbox-2.0 | tail
Conflicts: virtualbox
Conffiles:
/etc/init.d/vboxdrv 6e3cb8dd230d768740ce0c6e0ae6a86c
/etc/init.d/vboxnet a3828b76a2fdfc0fb6908f2a76c86550
Description: Sun xVM VirtualBox
VirtualBox is a powerful PC virtualization solution allowing you to run a
wide range of PC operating systems on your Linux system. This includes
Windows, Linux, FreeBSD, DOS, OpenBSD and others. VirtualBox comes with a broad
feature set and excellent performance, making it the premier virtualization
software solution on the market.
