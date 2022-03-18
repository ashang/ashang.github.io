---
title: xfs
date: 2019-03-05
---

```
# mkfs.xfs /dev/sdc2
meta-data=/dev/sdc2              isize=512    agcount=4, agsize=30511297 blks
         =                       sectsz=4096  attr=2, projid32bit=1
         =                       crc=1        finobt=1, sparse=1, rmapbt=0
         =                       reflink=1    bigtime=0
data     =                       bsize=4096   blocks=122045185, imaxpct=25
         =                       sunit=0      swidth=0 blks
naming   =version 2              bsize=4096   ascii-ci=0, ftype=1
log      =internal log           bsize=4096   blocks=59592, version=2
         =                       sectsz=4096  sunit=1 blks, lazy-count=1
realtime =none                   extsz=4096   blocks=0, rtextents=0


# mkfs.xfs /dev/sdd2
meta-data=/dev/sdd2              isize=512    agcount=4, agsize=61034797 blks
         =                       sectsz=4096  attr=2, projid32bit=1
         =                       crc=1        finobt=1, sparse=1, rmapbt=0
         =                       reflink=1    bigtime=0
data     =                       bsize=4096   blocks=244139185, imaxpct=25
         =                       sunit=0      swidth=0 blks
naming   =version 2              bsize=4096   ascii-ci=0, ftype=1
log      =internal log           bsize=4096   blocks=119208, version=2
         =                       sectsz=4096  sunit=1 blks, lazy-count=1
realtime =none                   extsz=4096   blocks=0, rtextents=0

# mount /dev/sdd2 /mnt/

$ mount
sysfs on /sys type sysfs (rw,nosuid,nodev,noexec,relatime)
proc on /proc type proc (rw,nosuid,nodev,noexec,relatime)
udev on /dev type devtmpfs (rw,nosuid,relatime,size=3996004k,nr_inodes=999001,mode=755)
devpts on /dev/pts type devpts (rw,nosuid,noexec,relatime,gid=5,mode=620,ptmxmode=000)
tmpfs on /run type tmpfs (rw,nosuid,nodev,noexec,relatime,size=807836k,mode=755)
/dev/sdb2 on / type ext4 (rw,relatime)
securityfs on /sys/kernel/security type securityfs (rw,nosuid,nodev,noexec,relatime)
tmpfs on /dev/shm type tmpfs (rw,nosuid,nodev)
tmpfs on /run/lock type tmpfs (rw,nosuid,nodev,noexec,relatime,size=5120k)
cgroup2 on /sys/fs/cgroup type cgroup2 (rw,nosuid,nodev,noexec,relatime,nsdelegate,memory_recursiveprot)
pstore on /sys/fs/pstore type pstore (rw,nosuid,nodev,noexec,relatime)
efivarfs on /sys/firmware/efi/efivars type efivarfs (rw,nosuid,nodev,noexec,relatime)
none on /sys/fs/bpf type bpf (rw,nosuid,nodev,noexec,relatime,mode=700)
systemd-1 on /proc/sys/fs/binfmt_misc type autofs (rw,relatime,fd=29,pgrp=1,timeout=0,minproto=5,maxproto=5,direct,pipe_ino=857)
hugetlbfs on /dev/hugepages type hugetlbfs (rw,relatime,pagesize=2M)
mqueue on /dev/mqueue type mqueue (rw,nosuid,nodev,noexec,relatime)
debugfs on /sys/kernel/debug type debugfs (rw,nosuid,nodev,noexec,relatime)
tracefs on /sys/kernel/tracing type tracefs (rw,nosuid,nodev,noexec,relatime)
sunrpc on /run/rpc_pipefs type rpc_pipefs (rw,relatime)
fusectl on /sys/fs/fuse/connections type fusectl (rw,nosuid,nodev,noexec,relatime)
configfs on /sys/kernel/config type configfs (rw,nosuid,nodev,noexec,relatime)
none on /run/credentials/systemd-sysusers.service type ramfs (ro,nosuid,nodev,noexec,relatime,mode=700)
/dev/sda2 on /home type ext4 (rw,relatime)
binfmt_misc on /proc/sys/fs/binfmt_misc type binfmt_misc (rw,nosuid,nodev,noexec,relatime)
tmpfs on /run/user/1000 type tmpfs (rw,nosuid,nodev,relatime,size=807832k,nr_inodes=201958,mode=700,uid=1000,gid=1000)
/dev/sdd2 on /mnt type xfs (rw,relatime,attr2,inode64,logbufs=8,logbsize=32k,noquota)
```

## xfs with grub

```
$ mkfs.xfs -V
mkfs.xfs version 4.3.0
```

From `man mkfs.xfs`

    -m global_metadata_options
        These options specify metadata format options that either apply to the entire filesystem or aren't easily characterised by a specific functionality group. The valid global_metadata_options are:

            crc=value
                This  is used to create a filesystem which maintains and checks CRC information in all metadata objects on disk. The value is either 0 to disable the feature, or 1 to enable the use
                of CRCs.

                CRCs enable enhanced error detection due to hardware issues, whilst the format changes also improves crash recovery algorithms and the ability  of  various  tools  to  validate  and
                repair  metadata corruptions when they are found.  The CRC algorithm used is CRC32c, so the overhead is dependent on CPU architecture as some CPUs have hardware acceleration of this
                algorithm. The overhead of calculating and checking the CRCs is not noticeable in normal operation.

                By default, mkfs.xfs will enable metadata CRCs.

            finobt=value
                This option enables the use of a separate free inode btree index in each allocation group. The value is either 0 to disable the feature, or 1 to create a free inode  btree  in  each
                allocation group.

                The free inode btree mirrors the existing allocated inode btree index which indexes both used and free inodes. The free inode btree does not index used inodes, allowing faster, more
                consistent inode allocation performance as filesystems age.

                By default, mkfs.xfs will create free inode btrees for filesystems created with the (default) -m crc=1 option set. When the option -m crc=0 is used, the free inode btree feature  is
                not supported and is disabled.


By default, mkfs.xfs will enable metadata CRCs, thus enabled both, `crc=1 finobt=1`.


```
$ xfs_info /dev/sdb1
meta-data=/dev/sdb1              isize=512    agcount=4, agsize=201039744 blks
         =                       sectsz=512   attr=2, projid32bit=1
         =                       crc=1        finobt=1 spinodes=0
data     =                       bsize=4096   blocks=804158976, imaxpct=5
         =                       sunit=0      swidth=0 blks
naming   =version 2              bsize=4096   ascii-ci=0 ftype=1
log      =internal               bsize=4096   blocks=392655, version=2
         =                       sectsz=512   sunit=0 blks, lazy-count=1
realtime =none                   extsz=4096   blocks=0, rtextents=0

```

To `mkfs.xfs -m crc=0` disables both.

```
mkfs.xfs -m crc=0
```

Or, build grub from git.



## self describing metadata

xfsprogs 3.2.0 has introduced a new on-disk format (v5) that includes a metadata checksum scheme called Self-Describing Metadata. Based upon CRC32 it provides for example additional protection against metadata corruption during unexpected power losses. Checksum is enabled by default when using xfsprogs 3.2.3 or later.

As per XFS wiki, consider changing the default CFQ I/O scheduler (for example to Deadline, Noop or BFQ) to enjoy all of the benefits of XFS, especially on SSDs.

- https://wiki.archlinux.org/index.php/XFS
- https://www.kernel.org/doc/Documentation/filesystems/xfs-self-describing-metadata.txt
- http://xfs.org/index.php/XFS_FAQ

