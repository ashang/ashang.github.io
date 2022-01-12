---
date: 2018-07-16
title: zram and swap
---

```
$ cat /lib/systemd/system/systemd-zram-setup@.service
# SPDX-License-Identifier: MIT
# This file is part of the zram-generator project
# https://github.com/systemd/zram-generator

[Unit]
Description=Create swap on /dev/%i
Documentation=man:zram-generator(8) man:zram-generator.conf(5)
After=dev-%i.device
DefaultDependencies=false

[Service]
Type=oneshot
RemainAfterExit=yes
ExecStart=/usr/lib/systemd/system-generators/zram-generator --setup-device '%i'
ExecStop=/usr/lib/systemd/system-generators/zram-generator --reset-device '%i'
```

```
$ free
               total        used        free      shared  buff/cache   available
Mem:         7848988     3549856     2734076      598424     1565056     3415800
Swap:        7848956     2010368     5838588
```

no entry in /etc/fstab
