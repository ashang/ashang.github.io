---
layout: post
title: xapt
tags: [xapt, apt, arm, armel, cross]
date: 2020-03-09
---

Update:
* Debian includes armel, directly working with apt is OK.

```text
deb [arch=armel] URL...
```

---

# xapt -a armel libwrap0-dev zlib1g-dev libssl-dev libgtk2.0-dev libedit-dev dh-exec libselinux1-dev libkrb5-dev libck-connector-dev


L/usr/arm-linux-gnueabi/lib/mit-krb5 -Wl,-z,relro -lgssapi_krb5 -lkrb5 -lk5crypto -lcom_err
/usr/lib/gcc/arm-linux-gnueabi/4.9/../../../../arm-linux-gnueabi/bin/ld: cannot find -lgssapi_krb5
/usr/lib/gcc/arm-linux-gnueabi/4.9/../../../../arm-linux-gnueabi/bin/ld: cannot find -lkrb5
/usr/lib/gcc/arm-linux-gnueabi/4.9/../../../../arm-linux-gnueabi/bin/ld: cannot find -lk5crypto
/usr/lib/gcc/arm-linux-gnueabi/4.9/../../../../arm-linux-gnueabi/bin/ld: cannot find -lcom_err


L/usr/powerpc-linux-gnu/lib/mit-krb5 -Wl,-z,relro -lgssapi_krb5 -lkrb5 -lk5crypto -lcom_err
/usr/lib/gcc/powerpc-linux-gnu/4.9/../../../../powerpc-linux-gnu/bin/ld: cannot find -lgssapi_krb5
/usr/lib/gcc/powerpc-linux-gnu/4.9/../../../../powerpc-linux-gnu/bin/ld: cannot find -lkrb5
/usr/lib/gcc/powerpc-linux-gnu/4.9/../../../../powerpc-linux-gnu/bin/ld: cannot find -lk5crypto
/usr/lib/gcc/powerpc-linux-gnu/4.9/../../../../powerpc-linux-gnu/bin/ld: cannot find -lcom_err

Then
xapt -a powerpc krb5-multidev

Then
/usr/lib/gcc/powerpc-linux-gnu/4.9/../../../../powerpc-linux-gnu/bin/ld: cannot find -lkrb5
/usr/lib/gcc/powerpc-linux-gnu/4.9/../../../../powerpc-linux-gnu/bin/ld: cannot find -lk5crypto

Then

apt install libk5crypto3 libkrb5support0 libkrb5-3 libkrb5-dev krb5-multidev

xapt -a armel libk5crypto3 libkrb5support0 libkrb5-3 libkrb5-dev krb5-multidev
xapt -a powerpc libk5crypto3 libkrb5support0 libkrb5-3 libkrb5-dev krb5-multidev

OK.



export CROSS_COMPILE=arm-linux-gnueabi-
export SYSROOT=/usr/arm-linux-gnueabi
export HOST=arm-linux-gnueabi
export CC=${CROSS_COMPILE}gcc
export LD=${CROSS_COMPILE}ld
./configure --host=${HOST} --prefix=/usr --libexecdir=/usr/lib/openssh --sysconfdir=/etc/ssh --with-pam --with-kerberos5=${SYSROOT}




Just open the .so-file with an texteditor and remove the absolute paths. This needs to be done for libpthread.so and libc.so

After this there will be another problem: Some libraries use another libraries. The linker does not find these libraries. So it is also necessary to use the -rpath-link option of the linker to overwrite the runtime link path during compile time. I had to give g++ these options:

Code: Select all

-Xlinker -rpath-link=/home/phate/rpi/chroot-raspbian-armhf/usr/lib/arm-linux-gnueabihf
-Xlinker -rpath-link=/home/phate/rpi/chroot-raspbian-armhf/lib/arm-linux-gnueabihf




Instead of removing the paths completely and then having to fiddle with rpath/rpath-link, you can just make these paths relative.

Code: Select all

/* GNU ld script
   Use the shared library, but some functions are only in
      the static library, so try that secondarily.  */
      OUTPUT_FORMAT(elf32-littlearm)
      GROUP ( ../../../lib/arm-linux-gnueabihf/libpthread.so.0 ../../../usr/lib/arm-linux-gnueabihf/libpthread_nonshared.a )

      When I did that, everything worked and I didn't need to change anything else. I'm on Xubuntu 14.04 and Raspbian 2015-05-05 release on the Pi.



## root@c8f5a503f634:# xapt install libmnl-dev
Warning: Multi-Arch support has been enabled.
apt-get  -o Apt::Get::Download-Only=true -y -o Apt::Architecture=armel -o Apt::Install-Recommends=false -o Dir::Etc=/var/lib/xapt/etc/xapt/ -o Dir::Etc::TrustedParts=/etc/apt/trusted.gpg.d -o Dir::Etc::Trusted=/etc/apt/trusted.gpg -o Dir::Etc::SourceList=/var/lib/xapt/etc/xapt/sources.list -o Dir::Etc::SourceParts=/var/lib/xapt/etc/xapt/sources.list.d/ -o Dir::St
ate=/var/lib/xapt/ -o Dir::State::Status=/var/lib/xapt//armel/dpkg/status -o Dir::Cache=/var/lib/xapt/ update



E: Unable to locate package install
root@c8f5a503f634:# xapt libmnl-dev
Warning: Multi-Arch support has been enabled.
apt-get  -o Apt::Get::Download-Only=true -y -o Apt::Architecture=armel -o Apt::Install-Recommends=false -o Dir::Etc=/var/lib/xapt/etc/xapt/ -o Dir::Etc::TrustedParts=/etc/apt/trusted.gpg.d -o Dir::Etc::Trusted=/etc/apt/trusted.gpg -o Dir::Etc::SourceList=/var/lib/xapt/etc/xapt/sources.list -o Dir::Etc::SourceParts=/var/lib/xapt/etc/xapt/sources.list.d/ -o Dir::State=/var/lib/xapt/ -o Dir::State::Status=/var/lib/xapt//armel/dpkg/status -o Dir::Cache=/var/lib/xapt/ update
Ign http://mirrors.ustc.edu.cn jessie InRelease
Get:1 http://mirrors.ustc.edu.cn jessie-updates InRelease [16.3 kB]
Ign http://apt.opennetlinux.org unstable InRelease
Get:2 http://mirrors.ustc.edu.cn jessie Release.gpg [1652 B]
Get:3 http://mirrors.ustc.edu.cn jessie Release [77.3 kB]
Ign http://apt.opennetlinux.org unstable Release.gpg
Get:4 http://apt.opennetlinux.org unstable Release [7726 B]
Get:5 http://mirrors.ustc.edu.cn jessie-updates/main armel Packages [20 B]
Get:6 http://mirrors.ustc.edu.cn jessie-updates/main Translation-en [14 B]
Get:7 http://mirrors.ustc.edu.cn jessie/main armel Packages [6676 kB]
Get:8 http://mirrors.ustc.edu.cn jessie/main Translation-en [4581 kB]
Get:9 http://apt.opennetlinux.org unstable/main armel Packages [846 B]
Ign http://apt.opennetlinux.org unstable/main Translation-en
Fetched 11.4 MB in 13s (861 kB/s)
Reading package lists... Done
apt-get  -o Apt::Get::Download-Only=true -y -o Apt::Architecture=armel -o Apt::Install-Recommends=false -o Dir::Etc=/var/lib/xapt/etc/xapt/ -o Dir::Etc::TrustedParts=/etc/apt/trusted.gpg.d -o Dir::Etc::Trusted=/etc/apt/trusted.gpg -o Dir::Etc::SourceList=/var/lib/xapt/etc/xapt/sources.list -o Dir::Etc::SourceParts=/var/lib/xapt/etc/xapt/sources.list.d/ -o Dir::State=/var/lib/xapt/ -o Dir::State::Status=/var/lib/xapt//armel/dpkg/status -o Dir::Cache=/var/lib/xapt/ install libmnl-dev
Reading package lists... Done
Building dependency tree... Done
The following extra packages will be installed:
  gcc-4.9-base libc6 libgcc1 libmnl0 multiarch-support
Suggested packages:
  glibc-doc debconf debconf-2.0 locales
The following NEW packages will be installed:
  gcc-4.9-base libc6 libgcc1 libmnl-dev libmnl0 multiarch-support
0 upgraded, 6 newly installed, 0 to remove and 0 not upgraded.
Need to get 4539 kB of archives.
After this operation, 9976 kB of additional disk space will be used.
Get:1 http://mirrors.ustc.edu.cn/debian/ jessie/main libc6 armel 2.19-18+deb8u10 [4133 kB]
Get:2 http://mirrors.ustc.edu.cn/debian/ jessie/main multiarch-support armel 2.19-18+deb8u10 [181 kB]
Get:3 http://mirrors.ustc.edu.cn/debian/ jessie/main gcc-4.9-base armel 4.9.2-10+deb8u1 [160 kB]
Get:4 http://mirrors.ustc.edu.cn/debian/ jessie/main libgcc1 armel 1:4.9.2-10+deb8u1 [41.5 kB]
Get:5 http://mirrors.ustc.edu.cn/debian/ jessie/main libmnl0 armel 1.0.3-5 [10.9 kB]
Get:6 http://mirrors.ustc.edu.cn/debian/ jessie/main libmnl-dev armel 1.0.3-5 [12.8 kB]
Fetched 4539 kB in 1s (2274 kB/s)
Download complete and in download only mode
dpkg-cross: Multi-Arch package detected; processing anyway as --convert-multiarch specified.
dpkg-cross: package gcc-4.9-base doesn't provide any useful files, but
processing it anyway as requested
Building gcc-4.9-base-armel-cross_4.9.2-10+deb8u1_all.deb
dpkg-deb: building package `gcc-4.9-base-armel-cross' in `./gcc-4.9-base-armel-cross_4.9.2-10+deb8u1_all.deb'.
dpkg-cross: Multi-Arch package detected; processing anyway as --convert-multiarch specified.
Building libgcc1-armel-cross_4.9.2-10+deb8u1_all.deb
dpkg-deb: building package `libgcc1-armel-cross' in `./libgcc1-armel-cross_4.9.2-10+deb8u1_all.deb'.
dpkg-cross: Multi-Arch package detected; processing anyway as --convert-multiarch specified.
Building libc6-armel-cross_2.19-18+deb8u10_all.deb
dpkg-deb: building package `libc6-armel-cross' in `./libc6-armel-cross_2.19-18+deb8u10_all.deb'.
Building libmnl-dev-armel-cross_1.0.3-5_all.deb
dpkg-deb: building package `libmnl-dev-armel-cross' in `./libmnl-dev-armel-cross_1.0.3-5_all.deb'.
dpkg-cross: Multi-Arch package detected; processing anyway as --convert-multiarch specified.
Building libmnl0-armel-cross_1.0.3-5_all.deb
dpkg-deb: building package `libmnl0-armel-cross' in `./libmnl0-armel-cross_1.0.3-5_all.deb'.
dpkg-cross: Multi-Arch package detected; processing anyway as --convert-multiarch specified.
dpkg-cross: package multiarch-support doesn't provide any useful files, but
processing it anyway as requested
Building multiarch-support-armel-cross_2.19-18+deb8u10_all.deb
dpkg-deb: building package `multiarch-support-armel-cross' in `./multiarch-support-armel-cross_2.19-18+deb8u10_all.deb'.
(Reading database ... 49329 files and directories currently installed.)
Preparing to unpack .../gcc-4.9-base-armel-cross_4.9.2-10+deb8u1_all.deb ...
Unpacking gcc-4.9-base-armel-cross (4.9.2-10+deb8u1) over (4.9.2-10+deb8u1) ...
Preparing to unpack .../libc6-armel-cross_2.19-18+deb8u10_all.deb ...
Unpacking libc6-armel-cross (2.19-18+deb8u10) over (2.19-18+deb8u10) ...
Preparing to unpack .../libgcc1-armel-cross_4.9.2-10+deb8u1_all.deb ...
Unpacking libgcc1-armel-cross (1:4.9.2-10+deb8u1) over (1:4.9.2-10+deb8u1) ...
Selecting previously unselected package libmnl-dev-armel-cross.
Preparing to unpack .../libmnl-dev-armel-cross_1.0.3-5_all.deb ...
Unpacking libmnl-dev-armel-cross (1.0.3-5) ...
Selecting previously unselected package libmnl0-armel-cross.
Preparing to unpack .../libmnl0-armel-cross_1.0.3-5_all.deb ...
Unpacking libmnl0-armel-cross (1.0.3-5) ...
Preparing to unpack .../multiarch-support-armel-cross_2.19-18+deb8u10_all.deb ...
Unpacking multiarch-support-armel-cross (2.19-18+deb8u10) over (2.19-18+deb8u10) ...
Setting up gcc-4.9-base-armel-cross (4.9.2-10+deb8u1) ...
Setting up multiarch-support-armel-cross (2.19-18+deb8u10) ...
Setting up libc6-armel-cross (2.19-18+deb8u10) ...
Setting up libgcc1-armel-cross (1:4.9.2-10+deb8u1) ...
Setting up libmnl0-armel-cross (1.0.3-5) ...
Setting up libmnl-dev-armel-cross (1.0.3-5) ...




