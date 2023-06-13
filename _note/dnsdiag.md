---
title: DNSDiag
date: 2014-12-20
---

[DNSDiag](https://dnsdiag.org/)

- dnsping
- dnstraceroute
- dnseval

```sh
$ dnsping -c 5 --dnssec --flags --tls -t AAAA -s 9.9.9.9 ripe.net
dnsping DNS: 9.9.9.9:853, hostname: ripe.net, proto: TLS, rdatatype: AAAA, flags: RD
169 bytes from 9.9.9.9: seq=1   time=940.784 ms [QR RD RA AD]  NOERROR
169 bytes from 9.9.9.9: seq=2   time=1140.410 ms [QR RD RA AD]  NOERROR
169 bytes from 9.9.9.9: seq=3   time=1026.979 ms [QR RD RA AD]  NOERROR
169 bytes from 9.9.9.9: seq=4   time=1045.875 ms [QR RD RA AD]  NOERROR
169 bytes from 9.9.9.9: seq=5   time=1901.580 ms [QR RD RA AD]  NOERROR

--- 9.9.9.9 dnsping statistics ---
5 requests transmitted, 5 responses received, 0% lost
min=940.784 ms, avg=1211.126 ms, max=1901.580 ms, stddev=392.438 ms
```

```sh
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

```sh
$ dnseval ripe.net
server    avg(ms)     min(ms)     max(ms)     stddev(ms)  lost(%)  ttl        flags                  response
---------------------------------------------------------------------------
1.1.1.1   0.000       0.000       0.000       0.000       %100     N/A        -- -- -- -- -- -- --   No Response
9.9.9.9   404.156     297.118     511.194     151.374     %33      300        QR -- -- RD RA -- --   NOERROR
1.0.0.1   252.260     145.856     450.350     97.728      %0       299        QR -- -- RD RA -- --   NOERROR
```

- https://github.com/farrokhi/dnsdiag
