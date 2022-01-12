---
date: 2017-07-15
title: mozilla firefox version unmatch
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
