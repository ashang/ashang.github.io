---
title: across
categories: security
date: 2018-11-09
---

```
$ sudo bash -c 'echo "deb http://httpredir.debian.org/debian bullseye-backports main contrib non-free" >  /etc/apt/sources.list.d/backports.list'
```

```
$ echo "deb http://httpredir.debian.org/debian bullseye-backports main contrib non-free" | sudo tee /etc/apt/sources.list.d/backports.list'
```
