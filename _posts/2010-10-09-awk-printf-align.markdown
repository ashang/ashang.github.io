---
author: aaronshang
comments: true
date: 2010-10-09 06:29:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/10/09/awk-printf-align/
slug: awk-printf-align
title: awk printf align
wordpress_id: 23
---

  
arp -n | awk '{printf("%-20s %-20s %-20s\n",$1, $3, $5)}'  

