---
author: aaronshang
comments: true
date: 2010-10-08 08:06:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/10/08/write-failed-is-ssh-timeout-3/
slug: write-failed-is-ssh-timeout-3
title: Write failed is SSH Timeout
wordpress_id: 1058
---

**** **SSH session Timeout and break with this:  
Write failed: Broken pipe?**  
  
to make it better, try tune client side option ServerAliveInterval to a small value.  
  
~/.ssh/ssh_config:  
ServerAliveInterval 30  
  

