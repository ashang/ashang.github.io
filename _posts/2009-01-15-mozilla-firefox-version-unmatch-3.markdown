---
author: aaronshang
comments: true
date: 2009-01-15 13:55:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2009/01/15/mozilla-firefox-version-unmatch-3/
slug: mozilla-firefox-version-unmatch-3
title: mozilla firefox version unmatch
wordpress_id: 1079
---

errors when launching firefox:  
  
$ firefox  
Error: Platform version '1.9' is not compatible with  
minVersion >= 1.9.0.1  
maxVersion <= 1.9.0.*  
  
$ sudo vi /usr/lib/firefox-3.0.4/application.ini   
    
find these lines:  
[Gecko]  
MinVersion=1.9.0.1  
MaxVersion=1.9.0.*  
  
modify the version range, then It works with this dirty trick.
