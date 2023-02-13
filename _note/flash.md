---
title: "Flash 软硬兼施"
---

# FS

Raw NAND 只能支持 Flash 文件系统如，jffs，yaffs，ubifs。不支持 ext 等以磁盘为基础的文件系统。

NAND 基础上有控制器的，如 U 盘，mmc，emmc, ufs, ssd 等则可以使用 ext

Yaffs2 以及 UBIFS 都是基于 linux 的 MTD 层而实现的。

MTD 层就是
linux 对于 NAND flash driver 封装的一个抽象层。

随着 EMMC 的发展，厂商将 FTL 的实现集成在 EMMC 内部。

这样 EMMC 就成为一个以 NAND flash 为介质的块设备。

EXT3/4 都是为了传统块设备而设计的文件系统。并不能发挥出 EMMC 的特性。

F2FS 基于块设备接口而设计，充分考虑到了 NAND flash 类介质的特性。

F2FS 设计时考虑了 Flash 储存的特性，比如说让写入的数据尽可能的写满一个数据
块，比如说基于日志结构可以 copy-on-write，避免改写，比如说区别冷热数据…

$ sudo parted -l
Model: ATA WDC WD10JPVT-08A (scsi)
Disk /dev/sda: 1000GB
Sector size (logical/physical): 512B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name                          Flags
 1      1049kB  1050MB  1049MB  ntfs                                       hidden, diag
 2      1050MB  1322MB  273MB   fat32        EFI system partition          boot, esp
 3      1322MB  1456MB  134MB                Microsoft reserved partition  msftres
 4      1456MB  216GB   214GB   ntfs         Basic data partition          msftdata
 5      216GB   216GB   505MB   ntfs                                       hidden, diag
 6      216GB   989GB   772GB   ntfs         Basic data partition          msftdata
 7      989GB   1000GB  11.5GB  ntfs                                       hidden, diag


Model: ATA TS32GMTS400-ACC (scsi)
Disk /dev/sdb: 32.0GB
Sector size (logical/physical): 512B/512B
Partition Table: gpt
Disk Flags:

Number  Start   End     Size    File system  Name                  Flags
 1      1049kB  201MB   200MB   fat16        EFI System Partition  boot, esp
 2      201MB   32.0GB  31.8GB  ext4


Model: Unknown (unknown)
Disk /dev/zram0: 8146MB
Sector size (logical/physical): 4096B/4096B
Partition Table: loop
Disk Flags:

Number  Start  End     Size    File system     Flags
 1      0.00B  8146MB  8146MB  linux-swap(v1)


# W22.7 0606 15:50:25 63%100% jobs:0 aaron@x230:~/y/





Model: SanDisk Ultra Fit (scsi)
Disk /dev/sdc: 15.4GB
Sector size (logical/physical): 512B/512B
Partition Table: msdos
Disk Flags:

Number  Start   End     Size    Type     File system  Flags
 1      16.4kB  15.4GB  15.4GB  primary  fat32        lba


EXT4 请求写的时候，需要发指令给闪存存储器，由闪存内部的控制器找到需要改写
的块，读取其中的内容，完成修改后写到另外一个块中，并重新完成逻辑块和物理
块的映射

而 F2FS，是在文件系统内直接完成的，减轻了存储器内部处理的负担

同时，F2FS 因为使用 NAT 地址转换表，避免了因为一个文件内容更新带
来的大规模传播更新效应，在这块效率也更高一些。

手机使用大部分是随机 io，占比 70-80%
由于操作系统内部有 page cache，常用文件都缓存了

c 库缓冲-----fflush---------〉内核缓冲--------fsync-----〉磁盘硬件有 ufs

其实只要不是缓存太小，写性能太差（手机长期使用后，存储空间不足后），一般性使用很难感受的出来多大的差别。或者说如果你是 ufs，感受不出来多大差异。

rootfs 位于 NAND，而 NAND Flash 使用了 UBIFS 文件系统，只要我们在 kernel 中加入
NAND 驱动、UBIFS 相关驱动，启动时通过 bootargs 向 kernel 传递正确的 rootfs 位置
和驱动信息，kernel 自身就可以顺利找到 rootfs 并挂载正确，从而继续下面的 init
工作。

无 initrd（initramfs）。拆不拆/boot 都
一样，没区别，都可以不加 initramfs。除非有人非要搞 plymouth 启动动画这种美
化的东西才会去生成一个 initramfs。为了正常启动只要把硬盘驱动（不用怀疑，
硬盘也有驱动……）、LVM（如果你用的话）、文件系统编译进去就行了，（根据各
版本内核默认配置不同，）可能会偶尔因为别的必须的东西没编译而导致内核恐慌
。当然很多人卡壳在第一步……笼统的来说，不生成 initramfs 的情况下，启动顺序
为：1、grub 引导 vmlinuz，vmlinuz 有 root 参数，例如 root=/dev/sda7，或者
root=UUID2、vmlinuz 读取/etc 中的 modules 文件，决定载入哪个模块（这里一般放
置网络模块等，例如 vbox 虚拟机驱动 vboxdrv，我的网卡 brcmsmac，b43 等），模块
大概是放在/lib/modules*。此时要求 vmlinuz 编译了可以读取 / 的文件系统。3、
启动。顺便说一下，gentoo 上的 mkinitrd 系列工具是被标记为推荐不安装的。

# Interface

## UFS VS NVMe

UFS（Universal Flash Storage）目标是取代 eMMC。在 2008 年，JEDEC 就开始为并行的 eMMC 寻找串行方案。到了 2012 年，UFS 1.0 诞生了。

UFS 相较 eMMC 最大的不同是并行信号改为了更加先进的串行信号，从而可以迅速提高频率，同时半双工改为全双工。

NVMe（NVM Express）目标是替换掉 SATA 接口。早在 2009 年 Intel 就开始着手寻找 SATA 的替代方案，在 2011 年有了 1.0。

NVMe 实际上是一种通讯协议，在通讯协议里是应用层，它使用 PCIe 协议作为数据和链路层。

之前 SSD 用 SATA 串行接口，接口采用 AHCI 规范，其已经成为制约 SSD 速度的瓶颈。

AHCI 只有 1 个命令队列，队列深度 32；
而 NVMe 可以有 65535 个队列，每个队列都可以深达 65536 个命令。

NVMe 也充分使用了 MSI 的 2048 个中断向量优势，延迟大大减小。

- 带宽

UFS 采用两条 lane，2.1 的最大带宽为 11.6Gbps，约为 1200MB/s,

NVMe 链路层采用 PCIe，PCIe 3.0 一般采用 4 条 lane，带宽是 4000MB/s，

2 个 lane，是 2000MB/s。

UFS 3.0 速度加倍，

PCIe 4.0 * 4 lane 带宽将达到 8000MB/s，两个 lane 也有 4000MB/s。

UFS 采用 UCS 命令集，它是 SCSI 命令的一个子集。

NVMe 采用为 NAND flash 量身定制的精简 ATA 命令集，大大减少命令的复杂度，命令队列数目和深度又保证了 4K 小文件的迅速读写。

两者相比 UFS 命令集和理论处理能力上又大大落于下风。


    $ fg3console
    2014-12-29 16:58:04 - Trying to download /fg3_bj_linux/install/travel_update_package.zip
    2014-12-29 16:58:04 - Downloading file: /fg3_bj_linux/install/travel_update_package.zip contentType: application/octet-stream size: 40668649
    2014-12-29 16:58:07 - Validation downloaded package...
    2014-12-29 16:58:07 - Creating local site from downloaded package...
    2014-12-29 16:58:07 - Unzipping local update package...
    2014-12-29 16:58:08 - Updating /home/CORPUSERS/28850410/.fg3.d/sites/2014_12_29_16_58_03/sites.xml
    2014-12-29 16:58:08 - Updating /home/CORPUSERS/28850410/.fg3.d/sites/2014_12_29_16_58_03/travel_default_settings.xml
    2014-12-29 16:58:08 - Loading local site...
    2014-12-29 16:58:09 - Local site loaded, and it is valid
    2014-12-29 16:58:12 - Keep user data = false
    2014-12-29 16:58:12 - Keep B2B data = false
    2014-12-29 16:58:12 - No flash items have been specified. Please use -f, -d, -upb, -upbc, -uhwc, -rlock, -glock, -teekey, or -rta switches


    $ fg3console -sd 4 -kud -kb2b -f APP-SW_ARIES_GENERIC_USER_23.1.A.0.322_1285-6521_S1-SW-TEST-B316-0001-MMC.zip -f FSP_ARIES_GENERIC-GGL_GLOBAL-LTE_USER_23.1.A.0.322_1286-9917_R4C_S1-SW-TEST-B316-0001-MMC.zip
    2014-12-29 19:55:17 - Loading local site...
    2014-12-29 19:55:17 - Local site loaded, and it is valid
    2014-12-29 19:55:20 - Keep user data = true
    2014-12-29 19:55:20 - Keep B2B data = true
    2014-12-29 19:55:20 - Please connect your phone to ANY USB port
    2014-12-29 19:55:39 - Phone detected on::775
    2014-12-29 19:55:39 - Waiting for a phone on port: 775. Timeout: (30,000) milliseconds
    2014-12-29 19:55:39 - Communication channel open on port: [775]
    2014-12-29 19:55:39 - Detected chipset: S1_MSM8974AB
    2014-12-29 19:55:39 - Detected PHONE: Aries
    2014-12-29 19:55:39 - Detected PROFILE: Aries BROWN - BROWN CID1
    2014-12-29 19:55:39 - Starting flash flow
    2014-12-29 19:55:39 - Using configuration: MemoryGroup
    2014-12-29 19:55:39 - Using profile: [Aries BROWN - BROWN CID1] on port: [775]
    2014-12-29 19:55:39 - Boot mode: SBOOT
    2014-12-29 19:55:39 - Downloading S1_LOADER_EROM --> /home/CORPUSERS/28850410/.fg3.d/sites/2014_12_29_16_58_03/Loaders_Brown/Loaders_Test/S1_MSM8974AB/026/s1_loader_MSM8974AB_26_AID_4_S1-LOADER-LIVE-9C84-0004-LOADER.sin
    2014-12-29 19:55:41 - Downloaded S1_LOADER_EROM --> TYPE="S1_LOADER";ID="1277-2052";VER="MSM8974AB_26";PROT_VER="04"
    2014-12-29 19:55:41 - Extracting archive entries from file APP-SW_ARIES_GENERIC_USER_23.1.A.0.322_1285-6521_S1-SW-TEST-B316-0001-MMC.zip
    2014-12-29 19:55:41 - Extracted archive entries from file APP-SW_ARIES_GENERIC_USER_23.1.A.0.322_1285-6521_S1-SW-TEST-B316-0001-MMC.zip
    2014-12-29 19:55:41 - User data has been preserved
    2014-12-29 19:55:41 - Extracting archive entries from file FSP_ARIES_GENERIC-GGL_GLOBAL-LTE_USER_23.1.A.0.322_1286-9917_R4C_S1-SW-TEST-B316-0001-MMC.zip
    2014-12-29 19:55:41 - Extracted archive entries from file FSP_ARIES_GENERIC-GGL_GLOBAL-LTE_USER_23.1.A.0.322_1286-9917_R4C_S1-SW-TEST-B316-0001-MMC.zip
    2014-12-29 19:55:41 - User data has been preserved
    2014-12-29 19:55:41 - Unpacking file: /home/CORPUSERS/28850410/APP-SW_ARIES_GENERIC_USER_23.1.A.0.322_1285-6521_S1-SW-TEST-B316-0001-MMC.zip...
    | 100%
    2014-12-29 19:55:41 - File unzipped: /home/CORPUSERS/28850410/APP-SW_ARIES_GENERIC_USER_23.1.A.0.322_1285-6521_S1-SW-TEST-B316-0001-MMC.zip
    2014-12-29 19:55:41 - Flashing file: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1421127672524/partition-image_S1-SW-TEST-B316-0001-MBR.sin
    2014-12-29 19:55:41 - Flashing file: partition-image_S1-SW-TEST-B316-0001-MBR.sin ...
    2014-12-29 19:55:41 - File flashed successfully: partition-image_S1-SW-TEST-B316-0001-MBR.sin
    2014-12-29 19:55:41 - Unpacking file [/home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1421127672524/boot.zip]->[/home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416]
    | 100%
    2014-12-29 19:55:41 - File unpacked successfully [/home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1421127672524/boot.zip]->[/home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416]
    2014-12-29 19:55:42 - Loading file into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/dbi_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID12-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - File loaded into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/dbi_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID12-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - Flashing file: dbi_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID12-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:55:42 - File flashed successfully: dbi_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID12-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - Loading file into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/emmc_appsboot_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID09-OEM0-AID1-DEBUG00-S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - File loaded into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/emmc_appsboot_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID09-OEM0-AID1-DEBUG00-S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - Flashing file: emmc_appsboot_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID09-OEM0-AID1-DEBUG00-S1-BOOT-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:55:42 - File flashed successfully: emmc_appsboot_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID09-OEM0-AID1-DEBUG00-S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - Loading file into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/rpm_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID0A-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - File loaded into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/rpm_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID0A-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - Flashing file: rpm_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID0A-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:55:42 - File flashed successfully: rpm_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID0A-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - Loading file into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/s1sbl_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID65-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - File loaded into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/s1sbl_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID65-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - Flashing file: s1sbl_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID65-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:55:42 - File flashed successfully: s1sbl_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID65-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - Loading file into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/sbl1_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID00-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - File loaded into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/sbl1_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID00-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:42 - Flashing file: sbl1_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID00-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:55:43 - File flashed successfully: sbl1_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID00-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:43 - Loading file into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/tz_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID07-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:43 - File loaded into memory: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1492594416/tz_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID07-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:43 - Flashing file: tz_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID07-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:55:43 - File flashed successfully: tz_S1_Boot_MSM8974AC_11_AID_1_L_MSM8974AC-TEST-HWID007B40E1-SWID07-OEM0-AID1-DEBUG00_S1-BOOT-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:43 - Boot delivered in the software file has been written to the phone
    2014-12-29 19:55:43 - Downloading TA file: fota-reset.ta to partition 2 ...
    2014-12-29 19:55:44 - TA file: fota-reset.ta has been flashed to the phone. Partition 2
    2014-12-29 19:55:44 - Downloading TA file: Aries_S1BootConfig_MiscTA.ta to partition 2 ...
    2014-12-29 19:55:44 - TA file: Aries_S1BootConfig_MiscTA.ta has been flashed to the phone. Partition 2
    2014-12-29 19:55:44 - Flashing file: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1421127672524/cache_S1-SW-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:44 - Flashing file: cache_S1-SW-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:55:44 - File flashed successfully: cache_S1-SW-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:44 - Flashing file: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1421127672524/kernel_S1-SW-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:44 - Flashing file: kernel_S1-SW-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:55:45 - File flashed successfully: kernel_S1-SW-TEST-B316-0001-MMC.sin
    / 1%2014-12-29 19:55:45 - Flashing file: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1421127672524/fotakernel_S1-SW-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:45 - Flashing file: fotakernel_S1-SW-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:55:45 - Unpacking file: /home/CORPUSERS/28850410/FSP_ARIES_GENERIC-GGL_GLOBAL-LTE_USER_23.1.A.0.322_1286-9917_R4C_S1-SW-TEST-B316-0001-MMC.zip...
    - 6%2014-12-29 19:55:46 - File flashed successfully: fotakernel_S1-SW-TEST-B316-0001-MMC.sin
    - 2%2014-12-29 19:55:46 - Flashing file: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1421127672524/ramdump_S1-SW-TEST-B316-0001-MMC.sin
    2014-12-29 19:55:46 - Flashing file: ramdump_S1-SW-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:55:46 - File flashed successfully: ramdump_S1-SW-TEST-B316-0001-MMC.sin
    | 100%
    2014-12-29 19:56:17 - File unzipped: /home/CORPUSERS/28850410/FSP_ARIES_GENERIC-GGL_GLOBAL-LTE_USER_23.1.A.0.322_1286-9917_R4C_S1-SW-TEST-B316-0001-MMC.zip
    / 1%2014-12-29 19:56:17 - Flashing file: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1422282255692/amss_fs_1_S1-MODEMSW-TEST-B316-0001-MMC.sin
    2014-12-29 19:56:17 - Flashing file: amss_fs_1_S1-MODEMSW-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:56:17 - File flashed successfully: amss_fs_1_S1-MODEMSW-TEST-B316-0001-MMC.sin
    / 1%2014-12-29 19:56:17 - Flashing file: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1422282255692/amss_fs_2_S1-MODEMSW-TEST-B316-0001-MMC.sin
    2014-12-29 19:56:17 - Flashing file: amss_fs_2_S1-MODEMSW-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:56:17 - File flashed successfully: amss_fs_2_S1-MODEMSW-TEST-B316-0001-MMC.sin
    / 1%2014-12-29 19:56:17 - Flashing file: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1422282255692/amss_fsg_S1-MODEMSW-TEST-B316-0001-MMC.sin
    2014-12-29 19:56:17 - Flashing file: amss_fsg_S1-MODEMSW-TEST-B316-0001-MMC.sin ...
    2014-12-29 19:56:17 - File flashed successfully: amss_fsg_S1-MODEMSW-TEST-B316-0001-MMC.sin
    / 1%2014-12-29 19:56:17 - Flashing file: /home/CORPUSERS/28850410/.fg3.d/tmp/sessions/1419854116361/unpack/1422282255692/system_S1-SW-TEST-B316-0001-MMC.sin
    2014-12-29 19:56:17 - Flashing file: system_S1-SW-TEST-B316-0001-MMC.sin ...
    | 100%
    | 100%
    | 100%
    | 100%
    2014-12-29 19:57:28 - File flashed successfully: system_S1-SW-TEST-B316-0001-MMC.sin
    | 100%
    2014-12-29 19:57:29 - Communication channel has been closed on port:[775]
    2014-12-29 19:57:29 - SUCCESS: Your phone has been flashed
    2014-12-29 19:57:30 - FG3 - CONSOLE ENDED


