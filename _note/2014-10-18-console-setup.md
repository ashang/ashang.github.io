Package: console-setup
Status: install ok installed
Priority: important
Section: utils
Installed-Size: 421
Maintainer: Debian Install System Team <debian-boot@lists.debian.org>
Architecture: all
Multi-Arch: foreign
Version: 1.193~deb10u1
Depends: console-setup-linux | console-setup-freebsd | hurd, xkb-data (>= 0.9), keyboard-configuration (= 1.193~deb10u1)
Pre-Depends: debconf (>= 1.5.34)
Suggests: lsb-base (>= 3.0-6), locales
Breaks: lsb (<< 2.0-6), lsb-base (<< 3.0-6), lsb-core (<< 2.0-6)
Conflicts: console-setup-mini
Description: console font and keymap setup program
 This package provides the console with the same keyboard
 configuration scheme as the X Window System. As a result, there is no
 need to duplicate or change the keyboard files just to make simple
 customizations such as the use of dead keys, the key functioning as
 AltGr or Compose key, the key(s) to switch between Latin and
 non-Latin mode, etc.
 .
 The package also installs console fonts supporting many of the
 world's languages.  It provides an unified set of font faces - the
 classic VGA, the simplistic Fixed, and the cleaned Terminus,
 TerminusBold and TerminusBoldVGA.
