---
title: ldd and pldd to print shared object dependencies
tags: ["ldd", "pldd", "objects"]
date: 2012-02-09
author: ast
---

`ldd` prints the shared objects required by each program or shared object.

```sh
$ ldd ~/bin/ls | sed 's/^ */    /'
  linux-vdso.so.1 (0x00007ffcc3563000)
  libselinux.so.1 => /lib64/libselinux.so.1 (0x00007f87e5459000)
  libcap.so.2 => /lib64/libcap.so.2 (0x00007f87e5254000)
  libc.so.6 => /lib64/libc.so.6 (0x00007f87e4e92000)
  libpcre.so.1 => /lib64/libpcre.so.1 (0x00007f87e4c22000)
  libdl.so.2 => /lib64/libdl.so.2 (0x00007f87e4a1e000)
  /lib64/ld-linux-x86-64.so.2 (0x00005574bf12e000)
  libattr.so.1 => /lib64/libattr.so.1 (0x00007f87e4817000)
  libpthread.so.0 => /lib64/libpthread.so.0 (0x00007f87e45fa000)

$ ldd /bin/ls | sed 's/^ */    /'
	linux-vdso.so.1 (0x00007ffeec340000)
	libselinux.so.1 => /lib/x86_64-linux-gnu/libselinux.so.1 (0x00007fa8f5c6a000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fa8f5a89000)
	libpcre2-8.so.0 => /lib/x86_64-linux-gnu/libpcre2-8.so.0 (0x00007fa8f59ef000)
	/lib64/ld-linux-x86-64.so.2 (0x00007fa8f5cdb000)
```

ldd invokes the  standard  dynamic  linker  (see  ld.so(8))  with  the
`LD_TRACE_LOADED_OBJECTS` environment variable set to 1.

This causes the dynamic  linker  to  inspect the program's dynamic dependencies, and find (according to the rules described in ld.so(8)) and load the dependencies.

For each dependency, ldd displays the location of  the matching  object  and the (hexadecimal) address at which it is loaded.
(The linux-vdso and ld-linux shared dependencies are special; see vdso(7) and ld.so(8).)

## Security

Be aware that in some circumstances (e.g., where the program specifies an ELF interpreter other than ld-linux.so), some versions of ldd may attempt to obtain the dependency information by attempting to directly execute the program, which may lead to the execution of whatever code  is  defined  in  the program's  ELF  interpreter, and perhaps to execution of the program itself.

In glibc versions before 2.27, the upstream ldd implementation did this for example, although  most  distributions  provided a modified version that did not.

Thus, you should never employ ldd on an untrusted executable, since this may result in the execution of arbitrary code.  A safer alternative when dealing with untrusted executables is:

```sh
$ objdump -p /path/to/program | grep NEEDED
```

Note, however, that this alternative shows only the direct dependencies of the executable, while ldd
       shows the entire dependency tree of the executable.

OPTIONS

       -v, --verbose
              Print all information, including, for example, symbol versioning information.

       -u, --unused
              Print unused direct dependencies.  (Since glibc 2.3.4.)

       -d, --data-relocs
              Perform relocations and report any missing objects (ELF only).

       -r, --function-relocs
              Perform  relocations  for  both data objects and functions, and report any missing objects or
              functions (ELF only).

## pldd

> pldd - display dynamic shared objects linked into a process

The  pldd  command  displays  a  list  of the dynamic shared objects (DSOs) that are linked into the process with the specified process ID (PID).  The list includes the libraries that have been dynami cally loaded using dlopen(3).

The command `lsof -p PID` also shows output that includes the dynamic shared objects that are linked into a process.

The  gdb(1) info shared command also shows the shared libraries being used by a process, so that one can obtain similar output to pldd using a command such as the following (to monitor the process with the specified pid):

```sh
$ gdb -ex "set confirm off" -ex "set height 0" -ex "info shared" \
    -ex "quit" -p $pid | grep '^0x.*0x'
```

```sh
$ echo $$               # Display PID of shell
1143
$ pldd $$               # Display DSOs linked into the shell
1143:   /usr/bin/bash
linux-vdso.so.1
/lib64/libtinfo.so.5
/lib64/libdl.so.2
/lib64/libc.so.6
/lib64/ld-linux-x86-64.so.2
/lib64/libnss_files.so.2
```