---
date: 2019-05-21
title: ARM VFP detection
---

  


  
ARM VFP detection

  
A CPU has VFPv3 hardware if the FPSID[19:16] bits are 2 or more.  
Currently Linux was only checking for 3 or more.  
  
arch/arm/vfp/vfpmodule.c  


[http://goo.gl/75bzu](http://goo.gl/75bzu)

  


 #ifdef CONFIG_VFPv3

-               if (VFP_arch >= 3) {

+               if (VFP_arch >= 2) {

                        elf_hwcap |= HWCAP_VFPv3;

  


  


The subarchitecture field in the fpsid register is 7 bits wide.

The topmost bit is used to designate that the subarchitecture designer is not ARM.

  


This change has the side effect of causing VFP implementations other than ARM to be reported as VFPv3 with common VFP subarch v3.  
Before this change it would be reported as VFPv1 with an implementation defined subarchitecture.

  


The VFP version is stored in ARM FPSID register of SUBARCH[22:16], and the reset value is 0b100_0000.  


But in vfp_init() of vfpmodule.c, the SUBARCH is treated as SUBARCH [19:16], so it is judged as normal VFP. 

  


The V8 javascript engine looks for vfpv3 in /proc/cpuinfo when deciding how to generate code. 

If it only report support for vfp, slower code will be generated.

  


$ adb shell cat /proc/cpuinfo

Processor       : ARMv7 Processor rev 8 (v7l)

processor       : 0

BogoMIPS        : 31.25

  


Features        : swp half thumb fastmult vfp edsp neon vfpv3

CPU implementer : 0x15

CPU architecture: 7

CPU variant     : 0x0

CPU part        : 0x02d

CPU revision    : 8

  


Hardware        : foobar

Revision        : 0000

Serial          : 0000000000000000

  

