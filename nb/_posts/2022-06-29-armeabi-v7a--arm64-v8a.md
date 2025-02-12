
armeabi-v7a, arm64-v8a, x86?

The armeabi-v7a ABI compiles to armeabi, thumb-2 and VFPv3-D16 instruction set,

Each combination of CPU and instruction set has its own Application Binary Interface (ABI). An ABI includes the following information:

The CPU instruction set (and extensions) that can be used. The endianness of memory stores and loads at runtime. Android is always little-endian. Conventions for passing data between applications and the system, including alignment constraints, and how the system uses the stack and registers when it calls functions. The format of executable binaries, such as programs and shared libraries, and the types of content they support. Android always uses ELF. For more information, see ELF System V Application Binary Interface. How C++ names are mangled. For more information, see Generic/Itanium C++ ABI.

PLDD(1)                                                                                                     Linux User Manual                                                                                                     PLDD(1)

NAME
       pldd - display dynamic shared objects linked into a process

SYNOPSIS
       pldd pid
       pldd option

DESCRIPTION
       The pldd command displays a list of the dynamic shared objects (DSOs) that are linked into the process with the specified process ID (PID).  The list includes the libraries that have been dynamically loaded using dlopen(3).

OPTIONS
       -?, --help
              Display a help message and exit.

       --usage
              Display a short usage message and exit.

       -V, --version
              Display program version information and exit.

EXIT STATUS
       On success, pldd exits with the status 0.  If the specified process does not exist, the user does not have permission to access its dynamic shared object list, or no command-line arguments are supplied, pldd exists with a sta‐
       tus of 1.  If given an invalid option, it exits with the status 64.

VERSIONS
       pldd is available since glibc 2.15.

CONFORMING TO
       The pldd command is not specified by POSIX.1.  Some other systems have a similar command.

NOTES
       The command

           lsof -p PID

       also shows output that includes the dynamic shared objects that are linked into a process.

       The gdb(1) info shared command also shows the shared libraries being used by a process, so that one can obtain similar output to pldd using a command such as the following (to monitor the process with the specified pid):

           $ gdb -ex "set confirm off" -ex "set height 0" -ex "info shared" \
                   -ex "quit" -p $pid | grep '^0x.*0x'

BUGS
       From glibc 2.19 to 2.29, pldd was broken: it just hung when executed.  This problem was fixed in glibc 2.30, and the fix has been backported to earlier glibc versions in some distributions.

EXAMPLES
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

SEE ALSO
       ldd(1), lsof(1), dlopen(3), ld.so(8)

COLOPHON
       This page is part of release 5.10 of the Linux man-pages project.  A description of the project, information about reporting bugs, and the latest version of this page, can be found at https://www.kernel.org/doc/man-pages/.


LDD(1)                                                                                                  Linux Programmer's Manual                                                                                                  LDD(1)

NAME
       ldd - print shared object dependencies

SYNOPSIS
       ldd [option]... file...

DESCRIPTION
       ldd  prints  the  shared  objects  (shared libraries) required by each program or shared object specified on the command line.  An example of its use and output (using sed(1) to trim leading white space for readability in this
       page) is the following:

           $ ldd /bin/ls | sed 's/^ */    /'
               linux-vdso.so.1 (0x00007ffcc3563000)
               libselinux.so.1 => /lib64/libselinux.so.1 (0x00007f87e5459000)
               libcap.so.2 => /lib64/libcap.so.2 (0x00007f87e5254000)
               libc.so.6 => /lib64/libc.so.6 (0x00007f87e4e92000)
               libpcre.so.1 => /lib64/libpcre.so.1 (0x00007f87e4c22000)
               libdl.so.2 => /lib64/libdl.so.2 (0x00007f87e4a1e000)
               /lib64/ld-linux-x86-64.so.2 (0x00005574bf12e000)
               libattr.so.1 => /lib64/libattr.so.1 (0x00007f87e4817000)
               libpthread.so.0 => /lib64/libpthread.so.0 (0x00007f87e45fa000)

       In the usual case, ldd invokes the standard dynamic linker (see ld.so(8)) with the LD_TRACE_LOADED_OBJECTS environment variable set to 1.  This causes the dynamic linker to inspect the program's dynamic dependencies, and  find
       (according  to  the rules described in ld.so(8)) and load the objects that satisfy those dependencies.  For each dependency, ldd displays the location of the matching object and the (hexadecimal) address at which it is loaded.
       (The linux-vdso and ld-linux shared dependencies are special; see vdso(7) and ld.so(8).)

   Security
       Be aware that in some circumstances (e.g., where the program specifies an ELF interpreter other than ld-linux.so), some versions of ldd may attempt to obtain the dependency information by attempting  to  directly  execute  the
       program,  which  may lead to the execution of whatever code is defined in the program's ELF interpreter, and perhaps to execution of the program itself.  (In glibc versions before 2.27, the upstream ldd implementation did this
       for example, although most distributions provided a modified version that did not.)

       Thus, you should never employ ldd on an untrusted executable, since this may result in the execution of arbitrary code.  A safer alternative when dealing with untrusted executables is:

           $ objdump -p /path/to/program | grep NEEDED

       Note, however, that this alternative shows only the direct dependencies of the executable, while ldd shows the entire dependency tree of the executable.

OPTIONS
       --version
              Print the version number of ldd.

       -v, --verbose
              Print all information, including, for example, symbol versioning information.

       -u, --unused
              Print unused direct dependencies.  (Since glibc 2.3.4.)

       -d, --data-relocs
              Perform relocations and report any missing objects (ELF only).

       -r, --function-relocs
              Perform relocations for both data objects and functions, and report any missing objects or functions (ELF only).

       --help Usage information.

BUGS
       ldd does not work on a.out shared libraries.

       ldd does not work with some extremely old a.out programs which were built before ldd support was added to the compiler releases.  If you use ldd on one of these programs, the program will attempt to run with argc = 0  and  the
       results will be unpredictable.

SEE ALSO
       pldd(1), sprof(1), ld.so(8), ldconfig(8)

COLOPHON
       This page is part of release 5.10 of the Linux man-pages project.  A description of the project, information about reporting bugs, and the latest version of this page, can be found at https://www.kernel.org/doc/man-pages/.

                                                                                                                2019-03-06                                                                                                         LDD(1)

8730:	/usr/bin/bash
linux-vdso.so.1
/lib/x86_64-linux-gnu/libtinfo.so.6
/lib/x86_64-linux-gnu/libdl.so.2
/lib/x86_64-linux-gnu/libc.so.6
/lib64/ld-linux-x86-64.so.2
