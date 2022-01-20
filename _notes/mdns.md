

mDNS/DNS-SD is a protocol for service discovery in a local area network.

It is standardized under RFCs 6762 [1] and 6763[2].

The protocol is also known by the Bonjour trademark by Apple, or Zeroconf.

On Linux, it is implemented in avahi (http://www.avahi.org/).

[1] http://tools.ietf.org/html/rfc6762
[2] http://tools.ietf.org/html/rfc6763


## Avahi usage

avahi-daemon is the main process that takes care of proper operation of the protocol. It takes care of
any configuration of the interfaces and network messaging. A user can control the deamon with
command line utilities, or via D-Bus. In this document, we will describe the former option. For the latter
one, please see http://www.avahi.org/wiki/Bindings.

 mDNS is a zero-configuration service, using essentially the same programming interfaces, packet formats and operating semantics as unicast Domain Name Service (DNS). It was designed to work as either a stand-alone protocol or compatibly with standard DNS servers.

It uses IP multicast User Datagram Protocol (UDP) packets, and is implemented by the Apple Bonjour and open source Avahi software packages



mDNS can work in conjunction with DNS Service Discovery (DNS-SD), a companion zero-configuration networking technique specified separately in RFC 6763.[4]



When an mDNS client needs to resolve a hostname, it sends an IP multicast query message that asks the host having that name to identify itself. That target machine then multicasts a message that includes its IP address. All machines in that subnet can then use that information to update their mDNS caches. Any host can relinquish its claim to a name by sending a response packet with a time to live (TTL) equal to zero.

By default, mDNS exclusively resolves hostnames ending with the .local top-level domain. This can cause problems if .local includes hosts that do not implement mDNS but that can be found via a conventional unicast DNS server. Resolving such conflicts requires network-configuration changes that mDNS was designed to avoid.


## Packet structure

An mDNS message is a multicast UDP packet sent using the following addressing:

IPv4 address 224.0.0.251 or IPv6 address ff02::fb
UDP port 5353
When using Ethernet frames, the standard IP multicast MAC address 01:00:5E:00:00:FB (for IPv4) or 33:33:00:00:00:FB (for IPv6)
The payload structure is based on the unicast DNS packet format, consisting of two parts—the header and the data.[5]

The header is identical to that found in unicast DNS, as are the sub-sections in the data part: queries, answers, authoritative-nameservers, and additional records. The number of records in each sub-section matches the value of the corresponding *COUNT field in the header.

## Link-Local Multicast Name Resolution (LLMNR)

In responding to queries, responders listen on UDP port 5355 on the following link-scope Multicast address:

IPv4 - 224.0.0.252, MAC address 01-00-5E-00-00-FC
IPv6 - FF02:0:0:0:0:0:1:3 (this notation can be abbreviated as FF02::1:3), MAC address 33-33-00-01-00-03
The responders also listen on TCP port 5355 on the unicast address that the host uses to respond to queries.




