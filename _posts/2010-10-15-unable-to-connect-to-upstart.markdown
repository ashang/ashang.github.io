---
author: aaronshang
comments: true
date: 2010-10-15 12:32:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/10/15/unable-to-connect-to-upstart/
slug: unable-to-connect-to-upstart
title: unable to connect to upstart
wordpress_id: 1002
---

## Upstart jobs cannot be run in a chroot

 Upstart  jobs cannot be started in a chroot because upstart acts as a service  supervisor, and processes within the chroot are unable to communicate  with the upstart running outside of the chroot ([430224](https://bugs.launchpad.net/bugs/430224)).   This will cause some packages that have been converted to use upstart  jobs instead of init scripts to fail to upgrade within a chroot.  Users  are advised to configure their chroots with /sbin/initctl pointing to  /bin/true  
  
  
[https://bugs.launchpad.net/ubuntu/+source/upstart/+bug/430224](https://bugs.launchpad.net/ubuntu/+source/upstart/+bug/430224)  
  
Replacing /sbin/initctl with a symlink to /bin/true is a fairly standard  
 way to disable services in a chroot  
  
  
100 root@odysseus ~ # apt-get install procps  
Reading package lists... Done  
Building dependency tree         
Reading state information... Done  
procps is already the newest version.  
0 upgraded, 0 newly installed, 0 to remove and 157 not upgraded.  
1 not fully installed or removed.  
After this operation, 0 B of additional disk space will be used.  
Do you want to continue [Y/n]?   
Setting up procps (1:3.2.8-9ubuntu3) ...  
start: Unable to connect to Upstart: Failed to connect to socket /com/ubuntu/upstart: Connection refused  
dpkg: error processing procps (--configure):  
 subprocess installed post-installation script returned error exit status 1  
configured to not write apport reports  
                                      Errors were encountered while processing:  
 procps  
E: Sub-process /usr/bin/dpkg returned an error code (1)  
  
  
100 root@odysseus ~ # dpkg-divert --local --rename --add /sbin/initctl  
Adding 'local diversion of /sbin/initctl to /sbin/initctl.distrib'  
  
  
root@odysseus ~ # ln -s /bin/true /sbin/initctl  
  
  
root@odysseus ~ # apt-get install procps  
Reading package lists... Done  
Building dependency tree         
Reading state information... Done  
procps is already the newest version.  
0 upgraded, 0 newly installed, 0 to remove and 157 not upgraded.  
1 not fully installed or removed.  
After this operation, 0 B of additional disk space will be used.  
Do you want to continue [Y/n]?   
Setting up procps (1:3.2.8-9ubuntu3) ...  
Processing triggers for menu ...  
Processing triggers for libc-bin ...  
ldconfig deferred processing now taking place  
apt-get install procps  5.42s user 0.62s system 57% cpu 10.574 total  
  
  


![](https://blogger.googleusercontent.com/tracker/4041220-7767561988834387070?l=ashang.blogspot.com)
