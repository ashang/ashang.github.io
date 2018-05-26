---
author: aaronshang
comments: true
date: 2010-10-18 07:48:03+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/10/18/php-fpm-vs-spawn-fcgi/
slug: php-fpm-vs-spawn-fcgi
title: php-fpm vs spawn-fcgi
wordpress_id: 34
tags:
- php-fpm
---

Basic features:

http://php-fpm.org/

What is PHP-FPM?
PHP-FPM (FastCGI Process Manager) is an alternative PHP FastCGI implementation with some additional features useful for sites of any size, especially busier sites.

These features include:

    * Adaptive process spawning (NEW!)
    * Basic statistics (ala Apache's mod_status) (NEW!)
    * Advanced process management with graceful stop/start
    * Ability to start workers with different uid/gid/chroot/environment and different php.ini (replaces safe_mode)
    * Stdout & stderr logging
    * Emergency restart in case of accidental opcode cache destruction
    * Accelerated upload support
    * Support for a "slowlog"
    * Enhancements to FastCGI, such as fastcgi_finish_request() - a special function to finish request & flush all data while continuing to do something time-consuming (video converting, stats processing, etc.)


... and much more.

It was not designed with virtual hosting in mind (large amounts of pools) however it can be adapted for any usage model.



Comparison:

http://php-fpm.org/about/

Uncomplete nginx practice:
http://wiki.nginx.org/NinX%2BPHP%2BFPM%2Bremote
