---
date: 2019-04-25
title: camcache
---

System almost crashed, with lots of messages output.

Then unplug and plug USB flash disks, USB cannot work:

```
[11812.865032] Write-error on swap-device (254:0:892408)
[11812.865099] compcache: Error allocating memory for compressed page: 111552, size=1867
[11812.865104] Write-error on swap-device (254:0:892416)
[11812.865165] compcache: Error allocating memory for compressed page: 111553, size=1481
[11812.865169] Write-error on swap-device (254:0:892424)
[11812.865247] compcache: Error allocating memory for compressed page: 109050, size=2197
[11812.865251] Write-error on swap-device (254:0:872400)
[11862.152794] __ratelimit: 23645 callbacks suppressed

[ 5736.237948] Write-error on swap-device (254:0:721112)
[ 5757.736695] usb 1-8: USB disconnect, address 4
[ 5760.176356] usb 1-7: new high speed USB device using ehci_hcd and address 5
[ 5760.315092] usb 1-7: configuration #1 chosen from 1 choice
[ 5760.375058] __ratelimit: 23479 callbacks suppressed
[ 5760.375070] allocation failed: out of vmalloc space - use vmalloc= to increase size.

...
[ 3628.464618] Write-error on swap-device (254:0:384008)
[ 3628.464714] compcache: Error allocating memory for compressed page: 48002, size=2407
[ 3628.464718] Write-error on swap-device (254:0:384016)
[ 3896.572024] usb 5-8: new high speed USB device using ehci_hcd and address 4
[ 3896.713287] usb 5-8: configuration #1 chosen from 1 choice
[ 3897.072735] __ratelimit: 9820 callbacks suppressed
[ 3897.072745] allocation failed: out of vmalloc space - use vmalloc= to increase size.
```

lots of messages:

```
-rw-r----- 1 syslog adm 123415460 2009-02-25 09:08 /var/log/kern.log.0
```

```
$ cat /proc/swaps
Filename Type Size Used Priority
/dev/ramzswap0 partition 515456 356876 100
```

workaround:

```
# swapoff /dev/ramzwap0
```

Also put this line into /etc/init.d/rc.local .

