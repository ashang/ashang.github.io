---
author: aaronshang
comments: true
date: 2008-10-29 01:43:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2008/10/29/time-on-unix-system-2/
slug: time-on-unix-system-2
title: time on UNIX system
wordpress_id: 889
---

Draft

  Internally, computer times are represented as a count of seconds  
since an epoch--a well-defined point of time.  On GNU and POSIX  
systems, the epoch is 1970-01-01 00:00:00 UTC, so `@0' represents this  
time, `@1' represents 1970-01-01 00:00:01 UTC, and so forth.  GNU and  
most other POSIX-compliant systems support such times as an extension  
to POSIX, using negative counts, so that `@-1' represents 1969-12-31  
23:59:59 UTC.

  Traditional Unix systems count seconds with 32-bit two's-complement  
integers and can represent times from 1901-12-13 20:45:52 through  
2038-01-19 03:14:07 UTC.  More modern systems use 64-bit counts of  
seconds with nanosecond subcounts, and can represent all the times in  
the known lifetime of the universe to a resolution of 1 nanosecond.

1972-09-24     # ISO 8601.

      -R, --rfc-2822  
             output date and time in RFC 2822 format.  Example: Mon,  
07 Aug 2006 12:34:56 -0600

  
      -u, --utc, --universal  
             print or set Coordinated Universal Time

![]()
