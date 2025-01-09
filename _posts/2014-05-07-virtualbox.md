---
title: VirtualBox notes
date: 2007-01-17
---

To share files into VirtualBox, add the share before starting the VM

    `VBoxManage sharedfolder add "VMname" -name "myshare" -hostpath "/path/to/share"`

Then mount the share

    `\\vboxsvr\myshare`


```
$ sudo dpkg-reconfigure virtualbox-dkms

-------- Uninstall Beginning --------
Module:  virtualbox
Version: 6.1.16
Kernel:  5.8.0-54-generic (x86_64)
-------------------------------------

Status: Before uninstall, this module version was ACTIVE on this kernel.

vboxdrv.ko:
 - Uninstallation
   - Deleting from: /lib/modules/5.8.0-54-generic/updates/dkms/
 - Original module
   - No original module was found for this module on this kernel.
   - Use the dkms install command to reinstall any previous module version.


vboxnetadp.ko:
 - Uninstallation
   - Deleting from: /lib/modules/5.8.0-54-generic/updates/dkms/
 - Original module
   - No original module was found for this module on this kernel.
   - Use the dkms install command to reinstall any previous module version.


vboxnetflt.ko:
 - Uninstallation
   - Deleting from: /lib/modules/5.8.0-54-generic/updates/dkms/
 - Original module
   - No original module was found for this module on this kernel.
   - Use the dkms install command to reinstall any previous module version.

depmod...

DKMS: uninstall completed.

------------------------------
Deleting module version: 6.1.16
completely from the DKMS tree.
------------------------------
Done.
Loading new virtualbox-6.1.16 DKMS files...
Building for 5.8.0-54-generic
Building initial module for 5.8.0-54-generic
Done.

vboxdrv.ko:
Running module version sanity check.
 - Original module
   - No original module exists within this kernel
 - Installation
   - Installing to /lib/modules/5.8.0-54-generic/updates/dkms/

vboxnetadp.ko:
Running module version sanity check.
 - Original module
   - No original module exists within this kernel
 - Installation
   - Installing to /lib/modules/5.8.0-54-generic/updates/dkms/

vboxnetflt.ko:
Running module version sanity check.
 - Original module
   - No original module exists within this kernel
 - Installation
   - Installing to /lib/modules/5.8.0-54-generic/updates/dkms/

depmod...

DKMS: install completed.

```

VirtualBox
-   Teleportation
    （实时迁移）；允许将一个正在运行的虚拟机迁移到另一台机器上；
-   虚拟机状态可以恢复到快照；
-   可以在虚拟机运行时更改网络连接模式；
-   PAE 和 AMD64 客户机显著的性能提升（仅限VT-x 和 AMD-V ，非 nested paging)；
-   EFI (Extended Firmware Interface) 支持
-   VirtIO 网络设备支持
+ 多头虚拟显示器
+ Hot-plug CPU
+ 联机快照合并
-   不同主机间迁移时，自动变更声卡模式，比如从 DirectAudio 变为 PulseAudio 。
-   Web 管理界面对于半角字符也使用 UTF-8 处理，而不再是 ASCII。
-   USB 2.0 EHCI 控制器和 RDP 服务器移入到 Extension
    Pack，不再包含在发布版本当中，保证了 VirtualBox
    是完全的开源软件。USB 1.1 OHCI
    控制器一直是核心部件，两者的区别在于传输速度。
-   增加 Open Virtualization Format Archive （OVA 格式）的支持。
-   copy-and-paste

-   在 Linux 主机上实现试验性的 PCI Passthrough 支持。
-   新的网卡模式“通用驱动”。
-   新的网络连接模式 UDP Tunnel。

## VirtualBox 的命令行界面程序为
VBoxManage
通过它你可以完成从命令行创建虚拟机、修改虚拟机的选项设置、对虚拟机进行控制等几乎所有的操作。如果在
Headless Server 上，你将发现 VirtualBox 的命令行界面非常有用。

通过执行 `VBoxManage --help` 命令，你可以获得 VBoxManage
的完整用法。本文并不打算解释其中的每一个选项，仅给出创建一个虚拟机的必要步骤。如果你感兴趣，不妨亲自去探索
VBoxManage 的其他用法。

VBoxManage createvm --name "Ubuntu 9.10" --register

 创建该虚拟机所用的虚拟硬盘，用 `--filename`
指定虚拟硬盘的名称，`--size` 选项指定虚拟硬盘的大小，本例为 5 GB：

VBoxManage createhd --filename "Ubuntu910.vdi" --size 5000 --remember

修改虚拟机的选项设置：

VBoxManage modifyvm "Ubuntu 9.10" --memory "512MB" --hda
"Ubuntu910.vdi" --dvd /home/linuxtoy/karmic-desktop-i386.iso --acpi
on --accelerate3d on --boot1 dvd --nic1 nat

其中，

* `--memory` 指定内存的大小
* `--hda` 指定所用的虚拟硬盘
* `--dvd` 指定所用的 ISO 映像
* `--acpi on` 启用 ACPI
* `--accelerate3d on` 启用 3D 加速
* `--boot1` 引导次序
* `--nic1` 网络设置

如果你愿意，那么现在便可以通过 `VBoxManage startvm "Ubuntu 9.10"`
来启动虚拟机。

## Teleportation

实现实时迁移的条件之一就是要先把虚拟机存储文件存放在公共的存储空间，因此需要设定一个共享存储
(Shared Storage)

的空间，让实现迁移的两台实体主机都能够连接到共享存储空间上的虚拟媒体文件，包括虚拟磁盘、虚拟光盘和虚拟软盘。否则，即使迁移完成以后，也会因为无法启动迁移后的虚拟机。实时迁移实际上把虚拟机的各个配置文件封装在一个文件，然后透过高速网络，把这个封装文件和内存运行状态从一台实体机迅速传送到另外一台实体机上，期间虚拟机一直保持运行状态。在现有技术条件下，大多虚拟机软件，如
VMware、KVM、Hyper-V、Xen 都需要共享存储。VirtualBox 支持 NFS 和
SMB/CIFS
协议的网络文件系统，也可以支持 iSCSI 连接到 SAN
网络。选用哪一种网络文件系统，则需要根据具体情况而定。SMB/CIFS 在
Windows
和 Linux 都设置简便。NFS 在 Windows 则略显繁复。

    Source 机
    CPU: Pentium E2160
    RAM: 2GB
    OS: Fedora 12 x86_64

    Target 机
    CPU: Athlon 64 X2 4200+
    RAM: 2GB
    OS: Windows 7 Ultimate x64

    Guest 机
    Name: XP
    CPU: Virtual Single-Core Processor without VT
    RAM: 1GB
    OS: Windows XP Professional

首先架设一个共享存储环境，我就选用了 SMB/CIFS 协议，在
Source 机架设了 Samba

服务。如果把共享存储服务放置在第三台电脑上会更好，但是我由于条件所限只能把共享存储服务安装在
Source 机上。具体方法就不再详述了。然后移动 Source
机上的虚拟磁盘文件到共享存储服务器上。重新注册到
Source 机上的 VirtualBox，并重新连接到 Guest 机，即可启动 Guest
机。

在 Target 机上新建一个虚拟机。虚拟机的配置和特性要求与
Source 机上的 Guest
机完全一致。随后把共享存储上的虚拟磁盘文件连接到这台虚拟机上。随后在
Target 机运行如下命令：

VBoxManage modifyvm --teleporter
on --teleporterport --teleporterpassword

以我的试验为例：

VBoxManage modifyvm XP --teleporter on --teleporterport
1234 --teleporterpassword 123456

若是在 Windows 上使用 VBoxManage
命令行，则需要在命令提示符进入 VirtualBox 的安装目录，用
VBoxManage.exe 替代 VBoxManage，使用效果是一样的。

以上命令瞬间执行完毕，然后启动 Target 机上的 Guest
机。此时 VirtualBox
弹出等待迁移的窗口。若取消迁移，可以按下窗口上的关闭键。

![等待迁移](http://dl.dropbox.com/u/1352061/photo/teleportation-1.jpeg)

然后在 Source 机运行迁移命令：

VBoxManage controlvm teleport --host // --port --password

以我的试验为例：

VBoxManage controlvm XP teleport --host 192.168.1.3 --port
1234 --password 123456

![迁移中](http://dl.dropbox.com/u/1352061/photo/teleportation-2.jpeg)

Source 机和 Target 机的 VirtualBox 控制台同样出现了正在
Teleporting 的状态：

![正在迁移](http://dl.dropbox.com/u/1352061/photo/teleportation-3.jpeg)

迁移过程实际上是很短暂的。VirtualBox
把虚拟机的配置文件封装并与虚拟机内存运行状态一并从
Source 机传送到 Target 机即可。按照我家里的网络情况，TP-Link
百兆家用路由器搭建的局域网，大约 20
秒的时间就可以完成迁移过程。VirtualBox
显示的剩余时间实际上是没有意义的。迁移前段 VirtualBox
进行文件校验应该会花费不少时间。实际所需要的时间是根据网络情况与
Source 机和 Target 机的性能配置而定。

当迁移完成以后，Source 机上的 Guest 机自动关闭，而 Target
机上的 Guest 自动启动并且恢复到 Guest
机关闭前的那一刻状态。此时VirtualBox 控制台就会显示
Teleported 状态。

![完成迁移](http://dl.dropbox.com/u/1352061/photo/teleportation-4.jpeg)

当 Guest 机下一次在 Target
机上启动前，需要把实时迁移的功能关闭，否则就会出现等待迁移的界面。

VBoxManage modifyvm XP --teleporter off

至此，整个实时迁移的试验宣告完成了。此外我更换了 Target
机的 OS，改为与 Source 机一样的 Fedora 12
x86\_64，似乎迁移的稳定性会更加好。以上截图大多数取自第二次迁移试验。

**注意事项：**

1. 在 VirtualBox 上运用实时迁移功能，Source 机和 Target
机的硬件配置越接近越相似出现错误的机会就会越少。如果
Source 机和 Target

机硬件配置一致，那么出现兼容性的问题就非常地小。特别是两台机器的处理器，尽量要相近的型号。型号差异过大，则非常容易导致出错，尤其是
Guest

机内运行着专门为特定处理器优化的软件。当在两台处理差异过大的机器上进行实时迁移，特别是在跨品牌处理器之间(主要是
AMD 与 Intel)
的迁移，那么建议用户关闭虚拟处理器的筛选器。命令如下
(后面<>为命令选项)：

VBoxManage modifyvm --cpuid

2. 实施迁移前，一定要确保 Source 机和 Target 机上的 Guest
机硬件配置和设置都是一样的，特别是 System 和 Display
的选项一定要保持一致，同样也需要采用相同的虚拟网卡。VirtualBox
的实时迁移功能并不需要依赖 VT 技术，但是不能在一台没有
VT 的 Guest 机和一台开启 VT 的 Guest
机之间迁移，否则就会出现错误。

3. 最好配备有千兆局域网或者更好的网络条件，因为 Guest

机的磁盘操作需要较高的速率，如果仅仅靠百兆局域网，那么速率上的限制和操作上的延时则极大地影响文件操作的效率和适用体验。

**总结**

VirtualBox 3.1

带来了实时迁移能力，实在让人惊喜。这应该是第一款跨处理器品牌跨平台的虚拟机软件，能够在
Windows、Linux、Mac OS X 和 Solaris
平台上进行实时迁移。良好的易用性，一直都是 VirtualBox
的优点。不过看起来，实时迁移对于 VirtualBox

而言还是刚刚起步，还有很远的路要走。没有为实时迁移这种重量级的特性配备图形化操作界面对
VirtualBox
这款以易用闻名的虚拟机来说，不得不说是一个遗憾。

最后，限于条件，我没有带有 VT 技术的 Intel
处理器。如果哪位热心朋友有这样的条件，可以进行一次带有
VT 的 AMD 与 Intel

的实时迁移试验，将会更有挑战性，因为这种情况下更容易出现处理器兼容性的问题。

{ Thanks liangsuilong. }
---
title: VirtualBox 更新到 1.5.6
date: 2008-02-20
---


开源虚拟机软件
[VirtualBox](http://linuxtoy.org/archives/virtualbox.html) 已更新到了
1.5.6
版。其中，一些有意思的更改内容包括：修正了无缝模式和全屏模式的问题，改善了
Solaris 客户机的性能，支持只读共享文件夹，支持 E1000 设备模拟，与 Kernel
2.6.24 的兼容性更好，等等。

![VirtualBox](http://i.linuxtoy.org/i/2007/10/virtualbox.png)

VirtualBox 1.5.6 的完整更改记录如下：

* GUI: ﬁxed several error messages
* GUI: ﬁxed registration dialog crashes once and for all
* GUI: really ask before resetting the VM
* GUI: release mouse and keyboard before the host activates the
screensaver
* GUI: ﬁxed issue with license display on big screens
* GUI: added setting for network name for internal networks
* GUI: added setting for network device type
* GUI: keyboard ﬁxes
* GUI: seamless mode and fullscreen mode ﬁxes
* GUI: ﬁxed soaked hostkey keyup event under certain conditions
* GUI: more informative message dialog buttons
* GUI: VM selector context menu
* VBoxSDL: added -termacpi switch
* VBoxSDL: ﬁxed automatic adaption of the guest screen resolution to
the size of the VM window
* VMM: under heavy guest activity, for example when copying ﬁles
to/from a shared folder, the VM could crash with an assertion
* VMM: added an option to select PIIX4 (improves compatibility with
Windows guests created by VMware)
* VMM: ﬁxed a bug which could lead to memory corruption under rare
circumstances
* VMM: improved performance of Solaris guests
* VRDP: ﬁxed a 1.5.4 regression VRDP client and server were
out-of-sync if the VM was started using the GUI
* VRDP: proper error handling if the VRDP library could not be loaded
* VBoxManage: ﬁxed crash during clonevdi
* VBoxManage: added ’list runningvms’ command
* VBoxManage: improved the compatibility when reading the partition
table of a raw disk
* Shared Folders: added support for read-only shared folders
* Shared Clipboard: several ﬁxes
* Network: experimental support for E1000 device emulation
* iSCSI: better check for misconﬁgured targets
* iSCSI: allow to directly attach to internal networks with integrated
mini IP stack
* PulseAudio: don’t hang during VM initialization if no sound server
is available
* VDI: ﬁxed sized virtual disk images are now completely written
during creation to workaround buggy sparse ﬁle handling on some OS (e.g.
Vista)
* VDI/VMDK: prevent indexing of .vdi and .vmdk ﬁles on Windows hosts
* RDP: ﬁxed compilation of the Linux rdesktop client on newer Linux
kernels
* RDP: install rdesktop-vrdp on Linux hosts
* ACPI: added sleep button event
* Serial: proper handling of inaccessible host devices
* Windows installer: allow smooth upgrade without deinstallation
* Linux installer: ﬁxed Slackware detection regression
* Linux installer: updated VBoxTunctl allowing to assign a tap device
to a group on Linux kernels > 2.6.23
* Windows additions: several ﬁxes, in particular for Windows NT4
* Linux additions: ﬁxed installer for Kubuntu 8.04
* Linux additions: add default video mode for handling video mode
hints from the host
* Linux host: compatibility ﬁxes with Linux > 2.6.24

- [下载 VirtualBox 1.5.6](http://www.virtualbox.org/wiki/Downloads)
---
title: VirtualBox 更新至 3.0.12
date: 2009-11-18
---


今天，Sun 将旗下的[开源虚拟机软件
VirtualBox](http://linuxtoy.org/archives/virtualbox.html) 升级到了
3.0.12
版本。该版本主要对之前版本中的缺陷进行了修正。

在 VirtualBox 3.0.12 中修正的缺陷包括：

* VMM: reduced IO-APIC overhead for 32 bits Windows NT/2000/XP/2003
guests; requires 64 bits support (VT-x only; bug #4392)
* VMM: fixed double timer interrupt delivery on old Linux kernels
using IO-APIC (caused guest time to run at double speed; bug #3135)
* VMM: reinitialize VT-x and AMD-V after host suspend or hibernate;
some BIOSes forget this (Windows hosts only; bug #5421)
* VMM: fix loading of saved state when RAM preallocation is enabled
* BIOS: ignore unknown shutdown codes instead of causing a guru
meditation (bug #5389)
* GUI: never start a VM on a single click into the selector window
(bug #2676)
* Serial: reduce the probability of lost bytes if the host end is
connected to a raw file
* VMDK: fix handling of split image variants and fix a 3.0.10
regression (bug #5355)
* VRDP: fixed occasional VRDP server crash
* Network: even if the virtual network cable was disconnected, some
guests were able to send / receive packets (E1000; bug #5366)
* Network: even if the virtual network cable was disconnected, the
PCNet card received some spurious packets which might confuse the guest
(bug #4496)
* Shared folders: fixed changing case of file names (bug #2520)
* Windows Additions: fix crash in seamless mode (contributed by
Huihong Luo)
* Linux Additions: fix writing to files opened in O\_APPEND mode (bug
#3805)
* Solaris Additions: fix regression in guest additions driver which
among other things caused lost guest property updates and periodic error
messages being written to the system log

详情可参阅
[ChangeLog](http://www.virtualbox.org/wiki/Changelog)。你可以从[这里下载
VirtualBox 3.0.12
的二进制包](http://download.virtualbox.org/virtualbox/3.0.12/)。
---
title: VirtualBox 更新到 3.0.2
date: 2009-07-11
---


Sun 在今天将 VirtualBox 更新到了 3.0.2
版本。[VirtualBox](http://linuxtoy.org/archives/virtualbox.html)
是一个开源、跨平台的虚拟机软件，新的 3.0.2 版主要修正了
[3.0](http://linuxtoy.org/archives/virtualbox-30-released.html)
中的缺陷和回归问题。

参阅 VirtualBox 3.0.2
[Changelog](http://www.virtualbox.org/wiki/Changelog)：

* VMM: fixed network regressions (guest hangs during network IO) (bug
#4343)
* VMM: guest SMP performance improvements
* VMM: fixed hangs and poor performance with Kaspersky Internet
Security (VT-x/AMD-V only; bug #1778)
* VMM: fixed crashes when executing certain Linux guests (software
virtualization only; bugs #2696 & #3868)
* ACPI: fixed Windows 2000 kernel hangs with IO-APIC enabled (bug
#4348)
* APIC: fixed high idle load for certain Linux guests (3.0
regression)
* BIOS: properly handle Ctrl-Alt-Del in real mode
* iSCSI: fixed configuration parsing (bug #4236)
* OVF: fix potential confusion when exporting networks
* OVF: compatibility fix (bug #4452)
* NAT: fixed crashes under certain circumstances (bug #4330)
* 3D support: fixed dynamic linking on Solaris/OpenSolaris guests (bug
#4399)
* 3D support: fixed incorrect context/window tracking for
multithreaded apps
* Shared Folders: fixed loading from saved state (bug #1595)
* Shared Folders: host file permissions set to 0400 with Windows guest
(bug #4381)
* X11 host and guest clipboard: fixed a number of issues, including
bug #4380 and #4344
* X11 Additions: fixed some issues with seamless windows in X11 guests
(bug #3727)
* Windows Additions: added VBoxServiceNT for NT4 guests (for time
synchronization and guest properties)
* Windows Additions: fixed version lookup
* Linux hosts: workaround for buggy graphics drivers showing a black
VM window on recent distributions (bug #4335)
* Linux hosts: fixed typo in kernel module startup script (bug
#4388)
* Installer: support Pardus Linux
* Solaris hosts: several installer fixes
* Solaris host: fixed a preemption issue causing VMs to never start on
Solaris 10 (bug #4328).
* Solaris guest: fixed mouse integration for OpenSolaris 2009.06 (bug
#4365)
* Windows hosts: fixed high CPU usage after resuming the host (bug
#2978)
* OVF: accept ovf/disk/ specifiers with a single slash in addition to
ovf://disk/ (bug #4452)
* Fixed a settings file conversion bug which sometimes caused hardware
acceleration to be enabled for virtual machines that had no explicit
configuration in the XML.

你可以从这里[下载 Virtualbox
3.0.2](http://download.virtualbox.org/virtualbox/3.0.2/)。
---
title: VirtualBox 更新至 3.0.8
date: 2009-10-07
---


Sun 已将 VirtualBox 更新至 3.0.8 版本。VirtualBox 3.0.8
是一个维护版本，主要修正之前版本中的 bug 和回归问题。

![VirtualBox](http://i.linuxtoy.org/i/2007/10/virtualbox.png)

见 VirtualBox 3.0.8
[Changelog](http://www.virtualbox.org/wiki/Changelog)
了解详情。VirtualBox 3.0.8

的源代码及二进制包可从[这里下载](http://download.virtualbox.org/virtualbox/3.0.8/)。
# Trouble-shooting
## 32-bit guest OS
* [Why does virtualbox only have 32-bit option, no 64-bit option on Windows 7?](https://superuser.com/questions/866962/why-does-virtualbox-only-have-32-bit-option-no-64-bit-option-on-windows-7)
* [Activating the Intel VT Virtualization Feature](https://www.thomas-krenn.com/en/wiki/Activating_the_Intel_VT_Virtualization_Feature)

## USB
* [How to set up USB for Virtualbox?](https://askubuntu.com/questions/25596/how-to-set-up-usb-for-virtualbox/25600)
* [How to Enable USB in VirtualBox](https://www.tecmint.com/enable-usb-in-virtualbox/)
* [How to Mount USB Drives on VirtualBox](https://dzone.com/articles/how-to-mount-usb-drives-on-virtualbox)



# Headless


$ sudo apt install virtualbox-ext-pack
Reading package lists... Done
Building dependency tree
Reading state information... Done
The following NEW packages will be installed:
  virtualbox-ext-pack
0 upgraded, 1 newly installed, 0 to remove and 0 not upgraded.
Need to get 10.5 kB of archives.
After this operation, 142 kB of additional disk space will be used.
Get:1 https://mirrors.ustc.edu.cn/ubuntu focal-updates/multiverse amd64 virtualbox-ext-pack all 6.1.16-1~ubuntu1.20.04.1 [10.5 kB]
Fetched 10.5 kB in 0s (52.6 kB/s)
Preconfiguring packages ...
...
Selecting previously unselected package virtualbox-ext-pack.
(Reading database ... 258239 files and directories currently installed.)
Preparing to unpack .../virtualbox-ext-pack_6.1.16-1~ubuntu1.20.04.1_all.deb ...
License has already been accepted.
Unpacking virtualbox-ext-pack (6.1.16-1~ubuntu1.20.04.1) ...
Setting up virtualbox-ext-pack (6.1.16-1~ubuntu1.20.04.1) ...
virtualbox-ext-pack: downloading: http://download.virtualbox.org/virtualbox/6.1.16/Oracle_VM_VirtualBox_Extension_Pack-6.1.16.vbox-extpack
The file will be downloaded into /usr/share/virtualbox-ext-pack
License accepted.
0%...10%...20%...30%...40%...50%...60%...70%...80%...90%...100%
Successfully installed "Oracle VM VirtualBox Extension Pack".



 9548  vboxmanage list vms
 9549  vboxmanage modifyvm winx --vrde on
 9551  vboxheadless -s winx

~$ VBoxManage startvm ubuntu-server --type headless




$ vboxheadless -s winx
Oracle VM VirtualBox Headless Interface 6.1.16_Ubuntu
(C) 2008-2021 Oracle Corporation
All rights reserved.

Error: failed to start machine. Error message: Nonexistent host networking interface, name 'wlp4s0' (VERR_INTERNAL_ERROR)






2: eno1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state UP group default qlen 1000
    link/ether 18:66:da:f6:ed:f4 brd ff:ff:ff:ff:ff:ff
    inet 10.10.50.50/24 brd 10.10.50.255 scope global eno1
       valid_lft forever preferred_lft forever
    inet6 fe80::1a66:daff:fef6:edf4/64 scope link
       valid_lft forever preferred_lft forever





../winx.20210606/winx.20210606.vbox:          <BridgedInterface name="wlp4s0"/>
../winx.pro.1909.1.20210606/winx.pro.1909.1.20210606.vbox:          <BridgedInterface name="eno1"/>



##
VBoxManage createvm --name "Windows XP" --register
If you do not specify --register, you will have to manually use the registervm command later.


VBoxManage modifyvm "Windows XP" --memory 256 --acpi on --boot1 dvd --nic1 nat

VBoxManage createhd --filename "WinXP.vdi" --size 10000

VBoxManage storagectl "Windows XP" --name "IDE Controller"
  --add ide --controller PIIX4

VBoxManage storageattach "Windows XP" --storagectl "IDE Controller"
 --port 0 --device 0 --type hdd --medium "WinXP.vdi"



VBoxManage storageattach "Windows XP" --storagectl "IDE Controller"
 --port 0 --device 1 --type dvddrive --medium /full/path/to/iso.iso

VBoxManage modifyvm "Windows XP" --vrde on


config enables the VRDP server depending on the VM configuration.

VBoxHeadless --startvm=vmname --vrde=config

$ VBoxHeadless --startvm "ol7u6" --capture --filename ol7u6-recording.webm



$ VBoxManage createvm –basefolder /VMF –name WebServer –register


$ VBoxManage modifyvm “WebServer” –hwvirtex on –pae on –ioapic on –cpus 2 –memory 2024 –acpi on –boot1 dvd –nic1 bridged –bridgeadapter1 eth0 –ostype Ubuntu_64




$ VBoxManage createhd –filename /VMF/WebServer/WebServer.vdi –size 500000 –format VDI



$ VBoxManage storagectl “WebServer” –name “SATA Controller” –add sata –controller IntelAhci –bootable on



$ VBoxManage storageattach “WebServer” –storagectl “SATA Controller” –port 0 –device 0 –type hdd –medium /VMF/WebServer/WebServer.vdi



$ VBoxManage storageattach “WebServer” –storagectl “SATA Controller” –port 1 –device 0 –type dvddrive –medium host:/dev/sr0 –passthrough on


$ VBoxHeadless –startvm “WebServer” &




VBoxManage modifyvm "<vmname>" --defaultfrontend headless


     VBoxManage modifyvm "ubuntu" --vrdp on --vrdpport 3389 --vrdpauthtype null --vrdpmulticon on




      <ExtraDataItem name="VBoxInternal/Devices/pcnet/0/LUN#0/Config/oracle/GuestPort" value="1521"/>
      <ExtraDataItem name="VBoxInternal/Devices/pcnet/0/LUN#0/Config/oracle/HostPort" value="1540"/>
      <ExtraDataItem name="VBoxInternal/Devices/pcnet/0/LUN#0/Config/oracle/Protocol" value="TCP"/>






## $ rdesktop -a 16 10.10.50.195
Autoselecting keyboard map 'en-us' from locale

ATTENTION! The server uses and invalid security certificate which can not be trusted for
the following identified reasons(s);

 1. Certificate issuer is not trusted by this system.

     Issuer: CN=wtf


Review the following certificate info before you trust it to be added as an exception.
If you do not trust the certificate the connection atempt will be aborted:

    Subject: CN=wtf
     Issuer: CN=wtf
 Valid From: Sun Jun  6 16:38:14 2021
         To: Mon Dec  6 16:38:14 2021

  Certificate fingerprints:

       sha1: 3d19b366cda9b3f67fdf275d36eee600e71a0123
     sha256: fbe0bc7df40d1012d84b87021c5143032296b60b11279229c9ce8b1d9e20e9ef


Do you trust this certificate (yes/no)? yes


Core(error): tcp_tls_connect(), TLS handshake failed. GnuTLS error: The operation timed out
Core(error): tcp_connect(), unable to connect to 10.10.50.195


# Remote

$ virtualbox
debug1: client_input_channel_open: ctype x11 rchan 3 win 65536 max 16384
debug1: client_request_x11: request from ::1 32794
debug1: channel 1: new [x11]
debug1: confirm x11
Qt WARNING: QApplication: invalid style override passed, ignoring it.
    Available styles: Windows, Fusion
debug1: client_input_channel_open: ctype x11 rchan 4 win 65536 max 16384
debug1: client_request_x11: request from ::1 32808
debug1: channel 2: new [x11]
debug1: confirm x11
debug1: SSH2_MSG_KEXINIT received
debug1: SSH2_MSG_KEXINIT sent
debug1: kex: algorithm: curve25519-sha256
debug1: kex: host key algorithm: ecdsa-sha2-nistp256
debug1: kex: server->client cipher: chacha20-poly1305@openssh.com MAC: <implicit> compression: none
debug1: kex: client->server cipher: chacha20-poly1305@openssh.com MAC: <implicit> compression: none
debug1: expecting SSH2_MSG_KEX_ECDH_REPLY
debug1: rekeying in progress
debug1: rekeying in progress
debug1: Server host key: ecdsa-sha2-nistp256 SHA256:70Vx/NZ4ZKMH6TvedM6fX5EP9/jlExCsVyvGziv41Y0
debug1: ssh_set_newkeys: rekeying out, input 1073975868 bytes 134201613 blocks, output 6370072 bytes 780105 blocks
debug1: rekey out after 134217728 blocks
debug1: SSH2_MSG_NEWKEYS sent
debug1: expecting SSH2_MSG_NEWKEYS
debug1: SSH2_MSG_NEWKEYS received
debug1: ssh_set_newkeys: rekeying in, input 1073975880 bytes 134201614 blocks, output 6370072 bytes 0 blocks
debug1: rekey in after 134217728 blocks
debug1: SSH2_MSG_KEXINIT received
debug1: SSH2_MSG_KEXINIT sent
debug1: kex: algorithm: curve25519-sha256
debug1: kex: host key algorithm: ecdsa-sha2-nistp256
debug1: kex: server->client cipher: chacha20-poly1305@openssh.com MAC: <implicit> compression: none
debug1: kex: client->server cipher: chacha20-poly1305@openssh.com MAC: <implicit> compression: none
debug1: expecting SSH2_MSG_KEX_ECDH_REPLY
debug1: rekeying in progress
debug1: rekeying in progress
debug1: Server host key: ecdsa-sha2-nistp256 SHA256:70Vx/NZ4ZKMH6TvedM6fX5EP9/jlExCsVyvGziv41Y0
debug1: ssh_set_newkeys: rekeying out, input 2147917904 bytes 134202419 blocks, output 7105372 bytes 80631 blocks
debug1: rekey out after 134217728 blocks
debug1: SSH2_MSG_NEWKEYS sent
debug1: expecting SSH2_MSG_NEWKEYS
debug1: SSH2_MSG_NEWKEYS received
debug1: ssh_set_newkeys: rekeying in, input 2147917916 bytes 134202420 blocks, output 7105372 bytes 0 blocks
debug1: rekey in after 134217728 blocks
debug1: channel 2: FORCE input drain
debug1: channel 2: free: x11, nchannels 3


debug1: client_input_channel_open: ctype x11 rchan 4 win 65536 max 16384
debug1: client_request_x11: request from ::1 34904
debug1: channel 2: new [x11]
debug1: confirm x11
debug1: channel 2: FORCE input drain
debug1: channel 2: free: x11, nchannels 3
debug1: channel 1: FORCE input drain
debug1: channel 1: free: x11, nchannels 2



