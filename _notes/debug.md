# debug tools

- Trace
  - strace for system call and signal
  - ltrace for library call
- GNU Debugger
- printk
- kdb / kgdb
- User-Mode Linux
- qemu

# route -nv
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
0.0.0.0         192.168.1.1     0.0.0.0         UG    1024   0        0 eth0
169.254.0.0     0.0.0.0         255.255.0.0     U     1000   0        0 eth0
192.168.1.0     0.0.0.0         255.255.255.0   U     0      0        0 eth0

# dhclient -v
Internet Systems Consortium DHCP Client 4.3.1
Copyright 2004-2014 Internet Systems Consortium.
All rights reserved.
For info, please visit https://www.isc.org/software/dhcp/

Listening on LPF/eth0/c8:bc:c8:8d:df:5a
Sending on   LPF/eth0/c8:bc:c8:8d:df:5a
Sending on   Socket/fallback
DHCPDISCOVER on eth0 to 255.255.255.255 port 67 interval 3 (xid=0x4833fb82)
DHCPREQUEST of 192.168.1.103 on eth0 to 255.255.255.255 port 67 (xid=0x4833fb82)
DHCPOFFER of 192.168.1.103 from 192.168.1.1
DHCPACK of 192.168.1.103 from 192.168.1.1
RTNETLINK answers: File exists
bound to 192.168.1.103 -- renewal in 3230 seconds.

# lshw -numeric -class network
  *-network
       description: Wireless interface
       product: BCM4322 802.11a/b/g/n Wireless LAN Controller [14E4:432B]
       vendor: Broadcom Corporation [14E4]
       physical id: 0
       bus info: pci@0000:02:00.0
       logical name: wlan0
       version: 01
       serial: 78:ca:39:b9:ee:8c
       width: 64 bits
       clock: 33MHz
       capabilities: pm msi pciexpress bus_master cap_list ethernet physical wireless
       configuration: broadcast=yes driver=wl0 driverversion=6.30.223.248 (r487574) latency=0 multicast=yes wireless=IEEE 802.11abg
       resources: irq:21 memory:d3200000-d3203fff
  *-network
       description: Ethernet interface
       product: NetXtreme BCM5764M Gigabit Ethernet PCIe [14E4:1684]
       vendor: Broadcom Corporation [14E4]
       physical id: 0
       bus info: pci@0000:03:00.0
       logical name: eth0
       version: 10
       serial: c8:bc:c8:8d:df:5a
       size: 100Mbit/s
       capacity: 1Gbit/s
       width: 64 bits
       clock: 33MHz
       capabilities: pm vpd msi pciexpress bus_master cap_list ethernet physical tp 10bt 10bt-fd 100bt 100bt-fd 1000bt 1000bt-fd autonegotiation
       configuration: autonegotiation=on broadcast=yes driver=tg3 driverversion=3.137 duplex=full firmware=5764m-v3.38 ip=192.168.1.103 latency=0 link=yes multicast=yes port=twisted pair speed=100Mbit/s
       resources: irq:26 memory:d3100000-d310ffff

# lshw -C display
  *-display
       description: VGA compatible controller
       product: MCP89 [GeForce 320M]
       vendor: NVIDIA Corporation
       physical id: 0
       bus info: pci@0000:04:00.0
       version: a2
       width: 64 bits
       clock: 33MHz
       capabilities: pm msi vga_controller bus_master cap_list rom
       configuration: driver=nvidia latency=0
       resources: irq:16 memory:d2000000-d2ffffff memory:c0000000-cfffffff memory:d0000000-d1ffffff ioport:1000(size=128) memory:d3000000-d301ffff

# web

netstat -plant|grep 80

# lsof -i:80

nginx   16482       root    6u  IPv4 4037738      0t0  TCP *:http (LISTEN)
nginx   16512 gitlab-www    6u  IPv4 4037738      0t0  TCP *:http (LISTEN)
nginx   16513 gitlab-www    6u  IPv4 4037738      0t0  TCP *:http (LISTEN)
nginx   16514 gitlab-www    6u  IPv4 4037738      0t0  TCP *:http (LISTEN)
nginx   16515 gitlab-www    6u  IPv4 4037738      0t0  TCP *:http (LISTEN)

# cc1

```shell
gcc -o test.o test-10356.c -### 2>&1 | grep cc1
```
to get the cc1 command line.

Then use gdb --args <cc1 cmdline> to debug the compiler.  Getting a backtrace before the abort would be nice.

## version

shell> cat /proc/version
... (gcc version 4.4.7 20120313 (Red Hat 4.4.7-4) (GCC) ) ...

shell> /lib64/libc.so.6
GNU C Library stable release version 2.12, by Roland McGrath et al.
Copyright (C) 2010 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.
Compiled by GNU CC version 4.4.7 20120313 (Red Hat 4.4.7-17).
Compiled on a Linux 2.6.32 system on 2016-05-10.
Available extensions:
	The C stubs add-on version 2.1.2.
	crypt add-on version 2.1 by Michael Glad and others
	GNU Libidn by Simon Josefsson
	Native POSIX Threads Library by Ulrich Drepper et al
	BIND-8.2.3-T5B
	RT using linux kernel aio
libc ABIs: UNIQUE IFUNC
For bug reporting instructions, please see:
<http://www.gnu.org/software/libc/bugs.html>.
再看看如何判断 PHP 之类的软件是用什么版本的 GCC 编译的？

shell> objdump -s --section .comment /usr/local/bin/php

/usr/local/bin/php:     file format elf64-x86-64

Contents of section .comment:
 0000 4743433a 2028474e 55292034 2e342e37  GCC: (GNU) 4.4.7
 0010 20323031 32303331 33202852 65642048   20120313 (Red H
 0020 61742034 2e342e37 2d313129 00474343  at 4.4.7-11).GCC
 0030 3a202847 4e552920 342e342e 37203230  : (GNU) 4.4.7 20
 0040 31323033 31332028 52656420 48617420  120313 (Red Hat
 0050 342e342e 372d3429 00                 4.4.7-4).
或者

shell> readelf -p .comment /usr/local/bin/php

String dump of section '.comment':
  [     0]  GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-11)
  [    2d]  GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-4)

## debug from dbg files

https://wiki.ubuntu.com/AptElfDebugSymbols

http://wiki.debian.org/DebugPackage

Briefly, you must first create the new package in debian/control by adding:

Package: foo-dbg
Architecture: any
Section: debug
Priority: extra
Depends:
    foo (= ${binary:Version}),
    ${misc:Depends}
Description: debugging symbols for foo
 foo is a library that lets you do stuff.
 .
 This package contains the debugging symbols for foo.
Then in debian/rules, use dh_strip to strip debugging symbols from binaries, but retain them for use in the debug packages.

override_dh_strip:
        dh_strip --dbg-package=foo-dbg

For ubuntu build chroots, installing pkg-create-dbgsym will cause packages built in that chroot to also output -dbgsym packages when stripped. This works for pbuilder, sbuild, cowbuilder, etc. and is how the "automatic" -dbgsym packages are generated in Soyuz.

In Debian, to get debugging information for glibc, you need to install the libc6-dbg package.

glibc-dbg is unstripped.

At the place GDB looks for debugging symbols by default (/usr/lib/debug/lib/), libc6-dbg stores only the frame unwind information used for backtracing.

If you want to step into glibc while debugging, you need to add LD_LIBRARY_PATH=/usr/lib/debug to debugged program's environment (set env VAR value from the GDB command line).

If that still does not work, try `LD_PRELOAD=/usr/lib/debug/.build-id/`.

Run valgrind

```
==17187== Memcheck, a memory error detector.
==17187== Copyright (C) 2002-2007, and GNU GPL'd, by Julian Seward et al.
==17187== Using LibVEX rev 1804, a library for dynamic binary translation.
==17187== Copyright (C) 2004-2007, and GNU GPL'd, by OpenWorks LLP.
==17187== Using valgrind-3.3.0-Debian, a dynamic binary instrumentation framework.
==17187== Copyright (C) 2000-2007, and GNU GPL'd, by Julian Seward et al.
==17187== For more details, rerun with: -v
==17187==

valgrind:  Fatal error at startup: a function redirection
valgrind:  which is mandatory for this platform-tool combination
valgrind:  cannot be set up.  Details of the redirection are:
valgrind:
valgrind:  A must-be-redirected function
valgrind:  whose name matches the pattern:      strlen
valgrind:  in an object with soname matching:   ld.so.1
valgrind:  was not found whilst processing
valgrind:  symbols from the object with soname: ld.so.1
valgrind:
valgrind:  Possible fix: install glibc's debuginfo package on this machine.
valgrind:
valgrind:  Cannot continue -- exiting now.  Sorry.
```

Valgrind wants to redirect strlen (and doubtlessly dozens of other functions that it failed before it could reach), because its ppc32 and pcc64 versions of those functions tend to yield horrifying false positives, rendering it useless on those platforms.

- Adding /usr/lib/debug to $LD_LIBRARY_PATH does not make any sense, as this directory contains only the debug-symbol-portions of the libraries. This directory is automatically searched by programs like valgrind / gdb for debug symbols matching the installed libraries if these are stripped.
- `SPLITDEBUG` on Gentoo splitting off the debug symbols from glibc and finally stripping it.
This means the installed libraries are stripped, but the debug symbols are extracted to /usr/lib/debug before, and only loaded if actually needed! If you use gentoo, you might also want the feature "installsources" to do sensible debugging and "compressdebug" to save some space.

## Memory

Memory debuggers work by monitoring memory access, allocations, and deallocation of memory.

Many memory debuggers require applications to be recompiled with special dynamic memory allocation libraries, whose APIs are mostly compatible with conventional dynamic memory allocation libraries, or else use dynamic linking.

Electric Fence is such a debugger which debugs memory allocation with malloc.

Some memory debuggers (e.g. Valgrind) work by running the executable in a virtual machine-like environment, monitoring memory access, allocation and deallocation so that no recompilation with special memory allocation libraries is required.

## Linux kernel debugging

- kdb – assembly-level debugger
- kgdb – kernel gdb extension
  - via serial line or Ethernet
  - host to run gdb
    - stty ispeed 115200 ospeed 115200 < /dev/ttyS0
    - gdb vmlinux
    - (gdb) remote target /dev/ttys0
  - target
    - append="gdb gdbttyS=0 gdbbaud=115200"
- Oops – messages duing exception
- printk – kernel print
- User-Mode Linux

## lldb

LLDB is support modern multi-threaded programs, handle debugging symbols in an efficient manner, use compiler based code knowledge and have plug-in support for functionality and extensions.

LLDB currently converts debug information into clang types so that it can leverage the clang compiler infrastructure.

LLDB also leverages the compiler to take care of all ABI details when making functions calls for expressions, when disassembling instructions and extracting instruction details, and much more.

The major benefits

- Up to date language support
- Multi-line expressions that can declare local variables and types
- Utilize the JIT for expressions when supported
- Evaluate expression Intermediate Representation (IR) when JIT can't be used

See <http://lldb.llvm.org/lldb-gdb.html>

## Reference

- <https://dev.launchpad.net/Debugging>
