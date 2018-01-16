
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
                algorithm.  Typically the overhead of calculating and checking the CRCs is not noticeable in normal operation.

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

