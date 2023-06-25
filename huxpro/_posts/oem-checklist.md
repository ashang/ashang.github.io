---
layout: post
title: OEM
date: 2020-05-08 18:00:00 +0100
header-style: text
tags:
  - Web
---

[COMMENT: "restart" would take several minutes]
[COMMENT: will ask Pica8 whether can skip]

YES XX

[Wed Jun 07 16:36:31.101 2023] admin
[Wed Jun 07 16:36:31.776 2023] Password: 
[Wed Jun 07 16:36:33.336 2023] You are required to change your password immediately (administrator enforced)
[Wed Jun 07 16:36:33.344 2023] Changing password for admin.
[Wed Jun 07 16:36:33.349 2023] Current password: [COMMENT: will send: adminadmin]



[Thu Jun 08 09:52:17.217 2023] admin@D-LinkOS> [COMMENT: needed to press <Enter> after seeing "exit"]

https://en.wikipedia.org/wiki/Gluster#GlusterFS

https://en.wikipedia.org/wiki/OverlayFS

https://en.wikipedia.org/wiki/UnionFS

https://quay.io/repository/

## Proposal of changes for OEM.

Part them into Phase 1 and Phase 2 according to priority and needed efforts.

1. Default login credentials are used for the first login.

Exmaple

    Username: admin
    Password : admin
 
Solution: By OEM framework.
Stage: Phase 1.

2. Create unique credentials specifically for shell access, separate from the login credentials used for the operating system.

Example for shell access

    Username "root" 
    password "D!ink$"
 
Solution: Support this feature in login code, and then enable protection via OEM framework.
Stage: Phase 2.

3. Not to show occurrence of "picos" during firmware upgrade/bootup.

Solution: Change module to neutral naming, such as `system` startup, etc.
Stage: Phase 1.

4. OEM to rename SNMP Private MIB

Solution: Support this in OVS code, and then enable protection via OEM framework.
Stage: Phase 1 - Hopefully.
 
5. Default STM share mode is 5, suggested it should be 3.
 
Solution: OEM framework.
Stage: Phase 1

(This one can actually be done by configuration. If the change is wanted, OEM framework can do it, easily.)

6. Use neutral naming for file/command names. Such as changing pica_startup to nos_startup

    /usr/lib/python2.7/dist-packages/pica8

    /usr/lib/python2.7/dist-packages/pica8/picacommand.py

    /usr/lib/python2.7/dist-packages/pica8/picascript.py

    /backup/pica

    /backup/pica/config/pica_startup.boot

    /ovs/snmp/share/snmp/mibs/pica_private_trap_mib.txt
 
Solution: Change in code.
Stage: Phase 2. Lot of Risks. Not all can be committed easily. Needs much efforts.




----

picos-pre.sh -- System-XX
picos.sh -- System-XX

LABEL:
PICOS-GRUB      NOS-GRUB
PicOS           NOS
PicOS2          NOS2


/etc/picos      /etc/nos

/picos_boot     nos_boot
# OEM config file

## The old way
* compiling para:
``````
  --with-brand-name=\"$sBrand\" \
  --with-company-name=\"$sCom\" \
  --with-platform-name=\"$sPlat\" \
  --with-host-name=\"$sHost\"\r"
``````
## lsb-release(Linux Standard Base)
### /etc/lsb-release
- DISTRIB_ID=Pica8, Inc
- DISTRIB_CODENAME=PicOS
- DISTRIB_MACHINE="platform"
- DISTRIB_MODEL="model for certain brand"
### pica/etc/lsb-release interface for L2L3
- DISTRIB_ID=Pica8, Inc
- DISTRIB_CODENAME=PicOS L2L3
- DISTRIB_MACHINE="platform"
- DISTRIB_MODEL="model for certain brand"
### /ovs/etc/lsb-release interface for OVS
- DISTRIB_ID=Pica8, Inc
- DISTRIB_CODENAME=PicOS OVS
- DISTRIB_MACHINE="platform"
- DISTRIB_MODEL="model for certain brand"

## /etc/brand
- used for one package against different model(like as4610 to as4610_30/54/p/t)

## /etc/picos/picos_start.conf

## /ovs/etc/feature.conf

## Refined

We agree with all the changes and opinions you mentioned.
The refined checkpoint document is all based on your proposals.

I don't have well-OEMed HW at hand, so the output log is only for your referneces.

Summary
================

## Checkpoints changed
- Add a section for "Switching Between configuration CLI and Linux shell"
- Change the order of checking points
  - In natural order of one run of ONIE info checking, then NOS installation and NOS Running.
- Use "> show ..." in NOS CLI, not "# run show" in configuration mode.
- Add who to check bootup hardware info outpu
- Make the checking more automation possible, for later automation or CI/CD usage
  - If the point to check or checking purpose is the same, prefer the means that can be done via commands.
  - For example, checkong output of "$ hostname", instead of looking for the output from command prompts.
  - For example, checkong HW info from commands, instead of looking for the output during bootup.

## Checkpoints skipped
- LLDP
  - It needs complex environment setup
- SNMP
  - It needs complex environment setup
- switching between "xorplus" and "ovs": the picos_boot part
  - It's for development verification purpose.
  - It consumes a lot of time.
- reboot
  - It consumes a lot of time.
  - The output can be get at startup.
- get a licence key into the switch
  - It doesn't impact basic functions for verification purpose.
  - Only production deployment needs to enable all ports.

## Others
- ONIE Uninstall
  - It's optional in our side. So please add this step if you think needed.
- BIOS checking
  - NOS has no means to impact this, so it is not necessary.
- Startup screen output
  - All check points from screen output can be checked from running systems by commands or reading from certain files.
  - Exceptions are some temporary info such as time stamps, which can be ignored.
- dmidecode parts are optional. That's good for double confirmation. You can add if needed.
