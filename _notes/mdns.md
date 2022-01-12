

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



