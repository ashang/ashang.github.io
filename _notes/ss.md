---
title: ss
date: 2016-11-23
--- 

By default, ss lists open non-listening TCP sockets that have established connections.

```
# ss -tmpie
State       Recv-Q        Send-Q               Local Address:Port               Peer Address:Port        Process
ESTAB       0             0                     10.0.0.2:ssh                 10.0.0.3:37462        users:(("dropbear",pid=10360,fd=6)) ino:110268 sk:2020 cgroup:/system.slice/dropbear.service <->
         skmem:(r0,rb131072,t0,tb87040,f4096,w0,o0,bl0,d0) ts sack cubic wscale:7,10 rto:208 rtt:4.254/1.68 ato:40 mss:1448 pmtu:1500 rcvmss:1448 advmss:1448 cwnd:10 bytes_sent:57182 bytes_retrans:60 bytes_acked:57122 bytes_received:8009 segs_out:254 segs_in:369 data_segs_out:243 data_segs_in:147 send 27.2Mbps lastsnd:16 lastrcv:16 lastack:12 pacing_rate 54.5Mbps delivery_rate 49.6Mbps delivered:244 busy:1756ms retrans:0/1 dsack_dups:1 rcv_space:14600 rcv_ssthresh:64076 minrtt:1.965
ESTAB       0             0                      10.0.0.2:ssh                 10.0.0.3:47454        users:(("dropbear",pid=2896,fd=6)) ino:45136 sk:200c cgroup:/system.slice/dropbear.service <->
         skmem:(r0,rb131072,t0,tb87040,f0,w0,o0,bl0,d4) ts sack cubic wscale:7,10 rto:1132 rtt:43.562/83.549 ato:40 mss:1448 pmtu:1500 rcvmss:1448 advmss:1448 cwnd:7 ssthresh:7 bytes_sent:9650 bytes_retrans:104 bytes_acked:9546 bytes_received:5101 segs_out:96 segs_in:123 data_segs_out:68 data_segs_in:56 send 1.86Mbps lastsnd:556860 lastrcv:556896 lastack:556860 pacing_rate 2.23Mbps delivery_rate 15.3Mbps delivered:69 busy:2692ms retrans:0/2 dsack_dups:2 rcv_rtt:4 rcv_space:14600 rcv_ssthresh:64076 minrtt:1.327
```
