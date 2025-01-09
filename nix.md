


nixos       3855  0.6  4.6 2766252 370796 ?      Sl   00:39   0:22  |   \_ calamares -D6
root        5116  0.0  0.0 222828  3560 ?        S    00:40   0:00  |       \_ /nix/store/rhvbjmcfnkg8i2dxpzr114cp1ws7f667-bash-5.2-p15/bin/bash /run/current-system/sw/bin/nixos-install --no-root-passwd --root /tmp/calamares-root-fayh_7pl
root        5138  0.5 11.9 2723608 963888 ?      Sl   00:40   0:19  |           \_ nix-build --out-link /tmp/calamares-root-fayh_7pl/tmp.PLaLSnfnyu/system --store /tmp/calamares-root-fayh_7pl --extra-substituters auto?trusted=1 <nixpkgs/nixos> -A system -I nixos-config=/tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix
nixos       5558  0.0  0.0 222568  2704 pts/1    S+   01:36   0:00          \_ grep calam

[nixos@nixos:~]$ sudo grep -r nixos.or /tmp/calamares-root-fayh_7pl/etc/
/tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix:  # (e.g. man configuration.nix or on https://nixos.org/nixos/options.html).

[nixos@nixos:~]$ sudo grep -r nixos.or /tmp/calamares-root-fayh_7pl/etc/ -C3
/tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix-  # on your system were taken. It‘s perfectly fine and recommended to leave
/tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix-  # this value at the release version of the first install of this system.
/tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix-  # Before changing this value read the documentation for this option
/tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix:  # (e.g. man configuration.nix or on https://nixos.org/nixos/options.html).
/tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix-  system.stateVersion = "23.05"; # Did you read the comment?
/tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix-
/tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix-}

[nixos@nixos:~]$ sudo grep -r cach /tmp/calamares-root-fayh_7pl/etc/ -C3

[nixos@nixos:~]$ ps afux | grep calam
nixos       3855  0.6  4.6 2750296 372008 ?      Sl   00:39   0:23  |   \_ calamares -D6
nixos       5666  0.0  0.0 222568  2508 pts/1    S+   01:37   0:00          \_ grep calam

[nixos@nixos:~]$ sudo su -

[root@nixos:~]# nixos-install --option substituters https://mirrors.ustc.edu.cn/nix-channels/store
configuration file /mnt/etc/nixos/configuration.nix doesn't exist

[root@nixos:~]# nixos-install --option substituters https://mirrors.ustc.edu.cn/nix-channels/store --no-root-passwd  --root /tmp/calamares-root-fayh_7pl
copying channel...
building the configuration in /tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix...



[nixos@nixos:~]$ mount|grep dm
/dev/sdb2 on /run/media/nixos/VTOYEFI type vfat (rw,nosuid,nodev,relatime,uid=1000,gid=100,fmask=0022,dmask=0022,codepage=437,iocharset=iso8859-1,shortname=mixed,showexec,utf8,flush,errors=remount-ro,uhelper=udisks2)
/dev/sdc1 on /tmp/calamares-root-fayh_7pl/boot type vfat (rw,relatime,fmask=0022,dmask=0022,codepage=437,iocharset=iso8859-1,shortname=mixed,errors=remount-ro)

[nixos@nixos:~]$ lsblk
NAME                                          MAJ:MIN RM   SIZE RO TYPE  MOUNTPOINTS
loop0                                           7:0    0   2.3G  1 loop  /nix/.ro-store
sda                                             8:0    0 465.8G  0 disk
├─sda1                                          8:1    0   328M  0 part
├─sda3                                          8:3    0     1G  0 part
└─sda4                                          8:4    0 464.4G  0 part
sdb                                             8:16   1   3.7G  0 disk
├─sdb1                                          8:17   1   3.7G  0 part
│ └─ventoy                                    254:0    0   2.3G  1 dm    /iso
└─sdb2                                          8:18   1    32M  0 part  /run/media/nixos/VTOYEFI
sdc                                             8:32   0  29.8G  0 disk
├─sdc1                                          8:33   0   512M  0 part  /tmp/calamares-root-fayh_7pl/boot
└─sdc2                                          8:34   0  29.3G  0 part
  └─luks-8b26ca46-c652-4617-869b-872ab98a1dd4 254:1    0  29.3G  0 crypt /tmp/calamares-root-fayh_7pl





[nixos@nixos:~]$ df
Filesystem     1K-blocks    Used Available Use% Mounted on
devtmpfs          402204       0    402204   0% /dev
tmpfs            4022024       8   4022016   1% /dev/shm
tmpfs            2011012    5388   2005624   1% /run
tmpfs            4022024     480   4021544   1% /run/wrappers
tmpfs            4022020  108904   3913116   3% /
/dev/root        2426912 2426912         0 100% /iso
/dev/loop0       2383872 2383872         0 100% /nix/.ro-store
tmpfs            4022020  549780   3472240  14% /nix/.rw-store
overlay          4022020  549780   3472240  14% /nix/store
tmpfs             804404      96    804308   1% /run/user/1000
/dev/sdb2          32498   27623      4875  86% /run/media/nixos/VTOYEFI
/dev/dm-1       30075536 2678128  25844320  10% /tmp/calamares-root-fayh_7pl
/dev/sdc1         523244       4    523240   1% /tmp/calamares-root-fayh_7pl/boot
tmpfs            4022020       0   4022020   0% /tmp/calamares-root-fayh_7pl/run




[nixos@nixos:~]$ ls -l /dev/mapper/
total 0
crw------- 1 root root 10, 236 Aug  9 00:29 control
lrwxrwxrwx 1 root root       7 Aug  9 00:40 luks-8b26ca46-c652-4617-869b-872ab98a1dd4 -> ../dm-1
lrwxrwxrwx 1 root root       7 Aug  9 00:40 ventoy -> ../dm-0






[root@nixos:~]# cat /tmp/calamares-root-fayh_7pl/boot/loader/entries/nixos-generation-1.conf
title NixOS
version Generation 1 NixOS 23.11pre511546.844ffa82bbe2, Linux Kernel 6.1.43, Built on 2023-08-09
linux /efi/nixos/fqg577x8jfak3d0cg5kmjnzwpx6lvdv8-linux-6.1.43-bzImage.efi
initrd /efi/nixos/mznnhaq5qc3z9zdlvyqqlnvhv0nx3y56-initrd-linux-6.1.43-initrd.efi
options init=/nix/store/q37hgql919nkbvlykwgangig9lln6qa8-nixos-system-nixos-23.11pre511546.844ffa82bbe2/init loglevel=4
machine-id e9491ccdeec84d429442fc27f2cb31db

[root@nixos:~]# cat /tmp/calamares-root-fayh_7pl/boot/loader/loader.conf
timeout 5
default nixos-generation-1.conf
console-mode keep




[root@nixos:~]# cat /tmp/calamares-root-fayh_7pl/etc/nixos/hardware-configuration.nix
# Do not modify this file!  It was generated by ‘nixos-generate-config’
# and may be overwritten by future invocations.  Please make changes
# to /etc/nixos/configuration.nix instead.
{ config, lib, pkgs, modulesPath, ... }:

{
  imports =
    [ (modulesPath + "/installer/scan/not-detected.nix")
    ];

  boot.initrd.availableKernelModules = [ "xhci_pci" "ahci" "usb_storage" "usbhid" "sd_mod" ];
  boot.initrd.kernelModules = [ ];
  boot.kernelModules = [ "kvm-intel" ];
  boot.extraModulePackages = [ ];

  fileSystems."/" =
    { device = "/dev/disk/by-uuid/247df13e-075c-49a7-9ab0-e777384e7393";
      fsType = "ext4";
    };

  boot.initrd.luks.devices."luks-8b26ca46-c652-4617-869b-872ab98a1dd4".device = "/dev/disk/by-uuid/8b26ca46-c652-4617-869b-872ab98a1dd4";

  fileSystems."/boot" =
    { device = "/dev/disk/by-uuid/89AF-4164";
      fsType = "vfat";
    };

  swapDevices = [ ];

  # Enables DHCP on each ethernet and wireless interface. In case of scripted networking
  # (the default) this is the recommended approach. When using systemd-networkd it's
  # still possible to use this option, but it's recommended to use it in conjunction
  # with explicit per-interface declarations with `networking.interfaces.<interface>.useDHCP`.
  networking.useDHCP = lib.mkDefault true;
  # networking.interfaces.enp0s31f6.useDHCP = lib.mkDefault true;
  # networking.interfaces.wlp1s0.useDHCP = lib.mkDefault true;

  nixpkgs.hostPlatform = lib.mkDefault "x86_64-linux";
  powerManagement.cpuFreqGovernor = lib.mkDefault "powersave";
  hardware.cpu.intel.updateMicrocode = lib.mkDefault config.hardware.enableRedistributableFirmware;
}






[root@nixos:~]# cat /tmp/calamares-root-fayh_7pl/etc/nixos/configuration.nix
# Edit this configuration file to define what should be installed on
# your system.  Help is available in the configuration.nix(5) man page
# and in the NixOS manual (accessible by running ‘nixos-help’).

{ config, pkgs, ... }:

{
  imports =
    [ # Include the results of the hardware scan.
      ./hardware-configuration.nix
    ];

  # Bootloader.
  boot.loader.systemd-boot.enable = true;
  boot.loader.efi.canTouchEfiVariables = true;

  # Setup keyfile
  boot.initrd.secrets = {
    "/crypto_keyfile.bin" = null;
  };

  networking.hostName = "nixos"; # Define your hostname.
  # networking.wireless.enable = true;  # Enables wireless support via wpa_supplicant.

  # Configure network proxy if necessary
  networking.proxy.default = "socks://10.10.50.10:10080/";
  # networking.proxy.noProxy = "127.0.0.1,localhost,internal.domain";

  # Enable networking
  networking.networkmanager.enable = true;

  # Set your time zone.
  time.timeZone = "America/New_York";

  # Select internationalisation properties.
  i18n.defaultLocale = "zh_CN.UTF-8";

  i18n.extraLocaleSettings = {
    LC_ADDRESS = "en_US.UTF-8";
    LC_IDENTIFICATION = "en_US.UTF-8";
    LC_MEASUREMENT = "en_US.UTF-8";
    LC_MONETARY = "en_US.UTF-8";
    LC_NAME = "en_US.UTF-8";
    LC_NUMERIC = "en_US.UTF-8";
    LC_PAPER = "en_US.UTF-8";
    LC_TELEPHONE = "en_US.UTF-8";
    LC_TIME = "en_US.UTF-8";
  };

  # Enable the X11 windowing system.
  services.xserver.enable = true;

  # Enable the Pantheon Desktop Environment.
  services.xserver.displayManager.lightdm.enable = true;
  services.xserver.desktopManager.pantheon.enable = true;

  # Configure keymap in X11
  services.xserver = {
    layout = "cn";
    xkbVariant = "";
  };

  # Enable CUPS to print documents.
  services.printing.enable = true;

  # Enable sound with pipewire.
  sound.enable = true;
  hardware.pulseaudio.enable = false;
  security.rtkit.enable = true;
  services.pipewire = {
    enable = true;
    alsa.enable = true;
    alsa.support32Bit = true;
    pulse.enable = true;
    # If you want to use JACK applications, uncomment this
    #jack.enable = true;

    # use the example session manager (no others are packaged yet so this is enabled by default,
    # no need to redefine it in your config for now)
    #media-session.enable = true;
  };

  # Enable touchpad support (enabled default in most desktopManager).
  # services.xserver.libinput.enable = true;

  # Define a user account. Don't forget to set a password with ‘passwd’.
  users.users.aaron = {
    isNormalUser = true;
    description = "Aaron";
    extraGroups = [ "networkmanager" "wheel" ];
    packages = with pkgs; [
      firefox
    #  thunderbird
    ];
  };

  # Allow unfree packages
  nixpkgs.config.allowUnfree = true;

  # List packages installed in system profile. To search, run:
  # $ nix search wget
  environment.systemPackages = with pkgs; [
  #  vim # Do not forget to add an editor to edit configuration.nix! The Nano editor is also installed by default.
  #  wget
  ];

  # Some programs need SUID wrappers, can be configured further or are
  # started in user sessions.
  # programs.mtr.enable = true;
  # programs.gnupg.agent = {
  #   enable = true;
  #   enableSSHSupport = true;
  # };

  # List services that you want to enable:

  # Enable the OpenSSH daemon.
  # services.openssh.enable = true;

  # Open ports in the firewall.
  # networking.firewall.allowedTCPPorts = [ ... ];
  # networking.firewall.allowedUDPPorts = [ ... ];
  # Or disable the firewall altogether.
  # networking.firewall.enable = false;

  # This value determines the NixOS release from which the default
  # settings for stateful data, like file locations and database versions
  # on your system were taken. It‘s perfectly fine and recommended to leave
  # this value at the release version of the first install of this system.
  # Before changing this value read the documentation for this option
  # (e.g. man configuration.nix or on https://nixos.org/nixos/options.html).
  system.stateVersion = "23.05"; # Did you read the comment?

}




[root@nixos:~]# cat /tmp/calamares-root-fayh_7pl/etc/nix/nix.conf
# WARNING: this file is generated from the nix.* options in
# your NixOS configuration, typically
# /etc/nixos/configuration.nix.  Do not edit it!
allowed-users = *
auto-optimise-store = false
builders =
cores = 0
extra-sandbox-paths =
max-jobs = auto
require-sigs = true
sandbox = true
sandbox-fallback = false
substituters = https://cache.nixos.org/
system-features = nixos-test benchmark big-parallel kvm
trusted-public-keys = cache.nixos.org-1:6NCHdD59X431o0gWypbMrAURkbJ16ZPMQFGspcDShjY=
trusted-substituters =
trusted-users = root


[root@nixos:~]# cat /tmp/calamares-root-fayh_7pl/etc/nix/registry.json
{"flakes":[{"exact":true,"from":{"id":"nixpkgs","type":"indirect"},"to":{"path":"/nix/store/lqsw50rvjyh2900i23snv3vj0wqgc6gb-nixos-23.05.362.6b0edc9c690/nixos","type":"path"}}],"version":2}
[root@nixos:~]#


...
building '/nix/store/a5rh41521jx0wgmh8bqbkasqhjfqbz24-user-units.drv'...
building '/nix/store/ig0hyb2m6xkg0z9cxlrz21c396fcyh4s-system-units.drv'...
building '/nix/store/j3sj62k050p8k6d068yng2iwalfscj44-etc.drv'...
building '/nix/store/xf7mdnv2m2xzrckk3s2fg3192hqg9w6m-nixos-system-nixos-23.11pre511546.844ffa82bbe2.drv'...
/nix/store/q37hgql919nkbvlykwgangig9lln6qa8-nixos-system-nixos-23.11pre511546.844ffa82bbe2
installing the boot loader...
setting up /etc...
Initializing machine ID from random generator.
Created "/boot/EFI".
Created "/boot/EFI/systemd".
Created "/boot/EFI/BOOT".
Created "/boot/loader".
Created "/boot/loader/entries".
Created "/boot/EFI/Linux".
Copied "/nix/store/41d6dz6cj7kj52gfmbyqwhp4hkvbrmfg-systemd-253.6/lib/systemd/boot/efi/systemd-bootx64.efi" to "/boot/EFI/systemd/systemd-bootx64.efi".
Copied "/nix/store/41d6dz6cj7kj52gfmbyqwhp4hkvbrmfg-systemd-253.6/lib/systemd/boot/efi/systemd-bootx64.efi" to "/boot/EFI/BOOT/BOOTX64.EFI".
Random seed file /boot/loader/random-seed successfully written (32 bytes).
Created EFI boot entry "Linux Boot Manager".
installation finished!


http://mirrors.ustc.edu.cn/help/nix-channels.html



如果你手动指定了 NIX_PATH 或是使用 Flakes 管理系统


替换 channel 为科大源

单独安装的 Nix 对应使用的是 nixpkgs。以 nixpkgs-unstable 为例：

$ nix-channel --add https://mirrors.ustc.edu.cn/nix-channels/nixpkgs-unstable nixpkgs
$ nix-channel --update

NixOS channel 也可以以类似命令替换，以 nixos-19.09 为例（需要以 root 用户身份执行）：

# nix-channel --add https://mirrors.ustc.edu.cn/nix-channels/nixos-19.09 nixos
# nix-channel --update

替换 binary cache 为科大源

对于单独安装的 Nix，需要修改或添加相应的配置（~/.config/nix/nix.conf 或 /etc/nix/nix.conf），配置在重启 nix-daemon 服务之后生效：

substituters = https://mirrors.ustc.edu.cn/nix-channels/store https://cache.nixos.org/

对于 NixOS 和 nix-darwin，需要编辑 NixOS / nix-darwin 配置文件，系统会自动生成对应的 /etc/nix/nix.conf 文件。





[root@nixos:~]# mount
devtmpfs on /dev type devtmpfs (rw,nosuid,size=402204k,nr_inodes=1001604,mode=755)
devpts on /dev/pts type devpts (rw,nosuid,noexec,relatime,gid=3,mode=620,ptmxmode=666)
tmpfs on /dev/shm type tmpfs (rw,nosuid,nodev,size=4022024k)
proc on /proc type proc (rw,nosuid,nodev,noexec,relatime)
tmpfs on /run type tmpfs (rw,nosuid,nodev,size=2011012k,mode=755)
ramfs on /run/keys type ramfs (rw,nosuid,nodev,relatime,mode=750)
tmpfs on /run/wrappers type tmpfs (rw,nodev,relatime,size=4022024k,mode=755)
sysfs on /sys type sysfs (rw,nosuid,nodev,noexec,relatime)
tmpfs on / type tmpfs (rw,relatime,mode=755)
/dev/mapper/ventoy on /iso type iso9660 (ro,relatime,nojoliet,check=s,map=n,blocksize=2048,iocharset=utf8)
/iso/nix-store.squashfs on /nix/.ro-store type squashfs (ro,relatime,errors=continue)
tmpfs on /nix/.rw-store type tmpfs (rw,relatime,mode=755)
overlay on /nix/store type overlay (rw,relatime,lowerdir=/mnt-root/nix/.ro-store,upperdir=/mnt-root/nix/.rw-store/store,workdir=/mnt-root/nix/.rw-store/work)
overlay on /nix/store type overlay (ro,relatime,lowerdir=/mnt-root/nix/.ro-store,upperdir=/mnt-root/nix/.rw-store/store,workdir=/mnt-root/nix/.rw-store/work)
securityfs on /sys/kernel/security type securityfs (rw,nosuid,nodev,noexec,relatime)
cgroup2 on /sys/fs/cgroup type cgroup2 (rw,nosuid,nodev,noexec,relatime,nsdelegate,memory_recursiveprot)
pstore on /sys/fs/pstore type pstore (rw,nosuid,nodev,noexec,relatime)
efivarfs on /sys/firmware/efi/efivars type efivarfs (rw,nosuid,nodev,noexec,relatime)
bpf on /sys/fs/bpf type bpf (rw,nosuid,nodev,noexec,relatime,mode=700)
ramfs on /run/credentials/systemd-tmpfiles-setup-dev.service type ramfs (ro,nosuid,nodev,noexec,relatime,mode=700)
debugfs on /sys/kernel/debug type debugfs (rw,nosuid,nodev,noexec,relatime)
hugetlbfs on /dev/hugepages type hugetlbfs (rw,relatime,pagesize=2M)
configfs on /sys/kernel/config type configfs (rw,nosuid,nodev,noexec,relatime)
mqueue on /dev/mqueue type mqueue (rw,nosuid,nodev,noexec,relatime)
fusectl on /sys/fs/fuse/connections type fusectl (rw,nosuid,nodev,noexec,relatime)
ramfs on /run/credentials/systemd-sysctl.service type ramfs (ro,nosuid,nodev,noexec,relatime,mode=700)
ramfs on /run/credentials/systemd-tmpfiles-setup.service type ramfs (ro,nosuid,nodev,noexec,relatime,mode=700)
tmpfs on /run/user/1000 type tmpfs (rw,nosuid,nodev,relatime,size=804404k,nr_inodes=201101,mode=700,uid=1000,gid=100)
gvfsd-fuse on /run/user/1000/gvfs type fuse.gvfsd-fuse (rw,nosuid,nodev,relatime,user_id=1000,group_id=100)
/dev/sdb2 on /run/media/nixos/VTOYEFI type vfat (rw,nosuid,nodev,relatime,uid=1000,gid=100,fmask=0022,dmask=0022,codepage=437,iocharset=iso8859-1,shortname=mixed,showexec,utf8,flush,errors=remount-ro,uhelper=udisks2)
portal on /run/user/1000/doc type fuse.portal (rw,nosuid,nodev,relatime,user_id=1000,group_id=100)
/dev/mapper/luks-8b26ca46-c652-4617-869b-872ab98a1dd4 on /tmp/calamares-root-fayh_7pl type ext4 (rw,relatime)
/dev/sdc1 on /tmp/calamares-root-fayh_7pl/boot type vfat (rw,relatime,fmask=0022,dmask=0022,codepage=437,iocharset=iso8859-1,shortname=mixed,errors=remount-ro)
devtmpfs on /tmp/calamares-root-fayh_7pl/dev type devtmpfs (rw,nosuid,size=402204k,nr_inodes=1001604,mode=755)
proc on /tmp/calamares-root-fayh_7pl/proc type proc (rw,relatime)
tmpfs on /tmp/calamares-root-fayh_7pl/run type tmpfs (rw,relatime,size=2011012k)
tmpfs on /tmp/calamares-root-fayh_7pl/run/udev type tmpfs (rw,nosuid,nodev,size=2011012k,mode=755)
sys on /tmp/calamares-root-fayh_7pl/sys type sysfs (rw,relatime)
efivarfs on /tmp/calamares-root-fayh_7pl/sys/firmware/efi/efivars type efivarfs (rw,relatime)




用户可以使用如下命令列出 ubuntu 仓库根目录的具体内容： rsync rsync://rsync.mirrors.ustc.edu.cn/ubuntu/

    https://zh.wikipedia.org/zh-cn/rsync






https://mirrors.ustc.edu.cn/ubuntu-cloud-images/
说明

OpenStack, LXD 等公有云使用的 Ubuntu 镜像




收录由 Canonical 定制的为云服务设计的 Ubuntu 镜像，包含官方对 KVM、Hyper-V、Xen 等虚拟化平台的官方定制镜像，可在 Google Compute Engine、Amazon AWS、Azure 环境以及 OpenStack、LXD 等虚拟化平台上运行。


<S-Del>    https://help.ubuntu.com/community/UEC/Images

    https://help.ubuntu.com/community/UEC/Images


    https://help.ubuntu.com/community/UEC/Images


    https://help.ubuntu.com/community/UEC/Images

https://github.com/NixOS/nix/tree/master/doc/manual/src/installation/installing-binary.md

http://www.eucalyptus.com/





Charmed OpenStack provides support for various SDN platforms, including OVN, OVS,





Reproducible

Nix builds packages in isolation from each other. This ensures that they are reproducible and don't have undeclared dependencies, so if a package works on one machine, it will also work on another.
Declarative

Nix makes it trivial to share development and build environments for your projects, regardless of what programming languages and tools you’re using.
Reliable

Nix ensures that installing or upgrading one package cannot break other packages. It allows you to roll back to previous versions, and ensures that no package is in an inconsistent state during an upgrade.




在安装 NixOS 时，添加 –option substituters 可以临时使用科大源：

# nixos-install --option substituters https://mirrors.ustc.edu.cn/nix-channels/store

同样，在 NixOS 切换配置时也可以设置为临时使用：

# nixos-rebuild --option substituters https://mirrors.ustc.edu.cn/nix-channels/store

将 substituters 后的参数设置为空字符串 "" 可以临时禁用自己设置的镜像。



对于所有 NixOS 19.09 及之后的版本和 nix-darwin， "https://cache.nixos.org/" 会被自动添加到配置中。



对于 NixOS 22.05 及之后的版本，在 /etc/nixos/configuration.nix 中添加：

nix.settings.substituters = [ "https://mirrors.ustc.edu.cn/nix-channels/store" ];





----


##

[root@nixos:~]# parted /dev/sda -- mklabel gpt
Warning: The existing disk label on /dev/sda will be destroyed and all data on this disk will be lost. Do you want to continue?
Yes/No? y
Information: You may need to update /etc/fstab.


[root@nixos:~]# parted /dev/sda -- mkpart primary 512MiB -0
Information: You may need to update /etc/fstab.


[root@nixos:~]# parted /dev/sda -- mkpart ESP fat32 1MiB 512MiB
Information: You may need to update /etc/fstab.



Disk /dev/sda: 465.76 GiB, 500107862016 bytes, 976773168 sectors
Disk model: ST500LT012-1DG14
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes
Disklabel type: gpt
Disk identifier: D5C9198A-1B25-41EF-97BE-594FB974B734

Device       Start       End   Sectors   Size Type
/dev/sda1  1048576 976773119 975724544 465.3G Linux filesystem
/dev/sda2     2048   1048575   1046528   511M Microsoft basic data

Partition table entries are not in disk order.



[nixos@nixos:/nix/store]$ sudo fdisk -l /dev/sda
Disk /dev/sda: 465.76 GiB, 500107862016 bytes, 976773168 sectors
Disk model: ST500LT012-1DG14
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes
Disklabel type: gpt
Disk identifier: D5C9198A-1B25-41EF-97BE-594FB974B734

Device       Start       End   Sectors   Size Type
/dev/sda1  1048576 976773119 975724544 465.3G Linux filesystem
/dev/sda2     2048   1048575   1046528   511M Microsoft basic data

Partition table entries are not in disk order.



[nixos@nixos:/nix/store]$ sudo parted -l
Model: ATA ST500LT012-1DG14 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: gpt
Disk Flags:

Number  Start  End    Size   File system  Name     Flags
 1      537MB  500GB  500GB               primary


[nixos@nixos:/nix/store]$ sudo partprobe

[nixos@nixos:/nix/store]$ sudo fdisk -l /dev/sda
Disk /dev/sda: 465.76 GiB, 500107862016 bytes, 976773168 sectors
Disk model: ST500LT012-1DG14
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes
Disklabel type: gpt
Disk identifier: D5C9198A-1B25-41EF-97BE-594FB974B734

Device       Start       End   Sectors   Size Type
/dev/sda1  1048576 976773119 975724544 465.3G Linux filesystem
/dev/sda2     2048   1048575   1046528   511M EFI System

Partition table entries are not in disk order.






[nixos@nixos:/nix/store]$ sudo parted -l
Model: ATA ST500LT012-1DG14 (scsi)
Disk /dev/sda: 500GB
Sector size (logical/physical): 512B/4096B
Partition Table: gpt
Disk Flags:

Number  Start   End    Size   File system  Name     Flags
 2      1049kB  537MB  536MB  fat32        ESP      boot, esp
 1      537MB   500GB  500GB               primary




[root@nixos:~]# mkfs.ext4 -L nixos /dev/sda1
mke2fs 1.46.2 (28-Feb-2021)
Creating filesystem with 121965568 4k blocks and 30498816 inodes
Filesystem UUID: cc3d1bb6-3602-44c9-aefc-da7464c8a4c8
Superblock backups stored on blocks:
	32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632, 2654208,
	4096000, 7962624, 11239424, 20480000, 23887872, 71663616, 78675968,
	102400000

Allocating group tables: done
Writing inode tables: done
Creating journal (262144 blocks): done
Writing superblocks and filesystem accounting information: done


[root@nixos:~]# mkfs.fat -F 32 -n boot /dev/sda2
mkfs.fat 4.1 (2017-01-24)
mkfs.fat: warning - lowercase labels might not work properly with DOS or Windows



[root@nixos:~]# mount /dev/disk/by-label/nixos /mnt

[root@nixos:~]# mkdir -p /mnt/boot

[root@nixos:~]# mount /dev/disk/by-label/boot /mnt/boot

[root@nixos:~]# nixos-generate-config --root /mnt
writing /mnt/etc/nixos/hardware-configuration.nix...
writing /mnt/etc/nixos/configuration.nix...
For more hardware-specific settings, see https://github.com/NixOS/nixos-hardware.

[root@nixos:~]# vi /mnt/etc/nixos/configuration.nix

[root@nixos:~]# nixos-install
building the configuration in /mnt/etc/nixos/configuration.nix...
these derivations will be built:
  /nix/store/01jbrnpbqv9kfx5dmi7m3a90k8gdcd4b-builder.pl.drv
  /nix/store/08w3fy0f82bbpjmfk86q466pz41ymxq2-audit-stop.drv
  /nix/store/0ayv1ghv0lznpz4n8fb1d7n8mman2h71-default.pa.drv
  /nix/store/0bis4mh07z44ypaipxmri8qdzd4cw7mz-unit-script-container_-post-start.drv
  /nix/store/0w04cni8aa4840hp403iabj3277rj0xh-unit-script-network-local-commands-start.drv
  /nix/store/g81mbhmhs5n9vbycv4hr9h1hg80srrwd-xdg-portals.drv
  /nix/store/rnpk0qv43jrrsswglac59ssqpy0gvf30-perl-5.32.1-env.drv
  /nix/store/8lmxb7ixwgqbybs6brslgl52x0k5riyd-nixos-generate-config.drv
  /nix/store/3i5jx764yj991hy8zdr2v2ba4ikcb175-perl-5.32.1-env.drv
  /nix/store/cb4f3cw1g3njksgv8jxjrbp8af9xa0wc-command-not-found.drv
  /nix/store/fgq85p0jgx51g7f8ixki0a8wi6zlmyix-nixos-version.drv
  /nix/store/q7pxss2jimlfqykjlyb8k1ppxwrdcpsa-nixos-build-vms.drv
  /nix/store/s1p3zimfi1nww3vdfkhm93ww2gmh9d6k-nixos-enter.drv
  /nix/store/s4ddbfg7rgy2rjmkipq9l1pv0kx94q4q-nixos-install.drv
  /nix/store/1m32l9mvi25x1r99kzsgdv1vdw1gciv5-nixos-manual.desktop.drv
  /nix/store/gyfxx5l0w8x262ba1m7b1bffv6grhbxr-nixos-help.drv
  /nix/store/sc4bcr464qn4da46xc2qp023i3vpibrd-nixos-help.drv
  /nix/store/v8ifqyyk1bmmr01f0p05m9a49bfmgg2q-nixos-container.drv
  /nix/store/zbr10nmwpy2x7q540hq864i1r3nr5xps-nixos-rebuild.drv
...
  /nix/store/zv167zw7gwr9h0gpkfcikdfqnscrd0q6-python3-3.8.9
  /nix/store/zv36yakyks3b1q6rdxscpvzbkhfpcaw3-gawk-5.1.0-info
  /nix/store/zv43ssg7mcm4jybnx264qlrgmk4j256z-net-snmp-5.9
  /nix/store/zvg8zqbyg82wwq6pqkh8bblmpg23qrzj-network-manager-applet-1.22.0
  /nix/store/zwbycqv244x04w9k96ca4srhcsq5gabs-cpio-2.13
  /nix/store/zwfj986164mvgcy4d4g5kkpc9p4xxkw4-xl2tpd-1.3.15
  /nix/store/zxy676hmgx697v79kv8ci5gcql8vrgjd-security-wrapper
  /nix/store/zyvvpfflx8lmpv76p4xgm88ss0vvb3j4-mesa-21.0.1-drivers
copying path '/nix/store/8y24k2dqb62nrv9m8j8jkc2134c7qxka-glibc-locales-2.32-48' to 'local'...
copying path '/nix/store/fjjnwmy8h79qhc6g1l0cj6w5v7a82lwv-linux-5.10.48' to 'local'...
copying path '/nix/store/261n6llkvfplxrsgxdzg43bdgk31sm9q-systemd-247.6-man' to 'local'...
copying path '/nix/store/y7zz7aa0928g5dmv04k8cg2vjfmh3ag6-util-linux-2.36.2-man' to 'local'...
copying path '/nix/store/kqid1bi1vq7isj9q008c7ccsqkscj9ja-xkb-validated' to 'local'...
copying path '/nix/store/ig2mllv2m01bv6w92kmgjv5ad4ia7nfk-acl-2.3.0-doc' to 'local'...
copying path '/nix/store/3p1ykwrplyv6fxcrs67im25692mhjk2f-acl-2.3.0-man' to 'local'...
copying path '/nix/store/3ddhng9cq1l3mrgziijdlz6jpcfr43ch-alsa-firmware-1.2.1' to 'local'...
copying path '/nix/store/8vn5x2ay8079jdx1ypnp30wq9l8qs35x-alsa-topology-conf-1.2.4' to 'local'...
copying path '/nix/store/r6z5cbgv46pmabw4hwrq9fgr6kdvi1rn-alsa-ucm-conf-1.2.4' to 'local'...
copying path '/nix/store/wbzzflvyix9skfpazmlyq2lw4fcwxd0b-attr-2.4.48-doc' to 'local'...
copying path '/nix/store/ijxffr30x1gamadwcqwmfwdf9bg31smg-attr-2.4.48-man' to 'local'...
copying path '/nix/store/gxxngpz47dmdc55r7agmh2lia8yz6w0r-bash-completion-2.11' to 'local'...
copying path '/nix/store/np1f0a34ck68dw6ca5rj2hqca2nbkdrk-bind-9.16.16-man' to 'local'...
copying path '/nix/store/hssw95b3i9qbjg9fpnq52f22nl96nz1l-busybox-static-x86_64-unknown-linux-musl-1.32.1' to 'local'...
copying path '/nix/store/4hh8a3vfaf97nw6ngi2ma2w62rjbgsja-bzip2-1.0.6.0.2-man' to 'local'...
copying path '/nix/store/d7xcsd54fj7kr8za26qvxn0m2ifx6mzq-ca-certificates.crt' to 'local'...
copying path '/nix/store/q9p6pddakbaqyqyq3l5ajywsmzvkvi80-cantarell-fonts-0.301' to 'local'...
...
copying path '/nix/store/xly2air1qb6da8s8kairfv6p81nyzqsw-xwayland-21.1.1' to 'local'...
copying path '/nix/store/fkyxf1x68g02wq2i0wad0y0gwmr4prb0-zlib-1.2.11-dev' to 'local'...
building '/nix/store/iv54779j1538zlvvhbqlz8h2j9vigg1j-NetworkManager.conf.drv'...
copying path '/nix/store/mq3gv86nadxysbhixlvrsd6k0m97g2bj-libpng-apng-1.6.37-dev' to 'local'...
copying path '/nix/store/k03x2iczaxxllb6r29z5rv4fgp4yn8rq-libtiff-4.2.0-dev' to 'local'...
copying path '/nix/store/1a8xqbf00gijrbkj22131jgc9clvhjzd-libvncserver-0.9.13' to 'local'...
copying path '/nix/store/1mnrhz10brl96jjz5l6l0p6rdzqq60qk-freetype-2.10.4-dev' to 'local'...
copying path '/nix/store/ixn8rm8rmasb816kws7f29kvhbxrvm5y-libxml2-2.9.12-dev' to 'local'...
building '/nix/store/ya3ii9v0qj267d03djpplrjjn35p030m-PackageKit.conf.drv'...
copying path '/nix/store/wn48b2khwk9svi7wzh8bq2igvrk0jg6n-fontconfig-2.13.92-dev' to 'local'...
copying path '/nix/store/47y9a5ck4kqrzqhjyhbf5ps9z0wyzw26-apache-httpd-2.4.48-dev' to 'local'...
copying path '/nix/store/5laa8c1qp0123klgrwgja6xvh04y6kpd-libXft-2.3.3-dev' to 'local'...
building '/nix/store/zlpn3dfd2hmfd0x4by0a5kjqwv5bl91n-Vendor.conf.drv'...
...
warning: unable to download 'https://cache.nixos.org/nar/1d01sisjidwxm5mdwha811asflllwm4r5ylqq8kfbrylq8rg4cay.nar.xz': HTTP error 200 (curl error: Transferred a partial file); retrying from offset 1022751 in 312 ms
copying path '/nix/store/8d6cqh9bmxb9pcny89mhcp0syiardzw2-gnome-system-monitor-40.1' to 'local'...
copying path '/nix/store/xz1ns6873xh13kzar3ky8xdg73c6zwsr-gnome-tour-40.0' to 'local'...
copying path '/nix/store/kvag7gygddnn4gcx4jb9faqic52ygwp2-lilv-0.24.12' to 'local'...
copying path '/nix/store/wawpgxh3q5k6zdxp2n8mrky6iiqxi4il-pcaudiolib-1.1' to 'local'...
...

copying path '/nix/store/pyb9fr6srbzz96mjrdb0yh6y27cjqg9r-sushi-3.38.0' to 'local'...
copying path '/nix/store/pf4wm8z7nx4nxaj0bahpj83cyk5nbyir-zenity-3.32.0' to 'local'...
building '/nix/store/qbxdyzf3j9z5cwr4vqa272494gms0k7v-asound.conf.drv'...
building '/nix/store/2cim77ji7r6ziwprf3gsasl7nwz0lmzg-console-env.drv'...
created 332 symlinks in user environment
...

Adding hwdb files for package /nix/store/ws7xqv0284s6df2pz4mjss40k6avd9qc-alsa-utils-1.2.4
Adding hwdb files for package /nix/store/3aa3qhg4a5ivkbpimbqdr8xs9ss0lw9g-pulseaudio-14.2
Generating hwdb database...
kernel version is 5.10.48
Running desktop-file validation
building '/nix/store/cyg5in4rqj49xvsfbn3hlqsx08w1xqza-02overridedns.drv'...
root module: xhci_pci
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
building '/nix/store/pi8acg9s7483krwr0ipd4hqh1sh9xw6l-dconf-system-config.drv'...
building '/nix/store/s4ddbfg7rgy2rjmkipq9l1pv0kx94q4q-nixos-install.drv'...
building '/nix/store/fgq85p0jgx51g7f8ixki0a8wi6zlmyix-nixos-version.drv'...
building '/nix/store/r52d6fw06ckdgw90qh8xvwbhayc64mlx-nixos.conf.drv'...
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/xhci-hcd.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/xhci-pci-renesas.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/xhci-pci.ko.xz
root module: ahci
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/libata.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/libahci.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/ahci.ko.xz
root module: nvme
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_common.ko.xz
copying path '/nix/store/y5b8kcz28ajmxan18cv8fpcvwbqh8bk7-gnome-session-40.1.1' to 'local'...
copying path '/nix/store/l9gjafdnrq2cqn4y9cg4z6ip52765sd4-chrome-gnome-shell-10.1' to 'local'...

  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/arch/x86/crypto/crct10dif-pclmul.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_common.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_generic.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/lib/crc-t10dif.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/block/t10-pi.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/nvme/host/nvme-core.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/nvme/host/nvme.ko.xz
root module: usb_storage
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/storage/usb-storage.ko.xz
root module: usbhid
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/usbhid/usbhid.ko.xz
root module: sd_mod
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/arch/x86/crypto/crct10dif-pclmul.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_generic.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/lib/crc-t10dif.ko.xz
building '/nix/store/sc4bcr464qn4da46xc2qp023i3vpibrd-nixos-help.drv'...
building '/nix/store/211bhl34sr99n33p0bcc1fs5xwvyyjlh-opengl-drivers.drv'...
building '/nix/store/a2r5dz42gkkb1kpsmvgc62gwhljjgdzk-other.pam.drv'...
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/block/t10-pi.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/sd_mod.ko.xz
root module: md_mod
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/md/md-mod.ko.xz
root module: raid0
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/md/md-mod.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/md/raid0.ko.xz
root module: raid1
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/md/md-mod.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/md/raid1.ko.xz
root module: raid10
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/md/md-mod.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/md/raid10.ko.xz
root module: raid456
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/arch/x86/crypto/crc32c-intel.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crc32c_generic.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/lib/libcrc32c.ko.xz
building '/nix/store/3i5jx764yj991hy8zdr2v2ba4ikcb175-perl-5.32.1-env.drv'...
building '/nix/store/5fmvkk7hjapms8s9sjcg21r98kdzcw76-perl-5.32.1-env.drv'...
building '/nix/store/6011xag0b7i3yg05yl1k23fwi8zq2qi1-perl-5.32.1-env.drv'...
building '/nix/store/rnpk0qv43jrrsswglac59ssqpy0gvf30-perl-5.32.1-env.drv'...
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/lib/raid6/raid6_pq.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/xor.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/md/md-mod.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/async_tx/async_tx.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/async_tx/async_xor.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/async_tx/async_pq.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/async_tx/async_memcpy.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/async_tx/async_raid6_recov.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/md/raid456.ko.xz
root module: ext2
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/fs/mbcache.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/fs/ext2/ext2.ko.xz
root module: ext4
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/fs/jbd2/jbd2.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/fs/mbcache.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/lib/crc16.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/arch/x86/crypto/crc32c-intel.ko.xz
created 2 symlinks in user environment
created 468 symlinks in user environment
copying path '/nix/store/34rvbbn464wbkdp8d8hd0zmk48k0mqwq-gnome-session-40.1.1-sessions' to 'local'...
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crc32c_generic.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/fs/ext4/ext4.ko.xz
root module: ahci
created 514 symlinks in user environment
created 180 symlinks in user environment
building '/nix/store/qkb3hk9ylmw3icp78vynprgkx0a6j0ik-runuser.pam.drv'...
building '/nix/store/ij46bicdcazs7pprcfsik6kdwacal7v7-smb-dummy.conf.drv'...
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/libata.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/libahci.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/ahci.ko.xz
root module: sata_nv
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/libata.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/sata_nv.ko.xz
root module: sata_via
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/libata.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/sata_via.ko.xz
root module: sata_sis
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/libata.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/pata_sis.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/sata_sis.ko.xz
created 177 symlinks in user environment
building '/nix/store/rb08qfhjirxh44kz6y71b743n77lgpac-desktops.drv'...
building '/nix/store/4nfxza7rhr28yzqwvfqhkb251g371xn5-nixos-tmpfiles.d.drv'...
building '/nix/store/1ra633yfwhb6z19h1zjacrfml0akd9lx-stage-2-init.sh.drv'...
root module: sata_uli
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/libata.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/sata_uli.ko.xz
root module: ata_piix
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/libata.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/ata_piix.ko.xz
root module: pata_marvell
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/libata.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/ata/pata_marvell.ko.xz
root module: sd_mod
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/arch/x86/crypto/crct10dif-pclmul.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/crypto/crct10dif_generic.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/lib/crc-t10dif.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/block/t10-pi.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/sd_mod.ko.xz
root module: sr_mod
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/cdrom/cdrom.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/scsi_mod.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/scsi/sr_mod.ko.xz
root module: mmc_block
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/mmc/core/mmc_core.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/mmc/core/mmc_block.ko.xz
root module: uhci_hcd
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
building '/nix/store/cb4f3cw1g3njksgv8jxjrbp8af9xa0wc-command-not-found.drv'...
building '/nix/store/392amgjfp6nyzqi21hspmnifbgrp86xl-udev-path.drv'...
building '/nix/store/lrnw85chxlbgn3gz3nkm64fc823mr6gg-unit-40-wlo1.link.drv'...
building '/nix/store/1pcbgbdrw0z9arzrka53k9xw9dczy1di-unit-ModemManager.service.drv'...
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/ehci-hcd.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/ehci-pci.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/uhci-hcd.ko.xz
root module: ehci_hcd
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/ehci-hcd.ko.xz
root module: ehci_pci
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/ehci-hcd.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/ehci-pci.ko.xz
root module: ohci_hcd
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/ohci-hcd.ko.xz
root module: ohci_pci
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/ohci-hcd.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/ehci-hcd.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/ehci-pci.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/ohci-pci.ko.xz
root module: xhci_hcd
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/xhci-hcd.ko.xz
root module: xhci_pci
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
building '/nix/store/v8ifqyyk1bmmr01f0p05m9a49bfmgg2q-nixos-container.drv'...
building '/nix/store/8lmxb7ixwgqbybs6brslgl52x0k5riyd-nixos-generate-config.drv'...
building '/nix/store/gw11w6bhkqsjx8gysp9asf1ny0d80jpl-unit-NetworkManager-dispatcher.service.drv'...
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/xhci-hcd.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/xhci-pci-renesas.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/xhci-pci.ko.xz
root module: usbhid
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/usbhid/usbhid.ko.xz
root module: hid_generic
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid-generic.ko.xz
root module: hid_lenovo
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/leds/led-class.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid-lenovo.ko.xz
root module: hid_apple
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid-apple.ko.xz
root module: hid_roccat
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid-roccat.ko.xz
root module: hid_logitech_hidpp
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid-logitech-hidpp.ko.xz
root module: hid_logitech_dj
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/common/usb-common.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/core/usbcore.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/usbhid/usbhid.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid-logitech-dj.ko.xz
root module: hid_microsoft
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/input/ff-memless.ko.xz
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid.ko.xz
created 434 symlinks in user environment
building '/nix/store/gzf2831g5k61mj85x4ndcyvarc7fh3ig-etc-bashrc.drv'...
building '/nix/store/ns40d0xc8307dy8nvk4xmimqirx2j3wm-tmpfiles.d.drv'...
building '/nix/store/bsqqjlk4zdxq5c3jnxfw3s07lvwffwi6-unit-NetworkManager-wait-online.service.drv'...
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/hid/hid-microsoft.ko.xz
root module: pcips2
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/input/serio/serio.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/input/serio/pcips2.ko.xz
root module: atkbd
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/input/serio/serio.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/input/serio/libps2.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/input/keyboard/atkbd.ko.xz
root module: i8042
  dependency already copied: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/input/serio/serio.ko.xz
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/input/serio/i8042.ko.xz
root module: rtc_cmos
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/rtc/rtc-cmos.ko.xz
root module: dm_mod
  copying dependency: /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/md/dm-mod.ko.xz
firmware for /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/xhci-pci.ko.xz: renesas_usb_fw.mem
WARNING: missing firmware renesas_usb_fw.mem for module /nix/store/imwwsan32v940fcyzd148pcf4ll1s6bn-linux-5.10.48-modules/lib/modules/5.10.48/kernel/drivers/usb/host/xhci-pci.ko.xz
building '/nix/store/rjzqys3mkl8dq284ha88im7g1i3w0ska-reload-container.drv'...
building '/nix/store/f9dhdrm0yhd8c4xm6php506mvarai35c-unit-NetworkManager.service.drv'...
building '/nix/store/qi51cngwkflja1snxrncqga61nb11wqk-unit-alsa-store.service.drv'...
building '/nix/store/s5b9pxqarvqr6ppxxnlcnadvg410k3af-unit-audit.service.drv'...
building '/nix/store/hs0699y4a2h74d0ih8fq8zfn1whbfmpl-system-path.drv'...
building '/nix/store/97fczdsakp81df1alaa6z7kpfji6mly1-udev-rules.drv'...
building '/nix/store/jx5j9ab3ajh1pqgf5l8hk2xv7rj7lj16-unit-avahi-daemon.service.drv'...
building '/nix/store/yb2lzqfzf3554w872ibizl5442xdxmn5-unit-avahi-daemon.socket.drv'...
building '/nix/store/hyaawcvwvp8gzk8d72xkgwk7g0v8f8k2-unit-bluetooth.service.drv'...
Adding rules for package /nix/store/prn4fa7351a47q917j3qziifkiwz99jp-mutter-40.1
Copying /nix/store/prn4fa7351a47q917j3qziifkiwz99jp-mutter-40.1/lib/udev/rules.d/61-mutter.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-mutter.rules
Adding rules for package /nix/store/vy6hxlh878gnzx5p2xksln1clwrzy13a-mdadm-4.1
Copying /nix/store/vy6hxlh878gnzx5p2xksln1clwrzy13a-mdadm-4.1/lib/udev/rules.d/01-md-raid-creating.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/01-md-raid-creating.rules
Copying /nix/store/vy6hxlh878gnzx5p2xksln1clwrzy13a-mdadm-4.1/lib/udev/rules.d/63-md-raid-arrays.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/63-md-raid-arrays.rules
Copying /nix/store/vy6hxlh878gnzx5p2xksln1clwrzy13a-mdadm-4.1/lib/udev/rules.d/64-md-raid-assembly.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/64-md-raid-assembly.rules
Copying /nix/store/vy6hxlh878gnzx5p2xksln1clwrzy13a-mdadm-4.1/lib/udev/rules.d/69-md-clustered-confirm-device.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-md-clustered-confirm-device.rules
Adding rules for package /nix/store/idflm37wxkph4rpplkdy4npal6fgry94-ipv6-privacy-extensions.rules
Copying /nix/store/idflm37wxkph4rpplkdy4npal6fgry94-ipv6-privacy-extensions.rules/etc/udev/rules.d/98-ipv6-privacy-extensions.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/98-ipv6-privacy-extensions.rules
Adding rules for package /nix/store/mqwjschvqkck42mif3dqj0svp0lnsjza-ipv6-privacy-extensions.rules
Copying /nix/store/mqwjschvqkck42mif3dqj0svp0lnsjza-ipv6-privacy-extensions.rules/etc/udev/rules.d/99-ipv6-privacy-extensions.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-ipv6-privacy-extensions.rules
Adding rules for package /nix/store/2xir7f0mmhsj2ns9rzk5bcxylgps8wd4-lvm2-2.03.12
Copying /nix/store/2xir7f0mmhsj2ns9rzk5bcxylgps8wd4-lvm2-2.03.12/lib/udev/rules.d/10-dm.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/10-dm.rules
Copying /nix/store/2xir7f0mmhsj2ns9rzk5bcxylgps8wd4-lvm2-2.03.12/lib/udev/rules.d/11-dm-lvm.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/11-dm-lvm.rules
Copying /nix/store/2xir7f0mmhsj2ns9rzk5bcxylgps8wd4-lvm2-2.03.12/lib/udev/rules.d/13-dm-disk.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/13-dm-disk.rules
Copying /nix/store/2xir7f0mmhsj2ns9rzk5bcxylgps8wd4-lvm2-2.03.12/lib/udev/rules.d/69-dm-lvm-metad.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-dm-lvm-metad.rules
Copying /nix/store/2xir7f0mmhsj2ns9rzk5bcxylgps8wd4-lvm2-2.03.12/lib/udev/rules.d/95-dm-notify.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-dm-notify.rules
Adding rules for package /nix/store/g7rnnf715rf9il3lj29crmqb5l0xz27b-bcache-tools-1.0.7
Copying /nix/store/g7rnnf715rf9il3lj29crmqb5l0xz27b-bcache-tools-1.0.7/lib/udev/rules.d/69-bcache.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-bcache.rules
Adding rules for package /nix/store/gx53a3azq4sm4fw04cfja4y7kgi9bziw-libinput-1.16.4
Copying /nix/store/gx53a3azq4sm4fw04cfja4y7kgi9bziw-libinput-1.16.4/lib/udev/rules.d/80-libinput-device-groups.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-libinput-device-groups.rules
Copying /nix/store/gx53a3azq4sm4fw04cfja4y7kgi9bziw-libinput-1.16.4/lib/udev/rules.d/90-libinput-fuzz-override.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-libinput-fuzz-override.rules
Adding rules for package /nix/store/91bamabl0k0d28824jwqbf2gll3hc0mh-colord-1.4.5
Copying /nix/store/91bamabl0k0d28824jwqbf2gll3hc0mh-colord-1.4.5/lib/udev/rules.d/69-cd-sensors.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-cd-sensors.rules
Copying /nix/store/91bamabl0k0d28824jwqbf2gll3hc0mh-colord-1.4.5/lib/udev/rules.d/95-cd-devices.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-cd-devices.rules
Adding rules for package /nix/store/z79cd8hp4gld95as3ry6m06c95qcdrrg-crda-3.18
building '/nix/store/83ppcr1mrv8b6cpl1ashgqvsjsdzw5d5-unit-console-getty.service-disabled.drv'...
building '/nix/store/f0a7l9x6kk6yba461m6q9b4mb867jbvi-unit-container-getty-.service.drv'...
building '/nix/store/zrpjgy7qzdpxa6xrqmpwwywrsrg9acdw-unit-cpufreq.service.drv'...
Copying /nix/store/z79cd8hp4gld95as3ry6m06c95qcdrrg-crda-3.18/lib/udev/rules.d/85-regulatory.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-regulatory.rules

...

Adding rules for package /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-broadmobi-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-broadmobi-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-cinterion-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-cinterion-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-dell-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dell-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-dlink-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dlink-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-ericsson-mbm.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ericsson-mbm.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-fibocom-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-fibocom-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-foxconn-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-foxconn-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-haier-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-haier-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-huawei-net-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-huawei-net-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-longcheer-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-longcheer-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-mtk-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-mtk-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-nokia-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-nokia-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-pcmcia-device-blacklist.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-pcmcia-device-blacklist.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-quectel-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-quectel-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-sierra.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-sierra.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-simtech-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-simtech-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-telit-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-telit-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-tplink-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-tplink-port-types.rules
building '/nix/store/2111r3q10hmcgf954lc3aqdrlzq72qsx-unit-dbus.socket.drv'...
building '/nix/store/p9b3dfhisz1l59zrnmdx9hqv2lc0jky6-unit-dhcpcd.service.drv'...
building '/nix/store/w770s08r483q7ghzwvzpxkkj7f33dvzd-unit-firewall.service.drv'...
collision between `/nix/store/cnsamh3ww6mvx13i41x84515lww2g7fh-nix-bash-completions-0.6.8/share/bash-completion/completions/nixos-container' and `/nix/store/fdji562lai5dk3yi6h6rdf3zawwxc0h0-nixos-container/share/bash-completion/completions/nixos-container'
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-ublox-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ublox-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-usb-device-blacklist.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-device-blacklist.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-usb-serial-adapters-greylist.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-serial-adapters-greylist.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-x22x-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-x22x-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/77-mm-zte-port-types.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-zte-port-types.rules
Copying /nix/store/r5r8ylh7cdbl3iklp5zg3w26jkwzhk7s-modem-manager-1.14.12/lib/udev/rules.d/80-mm-candidate.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-mm-candidate.rules
Adding rules for package /nix/store/gykb8snq9qrrqpnrhixxdv54kn4qir45-networkmanager-1.30.4
Copying /nix/store/gykb8snq9qrrqpnrhixxdv54kn4qir45-networkmanager-1.30.4/lib/udev/rules.d/84-nm-drivers.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/84-nm-drivers.rules
Copying /nix/store/gykb8snq9qrrqpnrhixxdv54kn4qir45-networkmanager-1.30.4/lib/udev/rules.d/85-nm-unmanaged.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-nm-unmanaged.rules
Copying /nix/store/gykb8snq9qrrqpnrhixxdv54kn4qir45-networkmanager-1.30.4/lib/udev/rules.d/90-nm-thunderbolt.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-nm-thunderbolt.rules
Adding rules for package /nix/store/3sbl62i047q0mg53iiziphw113dcjg7c-NetworkManager-fortisslvpn-gnome-1.2.10
Adding rules for package /nix/store/5k1qpkvfykn8sxvd5lddb21v4kdxp7j0-NetworkManager-iodine-gnome-unstable-2019-11-05
Adding rules for package /nix/store/yh85ijka2h6s37jqbpyfvn70vpp3i7cw-NetworkManager-l2tp-gnome-1.2.12
Adding rules for package /nix/store/8by4brd0lyfd73ghfqmmjbbl7m0pm0i3-NetworkManager-openconnect-gnome-1.2.6
Adding rules for package /nix/store/3wwjk9bx7709vc01mqdcazpr1sdcb72j-NetworkManager-openvpn-gnome-1.8.12
Adding rules for package /nix/store/00x0b1r58bzhgbyvadkam6ym5kw65rp1-NetworkManager-vpnc-gnome-1.2.6
Adding rules for package /nix/store/l8bg9r7dasqggbzffdplv096baswwscl-NetworkManager-sstp-gnome-unstable-2020-04-20
Adding rules for package /nix/store/7ggc4g52s6wil6v7zzgckzaa94ykikq2-wpa_supplicant-2.9
Adding rules for package /nix/store/2ig10zw1j21ij89ayz7ll3pppxmlw9ph-upower-0.99.11
Copying /nix/store/2ig10zw1j21ij89ayz7ll3pppxmlw9ph-upower-0.99.11/lib/udev/rules.d/95-upower-csr.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-csr.rules
Copying /nix/store/2ig10zw1j21ij89ayz7ll3pppxmlw9ph-upower-0.99.11/lib/udev/rules.d/95-upower-hid.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hid.rules
Copying /nix/store/2ig10zw1j21ij89ayz7ll3pppxmlw9ph-upower-0.99.11/lib/udev/rules.d/95-upower-hidpp.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hidpp.rules
Copying /nix/store/2ig10zw1j21ij89ayz7ll3pppxmlw9ph-upower-0.99.11/lib/udev/rules.d/95-upower-wup.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-wup.rules
Adding rules for package /nix/store/cjx5wlcybw268wgpkq88v78h842mh8d5-udisks-2.8.4
Copying /nix/store/cjx5wlcybw268wgpkq88v78h842mh8d5-udisks-2.8.4/lib/udev/rules.d/80-udisks2.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-udisks2.rules
Adding rules for package /nix/store/3sg0052027pkilbv453k76im6ngdzcmj-extra-udev-rules
Copying /nix/store/3sg0052027pkilbv453k76im6ngdzcmj-extra-udev-rules/etc/udev/rules.d/99-local.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-local.rules
Adding rules for package /nix/store/53cpk21kpdi5izl2prpg0c9n5rkgzhda-extra-hwdb-file
building '/nix/store/8xfi6qvr0mbxvs0f93jf5blcsrjnk7ad-unit-fs.target.drv'...
building '/nix/store/sry3yyp6hmhyz2fwbx4w7b18fk596jvj-unit-geoclue.service.drv'...
building '/nix/store/23nw5rybzi7xymq1padiqr4jiqpbm8dd-unit-getty-.service.drv'...
Adding rules for package /nix/store/43z79616kibnicgxqa5d6kzh6b45ncly-power-profiles-daemon-0.8.1
Adding rules for package /nix/store/cfh374anqcdsz2mvhcd1076nbpnf4v5n-bolt-0.9.1
Copying /nix/store/cfh374anqcdsz2mvhcd1076nbpnf4v5n-bolt-0.9.1/lib/udev/rules.d/90-bolt.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-bolt.rules
Adding rules for package /nix/store/r3l5ivicig3idkh6x1c5lmaviyvakywp-bluez-5.58
Adding rules for package /nix/store/pvg7y8fi7580ifp257173iv0hl7dlamy-gnome-settings-daemon-40.0.1
Copying /nix/store/pvg7y8fi7580ifp257173iv0hl7dlamy-gnome-settings-daemon-40.0.1/lib/udev/rules.d/61-gnome-settings-daemon-rfkill.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-gnome-settings-daemon-rfkill.rules
Adding rules for package /nix/store/f64wzd1sn3b0axklhk1wrcrhk3i58ig6-pipewire-0.3.30
Copying /nix/store/f64wzd1sn3b0axklhk1wrcrhk3i58ig6-pipewire-0.3.30/lib/udev/rules.d/90-pipewire-alsa.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pipewire-alsa.rules
Adding rules for package /nix/store/f01r2zb0nilk31r4jrg1a9gplrjck482-libmtp-1.1.18-bin
Copying /nix/store/f01r2zb0nilk31r4jrg1a9gplrjck482-libmtp-1.1.18-bin/lib/udev/rules.d/69-libmtp.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-libmtp.rules
Adding rules for package /nix/store/ws7xqv0284s6df2pz4mjss40k6avd9qc-alsa-utils-1.2.4
Copying /nix/store/ws7xqv0284s6df2pz4mjss40k6avd9qc-alsa-utils-1.2.4/lib/udev/rules.d/90-alsa-restore.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-alsa-restore.rules
Adding rules for package /nix/store/3aa3qhg4a5ivkbpimbqdr8xs9ss0lw9g-pulseaudio-14.2
Copying /nix/store/3aa3qhg4a5ivkbpimbqdr8xs9ss0lw9g-pulseaudio-14.2/lib/udev/rules.d/90-pulseaudio.rules to /nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pulseaudio.rules
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/00-path.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/00-path.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/00-path.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/00-path.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/00-path.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/00-path.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/01-md-raid-creating.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/01-md-raid-creating.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/01-md-raid-creating.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/01-md-raid-creating.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/01-md-raid-creating.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/01-md-raid-creating.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/10-dm.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/10-dm.rules'
building '/nix/store/a3dr270b92zlq4xq1sjq1scz5xrh858c-unit-gnome-session-gnome-initial-setup.target.drv'...
building '/nix/store/9qmj5iasjg3hy3filb6hq6rq1j5bp7bi-unit-gnome-session-initialized.target.drv'...
building '/nix/store/rp967y1vkiwn5whci0w13q8mp257xq62-unit-gnome-session-x11-services.target.drv'...
building '/nix/store/793km7z7m4drv2wgr1afl7x0c64vgdvv-unit-gnome-session.target.drv'...
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/10-dm.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/10-dm.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/10-dm.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/10-dm.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/11-dm-lvm.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/11-dm-lvm.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/11-dm-lvm.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/11-dm-lvm.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/11-dm-lvm.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/11-dm-lvm.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/13-dm-disk.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/13-dm-disk.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/13-dm-disk.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/13-dm-disk.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/13-dm-disk.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/13-dm-disk.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-gnome-settings-daemon-rfkill.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-gnome-settings-daemon-rfkill.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-gnome-settings-daemon-rfkill.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-gnome-settings-daemon-rfkill.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-gnome-settings-daemon-rfkill.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-gnome-settings-daemon-rfkill.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-mutter.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-mutter.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-mutter.rules'
building '/nix/store/vqq9ihabhfs3i0rlspjv7ky2rvn3jz50-unit-graphical-session.target.drv'...
building '/nix/store/g6kyn65irrnf2wl6iaswn4j18lsq8pmi-unit-keys.target.drv'...
building '/nix/store/2jakkzj9nfywq87yaic2l5ahrgvl14gl-unit-local-fs.target.drv'...
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-mutter.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-mutter.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/61-mutter.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/63-md-raid-arrays.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/63-md-raid-arrays.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/63-md-raid-arrays.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/63-md-raid-arrays.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/63-md-raid-arrays.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/64-md-raid-assembly.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/64-md-raid-assembly.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/64-md-raid-assembly.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/64-md-raid-assembly.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/64-md-raid-assembly.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/64-md-raid-assembly.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-bcache.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-bcache.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-bcache.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-bcache.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-bcache.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-bcache.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-cd-sensors.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-cd-sensors.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-cd-sensors.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-cd-sensors.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-cd-sensors.rules'
building '/nix/store/pbdzz3nqbrz80g6xjc1jfh1626kzlw7q-unit-multi-user.target.drv'...
building '/nix/store/k5yh8wxim6rhp1nk50f0i99nxjyl46nl-unit-network-interfaces.target.drv'...
building '/nix/store/439b6iyarjc28zasw79bzny86cga2ph3-unit-network-online.target.drv'...
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-cd-sensors.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-dm-lvm-metad.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-dm-lvm-metad.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-dm-lvm-metad.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-dm-lvm-metad.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-dm-lvm-metad.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-dm-lvm-metad.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-libmtp.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-libmtp.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-libmtp.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-libmtp.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-libmtp.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-libmtp.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-md-clustered-confirm-device.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-md-clustered-confirm-device.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-md-clustered-confirm-device.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-md-clustered-confirm-device.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-md-clustered-confirm-device.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/69-md-clustered-confirm-device.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-broadmobi-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-broadmobi-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-broadmobi-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-broadmobi-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-broadmobi-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-broadmobi-port-types.rules'
building '/nix/store/x2fvgnzlpav4hi0xrb84mydgzy4kwk36-unit-nix-daemon.service.drv'...
building '/nix/store/r4r22zhkd0phkimjjbmli9spw1a83b87-unit-nix-daemon.socket.drv'...
building '/nix/store/2cql0dqy6nf51d3n3mknjjfbvipily8b-unit-nix-optimise.service.drv'...
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-cinterion-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-cinterion-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-cinterion-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-cinterion-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-cinterion-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-cinterion-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dell-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dell-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dell-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dell-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dell-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dell-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dlink-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dlink-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dlink-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dlink-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dlink-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-dlink-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ericsson-mbm.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ericsson-mbm.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ericsson-mbm.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ericsson-mbm.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ericsson-mbm.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ericsson-mbm.rules'
building '/nix/store/pjhz0cairsy6cg751rb8vfbqfzadgbvi-unit-nscd.service.drv'...
building '/nix/store/q9a9kqhhi3had22zc86mql7lgxkxxcmr-unit-obex.service.drv'...
building '/nix/store/g5ihcj5dsbkyia7jhf876ag4gp8ha174-unit-pipewire-media-session.service.drv'...
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-fibocom-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-fibocom-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-fibocom-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-fibocom-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-fibocom-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-fibocom-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-foxconn-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-foxconn-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-foxconn-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-foxconn-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-foxconn-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-foxconn-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-haier-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-haier-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-haier-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-haier-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-haier-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-haier-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-huawei-net-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-huawei-net-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-huawei-net-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-huawei-net-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-huawei-net-port-types.rules'
building '/nix/store/flpl26pl1pdgm1j4bbfzac2c3if4x96k-unit-pipewire-pulse.socket.drv'...
building '/nix/store/sfw0h11sf339660h5l1z3cg2xa8n4jvi-unit-pipewire.service.drv'...
building '/nix/store/p23ia6611hha8820nbsrzx31m4nzlvh0-unit-pipewire.socket.drv'...
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-huawei-net-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-longcheer-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-longcheer-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-longcheer-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-longcheer-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-longcheer-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-longcheer-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-mtk-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-mtk-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-mtk-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-mtk-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-mtk-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-mtk-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-nokia-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-nokia-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-nokia-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-nokia-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-nokia-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-nokia-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-pcmcia-device-blacklist.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-pcmcia-device-blacklist.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-pcmcia-device-blacklist.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-pcmcia-device-blacklist.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-pcmcia-device-blacklist.rules'
building '/nix/store/4rxxjriqavvwxpzqmcyr421a9pq2rxv3-unit-plymouth-quit.service.drv'...
building '/nix/store/r3jymb5jrahchhg5wdyrq7y1hjdag8bc-unit-post-resume.target.drv'...
building '/nix/store/ijrm53k35pfc50px1j343npfipx1m9yf-unit-pulseaudio.service.drv'...
building '/nix/store/1dqyb39sz0fs5cabb2xlmwsnjvwyp5r1-unit-pulseaudio.socket.drv'...
created 14363 symlinks in user environment
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-pcmcia-device-blacklist.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-quectel-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-quectel-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-quectel-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-quectel-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-quectel-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-quectel-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-sierra.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-sierra.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-sierra.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-sierra.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-sierra.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-sierra.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-simtech-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-simtech-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-simtech-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-simtech-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-simtech-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-simtech-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-telit-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-telit-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-telit-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-telit-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-telit-port-types.rules'
building '/nix/store/wg935583sfxg2n87j8ngxkwgsf129f39-unit-remote-fs.target.drv'...
building '/nix/store/azxkm792jfdscnpy1y9yb72i6hz9j7a0-unit-resolvconf.service.drv'...
building '/nix/store/92y72kz9vn0c824yggppx9c0vhqsa0dn-unit-save-hwclock.service.drv'...
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-telit-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-tplink-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-tplink-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-tplink-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-tplink-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-tplink-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-tplink-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ublox-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ublox-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ublox-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ublox-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ublox-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-ublox-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-device-blacklist.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-device-blacklist.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-device-blacklist.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-device-blacklist.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-device-blacklist.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-device-blacklist.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-serial-adapters-greylist.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-serial-adapters-greylist.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-serial-adapters-greylist.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-serial-adapters-greylist.rules'
building '/nix/store/0bis4mh07z44ypaipxmri8qdzd4cw7mz-unit-script-container_-post-start.drv'...
building '/nix/store/dfxlg7ff4gdh0fapkv699b59sf6xcikk-unit-script-container_-pre-start.drv'...
building '/nix/store/lp6w9rbyn0vdi0avblfsc9n3in3607fq-unit-script-container_-start.drv'...
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-serial-adapters-greylist.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-usb-serial-adapters-greylist.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-x22x-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-x22x-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-x22x-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-x22x-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-x22x-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-x22x-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-zte-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-zte-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-zte-port-types.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-zte-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-zte-port-types.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/77-mm-zte-port-types.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-libinput-device-groups.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-libinput-device-groups.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-libinput-device-groups.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-libinput-device-groups.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-libinput-device-groups.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-libinput-device-groups.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-mm-candidate.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-mm-candidate.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-mm-candidate.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-mm-candidate.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-mm-candidate.rules'
building '/nix/store/hp3bj93bqd745aj0g3nc4hk0h1iv68zb-unit-script-display-manager-pre-start.drv'...
building '/nix/store/81824mg2zwjq2avxdvpx0l2jbxmlz25x-unit-script-display-manager-start.drv'...
building '/nix/store/aw803dl938xgsqpbvfqnhifh9wbllshs-unit-script-network-addresses-wlo1-pre-stop.drv'...
gtk-update-icon-cache: Cache file created successfully.
gtk-update-icon-cache: Cache file created successfully.
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-mm-candidate.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-udisks2.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-udisks2.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-udisks2.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-udisks2.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-udisks2.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/80-udisks2.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/84-nm-drivers.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/84-nm-drivers.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/84-nm-drivers.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/84-nm-drivers.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/84-nm-drivers.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/84-nm-drivers.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-nm-unmanaged.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-nm-unmanaged.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-nm-unmanaged.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-nm-unmanaged.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-nm-unmanaged.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-nm-unmanaged.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-regulatory.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-regulatory.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-regulatory.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-regulatory.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-regulatory.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/85-regulatory.rules'
building '/nix/store/ry4pxdqk0486a5wp84jkri331dbz439l-unit-script-network-addresses-wlo1-start.drv'...
building '/nix/store/0w04cni8aa4840hp403iabj3277rj0xh-unit-script-network-local-commands-start.drv'...
building '/nix/store/lrvb4n940w7nv4l6c04dp569si5f4nsd-unit-script-network-setup-start.drv'...
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-alsa-restore.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-alsa-restore.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-alsa-restore.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-alsa-restore.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-alsa-restore.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-alsa-restore.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-bolt.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-bolt.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-bolt.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-bolt.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-bolt.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-bolt.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-libinput-fuzz-override.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-libinput-fuzz-override.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-libinput-fuzz-override.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-libinput-fuzz-override.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-libinput-fuzz-override.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-libinput-fuzz-override.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-nm-thunderbolt.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-nm-thunderbolt.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-nm-thunderbolt.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-nm-thunderbolt.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-nm-thunderbolt.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-nm-thunderbolt.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pipewire-alsa.rules'
building '/nix/store/gkr285mjdgdhfsly2g18k2lirhhklbs7-unit-container-.service.drv'...
building '/nix/store/32bnwdk4vc8mqdhmj5h7aj6vc85krw57-unit-script-nix-gc-start.drv'...
building '/nix/store/sgbw270a7snmwf8rkphfvk9qdzipm3ww-unit-script-nixos-activation-start.drv'...
building '/nix/store/h06bm02i4z54a40kppyq6hk3l80b1k87-unit-script-post-resume-start.drv'...
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pipewire-alsa.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pipewire-alsa.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pipewire-alsa.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pipewire-alsa.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pipewire-alsa.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pulseaudio.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pulseaudio.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pulseaudio.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pulseaudio.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pulseaudio.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/90-pulseaudio.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-cd-devices.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-cd-devices.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-cd-devices.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-cd-devices.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-cd-devices.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-cd-devices.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-dm-notify.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-dm-notify.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-dm-notify.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-dm-notify.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-dm-notify.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-dm-notify.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-csr.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-csr.rules'
building '/nix/store/k4gj9wyi1781gr3mg54csqik01cp0p3p-dbus-1.drv'...
building '/nix/store/fns1p3p1p66ci6kfqq9c7hp3xmz2cflk-unit-accounts-daemon.service.drv'...
building '/nix/store/48q3whj2a0yk6ply5jlb6572l8g7n1my-unit-display-manager.service.drv'...
building '/nix/store/p9xjyw4amyl80d6x5y8d3rka1z4ggn42-unit-network-addresses-wlo1.service.drv'...
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-csr.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-csr.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-csr.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-csr.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hid.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hid.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hid.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hid.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hid.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hid.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hidpp.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hidpp.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hidpp.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hidpp.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hidpp.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-hidpp.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-wup.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-wup.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-wup.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-wup.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-wup.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/95-upower-wup.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/98-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/98-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/98-ipv6-privacy-extensions.rules'
building '/nix/store/vykhbw6pcqrzc87m9bg9gw6lvv4v285b-unit-network-local-commands.service.drv'...
building '/nix/store/8yg1bpn22c10dyn15scaxjdb8ig0pkqp-unit-network-setup.service.drv'...
building '/nix/store/snfk4kli8qb1zw3kkhdzdy650dld37ml-unit-nix-gc.service.drv'...
building '/nix/store/6l0iyxmqsldiygycv2jk3y851jlj8icx-unit-polkit.service.drv'...
building '/nix/store/4l84p2kl3dy7yqlzqgwd4nl9zpfk1qv0-unit-script-pre-sleep-start.drv'...
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/98-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/98-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/98-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-ipv6-privacy-extensions.rules'
substituteStream(): WARNING: pattern '"/sbin/modprobe' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-local.rules'
substituteStream(): WARNING: pattern '"/sbin/mdadm' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-local.rules'
substituteStream(): WARNING: pattern '"/sbin/blkid' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-local.rules'
substituteStream(): WARNING: pattern '"/bin/mount' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-local.rules'
substituteStream(): WARNING: pattern '/usr/bin/readlink' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-local.rules'
substituteStream(): WARNING: pattern '/usr/bin/basename' doesn't match anything in file '/nix/store/mp4spsb2cwqh822kh4b1wnw8zbvjsfr7-udev-rules/99-local.rules'
Checking that all programs called by relative paths in udev rules exist in /nix/store/i1kgf9gxxcfjzldjxrjq8a0kzafsi2qi-systemd-247.6/lib/udev... OK
Checking that all programs called by absolute paths in udev rules exist... OK
building '/nix/store/9r3529742fvn03h6l19manfamnxxlrpq-unit-dbus.service.drv'...
building '/nix/store/wg3sjl1y9ldsffd6zpc4hsj7gxfb5hj1-unit-dbus.service.drv'...
building '/nix/store/dnp06q26qrc7cdbrr5wzjr78bx910bqw-unit-nixos-activation.service.drv'...
building '/nix/store/bgd52nmbbazz6xpnknbq40l181kdzh6x-unit-post-resume.service.drv'...
building '/nix/store/ad92x78w482wm1xm5lhvfkxfilam7dsw-unit-script-prepare-kexec-start.drv'...
building '/nix/store/s70xn4facv22pn8zllgh3a7v839vwhn7-unit-serial-getty-.service.drv'...
building '/nix/store/x1pqmrzgp62x0gg66j18drxz0ia226i1-unit-systemd-backlight-.service.drv'...
building '/nix/store/py5dk2lx5k87h9c1161156pwrnc65zss-unit-systemd-fsck-.service.drv'...
building '/nix/store/v8xbrpiqcb4lrwjwg4v362q67x07fhhw-unit-systemd-importd.service.drv'...
building '/nix/store/qg75hnls9kbirnqrzygnk8mwkrrjgwny-unit-pre-sleep.service.drv'...
building '/nix/store/vv5l241wi0n53s7pd4qwp24mgfy4f9rs-unit-systemd-journal-flush.service.drv'...
building '/nix/store/rilqr1sr5sim6656cp4m5izc6y8hs4rf-unit-systemd-journal-gatewayd.socket.drv'...
building '/nix/store/x9gf0h31cnk7pq5m6i69hk1yi5fzdrf4-unit-systemd-journald.service.drv'...
building '/nix/store/1py6ccm8fnrkcdh1f80yjdkn0h0a1kcs-unit-systemd-logind.service.drv'...
building '/nix/store/ijkahlrxdhs4bls5v9z0v1y0m6av4vsx-unit-prepare-kexec.service.drv'...
building '/nix/store/846f8jpjdl5284nm96vpsbqijrmj75jh-unit-systemd-modules-load.service.drv'...
building '/nix/store/7hc94hnz5gv5f01zs1zd3d3gf4wim28a-unit-systemd-nspawn-.service.drv'...
building '/nix/store/i9c99fnl0m11yrar8fnvzrl95srckj3k-unit-systemd-pstore.service.drv'...
building '/nix/store/mx41y2ig6n8dw0vjc8ac8w42n3n32xji-unit-systemd-random-seed.service.drv'...
building '/nix/store/wkpv0izi8gsycply4dsabvxb3cv5ibv6-unit-systemd-remount-fs.service.drv'...
building '/nix/store/p9iijsdy035irf89var77bzsa9zkhxxm-unit-systemd-sysctl.service.drv'...
building '/nix/store/b6cg3jy78b0k0xnyd5csbdck3w8j94cq-unit-systemd-timedated.service.drv'...
building '/nix/store/kibc560xrgbfd9lnydinhavgfw1hxqsb-unit-systemd-timesyncd.service.drv'...
building '/nix/store/iyxfm9h3xyrhx8q3bgk2lh8g2fphc9kk-unit-systemd-udev-settle.service.drv'...
building '/nix/store/y3k1z6hiia9s7kyl3rhlfk9c1ngaciyl-unit-systemd-udevd.service.drv'...
building '/nix/store/sbr9wkjrigy5bz13mkax9ni22kh8d1gm-unit-systemd-update-utmp.service.drv'...
building '/nix/store/b3sq9f4gbrcd9aih20f7p7g6y0f4ffi6-unit-systemd-user-sessions.service.drv'...
building '/nix/store/7dfv77jamdgc8x2fbfd32ddygly2pa7d-unit-user-.service.drv'...
building '/nix/store/gfymvn3l65cfg4dx0v3986740gw2drv9-unit-user-runtime-dir-.service.drv'...
building '/nix/store/3825204n1rzvsxmhb693a41rx0jx1vsy-user-units.drv'...
building '/nix/store/9f3kj21fclj18lv6zsbzrhd6zbjc04h2-useradd.drv'...
building '/nix/store/b02xyjpcqb4aa2h5aan0ma8pyqry8w5f-users-groups.json.drv'...
building '/nix/store/5vf5wdnpa99n4fhdddasl1b785wax5x4-vconsole.conf.drv'...
building '/nix/store/3bxpyz7m0vjqc0cvqfafgwk4nwrpg5hz-wait-for-pstore.sh.drv'...
building '/nix/store/g81mbhmhs5n9vbycv4hr9h1hg80srrwd-xdg-portals.drv'...
building '/nix/store/jivp5vi5122i08jrvwzp4kblxs4gsw7c-xsession-wrapper.drv'...
building '/nix/store/nrcwj2kpip23vipcxzdknmpm8ail44wh-unit-mount-pstore.service.drv'...
building '/nix/store/iiznxlxw0dci5k48rb766j48hhqr8x7r-unit-reload-systemd-vconsole-setup.service.drv'...
/nix/store/w8sckj122xhfql6pfnvjqsmh93idbhry-gnome-shell-40.1/lib/systemd:
user: /nix/store/11g2nfi847fmmssbs05jnxxf48mdybi2-xdg-desktop-portal-gtk-1.8.0/share/systemd/user
building '/nix/store/176y9w686ghyq92m75gw8h27axsg5dyn-pam-environment.drv'...
...
building '/nix/store/2fsfglsfb38gcvvkn6wmzbvnkwf2lp2k-etc.drv'...
copying path '/nix/store/h238l5vvq869j4am58hmbrqp8gs17h0i-udev-rules' from 'https://cache.nixos.org'...
building '/nix/store/kqjrqq2qncf79j1ypx7mwsh7gb4ng4ww-link-units.drv'...
'/nix/store/i1kgf9gxxcfjzldjxrjq8a0kzafsi2qi-systemd-247.6/lib/systemd/network/99-default.link' -> '/nix/store/2yhg8h30znajaw6hjwhyj3w0k9iy96rx-link-units/99-default.link'
'/nix/store/3bd8y479s56vfz6xsp2g32aliz7x8dx3-unit-40-wlo1.link/40-wlo1.link' -> '/nix/store/2yhg8h30znajaw6hjwhyj3w0k9iy96rx-link-units/40-wlo1.link'
building '/nix/store/3hqg7rwha45qm85sshnxwrj61991zmjr-stage-1-init.sh.drv'...
checking syntax
building '/nix/store/wxmdm40cx01b2df5kbqh77jpxjmdm2rx-initrd-linux-5.10.48.drv'...
37413 blocks
building '/nix/store/6acq6agm68wbsmqp3sc3qh3f7gpi0r72-nixos-system-nixos-21.05.1412.cf59fbd5396.drv'...
/nix/store/2vc6rvjg3ccn0m5rc99x4r9lzxb583dj-nixos-system-nixos-21.05.1412.cf59fbd5396
copying channel...
installing the boot loader...
setting up /etc...
/etc/tmpfiles.d/journal-nocow.conf:26: Failed to resolve specifier: uninitialized /etc detected, skipping
All rules containing unresolvable specifiers will be skipped.
Initializing machine ID from random generator.
Created "/boot/EFI".
Created "/boot/EFI/systemd".
Created "/boot/EFI/BOOT".
Created "/boot/loader".
Created "/boot/loader/entries".
Created "/boot/EFI/Linux".
Copied "/nix/store/i1kgf9gxxcfjzldjxrjq8a0kzafsi2qi-systemd-247.6/lib/systemd/boot/efi/systemd-bootx64.efi" to "/boot/EFI/systemd/systemd-bootx64.efi".
Copied "/nix/store/i1kgf9gxxcfjzldjxrjq8a0kzafsi2qi-systemd-247.6/lib/systemd/boot/efi/systemd-bootx64.efi" to "/boot/EFI/BOOT/BOOTX64.EFI".
Random seed file /boot/loader/random-seed successfully written (512 bytes).
Successfully initialized system token in EFI variable with 512 bytes.
Created EFI boot entry "Linux Boot Manager".
setting up /etc...
setting up /etc...
setting root password...
New password:
Retype new password:
passwd: password updated successfully
installation finished!



http://www.gedit.org/

https://matrix.org/docs/projects/try-matrix-now.html
https://github.com/NixOS/nixpkgs/blob/release-21.05/nixos/modules/system/boot/loader/systemd-boot/systemd-boot.nix


100%



## Installing from another Linux distribution



     Install the Nix package manager:

    Short version:

curl -L https://nixos.org/nix/install | sh

. $HOME/.nix-profile/etc/profile.d/nix.sh # …or open a fresh shell

More details in the Nix manual

Switch to the NixOS channel:

If you've just installed Nix on a non-NixOS distribution, you will be on the nixpkgs channel by default.

nix-channel --list
nixpkgs https://nixos.org/channels/nixpkgs-unstable

As that channel gets released without running the NixOS tests, it will be safer to use the nixos-* channels instead:

nix-channel --add https://nixos.org/channels/nixos-version nixpkgs

You may want to throw in a nix-channel --update for good measure.

Install the NixOS installation tools:

You'll need nixos-generate-config and nixos-install, but this also makes some man pages and nixos-enter available, just in case you want to chroot into your NixOS partition. NixOS installs these by default, but you don't have NixOS yet..

nix-env -f '<nixpkgs>' -iA nixos-install-tools

Note

The following 5 steps are only for installing NixOS to another partition. For installing NixOS in place using NIXOS_LUSTRATE, skip ahead.

Prepare your target partition:

At this point it is time to prepare your target partition. Please refer to the partitioning, file-system creation, and mounting steps of Chapter 2, Installing NixOS

If you're about to install NixOS in place using NIXOS_LUSTRATE there is nothing to do for this step.

Generate your NixOS configuration:

sudo `which nixos-generate-config` --root /mnt

You'll probably want to edit the configuration files. Refer to the nixos-generate-config step in Chapter 2, Installing NixOS for more information.

Consider setting up the NixOS bootloader to give you the ability to boot on your existing Linux partition. For instance, if you're using GRUB and your existing distribution is running Ubuntu, you may want to add something like this to your configuration.nix:

boot.loader.grub.extraEntries = ''
  menuentry "Ubuntu" {
    search --set=ubuntu --fs-uuid 3cc3e652-0c1f-4800-8451-033754f68e6e
    configfile "($ubuntu)/boot/grub/grub.cfg"
  }
'';

(You can find the appropriate UUID for your partition in /dev/disk/by-uuid)

Create the nixbld group and user on your original distribution:

sudo groupadd -g 30000 nixbld

sudo useradd -u 30000 -g nixbld -G nixbld nixbld

Download/build/install NixOS:
Warning

Once you complete this step, you might no longer be able to boot on existing systems without the help of a rescue USB drive or similar.
Note

On some distributions there are separate PATHS for programs intended only for root. In order for the installation to succeed, you might have to use PATH="$PATH:/usr/sbin:/sbin" in the following command.

sudo PATH="$PATH" NIX_PATH="$NIX_PATH" `which nixos-install` --root /mnt

Again, please refer to the nixos-install step in Chapter 2, Installing NixOS for more information.

That should be it for installation to another partition!

Optionally, you may want to clean up your non-NixOS distribution:

sudo userdel nixbld

sudo groupdel nixbld

If you do not wish to keep the Nix package manager installed either, run something like sudo rm -rv ~/.nix-* /nix and remove the line that the Nix installer added to your ~/.profile.
Note

The following steps are only for installing NixOS in place using NIXOS_LUSTRATE:

Generate your NixOS configuration:

sudo `which nixos-generate-config` --root /

Note that this will place the generated configuration files in /etc/nixos. You'll probably want to edit the configuration files. Refer to the nixos-generate-config step in Chapter 2, Installing NixOS for more information.

You'll likely want to set a root password for your first boot using the configuration files because you won't have a chance to enter a password until after you reboot. You can initalize the root password to an empty one with this line: (and of course don't forget to set one once you've rebooted or to lock the account with sudo passwd -l root if you use sudo)

users.users.root.initialHashedPassword = "";

Build the NixOS closure and install it in the system profile:

nix-env -p /nix/var/nix/profiles/system -f '<nixpkgs/nixos>' -I nixos-config=/etc/nixos/configuration.nix -iA system

Change ownership of the /nix tree to root (since your Nix install was probably single user):

sudo chown -R 0.0 /nix

Set up the /etc/NIXOS and /etc/NIXOS_LUSTRATE files:

/etc/NIXOS officializes that this is now a NixOS partition (the bootup scripts require its presence).

/etc/NIXOS_LUSTRATE tells the NixOS bootup scripts to move everything that's in the root partition to /old-root. This will move your existing distribution out of the way in the very early stages of the NixOS bootup. There are exceptions (we do need to keep NixOS there after all), so the NixOS lustrate process will not touch:

    The /nix directory

    The /boot directory

    Any file or directory listed in /etc/NIXOS_LUSTRATE (one per line)

Note

Support for NIXOS_LUSTRATE was added in NixOS 16.09. The act of "lustrating" refers to the wiping of the existing distribution. Creating /etc/NIXOS_LUSTRATE can also be used on NixOS to remove all mutable files from your root partition (anything that's not in /nix or /boot gets "lustrated" on the next boot.

lustrate /ˈlʌstreɪt/ verb.

purify by expiatory sacrifice, ceremonial washing, or some other ritual action.

Let's create the files:

sudo touch /etc/NIXOS

sudo touch /etc/NIXOS_LUSTRATE

Let's also make sure the NixOS configuration files are kept once we reboot on NixOS:

echo etc/nixos | sudo tee -a /etc/NIXOS_LUSTRATE

Finally, move the /boot directory of your current distribution out of the way (the lustrate process will take care of the rest once you reboot, but this one must be moved out now because NixOS needs to install its own boot files:
Warning

Once you complete this step, your current distribution will no longer be bootable! If you didn't get all the NixOS configuration right, especially those settings pertaining to boot loading and root partition, NixOS may not be bootable either. Have a USB rescue device ready in case this happens.

sudo mv -v /boot /boot.bak &&
sudo /nix/var/nix/profiles/system/bin/switch-to-configuration boot

Cross your fingers, reboot, hopefully you should get a NixOS prompt!

If for some reason you want to revert to the old distribution, you'll need to boot on a USB rescue disk and do something along these lines:

mkdir root

mount /dev/sdaX root

mkdir root/nixos-root

mv -v root/* root/nixos-root/

mv -v root/nixos-root/old-root/* root/

mv -v root/boot.bak root/boot  # We had renamed this by hand earlier

umount root

reboot

This may work as is or you might also need to reinstall the boot loader

And of course, if you're happy with NixOS and no longer need the old distribution:

sudo rm -rf /old-root

It's also worth noting that this whole process can be automated. This is especially useful for Cloud VMs, where provider do not provide NixOS. For instance, nixos-infect uses the lustrate process to convert Digital Ocean droplets to NixOS from other distributions automatically.

## Changing the Configuration



 The file /etc/nixos/configuration.nix contains the current configuration of your machine. Whenever you’ve changed something in that file, you should do

nixos-rebuild switch

to build the new configuration, make it the default configuration for booting, and try to realise the configuration in the running system (e.g., by restarting system services).
Warning

This command doesn't start/stop user services automatically. nixos-rebuild only runs a daemon-reload for each user with running user services.

Warning

These commands must be executed as root, so you should either run them from a root shell or by prefixing them with sudo -i.

You can also do

nixos-rebuild test

to build the configuration and switch the running system to it, but without making it the boot default. So if (say) the configuration locks up your machine, you can just reboot to get back to a working configuration.

There is also

nixos-rebuild boot

to build the configuration and make it the boot default, but not switch to it now (so it will only take effect after the next reboot).

You can make your configuration show up in a different submenu of the GRUB 2 boot screen by giving it a different profile name, e.g.

nixos-rebuild switch -p test

which causes the new configuration (and previous ones created using -p test) to show up in the GRUB submenu “NixOS - Profile 'test'”. This can be useful to separate test configurations from “stable” configurations.

Finally, you can do

nixos-rebuild build

to build the configuration but nothing more. This is useful to see whether everything compiles cleanly.

If you have a machine that supports hardware virtualisation, you can also test the new configuration in a sandbox by building and running a QEMU virtual machine that contains the desired configuration. Just do

nixos-rebuild build-vm

./result/bin/run-*-vm

The VM does not have any data from your host system, so your existing user accounts and home directories will not be available unless you have set mutableUsers = false. Another way is to temporarily add the following to your configuration:

users.users.your-user.initialHashedPassword = "test";

Important: delete the $hostname.qcow2 file if you have started the virtual machine at least once without the right users, otherwise the changes will not get picked up. You can forward ports on the host to the guest. For instance, the following will forward host port 2222 to guest port 22 (SSH):

QEMU_NET_OPTS="hostfwd=tcp::2222-:22" ./result/bin/run-*-vm

allowing you to log in via SSH (assuming you have set the appropriate passwords or SSH authorized keys):

ssh -p 2222 localhost


  services.openssh.enable = true;
  services.openssh.enable = true;
## Upgrading NixOS

nix-channel --list | grep nixos
nixos https://nixos.org/channels/nixos-unstable

To switch to a different NixOS channel, do

nix-channel --add https://nixos.org/channels/channel-name nixos

(Be sure to include the nixos parameter at the end.) For instance, to use the NixOS 21.05 stable channel:

nix-channel --add https://nixos.org/channels/nixos-21.05 nixos

If you have a server, you may want to use the “small” channel instead:

nix-channel --add https://nixos.org/channels/nixos-21.05-small nixos

And if you want to live on the bleeding edge:

nix-channel --add https://nixos.org/channels/nixos-unstable nixos

You can then upgrade NixOS to the latest version in your chosen channel by running

nixos-rebuild switch --upgrade



which is equivalent to the more verbose nix-channel --update nixos; nixos-rebuild switch.
Note

Channels are set per user. This means that running nix-channel --add as a non root user (or without sudo) will not affect configuration in /etc/nixos/configuration.nix
Warning

It is generally safe to switch back and forth between channels. The only exception is that a newer NixOS may also have a newer Nix version, which may involve an upgrade of Nix’s database schema. This cannot be undone easily, so in that case you will not be able to go back to your original channel.
4.1. Automatic Upgrades

You can keep a NixOS system up-to-date automatically by adding the following to configuration.nix:

system.autoUpgrade.enable = true;
system.autoUpgrade.allowReboot = true;

This enables a periodically executed systemd service named nixos-upgrade.service. If the allowReboot option is false, it runs nixos-rebuild switch --upgrade to upgrade NixOS to the latest version in the current channel. (To see when the service runs, see systemctl list-timers.) If allowReboot is true, then the system will automatically reboot if the new generation contains a different kernel, initrd or kernel modules. You can also specify a channel explicitly, e.g.

system.autoUpgrade.channel = https://nixos.org/channels/nixos-21.05;




## nix

Introduction

Nix is a purely functional package manager. This means that it treats packages like values in purely functional programming languages such as Haskell — they are built by functions that don’t have side-effects, and they never change after they have been built. Nix stores packages in the Nix store, usually the directory /nix/store, where each package has its own unique subdirectory such as

/nix/store/b6gvzjyb2pg0kjfwrjmg1vfhh54ad73z-firefox-33.1/

where b6gvzjyb2pg0… is a unique identifier for the package that captures all its dependencies (it’s a cryptographic hash of the package’s build dependency graph). This enables many powerful features.
Multiple versions

You can have multiple versions or variants of a package installed at the same time. This is especially important when different applications have dependencies on different versions of the same package — it prevents the “DLL hell”. Because of the hashing scheme, different versions of a package end up in different paths in the Nix store, so they don’t interfere with each other.

An important consequence is that operations like upgrading or uninstalling an application cannot break other applications, since these operations never “destructively” update or delete files that are used by other packages.
Complete dependencies

Nix helps you make sure that package dependency specifications are complete. In general, when you’re making a package for a package management system like RPM, you have to specify for each package what its dependencies are, but there are no guarantees that this specification is complete. If you forget a dependency, then the package will build and work correctly on your machine if you have the dependency installed, but not on the end user's machine if it's not there.

Since Nix on the other hand doesn’t install packages in “global” locations like /usr/bin but in package-specific directories, the risk of incomplete dependencies is greatly reduced. This is because tools such as compilers don’t search in per-packages directories such as /nix/store/5lbfaxb722zp…-openssl-0.9.8d/include, so if a package builds correctly on your system, this is because you specified the dependency explicitly. This takes care of the build-time dependencies.

Once a package is built, runtime dependencies are found by scanning binaries for the hash parts of Nix store paths (such as r8vvq9kq…). This sounds risky, but it works extremely well.
Multi-user support

Nix has multi-user support. This means that non-privileged users can securely install software. Each user can have a different profile, a set of packages in the Nix store that appear in the user’s PATH. If a user installs a package that another user has already installed previously, the package won’t be built or downloaded a second time. At the same time, it is not possible for one user to inject a Trojan horse into a package that might be used by another user.
Atomic upgrades and rollbacks

Since package management operations never overwrite packages in the Nix store but just add new versions in different paths, they are atomic. So during a package upgrade, there is no time window in which the package has some files from the old version and some files from the new version — which would be bad because a program might well crash if it’s started during that period.

And since packages aren’t overwritten, the old versions are still there after an upgrade. This means that you can roll back to the old version:

$ nix-env --upgrade -A nixpkgs.some-package
$ nix-env --rollback

Garbage collection

When you uninstall a package like this…

$ nix-env --uninstall firefox

the package isn’t deleted from the system right away (after all, you might want to do a rollback, or it might be in the profiles of other users). Instead, unused packages can be deleted safely by running the garbage collector:

$ nix-collect-garbage

This deletes all packages that aren’t in use by any user profile or by a currently running program.
Functional package language

Packages are built from Nix expressions, which is a simple functional language. A Nix expression describes everything that goes into a package build action (a “derivation”): other packages, sources, the build script, environment variables for the build script, etc. Nix tries very hard to ensure that Nix expressions are deterministic: building a Nix expression twice should yield the same result.

Because it’s a functional language, it’s easy to support building variants of a package: turn the Nix expression into a function and call it any number of times with the appropriate arguments. Due to the hashing scheme, variants don’t conflict with each other in the Nix store.
Transparent source/binary deployment

Nix expressions generally describe how to build a package from source, so an installation action like

$ nix-env --install -A nixpkgs.firefox

could cause quite a bit of build activity, as not only Firefox but also all its dependencies (all the way up to the C library and the compiler) would have to be built, at least if they are not already in the Nix store. This is a source deployment model. For most users, building from source is not very pleasant as it takes far too long. However, Nix can automatically skip building from source and instead use a binary cache, a web server that provides pre-built binaries. For instance, when asked to build /nix/store/b6gvzjyb2pg0…-firefox-33.1 from source, Nix would first check if the file https://cache.nixos.org/b6gvzjyb2pg0….narinfo exists, and if so, fetch the pre-built binary referenced from there; otherwise, it would fall back to building from source.
Nix Packages collection

We provide a large set of Nix expressions containing hundreds of existing Unix packages, the Nix Packages collection (Nixpkgs).
Managing build environments

Nix is extremely useful for developers as it makes it easy to automatically set up the build environment for a package. Given a Nix expression that describes the dependencies of your package, the command nix-shell will build or download those dependencies if they’re not already in your Nix store, and then start a Bash shell in which all necessary environment variables (such as compiler search paths) are set.

For example, the following command gets all dependencies of the Pan newsreader, as described by its Nix expression:

$ nix-shell '<nixpkgs>' -A pan

You’re then dropped into a shell where you can edit, build and test the package:

[nix-shell]$ unpackPhase
[nix-shell]$ cd pan-*
[nix-shell]$ configurePhase
[nix-shell]$ buildPhase
[nix-shell]$ ./pan/gui/pan

##
Learn →
How Nix works

Nix is a purely functional package manager. This means that it treats packages like values in purely functional programming languages such as Haskell — they are built by functions that don’t have side-effects, and they never change after they have been built. Nix stores packages in the Nix store, usually the directory /nix/store, where each package has its own unique subdirectory such as

/nix/store/b6gvzjyb2pg0kjfwrjmg1vfhh54ad73z-firefox-33.1/

where b6gvzjyb2pg0… is a unique identifier for the package that captures all its dependencies (it’s a cryptographic hash of the package’s build dependency graph). This enables many powerful features.
Multiple versions

You can have multiple versions or variants of a package installed at the same time. This is especially important when different applications have dependencies on different versions of the same package — it prevents the “DLL hell”. Because of the hashing scheme, different versions of a package end up in different paths in the Nix store, so they don’t interfere with each other.

An important consequence is that operations like upgrading or uninstalling an application cannot break other applications, since these operations never “destructively” update or delete files that are used by other packages.
Complete dependencies

When you’re making a package for a package management system, like RPM, you are supposed to declare its dependencies, but you can't easily guarantee that your dependency declaration is complete. If you forget a dependency, that you have separately installed on your machine, then the component may build and work correctly on your machine, but failing on the end user's machine.

Nix ensures that package dependency specifications are complete.

Under Nix, a build process will only find resources that have been declared explicitly as dependencies. There's no way it can build until everything it needs has been correctly declared. If it builds, you will know you've provided a complete declaration.

Once a build is complete, ongoing runtime dependencies are detected automatically.
Multi-user support

Starting at version 0.11, Nix has multi-user support. This means that non-privileged users can securely install software. Each user can have a different profile, a set of packages in the Nix store that appear in the user’s PATH. If a user installs a package that another user has already installed previously, the package won’t be built or downloaded a second time. At the same time, it is not possible for one user to inject a Trojan horse into a package that might be used by another user.
Atomic upgrades and rollbacks

Since package management operations never overwrite packages in the Nix store but just add new versions in different paths, they are atomic. So during a package upgrade, there is no time window in which the package has some files from the old version and some files from the new version — which would be bad because a program might well crash if it’s started during that period.

And since packages aren’t overwritten, the old versions are still there after an upgrade. This means that you can roll back to the old version:

$ nix-env --upgrade some-packages
$ nix-env --rollback

Garbage collection

When you uninstall a package like this…

$ nix-env --uninstall firefox

the package isn’t deleted from the system right away (after all, you might want to do a rollback, or it might be in the profiles of other users). Instead, unused packages can be deleted safely by running the garbage collector:

$ nix-collect-garbage

This deletes all packages that aren’t in use by any user profile or by a currently running program.
Functional package language

Packages are built from Nix expressions, which is a simple functional language. A Nix expression describes everything that goes into a package build action (a “derivation”): other packages, sources, the build script, environment variables for the build script, etc. Nix tries very hard to ensure that Nix expressions are deterministic: building a Nix expression twice should yield the same result.

Because it’s a functional language, it’s easy to support building variants of a package: turn the Nix expression into a function and call it any number of times with the appropriate arguments. Due to the hashing scheme, variants don’t conflict with each other in the Nix store.
Transparent source/binary deployment

Nix expressions generally describe how to build a package from source, so an installation action like

$ nix-env --install firefox

could cause quite a bit of build activity, as not only Firefox but also all its dependencies (all the way up to the C library and the compiler) would have to built, at least if they are not already in the Nix store. This is a source deployment model. For most users, building from source is not very pleasant as it takes far too long. However, Nix can automatically skip building from source and instead use a binary cache, a web server that provides pre-built binaries. For instance, when asked to build /nix/store/b6gvzjyb2pg0…-firefox-33.1 from source, Nix would first check if the file http://cache.nixos.org/b6gvzjyb2pg0….narinfo exists, and if so, fetch the pre-built binary referenced from there; otherwise, it would fall back to building from source.
Nix Packages collection

We provide a large set of Nix expressions containing thousands of existing Unix packages, the Nix Packages collection (Nixpkgs).
Managing build environments

Nix is extremely useful for developers as it makes it easy to automatically set up the build environment for a package. Given a Nix expression that describes the dependencies of your package, the command nix-shell will build or download those dependencies if they’re not already in your Nix store, and then start a Bash shell in which all necessary environment variables (such as compiler search paths) are set.

For example, the following command gets all dependencies of the Pan newsreader, as described by its Nix expression:

$ nix-shell '<nixpkgs>' -A pan

You’re then dropped into a shell where you can edit, build and test the package:

[nix-shell]$ tar xf $src
[nix-shell]$ cd pan-*
[nix-shell]$ ./configure
[nix-shell]$ make
[nix-shell]$ ./pan/gui/pan

Since Nix packages are reproducible and have complete dependency specifications, Nix makes an excellent basis for a continuous build system.
Portability

Nix runs on Linux and macOS.
How NixOS works?

NixOS is based on Nix, a purely functional package management system. Nix stores all packages in isolation from each other under paths such as

/nix/store/5rnfzla9kcx4mj5zdc7nlnv8na1najvg-firefox-3.5.4/

The string 5rnf... is a cryptographic hash of all input used to build the package. Packages are never overwritten after they have been built; instead, if you change the build description of a package (its ‘Nix expression’), it’s rebuilt and installed in a different path in /nix/store so it doesn’t interfere with the old version. NixOS extends this by using Nix not only to build packages, but also things like configuration files. For instance, the configuration of the SSH daemon is also built from a Nix expression and stored under a path like

/nix/store/s2sjbl85xnrc18rl4fhn56irkxqxyk4p-sshd_config

By building entire system configurations from a Nix expression, NixOS ensures that such configurations don’t overwrite each other, can be rolled back, and so on.

A big implication of the way that Nix/NixOS stores packages is that there is no /bin, /sbin, /lib, /usr, and so on. Instead all packages are kept in /nix/store. (The only exception is a symlink /bin/sh to Bash in the Nix store.) Not using ‘global’ directories such as /bin is what allows multiple versions of a package to coexist. Nix does have a /etc to keep system-wide configuration files, but most files in that directory are symlinks to generated files in /nix/store.
Declarative system configuration model

In NixOS, the entire operating system — the kernel, applications, system packages, configuration files, and so on — is built by the Nix package manager from a description in a purely functional build language. The fact that it’s purely functional essentially means that building a new configuration cannot overwrite previous configurations. Most of the other features follow from this.

You configure a NixOS system by writing a specification of the functionality that you want on your machine in /etc/nixos/configuration.nix. For instance, here is a minimal configuration of a machine running an SSH daemon:

{
    boot.loader.grub.device = "/dev/sda";

    fileSystems."/".device = "/dev/sda1";

    services.sshd.enable = true;
  }

After changing /etc/nixos/configuration.nix, you realise the configuration by running this command:

$ nixos-rebuild switch

This command does everything necessary to make the configuration happen, including downloading and compiling OpenSSH, generating the configuration files for the SSH server, and so on.
Reliable upgrades

Another advantage of purely functional package management is that nixos-rebuild switch will always produce the same result, regardless of what packages or configuration files you already had on your system. Thus, upgrading a system is as reliable as reinstalling from scratch.
Atomic upgrades

NixOS has a transactional approach to configuration management: configuration changes such as upgrades are atomic. This means that if the upgrade to a new configuration is interrupted — say, the power fails half-way through — the system will still be in a consistent state: it will either boot in the old or the new configuration. In most other systems, you’ll end up in an inconsistent state, and your machine may not even boot anymore.
Rollbacks

Because the files of a new configuration don’t overwrite old ones, you can (atomically) roll back to a previous configuration. For instance, if after a nixos-rebuild switch you discover that you don’t like the new configuration, you can just go back:

$ nixos-rebuild switch --rollback

Grub boot menu

In fact, all old system configurations automatically show up in the Grub boot menu. So if the new configuration crashes or doesn’t boot properly, you can just roll back by selecting an older configuration in the Grub boot menu. Rollbacks are very fast: it doesn’t involve lots of files having to be restored from copies.
Reproducible system configurations

NixOS’ declarative configuration model makes it easy to reproduce a system configuration on another machine (for instance, to test a change in a test environment before doing it on the production server). You just copy the configuration.nix file to the target NixOS machine and run nixos-rebuild switch. This will give you the same configuration (kernel, applications, system services, and so on) except for ‘mutable state’ (such as the stuff that lives in /var).
Safe to test changes

NixOS makes it safe to test potentially dangerous changes to the system, because you can always roll back. (Unless you screw up the boot loader, that is…) For instance, whether the change is as simple as enabling a system service, or as large as rebuilding the entire system with a new version of Glibc, you can test it by doing:

$ nixos-rebuild test

This builds and activates the new configuration, but doesn’t make it the boot default. Thus, rebooting the system will take you back to the previous, known-good configuration.

An even nicer way to test changes is the following:

$ nixos-rebuild build-vm
$ ./result/bin/run-*-vm

This builds and starts a virtual machine that contains the new system configuration (i.e. a clone of the configuration of the host machine, with any changes that you made to configuration.nix). The VM doesn’t share any data with the host, so you can safely experiment inside the VM. The build-vm command is very efficient (it doesn’t require a disk image for the VM to be created), so it’s a very effective way to test changes.


## Quick Start

This chapter is for impatient people who don't like reading documentation. For more in-depth information you are kindly referred to subsequent chapters.

    Install single-user Nix by running the following:

$ bash <(curl -L https://nixos.org/nix/install)

This will install Nix in /nix. The install script will create /nix using sudo, so make sure you have sufficient rights. (For other installation methods, see here.)

See what installable packages are currently available in the channel:

$ nix-env -qaP
nixpkgs.docbook_xml_dtd_43                    docbook-xml-4.3
nixpkgs.docbook_xml_dtd_45                    docbook-xml-4.5
nixpkgs.firefox                               firefox-33.0.2
nixpkgs.hello                                 hello-2.9
nixpkgs.libxslt                               libxslt-1.1.28
…

Install some packages from the channel:

$ nix-env -iA nixpkgs.hello

This should download pre-built packages; it should not build them locally (if it does, something went wrong).

Test that they work:

$ which hello
/home/eelco/.nix-profile/bin/hello
$ hello
Hello, world!

Uninstall a package:

$ nix-env -e hello

You can also test a package without installing it:

$ nix-shell -p hello

This builds or downloads GNU Hello and its dependencies, then drops you into a Bash shell where the hello command is present, all without affecting your normal environment:

[nix-shell:~]$ hello
Hello, world!

[nix-shell:~]$ exit

$ hello
hello: command not found

To keep up-to-date with the channel, do:

$ nix-channel --update nixpkgs
$ nix-env -u '*'

The latter command will upgrade each installed package for which there is a “newer” version (as determined by comparing the version numbers).

If you're unhappy with the result of a nix-env action (e.g., an upgraded package turned out not to work properly), you can go back:

$ nix-env --rollback

You should periodically run the Nix garbage collector to get rid of unused packages, since uninstalls or upgrades don't actually delete them:

$ nix-collect-garbage -d


## Hacking

This section provides some notes on how to hack on Nix. To get the latest version of Nix from GitHub:

$ git clone https://github.com/NixOS/nix.git
$ cd nix

To build Nix for the current operating system/architecture use

$ nix-build

or if you have a flake-enabled nix:

$ nix build

This will build defaultPackage attribute defined in the flake.nix file. To build for other platforms add one of the following suffixes to it: aarch64-linux, i686-linux, x86_64-darwin, x86_64-linux. i.e.

$ nix-build -A defaultPackage.x86_64-linux

To build all dependencies and start a shell in which all environment variables are set up so that those dependencies can be found:

$ nix-shell

or if you have a flake-enabled nix:

$ nix develop

To get a shell with a different compilation environment (e.g. stdenv, gccStdenv, clangStdenv, clang11Stdenv):

$ nix-shell -A devShells.x86_64-linux.clang11StdenvPackages

or if you have a flake-enabled nix:

$ nix develop .#clang11StdenvPackages

To build Nix itself in this shell:

[nix-shell]$ ./bootstrap.sh
[nix-shell]$ ./configure $configureFlags --prefix=$(pwd)/outputs/out
[nix-shell]$ make -j $NIX_BUILD_CORES

To install it in $(pwd)/outputs and test it:

[nix-shell]$ make install
[nix-shell]$ make installcheck -j $NIX_BUILD_CORES
[nix-shell]$ ./outputs/out/bin/nix --version
nix (Nix) 3.0

To run a functional test:

make tests/test-name-should-auto-complete.sh.test

To run the unit-tests for C++ code:

make check

If you have a flakes-enabled Nix you can replace:

$ nix-shell

by:

$ nix develop



https://releases.nixos.org/?prefix=nixos/21.11/



----

## substituters = https://mirrors.ustc.edu.cn/nix-channels/store https://cache.nixos.org/



aaron:$y$j9T$QoQOwuVaqzKWABSnEJA5j1$S0AELYORTIhlUEGkaSfQzCX5E46E0eTTTI90B.Jmfh5:19578::::::





“天格计划”是以本科生为主体的空间科学项目，由清华大学发起，已经发射了数颗用于探测短伽马射线暴的卫星载荷。星测未来团队成长于“天格计划”，基于 FPGA-SoC + GPU-SoC 超异构体系打造卫星边缘端的智能计算平台，并配合开放平台与 AI 算法将传统功能卫星升级为智能卫星。本次 Tunight 工物系学长仓基荣（CEO）和宋钰康（产品总监）将与大家分享卫星端智能处理的挑战和解决思路，针对一个具体有趣的落地项目做详细介绍和互动，包括相关领域的核心能力设计和未来发展规划，分享 AI 上天的全流程实践，并期待一起合作完成更多有意思的项目！



“天格计划”是以本科生为主体的空间科学项目，由清华大学发起，已经发射了数颗用于探测短伽马射线暴的卫星载荷。星测未来团队成长于“天格计划”，基于 FPGA-SoC + GPU-SoC 超异构体系打造卫星边缘端的智能计算平台，并配合开放平台与 AI 算法将传统功能卫星升级为智能卫星。本次 Tunight 工物系学长仓基荣（CEO）和宋钰康（产品总监）将与大家分享卫星端智能处理的挑战和解决思路，针对一个具体有趣的落地项目做详细介绍和互动，包括相关领域的核心能力设计和未来发展规划，分享 AI 上天的全流程实践，并期待一起合作完成更多有意思的项目！


“天格计划”是以本科生为主体的空间科学项目，由清华大学发起，已经发射了数颗用于探测短伽马射线暴的卫星载荷。星测未来团队成长于“天格计划”，基于 FPGA-SoC + GPU-SoC 超异构体系打造卫星边缘端的智能计算平台，并配合开放平台与 AI 算法将传统功能卫星升级为智能卫星。本次 Tunight 工物系学长仓基荣（CEO）和宋钰康（产品总监）将与大家分享卫星端智能处理的挑战和解决思路，针对一个具体有趣的落地项目做详细介绍和互动，包括相关领域的核心能力设计和未来发展规划，分享 AI 上天的全流程实践，并期待一起合作完成更多有意思的项目！



“天格计划”是以本科生为主体的空间科学项目，由清华大学发起，已经发射了数颗用于探测短伽马射线暴的卫星载荷。星测未来团队成长于“天格计划”，基于 FPGA-SoC + GPU-SoC 超异构体系打造卫星边缘端的智能计算平台，并配合开放平台与 AI 算法将传统功能卫星升级为智能卫星。本次 Tunight 工物系学长仓基荣（CEO）和宋钰康（产品总监）将与大家分享卫星端智能处理的挑战和解决思路，针对一个具体有趣的落地项目做详细介绍和互动，包括相关领域的核心能力设计和未来发展规划，分享 AI 上天的全流程实践，并期待一起合作完成更多有意思的项目！

https://mirrors.tuna.tsinghua.edu.cn/tuna/tunight/2023-04-08-send-ai-into-space/video.mp4




Installing behind a proxy

To install NixOS behind a proxy, do the following before running nixos-install.

Update proxy configuration in /mnt/etc/nixos/configuration.nix to keep the internet accessible after reboot.

networking.proxy.default = "http://user:password@proxy:port/";
networking.proxy.noProxy = "127.0.0.1,localhost,internal.domain";
Setup the proxy environment variables in the shell where you are running nixos-install.

# proxy_url="http://user:password@proxy:port/"
# export http_proxy="$proxy_url"
# export HTTP_PROXY="$proxy_url"
# export https_proxy="$proxy_url"
# export HTTPS_PROXY="$proxy_url"
Note
If you are switching networks with different proxy configurations, use the specialisation option in configuration.nix to switch proxies at runtime. Refer to Appendix A for more information.
Changing the Configuration

The file /etc/nixos/configuration.nix contains the current configuration of your machine. Whenever you’ve changed something in that file, you should do

# nixos-rebuild switch
to build the new configuration, make it the default configuration for booting, and try to realise the configuration in the running system (e.g., by restarting system services).

Warning
This command doesn’t start/stop user services automatically. nixos-rebuild only runs a daemon-reload for each user with running user services.
Warning
These commands must be executed as root, so you should either run them from a root shell or by prefixing them with sudo -i.
You can also do

# nixos-rebuild test
to build the configuration and switch the running system to it, but without making it the boot default. So if (say) the configuration locks up your machine, you can just reboot to get back to a working configuration.

There is also

# nixos-rebuild boot
to build the configuration and make it the boot default, but not switch to it now (so it will only take effect after the next reboot).

You can make your configuration show up in a different submenu of the GRUB 2 boot screen by giving it a different profile name, e.g.

# nixos-rebuild switch -p test
which causes the new configuration (and previous ones created using -p test) to show up in the GRUB submenu “NixOS - Profile ‘test’”. This can be useful to separate test configurations from “stable” configurations.

Finally, you can do

$ nixos-rebuild build
to build the configuration but nothing more. This is useful to see whether everything compiles cleanly.





## If you have a machine that supports hardware virtualisation, you can also test the new configuration in a sandbox by building and running a QEMU virtual machine that contains the desired configuration. Just do

$ nixos-rebuild build-vm
$ ./result/bin/run-*-vm
The VM does not have any data from your host system, so your existing user accounts and home directories will not be available unless you have set mutableUsers = false. Another way is to temporarily add the following to your configuration:

users.users.your-user.initialHashedPassword = "test";
Important: delete the $hostname.qcow2 file if you have started the virtual machine at least once without the right users, otherwise the changes will not get picked up. You can forward ports on the host to the guest. For instance, the following will forward host port 2222 to guest port 22 (SSH):

$ QEMU_NET_OPTS="hostfwd=tcp::2222-:22" ./result/bin/run-*-vm
allowing you to log in via SSH (assuming you have set the appropriate passwords or SSH authorized keys):

$ ssh -p 2222 localhost




Almost all good writing begins with terrible first efforts. You need to start somewhere. (Anne Lamott)



Everything not saved will be lost. (Nintendo Quit Screen message)







https://blog.mayflower.de/5976-From-Vagrant-to-Nixops.html


## Checking reproducibility
Building a package twice can't prove it is reproducible: you might simply have gotten lucky. However, it is a useful first step.

To check whether you can reproduce a package on your machine, you can use nix-build '<nixpkgs>' -A hello --check --keep-failed or nix build nixpkgs#hello --rebuild --keep-failed.

For fixed-output derivations, run the build four times:

With an empty outputHash
With the outputHash produced in the previous build, saving the result
With an empty outputHash again
With the outputHash produced in the previous build
On failures, you can use diffoscope to analyze the differences in the outputs of the two builds. To view the build log of the build that produced the artifact in the binary cache you can use nix-store --read-log $(nix-instantiate '<nixpkgs>' -A hello).




https://diffoscope.org/




