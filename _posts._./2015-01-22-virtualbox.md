---
Title: VirtualBox
Date: 2007-01-17 20:59
---

对于 VMWare、Virtual PC
这些虚拟机软件，可能大家都比较熟悉。今天我要介绍的是另一个虚拟机软件——[VirtualBox](http://www.virtualbox.org/)。VirtualBox
是一款功能强大的 x86
虚拟机软件，它不仅具有丰富的特色，而且性能也很优异。更可喜的是，VirtualBox
于数日前走向开源，成为了一个发布在 GPL 许可之下的自由软件。

[![VirtualBox](http://i.linuxtoy.org/i/2007/01/virtualbox_s.png)](http://i.linuxtoy.org/i/2007/01/virtualbox.png)


$ vboxmanage convertdd PolarOS-20201014-0.img PolarOS-20201014-0.vdi

$ sudo bash VirtualBox-6.0.10-132072-Linux_amd64.run
Verifying archive integrity... All good.
Uncompressing VirtualBox for Linux installation.............
VirtualBox Version 6.0.10 r132072 (2019-07-12T09:14:52Z) installer
depmod: WARNING: could not open /lib/modules/4.15.0-42-generic/modules.order: No such file or directory
depmod: WARNING: could not open /lib/modules/4.15.0-42-generic/modules.builtin: No such file or directory
Removing previous installation of VirtualBox 5.2.16 r123759 from /opt/VirtualBox
Installing VirtualBox to /opt/VirtualBox
Python found: python, installing bindings...

VirtualBox has been installed successfully.

You will find useful information about using VirtualBox in the user manual
  /opt/VirtualBox/UserManual.pdf
and in the user FAQ
  http://www.virtualbox.org/wiki/User_FAQ

We hope that you enjoy using VirtualBox.





# Headless
```
$ vboxmanage list vms
$ vboxheadless -s deb8-20200303
xcb_connection_has_error() returned true



```
#

$ virtualbox
WARNING: The character device /dev/vboxdrv does not exist.
         Please install the virtualbox-dkms package and the appropriate
         headers, most likely linux-headers-amd64.

         You will not be able to start VMs until this problem is fixed.

$ sudo apt install linux-headers-amd64
Reading package lists... Done
Building dependency tree
Reading state information... Done
Package linux-headers-amd64 is not available, but is referred to by another package.
This may mean that the package is missing, has been obsoleted, or
is only available from another source

E: Package 'linux-headers-amd64' has no installation candidate

$ sudo apt install linux-headers
Reading package lists... Done
Building dependency tree
Reading state information... Done
Package linux-headers is a virtual package provided by:
...

$ sudo apt install linux-headers-generic


$ sudo bash VirtualBox-6.0.10-132072-Linux_amd64.run
Verifying archive integrity... All good.
Uncompressing VirtualBox for Linux installation.............
VirtualBox Version 6.0.10 r132072 (2019-07-12T09:14:52Z) installer
depmod: WARNING: could not open /lib/modules/4.15.0-42-generic/modules.order: No such file or directory
depmod: WARNING: could not open /lib/modules/4.15.0-42-generic/modules.builtin: No such file or directory
Removing previous installation of VirtualBox 5.2.16 r123759 from /opt/VirtualBox
Installing VirtualBox to /opt/VirtualBox
Python found: python, installing bindings...

VirtualBox has been installed successfully.

You will find useful information about using VirtualBox in the user manual
  /opt/VirtualBox/UserManual.pdf
and in the user FAQ
  http://www.virtualbox.org/wiki/User_FAQ

We hope that you enjoy using VirtualBox.



# Extension_Pack
Oracle_VM_VirtualBox_Extension_Pack-6.1.6.vbox-extpack

名称:
Oracle VM VirtualBox Extension Pack
版本:
6.1.6r137129
描述:
Oracle Cloud Infrastructure integration, USB 2.0 and USB 3.0 Host Controller, Host Webcam, VirtualBox RDP, PXE ROM, Disk Encryption, NVMe.

安装扩展包 /home/ashang/Oracle_VM_VirtualBox_Extension_Pack-6.1.6.vbox-extpack 失败。

The installer failed with exit code 127: Error creating textual authentication agent: Error opening current controlling terminal for the process (`/dev/tty'): No such device or address.

返回 代码: NS_ERROR_FAILURE (0x80004005)
组件: ExtPackManagerWrap
界面: IExtPackManager {70401eef-c8e9-466b-9660-45cb3e9979e4}


# Headless

> VBoxHeadless. A front-end that produces no visible output on the host at all, but can
> act as a RDP server if the VirtualBox Remote Desktop Extension (VRDE) is installed and
> enabled for the VM. As opposed to the other graphical interfaces, the headless front-end
> requires no graphics support. This is useful, for example, if you want to host your virtual
> machines on a headless Linux server that has no X Window system installed.

It is not indended for X over SSH.

# Webcam passthrough
# PXE boot ROM.
# PCI passthrough
# Disk image encryption with AES algorithm

