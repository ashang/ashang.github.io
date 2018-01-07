---
author: aaronshang
comments: true
date: 2010-09-27 08:09:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/09/27/radius-vs-tacacs-4/
slug: radius-vs-tacacs-4
title: radius vs tacacs+
wordpress_id: 1060
---

  
  
  
  
radius is UDP, so need re-transmit attempts, time-outs to compensate for best-effort transport,   
  
tacacs+ is TCP,   
  
- ACK within network round-trip time, i.e., RTT, regardless how loaded and slow the backend auth mechanism might be  
- immediate indication of crashed, or not running, server by a reset RST;  
    UDP cannot tell the diff between a server that is down, slow, or non-existent   
- TCP keepalive, server crashes can be detected out-of-band with actual requests; can maintain multiple server connections simultaneously.  
  
  
  
  
Pakcet encryption  
  
radius only encrypts pass in the access-request packet, from client to server,   
  
tacacs+ has header field to indicate whether the body is encrypted or not  
  
  
  
  
  
radius combines authentication and authorization,   
  
  
tacacs+ separates AAA. can use kerberos to do authentication,   
  
  
permission granted upon particular com,and  
  
  
  
  
  
  
  
  
  
  
  
TODO: diameter   

