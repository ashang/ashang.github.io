---
title: "Flash 软硬兼施"
---

# FS

Raw NAND只能支持Flash文件系统如，jffs，yaffs，ubifs。不支持ext等以磁盘为基础的文件系统。

NAND基础上有控制器的，如U盘，mmc，emmc, ufs, ssd等则可以使用 ext

Yaffs2以及UBIFS都是基于linux的MTD层而实现的。

MTD层就是
linux对于NAND flash driver封装的一个抽象层。

随着EMMC的发展，厂商将 FTL的实现集成在EMMC内部。

这样EMMC就成为一个以NAND flash为介质的块设备。

EXT3/4都是为了传统块设备而设计的文件系统。并不能发挥出EMMC 的特性。

F2FS基于块设备接口而设计，充分考虑到了NAND flash类介质的特性。

F2FS设计时考虑了Flash储存的特性，比如说让写入的数据尽可能的写满一个数据
块，比如说基于日志结构可以copy-on-write，避免改写，比如说区别冷热数据…

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




EXT4请求写的时候，需要发指令给闪存存储器，由闪存内部的控制器找到需要改写
的块，读取其中的内容，完成修改后写到另外一个块中，并重新完成逻辑块和物理
块的映射而F2FS，是在文件系统内直接完成的，减轻了存储器内部处理的负担，相
对更友好。同时，F2FS因为使用NAT地址转换表，避免了因为一个文件内容更新带
来的大规模传播更新效应，在这块效率也更高一些。所以，F2FS确实有效果。华为
内部测试也确实证明了这一点。手机使用大部分是随机io，占比70-80%由于操作系
统内部有page cache，常用文件都缓存了c库缓冲-----fflush---------〉内核缓
冲--------fsync-----〉磁盘硬件有ufs，其实只要不是缓存太小，写性能太差(手
机长期使用后，存储空间不足后)，一般性使用很难感受的出来多大的差别。或者
说如果你是ufs，感受不出来多大差异。硬件不行，靠软件发掘潜在的性能，就是
这个道理。


据说不稳定，数据容易出错


rootfs位于NAND，而NAND Flash使用了UBIFS文件系统，只要我们在kernel中加入
NAND驱动、UBIFS相关驱动，启动时通过bootargs向kernel传递正确的rootfs位置
和驱动信息，kernel自身就可以顺利找到rootfs并挂载正确，从而继续下面的init
工作。



我们的 Gentoo 全是一个3-6M大的内核，无initrd（initramfs）。拆不拆/boot都
一样，没区别，都可以不加initramfs。除非有人非要搞plymouth启动动画这种美
化的东西才会去生成一个initramfs。为了正常启动只要把硬盘驱动（不用怀疑，
硬盘也有驱动……）、LVM（如果你用的话）、文件系统编译进去就行了，（根据各
版本内核默认配置不同，）可能会偶尔因为别的必须的东西没编译而导致内核恐慌
。当然很多人卡壳在第一步……笼统的来说，不生成initramfs的情况下，启动顺序
为：1、grub引导vmlinuz，vmlinuz有root参数，例如root=/dev/sda7，或者
root=UUID2、vmlinuz读取/etc中的modules文件，决定载入哪个模块（这里一般放
置网络模块等，例如vbox虚拟机驱动vboxdrv，我的网卡brcmsmac，b43等），模块
大概是放在/lib/modules*。此时要求vmlinuz编译了可以读取 / 的文件系统。3、
启动。顺便说一下，gentoo上的mkinitrd系列工具是被标记为推荐不安装的。






# Interface

UFS VS NVMe

最近某手机厂商的闪存门在知乎上被人踢爆，在所谓“爵士水军”和“友商水军”的口水大战中，至少eMMC, UFS等火星名词被广泛的科普了一把。苹果粉也不时掺和进来，NVMe在苹果手机上的应用让这个群体平添了一份“高冷”，安卓的小伙伴们被鄙视的都不敢回嘴了！

本着看热闹不怕事大的原则，我这个低端山寨手机拥趸决定以一个吸引眼球的故事开始本系列：到底UFS 2.1和NVMe谁性能好，谁能“代表社会先进生产力”呢？

UFS VS NVMe

UFS是为了替代eMMC而生，主要面向手机等嵌入式场景。NVMe是目标是取代SATA SSD硬盘接口，主要应用在计算机平台。两者似乎没有必要也没有机会正面PK，但是苹果就是这么任性，偏偏要在手机上使用NVMe。这就像一场荒（YOU）诞（QU）的穿越剧，关公（NVMe）和秦琼（UFS）被强行穿越到我们眼前PK，而且被要求fight to death!作为资深吃瓜群众，在他们开打之前，我先来介绍下两位选手的个人情况。




秦琼：UFS

UFS（Universal Flash Storage）目标是取代eMMC。在2008年，JEDEC就开始为并行的eMMC寻找串行方案。到了2012年，UFS 1.0诞生了，知道今天已经是2.1版了。UFS相较eMMC最大的不同是并行信号改为了更加先进的串行信号，从而可以迅速提高频率，同时半双工改为全双工。如图：




关公：NVMe

NVMe（NVM Express）目标是替换掉SATA接口。早在2009年Intel就开始着手寻找SATA的替代方案，在2011年有了1.0。最新的版本是1.2.1。NVMe实际上是一种通讯协议，在通讯协议里是应用层，它使用PCIe协议作为数据和链路层。如下：




NVMe是为SSD而生。在此之前SSD都用SATA接口。有人会好奇SATA也是串行接口，为啥还要创造个新的接口。SATA接口采用AHCI规范，其已经成为制约SSD速度的瓶颈。AHCI只有1个命令队列，队列深度32；而NVMe可以有65535个队列，每个队列都可以深达65536个命令。NVMe也充分使用了MSI的2048个中断向量优势，延迟大大减小。

战力分析

介绍完了两位猛将，我们来看看他们的装备。因为他们都基于NAND Flash技术，我们就从他们的区别最明显的部分比起。

1。坐骑

秦琼坐下黄骠马，入选唐朝七骏图。关公胯下赤兔马，人中龙凤，马中赤兔。都是大名顶顶。坐骑是速度的保证，要不关二爷也做不到温酒斩华雄。协议的带宽也是速度的象征，UFS采用两条lane，2.1的最大带宽为11.6Gbps，约为1200MB/s,如下图：




NVMe链路层采用PCIe，目前PCIe是3.0，一般采用4条lane，如果你看过前面我们PCIe的介绍（传送门：深入PCI与PCIe之一：硬件篇 - 知乎专栏），我们就知道带宽是4000MB/s，如下图：




就算2个lane，也是2000MB/s，>1200MB/s。看来黄骠马跑不过赤兔马啊。有人说不公平，UFS 3.0要来了，速度会加倍，如下图：




可是PCIe 4.0也会在今年面世，相信最需要带宽的NVMe会立刻采用，PCIe 4.0 * 4 lane的带宽将达到恐怖的8000MB/s，两个lane也有4000MB/s。完全是碾压式的。

2。武器

秦琼手拿两根四棱金装熟铜锏，关羽手持青龙偃月刀。兵器的好坏也决定PK的强弱。UFS采用UCS命令集，它是SCSI命令的一个子集。NVMe采用为NAND flash量身定制的精简ATA命令集，大大减少命令的复杂度，恐怖的命令队列数目和深度又保证了4K小文件的迅速读写。两者相比UFS命令集和理论处理能力上又大大落于下风。看来还是青龙偃月刀厉害啊。




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


