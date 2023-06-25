
```
$ locale-check
locale-check DEFAULT_LOCALE

Check that the various locale-related environment variables contain
values that can be set. Output shell that can be passed to eval to
set any invalid environment variables to DEFAULT_LOCALE
```

```
$ cat /etc/profile.d/01-locale-fix.sh
# Make sure the locale variables are set to valid values.
eval $(/usr/bin/locale-check C.UTF-8)

$ dpkg -S /etc/profile.d/01-locale-fix.sh
base-files: /etc/profile.d/01-locale-fix.sh

$ dpkg -s base-files
Package: base-files
Essential: yes
Status: install ok installed
Priority: required
Section: admin
Installed-Size: 387
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Architecture: amd64
Multi-Arch: foreign
Version: 10.1ubuntu2.8
Replaces: base, dpkg (<= 1.15.0), miscutils
Provides: base
Depends: libc6 (>= 2.3.4)
Pre-Depends: awk
Breaks: initscripts (<< 2.88dsf-13.3), sendfile (<< 2.1b.20080616-5.2~)
Conffiles:
 /etc/debian_version 71f3b31c52b52a91784e496ddf94b019
 /etc/default/motd-news c08a329a603b640095da5ffe4e73491c
 /etc/dpkg/origins/debian 731423fa8ba067262f8ef37882d1e742
 /etc/dpkg/origins/ubuntu ea35901c45553c3451f60476be94d2d8
 /etc/host.conf 89408008f2585c957c031716600d5a80
 /etc/issue 9c771e1fa41a5a833f5824b41bd3eb1f
 /etc/issue.net 39eb618332de8dab671b125032ddb788
 /etc/legal 0110925f6e068836ef2e09356e3651d9
 /etc/lsb-release 741234b05e5349212282f0b1477be224
 /etc/profile.d/01-locale-fix.sh 870346d97b16faac4a371b04ffe4cc2f
 /etc/update-motd.d/00-header 4a1e6eed7a59f200b4267085721750a3
 /etc/update-motd.d/10-help-text d95d18b11ac12cf6582d08a1643034f3
 /etc/update-motd.d/50-motd-news 0031f05946932b1e0a4f4ec86dda97e0
Description: Debian base system miscellaneous files
 This package contains the basic filesystem hierarchy of a Debian system, and
 several important miscellaneous files, such as /etc/debian_version,
 /etc/host.conf, /etc/issue, /etc/motd, /etc/profile, and others,
 and the text of several common licenses in use on Debian systems.
Original-Maintainer: Santiago Vila <sanvila@debian.org>
```
