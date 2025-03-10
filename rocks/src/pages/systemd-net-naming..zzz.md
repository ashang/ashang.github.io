---
title: systemd-net-naming
date: 2022-03-03
---



The naming scheme may also be overridden using the net.naming-scheme= kernel command line switch, see systemd-udevd.service(8). 



Note that while the concept of network interface naming schemes is primarily relevant in the context of systemd-udevd.service, the systemd-nspawn(1) container manager also takes it into account when naming network interfaces

Two character prefixes based on the type of interface

Prefix	Description
en	Ethernet
ib	InfiniBand
sl	Serial line IP (slip)
wl	Wireless local area network (WLAN)
ww	Wireless wide area network (WWAN)



Example 1. Using udevadm test-builtin to display device properties

$ udevadm test-builtin net_id /sys/class/net/enp0s31f6
...
Using default interface naming scheme 'v243'.
ID_NET_NAMING_SCHEME=v243
ID_NET_NAME_MAC=enx54ee75cb1dc0
ID_OUI_FROM_DATABASE=Wistron InfoComm(Kunshan)Co.,Ltd.
ID_NET_NAME_PATH=enp0s31f6
...

Example 2. PCI Ethernet card with firmware index "1"

ID_NET_NAME_ONBOARD=eno1
ID_NET_NAME_ONBOARD_LABEL=Ethernet Port 1
      

Example 3. PCI Ethernet card in hotplug slot with firmware index number

# /sys/devices/pci0000:00/0000:00:1c.3/0000:05:00.0/net/ens1
ID_NET_NAME_MAC=enx000000000466
ID_NET_NAME_PATH=enp5s0
ID_NET_NAME_SLOT=ens1

Example 4. PCI Ethernet multi-function card with 2 ports

# /sys/devices/pci0000:00/0000:00:1c.0/0000:02:00.0/net/enp2s0f0
ID_NET_NAME_MAC=enx78e7d1ea46da
ID_NET_NAME_PATH=enp2s0f0

# /sys/devices/pci0000:00/0000:00:1c.0/0000:02:00.1/net/enp2s0f1
ID_NET_NAME_MAC=enx78e7d1ea46dc
ID_NET_NAME_PATH=enp2s0f1

Example 5. PCI WLAN card

# /sys/devices/pci0000:00/0000:00:1c.1/0000:03:00.0/net/wlp3s0
ID_NET_NAME_MAC=wlx0024d7e31130
ID_NET_NAME_PATH=wlp3s0

Example 6. PCI IB host adapter with 2 ports

# /sys/devices/pci0000:00/0000:00:03.0/0000:15:00.0/net/ibp21s0f0
ID_NET_NAME_PATH=ibp21s0f0

# /sys/devices/pci0000:00/0000:00:03.0/0000:15:00.1/net/ibp21s0f1
ID_NET_NAME_PATH=ibp21s0f1

Example 7. USB built-in 3G modem

# /sys/devices/pci0000:00/0000:00:1d.0/usb2/2-1/2-1.4/2-1.4:1.6/net/wwp0s29u1u4i6
ID_NET_NAME_MAC=wwx028037ec0200
ID_NET_NAME_PATH=wwp0s29u1u4i6

Example 8. USB Android phone

# /sys/devices/pci0000:00/0000:00:1d.0/usb2/2-1/2-1.2/2-1.2:1.0/net/enp0s29u1u2
ID_NET_NAME_MAC=enxd626b3450fb5
ID_NET_NAME_PATH=enp0s29u1u2


-p, --path=DEVPATH¶
The /sys path of the device to query, e.g. [/sys]/class/block/sda. This option is an alternative to the positional argument with a /sys/ prefix. udevadm info --path=/class/block/sda is equivalent to udevadm info /sys/class/block/sda.

-n, --name=FILE
The name of the device node or a symlink to query, e.g. [/dev]/sda. This option is an alternative to the positional argument with a /dev/ prefix. udevadm info --name=sda is equivalent to udevadm info /dev/sda.

-r, --root
Print absolute paths in name or symlink query.

