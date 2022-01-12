---
date: 2017-06-30
title: Write failed is SSH Timeout
---

SSH session Timeout and break with this:
```
Write failed: Broken pipe?**
```

To make it better, try tune client side option ServerAliveInterval to a small value.

```
$ cat ~/.ssh/ssh_config
ServerAliveInterval 30
```
