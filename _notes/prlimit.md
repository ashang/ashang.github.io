---
title: prlimit to control resource limits
date: 2017-08-08
---

In operating systems, each process has a determined set of resources available
during its life time. For Linux, these include the amount of files it can open,
size of a core dump, amount of threads and stack size, among several others.
Each resource is has two limits: soft and hard, referring to the scope the limit
value can fluctuate between [soft, hard]. The first one can be considered the
default value, and the hard as the ceiling value. It is the kernel's job to make
sure these limits are enforced.

Traditionally, the ulimit(1) command has been used to set and retrieve the
resource limits of a process. This program, however, has two fundamental
problems: it only works with bash and, more important, it cannot be used for any
PID, only for the shell and its children.

We have developed a new tool, prlimit(1), that not only overcomes these issues,
but also presents a generic, user-friendlier way of setting/getting the
limits.It uses the system call of the same name introduced into kernel 2.6.36.
Below are some examples, enjoy.

See both limits for all bash's resources:
```
$ prlimit --pid $$
RESOURCE   DESCRIPTION                             SOFT      HARD UNITS
AS         address space limit                unlimited unlimited bytes
CORE       max core file size                         0 unlimited blocks
CPU        CPU time                           unlimited unlimited seconds
DATA       max data size                      unlimited unlimited bytes
FSIZE      max file size                      unlimited unlimited blocks
LOCKS      max amount of file locks held      unlimited unlimited ------
MEMLOCK    max locked-in-memory address space     65536     65536 kbytes
MSGQUEUE   max bytes in POSIX mqueues            819200    819200 bytes
NICE       max nice prio allowed to raise             0         0 ------
NOFILE     max amount of open files                1024      1024 ------
NPROC      max number of processes            unlimited unlimited ------
RSS        max resident set size              unlimited unlimited pages
RTPRIO     max real-time priority                     0         0 ------
RTTIME     timeout for real-time tasks        unlimited unlimited microsecs
SIGPENDING max amount of pending signals          16382     16382 ------
STACK      max stack size                       8388608 unlimited kbytes
```

Set both limits for the stack size to unlimited, then display it:
```
$ prlimit --pid $$ --stack=unlimited
$ prlimit --pid $$ --stack
RESOURCE DESCRIPTION         SOFT      HARD UNITS
STACK    max stack size unlimited unlimited kbytes
```
