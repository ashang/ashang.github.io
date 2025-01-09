---
title: zfs
date: 2017-01-26
--- 

ZFS is a next generation filesystem that supports many advanced storage
technologies such as volume management, snapshots, checksumming, compression
and deduplication, replication and more.

It was created by Sun Microsystems (now Oracle Corporation) and is open sourced
under the CDDL license. Due to licensing incompatibilities between the CDDL and
GPL, ZFS cannot be shipped as part of the mainline Linux kernel. However, the
ZFS On Linux (ZoL) project provides an out-of-tree kernel module and userspace
tools which can be installed separately.

ZFS filesystems are thinly provisioned and have space allocated to them from a
ZFS pool (zpool) via allocate on demand operations. Snapshots and clones are
space-efficient point-in-time copies of ZFS filesystems. Snapshots are
read-only. Clones are read-write. Clones can only be created from snapshots. 

By default, ZFS will allocate space in blocks of 128K.


Create a new zpool.

# zpool create -f zpool-docker /dev/xvdb

Check that the zpool exists.

# zfs list
NAME            USED  AVAIL    REFER  MOUNTPOINT
zpool-docker    55K   3.84G    19K    /zpool-docker


# docker info
Containers: 0
Images: 0
Storage Driver: zfs
 Zpool: zpool-docker
 Zpool Health: ONLINE
 Parent Dataset: zpool-docker/docker
 Space Used By Parent: 27648
 Space Available: 4128139776
 Parent Quota: no
 Compression: off
Execution Driver: native-0.2
[...]


Memory. Memory has a major impact on ZFS performance. This goes back to the fact that ZFS was originally designed for use on big Sun Solaris servers with large amounts of memory. Keep this in mind when sizing your Docker hosts.

ZFS Features. Using ZFS features, such as deduplication, can significantly increase the amount of memory ZFS uses. For memory consumption and performance reasons it is recommended to turn off ZFS deduplication. However, deduplication at other layers in the stack (such as SAN or NAS arrays) can still be used as these do not impact ZFS memory usage and performance. If using SAN, NAS or other hardware RAID technologies you should continue to follow existing best practices for using them with ZFS.

ZFS Caching. ZFS caches disk blocks in a memory structure called the adaptive replacement cache (ARC). The Single Copy ARC feature of ZFS allows a single cached copy of a block to be shared by multiple clones of a filesystem. This means that multiple running containers can share a single copy of cached block. This means that ZFS is a good option for PaaS and other high density use cases.

Fragmentation. Fragmentation is a natural byproduct of copy-on-write filesystems like ZFS. However, ZFS writes in 128K blocks and allocates slabs (multiple 128K blocks) to CoW operations in an attempt to reduce fragmentation. The ZFS intent log (ZIL) and the coalescing of writes (delayed writes) also help to reduce fragmentation.

Use the native ZFS driver for Linux. Although the Docker zfs storage driver supports the ZFS FUSE implementation, it is not recommended when high performance is required. The native ZFS on Linux driver tends to perform better than the FUSE implementation.

Use of SSD. For best performance it is always a good idea to use fast storage media such as solid state devices (SSD). However, if you only have a limited amount of SSD storage available it is recommended to place the ZIL on SSD.

Use Data Volumes. Data volumes provide the best and most predictable performance. This is because they bypass the storage driver and do not incur any of the potential overheads introduced by thin provisioning and copy-on-write. For this reason, you should place heavy write workloads on data volumes.
