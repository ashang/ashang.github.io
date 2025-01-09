---
date: 2017-06-30
title: hdparm
---

```
# hdparm -W 0 /dev/sda

/dev/sda:
 setting drive write-caching to 0 (off)
 write-caching =  0 (off)

# hdparm -I /dev/sda | grep 'Write cache'
                Write cache


# hdparm -W 1 /dev/sda

/dev/sda:
 setting drive write-caching to 1 (on)
 write-caching =  1 (on)

# hdparm -I /dev/sda | grep 'Write cache'
           *    Write cache
```
