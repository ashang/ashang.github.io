Package: debian-security-support
Status: install ok installed
Priority: optional
Section: admin
Installed-Size: 140
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Architecture: all
Version: 2019.02.01
Depends: debconf (>= 0.5) | debconf-2.0, adduser, gettext-base
Conffiles:
 /etc/dpkg/dpkg.cfg.d/debian-security-support 08577c44ee76afd1a5622392d32318ea
Description: Debian security support coverage checker
 For some Debian packages, it is not feasible to maintain full security
 support for all use cases through the full distribution release
 cycle.
 .
 This package provides a program to identify installed packages for
 which support has had to be limited or prematurely ended, and to
 alert the administrator.
 .
 New versions of this package with updated checklists will be provided
 via standard and/or extended security support.
Original-Maintainer: Christoph Biedl <debian.axhn@manchmal.in-ulm.de>
