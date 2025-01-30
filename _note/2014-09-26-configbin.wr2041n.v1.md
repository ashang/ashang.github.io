

https://github.com/siwind/openwrt




详情：https://www.right.com.cn/forum/thread-484835-1-1.html

1) 解锁uboot的OpenWrt固件(从tp-link网页的管理页面升级即可)： 
 openwrt-wr2041n-v1-unlock.bin (注意：只能在原厂升级固件处刷！)

2) 在解锁了u-boot的OpenWrt系统中刷入不死u-boot:
 breed-ar9344-r1163.bin
 
3) 在openwrt中或者breed中升级的带完整功能OpenWrt固件：
  --不带任何其它插件的OpenWrt（可刷4M-原厂flash，但是剩余空间不多156K）
     openwrt-ar71xx-tiny-tl-wr2041n-v1-squashfs-sysupgrade-4.14.bin: 
  
  --集成KMS的Openwrt固件，可以用在8/16M-flash固件中:
     openwrt-ar71xx-tiny-tl-wr2041n-v1-squashfs-sysupgrade-4.14-KMS.bin
	 
4) TP-LINK 原厂固件（在breed中升级固件/Openwrt中刷入firmware即可返回原厂系统）
 tp-link-wr2041nv1.bin
 
 
 

## 

路由的方案，CPU是AR9344 频率560MHz，内存64MB 闪存4MB。AR9344是比较有名的CPU，现在还有些路由在用它。无线方面，用的AR9381，3T3R，每条通道都有独立的PA和LNA，信号在TPlink的产品里算是好的。

无线芯片： AR9381/AR9381-ALIA无线芯片，带双功放。
CPU: AR9344 / AR9344-BC2A
内存： DDR2 64M内存/现代64MB内存H5PS5162GFR-Y5C/H5PS5162GFR Y5C
FLASH: 4MB/FL032PIF

原厂的固件，无线非常不稳定。 而OpenWrt现在对athos芯片的支持非常好，刷入Openwrt是不错的选择。只是FLASH太小， 实在是束手束脚。

如果不改flash, 下面的固件也是合适的，只是不能安装其它功能插件了。


解锁及刷机
1)  在原厂固件的 “升级”处刷入解锁了u-boot的OpenWrt固件 （因为是解锁固件，功能不全）
   openwrt-wr2041n-v1-unlock.bin

   关于如何编译解锁u-boot分区的固件， 在文件：target\linux\ar71xx\files\drivers\mtd\tplinkpart.c中，注释掉相应的mask即可。编译后的xxx-factory.bin就是。



    parts[0].name = "u-boot";
            parts[0].offset = 0;
            parts[0].size = offset;
    /*        parts[0].mask_flags = MTD_WRITEABLE; */       //注释掉这一行

            parts[1].name = "kernel";
            parts[1].offset = offset;
            parts[1].size = rootfs_offset - offset;

            parts[2].name = "rootfs";
            parts[2].offset = rootfs_offset;
            parts[2].size = art_offset - rootfs_offset;

            parts[3].name = "art";
            parts[3].offset = art_offset;
            parts[3].size = TPLINK_ART_LEN;
    /*        parts[3].mask_flags = MTD_WRITEABLE; */             //注释掉这一行

            parts[4].name = "firmware";
            parts[4].offset = offset;
            parts[4].size = art_offset - offset;



2)  升级解锁固件后，重启即可进入OpenWrt系统， 然后备份无线配置的art文件。
可以在OpenWrt的LUCI界面备份无线配置art：System-->Backup/FlashFirmware:
“save mtd content”-->art：


或者：
SSH登录进入路由（192.168.1.1）， 输入如下命令备份：
(SSH登录的用户名root, 密码无)\


    # cd tmp
    # cat /proc/mtd
    # dd if=/dev/mtd4 of=4-art.bin
    # dd if=/dev/mtd5  of=5-firmware.bin
    # tar czvf  2041n-v1-rom.tar.gz   4-art.bin  5-firmware.bin
    # touch /www/a.tar.gz
    # mount --bind  2041n-v1-rom.tar.gz   /www/a.tar.gz





从浏览器地址 http://192.168.1.1/a.tar.gz 下载打包的rom文件，重命名为2041n-v1-rom.tar.gz并保存。


3） 刷入不死u-boot和全功能OpenWrt固件
SSH登录进入路由（192.168.1.1），进入/tmp目录，用wget命令下载breed文件(breed-ar9344-r1163.bin)或者用命令"rz" 上传刷机的文件，
之后刷机：



    # cd /tmp
    # rz       (在弹出的对话框中选择"breed-ar9344-r1163.bin")
    # mtd write    breed-ar9344-r1163.bin       u-boot
    #
    # rz       (在弹出的对话框中选择OpenWrt固件, 例如："openwrt-ar71xx-tiny-tl-wr2041n-v1-squashfs-sysupgrade-4M-v18.06.2.bin")
    # mtd write    openwrt-ar71xx-tiny-tl-wr2041n-v1-squashfs-sysupgrade-4M-v18.06.2.bin   firmware
    # reboot     (刷完重启)



 刷入Openwrt固件，可以在解锁后的Openwrt的web界面，“系统” -->"备份升级"，“刷写固件”处刷入Openwrt固件(xxx-sysupgrade-xxx.bin)。


或者(其它方法也行)：
可以用HFS软件搭建。（http://www.rejetto.com/hfs/?f=dl）

    # cd /tmp
    # wget  http://192.168.1.xx/breed-ar9344-r1163.bin
    # mtd write breed-ar9344-r1163.bin  u-boot




刷入Openwrt固件： openwrt-ar71xx-tiny-tl-wr2041n-v1-squashfs-sysupgrade-4.14.bin

    # cd /tmp
    # wget http://192.168.1.xx/openwrt-ar71xx-tiny-tl-wr2041n-v1-squashfs-sysupgrade-4.14.bin

    # mtd write  openwrt-ar71xx-tiny-tl-wr2041n-v1-squashfs-sysupgrade-4.14.bin   firmware




4) 进breed
  刷写好以后， 开机按reset部分，待红灯闪烁， 即可进入breed。
  我们在breed里面，需要设置TP-LINK的参数， 分别为PIN和MAC地址。翻开路由器背面看看，然后填写到breed中。

   之后，在这里可以备份art文件，或者刷入OpenWrt固件或者原厂固件。


5） 重启/开机，即可。
如果想回到原厂固件，那么进入breed， 刷入原厂固件即可。

或者：
在OpenWrt环境下刷原厂固件更简单：
1)  OpenWrt网页  -->  System  -->  Backup/Flash Firmware --> Flash new firmware image,  
    选择TP-LINK的官方固件 “tp-link-wr2041nv1.bin”，升级后就是TP-LINK 原厂系统。
2)  SSH登录如路由，用mtd命令刷机：

    # cd  /tmp
    # rz       (输入TP-LINK官方固件 :  tp-link-wr2041nv1.bin)

    # mtd write  tp-link-wr2041nv1.bin   firmware
    # reboot


4. 结论
1) 备份原机的无线配置文件art！！
2) 路由的无线还是不错的，默认情况下发射功率26dbm， 秒杀很多矿渣的无线功能(很多20dbm都调不到)
3) 经测试， 两个lan有线口对拷，速度稳定在11M上下， 而LAN--WLAN对拷，速度在10M-11M左右波动，完全可以跑满此百兆路由。
4) 此OpenWrt固件集成KMS/upnp， 以及IPv6等。
    i) 带4M字样的固件，支持upnp和IPv6, 英文界面   
   ii) 不带4M字样的固件，需要硬改flash为8M/16M,  集成KMS/MWAN3/UPNP/IPv6等。





固件功能说明：



1) openwrt-tl-wr2041n-xx-sysupgrade-4M-v18.xxx.bin
   适用于原机4M-flash存储的固件。包含基本功能(ssh,logd,opkg等)和upnp,WEB界面。

2) openwrt-tl-wr2041n-xx-sysupgrade-lite-4M-v18.xxx.bin
   适用于原机4M-flash存储的固件，精简掉logd, opkg功能，同时加入 upnp,KMS服务器(vlmcsd), WOL。

3) openwrt-tl-wr2041n-xx-sysupgrade-8M-v18.xxx.bin
   适用于硬改flash容量为8M及以上(含16M)的情况。
   功能包含： dnsmasq-full, IPv6-NAT, upnp, 负载均衡, KMS服务器, WOL网络唤醒等。



补充内容 (2020-3-25 18:30):
已经添加Openwrt-trojan.ipk。

 带KMS功能用于激活Windows/office全家桶功能不错，之前送了几个亲戚家用~~

4M-flash因为空间没有了，不能保存任何配置。
4M-FLASH就只能OpenWrt的基本系统，或者精简某些基本功能后，带其它插件。



带...4M-xx.bin的，是可以不用硬改flash, 直接在原厂的4M大小flash上面直接刷的。 不带...4M...bin的，是需要硬改flash为8M或者18M才能刷的。 另外就是OpenWrt版本版本不一样，刷哪个都行。其中v18.06.2的，是Openwrt的稳定版。

4M-xx的固件有ipv6方面的功能





#3333////	a						

wr2041n路由，拆开看过芯片方案，是ar9344+ar9381，没有交换芯片，ar9344内置了交换，与wr941n v6的方案一致，与国外wrd3500方案相似
今天去openwrt的官网下载目录找到wr941n v6的trunk版固件，下载下来，改固件头验证，刷进wr2041之，成功刷入，4个LAN口与WAN口，及WIFI都能工作正常。
但450Mbps的速率无法工作，只能最大300Mbps，以及固件刷完之后依然显示TP-LINK TL-WDR3500， LAN口灯的顺序乱了，WAN及WIFI灯正常。
在此请问可有高手能帮忙修正，令OpenWRT能早日真正支持此款型号。


附上已改好固件头，能直接在wr2041n官方固件下用web界面刷的openwrt trunk，需要自己安装LUCI界面，默认ip 192.168.1.1
http://pan.baidu.com/share/link? ... 846171&third=15






附上内核及系统log， 望熟悉内核及架构的朋友能帮忙修正，或者去openwrt官网那开个ticket request


    [    0.000000] Linux version 3.10.10 (fnord@tschunk) (gcc version 4.6.4 (OpenWrt/Linaro GCC 4.6-2012.12 r37911) ) #1 Sat Sep 7 03:45:05 UTC 2013
    [    0.000000] MyLoader: sysp=b9edac4d, boardp=18bd4ff2, parts=495b283a
    [    0.000000] bootconsole [early0] enabled
    [    0.000000] CPU revision is: 0001974c (MIPS 74Kc)
    [    0.000000] SoC: Atheros AR9344 rev 2
    [    0.000000] Clocks: CPU:560.000MHz, DDR:450.000MHz, AHB:225.000MHz, Ref:40.000MHz
    [    0.000000] Determined physical RAM map:
    [    0.000000]  memory: 04000000 @ 00000000 (usable)
    [    0.000000] Initrd not found or empty - disabling initrd
    [    0.000000] Zone ranges:
    [    0.000000]   Normal   [mem 0x00000000-0x03ffffff]
    [    0.000000] Movable zone start for each node
    [    0.000000] Early memory node ranges
    [    0.000000]   node   0: [mem 0x00000000-0x03ffffff]
    [    0.000000] On node 0 totalpages: 16384
    [    0.000000] free_area_init_node: node 0, pgdat 80322b60, node_mem_map 81000000
    [    0.000000]   Normal zone: 128 pages used for memmap
    [    0.000000]   Normal zone: 0 pages reserved
    [    0.000000]   Normal zone: 16384 pages, LIFO batch:3
    [    0.000000] Primary instruction cache 64kB, VIPT, 4-way, linesize 32 bytes.
    [    0.000000] Primary data cache 32kB, 4-way, VIPT, cache aliases, linesize 32 bytes
    [    0.000000] pcpu-alloc: s0 r0 d32768 u32768 alloc=1*32768
    [    0.000000] pcpu-alloc: [0] 0
    [    0.000000] Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 16256
    [    0.000000] Kernel command line:  board=TL-WDR3500 console=ttyS0,115200 rootfstype=squashfs,jffs2 noinitrd
    [    0.000000] PID hash table entries: 256 (order: -2, 1024 bytes)
    [    0.000000] Dentry cache hash table entries: 8192 (order: 3, 32768 bytes)
    [    0.000000] Inode-cache hash table entries: 4096 (order: 2, 16384 bytes)
    [    0.000000] Writing ErrCtl register=00000000
    [    0.000000] Readback ErrCtl register=00000000
    [    0.000000] Memory: 61204k/65536k available (2309k kernel code, 4332k reserved, 607k data, 216k init, 0k highmem)
    [    0.000000] SLUB: HWalign=32, Order=0-3, MinObjects=0, CPUs=1, Nodes=1
    [    0.000000] NR_IRQS:51
    [    0.060000] Calibrating delay loop... 278.93 BogoMIPS (lpj=1394688)
    [    0.070000] pid_max: default: 32768 minimum: 301
    [    0.070000] Mount-cache hash table entries: 512
    [    0.080000] NET: Registered protocol family 16
    [    0.080000] MIPS: machine is TP-LINK TL-WDR3500
    [    0.090000] registering PCI controller with io_map_base unset
    [    0.510000] bio: create slab <bio-0> at 0
    [    0.510000] PCI host bridge to bus 0000:00
    [    0.520000] pci_bus 0000:00: root bus resource [mem 0x10000000-0x13ffffff]
    [    0.520000] pci_bus 0000:00: root bus resource [io  0x0000]
    [    0.530000] pci_bus 0000:00: No busn resource found for root bus, will use [bus 00-ff]
    [    0.530000] pci 0000:00:00.0: [168c:0030] type 00 class 0x028000
    [    0.530000] pci 0000:00:00.0: invalid calibration data
    [    0.540000] pci 0000:00:00.0: reg 10: [mem 0x00000000-0x0001ffff 64bit]
    [    0.540000] pci 0000:00:00.0: reg 30: [mem 0x00000000-0x0000ffff pref]
    [    0.540000] pci 0000:00:00.0: supports D1
    [    0.540000] pci 0000:00:00.0: PME# supported from D0 D1 D3hot
    [    0.540000] pci_bus 0000:00: busn_res: [bus 00-ff] end is updated to 00
    [    0.540000] pci 0000:00:00.0: BAR 0: assigned [mem 0x10000000-0x1001ffff 64bit]
    [    0.540000] pci 0000:00:00.0: BAR 6: assigned [mem 0x10020000-0x1002ffff pref]
    [    0.550000] pci 0000:00:00.0: using irq 40 for pin 1
    [    0.550000] Switching to clocksource MIPS
    [    0.560000] NET: Registered protocol family 2
    [    0.560000] TCP established hash table entries: 512 (order: 0, 4096 bytes)
    [    0.560000] TCP bind hash table entries: 512 (order: -1, 2048 bytes)
    [    0.570000] TCP: Hash tables configured (established 512 bind 512)
    [    0.570000] TCP: reno registered
    [    0.570000] UDP hash table entries: 256 (order: 0, 4096 bytes)
    [    0.580000] UDP-Lite hash table entries: 256 (order: 0, 4096 bytes)
    [    0.590000] NET: Registered protocol family 1
    [    0.590000] PCI: CLS 0 bytes, default 32
    [    0.610000] squashfs: version 4.0 (2009/01/31) Phillip Lougher
    [    0.610000] jffs2: version 2.2 (NAND) (SUMMARY) (LZMA) (RTIME) (CMODE_PRIORITY) (c) 2001-2006 Red Hat, Inc.
    [    0.620000] msgmni has been set to 119
    [    0.630000] io scheduler noop registered
    [    0.630000] io scheduler deadline registered (default)
    [    0.640000] Serial: 8250/16550 driver, 16 ports, IRQ sharing enabled
    [    0.670000] serial8250.0: ttyS0 at MMIO 0x18020000 (irq = 11) is a 16550A
    [    0.670000] console [ttyS0] enabled, bootconsole disabled
    [    0.690000] ath79-spi ath79-spi: master is unqueued, this is deprecated
    [    0.700000] m25p80 spi0.0: found s25sl032p, expected m25p80
    [    0.700000] m25p80 spi0.0: s25sl032p (4096 Kbytes)
    [    0.710000] 5 tp-link partitions found on MTD device spi0.0
    [    0.710000] Creating 5 MTD partitions on "spi0.0":
    [    0.720000] 0x000000000000-0x000000020000 : "u-boot"
    [    0.720000] 0x000000020000-0x000000122d40 : "kernel"
    [    0.730000] mtd: partition "kernel" must either start or end on erase block boundary or be smaller than an erase block -- forcing read-only
    [    0.740000] 0x000000122d40-0x0000003f0000 : "rootfs"
    [    0.750000] mtd: partition "rootfs" must either start or end on erase block boundary or be smaller than an erase block -- forcing read-only
    [    0.760000] mtd: partition "rootfs" set to be root filesystem
    [    0.770000] mtd: partition "rootfs_data" created automatically, ofs=0x2e0000, len=0x110000
    [    0.780000] 0x0000002e0000-0x0000003f0000 : "rootfs_data"
    [    0.780000] 0x0000003f0000-0x000000400000 : "art"
    [    0.790000] 0x000000020000-0x0000003f0000 : "firmware"
    [    0.810000] libphy: ag71xx_mdio: probed
    [    0.820000] eth0: Atheros AG71xx at 0xba000000, irq 5, mode:GMII
    [    1.370000] eth0: Found an AR934X built-in switch
    [    2.410000] eth1: Atheros AG71xx at 0xb9000000, irq 4, mode:MII
    [    2.960000] ag71xx ag71xx.0 eth1: connected to PHY at ag71xx-mdio.1:04 [uid=004dd042, driver=Generic PHY]
    [    2.970000] TCP: cubic registered
    [    2.980000] NET: Registered protocol family 17
    [    2.980000] Bridge firewalling registered
    [    2.990000] 8021q: 802.1Q VLAN Support v1.8
    [    3.000000] VFS: Mounted root (squashfs filesystem) readonly on device 31:2.
    [    3.010000] Freeing unused kernel memory: 216K (8033a000 - 80370000)
    [    4.580000] usbcore: registered new interface driver usbfs
    [    4.590000] usbcore: registered new interface driver hub
    [    4.590000] usbcore: registered new device driver usb
    [    4.770000] ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
    [    4.770000] ehci-platform: EHCI generic platform driver
    [    4.780000] ehci-platform ehci-platform: EHCI Host Controller
    [    4.790000] ehci-platform ehci-platform: new USB bus registered, assigned bus number 1
    [    4.800000] ehci-platform ehci-platform: irq 3, io mem 0x1b000000
    [    4.820000] ehci-platform ehci-platform: USB 2.0 started, EHCI 1.00
    [    4.820000] hub 1-0:1.0: USB hub found
    [    4.830000] hub 1-0:1.0: 1 port detected
    [    4.880000] ohci_hcd: USB 1.1 'Open' Host Controller (OHCI) Driver
    [    9.550000] jffs2: notice: (335) jffs2_build_xattr_subsystem: complete building xattr subsystem, 1 of xdatum (0 unchecked, 0 orphan) and 12 of xref (0 dead, 3 orphan) found.
    [   11.210000] Loading modules backported from Linux version master-2013-06-27-0-gdcfa6d5
    [   11.220000] Backport generated by backports.git backports-20130617-4-ge3220f5
    [   11.250000] cfg80211: Calling CRDA to update world regulatory domain
    [   11.250000] cfg80211: World regulatory domain updated:
    [   11.260000] cfg80211:   (start_freq - end_freq @ bandwidth), (max_antenna_gain, max_eirp)
    [   11.270000] cfg80211:   (2402000 KHz - 2472000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   11.270000] cfg80211:   (2457000 KHz - 2482000 KHz @ 20000 KHz), (300 mBi, 2000 mBm)
    [   11.280000] cfg80211:   (2474000 KHz - 2494000 KHz @ 20000 KHz), (300 mBi, 2000 mBm)
    [   11.290000] cfg80211:   (5170000 KHz - 5250000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   11.300000] cfg80211:   (5735000 KHz - 5835000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   11.520000] NET: Registered protocol family 10
    [   11.910000] ath: phy0: Unable to initialize hardware; initialization status: -5
    [   11.920000] ath9k ar934x_wmac: failed to initialize device
    [   11.930000] ath9k: probe of ar934x_wmac failed with error -5
    [   11.930000] PCI: Enabling device 0000:00:00.0 (0000 -> 0002)
    [   11.940000] ath: EEPROM regdomain: 0x0
    [   11.940000] ath: EEPROM indicates default country code should be used
    [   11.940000] ath: doing EEPROM country->regdmn map search
    [   11.940000] ath: country maps to regdmn code: 0x3a
    [   11.940000] ath: Country alpha2 being used: US
    [   11.940000] ath: Regpair used: 0x3a
    [   11.950000] ieee80211 phy1: Selected rate control algorithm 'minstrel_ht'
    [   11.950000] cfg80211: Calling CRDA for country: US
    [   11.960000] ieee80211 phy1: Atheros AR9300 Rev:3 mem=0xb0000000, irq=40
    [   11.970000] cfg80211: Regulatory domain changed to country: US
    [   11.970000] cfg80211:   (start_freq - end_freq @ bandwidth), (max_antenna_gain, max_eirp)
    [   11.980000] cfg80211:   (2402000 KHz - 2472000 KHz @ 40000 KHz), (300 mBi, 2700 mBm)
    [   11.990000] cfg80211:   (5170000 KHz - 5250000 KHz @ 40000 KHz), (300 mBi, 1700 mBm)
    [   12.000000] cfg80211:   (5250000 KHz - 5330000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   12.000000] cfg80211:   (5490000 KHz - 5600000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   12.010000] cfg80211:   (5650000 KHz - 5710000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   12.020000] cfg80211:   (5735000 KHz - 5835000 KHz @ 40000 KHz), (300 mBi, 3000 mBm)
    [   12.080000] PPP generic driver version 2.4.2
    [   12.290000] ip_tables: (C) 2000-2006 Netfilter Core Team
    [   12.330000] xt_time: kernel timezone is -0000
    [   12.460000] NET: Registered protocol family 24
    [   12.470000] nf_conntrack version 0.5.0 (959 buckets, 3836 max)
    [   12.750000] ip6_tables: (C) 2000-2006 Netfilter Core Team
    [   17.290000] IPv6: ADDRCONF(NETDEV_UP): eth0: link is not ready
    [   17.290000] device eth0 entered promiscuous mode
    [   17.300000] IPv6: ADDRCONF(NETDEV_UP): br-lan: link is not ready
    [   17.310000] IPv6: ADDRCONF(NETDEV_UP): eth1: link is not ready
    [   20.030000] eth1: link up (100Mbps/Full duplex)
    [   20.030000] IPv6: ADDRCONF(NETDEV_CHANGE): eth1: link becomes ready
    [   22.910000] IPv6: ADDRCONF(NETDEV_UP): wlan1: link is not ready
    [   22.930000] device wlan1 entered promiscuous mode
    [   22.940000] IPv6: ADDRCONF(NETDEV_UP): wlan1: link is not ready
    [   22.960000] IPv6: ADDRCONF(NETDEV_CHANGE): wlan1: link becomes ready
    [   22.970000] br-lan: port 2(wlan1) entered forwarding state
    [   22.970000] br-lan: port 2(wlan1) entered forwarding state
    [   22.980000] IPv6: ADDRCONF(NETDEV_CHANGE): br-lan: link becomes ready
    [   24.970000] br-lan: port 2(wlan1) entered forwarding state
    [ 3665.020000] eth1: link down
    [ 3665.050000] IPv6: ADDRCONF(NETDEV_UP): eth1: link is not ready
    [ 3666.030000] eth1: link up (100Mbps/Full duplex)
    [ 3666.030000] IPv6: ADDRCONF(NETDEV_CHANGE): eth1: link becomes ready

复制代码

    Thu Jan  1 08:00:10 1970 auth.info kernel: [    0.690000] ath79-spi ath79-spi: master is unqueued, this is deprecated
    Thu Jan  1 08:00:10 1970 auth.err kernel: [    0.700000] m25p80 spi0.0: found s25sl032p, expected m25p80
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    0.700000] m25p80 spi0.0: s25sl032p (4096 Kbytes)
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.710000] 5 tp-link partitions found on MTD device spi0.0
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.710000] Creating 5 MTD partitions on "spi0.0":
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.720000] 0x000000000000-0x000000020000 : "u-boot"
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.720000] 0x000000020000-0x000000122d40 : "kernel"
    Thu Jan  1 08:00:10 1970 auth.err kernel: [    0.730000] mtd: partition "kernel" must either start or end on erase block boundary or be smaller than an erase block -- forcing read-only
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.740000] 0x000000122d40-0x0000003f0000 : "rootfs"
    Thu Jan  1 08:00:10 1970 auth.err kernel: [    0.750000] mtd: partition "rootfs" must either start or end on erase block boundary or be smaller than an erase block -- forcing read-only
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.760000] mtd: partition "rootfs" set to be root filesystem
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    0.770000] mtd: partition "rootfs_data" created automatically, ofs=0x2e0000, len=0x110000
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.780000] 0x0000002e0000-0x0000003f0000 : "rootfs_data"
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.780000] 0x0000003f0000-0x000000400000 : "art"
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.790000] 0x000000020000-0x0000003f0000 : "firmware"
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    0.810000] libphy: ag71xx_mdio: probed
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    0.820000] eth0: Atheros AG71xx at 0xba000000, irq 5, mode:GMII
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    1.370000] eth0: Found an AR934X built-in switch
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    2.410000] eth1: Atheros AG71xx at 0xb9000000, irq 4, mode:MII
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    2.960000] ag71xx ag71xx.0 eth1: connected to PHY at ag71xx-mdio.1:04 [uid=004dd042, driver=Generic PHY]
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    2.970000] TCP: cubic registered
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    2.980000] NET: Registered protocol family 17
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    2.980000] Bridge firewalling registered
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    2.990000] 8021q: 802.1Q VLAN Support v1.8
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    3.000000] VFS: Mounted root (squashfs filesystem) readonly on device 31:2.
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    3.010000] Freeing unused kernel memory: 216K (8033a000 - 80370000)
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.580000] usbcore: registered new interface driver usbfs
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.590000] usbcore: registered new interface driver hub
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.590000] usbcore: registered new device driver usb
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.770000] ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.770000] ehci-platform: EHCI generic platform driver
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.780000] ehci-platform ehci-platform: EHCI Host Controller
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.790000] ehci-platform ehci-platform: new USB bus registered, assigned bus number 1
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.800000] ehci-platform ehci-platform: irq 3, io mem 0x1b000000
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.820000] ehci-platform ehci-platform: USB 2.0 started, EHCI 1.00
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.820000] hub 1-0:1.0: USB hub found
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.830000] hub 1-0:1.0: 1 port detected
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.880000] ohci_hcd: USB 1.1 'Open' Host Controller (OHCI) Driver
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    9.550000] jffs2: notice: (335) jffs2_build_xattr_subsystem: complete building xattr subsystem, 1 of xdatum (0 unchecked, 0 orphan) and 12 of xref (0 dead, 3 orphan) found.
    Sat Sep  7 19:49:00 2013 daemon.info sysinit: Sat Sep  7 11:49:00 UTC 2013
    Sat Sep  7 19:49:00 2013 authpriv.alert syslog: kmodloader: loading kernel modules from /etc/modules.d/**
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.210000] Loading modules backported from Linux version master-2013-06-27-0-gdcfa6d5
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.220000] Backport generated by backports.git backports-20130617-4-ge3220f5
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.250000] cfg80211: Calling CRDA to update world regulatory domain
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.250000] cfg80211: World regulatory domain updated:
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.260000] cfg80211:   (start_freq - end_freq @ bandwidth), (max_antenna_gain, max_eirp)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.270000] cfg80211:   (2402000 KHz - 2472000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.270000] cfg80211:   (2457000 KHz - 2482000 KHz @ 20000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.280000] cfg80211:   (2474000 KHz - 2494000 KHz @ 20000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.290000] cfg80211:   (5170000 KHz - 5250000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.300000] cfg80211:   (5735000 KHz - 5835000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.520000] NET: Registered protocol family 10
    Sat Sep  7 19:49:01 2013 auth.emerg kernel: [   11.910000] ath: phy0: Unable to initialize hardware; initialization status: -5
    Sat Sep  7 19:49:01 2013 auth.emerg kernel: [   11.920000] ath9k ar934x_wmac: failed to initialize device
    Sat Sep  7 19:49:01 2013 auth.err kernel: [   11.930000] ath9k: probe of ar934x_wmac failed with error -5
    Sat Sep  7 19:49:01 2013 auth.err kernel: [   11.930000] PCI: Enabling device 0000:00:00.0 (0000 -> 0002)
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: EEPROM regdomain: 0x0
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: EEPROM indicates default country code should be used
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: doing EEPROM country->regdmn map search
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: country maps to regdmn code: 0x3a
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: Country alpha2 being used: US
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: Regpair used: 0x3a
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.950000] ieee80211 phy1: Selected rate control algorithm 'minstrel_ht'
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.950000] cfg80211: Calling CRDA for country: US
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.960000] ieee80211 phy1: Atheros AR9300 Rev:3 mem=0xb0000000, irq=40
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.970000] cfg80211: Regulatory domain changed to country: US
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.970000] cfg80211:   (start_freq - end_freq @ bandwidth), (max_antenna_gain, max_eirp)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.980000] cfg80211:   (2402000 KHz - 2472000 KHz @ 40000 KHz), (300 mBi, 2700 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.990000] cfg80211:   (5170000 KHz - 5250000 KHz @ 40000 KHz), (300 mBi, 1700 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.000000] cfg80211:   (5250000 KHz - 5330000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.000000] cfg80211:   (5490000 KHz - 5600000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.010000] cfg80211:   (5650000 KHz - 5710000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.020000] cfg80211:   (5735000 KHz - 5835000 KHz @ 40000 KHz), (300 mBi, 3000 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.080000] PPP generic driver version 2.4.2
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.290000] ip_tables: (C) 2000-2006 Netfilter Core Team
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.330000] xt_time: kernel timezone is -0000
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.460000] NET: Registered protocol family 24
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.470000] nf_conntrack version 0.5.0 (959 buckets, 3836 max)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.750000] ip6_tables: (C) 2000-2006 Netfilter Core Team
    Sat Sep  7 19:49:06 2013 auth.info kernel: [   17.290000] IPv6: ADDRCONF(NETDEV_UP): eth0: link is not ready
    Sat Sep  7 19:49:06 2013 auth.info kernel: [   17.290000] device eth0 entered promiscuous mode
    Sat Sep  7 19:49:06 2013 auth.info kernel: [   17.300000] IPv6: ADDRCONF(NETDEV_UP): br-lan: link is not ready
    Sat Sep  7 19:49:06 2013 daemon.error netifd: Interface 'lan' is now up
    Sat Sep  7 19:49:06 2013 daemon.error netifd: Interface 'loopback' is now up
    Sat Sep  7 19:49:06 2013 auth.info kernel: [   17.310000] IPv6: ADDRCONF(NETDEV_UP): eth1: link is not ready
    Sat Sep  7 19:49:06 2013 daemon.error netifd: wan (731): udhcpc (v1.19.4) started
    Sat Sep  7 19:49:06 2013 authpriv.error firewall: Reloading firewall due to ifup of lan (br-lan)
    Sat Sep  7 19:49:06 2013 daemon.error netifd: wan (731): Sending discover...
    Sat Sep  7 19:49:07 2013 daemon.err 6relayd[753]: Failed to relay to ff02::1%br-lan (Cannot assign requested address)
    Sat Sep  7 19:49:08 2013 daemon.err 6relayd[753]: Failed to relay to ff02::1%br-lan (Cannot assign requested address)
    Sat Sep  7 19:49:09 2013 auth.info kernel: [   20.030000] eth1: link up (100Mbps/Full duplex)
    Sat Sep  7 19:49:09 2013 auth.info kernel: [   20.030000] IPv6: ADDRCONF(NETDEV_CHANGE): eth1: link becomes ready
    Sat Sep  7 19:49:09 2013 daemon.error netifd: wan (731): Sending discover...
    Sat Sep  7 19:49:09 2013 daemon.error netifd: wan (731): Sending select for 192.168.11.179...
    Sat Sep  7 19:49:09 2013 daemon.error netifd: wan (731): Lease of 192.168.11.179 obtained, lease time 86400
    Sat Sep  7 19:49:09 2013 daemon.error netifd: Interface 'wan' is now up
    Sat Sep  7 19:49:10 2013 daemon.error odhcp6c[797]: (re)starting transaction on eth1
    Sat Sep  7 19:49:10 2013 daemon.error odhcp6c[797]: Sending SOLICIT (timeout 4294967295s)
    Sat Sep  7 19:49:10 2013 authpriv.error firewall: Reloading firewall due to ifup of wan (eth1)
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.910000] IPv6: ADDRCONF(NETDEV_UP): wlan1: link is not ready
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.930000] device wlan1 entered promiscuous mode
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.940000] IPv6: ADDRCONF(NETDEV_UP): wlan1: link is not ready
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.960000] IPv6: ADDRCONF(NETDEV_CHANGE): wlan1: link becomes ready
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.970000] br-lan: port 2(wlan1) entered forwarding state
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.970000] br-lan: port 2(wlan1) entered forwarding state
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.980000] IPv6: ADDRCONF(NETDEV_CHANGE): br-lan: link becomes ready
    Sat Sep  7 19:49:14 2013 auth.info kernel: [   24.970000] br-lan: port 2(wlan1) entered forwarding state
    Sat Sep  7 19:49:15 2013 security.info dropbear[949]: Not backgrounding
    Sat Sep  7 19:49:17 2013 authpriv.error dnsmasq: DNS rebinding protection is active, will discard upstream RFC1918 responses!
    Sat Sep  7 19:49:17 2013 authpriv.error dnsmasq: Allowing 127.0.0.0/8 responses
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: started, version 2.66 cachesize 150
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: compile time options: IPv6 GNU-getopt no-DBus no-i18n no-IDN DHCP no-DHCPv6 no-Lua TFTP no-conntrack no-ipset no-auth
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq-dhcp[1007]: DHCP, IP range 192.168.1.100 -- 192.168.1.249, lease time 12h
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: using local addresses only for domain lan
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: reading /tmp/resolv.conf.auto
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: using nameserver 192.168.11.1#53
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: using nameserver 221.179.38.7#53
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: using nameserver 211.136.192.6#53
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: using local addresses only for domain lan
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: read /etc/hosts - 1 addresses
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq-dhcp[1007]: read /etc/ethers - 0 addresses
    Sat Sep  7 19:49:20 2013 daemon.info sysinit: setting up led USB
    Sat Sep  7 19:49:20 2013 daemon.info sysinit: setting up led WLAN2G
    Sat Sep  7 19:49:20 2013 daemon.info sysinit: sh: write error: Invalid argument
    Sat Sep  7 19:49:21 2013 daemon.info sysinit: - init complete -
    Sat Sep  7 20:49:38 2013 daemon.info hostapd: wlan1: STA 2c:b0:5d:65:a1:af IEEE 802.11: authenticated
    Sat Sep  7 20:49:38 2013 daemon.info hostapd: wlan1: STA 2c:b0:5d:65:a1:af IEEE 802.11: associated (aid 1)
    Sat Sep  7 20:49:39 2013 daemon.info dnsmasq-dhcp[1007]: DHCPREQUEST(br-lan) 192.168.1.233 2c:b0:5d:65:a1:af
    Sat Sep  7 20:49:39 2013 daemon.info dnsmasq-dhcp[1007]: DHCPACK(br-lan) 192.168.1.233 2c:b0:5d:65:a1:af Kelly-PC
    Sat Sep  7 20:49:41 2013 daemon.info dnsmasq[1007]: read /etc/hosts - 1 addresses
    Sat Sep  7 20:49:41 2013 daemon.info dnsmasq[1007]: read /tmp/hosts/6relayd - 1 addresses
    Sat Sep  7 20:49:41 2013 daemon.info dnsmasq-dhcp[1007]: read /etc/ethers - 0 addresses
    Sat Sep  7 20:49:42 2013 daemon.info dnsmasq-dhcp[1007]: DHCPINFORM(br-lan) 192.168.1.233 2c:b0:5d:65:a1:af
    Sat Sep  7 20:49:42 2013 daemon.info dnsmasq-dhcp[1007]: DHCPACK(br-lan) 192.168.1.233 2c:b0:5d:65:a1:af Kelly-PC
    Sat Sep  7 20:49:43 2013 security.info dropbear[1031]: Child connection from 192.168.1.233:52151
    Sat Sep  7 20:49:45 2013 security.err dropbear[1031]: Bad password attempt for 'root' from 192.168.1.233:52151
    Sat Sep  7 20:49:49 2013 security.error dropbear[1031]: Password auth succeeded for 'root' from 192.168.1.233:52151
    Sat Sep  7 20:50:26 2013 daemon.error netifd: Interface 'wan6' is now down
    Sat Sep  7 20:50:26 2013 daemon.err dnsmasq[1007]: no servers found in /tmp/resolv.conf.auto, will retry
    Sat Sep  7 20:50:26 2013 daemon.error netifd: wan (731): Received SIGTERM
    Sat Sep  7 20:50:26 2013 daemon.error netifd: Interface 'wan' is now down
    Sat Sep  7 20:50:26 2013 auth.info kernel: [ 3665.020000] eth1: link down
    Sat Sep  7 20:50:26 2013 auth.info kernel: [ 3665.050000] IPv6: ADDRCONF(NETDEV_UP): eth1: link is not ready
    Sat Sep  7 20:50:27 2013 auth.info kernel: [ 3666.030000] eth1: link up (100Mbps/Full duplex)
    Sat Sep  7 20:50:27 2013 auth.info kernel: [ 3666.030000] IPv6: ADDRCONF(NETDEV_CHANGE): eth1: link becomes ready
    Sat Sep  7 20:50:30 2013 daemon.error netifd: Interface 'wan' is now up
    Sat Sep  7 20:50:30 2013 daemon.error odhcp6c[1148]: (re)starting transaction on eth1
    Sat Sep  7 20:50:30 2013 daemon.error odhcp6c[1148]: Sending SOLICIT (timeout 4294967295s)
    Sat Sep  7 20:50:30 2013 authpriv.error firewall: Reloading firewall due to ifup of wan (eth1)
    Sat Sep  7 20:51:00 2013 daemon.info dnsmasq[1007]: reading /tmp/resolv.conf.auto
    Sat Sep  7 20:51:00 2013 daemon.info dnsmasq[1007]: using nameserver 192.168.11.1#53
    Sat Sep  7 20:51:00 2013 daemon.info dnsmasq[1007]: using nameserver 221.179.38.7#53
    Sat Sep  7 20:51:00 2013 daemon.info dnsmasq[1007]: using nameserver 211.136.192.6#53
    Sat Sep  7 20:51:00 2013 daemon.info dnsmasq[1007]: using local addresses only for domain lan
    Sat Sep  7 20:51:05 2013 security.info dropbear[1224]: Child connection from 192.168.1.233:52156
    Sat Sep  7 20:51:08 2013 daemon.info dnsmasq-dhcp[1007]: DHCPINFORM(br-lan) 192.168.1.233 2c:b0:5d:65:a1:af 

复制代码





``aaa``
ASDFASDFadfadfadsf

wr2041n路由，拆开看过芯片方案，是ar9344+ar9381，没有交换芯片，ar9344内置了交换，与wr941n v6的方案一致，与国外wrd3500方案相似
今天去openwrt的官网下载目录找到wr941n v6的trunk版固件，下载下来，改固件头验证，刷进wr2041之，成功刷入，4个LAN口与WAN口，及WIFI都能工作正常。
但450Mbps的速率无法工作，只能最大300Mbps，以及固件刷完之后依然显示TP-LINK TL-WDR3500， LAN口灯的顺序乱了，WAN及WIFI灯正常。
在此请问可有高手能帮忙修正，令OpenWRT能早日真正支持此款型号。


附上已改好固件头，能直接在wr2041n官方固件下用web界面刷的openwrt trunk，需要自己安装LUCI界面，默认ip 192.168.1.1
http://pan.baidu.com/share/link? ... 846171&third=15






附上内核及系统log， 望熟悉内核及架构的朋友能帮忙修正，或者去openwrt官网那开个ticket request


    [    0.000000] Linux version 3.10.10 (fnord@tschunk) (gcc version 4.6.4 (OpenWrt/Linaro GCC 4.6-2012.12 r37911) ) #1 Sat Sep 7 03:45:05 UTC 2013
    [    0.000000] MyLoader: sysp=b9edac4d, boardp=18bd4ff2, parts=495b283a
    [    0.000000] bootconsole [early0] enabled
    [    0.000000] CPU revision is: 0001974c (MIPS 74Kc)
    [    0.000000] SoC: Atheros AR9344 rev 2
    [    0.000000] Clocks: CPU:560.000MHz, DDR:450.000MHz, AHB:225.000MHz, Ref:40.000MHz
    [    0.000000] Determined physical RAM map:
    [    0.000000]  memory: 04000000 @ 00000000 (usable)
    [    0.000000] Initrd not found or empty - disabling initrd
    [    0.000000] Zone ranges:
    [    0.000000]   Normal   [mem 0x00000000-0x03ffffff]
    [    0.000000] Movable zone start for each node
    [    0.000000] Early memory node ranges
    [    0.000000]   node   0: [mem 0x00000000-0x03ffffff]
    [    0.000000] On node 0 totalpages: 16384
    [    0.000000] free_area_init_node: node 0, pgdat 80322b60, node_mem_map 81000000
    [    0.000000]   Normal zone: 128 pages used for memmap
    [    0.000000]   Normal zone: 0 pages reserved
    [    0.000000]   Normal zone: 16384 pages, LIFO batch:3
    [    0.000000] Primary instruction cache 64kB, VIPT, 4-way, linesize 32 bytes.
    [    0.000000] Primary data cache 32kB, 4-way, VIPT, cache aliases, linesize 32 bytes
    [    0.000000] pcpu-alloc: s0 r0 d32768 u32768 alloc=1*32768
    [    0.000000] pcpu-alloc: [0] 0
    [    0.000000] Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 16256
    [    0.000000] Kernel command line:  board=TL-WDR3500 console=ttyS0,115200 rootfstype=squashfs,jffs2 noinitrd
    [    0.000000] PID hash table entries: 256 (order: -2, 1024 bytes)
    [    0.000000] Dentry cache hash table entries: 8192 (order: 3, 32768 bytes)
    [    0.000000] Inode-cache hash table entries: 4096 (order: 2, 16384 bytes)
    [    0.000000] Writing ErrCtl register=00000000
    [    0.000000] Readback ErrCtl register=00000000
    [    0.000000] Memory: 61204k/65536k available (2309k kernel code, 4332k reserved, 607k data, 216k init, 0k highmem)
    [    0.000000] SLUB: HWalign=32, Order=0-3, MinObjects=0, CPUs=1, Nodes=1
    [    0.000000] NR_IRQS:51
    [    0.060000] Calibrating delay loop... 278.93 BogoMIPS (lpj=1394688)
    [    0.070000] pid_max: default: 32768 minimum: 301
    [    0.070000] Mount-cache hash table entries: 512
    [    0.080000] NET: Registered protocol family 16
    [    0.080000] MIPS: machine is TP-LINK TL-WDR3500
    [    0.090000] registering PCI controller with io_map_base unset
    [    0.510000] bio: create slab <bio-0> at 0
    [    0.510000] PCI host bridge to bus 0000:00
    [    0.520000] pci_bus 0000:00: root bus resource [mem 0x10000000-0x13ffffff]
    [    0.520000] pci_bus 0000:00: root bus resource [io  0x0000]
    [    0.530000] pci_bus 0000:00: No busn resource found for root bus, will use [bus 00-ff]
    [    0.530000] pci 0000:00:00.0: [168c:0030] type 00 class 0x028000
    [    0.530000] pci 0000:00:00.0: invalid calibration data
    [    0.540000] pci 0000:00:00.0: reg 10: [mem 0x00000000-0x0001ffff 64bit]
    [    0.540000] pci 0000:00:00.0: reg 30: [mem 0x00000000-0x0000ffff pref]
    [    0.540000] pci 0000:00:00.0: supports D1
    [    0.540000] pci 0000:00:00.0: PME# supported from D0 D1 D3hot
    [    0.540000] pci_bus 0000:00: busn_res: [bus 00-ff] end is updated to 00
    [    0.540000] pci 0000:00:00.0: BAR 0: assigned [mem 0x10000000-0x1001ffff 64bit]
    [    0.540000] pci 0000:00:00.0: BAR 6: assigned [mem 0x10020000-0x1002ffff pref]
    [    0.550000] pci 0000:00:00.0: using irq 40 for pin 1
    [    0.550000] Switching to clocksource MIPS
    [    0.560000] NET: Registered protocol family 2
    [    0.560000] TCP established hash table entries: 512 (order: 0, 4096 bytes)
    [    0.560000] TCP bind hash table entries: 512 (order: -1, 2048 bytes)
    [    0.570000] TCP: Hash tables configured (established 512 bind 512)
    [    0.570000] TCP: reno registered
    [    0.570000] UDP hash table entries: 256 (order: 0, 4096 bytes)
    [    0.580000] UDP-Lite hash table entries: 256 (order: 0, 4096 bytes)
    [    0.590000] NET: Registered protocol family 1
    [    0.590000] PCI: CLS 0 bytes, default 32
    [    0.610000] squashfs: version 4.0 (2009/01/31) Phillip Lougher
    [    0.610000] jffs2: version 2.2 (NAND) (SUMMARY) (LZMA) (RTIME) (CMODE_PRIORITY) (c) 2001-2006 Red Hat, Inc.
    [    0.620000] msgmni has been set to 119
    [    0.630000] io scheduler noop registered
    [    0.630000] io scheduler deadline registered (default)
    [    0.640000] Serial: 8250/16550 driver, 16 ports, IRQ sharing enabled
    [    0.670000] serial8250.0: ttyS0 at MMIO 0x18020000 (irq = 11) is a 16550A
    [    0.670000] console [ttyS0] enabled, bootconsole disabled
    [    0.690000] ath79-spi ath79-spi: master is unqueued, this is deprecated
    [    0.700000] m25p80 spi0.0: found s25sl032p, expected m25p80
    [    0.700000] m25p80 spi0.0: s25sl032p (4096 Kbytes)
    [    0.710000] 5 tp-link partitions found on MTD device spi0.0
    [    0.710000] Creating 5 MTD partitions on "spi0.0":
    [    0.720000] 0x000000000000-0x000000020000 : "u-boot"
    [    0.720000] 0x000000020000-0x000000122d40 : "kernel"
    [    0.730000] mtd: partition "kernel" must either start or end on erase block boundary or be smaller than an erase block -- forcing read-only
    [    0.740000] 0x000000122d40-0x0000003f0000 : "rootfs"
    [    0.750000] mtd: partition "rootfs" must either start or end on erase block boundary or be smaller than an erase block -- forcing read-only
    [    0.760000] mtd: partition "rootfs" set to be root filesystem
    [    0.770000] mtd: partition "rootfs_data" created automatically, ofs=0x2e0000, len=0x110000
    [    0.780000] 0x0000002e0000-0x0000003f0000 : "rootfs_data"
    [    0.780000] 0x0000003f0000-0x000000400000 : "art"
    [    0.790000] 0x000000020000-0x0000003f0000 : "firmware"
    [    0.810000] libphy: ag71xx_mdio: probed
    [    0.820000] eth0: Atheros AG71xx at 0xba000000, irq 5, mode:GMII
    [    1.370000] eth0: Found an AR934X built-in switch
    [    2.410000] eth1: Atheros AG71xx at 0xb9000000, irq 4, mode:MII
    [    2.960000] ag71xx ag71xx.0 eth1: connected to PHY at ag71xx-mdio.1:04 [uid=004dd042, driver=Generic PHY]
    [    2.970000] TCP: cubic registered
    [    2.980000] NET: Registered protocol family 17
    [    2.980000] Bridge firewalling registered
    [    2.990000] 8021q: 802.1Q VLAN Support v1.8
    [    3.000000] VFS: Mounted root (squashfs filesystem) readonly on device 31:2.
    [    3.010000] Freeing unused kernel memory: 216K (8033a000 - 80370000)
    [    4.580000] usbcore: registered new interface driver usbfs
    [    4.590000] usbcore: registered new interface driver hub
    [    4.590000] usbcore: registered new device driver usb
    [    4.770000] ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
    [    4.770000] ehci-platform: EHCI generic platform driver
    [    4.780000] ehci-platform ehci-platform: EHCI Host Controller
    [    4.790000] ehci-platform ehci-platform: new USB bus registered, assigned bus number 1
    [    4.800000] ehci-platform ehci-platform: irq 3, io mem 0x1b000000
    [    4.820000] ehci-platform ehci-platform: USB 2.0 started, EHCI 1.00
    [    4.820000] hub 1-0:1.0: USB hub found
    [    4.830000] hub 1-0:1.0: 1 port detected
    [    4.880000] ohci_hcd: USB 1.1 'Open' Host Controller (OHCI) Driver
    [    9.550000] jffs2: notice: (335) jffs2_build_xattr_subsystem: complete building xattr subsystem, 1 of xdatum (0 unchecked, 0 orphan) and 12 of xref (0 dead, 3 orphan) found.
    [   11.210000] Loading modules backported from Linux version master-2013-06-27-0-gdcfa6d5
    [   11.220000] Backport generated by backports.git backports-20130617-4-ge3220f5
    [   11.250000] cfg80211: Calling CRDA to update world regulatory domain
    [   11.250000] cfg80211: World regulatory domain updated:
    [   11.260000] cfg80211:   (start_freq - end_freq @ bandwidth), (max_antenna_gain, max_eirp)
    [   11.270000] cfg80211:   (2402000 KHz - 2472000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   11.270000] cfg80211:   (2457000 KHz - 2482000 KHz @ 20000 KHz), (300 mBi, 2000 mBm)
    [   11.280000] cfg80211:   (2474000 KHz - 2494000 KHz @ 20000 KHz), (300 mBi, 2000 mBm)
    [   11.290000] cfg80211:   (5170000 KHz - 5250000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   11.300000] cfg80211:   (5735000 KHz - 5835000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   11.520000] NET: Registered protocol family 10
    [   11.910000] ath: phy0: Unable to initialize hardware; initialization status: -5
    [   11.920000] ath9k ar934x_wmac: failed to initialize device
    [   11.930000] ath9k: probe of ar934x_wmac failed with error -5
    [   11.930000] PCI: Enabling device 0000:00:00.0 (0000 -> 0002)
    [   11.940000] ath: EEPROM regdomain: 0x0
    [   11.940000] ath: EEPROM indicates default country code should be used
    [   11.940000] ath: doing EEPROM country->regdmn map search
    [   11.940000] ath: country maps to regdmn code: 0x3a
    [   11.940000] ath: Country alpha2 being used: US
    [   11.940000] ath: Regpair used: 0x3a
    [   11.950000] ieee80211 phy1: Selected rate control algorithm 'minstrel_ht'
    [   11.950000] cfg80211: Calling CRDA for country: US
    [   11.960000] ieee80211 phy1: Atheros AR9300 Rev:3 mem=0xb0000000, irq=40
    [   11.970000] cfg80211: Regulatory domain changed to country: US
    [   11.970000] cfg80211:   (start_freq - end_freq @ bandwidth), (max_antenna_gain, max_eirp)
    [   11.980000] cfg80211:   (2402000 KHz - 2472000 KHz @ 40000 KHz), (300 mBi, 2700 mBm)
    [   11.990000] cfg80211:   (5170000 KHz - 5250000 KHz @ 40000 KHz), (300 mBi, 1700 mBm)
    [   12.000000] cfg80211:   (5250000 KHz - 5330000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   12.000000] cfg80211:   (5490000 KHz - 5600000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   12.010000] cfg80211:   (5650000 KHz - 5710000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    [   12.020000] cfg80211:   (5735000 KHz - 5835000 KHz @ 40000 KHz), (300 mBi, 3000 mBm)
    [   12.080000] PPP generic driver version 2.4.2
    [   12.290000] ip_tables: (C) 2000-2006 Netfilter Core Team
    [   12.330000] xt_time: kernel timezone is -0000
    [   12.460000] NET: Registered protocol family 24
    [   12.470000] nf_conntrack version 0.5.0 (959 buckets, 3836 max)
    [   12.750000] ip6_tables: (C) 2000-2006 Netfilter Core Team
    [   17.290000] IPv6: ADDRCONF(NETDEV_UP): eth0: link is not ready
    [   17.290000] device eth0 entered promiscuous mode
    [   17.300000] IPv6: ADDRCONF(NETDEV_UP): br-lan: link is not ready
    [   17.310000] IPv6: ADDRCONF(NETDEV_UP): eth1: link is not ready
    [   20.030000] eth1: link up (100Mbps/Full duplex)
    [   20.030000] IPv6: ADDRCONF(NETDEV_CHANGE): eth1: link becomes ready
    [   22.910000] IPv6: ADDRCONF(NETDEV_UP): wlan1: link is not ready
    [   22.930000] device wlan1 entered promiscuous mode
    [   22.940000] IPv6: ADDRCONF(NETDEV_UP): wlan1: link is not ready
    [   22.960000] IPv6: ADDRCONF(NETDEV_CHANGE): wlan1: link becomes ready
    [   22.970000] br-lan: port 2(wlan1) entered forwarding state
    [   22.970000] br-lan: port 2(wlan1) entered forwarding state
    [   22.980000] IPv6: ADDRCONF(NETDEV_CHANGE): br-lan: link becomes ready
    [   24.970000] br-lan: port 2(wlan1) entered forwarding state
    [ 3665.020000] eth1: link down
    [ 3665.050000] IPv6: ADDRCONF(NETDEV_UP): eth1: link is not ready
    [ 3666.030000] eth1: link up (100Mbps/Full duplex)
    [ 3666.030000] IPv6: ADDRCONF(NETDEV_CHANGE): eth1: link becomes ready

复制代码

    Thu Jan  1 08:00:10 1970 auth.info kernel: [    0.690000] ath79-spi ath79-spi: master is unqueued, this is deprecated
    Thu Jan  1 08:00:10 1970 auth.err kernel: [    0.700000] m25p80 spi0.0: found s25sl032p, expected m25p80
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    0.700000] m25p80 spi0.0: s25sl032p (4096 Kbytes)
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.710000] 5 tp-link partitions found on MTD device spi0.0
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.710000] Creating 5 MTD partitions on "spi0.0":
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.720000] 0x000000000000-0x000000020000 : "u-boot"
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.720000] 0x000000020000-0x000000122d40 : "kernel"
    Thu Jan  1 08:00:10 1970 auth.err kernel: [    0.730000] mtd: partition "kernel" must either start or end on erase block boundary or be smaller than an erase block -- forcing read-only
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.740000] 0x000000122d40-0x0000003f0000 : "rootfs"
    Thu Jan  1 08:00:10 1970 auth.err kernel: [    0.750000] mtd: partition "rootfs" must either start or end on erase block boundary or be smaller than an erase block -- forcing read-only
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.760000] mtd: partition "rootfs" set to be root filesystem
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    0.770000] mtd: partition "rootfs_data" created automatically, ofs=0x2e0000, len=0x110000
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.780000] 0x0000002e0000-0x0000003f0000 : "rootfs_data"
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.780000] 0x0000003f0000-0x000000400000 : "art"
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    0.790000] 0x000000020000-0x0000003f0000 : "firmware"
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    0.810000] libphy: ag71xx_mdio: probed
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    0.820000] eth0: Atheros AG71xx at 0xba000000, irq 5, mode:GMII
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    1.370000] eth0: Found an AR934X built-in switch
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    2.410000] eth1: Atheros AG71xx at 0xb9000000, irq 4, mode:MII
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    2.960000] ag71xx ag71xx.0 eth1: connected to PHY at ag71xx-mdio.1:04 [uid=004dd042, driver=Generic PHY]
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    2.970000] TCP: cubic registered
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    2.980000] NET: Registered protocol family 17
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    2.980000] Bridge firewalling registered
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    2.990000] 8021q: 802.1Q VLAN Support v1.8
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    3.000000] VFS: Mounted root (squashfs filesystem) readonly on device 31:2.
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    3.010000] Freeing unused kernel memory: 216K (8033a000 - 80370000)
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.580000] usbcore: registered new interface driver usbfs
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.590000] usbcore: registered new interface driver hub
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.590000] usbcore: registered new device driver usb
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.770000] ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.770000] ehci-platform: EHCI generic platform driver
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.780000] ehci-platform ehci-platform: EHCI Host Controller
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.790000] ehci-platform ehci-platform: new USB bus registered, assigned bus number 1
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.800000] ehci-platform ehci-platform: irq 3, io mem 0x1b000000
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.820000] ehci-platform ehci-platform: USB 2.0 started, EHCI 1.00
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.820000] hub 1-0:1.0: USB hub found
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.830000] hub 1-0:1.0: 1 port detected
    Thu Jan  1 08:00:10 1970 auth.info kernel: [    4.880000] ohci_hcd: USB 1.1 'Open' Host Controller (OHCI) Driver
    Thu Jan  1 08:00:10 1970 auth.error kernel: [    9.550000] jffs2: notice: (335) jffs2_build_xattr_subsystem: complete building xattr subsystem, 1 of xdatum (0 unchecked, 0 orphan) and 12 of xref (0 dead, 3 orphan) found.
    Sat Sep  7 19:49:00 2013 daemon.info sysinit: Sat Sep  7 11:49:00 UTC 2013
    Sat Sep  7 19:49:00 2013 authpriv.alert syslog: kmodloader: loading kernel modules from /etc/modules.d/**
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.210000] Loading modules backported from Linux version master-2013-06-27-0-gdcfa6d5
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.220000] Backport generated by backports.git backports-20130617-4-ge3220f5
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.250000] cfg80211: Calling CRDA to update world regulatory domain
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.250000] cfg80211: World regulatory domain updated:
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.260000] cfg80211:   (start_freq - end_freq @ bandwidth), (max_antenna_gain, max_eirp)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.270000] cfg80211:   (2402000 KHz - 2472000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.270000] cfg80211:   (2457000 KHz - 2482000 KHz @ 20000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.280000] cfg80211:   (2474000 KHz - 2494000 KHz @ 20000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.290000] cfg80211:   (5170000 KHz - 5250000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.300000] cfg80211:   (5735000 KHz - 5835000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:00 2013 auth.info kernel: [   11.520000] NET: Registered protocol family 10
    Sat Sep  7 19:49:01 2013 auth.emerg kernel: [   11.910000] ath: phy0: Unable to initialize hardware; initialization status: -5
    Sat Sep  7 19:49:01 2013 auth.emerg kernel: [   11.920000] ath9k ar934x_wmac: failed to initialize device
    Sat Sep  7 19:49:01 2013 auth.err kernel: [   11.930000] ath9k: probe of ar934x_wmac failed with error -5
    Sat Sep  7 19:49:01 2013 auth.err kernel: [   11.930000] PCI: Enabling device 0000:00:00.0 (0000 -> 0002)
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: EEPROM regdomain: 0x0
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: EEPROM indicates default country code should be used
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: doing EEPROM country->regdmn map search
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: country maps to regdmn code: 0x3a
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: Country alpha2 being used: US
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.940000] ath: Regpair used: 0x3a
    Sat Sep  7 19:49:01 2013 auth.none kernel: [   11.950000] ieee80211 phy1: Selected rate control algorithm 'minstrel_ht'
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.950000] cfg80211: Calling CRDA for country: US
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.960000] ieee80211 phy1: Atheros AR9300 Rev:3 mem=0xb0000000, irq=40
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.970000] cfg80211: Regulatory domain changed to country: US
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.970000] cfg80211:   (start_freq - end_freq @ bandwidth), (max_antenna_gain, max_eirp)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.980000] cfg80211:   (2402000 KHz - 2472000 KHz @ 40000 KHz), (300 mBi, 2700 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   11.990000] cfg80211:   (5170000 KHz - 5250000 KHz @ 40000 KHz), (300 mBi, 1700 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.000000] cfg80211:   (5250000 KHz - 5330000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.000000] cfg80211:   (5490000 KHz - 5600000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.010000] cfg80211:   (5650000 KHz - 5710000 KHz @ 40000 KHz), (300 mBi, 2000 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.020000] cfg80211:   (5735000 KHz - 5835000 KHz @ 40000 KHz), (300 mBi, 3000 mBm)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.080000] PPP generic driver version 2.4.2
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.290000] ip_tables: (C) 2000-2006 Netfilter Core Team
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.330000] xt_time: kernel timezone is -0000
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.460000] NET: Registered protocol family 24
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.470000] nf_conntrack version 0.5.0 (959 buckets, 3836 max)
    Sat Sep  7 19:49:01 2013 auth.info kernel: [   12.750000] ip6_tables: (C) 2000-2006 Netfilter Core Team
    Sat Sep  7 19:49:06 2013 auth.info kernel: [   17.290000] IPv6: ADDRCONF(NETDEV_UP): eth0: link is not ready
    Sat Sep  7 19:49:06 2013 auth.info kernel: [   17.290000] device eth0 entered promiscuous mode
    Sat Sep  7 19:49:06 2013 auth.info kernel: [   17.300000] IPv6: ADDRCONF(NETDEV_UP): br-lan: link is not ready
    Sat Sep  7 19:49:06 2013 daemon.error netifd: Interface 'lan' is now up
    Sat Sep  7 19:49:06 2013 daemon.error netifd: Interface 'loopback' is now up
    Sat Sep  7 19:49:06 2013 auth.info kernel: [   17.310000] IPv6: ADDRCONF(NETDEV_UP): eth1: link is not ready
    Sat Sep  7 19:49:06 2013 daemon.error netifd: wan (731): udhcpc (v1.19.4) started
    Sat Sep  7 19:49:06 2013 authpriv.error firewall: Reloading firewall due to ifup of lan (br-lan)
    Sat Sep  7 19:49:06 2013 daemon.error netifd: wan (731): Sending discover...
    Sat Sep  7 19:49:07 2013 daemon.err 6relayd[753]: Failed to relay to ff02::1%br-lan (Cannot assign requested address)
    Sat Sep  7 19:49:08 2013 daemon.err 6relayd[753]: Failed to relay to ff02::1%br-lan (Cannot assign requested address)
    Sat Sep  7 19:49:09 2013 auth.info kernel: [   20.030000] eth1: link up (100Mbps/Full duplex)
    Sat Sep  7 19:49:09 2013 auth.info kernel: [   20.030000] IPv6: ADDRCONF(NETDEV_CHANGE): eth1: link becomes ready
    Sat Sep  7 19:49:09 2013 daemon.error netifd: wan (731): Sending discover...
    Sat Sep  7 19:49:09 2013 daemon.error netifd: wan (731): Sending select for 192.168.11.179...
    Sat Sep  7 19:49:09 2013 daemon.error netifd: wan (731): Lease of 192.168.11.179 obtained, lease time 86400
    Sat Sep  7 19:49:09 2013 daemon.error netifd: Interface 'wan' is now up
    Sat Sep  7 19:49:10 2013 daemon.error odhcp6c[797]: (re)starting transaction on eth1
    Sat Sep  7 19:49:10 2013 daemon.error odhcp6c[797]: Sending SOLICIT (timeout 4294967295s)
    Sat Sep  7 19:49:10 2013 authpriv.error firewall: Reloading firewall due to ifup of wan (eth1)
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.910000] IPv6: ADDRCONF(NETDEV_UP): wlan1: link is not ready
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.930000] device wlan1 entered promiscuous mode
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.940000] IPv6: ADDRCONF(NETDEV_UP): wlan1: link is not ready
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.960000] IPv6: ADDRCONF(NETDEV_CHANGE): wlan1: link becomes ready
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.970000] br-lan: port 2(wlan1) entered forwarding state
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.970000] br-lan: port 2(wlan1) entered forwarding state
    Sat Sep  7 19:49:12 2013 auth.info kernel: [   22.980000] IPv6: ADDRCONF(NETDEV_CHANGE): br-lan: link becomes ready
    Sat Sep  7 19:49:14 2013 auth.info kernel: [   24.970000] br-lan: port 2(wlan1) entered forwarding state
    Sat Sep  7 19:49:15 2013 security.info dropbear[949]: Not backgrounding
    Sat Sep  7 19:49:17 2013 authpriv.error dnsmasq: DNS rebinding protection is active, will discard upstream RFC1918 responses!
    Sat Sep  7 19:49:17 2013 authpriv.error dnsmasq: Allowing 127.0.0.0/8 responses
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: started, version 2.66 cachesize 150
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: compile time options: IPv6 GNU-getopt no-DBus no-i18n no-IDN DHCP no-DHCPv6 no-Lua TFTP no-conntrack no-ipset no-auth
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq-dhcp[1007]: DHCP, IP range 192.168.1.100 -- 192.168.1.249, lease time 12h
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: using local addresses only for domain lan
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: reading /tmp/resolv.conf.auto
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: using nameserver 192.168.11.1#53
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: using nameserver 221.179.38.7#53
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: using nameserver 211.136.192.6#53
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: using local addresses only for domain lan
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq[1007]: read /etc/hosts - 1 addresses
    Sat Sep  7 19:49:20 2013 daemon.info dnsmasq-dhcp[1007]: read /etc/ethers - 0 addresses
    Sat Sep  7 19:49:20 2013 daemon.info sysinit: setting up led USB
    Sat Sep  7 19:49:20 2013 daemon.info sysinit: setting up led WLAN2G
    Sat Sep  7 19:49:20 2013 daemon.info sysinit: sh: write error: Invalid argument
    Sat Sep  7 19:49:21 2013 daemon.info sysinit: - init complete -
    Sat Sep  7 20:49:38 2013 daemon.info hostapd: wlan1: STA 2c:b0:5d:65:a1:af IEEE 802.11: authenticated
    Sat Sep  7 20:49:38 2013 daemon.info hostapd: wlan1: STA 2c:b0:5d:65:a1:af IEEE 802.11: associated (aid 1)
    Sat Sep  7 20:49:39 2013 daemon.info dnsmasq-dhcp[1007]: DHCPREQUEST(br-lan) 192.168.1.233 2c:b0:5d:65:a1:af
    Sat Sep  7 20:49:39 2013 daemon.info dnsmasq-dhcp[1007]: DHCPACK(br-lan) 192.168.1.233 2c:b0:5d:65:a1:af Kelly-PC
    Sat Sep  7 20:49:41 2013 daemon.info dnsmasq[1007]: read /etc/hosts - 1 addresses
    Sat Sep  7 20:49:41 2013 daemon.info dnsmasq[1007]: read /tmp/hosts/6relayd - 1 addresses
    Sat Sep  7 20:49:41 2013 daemon.info dnsmasq-dhcp[1007]: read /etc/ethers - 0 addresses
    Sat Sep  7 20:49:42 2013 daemon.info dnsmasq-dhcp[1007]: DHCPINFORM(br-lan) 192.168.1.233 2c:b0:5d:65:a1:af
    Sat Sep  7 20:49:42 2013 daemon.info dnsmasq-dhcp[1007]: DHCPACK(br-lan) 192.168.1.233 2c:b0:5d:65:a1:af Kelly-PC
    Sat Sep  7 20:49:43 2013 security.info dropbear[1031]: Child connection from 192.168.1.233:52151
    Sat Sep  7 20:49:45 2013 security.err dropbear[1031]: Bad password attempt for 'root' from 192.168.1.233:52151
    Sat Sep  7 20:49:49 2013 security.error dropbear[1031]: Password auth succeeded for 'root' from 192.168.1.233:52151
    Sat Sep  7 20:50:26 2013 daemon.error netifd: Interface 'wan6' is now down
    Sat Sep  7 20:50:26 2013 daemon.err dnsmasq[1007]: no servers found in /tmp/resolv.conf.auto, will retry
    Sat Sep  7 20:50:26 2013 daemon.error netifd: wan (731): Received SIGTERM
    Sat Sep  7 20:50:26 2013 daemon.error netifd: Interface 'wan' is now down
    Sat Sep  7 20:50:26 2013 auth.info kernel: [ 3665.020000] eth1: link down
    Sat Sep  7 20:50:26 2013 auth.info kernel: [ 3665.050000] IPv6: ADDRCONF(NETDEV_UP): eth1: link is not ready
    Sat Sep  7 20:50:27 2013 auth.info kernel: [ 3666.030000] eth1: link up (100Mbps/Full duplex)
    Sat Sep  7 20:50:27 2013 auth.info kernel: [ 3666.030000] IPv6: ADDRCONF(NETDEV_CHANGE): eth1: link becomes ready
    Sat Sep  7 20:50:30 2013 daemon.error netifd: Interface 'wan' is now up
    Sat Sep  7 20:50:30 2013 daemon.error odhcp6c[1148]: (re)starting transaction on eth1
    Sat Sep  7 20:50:30 2013 daemon.error odhcp6c[1148]: Sending SOLICIT (timeout 4294967295s)
    Sat Sep  7 20:50:30 2013 authpriv.error firewall: Reloading firewall due to ifup of wan (eth1)
    Sat Sep  7 20:51:00 2013 daemon.info dnsmasq[1007]: reading /tmp/resolv.conf.auto
    Sat Sep  7 20:51:00 2013 daemon.info dnsmasq[1007]: using nameserver 192.168.11.1#53
    Sat Sep  7 20:51:00 2013 daemon.info dnsmasq[1007]: using nameserver 221.179.38.7#53
    Sat Sep  7 20:51:00 2013 daemon.info dnsmasq[1007]: using nameserver 211.136.192.6#53
    Sat Sep  7 20:51:00 2013 daemon.info dnsmasq[1007]: using local addresses only for domain lan
    Sat Sep  7 20:51:05 2013 security.info dropbear[1224]: Child connection from 192.168.1.233:52156
    Sat Sep  7 20:51:08 2013 daemon.info dnsmasq-dhcp[1007]: DHCPINFORM(br-lan) 192.168.1.233 2c:b0:5d:65:a1:af 

复制代码







TP-Link WR1041N  OpenWrt  

TP-Link WR1041N  OpenWrt 

luci的web管理界面
1.。固件默认中文
2.。.默认用户名 root 密码admin


WR1041N的升级界面，上传刚才下载的openwrt固件升级

官方版本没有内置Web管理界面


connect

=== IMPORTANT ============================

  Use 'passwd' to set your login password

  this will disable telnet and enable SSH

------------------------------------------

 

 

BusyBox v1.19.4 (2012-05-28 11:39:51 PDT) built-in shell (ash)

Enter 'help' for a list of built-in commands.

 
————————————————
版权声明：本文为CSDN博主「佳岳」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/xuejiayue1105/article/details/9315947

ATTITUDE ADJUSTMENT (Bleeding Edge, r31954)


 * 1/4 oz Vodka      Pour all ingredients into mixing

  * 1/4 oz Gin        tin with ice, strain into glass.

  * 1/4 oz Amaretto

  * 1/4 oz Triple sec

  * 1/4 oz Peach schnapps

  * 1/4 oz Sour mix

  * 1 splash Cranberry juice

-----------------------------------------------------

root@OpenWrt:/#passwd

Changing password for root

New password:

Retype password:

Password for root changed by root 
————————————————
版权声明：本文为CSDN博主「佳岳」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/xuejiayue1105/article/details/9315947




root@OpenWrt:/# vi /etc/config/network

 

 

        config interface 'wan'

        option ifname 'eth0.2'

        option proto 'pppoe'


        option username '你的ADSL帐号'

        option password '你的ADSL密码' 
————————————————
版权声明：本文为CSDN博主「佳岳」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/xuejiayue1105/article/details/9315947

然后我们开始拨号，更新可选工具包，安装Luci管理界面，安装Luci 中文包，multiwan多拨管理，启动管理界面：





root@OpenWrt:/#/etc/init.d/network restart

root@OpenWrt:/#opkg update

root@OpenWrt:/#opkg install luci

root@OpenWrt:/#opkg install luci-i18n-chinese

root@OpenWrt:/#opkg install luci-app-multiwan

root@OpenWrt:/#/etc/init.d/uhttpd enable

root@OpenWrt:/#/etc/init.d/uhttpd start 



刷OPEN WRT 后WIFI故障解决  
 
 

vi /etc/config/wireless   #删除或注释掉option disabled 1这句

只要执行这一句就可以一般的话

如果不行的话


root@OpenWrt:~# rm /etc/config/wireless   #重建无线配置文件
root@OpenWrt:~# wifi detect >  /etc/config/wireless
root@OpenWrt:~# vi /etc/config/wireless   #删除或注释掉option disabled 1这句 (如果看)
root@OpenWrt:~# wifi up
 \

 

看看运行日志

 

     === IMPORTANT ============================
      Use 'passwd' to set your login password
      this will disable telnet and enable SSH
     ------------------------------------------
     
     
    BusyBox v1.19.4 (2013-07-11 10:30:19 PDT) built-in shell (ash)
    Enter 'help' for a list of built-in commands.
      _______                     ________        __
     |       |.-----.-----.-----.|  |  |  |.----.|  |_
     |   -   ||  _  |  -__|     ||  |  |  ||   _||   _|
     |_______||   __|_____|__|__||________||__|  |____|
              |__| W I R E L E S S   F R E E D O M
     -----------------------------------------------------
     BARRIER BREAKER (Bleeding Edge, r37237)
     -----------------------------------------------------
      * 1/2 oz Galliano         Pour all ingredients into
      * 4 oz cold Coffee        an irish coffee mug filled
      * 1 1/2 oz Dark Rum       with crushed ice. Stir.
      * 2 tsp. Creme de Cacao
     -----------------------------------------------------
    root@OpenWrt:/# passwd
    Changing password for root
    New password: 
    Bad password: too short
    Retype password: 
    Password for root changed by root
    root@OpenWrt:/# ls
    bin      dev      etc      lib      mnt      overlay  proc     rom      root     sbin     sys      tmp      usr      var      www
    root@OpenWrt:/# ls -ltr
    dr-xr-xr-x   40 root     root             0 Jan  1 00:00 proc
    dr-xr-xr-x   11 root     root             0 Jan  1 00:00 sys
    drwxr-xr-x    4 root     root          1100 Jan  1 00:00 dev
    drwxrwxrwt   12 root     root           340 Jan  1 00:00 tmp
    drwxr-xr-x    4 root     root             0 Jan  1 00:00 overlay
    drwxr-xr-x    1 root     root             0 Jan  1 00:01 etc
    drwxr-xr-x    2 root     root             3 Jul 11  2013 www
    drwxr-xr-x    2 root     root             3 Jul 11  2013 root
    drwxr-xr-x    2 root     root             3 Jul 11  2013 mnt
    drwxr-xr-x    6 root     root            74 Jul 11  2013 usr
    drwxr-xr-x   11 root     root           624 Jul 11  2013 lib
    lrwxrwxrwx    1 root     root             4 Jul 11  2013 var -> /tmp
    drwxr-xr-x    2 root     root           687 Jul 11  2013 sbin
    drwxr-xr-x    2 root     root           703 Jul 11  2013 bin
    drwxr-xr-x   16 root     root           211 Jul 11  2013 rom
    root@OpenWrt:/# vi /etc/config/network
            option netmask '255.0.0.0'
            option ula_prefix 'fd44:2621:80f2::/48'
            option ip6assign '60'
            option proto 'dhcp'
            option proto 'dhcpv6'
            option enable_vlan '1'
            option ports '0t 2 3 4 5'
            option ports '0t 1'
    ~
    ~
    ~
    ~
    ~
    config interface 'loopback'
            option ifname 'lo'
            option proto 'static'
            option ipaddr '127.0.0.1'
            option netmask '255.0.0.0'
    config globals 'globals'
            option ula_prefix 'fd44:2621:80f2::/48'
    config interface 'lan'
            option ifname 'eth0.1'
            option type 'bridge'
            option proto 'static'
            option ipaddr '192.168.1.1'
            option netmask '255.255.255.0'
            option ip6assign '60'
    config interface 'wan'
            option ifname 'eth0.2'
            option proto 'dhcp'
    config interface 'wan6'
            option ifname '@wan'
            option proto 'dhcpv6'
    config switch
            option name 'switch0'
            option reset '1'
            option enable_vlan '1'
    config switch_vlan
            option device 'switch0'
            option vlan '1'
            option ports '0t 2 3 4 5'
    config switch_vlan
            option device 'switch0'
            option vlan '2'
            option ports '0t 1'
            option proto 'pppoe'
                           
            option proto 'dhcpv6'
                 
            option enable_vlan '1'
                      
            option ports '0t 2 3 4 5'
                      
            option ports '0t 1'
            option username '051288635066'
                           
                                
            option proto 'dhcpv6'
                                 
            option enable_vlan '1'
                                   
            option ports '0t 2 3 4 5'
                                   
            option ports '0t 1'
    root@OpenWrt:/# ls -ltr
    dr-xr-xr-x   40 root     root             0 Jan  1 00:00 proc
    dr-xr-xr-x   11 root     root             0 Jan  1 00:00 sys
    drwxr-xr-x    4 root     root          1100 Jan  1 00:00 dev
    drwxrwxrwt   12 root     root           340 Jan  1 00:00 tmp
    drwxr-xr-x    4 root     root             0 Jan  1 00:00 overlay
    drwxr-xr-x    1 root     root             0 Jan  1 00:01 etc
    drwxr-xr-x    2 root     root             3 Jul 11  2013 www
    drwxr-xr-x    2 root     root             3 Jul 11  2013 root
    drwxr-xr-x    2 root     root             3 Jul 11  2013 mnt
    drwxr-xr-x    6 root     root            74 Jul 11  2013 usr
    drwxr-xr-x   11 root     root           624 Jul 11  2013 lib
    lrwxrwxrwx    1 root     root             4 Jul 11  2013 var -> /tmp
    drwxr-xr-x    2 root     root           687 Jul 11  2013 sbin
    drwxr-xr-x    2 root     root           703 Jul 11  2013 bin
    drwxr-xr-x   16 root     root           211 Jul 11  2013 rom
    root@OpenWrt:/# cd /etc/
    root@OpenWrt:/etc# ls
    TZ                    dnsmasq.conf          hosts                 modules-boot.d        passwd                rc.button             shadow
    banner                dropbear              hotplug-preinit.json  modules.d             passwd-               rc.common             shadow-
    config                ethers                hotplug.d             mtab                  ppp                   rc.d                  shells
    crontabs              firewall.user         hotplug.json          openwrt_release       preinit               rc.local              sysctl.conf
    defconfig             fstab                 init.d                openwrt_version       profile               resolv.conf           sysupgrade.conf
    diag.sh               group                 inittab               opkg.conf             protocols             services              uci-defaults
    root@OpenWrt:/etc# cd network
    /bin/ash: cd: can't cd to network
    root@OpenWrt:/etc# ls
    TZ                    dnsmasq.conf          hosts                 modules-boot.d        passwd                rc.button             shadow
    banner                dropbear              hotplug-preinit.json  modules.d             passwd-               rc.common             shadow-
    config                ethers                hotplug.d             mtab                  ppp                   rc.d                  shells
    crontabs              firewall.user         hotplug.json          openwrt_release       preinit               rc.local              sysctl.conf
    defconfig             fstab                 init.d                openwrt_version       profile               resolv.conf           sysupgrade.conf
    diag.sh               group                 inittab               opkg.conf             protocols             services              uci-defaults
    root@OpenWrt:/etc# cd config
    root@OpenWrt:/etc/config# ls
    6relayd   dhcp      dropbear  firewall  network   system    ubootenv  wireless
    root@OpenWrt:/etc/config# ls -ltr
    -rw-r--r--    1 root     root           486 Jan  1 00:00 wireless
    -rw-r--r--    1 root     root           373 Jan  1 00:00 system
    -rw-r--r--    1 root     root             0 Jan  1 00:00 ubootenv
    -rw-r--r--    1 root     root           824 Jan  1 00:05 network
    -rw-r--r--    1 root     root          3887 Jul 11  2013 firewall
    -rw-r--r--    1 root     root           708 Jul 11  2013 6relayd
    -rw-r--r--    1 root     root           885 Jul 11  2013 dhcp
    -rw-r--r--    1 root     root           134 Jul 11  2013 dropbear
    root@OpenWrt:/etc/config# vi network
            option netmask '255.0.0.0'
            option ula_prefix 'fd44:2621:80f2::/48'
            option ip6assign '60'
            option password '25211621'
            option proto 'dhcpv6'
            option enable_vlan '1'
            option ports '0t 2 3 4 5'
            option ports '0t 1'
    ~
    ~
    ~
    root@OpenWrt:/etc/config# cd ..
    root@OpenWrt:/etc# ls
    TZ                    dnsmasq.conf          hosts                 modules-boot.d        passwd                rc.button             shadow
    banner                dropbear              hotplug-preinit.json  modules.d             passwd-               rc.common             shadow-
    config                ethers                hotplug.d             mtab                  ppp                   rc.d                  shells
    crontabs              firewall.user         hotplug.json          openwrt_release       preinit               rc.local              sysctl.conf
    defconfig             fstab                 init.d                openwrt_version       profile               resolv.conf           sysupgrade.conf
    diag.sh               group                 inittab               opkg.conf             protocols             services              uci-defaults
    root@OpenWrt:/etc# cd init.d
    root@OpenWrt:/etc/init.d# ls
    6relayd    cron       dnsmasq    dropbear   led        network    sysntpd    umount
    boot       defconfig  done       firewall   log        sysctl     telnet     usb
    root@OpenWrt:/etc/init.d# ls -ltr
    -rwxr-xr-x    1 root     root           318 Oct 10  2012 defconfig
    -rwxr-xr-x    1 root     root           102 Oct 10  2012 umount
    -rwxr-xr-x    1 root     root           586 Oct 10  2012 sysntpd
    -rwxr-xr-x    1 root     root          2015 Nov 26  2012 led
    -rwxr-xr-x    1 root     root           160 Dec 21  2012 usb
    -rwxr-xr-x    1 root     root           126 Apr 10  2013 sysctl
    -rwxr-xr-x    1 root     root           308 May 27  2013 done
    -rwxr-xr-x    1 root     root           576 Jun 15  2013 network
    -rwxr-xr-x    1 root     root          1906 Jul 11  2013 boot
    -rwxr-xr-x    1 root     root          1099 Jul 11  2013 log
    -rwxr-xr-x    1 root     root           262 Jul 11  2013 firewall
    -rwxr-xr-x    1 root     root          4096 Jul 11  2013 6relayd
    -rwxr-xr-x    1 root     root         12818 Jul 11  2013 dnsmasq
    -rwxr-xr-x    1 root     root          4061 Jul 11  2013 dropbear
    -rwxr-xr-x    1 root     root           878 Jul 11  2013 telnet
    -rwxr-xr-x    1 root     root           385 Jul 11  2013 cron
    root@OpenWrt:/etc/init.d# network restart
    /bin/ash: network: not found
    root@OpenWrt:/etc/init.d# ./network restart
    'radio0' is disabled
    'radio0' is disabled
    'radio0' is disabled
    'radio0' is disabled
    root@OpenWrt:/etc/init.d# cd /
    root@OpenWrt:/# dir
    /bin/ash: dir: not found
    root@OpenWrt:/# ls
    bin      dev      etc      lib      mnt      overlay  proc     rom      root     sbin     sys      tmp      usr      var      www
    root@OpenWrt:/# opkg update
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/Packages.gz.
    Updated list of available packages in /var/opkg-lists/barrier_breaker.
    root@OpenWrt:/# opkg install luci
    Installing luci (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci_svn-r9868-1_ar71xx.ipk.
    Installing uhttpd (2013-06-01-87c52f8461fa74733572f4efc53bc30a64ca8575) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/uhttpd_2013-06-01-87c52f8461fa74733572f4efc53bc30a64ca8575_ar71xx.ipk.
    Installing uhttpd-mod-ubus (2013-06-01-87c52f8461fa74733572f4efc53bc30a64ca8575) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/uhttpd-mod-ubus_2013-06-01-87c52f8461fa74733572f4efc53bc30a64ca8575_ar71xx.ipk.
    Installing luci-mod-admin-full (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-mod-admin-full_svn-r9868-1_ar71xx.ipk.
    Installing luci-mod-admin-core (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-mod-admin-core_svn-r9868-1_ar71xx.ipk.
    Installing luci-lib-web (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-lib-web_svn-r9868-1_ar71xx.ipk.
    Installing luci-lib-core (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-lib-core_svn-r9868-1_ar71xx.ipk.
    Installing lua (5.1.5-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/lua_5.1.5-1_ar71xx.ipk.
    Installing liblua (5.1.5-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/liblua_5.1.5-1_ar71xx.ipk.
    Installing libuci-lua (2013-06-11.1-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/libuci-lua_2013-06-11.1-1_ar71xx.ipk.
    Installing libubus-lua (2013-05-30-f72dca720bb50d45b1b01bab5b01cb80c78c5230) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/libubus-lua_2013-05-30-f72dca720bb50d45b1b01bab5b01cb80c78c5230_ar71xx.ipk.
    Installing luci-lib-sys (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-lib-sys_svn-r9868-1_ar71xx.ipk.
    Installing luci-lib-nixio (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-lib-nixio_svn-r9868-1_ar71xx.ipk.
    Installing luci-sgi-cgi (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-sgi-cgi_svn-r9868-1_ar71xx.ipk.
    Installing luci-proto-core (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-proto-core_svn-r9868-1_ar71xx.ipk.
    Installing luci-i18n-english (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-i18n-english_svn-r9868-1_ar71xx.ipk.
    Installing luci-lib-ipkg (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-lib-ipkg_svn-r9868-1_ar71xx.ipk.
    Installing luci-theme-bootstrap (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-theme-bootstrap_svn-r9868-1_ar71xx.ipk.
    Installing luci-theme-base (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-theme-base_svn-r9868-1_ar71xx.ipk.
    Installing luci-app-firewall (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-app-firewall_svn-r9868-1_ar71xx.ipk.
    Installing luci-proto-ppp (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-proto-ppp_svn-r9868-1_ar71xx.ipk.
    Installing libiwinfo-lua (46) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/libiwinfo-lua_46_ar71xx.ipk.
    Installing libiwinfo (46) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/libiwinfo_46_ar71xx.ipk.
    Configuring luci-lib-sys.
    Configuring liblua.
    Configuring libuci-lua.
    Configuring lua.
    Configuring libubus-lua.
    Configuring luci-lib-core.
    Configuring luci-lib-nixio.
    Configuring luci-sgi-cgi.
    Configuring luci-lib-web.
    Configuring luci-proto-core.
    Configuring luci-i18n-english.
    Configuring luci-mod-admin-core.
    Configuring libiwinfo.
    Configuring libiwinfo-lua.
    Configuring luci-theme-base.
    Configuring luci-theme-bootstrap.
    Configuring luci-app-firewall.
    Configuring luci-lib-ipkg.
    Configuring luci-proto-ppp.
    Configuring luci-mod-admin-full.
    Configuring uhttpd.
    Configuring uhttpd-mod-ubus.
    Configuring luci.
    root@OpenWrt:/# opkg install luci-i18n-chinese
    Installing luci-i18n-chinese (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-i18n-chinese_svn-r9868-1_ar71xx.ipk.
    Configuring luci-i18n-chinese.
    root@OpenWrt:/# opkg intall luci-app-multiwan
    opkg: unknown sub-command intall
    usage: opkg [options...] sub-command [arguments...]
    where sub-command is one of:
    Package Manipulation:
            update                  Update list of available packages
            upgrade <pkgs>          Upgrade packages
            install <pkgs>          Install package(s)
            configure <pkgs>        Configure unpacked package(s)
            remove <pkgs|regexp>    Remove package(s)
            flag <flag> <pkgs>      Flag package(s)
             <flag>=hold|noprune|user|ok|installed|unpacked (one per invocation)
     
    Informational Commands:
            list                    List available packages
            list-installed          List installed packages
            list-upgradable         List installed and upgradable packages
            list-changed-conffiles  List user modified configuration files
            files <pkg>             List files belonging to <pkg>
            search <file|regexp>    List package providing <file>
            find <regexp>           List packages whose name or description matches <regexp>
            info [pkg|regexp]       Display all info for <pkg>
            status [pkg|regexp]     Display all status for <pkg>
            download <pkg>          Download <pkg> to current directory
            compare-versions <v1> <op> <v2>
                                compare versions using <= < > >= = << >>
            print-architecture      List installable package architectures
            depends [-A] [pkgname|pat]+
            whatdepends [-A] [pkgname|pat]+
            whatdependsrec [-A] [pkgname|pat]+
            whatrecommends[-A] [pkgname|pat]+
            whatsuggests[-A] [pkgname|pat]+
            whatprovides [-A] [pkgname|pat]+
            whatconflicts [-A] [pkgname|pat]+
            whatreplaces [-A] [pkgname|pat]+
     
    Options:
            -A                      Query all packages not just those installed
            -V[<level>]             Set verbosity level to <level>.
            --verbosity[=<level>]   Verbosity levels:
                                            0 errors only
                                            1 normal messages (default)
                                            2 informative messages
                                            3 debug
                                            4 debug level 2
            -f <conf_file>          Use <conf_file> as the opkg configuration file
            --conf <conf_file>
            --cache <directory>     Use a package cache
            -d <dest_name>          Use <dest_name> as the the root directory for
            --dest <dest_name>      package installation, removal, upgrading.
                                    <dest_name> should be a defined dest name from
                                    the configuration file, (but can also be a
                                    directory name in a pinch).
            -o <dir>                Use <dir> as the root directory for
            --offline-root <dir>    offline installation of packages.
            --add-arch <arch>:<prio>        Register architecture with given priority
            --add-dest <name>:<path>        Register destination with given path
    Force Options:
            --force-depends         Install/remove despite failed dependencies
            --force-maintainer      Overwrite preexisting config files
            --force-reinstall       Reinstall package(s)
            --force-overwrite       Overwrite files from other package(s)
            --force-downgrade       Allow opkg to downgrade packages
            --force-space           Disable free space checks
            --force-postinstall     Run postinstall scripts even in offline mode
            --force-remove  Remove package even if prerm script fails
            --noaction              No action -- test only
            --download-only No action -- download only
            --nodeps                Do not follow dependencies
            --nocase                Perform case insensitive pattern matching
            --force-removal-of-dependent-packages
                                    Remove package and all dependencies
            --autoremove            Remove packages that were installed
                                    automatically to satisfy dependencies
            -t                      Specify tmp-dir.
            --tmp-dir               Specify tmp-dir.
     regexp could be something like 'pkgname*' '*file*' or similar
     e.g. opkg info 'libstd*' or opkg search '*libop*' or opkg remove 'libncur*'
    root@OpenWrt:/# opkg install luci-app-multiwan
    Installing luci-app-multiwan (svn-r9868-1) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/luci-app-multiwan_svn-r9868-1_ar71xx.ipk.
    Installing multiwan (1.0.22-2) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/multiwan_1.0.22-2_ar71xx.ipk.
    Installing ip (3.9.0-3) to root...
    Downloading http://downloads.openwrt.org/snapshots/trunk/ar71xx/packages/ip_3.9.0-3_ar71xx.ipk.
    Installing iptables-mod-conntrack-extra (1.4.19.1-1) to root...
    Configuring ip.
    Configuring multiwan.
    Collected errors:
     * verify_pkg_installable: Only have 4kb available on filesystem /overlay, pkg iptables-mod-conntrack-extra needs 8
     * opkg_install_cmd: Cannot install package luci-app-multiwan.
    root@OpenWrt:/# /etc/init.d/uhttpd enable
    ln: /etc/rc.d/S50uhttpd: No space left on device
    root@OpenWrt:/# cd /etc/init.d
    root@OpenWrt:/etc/init.d# ls
    6relayd            done               luci_dhcp_migrate  sysntpd
    boot               dropbear           luci_fixtime       telnet
    cron               firewall           multiwan           uhttpd
    defconfig          led                network            umount
    dnsmasq            log                sysctl             usb
    root@OpenWrt:/etc/init.d# ./uhttpd enable
    ln: /etc/rc.d/S50uhttpd: No space left on device
    root@OpenWrt:/etc/init.d# ./uhttpd start
    root@OpenWrt:/etc/init.d# exit


安装相应的软件包实现科学上网、突破校园网共享、搭建ipv6，甚至可以通过多线多拨实现网速叠加。


U-Boot/Breed是系统引导加载器，俗称“刷不死”，因为在U-Boot或Breed下刷机安全性很高，不容易变砖，所以大多路由器玩家在**正式搭载**OpenWrt之前都会先刷入一个U-Boot或Breed。但是需要说明的是U-Boot和Breed并不是同一个东西



## Breed
BIOS、UEFI、GRUB、RedBoot、U-Boot、CFE、Breed 等都是 Bootloader。

“不死”指的是所有固件更新操作均在 Breed 里面完成

有些官方升级固件自带 Bootloader，如果从官方固件的 Web 进行升级，那么会导致 Breed 被覆盖。


Breed 在刷入固件时会自动去掉固件自带的 Bootloader，因此能够保证 Breed 本身是“不死”的

Breed 不支持启动非 Linux 类型的固件


Breed 拥有以下新特性：

    实时刷机进度，进度条能准确反映刷机进度
    Web 页面快速响应
    最大固件备份速度，依 Flash 而定，一般能达到 1MB/s
    免按复位键进入 Web 刷机模式
    Telnet 功能，免 TTL 进入 Breed 命令控制台
    复位键定义测试功能
    固件启动失败自动进入 Web 刷机模式
    可自定义位置和大小的环境变量块


[免按复位键进入 Web 刷机模式]
通过一个 Breed Enter 工具实现 (需要 Npcap 支持)
https://github.com/nmap/npcap/releases/download/v0.10-r7/npcap-0.10-r7.exe 下载 Npcap，安装时 WinPcap 兼容模式


确保路由与电脑通过网线相连

1. 启动 BreedEnter.exe

2. 路由断电再通电


3. 如果程序界面提示如下即表明已进入 Web 刷机模式





[修改串口波特率]

    进入 Breed 命令控制台
    执行命令 setbrg <波特率> 即可
    重启生效




[刷入方式]
跟 U-Boot 相同的刷入方法：

    从 PandoraBox U-Boot 中刷入
    在固件中使用 mtd 命令刷入
    在 U-Boot TTL 中刷入
    用编程器刷入

 AR/QCA 芯片从 U-Boot 更新到 Breed 后请一定记得检查 MAC 地址是否有效，如果全部是FF，请自行修改！！



Breed

https://www.right.com.cn/forum/thread-161906-1-1.html


https://www.right.com.cn/forum/thread-161906-1-1.html

Breed 命令控制台说明

Breed 内置了命令解释器，可以实现刷机等操作

[进入 Breed 命令控制台的方法]

    通过串口 (TTL)，在启动提示 Press any key to interrupt autoboot ... 时按任意键中断启动即进入 Breed 命令控制台
    通过开机按复位键或 BreedEnter.exe 方法中断 Breed，即可通过 telnet 方法进入 Breed 命令控制台 (CMD 中 telnet 192.168.1.1 即可)
    请使用 Windows 自带的 telnet 客户端或者 PuTTY，linux 下的 telnet 客户端兼容不好




[Breed 命令控制台功能说明]

    vt100 控制台兼容
    支持 10 条历史命令，上下键调出
    每条命令最长支持 1024 个字符
    左右键、Home/End 键移动光标，可以插入和删除字符



Breed 内置命令介绍

[abstatus]
语法：abstatus
作用：显示自动启动被中断的原因

[arp]
语法：arp
作用：显示当前 ARP 表

[boot]
语法：boot mem <addr>
          boot flash [bank <n>] <addr>
          boot linux <addr>
          boot raw <addr>
          boot breed <addr>
参数：<addr> - 启动地址
          <n> - Flash bank 号
说明：启动固件。
          boot mem 从内存地址启动固件；
          boot flash 从 Flash 启动固件，bank 号可选，默认为 0；
          boot linux 将 <addr> 视作 Linux 内核入口地址，并启动；
          boot raw 禁用中断，并从 <addr> 处执行；
          boot breed 将 <addr> 视作上传的 Breed bin 文件地址，并直接启动。

[btntst]
语法：btntst
          btntst enable <n>
          btntst disable <n>
          btntst restore
参数：<n> - GPIO 号
说明：测试 GPIO 按钮
          btntst enable - 启用对 GPIO#n 的状态检测
          btntst disable - 禁用对 GPIO#n 的状态检测
          btntst restore - 恢复默认检测设置

[dhcp]
语法：dhcp
          dhcp [enable|disable]
说明：显示当前的 DHCP 租约
          dhcp enable 开启 DHCP 服务
          dhcp disable 关闭 DHCP 服务
          改动不会保存，重启后恢复默认 DHCP 开启状态

[env]
语法：env
          env list
          env get <key>
          env set <key> <value>
          env unset <key>
          env clear
          env save
参数：
          <key> 环境变量名
          <value> 环境变量数据
说明：管理环境变量
          必须使用 envconf 启用环境变量后才能使用此命令
          修改环境变量后必须保存
          env list 列出所有环境变量，显示总空间和空闲空间
          env get 获取名称为 <key> 的环境变量的值
          env set 设置环境变量 <key> 的值为 <value>，不存在则新建
          env unset 删除名称为 <key> 的环境变量及其值
          env clear 清除所有环境变量
          env save 保存环境变量

[envconf]
语法：envconf
          envconf disable
          envconf <addr> <size>
参数：
          <addr> 环境变量在 Flash 中的存储位置，起始为 0
          <size> 环境变量大小，不能小于 0x100 字节
说明：启用或禁用环境变量
          envconf disable 禁用环境变量功能
          指定 <addr> 和 <size> 则启用环境变量
注意：部分型号的 Breed 使用固定的环境变量设置，因此此命令不可用

[exit]
语法：exit
说明：退出 telnet 模式

[flash]
语法：flash list
          flash [bank <n>] info
          flash [bank <n>] dump <addr> <size>
          flash [bank <n>] read <addr> <dst> <size>
          flash [bank <n>] erase <addr> <size>
          flash [bank <n>] write <addr> <src> <size>
参数：<n> - Flash bank 号
           <addr> - Flash 地址
           <size> - 读取/擦除/写入数据大小
           <src> - 要写入 Flash 的数据内存地址
           <dst> - 要存放读取的 Flash 数据的内存地址
说明：flash list 列出所有 Flash
          flash info 显示 Flash 的详细信息
          flash dump 显示 Flash 内的数据
          flash read 将 Flash 内的数据读取到内存
          flash erase 擦除 Flash
          flash write 将内存数据写入到 Flash

[gpio]
语法：gpio [status|list]
          gpio button
          gpio led
          gpio get <n>
          gpio set <n> <hi|lo>
          gpio dir set <n> <in|out>
          gpio led set <name> <on|off>
参数： [status] - 列出所有 GPIO 及其状态
           <n> - GPIO 号
           <hi> <lo> - 高/低电平
           <in> <out> - GPIO 方向为输入/输出
           <name> - LED 名称
           <on> <off> - LED 亮/灭
说明：gpio [status|list] 列出所有 GPIO 及其状态
           gpio button 显示当前路由上按钮的状态
           gpio led 显示当前路由上部分 LED 的状态
           gpio get 获取指定 GPIO 的电平状态
           gpio set 设置指定 GPIO 的电平状态
           gpio dir set 设置指定 GPIO 的方向
           gpio led set 设置 LED 的亮灭

[help]
语法：help
说明：列出所有可用的命令

[mem]
语法：mem dump [keep] <start_addr> [size]
          mem crc32 <addr> <size>
          mem read [byte|short|long] <addr>
          mem write [byte|short|long] <addr> <value>
          mem write str <addr> <str>
          mem copy <dst> <src> <size>
          mem fill <dst> <val> <size>
          mem compare <addr1> <addr2> <size>
参数：[keep] - 保持原始字节序
          <start_addr> <addr> <addr1> <addr2> - 起始地址
          <size> [size] - 显示/计算的数据大小
          [byte] [short] [long] - 指定操作数大小，分别为 1字节、2字节、4字节
          <value> - 要写入的值
          <str> - 要写入的字符串，支持 C 语言类型的编码
说明：mem dump 显示内存数据，可指定要显示的字节数，keep 表示保存原始字节序，否则输出时将转换为 CPU 字节序。
          mem crc32 计算内存数据的 CRC32 校验
          mem read 读取内存某个地址的数值
          mem write 修改内存某个地址的数值
          mem write str 将字符串写入某个内存地址
          mem copy 复制内存块
          mem fill 填充内存块
          mem compare 比较内存块

[mdio]
语法：mdio list
          mdio <dev> dump <phy>
          mdio <dev> read <phy> <reg>
          mdio <dev> write <phy> <reg> <val>
参数：<dev> - 设备名
          <phy> - PHY 号
          <reg> - 寄存器
          <val> - 数值
说明：mdio list 列出网络接口设备
          mdio dump 转储指定接口的 MII 寄存器 (0 ~ 31)
          mdio read 读取指定接口的 MII 寄存器
          mdio write 修改指定接口的 MII 寄存器

[net]
语法：net [start|stop]
说明：net start 启动网络服务
          net stop 停止网络服务，并关闭所有网络连接

[netstat]
语法：netstat
说明：显示当前活动的网络连接

[reset]
语法：reset
说明：重启路由

[setbrg]
语法：setbrg <val>
参数：<val> - 波特率
作用：设置 Breed 串口输出的波特率，一直生效

[spi]
语法：spi list
          spi [dev <slave>] <op> [<op> [<op> ...]]
参数：<slave> - SPI 设备名
          <op> - 一个操作
操作类型：
          start          开始一次 SPI 传输，即拉低 CS 电平
          stop          结束 SPI 传输，即拉高 CS 电平
          read <addr> <size>          读取数据到内存
          read display <size>          读取数据并直接显示为十六进制格式
          write <addr> <size>          将内存地址中的数据写入
          write str <str>          将 <str> 字符串写入
          speed <speed_str>           设置 SPI 总线频率。默认单位为 Hz，可以增加后缀k/m表示KHz/MHz
说明：spi list 列出所有 SPI 设备
          spi 命令后面可以跟多个操作，如：
          spi start write "\x9f" read display 3 stop

[sysinfo]
语法：sysinfo
说明：显示系统信息

[thread]
语法：thread
说明：列出所有线程信息

[wget]
语法：wget [addr] <url>
参数：[addr] - 要存放数据的内存地址，可忽略
          <url> - 要请求文件数据的 HTTP 链接
说明：通过 HTTP 协议加载文件到内存。URL 里只能使用 IP 地址。


TTL 刷机说明

首先请参考帖子 U-Boot 刷机方法大全 用 HFS 搭建 HTTP 文件服务器

1. 传输文件：
执行命令 wget http://<电脑 IP 地址>/<文件名>





记录下 Saving to address 后面的内存地址和 Length: 后面 0x 开头的数据大小
这里内存地址是 0x80000000，数据大小是 0x800000

2. 擦除 Flash：

请根据实际情况确定擦除地址和大小

执行命令 flash erase <起始地址> <擦除大小>




3. 写入数据：

执行命令 flash write <Flash 地址> <内存地址> <数据大小>
<内存地址> 即为第一步中记录的地址




复位键测试说明

首先用 4 楼的方法进入 Breed 命令控制台

然后执行命令 btntst

然后就可以按路由器上的按钮。每按下按钮或放开按钮时，都会有一行输出



其中第一列 GPIO# 后面的数据即是当前按钮的 GPIO 号
第二列是用于 OpenWrt dts 文件中的 GPIO 定义
最后是 GPIO 状态

如果按下按钮，提示 GPIO 状态为 0，松开，状态为 1，说明此按钮时低电平活动的 (active-low)，反之则是高电平活动 (active-high)


如果运行 btntst 命令后出现某 GPIO 电平变化持续输出的情况，可以先执行命令
btntst disable <n>
<n> 为持续变化的 GPIO 号
然后再执行 btntst 命令，这样就能忽略检测 GPIO <n> 的状态

btntst enable <n>
恢复检测 GPIO <n> 的状态

btntst restore
恢复初始 GPIO 状态检测设置 (重启后也就恢复了)



环境变量说明

Breed 中的环境变量需要先进行设置后方能使用
但是注意：部分型号的 Breed 和 NAND 启动的 Breed，使用固定设置的环境变量，因此没有环境变量设置页面和 envconf 命令！
以及 WDR6500v2 的 Breed 因为体积原因不支持环境变量！
判断一个 Breed 是否支持环境变量，请直接观察 Breed Web 恢复控制台中是否存在 “环境变量编辑” 页面，或在 Breed 命令行中执行 env 命令，若 “环境变量编辑” 页面 或 env 命令存在，则表明此 Breed 支持环境变量！

Breed Web 恢复控制台中有环境变量设置页面，请根据页面中的提示进行设置



Breed Web 恢复控制台中有环境变量编辑器：


环境变量也可以使用命令进行修改

可以设置的环境变量：

network.ipaddr
        Breed 的 IP 地址
        示例：env set network.ipaddr 192.168.1.1

network.netmask
        Breed 的子网掩码
        示例：env set network.netmask 255.255.255.0

network.dhcpd.disabled
        禁用 DHCP 服务器。设为 1 禁用，其它值则启用
        示例：env set network.dhcpd.disabled 0

network.autoneg.timeout
        以太网 PHY 自动协商等待时间，范围  0 - 10，0 表示不等待
        示例：env set network.autoneg.timeout 5

sys.led_blink.disabled
        禁用 SYS LED Heartbeat 闪烁。设为 1 禁用，其它值则启用
        示例：env set sys.led_blink.disabled 0

autoboot.disabled
        禁用自动启动，不启动固件，直接进入 Breed 命令行/刷机模式。设为 1 禁用，其它值则启用
        示例：env set autoboot.disabled 1

autoboot.delay
        自动启动等待时间，必须大于 0
        示例：env set autoboot.delay 5

autoboot.command
        自动启动命令，可以包含多个命令，使用半角分号 ; 分开
        示例：env set autoboot.command "boot mem 0x9f020000"

linux.cmdline
        Linux 内核命令行
        示例：env set linux.cmdline "console=ttyS0,115200 root=31:02 rootfstype=squashfs,jffs2 init=/sbin/init"
        如果要使用 autoboot 命令，需要执行 env unset linux.cmdline 禁用自定义内核命令行

linux.initrd.start
        initrd 起始地址
        示例：env set linux.initrd.start 0x80400000

linux.initrd.size
        initrd 大小
        示例：env set linux.initrd.size 0x500000

gpio.customized.reset
        指定一个自定义复位键配置（仅对少数特殊版本的 Breed 有效）
        说明：数据格式为 数字+活动状态。数字为 GPIO 编号，有效 GPIO 号请执行 gpio 命令查看。
        　　　活动状态为一个字母，不区分大小写，L 表示低电平有效 (active-low)，H 表示高电平有效 (active-high)
        示例：env set gpio.customized.reset 11L


如果要恢复某设置的默认设置，执行 env unset 删除对应环境变量名即可

修改后请务必保存！！！


自定义复位键说明

仅针对文件名是 -blank 结尾的文件有效
此类文件不包含任何 GPIO 配置，因此在首次刷入时不能通过按复位键中断启动。
此类 Breed 也因此不支持自定义超频功能。
使用方法是：
首先通过 BreedEnter 中断启动，或者直接通过串口中断启动
然后通过 Breed Web 开启环境变量支持
最后通过设置环境变量设置有效的复位键，并保存
环境变量设置请参考上面的说明


小米 Mini 固件启动设置

进入 Breed 恢复控制台

进入 固件启动设置 页面



将固件类型选择为 小米 Mini 保存即可。

然后就可以完美启动小米 Mini 原厂固件了
而且可以使用串口 (TTL) 登录




>> TP 
打开串口调试工具，给路由器上电可以看到引导信息，在“Autobooting in 1 seconds”之后快速按下tpl，可以进入Uboot的命令行
看到ar7240>
5.在命令行中输入（"ar7240>”及括号部分不要输）
ar7240> setenv ipaddr 192.168.1.1 （此地址为路由器地址）
ar7240> setenv serverip 192.168.1.10（此地址为TFTP服务器即电脑的地址）
printenv （查看当前的环境，核对两个地址是否正确）
6.下一步是将固件拷到路由器内存里
ar7240> tftpboot 0x80000000 openwrt-ar71xx-generic-tl-wr841nd-v7-squashfs-factory.bin
然后等它拷完（非常快）



7.擦写flash
ar7240> erase 0x9f020000 +0x3c0000 （0x9f020000为内核的启动地址，在开机的引导信息中可以看到，见 840N的U-boot32行“## Booting image at 9f020000 ...”，
0x3c0000为固件大小，这个输错了路由器会变砖，上一步返回信息的最后一句会给出）
等待擦除
ar7240> cp.b 0x80000000 0x9f020000 0x3c0000
ar7240> bootm 0x9f020000
之后，系统就开始重新启动了，将计算机网线接入 LAN口，广域网网线接入WAN，可以上网啦。
输入192.168.1.1，没有密码，login以后再设 


