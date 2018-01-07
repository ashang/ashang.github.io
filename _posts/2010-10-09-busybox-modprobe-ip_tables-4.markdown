---
author: aaronshang
comments: true
date: 2010-10-09 09:31:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/10/09/busybox-modprobe-ip_tables-4/
slug: busybox-modprobe-ip_tables-4
title: busybox modprobe ip_tables
wordpress_id: 1055
---

  
no matter whether the modules exist or not, busybox will put module info into this file:  
/lib/modules/`uname -r`/[modules.dep.bb](http://modules.dep.bb)  
  
the file will not be made empty even the modules removed:  
# modprobe -v -r ip_tables  
  
# more [modules.dep.bb](http://modules.dep.bb)   
kernel/net/ipv4/netfilter/ip_tables.ko symbol:ipt_unregister_table symbol:ipt_register_table symbol:ipt_do_table symbol:ipt_do_table symbol:ipt_unregister_table symbol:ipt_register_table  
  
kernel/net/ipv4/netfilter/iptable_filter.ko  
ip_tables  
  
  
  
  
The modules should be put into the right place, such as:  
/lib/modules/`uname -r`/kernel/net/ipv4/netfilter  
  
  

    
    iptables tries to load ip_tables even though it is statically compiled in the kernel

  

