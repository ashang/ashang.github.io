---
title: "snort3"
date: 2017-08-20T21:38:52+08:00
lastmod: 2017-08-28T21:41:52+08:00
menu: "main"
weight: 50

# you can close something for this content if you open it in config.toml.
comment: false
mathjax: false
---


Snort 3 is redesigned in C++ which makes the code base more modular and easier to maintain on your network.

Threading and shared memory allow you to scale Snort 3 to your network and create a much faster start-up. This allows multiple packet processing to free up more memory for more packet processing power.



wget https://www.snort.org/downloads/snort/daq-2.0.7.tar.gz

wget https://www.snort.org/downloads/snort/snort-2.9.20.tar.gz
tar xvzf daq-2.0.7.tar.gz

cd daq-2.0.7
./configure && make && sudo make install

cd ..
tar xvzf snort-2.9.20.tar.gz

cd snort-2.9.20
./configure --enable-sourcefire && make && sudo make install




wget https://www.snort.org/downloads/community/community-rules.tar.gz -O community-rules.tar.gz
tar -xvzf community-rules.tar.gz -C /etc/snort/rules




wget https://www.snort.org/downloads/snort/daq-2.0.7.tar.gz

wget https://www.snort.org/downloads/snort/snort-2.9.20.tar.gz
tar xvzf daq-2.0.7.tar.gz

cd daq-2.0.7
./configure && make && sudo make install

cd ..
tar xvzf snort-2.9.20.tar.gz

cd snort-2.9.20
./configure --enable-sourcefire && make && sudo make install




$ snort
Running in packet dump mode

        --== Initializing Snort ==--
Initializing Output Plugins!
pcap DAQ configured to passive.
Acquiring network traffic from "wlp3s0".
ERROR: Can't start DAQ (-1) - socket: Operation not permitted!
Fatal Error, Quitting..
# W46.5 1118 15:49:36  aaron@x2:~/rustre/content/post
$ sudo snort
Running in packet dump mode

        --== Initializing Snort ==--
Initializing Output Plugins!
pcap DAQ configured to passive.
Acquiring network traffic from "wlp3s0".
Decoding Ethernet

        --== Initialization Complete ==--

   ,,_     -*> Snort! <*-
  o"  )~   Version 2.9.15.1 GRE (Build 15125)
   ''''    By Martin Roesch & The Snort Team: http://www.snort.org/contact#team
           Copyright (C) 2014-2019 Cisco and/or its affiliates. All rights reserved.
           Copyright (C) 1998-2013 Sourcefire, Inc., et al.
           Using libpcap version 1.10.1 (with TPACKET_V3)
           Using PCRE version: 8.39 2016-06-14
           Using ZLIB version: 1.2.11

Commencing packet processing (pid=2455342)
WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.389750 10.10.50.177:50917 -> 239.255.255.250:1900
UDP TTL:1 TOS:0x0 ID:33004 IpLen:20 DgmLen:203
Len: 175
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.391952 fe80::14d0:7abc:38ef:6f80 -> ff02::16
IPV6-ICMP TTL:1 TOS:0x0 ID:84017152 IpLen:40 DgmLen:76
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.399935 10.10.50.50:22 -> 10.10.50.14:43324
TCP TTL:64 TOS:0x10 ID:58471 IpLen:20 DgmLen:208 DF
***AP*** Seq: 0x41FA9C3E  Ack: 0x9952E8ED  Win: 0x2AA  TcpLen: 32
TCP Options (3) => NOP NOP TS: 3084882237 2025045579
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.400223 10.10.50.14:43324 -> 10.10.50.50:22
TCP TTL:64 TOS:0x10 ID:63595 IpLen:20 DgmLen:52 DF
***A**** Seq: 0x9952E8ED  Ack: 0x41FA9CDA  Win: 0xD5E  TcpLen: 32
TCP Options (3) => NOP NOP TS: 2025045860 3084882237
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.400837 10.10.50.50:22 -> 10.10.50.14:43324
TCP TTL:64 TOS:0x10 ID:58472 IpLen:20 DgmLen:200 DF
***AP*** Seq: 0x41FA9CDA  Ack: 0x9952E8ED  Win: 0x2AA  TcpLen: 32
TCP Options (3) => NOP NOP TS: 3084882312 2025045579
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.401024 10.10.50.14:43324 -> 10.10.50.50:22
TCP TTL:64 TOS:0x10 ID:63596 IpLen:20 DgmLen:52 DF
***A**** Seq: 0x9952E8ED  Ack: 0x41FA9D6E  Win: 0xD5E  TcpLen: 32
TCP Options (3) => NOP NOP TS: 2025045861 3084882312
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.450848 10.10.50.134:5353 -> 224.0.0.251:5353
UDP TTL:255 TOS:0x0 ID:25994 IpLen:20 DgmLen:140
Len: 112
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.454964 fe80::14d0:7abc:38ef:6f80:5353 -> ff02::fb:5353
UDP TTL:255 TOS:0x0 ID:0 IpLen:40 DgmLen:160
Len: 112
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
WARNING: No preprocessors configured for policy 0.
WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.697249 10.10.50.50:22 -> 10.10.50.14:43324
TCP TTL:64 TOS:0x10 ID:58473 IpLen:20 DgmLen:224 DF
***AP*** Seq: 0x41FA9D6E  Ack: 0x9952E8ED  Win: 0x2AA  TcpLen: 32
TCP Options (3) => NOP NOP TS: 3084882528 2025045861
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.697907 10.10.50.14:43324 -> 10.10.50.50:22
TCP TTL:64 TOS:0x10 ID:63597 IpLen:20 DgmLen:52 DF
***A**** Seq: 0x9952E8ED  Ack: 0x41FA9E1A  Win: 0xD5E  TcpLen: 32
TCP Options (3) => NOP NOP TS: 2025046157 3084882528
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.698092 10.10.50.50:22 -> 10.10.50.14:43324
TCP TTL:64 TOS:0x10 ID:58474 IpLen:20 DgmLen:208 DF
***AP*** Seq: 0x41FA9E1A  Ack: 0x9952E8ED  Win: 0x2AA  TcpLen: 32
TCP Options (3) => NOP NOP TS: 3084882600 2025045861
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.698349 10.10.50.14:43324 -> 10.10.50.50:22
TCP TTL:64 TOS:0x10 ID:63598 IpLen:20 DgmLen:52 DF
***A**** Seq: 0x9952E8ED  Ack: 0x41FA9EB6  Win: 0xD5E  TcpLen: 32
TCP Options (3) => NOP NOP TS: 2025046158 3084882600
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.741010 10.10.50.14:32928 -> 10.10.50.16:8834
TCP TTL:64 TOS:0x0 ID:31593 IpLen:20 DgmLen:60 DF
******S* Seq: 0xF4067E93  Ack: 0x0  Win: 0xFAF0  TcpLen: 40
TCP Options (5) => MSS: 1460 SackOK TS: 2975485121 0 NOP WS: 7
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.743665 10.10.50.16:8834 -> 10.10.50.14:32928
TCP TTL:64 TOS:0x0 ID:0 IpLen:20 DgmLen:60 DF
***A**S* Seq: 0xFAA650A6  Ack: 0xF4067E94  Win: 0xFE88  TcpLen: 40
TCP Options (5) => MSS: 1460 SackOK TS: 2777268919 2975485121 NOP WS: 7
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:49:44.744313 10.10.50.14:32928 -> 10.10.50.16:8834
TCP TTL:64 TOS:0x0 ID:31594 IpLen:20 DgmLen:52 DF
***A**** Seq: 0xF4067E94  Ack: 0xFAA650A7  Win: 0x1F6  TcpLen: 32
TCP Options (3) => NOP NOP TS: 2975485124 2777268919
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

...

WARNING: No preprocessors configured for policy 0.
11/18-15:53:40.192397 10.10.50.24:10080 -> 10.10.50.14:56612
TCP TTL:64 TOS:0x0 ID:39169 IpLen:20 DgmLen:52 DF
***A**** Seq: 0xF4322327  Ack: 0x632444E0  Win: 0x1F9  TcpLen: 32
TCP Options (3) => NOP NOP TS: 2896836642 344422720
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
11/18-15:53:40.192484 10.10.50.14:56612 -> 10.10.50.24:10080
TCP TTL:64 TOS:0x0 ID:2680 IpLen:20 DgmLen:52 DF
***A**** Seq: 0x632444E0  Ack: 0xF4322328  Win: 0x1F5  TcpLen: 32
TCP Options (3) => NOP NOP TS: 344437728 2896836384
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

WARNING: No preprocessors configured for policy 0.
WARNING: No preprocessors configured for policy 0.
WARNING: No preprocessors configured for policy 0.
WARNING: No preprocessors configured for policy 0.
*** Caught Int-Signal
WARNING: No preprocessors configured for policy 0.
11/18-15:53:40.443691 10.10.50.125:61122 -> 239.255.255.250:1900
UDP TTL:1 TOS:0x0 ID:27347 IpLen:20 DgmLen:203
Len: 175
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

===============================================================================
Run time for packet processing was 237.35506 seconds
Snort processed 32155 packets.
Snort ran for 0 days 0 hours 3 minutes 57 seconds
   Pkts/min:        10718
   Pkts/sec:          135
===============================================================================
Memory usage summary:
  Total non-mmapped bytes (arena):       790528
  Bytes in mapped regions (hblkhd):      21590016
  Total allocated space (uordblks):      684720
  Total free space (fordblks):           105808
  Topmost releasable block (keepcost):   103120
===============================================================================
Packet I/O Totals:
   Received:        32170
   Analyzed:        32155 ( 99.953%)
    Dropped:            0 (  0.000%)
   Filtered:            0 (  0.000%)
Outstanding:           15 (  0.047%)
   Injected:            0
===============================================================================
Breakdown by protocol (includes rebuilt packets):
        Eth:        32155 (100.000%)
       VLAN:            0 (  0.000%)
        IP4:        30723 ( 95.547%)
       Frag:            0 (  0.000%)
       ICMP:           30 (  0.093%)
        UDP:         1151 (  3.580%)
        TCP:        29464 ( 91.631%)
        IP6:          295 (  0.917%)
    IP6 Ext:          343 (  1.067%)
   IP6 Opts:           48 (  0.149%)
      Frag6:            0 (  0.000%)
      ICMP6:           69 (  0.215%)
       UDP6:          226 (  0.703%)
       TCP6:            0 (  0.000%)
     Teredo:            0 (  0.000%)
    ICMP-IP:            0 (  0.000%)
    IP4/IP4:            0 (  0.000%)
    IP4/IP6:            0 (  0.000%)
    IP6/IP4:            0 (  0.000%)
    IP6/IP6:            0 (  0.000%)
        GRE:            0 (  0.000%)
    GRE Eth:            0 (  0.000%)
   GRE VLAN:            0 (  0.000%)
    GRE IP4:            0 (  0.000%)
    GRE IP6:            0 (  0.000%)
GRE IP6 Ext:            0 (  0.000%)
   GRE PPTP:            0 (  0.000%)
    GRE ARP:            0 (  0.000%)
    GRE IPX:            0 (  0.000%)
   GRE Loop:            0 (  0.000%)
       MPLS:            0 (  0.000%)
        ARP:          982 (  3.054%)
        IPX:            0 (  0.000%)
   Eth Loop:            0 (  0.000%)
   Eth Disc:            0 (  0.000%)
   IP4 Disc:            0 (  0.000%)
   IP6 Disc:            0 (  0.000%)
   TCP Disc:            0 (  0.000%)
   UDP Disc:            0 (  0.000%)
  ICMP Disc:            0 (  0.000%)
All Discard:            0 (  0.000%)
      Other:          233 (  0.725%)
Bad Chk Sum:            0 (  0.000%)
    Bad TTL:            0 (  0.000%)
     S5 G 1:            0 (  0.000%)
     S5 G 2:            0 (  0.000%)
      Total:        32155
===============================================================================
Snort exiting




snort    2861541  0.2  1.0 134476 85988 ?        Ssl  00:00   1:53 /usr/sbin/snort -m 027 -D -d -l /var/log/snort -u snort -g snort --pid-path /run/snort/ -c /etc/snort/snort.conf -S "HOME_NET=[10.10.0.0/16]" -i wlp3s0
