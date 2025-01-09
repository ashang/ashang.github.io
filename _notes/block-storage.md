---
title: block storage
date: 2018-12-14
---

Create new empty partitions
```shell
# parted -s /dev/vdb mklabel gpt
# parted -s /dev/vdb unit mib mkpart primary 0% 100%
```

Mount block storage:
```shell
# mkdir /mnt/blockstorage
# echo >> /etc/fstab
# echo /dev/vdb1 /mnt/blockstorage ext4 defaults,noatime,nofail 0 0 >> /etc/fstab
```

Grow the partition to fill all available block storage space.

```shell
# growpart /dev/vdb 1
```

Force a filesystem check before resizing.
```shell
# e2fsck -fp /dev/vdb1
```

Resize the filesystem to fill the entire partition.
```shell
# resize2fs /dev/vdb1
```

Remount the block storage.
```shell
# mount /mnt/blockstorage
```
