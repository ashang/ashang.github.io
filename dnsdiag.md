---
layout: page
title: DNSDiag
date: 2014-12-20
tags: ["Apps"]
---

[DNSDiag](https//dnsdiag.org/)
- dnsping
- dnstraceroute
- dnseval

```
./dnsping -s 8.8.8.8 -c 5 linuxtoy.org
dnsping DNS: 8.8.8.853, hostname linuxtoy.org, rdatatype: A
39 bytes from 8.8.8.8: seq=0   time=111.764 ms
38 bytes from 8.8.8.8: seq=1   time=65.606 ms
39 bytes from 8.8.8.8: seq=2   time=110.593 ms
38 bytes from 8.8.8.8: seq=3   time=67.940 ms
38 bytes from 8.8.8.8: seq=4   time=66.181 ms

--- 8.8.8.8 dnsping statistics ---
5 requests transmitted, 5 responses received,   0% lost
min=65.606 ms, avg=84.417 ms, max=111.764 ms, stddev=24.449 ms
```

```
./dnstraceroute --expert -s 8.8.8.8 linuxtoy.org
dnstraceroute DNS: 8.8.8.853, hostname linuxtoy.org, rdatatype: A
1       gateway (10.217.89.1) 1 ms
2       10.210.4.37 (10.210.4.37) 1 ms
3       10.210.2.67 (10.210.2.67) 1 ms
4       254.118.142.219.broad.bj.bj.dynamic.163data.com.cn (219.142.118.254) 2 ms
5       10.210.1.14 (10.210.1.14) 4 ms
6       192.168.5.30 (192.168.5.30) 7 ms
7       180.149.129.217 (180.149.129.217) 7 ms
8        *
9       180.149.128.9 (180.149.128.9) 8 ms
10      202.97.53.146 (202.97.53.146) 8 ms
11      202.97.58.94 (202.97.58.94) 9 ms
12      202.97.91.114 (202.97.91.114) 49 ms
13      202.97.62.214 (202.97.62.214) 47 ms
14      209.85.241.58 (209.85.241.58) 43 ms
15      209.85.142.185 (209.85.142.185) 45 ms
16      216.239.41.7 (216.239.41.7) 152 ms
17      209.85.243.23 (209.85.243.23) 62 ms
18       *
19      google-public-dns-a.google.com (8.8.8.8) 72 ms

=== Expert Hints ===
 [*] public DNS server is next to an invisible hop (probably a firewall)
```

```
./dnseval linuxtoy.org
server              avg(ms)     min(ms)     max(ms)     stddev(ms)  lost(%)
---------------------------------------------------------------------------
10.210.12.10        51.627      1.169       503.838     158.891     %0
202.106.182.153     285.889     2.336       604.162     312.265     %14
```

https//github.com/farrokhi/dnsdiag
