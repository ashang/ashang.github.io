

[IP: Sec:  Score:-/100 ヽ༼ ಠ益ಠ ༽ﾉ]
[06:17:08] kodachi@Live-OS:~/Desktop $ sudo parted -l
Model: DELL PERC H310 (scsi)
Disk /dev/sda: 6595GB
Sector size (logical/physical): 512B/512B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name  Flags
 1      1049kB  6595GB  6595GB  ext4
 2      6595GB  6595GB  188MB   fat16              boot, esp


Model: Kingston DataTraveler G2 (scsi)
Disk /dev/sdb: 4010MB
Sector size (logical/physical): 512B/512B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name     Flags
 1      1049kB  3976MB  3975MB               Ventoy   msftdata
 2      3976MB  4010MB  33.6MB  fat16        VTOYEFI  hidden, msftdata


[06:17:14] kodachi@Live-OS:~/Desktop $ sudo fsck -y /dev/sda1
fsck from util-linux 2.31.1
e2fsck 1.44.1 (24-Mar-2018)
/dev/sda1: clean, 14710275/402522112 files, 407665260/1610074744 blocks
[06:17:24] kodachi@Live-OS:~/Desktop $ sudo fsck -yf /dev/sda1
fsck from util-linux 2.31.1
e2fsck 1.44.1 (24-Mar-2018)
Pass 1: Checking inodes, blocks, and sizes
Pass 2: Checking directory structure
Pass 3: Checking directory connectivity
Pass 4: Checking reference counts
Pass 5: Checking group summary information
/dev/sda1: 14710275/402522112 files (0.2% non-contiguous), 407665260/1610074744 blocks
[06:20:15] kodachi@Live-OS:~/Desktop $



