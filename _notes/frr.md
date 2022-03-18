---
title: frr
date: 2018-10-24
---

```
 /usr/bin/install -c -m 644 ../eigrpd/eigrp_dump.h ../eigrpd/eigrp_topology.h ../eigrpd/eigrpd.h '/home/aaron/arm/build/rootfs/usr/include/frr/eigrpd'
   /bin/bash ./libtool   --mode=install /usr/bin/install -c -s  zebra/zebra_irdp.la zebra/zebra_snmp.la zebra/zebra_fpm.la zebra/zebra_cumulus_mlag.la zebra/dplane_fpm_nl.la bgpd/bgpd_snmp.la bgpd/bgpd_bmp.la ripd/ripd_snmp.la ospfd/ospfd_snmp.la ospf6d/ospf6d_snmp.la isisd/isisd_snmp.la ldpd/ldpd_snmp.la pathd/pathd_pcep.la '/home/aaron/arm/build/rootfs/usr/lib/frr/modules'
   libtool: install: /usr/bin/install -c zebra/.libs/zebra_irdp.so /home/aaron/arm/build/rootfs/usr/lib/frr/modules/zebra_irdp.so
   libtool: install: arm-linux-gnueabi-strip --strip-unneeded /home/aaron/arm/build/rootfs/usr/lib/frr/modules/zebra_irdp.so
   libtool: install: /usr/bin/install -c zebra/.libs/zebra_irdp.lai /home/aaron/arm/build/rootfs/usr/lib/frr/modules/zebra_irdp.la
   libtool:   error: error: cannot install 'zebra/zebra_snmp.la' to a directory not ending in /usr/lib/arm-linux-gnueabi/frr/modules
   make[3]: *** [Makefile:6267: install-moduleLTLIBRARIES] Error 1
```
