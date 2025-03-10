---
#layout: page
layout: base
title: picos
---

```sh
root@Xorplus:/home/admin# version 
Copyright (C) 2009-2018 Pica8, Inc.
===================================
Hardware Model                : DELL S4048-ON
Linux System Version/Revision : 3.1.0/3bdda77
Linux System Released Date    : 12/25/2018
L2/L3 Version/Revision        : 3.1.0/3bdda77
L2/L3 Released Date           : 12/25/2018
OVS/OF Version/Revision       : 3.1.0/3bdda77
OVS/OF Released Date          : 12/25/2018

root@Xorplus:/home/admin# system-diag 
************ System Diagnosis Start ************
Date: Thu Dec 27 09:47:48 UTC 2018
Version:
	Copyright (C) 2009-2018 Pica8, Inc.
	===================================
	Hardware Model                : DELL S4048-ON
	Linux System Version/Revision : 3.1.0/3bdda77
	Linux System Released Date    : 12/25/2018
	L2/L3 Version/Revision        : 3.1.0/3bdda77
	L2/L3 Released Date           : 12/25/2018
	OVS/OF Version/Revision       : 3.1.0/3bdda77
	OVS/OF Released Date          : 12/25/2018
	ONIE version	: 3.21.1.1
	CPLD1 version	: 0xf
	CPLD2 version	: 0xc
	CPLD3 version	: 0x5
Hardware information:
	MAC address	: 34:17:EB:FA:90:C4
	Serial number	: CN099TJK282985640054
	Product name	: S4048ON
PSU:
	PSU 1 status	: not present
	PSU 2 status	: present and powered on
System FAN:
	Fan 1 OK, fan speed is 6553
	Fan 2 OK, fan speed is 6597
	Fan 3 OK, fan speed is 6597
	Fan 4 OK, fan speed is 6597
	Fan 5 fault
	Fan 6 fault
Temperature:
	CPU temperature		: 28 C / 82 F
	Switch chip temperature	: 29 C / 84 F
	Board temperature	: 23 C / 73 F
Optical modules:
	Port 1 Module type: Unknown id (0x61); Vendor name: uuuu; Serial number: A85351050276
	Port 2 Module type: SFP; Vendor name: DELTA; Serial number: 083209000010
	Port 3 Module type: SFP; Vendor name: FINISAR; Serial number: H122BS4
	Port 4 Module type: SFP; Vendor name: FINISAR; Serial number: P1182B5
	Port 5 no module
	Port 6 no module
	Port 7 no module
	Port 8 no module
	Port 9 no module
	Port 10 no module
	Port 11 no module
	Port 12 no module
	Port 13 no module
	Port 14 no module
	Port 15 no module
	Port 16 no module
	Port 17 no module
	Port 18 no module
	Port 19 no module
	Port 20 no module
	Port 21 no module
	Port 22 no module
	Port 23 no module
	Port 24 no module
	Port 25 no module
	Port 26 no module
	Port 27 no module
	Port 28 no module
	Port 29 no module
	Port 30 no module
	Port 31 no module
	Port 32 no module
	Port 33 no module
	Port 34 no module
	Port 35 no module
	Port 36 no module
	Port 37 no module
	Port 38 no module
	Port 39 no module
	Port 40 no module
	Port 41 no module
	Port 42 no module
	Port 43 no module
	Port 44 no module
	Port 45 no module
	Port 46 no module
	Port 47 no module
	Port 48 no module
	Port 49 no module
	Port 50 no module
	Port 51 no module
	Port 52 no module
	Port 53 no module
	Port 54 no module
RTC:
	RTC is OK!
	Time	: Thu Dec 27 09:47:49 2018  -0.364242 seconds
Disk space:
	/dev/sda	: 7641 MB
	/dev/sda2	: 128 MB
	/dev/sda3	: 300 MB
	/dev/sda4	: 16 MB
	/dev/sda5	: 2048 MB	(Rootfs)
	/dev/sda6	: 2048 MB
	/dev/sda7	: 3098 MB
	/dev/sdb1	: 486 MB
	/dev/sda1	: 2 MB
	Free space of rootfs partition is 324 MB.
Memory size:
	Total memory	: 2015156 KB
	Free memory	: 967324 KB
CPU utilization: 24.16%
```