---
title:  "$ time"
layout: post
---

About time command in shell.

```
$ bash -c "type time"
time is a shell keyword

$ zsh -c "type time"
time is a reserved word
```

# time in bash

```
$ time du -hs
7.7M	.

real	0m0.015s
user	0m0.008s
sys	0m0.007s
```

# time in zsh

```
$ time du -hs
7.7M	.
du -hs  0.00s user 0.01s system 93% cpu 0.006 total
...

$ time ./configure  10.17s user 3.35s system 96% cpu 13.949 total
...

$ time make  118.78s user 14.75s system 98% cpu 2:15.41 total
```

