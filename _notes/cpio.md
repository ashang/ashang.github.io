---
title: cpio
date: 2019-04-10
---

```
$ find . -depth -print | cpio -H newc -o > ../io.cpio
 83 blocks

$ file ../io.cpio
io.cpio: ASCII cpio archive (SVR4 with no CRC )
```
