
# /etc/network/interfaces

/etc/network/interfaces contains network interface configuration information for the ifup(8) and ifdown(8) commands. This is where you configure how your system is connected to the network.

For more information, see interfaces(5).

## EXAMPLE

The following example configures two network interfaces: eth0 is brought up at boot, and uses DHCP for IPv4 and SLAAC for IPv6, whereas eth1 is brought up whenever the network hardware is detected, and is configured with static IPv4 and IPv6 addresses.

```conf
auto eth0
allow-hotplug eth1

iface eth0 inet dhcp

iface eth0 inet6 auto

iface eth1 inet static
     address 192.168.1.2/24
     gateway 192.168.1.1


iface eth1 inet6 static
     address fec0:0:0:1::2/64
     gateway fec0:0:0:1::1
```

```shell
$ cat /etc/network/interfaces
# This file describes the network interfaces available on your system
# and how to activate them. For more information, see interfaces(5).

source /etc/network/interfaces.d/*

auto lo enp7s0

iface lo inet loopback

allow-hotplug enp7s0
#iface enp7s0 inet dhcp

iface enp7s0 inet static
        address 10.10.10.19
        netmask 255.255.255.0
        network 10.10.10.0
        broadcast 10.10.10.255
        gateway 10.10.10.1

iface enp7s0 inet static
  address 10.10.10.17
  netmask 255.255.255.0
```

#wireless-key s:B19227ef6e
#wireless-essid midgroup

The file consists of zero or more "iface", "mapping", "auto", "allow-", "source" and "source-directory" stanzas. Here is an example:

```conf
allow-hotplug eth1

source interfaces.d/machine-dependent

source-directory interfaces.d

mapping eth1
     script /usr/local/sbin/map-scheme
     map HOME eth0-home
     map WORK eth0-work

iface eth1-home inet static
     address 192.168.1.2/24
     gateway 192.168.1.1
     up flush-mail
```

iface eth1-work inet dhcp

Lines  beginning  with  the  word  "auto" are used to identify the physical interfaces to be brought up when ifup is run with the -a option.  (This option is used by the system boot scripts.)  Physical interface names should follow the word "auto" on the same line.  There can be multiple "auto" stanzas.
ifup brings the named interfaces up in the order listed.

Lines beginning with "allow-" are used to identify interfaces that should be brought up automatically by various subsytems. This may be done using a command such as "ifup --allow=hotplug eth0 eth1", which will only bring up eth0 or eth1 if it is listed in an "allow-hotplug" line. Note that  "allow-auto"
and "auto" are synonyms.

Lines beginning with "no-auto-down" are used to identify interfaces that should not be brought down by the command "ifdown -a". Its main use is to prevent an interface from being brought down during system shutdown time, for example if the root filesystem is a network filesystem and the interface should
stay up until the very end. Note that you can still bring down the interface by specifying the interface name explicitly.

Lines beginning with "no-scripts" are used to identify interfaces for which scripts in /etc/network/if-*.d/ should not be run when those interfaces are brought up or down.

Lines beginning with "source" are used to include stanzas from other files, so configuration can be split into many files. The word "source" is followed by the path of file to be sourced. Shell wildcards can be used.  (See wordexp(3) for details.)

Similarly, "source-directory" keyword is used to source multiple files at once, without specifying them individually or using shell globs. Additionally, when "source-directory" is used, names of the files are checked to match the following regular expression: ^[a-zA-Z0-9_-]+$. In other words, the  names
must consist entirely of ASCII upper- and lower-case letters, ASCII digits, ASCII underscores, and ASCII minus-hyphens. In the directory path, shell wildcards may be used as well.

When  sourcing  files  or  directories,  if  a  path doesn't have a leading slash, it's considered relative to the directory containing the file in which the keyword is placed. In the example above, if the file is located at /etc/network/interfaces, paths to the included files are understood to be under
/etc/network.

Currently, "source-directory" isn't supported by network-manager and guessnet.

ifconfig wlan0 down
ifconfig wlan0 hw ether 13:11:20:33:49:66
ifconfig wlan0 up

# ifconfig
eth0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 10.10.50.10  netmask 255.255.255.0  broadcast 10.10.50.255
        inet6 fe80::92b1:1cff:fe11:709a  prefixlen 64  scopeid 0x20<link>
        ether 90:b1:1c:11:70:9a  txqueuelen 1000  (Ethernet)
        RX packets 10372195  bytes 1690920390 (1.6 GB)
        RX errors 0  dropped 242  overruns 0  frame 0
        TX packets 14186160  bytes 18831118036 (18.8 GB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
        device interrupt 16

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 0  (Local Loopback)
        RX packets 25930  bytes 52654085 (52.6 MB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 25930  bytes 52654085 (52.6 MB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

you can only have one default gateway in your setup. I missed this because I was also trying to add routes to networks behind the machine on the other end of eth3.
In the end, removing the gw line in the eth3 entry solved the problem.

My final /etc/networking/interfaces looks like this:

# The loopback network interface
auto lo
iface lo inet loopback

auto eth0
iface eth0 inet static
        address xxx.yyy.zzz.mmm
        netmask 255.255.255.0
        gateway xxx.yyy.zzz.1
        dns-nameservers xxx.yyy.zzz.aaa xxx.yyy.zzz.bbb
        dns-search mydomain.nl

auto eth3
iface eth3 inet static
        address 192.168.4.1
        netmask 255.255.255.0
        post-up /sbin/route add -net 192.168.1.0 netmask 255.255.255.0 gw 192.168.4.250
        post-up /sbin/route add -net 192.168.2.0 netmask 255.255.255.0 gw 192.168.4.250
        post-up /sbin/route add -net 192.168.3.0 netmask 255.255.255.0 gw 192.168.4.250
        post-down /sbin/route del -net 192.168.1.0 netmask 255.255.255.0
        post-down /sbin/route del -net 192.168.2.0 netmask 255.255.255.0
        post-down /sbin/route del -net 192.168.3.0 netmask 255.255.255.0

## The loopback network interface

auto lo
iface lo inet loopback

Bridging software will configure eth0 when it is added as a port to br0 (below)

This minimal configuration avoids message "Ignoring unknown interface eth0=eth0"

auto eth0
iface eth0 inet manual
up ifconfig $IFACE 0.0.0.0 up
down ifconfig $IFACE down

## TAP

tap0 is a tap int the brige below for use by VirtualBox.
# * Guest OS will configure, hence "manual"
# * VirtualBox will be running with owner c (and group vboxusers), hence user c
# * "ifconfig" is part of ifupdown package
# * "tunctl_user" is part of tunctl package
auto tap0
iface tap0 inet manual
up ifconfig $IFACE 0.0.0.0 up
down ifconfig $IFACE down
tunctl_user c

# tap1, same as tap0, for second VirtualBox VM
auto tap1
iface tap1 inet manual
up ifconfig $IFACE 0.0.0.0 up
down ifconfig $IFACE down
tunctl_user c

# br0 is a bridge connecting physical interface eth0 to OS, tap0 and tap1
# * Bridge port stanzas must appear earlier
# * Static configuration
# * No need for spanning tree protocol (stp) because no other bridges on network
auto br0
iface br0 inet static
address 192.168.1.47
network 192.168.1.0
netmask 255.255.255.0
broadcast 192.168.1.255
gateway 192.168.1.1
bridge_ports eth0 tap0 tap1
bridge_maxwait 0
bridge_stp off

## TUN

tun1 is a point-to-point interface, you do not need a gateway to send out packets.
