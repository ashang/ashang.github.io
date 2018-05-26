---
author: aaronshang
comments: true
date: 2012-09-14 09:29:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2012/09/14/linux-proxy/
slug: linux-proxy
title: Linux proxy
wordpress_id: 1028
---

  
  
**== proxy for apt ==**  
  
edit  
/etc/apt/apt.conf  
  
or  
$ sudo vi /etc/apt/apt.conf.d/60proxy  
Acquire::http::Proxy "http://x.x.x.x:port";  
  
Don't miss the trailing ";".   
  
The proxy can be in pac form:  
"http://x.x.x.x:port/accelerated.pac"  
  
URL:  
[http://en.wikipedia.org/wiki/Proxy_auto-config](http://en.wikipedia.org/wiki/Proxy_auto-config)  
  
**== proxy for wget ==**  

    
    wget -e http_proxy=http://x.x.x.x:port -c -m -np -k URL 
    
     
