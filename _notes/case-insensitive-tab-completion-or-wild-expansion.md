---
date: 2017-02-18
title: case insensitive tab-completion or wild expansion
---

To let wildcard expansion case insensitive, enable in bashrc

```shell
shopt -s nocaseglob
```

To let tab-completion case insensitive, bind the completion-ignore-case option

```shell
bind `echo set completion-ignore-case on`
```

This will be effective immediately.

Or add this in inputrc for readline;

```shell
$ echo 'set completion-ignore-case On' >> ~/.inputrc
```

Include the system inputrc file:

```shell
include /etc/inputrc
```

To show all binds:

```shell
bind -p
```

To let bash recognizes spelling mistakes, add this in ~/.bashrc:

```shell
shopt -s cdspell
```

For tcsh / zsh users:

```shell
set complete enhance
```

Reference:
- [http://www.caliban.org/bash/index.shtml#completion](http://www.caliban.org/bash/index.shtml#completion)
- [https://wiki.ubuntu.com/Spec/EnhancedBash](https://wiki.ubuntu.com/Spec/EnhancedBash)

