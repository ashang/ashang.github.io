---
title: ethtool
date: 2017-10-01
---

ethtool can query NIC speed, auto-negotiation and checksum offload.

# Features

- Get identification and diagnostic information
- Get extended device statistics
- Control speed, duplex, autonegotiation and flow control for Ethernet devices
- Control checksum offload and other hardware offload features
- Control DMA ring sizes and interrupt moderation
- Control receive queue selection for multiqueue devices
- Upgrade firmware in flash memory

Most features are dependent on support in the specific driver.

# Common usage

Some queries need priviledges.

```
$ sudo ethtool eth0
Settings for eth0:
        Supported ports: [ TP ]
        Supported link modes:   10baseT/Half 10baseT/Full
                                100baseT/Half 100baseT/Full
                                1000baseT/Half 1000baseT/Full
        Supported pause frame use: No
        Supports auto-negotiation: Yes
        Advertised link modes:  10baseT/Half 10baseT/Full
                                100baseT/Half 100baseT/Full
                                1000baseT/Half 1000baseT/Full
        Advertised pause frame use: Symmetric
        Advertised auto-negotiation: Yes
        Link partner advertised link modes:  10baseT/Half 10baseT/Full
                                             100baseT/Half 100baseT/Full
                                             1000baseT/Full
        Link partner advertised pause frame use: No
        Link partner advertised auto-negotiation: Yes
        Speed: 1000Mb/s
        Duplex: Full
        Port: Twisted Pair
        PHYAD: 1
        Transceiver: internal
        Auto-negotiation: on
        MDI-X: off
        Supports Wake-on: g
        Wake-on: d
        Current message level: 0x000000ff (255)
                               drv probe link timer ifdown ifup rx_err tx_err
        Link detected: yes
```

## -i

```
$ sudo ethtool -i enp0s31f6
driver: e1000e
version: 5.13.0-22-generic
firmware-version: 0.8-4
expansion-rom-version:
bus-info: 0000:00:1f.6
supports-statistics: yes
supports-test: yes
supports-eeprom-access: yes
supports-register-dump: yes
supports-priv-flags: yes
# ethtool -i docker0
driver: bridge
version: 2.3
firmware-version: N/A
expansion-rom-version:
bus-info: N/A
supports-statistics: no
supports-test: no
supports-eeprom-access: no
supports-register-dump: no
supports-priv-flags: no
# ethtool -i wlp5s0
driver: iwlwifi
version: 5.13.0-22-generic
firmware-version: 29.4063824552.0 7265D-29.ucode
expansion-rom-version:
bus-info: 0000:05:00.0
supports-statistics: yes
supports-test: no
supports-eeprom-access: no
supports-register-dump: no
supports-priv-flags: no
# ethtool -i br-d645f86901eb
driver: bridge
version: 2.3
firmware-version: N/A
expansion-rom-version:
bus-info: N/A
supports-statistics: no
supports-test: no
supports-eeprom-access: no
supports-register-dump: no
supports-priv-flags: no
```

## Blink a NIC

```
$ ethtool -p eth0
```

For two minutes:

```
$ ethtool -p eth0 120
```

## -t

```
$ sudo ethtool -t eno1
The test result is PASS
The test extra info:
nvram test        (online)       0
link test         (online)       0
register test     (offline)      0
memory test       (offline)      0
mac loopback test (offline)      0
phy loopback test (offline)      0
ext loopback test (offline)      0
interrupt test    (offline)      0
```

>-t, --test devname word
>
>>    where word is one of the following:
>>
>>    offline — Perform a comprehensive set of tests. Service will be interrupted.
>>
>>    online — Perform a reduced set of tests. Service should not be interrupted.

# Some deb distros support interface scripts.

```
$ sudo vim /etc/network/interfaces
post-up ethtool -s eth2 speed 1000 duplex full autoneg off
```

## Setting NIC features.

```
# ethtool -s eth0 speed 1000 duplex full autoneg off
# ethtool -s enp0s31f6 speed 100 duplex full autoneg off
# ethtool -s enp0s31f6 speed 1000 duplex full autoneg off
```

## -x

```
$ ethtool -x eth0
RX flow hash indirection table for eth0 with 4 RX ring(s):
    0:      0     1     2     3     0     1     2     3
    8:      0     1     2     3     0     1     2     3
   16:      0     1     2     3     0     1     2     3
   24:      0     1     2     3     0     1     2     3
   32:      0     1     2     3     0     1     2     3
   40:      0     1     2     3     0     1     2     3
   48:      0     1     2     3     0     1     2     3
   56:      0     1     2     3     0     1     2     3
   64:      0     1     2     3     0     1     2     3
   72:      0     1     2     3     0     1     2     3
   80:      0     1     2     3     0     1     2     3
   88:      0     1     2     3     0     1     2     3
   96:      0     1     2     3     0     1     2     3
  104:      0     1     2     3     0     1     2     3
  112:      0     1     2     3     0     1     2     3
  120:      0     1     2     3     0     1     2     3
```

Once you change the speed when the adapter is online, it automatically goes offline, and you need to bring it back online.
That can be done by using `ifup` or `ip link set <dev> up` .

# On wifi

ethtool on wifi interface can only show the link status.

```
$ ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host
       valid_lft forever preferred_lft forever
2: wlo1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default qlen 1000
    link/ether b4:69:21:53:28:c0 brd ff:ff:ff:ff:ff:ff
    altname wlp0s20f3
    inet 10.10.50.13/24 brd 10.10.50.255 scope global dynamic noprefixroute wlo1
       valid_lft 41366sec preferred_lft 41366sec
    inet6 fe80::a49c:2ce3:9ab1:dde5/64 scope link noprefixroute
       valid_lft forever preferred_lft forever
3: br-a80da0ac7f38: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default
    link/ether 02:42:dd:2c:d2:72 brd ff:ff:ff:ff:ff:ff
    inet 192.168.58.1/24 brd 192.168.58.255 scope global br-a80da0ac7f38
       valid_lft forever preferred_lft forever
4: docker0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default
    link/ether 02:42:b6:0b:31:ed brd ff:ff:ff:ff:ff:ff
    inet 172.17.0.1/16 brd 172.17.255.255 scope global docker0
       valid_lft forever preferred_lft forever
5: br-d3426515317e: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default
    link/ether 02:42:15:75:86:30 brd ff:ff:ff:ff:ff:ff
    inet 172.18.0.1/16 brd 172.18.255.255 scope global br-d3426515317e
       valid_lft forever preferred_lft forever

$ ethtool wlo1
Settings for wlo1:
	Link detected: yes

$ ethtool -i wlo1
driver: iwlwifi
version: 5.10.86-1-MANJARO
firmware-version: 46.6b541b68.0 9000-pu-b0-jf-b0-
expansion-rom-version:
bus-info: 0000:00:14.3
supports-statistics: yes
supports-test: no
supports-eeprom-access: no
supports-register-dump: no
supports-priv-flags: no
```

```
$ sudo ethtool -S wlo1
NIC statistics:
     rx_packets: 75551
     rx_bytes: 8534342
     rx_duplicates: 0
     rx_fragments: 82037
     rx_dropped: 6944
     tx_packets: 97930
     tx_bytes: 22451922
     tx_filtered: 0
     tx_retry_failed: 0
     tx_retries: 5063
     sta_state: 4
     txrate: 263300000
     rxrate: 433300000
     signal: 202
     channel: 0
     noise: 18446744073709551615
     ch_time: 18446744073709551615
     ch_time_busy: 18446744073709551615
     ch_time_ext_busy: 18446744073709551615
     ch_time_rx: 18446744073709551615
     ch_time_tx: 18446744073709551615
```

```
$ ethtool -T wlo1
Time stamping parameters for wlo1:
Capabilities:
        software-receive
        software-system-clock
PTP Hardware Clock: none
Hardware Transmit Timestamp Modes: none
Hardware Receive Filter Modes: none
```

# API

ethtool consists of two components, an API within the Linux kernel through which NICs can send and receive parameters through their device driver software, and a userspace API based on the Linux SIOCETHTOOL ioctl mechanism through which application programs can communicate with the kernel to send and receive NIC and NIC driver parameters.

# Notes from the authors

>The ethtool utility is intended for use by system administrators and network administrators, and not primarily by kernel developers.
>
>It should not expose unpleasant details of the ethtool API to the user if this can be avoided. For example, the user should not need to know the unfortunate history
of and subtle differences between the RX n-tuple versus RX NFC commands. If the user runs ethtool -U with a filter specification that can be represented
through either ETHTOOL_SRXNTUPLE or ETHTOOL_RXCLSRLINS, we will try both commands in turn.
>
>Many existing options return exit codes indicating specific failure points. This is not sustainable, as exit codes are 8-bit and shells assign special
meaning to values from 127 upward. Any new failure points must produce an exit code of 1.
