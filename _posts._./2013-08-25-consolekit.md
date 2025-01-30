Package: consolekit
Status: install ok installed
Priority: optional
Section: admin
Installed-Size: 462
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Architecture: amd64
Version: 0.4.5-3.1ubuntu2
Depends: libc6 (>= 2.4), libck-connector0 (= 0.4.5-3.1ubuntu2), libdbus-1-3 (>= 1.0.2), libdbus-glib-1-2 (>= 0.88), libglib2.0-0 (>= 2.31.8), libpolkit-gobject-1-0 (>= 0.94), libx11-6, zlib1g (>= 1:1.1.4), dbus (>= 1.1.2)
Recommends: libpam-ck-connector
Breaks: udev (<< 147)
Conffiles:
 /etc/ConsoleKit/seats.d/00-primary.seat eb3f3c54b501dbdaf38dbc38a4ee91fe
 /etc/X11/Xsession.d/90consolekit 628cccb5bdaaf3388da6b09c02eb07c8
 /etc/logrotate.d/consolekit 94c8a5d4828b67bcabe2e9ef0d301921
 /etc/dbus-1/system.d/ConsoleKit.conf 9a2dbb48a49638bf1cb1b5ff90755a29
Description: framework for defining and tracking users, sessions and seats
 ConsoleKit is a system daemon for tracking what users are logged
 into the system and how they interact with the computer (e.g.
 which keyboard and mouse they use).
 .
 It provides asynchronous notification via the system message bus.
 .
 This package provides the system daemon and tools to interact with it.
Homepage: http://www.freedesktop.org/wiki/Software/ConsoleKit
Original-Maintainer: Utopia Maintenance Team <pkg-utopia-maintainers@lists.alioth.debian.org>
