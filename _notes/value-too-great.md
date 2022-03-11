
---
date: 2022-02-06
title: Banlieue 13
---

```shell
$ for i in {01..10..2}; do echo $(( $i + 1 ));done
2
4
6
8
-bash: 09: value too great for base (error token is "09")
```

The root cause is that numbers starting with zeros are treated as octal.

The solution is to set as using base 10.

```shell
$ for i in {01..10..2}; do echo $(( 10#$i + 1 ));done
2
4
6
8
10
```

Or use expr.

```shell
$ for i in {01..10..2}; do echo $( expr $i + 1 );done
```

To output with leading 0, try to use printf format string.

```shell
$ for i in {01..10..2}; do printf %03d $( expr $i + 1 );echo;done
```

```shell
$ for i in {01..10..2}; do printf %03d $(( 10#$i + 1 ));echo;done
002
004
006
008
010
```
