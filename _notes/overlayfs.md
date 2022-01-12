---
title: OverlayFS
date: 2017-07-02
---

OverlayFS is a modern union filesystem that is similar to AUFS. In comparison
to AUFS, OverlayFS:

- has a simpler design
- has been in the mainline Linux kernel since version 3.18 is potentially faster
- As a result, OverlayFS is rapidly gaining popularity in the Docker community and is seen by many as a natural successor to AUFS.


Since it was merged into the mainline kernel, the OverlayFS kernel module was
renamed from "overlayfs" to "overlay".


## In container

Show layers.

```
# mount -t overlay
```
