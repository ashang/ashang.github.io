---
date: 2018-07-16
title: vim yanking
---

> Kernel driver not installed (rc=-1908)

The VirtualBox Linux kernel driver (vboxdrv) is probably not loaded.You may not have kernel driver installed for kernel that is runnig, if so you may do as root: dnf install akmod-VirtualBox kernel-devel-$(uname -r)If you installed VirtualBox packages and don't want reboot the system, you may need load the kernel driver, doing as root: akmods; systemctl restart vboxdrv.service

If your system has EFI Secure Boot enabled you may also need to sign the kernel modules (vboxdrv, vboxnetflt, vboxnetadp, vboxpci) before you can load them. Please see your Linux system's documentation for more information.

where: suplibOsInit what: 3 VERR_VM_DRIVER_NOT_INSTALLED (-1908) - The support driver is not installed. On linux, open returned ENOENT



