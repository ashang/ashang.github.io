---
date: 2017-04-01
title: backquote sign as single quote
tags:
- acute
- apostrophe
- backquote
- diacritic
- quote
- typo
---

<blockquote>
dpkg: version 'uname -r' has bad syntax: version string has
embedded spaces
update-initramfs: Generating /boot/initrd.img-uname
grep: /boot/config-uname: No such file or directory
WARNING: missing /lib/modules/uname
Device driver support needs thus be built-in linux image!
FATAL: modules must be specified using absolute paths.
"uname" is a relative path
FATAL: Could not load /lib/modules/uname/modules.dep: No such file
or directory
</blockquote>

It was a typo:

backquote (grave in diacritic) taken for apostrophe (single quote, or acute in diacritic)

`uname -r` should be 'uname -r'

See also:
- http://en.wikipedia.org/wiki/Apostrophe
- http://en.wikipedia.org/wiki/Diacritic
- http://en.wikipedia.org/wiki/Enhanced_keyboard
