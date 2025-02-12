Package: irqbalance
Status: install ok installed
Priority: optional
Section: utils
Installed-Size: 147
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Architecture: amd64
Version: 1.8.0-1
Depends: libc6 (>= 2.34), libcap-ng0 (>= 0.7.9), libglib2.0-0 (>= 2.35.8), libncursesw6 (>= 6), libnuma1 (>= 2.0.11), libsystemd0, libtinfo6 (>= 6)
Pre-Depends: init-system-helpers (>= 1.54~)
Conffiles:
 /etc/default/irqbalance 36e64b919c5778f81128d01a0cf29014
 /etc/init.d/irqbalance fcb4a4d3f2770082bcbf0f3dc899b70c
Description: Daemon to balance interrupts for SMP systems
 Daemon to balance interrupts across multiple CPUs, which can lead to better
 performance and IO balance on SMP systems. This package is especially useful
 on systems with multi-core processors, as interrupts will typically only be
 serviced by the first core.
 .
 Note: irqbalance is not useful if you don't have more than one CPU core.
Original-Maintainer: Paride Legovini <paride@debian.org>
Homepage: https://github.com/Irqbalance/irqbalance
