---
author: aaronshang
comments: true
date: 2010-10-08 10:10:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/10/08/debian-setting-locale-failed-3/
slug: debian-setting-locale-failed-3
title: debian setting locale failed
wordpress_id: 1057
---

  
perl: warning: Setting locale failed.  
perl: warning: Please check that your locale settings:  
        LANGUAGE = (unset),  
        LC_ALL = (unset),  
        LANG = "zh_CN.UTF-8"  
    are supported and installed on your system.  
perl: warning: Falling back to the standard locale ("C").  
locale: Cannot set LC_CTYPE to default locale: No such file or directory  
locale: Cannot set LC_MESSAGES to default locale: No such file or directory  
locale: Cannot set LC_ALL to default locale: No such file or directory  
   
  
to fix this:  
# dpkg-reconfigure locales
