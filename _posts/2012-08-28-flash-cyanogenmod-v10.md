---
author: aaronshang
comments: true
date: 2012-08-28 01:14:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2012/08/28/flash-cyanogenmod-v10/
slug: flash-cyanogenmod-v10
title: Flash CyanogenMod v10
wordpress_id: 1031
---

  


Find your device image here:____

[http://www.cyanogenmod.com/devices](http://www.cyanogenmod.com/devices)

  


Here is for Sony Ericsson Xperia Play, etc.

[http://www.cyanogenmod.com/devices/sony-ericsson-xperia-play-gsm](http://www.cyanogenmod.com/devices/sony-ericsson-xperia-play-gsm)

  


If you see boot-device_code.img for your prototype, also download it to use for the boot.img.____

Push the image zip file to your phone storage.____

  


Your device should be unlockable and unlocked, check here for Sony Ericsson Arc, etc

[http://unlockbootloader.sonymobile.com/](http://unlockbootloader.sonymobile.com/)____

  


At least you should get fastboot and android driver to your PC.____

If you work on a Linux system, it's OK to just get a Linux version fastboot.____

  
  


Steps:____

Power on your device, while press the unlock button.____

Some unlock button according to different devices.____

__·         __Menu button (for Xperia™ arc, Xperia™ arc S, Xperia™ neo, Xperia™ neo V, Xperia™ pro).____

__·         __Search button (for Xperia™ PLAY).____

__·         __Volume up button (for Xperia™ mini, Xperia™ mini pro, Xperia™ ray, Xperia™ active, Live with Walkman™, Xperia™ S).____

  


Check if fastboot can work on the device, version 0.3 means you can continue.____

**fastboot -i 0x0fce getvar version____**

_version: 0.3_____

_finished. total time: 0.000s_____

  


Then flash the boot image.____

**fastboot flash boot boot.img____**

_sending 'boot' (5290 KB)..._____

_(bootloader) USB download speed was 9707kB/s_____

_OKAY [  0.562s]_____

_writing 'boot'..._____

_(bootloader) Download buffer format: boot IMG_____

_(bootloader) Flash of partition 'boot' requested_____

_(bootloader) S1 partID 0x0000000C, block 0x00000280-0x00000BeC___

_(bootloader) Erase operation complete, 0 bad blocks encountered_____

_(bootloader) Flashing..._____

_(bootloader) Flash operation complete_____

_OKAY [  1.109s]_____

_finished. total time: 1.672s_____

  


__Reboot your device, press volume done button many times during booting. (* indeed, once is OK just after the front keypad is lighten.)

__

  


Using the menu with volume up/down and back to navigate, and Home (on some devices it is Power) button to select, wipe your user data, wipe your cache, and then install update zip file. Wait for the update is finished, then back to upper menu and select to restart the device.____

  


Now you have Jelly Bean, which is now Android 4.1.1.
