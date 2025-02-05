---
#layout: page
layout: base
title: pica8.com
---


---------- Forwarded message ---------
From: "Sasikumar Puthiyaveedu" <Sasikumar.puthiyaveedu@pica8.com>
Date: Wed, Feb 5, 2025, 06:18
Subject: Re: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total
To: "徐光宇"<jackie.xu@feisu.com>
Cc: "Don DeRisi"<don.derisi@pica8.com>, "Iris Rong"<iris.rong@pica8.com>, "vic.lan@feisu.com"<vic.lan@feisu.com>, "Angela Hung"<angela.hung@pica8.com>, "唐德军"<mikel.tang@feisu.com>, "Iris.rong@feisu.com"<iris.rong@feisu.com>, "尹娜"<vivien.yin@feisu.com>, "Zoneson Chen"<zoneson.chen@pica8.com>, "Mikel Tang"<mikel.tang@pica8.com>, "杜林"<lin.du@feisu.com>, "窦博森"<benson.dou@feisu.com>
Hi Jackie,
Thank you very much. Image working good.
Initially I couldn’t upgrade from 4.2.3.11 to 4.2.3.12 .  I was trying from switch which is already in a troubled state.
Here is that detail.
admin@vz-poe4610> show ver
Copyright (C) 2009-2024 Pica8, Inc.
===================================
Base ethernet MAC Address     : 3c:2c:99:e9:87:41
Hardware Model                : AS4610_54P
Linux System Version/Revision : 4.2.3.11/bca1de2648
Linux System Released Date    : 10/16/2024
L2/L3 Version/Revision        : 4.2.3.11/bca1de2648
L2/L3 Released Date           : 10/16/2024
 
admin@vz-poe4610> upgrade2 image-file /cftmp/onie-installer-picos-4.2.3.12-761d282c5a-as4610.bin
Verifying image checksum ... OK.
Preparing image archive ... OK.
Checking prerequisites
       Hardware compatibility (as4610)                        [OK]
       Configuration file (/pica/config/pica_startup.boot)    [OK]
       License                                                [OK]
       Tools (gdisk/partprobe)                                [OK]
       Partition type (GPT)                                   [OK]
       UBOOT environment check                                [OK]
       Boot option (PICOS-4.2.3.11)                           [OK]
       Partition label (PicOS2)                               [OK]
Preparing partition(s)
       Found partition /dev/sda2 (2048MB)                     [OK]
       Installing new image on /dev/sda2 [Y/n]?y
       Format partition /dev/sda2 (EXT3/EXT4)                 [OK]
Stopping PICOS
Extracting image
       Mount /dev/sda2                                        [OK]
       Extract files, taking about 3 minutes                  [/][  663.558350] picos.sh[3831]: .
                                                              [\]/tmp/tmp.D0AgAOWM57/installer/upgrade-functions: line 1481:  3786 Aborted                 (core dumped) tar -zxf $NAME -C $mnt > /dev/null 2> $file
                                                              [/]                  [FAILED]
Error: Extract /cftmp//tmp/tmp.D0AgAOWM57/installer/rootfs.tar.gz failed(free(): invalid next size (fast))!
admin@vz-poe4610> admin@vz-poe4610:~$ [  886.829857] picos.sh[5487]: .
 
admin@vz-poe4610:~$ version
Copyright (C) 2009-2024 Pica8, Inc.
===================================
Hardware Model                : AS4610_54P
Linux System Version/Revision : 4.2.3.11/bca1de2648
Linux System Released Date    : 10/16/2024
L2/L3 Version/Revision        : 4.2.3.11/bca1de2648
L2/L3 Released Date           : 10/16/2024
OVS/OF Version/Revision       : 4.2.3.11/bca1de2648
OVS/OF Released Date          : 10/16/2024
 
admin@vz-poe4610:~$ cd /pica/core/
admin@vz-poe4610:/pica/core$ ls
core.bcmINTR.pid_4085.uid_0.sig_6  core.tar.pid_3786.uid_0.sig_6
admin@vz-poe4610:/pica/core$ ls -ltr
total 108332
-rw------- 1 root root 175251456 Feb  4 18:20 core.bcmINTR.pid_4085.uid_0.sig_6
-rw------- 1 root xorp   1036288 Feb  4 18:20 core.tar.pid_3786.uid_0.sig_6
admin@vz-poe4610:/pica/core$ cd /cftmp/
admin@vz-poe4610:/cftmp$ 
 
 
AFTER REMOVING TWO PHONES and POWER OFF ON
 
===================================
admin@vz-poe4610> show ver
Copyright (C) 2009-2024 Pica8, Inc.
===================================
Base ethernet MAC Address     : 3c:2c:99:e9:87:41
Hardware Model                : AS4610_54P
Linux System Version/Revision : 4.2.3.11/bca1de2648
Linux System Released Date    : 10/16/2024
L2/L3 Version/Revision        : 4.2.3.11/bca1de2648
L2/L3 Released Date           : 10/16/2024
 
admin@vz-poe4610> upgrade2 image-file fl
Possible completions:
  <image-name>                    Image with bin format file(*.bin)
admin@vz-poe4610> start shell sh
admin@vz-poe4610:~$ df -k
Filesystem     1K-blocks   Used Available Use% Mounted on
udev             1005584      0   1005584   0% /dev
tmpfs             204860   8036    196824   4% /run
/dev/sda3        1998672 942152    951664  50% /
tmpfs            1024284      0   1024284   0% /dev/shm
tmpfs               5120      0      5120   0% /run/lock
tmpfs            1024284      0   1024284   0% /sys/fs/cgroup
tmpfs              51200    536     50664   2% /tmp
/dev/sda4        3283684   5888   3107660   1% /udata
admin@vz-poe4610:~$
admin@vz-poe4610:~$ cd /pica/core
admin@vz-poe4610:/pica/core$ ls -ltr
total 207492
-rw------- 1 root root 175251456 Feb  4 18:20 core.bcmINTR.pid_4085.uid_0.sig_6
-rw------- 1 root xorp   1036288 Feb  4 18:20 core.tar.pid_3786.uid_0.sig_6
-rw------- 1 root xorp 159514624 Feb  4 18:41 pica8@1
admin@vz-poe4610:/pica/core$
admin@vz-poe4610:/pica/core$ sudo rim core.bcmINTR.pid_4085.uid_0.sig_6
sudo: rim: command not found
admin@vz-poe4610:/pica/core$ sudo rm core.bcmINTR.pid_4085.uid_0.sig_6
admin@vz-poe4610:/pica/core$ sudo rm core.tar.pid_3786.uid_0.sig_6
admin@vz-poe4610:/pica/core$
admin@vz-poe4610:/pica/core$ cli
Synchronizing configuration...OK.
Welcome to PICOS on vz-poe4610
admin@vz-poe4610> 
admin@vz-poe4610> upgrade2 image-file /cft
Possible completions:
  <image-name>                    Image with bin format file(*.bin)
admin@vz-poe4610> upgrade2 image-file /cftmp/onie-installer-picos-4.2.3.12-761d282c5a-as4610.bin
Verifying image checksum ... OK.
Preparing image archive ... OK.
Checking prerequisites
       Hardware compatibility (as4610)                        [OK]
       Configuration file (/pica/config/pica_startup.boot)    [OK]
       License                                                [OK]
       Tools (gdisk/partprobe)                                [OK]
       Partition type (GPT)                                   [OK]
       UBOOT environment check                                [OK]
       Boot option (PICOS-4.2.3.11)                           [OK]
       Partition label (PicOS2)                               [OK]
Preparing partition(s)
       Found partition /dev/sda2 (2048MB)                     [OK]
       Installing new image on /dev/sda2 [Y/n]?y
       Format partition /dev/sda2 (EXT3/EXT4)                 [OK]
Stopping PICOS
Extracting image
       Mount /dev/sda2                                        [OK]
       Extract files, taking about 3 minutes                  [OK]
       Copy configuration files from /dev/sda3 to /dev/sda2   [OK]
Updating default boot option
       Modify default boot option to PICOS-4.2.3.12           [OK]
PICOS-4.2.3.12 upgrade successful!
Please find log at /cftmp/upgrade2.log!
Rebooting the system to enter PICOS-4.2.3.12!
PRESS SPACE KEY TO STOP REBOOT
Countdown: 10 9 8 7 6 5 4 3 2 1 ...
Rebooting...
admin@vz-poe4610> admin@vz-poe4610:/pica/core$ [  701.784278] picos_monitor[4892]: Stopping monitor
[  708.971237] reboot: Restarting system
 
 
U-Boot 2012.10-gd563f4a (Apr 13 2017 - 12:08:06) - 2012.10.0.5
 
DCO:   28 (PASS)
Device:Helix4 (0xdc14)
SKU:   BCM56340 (0xb340)
DRAM:  DDR3, 750MHz
       Validate DDR shmoo parameters stored in flash ..... OK
       Press Ctrl-C to run DDR shmoo ..... skipped
       Restoring DDR shmoo parameters from flash ..... done
       Running simple memory test ..... OK
       Enabling DDR ECC reporting
       Enabling DDR ECC correction
       DDR Interface Ready
DRAM:  2 GiB
WARNING: Caches not enabled
SF:    MX25L6405D with page size 4 KiB, total 8 MiB
EEPROM:TlvInfo v1 len=160
In:    serial
Out:   serial
Err:   serial
CLOCKS:ARM Core=1000Hz, AXI=500Hz, APB=125Hz, Peripheral=500Hz
USB0:  Bringing USB2 host out of reset...
Net:   eth-0
Hit any key to stop autoboot:  0 
(Re)start USB...
USB:   Bringing USB2 host out of reset...
usb2_reset_state is: 00000000
Register 1212 NbrPorts 2
USB EHCI 1.00
scanning bus for devices... 3 USB Device(s) found
       scanning bus for storage devices... 1 Storage Device(s) found
Loading file "boot/uImage.itb" from usb device 0:2
...9144732 bytes read
## Booting kernel from FIT Image at 70000000 ...
   Using '4610' configuration
   Trying 'kernel@1' kernel subimage
     Description:  ARM Kernel
     Type:         Kernel Image
     Compression:  gzip compressed
     Data Start:   0x700000d0
     Data Size:    5426669 Bytes = 5.2 MiB
     Architecture: ARM
     OS:           Linux
     Load Address: 0x61008000
     Entry Point:  0x61008000
     Hash algo:    crc32
     Hash value:   8fff7266
   Verifying Hash Integrity ... crc32+ OK
## Loading init Ramdisk from FIT Image at 70000000 ...
   Using '4610' configuration
   Trying 'ramdisk@1' ramdisk subimage
     Description:  ramdisk
     Type:         RAMDisk Image
     Compression:  uncompressed
     Data Start:   0x705328e0
     Data Size:    3693000 Bytes = 3.5 MiB
     Architecture: ARM
     OS:           Linux
     Load Address: 0x00000000
     Entry Point:  0x00000000
     Hash algo:    crc32
     Hash value:   be677e15
   Verifying Hash Integrity ... crc32+ OK
## Flattened Device Tree from FIT Image at 70000000
   Using '4610' configuration
   Trying 'dtb@as4610' FDT blob subimage
     Description:  AS4610 dtb
     Type:         Flat Device Tree
     Compression:  uncompressed
     Data Start:   0x7052cf98
     Data Size:    7761 Bytes = 7.6 KiB
     Architecture: ARM
     Hash algo:    crc32
     Hash value:   2b1d4a4d
   Verifying Hash Integrity ... crc32+ OK
   Booting using the fdt blob at 0x7052cf98
   Uncompressing Kernel Image ... OK
boot_prep_linux commandline: root=LABEL=PicOS rw fsck.mode=force fsckfix quiet console=ttyS0,115200
   Loading Device Tree to 64ffb000, end 64fffe50 ... OK
 
Starting kernel ...
 
Loading, please wait...
[    4.274884] sd 0:0:0:0: [sda] No Caching mode page found
[    4.280242] sd 0:0:0:0: [sda] Assuming drive cache: write through
[   40.014566] picos-pre.sh[276]: call /usr/sbin/convert-config-upgrade
[   40.279478] picos-pre.sh[276]: [*]Input Filename is /pica/config/pica_startup.boot
[   40.319747] picos-pre.sh[276]: [*]Output Filename is /pica/config/pica_startup.boot
[   44.509984] picos-pre.sh[276]: call /usr/sbin/config_encode_base64.py
[   53.961076] picos-pre.sh[276]: Auto Provisioning Tool - checking updates ....
[   55.033598] picos-pre.sh[276]: No tftp server address found, exit now
[   55.221682] picos_monitor[627]: Starting monitor
[   58.500101] system-diag[628]: ************ System Diagnosis Start ************
Date: Tue Feb 19 06:32:26 UTC 2019
[   58.579465] system-diag[628]: Version:
[   58.609461] system-diag[628]:   Copyright (C) 2009-2025 Pica8, Inc.
[   58.649501] system-diag[628]:   ===================================
[   58.689463] system-diag[628]:   Hardware Model                : AS4610_54P
[   58.729522] system-diag[628]:   Linux System Version/Revision : 4.2.3.12/761d282c5a
[   58.769511] system-diag[628]:   Linux System Released Date    : 02/04/2025
[   58.809476] system-diag[628]:   L2/L3 Version/Revision        : 4.2.3.12/761d282c5a
[   58.849581] system-diag[628]:   L2/L3 Released Date           : 02/04/2025
[   58.889445] system-diag[628]:   OVS/OF Version/Revision       : 4.2.3.12/761d282c5a
[   58.929464] system-diag[628]:   OVS/OF Released Date          : 02/04/2025
[   58.969470] system-diag[628]:   ONIE version  : 2016.05.00.04
[   59.009633] system-diag[628]:   CPLD version  : 0x3
[   59.017083] system-diag[628]: Hardware information:
[   59.043209] system-diag[628]:   MAC address   : 3C:2C:99:E9:87:41
[   59.079497] system-diag[628]:   Serial number : EC1826002068
[   59.119474] system-diag[628]:   Product name  : 4610-54P-O-AC-F
[   59.159499] system-diag[628]: PSU:
[   59.189510] system-diag[628]:   PSU 1 status  : present but powered off
[   59.229682] system-diag[628]:   PSU 2 status  : present and powered on
[   59.269518] system-diag[628]: System FAN:
[   59.299523] system-diag[628]:   Fan 1 OK, fan speed is 10200
[   59.339521] system-diag[628]: Temperature:
[   59.369528] system-diag[628]:   CPU temperature             : 44 C / 111 F
[   59.409482] system-diag[628]:   Switch chip temperature     : N/A
[   59.449523] system-diag[628]:   Board temperature    : N/A
[   59.489719] system-diag[628]: Optical modules:
[   59.530718] system-diag[628]:   Port 1 Module type: SFP; Vendor name: CISCO-TRANSPORTO; Serial number: GDT8B4762109
[   59.569656] system-diag[628]:   Port 2 Module type: SFP; Vendor name: CISCO; Serial number: FNS19290AUJ
[   59.609633] system-diag[628]:   Port 3 Module type: SFP; Vendor name: OEM; Serial number: CS102K85425
[   59.649606] system-diag[628]:   Port 4 Module type: SFP; Vendor name: CISCO-TRANSPORTO; Serial number: GDT8B0801293
[   59.689611] system-diag[628]:   Port 5 no module
[   59.729593] system-diag[628]:   Port 6 no module
[   59.769460] system-diag[628]: RTC:
[   59.799454] system-diag[628]:   RTC is OK!
[   59.829520] system-diag[628]:   Time   : 2019-02-19 06:32:27.442838+00:00
[   59.869648] system-diag[628]: Disk space:
[   59.899487] system-diag[628]:   /dev/sda      : 7676 MB
[   59.939471] system-diag[628]:   /dev/sda1     : 256 MB
[   59.979537] system-diag[628]:   /dev/sda2     : 2048 MB     (Rootfs)
[   60.019396] system-diag[628]:   /dev/sda3     : 2048 MB
[   60.059337] system-diag[628]:   /dev/sda4     : 3322 MB
[   60.099376] system-diag[628]:   Free space of rootfs partition is 1312 MB.
[   60.139327] system-diag[628]: Memory size:
[   60.169346] system-diag[628]:   Total memory  : 2048572 KB
[   60.209345] system-diag[628]:   Free memory   : 1892844 KB
[   60.249376] system-diag[628]: CPU utilization: 67.44%
POE module:96] s OKem-diag[628]: POE module:
[   64.179486] system-diag[628]: ************  System Diagnosis End  ************
[  129.194062] picos.sh[634]: .
2019-02-19 06:33:39,802 Auto-deploy WARNING : Auto-deploy Agent Start
 
Debian GNU/Linux 10 vz-poe4610 ttyS0
 
vz-poe4610 login: 2025-02-04 19:07:11,820 Auto-deploy WARNING : Sync time with ntp server pool.ntp.org
2025-02-04 19:07:11,840 Auto-deploy WARNING : Got platform name as4610_54p
2025-02-04 19:07:12,352 Auto-deploy WARNING : Got version number 4.2.3.12
2025-02-04 19:07:12,363 Auto-deploy WARNING : Got serial num EC1826002068
2025-02-04 19:07:12,434 Auto-deploy WARNING : Got hardware id FEBD-9635-60EC-C3CA
2025-02-04 19:07:12,454 Auto-deploy WARNING : Agent Initialized
2025-02-04 19:07:12,471 Auto-deploy WARNING : Modify /etc/bash.bashrc
2025-02-04 19:07:12,490 Auto-deploy WARNING : Try to enable VPN
2025-02-04 19:07:12,495 Auto-deploy WARNING : 
Download URL: https://172.16.0.234:443/management/vpn/EC1826002068/client.conf
2025-02-04 19:07:12,600 Auto-deploy WARNING : 
Download URL: https://172.16.0.234:443/management/vpn/EC1826002068/automation.up
2025-02-04 19:07:12,654 Auto-deploy WARNING : 
Download URL: https://172.16.0.234:443/management/vpn/EC1826002068/update_vpn_ip.sh
2025-02-04 19:07:12,725 Auto-deploy WARNING : 
Download URL: https://172.16.0.234:443/management/vpn/EC1826002068/client.key
2025-02-04 19:07:12,798 Auto-deploy WARNING : 
Download URL: https://172.16.0.234:443/management/vpn/EC1826002068/client.crt
2025-02-04 19:07:12,877 Auto-deploy WARNING : 
Download URL: https://172.16.0.234:443/management/vpn/EC1826002068/ca.crt
2025-02-04 19:07:17,949 Auto-deploy WARNING : 
add execute permission in automation.up
2025-02-04 19:07:17,980 Auto-deploy WARNING : 
Start the openvpn service.
2025-02-04 19:07:42,069 Auto-deploy WARNING : Restore /etc/bash.bashrc
2025-02-04 19:07:42,407 Auto-deploy WARNING : This switch has been already deployed, agent will quit
 
Debian GNU/Linux 10 vz-poe4610 ttyS0
 
vz-poe4610 login: admin
Password: 
Synchronizing configuration...OK.
Welcome to PICOS on vz-poe4610
admin@vz-poe4610> show ver
Copyright (C) 2009-2025 Pica8, Inc.
===================================
Base ethernet MAC Address     : 3c:2c:99:e9:87:41
Hardware Model                : AS4610_54P
Linux System Version/Revision : 4.2.3.12/761d282c5a
Linux System Released Date    : 02/04/2025
L2/L3 Version/Revision        : 4.2.3.12/761d282c5a
L2/L3 Released Date           : 02/04/2025
 
admin@vz-poe4610> show poe power 
Total power allocated  RealTime consumption   Power available  Power Mode      PSU1 Status             PSU2 Status  
---------------------  --------------------   ---------------  ----------      -----------             ------------------
47.90W                 48.10W                 675.00W          redundant       Present but powered off Powered on              
admin@vz-poe4610> show poe interface all
Port       Status     Consume Reserved  Pair PD-Type     PD-Class  Detection-Type
----       ------     ------- --------- ---- -------     --------  ---------------
ge-1/1/1   Delivering 3.80W   3.80W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/2   Delivering 3.70W   3.70W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/3   Delivering 3.80W   3.80W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/4   Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/5   Delivering 3.60W   3.60W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/6   Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/7   Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/8   Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/9   Delivering 3.70W   3.70W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/10  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/11  Delivering 3.50W   3.50W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/12  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/13  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/14  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/15  Delivering 3.90W   3.90W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/16  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/17  Delivering 3.90W   3.90W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/18  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/19  Delivering 3.70W   3.70W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/20  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/21  Delivering 4.00W   4.00W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/22  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/23  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/24  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/25  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/26  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/27  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/28  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/29  Delivering 3.20W   3.20W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/30  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/31  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/32  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/33  Delivering 3.50W   3.50W     A    IEEE        3         IEEE 802.3af 4-Point & Legacy
ge-1/1/34  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/35  Delivering 3.80W   3.80W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/36  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/37  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/38  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/39  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/40  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/41  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/42  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/43  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/44  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/45  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/46  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/47  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/48  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
admin@vz-poe4610> show poe interface all | match Deliv| count
Count: 13 lines
admin@vz-poe4610> run sh in
Not a XORP operational mode command!
admin@vz-poe4610> show interface brief 
Interface       Management  Status  Flow Control  Duplex  Speed    Description
--------------  ----------  ------  ------------  ------  -------  ------------------------------
ge-1/1/1        Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/2        Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/3        Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/4        Enabled     Down    Disabled      Full    Auto     
ge-1/1/5        Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/6        Enabled     Down    Disabled      Full    Auto     
ge-1/1/7        Enabled     Down    Disabled      Full    Auto     
ge-1/1/8        Enabled     Down    Disabled      Full    Auto     
ge-1/1/9        Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/10       Enabled     Down    Disabled      Full    Auto     
ge-1/1/11       Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/12       Enabled     Down    Disabled      Full    Auto     
ge-1/1/13       Enabled     Down    Disabled      Full    Auto     
ge-1/1/14       Enabled     Down    Disabled      Full    Auto     
ge-1/1/15       Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/16       Enabled     Down    Disabled      Full    Auto     
ge-1/1/17       Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/18       Enabled     Down    Disabled      Full    Auto     
ge-1/1/19       Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/20       Enabled     Down    Disabled      Full    Auto     
admin@vz-poe4610> 
admin@vz-poe4610> 
admin@vz-poe4610> 
admin@vz-poe4610> ADDED TWO more phone
                  ^
unknown command.
admin@vz-poe4610>  show poe interface all | match Deliv| count
Count: 15 lines
admin@vz-poe4610> 
admin@vz-poe4610> show poe power 
Total power allocated  RealTime consumption   Power available  Power Mode      PSU1 Status             PSU2 Status  
---------------------  --------------------   ---------------  ----------      -----------             ------------------
55.10W                 55.40W                 675.00W          redundant       Present but powered off Powered on              
admin@vz-poe4610> 
admin@vz-poe4610> show interface brief all
ERROR: no matching command:
show interface brief all
                     ^
admin@vz-poe4610> show interface brief 
Interface       Management  Status  Flow Control  Duplex  Speed    Description
--------------  ----------  ------  ------------  ------  -------  ------------------------------
ge-1/1/1        Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/2        Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/3        Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/4        Enabled     Down    Disabled      Full    Auto     
ge-1/1/5        Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/6        Enabled     Down    Disabled      Full    Auto     
ge-1/1/7        Enabled     Down    Disabled      Full    Auto     
ge-1/1/8        Enabled     Down    Disabled      Full    Auto     
ge-1/1/9        Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/10       Enabled     Down    Disabled      Full    Auto     
ge-1/1/11       Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/12       Enabled     Down    Disabled      Full    Auto     
ge-1/1/13       Enabled     Down    Disabled      Full    Auto     
ge-1/1/14       Enabled     Down    Disabled      Full    Auto     
ge-1/1/15       Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/16       Enabled     Down    Disabled      Full    Auto     
ge-1/1/17       Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/18       Enabled     Down    Disabled      Full    Auto     
ge-1/1/19       Enabled     Up      Disabled      Full    1Gb/s    
ge-1/1/20       Enabled     Down    Disabled      Full    Auto     
admin@vz-poe4610> show po
Possible completions:
   poe                            Display information about POE
   policer                        Show policers
   port-security                  Show secure port information
admin@vz-poe4610> show poe interface all
Possible completions:
  <interface>                     Show information about the specified interface
  all                             Show information about the specified interface
admin@vz-poe4610> show poe interface all 
Port       Status     Consume Reserved  Pair PD-Type     PD-Class  Detection-Type
----       ------     ------- --------- ---- -------     --------  ---------------
ge-1/1/1   Delivering 3.80W   3.80W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/2   Delivering 3.70W   3.70W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/3   Delivering 3.80W   3.80W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/4   Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/5   Delivering 3.50W   3.50W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/6   Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/7   Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/8   Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/9   Delivering 3.60W   3.60W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/10  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/11  Delivering 3.40W   3.40W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/12  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/13  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/14  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/15  Delivering 4.00W   4.00W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/16  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/17  Delivering 3.90W   3.90W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/18  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/19  Delivering 3.60W   3.60W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/20  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/21  Delivering 3.90W   3.90W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/22  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/23  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/24  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/25  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/26  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/27  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/28  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/29  Delivering 3.40W   3.40W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/30  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/31  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/32  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/33  Delivering 3.50W   3.50W     A    IEEE        3         IEEE 802.3af 4-Point & Legacy
ge-1/1/34  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/35  Delivering 3.90W   3.90W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/36  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/37  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/38  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/39  Delivering 3.90W   3.90W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/40  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/41  Delivering 3.30W   3.30W     A    IEEE        2         IEEE 802.3af 4-Point & Legacy
ge-1/1/42  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/43  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/44  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/45  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/46  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/47  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
ge-1/1/48  Searching  0.00W   0.00W     A    None        None      IEEE 802.3af 4-Point & Legacy
admin@vz-poe4610>  
 
admin@vz-poe4610> show system uptime 
 22:14:06 up  3:09,  1 user,  load average: 2.64, 2.54, 2.59
admin@vz-poe4610> 
 
Switch is up for almost 3 hrs now with 15 phones. I will add more phones , AP  and see.
Note: Iris, can you please ask someone to do a QA on this image . We (PA)need to do onie load,  upgrade from 2.x to  this image etc with VZ full config.
Like to work on an image which passed your QA test.
Regards,
Sasi
From: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Date: Tuesday, February 4, 2025 at 08:26
To: 徐光宇 <jackie.xu@feisu.com>
Cc: Don DeRis
i <don.derisi@pica8.com>, Iris Rong <iris.rong@pica8.com>, vic.lan@feisu.com <vic.lan@feisu.com>, Angela Hung <angela.hung@pica8.com>, 唐德军 <mikel.tang@feisu.com>, Iris.rong@feisu.com <iris.rong@feisu.com>, 尹娜 <vivien.yin@feisu.com>, Zoneson Chen <zoneson.chen@pica8.com>, Mikel Tang <mikel.tang@pica8.com>, 杜林 <lin.du@feisu.com>, 窦博森 <benson.dou@feisu.com>
Subject: Re: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

HI Lin and team,
Thank you so much.  Will load and test .
 
Regards,
sasi
 
From: 徐光宇 <jackie.xu@feisu.com>
Date: Tuesday, February 4, 2025 at 02:08
To: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Cc: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>, Don DeRisi <don.derisi@pica8.com>, Iris Rong <iris.rong@pica8.com>, vic.lan@feisu.com <vic.lan@feisu.com>, Angela Hung <angela.hung@pica8.com>, 唐德军 <mikel.tang@feisu.com>, Iris.rong@feisu.com <iris.rong@feisu.com>, 尹娜 <vivien.yin@feisu.com>, Zoneson Chen <zoneson.chen@pica8.com>, Mikel Tang <mikel.tang@pica8.com>, 杜林 <lin.du@feisu.com>, 窦博森 <benson.dou@feisu.com>
Subject: Re: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

Hi  Sasi,
 This issue is fixed now. The latest package path :
 scp jackie.xu@10.10.50.16:/home/jackie.xu/my_packet/onie-installer-picos-4.2.3.12-761d282c5a-as4610.bin  ./ 
The password:  jackie.xu
 
 
Could you help to verify it ?
 
Thanks
Jackie
From: "Lin Du"<lin.du@pica8.com>
Date: Mon, Feb 3, 2025, 18:58
Subject: 回复: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total
To: "Sasikumar Puthiyaveedu"<Sasikumar.puthiyaveedu@pica8.com>, "Don DeRisi"<don.derisi@pica8.com>
Cc: "Iris Rong"<iris.rong@pica8.com>, "vic.lan@feisu.com"<vic.lan@feisu.com>, "Angela Hung"<angela.hung@pica8.com>, "唐德军"<mikel.tang@feisu.com>, "Iris.rong@feisu.com"<iris.rong@feisu.com>, "jackie.xu@feisu.com"<jackie.xu@feisu.com>, "尹娜"<vivien.yin@feisu.com>, "Zoneson Chen"<zoneson.chen@pica8.com>, "Mikel Tang"<mikel.tang@pica8.com>
Sasi,
As described before, this issue is related to the 2 seconds timer, and Jackie has fingered out the detailed root cause.
Will build an image for testing tomorrow.
Thanks,
Lin
 
发件人: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
发送时间: Monday, February 3, 2025 1:46 PM
收件人: Lin Du <lin.du@pica8.com>; Don DeRisi <don.derisi@pica8.com>
抄送: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>; Zoneson Chen <zoneson.chen@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
主题: Re: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total
 
If you want to power down/up.
 
PDU

- 172.16.0.254
- admin/1234
- PORT #8
- 8
- AS4610-gotfromvz
- ON

From: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Date: Sunday, February 2, 2025 at 21:05
To: Lin Du <lin.du@pica8.com>, Don DeRisi <don.derisi@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>, vic.lan@feisu.com <vic.lan@feisu.com>, Angela Hung <angela.hung@pica8.com>, 唐德军 <mikel.tang@feisu.com>, Iris.rong@feisu.com <iris.rong@feisu.com>, jackie.xu@feisu.com <jackie.xu@feisu.com>, 尹娜 <vivien.yin@feisu.com>, Zoneson Chen <zoneson.chen@pica8.com>, Mikel Tang <mikel.tang@pica8.com>
Subject: Re: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

Here is the access info, Lin.

sasi@MacBook-Air ~ % telnet 172.16.0.18 7026             

Trying 172.16.0.18...

Connected to 172.16.0.18.

Escape character is '^]'.

admin@vz-poe4610# 

 
telnet> q

Connection closed.

sasi@MacBook-Air ~ % 

 
Regards,
sasi
From: Lin Du <lin.du@pica8.com>
Date: Sunday, February 2, 2025 at 16:55
To: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>, Don DeRisi <don.derisi@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>, vic.lan@feisu.com <vic.lan@feisu.com>, Angela Hung <angela.hung@pica8.com>, 唐德军 <mikel.tang@feisu.com>, Iris.rong@feisu.com <iris.rong@feisu.com>, jackie.xu@feisu.com <jackie.xu@feisu.com>, 尹娜 <vivien.yin@feisu.com>, Zoneson Chen <zoneson.chen@pica8.com>, Mikel Tang <mikel.tang@pica8.com>
Subject: 回复: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

Sasi,
Thanks for your verification.
Could you share with us your device access info so we can have a try after change the codes?
Regards,
Lin
 
发件人: Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
发送时间: Saturday, February 1, 2025 7:45 AM
收件人: Lin Du <lin.du@pica8.com>; Don DeRisi <don.derisi@pica8.com>
抄送: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>; Zoneson Chen <zoneson.chen@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
主题: Re: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total
 
Lin and Team,
We got phones .Thank you , Don, for ordering it.
Able to reproduce it in our lab.
 
1# loaded 4.2.3.11 and Full VZ config . NO Uplink to DHCP etc . just Power and phones.
When adding phone# 15 we end up in trouble and got log messages
 
2# Rolled Back the config to default.  --  . just Power and phones.  
  Just put lldp and poe conif only (like vz)
 

admin@vz-poe4610# show | display set |

    set interface traceoptions flag all disable false

    set poe interface all threshold-mode 1

    set poe interface all max-power 32

    set poe interface all lldp-negotiation false

    set poe interface ge-1/1/1

    set poe interface ge-1/1/2

    set poe interface ge-1/1/3

    set poe interface ge-1/1/4

    set poe interface ge-1/1/5

    set poe interface ge-1/1/6

    set poe interface ge-1/1/7

    set poe interface ge-1/1/8

    set poe interface ge-1/1/9

    set poe interface ge-1/1/10

    set poe interface ge-1/1/11

    set poe interface ge-1/1/12

    set poe interface ge-1/1/13

    set poe interface ge-1/1/14

    set poe interface ge-1/1/15

    set poe interface ge-1/1/16

    set poe interface ge-1/1/17

    set poe interface ge-1/1/18

    set poe interface ge-1/1/19

    set poe interface ge-1/1/20

    set poe interface ge-1/1/21

    set poe interface ge-1/1/22

    set poe interface ge-1/1/23

    set poe interface ge-1/1/24

    set poe interface ge-1/1/25

    set poe interface ge-1/1/26

    set poe interface ge-1/1/27

    set poe interface ge-1/1/28

    set poe interface ge-1/1/29

    set poe interface ge-1/1/30

    set poe interface ge-1/1/31

    set poe interface ge-1/1/32

    set poe interface ge-1/1/33

    set poe interface ge-1/1/34

    set poe interface ge-1/1/35

    set poe interface ge-1/1/36

    set poe interface ge-1/1/37

    set poe interface ge-1/1/38

    set poe interface ge-1/1/39

    set poe interface ge-1/1/40

    set poe interface ge-1/1/41

    set poe interface ge-1/1/42

    set poe interface ge-1/1/43

    set poe interface ge-1/1/44

    set poe interface ge-1/1/45

    set poe interface ge-1/1/46

    set poe interface ge-1/1/47

    set poe interface ge-1/1/48

    set poe power management-mode 4

    set protocols lldp enable true

    set system hostname "vz-poe4610"

    set system log-level "trace"

 

admin@vz-poe4610# 

Able to hit the issue just after connecting phone#15   ( going to port #41). Logs are pasting here.
Please note that ‘ show interface ‘ cli worked for couple of times here and slowly dead/not responding.
 
admin@vz-poe4610> show lldp neighbor | match SEP | count

Count: 14 lines

admin@vz-poe4610>

admin@vz-poe4610> show poe power 

Total power allocated  RealTime consumption   Power available  Power Mode      PSU1 Status             PSU2 Status  

---------------------  --------------------   ---------------  ----------      -----------             ------------------

51.70W                 51.70W                 675.00W          redundant       Present but powered off Powered on              

admin@vz-poe4610> 

 
NOW connecting  phone #15 to port #41
 
 
 
 
 
admin@vz-poe4610:~$ tail -f /tmp/log/messages 
2025-01-31 23:08:24.261 vz-poe4610 local0.debug : [LOGIN]eth0 add address 2603:3024:189f:58e3:3e2c:99ff:fee9:8740 type: 1
2025-01-31 23:08:25.847 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:26.326 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:27.817 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:28.356 vz-poe4610 local0.debug : [SIF]sending arp sync requset timer expires
2025-01-31 23:08:29.317 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:29.846 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:31.821 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:32.300 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:33.851 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:35.347 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:35.826 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:37.742 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/39, reason:0, flag:3
2025-01-31 23:08:37.743 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/39, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:37.743 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 04 2A  E2 70 80 B6 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 97 5D 00 01 
00 13 53 45 50 30 34 32  41 45 32 37 30 38 30 42 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
34 2D 30 2D 31 2D 30 32  30 31 2D 31 37 31 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C B6 90  00 00 00 00 18 9B 00 0B 
00 05 01 00 10 00 06 18  9B 7B 0D CC C6 
2025-01-31 23:08:37.860 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:38.336 vz-poe4610 local0.debug : [SIF]sending arp sync requset timer expires
2025-01-31 23:08:38.337 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:38.779 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/39, reason:0, flag:3
2025-01-31 23:08:38.780 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/39, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:38.780 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 04 2A  E2 70 80 B6 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 34 32 
41 45 32 37 30 38 30 42  36 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 34 
32 41 45 32 37 30 38 30  42 36 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 34 2D 
30 2D 31 2D 30 32 30 31  2D 31 37 31 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3D FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 34 2D 30 2D 31 2D 30 
32 30 31 2D 31 37 31 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 30  31 35 38 45 46 4D FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3D 00 3D  00 00 FA 12 79 AB 
2025-01-31 23:08:39.699 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/17, reason:0, flag:3
2025-01-31 23:08:39.700 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/17, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:39.701 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 2C 01  B5 E5 82 AD 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 85 F2 00 01 
00 13 53 45 50 32 43 30  31 42 35 45 35 38 32 41 
44 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C AD 97  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 C8 9D 68 C1 
2025-01-31 23:08:39.817 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:39.818 vz-poe4610 local0.debug : [SIF]sending arp request timer expires
2025-01-31 23:08:39.974 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/2, reason:0, flag:3
2025-01-31 23:08:39.975 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/2, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:39.975 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 00 7E  95 FC AA CC 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 49 C2 00 01 
00 13 53 45 50 30 30 37  45 39 35 46 43 41 41 43 
43 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C CC BF  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 3B 73 0E C9 
2025-01-31 23:08:40.029 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/3, reason:0, flag:3
2025-01-31 23:08:40.029 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/3, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:40.030 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC D0 EC  35 2C CC 5E 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 B5 A4 00 01 
00 13 53 45 50 44 30 45  43 33 35 32 43 43 43 35 
45 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 5E E1  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 00 2B D8 8A 
2025-01-31 23:08:41.238 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/17, reason:0, flag:3
2025-01-31 23:08:41.239 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/17, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:41.241 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 2C 01  B5 E5 82 AD 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 32 43 30 
31 42 35 45 35 38 32 41  44 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 32 43 
30 31 42 35 45 35 38 32  41 44 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 33  30 32 46 4A 34 43 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3B 00 3B  00 00 CA C1 ED DE 
2025-01-31 23:08:41.300 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:41.488 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/1, reason:0, flag:3
2025-01-31 23:08:41.489 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/1, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:41.490 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC B4 A8  B9 68 F5 BC 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 75 5E 00 01 
00 13 53 45 50 42 34 41  38 42 39 36 38 46 35 42 
43 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C BD 0A  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 D0 A2 5C D3 
2025-01-31 23:08:41.529 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/2, reason:0, flag:3
2025-01-31 23:08:41.530 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/2, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:41.531 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 00 7E  95 FC AA CC 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 30 37 
45 39 35 46 43 41 41 43  43 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 30 
37 45 39 35 46 43 41 41  43 43 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 32  32 30 45 33 58 47 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3B 00 3B  00 00 3A 8F A3 2A 
2025-01-31 23:08:41.591 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/3, reason:0, flag:3
2025-01-31 23:08:41.592 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/3, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:41.594 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E D0 EC  35 2C CC 5E 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 44 30 45 
43 33 35 32 43 43 43 35  45 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 44 30 
45 43 33 35 32 43 43 43  35 45 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 33  30 33 47 32 37 46 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3B 00 3B  00 00 7A A7 B3 10 
2025-01-31 23:08:41.606 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/9, reason:0, flag:3
2025-01-31 23:08:41.608 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/9, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:41.609 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC B4 A8  B9 68 ED BD 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 64 67 00 01 
00 13 53 45 50 42 34 41  38 42 39 36 38 45 44 42 
44 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C BE 02  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 7E 39 EB 3E 
2025-01-31 23:08:41.850 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:42.576 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/1, reason:0, flag:3
2025-01-31 23:08:42.576 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/1, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:42.577 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E B4 A8  B9 68 F5 BC 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 42 34 41 
38 42 39 36 38 46 35 42  43 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 42 34 
41 38 42 39 36 38 46 35  42 43 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 31  34 37 45 50 52 31 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3B 00 3B  00 00 86 CD 66 1F 
2025-01-31 23:08:42.606 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/9, reason:0, flag:3
2025-01-31 23:08:42.607 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/9, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:42.607 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E B4 A8  B9 68 ED BD 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 42 34 41 
38 42 39 36 38 45 44 42  44 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 42 34 
41 38 42 39 36 38 45 44  42 44 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 31  34 37 45 4D 59 55 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3B 00 3B  00 00 6B 86 E7 37 
2025-01-31 23:08:43.851 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:44.297 vz-poe4610 local0.debug : [LOGIN]eth0 add address 2603:3024:189f:58e3:3e2c:99ff:fee9:8740 type: 1
2025-01-31 23:08:44.326 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:45.206 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/15, reason:0, flag:3
2025-01-31 23:08:45.207 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/15, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:45.207 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 04 2A  E2 70 89 3C 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 FB 5E 00 01 
00 13 53 45 50 30 34 32  41 45 32 37 30 38 39 33 
43 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
34 2D 30 2D 31 2D 30 32  30 31 2D 31 37 31 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 3C 9E  00 00 00 00 18 9B 00 0B 
00 05 01 00 10 00 06 18  9B 38 4F FB 11 
2025-01-31 23:08:45.210 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/21, reason:0, flag:3
2025-01-31 23:08:45.211 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/21, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:45.211 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 2C 31  24 6F C5 A1 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 91 15 00 01 
00 13 53 45 50 32 43 33  31 32 34 36 46 43 35 41 
31 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C A1 DA  00 00 00 00 18 9B 00 0B 
00 05 01 00 10 00 06 18  9B AB 50 61 CF 
2025-01-31 23:08:45.469 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/35, reason:0, flag:3
2025-01-31 23:08:45.470 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/35, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:45.470 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 00 EB  D5 CD 87 B2 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 80 2E 00 01 
00 13 53 45 50 30 30 45  42 44 35 43 44 38 37 42 
32 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C B2 9C  00 00 00 00 18 9B 00 0B 
00 05 01 00 10 00 06 18  9B 0B CE 82 93 
2025-01-31 23:08:45.827 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:46.374 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/15, reason:0, flag:3
2025-01-31 23:08:46.375 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/15, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:46.375 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 04 2A  E2 70 89 3C 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 34 32 
41 45 32 37 30 38 39 33  43 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 34 
32 41 45 32 37 30 38 39  33 43 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 34 2D 
30 2D 31 2D 30 32 30 31  2D 31 37 31 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3D FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 34 2D 30 2D 31 2D 30 
32 30 31 2D 31 37 31 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 30  31 35 38 47 42 5A FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3D 00 3D  00 00 EB EC 1C 23 
2025-01-31 23:08:46.439 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/21, reason:0, flag:3
2025-01-31 23:08:46.440 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/21, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:46.440 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 2C 31  24 6F C5 A1 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 32 43 33 
31 32 34 36 46 43 35 41  31 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 32 43 
33 31 32 34 36 46 43 35  41 31 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3D FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 31  30 37 45 32 58 44 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3D 00 3D  00 00 BB BF D1 FB 
2025-01-31 23:08:46.699 vz-poe4610 local0.debug : [LOGIN]eth0 add address 2603:3024:189f:58e3:3e2c:99ff:fee9:8740 type: 1
2025-01-31 23:08:46.726 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/35, reason:0, flag:3
2025-01-31 23:08:46.727 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/35, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:46.727 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 00 EB  D5 CD 87 B2 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 30 45 
42 44 35 43 44 38 37 42  32 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 30 
45 42 44 35 43 44 38 37  42 32 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3D FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 30  32 36 47 50 48 4C FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3D 00 3D  00 00 D1 1E CC 15 
2025-01-31 23:08:47.327 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:47.867 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:48.347 vz-poe4610 local0.debug : [SIF]sending arp sync requset timer expires
2025-01-31 23:08:49.847 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:49.880 vz-poe4610 local0.debug : [SIF]mfc_msg_handler
2025-01-31 23:08:49.880 vz-poe4610 local0.debug : [SIF]
4c 00 00 00 1c 00 00 00 00 00 00 00 00 00 00 00 
02 00 00 00 04 00 00 00 04 00 00 01 08 00 01 00 
ac 10 00 01 0a 00 02 00 00 1c 54 5d c8 5a 00 00 
08 00 04 00 04 00 00 00 14 00 03 00 3b 0d 00 00 
3b 0d 00 00 00 00 00 00 01 00 00 00 
2025-01-31 23:08:49.881 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor msg type:ADD, flag: 0, family: 2, state: 0x4, 
2025-01-31 23:08:49.882 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor:ip 172.16.0.1 lladdr 00:1c:54:5d:c8:5a interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:08:49.882 vz-poe4610 local0.debug : [PICA_LIB_COMMON]End Neighbor:ip 172.16.0.1 lladdr 00:1c:54:5d:c8:5a interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:08:50.356 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:51.741 vz-poe4610 local0.debug : [LOGIN]eth0 add address 2603:3024:189f:58e3:3e2c:99ff:fee9:8740 type: 1
2025-01-31 23:08:51.851 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:52.812 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/19, reason:0, flag:3
2025-01-31 23:08:52.813 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/19, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:52.813 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 00 EB  D5 CD F2 8B 81 00 00 01 
00 81 AA AA 03 00 00 0C  20 00 02 B4 35 4E 00 01 
00 13 53 45 50 30 30 45  42 44 35 43 44 46 32 38 
42 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 1B 73  69 70 38 38 78 78 2E 31 
31 2D 37 2D 31 2D 31 37  2E 6C 6F 61 64 73 00 06 
00 17 43 69 73 63 6F 20  49 50 20 50 68 6F 6E 65 
20 38 38 34 31 00 1C 00  07 00 02 00 00 19 00 0C 
8C 0C 00 00 00 00 18 9B  00 0B 00 05 01 00 10 00 
06 18 9B 06 C9 8A 65 
2025-01-31 23:08:53.088 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/19, reason:0, flag:3
2025-01-31 23:08:53.089 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/19, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:53.090 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 00 EB  D5 CD F2 8B 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 30 45 
42 44 35 43 44 46 32 38  42 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 30 
45 42 44 35 43 44 46 32  38 42 0C 30 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 31 2D 
37 2D 31 2D 31 37 2E 6C  6F 61 64 73 0E 04 00 24 
00 24 FE 09 00 12 0F 01  03 6C 01 00 1E FE 07 00 
12 BB 01 00 33 03 FE 08  00 12 BB 02 01 1F FF 6E 
FE 08 00 12 BB 02 02 1F  FF 20 FE 07 00 12 BB 04 
50 00 3D FE 05 00 12 BB  05 31 FE 1B 00 12 BB 06 
73 69 70 38 38 78 78 2E  31 31 2D 37 2D 31 2D 31 
37 2E 6C 6F 61 64 73 FE  1B 00 12 BB 07 73 69 70 
38 38 78 78 2E 31 31 2D  37 2D 31 2D 31 37 2E 6C 
6F 61 64 73 FE 0F 00 12  BB 08 46 43 48 32 30 32 
36 48 4A 4E 55 FE 17 00  12 BB 09 43 69 73 63 6F 
20 53 79 73 74 65 6D 73  2C 20 49 6E 63 2E FE 0B 
00 12 BB 0A 43 50 2D 38  38 34 31 FE 04 00 12 BB 
0B FE 0C 00 12 0F 02 00  01 03 50 00 3D 00 3D 00 
00 50 EB 5F 29 
2025-01-31 23:08:53.144 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/5, reason:0, flag:3
2025-01-31 23:08:53.144 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/5, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:53.145 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 04 2A  E2 70 1E F8 81 00 00 01 
00 81 AA AA 03 00 00 0C  20 00 02 B4 D4 47 00 01 
00 13 53 45 50 30 34 32  41 45 32 37 30 31 45 46 
38 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 1B 73  69 70 38 38 78 78 2E 31 
31 2D 37 2D 31 2D 31 37  2E 6C 6F 61 64 73 00 06 
00 17 43 69 73 63 6F 20  49 50 20 50 68 6F 6E 65 
20 38 38 34 31 00 1C 00  07 00 02 00 00 19 00 0C 
F8 37 00 00 00 00 18 9B  00 0B 00 05 01 00 10 00 
06 18 9B 05 CB 49 CE 
2025-01-31 23:08:53.316 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:53.423 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/5, reason:0, flag:3
2025-01-31 23:08:53.423 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/5, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:53.424 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 04 2A  E2 70 1E F8 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 34 32 
41 45 32 37 30 31 45 46  38 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 34 
32 41 45 32 37 30 31 45  46 38 0C 30 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 31 2D 
37 2D 31 2D 31 37 2E 6C  6F 61 64 73 0E 04 00 24 
00 24 FE 09 00 12 0F 01  03 6C 01 00 1E FE 07 00 
12 BB 01 00 33 03 FE 08  00 12 BB 02 01 1F FF 6E 
FE 08 00 12 BB 02 02 1F  FF 20 FE 07 00 12 BB 04 
50 00 3D FE 05 00 12 BB  05 31 FE 1B 00 12 BB 06 
73 69 70 38 38 78 78 2E  31 31 2D 37 2D 31 2D 31 
37 2E 6C 6F 61 64 73 FE  1B 00 12 BB 07 73 69 70 
38 38 78 78 2E 31 31 2D  37 2D 31 2D 31 37 2E 6C 
6F 61 64 73 FE 0F 00 12  BB 08 46 43 48 32 30 31 
34 38 53 4E 4E FE 17 00  12 BB 09 43 69 73 63 6F 
20 53 79 73 74 65 6D 73  2C 20 49 6E 63 2E FE 0B 
00 12 BB 0A 43 50 2D 38  38 34 31 FE 04 00 12 BB 
0B FE 0C 00 12 0F 02 00  01 03 50 00 3D 00 3D 00 
00 53 34 20 32 
2025-01-31 23:08:53.836 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:54.199 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/33, reason:0, flag:3
2025-01-31 23:08:54.201 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/33, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:54.203 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 00 C1  B1 E5 0A F6 81 00 00 01 
00 81 AA AA 03 00 00 0C  20 00 02 B4 E0 55 00 01 
00 13 53 45 50 30 30 43  31 42 31 45 35 30 41 46 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 1B 73  69 70 38 38 78 78 2E 31 
31 2D 37 2D 31 2D 31 37  2E 6C 6F 61 64 73 00 06 
00 17 43 69 73 63 6F 20  49 50 20 50 68 6F 6E 65 
20 38 38 35 31 00 1C 00  07 00 02 00 00 19 00 0C 
F6 23 00 00 00 00 24 0A  00 0B 00 05 01 00 10 00 
06 24 0A F3 E1 35 3C 
2025-01-31 23:08:54.486 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/33, reason:0, flag:3
2025-01-31 23:08:54.487 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/33, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:54.488 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 00 C1  B1 E5 0A F6 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 30 43 
31 42 31 45 35 30 41 46  36 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 30 
43 31 42 31 45 35 30 41  46 36 0C 30 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 35 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 31 2D 
37 2D 31 2D 31 37 2E 6C  6F 61 64 73 0E 04 00 24 
00 24 FE 09 00 12 0F 01  03 6C 01 00 1E FE 07 00 
12 BB 01 00 33 03 FE 08  00 12 BB 02 01 1F FF 6E 
FE 08 00 12 BB 02 02 1F  FF 20 FE 07 00 12 BB 04 
50 00 58 FE 05 00 12 BB  05 31 FE 1B 00 12 BB 06 
73 69 70 38 38 78 78 2E  31 31 2D 37 2D 31 2D 31 
37 2E 6C 6F 61 64 73 FE  1B 00 12 BB 07 73 69 70 
38 38 78 78 2E 31 31 2D  37 2D 31 2D 31 37 2E 6C 
6F 61 64 73 FE 0F 00 12  BB 08 46 43 48 32 31 31 
34 44 4C 46 54 FE 17 00  12 BB 09 43 69 73 63 6F 
20 53 79 73 74 65 6D 73  2C 20 49 6E 63 2E FE 0B 
00 12 BB 0A 43 50 2D 38  38 35 31 FE 04 00 12 BB 
0B FE 0C 00 12 0F 02 00  01 04 50 00 58 00 58 00 
00 AF C5 B0 E2 
2025-01-31 23:08:55.000 vz-poe4610 local0.debug : [SIF]mfc_msg_handler
2025-01-31 23:08:55.000 vz-poe4610 local0.debug : [SIF]
4c 00 00 00 1c 00 00 00 00 00 00 00 00 00 00 00 
02 00 00 00 04 00 00 00 04 00 00 01 08 00 01 00 
ac 10 00 ea 0a 00 02 00 00 0c 29 97 fe aa 00 00 
08 00 04 00 01 00 00 00 14 00 03 00 30 0d 00 00 
29 0f 00 00 00 00 00 00 01 00 00 00 
2025-01-31 23:08:55.001 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor msg type:ADD, flag: 0, family: 2, state: 0x4, 
2025-01-31 23:08:55.001 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:08:55.001 vz-poe4610 local0.debug : [PICA_LIB_COMMON]End Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:08:55.837 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:56.309 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:57.003 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/29, reason:0, flag:3
2025-01-31 23:08:57.003 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/29, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:57.004 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E A4 B4  39 D2 4D 4B 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 41 34 42 
34 33 39 44 32 34 44 34  42 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 41 34 
42 34 33 39 44 32 34 44  34 42 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 34 2D 
30 2D 31 2D 30 32 30 31  2D 31 37 31 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 23 00 12 BB 06 73 62  32 33 38 38 78 78 2E 42 
45 2D 30 31 2D 30 33 31  2E 73 62 6E 20 73 69 7A 
65 3D 2D 31 0A FE 21 00  12 BB 07 73 69 70 38 38 
78 78 2E 31 34 2D 30 2D  31 2D 30 32 30 31 2D 31 
37 31 2E 6C 6F 61 64 73  FE 0F 00 12 BB 08 46 43 
48 32 34 30 33 45 30 48  39 FE 17 00 12 BB 09 43 
69 73 63 6F 20 53 79 73  74 65 6D 73 2C 20 49 6E 
63 2E FE 0B 00 12 BB 0A  43 50 2D 38 38 34 31 FE 
04 00 12 BB 0B FE 0C 00  12 0F 02 00 01 03 50 00 
3B 00 3B 00 00 B2 38 4F  07 
2025-01-31 23:08:57.132 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/11, reason:0, flag:3
2025-01-31 23:08:57.133 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/11, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:57.134 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E DC 77  4C 53 57 B3 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 44 43 37 
37 34 43 35 33 35 37 42  33 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 44 43 
37 37 34 43 35 33 35 37  42 33 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 23 00 12 BB 06 73 62  32 33 38 38 78 78 2E 42 
45 2D 30 31 2D 30 32 37  2E 73 62 6E 20 73 69 7A 
65 3D 2D 31 0A FE 21 00  12 BB 07 73 69 70 38 38 
78 78 2E 31 32 2D 38 2D  31 2D 30 30 30 31 2D 34 
35 35 2E 6C 6F 61 64 73  FE 0F 00 12 BB 08 46 43 
48 32 34 34 31 33 57 58  52 FE 17 00 12 BB 09 43 
69 73 63 6F 20 53 79 73  74 65 6D 73 2C 20 49 6E 
63 2E FE 0B 00 12 BB 0A  43 50 2D 38 38 34 31 FE 
04 00 12 BB 0B FE 0C 00  12 0F 02 00 01 03 50 00 
3B 00 3B 00 00 42 90 80  C0 
2025-01-31 23:08:57.517 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/29, reason:0, flag:3
2025-01-31 23:08:57.518 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/29, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:57.518 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC A4 B4  39 D2 4D 4B 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 E7 2C 00 01 
00 13 53 45 50 41 34 42  34 33 39 44 32 34 44 34 
42 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
34 2D 30 2D 31 2D 30 32  30 31 2D 31 37 31 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 4B 62  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 D9 82 C5 59 
2025-01-31 23:08:57.570 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/11, reason:0, flag:3
2025-01-31 23:08:57.571 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/11, egress 0/0/0, reason 0, flag 3
2025-01-31 23:08:57.571 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC DC 77  4C 53 57 B3 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 7A 24 00 01 
00 13 53 45 50 44 43 37  37 34 43 35 33 35 37 42 
33 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C B3 6C  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 3B 42 39 7A 
2025-01-31 23:08:57.866 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:08:58.347 vz-poe4610 local0.debug : [SIF]sending arp sync requset timer expires
2025-01-31 23:08:59.357 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:08:59.836 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:00.708 vz-poe4610 local0.debug : [LOGIN]eth0 add address 2603:3024:189f:58e3:3e2c:99ff:fee9:8740 type: 1
2025-01-31 23:09:01.867 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:02.046 vz-poe4610 local0.debug : [SIF]mfc_msg_handler
2025-01-31 23:09:02.047 vz-poe4610 local0.debug : [SIF]
4c 00 00 00 1c 00 00 00 00 00 00 00 00 00 00 00 
02 00 00 00 04 00 00 00 10 00 00 01 08 00 01 00 
ac 10 00 ea 0a 00 02 00 00 0c 29 97 fe aa 00 00 
08 00 04 00 01 00 00 00 14 00 03 00 f0 0f 00 00 
f9 01 00 00 00 00 00 00 02 00 00 00 
2025-01-31 23:09:02.048 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor msg type:ADD, flag: 0, family: 2, state: 0x10, 
2025-01-31 23:09:02.049 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:09:02.051 vz-poe4610 local0.debug : [PICA_LIB_COMMON]End Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:09:02.052 vz-poe4610 local0.debug : [SIF]mfc_msg_handler
2025-01-31 23:09:02.052 vz-poe4610 local0.debug : [SIF]
4c 00 00 00 1c 00 00 00 00 00 00 00 00 00 00 00 
02 00 00 00 04 00 00 00 02 00 00 01 08 00 01 00 
ac 10 00 ea 0a 00 02 00 00 0c 29 97 fe aa 00 00 
08 00 04 00 01 00 00 00 14 00 03 00 00 00 00 00 
f9 01 00 00 00 00 00 00 02 00 00 00 
2025-01-31 23:09:02.053 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor msg type:ADD, flag: 0, family: 2, state: 0x2, 
2025-01-31 23:09:02.054 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:09:02.055 vz-poe4610 local0.debug : [PICA_LIB_COMMON]End Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:09:02.349 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:03.840 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:04.067 vz-poe4610 local0.info : [LOGIN]Turn on the poe led of port ge-1/1/41
2025-01-31 23:09:04.356 vz-poe4610 local0.debug : [LOGIN]eth0 add address 2603:3024:189f:58e3:3e2c:99ff:fee9:8740 type: 1
2025-01-31 23:09:05.337 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:05.667 vz-poe4610 local0.debug : [SIF]Port ge-1/1/41 status is up, speed:1000, duplex:2, medium:0
2025-01-31 23:09:05.668 vz-poe4610 local0.warning : [SIF]Interface ge-1/1/41, changed state to up
2025-01-31 23:09:05.668 vz-poe4610 local0.debug : [SIF]set vif lo up 1, vrf 0, active 1, _active 0
2025-01-31 23:09:05.791 vz-poe4610 local0.info : [PICA_LIB_COMMON]Card batch set port state(1) successfully.
2025-01-31 23:09:05.793 vz-poe4610 local0.debug : [SIF]Set port msti state, msti=0, ifname=ge-1/1/41, state=0
2025-01-31 23:09:05.849 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:07.830 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:08.309 vz-poe4610 local0.debug : [SIF]sending arp sync requset timer expires
2025-01-31 23:09:08.311 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:09.817 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:09.818 vz-poe4610 local0.debug : [SIF]sending arp request timer expires
2025-01-31 23:09:10.032 vz-poe4610 local0.debug : [LOGIN]eth0 add address 2603:3024:189f:58e3:3e2c:99ff:fee9:8740 type: 1
2025-01-31 23:09:11.317 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:11.856 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:13.821 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:14.300 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:14.657 vz-poe4610 local0.info : [PICA_LIB_COMMON]Card batch set port state(2) successfully.
2025-01-31 23:09:14.659 vz-poe4610 local0.debug : [SIF]Set port msti state, msti=0, ifname=ge-1/1/41, state=1
2025-01-31 23:09:14.660 vz-poe4610 local0.debug : [SIF]Set port msti state, msti=0, ifname=ge-1/1/41, state=2
2025-01-31 23:09:15.857 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:17.357 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:17.830 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:18.310 vz-poe4610 local0.debug : [SIF]sending arp sync requset timer expires
2025-01-31 23:09:18.451 vz-poe4610 local0.warning : [SIF]Interface ge-1/1/41, changed state to down
2025-01-31 23:09:18.452 vz-poe4610 local0.debug : [SIF]set vif lo up 1, vrf 0, active 1, _active 0
2025-01-31 23:09:18.472 vz-poe4610 local0.debug : [SIF]set port lacp state, ge-1/1/41:0x5
2025-01-31 23:09:18.473 vz-poe4610 local0.debug : [SIF]set vif lo up 1, vrf 0, active 1, _active 0
2025-01-31 23:09:18.557 vz-poe4610 local0.info : [PICA_LIB_COMMON]Card batch set port state(1) successfully.
2025-01-31 23:09:18.558 vz-poe4610 local0.debug : [SIF]Set port msti state, msti=0, ifname=ge-1/1/41, state=0
2025-01-31 23:09:19.830 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:20.310 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:21.766 vz-poe4610 local0.debug : [LOGIN]eth0 add address 2603:3024:189f:58e3:3e2c:99ff:fee9:8740 type: 1
2025-01-31 23:09:21.810 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:23.307 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:23.846 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:25.811 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:26.277 vz-poe4610 local0.debug : [SIF]Port ge-1/1/41 status is up, speed:1000, duplex:2, medium:0
2025-01-31 23:09:26.279 vz-poe4610 local0.warning : [SIF]Interface ge-1/1/41, changed state to up
2025-01-31 23:09:26.281 vz-poe4610 local0.debug : [SIF]set vif lo up 1, vrf 0, active 1, _active 0
2025-01-31 23:09:26.298 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:26.411 vz-poe4610 local0.info : [PICA_LIB_COMMON]Card batch set port state(1) successfully.
2025-01-31 23:09:26.412 vz-poe4610 local0.debug : [SIF]Set port msti state, msti=0, ifname=ge-1/1/41, state=0
2025-01-31 23:09:27.840 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:28.320 vz-poe4610 local0.debug : [SIF]sending arp sync requset timer expires
2025-01-31 23:09:29.347 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:29.826 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:31.850 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:32.329 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:33.837 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:35.157 vz-poe4610 local0.info : [PICA_LIB_COMMON]Card batch set port state(2) successfully.
2025-01-31 23:09:35.160 vz-poe4610 local0.debug : [SIF]Set port msti state, msti=0, ifname=ge-1/1/41, state=1
2025-01-31 23:09:35.160 vz-poe4610 local0.debug : [SIF]Set port msti state, msti=0, ifname=ge-1/1/41, state=2
2025-01-31 23:09:35.340 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:35.819 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:35.960 vz-poe4610 local0.debug : [SIF]mfc_msg_handler
2025-01-31 23:09:35.960 vz-poe4610 local0.debug : [SIF]
4c 00 00 00 1c 00 00 00 00 00 00 00 00 00 00 00 
02 00 00 00 04 00 00 00 04 00 00 01 08 00 01 00 
ac 10 00 ea 0a 00 02 00 00 0c 29 97 fe aa 00 00 
08 00 04 00 01 00 00 00 14 00 03 00 40 0d 00 00 
39 0f 00 00 00 00 00 00 01 00 00 00 
2025-01-31 23:09:35.961 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor msg type:ADD, flag: 0, family: 2, state: 0x4, 
2025-01-31 23:09:35.961 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:09:35.962 vz-poe4610 local0.debug : [PICA_LIB_COMMON]End Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:09:37.707 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/39, reason:0, flag:3
2025-01-31 23:09:37.708 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/39, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:37.709 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 04 2A  E2 70 80 B6 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 97 5C 00 01 
00 13 53 45 50 30 34 32  41 45 32 37 30 38 30 42 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
34 2D 30 2D 31 2D 30 32  30 31 2D 31 37 31 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C B6 91  00 00 00 00 18 9B 00 0B 
00 05 01 00 10 00 06 18  9B 0F 41 98 5D 
2025-01-31 23:09:37.829 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:38.300 vz-poe4610 local0.debug : [SIF]sending arp sync requset timer expires
2025-01-31 23:09:38.300 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:38.452 vz-poe4610 local0.debug : [LOGIN]eth0 add address 2603:3024:189f:58e3:3e2c:99ff:fee9:8740 type: 1
2025-01-31 23:09:38.749 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/39, reason:0, flag:3
2025-01-31 23:09:38.750 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/39, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:38.750 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 04 2A  E2 70 80 B6 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 34 32 
41 45 32 37 30 38 30 42  36 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 34 
32 41 45 32 37 30 38 30  42 36 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 34 2D 
30 2D 31 2D 30 32 30 31  2D 31 37 31 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3D FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 34 2D 30 2D 31 2D 30 
32 30 31 2D 31 37 31 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 30  31 35 38 45 46 4D FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3D 00 3D  00 00 FA 12 79 AB 
2025-01-31 23:09:39.672 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/17, reason:0, flag:3
2025-01-31 23:09:39.673 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/17, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:39.674 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 2C 01  B5 E5 82 AD 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 85 F1 00 01 
00 13 53 45 50 32 43 30  31 42 35 45 35 38 32 41 
44 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C AD 98  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 1F 36 1C AB 
2025-01-31 23:09:39.737 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:39.737 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:39.738 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 68 9E  0B 29 F8 86 81 00 00 01 
00 8F AA AA 03 00 00 0C  20 00 02 B4 79 C4 00 01 
00 13 53 45 50 36 38 39  45 30 42 32 39 46 38 38 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 86 F9  00 00 00 00 18 A8 00 0F 
00 08 20 02 00 01 00 0B  00 05 01 00 10 00 06 18 
A8 BB 84 6A 8B 
2025-01-31 23:09:39.857 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:39.858 vz-poe4610 local0.debug : [SIF]sending arp request timer expires
2025-01-31 23:09:39.948 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/2, reason:0, flag:3
2025-01-31 23:09:39.948 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/2, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:39.949 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 00 7E  95 FC AA CC 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 49 C1 00 01 
00 13 53 45 50 30 30 37  45 39 35 46 43 41 41 43 
43 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C CC C0  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 A4 4C 12 6A 
2025-01-31 23:09:40.002 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/3, reason:0, flag:3
2025-01-31 23:09:40.003 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/3, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:40.003 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC D0 EC  35 2C CC 5E 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 B5 A3 00 01 
00 13 53 45 50 44 30 45  43 33 35 32 43 43 43 35 
45 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 5E E2  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 C8 15 3F F7 
2025-01-31 23:09:40.745 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:40.746 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:40.746 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 68 9E  0B 29 F8 86 81 00 00 01 
00 8F AA AA 03 00 00 0C  20 00 02 B4 79 C3 00 01 
00 13 53 45 50 36 38 39  45 30 42 32 39 46 38 38 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 86 FA  00 00 00 00 18 A8 00 0F 
00 08 20 02 00 01 00 0B  00 05 01 00 10 00 06 18 
A8 72 09 76 D0 
2025-01-31 23:09:41.210 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/17, reason:0, flag:3
2025-01-31 23:09:41.211 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/17, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:41.211 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 2C 01  B5 E5 82 AD 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 32 43 30 
31 42 35 45 35 38 32 41  44 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 32 43 
30 31 42 35 45 35 38 32  41 44 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 33  30 32 46 4A 34 43 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3B 00 3B  00 00 CA C1 ED DE 
2025-01-31 23:09:41.327 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:41.407 vz-poe4610 local0.debug : [SIF]mfc_msg_handler
2025-01-31 23:09:41.408 vz-poe4610 local0.debug : [SIF]
4c 00 00 00 1c 00 00 00 00 00 00 00 00 00 00 00 
02 00 00 00 04 00 00 00 10 00 00 01 08 00 01 00 
ac 10 00 ea 0a 00 02 00 00 0c 29 97 fe aa 00 00 
08 00 04 00 01 00 00 00 14 00 03 00 60 0f 00 00 
fa 01 00 00 00 00 00 00 02 00 00 00 
2025-01-31 23:09:41.410 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor msg type:ADD, flag: 0, family: 2, state: 0x10, 
2025-01-31 23:09:41.411 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:09:41.412 vz-poe4610 local0.debug : [PICA_LIB_COMMON]End Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:09:41.413 vz-poe4610 local0.debug : [SIF]mfc_msg_handler
2025-01-31 23:09:41.414 vz-poe4610 local0.debug : [SIF]
4c 00 00 00 1c 00 00 00 00 00 00 00 00 00 00 00 
02 00 00 00 04 00 00 00 02 00 00 01 08 00 01 00 
ac 10 00 ea 0a 00 02 00 00 0c 29 97 fe aa 00 00 
08 00 04 00 01 00 00 00 14 00 03 00 00 00 00 00 
fa 01 00 00 00 00 00 00 02 00 00 00 
2025-01-31 23:09:41.415 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor msg type:ADD, flag: 0, family: 2, state: 0x2, 
2025-01-31 23:09:41.416 vz-poe4610 local0.debug : [PICA_LIB_COMMON]Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:09:41.417 vz-poe4610 local0.debug : [PICA_LIB_COMMON]End Neighbor:ip 172.16.0.234 lladdr 00:0c:29:97:fe:aa interface eth0 vtep  vni 0 vlan 0 flags 
2025-01-31 23:09:41.460 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/1, reason:0, flag:3
2025-01-31 23:09:41.461 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/1, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:41.462 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC B4 A8  B9 68 F5 BC 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 75 5D 00 01 
00 13 53 45 50 42 34 41  38 42 39 36 38 46 35 42 
43 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C BD 0B  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 8E 1B 05 A0 
2025-01-31 23:09:41.502 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/2, reason:0, flag:3
2025-01-31 23:09:41.503 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/2, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:41.503 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 00 7E  95 FC AA CC 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 30 37 
45 39 35 46 43 41 41 43  43 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 30 
37 45 39 35 46 43 41 41  43 43 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 32  32 30 45 33 58 47 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3B 00 3B  00 00 3A 8F A3 2A 
2025-01-31 23:09:41.564 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/3, reason:0, flag:3
2025-01-31 23:09:41.565 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/3, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:41.566 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E D0 EC  35 2C CC 5E 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 44 30 45 
43 33 35 32 43 43 43 35  45 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 44 30 
45 43 33 35 32 43 43 43  35 45 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 33  30 33 47 32 37 46 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3B 00 3B  00 00 7A A7 B3 10 
2025-01-31 23:09:41.580 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/9, reason:0, flag:3
2025-01-31 23:09:41.581 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/9, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:41.582 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC B4 A8  B9 68 ED BD 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 64 66 00 01 
00 13 53 45 50 42 34 41  38 42 39 36 38 45 44 42 
44 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C BE 03  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 0A 75 BF A5 
2025-01-31 23:09:41.754 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:41.754 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:41.755 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 68 9E  0B 29 F8 86 81 00 00 01 
00 8F AA AA 03 00 00 0C  20 00 02 B4 79 C2 00 01 
00 13 53 45 50 36 38 39  45 30 42 32 39 46 38 38 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 86 FB  00 00 00 00 18 A8 00 0F 
00 08 20 02 00 01 00 0B  00 05 01 00 10 00 06 18 
A8 F5 D5 0E 4A 
2025-01-31 23:09:41.810 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:42.546 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/1, reason:0, flag:3
2025-01-31 23:09:42.547 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/1, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:42.547 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E B4 A8  B9 68 F5 BC 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 42 34 41 
38 42 39 36 38 46 35 42  43 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 42 34 
41 38 42 39 36 38 46 35  42 43 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 31  34 37 45 50 52 31 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3B 00 3B  00 00 86 CD 66 1F 
2025-01-31 23:09:42.580 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/9, reason:0, flag:3
2025-01-31 23:09:42.580 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/9, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:42.581 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E B4 A8  B9 68 ED BD 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 42 34 41 
38 42 39 36 38 45 44 42  44 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 42 34 
41 38 42 39 36 38 45 44  42 44 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 31  34 37 45 4D 59 55 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3B 00 3B  00 00 6B 86 E7 37 
2025-01-31 23:09:42.761 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:42.762 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:42.762 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 68 9E  0B 29 F8 86 81 00 00 01 
00 8F AA AA 03 00 00 0C  20 00 02 B4 79 C1 00 01 
00 13 53 45 50 36 38 39  45 30 42 32 39 46 38 38 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 86 FC  00 00 00 00 18 A8 00 0F 
00 08 20 02 00 01 00 0B  00 05 01 00 10 00 06 18 
A8 E3 20 62 15 
2025-01-31 23:09:43.770 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:43.771 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:43.772 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 68 9E  0B 29 F8 86 81 00 00 01 
00 8F AA AA 03 00 00 0C  20 00 02 B4 79 C0 00 01 
00 13 53 45 50 36 38 39  45 30 42 32 39 46 38 38 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 86 FD  00 00 00 00 18 A8 00 0F 
00 08 20 02 00 01 00 0B  00 05 01 00 10 00 06 18 
A8 64 FC 1A 8F 
2025-01-31 23:09:43.830 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:44.310 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:44.779 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:44.779 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:44.780 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 68 9E  0B 29 F8 86 81 00 00 01 
00 8F AA AA 03 00 00 0C  20 00 02 B4 79 BF 00 01 
00 13 53 45 50 36 38 39  45 30 42 32 39 46 38 38 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 86 FE  00 00 00 00 18 A8 00 0F 
00 08 20 02 00 01 00 0B  00 05 01 00 10 00 06 18 
A8 31 89 D7 1D 
2025-01-31 23:09:45.176 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/15, reason:0, flag:3
2025-01-31 23:09:45.177 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/15, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:45.177 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 04 2A  E2 70 89 3C 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 FB 5D 00 01 
00 13 53 45 50 30 34 32  41 45 32 37 30 38 39 33 
43 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
34 2D 30 2D 31 2D 30 32  30 31 2D 31 37 31 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 3C 9F  00 00 00 00 18 9B 00 0B 
00 05 01 00 10 00 06 18  9B 66 F6 A2 62 
2025-01-31 23:09:45.183 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/21, reason:0, flag:3
2025-01-31 23:09:45.183 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/21, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:45.184 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 2C 31  24 6F C5 A1 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 91 14 00 01 
00 13 53 45 50 32 43 33  31 32 34 36 46 43 35 41 
31 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C A1 DB  00 00 00 00 18 9B 00 0B 
00 05 01 00 10 00 06 18  9B DF 1C 35 54 
2025-01-31 23:09:45.441 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/35, reason:0, flag:3
2025-01-31 23:09:45.441 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/35, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:45.442 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 00 EB  D5 CD 87 B2 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 80 2D 00 01 
00 13 53 45 50 30 30 45  42 44 35 43 44 38 37 42 
32 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C B2 9D  00 00 00 00 18 9B 00 0B 
00 05 01 00 10 00 06 18  9B 55 77 DB E0 
2025-01-31 23:09:45.726 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:45.727 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:45.728 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 68 9E  0B 29 F8 86 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 36 38 39 
45 30 42 32 39 46 38 38  36 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 36 38 
39 45 30 42 32 39 46 38  38 36 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 80 01 6E FE 08  00 12 BB 02 02 80 01 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 23 00 12 BB 06 73 62  32 33 38 38 78 78 2E 42 
45 2D 30 31 2D 30 32 37  2E 73 62 6E 20 73 69 7A 
65 3D 2D 31 0A FE 21 00  12 BB 07 73 69 70 38 38 
78 78 2E 31 32 2D 38 2D  31 2D 30 30 30 31 2D 34 
35 35 2E 6C 6F 61 64 73  FE 0F 00 12 BB 08 46 43 
48 32 34 34 34 33 38 30  30 FE 17 00 12 BB 09 43 
69 73 63 6F 20 53 79 73  74 65 6D 73 2C 20 49 6E 
63 2E FE 0B 00 12 BB 0A  43 50 2D 38 38 34 31 FE 
04 00 12 BB 0B FE 0C 00  12 0F 02 00 01 03 50 00 
3B 00 3B 00 00 53 C4 C6  88 
2025-01-31 23:09:45.787 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:45.788 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:45.788 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 68 9E  0B 29 F8 86 81 00 00 01 
00 8F AA AA 03 00 00 0C  20 00 02 B4 79 BE 00 01 
00 13 53 45 50 36 38 39  45 30 42 32 39 46 38 38 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 86 FF  00 00 00 00 18 A8 00 0F 
00 08 20 02 00 01 00 0B  00 05 01 00 10 00 06 18 
A8 B6 55 AF 87 
2025-01-31 23:09:45.840 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:46.328 vz-poe4610 local0.debug : [LOGIN]update register poe event, name:ge-1/1/41, ifname:ge-1/1/41
2025-01-31 23:09:46.343 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/15, reason:0, flag:3
2025-01-31 23:09:46.344 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/15, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:46.344 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 04 2A  E2 70 89 3C 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 34 32 
41 45 32 37 30 38 39 33  43 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 34 
32 41 45 32 37 30 38 39  33 43 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 34 2D 
30 2D 31 2D 30 32 30 31  2D 31 37 31 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3D FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 34 2D 30 2D 31 2D 30 
32 30 31 2D 31 37 31 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 30  31 35 38 47 42 5A FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3D 00 3D  00 00 EB EC 1C 23 
2025-01-31 23:09:46.411 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/21, reason:0, flag:3
2025-01-31 23:09:46.412 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/21, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:46.412 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 2C 31  24 6F C5 A1 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 32 43 33 
31 32 34 36 46 43 35 41  31 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 32 43 
33 31 32 34 36 46 43 35  41 31 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3D FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 31  30 37 45 32 58 44 FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3D 00 3D  00 00 BB BF D1 FB 
2025-01-31 23:09:46.560 vz-poe4610 local0.info : [LOGIN]push config
2025-01-31 23:09:46.560 vz-poe4610 local0.info : [LOGIN]push config
2025-01-31 23:09:46.580 vz-poe4610 local0.info : [LOGIN]Port 1 set priority success
2025-01-31 23:09:46.656 vz-poe4610 local0.info : [LOGIN]Port 1 set power threshold type success
2025-01-31 23:09:46.697 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/35, reason:0, flag:3
2025-01-31 23:09:46.697 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/35, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:46.698 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 00 EB  D5 CD 87 B2 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 30 45 
42 44 35 43 44 38 37 42  32 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 30 
45 42 44 35 43 44 38 37  42 32 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3D FE 05 00 12 BB 05 31 
FE 08 00 12 BB 06 32 33  34 35 FE 21 00 12 BB 07 
73 69 70 38 38 78 78 2E  31 32 2D 38 2D 31 2D 30 
30 30 31 2D 34 35 35 2E  6C 6F 61 64 73 FE 0F 00 
12 BB 08 46 43 48 32 30  32 36 47 50 48 4C FE 17 
00 12 BB 09 43 69 73 63  6F 20 53 79 73 74 65 6D 
73 2C 20 49 6E 63 2E FE  0B 00 12 BB 0A 43 50 2D 
38 38 34 31 FE 04 00 12  BB 0B FE 0C 00 12 0F 02 
00 01 03 50 00 3D 00 3D  00 00 D1 1E CC 15 
2025-01-31 23:09:46.726 vz-poe4610 local0.info : [LOGIN]Port 1 set power threshold success
2025-01-31 23:09:46.738 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:46.738 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:46.739 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 68 9E  0B 29 F8 86 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 36 38 39 
45 30 42 32 39 46 38 38  36 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 36 38 
39 45 30 42 32 39 46 38  38 36 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 80 01 6E FE 08  00 12 BB 02 02 80 01 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 23 00 12 BB 06 73 62  32 33 38 38 78 78 2E 42 
45 2D 30 31 2D 30 32 37  2E 73 62 6E 20 73 69 7A 
65 3D 2D 31 0A FE 21 00  12 BB 07 73 69 70 38 38 
78 78 2E 31 32 2D 38 2D  31 2D 30 30 30 31 2D 34 
35 35 2E 6C 6F 61 64 73  FE 0F 00 12 BB 08 46 43 
48 32 34 34 34 33 38 30  30 FE 17 00 12 BB 09 43 
69 73 63 6F 20 53 79 73  74 65 6D 73 2C 20 49 6E 
63 2E FE 0B 00 12 BB 0A  43 50 2D 38 38 34 31 FE 
04 00 12 BB 0B FE 0C 00  12 0F 02 00 01 03 50 00 
3B 00 3B 00 00 53 C4 C6  88 
2025-01-31 23:09:46.789 vz-poe4610 local0.info : [LOGIN]Port 2 set priority success
2025-01-31 23:09:46.797 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:46.797 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:46.797 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 68 9E  0B 29 F8 86 81 00 00 01 
00 8F AA AA 03 00 00 0C  20 00 02 B4 79 BD 00 01 
00 13 53 45 50 36 38 39  45 30 42 32 39 46 38 38 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 87 00  00 00 00 00 18 A8 00 0F 
00 08 20 02 00 01 00 0B  00 05 01 00 10 00 06 18 
A8 B0 D2 FE 50 
2025-01-31 23:09:46.866 vz-poe4610 local0.info : [LOGIN]Port 2 set power threshold type success
2025-01-31 23:09:46.929 vz-poe4610 local0.info : [LOGIN]Port 2 set power threshold success
2025-01-31 23:09:46.996 vz-poe4610 local0.info : [LOGIN]Port 3 set priority success
2025-01-31 23:09:47.066 vz-poe4610 local0.info : [LOGIN]Port 3 set power threshold type success
2025-01-31 23:09:47.136 vz-poe4610 local0.info : [LOGIN]Port 3 set power threshold success
2025-01-31 23:09:47.206 vz-poe4610 local0.info : [LOGIN]Port 5 set priority success
2025-01-31 23:09:47.280 vz-poe4610 local0.info : [LOGIN]Port 5 set power threshold type success
2025-01-31 23:09:47.320 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:47.351 vz-poe4610 local0.info : [LOGIN]Port 5 set power threshold success
2025-01-31 23:09:47.426 vz-poe4610 local0.info : [LOGIN]Port 9 set priority success
2025-01-31 23:09:47.496 vz-poe4610 local0.info : [LOGIN]Port 9 set power threshold type success
2025-01-31 23:09:47.566 vz-poe4610 local0.info : [LOGIN]Port 9 set power threshold success
2025-01-31 23:09:47.636 vz-poe4610 local0.info : [LOGIN]Port 11 set priority success
2025-01-31 23:09:47.706 vz-poe4610 local0.info : [LOGIN]Port 11 set power threshold type success
2025-01-31 23:09:47.776 vz-poe4610 local0.info : [LOGIN]Port 11 set power threshold success
2025-01-31 23:09:47.846 vz-poe4610 local0.info : [LOGIN]Port 15 set priority success
2025-01-31 23:09:47.857 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:47.916 vz-poe4610 local0.info : [LOGIN]Port 15 set power threshold type success
2025-01-31 23:09:47.986 vz-poe4610 local0.info : [LOGIN]Port 15 set power threshold success
2025-01-31 23:09:48.056 vz-poe4610 local0.info : [LOGIN]Port 17 set priority success
2025-01-31 23:09:48.126 vz-poe4610 local0.info : [LOGIN]Port 17 set power threshold type success
2025-01-31 23:09:48.197 vz-poe4610 local0.info : [LOGIN]Port 17 set power threshold success
2025-01-31 23:09:48.266 vz-poe4610 local0.info : [LOGIN]Port 19 set priority success
2025-01-31 23:09:48.336 vz-poe4610 local0.debug : [SIF]sending arp sync requset timer expires
2025-01-31 23:09:48.337 vz-poe4610 local0.info : [LOGIN]Port 19 set power threshold type success
2025-01-31 23:09:48.410 vz-poe4610 local0.info : [LOGIN]Port 19 set power threshold success
2025-01-31 23:09:48.480 vz-poe4610 local0.info : [LOGIN]Port 21 set priority success
2025-01-31 23:09:48.550 vz-poe4610 local0.info : [LOGIN]Port 21 set power threshold type success
2025-01-31 23:09:48.626 vz-poe4610 local0.info : [LOGIN]Port 21 set power threshold success
2025-01-31 23:09:48.696 vz-poe4610 local0.info : [LOGIN]Port 29 set priority success
2025-01-31 23:09:48.760 vz-poe4610 local0.info : [LOGIN]Port 29 set power threshold type success
2025-01-31 23:09:48.829 vz-poe4610 local0.info : [LOGIN]Port 29 set power threshold success
2025-01-31 23:09:48.906 vz-poe4610 local0.info : [LOGIN]Port 33 set priority success
2025-01-31 23:09:48.969 vz-poe4610 local0.info : [LOGIN]Port 33 set power threshold type success
2025-01-31 23:09:49.046 vz-poe4610 local0.info : [LOGIN]Port 33 set power threshold success
2025-01-31 23:09:49.116 vz-poe4610 local0.info : [LOGIN]Port 35 set priority success
2025-01-31 23:09:49.186 vz-poe4610 local0.info : [LOGIN]Port 35 set power threshold type success
2025-01-31 23:09:49.256 vz-poe4610 local0.info : [LOGIN]Port 35 set power threshold success
2025-01-31 23:09:49.273 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:49.274 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:49.275 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 68 9E  0B 29 F8 86 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 36 38 39 
45 30 42 32 39 46 38 38  36 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 36 38 
39 45 30 42 32 39 46 38  38 36 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 23 00 12 BB 06 73 62  32 33 38 38 78 78 2E 42 
45 2D 30 31 2D 30 32 37  2E 73 62 6E 20 73 69 7A 
65 3D 2D 31 0A FE 21 00  12 BB 07 73 69 70 38 38 
78 78 2E 31 32 2D 38 2D  31 2D 30 30 30 31 2D 34 
35 35 2E 6C 6F 61 64 73  FE 0F 00 12 BB 08 46 43 
48 32 34 34 34 33 38 30  30 FE 17 00 12 BB 09 43 
69 73 63 6F 20 53 79 73  74 65 6D 73 2C 20 49 6E 
63 2E FE 0B 00 12 BB 0A  43 50 2D 38 38 34 31 FE 
04 00 12 BB 0B FE 0C 00  12 0F 02 00 01 03 50 00 
3B 00 3B 00 00 31 89 04  6B 
2025-01-31 23:09:49.285 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/41, reason:0, flag:3
2025-01-31 23:09:49.286 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/41, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:49.287 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 68 9E  0B 29 F8 86 81 00 00 01 
00 8F AA AA 03 00 00 0C  20 00 02 B4 7A 81 00 01 
00 13 53 45 50 36 38 39  45 30 42 32 39 46 38 38 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
32 2D 38 2D 31 2D 30 30  30 31 2D 34 35 35 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 87 01  00 00 00 00 17 C6 00 0F 
00 08 20 02 00 01 00 0B  00 05 01 00 10 00 06 17 
C6 8F 73 2E A2 
2025-01-31 23:09:49.326 vz-poe4610 local0.info : [LOGIN]Port 39 set priority success
2025-01-31 23:09:49.396 vz-poe4610 local0.info : [LOGIN]Port 39 set power threshold type success
2025-01-31 23:09:49.471 vz-poe4610 local0.info : [LOGIN]Port 39 set power threshold success
2025-01-31 23:09:49.540 vz-poe4610 local0.info : [LOGIN]Port 41 set priority success
2025-01-31 23:09:49.616 vz-poe4610 local0.info : [LOGIN]Port 41 set power threshold type success
2025-01-31 23:09:49.686 vz-poe4610 local0.info : [LOGIN]Port 41 set power threshold success
2025-01-31 23:09:49.736 vz-poe4610 local0.info : [LOGIN]push config
2025-01-31 23:09:49.736 vz-poe4610 local0.info : [LOGIN]push config
2025-01-31 23:09:49.756 vz-poe4610 local0.info : [LOGIN]Port 1 set priority success
2025-01-31 23:09:49.826 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:49.827 vz-poe4610 local0.info : [LOGIN]Port 1 set power threshold type success
2025-01-31 23:09:49.889 vz-poe4610 local0.info : [LOGIN]Port 1 set power threshold success
2025-01-31 23:09:49.959 vz-poe4610 local0.info : [LOGIN]Port 2 set priority success
2025-01-31 23:09:50.036 vz-poe4610 local0.info : [LOGIN]Port 2 set power threshold type success
2025-01-31 23:09:50.106 vz-poe4610 local0.info : [LOGIN]Port 2 set power threshold success
2025-01-31 23:09:50.176 vz-poe4610 local0.info : [LOGIN]Port 3 set priority success
2025-01-31 23:09:50.248 vz-poe4610 local0.info : [LOGIN]Port 3 set power threshold type success
2025-01-31 23:09:50.307 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:50.320 vz-poe4610 local0.info : [LOGIN]Port 3 set power threshold success
2025-01-31 23:09:50.396 vz-poe4610 local0.info : [LOGIN]Port 5 set priority success
2025-01-31 23:09:50.467 vz-poe4610 local0.info : [LOGIN]Port 5 set power threshold type success
2025-01-31 23:09:50.531 vz-poe4610 local0.info : [LOGIN]Port 5 set power threshold success
2025-01-31 23:09:50.606 vz-poe4610 local0.info : [LOGIN]Port 9 set priority success
2025-01-31 23:09:50.676 vz-poe4610 local0.info : [LOGIN]Port 9 set power threshold type success
2025-01-31 23:09:50.746 vz-poe4610 local0.info : [LOGIN]Port 9 set power threshold success
2025-01-31 23:09:50.809 vz-poe4610 local0.info : [LOGIN]Port 11 set priority success
2025-01-31 23:09:50.886 vz-poe4610 local0.info : [LOGIN]Port 11 set power threshold type success
2025-01-31 23:09:50.956 vz-poe4610 local0.info : [LOGIN]Port 11 set power threshold success
2025-01-31 23:09:51.026 vz-poe4610 local0.info : [LOGIN]Port 15 set priority success
2025-01-31 23:09:51.096 vz-poe4610 local0.info : [LOGIN]Port 15 set power threshold type success
2025-01-31 23:09:51.166 vz-poe4610 local0.info : [LOGIN]Port 15 set power threshold success
2025-01-31 23:09:51.236 vz-poe4610 local0.info : [LOGIN]Port 17 set priority success
2025-01-31 23:09:51.308 vz-poe4610 local0.info : [LOGIN]Port 17 set power threshold type success
2025-01-31 23:09:51.376 vz-poe4610 local0.info : [LOGIN]Port 17 set power threshold success
2025-01-31 23:09:51.446 vz-poe4610 local0.info : [LOGIN]Port 19 set priority success
2025-01-31 23:09:51.519 vz-poe4610 local0.info : [LOGIN]Port 19 set power threshold type success
2025-01-31 23:09:51.590 vz-poe4610 local0.info : [LOGIN]Port 19 set power threshold success
2025-01-31 23:09:51.659 vz-poe4610 local0.info : [LOGIN]Port 21 set priority success
2025-01-31 23:09:51.729 vz-poe4610 local0.info : [LOGIN]Port 21 set power threshold type success
2025-01-31 23:09:51.796 vz-poe4610 local0.info : [LOGIN]Port 21 set power threshold success
2025-01-31 23:09:51.861 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:51.866 vz-poe4610 local0.info : [LOGIN]Port 29 set priority success
2025-01-31 23:09:51.936 vz-poe4610 local0.info : [LOGIN]Port 29 set power threshold type success
2025-01-31 23:09:52.006 vz-poe4610 local0.info : [LOGIN]Port 29 set power threshold success
2025-01-31 23:09:52.076 vz-poe4610 local0.info : [LOGIN]Port 33 set priority success
2025-01-31 23:09:52.146 vz-poe4610 local0.info : [LOGIN]Port 33 set power threshold type success
2025-01-31 23:09:52.216 vz-poe4610 local0.info : [LOGIN]Port 33 set power threshold success
2025-01-31 23:09:52.286 vz-poe4610 local0.info : [LOGIN]Port 35 set priority success
2025-01-31 23:09:52.356 vz-poe4610 local0.info : [LOGIN]Port 35 set power threshold type success
2025-01-31 23:09:52.426 vz-poe4610 local0.info : [LOGIN]Port 35 set power threshold success
2025-01-31 23:09:52.496 vz-poe4610 local0.info : [LOGIN]Port 39 set priority success
2025-01-31 23:09:52.566 vz-poe4610 local0.info : [LOGIN]Port 39 set power threshold type success
2025-01-31 23:09:52.630 vz-poe4610 local0.info : [LOGIN]Port 39 set power threshold success
2025-01-31 23:09:52.699 vz-poe4610 local0.info : [LOGIN]Port 41 set priority success
2025-01-31 23:09:52.766 vz-poe4610 local0.info : [LOGIN]Port 41 set power threshold type success
2025-01-31 23:09:52.788 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/19, reason:0, flag:3
2025-01-31 23:09:52.788 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/19, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:52.789 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 00 EB  D5 CD F2 8B 81 00 00 01 
00 81 AA AA 03 00 00 0C  20 00 02 B4 35 4D 00 01 
00 13 53 45 50 30 30 45  42 44 35 43 44 46 32 38 
42 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 1B 73  69 70 38 38 78 78 2E 31 
31 2D 37 2D 31 2D 31 37  2E 6C 6F 61 64 73 00 06 
00 17 43 69 73 63 6F 20  49 50 20 50 68 6F 6E 65 
20 38 38 34 31 00 1C 00  07 00 02 00 00 19 00 0C 
8C 0D 00 00 00 00 18 9B  00 0B 00 05 01 00 10 00 
06 18 9B D4 BB 43 DC 
2025-01-31 23:09:52.836 vz-poe4610 local0.info : [LOGIN]Port 41 set power threshold success
2025-01-31 23:09:52.887 vz-poe4610 local0.info : [LOGIN]push config
2025-01-31 23:09:52.888 vz-poe4610 local0.info : [LOGIN]push config
2025-01-31 23:09:52.906 vz-poe4610 local0.info : [LOGIN]Port 1 set priority success
2025-01-31 23:09:52.976 vz-poe4610 local0.info : [LOGIN]Port 1 set power threshold type success
2025-01-31 23:09:53.046 vz-poe4610 local0.info : [LOGIN]Port 1 set power threshold success
2025-01-31 23:09:53.061 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/19, reason:0, flag:3
2025-01-31 23:09:53.062 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/19, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:53.063 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 00 EB  D5 CD F2 8B 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 30 45 
42 44 35 43 44 46 32 38  42 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 30 
45 42 44 35 43 44 46 32  38 42 0C 30 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 31 2D 
37 2D 31 2D 31 37 2E 6C  6F 61 64 73 0E 04 00 24 
00 24 FE 09 00 12 0F 01  03 6C 01 00 1E FE 07 00 
12 BB 01 00 33 03 FE 08  00 12 BB 02 01 1F FF 6E 
FE 08 00 12 BB 02 02 1F  FF 20 FE 07 00 12 BB 04 
50 00 3D FE 05 00 12 BB  05 31 FE 1B 00 12 BB 06 
73 69 70 38 38 78 78 2E  31 31 2D 37 2D 31 2D 31 
37 2E 6C 6F 61 64 73 FE  1B 00 12 BB 07 73 69 70 
38 38 78 78 2E 31 31 2D  37 2D 31 2D 31 37 2E 6C 
6F 61 64 73 FE 0F 00 12  BB 08 46 43 48 32 30 32 
36 48 4A 4E 55 FE 17 00  12 BB 09 43 69 73 63 6F 
20 53 79 73 74 65 6D 73  2C 20 49 6E 63 2E FE 0B 
00 12 BB 0A 43 50 2D 38  38 34 31 FE 04 00 12 BB 
0B FE 0C 00 12 0F 02 00  01 03 50 00 3D 00 3D 00 
00 50 EB 5F 29 
2025-01-31 23:09:53.117 vz-poe4610 local0.info : [LOGIN]Port 2 set priority success
2025-01-31 23:09:53.118 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/5, reason:0, flag:3
2025-01-31 23:09:53.118 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/5, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:53.119 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 04 2A  E2 70 1E F8 81 00 00 01 
00 81 AA AA 03 00 00 0C  20 00 02 B4 D4 46 00 01 
00 13 53 45 50 30 34 32  41 45 32 37 30 31 45 46 
38 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 1B 73  69 70 38 38 78 78 2E 31 
31 2D 37 2D 31 2D 31 37  2E 6C 6F 61 64 73 00 06 
00 17 43 69 73 63 6F 20  49 50 20 50 68 6F 6E 65 
20 38 38 34 31 00 1C 00  07 00 02 00 00 19 00 0C 
F8 38 00 00 00 00 18 9B  00 0B 00 05 01 00 10 00 
06 18 9B 7C D3 40 0A 
2025-01-31 23:09:53.179 vz-poe4610 local0.info : [LOGIN]Port 2 set power threshold type success
2025-01-31 23:09:53.249 vz-poe4610 local0.info : [LOGIN]Port 2 set power threshold success
2025-01-31 23:09:53.320 vz-poe4610 local0.info : [LOGIN]Port 3 set priority success
2025-01-31 23:09:53.351 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:53.389 vz-poe4610 local0.info : [LOGIN]Port 3 set power threshold type success
2025-01-31 23:09:53.399 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/5, reason:0, flag:3
2025-01-31 23:09:53.399 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/5, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:53.400 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 04 2A  E2 70 1E F8 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 34 32 
41 45 32 37 30 31 45 46  38 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 34 
32 41 45 32 37 30 31 45  46 38 0C 30 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 31 2D 
37 2D 31 2D 31 37 2E 6C  6F 61 64 73 0E 04 00 24 
00 24 FE 09 00 12 0F 01  03 6C 01 00 1E FE 07 00 
12 BB 01 00 33 03 FE 08  00 12 BB 02 01 1F FF 6E 
FE 08 00 12 BB 02 02 1F  FF 20 FE 07 00 12 BB 04 
50 00 3D FE 05 00 12 BB  05 31 FE 1B 00 12 BB 06 
73 69 70 38 38 78 78 2E  31 31 2D 37 2D 31 2D 31 
37 2E 6C 6F 61 64 73 FE  1B 00 12 BB 07 73 69 70 
38 38 78 78 2E 31 31 2D  37 2D 31 2D 31 37 2E 6C 
6F 61 64 73 FE 0F 00 12  BB 08 46 43 48 32 30 31 
34 38 53 4E 4E FE 17 00  12 BB 09 43 69 73 63 6F 
20 53 79 73 74 65 6D 73  2C 20 49 6E 63 2E FE 0B 
00 12 BB 0A 43 50 2D 38  38 34 31 FE 04 00 12 BB 
0B FE 0C 00 12 0F 02 00  01 03 50 00 3D 00 3D 00 
00 53 34 20 32 
2025-01-31 23:09:53.456 vz-poe4610 local0.info : [LOGIN]Port 3 set power threshold success
2025-01-31 23:09:53.526 vz-poe4610 local0.info : [LOGIN]Port 5 set priority success
2025-01-31 23:09:53.599 vz-poe4610 local0.info : [LOGIN]Port 5 set power threshold type success
2025-01-31 23:09:53.670 vz-poe4610 local0.info : [LOGIN]Port 5 set power threshold success
2025-01-31 23:09:53.750 vz-poe4610 local0.info : [LOGIN]Port 9 set priority success
2025-01-31 23:09:53.810 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:53.816 vz-poe4610 local0.info : [LOGIN]Port 9 set power threshold type success
2025-01-31 23:09:53.890 vz-poe4610 local0.info : [LOGIN]Port 9 set power threshold success
2025-01-31 23:09:53.959 vz-poe4610 local0.info : [LOGIN]Port 11 set priority success
2025-01-31 23:09:54.029 vz-poe4610 local0.info : [LOGIN]Port 11 set power threshold type success
2025-01-31 23:09:54.099 vz-poe4610 local0.info : [LOGIN]Port 11 set power threshold success
2025-01-31 23:09:54.171 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/33, reason:0, flag:3
2025-01-31 23:09:54.172 vz-poe4610 local0.info : [LOGIN]Port 15 set priority success
2025-01-31 23:09:54.172 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/33, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:54.173 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC 00 C1  B1 E5 0A F6 81 00 00 01 
00 81 AA AA 03 00 00 0C  20 00 02 B4 E0 54 00 01 
00 13 53 45 50 30 30 43  31 42 31 45 35 30 41 46 
36 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 1B 73  69 70 38 38 78 78 2E 31 
31 2D 37 2D 31 2D 31 37  2E 6C 6F 61 64 73 00 06 
00 17 43 69 73 63 6F 20  49 50 20 50 68 6F 6E 65 
20 38 38 35 31 00 1C 00  07 00 02 00 00 19 00 0C 
F6 24 00 00 00 00 24 0A  00 0B 00 05 01 00 10 00 
06 24 0A 86 57 6D EF 
2025-01-31 23:09:54.236 vz-poe4610 local0.info : [LOGIN]Port 15 set power threshold type success
2025-01-31 23:09:54.310 vz-poe4610 local0.info : [LOGIN]Port 15 set power threshold success
2025-01-31 23:09:54.380 vz-poe4610 local0.info : [LOGIN]Port 17 set priority success
2025-01-31 23:09:54.450 vz-poe4610 local0.info : [LOGIN]Port 17 set power threshold type success
2025-01-31 23:09:54.463 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/33, reason:0, flag:3
2025-01-31 23:09:54.464 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/33, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:54.464 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E 00 C1  B1 E5 0A F6 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 30 30 43 
31 42 31 45 35 30 41 46  36 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 30 30 
43 31 42 31 45 35 30 41  46 36 0C 30 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 35 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 31 2D 
37 2D 31 2D 31 37 2E 6C  6F 61 64 73 0E 04 00 24 
00 24 FE 09 00 12 0F 01  03 6C 01 00 1E FE 07 00 
12 BB 01 00 33 03 FE 08  00 12 BB 02 01 1F FF 6E 
FE 08 00 12 BB 02 02 1F  FF 20 FE 07 00 12 BB 04 
50 00 58 FE 05 00 12 BB  05 31 FE 1B 00 12 BB 06 
73 69 70 38 38 78 78 2E  31 31 2D 37 2D 31 2D 31 
37 2E 6C 6F 61 64 73 FE  1B 00 12 BB 07 73 69 70 
38 38 78 78 2E 31 31 2D  37 2D 31 2D 31 37 2E 6C 
6F 61 64 73 FE 0F 00 12  BB 08 46 43 48 32 31 31 
34 44 4C 46 54 FE 17 00  12 BB 09 43 69 73 63 6F 
20 53 79 73 74 65 6D 73  2C 20 49 6E 63 2E FE 0B 
00 12 BB 0A 43 50 2D 38  38 35 31 FE 04 00 12 BB 
0B FE 0C 00 12 0F 02 00  01 04 50 00 58 00 58 00 
00 AF C5 B0 E2 
2025-01-31 23:09:54.530 vz-poe4610 local0.info : [LOGIN]Port 17 set power threshold success
2025-01-31 23:09:54.600 vz-poe4610 local0.info : [LOGIN]Port 19 set priority success
2025-01-31 23:09:54.670 vz-poe4610 local0.info : [LOGIN]Port 19 set power threshold type success
2025-01-31 23:09:54.746 vz-poe4610 local0.info : [LOGIN]Port 19 set power threshold success
2025-01-31 23:09:54.816 vz-poe4610 local0.info : [LOGIN]Port 21 set priority success
2025-01-31 23:09:54.886 vz-poe4610 local0.info : [LOGIN]Port 21 set power threshold type success
2025-01-31 23:09:54.959 vz-poe4610 local0.info : [LOGIN]Port 21 set power threshold success
2025-01-31 23:09:55.026 vz-poe4610 local0.info : [LOGIN]Port 29 set priority success
2025-01-31 23:09:55.096 vz-poe4610 local0.info : [LOGIN]Port 29 set power threshold type success
2025-01-31 23:09:55.169 vz-poe4610 local0.info : [LOGIN]Port 29 set power threshold success
2025-01-31 23:09:55.240 vz-poe4610 local0.info : [LOGIN]Port 33 set priority success
2025-01-31 23:09:55.306 vz-poe4610 local0.info : [LOGIN]Port 33 set power threshold type success
2025-01-31 23:09:55.376 vz-poe4610 local0.info : [LOGIN]Port 33 set power threshold success
2025-01-31 23:09:55.446 vz-poe4610 local0.info : [LOGIN]Port 35 set priority success
2025-01-31 23:09:55.517 vz-poe4610 local0.info : [LOGIN]Port 35 set power threshold type success
2025-01-31 23:09:55.586 vz-poe4610 local0.info : [LOGIN]Port 35 set power threshold success
2025-01-31 23:09:55.660 vz-poe4610 local0.info : [LOGIN]Port 39 set priority success
2025-01-31 23:09:55.727 vz-poe4610 local0.info : [LOGIN]Port 39 set power threshold type success
2025-01-31 23:09:55.799 vz-poe4610 local0.info : [LOGIN]Port 39 set power threshold success
2025-01-31 23:09:55.830 vz-poe4610 local0.debug : [SIF]Checking and refreshing every ARP entry timer expires
2025-01-31 23:09:55.869 vz-poe4610 local0.info : [LOGIN]Port 41 set priority success
2025-01-31 23:09:55.939 vz-poe4610 local0.info : [LOGIN]Port 41 set power threshold type success
2025-01-31 23:09:56.010 vz-poe4610 local0.info : [LOGIN]Port 41 set power threshold success
2025-01-31 23:09:56.309 vz-poe4610 local0.debug : [SIF]Reading SG count in HW timer expires
2025-01-31 23:09:57.000 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/29, reason:0, flag:3
2025-01-31 23:09:57.000 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/29, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:57.001 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E A4 B4  39 D2 4D 4B 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 41 34 42 
34 33 39 44 32 34 44 34  42 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 41 34 
42 34 33 39 44 32 34 44  34 42 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 34 2D 
30 2D 31 2D 30 32 30 31  2D 31 37 31 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 23 00 12 BB 06 73 62  32 33 38 38 78 78 2E 42 
45 2D 30 31 2D 30 33 31  2E 73 62 6E 20 73 69 7A 
65 3D 2D 31 0A FE 21 00  12 BB 07 73 69 70 38 38 
78 78 2E 31 34 2D 30 2D  31 2D 30 32 30 31 2D 31 
37 31 2E 6C 6F 61 64 73  FE 0F 00 12 BB 08 46 43 
48 32 34 30 33 45 30 48  39 FE 17 00 12 BB 09 43 
69 73 63 6F 20 53 79 73  74 65 6D 73 2C 20 49 6E 
63 2E FE 0B 00 12 BB 0A  43 50 2D 38 38 34 31 FE 
04 00 12 BB 0B FE 0C 00  12 0F 02 00 01 03 50 00 
3B 00 3B 00 00 B2 38 4F  07 
2025-01-31 23:09:57.117 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/11, reason:0, flag:3
2025-01-31 23:09:57.117 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/11, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:57.118 vz-poe4610 local0.debug : [SIF]
01 80 C2 00 00 0E DC 77  4C 53 57 B3 81 00 00 01 
88 CC 02 06 05 01 00 00  00 00 04 10 07 44 43 37 
37 34 43 35 33 35 37 42  33 3A 50 31 06 02 00 B4 
08 07 53 57 20 50 4F 52  54 0A 0F 53 45 50 44 43 
37 37 34 43 35 33 35 37  42 33 0C 36 43 69 73 63 
6F 20 49 50 20 50 68 6F  6E 65 20 38 38 34 31 2C 
20 56 31 2C 20 73 69 70  38 38 78 78 2E 31 32 2D 
38 2D 31 2D 30 30 30 31  2D 34 35 35 2E 6C 6F 61 
64 73 0E 04 00 24 00 24  FE 09 00 12 0F 01 03 6C 
01 00 1E FE 07 00 12 BB  01 00 33 03 FE 08 00 12 
BB 02 01 1F FF 6E FE 08  00 12 BB 02 02 1F FF 20 
FE 07 00 12 BB 04 50 00  3B FE 05 00 12 BB 05 31 
FE 23 00 12 BB 06 73 62  32 33 38 38 78 78 2E 42 
45 2D 30 31 2D 30 32 37  2E 73 62 6E 20 73 69 7A 
65 3D 2D 31 0A FE 21 00  12 BB 07 73 69 70 38 38 
78 78 2E 31 32 2D 38 2D  31 2D 30 30 30 31 2D 34 
35 35 2E 6C 6F 61 64 73  FE 0F 00 12 BB 08 46 43 
48 32 34 34 31 33 57 58  52 FE 17 00 12 BB 09 43 
69 73 63 6F 20 53 79 73  74 65 6D 73 2C 20 49 6E 
63 2E FE 0B 00 12 BB 0A  43 50 2D 38 38 34 31 FE 
04 00 12 BB 0B FE 0C 00  12 0F 02 00 01 03 50 00 
3B 00 3B 00 00 42 90 80  C0 
2025-01-31 23:09:57.140 vz-poe4610 local0.info : [LOGIN]push config
2025-01-31 23:09:57.141 vz-poe4610 local0.info : [LOGIN]push config
2025-01-31 23:09:57.166 vz-poe4610 local0.info : [LOGIN]Port 1 set priority success
2025-01-31 23:09:57.236 vz-poe4610 local0.info : [LOGIN]Port 1 set power threshold type success
2025-01-31 23:09:57.306 vz-poe4610 local0.info : [LOGIN]Port 1 set power threshold success
2025-01-31 23:09:57.379 vz-poe4610 local0.info : [LOGIN]Port 2 set priority success
2025-01-31 23:09:57.449 vz-poe4610 local0.info : [LOGIN]Port 2 set power threshold type success
2025-01-31 23:09:57.499 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/29, reason:0, flag:3
2025-01-31 23:09:57.499 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/29, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:57.500 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC A4 B4  39 D2 4D 4B 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 E7 2B 00 01 
00 13 53 45 50 41 34 42  34 33 39 44 32 34 44 34 
42 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21 73  69 70 38 38 78 78 2E 31 
34 2D 30 2D 31 2D 30 32  30 31 2D 31 37 31 2E 6C 
6F 61 64 73 00 06 00 17  43 69 73 63 6F 20 49 50 
20 50 68 6F 6E 65 20 38  38 34 31 00 1C 00 07 00 
02 00 00 19 00 0C 4B 63  00 00 00 00 17 C6 00 0B 
00 05 01 00 10 00 06 17  C6 92 D7 F6 21 
2025-01-31 23:09:57.526 vz-poe4610 local0.info : [LOGIN]Port 2 set power threshold success
2025-01-31 23:09:57.561 vz-poe4610 local0.debug : [SIF]receive packet on port 1/1/11, reason:0, flag:3
2025-01-31 23:09:57.562 vz-poe4610 local0.debug : [SIF]receive packet, ingress 1/1/11, egress 0/0/0, reason 0, flag 3
2025-01-31 23:09:57.563 vz-poe4610 local0.debug : [SIF]
01 00 0C CC CC CC DC 77  4C 53 57 B3 81 00 00 01 
00 87 AA AA 03 00 00 0C  20 00 02 B4 7A 23 00 01 
00 13 53 45 50 44 43 37  37 34 43 35 33 35 37 42 
33 00 03 00 0A 50 6F 72  74 20 31 00 04 00 08 00 
00 04 90 00 05 00 21
 
 
admin@vz-poe4610# run show lldp neighbor |match SEP |count

Count: 15 lines

admin@vz-poe4610#

 
admin@vz-poe4610> show poe interface all 

 

Command interrupted!

 

admin@vz-poe4610> show interface br

Interface       Management  Status  Flow Control  Duplex  Speed    Description

--------------  ----------  ------  ------------  ------  -------  ------------------------------

ge-1/1/1        Enabled     Up      Disabled      Full    1Gb/s    

ge-1/1/2        Enabled     Up      Disabled      Full    1Gb/s    

ge-1/1/3        Enabled     Up      Disabled      Full    1Gb/s    

ge-1/1/4        Enabled     Down    Disabled      Full    Auto     

ge-1/1/5        Enabled     Up      Disabled      Full    1Gb/s    

ge-1/1/6        Enabled     Down    Disabled      Full    Auto     

ge-1/1/7        Enabled     Down    Disabled      Full    Auto     

ge-1/1/8        Enabled     Down    Disabled      Full    Auto     

ge-1/1/9        Enabled     Up      Disabled      Full    1Gb/s    

ge-1/1/10       Enabled     Down    Disabled      Full    Auto     

ge-1/1/11       Enabled     Up      Disabled      Full    1Gb/s    

ge-1/1/12       Enabled     Down    Disabled      Full    Auto     

ge-1/1/13       Enabled     Down    Disabled      Full    Auto     

ge-1/1/14       Enabled     Down    Disabled      Full    Auto     

ge-1/1/15       Enabled     Up      Disabled      Full    1Gb/s    

ge-1/1/16       Enabled     Down    Disabled      Full    Auto     

ge-1/1/17       Enabled     Up      Disabled      Full    1Gb/s    

ge-1/1/18       Enabled     Down    Disabled      Full    Auto     

ge-1/1/19       Enabled     Up      Disabled      Full    1Gb/s    

ge-1/1/20       Enabled     Down    Disabled      Full    Auto     

admin@vz-poe4610>

admin@vz-poe4610> configure 

Entering configuration mode.

User admin is also in configuration mode.

admin@vz-poe4610# set interface gigabit-ethernet ge-1/1/10 disable true

admin@vz-poe4610# commit 

 

Command interrupted!

 

admin@vz-poe4610# exit discard 

ERROR:  Waiting your 'commit' or 'load' to be finished.

admin@vz-poe4610# 

 

 

admin@vz-poe4610# run show interface br

 

Command interrupted!

 

admin@vz-poe4610# 

 
Once you have a  fix, we can verify it in our lab.
 
Regards,
sasi
 
 
From: Lin Du <lin.du@pica8.com>
Date: Tuesday, January 28, 2025 at 20:15
To: Don DeRisi <don.derisi@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>, vic.lan@feisu.com <vic.lan@feisu.com>, Angela Hung <angela.hung@pica8.com>, 唐德军 <mikel.tang@feisu.com>, Iris.rong@feisu.com <iris.rong@feisu.com>, jackie.xu@feisu.com <jackie.xu@feisu.com>, 尹娜 <vivien.yin@feisu.com>, Zoneson Chen <zoneson.chen@pica8.com>, Mikel Tang <mikel.tang@pica8.com>, Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: 回复: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

Don,
Good to know we can set up a test bed.
Make sure the phone and up, get DHCP address, LLDP/CDP talking as well. Not sure if extra gateway software is needed or open source one can work.
 
The time slot is not an issue for me. Just let me know the scheduled time.
Thanks,
Lin
 
发件人: Don DeRisi <don.derisi@pica8.com>
发送时间: Wednesday, January 29, 2025 6:48 AM
收件人: Lin Du <lin.du@pica8.com>
抄送: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>; Zoneson Chen <zoneson.chen@pica8.com>; Mikel Tang <mikel.tang@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
主题: RE: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total
 
One update … We placed an order for 15 Cisco 8841 phones for Palo Alto, to deliver Thursday (8) and Friday (7).
Verizon is moving to Cisco model 8841 as their standard.
We’ll look for Sasi to recreate problem in lab.
This should be good test bed also for testing a fix when we get there.
 
I know it is Holiday – Happy New Year.
 
Same as below to have a call with Verizon for more logging:
Lin, do you have any preference or restriction on days and time of day to join?  
For example, 9 AM ET to 11 AM ET (10 PM to midnight Beijing) may work.  Perhaps Thursday (per Nick schedule).
 
 
Regards,
Don
 
From: Don DeRisi
Sent: Tuesday, January 28, 2025 10:16 AM
To: Lin Du <lin.du@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>; Zoneson Chen <zoneson.chen@pica8.com>; Mikel Tang <mikel.tang@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: RE: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total
 
HI Lin,  thank you for summary.
 
I have wondered for a while, please say what is the acronym SIF is.  I can guess, but best to ask.  I know pica_sif is a running process.
 
Can you say what type of logging (or commands) you would use for “open the logging setting, so as to get the failed log message”?
 
I will get timeslots for you and others to join with us and Nick for session using staging lab in Florida.
Nick has said >>>I won't be back in the office till later this week
 
Lin, do you have any preference or restriction on days and time of day to join?  
For example, 9 AM ET to 11 AM ET (10 PM to midnight Beijing) may work.  Perhaps Thursday (per Nick schedule).
 
Also, Asad is looking to add phones in his Hempstead NY lab.
 
Regards,
Don
 
From: Lin Du <lin.du@pica8.com>
Sent: Tuesday, January 28, 2025 9:46 AM
To: Don DeRisi <don.derisi@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>; Zoneson Chen <zoneson.chen@pica8.com>; Mikel Tang <mikel.tang@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: 回复: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total
 
Don,
Let me summarize the known issues here.
If we can recreate the full environment, that will be helpful, i.e. poe, voice vlan, DHCP IP should function properly. If we can reproduce it, the fixing should be easy.

The phones here only work as PoE power devices, no other ops can be configured on phone side, so voice vlan/LLDP cannot function properly

Looks pica_sif module hangs, so all packet-in and most of the configurations are stuck. Vlan/voice vlan processing is stayed in pica_sif module. Other show commands may have to talk pica_sif module for interface list to display but no response/stuck.

The sif(pica_sif) logging for vlan/voice vlan and DHCP snooping could identify the failure point. Looks the process is run into a loop without return when plugin the 15th phone.

Vivien is applying for the testing phones within product QA department, if any support doc is needed, will ask for your help directly.

 
Let me know the possible time slot for the next session of later this week, will try to join the session.
What we try to do is the open the logging setting, so as to get the failed log message. Which should tell the failed point.
Thanks,
Lin
 
发件人: Don DeRisi <don.derisi@pica8.com>
发送时间: Tuesday, January 28, 2025 9:20 AM
收件人: Lin Du <lin.du@pica8.com>
抄送: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>; Zoneson Chen <zoneson.chen@pica8.com>; Mikel Tang <mikel.tang@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
主题: Re: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total
 
Hi Lin, All, 
 
This update in from Nick.
Seems very recreatable with 14 physical phones.
This now at a staging lab, not in production.  GOOD
 
Later in week for him to be back.  Will try to ship phones to Palo Alto.
But maybe he can host a session for Eng to join on his staging lab.
 
This update in Ticket # 88642   (https://fscomhelp.zendesk.com/agent/tickets/88642)
 
Don
 
Start email copy
From: Holmes, Nicholas A <nicholas.holmes@verizon.com>
Sent: Monday, January 27, 2025 8:04 PM
To: Don DeRisi <don.derisi@pica8.com>
Cc: Kamal, Asad <asad.kamal@verizon.com>; Support <support@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: Re: [E] PicOS 4.2.3.11 - switch problem recreated at 14 phones threshold
 
Hello Don, Team,
 
I was able to reproduce this on a device that I have on console in my staging room. 
 
I had 14 phones, 13 - 8841's and 1 - 8861 phones. I did also have 2 Aruba AP635's connected but I disconnected those and still appear to have the issue. 
 
I won't be back in the office till later this week to be able to physically plug, unplug devices if we want to test with that setup. 
 
I will try to find out if I can ship out those phones for testing in Palo Alto Pica8 location and get back to you. 
 
Thanks
 
Nick
----------
End email copy
 
Regards,
Don

 

 
From: Don DeRisi
Sent: Monday, January 27, 2025 4:36 PM
To: Lin Du <lin.du@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com <vic.lan@feisu.com>; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com <iris.rong@feisu.com>; jackie.xu@feisu.com <jackie.xu@feisu.com>; 尹娜 <vivien.yin@feisu.com>; Zoneson Chen <zoneson.chen@pica8.com>; Mikel Tang <mikel.tang@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: RE: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total
 
Hi Lin, no update yet on getting phones from Verizon for Palo Alto.

 

They did suggest we try for a timeslot where Engineers can join us for a troubleshoot call using their site.

Especially with Holiday this may be difficult, but please let us know.

(We have had Verizon calls in past with Mikel, or Aaron, Tom, Vic, Leon, not sure who all.)

 

Meanwhile,  a few points to maybe help with thinking on the problem.

 

any ideas on why only some commands fail during problem?  These are from prior list:
show interface brief hangs (hang for basking ridge recording)
show poe power hangs (hang for basking ridge recording – show poe interface all)
set command followed by commit hangs (see in prior cases not done today)
show tech_support hangs
show spanning tree hangs
Other commands like show lldp neighbor are good, CLI is working otherwise; go to shell good.
 

In the recording, before the trouble at 26:51 for show interface brief being locked out or hung,  
at 26:22 for port 14, lldp neighbor and dhcp snooping binding both have IP 0.0.0.0 but dhcp snooping also has the vlan 2124.

(port 14 first shows trouble getting IP at 25:14, followed by many attempts with dhcp snooping binding)

So, we tag the vlan for problem port 14 but do not get an IP. 

Failure is after the vlan tag logic and before completing DHCP IP.  

Does this help isolate where the problem occurs?

 

 

Regards,

Don

 

From: Don DeRisi
Sent: Monday, January 27, 2025 9:52 AM
To: Lin Du <lin.du@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>; Zoneson Chen <zoneson.chen@pica8.com>; Mikel Tang <mikel.tang@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: RE: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

 

Lin, reading your note more carefully …

 

You wrote

>>. Looks this issue is related CDP/voice vlan or other factors, which cannot be simulated with PoE tester..

>>>If we can get the devices from Verizon to reproduce this issue with more logging opened, that can save some time and get it fixed quickly.

 

So voice vlan not yet simulated.

And yes, test bed in Palo Alto with more phones (target 15), and with more logging should help.

 

I’ll go ahead and request phones from Verizon for Palo Alto.

 

Regards,

Don

 

From: Don DeRisi
Sent: Monday, January 27, 2025 9:42 AM
To: Lin Du <lin.du@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>; Zoneson Chen <zoneson.chen@pica8.com>; Mikel Tang <mikel.tang@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: RE: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

 

Hi Lin, All,  thanks Vivien for this test.

 

Are the phones in a voice vlan?.  Do POE tester ports go to voice vlan?

As you know, voice vlan is tagged when device identified as a phone, which can be by any of:

CDP – see “voice”in platform string
LLDP MED attributes
NAC RADIUS response attribute (no NAC in current test)
 

I think we need to invest and have a full set of phones.  Verizon configures 40 ports for phones.

Here we have trouble at 14 or 15 phones.

 

Also at times we need PC devices behind phones.  This does noy seem to trigger the problem now as shown in Friday’s test at Basking Ridge. (shown in recording)

 

Lin,  If you want me to write business justification for approval, please let me know.

Understood challenges during Spring Holidays.

 

Verizon offered to ship phones to Palo Alto lab.

With Sasi and team assistance will that be sufficient test bed for test with Engineering team?

 

Regards,

Don

 

From: Lin Du <lin.du@pica8.com>
Sent: Monday, January 27, 2025 4:53 AM
To: Don DeRisi <don.derisi@pica8.com>; Zoneson Chen <zoneson.chen@pica8.com>; Mikel Tang <mikel.tang@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>
Subject: 回复: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

 

Don, Sasi, Zoneson

Vivien helped testing with the provided config as following.

 

Hi All，

Sorry for not producing the issue about cli hang.

1, Now I connected 5 ip-phones and 2 arubas, and 24 poe tester which have 29 ports in all power on.

image001.jpg

2, Also using ixia network to generate dhcp snooping table:

admin@bsrgnj11z-ue40500# run show dhcp snooping binding

Total Snooping host count:    57

MAC Address         IP Address      Port            VLAN ID   Lease(sec)

--------------------------------------------------------------------------------------------

22:11:11:11:11:11   192.168.10.2    ge-1/1/47       1124      200/200

a8:5b:f7:c2:45:52   192.168.10.22   ge-1/1/1        1124      84535/86400

00:00:26:6f:a7:ce   192.168.10.43   ge-1/1/47       1124      84481/86400

00:00:26:6f:a7:d0   192.168.10.12   ge-1/1/47       1124      85750/86400

00:00:26:6f:a7:d1   192.168.10.17   ge-1/1/47       1124      85753/86400

00:00:26:6f:a7:d2   192.168.10.10   ge-1/1/47       1124      85750/86400

00:00:26:6f:a7:d3   192.168.10.8    ge-1/1/47       1124      85750/86400

00:00:26:6f:a7:d4   192.168.10.14   ge-1/1/47       1124      85750/86400

00:00:26:6f:a7:d5   192.168.10.13   ge-1/1/47       1124      85750/86400

00:00:26:6f:a7:d6   192.168.10.9    ge-1/1/47       1124      85750/86400

00:00:26:6f:a7:d7   192.168.10.11   ge-1/1/47       1124      85750/86400

00:00:26:6f:a7:d8   192.168.10.16   ge-1/1/47       1124      85753/86400

00:00:26:6f:a7:d9   192.168.10.19   ge-1/1/47       1124      85757/86400

00:00:26:6f:a7:da   192.168.10.20   ge-1/1/47       1124      85757/86400

00:00:26:6f:a7:db   192.168.10.22   ge-1/1/47       1124      85760/86400

00:00:26:6f:a7:dc   192.168.10.15   ge-1/1/47       1124      85751/86400

00:00:26:6f:a7:dd   192.168.10.21   ge-1/1/47       1124      85757/86400

00:00:26:6f:a7:de   192.168.10.18   ge-1/1/47       1124      85755/86400

00:00:26:6f:a7:ee   192.168.10.23   ge-1/1/47       1124      85896/86400

00:00:26:6f:a7:ef   192.168.10.24   ge-1/1/47       1124      85896/86400

00:00:26:6f:a7:f0   192.168.10.26   ge-1/1/47       1124      85896/86400

00:00:26:6f:a7:f1   192.168.10.25   ge-1/1/47       1124      85896/86400

00:00:26:6f:a7:f2   192.168.10.28   ge-1/1/47       1124      85896/86400

00:00:26:6f:a7:f3   192.168.10.30   ge-1/1/47       1124      85902/86400

00:00:26:6f:a7:f4   192.168.10.31   ge-1/1/47       1124      85903/86400

00:00:26:6f:a7:f5   192.168.10.27   ge-1/1/47       1124      85896/86400

00:00:26:6f:a7:f6   192.168.10.29   ge-1/1/47       1124      85896/86400

d0:d3:e0:c0:0b:f7   192.168.10.7    ge-1/1/7        1124      85231/86400

cc:5a:53:63:21:1b   192.168.20.7    ge-1/1/3        2124      86395/86400

6c:fa:89:72:60:41   0.0.0.0         ge-1/1/5        2124      0/0

cc:98:91:4e:c9:79   0.0.0.0         ge-1/1/4        2124      0/0

00:00:26:6f:a7:cf   192.168.20.10   ge-1/1/48       2124      85607/86400

00:00:26:6f:a7:df   192.168.20.15   ge-1/1/48       2124      85842/86400

00:00:26:6f:a7:e0   192.168.20.17   ge-1/1/48       2124      85842/86400

00:00:26:6f:a7:e1   192.168.20.11   ge-1/1/48       2124      85842/86400

00:00:26:6f:a7:e2   192.168.20.14   ge-1/1/48       2124      85842/86400

00:00:26:6f:a7:e3   192.168.20.24   ge-1/1/48       2124      85851/86400

00:00:26:6f:a7:e4   192.168.20.12   ge-1/1/48       2124      85842/86400

00:00:26:6f:a7:e5   192.168.20.13   ge-1/1/48       2124      85842/86400

00:00:26:6f:a7:e6   192.168.20.16   ge-1/1/48       2124      85842/86400

00:00:26:6f:a7:e7   192.168.20.25   ge-1/1/48       2124      85851/86400

00:00:26:6f:a7:e8   192.168.20.20   ge-1/1/48       2124      85847/86400

00:00:26:6f:a7:e9   192.168.20.18   ge-1/1/48       2124      85845/86400

00:00:26:6f:a7:ea   192.168.20.22   ge-1/1/48       2124      85849/86400

00:00:26:6f:a7:eb   192.168.20.21   ge-1/1/48       2124      85848/86400

00:00:26:6f:a7:ec   192.168.20.23   ge-1/1/48       2124      85850/86400

00:00:26:6f:a7:ed   192.168.20.19   ge-1/1/48       2124      85845/86400

18:9c:5d:b7:e4:f4   192.168.20.9    ge-1/1/2        2124      86386/86400

00:00:26:6f:a7:f7   192.168.20.29   ge-1/1/48       2124      85968/86400

00:00:26:6f:a7:f8   192.168.20.27   ge-1/1/48       2124      85968/86400

00:00:26:6f:a7:f9   192.168.20.28   ge-1/1/48       2124      85968/86400

00:00:26:6f:a7:fa   192.168.20.31   ge-1/1/48       2124      85968/86400

00:00:26:6f:a7:fb   192.168.20.26   ge-1/1/48       2124      85968/86400

00:00:26:6f:a7:fc   192.168.20.32   ge-1/1/48       2124      85968/86400

00:00:26:6f:a7:fd   192.168.20.34   ge-1/1/48       2124      85976/86400

00:00:26:6f:a7:fe   192.168.20.30   ge-1/1/48       2124      85968/86400

00:00:26:6f:a7:ff   192.168.20.33   ge-1/1/48       2124      85972/86400

3, Check lldp neighbor.

image002.jpg

 

4,version：

admin@bsrgnj11z-ue40500# run show version

Copyright (C) 2009-2024 Pica8, Inc.

===================================

Base ethernet MAC Address     : a8:2b:b5:f6:ca:01

Hardware Model                : AS4610_54P

Linux System Version/Revision : 4.2.3.10/bcfef5cc80

Linux System Released Date    : 04/03/2024

L2/L3 Version/Revision        : 4.2.3.10/bcfef5cc80

L2/L3 Released Date           : 04/03/2024

 

 

 

 

Here are the testing results:

Total 28 PoE ports are up, of which 5 devices are phones, 2 are Aruba devices, all others are PoE Tester ports
14 LLDP entries
Around 40 DHCP binding entries
All PoE devices can up properly.
 

Looks this issue is related CDP/voice vlan or other factors, which cannot be simulated with PoE tester..

Vivien is applying for other 10 Phones for testing, but it may take some time to be approved and shipped after the holidays.

 

If we can get the devices from Verizon to reproduce this issue with more logging opened, that can save some time and get it fixed quickly.

Thanks,

 

Lin

 

发件人: Don DeRisi <don.derisi@pica8.com>
发送时间: Sunday, January 26, 2025 4:56 AM
收件人: Zoneson Chen <zoneson.chen@pica8.com>; Lin Du <lin.du@pica8.com>; Mikel Tang <mikel.tang@pica8.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
抄送: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>
主题: RE: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

 

Hi All,    good to know access approval can work.  Anyone else needing it please request as you try access.  A message comes to me from SharePoint.

 

Sasi tells me he was able to review the step by step with Lin last night (PT time).

I know troubleshoot and fix analysis underway.

I reviewed the recording and put info in this chart.

 

This is review of leading up to the trouble.  Maybe not needed at this point.

It basically shows stable until after adding 15th phone at 25:51 (port 14)

Prior, 14 phones and 1 cisco navigator using POE, all good. 

 

Exact detail of 15th phone gets power (6.1 W, see below), goes to vlan, but does not get IP is shown.

Maybe a clue here of where code meets trouble.

 

Some timeline highlights

At 23:45 phones get 3.5 W, cisco navigator 6.5 W.

At 24:30 still stable, good show interface brief.  14 phones, 1 cisco navigator.

At 24:53 added 15th phone.

At 25:51 show interface brief gets stuck

Subsequent commands show port 14 (the 15th phone) in voice vlan 2124, but it never gets a DHCP IP.

Also note that the detail at 26:40 shows port 14 allocated 6.1 W (not 3.5 W).   Not sure if detail POE allocated would be same as show poe all “consume” – it should be. This is not a lot of power but maybe a clue.

 

Later in the call we had a reboot and some loss of coordination on how many phones.

Not sure we got a test of reboot with 14 phones to show stable.

More test cases can be defined of course.

 

 

time

command

info

# phones
good

cisco nav

# phones
0.0.0.0 and no good IP

total
entries

 

 

 

 

 

 

 

23:05

show lldp neighbor; and
show dhcp snooping binding

brings us to 14 phones in vlan 2124;
 and 1 cisco navigator vlan 1124 port 17 (100Mb/s)

14

1

 

15

23:45

show poe interface all

still works; port 17 6.5 W, phones 3.5W; 2 still searching

 

 

 

 

24:30

show interface brief

still works

 

 

 

 

24:49

show lldp neighbor

pop-up msg "15 plugged in";
TOTAL 14 phones and 1 cisco navigator = 15 T

14

1

 

15

24:53

 

"he added 1 more phone"; so 15 phones + 1 cisco navigator

 

 

 

 

24:58

show interface brief

still works

 

 

 

 

25:17

show lldp neighbor

show 15 T; (note 0.0.0.0 is new or timing out of table, good IP for same port shown, e.g. port 10 and 12 good IP and 0.0.0.0 will go away; port 14 stays at 0.0.0.0

14

1

1

16

25:25

show dhcp snooping binding

16 entries (cisco port 17 + 14 phones good IP; 1 phone port14 at 0.0.0.0

 

 

 

 

25:35

show dhcp snooping binding

repeats same many times waiting for port 14

 

 

 

 

25:42

show dhcp snooping binding

now port 14 dropped out, so now 15 entries including port 17 cisco navigator

14

1

0

15

25:49

show vlans

15 in vlan 2124 (includes port 14) (ignore uplink port 48)

 

 

 

 

25:51

show interface brief

locked out

 

 

 

 

26:06

 

"15th phone did it!"

 

 

 

 

26:18

ctrl c command interrupt

 

 

 

 

 

26:20

show lldp neighbor

port 14 has 0.0.0.0; 14 phones good IP

 

 

 

 

26:22

show dhcp snooping binding

16 entries: 1 cisco navigator; 14 good phone with IP; port 14 problem phone 0.0.0.

14

1

1

16

26:40

show lldp neighbor ge-1/1/14

detail on port 14 - 8841 phone ; has vlan 2124; requested power 6.1, allocated 6.1W

 

 

 

 

26:54

show interface brief

still stuck

 

 

 

 

27:12

ctrl c command interrupt

 

 

 

 

 

27:16

show poe interface all

 

 

 

 

 

28:07

ctrl c command interrupt

 

 

 

 

 

28:27

show running |match lldp

shows the 2 test commands for POE

 

 

 

 

 

 

Regards,

Don

 

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Saturday, January 25, 2025 12:52 PM
To: Don DeRisi <don.derisi@pica8.com>; Lin Du <lin.du@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com; jackie.xu@feisu.com; 尹娜 <vivien.yin@feisu.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: Re: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

 

Don,

 

Thank you for the approval! I can watch it now.

 

Thanks,

 

Zoneson

 

From: Don DeRisi <don.derisi@pica8.com>
Date: Saturday, January 25, 2025 at 1:16 AM
To: Zoneson Chen <zoneson.chen@pica8.com>, Lin Du <lin.du@pica8.com>, Mikel Tang <mikel.tang@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>, vic.lan@feisu.com <vic.lan@feisu.com>, Angela Hung <angela.hung@pica8.com>, 唐德军 <mikel.tang@feisu.com>, Iris.rong@feisu.com <iris.rong@feisu.com>, jackie.xu@feisu.com <jackie.xu@feisu.com>, 尹娜 <vivien.yin@feisu.com>, Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: Re: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

I approved requests that have come in for Mikel, Lin, and Zoneson.

 

All,  Please request access if needed still.

 

Sasi had access right away.  

 

Regards,

Don

 

From: Zoneson Chen <zoneson.chen@pica8.com>
Sent: Friday, January 24, 2025 10:12 PM
To: Don DeRisi <don.derisi@pica8.com>; Lin Du <lin.du@pica8.com>; Mikel Tang <mikel.tang@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>; vic.lan@feisu.com <vic.lan@feisu.com>; Angela Hung <angela.hung@pica8.com>; 唐德军 <mikel.tang@feisu.com>; Iris.rong@feisu.com <iris.rong@feisu.com>; jackie.xu@feisu.com <jackie.xu@feisu.com>; 尹娜 <vivien.yin@feisu.com>; Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: Re: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

 

Don,

 

I cannot watch. I have requested for privilege to access it. I use my zoneson.chen@pica8.com credentials for Microsoft Office 365, but it fails.

 

Thanks,

 

Zoneson

 

From: Don DeRisi <don.derisi@pica8.com>
Date: Friday, January 24, 2025 at 12:42 PM
To: Lin Du <lin.du@pica8.com>, Mikel Tang <mikel.tang@pica8.com>
Cc: Iris Rong <iris.rong@pica8.com>, vic.lan@feisu.com <vic.lan@feisu.com>, Zoneson Chen <zoneson.chen@pica8.com>, Angela Hung <angela.hung@pica8.com>, 唐德军 <mikel.tang@feisu.com>, Iris.rong@feisu.com <iris.rong@feisu.com>, jackie.xu@feisu.com <jackie.xu@feisu.com>, 尹娜 <vivien.yin@feisu.com>, Sasikumar Puthiyaveedu <Sasikumar.puthiyaveedu@pica8.com>
Subject: RE: Verizon IT - 4.2.3.10 - Seattle switch problems 11 phones, 18 POE total

Troubleshoot recording on Teams

​mp4 icon Pica8 tshoot basking ridge-20250124_134310-Meeting Recording.mp4

 

 

You may need Teams login.

 

Let us know if you can access.
