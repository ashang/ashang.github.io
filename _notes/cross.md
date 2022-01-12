---
title: cross
date: 2017-11-16
---

```
$ sudo vtysh -d zebra -c "show version"
FRRouting 8.0
Copyright 1996-2022 Kunihiro Ishiguro, et al.
configured with:
    '--sbindir=/usr/lib/frr' '--sysconfdir=/etc/frr' '--with-vtysh-pager=/usr/bin/pager' '--disable-dependency-tracking' '--enable-fpm' '--enable-snmp' '--enable-werror' '--enable-systemd' '--disable-zeromq' '--enable-ospfapi' '--enable-bgp-vnc' '--disable-protobuf' '--enable-multipath=256' '--enable-user=frr' '--enable-group=frr' '--enable-vty-group=frrvty' '--enable-configfile-mask=0640' '--enable-logfile-mask=0640' '--host=' '--libdir=/usr/lib/x86_64-linux-gnu/frr' '--with-moduledir=/usr/lib/x86_64-linux-gnu/frr/modules' '--localstatedir=/var/run/frr' '--prefix=/usr' 'host_alias=' 'PKG_CONFIG_PATH=:/home/build/master/x86/build/x86/rootfs/usr/lib/pkgconfig' 'LIBYANG_CFLAGS=-I/home/build/master/x86/build/x86/rootfs/usr/include' 'LIBYANG_LIBS=-L/home/build/master/x86/build/x86/rootfs/usr/lib -Wl,-rpath,/home/build/master/x86/build/x86/rootfs/usr/lib -lyang'

$ file /lib/ld-linux.so.3 /lib64/ld-linux-x86-64.so.2
/lib/ld-linux.so.3:          symbolic link to arm-linux-gnueabi/ld-2.28.so
/lib64/ld-linux-x86-64.so.2: symbolic link to /lib/x86_64-linux-gnu/ld-2.28.so

checking build system type... x86_64-pc-linux-gnu
checking host system type... arm-unknown-linux-gnueabi
configure: ...
configure: ... cross-compilation: creating hosttools directory and self-configuring for build platform tools
configure: ... use HOST_CPPFLAGS / HOST_CFLAGS / HOST_LDFLAGS if neccessary
configure: ...
checking build system type... x86_64-pc-linux-gnu
checking host system type... x86_64-pc-linux-gnu
checking for a BSD-compatible install... /usr/bin/install -c


native compilation on ARM devices is a waste of time (you need ca. 2.5h on ARM to build openssl vs. 5-10min on modern desktop using single thread!).

Second remark is that compilation always creates a mess. You need to install sources, compiler, libraries, devel packages and so on. Even if you try to delete unneeded things afterwards then there are always some remainings. So, it is always a good idea to separate the host side os from the build environment by creating chroot (a linux inside of another linux). After compilation you may simply delete the chroot directory.
In case of cross compilation you actually create a mixture of packages from different architectures (host and target). I would not even consider doing this without chroot cage.



# no libyang


# redefine

/usr/arm-linux-gnueabi/include/linux/in.h:168:8: error: redefinition of ‘struct ip_mreq’





# /usr/lib/gcc-cross/arm-linux-gnueabi/8/../../../../arm-linux-gnueabi/bin/ld: lib/.libs/libfrr.so: undefined reference to `lyd_dup_siblings'


`


# snmp

checking whether we can link to Net-SNMP... no

```
dnl ------------------
dnl check Net-SNMP library
dnl ------------------
if test "$enable_snmp" != "" -a "$enable_snmp" != "no"; then
   AC_PATH_TOOL([NETSNMP_CONFIG], [net-snmp-config], [no])
   if test "$NETSNMP_CONFIG" = "no"; then
      AC_MSG_ERROR([--enable-snmp given but unable to find net-snmp-config])
   fi
   SNMP_LIBS="`${NETSNMP_CONFIG} --agent-libs`"
   SNMP_CFLAGS="`${NETSNMP_CONFIG} --base-cflags`"
   # net-snmp lists all of its own dependencies.  we absolutely do not want that
   # among other things we avoid a GPL vs. OpenSSL license conflict here
   for removelib in crypto ssl sensors pci wrap; do
     SNMP_LIBS="`echo $SNMP_LIBS | sed -e 's/\(^\|\s\)-l'$removelib'\b/ /g' -e 's/\(^\|\s\)\([^\s]*\/\)\?lib'$removelib'\.[^\s]\+\b/ /g'`"
   done
   AC_MSG_CHECKING([whether we can link to Net-SNMP])
   AC_LINK_IFELSE_FLAGS([$SNMP_CFLAGS], [$SNMP_LIBS], [AC_LANG_PROGRAM([
int main(void);
],
[
{
  return 0;
}
])], [
     AC_MSG_RESULT([no])
     AC_MSG_ERROR([--enable-snmp given but not usable])])
   case "${enable_snmp}" in
     yes)
      SNMP_METHOD=agentx
      ;;
     agentx)
      SNMP_METHOD="${enable_snmp}"
      ;;
     *)
      AC_MSG_ERROR([--enable-snmp given with an unknown method (${enable_snmp}). Use yes or agentx])
      ;;
   esac
   AH_TEMPLATE([SNMP_AGENTX], [Use SNMP AgentX to interface with snmpd])
   AC_DEFINE_UNQUOTED(AS_TR_CPP(SNMP_${SNMP_METHOD}),,[SNMP method to interface with snmpd])
fi
```



## yang

$ sudo cp  ./build/arm/.rootfs-FYrikY/usr/lib/libyang* /usr/lib/arm-linux-gnueabi/

找不到libyang，关键在rpath

    LIBYANG_LIBS="-L$DEP_ROOTFS/usr/lib -Wl,-rpath,$DEP_ROOTFS/usr/lib -lyang"



##


 modules/python/common.cmake

    # This file is included from a subdirectory
        set(PYTHON_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../")

        ocv_add_module(${MODULE_NAME} BINDINGS)

became

        # This file is included from a subdirectory
        set(PYTHON_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../")

        find_package(HDF5)
        include_directories(${HDF5_INCLUDE_DIRS})

        ocv_add_module(${MODULE_NAME} BINDINGS)

And this worked for me, I only had to run make again (Ubuntu 16.10)


##原来的linux/smp_lock.h这个头文件在新版本中被替换成了linux/hardirq.h

/usr/lib/gcc/x86_64-linux-gnu/9/cc1plus

$ `g++ -print-prog-name=cc1plus` -v
ignoring nonexistent directory "/usr/local/include"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/9/include-fixed"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/9/../../../../x86_64-linux-gnu/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/include/c++/9
 /usr/include/x86_64-linux-gnu/c++/9
 /usr/include/c++/9/backward
 /usr/lib/gcc/x86_64-linux-gnu/9/include
 /usr/include
End of search list.

# vim

:!scp -q '/tmp/vU6lxAP/0' 'arm/build_frr.sh'

syntax

-Wl,-rpath,/usr/local/lib

# Docker

sudo apt install libsystemd-dev sudo libjson-c-dev gcc-arm-linux-gnueabi crossbuild-essential-armel vim git automake autoconf libtool build-essential cmake libelf-dev python3


# I've included -Wl,-rpath,/home/aosterman/tools/system/lib -Wl,-rpath,/home/aosterman/tools/system/lib64 in LDFLAGS, CFLAGS and CPPFLAGS and exported all of them. I can force the build to succeed by setting LD_LIBRARY_PATH, but the final result only works if I set it again at run time, which I absolutely do not want to do.


By default both --libdir and --libexec build themselves relative to --prefix, so I doubt that's it. The ./configure example above would be fine if I was installing a system copy, as libtool will take care of all that automagically by itself. My issue is that I'm trying to compile it in a non-standard location without root access.

More testing is needed, but it looks like setting LD_RUN_PATH while compiling causes it to bake rpath into the binaries correctly.

# little background on dynamic linking

the job of dynamic linker and loader(ld.so) is to resolve the executable’s dependencies on shared libraries and to load the required ones at run-time. readelf .bin to find the NEDDED headers and search the DSO with a matching SONAME

    DT_RPATH in the ELF binary, unless DT_RUNPATH set.
        LD_LIBRARY_PATH entries, unless setuid/setgid
            DT_RUNPATH in ELF binary
                /etc/ld.so.cache entries, unless -z nodeflib given at link time
                    /lib, /usr/lib unless -z nodeflib
                        Done, “not found”.

                        however, exceptions(small print…)

                            step1 & 2 if DT_RPATH will ignored is DT_RUNPATH is set. then LD_LIBRARY_PATH will search first
                                step 3 LD_LIBRARY can be override by calling dynamic linker with option –library-path
                                    step6 if executable is linked with ```-z`` so #6 is skipped.
                                        if using origin flag, remember to pass -z origin to mark the obejct as requiring origin processing
                                                LD_PRELOAD happen before all those.
                                                    LD_LIBRARY_PATH inherited by all processes generated by parent and it is considered evil

                                                    Encoding rpath/runpath in binaray

                                                    ELF binaries can contains supplemental path for DSO, those path must encoded at compile time and it is searched before system default path(which could overriden by LD_LIBRARY_PATH). so the problem of find a DSO is done by the dev build the app rather than the user that deploy the app. there are two way to do rpath

                                                        set LD_RUN_PATH to the search path you want to encode
                                                            for rpath: add linker flag -Wl, -rpath, /user/local/lib similar to -L, you could add multiple time, order doestn’t matters AND --enable-new-dtagsfor runpath
                                                                    using chrpath to change already-present RPATH

                                                                    $ gcc program.c -lm -o program '-Wl,-rpath,$ORIGIN/lib'
                                                                    $ ldd program | grep libm
                                                                            libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 // local lib can't found
                                                                            $ mkdir lib && cp /lib/x86_64-linux-gnu/libm.so.6
                                                                            $ ldd program | grep libm
                                                                                    libm.so.6 => /home/longwei/lib/libm.so.6 //use local lib instead

                                                                                    after compiler, you need to change elf binaray in order to change the rpath install_name_tool or patchelf

                                                                                    tl;dr

                                                                                        rpath is NOT runpath, runpath is introduced around 2000 when rpath cause mass issue used by libtool via overriding LD_LIBRARY_PATH
                                                                                            RUNPATH happens after LD_LIBRARY_PATH, and set RUNPATH will cancel RPATH.
                                                                                                chrpath -d foo.so to suppress rpth => runpath.
                                                                                                    runpath is not used for finding indirect library dependecies.



#  What’s the best practice?

when shipping a app, linking to core libs like(libc | libm) is ok as long as the version is good enough. it’s good to enable user to tweak/adjusting library search path.

so there is basically two way, RPATH and LD_LIBRARY_PATH LD_LIBRARY_PATH is very simple, run a shell script to bootstrap the environment and then call the executable. it only takes an absolute path and it will leave RPATH untouched. the catch is LD_LIBRARY_PATH can break other things in very subtle way…

another way is is tell compiler the locations at link time by RPATH, it is stored in the elf executable, in the dynamic section. It can be a relative path.

here is the catch, RUNPATH is recommended over RPATH, and RPATH is deprecated, but RUNPATH is currently not supported by all systems…

    you could using relative path of your current path, but user may not invoke the execuatable in pwd
    then $ORIGIN variable to define where is the executable
    but that’s not all, because $ORIGIN will be escape as RIGIN…

unix:{
    # suppress the default RPATH if you wish
    QMAKE_LFLAGS_RPATH=
    # add your own with quoting gyrations to make sure $ORIGIN gets to the command line unexpanded
    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\../mylibs\'"
    #There is QMAKE_RPATHDIR, But it won't work with a path containing $ORIGIN
    QMAKE_RPATHDIR += $${QUOTE}$${DOLLAR}$${DOLLAR}ORIGIN$${QUOTE}
}

but there is more, you may also need to pass in -Wl,-z,origin because gcc think pass -rpath=$ORIGIN is not good enough hassle. Here is a example when

readelf -d foo | grep ORIGIN
0x000000000000000f (RPATH)    Library rpath: [$ORIGIN:QT_INSTALL_GCC:QT_INSTALL_GCC/lib]
0x000000006ffffffb (FLAGS_1)  Flags: ORIGIN

Commands for Shared Library Management & Debugging Problem

TODO
System default path

command

    ldconfig: updates the necessary links for the run time binding
    ldd: tekk what’s lib a given program needs to run
    ltrace: A library call tracer
    ld.so/ld-linux.so: dynamic linker/loader

important file

    /lib/ld-linux.so.* : Execution time linker/loader.
    /etc/ld.so.conf : File containing a list of colon, space, tab, newline, or comma separated directories in which to search for libraries.
    /etc/ld.so.cache : File containing an ordered list of libraries found in the directories specified in /etc/ld.so.conf. This file is not in human readable format, and is not intended to be edited. This file is created by ldconfig command.
    lib*.so.version : Shared libraries stores in /lib, /usr/lib, /usr/lib64, /lib64, /usr/local/lib directories.

supposed I installed a new library in~/lib then ldconfig -l ~/lib/foo.so to manually linking this DSO.

another way is to create a /etc/ld.so.conf/foo.conf (name don’t matters). then ldconfig to update the cache.




#
export TMP=/tmp/$0_$$


pushd "$(dirname $0)" &>/dev/null
MYDIR=$(pwd)
popd &>/dev/null






# % libtool link g++ foo.cc -o foo -rpath /somewhere
libtool: link: g++ foo.cc -o foo  -Wl,-rpath -Wl,/somewhere
% readelf -d foo | grep RPATH
0x000000000000000f (RPATH)              Library rpath: [/somewhere]








a23$ libtool --mode=compile gcc -g -O -c foo.c
gcc -g -O -c foo.c -o foo.o
a23$ libtool --mode=compile gcc -g -O -c hello.c
gcc -g -O -c hello.c -o hello.o






On shared library systems, libtool automatically generates an additional PIC object by inserting the appropriate PIC generation flags into the compilation command:

burger$ libtool --mode=compile gcc -g -O -c foo.c
mkdir .libs
gcc -g -O -c foo.c  -fPIC -DPIC -o .libs/foo.o
gcc -g -O -c foo.c -o foo.o >/dev/null 2>&1
burger$

Note that Libtool automatically created .libs directory upon its first execution, where PIC library object files will be stored.



# libtool manual 3.2 Linking libraries

Without libtool, the programmer would invoke the ar command to create a static library:

burger$ ar cru libhello.a hello.o foo.o
burger$

But of course, that would be too simple, so many systems require that you run the ranlib command on the resulting library (to give it better karma, or something):

burger$ ranlib libhello.a
burger$

It seems more natural to use the C compiler for this task, given libtool’s “libraries are programs” approach. So, on platforms without shared libraries, libtool simply acts as a wrapper for the system ar (and possibly ranlib) commands.

Again, the libtool control file name (.la suffix) differs from the standard library name (.a suffix). The arguments to libtool are the same ones you would use to produce an executable named libhello.la with your compiler (see Link mode):

a23$ libtool --mode=link gcc -g -O -o libhello.la foo.o hello.o
*** Warning: Linking the shared library libhello.la against the
*** non-libtool objects foo.o hello.o is not portable!
ar cru .libs/libhello.a
ranlib .libs/libhello.a
creating libhello.la
(cd .libs && rm -f libhello.la && ln -s ../libhello.la libhello.la)
a23$

Aha! Libtool caught a common error… trying to build a library from standard objects instead of special .lo object files. This doesn’t matter so much for static libraries, but on shared library systems, it is of great importance. (Note that you may replace libhello.la with libhello.a in which case libtool won’t issue the warning any more. But although this method works, this is not intended to be used because it makes you lose the benefits of using Libtool.)

So, let’s try again, this time with the library object files. Remember also that we need to add -lm to the link command line because foo.c uses the cos math library function (see Using libtool).

Another complication in building shared libraries is that we need to specify the path to the directory wher they will (eventually) be installed (in this case, /usr/local/lib)1:

a23$ libtool --mode=link gcc -g -O -o libhello.la foo.lo hello.lo \
                -rpath /usr/local/lib -lm
ar cru .libs/libhello.a foo.o hello.o
ranlib .libs/libhello.a
creating libhello.la
(cd .libs && rm -f libhello.la && ln -s ../libhello.la libhello.la)
a23$

Now, let’s try the same trick on the shared library platform:

burger$ libtool --mode=link gcc -g -O -o libhello.la foo.lo hello.lo \
                -rpath /usr/local/lib -lm
rm -fr  .libs/libhello.a .libs/libhello.la
ld -Bshareable -o .libs/libhello.so.0.0 .libs/foo.o .libs/hello.o -lm
ar cru .libs/libhello.a foo.o hello.o
ranlib .libs/libhello.a
creating libhello.la
(cd .libs && rm -f libhello.la && ln -s ../libhello.la libhello.la)



#


burger$ libtool --mode=link gcc -g -O -o hell main.o libhello.la
gcc -g -O -o .libs/hell main.o -L./.libs -R/usr/local/lib -lhello -lm
creating hell
burger$

Now assume libhello.la had already been installed, and you want to link a new program with it. You could figure out where it lives by yourself, then run:

burger$ gcc -g -O -o test test.o -L/usr/local/lib -lhello -lm

However, unless /usr/local/lib is in the standard library search path, you won’t be able to run test. However, if you use libtool to link the already-installed libtool library, it will do The Right Thing (TM) for you:

burger$ libtool --mode=link gcc -g -O -o test test.o \
                /usr/local/lib/libhello.la
gcc -g -O -o .libs/test test.o -Wl,--rpath \
        -Wl,/usr/local/lib /usr/local/lib/libhello.a -lm
creating test



# GDB complains because it cannot find the shared library that hell is linked against. So, we must use libtool to properly set the library path and run the debugger. Fortunately, we can forget all about the .libs directory, and just run it on the executable wrapper (see Execute mode):

burger$ libtool --mode=execute gdb hell
GNU gdb 5.3 (i386-unknown-netbsd)
Copyright 2002 Free Software Foundation, Inc.
GDB is free software, covered by the GNU General Public License,
and you are welcome to change it and/or distribute copies of it
under certain conditions.  Type "show copying" to see the conditions.
There is no warranty for GDB.  Type "show warranty" for details.
(gdb) break main
Breakpoint 1 at 0x8048547: file main.c, line 29.
(gdb) run
Starting program: /home/src/libtool/demo/.libs/hell

Breakpoint 1, main (argc=1, argv=0xbffffc40) at main.c:29
29        printf ("Welcome to GNU Hell!\n");
(gdb) quit
The program is running.  Quit anyway (and kill it)? (y or n) y




# libtool --mode=install cp libhello.la /usr/local/lib/libhello.la
cp libhello.la /usr/local/lib/libhello.la
cp .libs/libhello.a /usr/local/lib/libhello.a
ranlib /usr/local/lib/libhello.a





burger# libtool --mode=install install -c libhello.la \
                /usr/local/lib/libhello.la
install -c .libs/libhello.so.0.0 /usr/local/lib/libhello.so.0.0
install -c libhello.la /usr/local/lib/libhello.la
install -c .libs/libhello.a /usr/local/lib/libhello.a
ranlib /usr/local/lib/libhello.a






It is safe to specify the -s (strip symbols) flag if you use a BSD-compatible install program when installing libraries. Libtool will either ignore the -s flag, or will run a program that will strip only debugging and compiler symbols from the library.

Once the libraries have been put in place, there may be some additional configuration that you need to do before using them. First, you must make sure that where the library is installed actually agrees with the -rpath flag you used to build it.

Then, running ‘libtool -n finish libdir’ can give you further hints on what to do (see Finish mode):

burger# libtool -n finish /usr/local/lib
PATH="$PATH:/sbin" ldconfig -m /usr/local/lib
-----------------------------------------------------------------
Libraries have been installed in:
   /usr/local/lib

To link against installed libraries in a given directory, LIBDIR,
you must use the '-LLIBDIR' flag during linking.

 You will also need to do one of the following:
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-RLIBDIR' linker flag

```

