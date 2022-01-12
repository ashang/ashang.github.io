---
title: xapt
date: 2019-04-13
---

Source: emdebian-crush

Replaces: emdebian-crush (<= 2.2.3), pdebuild-cross (<= 2.2.5.1)

Depends: perl, apt, dpkg-cross, dpkg-dev, libconfig-inifiles-perl, libdpkg-perl, liblocale-gettext-perl

- /etc/xapt.d/debian.conf 089675a01c6176fccbb30e4d2870df92
- /etc/bash_completion.d/xapt f4d9895bcddbaab086052e27d02ed5d9

xapt is to retrieve, build and install libraries for cross-compiling.

 xapt wraps apt and calls dpkg-cross for the collected
 archives. Downloaded files are passed directly to dpkg-cross.
 .
 embuilddeps can be used to parse debian/control to install the
 native and cross dependencies, using apt and xapt respectively,
 for a particular unpacked source package.

- http://www.emdebian.org/crush/
