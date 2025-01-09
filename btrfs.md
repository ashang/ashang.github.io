
```
root@Live-OS:~# fsck /dev/sda1
fsck from util-linux 2.31.1
If you wish to check the consistency of a BTRFS filesystem or
repair a damaged filesystem, see btrfs(8) subcommand 'check'.
root@Live-OS:~# btrfs check /dev/sda1
Checking filesystem on /dev/sda1
UUID: 25ffb95b-49e6-4693-828c-d2a64e57a1ed
checking extents
checking free space cache
checking fs roots
checking csums
checking root refs
found 1648001413120 bytes used, no error found
total csum bytes: 1592789836
total tree bytes: 16581967872
total fs tree bytes: 14062370816
total extent tree bytes: 684081152
btree space waste bytes: 2698227301
file data blocks allocated: 1631421841408
 referenced 1631421816832
```
