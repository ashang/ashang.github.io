---
date: 2018-12-13
title: Linux proxy
---

  
  
**== proxy for apt ==**  
  
edit  
/etc/apt/apt.conf  
  
or  
# vi /etc/apt/apt.conf.d/60proxy  
Acquire::http::Proxy "http://x.x.x.x:port";  
  
Don't miss the trailing ";".   
  
The proxy can be in pac form:  
"http://x.x.x.x:port/accelerated.pac"  
  
URL:  
[http://en.wikipedia.org/wiki/Proxy_auto-config](http://en.wikipedia.org/wiki/Proxy_auto-config)  
  
**== proxy for wget ==**  

    
    wget -e http_proxy=http://x.x.x.x:port -c -m -np -k URL 
    
     
