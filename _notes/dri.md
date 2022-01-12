

nvs 310

sgx cpu

nouveau



$ glxgears -info | grep REND
GL_RENDERER   = NVS 310/PCIe/SSE2
X connection to :1 broken (explicit kill or server shutdown).

$ glxgears -info | grep REND
GL_RENDERER   = NVD9
X connection to :0 broken (explicit kill or server shutdown).

$ DRI_PRIME=1 glxgears -info | grep REND
GL_RENDERER   = NVD9
X connection to :0 broken (explicit kill or server shutdown).

$ DRI_PRIME=0 glxgears -info | grep REND
GL_RENDERER   = NVD9
X connection to :0 broken (explicit kill or server shutdown).


#


```
ERROR: Root device mounted successfully, but /sbin/init does not exist.
Bailing out, you are on your own now. Good luck.

sh: can't access tty: job control turned off
[rootfs /]# _
```
`/etc/fstab`
`/dev/sda8` passno 0

`/etc/mkinitcpio.conf`
3个 hook

HOOKS="shutdown usr fsck"



Important" : do not remove any of the hooks already present. Just add the above to those 

e need to make sure that /usr is mounted by the initial ramdisk. That's what the Arch wiki quote in your OP means:

    If you keep /usr as a separate partition, you must adhere to the following requirements:

        Enable mkinitcpio-generate-shutdown-ramfs.service or add the shutdown hook.

        Add the fsck hook, mark /usr with a passno of 0 in /etc/fstab. While recommended for everyone, it is mandatory if you want your /usr partition to be fsck'ed at boot-up. Without this hook, /usr will never be fsck'd.

        Add the usr hook. This will mount the /usr partition after root is mounted. Prior to 0.9.0, mounting of /usr would be automatic if it was found in the real root's /etc/fstab.


Mark /usr with a passno of 0 in /etc/fstab. To do this, open manjaro_root/etc/fstab and find the /usr line. For this example, I will assume it is /dev/sda12 but use whichever one it is on your system. The "pass" number is the last field of an /etc/fstab entry. So, you need to make sure the line looks like

/dev/sda12  /usr  ext4  rw,errors=remount-ro     0      0
                                                        ^
                         This is the important one -----|




sudo mount --bind /dev ~/manjaro_root/dev && 
sudo mount --bind /dev/pts ~/manjaro_root/dev/pts && 
sudo mount --bind /proc ~/manjaro_root/proc && 
sudo mount --bind /sys ~/manjaro_root/sys &&
sudo chroot ~/manjaro_root


`mkinitcpio -p linux` 生成 RAMDISK 镜像&#65292;重做了 grub 的配置文件&#12290;重启后总算解决了这个问题&#12290;




sudo update-grub


# mount -t proc proc ~/foo/proc/
# mount --rbind /sys ~/foo/sys/
# mount --rbind /dev ~/foo/dev/

## Grub Windows 10

not efi

```
menuentry 'Windows 10' {
    insmod part_msdos
    insmod ntfs
    set root='(hd0,msdos1)'
    chainloader +1
}
```

# GeForce GT500M。 先是卸载了之前误装的 nouveau，不过它的wiki相当不错，配套的 [freedesktop.org 页面](https://nouveau.freedesktop.org/wiki/CodeNames/#NVC0) 提供了完整的 Code Names，我的 GT500M 属于 NVC0 Family (Fermi 架构) 的 `NVD9 (GF119)` 。 在 Nvidia 的官网页面上 [Legacy Driver](https://www.nvidia.com/object/IO_32667.html) 里面可以看到 `390.xx Driver` 可以支持这款显卡。[Archlinux Nvidia 的 wiki](https://wiki.archlinux.org/index.php/NVIDIA#Minimal_configuration) 上也写得很清楚： > For GeForce 400/500 series cards [NVCx and NVDx] from around 2010-2011, install the nvidia-390xx or nvidia-390xx-lts package. 于是执行最简步骤，顺利地安装了以下packages： yay -S xf86-video-intel yay -S mesa xf86-input-mouse xf86-input-evdev xf86-input-keyboard yay -S nvidia-390xx nvidia-390xx-utils 接着安装 [“大黄蜂” 【bumblebee】](https://wiki.archlinux.org/index.php/Bumblebee)，它是相当于 Nvidia Optimus 的一种技术，针对笔记本电脑的显卡切换提供无缝的支持，大多数情况下使用 Intel 的集成显卡来渲染，当需要的时候（例如游戏或是OpenGL调用）可以切换为 NVIDIA 独立显卡提供高帧率的渲染。 早期的计算机不具备这种能力，需要用户重启后在 BIOS 内进行手动的设置才可以，到了 2007 年左右，出现了初代的 Switchable Graphics 技术，但是仍然不受到用户的注意。 因此 2010 年左右 NVIDIA 推出了 Optimus 技术，简单来说，驱动程序将需要处理的 3D 渲染工作交给 GPU 做出运算处理，透过 PCI-E 将渲染结果穿给 Intel IGP 最终的图像输出到屏幕仍旧是 IGP 处理器来完成。这有点儿类似于当年 3DFX 加速卡将 3D 工作完成后交给 2D 显示卡做显示输出。由于 IGP 只是被当作一个简单的显示控制器，渲染是无缝切无闪烁的，对于用户来说不需要手动切换，更不需要重启计算机。 > Bumblebee is an effort to make NVIDIA Optimus enabled laptops work in GNU/Linux systems. Such feature involves two graphics cards with two different power consumption profiles plugged in a layered way sharing a single framebuffer. > It tries to mimic the Optimus technology behavior; using the dedicated GPU for rendering when needed and power it down when not in use. The present releases only support rendering on-demand, ... 安装 Bumblebee 的命令如下： yay -S bumblebee sudo usermod -a -G bumblebee ${whoami} sudo systemctl enable bumblebeed 安装好之后可以发现系统实际上屏蔽了 nvidia 的驱动，`lspci -vnn | grep -i -A10 vga` 可以发现居然识别不出独立显卡 VGA 设备（一开始我没有仔细阅读文档，一直困惑是哪里执行了错误的步骤或是 package 不对……）！ 继续按照 wiki 的测试步骤，在桌面环境下 yay -S glxgears glxinfo optirun glxgears -info 可以看到一个窗口弹出，显示三个齿轮转动的 3D 动画。`optirun` 实际上是启用了独立显卡来执行，所以在命令行里可以看到帧率相当高（1000+)。之后如果简单的执行 `glxgears -info` 会看到集显自己来渲染，帧率基本上只有 60 左右。 再往下可以执行 `optirun -b none nvidia-settings -c :8`，这条命令会启动 NVIDIA 的配置窗口，里面可以看到独显的具体技术参数等。 在 `/etc/bumblebee/bumblebee.conf` 里面确认选择的是 nvidia driver，然后查看 `xorg.conf.nvidia` 的配置项。基本上应该是不用修改的。 `/etc/X11/` 里面默认是不需要 `xorg.conf` 文件的，因为使用的依旧是集显。 至此，bumblebee 配置告一段落，后面有时间会再研究是否可以支持外接显示器。 参考资料： 1. [Archlinux - Nvidia 驱动安装血泪史](https://www.jianshu.com/p/eda410b53d5d) 2. [ArchLinux - 双显卡安装 NVIDIA 闭源驱动](https://gorgias.me/2017/01/17/Arch-Linux-%E5%8F%8C%E6%98%BE%E5%8D%A1-%E5%AE%89%E8%A3%85-NVIDIA-%E9%97%AD%E6%BA%90%E9%A9%B1%E5%8A%A8/


hashcat跑字典，hashcat不支持Nouveau，只能使用闭源驱动。

使用集显时，可以不需要xorg.conf，需要微调时才会用到。但是使用独显时，必须要配置xorg.conf，不然会出现各种错误导致Xorg server不能运行，或者是运行后出各种问题。

这里的显卡切换解决方案是Bumblebee，也听说过一个空格引发的血案。据说nvidia-prime要更好，但是得折腾xorg.conf，先略过。


https://wiki.archlinux.org/index.php/Bumblebee#Installing_Bumblebee_with_Intel.2FNVIDIA

一定要保证能正常进入桌面才能进行接下来的安装

安装以下内容

1

	

sudo pacman -S bumblebee bbswitch

把用户添加到bumblebee用户组

1

	

sudo gpasswd -a gorgias bumblebee

开启bumblebeed.service服务

1

	

sudo systemctl enable bumblebeed.service

这里顺序要注意，NVIDIA驱动要先安装，不然会和某些库文件冲突导致开机黑屏，或者因为缺少32位库导致VMWare不能使用GPU

1

	

sudo pacman -S bumblebee nvidia opencl-nvidia lib32-nvidia-utils lib32-opencl-nvidia mesa lib32-mesa-libgl xf86-video-intel

配置bumblebee

1
2
3
4
5
6
7
8

	

sudo vi /etc/bumblebee/bumblebee.conf
-----------------------------------------
这一个不要auto，指定nvidia
Driver=nvidia

电源管理指定bbswitch
[driver-nvidia]
PMMethod=bbswitch

然后重启，可以进入桌面，检测一下是否能启用独显

安装测试工具

1

	

sudo pacman -S glxspheres32 glxspheres64

然后运行

1
2
3
4

	

glxspheres32
glxspheres64
optirun glxspheres32
optirun glxspheres64





首先解决不能生成可用显示参数的问题，非CRT显示器需要加上-r参数，参考CVT Timings Program

    Reduced Blanking - Timings for LCD flat panels and other monitors that do not require long blanking intervals as a retrace period. CRTs require this because the electron beam takes time to horizontally resteer to the other side of the monitor.

1
2
3
4
5
6
7
8
9

	

usage: cvt [-v|--verbose] [-r|--reduced] X Y [refresh]

 -v|--verbose : Warn about CVT standard adherance.
 -r|--reduced : Create a mode with reduced blanking (default: normal blanking).
            X : Desired horizontal resolution (multiple of 8, required).
            Y : Desired vertical resolution (required).
      refresh : Desired refresh rate (default: 60.0Hz).

Calculates VESA CVT (Coordinated Video Timing) modelines for use with X.

最后执行这段命令就能得到可用显示参数

1
2
3

	

$ cvt -r 1920 1080

Modeline "1920x1080R"  138.50  1920 1968 2000 2080  1080 1083 1088 1111 +hsync -vsync





在xorg配置文件里就能完美解决，参考Monitor Settings，Section的含义可以参考Wiki。

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21

	

/etc/X11/xorg.conf.d/10-monitor.conf
--------------------------------------
Section "Monitor"
    Identifier "VGA1"
    Modeline "1920x1080R"  138.50  1920 1968 2000 2080  1080 1083 1088 1111 +hsync -vsync
    Option "PreferredMode" "1920x1080R"
EndSection

Section "Screen"
    Identifier "Screen0"
    Monitor "VGA1"
    DefaultDepth 24
    SubSection "Display"
        Modes "1920x1080R"
    EndSubSection
EndSection

Section "Device"
    Identifier "Device0"
    Driver "intel"
EndSection

这里说一下如何配置，Driver这里设成独显的驱动intel。
Identifier可以使用xrandr查看，查看Monitor,Screen

1
2

	

xrandr
xrandr --listmonitors



