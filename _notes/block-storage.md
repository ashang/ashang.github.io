---
title: block storage
date: 2018-12-14
---

Create new empty partitions
```
# parted -s /dev/vdb mklabel gpt
# parted -s /dev/vdb unit mib mkpart primary 0% 100%
```

Mount block storage:
```
# mkdir /mnt/blockstorage
# echo >> /etc/fstab
# echo /dev/vdb1               /mnt/blockstorage       ext4    defaults,noatime,nofail 0 0 >> /etc/fstab
```

Grow the partition to fill all available block storage space.

```
# growpart /dev/vdb 1
```

Force a filesystem check before resizing.
```
# e2fsck -fp /dev/vdb1
```

Resize the filesystem to fill the entire partition.
```
# resize2fs /dev/vdb1
```

Remount the block storage.
```
# mount /mnt/blockstorage
```
