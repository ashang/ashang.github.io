---
date: 2018-06-10
title: use proxy for apt
---

  


add proxy server to  
/etc/apt/apt.conf.d/80proxy   
  
Acquire::http::Proxy "[http://proxy.server.hostname:8080/](http://proxy.server.hostname:8080/)";  
 Acquire::http::Proxy::proxy.server.hostname DIRECT;  
 

  


![](https://blogger.googleusercontent.com/tracker/4041220-5974307861553183122?l=ashang.blogspot.com)
