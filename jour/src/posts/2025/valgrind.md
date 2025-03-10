---
title: valgrind
date: 2011-04-16T12:18:00.000+02:00
tags: ["testing","valgrind","debugging"]
---

./libtool --mode=execute 负责设置正确的运行环境（确保动态库能找到）。
valgrind 是你要使用的调试工具，可以换成 gdb 或 strace：

    ./libtool --mode=execute gdb zebra/zebra
    ./libtool --mode=execute strace zebra/zebra

[--valgrind-opts]：valgrind 选项（可选），例如 --leak-check=full。
zebra/zebra：你要运行的 FRR 组件（zebra 进程）。
[--zebra-opts]：zebra 进程的参数（可选）。



# valgrind + OSX

I just started implementing unit tests for my hobby project and I wanted to integrate [valgrind](http://www.valgrind.org/) into my testing process, especially since it recently got fully supported on OSX. So I tried the MacPorts installation of the package.

Unfortunately, I run a 10.6 64-bit os and so the packages that are automatically built come out as x86_64 executables. But in my hobby project, I keep everything 32bit. And even though the valgrind [documentation](http://valgrind.org/docs/manual/manual-core.html#manual-core.install) indicates that it should work with both 32 bit and 64 bit executables, I couldn't get it to work. It just produced errors like:

    valgrind: ./a.out: cannot execute binary file

So, my current solution is that I've downloaded the source and compiled it with only 32 bit support. Instructions are found [here](http://valgrind.org/downloads/repository.html) with the change:

    ./configure --enable-only32bit

And I keep the working 64 bit version available so I can still test all executables.

If anyone knows what I should do to get both 32 / 64 bit support in the same valgrind executable, please let me know!

```sh
==2396== 319,022 (11,408 direct, 307,614 indirect) bytes in 31 blocks are definitely lost in loss record 9,603 of 9,614
==2396== at 0x4C33B25: calloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==2396== by 0x8D3D89A: pam_start (in /lib/x86_64-linux-gnu/libpam.so.0.83.1)
==2396== by 0x413E91: sshpam_init (server_ssh.cc:394)
==2396== by 0x413E91: sshcb_auth_password (server_ssh.cc:484)
==2396== by 0x413E91: sshcb_msg(ssh_session_struct*, ssh_message_struct*, void*) (server_ssh.cc:1234)
==2396== by 0x8699DC9: ssh_message_queue (in /usr/lib/libssh.so.4.4.0)
==2396== by 0x869A557: ssh_packet_userauth_request (in /usr/lib/libssh.so.4.4.0)
==2396== by 0x869EE12: ssh_packet_process (in /usr/lib/libssh.so.4.4.0)
==2396== by 0x869F36A: ssh_packet_socket_callback (in /usr/lib/libssh.so.4.4.0)
==2396== by 0x86A8E31: ssh_socket_pollcallback (in /usr/lib/libssh.so.4.4.0)
==2396== by 0x86A4ACB: ssh_poll_ctx_dopoll (in /usr/lib/libssh.so.4.4.0)
==2396== by 0x86A60A8: ssh_handle_packets (in /usr/lib/libssh.so.4.4.0)
==2396== by 0x86BE49D: ssh_execute_message_callbacks (in /usr/lib/libssh.so.4.4.0)
==2396== by 0x415001: np_ssh_client_transport(client_struct_ssh*) (server_ssh.cc:959)
```
- http://www.cprogramming.com/debugging/valgrind.html 


./libtool --mode=execute valgrind [--valgrind-opts] zebra/zebra [--zebra-opts]



eclipse-cdt-valgrind - Valgrind integration for Eclipse CDT



alleyoop - Front-end to the Valgrind memory checker
eclipse-cdt-profiling-framework - framework for profiling tools for Eclipse CDT
eclipse-cdt-valgrind - Valgrind integration for Eclipse CDT
libtsan0 - ThreadSanitizer -- a Valgrind-based detector of data races (runtime)
libtsan0-dbg - ThreadSanitizer -- a Valgrind-based detector of data races (debug symbols)
jovie-dbg - debugging symbols for jovie
kaccessible-dbg - debugging symbols for kaccessible
kcachegrind - visualisation tool for the Valgrind profiler
kcachegrind-converters - format converters for KCachegrind profiler visualisation tool
kdesdk-scripts - scripts and data files for development
kmag-dbg - debugging symbols for kmag
kmousetool-dbg - debugging symbols for kmousetool
kmouth-dbg - debugging symbols for kmouth
kwalletmanager-dbg - debugging symbols for kwalletmanager
libtest-valgrind-perl - module to test Perl code through valgrind
mutextrace - Lock debugging tool
nemiver - Standalone graphical debugger for GNOME
valgrind - instrumentation framework for building dynamic analysis tools
valgrind-dbg - instrumentation framework for building dynamic analysis tools (debug)
valgrind-mpi - instrumentation framework for building dynamic analysis tools (MPI module)
valkyrie - open-source graphical user interface for the Valgrind
## Install 

### Install x86_64/amd64


Install from local server to save download time.


About 500MiB space is needed.


```
for i in gdb_7.4.1+dfsg-0.1_amd64.deb gdbserver_7.4.1+dfsg-0.1_amd64.deb libc-bin_2.13-38+deb7u11_amd64.deb libc6-dbg_2.13-38+deb7u11_amd64.deb libc6_2.13-38+deb7u11_amd64.deb libpython2.7_2.7.3-6+deb7u3_amd64.deb python2.7-minimal_2.7.3-6+deb7u3_amd64.deb python2.7_2.7.3-6+deb7u3_amd64.deb valgrind-dbg_1%3a3.7.0-6_amd64.deb valgrind_1%3a3.7.0-6_amd64.deb ; do wget http://10.10.50.10/ftp/valgrind-wheezy/$i; sudo dpkg -i $i; done

sudo apt-get install -f

```

### Install powerpc

```
for i in valgrind_3.10.0-4_powerpc.deb valgrind_3.7.0-6_powerpc.deb valgrind-mpi_3.10.0-4_powerpc.deb ; do wget http://10.10.50.10/ftp/valgrind-wheezy/$i; sudo dpkg -i $i; done

sudo apt-get install -f

```


### Install ppc64el

```
for i in valgrind_3.10.0-4_ppc64el.deb valgrind-dbg_3.10.0-4_ppc64el.deb valgrind-mpi_3.10.0-4_ppc64el.deb ; do wget http://10.10.50.10/ftp/valgrind-wheezy/$i; sudo dpkg -i $i; done

sudo apt-get install -f

```

### Install armhf

```
for i in valgrind_3.10.0-4_armhf.deb valgrind-dbg_3.10.0-4_armhf.deb valgrind-mpi_3.10.0-4_armhf.deb ; do wget http://10.10.50.10/ftp/valgrind-wheezy/$i; sudo dpkg -i $i; done

sudo apt-get install -f

```

## Usage

To add steps here.


## See also

http://www.cprogramming.com/debugging/valgrind.html 


