---
author: aaronshang
comments: true
date: 2012-11-16 01:49:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2012/11/16/packages-cannot-be-authenticated/
slug: packages-cannot-be-authenticated
title: packages cannot be authenticated
wordpress_id: 1024
---

  
  
WARNING: The following packages cannot be authenticated!  
  
$ sudo apt-get install  gstreamer1.0-pulseaudio   
Reading package lists... Done  
Building dependency tree         
Reading state information... Done  
 The following packages were automatically installed and are no longer required:  
  libdirac-encoder0 libopencore-amrnb0 libopencore-amrwb0 libsvga1 libvo-aacenc0 libvo-amrwbenc0  
Use 'apt-get autoremove' to remove them.  
 The following NEW packages will be installed:  
  gstreamer1.0-pulseaudio  
0 upgraded, 1 newly installed, 0 to remove and 1 not upgraded.  
Need to get 57.6 kB of archives.  
After this operation, 220 kB of additional disk space will be used.  
 WARNING: The following packages cannot be authenticated!  
  gstreamer1.0-pulseaudio  
Install these packages without verification [y/N]?   
  
  
To solve that:
    
    <code>$ sudo apt-key update  $ sudo apt-get update  </code>

  
  
  
Related:  
  


$ sudo apt-key list  
$ sudo apt-key remove FBB75451  
$ sudo apt-key list  


  

