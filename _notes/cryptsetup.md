---
title: cryptsetup
date: 2019-04-10
---

cryptsetup luksFormat /dev/sdc3

cryptsetup open /dev/sdc3 lilybackup

最后的参数是一个名字，它会是解密后的设备在 /dev/mapper 下的文件名。

如果一切完毕，要记得（在卸载文件系统之后）关闭该设备：

cryptsetup luksClose lilybackup

dm-crypt 是块设备级的加密。我们还要在其上建立文件系统：

mkfs.btrfs /dev/mapper/lilybackup


```
$ sudo cryptsetup luksOpen /dev/sda barn
Enter passphrase for /dev/sda:
device-mapper: reload ioctl on barn (254:1) failed: No such file or directory

$ sudo pacman -S device-mapper
resolving dependencies...
looking for conflicting packages...

Packages (1) device-mapper-2.03.14-2

Total Installed Size:  0.83 MiB
Net Upgrade Size:      0.00 MiB

:: Proceed with installation? [Y/n]
(1/1) checking keys in keyring                                                                  [########################################################] 100%
(1/1) checking package integrity                                                                [########################################################] 100%
(1/1) loading package files                                                                     [########################################################] 100%
(1/1) checking for file conflicts                                                               [########################################################] 100%
(1/1) checking available disk space                                                             [########################################################] 100%
:: Processing package changes...
(1/1) reinstalling device-mapper                                                                [########################################################] 100%
:: Running post-transaction hooks...
(1/4) Reloading system manager configuration...
(2/4) Reloading device manager configuration...
(3/4) Arming ConditionNeedsUpdate...
(4/4) Updating linux initcpios...
==> Building image from preset: /etc/mkinitcpio.d/linux510.preset: 'default'
  -> -k /boot/vmlinuz-5.10-x86_64 -c /etc/mkinitcpio.conf -g /boot/initramfs-5.10-x86_64.img
==> Starting build: 5.10.86-1-MANJARO
  -> Running build hook: [base]
  -> Running build hook: [udev]
  -> Running build hook: [autodetect]
  -> Running build hook: [modconf]
  -> Running build hook: [block]
  -> Running build hook: [keyboard]
  -> Running build hook: [keymap]
  -> Running build hook: [encrypt]
  -> Running build hook: [filesystems]
  -> Running build hook: [fsck]
==> Generating module dependencies
==> Creating gzip-compressed initcpio image: /boot/initramfs-5.10-x86_64.img
==> Image generation successful
==> Building image from preset: /etc/mkinitcpio.d/linux510.preset: 'fallback'
  -> -k /boot/vmlinuz-5.10-x86_64 -c /etc/mkinitcpio.conf -g /boot/initramfs-5.10-x86_64-fallback.img -S autodetect
==> Starting build: 5.10.86-1-MANJARO
  -> Running build hook: [base]
  -> Running build hook: [udev]
  -> Running build hook: [modconf]
  -> Running build hook: [block]
  -> Running build hook: [keyboard]
  -> Running build hook: [keymap]
  -> Running build hook: [encrypt]
  -> Running build hook: [filesystems]
  -> Running build hook: [fsck]
==> Generating module dependencies
==> Creating gzip-compressed initcpio image: /boot/initramfs-5.10-x86_64-fallback.img
==> Image generation successful
```

```
$ sudo cryptsetup luksOpen /dev/sda barn
 Enter passphrase for /dev/sda:
 device-mapper: reload ioctl on barn (254:1) failed: No such file or directory
```

```
Default compiled-in metadata format is LUKS2 (for luksFormat action).

LUKS2 external token plugin support is compiled-in.
LUKS2 external token plugin path: /usr/lib/cryptsetup.

Default compiled-in key and passphrase parameters:
        Maximum keyfile size: 8192kB, Maximum interactive passphrase length 512 (characters)
Default PBKDF for LUKS1: pbkdf2, iteration time: 2000 (ms)
Default PBKDF for LUKS2: argon2id
        Iteration time: 2000, Memory required: 1048576kB, Parallel threads: 4

Default compiled-in device cipher parameters:
        loop-AES: aes, Key 256 bits
        plain: aes-cbc-essiv:sha256, Key: 256 bits, Password hashing: ripemd160
        LUKS: aes-xts-plain64, Key: 256 bits, LUKS header hashing: sha256, RNG: /dev/urandom
        LUKS: Default keysize with XTS mode (two internal keys) will be doubled.
```


    Copy NOS rootfs and NOS kernel and initrd to flash inside the switch;
    Create NOS partitions in USB drive;
    Start NOS kernel and mount initrd;
    Encrypt NOS partitions in USB driver by using cryptsetup with the unique ID as passphrase;
    Mount encrypted NOS partitions;
    Extract NOS rootfs tarball to NOS partitions;
    Change root to NOS rootfs;

Keep the passphrase key in a separate partition on the internal flash

This way the key stays constant across active and standby partitions on the usb and upgrade workflows.

My recommendation is to not generate it using any algorithm, that is akin to a system with default login password. Use a random 256 byte passphrase.

## cryptsetup

: cryptsetup-luks

 /etc/default/cryptdisks 756141f7eacf1a272a2f6e51646b3aa4
 /etc/init.d/cryptdisks 20b58baefc1aed5021a28e2fb9439edd
 /etc/init.d/cryptdisks-early 9c58f4b1314fe50c79ec0caff22bf298
 /etc/init/cryptdisks-udev.conf ed789690d1770e3f3a2682c11e359bb6
 /etc/init/cryptdisks.conf e5527ceb5c020174a6464b81126bb5f7

 Cryptsetup provides an interface for configuring encryption on block
 devices (such as /home or swap partitions), using the Linux kernel
 device mapper target dm-crypt. It features integrated Linux Unified Key
 Setup (LUKS) support.
 .
 Cryptsetup is backwards compatible with the on-disk format of cryptoloop,
 but also supports more secure formats. This package includes support for
 automatically configuring encrypted devices at boot time via the config
 file /etc/crypttab. Additional features are cryptoroot support through
 initramfs-tools and several supported ways to read a passphrase or key.
Homepage: http://code.google.com/p/cryptsetup/
Original-Maintainer: Debian Cryptsetup Team <pkg-cryptsetup-devel@lists.alioth.debian.org>
