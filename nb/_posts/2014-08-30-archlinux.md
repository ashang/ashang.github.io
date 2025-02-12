---
title: archlinux
---

```
dpkg-architecture -qDEB_HOST_MULTIARCH
x86_64-linux-gnu
```

https://www.archlinux.de/?page=PackageStatistics


# packagename

pacman -S packagename
pacman -R packagename
pacman -Syu #升级系统中的所有包
pacman -Ss package #查询软件包
pacman -Qs package #查询已安装的包
pacman -Sw package #下载但不安装包
pacman -U /path/package.pkg.tar.gz #安装本地包
pacman -Scc #清理包缓存
pacman -Sf pacman #重新安装包


# useful packages
pacman -S gbkunzip



# pacman -R

    $ sudo pacman -R pamac
    checking dependencies...

    Packages (1) pamac-2.4.1-1

    Total Removed Size:  2.84 MiB

    :: Do you want to remove these packages? [Y/n]
    (1/1) removing pamac [#######################################] 100%
    warning: /etc/pamac.conf saved as /etc/pamac.conf.pacsave
    gtk-update-icon-cache: Cache file created successfully.
    ==> The polkit-gnome agent is no longer autostarted by default
        except in GNOME Flashback.
        For Xfce, LXDE etc., lxsession is the suggested lightweight alternative.
        See https://wiki.archlinux.org/index.php/Polkit#Authentication_agents
        for more details.


systemctl edit sshd.socket
systemctl daemon-reload ssh
systemctl restart sshd
systemctl restart network-online.target
## Arch Linux

AUR package is easier to build than deb packaging.

##Installation
https://wiki.archlinux.org/index.php/Installation_Guide

###Set the keyboard layout

   The default keyboard layout is US. Alternative keyboard layouts can be
   loaded with loadkeys keymap_file: keymap files can be found in
   /usr/share/kbd/keymaps/ (path and file extension can be ommitted).

###Connect to the Internet

For supported wireless devices run wifi-menu to set up the network

###Select the mirrors

Edit /etc/pacman.d/mirrorlist and select a download mirror.
This copy of the mirrorlist file will
   later be copied on the new system by pacstrap, so it is worth getting
   it right.

###Install the base packages

   Use the pacstrap script to install the base group:
```
# pacstrap /mnt base
```

   Other packages or groups can be installed by appending their names to
   the above command (space seperated), possibly including the boot
   loader.

  Configure the system

   Generate an fstab file (use -U or -L to define by UUID or labels):
```
# genfstab -p /mnt >> /mnt/etc/fstab
```

   Change root into the new system:
```
# arch-chroot /mnt
```

   Set the hostname:
```
# echo computer_name > /etc/hostname
```

   Set the time zone:
```
# ln -sf /usr/share/zoneinfo/zone/subzone /etc/localtime
```

   Uncomment the needed locales in /etc/locale.gen, then generate them
   with:
```
# locale-gen
```

   Set locale preferences in /etc/locale.conf and possibly
   $HOME/.config/locale.conf:
```
# echo LANG=your_locale > /etc/locale.conf
```

   Add console keymap and font preferences in /etc/vconsole.conf.

   Configure the network for the newly installed environment: see Network
   configuration and Wireless network configuration.

   Configure /etc/mkinitcpio.conf if additional features are needed.
   Create a new initial RAM disk with:
```
# mkinitcpio -p linux
```

   Set the root password:
```
# passwd
```

###Install a bootloader


###Reboot

   Exit the chroot environment by typing exit or pressing Ctrl+D.

   Optionally manually unmount all the partitions with umount -R /mnt:
   this allows noticing any "busy" partitions, and finding the cause with
   fuser.

   Finally, restart the machine by typing reboot: any partitions still
   mounted will be automatically unmounted by systemd. Remember to remove
   the installation media and then login into the new system with the root
   account.

##



sudo pacman -Sy
This will only download the package lists if there has been a change.
Occasionally you may want to force the package lists to be down-
loaded. To do this, type:
sudo pacman -Syy

# Updating software
Pacman will allow you to perform an update of software already
installed with the command:
sudo pacman -Su

It’s a good idea to check whether the package lists are up-to-date at
the same time. To do so, type:
sudo pacman -Syu

You can also force a package list synchronisation before performing
an update with:
sudo pacman -Syyu



It’s also possible to remove a package and any dependencies it re-
quired when it was installed. Assuming those other packages are not
being used by another piece of software, they will become orphan
packages. These serve no function other than taking up space! To
remove a software package with its dependencies, type:
sudo pacman -Rs leafpad
A package may also create configuration files. Normally these are
left in place so your configuration is not lost, and can be reused if
you install the package again. However, if you want to remove these
configuration files too, the command is:
sudo pacman -Rns leafpad
If at a later date you want to remove all orphan packages and con-
figuration files for packages that you removed some time ago, the
following command will do it:
sudo pacman -Rns $(pacman -Qtdq)


To update the mirror list use the following command:
sudo pacman-mirrors -g


This will test the speed of all currently available mirrors and set your
machine to use the best for you. Once this command has completed,
you should force a download of the package lists with the command:

sudo pacman -Syyu


# Arch Mirrors

Server = http://mirrors.ustc.edu.cn/archlinux/$repo/os/$arch
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch

# Arch ARM

编辑/etc/pacman.d/mirrorlist，先注释掉里面的所有行，然后在文件的最顶端添加

    Server = https://mirrors.ustc.edu.cn/archlinuxarm/$arch/$repo


# Note that if you merge makepkg.conf.pacnew into your makepkg.conf and you would be fine to build glibc...

The only thing that I modified in makepkg.conf was mach=native instead of mach=generic.

Lesson learned: when a new verion of pacman is out we need to update the makepkg.conf file also.

# Arch Linux Chinese Community Repository
Packaging consistency check: [![Build Status](https://travis-ci.org/archlinuxcn/repo.svg?branch=master)](https://travis-ci.org/archlinuxcn/repo)

##Usage

Add repo

	[archlinuxcn]
	SigLevel = Optional TrustAll
	Server = https://mirrors.ustc.edu.cn/archlinuxcn/$arch

	[archlinuxcn]
	SigLevel = Optional TrustedOnly
	Server = http://repo.archlinuxcn.org/$arch

	[archlinuxcn]
	Server = http://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch

to your /etc/pacman.conf .

For mirrors (mainly in China), see https://github.com/archlinuxcn/mirrorlist-repo.

Add PGP Keys

    sudo pacman -Syy && sudo pacman -S archlinuxcn-keyring

/etc/pacman.d/mirrorlist

    Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch
    Server = http://mirrors.163.com/archlinux/$repo/os/$arch

To update package cache

    sudo pacman -Syy

## AUR mirror

/etc/yaourtrc

    AURURL="https://aur.tuna.tsinghua.edu.cn"

[rsync](rsync)
to transfer a copy of the entire tree, excluding a few selected folders.

allows greater control over file permissions, attributes, [Access Control Lists](Access_Control_Lists) and [extended attributes](extended_attributes).

All aforementioned methods will work even while the system is running, but files changed during the transfer may or may not be transferred, which can cause undefined behavior of some programs using the transferred files.

This approach works well for migrating an existing installation to a new hard drive or [SSD](SSD "wikilink").

With a single command
---------------------

Run the following command as root to make sure that rsync can access all system files and preserve the ownership:

`# rsync -aAXv --exclude={"/dev/*","/proc/*","/sys/*","/tmp/*","/run/*","/mnt/*","/media/*","/lost+found"} / `*`/path/to/backup/folder`*

By using the set of options, the files are transferred in archive mode which ensures that symbolic links, devices, permissions, ownerships, modification times, [ACLs](ACL "wikilink"), and extended attributes are preserved, assuming that the target [file system](file_system "wikilink") supports the feature.

The option causes files that match the given patterns to be excluded. The contents of , , , , and are excluded in the above command, because they are populated at boot, although the folders themselves are *not* created. is filesystem-specific. The command above depends on brace expansion available in both the [bash](https://www.gnu.org/software/bash/manual/html_node/Brace-Expansion.html) and [zsh](http://zsh.sourceforge.net/Doc/Release/Expansion.html#Brace-Expansion) shells. When using a different [shell](shell "wikilink"), patterns should be repeated manually. Quoting the exclude patterns will avoid expansion by the [shell](shell "wikilink"), which is necessary, for example, when backing up over [SSH](SSH "wikilink"). Ending the excluded paths with ensures that the directories themselves are created if they do not already exist.

You may want to include additional [rsync](rsync "wikilink") options, such as the following. See for the full list.

-   If you use many hard links, consider adding the option, which is turned off by default due to its memory expense; however, it should be no problem on most modern machines. Many hard links reside under the  directory.
-   You may want to add rsync's option if you are running this multiple times to the same backup folder. In this case make sure that the source path does not end with , or this option will only have effect on the files inside the subdirectories of the source directory, but it will have no effect on the files residing directly inside the source directory.
-   If you use any sparse files, such as virtual disks, [Docker](Docker "wikilink") images and similar, you should add the  option.
-   The option will disable mapping of user and group names; instead, numeric group and user IDs will be transfered. This is useful when backing up over [SSH](SSH "wikilink") or when using a live system to backup different system disk.
-   Choosing option instead of will show the overall progress info and transfer speed instead of the list of files being transferred.

If you wish to restore the backup, use the same rsync command that was executed but with the source and destination reversed.

Boot requirements
-----------------

Having a bootable backup can be useful in case the filesystem becomes corrupt or if an update breaks the system. The backup can also be used as a test bed for updates, with the *testing* repo enabled, etc. If you transferred the system to a different partition or drive and you want to boot it, the process is as simple as updating the backup's and your bootloader's configuration file.

This section assumes that you backed up the system to another drive or partition, that your current bootloader is working fine, and that you want to boot from the backup as well.

## Update the fstab

Without rebooting, edit the backup's [fstab](fstab "wikilink") by commenting out or removing any existing entries. Add one entry for the partition containing the backup like the example here:

`/dev/sda`*`X`*`    /             `*`ext4`*`      defaults                 0   1`

Remember to use the proper device name and filesystem type.

## Update the bootloader's configuration file

For [Syslinux](Syslinux "wikilink"), all you need to do is duplicate the current entry, except pointing to a different drive or partition.

For [GRUB](GRUB "wikilink"), it is recommended that you automatically [re-generate the main configuration file](GRUB#Generate_the_main_configuration_file "wikilink"). If you want to freshly install all grub files to somewhere other than , such as , use the flag.

Also verify the new menu entry in . Make sure the UUID is matching the new partition, otherwise it could still boot the old system. Find the UUID of a partition as follows:

`# lsblk -no NAME,UUID /dev/sdb3`

where you substitute the desired partition for /dev/sdb3. To list the UUIDs of partitions grub thinks it can boot, use grep:

`# grep UUID= /boot/grub/grub.cfg`

First boot
----------

Reboot the computer and select the right entry in the bootloader. This will load the system for the first time. All peripherals should be detected and the empty folders in will be populated.

Now you can re-edit to add the previously removed partitions and mount points.

See also
--------

-   [Howto – local and remote snapshot backup using rsync with hard links](http://blog.pointsoftware.ch/index.php/howto-local-and-remote-snapshot-backup-using-rsync-with-hard-links/) Includes file deduplication with hard-links, MD5 integrity signature, 'chattr' protection, filter rules, disk quota, retention policy with exponential distribution (backups rotation while saving more recent backups than older)

<de:Backups> [ja:バックアッププログラム](ja:バックアッププログラム "wikilink") [ru:Backup programs](ru:Backup_programs "wikilink")

This page lists and compares applications that synchronize data between two or more locations, and those that build on top of such functionality to make incremental copies of important data for backup purposes. Because of their relationship, the two groups share several traits that justify describing them in the same article.

Backup overview
---------------

Having backups of important data is a necessary measure to take, since human and machine processing errors are very likely to generate corruption as time passes, and also the physical media where the data is stored is inevitably destined to fail. In order to choose the best program for one's own needs, the following aspects should be considered:

-   The type of backup medium that is going to store the data, e.g. CD, DVD, remote server, external hard drive, etc.
-   The planned frequency of backups, e.g. daily, weekly, monthly, etc.
-   The features expected from the backup solution, e.g. compression, encryption, handles renames, etc.
-   The planned method to restore backups if needed.

Data synchronization
--------------------

These applications simply keep directories synchronized between multiple locations/machines, in a "mirror" fashion. Nonetheless, most of them still allow storing and reverting to old revisions of modified or deleted files.

See also [Wikipedia:Comparison of file synchronization software](Wikipedia:Comparison_of_file_synchronization_software "wikilink").

**Legend:**

-   **Name**: the application name, linking to the official website.
-   **Installation**: a link to the main ArchWiki article, if existing, or directly to the package pages.
-   **Implementation**: the programming language, library, or utility that the application is based on.
-   **Delta transfer**: only the modified *parts* of files are transferred.
-   **Encrypted transfer**: data is encrypted by default when transferred over the network.
-   **FS metadata**: file system permissions and attributes are synchronized.
-   **Resumable**: the synchronization can be resumed without restarting it if interrupted.
-   **Handles renames**: moved/renamed files are detected and not stored or transferred twice; it typically means that a checksum is computed for files or chunks thereof.
-   **Version control**: the old version of files are backed up (**reverse incremental backup**).
-   **Conflict resolution**: the application handles file conflicts, either automatically or interactively, i.e. it does not silently discard conflicting files.
-   **Multidirectional**: *more* than 2 locations can be kept in sync together.
-   **FS monitoring**: the application listens to file system events to trigger the synchronization.
-   **CLI**: the application is command-line driven, i.e. it is scriptable.
-   **Other interfaces**: the application has the specified user interfaces, e.g. GUI, TUI, or web-based.
-   **Licence**: the licence of the server and client applications.
-   **Other platforms**: supported operating systems other than Linux.
-   **Active**: whether the project is currently maintained.
-   **Specificity**: brief notes about special features that notably set the application apart from the others.

| Name                                                                            | Installation                            | Implementation     | Delta transfer | Encrypted transfer                    | FS metadata | Resumable | Handles renames | Version control                             | Conflict resolution | Multidirectional | FS monitoring | CLI | Other interfaces | Licence              | Other platforms                                                         | Active | Specificity                                  |
|---------------------------------------------------------------------------------|-----------------------------------------|--------------------|----------------|---------------------------------------|-------------|-----------|-----------------|---------------------------------------------|---------------------|------------------|---------------|-----|------------------|----------------------|-------------------------------------------------------------------------|--------|----------------------------------------------|
| [Resilio Sync](https://www.resilio.com/individuals/) (formerly BitTorrent Sync) | [Resilio Sync](Resilio_Sync "wikilink") | Closed source      |                | , also LAN transfer encryption option | ?           |           | ?               | , previous versions moved to archive folder | ?                   |                  | ?             |     |                  | Proprietary freemium | OS X, Windows, Android, iOS, Windows Phone, Amazon Kindle Fire, FreeBSD |        | P2P sync                                     |
| [FreeFileSync](http://freefilesync.sourceforge.net/)                            |                                         | C++                | ?              |                                       | ?           | ?         |                 |                                             | ?                   |                  | ?             |     |                  | GPL                  | Windows, OS X                                                           |        |                                              |
| [git-annex](http://git-annex.branchable.com/)                                   |                                         | Haskell, git       |                |                                       | ?           | ?         | ?               |                                             | ?                   |                  | ?             |     |                  | GPLv3                | OS X, Android                                                           |        | Manage files with git                        |
| [Grsync](http://www.opbyte.it/grsync/)                                          |                                         | rsync front-end    |                |                                       | ?           | ?         | ?               | ?                                           | ?                   |                  | ?             |     |                  | GPLv2                |                                                                         | ?      |                                              |
| [gutbackup](https://github.com/gutenye/gutbackup)                               |                                         | rsync wrapper      |                |                                       | ?           | ?         | ?               | ?                                           | ?                   |                  | ?             |     |                  | MIT                  |                                                                         | ?      |                                              |
| [Jotasync](http://jotasync.trixon.se/)                                          |                                         | Java gui for rsync |                |                                       | ?           | ?         | ?               | ?                                           | ?                   |                  | ?             |     |                  | Apache v2            | OS X, Windows                                                           |        | Integrated scheduler.                        |
| [luckyBackup](http://luckybackup.sourceforge.net/index.html)                    |                                         | C++                |                |                                       | ?           | ?         | ?               |                                             | ?                   |                  | ?             |     |                  | GPLv3                |                                                                         |        |                                              |
| [osync.sh](http://www.netpower.fr/osync)                                        |                                         | Shell              |                |                                       | ?           |           | ?               |                                             | ?                   |                  |               |     |                  | BSD                  |                                                                         |        |                                              |
| [rdiff-backup](http://www.nongnu.org/rdiff-backup/)                             |                                         | Python 2           |                |                                       |             | ?         |                 |                                             |                     |                  |               |     |                  | GPL                  | Win32                                                                   | ?      |                                              |
| [rsync](http://rsync.samba.org/)                                                | [rsync](rsync "wikilink")               | C                  |                |                                       |             |           |                 |                                             |                     |                  |               |     |                  | GPLv3                | Win32                                                                   |        | Standard install on all Linux distributions. |
| [SparkleShare](http://sparkleshare.org/)                                        |                                         | C\#                | ?              | ?                                     | ?           | ?         | ?               | ?                                           | ?                   | ?                | ?             |     |                  | GPLv3                | Windows, OS X                                                           | ?      |                                              |
| [Syncthing](https://syncthing.net/)                                             | [Syncthing](Syncthing "wikilink")       | Go                 |                |                                       |             | ?         | ?               | , previous versions moved to archive folder |                     |                  |               |     |                  | MPL v2               | Windows, OS X, Android, BSD, Solaris                                    |        | P2P sync                                     |
| [Synkron](http://synkron.sourceforge.net/)                                      |                                         | C++                | ?              | ?                                     | ?           | ?         | ?               | ?                                           | ?                   |                  | ?             |     |                  | GPLv2                | Windows, OS X                                                           |        |                                              |
| [taskd](https://tasktools.org/projects/taskd.html)                              | [Taskd](Taskd "wikilink")               | C++, python,       |                |                                       | ?           |           | ?               | ?                                           | ?                   |                  |               |     |                  | MIT                  | Android                                                                 |        |                                              |
| [Unison](http://www.cis.upenn.edu/~bcpierce/unison/)                            | [Unison](Unison "wikilink")             | OCaml              |                |                                       |             |           |                 |                                             |                     |                  |               |     |                  | GPL                  | Windows, OS X, FreeBSD, Android                                         |        |                                              |
| Name                                                                            | Installation                            | Implementation     | Delta transfer | Encrypted transfer                    | FS metadata | Resumable | Handles renames | Version control                             | Conflict resolution | Multidirectional | FS monitoring | CLI | Other interfaces | Licence              | Other platforms                                                         | Active | Specificity                                  |

Incremental backups
-------------------

Applications that can do incremental backups remember and take into account what data has been backed up during the last run (so-called "diffs") and eliminate the need to have duplicates of unchanged data. Restoring the data to a certain point in time would require locating the last full backup and all the incremental backups from then to the moment when it is supposed to be restored. This sort of backup is useful for those who do it very often.

See also [Dotfiles\#Version control](Dotfiles#Version_control "wikilink").

**Legend:**

-   **Name**: the application name, linking to the official website.
-   **Installation**: a link to the main ArchWiki article, if existing, or directly to the package pages.
-   **Implementation**: the programming language, library, or utility that the application is based on.
-   **Compressed storage**: compression is used for storage.
-   **Encrypted storage**: encryption is used for storage.
-   **Delta transfer**: only the modified *parts* of files are transferred.
-   **Encrypted transfer**: data is encrypted by default when transferred over a network.
-   **FS metadata**: file system permissions and attributes are backed up.
-   **Easy access**: the backup is stored plainly in the file system, or is mountable as such.
-   **Resumable**: the backup can be resumed without restarting it if interrupted.
-   **Handles renames**: moved/renamed files are detected and not stored or transferred twice; it typically means that a checksum is computed for files or chunks thereof.
-   **CLI**: the application is command-line driven, i.e. it is scriptable.
-   **Other interfaces**: the application has the specified user interfaces, e.g. GUI, TUI, or web-based.
-   **Licence**: the licence of the server and client applications.
-   **Other platforms**: supported operating systems other than Linux.
-   **Active**: whether the project is currently maintained.
-   **Specificity**: brief notes about special features that notably set the application apart from the others.

## Single machine

These applications are aimed at backing up data from the machine they are installed on, although the backup destination can be located on an external machine or storage media.

### Chunk-based increments

If a file is modified, these applications store only its changed *parts* at the next snapshot. Compared to [\#File-based increments](#File-based_increments "wikilink") applications, these are more space-efficient, especially when large files receive small modifications; on the other hand, the archived snapshots have to be opened with the backup application that created them, since the files have to be reconstructed from the stored binary diffs.

| Name                                                                                       | Installation                      | Implementation       | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata                                                                                             | Easy access                                                            | Resumable                                                                                                                      | Handles renames | CLI | Other interfaces | Licence | Other platforms                | Active | Specificity                                                                                                                 |
|--------------------------------------------------------------------------------------------|-----------------------------------|----------------------|--------------------|-------------------|----------------|--------------------|---------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------|-----------------|-----|------------------|---------|--------------------------------|--------|-----------------------------------------------------------------------------------------------------------------------------|
| [Areca Backup](http://areca.sourceforge.net/)                                              |                                   | Java                 |                    |                   |                |                    |                                                                                                         |                                                                        |                                                                                                                                |                 |     |                  | GPLv2   | Windows                        |        |                                                                                                                             |
| [Attic](https://github.com/jborg/attic/)                                                   |                                   | Python               |                    |                   |                |                    |                                                                                                         |                                                                        |                                                                                                                                |                 |     |                  | BSD     |                                |        |                                                                                                                             |
| [BorgBackup](http://borgbackup.readthedocs.org/en/stable/)                                 |                                   | Python (Attic fork)  |                    |                   |                |                    | [1](http://borgbackup.readthedocs.org/en/stable/faq.html#which-file-types-attributes-etc-are-preserved) | [2](http://borgbackup.readthedocs.org/en/stable/usage.html#borg-mount) | [3](http://borgbackup.readthedocs.org/en/stable/faq.html#if-a-backup-stops-mid-way-does-the-already-backed-up-data-stay-there) |                 |     |                  | BSD     | -   BSD, OS X                  |        |                                                                                                                             |
| [btar](http://viric.name/cgi-bin/btar)                                                     |                                   | C                    |                    |                   |                |                    | ?                                                                                                       |                                                                        | ?                                                                                                                              | ?               |     |                  | GPLv3   |                                |        | Redundancy, indexed extraction, multicore compression, input and output serialisation, tolerance to partial archive errors. |
| [bup](https://bup.github.io/)                                                              |                                   | C, Python, git       |                    |                   |                |                    |                                                                                                         | [4](https://bup.github.io/man/bup-fuse.html)                           |                                                                                                                                |                 |     |                  | GPLv2   | Windows, OS X, NetBSD, Solaris |        | Same storage format as git                                                                                                  |
| [bups](https://github.com/emersion/bups)                                                   |                                   | bup frontend         |                    |                   |                |                    |                                                                                                         |                                                                        |                                                                                                                                |                 |     |                  | MIT     |                                |        |                                                                                                                             |
| [Déjà Dup](https://launchpad.net/deja-dup)                                                 | [Déjà Dup](Déjà_Dup "wikilink")   | duplicity front-end  |                    |                   |                |                    | ?                                                                                                       |                                                                        |                                                                                                                                |                 |     |                  | GPLv3   |                                |        | Integrated into [GNOME Files](GNOME_Files "wikilink").                                                                      |
| [Duplicati](http://www.duplicati.com/)                                                     |                                   | C\#                  |                    |                   |                |                    |                                                                                                         |                                                                        |                                                                                                                                |                 |     |                  | LGPL    | Windows                        |        |                                                                                                                             |
| [Duplicity](http://www.nongnu.org/duplicity/)                                              | [Duplicity](Duplicity "wikilink") | librsync             |                    |                   |                |                    | ?                                                                                                       |                                                                        |                                                                                                                                |                 |     |                  | GPL     |                                |        |                                                                                                                             |
| [Duply](http://www.duply.net/)                                                             | [Duply](Duply "wikilink")         | duplicity front-end  |                    |                   |                |                    | ?                                                                                                       |                                                                        |                                                                                                                                |                 |     |                  | GPLv2   |                                |        |                                                                                                                             |
| [Kup Backup System](http://kde-apps.org/content/show.php/Kup+Backup+System?content=147465) |                                   | rsync, bup front-end |                    |                   |                |                    |                                                                                                         |                                                                        |                                                                                                                                |                 |     |                  | GPLv2   |                                |        |                                                                                                                             |
| [obnam](http://liw.fi/obnam/)                                                              |                                   | Python               |                    |                   |                |                    | ?                                                                                                       |                                                                        |                                                                                                                                | ?               |     |                  | GPLv3   |                                |        |                                                                                                                             |
| [ZBackup](http://zbackup.org/)                                                             |                                   | C++                  |                    |                   |                |                    | ?                                                                                                       |                                                                        |                                                                                                                                |                 |     |                  | GPLv2   |                                |        | Repository consists of immutable files.                                                                                     |
| Name                                                                                       | Installation                      | Implementation       | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata                                                                                             | Easy access                                                            | Resumable                                                                                                                      | Handles renames | CLI | Other interfaces | Licence | Other platforms                | Active | Specificity                                                                                                                 |

### File-based increments

If a file is modified, these applications store its new version entirely at the next snapshot. Compared to [\#Chunk-based increments](#Chunk-based_increments "wikilink") applications, these are less space-efficient, especially when large files receive small modifications; on the other hand, often the archived snapshots can be opened without the need to have the backup application installed.

**Specific legend:**

-   **Hard links**: whether unmodified files are stored as hard links to previous versions.

| Name                                                           | Installation                            | Implementation      | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata | Easy access | Resumable | Handles renames | Hard links | CLI | Other interfaces | Licence | Other platforms                                        | Active | Specificity                                                       |
|----------------------------------------------------------------|-----------------------------------------|---------------------|--------------------|-------------------|----------------|--------------------|-------------|-------------|-----------|-----------------|------------|-----|------------------|---------|--------------------------------------------------------|--------|-------------------------------------------------------------------|
| [Back In Time](https://github.com/bit-team/backintime)         | [Back In Time](Back_In_Time "wikilink") | Python, rsync, diff |                    |                   |                |                    |             |             |           |                 |            |     |                  | GPLv2   |                                                        |        |                                                                   |
| [DAR](http://dar.linux.free.fr/) (Disk ARchive)                |                                         | C++                 |                    |                   | ?              |                    | ?           | ?           | ?         | ?               |            |     |                  | GPL     | Windows, Solaris, FreeBSD, NetBSD, MacOS X             |        | Automatic backup using [cron](cron "wikilink") is possible with . |
| [DarGUI](http://dargui.sourceforge.net/)                       |                                         | DAR front-end       |                    |                   | ?              |                    | ?           | ?           | ?         | ?               |            |     |                  | GPL     | Windows                                                | ?      |                                                                   |
| [hdup](http://miek.nl/projects/hdup2/)                         |                                         | C                   |                    |                   | ?              |                    | ?           |             |           |                 |            |     |                  | GPLv2   |                                                        |        | Multiple backup targets.                                          |
| [Link-Backup](http://www.scottlu.com/Content/Link-Backup.html) |                                         | Python              |                    |                   | ?              |                    | ?           | ?           |           |                 |            |     |                  | MIT     |                                                        |        | It copies itself to the server.                                   |
| [rdup](https://github.com/miekg/rdup)                          |                                         | C                   |                    |                   | ?              | ?                  | ?           |             | ?         |                 |            |     |                  | GPLv3   |                                                        |        | Set of command-line tools.                                        |
| [rsnapshot](http://www.rsnapshot.org/)                         | [rsnapshot](rsnapshot "wikilink")       | rsync               |                    |                   |                |                    | ?           | ?           | ?         | ?               |            |     |                  | GPLv2   | Win32                                                  |        |                                                                   |
| [sbackup](https://launchpad.net/sbackup)                       |                                         | Python              |                    |                   | ?              |                    | ?           |             |           |                 |            |     |                  | GPLv3   |                                                        |        |                                                                   |
| [TimeShift](https://launchpad.net/timeshift)                   |                                         | rsync               |                    |                   |                |                    | ?           | ?           | ?         | ?               |            |     |                  | GPLv3   | Designed for full-system backups to dedicated devices. |        |                                                                   |
| Name                                                           | Installation                            | Implementation      | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata | Easy access | Resumable | Handles renames | Hard links | CLI | Other interfaces | Licence | Other platforms                                        | Active | Specificity                                                       |

## Network oriented

These applications have been designed to centralize the backup of several machines connected to a network, through a server-client model. In general they are more complicated to deploy, compared to [\#Single machine](#Single_machine "wikilink") solutions.

**Specific legend:**

-   **Increment type**: the strategy used to reduce used space by deduplicating data (i.e., besides compression).
    -   **file-based**: if a file is modified, the entire new version is stored at each snapshot.
        -   **hard-links**: whether unmodified files are stored as hard links to previous versions.
    -   **chunk-based**: only the modified *parts* of files are stored at each snapshot.

| Name                                                                                                            | Installation                                                                          | Implementation    | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata | Easy access | Resumable | Handles renames | Increment type                                                                                                                                                                                                                            | CLI      | Other interfaces | Licence | Other platforms        | Active | Specificity                                                                                                                                             |
|-----------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------|-------------------|--------------------|-------------------|----------------|--------------------|-------------|-------------|-----------|-----------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------|------------------|---------|------------------------|--------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| [BackupPC](http://backuppc.sourceforge.net/index.html)                                                          | [BackupPC](BackupPC "wikilink")                                                       | Perl              |                    |                   |                |                    |             |             |           | ?               | file-based, hard links [5](http://backuppc.sourceforge.net/faq/BackupPC.html#Backup-basics)                                                                                                                                               |          |                  | GPLv2   | Any (no client needed) |        | Identical files across backups of the same or different clients are stored only once.                                                                   |
| [Bacula](http://www.bacula.org)                                                                                 | [bacula-\*](https://aur.archlinux.org/packages/?K=bacula-) in [AUR](AUR "wikilink")   | C++               |                    |                   | ?              |                    | ?           | ?           |           | ?               | file-based [6](http://burp.grke.org/why.html)                                                                                                                                                                                             |          |                  | AGPLv3  | Windows, OS X          |        |                                                                                                                                                         |
| [burp](http://burp.grke.org)                                                                                    |                                                                                       | librsync          |                    |                   |                |                    | ?           | ?           | ?         | ?               | chunk-based [7](http://burp.grke.org/why.html)                                                                                                                                                                                            |          |                  | AGPLv3  | Windows                |        |                                                                                                                                                         |
| [SafeKeep](http://safekeep.sourceforge.net/)                                                                    |                                                                                       | rdiff-backup      |                    |                   | ?              |                    | ?           | ?           | ?         | ?               | chunk-based [8](http://safekeep.sourceforge.net/safekeep.html)                                                                                                                                                                            |          |                  | GPL     |                        |        | Integrates with [LVM](LVM "wikilink") and databases to create consistent backups. Bandwidth throttling.                                                 |
| [Snebu](http://www.snebu.com)                                                                                   |                                                                                       | C                 |                    |                   | ?              |                    | ?           | ?           | ?         | ?               | ?                                                                                                                                                                                                                                         |          |                  | GPLv3   |                        | ?      | Supports arbitrary retention schedules.                                                                                                                 |
| [Synbak](http://www.initzero.it/portal/soluzioni/software-open-source/synbak-universal-backup-system_2623.html) |                                                                                       | Multitool wrapper |                    |                   |                |                    |             | ?           | ?         | ?               | ?                                                                                                                                                                                                                                         |          |                  | GPLv3   |                        |        | Unifies several backup methods.                                                                                                                         |
| [UrBackup](https://www.urbackup.org)                                                                            | [urbackup\*](https://aur.archlinux.org/packages/?K=urbackup) in [AUR](AUR "wikilink") | C++               |                    |                   |                |                    |             |             |           |                 | file-based,hard-links and symlinks\[<http://blog.urbackup.org/156/symbolically-linking-directories-during-incremental-file-backups%5D/chunk-based> CoW-Snapshots[9](http://blog.urbackup.org/83/file-backup-storage-with-btrfs-snapshots) | (client) |                  | AGPLv3+ | Windows, macOS         |        | Identical files across backups of the same or different clients are stored only once. Integrates with LVM, dattobd and btrfs for file system snapshots. |
| Name                                                                                                            | Installation                                                                          | Implementation    | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata | Easy access | Resumable | Handles renames | Increment type                                                                                                                                                                                                                            | CLI      | Other interfaces | Licence | Other platforms        | Active | Specificity                                                                                                                                             |

Cloud storage
-------------

## Third-party services

See also [Wikipedia:Comparison of online backup services](Wikipedia:Comparison_of_online_backup_services "wikilink").

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-   ,  (free)

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

### Multi-service clients

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

## Custom infrastructure

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

Version control systems
-----------------------

These are traditionally used for keeping track of software development; but if you want to have a simple way to manage your config files in one directory, it might be a good solution.

See also [Wikipedia:Comparison of revision control software](Wikipedia:Comparison_of_revision_control_software "wikilink").

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

See also
--------

-   [Wikipedia:List of backup software](Wikipedia:List_of_backup_software "wikilink")
-   [Wikipedia:Comparison of backup software](Wikipedia:Comparison_of_backup_software "wikilink")
-   [Backing up Linux and other Unix(-like) systems](http://www.halfgaar.net/backing-up-unix)
-   [Mirroring an Entire Site using Rsync over SSH](http://www.askapache.com/security/mirror-using-rsync-ssh.html)
-   [Performance comparison of five remote incremental backup tools: Rsync, Rdiff-backup, Duplicity, Areca and Link-Backup](http://www.si-journal.org/index.php/JSI/article/view/205)
-   [rsync-snapshot.sh](http://blog.pointsoftware.ch/index.php/howto-local-and-remote-snapshot-backup-using-rsync-with-hard-links/) — Local and remote snapshot backup using rsync with hard links

<es:Rsync> <ja:Rsync> <zh-CN:Rsync> [rsync](https://rsync.samba.org/) is an open source utility that provides fast incremental file transfer.

Installation
------------

[Install](Install "wikilink") the package.

Usage
-----

For more examples, search the [Community Contributions](https://bbs.archlinux.org/viewforum.php?id=27) and [General Programming](https://bbs.archlinux.org/viewforum.php?id=33) forums.

## As a cp alternative

rsync can be used as an advanced alternative for the command, especially for copying larger files:

`$ rsync -P source destination`

The option is the same as , which keeps partially transferred files and shows a progress bar during transfer.

You may want to use the option to recurse into directories.

Files can be copied locally as with cp, but the motivating purpose of rsync is to copy files remotely, i.e. between two different hosts. Remote locations can be specified with a host-colon syntax:

`$ rsync source host:destination`

or

`$ rsync host:source destination`

Network file transfers use the SSH protocol by default.

Whether transferring files locally or remotely, rsync first creates an index of block checksums of each source file. This index is used to find any identical blocks of data which might exist in the destination. Such blocks are used in-place, rather than being copied from the source. This can greatly accelerate the synchronization of large files with small changes. For more information, see [official documentation](https://rsync.samba.org/documentation.html), [how rsync works](https://rsync.samba.org/how-rsync-works.html).

### Trailing slash caveat

Arch by default uses GNU cp (part of [GNU coreutils](https://www.archlinux.org/packages/?name=coreutils)). However, rsync follows the convention of BSD cp, which gives special treatment to source directories with a trailing slash "/". Although

`$ rsync -r source destination`

creates a directory "destination/source" with the contents of "source", the command

`$ rsync -r source/ destination`

copies all of the files in "source/" directly into "destination", with no intervening subdirectory - just as if you had invoked it as

`$ rsync -r source/. destination`

This behavior is different from that of GNU cp, which treats "source" and "source/" identically (but not "source/."). Also, some shells automatically append the trailing slash when tab-completing directory names. Because of these factors, there can be a tendency among new or occasional rsync users to forget about rsync's different behavior, and inadvertently create a mess or even overwrite important files by leaving the trailing slash on the command line.

Thus it can be prudent to use a wrapper script to automatically remove trailing slashes before invoking rsync:

`#!/bin/zsh`
`new_args=();`
`for i in "$@"; do`
`    case $i in /) i=/;; */) i=${i%/};; esac`
`    new_args+=$i;`
`done`
`exec rsync "${(@)new_args}"`

This script can be put somewhere in the path, and aliased to rsync in the shell init file.

## As a backup utility

The rsync protocol can easily be used for backups, only transferring files that have changed since the last backup. This section describes a very simple scheduled backup script using rsync, typically used for copying to removable media. For a more thorough example and **additional options required to preserve some system files**, see [Full system backup with rsync](Full_system_backup_with_rsync "wikilink").

### Automated backup

For the sake of this example, the script is created in the directory, and will be run on a daily basis if a cron [daemon](daemon "wikilink") is installed and properly configured. Configuring and using [cron](cron "wikilink") is outside the scope of this article.

First, create a script containing the appropriate command options:

 : indicates that files should be archived, meaning that most of their characteristics are preserved (but **not** ACLs, hard links or extended attributes such as capabilities)
 : means files deleted on the source are to be deleted on the backup as well

Here, should be changed to what needs to be backed-up (, for example) and is where the backup should be saved (, for instance).

Finally, the script must be executable:

`# chmod +x /etc/cron.daily/backup`

### Automated backup with SSH

If backing-up to a remote host using [SSH](SSH "wikilink"), use this script instead:

 : tells rsync to use SSH
 : is the user on the host
 : groups all these options  (recursive, links, perms, times, group, owner, devices)

### Automated backup with NetworkManager

This script starts a backup when you plugin your wire.

First, create a script containing the appropriate command options:

 : group all this options  recursive, links, perms, times, group, owner, devices
 : read the relative path of */folder/to/backup* from this file
 : limit I/O bandwidth; KBytes per second

Also, the script must have write permission for owner (root, of course) only (see [NetworkManager dispatcher](NetworkManager#Network_services_with_NetworkManager_dispatcher "wikilink") for details).

### Automated backup with systemd and inotify

Instead of running time interval backups with time based schedules, such as those implemented in [cron](cron "wikilink"), it is possible to run a backup every time one of the files you are backing up changes. units use to monitor the filesystem, and can be used in conjunction with files to start any process (in this case your [rsync](rsync "wikilink") backup) based on a filesystem event.

First, create the file that will monitor the files you are backing up:

Then create a file that will be activated when it detects a change. By default a service file of the same name as the path unit (in this case ) will be activated, except with the extension instead of (in this case ).

Now all you have to do is [start](start "wikilink")/enable like a normal systemd service and it will start monitoring file changes and automatically starting .

### Differential backup on a week

This is a useful option of rsync, creating a full backup and a differential backup for each day of a week.

First, create a script containing the appropriate command options:

 : implies  update destination files in-place

### Snapshot backup

The same idea can be used to maintain a tree of snapshots of your files. In other words, a directory with date-ordered copies of the files. The copies are made using hardlinks, which means that only files that did change will occupy space. Generally speaking, this is the idea behind Apple's TimeMachine.

This basic script is easy to implement and creates quick incremental snapshots using the option to hardlink unchanged files:

There must be a symlink to a full backup already in existence as a target for . If the most recent snapshot is deleted, the symlink will need to be recreated to point to the most recent snapshot. If does not find a working symlink, rsync will proceed to copy all source files instead of only the changes.

A more sophisticated version checks to see if a certain number of changes have been made before making the backup and utilizes to hardlink unchanged files:

To make things really, really simple this script can be run from a [systemd/Timers](systemd/Timers "wikilink") unit.

## rsync daemon

*rsync* can be run as daemon on a server listening on port .

Edit the template , configure a share and [start](start "wikilink") the .

Usage from client, e.g. list server content:

`$ rsync `[`rsync://`](rsync://)*`server/share`*

transfer file from client to server:

`$ rsync `*`local-file`*` `[`rsync://`](rsync://)*`server/share/`*

Consider iptables to open port and user authentication.


https://www.archlinux.de/?page=PackageStatistics


# packagename

pacman -S packagename
pacman -R packagename
pacman -Syu #升级系统中的所有包
pacman -Ss package #查询软件包
pacman -Qs package #查询已安装的包
pacman -Sw package #下载但不安装包
pacman -U /path/package.pkg.tar.gz #安装本地包
pacman -Scc #清理包缓存
pacman -Sf pacman #重新安装包


systemctl edit sshd.socket
systemctl daemon-reload ssh
systemctl restart sshd
systemctl restart network-online.target

# useful packages
pacman -S gbkunzip



# pacman -R

    $ sudo pacman -R pamac
    checking dependencies...

    Packages (1) pamac-2.4.1-1

    Total Removed Size:  2.84 MiB

    :: Do you want to remove these packages? [Y/n]
    (1/1) removing pamac [#######################################] 100%
    warning: /etc/pamac.conf saved as /etc/pamac.conf.pacsave
    gtk-update-icon-cache: Cache file created successfully.
    ==> The polkit-gnome agent is no longer autostarted by default
        except in GNOME Flashback.
        For Xfce, LXDE etc., lxsession is the suggested lightweight alternative.
        See https://wiki.archlinux.org/index.php/Polkit#Authentication_agents
        for more details.




[rsync](rsync]
to transfer a copy of the entire tree, excluding a few selected folders.

allows greater control over file permissions, attributes, [Access Control Lists](Access_Control_Lists) and [extended attributes](extended_attributes).

All aforementioned methods will work even while the system is running, but files changed during the transfer may or may not be transferred, which can cause undefined behavior of some programs using the transferred files.

This approach works well for migrating an existing installation to a new hard drive or [SSD](SSD "wikilink").

With a single command
---------------------

Run the following command as root to make sure that rsync can access all system files and preserve the ownership:

`# rsync -aAXv --exclude={"/dev/*","/proc/*","/sys/*","/tmp/*","/run/*","/mnt/*","/media/*","/lost+found"} / `*`/path/to/backup/folder`*

By using the set of options, the files are transferred in archive mode which ensures that symbolic links, devices, permissions, ownerships, modification times, [ACLs](ACL "wikilink"), and extended attributes are preserved, assuming that the target [file system](file_system "wikilink") supports the feature.

The option causes files that match the given patterns to be excluded. The contents of , , , , and are excluded in the above command, because they are populated at boot, although the folders themselves are *not* created. is filesystem-specific. The command above depends on brace expansion available in both the [bash](https://www.gnu.org/software/bash/manual/html_node/Brace-Expansion.html) and [zsh](http://zsh.sourceforge.net/Doc/Release/Expansion.html#Brace-Expansion) shells. When using a different [shell](shell "wikilink"), patterns should be repeated manually. Quoting the exclude patterns will avoid expansion by the [shell](shell "wikilink"), which is necessary, for example, when backing up over [SSH](SSH "wikilink"). Ending the excluded paths with ensures that the directories themselves are created if they do not already exist.

You may want to include additional [rsync](rsync "wikilink") options, such as the following. See for the full list.

-   If you use many hard links, consider adding the option, which is turned off by default due to its memory expense; however, it should be no problem on most modern machines. Many hard links reside under the  directory.
-   You may want to add rsync's option if you are running this multiple times to the same backup folder. In this case make sure that the source path does not end with , or this option will only have effect on the files inside the subdirectories of the source directory, but it will have no effect on the files residing directly inside the source directory.
-   If you use any sparse files, such as virtual disks, [Docker](Docker "wikilink") images and similar, you should add the  option.
-   The option will disable mapping of user and group names; instead, numeric group and user IDs will be transfered. This is useful when backing up over [SSH](SSH "wikilink") or when using a live system to backup different system disk.
-   Choosing option instead of will show the overall progress info and transfer speed instead of the list of files being transferred.

If you wish to restore the backup, use the same rsync command that was executed but with the source and destination reversed.

Boot requirements
-----------------

Having a bootable backup can be useful in case the filesystem becomes corrupt or if an update breaks the system. The backup can also be used as a test bed for updates, with the *testing* repo enabled, etc. If you transferred the system to a different partition or drive and you want to boot it, the process is as simple as updating the backup's and your bootloader's configuration file.

This section assumes that you backed up the system to another drive or partition, that your current bootloader is working fine, and that you want to boot from the backup as well.

### Update the fstab

Without rebooting, edit the backup's [fstab](fstab "wikilink") by commenting out or removing any existing entries. Add one entry for the partition containing the backup like the example here:

`/dev/sda`*`X`*`    /             `*`ext4`*`      defaults                 0   1`

Remember to use the proper device name and filesystem type.

### Update the bootloader's configuration file

For [Syslinux](Syslinux "wikilink"), all you need to do is duplicate the current entry, except pointing to a different drive or partition.

For [GRUB](GRUB "wikilink"), it is recommended that you automatically [re-generate the main configuration file](GRUB#Generate_the_main_configuration_file "wikilink"). If you want to freshly install all grub files to somewhere other than , such as , use the flag.

Also verify the new menu entry in . Make sure the UUID is matching the new partition, otherwise it could still boot the old system. Find the UUID of a partition as follows:

`# lsblk -no NAME,UUID /dev/sdb3`

where you substitute the desired partition for /dev/sdb3. To list the UUIDs of partitions grub thinks it can boot, use grep:

`# grep UUID= /boot/grub/grub.cfg`

First boot
----------

Reboot the computer and select the right entry in the bootloader. This will load the system for the first time. All peripherals should be detected and the empty folders in will be populated.

Now you can re-edit to add the previously removed partitions and mount points.

See also
--------

-   [Howto – local and remote snapshot backup using rsync with hard links](http://blog.pointsoftware.ch/index.php/howto-local-and-remote-snapshot-backup-using-rsync-with-hard-links/) Includes file deduplication with hard-links, MD5 integrity signature, 'chattr' protection, filter rules, disk quota, retention policy with exponential distribution (backups rotation while saving more recent backups than older)

<de:Backups> [ja:バックアッププログラム](ja:バックアッププログラム "wikilink") [ru:Backup programs](ru:Backup_programs "wikilink")

This page lists and compares applications that synchronize data between two or more locations, and those that build on top of such functionality to make incremental copies of important data for backup purposes. Because of their relationship, the two groups share several traits that justify describing them in the same article.

Backup overview
---------------

Having backups of important data is a necessary measure to take, since human and machine processing errors are very likely to generate corruption as time passes, and also the physical media where the data is stored is inevitably destined to fail. In order to choose the best program for one's own needs, the following aspects should be considered:

-   The type of backup medium that is going to store the data, e.g. CD, DVD, remote server, external hard drive, etc.
-   The planned frequency of backups, e.g. daily, weekly, monthly, etc.
-   The features expected from the backup solution, e.g. compression, encryption, handles renames, etc.
-   The planned method to restore backups if needed.

Data synchronization
--------------------

These applications simply keep directories synchronized between multiple locations/machines, in a "mirror" fashion. Nonetheless, most of them still allow storing and reverting to old revisions of modified or deleted files.

See also [Wikipedia:Comparison of file synchronization software](Wikipedia:Comparison_of_file_synchronization_software "wikilink").

**Legend:**

-   **Name**: the application name, linking to the official website.
-   **Installation**: a link to the main ArchWiki article, if existing, or directly to the package pages.
-   **Implementation**: the programming language, library, or utility that the application is based on.
-   **Delta transfer**: only the modified *parts* of files are transferred.
-   **Encrypted transfer**: data is encrypted by default when transferred over the network.
-   **FS metadata**: file system permissions and attributes are synchronized.
-   **Resumable**: the synchronization can be resumed without restarting it if interrupted.
-   **Handles renames**: moved/renamed files are detected and not stored or transferred twice; it typically means that a checksum is computed for files or chunks thereof.
-   **Version control**: the old version of files are backed up (**reverse incremental backup**).
-   **Conflict resolution**: the application handles file conflicts, either automatically or interactively, i.e. it does not silently discard conflicting files.
-   **Multidirectional**: *more* than 2 locations can be kept in sync together.
-   **FS monitoring**: the application listens to file system events to trigger the synchronization.
-   **CLI**: the application is command-line driven, i.e. it is scriptable.
-   **Other interfaces**: the application has the specified user interfaces, e.g. GUI, TUI, or web-based.
-   **Licence**: the licence of the server and client applications.
-   **Other platforms**: supported operating systems other than Linux.
-   **Active**: whether the project is currently maintained.
-   **Specificity**: brief notes about special features that notably set the application apart from the others.

| Name                                                                            | Installation                            | Implementation     | Delta transfer | Encrypted transfer                    | FS metadata | Resumable | Handles renames | Version control                             | Conflict resolution | Multidirectional | FS monitoring | CLI | Other interfaces | Licence              | Other platforms                                                         | Active | Specificity                                  |
|---------------------------------------------------------------------------------|-----------------------------------------|--------------------|----------------|---------------------------------------|-------------|-----------|-----------------|---------------------------------------------|---------------------|------------------|---------------|-----|------------------|----------------------|-------------------------------------------------------------------------|--------|----------------------------------------------|
| [Resilio Sync](https://www.resilio.com/individuals/) (formerly BitTorrent Sync) | [Resilio Sync](Resilio_Sync "wikilink") | Closed source      |                | , also LAN transfer encryption option | ?           |           | ?               | , previous versions moved to archive folder | ?                   |                  | ?             |     |                  | Proprietary freemium | OS X, Windows, Android, iOS, Windows Phone, Amazon Kindle Fire, FreeBSD |        | P2P sync                                     |
| [FreeFileSync](http://freefilesync.sourceforge.net/)                            |                                         | C++                | ?              |                                       | ?           | ?         |                 |                                             | ?                   |                  | ?             |     |                  | GPL                  | Windows, OS X                                                           |        |                                              |
| [git-annex](http://git-annex.branchable.com/)                                   |                                         | Haskell, git       |                |                                       | ?           | ?         | ?               |                                             | ?                   |                  | ?             |     |                  | GPLv3                | OS X, Android                                                           |        | Manage files with git                        |
| [Grsync](http://www.opbyte.it/grsync/)                                          |                                         | rsync front-end    |                |                                       | ?           | ?         | ?               | ?                                           | ?                   |                  | ?             |     |                  | GPLv2                |                                                                         | ?      |                                              |
| [gutbackup](https://github.com/gutenye/gutbackup)                               |                                         | rsync wrapper      |                |                                       | ?           | ?         | ?               | ?                                           | ?                   |                  | ?             |     |                  | MIT                  |                                                                         | ?      |                                              |
| [Jotasync](http://jotasync.trixon.se/)                                          |                                         | Java gui for rsync |                |                                       | ?           | ?         | ?               | ?                                           | ?                   |                  | ?             |     |                  | Apache v2            | OS X, Windows                                                           |        | Integrated scheduler.                        |
| [luckyBackup](http://luckybackup.sourceforge.net/index.html)                    |                                         | C++                |                |                                       | ?           | ?         | ?               |                                             | ?                   |                  | ?             |     |                  | GPLv3                |                                                                         |        |                                              |
| [osync.sh](http://www.netpower.fr/osync)                                        |                                         | Shell              |                |                                       | ?           |           | ?               |                                             | ?                   |                  |               |     |                  | BSD                  |                                                                         |        |                                              |
| [rdiff-backup](http://www.nongnu.org/rdiff-backup/)                             |                                         | Python 2           |                |                                       |             | ?         |                 |                                             |                     |                  |               |     |                  | GPL                  | Win32                                                                   | ?      |                                              |
| [rsync](http://rsync.samba.org/)                                                | [rsync](rsync "wikilink")               | C                  |                |                                       |             |           |                 |                                             |                     |                  |               |     |                  | GPLv3                | Win32                                                                   |        | Standard install on all Linux distributions. |
| [SparkleShare](http://sparkleshare.org/)                                        |                                         | C\#                | ?              | ?                                     | ?           | ?         | ?               | ?                                           | ?                   | ?                | ?             |     |                  | GPLv3                | Windows, OS X                                                           | ?      |                                              |
| [Syncthing](https://syncthing.net/)                                             | [Syncthing](Syncthing "wikilink")       | Go                 |                |                                       |             | ?         | ?               | , previous versions moved to archive folder |                     |                  |               |     |                  | MPL v2               | Windows, OS X, Android, BSD, Solaris                                    |        | P2P sync                                     |
| [Synkron](http://synkron.sourceforge.net/)                                      |                                         | C++                | ?              | ?                                     | ?           | ?         | ?               | ?                                           | ?                   |                  | ?             |     |                  | GPLv2                | Windows, OS X                                                           |        |                                              |
| [taskd](https://tasktools.org/projects/taskd.html)                              | [Taskd](Taskd "wikilink")               | C++, python,       |                |                                       | ?           |           | ?               | ?                                           | ?                   |                  |               |     |                  | MIT                  | Android                                                                 |        |                                              |
| [Unison](http://www.cis.upenn.edu/~bcpierce/unison/)                            | [Unison](Unison "wikilink")             | OCaml              |                |                                       |             |           |                 |                                             |                     |                  |               |     |                  | GPL                  | Windows, OS X, FreeBSD, Android                                         |        |                                              |
| Name                                                                            | Installation                            | Implementation     | Delta transfer | Encrypted transfer                    | FS metadata | Resumable | Handles renames | Version control                             | Conflict resolution | Multidirectional | FS monitoring | CLI | Other interfaces | Licence              | Other platforms                                                         | Active | Specificity                                  |

Incremental backups
-------------------

Applications that can do incremental backups remember and take into account what data has been backed up during the last run (so-called "diffs") and eliminate the need to have duplicates of unchanged data. Restoring the data to a certain point in time would require locating the last full backup and all the incremental backups from then to the moment when it is supposed to be restored. This sort of backup is useful for those who do it very often.

See also [Dotfiles\#Version control](Dotfiles#Version_control "wikilink").

**Legend:**

-   **Name**: the application name, linking to the official website.
-   **Installation**: a link to the main ArchWiki article, if existing, or directly to the package pages.
-   **Implementation**: the programming language, library, or utility that the application is based on.
-   **Compressed storage**: compression is used for storage.
-   **Encrypted storage**: encryption is used for storage.
-   **Delta transfer**: only the modified *parts* of files are transferred.
-   **Encrypted transfer**: data is encrypted by default when transferred over a network.
-   **FS metadata**: file system permissions and attributes are backed up.
-   **Easy access**: the backup is stored plainly in the file system, or is mountable as such.
-   **Resumable**: the backup can be resumed without restarting it if interrupted.
-   **Handles renames**: moved/renamed files are detected and not stored or transferred twice; it typically means that a checksum is computed for files or chunks thereof.
-   **CLI**: the application is command-line driven, i.e. it is scriptable.
-   **Other interfaces**: the application has the specified user interfaces, e.g. GUI, TUI, or web-based.
-   **Licence**: the licence of the server and client applications.
-   **Other platforms**: supported operating systems other than Linux.
-   **Active**: whether the project is currently maintained.
-   **Specificity**: brief notes about special features that notably set the application apart from the others.

### Single machine

These applications are aimed at backing up data from the machine they are installed on, although the backup destination can be located on an external machine or storage media.

#### Chunk-based increments

If a file is modified, these applications store only its changed *parts* at the next snapshot. Compared to [\#File-based increments](#File-based_increments "wikilink") applications, these are more space-efficient, especially when large files receive small modifications; on the other hand, the archived snapshots have to be opened with the backup application that created them, since the files have to be reconstructed from the stored binary diffs.

| Name                                                                                       | Installation                      | Implementation       | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata                                                                                             | Easy access                                                            | Resumable                                                                                                                      | Handles renames | CLI | Other interfaces | Licence | Other platforms                | Active | Specificity                                                                                                                 |
|--------------------------------------------------------------------------------------------|-----------------------------------|----------------------|--------------------|-------------------|----------------|--------------------|---------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------|-----------------|-----|------------------|---------|--------------------------------|--------|-----------------------------------------------------------------------------------------------------------------------------|
| [Areca Backup](http://areca.sourceforge.net/)                                              |                                   | Java                 |                    |                   |                |                    |                                                                                                         |                                                                        |                                                                                                                                |                 |     |                  | GPLv2   | Windows                        |        |                                                                                                                             |
| [Attic](https://github.com/jborg/attic/)                                                   |                                   | Python               |                    |                   |                |                    |                                                                                                         |                                                                        |                                                                                                                                |                 |     |                  | BSD     |                                |        |                                                                                                                             |
| [BorgBackup](http://borgbackup.readthedocs.org/en/stable/)                                 |                                   | Python (Attic fork)  |                    |                   |                |                    | [1](http://borgbackup.readthedocs.org/en/stable/faq.html#which-file-types-attributes-etc-are-preserved) | [2](http://borgbackup.readthedocs.org/en/stable/usage.html#borg-mount) | [3](http://borgbackup.readthedocs.org/en/stable/faq.html#if-a-backup-stops-mid-way-does-the-already-backed-up-data-stay-there) |                 |     |                  | BSD     | -   BSD, OS X                  |        |                                                                                                                             |
| [btar](http://viric.name/cgi-bin/btar)                                                     |                                   | C                    |                    |                   |                |                    | ?                                                                                                       |                                                                        | ?                                                                                                                              | ?               |     |                  | GPLv3   |                                |        | Redundancy, indexed extraction, multicore compression, input and output serialisation, tolerance to partial archive errors. |
| [bup](https://bup.github.io/)                                                              |                                   | C, Python, git       |                    |                   |                |                    |                                                                                                         | [4](https://bup.github.io/man/bup-fuse.html)                           |                                                                                                                                |                 |     |                  | GPLv2   | Windows, OS X, NetBSD, Solaris |        | Same storage format as git                                                                                                  |
| [bups](https://github.com/emersion/bups)                                                   |                                   | bup frontend         |                    |                   |                |                    |                                                                                                         |                                                                        |                                                                                                                                |                 |     |                  | MIT     |                                |        |                                                                                                                             |
| [Déjà Dup](https://launchpad.net/deja-dup)                                                 | [Déjà Dup](Déjà_Dup "wikilink")   | duplicity front-end  |                    |                   |                |                    | ?                                                                                                       |                                                                        |                                                                                                                                |                 |     |                  | GPLv3   |                                |        | Integrated into [GNOME Files](GNOME_Files "wikilink").                                                                      |
| [Duplicati](http://www.duplicati.com/)                                                     |                                   | C\#                  |                    |                   |                |                    |                                                                                                         |                                                                        |                                                                                                                                |                 |     |                  | LGPL    | Windows                        |        |                                                                                                                             |
| [Duplicity](http://www.nongnu.org/duplicity/)                                              | [Duplicity](Duplicity "wikilink") | librsync             |                    |                   |                |                    | ?                                                                                                       |                                                                        |                                                                                                                                |                 |     |                  | GPL     |                                |        |                                                                                                                             |
| [Duply](http://www.duply.net/)                                                             | [Duply](Duply "wikilink")         | duplicity front-end  |                    |                   |                |                    | ?                                                                                                       |                                                                        |                                                                                                                                |                 |     |                  | GPLv2   |                                |        |                                                                                                                             |
| [Kup Backup System](http://kde-apps.org/content/show.php/Kup+Backup+System?content=147465) |                                   | rsync, bup front-end |                    |                   |                |                    |                                                                                                         |                                                                        |                                                                                                                                |                 |     |                  | GPLv2   |                                |        |                                                                                                                             |
| [obnam](http://liw.fi/obnam/)                                                              |                                   | Python               |                    |                   |                |                    | ?                                                                                                       |                                                                        |                                                                                                                                | ?               |     |                  | GPLv3   |                                |        |                                                                                                                             |
| [ZBackup](http://zbackup.org/)                                                             |                                   | C++                  |                    |                   |                |                    | ?                                                                                                       |                                                                        |                                                                                                                                |                 |     |                  | GPLv2   |                                |        | Repository consists of immutable files.                                                                                     |
| Name                                                                                       | Installation                      | Implementation       | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata                                                                                             | Easy access                                                            | Resumable                                                                                                                      | Handles renames | CLI | Other interfaces | Licence | Other platforms                | Active | Specificity                                                                                                                 |

#### File-based increments

If a file is modified, these applications store its new version entirely at the next snapshot. Compared to [\#Chunk-based increments](#Chunk-based_increments "wikilink") applications, these are less space-efficient, especially when large files receive small modifications; on the other hand, often the archived snapshots can be opened without the need to have the backup application installed.

**Specific legend:**

-   **Hard links**: whether unmodified files are stored as hard links to previous versions.

| Name                                                           | Installation                            | Implementation      | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata | Easy access | Resumable | Handles renames | Hard links | CLI | Other interfaces | Licence | Other platforms                                        | Active | Specificity                                                       |
|----------------------------------------------------------------|-----------------------------------------|---------------------|--------------------|-------------------|----------------|--------------------|-------------|-------------|-----------|-----------------|------------|-----|------------------|---------|--------------------------------------------------------|--------|-------------------------------------------------------------------|
| [Back In Time](https://github.com/bit-team/backintime)         | [Back In Time](Back_In_Time "wikilink") | Python, rsync, diff |                    |                   |                |                    |             |             |           |                 |            |     |                  | GPLv2   |                                                        |        |                                                                   |
| [DAR](http://dar.linux.free.fr/) (Disk ARchive)                |                                         | C++                 |                    |                   | ?              |                    | ?           | ?           | ?         | ?               |            |     |                  | GPL     | Windows, Solaris, FreeBSD, NetBSD, MacOS X             |        | Automatic backup using [cron](cron "wikilink") is possible with . |
| [DarGUI](http://dargui.sourceforge.net/)                       |                                         | DAR front-end       |                    |                   | ?              |                    | ?           | ?           | ?         | ?               |            |     |                  | GPL     | Windows                                                | ?      |                                                                   |
| [hdup](http://miek.nl/projects/hdup2/)                         |                                         | C                   |                    |                   | ?              |                    | ?           |             |           |                 |            |     |                  | GPLv2   |                                                        |        | Multiple backup targets.                                          |
| [Link-Backup](http://www.scottlu.com/Content/Link-Backup.html) |                                         | Python              |                    |                   | ?              |                    | ?           | ?           |           |                 |            |     |                  | MIT     |                                                        |        | It copies itself to the server.                                   |
| [rdup](https://github.com/miekg/rdup)                          |                                         | C                   |                    |                   | ?              | ?                  | ?           |             | ?         |                 |            |     |                  | GPLv3   |                                                        |        | Set of command-line tools.                                        |
| [rsnapshot](http://www.rsnapshot.org/)                         | [rsnapshot](rsnapshot "wikilink")       | rsync               |                    |                   |                |                    | ?           | ?           | ?         | ?               |            |     |                  | GPLv2   | Win32                                                  |        |                                                                   |
| [sbackup](https://launchpad.net/sbackup)                       |                                         | Python              |                    |                   | ?              |                    | ?           |             |           |                 |            |     |                  | GPLv3   |                                                        |        |                                                                   |
| [TimeShift](https://launchpad.net/timeshift)                   |                                         | rsync               |                    |                   |                |                    | ?           | ?           | ?         | ?               |            |     |                  | GPLv3   | Designed for full-system backups to dedicated devices. |        |                                                                   |
| Name                                                           | Installation                            | Implementation      | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata | Easy access | Resumable | Handles renames | Hard links | CLI | Other interfaces | Licence | Other platforms                                        | Active | Specificity                                                       |

### Network oriented

These applications have been designed to centralize the backup of several machines connected to a network, through a server-client model. In general they are more complicated to deploy, compared to [\#Single machine](#Single_machine "wikilink") solutions.

**Specific legend:**

-   **Increment type**: the strategy used to reduce used space by deduplicating data (i.e., besides compression).
    -   **file-based**: if a file is modified, the entire new version is stored at each snapshot.
        -   **hard-links**: whether unmodified files are stored as hard links to previous versions.
    -   **chunk-based**: only the modified *parts* of files are stored at each snapshot.

| Name                                                                                                            | Installation                                                                          | Implementation    | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata | Easy access | Resumable | Handles renames | Increment type                                                                                                                                                                                                                            | CLI      | Other interfaces | Licence | Other platforms        | Active | Specificity                                                                                                                                             |
|-----------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------|-------------------|--------------------|-------------------|----------------|--------------------|-------------|-------------|-----------|-----------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------|------------------|---------|------------------------|--------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| [BackupPC](http://backuppc.sourceforge.net/index.html)                                                          | [BackupPC](BackupPC "wikilink")                                                       | Perl              |                    |                   |                |                    |             |             |           | ?               | file-based, hard links [5](http://backuppc.sourceforge.net/faq/BackupPC.html#Backup-basics)                                                                                                                                               |          |                  | GPLv2   | Any (no client needed) |        | Identical files across backups of the same or different clients are stored only once.                                                                   |
| [Bacula](http://www.bacula.org)                                                                                 | [bacula-\*](https://aur.archlinux.org/packages/?K=bacula-) in [AUR](AUR "wikilink")   | C++               |                    |                   | ?              |                    | ?           | ?           |           | ?               | file-based [6](http://burp.grke.org/why.html)                                                                                                                                                                                             |          |                  | AGPLv3  | Windows, OS X          |        |                                                                                                                                                         |
| [burp](http://burp.grke.org)                                                                                    |                                                                                       | librsync          |                    |                   |                |                    | ?           | ?           | ?         | ?               | chunk-based [7](http://burp.grke.org/why.html)                                                                                                                                                                                            |          |                  | AGPLv3  | Windows                |        |                                                                                                                                                         |
| [SafeKeep](http://safekeep.sourceforge.net/)                                                                    |                                                                                       | rdiff-backup      |                    |                   | ?              |                    | ?           | ?           | ?         | ?               | chunk-based [8](http://safekeep.sourceforge.net/safekeep.html)                                                                                                                                                                            |          |                  | GPL     |                        |        | Integrates with [LVM](LVM "wikilink") and databases to create consistent backups. Bandwidth throttling.                                                 |
| [Snebu](http://www.snebu.com)                                                                                   |                                                                                       | C                 |                    |                   | ?              |                    | ?           | ?           | ?         | ?               | ?                                                                                                                                                                                                                                         |          |                  | GPLv3   |                        | ?      | Supports arbitrary retention schedules.                                                                                                                 |
| [Synbak](http://www.initzero.it/portal/soluzioni/software-open-source/synbak-universal-backup-system_2623.html) |                                                                                       | Multitool wrapper |                    |                   |                |                    |             | ?           | ?         | ?               | ?                                                                                                                                                                                                                                         |          |                  | GPLv3   |                        |        | Unifies several backup methods.                                                                                                                         |
| [UrBackup](https://www.urbackup.org)                                                                            | [urbackup\*](https://aur.archlinux.org/packages/?K=urbackup) in [AUR](AUR "wikilink") | C++               |                    |                   |                |                    |             |             |           |                 | file-based,hard-links and symlinks\[<http://blog.urbackup.org/156/symbolically-linking-directories-during-incremental-file-backups%5D/chunk-based> CoW-Snapshots[9](http://blog.urbackup.org/83/file-backup-storage-with-btrfs-snapshots) | (client) |                  | AGPLv3+ | Windows, macOS         |        | Identical files across backups of the same or different clients are stored only once. Integrates with LVM, dattobd and btrfs for file system snapshots. |
| Name                                                                                                            | Installation                                                                          | Implementation    | Compressed storage | Encrypted storage | Delta transfer | Encrypted transfer | FS metadata | Easy access | Resumable | Handles renames | Increment type                                                                                                                                                                                                                            | CLI      | Other interfaces | Licence | Other platforms        | Active | Specificity                                                                                                                                             |

Cloud storage
-------------

### Third-party services

See also [Wikipedia:Comparison of online backup services](Wikipedia:Comparison_of_online_backup_services "wikilink").

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-   ,  (free)

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

#### Multi-service clients

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

### Custom infrastructure

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

Version control systems
-----------------------

These are traditionally used for keeping track of software development; but if you want to have a simple way to manage your config files in one directory, it might be a good solution.

See also [Wikipedia:Comparison of revision control software](Wikipedia:Comparison_of_revision_control_software "wikilink").

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

<!-- -->

-

See also
--------

-   [Wikipedia:List of backup software](Wikipedia:List_of_backup_software "wikilink")
-   [Wikipedia:Comparison of backup software](Wikipedia:Comparison_of_backup_software "wikilink")
-   [Backing up Linux and other Unix(-like) systems](http://www.halfgaar.net/backing-up-unix)
-   [Mirroring an Entire Site using Rsync over SSH](http://www.askapache.com/security/mirror-using-rsync-ssh.html)
-   [Performance comparison of five remote incremental backup tools: Rsync, Rdiff-backup, Duplicity, Areca and Link-Backup](http://www.si-journal.org/index.php/JSI/article/view/205)
-   [rsync-snapshot.sh](http://blog.pointsoftware.ch/index.php/howto-local-and-remote-snapshot-backup-using-rsync-with-hard-links/) — Local and remote snapshot backup using rsync with hard links

<es:Rsync> <ja:Rsync> <zh-CN:Rsync> [rsync](https://rsync.samba.org/) is an open source utility that provides fast incremental file transfer.

Installation
------------

[Install](Install "wikilink") the package.

Usage
-----

For more examples, search the [Community Contributions](https://bbs.archlinux.org/viewforum.php?id=27) and [General Programming](https://bbs.archlinux.org/viewforum.php?id=33) forums.

### As a cp alternative

rsync can be used as an advanced alternative for the command, especially for copying larger files:

`$ rsync -P source destination`

The option is the same as , which keeps partially transferred files and shows a progress bar during transfer.

You may want to use the option to recurse into directories.

Files can be copied locally as with cp, but the motivating purpose of rsync is to copy files remotely, i.e. between two different hosts. Remote locations can be specified with a host-colon syntax:

`$ rsync source host:destination`

or

`$ rsync host:source destination`

Network file transfers use the SSH protocol by default.

Whether transferring files locally or remotely, rsync first creates an index of block checksums of each source file. This index is used to find any identical blocks of data which might exist in the destination. Such blocks are used in-place, rather than being copied from the source. This can greatly accelerate the synchronization of large files with small changes. For more information, see [official documentation](https://rsync.samba.org/documentation.html), [how rsync works](https://rsync.samba.org/how-rsync-works.html).

#### Trailing slash caveat

Arch by default uses GNU cp (part of [GNU coreutils](https://www.archlinux.org/packages/?name=coreutils)). However, rsync follows the convention of BSD cp, which gives special treatment to source directories with a trailing slash "/". Although

`$ rsync -r source destination`

creates a directory "destination/source" with the contents of "source", the command

`$ rsync -r source/ destination`

copies all of the files in "source/" directly into "destination", with no intervening subdirectory - just as if you had invoked it as

`$ rsync -r source/. destination`

This behavior is different from that of GNU cp, which treats "source" and "source/" identically (but not "source/."). Also, some shells automatically append the trailing slash when tab-completing directory names. Because of these factors, there can be a tendency among new or occasional rsync users to forget about rsync's different behavior, and inadvertently create a mess or even overwrite important files by leaving the trailing slash on the command line.

Thus it can be prudent to use a wrapper script to automatically remove trailing slashes before invoking rsync:

`#!/bin/zsh`
`new_args=();`
`for i in "$@"; do`
`    case $i in /) i=/;; */) i=${i%/};; esac`
`    new_args+=$i;`
`done`
`exec rsync "${(@)new_args}"`

This script can be put somewhere in the path, and aliased to rsync in the shell init file.

### As a backup utility

The rsync protocol can easily be used for backups, only transferring files that have changed since the last backup. This section describes a very simple scheduled backup script using rsync, typically used for copying to removable media. For a more thorough example and **additional options required to preserve some system files**, see [Full system backup with rsync](Full_system_backup_with_rsync "wikilink").

#### Automated backup

For the sake of this example, the script is created in the directory, and will be run on a daily basis if a cron [daemon](daemon "wikilink") is installed and properly configured. Configuring and using [cron](cron "wikilink") is outside the scope of this article.

First, create a script containing the appropriate command options:

 : indicates that files should be archived, meaning that most of their characteristics are preserved (but **not** ACLs, hard links or extended attributes such as capabilities)
 : means files deleted on the source are to be deleted on the backup as well

Here, should be changed to what needs to be backed-up (, for example) and is where the backup should be saved (, for instance).

Finally, the script must be executable:

`# chmod +x /etc/cron.daily/backup`

#### Automated backup with SSH

If backing-up to a remote host using [SSH](SSH "wikilink"), use this script instead:

 : tells rsync to use SSH
 : is the user on the host
 : groups all these options  (recursive, links, perms, times, group, owner, devices)

#### Automated backup with NetworkManager

This script starts a backup when you plugin your wire.

First, create a script containing the appropriate command options:

 : group all this options  recursive, links, perms, times, group, owner, devices
 : read the relative path of */folder/to/backup* from this file
 : limit I/O bandwidth; KBytes per second

Also, the script must have write permission for owner (root, of course) only (see [NetworkManager dispatcher](NetworkManager#Network_services_with_NetworkManager_dispatcher "wikilink") for details).

#### Automated backup with systemd and inotify

Instead of running time interval backups with time based schedules, such as those implemented in [cron](cron "wikilink"), it is possible to run a backup every time one of the files you are backing up changes. units use to monitor the filesystem, and can be used in conjunction with files to start any process (in this case your [rsync](rsync "wikilink") backup) based on a filesystem event.

First, create the file that will monitor the files you are backing up:

Then create a file that will be activated when it detects a change. By default a service file of the same name as the path unit (in this case ) will be activated, except with the extension instead of (in this case ).

Now all you have to do is [start](start "wikilink")/enable like a normal systemd service and it will start monitoring file changes and automatically starting .

#### Differential backup on a week

This is a useful option of rsync, creating a full backup and a differential backup for each day of a week.

First, create a script containing the appropriate command options:

 : implies  update destination files in-place

#### Snapshot backup

The same idea can be used to maintain a tree of snapshots of your files. In other words, a directory with date-ordered copies of the files. The copies are made using hardlinks, which means that only files that did change will occupy space. Generally speaking, this is the idea behind Apple's TimeMachine.

This basic script is easy to implement and creates quick incremental snapshots using the option to hardlink unchanged files:

There must be a symlink to a full backup already in existence as a target for . If the most recent snapshot is deleted, the symlink will need to be recreated to point to the most recent snapshot. If does not find a working symlink, rsync will proceed to copy all source files instead of only the changes.

A more sophisticated version checks to see if a certain number of changes have been made before making the backup and utilizes to hardlink unchanged files:

To make things really, really simple this script can be run from a [systemd/Timers](systemd/Timers "wikilink") unit.

### rsync daemon

*rsync* can be run as daemon on a server listening on port .

Edit the template , configure a share and [start](start "wikilink") the .

Usage from client, e.g. list server content:

`$ rsync `[`rsync://`](rsync://)*`server/share`*

transfer file from client to server:

`$ rsync `*`local-file`*` `[`rsync://`](rsync://)*`server/share/`*

Consider iptables to open port and user authentication.



#
```
# pacman -S --needed base-devel
:: There are 25 members in group base-devel:
:: Repository core
   1) autoconf  2) automake  3) binutils  4) bison  5) fakeroot  6) file  7) findutils  8) flex  9) gawk  10) gcc  11) gettext  12) grep
   13) groff  14) gzip  15) libtool  16) m4  17) make  18) pacman  19) patch  20) pkg-config  21) sed  22) sudo  23) texinfo  24) util-linux
   25) which

Enter a selection (default=all):
```


    pacman -U https://archive.archlinux.org/packages/ ... packagename.pkg.tar.xz

## Kernel

## Kernel building using asp
ASPROOT=. makepkg -s
cd linux/
cd repos/core-x86_64/
makepkg -s

## Kernel making

- https://wiki.archlinux.org/index.php/Kernels/Traditional_compilation


## Mirror

```sh
curl "https://archlinux.org/mirrorlist/?country=CN&protocol=https&ip_version=4"

##
## Arch Linux repository mirrorlist
## Generated on 2022-07-14
##

## China
#Server = https://mirrors.aliyun.com/archlinux/$repo/os/$arch
#Server = https://mirrors.bfsu.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.cqu.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.dgut.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.hit.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.neusoft.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.nju.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.njupt.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirror.redrock.team/archlinux/$repo/os/$arch
#Server = https://mirrors.shanghaitech.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.sjtug.sjtu.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.ustc.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.wsyu.edu.cn/archlinux/$repo/os/$arch
#Server = https://mirrors.xjtu.edu.cn/archlinux/$repo/os/$arch
```
