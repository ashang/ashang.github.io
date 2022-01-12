---
date: 2017-06-30
title: Write failed is SSH Timeout
---

```
$ sudo hdparm -W 0 /dev/sda

/dev/sda:
 setting drive write-caching to 0 (off)
 write-caching =  0 (off)

$ sudo hdparm -I /dev/sda | grep 'Write cache'
                Write cache


$ sudo hdparm -W 1 /dev/sda

/dev/sda:
 setting drive write-caching to 1 (on)
 write-caching =  1 (on)

$ sudo hdparm -I /dev/sda | grep 'Write cache'
           *    Write cache
```
