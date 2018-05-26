---
author: aaronshang
comments: true
date: 2011-06-18 02:46:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2011/06/18/use-proxy-for-apt/
slug: use-proxy-for-apt
title: use proxy for apt
wordpress_id: 1014
---

  


add proxy server to  
/etc/apt/apt.conf.d/80proxy   
  
Acquire::http::Proxy "[http://proxy.server.hostname:8080/](http://proxy.server.hostname:8080/)";  
 Acquire::http::Proxy::proxy.server.hostname DIRECT;  
 

  


![](https://blogger.googleusercontent.com/tracker/4041220-5974307861553183122?l=ashang.blogspot.com)
