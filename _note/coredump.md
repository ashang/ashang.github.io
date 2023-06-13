---
sticky: true
title: Piping core dumps
date: 2012-07-09T16:04:56+08:00
tags: Example
---



A core dump is a file containing a process’s memory contents when the process terminates unexpectedly.
Core dumps are triggered by the kernel in response to program crashes. A core dump can be invaluable as a post-mortem snapshot of the program’s state at the time of the crash, especially if the fault is hard to reliably reproduce.

Most Linux systems have core dumps enabled by default. As always, there is a tradeoff to make here. On one hand, we want to gather data for improved stability and troubleshooting. On the other, we want to limit the debug data and avoid leaking sensitive data.

The first option is good for machines where unstable programs need to be investigated, as the workstation of a developer. The second option is better suited for production systems storing or processing sensitive data.

Enable core dumps
To enable dumps, we need to update soft limits on the system. This is done by ulimit command with -S switch which indicates that it is a soft limit. The -c denotes the size of a core dump.

ulimit -S -c unlimited

If you want to enable core dump permanently, add following line in /etc/security/limits.conf to update system limit

* soft core unlimited

The above line will set the core file size to unlimited which will enable dump implicitly

Disable core dumps
It makes sense to disable any core dumps on Linux by default for all your systems. This is because the files take up disk space and may contain sensitive data

We can execute the following command to disable the core dump by updating soft limits.

ulimit -S -c 0

If you want to disable core dump permanently, add following lines in /etc/security/limits.conf to update system limit

* soft core 0
* hard core 0

The above line will set the core file size to 0 which will disable dump implicitly

A hard limit is something that never can be overridden, while a soft limit might only be applicable for specific users.

Where are my core dumps?
Linux creates a core dump file at a configurable location
Default location is |/usr/libexec/abrt-hook-ccpp %s %c %p %u %g %t e %P %I

We can change this location using sysctl command

sudo sysctl -w kernel.core_pattern=/coredumps/core-%e-%s-%u-%g-%p-%t

This command will update core_pattern file — /proc/sys/kernel/core_pattern with new location. You can find more information related to format specifiers in core_pattern here.

You can make core dump file path changes permanant, by adding following line in /etc/sysctl.conf

    kernel.core_pattern="/coredumps/core-%e-%s-%u-%g-%p-%t"



----


Use systemctl edit smb.service to update the dependencies.

After=dirsrv.target - Will ensure the smb.service is started after dirsrv.target.

For robustness, (which will be worth while if you're tinkering with this stuff) you may also wish to include some of the following:

Requires=dirsrv.target - Activate dirsrv.target when smb.service is activated. Will cause smb.service to fail if dirsrv.target fails.

Wants=dirsrv.target - Activate dirsrv.target when smb.service is activated. Won't cause smb.service to fail if dirsrv.target fails.

BindsTo=dirsrv.target - If dirsrv.target is deactivated, deactivate smb.service.





 systemctl --type service --state running




$ cat /proc/sys/kernel/core_pattern
|/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %h

$ cat /proc/sys/kernel/core_pipe_limit
16



file: /proc/sys/kernel/core_uses_pid
variable: kernel.core_uses_pid
Official reference
The default coredump filename is “core”. By setting core_uses_pid to 1, the coredump filename becomes core.PID. If core_pattern does not include “%p” (default does not) and core_uses_pid is set, then .PID will be appended to the filename.




following call to the application source (in the C language):

    prctl(PR_SET_DUMPABLE, 1);


signals are valid for this platform

Raw
kill -l
BE CAREFUL

Raw
kill -6 <pid>
or

Raw
kill -SIGABRT <pid>
or

Raw
kill -ABRT <pid>
To it manually

Raw
gcore <pid>






DefaultLimitCORE=0:infinity",

    man core tells us:

Piping core dumps to a program

Since kernel 2.6.19, Linux supports an alternate syntax for the /proc/sys/kernel/core_pattern file. If the first character of this file is a pipe symbol (|), then the remainder of the line is interpreted as a program to be executed. Instead of being written to a disk file, the core dump is given as standard input to the program.

Note the following points:

The program must be specified using an absolute pathname (or a pathname relative to the root directory, /), and must immediately follow the '|' character.

The process created to run the program runs as user and group root.

Command-line arguments can be supplied to the program (since Linux 2.6.24), delimited by white space (up to a total line length of 128 bytes).

The command-line arguments can include any of the % specifiers listed above. For example, to pass the PID of the process that is being dumped, specify %p in an argument.

You can put a script there, like e.g.

| /path/to/myscript %p %s %c
You can detect which process is triggering the coredump: (man core):

       %%  a single % character
       %p  PID of dumped process
       %u  (numeric) real UID of dumped process
       %g  (numeric) real GID of dumped process
       %s  number of signal causing dump
       %t  time of dump, expressed as seconds since the Epoch,  1970-01-01
           00:00:00 +0000 (UTC)
       %h  hostname (same as nodename returned by uname(2))
       %e  executable filename (without path prefix)
       %E  pathname of executable, with slashes ('/') replaced by exclama‐
           tion marks ('!').
       %c  core file size soft resource limit of crashing  process  (since
           Linux 2.6.24)


Core dump files will be generated after an uncaught signal in a process (as a SIGSEGV or SIGQUIT), in the base directory where the program was executed, and named as `core` or `core.PID`.

For example:
$> ulimit -c unlimited
$> kill -s SIGSEGV $$

This will trigger a segmentation fault in your current shell (you probably guessed it after seeing that the shell session where you executed it was closed), and generate a core file in:
/home/user/core

Now… is it possible to change where that file is generated by default instead of the current directory? And is it possible to change the name of that generated file? The answer is YES! to both. Let’s see how we can get this.

# The Core Pattern in Kernel

Since some years ago, the kernel configuration includes a file named “core_pattern”:
/proc/sys/kernel/core_pattern

In my system, that file contains just this single word:
core

As expected, this pattern shows how the core file will be generated. Two things can be understood from the previous line: The filename of the core dump file generated will be “core”; and second, the current directory will be used to store it (as the path specified is completely relative to the current directory).

Now, if we change the contents of that file… (as root, of course)

$> mkdir -p /tmp/cores
$> chmod a+rwx /tmp/cores
$> echo "/tmp/cores/core.%e.%p.%h.%t" > /proc/sys/kernel/core_pattern

And we run the same as before:

$> cd /home/user
$> ulimit -c unlimited
$> $> kill -s SIGSEGV $$

We get… voilá!
/tmp/cores/core.bash.8539.drehbahn-mbp.1236975953

Not only the program name (“bash“) or the PID (“8539“), but also the hostname (“drehbahn-mbp“) and the unix time (“1236975953“) are appended in the name of the core file!! And of course, it is stored in the absolute path we specified (“/tmp/cores/“).

You can use the following pattern elements in the core_pattern file:

%p: pid
%: '%' is dropped
%%: output one '%'
%u: uid
%g: gid
%s: signal number
%t: UNIX time of dump
%h: hostname
%e: executable filename
%: both are dropped

Isn’t is great?! Imagine that you have a cluster of machines and you want to use a NFS directory to store all core files from all the nodes. You will be able to detect which node generated the core file (with the hostname), which program generated it (with the program name), and also when did it happen (with the unix time).



%p:       pid
%<NUL>:   '%' is dropped
%%:       output one '%'
%u:       uid
%g:       gid
%s:       signal number
%t:       UNIX time of dump
%h:       hostname
%e:       executable filename
%<OTHER>: both are dropped

If core_pattern does not include "%p" (default does not) and core_uses_pid is set, then .PID will be appended to the filename.

example:

    echo "core.%e.%p" > /proc/sys/kernel/core_pattern

produces files names

    core.<executable>.<pid>

to make the changes permanent, add the following line to /etc/sysctl.conf:

    kernel.core_pattern = core.%e.%p

# man 5 core

http://man7.org/linux/man-pages/man5/core.5.html

       The  default  action of certain signals is to cause a process to terminate and produce a core dump file, a disk file containing an image of the process's memory at the time of termination.  This image can be used in a debugger (e.g., gdb(1)) to inspect the state of the program at the time that it termi‐
       nated.  A list of the signals which cause a process to dump core can be found in signal(7).

       A process can set its soft RLIMIT_CORE resource limit to place an upper limit on the size of the core dump file that will be produced if it receives a "core dump" signal; see getrlimit(2) for details.

       There are various circumstances in which a core dump file is not produced:

       *  The process does not have permission to write the core file.  (By default, the core file is called core or core.pid, where pid is the ID of the process that dumped core, and is created in the current working directory.  See below for details on naming.)  Writing the core file fails if  the  directory
          in which it is to be created is nonwritable, or if a file with the same name exists and is not writable or is not a regular file (e.g., it is a directory or a symbolic link).

       *  A (writable, regular) file with the same name as would be used for the core dump already exists, but there is more than one hard link to that file.

       *  The filesystem where the core dump file would be created is full; or has run out of inodes; or is mounted read-only; or the user has reached their quota for the filesystem.

       *  The directory in which the core dump file is to be created does not exist.

       *  The RLIMIT_CORE (core file size) or RLIMIT_FSIZE (file size) resource limits for the process are set to zero; see getrlimit(2) and the documentation of the shell's ulimit command (limit in csh(1)).

       *  The binary being executed by the process does not have read permission enabled.

       *  The  process is executing a set-user-ID (set-group-ID) program that is owned by a user (group) other than the real user (group) ID of the process, or the process is executing a program that has file capabilities (see capabilities(7)).  (However, see the description of the prctl(2) PR_SET_DUMPABLE op‐
          eration, and the description of the /proc/sys/fs/suid_dumpable file in proc(5).)

       *  /proc/sys/kernel/core_pattern is empty and /proc/sys/kernel/core_uses_pid contains the value 0.  (These files are described below.)  Note that if /proc/sys/kernel/core_pattern is empty and /proc/sys/kernel/core_uses_pid contains the value 1, core dump files will have names of the form .pid, and  such
          files are hidden unless one uses the ls(1) -a option.

       *  (Since Linux 3.7) The kernel was configured without the CONFIG_COREDUMP option.

       In addition, a core dump may exclude part of the address space of the process if the madvise(2) MADV_DONTDUMP flag was employed.

       On systems that employ systemd(1) as the init framework, core dumps may instead be placed in a location determined by systemd(1).  See below for further details.

   Naming of core dump files
       By default, a core dump file is named core, but the /proc/sys/kernel/core_pattern file (since Linux 2.6 and 2.4.21) can be set to define a template that is used to name core dump files.  The template can contain % specifiers which are substituted by the following values when a core file is created:

           %%  a single % character
           %c  core file size soft resource limit of crashing process (since Linux 2.6.24)
           %d  dump mode—same as value returned by prctl(2) PR_GET_DUMPABLE (since Linux 3.7)
           %e  executable filename (without path prefix)
           %E  pathname of executable, with slashes ('/') replaced by exclamation marks ('!') (since Linux 3.0).
           %g  (numeric) real GID of dumped process
           %h  hostname (same as nodename returned by uname(2))
           %i  TID of thread that triggered core dump, as seen in the PID namespace in which the thread resides (since Linux 3.18)
           %I  TID of thread that triggered core dump, as seen in the initial PID namespace (since Linux 3.18)
           %p  PID of dumped process, as seen in the PID namespace in which the process resides
           %P  PID of dumped process, as seen in the initial PID namespace (since Linux 3.12)
           %s  number of signal causing dump
           %t  time of dump, expressed as seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC)
           %u  (numeric) real UID of dumped process

       A single % at the end of the template is dropped from the core filename, as is the combination of a % followed by any character other than those listed above.  All other characters in the template become a literal part of the core filename.  The template may include '/' characters, which are interpreted
       as delimiters for directory names.  The maximum size of the resulting core filename is 128 bytes (64 bytes in kernels before 2.6.19).  The default value in this file is "core".  For backward compatibility, if /proc/sys/kernel/core_pattern does not include %p and /proc/sys/kernel/core_uses_pid  (see  be‐
       low) is nonzero, then .PID will be appended to the core filename.

       Paths are interpreted according to the settings that are active for the crashing process.  That means the crashing process's mount namespace (see mount_namespaces(7)), its current working directory (found via getcwd(2)), and its root directory (see chroot(2)).

       Since  version  2.4,  Linux  has also provided a more primitive method of controlling the name of the core dump file.  If the /proc/sys/kernel/core_uses_pid file contains the value 0, then a core dump file is simply named core.  If this file contains a nonzero value, then the core dump file includes the
       process ID in a name of the form core.PID.

       Since Linux 3.6, if /proc/sys/fs/suid_dumpable is set to 2 ("suidsafe"), the pattern must be either an absolute pathname (starting with a leading '/' character) or a pipe, as defined below.

   Piping core dumps to a program
       Since kernel 2.6.19, Linux supports an alternate syntax for the /proc/sys/kernel/core_pattern file.  If the first character of this file is a pipe symbol (|), then the remainder of the line is interpreted as the command-line for a user-space program (or script) that is to be executed.  Instead of  being
       written to a disk file, the core dump is given as standard input to the program.  Note the following points:

       *  The program must be specified using an absolute pathname (or a pathname relative to the root directory, /), and must immediately follow the '|' character.

       *  The command-line arguments can include any of the % specifiers listed above.  For example, to pass the PID of the process that is being dumped, specify %p in an argument.

       *  The process created to run the program runs as user and group root.

       *  Running as root does not confer any exceptional security bypasses.  Namely, LSMs (e.g., SELinux) are still active and may prevent the handler from accessing details about the crashed process via /proc/[pid].

       *  The program pathname is interpreted with respect to the initial mount namespace as it is always executed there.  It is not affected by the settings (e.g., root directory, mount namespace, current working directory) of the crashing process.

       *  The process runs in the initial namespaces (PID, mount, user, and so on) and not in the namespaces of the crashing process.  One can utilize specifiers such as %P to find the right /proc/[pid] directory and probe/enter the crashing process's namespaces if needed.

       *  The process starts with its current working directory as the root directory.  If desired, it is possible change to the working directory of the dumping process by employing the value provided by the %P specifier to change to the location of the dumping process via /proc/[pid]/cwd.

       *  Command-line arguments can be supplied to the program (since Linux 2.6.24), delimited by white space (up to a total line length of 128 bytes).

       *  The RLIMIT_CORE limit is not enforced for core dumps that are piped to a program via this mechanism.

   /proc/sys/kernel/core_pipe_limit
       When collecting core dumps via a pipe to a user-space program, it can be useful for the collecting program to gather data about the crashing process from that process's /proc/[pid] directory.  In order to do this safely, the kernel must wait for the program collecting the core dump to exit, so as not to
       remove the crashing process's /proc/[pid] files prematurely.  This in turn creates the possibility that a misbehaving collecting program can block the reaping of a crashed process by simply never exiting.

       Since Linux 2.6.32, the /proc/sys/kernel/core_pipe_limit can be used to defend against this possibility.  The value in this file defines how many concurrent crashing processes may be piped to user-space programs in parallel.  If this value is exceeded, then those crashing processes above this value  are
       noted in the kernel log and their core dumps are skipped.

       A value of 0 in this file is special.  It indicates that unlimited processes may be captured in parallel, but that no waiting will take place (i.e., the collecting program is not guaranteed access to /proc/<crashing-PID>).  The default value for this file is 0.

   Controlling which mappings are written to the core dump
       Since kernel 2.6.23, the Linux-specific /proc/[pid]/coredump_filter file can be used to control which memory segments are written to the core dump file in the event that a core dump is performed for the process with the corresponding process ID.

       The value in the file is a bit mask of memory mapping types (see mmap(2)).  If a bit is set in the mask, then memory mappings of the corresponding type are dumped; otherwise they are not dumped.  The bits in this file have the following meanings:

           bit 0  Dump anonymous private mappings.
           bit 1  Dump anonymous shared mappings.
           bit 2  Dump file-backed private mappings.
           bit 3  Dump file-backed shared mappings.
           bit 4 (since Linux 2.6.24)
                  Dump ELF headers.
           bit 5 (since Linux 2.6.28)
                  Dump private huge pages.
           bit 6 (since Linux 2.6.28)
                  Dump shared huge pages.
           bit 7 (since Linux 4.4)
                  Dump private DAX pages.
           bit 8 (since Linux 4.4)
                  Dump shared DAX pages.

       By default, the following bits are set: 0, 1, 4 (if the CONFIG_CORE_DUMP_DEFAULT_ELF_HEADERS kernel configuration option is enabled), and 5.  This default can be modified at boot time using the coredump_filter boot option.

       The value of this file is displayed in hexadecimal.  (The default value is thus displayed as 33.)

       Memory-mapped I/O pages such as frame buffer are never dumped, and virtual DSO pages are always dumped, regardless of the coredump_filter value.

       A child process created via fork(2) inherits its parent's coredump_filter value; the coredump_filter value is preserved across an execve(2).

       It can be useful to set coredump_filter in the parent shell before running a program, for example:

           $ echo 0x7 > /proc/self/coredump_filter
           $ ./some_program

       This file is provided only if the kernel was built with the CONFIG_ELF_CORE configuration option.

   Core dumps and systemd
       On  systems  using the systemd(1) init framework, core dumps may be placed in a location determined by systemd(1).  To do this, systemd(1) employs the core_pattern feature that allows piping core dumps to a program.  One can verify this by checking whether core dumps are being piped to the systemd-core‐
       dump(8) program:

           $ cat /proc/sys/kernel/core_pattern
           |/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %e

       In this case, core dumps will be placed in the location configured for systemd-coredump(8), typically as lz4(1) compressed files in the directory /var/lib/systemd/coredump/.  One can list the core dumps that have been recorded by systemd-coredump(8) using coredumpctl(1):

         $ coredumpctl list | tail -5
         Wed 2017-10-11 22:25:30 CEST  2748 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:29:10 CEST  2716 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:30:50 CEST  2767 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:37:40 CEST  2918 1000 1000 3 present  /usr/bin/cat
         Thu 2017-10-12 08:13:07 CEST  2955 1000 1000 3 present  /usr/bin/cat

       The information shown for each core dump includes the date and time of the dump, the PID, UID, and GID  of the dumping process, the signal number that caused the core dump, and the pathname of the executable that was being run by the dumped process.  Various options to coredumpctl(1) allow  a  specified
       coredump file to be pulled from the systemd(1) location into a specified file.  For example, to extract the core dump for PID 2955 shown above to a file named core in the current directory, one could use:

           $ coredumpctl dump 2955 -o core

       For more extensive details, see the coredumpctl(1) manual page.

       To disable the systemd(1) mechanism that archives core dumps, restoring to something more like traditional Linux behavior, one can set an override for the systemd(1) mechanism, using something like:

         # echo "kernel.core_pattern=core.%p" > /etc/sysctl.d/50-coredump.conf
         # /lib/systemd/systemd-sysctl

NOTES
       The gdb(1) gcore command can be used to obtain a core dump of a running process.

       In  Linux versions up to and including 2.6.27, if a multithreaded process (or, more precisely, a process that shares its memory with another process by being created with the CLONE_VM flag of clone(2)) dumps core, then the process ID is always appended to the core filename, unless the process ID was al‐
       ready included elsewhere in the filename via a %p specification in /proc/sys/kernel/core_pattern.  (This is primarily useful when employing the obsolete LinuxThreads implementation, where each thread of a process has a different PID.)

示例处理程序展示了pipe语法。

    $ cc -o core_pattern_pipe_test core_pattern_pipe_test.c
    $ su
    Password:
    # echo "|$PWD/core_pattern_pipe_test %p UID=%u GID=%g sig=%s" > \
        /proc/sys/kernel/core_pattern
    # exit
    $ sleep 100
    ^\                     # type control-backslash
    Quit (core dumped)

    $ cat core.info
    argc=5
    argc[0]=</to/work/core_pattern_pipe_test>
    argc[1]=<9272>
    argc[2]=<UID=1000>
    argc[3]=<GID=1000>
    argc[4]=<sig=3>
    Total bytes in core dump: 393216

示例处理程序源代码如下。

       /* core_pattern_pipe_test.c */

       #define _GNU_SOURCE
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <limits.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>

       #define BUF_SIZE 1024

       int
       main(int argc, char *argv[])
       {
           int tot, j;
           ssize_t nread;
           char buf[BUF_SIZE];
           FILE *fp;
           char cwd[PATH_MAX];

           /* Change our current working directory to that of the
              crashing process */

           snprintf(cwd, PATH_MAX, "/proc/%s/cwd", argv[1]);
           chdir(cwd);

           /* Write output to file "core.info" in that directory */

           fp = fopen("core.info", "w+");
           if (fp == NULL)
               exit(EXIT_FAILURE);

           /* Display command-line arguments given to core_pattern
              pipe program */

           fprintf(fp, "argc=%d\n", argc);
           for (j = 0; j < argc; j++)
               fprintf(fp, "argc[%d]=<%s>\n", j, argv[j]);

           /* Count bytes in standard input (the core dump) */

           tot = 0;
           while ((nread = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
               tot += nread;
           fprintf(fp, "Total bytes in core dump: %d\n", tot);

           fclose(fp);
           exit(EXIT_SUCCESS);
       }



```
$ coredumpctl list
TIME                            PID  UID  GID SIG     COREFILE EXE                              SIZE
Fri 2021-12-17 15:55:34 HKT    2228 1000 1000 SIGABRT missing  /usr/bin/zsh                      n/a
Fri 2021-12-17 15:55:36 HKT    2284 1000 1000 SIGABRT missing  /usr/bin/zsh                      n/a
Fri 2021-12-24 11:06:03 HKT 2541739 1000 1000 SIGSEGV missing  /usr/bin/gthumb                   n/a
Fri 2021-12-24 11:41:10 HKT 2545434 1000 1000 SIGSEGV missing  /usr/bin/gthumb                   n/a
Fri 2021-12-24 11:58:03 HKT 2570848 1000 1000 SIGSEGV missing  /usr/bin/gthumb                   n/a
Fri 2021-12-24 15:42:38 HKT 2691006 1000 1000 SIGSEGV missing  /usr/bin/gthumb                   n/a
Mon 2021-12-27 08:43:00 HKT  533914 1000 1000 SIGABRT missing  /aaron/cinelerra/bin/cinelerra    n/a
Mon 2021-12-27 08:54:04 HKT  546272 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 08:55:40 HKT  547396 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 08:59:07 HKT  548935 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 09:02:30 HKT  554398 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 09:04:19 HKT  556436 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 09:14:02 HKT  566188 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 09:18:05 HKT  556312 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 17:54:54 HKT  870319 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 17:54:57 HKT  870392 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 18:02:00 HKT  874204 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 18:02:04 HKT  874279 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 18:03:55 HKT  875593 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 18:03:59 HKT  875671 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 19:19:20 HKT  737953 1000 1000 SIGSEGV missing  /usr/bin/shotcut                  n/a
Tue 2021-12-28 19:24:28 HKT  391251 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Tue 2021-12-28 19:24:38 HKT  391430 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Tue 2021-12-28 19:30:05 HKT  393082 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Tue 2021-12-28 19:33:49 HKT  399301 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Wed 2021-12-29 22:29:21 HKT 1276878 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Wed 2021-12-29 22:30:08 HKT 1277461 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Thu 2021-12-30 09:16:25 HKT 1293884 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Thu 2021-12-30 09:17:01 HKT 1294264 1000 1000 SIGABRT present  /usr/lib/electron13/electron     4.2M
Thu 2021-12-30 09:17:16 HKT 1294416 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Thu 2021-12-30 21:47:33 HKT 1698150 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Thu 2021-12-30 21:48:01 HKT 1698536 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
```

```
$ coredumpctl info 391251
           PID: 391251 (chrome)
           UID: 1000 (aaron)
           GID: 1000 (aaron)
        Signal: 5 (TRAP)
     Timestamp: Tue 2021-12-28 19:24:27 HKT (2 days ago)
  Command Line: $'/opt/google/chrome/chrome --enable-crashpad https://www.reddit.com/message/messages/1z8yjhs?%24deep_link=true&correlation_id=f12bccd8-bfd6-4d0d-aea1-59fd8e4c1c4a&ref=email_private_message&ref_campaign=email_private_message&ref_source=email&%243p=e_as&_branch_match_id=1004333426649027454&utm_medium=Email%20Amazon%20SES&_branch_referrer=H4sIAA%2FVwOdP%2FGnaLa%2FvZdmEs%2FnJQui%2ByrAU9ui%2FD%2Bxb62%2BoAe2Nr7CGQEAAA%3D%3D'
    Executable: /opt/google/chrome/chrome
 Control Group: /user.slice/user-1000.slice/session-19.scope
          Unit: session-19.scope
         Slice: user-1000.slice
       Session: 19
     Owner UID: 1000 (aaron)
       Boot ID: 8d6d191c376472e88f1310212d123f67
    Machine ID: 6f96bd5861c64ff384d6b057b0677620
      Hostname: i54
       Storage: /var/lib/systemd/coredump/core.chrome.1000.8d6d819137647c2e8f1310212d12f673.391251.1640690667000000.zst (present)
     Disk Size: 2.0M
       Message: Process 391251 (chrome) of user 1000 dumped core.

                Module linux-vdso.so.1 with build-id d5b2c025831b6fe3cf78cde796e02920540c6291
                Module libbrotlicommon.so.1 with build-id a4ba3f4b4571c8272343b621da812a6e24a202a7
                Module libgpg-error.so.0 with build-id 3801187d42c4955bd93c605451430cdf1b164e63
                Module libbrotlidec.so.1 with build-id 45defc036e918e0140a72f1fbce6e7692d38241d
                Module libbz2.so.1.0 with build-id 919597c477c9b2cb9cdbb7745ed6494ac0e6da60
                Module libgraphite2.so.3 with build-id 47761dc11e553f519cde97ed9ee985be12ccdae2
                Module libdatrie.so.1 with build-id 6fe3b6ece2c8e7d11869fa051375128d8f808f58
                Module libgcrypt.so.20 with build-id db45f5d5e0f7af1e77324fea1885f974619ad268
                Module libcap.so.2 with build-id f56c6cd6ad4d35053340d7ff2f8f954498796739
                Module liblz4.so.1 with build-id e63600ab23b2f6997f42fac2fa56e1f02ce159a1
                Module libzstd.so.1 with build-id 4b10444c1560ebc574af4d5f488b7408b22d450e
                Module liblzma.so.5 with build-id 8b615460aa230708c5183f16bede67aa0437d95e
                Module librt.so.1 with build-id 75484da2d6f1515189eefa076e0a40328834cd16
                Module libblkid.so.1 with build-id f03a24e92c9852272bd0049b5bcb7ed6cf0e664f
                Module libgmp.so.10 with build-id e58d34ab389d1b649c24195c2d145e3ff2e58290
                Module libhogweed.so.6 with build-id 2d70cff7b1841b4d9ca4e8e7726cd4b944c07fdc
                Module libnettle.so.8 with build-id 9a878e513c02007598fcf1e2e286c2203f13536e
                Module libtasn1.so.6 with build-id ee3429ca5e94718aea4fe5249fc859e0cd88e4e9
                Module libunistring.so.2 with build-id 015ac6d6bcb60b7d8bea31a80d1941b06e8636ab
                Module libidn2.so.0 with build-id 1ce2b50ad9f9821c2c629b521cf5a3c99593d332
                Module libp11-kit.so.0 with build-id f97c44b297b54185bbe3eb6ed6dab5d8967f1532
                Module libXi.so.6 with build-id 16603be937a02a7e61b0b0395d064be7efd86f49
                Module libpixman-1.so.0 with build-id 341f793dcada3a48a306a793d265a517e3f2e7d6
                Module libxcb-shm.so.0 with build-id fb797f299a446f559a95afcc168227482cc800d1
                Module libxcb-render.so.0 with build-id a37bdb37744b508be9dd29fd9ccb9bb0170d43e5
                Module libfreetype.so.6 with build-id 26c5f833068ff72660d1975cbc2074c3eb47fad8
                Module libfontconfig.so.1 with build-id 1103a641395c7d3b42e49b793d3a9ea927c77bf6
                Module libpng16.so.16 with build-id 2dc0bce07f199bf983c07a05fb95a6f4af83a9b3
                Module libharfbuzz.so.0 with build-id 1d9dee49dd99162c3f83eb3259c3c88c6b4cd7fe
                Module libthai.so.0 with build-id a7ac5010b4275c49308021200d23690533952702
                Module libfribidi.so.0 with build-id 79124bad061c2aab4ec89f25d067363d5b781114
                Module libstdc++.so.6 with build-id 9b5eeeb149bf3c4efe787fb398b44f00507aec87
                Module libwayland-server.so.0 with build-id 645526447334b85a6f4bf5a8b37737b27696365f
                Module libXrender.so.1 with build-id 97e0b9ab6ba96ebc86527cc2b3c3078aad8616b3
                Module libXdmcp.so.6 with build-id 8ca0792d23c8b8b4c0864297512349292bea5955
                Module libXau.so.6 with build-id 1c67764663e07bec24d8951e5fd93f4d165979ff
                Module libsystemd.so.0 with build-id 5e0c342d74b444cce6793925b41760cf298c417c
                Module libresolv.so.2 with build-id c915c72668282861a813f7ea3c0780f37b681dc0
                Module libmount.so.1 with build-id ff9a1d99d35cf640d0bfdaba294854372672c29b
                Module libgmodule-2.0.so.0 with build-id 34cabbd12d9baf397a0255f174e4c96165bc329b
                Module libz.so.1 with build-id 81bf6e728a6d6f5b105b0f8b25f6c614ce10452a
                Module libgnutls.so.30 with build-id 8c87466eacaec0041a370df713d0fd200358c94c
                Module libavahi-client.so.3 with build-id 1858551543958190c653b565cf0eb64609ad908a
                Module libavahi-common.so.3 with build-id 80fda945459a3476ccd1050783dfd5f5c17c479a
                Module libplc4.so with build-id 44dcd42fb72cc8aab586dbf4000293590bb19e67
                Module libplds4.so with build-id e915f74a1aff6a20d65b5f03f5ee2e0197153a33
                Module libpcre.so.1 with build-id 845483dd0acba86de9f0313102bebbaf3ce52767
                Module libffi.so.8 with build-id f90d8b734f6de9b25faedb8cbfab7054dafc0a42
                Module ld-linux-x86-64.so.2 with build-id 040cc3dd10461562f177df39e3be2f3704258c3c
                Module libc.so.6 with build-id 4b406737057708c0e4c642345a703c47a61c73dc
                Module libgcc_s.so.1 with build-id 7f8508bb914546ada778809b64b99d234337d835
                Module libatspi.so.0 with build-id de251156cf6f2f447c5e2b8721bd913d79995d4f
                Module libasound.so.2 with build-id b17fc1317a484842433c772360376623b64ec3d8
                Module libcairo.so.2 with build-id 06820af9cf79c2deb207d9533a61caf04e67a8ad
                Module libpango-1.0.so.0 with build-id 730a8183a36afae82dd6a5564c0e490fed239a40
                Module libxkbcommon.so.0 with build-id 1f1bc7527e57c886c3df5803068122e1971d4724
                Module libgbm.so.1 with build-id 8f461cda076ab0774a933494486b094130da86df
                Module libXrandr.so.2 with build-id d4e869b5c72541e1de8f96b456248987ea52d51b
                Module libXfixes.so.3 with build-id 0a05c7e8714522bfbdd7c0027c3e2a94965664b0
                Module libXext.so.6 with build-id d70f24beb4fad748d6becffdcc13e51be0a2ebfa
                Module libXdamage.so.1 with build-id a1d867e093c16944b2c0083be98050ef35c9e5c2
                Module libXcomposite.so.1 with build-id f1bb5ffb6203ab2907ac044a204ce3902a79f1c1
                Module libX11.so.6 with build-id 5ba5798d193c0065014b8c6252a0678671c8d478
                Module libm.so.6 with build-id 2b8fd1f869ecab4e0b55e92f2f151897f6818acf
                Module libxcb.so.1 with build-id 0d1ef11740a5daad2ee331e812a51aa6574af222
                Module libexpat.so.1 with build-id 16023a53e7b5bbdff92bd0bf2eebd36f9b5b879f
                Module libdbus-1.so.3 with build-id 74f2ab9c60512f3a93c932c3f627564d42e0b11e
                Module libdrm.so.2 with build-id 457a1a1bd25f1d5541a10d3f16c5dc1440d77c7d
                Module libgio-2.0.so.0 with build-id fc7ccd9c7c26cbb1e938b1c0879f078c2f47d803
                Module libcups.so.2 with build-id 68a2ef2ccefd545e68b78c5acb20bcb2818c5049
                Module libatk-bridge-2.0.so.0 with build-id 1161ebbcc5aa791075dfa026671875e5417287bd
                Module libatk-1.0.so.0 with build-id aacaa40363d304858b654728a893bc212a4ca119
                Module libnspr4.so with build-id c5d12234f7975d11a11e67646533657d014d9540
                Module libsmime3.so with build-id caced12c534af7e258c29547a53aaf3c93a9501a
                Module libnssutil3.so with build-id 0762279c689e9de8745f0a4c120a1d8559f849c2
                Module libnss3.so with build-id ad8cd43ed62aba11f3b40eabb482516773dd9cbc
                Module libglib-2.0.so.0 with build-id 8214b56e554b7cbead4034b6ba32c90bc8c674da
                Module libgobject-2.0.so.0 with build-id 3e451709a0a5772b9550d3a4c28dcb37a87028fa
                Module libpthread.so.0 with build-id 07c8f95b4f3251d08550217ad8a1f31066229996
                Module libdl.so.2 with build-id 5abc547e7b0949f89f3c0e21ab0c8331a7440a8a
                Module chrome with build-id dc2f8d794740d875f9cc1b3ed2b6715b5975a6fa
                Stack trace of thread 391251:
                #0  0x0000557285b3f1e2 n/a (chrome + 0x41a41e2)
                #1  0x0000557285bc1171 n/a (chrome + 0x4226171)
                #2  0x0000557285bc106f n/a (chrome + 0x422606f)
                #3  0x0000557285bc09f0 n/a (chrome + 0x42259f0)
                #4  0x0000557285bc0539 n/a (chrome + 0x4225539)
                #5  0x00005572852ffe95 n/a (chrome + 0x3964e95)
                #6  0x00005572852ff6bd n/a (chrome + 0x39646bd)
                #7  0x00005572852f36a5 n/a (chrome + 0x39586a5)
                #8  0x00005572852bcc92 n/a (chrome + 0x3921c92)
                #9  0x00005572852b9e83 ChromeMain (chrome + 0x391ee83)
                #10 0x00007f14f70aeb25 __libc_start_main (libc.so.6 + 0x27b25)
                #11 0x000055728bdfff7a _start (chrome + 0xa464f7a)

                Stack trace of thread 391274:
                #0  0x00007f14f718592e epoll_wait (libc.so.6 + 0xfe92e)
                #1  0x0000557283babefb n/a (chrome + 0x2210efb)
                #2  0x0000557285311149 n/a (chrome + 0x3976149)
                #3  0x0000557285310f1f n/a (chrome + 0x3975f1f)
                #4  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #5  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #6  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #7  0x00005572853f9fed n/a (chrome + 0x3a5efed)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391272:
                #0  0x00007f14f7152a2f wait4 (libc.so.6 + 0xcba2f)
                #1  0x0000557285964ceb n/a (chrome + 0x3fc9ceb)
                #2  0x000055728871b878 n/a (chrome + 0x6d80878)
                #3  0x0000557285126363 n/a (chrome + 0x378b363)
                #4  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #5  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391277:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391278:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391281:
                #0  0x00007f14f717d201 __select (libc.so.6 + 0xf6201)
                #1  0x000055728871cc65 n/a (chrome + 0x6d81c65)
                #2  0x0000557285126363 n/a (chrome + 0x378b363)
                #3  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #4  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391280:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4fa0d n/a (chrome + 0x22b4a0d)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391275:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391276:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391273:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557288712d87 n/a (chrome + 0x6d77d87)
                #5  0x0000557288712f68 n/a (chrome + 0x6d77f68)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391264:
                #0  0x00007f14f717ab2f __poll (libc.so.6 + 0xf3b2f)
                #1  0x00005572843e07c3 n/a (chrome + 0x2a457c3)
                #2  0x0000557285126363 n/a (chrome + 0x378b363)
                #3  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #4  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391282:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31270 pthread_cond_wait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf270)
                #2  0x0000557283c50c65 n/a (chrome + 0x22b5c65)
                #3  0x000055728428557e n/a (chrome + 0x28ea57e)
                #4  0x00005572886f0862 n/a (chrome + 0x6d55862)
                #5  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #6  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #7  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391279:
                #0  0x00007f14f718592e epoll_wait (libc.so.6 + 0xfe92e)
                #1  0x0000557283babefb n/a (chrome + 0x2210efb)
                #2  0x0000557285311149 n/a (chrome + 0x3976149)
                #3  0x0000557285310e0a n/a (chrome + 0x3975e0a)
                #4  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #5  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #6  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #7  0x0000557286fc4052 n/a (chrome + 0x5629052)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)
                ELF object binary architecture: AMD x86-64
$ coredumpctl gdb 391251
```



The core dump files stored in /var/lib/systemd/coredump/ will be automatically
cleaned by systemd-tmpfiles --clean, which is triggered daily with
systemd-tmpfiles-clean.timer. Core dumps are configured to persist for at least
3 days, see systemd-tmpfiles --cat-config.


```

           PID: 391251 (chrome)
           UID: 1000 (aaron)
           GID: 1000 (aaron)
        Signal: 5 (TRAP)
     Timestamp: Tue 2021-12-28 19:24:27 HKT (2 days ago)
  Command Line: $'/opt/google/chrome/chrome --enable-crashpad https://www.reddit.com/message/messages/18zsjyh?%24deep_link=true&correlation_id=f12bdcc8-bdf6-4dd0-aae1-59fde841cc4a&ref=email_private_message&ref_campaign=email_private_message&ref_source=email&%243p=e_as&_branch_match_id=1004334326694027454&utm_medium=Email%20Amazon%20SES&_branch_referrer=H4sIAAAAAAAAA4WO3WrDMAxGn8a7S7LEbskGZRRKX8OolpJoc2IjOw3b09eB%2FVwOdPHx6RykKeeYXptGCJFzDTHWnpePRsc31RkdT2QhPZUYhEdewNtV%2FGnaLaXPqruW2bat%2FvZdmEsxU0ow0l9KJbb9V3r%2FnJQuikGiaPdDSl%2ByrAU9uiBCHjKHxTKWfmi7GzrXVzccjpVBfK4AqK0OLwNSb1rnDBRPaCgwzcDeRuE7ZLK%2FD%2Bxb62COwOPyD5bCKo5%2BoAe2Nr7CGQEAAA%3D%3D'
    Executable: /opt/google/chrome/chrome
 Control Group: /user.slice/user-1000.slice/session-19.scope
          Unit: session-19.scope
         Slice: user-1000.slice
       Session: 19
     Owner UID: 1000 (aaron)
       Boot ID: 8d6d8191c376472e8f1310212d123f67
    Machine ID: 6f96bd5861c64ff3b84d6b0570627760
      Hostname: i54
       Storage: /var/lib/systemd/coredump/core.chrome.1000.8d6d8191c376472e8f1310212d123f67.391251.1640690667000000.zst (present)
     Disk Size: 2.0M
       Message: Process 391251 (chrome) of user 1000 dumped core.

                Module linux-vdso.so.1 with build-id d5b2c025831b6fe3cf78cde796e02920540c6291
                Module libbrotlicommon.so.1 with build-id a4ba3f4b4571c8272343b621da812a6e24a202a7
                Module libgpg-error.so.0 with build-id 3801187d42c4955bd93c605451430cdf1b164e63
                Module libbrotlidec.so.1 with build-id 45defc036e918e0140a72f1fbce6e7692d38241d
                Module libbz2.so.1.0 with build-id 919597c477c9b2cb9cdbb7745ed6494ac0e6da60
                Module libgraphite2.so.3 with build-id 47761dc11e553f519cde97ed9ee985be12ccdae2
                Module libdatrie.so.1 with build-id 6fe3b6ece2c8e7d11869fa051375128d8f808f58
                Module libgcrypt.so.20 with build-id db45f5d5e0f7af1e77324fea1885f974619ad268
                Module libcap.so.2 with build-id f56c6cd6ad4d35053340d7ff2f8f954498796739
                Module liblz4.so.1 with build-id e63600ab23b2f6997f42fac2fa56e1f02ce159a1
                Module libzstd.so.1 with build-id 4b10444c1560ebc574af4d5f488b7408b22d450e
                Module liblzma.so.5 with build-id 8b615460aa230708c5183f16bede67aa0437d95e
                Module librt.so.1 with build-id 75484da2d6f1515189eefa076e0a40328834cd16
                Module libblkid.so.1 with build-id f03a24e92c9852272bd0049b5bcb7ed6cf0e664f
                Module libgmp.so.10 with build-id e58d34ab389d1b649c24195c2d145e3ff2e58290
                Module libhogweed.so.6 with build-id 2d70cff7b1841b4d9ca4e8e7726cd4b944c07fdc
                Module libnettle.so.8 with build-id 9a878e513c02007598fcf1e2e286c2203f13536e
                Module libtasn1.so.6 with build-id ee3429ca5e94718aea4fe5249fc859e0cd88e4e9
                Module libunistring.so.2 with build-id 015ac6d6bcb60b7d8bea31a80d1941b06e8636ab
                Module libidn2.so.0 with build-id 1ce2b50ad9f9821c2c629b521cf5a3c99593d332
                Module libp11-kit.so.0 with build-id f97c44b297b54185bbe3eb6ed6dab5d8967f1532
                Module libXi.so.6 with build-id 16603be937a02a7e61b0b0395d064be7efd86f49
                Module libpixman-1.so.0 with build-id 341f793dcada3a48a306a793d265a517e3f2e7d6
                Module libxcb-shm.so.0 with build-id fb797f299a446f559a95afcc168227482cc800d1
                Module libxcb-render.so.0 with build-id a37bdb37744b508be9dd29fd9ccb9bb0170d43e5
                Module libfreetype.so.6 with build-id 26c5f833068ff72660d1975cbc2074c3eb47fad8
                Module libfontconfig.so.1 with build-id 1103a641395c7d3b42e49b793d3a9ea927c77bf6
                Module libpng16.so.16 with build-id 2dc0bce07f199bf983c07a05fb95a6f4af83a9b3
                Module libharfbuzz.so.0 with build-id 1d9dee49dd99162c3f83eb3259c3c88c6b4cd7fe
                Module libthai.so.0 with build-id a7ac5010b4275c49308021200d23690533952702
                Module libfribidi.so.0 with build-id 79124bad061c2aab4ec89f25d067363d5b781114
                Module libstdc++.so.6 with build-id 9b5eeeb149bf3c4efe787fb398b44f00507aec87
                Module libwayland-server.so.0 with build-id 645526447334b85a6f4bf5a8b37737b27696365f
                Module libXrender.so.1 with build-id 97e0b9ab6ba96ebc86527cc2b3c3078aad8616b3
                Module libXdmcp.so.6 with build-id 8ca0792d23c8b8b4c0864297512349292bea5955
                Module libXau.so.6 with build-id 1c67764663e07bec24d8951e5fd93f4d165979ff
                Module libsystemd.so.0 with build-id 5e0c342d74b444cce6793925b41760cf298c417c
                Module libresolv.so.2 with build-id c915c72668282861a813f7ea3c0780f37b681dc0
                Module libmount.so.1 with build-id ff9a1d99d35cf640d0bfdaba294854372672c29b
                Module libgmodule-2.0.so.0 with build-id 34cabbd12d9baf397a0255f174e4c96165bc329b
                Module libz.so.1 with build-id 81bf6e728a6d6f5b105b0f8b25f6c614ce10452a
                Module libgnutls.so.30 with build-id 8c87466eacaec0041a370df713d0fd200358c94c
                Module libavahi-client.so.3 with build-id 1858551543958190c653b565cf0eb64609ad908a
                Module libavahi-common.so.3 with build-id 80fda945459a3476ccd1050783dfd5f5c17c479a
                Module libplc4.so with build-id 44dcd42fb72cc8aab586dbf4000293590bb19e67
                Module libplds4.so with build-id e915f74a1aff6a20d65b5f03f5ee2e0197153a33
                Module libpcre.so.1 with build-id 845483dd0acba86de9f0313102bebbaf3ce52767
                Module libffi.so.8 with build-id f90d8b734f6de9b25faedb8cbfab7054dafc0a42
                Module ld-linux-x86-64.so.2 with build-id 040cc3dd10461562f177df39e3be2f3704258c3c
                Module libc.so.6 with build-id 4b406737057708c0e4c642345a703c47a61c73dc
                Module libgcc_s.so.1 with build-id 7f8508bb914546ada778809b64b99d234337d835
                Module libatspi.so.0 with build-id de251156cf6f2f447c5e2b8721bd913d79995d4f
                Module libasound.so.2 with build-id b17fc1317a484842433c772360376623b64ec3d8
                Module libcairo.so.2 with build-id 06820af9cf79c2deb207d9533a61caf04e67a8ad
                Module libpango-1.0.so.0 with build-id 730a8183a36afae82dd6a5564c0e490fed239a40
                Module libxkbcommon.so.0 with build-id 1f1bc7527e57c886c3df5803068122e1971d4724
                Module libgbm.so.1 with build-id 8f461cda076ab0774a933494486b094130da86df
                Module libXrandr.so.2 with build-id d4e869b5c72541e1de8f96b456248987ea52d51b
                Module libXfixes.so.3 with build-id 0a05c7e8714522bfbdd7c0027c3e2a94965664b0
                Module libXext.so.6 with build-id d70f24beb4fad748d6becffdcc13e51be0a2ebfa
                Module libXdamage.so.1 with build-id a1d867e093c16944b2c0083be98050ef35c9e5c2
                Module libXcomposite.so.1 with build-id f1bb5ffb6203ab2907ac044a204ce3902a79f1c1
                Module libX11.so.6 with build-id 5ba5798d193c0065014b8c6252a0678671c8d478
                Module libm.so.6 with build-id 2b8fd1f869ecab4e0b55e92f2f151897f6818acf
                Module libxcb.so.1 with build-id 0d1ef11740a5daad2ee331e812a51aa6574af222
                Module libexpat.so.1 with build-id 16023a53e7b5bbdff92bd0bf2eebd36f9b5b879f
                Module libdbus-1.so.3 with build-id 74f2ab9c60512f3a93c932c3f627564d42e0b11e
                Module libdrm.so.2 with build-id 457a1a1bd25f1d5541a10d3f16c5dc1440d77c7d
                Module libgio-2.0.so.0 with build-id fc7ccd9c7c26cbb1e938b1c0879f078c2f47d803
                Module libcups.so.2 with build-id 68a2ef2ccefd545e68b78c5acb20bcb2818c5049
                Module libatk-bridge-2.0.so.0 with build-id 1161ebbcc5aa791075dfa026671875e5417287bd
                Module libatk-1.0.so.0 with build-id aacaa40363d304858b654728a893bc212a4ca119
                Module libnspr4.so with build-id c5d12234f7975d11a11e67646533657d014d9540
                Module libsmime3.so with build-id caced12c534af7e258c29547a53aaf3c93a9501a
                Module libnssutil3.so with build-id 0762279c689e9de8745f0a4c120a1d8559f849c2
                Module libnss3.so with build-id ad8cd43ed62aba11f3b40eabb482516773dd9cbc
                Module libglib-2.0.so.0 with build-id 8214b56e554b7cbead4034b6ba32c90bc8c674da
                Module libgobject-2.0.so.0 with build-id 3e451709a0a5772b9550d3a4c28dcb37a87028fa
                Module libpthread.so.0 with build-id 07c8f95b4f3251d08550217ad8a1f31066229996
                Module libdl.so.2 with build-id 5abc547e7b0949f89f3c0e21ab0c8331a7440a8a
                Module chrome with build-id dc2f8d794740d875f9cc1b3ed2b6715b5975a6fa
                Stack trace of thread 391251:
                #0  0x0000557285b3f1e2 n/a (chrome + 0x41a41e2)
                #1  0x0000557285bc1171 n/a (chrome + 0x4226171)
                #2  0x0000557285bc106f n/a (chrome + 0x422606f)
                #3  0x0000557285bc09f0 n/a (chrome + 0x42259f0)
                #4  0x0000557285bc0539 n/a (chrome + 0x4225539)
                #5  0x00005572852ffe95 n/a (chrome + 0x3964e95)
                #6  0x00005572852ff6bd n/a (chrome + 0x39646bd)
                #7  0x00005572852f36a5 n/a (chrome + 0x39586a5)
                #8  0x00005572852bcc92 n/a (chrome + 0x3921c92)
                #9  0x00005572852b9e83 ChromeMain (chrome + 0x391ee83)
                #10 0x00007f14f70aeb25 __libc_start_main (libc.so.6 + 0x27b25)
                #11 0x000055728bdfff7a _start (chrome + 0xa464f7a)

                Stack trace of thread 391274:
                #0  0x00007f14f718592e epoll_wait (libc.so.6 + 0xfe92e)
                #1  0x0000557283babefb n/a (chrome + 0x2210efb)
                #2  0x0000557285311149 n/a (chrome + 0x3976149)
                #3  0x0000557285310f1f n/a (chrome + 0x3975f1f)
                #4  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #5  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #6  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #7  0x00005572853f9fed n/a (chrome + 0x3a5efed)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391272:
                #0  0x00007f14f7152a2f wait4 (libc.so.6 + 0xcba2f)
                #1  0x0000557285964ceb n/a (chrome + 0x3fc9ceb)
                #2  0x000055728871b878 n/a (chrome + 0x6d80878)
                #3  0x0000557285126363 n/a (chrome + 0x378b363)
                #4  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #5  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391277:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391278:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391281:
                #0  0x00007f14f717d201 __select (libc.so.6 + 0xf6201)
                #1  0x000055728871cc65 n/a (chrome + 0x6d81c65)
                #2  0x0000557285126363 n/a (chrome + 0x378b363)
                #3  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #4  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391280:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4fa0d n/a (chrome + 0x22b4a0d)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391275:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391276:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391273:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557288712d87 n/a (chrome + 0x6d77d87)
                #5  0x0000557288712f68 n/a (chrome + 0x6d77f68)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391264:
                #0  0x00007f14f717ab2f __poll (libc.so.6 + 0xf3b2f)
                #1  0x00005572843e07c3 n/a (chrome + 0x2a457c3)
                #2  0x0000557285126363 n/a (chrome + 0x378b363)
                #3  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #4  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391282:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31270 pthread_cond_wait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf270)
                #2  0x0000557283c50c65 n/a (chrome + 0x22b5c65)
                #3  0x000055728428557e n/a (chrome + 0x28ea57e)
                #4  0x00005572886f0862 n/a (chrome + 0x6d55862)
                #5  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #6  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #7  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391279:
                #0  0x00007f14f718592e epoll_wait (libc.so.6 + 0xfe92e)
                #1  0x0000557283babefb n/a (chrome + 0x2210efb)
                #2  0x0000557285311149 n/a (chrome + 0x3976149)
                #3  0x0000557285310e0a n/a (chrome + 0x3975e0a)
                #4  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #5  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #6  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #7  0x0000557286fc4052 n/a (chrome + 0x5629052)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)
                ELF object binary architecture: AMD x86-64

GNU gdb (GDB) 11.1
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-pc-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from /opt/google/chrome/chrome...
(No debugging symbols found in /opt/google/chrome/chrome)

warning: Can't open file /usr/lib/libzstd.so.1.5.0 during file-backed mapping note processing
[New LWP 391251]
[New LWP 391274]
[New LWP 391272]
[New LWP 391277]
[New LWP 391278]
[New LWP 391281]
[New LWP 391280]
[New LWP 391275]
[New LWP 391276]
[New LWP 391273]
[New LWP 391264]
[New LWP 391282]
[New LWP 391279]

warning: .dynamic section for "/usr/lib/libzstd.so.1" is not at the expected address (wrong library or version mismatch?)
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
Core was generated by `/opt/google/chrome/chrome --enable-crashpad https://www.reddit.com/message/mess'.
Program terminated with signal SIGTRAP, Trace/breakpoint trap.
#0  0x0000557285b3f1e2 in ?? ()
[Current thread is 1 (Thread 0x7f14f5f18cc0 (LWP 391251))]
(gdb) bt
#0  0x0000557285b3f1e2 in  ()
#1  0x000055728c5e9088 in  ()
#2  0x00007ffd6a14d868 in  ()
#3  0x00001e66000842c0 in  ()
#4  0xaaaaaaaaaaaaaaaa in  ()
#5  0x00007ffd6a14d850 in  ()
#6  0x0000557285bc1171 in  ()
#7  0x00000000ffffff00 in  ()
#8  0x00001e6600144600 in  ()
#9  0x00007ffd6a14d880 in  ()
#10 0x0000557285bc106f in  ()
#11 0x00007ffd6a14d8d0 in  ()
#12 0x0000557285000000 in  ()
#13 0x00001e660051a040 in  ()
#14 0x00001e6600558000 in  ()
#15 0x00007ffd6a14d8d0 in  ()
#16 0x0000557285bc09f0 in  ()
#17 0x00001e660051a040 in  ()
#18 0xaaaaaaaaaaaaaaaa in  ()
#19 0x0000000000000000 in  ()
(gdb)

```
systemd, add the following setting in /etc/systemd/system.conf and run systemctl daemon-reexec.
Raw
DefaultLimitCORE=infinity
Now, add the below sysctl parameters.
Raw
fs.suid_dumpable=2
Raw
# sysctl -p

## What is a core file?
A core file is an image of a process that has crashed It contains all process information pertinent to debugging: contents of hardware registers, process status, and process data. Gdb will allow you use this file to determine where your program crashed.


When it starts up, you can use bt (for backtrace) to get a stack trace from the time of the crash. In the backtrace, each function invocation is given a number. You can use frame number (replacing number with the corresponding number in the stack trace) to select a particular stack frame.

You can then use list to see code around that function, and info locals to see the local variables. You can also use print name_of_variable (replacing "name_of_variable" with a variable name) to see its value.


## VSCODE

The C/C++ extension for VS Code also has the ability to debug memory dumps. To debug a memory dump, open your launch.json file and add the coreDumpPath (for GDB or LLDB) or dumpPath (for the Visual Studio Windows Debugger) property to the C++ Launch configuration, set its value to be a string containing the path to the memory dump. This will even work for x86 programs being debugged on an x64 machine.



##
The last line that gdb will print before the "(gdb)" prompt will be something like:

#0 0xef607e54 in main() at line 344 in main.cpp
This corresponds to the last statement that was attempted which likely caused the crash.
You can find out which function called the current function by using the "up" command which will print out a similar line. The "down" command does the opposite of the "up" command. Finally, to view the entire stack frame, use the "backtrace" command or it's abbreviation "bt".



#BFD库可以用来读取核心转储的结构化数据。
The BFD library can be used to read the structured data out of a core dump.



# Core Dumps on CPU Signals
Preconditions
Make sure the Linux kernel has the needed configuration options set as we don't enable these by default. Check and if needed recompile the kernel with enabled core dump options.

Check for 3.0, 3.1 kernels:

zcat /proc/config.gz | grep CONFIG_ELF_CORE
Check for 3.7 and later kernels:

zcat /proc/config.gz | grep CONFIG_COREDUMP
Enabling Core Dumps
The following enables core dump generation when a user process triggers a signal and sets the core file location to /tmp/ with a sensible name. Note that these settings aren't stored persistently.

ulimit -c unlimited
echo 1 > /proc/sys/kernel/core_uses_pid
echo "/tmp/core-%e-%s-%u-%g-%p-%t" > /proc/sys/kernel/core_pattern
Should you run an executable with 'suid' or 'guid' rights you also need the following:

echo 2 > /proc/sys/fs/suid_dumpable
Note: Depending on the memory usage of a process core files can be huge. Enabling core dumps on a system can fill up its mass storage over time. To enable core dumps on production systems it is highly recommended to use a daemon to manage the core dumps (e.g. make sure that the core dumps do not use more than a certain amount of space). Systemd might be a viable solution for this, however the coredump functionality is not enabled by default in OpenEmbedded (see recipes-core/systemd/systemd_xxx.bb in OpenEmbedded core).

Trigger a Core Dump
To test the creation of core dumps, one can use the kill command to send a segmentation fault signal to the process:

kill -11 [PID]
Or alternatively using killall which also allows to use the signal name:

killall -SIGSEGV firefox
Create a Core Dump of a Running Application
To create a single core dump without provoking an abnormal process termination the utility gcore can be used.

This allows to create a core dump at any time of execution. The utility gcore is part of gdb, one can install it using the package feeds:

opkg install gdb
Use gcore with the process ID as argument to create a core dump of a user process.

# gcore -o /tmp/core-myapp 280
0x76f46588 in read () from /lib/libc.so.6
Saved corefile /tmp/core-myapp.280
Analysing Core Dumps
A cross gdb can be used to analyse a core file. Additionally to the core dump gdb needs the executable and all linked static object files. One can use the OpenEmbedded built cross gdb and the target sysroot for that.

Copy the core file to your development PC into the OpenEmbedded sysroot and use gdb to do the analysis:

In oe-core/build/out-glibc/sysroot/colibri-t30:

../x86_64-linux/usr/bin/armv7ahf-vfp-neon-angstrom-linux-gnueabi/arm-angstrom-linux-gnueabi-gdb -ex 'set sysroot .' -ex 'core-file ./core-firefox-4-0-0-596-1402701200' usr/lib/firefox/firefox



## what’s a segfault?
A “segmentation fault” is when your program tries to access memory that it’s not allowed to access, or tries to . This can be caused by:

trying to dereference a null pointer (you’re not allowed to access the memory address 0)
trying to dereference some other pointer that isn’t in your memory
a C++ vtable pointer that got corrupted and is pointing to the wrong place, which causes the program to try to execute some memory that isn’t executable

## valgrind
I found the easiest way to figure out why my program is segfaulting was to use valgrind: I ran

valgrind -v your-program
and this gave me a stack trace of what happened. Neat!

But I also wanted to do a more in-depth investigation and find out more than just what valgrind was telling me! So I wanted to get a core dump and explore it.

How to get a core dump
A core dump is a copy of your program’s memory, and it’s useful when you’re trying to debug what went wrong with your problematic program.

When your program segfaults, the Linux kernel will sometimes write a core dump to disk. When I originally tried to get a core dump, I was pretty frustrated for a long time because – Linux wasn’t writing a core dump!! Where was my core dump????

Here’s what I ended up doing:

Run ulimit -c unlimited before starting my program
Run sudo sysctl -w kernel.core_pattern=/tmp/core-%e.%p.%h.%t
ulimit: set the max size of a core dump
ulimit -c sets the maximum size of a core dump. It’s often set to 0, which means that the kernel won’t write core dumps at all. It’s in kilobytes. ulimits are per process – you can see a process’s limits by running cat /proc/PID/limit

For example these are the limits for a random Firefox process on my system:

$ cat /proc/6309/limits

The kernel uses the soft limit (in this case, “max core file size = 0”) when deciding how big of a core file to write. You can increase the soft limit up to the hard limit using the ulimit shell builtin (ulimit -c unlimited!)

kernel.core_pattern: where core dumps are written
kernel.core_pattern is a kernel parameter or a “sysctl setting” that controls where the Linux kernel writes core dumps to disk.

Kernel parameters are a way to set global settings on your system. You can get a list of every kernel parameter by running sysctl -a, or use sysctl kernel.core_pattern to look at the kernel.core_pattern setting specifically.

So sysctl -w kernel.core_pattern=/tmp/core-%e.%p.%h.%t will write core dumps to /tmp/core-<a bunch of stuff identifying the process>

If you want to know more about what these %e, %p parameters read, see man core.

It’s important to know that kernel.core_pattern is a global settings – it’s good to be a little careful about changing it because it’s possible that other systems depend on it being set a certain way.

kernel.core_pattern & Ubuntu
By default on Ubuntu systems, this is what kernel.core_pattern is set to

$ sysctl kernel.core_pattern
kernel.core_pattern = |/usr/share/apport/apport %p %s %c %d %P
This caused me a lot of confusion (what is this apport thing and what is it doing with my core dumps??) so here’s what I learned about this:

Ubuntu uses a system called “apport” to report crashes in apt packages
Setting kernel.core_pattern=|/usr/share/apport/apport %p %s %c %d %P means that core dumps will be piped to apport
apport has logs in /var/log/apport.log
apport by default will ignore crashes from binaries that aren’t part of an Ubuntu packages
I ended up just overriding this Apport business and setting kernel.core_pattern to sysctl -w kernel.core_pattern=/tmp/core-%e.%p.%h.%t because I was on a dev machine, I didn’t care whether Apport was working on not, and I didn’t feel like trying to convince Apport to give me my core dumps.

So you have a core dump. Now what?
Okay, now we know about ulimits and kernel.core_pattern and you have actually have a core dump file on disk in /tmp. Amazing! Now what??? We still don’t know why the program segfaulted!

The next step is to open the core file with gdb and get a backtrace.

Getting a backtrace from gdb
You can open a core file with gdb like this:

$ gdb -c my_core_file
Next, we want to know what the stack was when the program crashed. Running bt at the gdb prompt will give you a backtrace. In my case gdb hadn’t loaded symbols for the binary, so it was just like ??????. Luckily, loading symbols fixed it.

Here’s how to load debugging symbols.

symbol-file /path/to/my/binary
sharedlibrary
This loads symbols from the binary and from any shared libraries the binary uses. Once I did that, gdb gave me a beautiful stack trace with line numbers when I ran bt!!!

If you want this to work, the binary should be compiled with debugging symbols. Having line numbers in your stack traces is extremely helpful when trying to figure out why a program crashed :)

look at the stack for every thread
Here’s how to get the stack for every thread in gdb!

thread apply all bt full

## args

the core file contains the CLI arguments, no need to pass it again



If you want to use gdb without your core, consider

gdb --args ./my_prog arg
or else run just gdb ./my_prog then issue the set args command to gdb.

If your process is still running as pid 1234, you could with gdb ./my_prog 1234 attach the gdb to the running process.


#

the core file contains, among other things, the full stack and heap memory allocated.

Shouldn't that be pretty much constant for such a simple program (give or take a few bytes at the most), hence producing a consistent core between multiple instances?



4096 is the virtual memory page size. When the core dump is created, all of the vm pages assigned to the process will be dumped to the core file. The smaller file is 2933 pages, and the larger file is 2934 pages. So that's fairly consistent. – user3386109 Aug 1 '15 at 19:42





The programs got so large because they were not allocating physical memory, just virtual memory. When GLIBC's malloc() is given a large amount of memory to allocate it request to do so in another virtual memory page from the kernel. For some reason the core file is writing all of the memory, including bytes that never physically existed (this is weird since files in Linux with most file systems can leave file holes). – Veltas Aug 5 '15 at 23:33

- http://stackoverflow.com/questions/13982478/what-is-file-hole-and-how-can-it-be-used




----

The implementation of core dumping can be found in fs/binfmt_elf.c. I'll follow the code in 3.12 and above (it changed with commit 9b56d5438) but the logic is very similar.



The code initially decides how much to dump of a VMA (virtual memory area) in vma_dump_size. For an anonymous VMA such as the brk heap, it returns the full size of the VMA. During this step, the core limit is not involved.

好！

The first phase of writing the core dump then writes a PT_LOAD header for each VMA. This is basically a pointer that says where to find the data in the remainder of the ELF file. The actual data is written by a for loop, and is actually a second phase.



###



 dumped when the appropriate signal it triggered. To get the best results, we’d set the core file size limit everywhere to unlimited and be done with it, but what if you want to limit that to a certain size? I stumble to a small confusion lately when doing this for MySQL, so let me share quickly.

 First, for MySQL, mysqld_safe would use ulimit to set the core-file-size value you pass to it. Now remember according to the manual, this value should be in blocks (some documentation says its in chunks of 1024 bytes). However, according to my experience on CentOS 6, this is the physical block size of the device where your core_pattern is pointed to.
 [root@centos6 ~]# ulimit -a
 ...
 core file size          (blocks, -c) 0

 [root@centos6 ~]# cat /proc/sys/kernel/core_pattern
 /var/tmp/core


 $ cat /proc/sys/kernel/core_pattern
 |/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %h

 $ ll /var/lib/systemd/coredump/
 -rw-r-----+ 1 root root  3932881 Mar 18 19:16 core.offlineimap.1000.455227dc8b2b42969381aa81befa0fa1.13167.1584530161000000000000.lz4
 -rw-r-----+ 1 root root  3926468 Mar 20 08:14 core.offlineimap.1000.455227dc8b2b42969381aa81befa0fa1.549046.1584663241000000000000.lz4
 -rw-r-----+ 1 root root  1899617 Mar 18 16:44 core.pcmanfm.1000.455227dc8b2b42969381aa81befa0fa1.4629.1584521082000000000000.lz4
 -rw-r-----+ 1 root root 64522221 Mar 19 18:10 core.thunderbird.1000.455227dc8b2b42969381aa81befa0fa1.223214.1584612639000000000000.lz4



 [root@centos6 ~]# blockdev --getbsz /dev/sda2
 4096
 [root@centos6 ~]# blockdev --getpbsz /dev/sda2
 512
 1
 2
 3
 4
 5
 6
 7
 8
 9
 10
 11

  [root@centos6 ~]# ulimit -a
  ...
  core file size          (blocks, -c) 0

   [root@centos6 ~]# cat /proc/sys/kernel/core_pattern
   /var/tmp/core

    [root@centos6 ~]# blockdev --getbsz /dev/sda2
    4096
    [root@centos6 ~]# blockdev --getpbsz /dev/sda2
    512

    Based on the above, my core_pattern point to /var, which sits on sda2. This partition according to blockdev has a filesystem blocksize of 4K and a physical block size of 512B. Putting this to the test, say I configure MySQL to a core file size ulimit of 10240, then I would get:
    [root@centos6 ~]# cat /proc/`pidof mysqld`/limits
    Limit                     Soft Limit           Hard Limit           Units
    ...
    Max core file size        5242880              5242880              bytes
    1
    2
    3
    4

      [root@centos6 ~]# cat /proc/`pidof mysqld`/limits
      Limit                     Soft Limit           Hard Limit           Units
      ...
      Max core file size        5242880              5242880              bytes


# Core dump
A core dump is a file containing a process's address space (memory) when the process terminates unexpectedly. Core dumps may be produced on-demand (such as by a debugger), or automatically upon termination.

Core dumps are triggered by the kernel in response to program crashes, and may be passed to a helper program (such as systemd-coredump) for further processing.

# Disable setuid processes dumping their memory

The behavior can be altered with a sysctl key, or directly via the /proc file system.

For permanent settings, the sysctl command and configuration is typically used. A setting is called a ‘key’, which has a related value attached to it (also known as a key-value pair).

To disable program with the setuid bit to dump, set the fs.suid_dumpable to zero.

    echo `fs.suid_dumpable=0` >> /etc/sysctl.conf

Reload the sysctl configuration with the -p flag to activate any changes you made.

    sysctl -p

Just want to test without making permanent changes? Use sysctl -w followed by the key=value.

# Enable Core Dumps

The -c denotes the size of a core dump. `-S` for soft limit.

    ulimit -S -c 0

Allow all processes to use core dumps

    ulimit -S -c unlimited

Set system limit in /etc/security/limits.conf

    * soft core unlimited

# Disable Core Dumps
To disable core dumps for all users, edit /etc/security/limits.conf

    * hard core 0

Save and close the file. Once a hard limit is set, user cannot increase that limit within his own session.

    # echo 'fs.suid_dumpable = 0' >> /etc/sysctl.conf
    # sysctl -p

This will make sure that core dumps can never be made by setuid programs. Finally, add the following to /etc/profile to set a soft limit to stop the creation of core dump files for all users (which is default and must be disabled):

    # echo 'ulimit -S -c 0 > /dev/null 2>&1' >> /etc/profile

- sysctl fs.suid_dumpable key values

    0 - disabled
    1 - enabled
    2 - enabled with restrictions

## configure ulimit via profile
The values for ulimit can also be set via /etc/profile or a custom file in the /etc/profile.d directory. The latter is preferred when it is available. For example by creating a file named /etc/profile.d/disable-coredumps.sh.

    echo “ulimit -c 0 > /dev/null 2>&1` > /etc/profile.d/disable-coredumps.sh

This command adds the setting to a new file and sets both the soft and hard limit to zero. Each user gets this value when logging in.

# Steps to Reproduce
1. journalctl -f
2. systemctl start systemd-hostnamed
3. pkill -e -SEGV systemd-hostnam

Actual results:

journal shows no backtrace and coredumpctl shows no coredump.

Expected results:

Journal shows something like `Process 3271 (systemd-hostnam) of user 0 dumped core.` and a backtrace.


Additional info:

 * This works for `default namespace` processes, like so:
   sleep 100 &
   pkill -e -SEGV sleep
   Then you get a core dump.

 * This works once you disable SELinux (setenforce 0). However, there are no SELinux violations logged.

 * This is not dependent on systemd-coredump. You can do
```

# cat <<EOF > /tmp/core.sh
#!/bin/sh
echo `invoked core dump: $@` >> /tmp/log
cat > /tmp/core
echo `invoked core dump: $@ DONE` >> /tmp/log
EOF
# chmod 755 /tmp/core.sh
# echo `|/tmp/core.sh %P %u` > /proc/sys/kernel/core_pattern

```

# Create normal dump files
This particular setting is done via the sysctl kernel.core_pattern setting or /proc/sys/kernel/core_pattern. Most systems will have a pipe (|) in this setting to indicate that a program needs to take care of the generated data.

You can temporarily change this setting, by echoing `core` to that file, or use the sysctl utility.

    sysctl -w kernel.core_pattern=core

An important note is that this change might not be enough. It depends also on your fs.suid_dumpable setting. A warning will be logged to your kernel logger if that is the case.

> Sep 06 15:51:18 hardening kernel: Unsafe core_pattern used with suid_dumpable=2. Pipe handler or fully qualified core dump path required.

When needed set your core_pattern to a full path, optionally with variables defining who was running it, the PID, etc.

    sysctl -w kernel.core_pattern=/var/crash/core.%u.%e.%p

In this example, our dumps will contain the user id, program name, and process id.

# Change the way the core dump is written

Subsequent core dumps overwrite the previous instead of creating a new file.

Add these lines to /etc/sysctl.conf:

```
kernel.core_uses_pid = 0
kernel.core_pattern = core
```
And run sysctl -p.

Now the core dumps will be named simply core.

# Disable automatic core dumps
Users may wish to disable automatic core dumps for a number of reasons:

  - Performance: generating core dumps for memory-heavy processes can
    waste system resources and delay the cleanup of memory.
  - Disk space: core dumps of memory-heavy processes may consume disk
    space equal to, if not greater, than the process's memory footprint
    if not compressed.
  - Security: core dumps, although typically readable only by root, may
    contain sensitive data (such as passwords or cryptographic keys),
    which are written to disk following a crash.

## Using sysctl

`sysctl` can be used to set the `kernel.core_pattern` to nothing to disable core dump handling.

    cat /etc/sysctl.d/50-coredump.conf
    kernel.core_pattern=|!/bin/false

To apply the setting immediately:

    # sysctl -p /etc/sysctl.d/50-coredump.conf

- https://github.com/systemd/systemd/issues/659#issuecomment-328372788

## Using ulimit

The maximum core dump size is enforced by ulimit. Setting it to zero
disables core dumps entirely.

    cat /etc/security/limits.conf
    * hard core 0

## Using systemd
systemd by default is to generate core dumps for all processes in `/var/lib/systemd/coredump`.

This behavior can be overridden by creating a configuration snippet in the `/etc/systemd/coredump.conf.d/`

Set the Storage setting to ‘none’. Then configure ProcessSizeMax to limited the maximum size to zero.

    cat /etc/systemd/coredump.conf.d/custom.conf
    [[Coredump]]
    Storage=none
    ProcessSizeMax=0

Don't forget to include the `Coredump` section name, otherwise this option will be ignored

    $ sudo systemctl daemon-reload

You might need to override settings via /etc/sysctl.d/50-coredump.conf and define how and where you want to store your core dumps.

This method alone is usually sufficient to disable userspace core dumps,
so long as no other programs enable automatic core dumps on the system,
but the coredump is still generated in memory and systemd-coredump run.

# Systemd core dumps
## Core dump control in `systemd`
Put into `service` file.

    LimitCORE=infinity

When using systemd and the systemd-coredump service, change the coredump.conf file. This file is most likely located at /usr/lib/sysctl.d/50-coredump.conf. As systemd has a set of files, ensure to check the others like:

    /etc/systemd/coredump.conf
    /etc/systemd/coredump.conf.d/*.conf
    /run/systemd/coredump.conf.d/*.conf
    /usr/lib/systemd/coredump.conf.d/*.conf

```
cat /etc/systemd/coredump.conf
#  This file is part of systemd.
#
#  systemd is free software; you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; either version 2.1 of the License, or
#  (at your option) any later version.
#
# Entries in this file show the compile time defaults.
# You can change settings by editing this file.
# Defaults can be restored by simply deleting this file.
#
# See coredump.conf(5) for details.

[Coredump]
#Storage=external
#Compress=yes
#ProcessSizeMax=2G
#ExternalSizeMax=2G
#JournalSizeMax=767M
#MaxUse=
#KeepFree=
```

```
$ sudo apt install systemd-coredump
$ dpkg -L systemd-coredump | grep conf
    /etc/systemd/coredump.conf
    /usr/lib/sysctl.d/50-coredump.conf
    /usr/share/man/man5/coredump.conf.5.gz
    /usr/share/man/man5/coredump.conf.d.5.gz
```

## coredump.conf

```
cat /usr/lib/sysctl.d/50-coredump.conf
#  This file is part of systemd.
#
#  systemd is free software; you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; either version 2.1 of the License, or
#  (at your option) any later version.

# See sysctl.d(5) for the description of the files in this directory,
# and systemd-coredump(8) and core(5) for the explanation of the
# setting below.

kernel.core_pattern=|/lib/systemd/systemd-coredump %P %u %g %s %t 9223372036854775808 %h %e
```

- P: Process name
- u: UID
- g: Boot ID
- s: pid
- t: Time
- e: Ext

The default set might send all core dumps to journald as part of the system logs.

# Making a core dump

## kill a running process by SIGSEGV
SIGSEGV is short for segmentation violation and also known as a segmentation fault.

    kill -s SIGSEGV PID

If you replace PID with “$$` the current program (most likely your shell) will crash.

## Use `gdb`
Attach to the process:

    $ gdb -p 2071

    (gdb) generate-core-file
    Saved corefile core.2071
    (gdb) quit

The `kernel.core_pattern` `sysctl` decides where automatic core dumps go.

    $ cat /proc/sys/kernel/core_pattern
    |/usr/lib/systemd/systemd-coredump %p %u %g %s %t %e

    $ cat /proc/sys/kernel/core_pattern
    |/lib/systemd/systemd-coredump %P %u %g %s %t 9223372036854775808 %h %e

**Note**

If you do not have full-disk encryption, this means your program's memory will be written to raw disk! This is a potential information leak even if you have encrypted swap.

# Examining a core dump

Use *coredumpctl* to find the corresponding dump:

    # coredumpctl list

    TIME                            PID   UID   GID SIG COREFILE  EXE
    Mon 2018-08-13 17:04:29 CST     322  1000  1000   8 present   /path/to/as/a.out
    `
    Tue 2018-11-27 08:53:15 CST    9762  1000  1000  11 missing   /usr/bin/sogou-qimpanel


    'core.a\x2eout.1000.9842428dbdab46be81201ba3044c75e3.322.1534151068000000.lz4'

You need to uniquely identify the relevant dump. This is possible by specifying a `PID`, name of the executable, path to the executable or a journalctl predicate.

    # coredumpctl info $PID

               PID: 322 (a.out)
               UID: 1000 (as)
               GID: 1000 (as)
            Signal: 8 (FPE)
         Timestamp: Mon 2018-08-13 17:04:28 CST (2min 41s ago)
      Command Line: ./a.out
        Executable: /path/to/as/a.out
     Control Group: /user.slice/user-1000.slice/session-3.scope
              Unit: session-3.scope
             Slice: user-1000.slice
           Session: 3
         Owner UID: 1000 (as)
           Boot ID: 9842428dbdab46be81201ba3044c75e3
        Machine ID: f861ca6111b841899436fcdecf2db3e6
          Hostname: i3
           Storage: /var/lib/systemd/coredump/core.a\x2eout.1000.9842428dbdab46be81201ba3044c75e3.322.1534151068000000.lz4
           Message: Process 322 (a.out) of user 1000 dumped core.

                Stack trace of thread 322:
                #0  0x000055ab9c5a5134 main (a.out)
                #1  0x00007f91c9e62b17 __libc_start_main (libc.so.6)
                #2  0x000055ab9c5a506a _start (a.out)

Pay attention to `Signal` row, that helps to identify crash cause. For deeper analysis you can examine the backtrace using `gdb`:

    # coredumpctl gdb $PID

When `gdb` is started, use the `bt` command to print the backtrace:

    (gdb) bt

# Automatic Bug Reporting Tool (ABRT)
- https://fedorahosted.org/abrt/wiki/AbrtDeployment2

In short if abrtd deamon is running then it is what handles creation of core dump files. In this case, you need to configure abrtd deamon via /etc/abrt/abrt.conf.

You may use `BlackList` directive to exclude the binaries.

# Can script dump core?
Yes.

Analysis to be added here.

# Reference
- [american fuzzy lop](http://lcamtuf.coredump.cx/afl/) - An tool for
    automated tests of the kernel and programs
- [Filesystem fuzzing](https://lwn.net/Articles/637151/) - LWN article
    about testing filesystems for bugs
- https://www.freedesktop.org/software/systemd/man/coredump.conf.html
- https://www.freedesktop.org/software/systemd/man/systemd-coredump.html



## Multithread


It appears that your binary is multithreaded and crash happened in some auxiliary thread. You should therefore find main thread and switch to it. Here is an example of how to do it for Firefox with many threads:

(gdb) t a a bt -1

Thread 59 (Thread 0x7f691deff700 (LWP 25924)):
#12 0x00007f69dce93f6f in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:105
..........
..........
many threads are listed here
..........
..........
Thread 1 (Thread 0x7f69de01a740 (LWP 4143)):
#17 0x000056374cb38817 in main ()
(gdb) t 1
[Switching to thread 1 (Thread 0x7f69de01a740 (LWP 4143))]
#0  0x00007f69dce8800d in poll () at ../sysdeps/unix/syscall-template.S:84
84  T_PSEUDO (SYSCALL_SYMBOL, SYSCALL_NAME, SYSCALL_NARGS)
Now gdb is switched to main thread (Thread 1).





gdb <executable> <core-file> or gdb <executable> -c <core-file> or

gdb <executable>
...
(gdb) core <core-file>




$ gdb --args ./crash -p param1 -o param2
GNU gdb (GDB) 7.1-ubuntu
...
(gdb) r
Starting program: /home/@@@@/crash -p param1 -o param2

Program received signal SIGSEGV, Segmentation fault.
__strlen_ia32 () at ../sysdeps/i386/i686/multiarch/../../i586/strlen.S:99
99    ../sysdeps/i386/i686/multiarch/../../i586/strlen.S: No such file or directory.
    in ../sysdeps/i386/i686/multiarch/../../i586/strlen.S
(gdb)









(gdb) where
This will get you with the information, of the stack, where you can analayze the cause of the crash/fault. Other command, for the same purposes is:

...
(gdb) bt full
This is the same as above. By convention, it lists the whole stack information (which ultimately leads to the crash location).




## objdump -s core can be used to dump memory in bulk


##

    man core tells us:

Piping core dumps to a program

Since kernel 2.6.19, Linux supports an alternate syntax for the /proc/sys/kernel/core_pattern file. If the first character of this file is a pipe symbol (|), then the remainder of the line is interpreted as a program to be executed. Instead of being written to a disk file, the core dump is given as standard input to the program.

Note the following points:

The program must be specified using an absolute pathname (or a pathname relative to the root directory, /), and must immediately follow the '|' character.

The process created to run the program runs as user and group root.

Command-line arguments can be supplied to the program (since Linux 2.6.24), delimited by white space (up to a total line length of 128 bytes).

The command-line arguments can include any of the % specifiers listed above. For example, to pass the PID of the process that is being dumped, specify %p in an argument.

You can put a script there, like e.g.

| /path/to/myscript %p %s %c
You can detect which process is triggering the coredump: (man core):

       %%  a single % character
       %p  PID of dumped process
       %u  (numeric) real UID of dumped process
       %g  (numeric) real GID of dumped process
       %s  number of signal causing dump
       %t  time of dump, expressed as seconds since the Epoch,  1970-01-01
           00:00:00 +0000 (UTC)
       %h  hostname (same as nodename returned by uname(2))
       %e  executable filename (without path prefix)
       %E  pathname of executable, with slashes ('/') replaced by exclama‐
           tion marks ('!').
       %c  core file size soft resource limit of crashing  process  (since
           Linux 2.6.24)


Core dump files will be generated after an uncaught signal in a process (as a SIGSEGV or SIGQUIT), in the base directory where the program was executed, and named as `core` or `core.PID`.

For example:
$> ulimit -c unlimited
$> kill -s SIGSEGV $$

This will trigger a segmentation fault in your current shell (you probably guessed it after seeing that the shell session where you executed it was closed), and generate a core file in:
/home/user/core

Now… is it possible to change where that file is generated by default instead of the current directory? And is it possible to change the name of that generated file? The answer is YES! to both. Let’s see how we can get this.

# The Core Pattern in Kernel

Since some years ago, the kernel configuration includes a file named “core_pattern”:
/proc/sys/kernel/core_pattern

In my system, that file contains just this single word:
core

As expected, this pattern shows how the core file will be generated. Two things can be understood from the previous line: The filename of the core dump file generated will be “core”; and second, the current directory will be used to store it (as the path specified is completely relative to the current directory).

Now, if we change the contents of that file… (as root, of course)

$> mkdir -p /tmp/cores
$> chmod a+rwx /tmp/cores
$> echo "/tmp/cores/core.%e.%p.%h.%t" > /proc/sys/kernel/core_pattern

And we run the same as before:

$> cd /home/user
$> ulimit -c unlimited
$> $> kill -s SIGSEGV $$

We get… voilá!
/tmp/cores/core.bash.8539.drehbahn-mbp.1236975953

Not only the program name (“bash“) or the PID (“8539“), but also the hostname (“drehbahn-mbp“) and the unix time (“1236975953“) are appended in the name of the core file!! And of course, it is stored in the absolute path we specified (“/tmp/cores/“).

You can use the following pattern elements in the core_pattern file:

%p: pid
%: '%' is dropped
%%: output one '%'
%u: uid
%g: gid
%s: signal number
%t: UNIX time of dump
%h: hostname
%e: executable filename
%: both are dropped

Isn’t is great?! Imagine that you have a cluster of machines and you want to use a NFS directory to store all core files from all the nodes. You will be able to detect which node generated the core file (with the hostname), which program generated it (with the program name), and also when did it happen (with the unix time).



%p:       pid
%<NUL>:   '%' is dropped
%%:       output one '%'
%u:       uid
%g:       gid
%s:       signal number
%t:       UNIX time of dump
%h:       hostname
%e:       executable filename
%<OTHER>: both are dropped

If core_pattern does not include "%p" (default does not) and core_uses_pid is set, then .PID will be appended to the filename.

example:

    echo "core.%e.%p" > /proc/sys/kernel/core_pattern

produces files names

    core.<executable>.<pid>

to make the changes permanent, add the following line to /etc/sysctl.conf:

    kernel.core_pattern = core.%e.%p

# man 5 core

http://man7.org/linux/man-pages/man5/core.5.html

       The  default  action of certain signals is to cause a process to terminate and produce a core dump file, a disk file containing an image of the process's memory at the time of termination.  This image can be used in a debugger (e.g., gdb(1)) to inspect the state of the program at the time that it termi‐
       nated.  A list of the signals which cause a process to dump core can be found in signal(7).

       A process can set its soft RLIMIT_CORE resource limit to place an upper limit on the size of the core dump file that will be produced if it receives a "core dump" signal; see getrlimit(2) for details.

       There are various circumstances in which a core dump file is not produced:

       *  The process does not have permission to write the core file.  (By default, the core file is called core or core.pid, where pid is the ID of the process that dumped core, and is created in the current working directory.  See below for details on naming.)  Writing the core file fails if  the  directory
          in which it is to be created is nonwritable, or if a file with the same name exists and is not writable or is not a regular file (e.g., it is a directory or a symbolic link).

       *  A (writable, regular) file with the same name as would be used for the core dump already exists, but there is more than one hard link to that file.

       *  The filesystem where the core dump file would be created is full; or has run out of inodes; or is mounted read-only; or the user has reached their quota for the filesystem.

       *  The directory in which the core dump file is to be created does not exist.

       *  The RLIMIT_CORE (core file size) or RLIMIT_FSIZE (file size) resource limits for the process are set to zero; see getrlimit(2) and the documentation of the shell's ulimit command (limit in csh(1)).

       *  The binary being executed by the process does not have read permission enabled.

       *  The  process is executing a set-user-ID (set-group-ID) program that is owned by a user (group) other than the real user (group) ID of the process, or the process is executing a program that has file capabilities (see capabilities(7)).  (However, see the description of the prctl(2) PR_SET_DUMPABLE op‐
          eration, and the description of the /proc/sys/fs/suid_dumpable file in proc(5).)

       *  /proc/sys/kernel/core_pattern is empty and /proc/sys/kernel/core_uses_pid contains the value 0.  (These files are described below.)  Note that if /proc/sys/kernel/core_pattern is empty and /proc/sys/kernel/core_uses_pid contains the value 1, core dump files will have names of the form .pid, and  such
          files are hidden unless one uses the ls(1) -a option.

       *  (Since Linux 3.7) The kernel was configured without the CONFIG_COREDUMP option.

       In addition, a core dump may exclude part of the address space of the process if the madvise(2) MADV_DONTDUMP flag was employed.

       On systems that employ systemd(1) as the init framework, core dumps may instead be placed in a location determined by systemd(1).  See below for further details.

   Naming of core dump files
       By default, a core dump file is named core, but the /proc/sys/kernel/core_pattern file (since Linux 2.6 and 2.4.21) can be set to define a template that is used to name core dump files.  The template can contain % specifiers which are substituted by the following values when a core file is created:

           %%  a single % character
           %c  core file size soft resource limit of crashing process (since Linux 2.6.24)
           %d  dump mode—same as value returned by prctl(2) PR_GET_DUMPABLE (since Linux 3.7)
           %e  executable filename (without path prefix)
           %E  pathname of executable, with slashes ('/') replaced by exclamation marks ('!') (since Linux 3.0).
           %g  (numeric) real GID of dumped process
           %h  hostname (same as nodename returned by uname(2))
           %i  TID of thread that triggered core dump, as seen in the PID namespace in which the thread resides (since Linux 3.18)
           %I  TID of thread that triggered core dump, as seen in the initial PID namespace (since Linux 3.18)
           %p  PID of dumped process, as seen in the PID namespace in which the process resides
           %P  PID of dumped process, as seen in the initial PID namespace (since Linux 3.12)
           %s  number of signal causing dump
           %t  time of dump, expressed as seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC)
           %u  (numeric) real UID of dumped process

       A single % at the end of the template is dropped from the core filename, as is the combination of a % followed by any character other than those listed above.  All other characters in the template become a literal part of the core filename.  The template may include '/' characters, which are interpreted
       as delimiters for directory names.  The maximum size of the resulting core filename is 128 bytes (64 bytes in kernels before 2.6.19).  The default value in this file is "core".  For backward compatibility, if /proc/sys/kernel/core_pattern does not include %p and /proc/sys/kernel/core_uses_pid  (see  be‐
       low) is nonzero, then .PID will be appended to the core filename.

       Paths are interpreted according to the settings that are active for the crashing process.  That means the crashing process's mount namespace (see mount_namespaces(7)), its current working directory (found via getcwd(2)), and its root directory (see chroot(2)).

       Since  version  2.4,  Linux  has also provided a more primitive method of controlling the name of the core dump file.  If the /proc/sys/kernel/core_uses_pid file contains the value 0, then a core dump file is simply named core.  If this file contains a nonzero value, then the core dump file includes the
       process ID in a name of the form core.PID.

       Since Linux 3.6, if /proc/sys/fs/suid_dumpable is set to 2 ("suidsafe"), the pattern must be either an absolute pathname (starting with a leading '/' character) or a pipe, as defined below.

   Piping core dumps to a program
       Since kernel 2.6.19, Linux supports an alternate syntax for the /proc/sys/kernel/core_pattern file.  If the first character of this file is a pipe symbol (|), then the remainder of the line is interpreted as the command-line for a user-space program (or script) that is to be executed.  Instead of  being
       written to a disk file, the core dump is given as standard input to the program.  Note the following points:

       *  The program must be specified using an absolute pathname (or a pathname relative to the root directory, /), and must immediately follow the '|' character.

       *  The command-line arguments can include any of the % specifiers listed above.  For example, to pass the PID of the process that is being dumped, specify %p in an argument.

       *  The process created to run the program runs as user and group root.

       *  Running as root does not confer any exceptional security bypasses.  Namely, LSMs (e.g., SELinux) are still active and may prevent the handler from accessing details about the crashed process via /proc/[pid].

       *  The program pathname is interpreted with respect to the initial mount namespace as it is always executed there.  It is not affected by the settings (e.g., root directory, mount namespace, current working directory) of the crashing process.

       *  The process runs in the initial namespaces (PID, mount, user, and so on) and not in the namespaces of the crashing process.  One can utilize specifiers such as %P to find the right /proc/[pid] directory and probe/enter the crashing process's namespaces if needed.

       *  The process starts with its current working directory as the root directory.  If desired, it is possible change to the working directory of the dumping process by employing the value provided by the %P specifier to change to the location of the dumping process via /proc/[pid]/cwd.

       *  Command-line arguments can be supplied to the program (since Linux 2.6.24), delimited by white space (up to a total line length of 128 bytes).

       *  The RLIMIT_CORE limit is not enforced for core dumps that are piped to a program via this mechanism.

   /proc/sys/kernel/core_pipe_limit
       When collecting core dumps via a pipe to a user-space program, it can be useful for the collecting program to gather data about the crashing process from that process's /proc/[pid] directory.  In order to do this safely, the kernel must wait for the program collecting the core dump to exit, so as not to
       remove the crashing process's /proc/[pid] files prematurely.  This in turn creates the possibility that a misbehaving collecting program can block the reaping of a crashed process by simply never exiting.

       Since Linux 2.6.32, the /proc/sys/kernel/core_pipe_limit can be used to defend against this possibility.  The value in this file defines how many concurrent crashing processes may be piped to user-space programs in parallel.  If this value is exceeded, then those crashing processes above this value  are
       noted in the kernel log and their core dumps are skipped.

       A value of 0 in this file is special.  It indicates that unlimited processes may be captured in parallel, but that no waiting will take place (i.e., the collecting program is not guaranteed access to /proc/<crashing-PID>).  The default value for this file is 0.

   Controlling which mappings are written to the core dump
       Since kernel 2.6.23, the Linux-specific /proc/[pid]/coredump_filter file can be used to control which memory segments are written to the core dump file in the event that a core dump is performed for the process with the corresponding process ID.

       The value in the file is a bit mask of memory mapping types (see mmap(2)).  If a bit is set in the mask, then memory mappings of the corresponding type are dumped; otherwise they are not dumped.  The bits in this file have the following meanings:

           bit 0  Dump anonymous private mappings.
           bit 1  Dump anonymous shared mappings.
           bit 2  Dump file-backed private mappings.
           bit 3  Dump file-backed shared mappings.
           bit 4 (since Linux 2.6.24)
                  Dump ELF headers.
           bit 5 (since Linux 2.6.28)
                  Dump private huge pages.
           bit 6 (since Linux 2.6.28)
                  Dump shared huge pages.
           bit 7 (since Linux 4.4)
                  Dump private DAX pages.
           bit 8 (since Linux 4.4)
                  Dump shared DAX pages.

       By default, the following bits are set: 0, 1, 4 (if the CONFIG_CORE_DUMP_DEFAULT_ELF_HEADERS kernel configuration option is enabled), and 5.  This default can be modified at boot time using the coredump_filter boot option.

       The value of this file is displayed in hexadecimal.  (The default value is thus displayed as 33.)

       Memory-mapped I/O pages such as frame buffer are never dumped, and virtual DSO pages are always dumped, regardless of the coredump_filter value.

       A child process created via fork(2) inherits its parent's coredump_filter value; the coredump_filter value is preserved across an execve(2).

       It can be useful to set coredump_filter in the parent shell before running a program, for example:

           $ echo 0x7 > /proc/self/coredump_filter
           $ ./some_program

       This file is provided only if the kernel was built with the CONFIG_ELF_CORE configuration option.

   Core dumps and systemd
       On  systems  using the systemd(1) init framework, core dumps may be placed in a location determined by systemd(1).  To do this, systemd(1) employs the core_pattern feature that allows piping core dumps to a program.  One can verify this by checking whether core dumps are being piped to the systemd-core‐
       dump(8) program:

           $ cat /proc/sys/kernel/core_pattern
           |/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %e

       In this case, core dumps will be placed in the location configured for systemd-coredump(8), typically as lz4(1) compressed files in the directory /var/lib/systemd/coredump/.  One can list the core dumps that have been recorded by systemd-coredump(8) using coredumpctl(1):

         $ coredumpctl list | tail -5
         Wed 2017-10-11 22:25:30 CEST  2748 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:29:10 CEST  2716 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:30:50 CEST  2767 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:37:40 CEST  2918 1000 1000 3 present  /usr/bin/cat
         Thu 2017-10-12 08:13:07 CEST  2955 1000 1000 3 present  /usr/bin/cat

       The information shown for each core dump includes the date and time of the dump, the PID, UID, and GID  of the dumping process, the signal number that caused the core dump, and the pathname of the executable that was being run by the dumped process.  Various options to coredumpctl(1) allow  a  specified
       coredump file to be pulled from the systemd(1) location into a specified file.  For example, to extract the core dump for PID 2955 shown above to a file named core in the current directory, one could use:

           $ coredumpctl dump 2955 -o core

       For more extensive details, see the coredumpctl(1) manual page.

       To disable the systemd(1) mechanism that archives core dumps, restoring to something more like traditional Linux behavior, one can set an override for the systemd(1) mechanism, using something like:

         # echo "kernel.core_pattern=core.%p" > /etc/sysctl.d/50-coredump.conf
         # /lib/systemd/systemd-sysctl

NOTES
       The gdb(1) gcore command can be used to obtain a core dump of a running process.

       In  Linux versions up to and including 2.6.27, if a multithreaded process (or, more precisely, a process that shares its memory with another process by being created with the CLONE_VM flag of clone(2)) dumps core, then the process ID is always appended to the core filename, unless the process ID was al‐
       ready included elsewhere in the filename via a %p specification in /proc/sys/kernel/core_pattern.  (This is primarily useful when employing the obsolete LinuxThreads implementation, where each thread of a process has a different PID.)

示例处理程序展示了pipe语法。

    $ cc -o core_pattern_pipe_test core_pattern_pipe_test.c
    $ su
    Password:
    # echo "|$PWD/core_pattern_pipe_test %p UID=%u GID=%g sig=%s" > \
        /proc/sys/kernel/core_pattern
    # exit
    $ sleep 100
    ^\                     # type control-backslash
    Quit (core dumped)

    $ cat core.info
    argc=5
    argc[0]=</to/work/core_pattern_pipe_test>
    argc[1]=<9272>
    argc[2]=<UID=1000>
    argc[3]=<GID=1000>
    argc[4]=<sig=3>
    Total bytes in core dump: 393216

示例处理程序源代码如下。

       /* core_pattern_pipe_test.c */

       #define _GNU_SOURCE
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <limits.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>

       #define BUF_SIZE 1024

       int
       main(int argc, char *argv[])
       {
           int tot, j;
           ssize_t nread;
           char buf[BUF_SIZE];
           FILE *fp;
           char cwd[PATH_MAX];

           /* Change our current working directory to that of the
              crashing process */

           snprintf(cwd, PATH_MAX, "/proc/%s/cwd", argv[1]);
           chdir(cwd);

           /* Write output to file "core.info" in that directory */

           fp = fopen("core.info", "w+");
           if (fp == NULL)
               exit(EXIT_FAILURE);

           /* Display command-line arguments given to core_pattern
              pipe program */

           fprintf(fp, "argc=%d\n", argc);
           for (j = 0; j < argc; j++)
               fprintf(fp, "argc[%d]=<%s>\n", j, argv[j]);

           /* Count bytes in standard input (the core dump) */

           tot = 0;
           while ((nread = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
               tot += nread;
           fprintf(fp, "Total bytes in core dump: %d\n", tot);

           fclose(fp);
           exit(EXIT_SUCCESS);
       }



```
$ coredumpctl list
TIME                            PID  UID  GID SIG     COREFILE EXE                              SIZE
Fri 2021-12-17 15:55:34 HKT    2228 1000 1000 SIGABRT missing  /usr/bin/zsh                      n/a
Fri 2021-12-17 15:55:36 HKT    2284 1000 1000 SIGABRT missing  /usr/bin/zsh                      n/a
Fri 2021-12-24 11:06:03 HKT 2541739 1000 1000 SIGSEGV missing  /usr/bin/gthumb                   n/a
Fri 2021-12-24 11:41:10 HKT 2545434 1000 1000 SIGSEGV missing  /usr/bin/gthumb                   n/a
Fri 2021-12-24 11:58:03 HKT 2570848 1000 1000 SIGSEGV missing  /usr/bin/gthumb                   n/a
Fri 2021-12-24 15:42:38 HKT 2691006 1000 1000 SIGSEGV missing  /usr/bin/gthumb                   n/a
Mon 2021-12-27 08:43:00 HKT  533914 1000 1000 SIGABRT missing  /aaron/cinelerra/bin/cinelerra    n/a
Mon 2021-12-27 08:54:04 HKT  546272 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 08:55:40 HKT  547396 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 08:59:07 HKT  548935 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 09:02:30 HKT  554398 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 09:04:19 HKT  556436 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 09:14:02 HKT  566188 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 09:18:05 HKT  556312 1000 1000 SIGABRT missing  /usr/lib/virtualbox/VirtualBoxVM  n/a
Mon 2021-12-27 17:54:54 HKT  870319 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 17:54:57 HKT  870392 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 18:02:00 HKT  874204 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 18:02:04 HKT  874279 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 18:03:55 HKT  875593 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 18:03:59 HKT  875671 1000 1000 SIGSEGV missing  /usr/bin/melt-7                   n/a
Mon 2021-12-27 19:19:20 HKT  737953 1000 1000 SIGSEGV missing  /usr/bin/shotcut                  n/a
Tue 2021-12-28 19:24:28 HKT  391251 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Tue 2021-12-28 19:24:38 HKT  391430 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Tue 2021-12-28 19:30:05 HKT  393082 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Tue 2021-12-28 19:33:49 HKT  399301 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Wed 2021-12-29 22:29:21 HKT 1276878 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Wed 2021-12-29 22:30:08 HKT 1277461 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Thu 2021-12-30 09:16:25 HKT 1293884 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Thu 2021-12-30 09:17:01 HKT 1294264 1000 1000 SIGABRT present  /usr/lib/electron13/electron     4.2M
Thu 2021-12-30 09:17:16 HKT 1294416 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Thu 2021-12-30 21:47:33 HKT 1698150 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
Thu 2021-12-30 21:48:01 HKT 1698536 1000 1000 SIGTRAP present  /opt/google/chrome/chrome        2.0M
```

```
$ coredumpctl info 391251
           PID: 391251 (chrome)
           UID: 1000 (aaron)
           GID: 1000 (aaron)
        Signal: 5 (TRAP)
     Timestamp: Tue 2021-12-28 19:24:27 HKT (2 days ago)
  Command Line: $'/opt/google/chrome/chrome --enable-crashpad https://www.reddit.com/message/messages/1z8yjhs?%24deep_link=true&correlation_id=f12bccd8-bfd6-4d0d-aea1-59fd8e4c1c4a&ref=email_private_message&ref_campaign=email_private_message&ref_source=email&%243p=e_as&_branch_match_id=1004333426649027454&utm_medium=Email%20Amazon%20SES&_branch_referrer=H4sIAA%2FVwOdP%2FGnaLa%2FvZdmEs%2FnJQui%2ByrAU9ui%2FD%2Bxb62%2BoAe2Nr7CGQEAAA%3D%3D'
    Executable: /opt/google/chrome/chrome
 Control Group: /user.slice/user-1000.slice/session-19.scope
          Unit: session-19.scope
         Slice: user-1000.slice
       Session: 19
     Owner UID: 1000 (aaron)
       Boot ID: 8d6d191c376472e88f1310212d123f67
    Machine ID: 6f96bd5861c64ff384d6b057b0677620
      Hostname: i54
       Storage: /var/lib/systemd/coredump/core.chrome.1000.8d6d819137647c2e8f1310212d12f673.391251.1640690667000000.zst (present)
     Disk Size: 2.0M
       Message: Process 391251 (chrome) of user 1000 dumped core.

                Module linux-vdso.so.1 with build-id d5b2c025831b6fe3cf78cde796e02920540c6291
                Module libbrotlicommon.so.1 with build-id a4ba3f4b4571c8272343b621da812a6e24a202a7
                Module libgpg-error.so.0 with build-id 3801187d42c4955bd93c605451430cdf1b164e63
                Module libbrotlidec.so.1 with build-id 45defc036e918e0140a72f1fbce6e7692d38241d
                Module libbz2.so.1.0 with build-id 919597c477c9b2cb9cdbb7745ed6494ac0e6da60
                Module libgraphite2.so.3 with build-id 47761dc11e553f519cde97ed9ee985be12ccdae2
                Module libdatrie.so.1 with build-id 6fe3b6ece2c8e7d11869fa051375128d8f808f58
                Module libgcrypt.so.20 with build-id db45f5d5e0f7af1e77324fea1885f974619ad268
                Module libcap.so.2 with build-id f56c6cd6ad4d35053340d7ff2f8f954498796739
                Module liblz4.so.1 with build-id e63600ab23b2f6997f42fac2fa56e1f02ce159a1
                Module libzstd.so.1 with build-id 4b10444c1560ebc574af4d5f488b7408b22d450e
                Module liblzma.so.5 with build-id 8b615460aa230708c5183f16bede67aa0437d95e
                Module librt.so.1 with build-id 75484da2d6f1515189eefa076e0a40328834cd16
                Module libblkid.so.1 with build-id f03a24e92c9852272bd0049b5bcb7ed6cf0e664f
                Module libgmp.so.10 with build-id e58d34ab389d1b649c24195c2d145e3ff2e58290
                Module libhogweed.so.6 with build-id 2d70cff7b1841b4d9ca4e8e7726cd4b944c07fdc
                Module libnettle.so.8 with build-id 9a878e513c02007598fcf1e2e286c2203f13536e
                Module libtasn1.so.6 with build-id ee3429ca5e94718aea4fe5249fc859e0cd88e4e9
                Module libunistring.so.2 with build-id 015ac6d6bcb60b7d8bea31a80d1941b06e8636ab
                Module libidn2.so.0 with build-id 1ce2b50ad9f9821c2c629b521cf5a3c99593d332
                Module libp11-kit.so.0 with build-id f97c44b297b54185bbe3eb6ed6dab5d8967f1532
                Module libXi.so.6 with build-id 16603be937a02a7e61b0b0395d064be7efd86f49
                Module libpixman-1.so.0 with build-id 341f793dcada3a48a306a793d265a517e3f2e7d6
                Module libxcb-shm.so.0 with build-id fb797f299a446f559a95afcc168227482cc800d1
                Module libxcb-render.so.0 with build-id a37bdb37744b508be9dd29fd9ccb9bb0170d43e5
                Module libfreetype.so.6 with build-id 26c5f833068ff72660d1975cbc2074c3eb47fad8
                Module libfontconfig.so.1 with build-id 1103a641395c7d3b42e49b793d3a9ea927c77bf6
                Module libpng16.so.16 with build-id 2dc0bce07f199bf983c07a05fb95a6f4af83a9b3
                Module libharfbuzz.so.0 with build-id 1d9dee49dd99162c3f83eb3259c3c88c6b4cd7fe
                Module libthai.so.0 with build-id a7ac5010b4275c49308021200d23690533952702
                Module libfribidi.so.0 with build-id 79124bad061c2aab4ec89f25d067363d5b781114
                Module libstdc++.so.6 with build-id 9b5eeeb149bf3c4efe787fb398b44f00507aec87
                Module libwayland-server.so.0 with build-id 645526447334b85a6f4bf5a8b37737b27696365f
                Module libXrender.so.1 with build-id 97e0b9ab6ba96ebc86527cc2b3c3078aad8616b3
                Module libXdmcp.so.6 with build-id 8ca0792d23c8b8b4c0864297512349292bea5955
                Module libXau.so.6 with build-id 1c67764663e07bec24d8951e5fd93f4d165979ff
                Module libsystemd.so.0 with build-id 5e0c342d74b444cce6793925b41760cf298c417c
                Module libresolv.so.2 with build-id c915c72668282861a813f7ea3c0780f37b681dc0
                Module libmount.so.1 with build-id ff9a1d99d35cf640d0bfdaba294854372672c29b
                Module libgmodule-2.0.so.0 with build-id 34cabbd12d9baf397a0255f174e4c96165bc329b
                Module libz.so.1 with build-id 81bf6e728a6d6f5b105b0f8b25f6c614ce10452a
                Module libgnutls.so.30 with build-id 8c87466eacaec0041a370df713d0fd200358c94c
                Module libavahi-client.so.3 with build-id 1858551543958190c653b565cf0eb64609ad908a
                Module libavahi-common.so.3 with build-id 80fda945459a3476ccd1050783dfd5f5c17c479a
                Module libplc4.so with build-id 44dcd42fb72cc8aab586dbf4000293590bb19e67
                Module libplds4.so with build-id e915f74a1aff6a20d65b5f03f5ee2e0197153a33
                Module libpcre.so.1 with build-id 845483dd0acba86de9f0313102bebbaf3ce52767
                Module libffi.so.8 with build-id f90d8b734f6de9b25faedb8cbfab7054dafc0a42
                Module ld-linux-x86-64.so.2 with build-id 040cc3dd10461562f177df39e3be2f3704258c3c
                Module libc.so.6 with build-id 4b406737057708c0e4c642345a703c47a61c73dc
                Module libgcc_s.so.1 with build-id 7f8508bb914546ada778809b64b99d234337d835
                Module libatspi.so.0 with build-id de251156cf6f2f447c5e2b8721bd913d79995d4f
                Module libasound.so.2 with build-id b17fc1317a484842433c772360376623b64ec3d8
                Module libcairo.so.2 with build-id 06820af9cf79c2deb207d9533a61caf04e67a8ad
                Module libpango-1.0.so.0 with build-id 730a8183a36afae82dd6a5564c0e490fed239a40
                Module libxkbcommon.so.0 with build-id 1f1bc7527e57c886c3df5803068122e1971d4724
                Module libgbm.so.1 with build-id 8f461cda076ab0774a933494486b094130da86df
                Module libXrandr.so.2 with build-id d4e869b5c72541e1de8f96b456248987ea52d51b
                Module libXfixes.so.3 with build-id 0a05c7e8714522bfbdd7c0027c3e2a94965664b0
                Module libXext.so.6 with build-id d70f24beb4fad748d6becffdcc13e51be0a2ebfa
                Module libXdamage.so.1 with build-id a1d867e093c16944b2c0083be98050ef35c9e5c2
                Module libXcomposite.so.1 with build-id f1bb5ffb6203ab2907ac044a204ce3902a79f1c1
                Module libX11.so.6 with build-id 5ba5798d193c0065014b8c6252a0678671c8d478
                Module libm.so.6 with build-id 2b8fd1f869ecab4e0b55e92f2f151897f6818acf
                Module libxcb.so.1 with build-id 0d1ef11740a5daad2ee331e812a51aa6574af222
                Module libexpat.so.1 with build-id 16023a53e7b5bbdff92bd0bf2eebd36f9b5b879f
                Module libdbus-1.so.3 with build-id 74f2ab9c60512f3a93c932c3f627564d42e0b11e
                Module libdrm.so.2 with build-id 457a1a1bd25f1d5541a10d3f16c5dc1440d77c7d
                Module libgio-2.0.so.0 with build-id fc7ccd9c7c26cbb1e938b1c0879f078c2f47d803
                Module libcups.so.2 with build-id 68a2ef2ccefd545e68b78c5acb20bcb2818c5049
                Module libatk-bridge-2.0.so.0 with build-id 1161ebbcc5aa791075dfa026671875e5417287bd
                Module libatk-1.0.so.0 with build-id aacaa40363d304858b654728a893bc212a4ca119
                Module libnspr4.so with build-id c5d12234f7975d11a11e67646533657d014d9540
                Module libsmime3.so with build-id caced12c534af7e258c29547a53aaf3c93a9501a
                Module libnssutil3.so with build-id 0762279c689e9de8745f0a4c120a1d8559f849c2
                Module libnss3.so with build-id ad8cd43ed62aba11f3b40eabb482516773dd9cbc
                Module libglib-2.0.so.0 with build-id 8214b56e554b7cbead4034b6ba32c90bc8c674da
                Module libgobject-2.0.so.0 with build-id 3e451709a0a5772b9550d3a4c28dcb37a87028fa
                Module libpthread.so.0 with build-id 07c8f95b4f3251d08550217ad8a1f31066229996
                Module libdl.so.2 with build-id 5abc547e7b0949f89f3c0e21ab0c8331a7440a8a
                Module chrome with build-id dc2f8d794740d875f9cc1b3ed2b6715b5975a6fa
                Stack trace of thread 391251:
                #0  0x0000557285b3f1e2 n/a (chrome + 0x41a41e2)
                #1  0x0000557285bc1171 n/a (chrome + 0x4226171)
                #2  0x0000557285bc106f n/a (chrome + 0x422606f)
                #3  0x0000557285bc09f0 n/a (chrome + 0x42259f0)
                #4  0x0000557285bc0539 n/a (chrome + 0x4225539)
                #5  0x00005572852ffe95 n/a (chrome + 0x3964e95)
                #6  0x00005572852ff6bd n/a (chrome + 0x39646bd)
                #7  0x00005572852f36a5 n/a (chrome + 0x39586a5)
                #8  0x00005572852bcc92 n/a (chrome + 0x3921c92)
                #9  0x00005572852b9e83 ChromeMain (chrome + 0x391ee83)
                #10 0x00007f14f70aeb25 __libc_start_main (libc.so.6 + 0x27b25)
                #11 0x000055728bdfff7a _start (chrome + 0xa464f7a)

                Stack trace of thread 391274:
                #0  0x00007f14f718592e epoll_wait (libc.so.6 + 0xfe92e)
                #1  0x0000557283babefb n/a (chrome + 0x2210efb)
                #2  0x0000557285311149 n/a (chrome + 0x3976149)
                #3  0x0000557285310f1f n/a (chrome + 0x3975f1f)
                #4  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #5  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #6  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #7  0x00005572853f9fed n/a (chrome + 0x3a5efed)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391272:
                #0  0x00007f14f7152a2f wait4 (libc.so.6 + 0xcba2f)
                #1  0x0000557285964ceb n/a (chrome + 0x3fc9ceb)
                #2  0x000055728871b878 n/a (chrome + 0x6d80878)
                #3  0x0000557285126363 n/a (chrome + 0x378b363)
                #4  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #5  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391277:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391278:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391281:
                #0  0x00007f14f717d201 __select (libc.so.6 + 0xf6201)
                #1  0x000055728871cc65 n/a (chrome + 0x6d81c65)
                #2  0x0000557285126363 n/a (chrome + 0x378b363)
                #3  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #4  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391280:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4fa0d n/a (chrome + 0x22b4a0d)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391275:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391276:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391273:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557288712d87 n/a (chrome + 0x6d77d87)
                #5  0x0000557288712f68 n/a (chrome + 0x6d77f68)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391264:
                #0  0x00007f14f717ab2f __poll (libc.so.6 + 0xf3b2f)
                #1  0x00005572843e07c3 n/a (chrome + 0x2a457c3)
                #2  0x0000557285126363 n/a (chrome + 0x378b363)
                #3  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #4  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391282:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31270 pthread_cond_wait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf270)
                #2  0x0000557283c50c65 n/a (chrome + 0x22b5c65)
                #3  0x000055728428557e n/a (chrome + 0x28ea57e)
                #4  0x00005572886f0862 n/a (chrome + 0x6d55862)
                #5  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #6  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #7  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391279:
                #0  0x00007f14f718592e epoll_wait (libc.so.6 + 0xfe92e)
                #1  0x0000557283babefb n/a (chrome + 0x2210efb)
                #2  0x0000557285311149 n/a (chrome + 0x3976149)
                #3  0x0000557285310e0a n/a (chrome + 0x3975e0a)
                #4  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #5  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #6  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #7  0x0000557286fc4052 n/a (chrome + 0x5629052)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)
                ELF object binary architecture: AMD x86-64
$ coredumpctl gdb 391251
```



The core dump files stored in /var/lib/systemd/coredump/ will be automatically
cleaned by systemd-tmpfiles --clean, which is triggered daily with
systemd-tmpfiles-clean.timer. Core dumps are configured to persist for at least
3 days, see systemd-tmpfiles --cat-config.


```

           PID: 391251 (chrome)
           UID: 1000 (aaron)
           GID: 1000 (aaron)
        Signal: 5 (TRAP)
     Timestamp: Tue 2021-12-28 19:24:27 HKT (2 days ago)
  Command Line: $'/opt/google/chrome/chrome --enable-crashpad https://www.reddit.com/message/messages/18zsjyh?%24deep_link=true&correlation_id=f12bdcc8-bdf6-4dd0-aae1-59fde841cc4a&ref=email_private_message&ref_campaign=email_private_message&ref_source=email&%243p=e_as&_branch_match_id=1004334326694027454&utm_medium=Email%20Amazon%20SES&_branch_referrer=H4sIAAAAAAAAA4WO3WrDMAxGn8a7S7LEbskGZRRKX8OolpJoc2IjOw3b09eB%2FVwOdPHx6RykKeeYXptGCJFzDTHWnpePRsc31RkdT2QhPZUYhEdewNtV%2FGnaLaXPqruW2bat%2FvZdmEsxU0ow0l9KJbb9V3r%2FnJQuikGiaPdDSl%2ByrAU9uiBCHjKHxTKWfmi7GzrXVzccjpVBfK4AqK0OLwNSb1rnDBRPaCgwzcDeRuE7ZLK%2FD%2Bxb62COwOPyD5bCKo5%2BoAe2Nr7CGQEAAA%3D%3D'
    Executable: /opt/google/chrome/chrome
 Control Group: /user.slice/user-1000.slice/session-19.scope
          Unit: session-19.scope
         Slice: user-1000.slice
       Session: 19
     Owner UID: 1000 (aaron)
       Boot ID: 8d6d8191c376472e8f1310212d123f67
    Machine ID: 6f96bd5861c64ff3b84d6b0570627760
      Hostname: i54
       Storage: /var/lib/systemd/coredump/core.chrome.1000.8d6d8191c376472e8f1310212d123f67.391251.1640690667000000.zst (present)
     Disk Size: 2.0M
       Message: Process 391251 (chrome) of user 1000 dumped core.

                Module linux-vdso.so.1 with build-id d5b2c025831b6fe3cf78cde796e02920540c6291
                Module libbrotlicommon.so.1 with build-id a4ba3f4b4571c8272343b621da812a6e24a202a7
                Module libgpg-error.so.0 with build-id 3801187d42c4955bd93c605451430cdf1b164e63
                Module libbrotlidec.so.1 with build-id 45defc036e918e0140a72f1fbce6e7692d38241d
                Module libbz2.so.1.0 with build-id 919597c477c9b2cb9cdbb7745ed6494ac0e6da60
                Module libgraphite2.so.3 with build-id 47761dc11e553f519cde97ed9ee985be12ccdae2
                Module libdatrie.so.1 with build-id 6fe3b6ece2c8e7d11869fa051375128d8f808f58
                Module libgcrypt.so.20 with build-id db45f5d5e0f7af1e77324fea1885f974619ad268
                Module libcap.so.2 with build-id f56c6cd6ad4d35053340d7ff2f8f954498796739
                Module liblz4.so.1 with build-id e63600ab23b2f6997f42fac2fa56e1f02ce159a1
                Module libzstd.so.1 with build-id 4b10444c1560ebc574af4d5f488b7408b22d450e
                Module liblzma.so.5 with build-id 8b615460aa230708c5183f16bede67aa0437d95e
                Module librt.so.1 with build-id 75484da2d6f1515189eefa076e0a40328834cd16
                Module libblkid.so.1 with build-id f03a24e92c9852272bd0049b5bcb7ed6cf0e664f
                Module libgmp.so.10 with build-id e58d34ab389d1b649c24195c2d145e3ff2e58290
                Module libhogweed.so.6 with build-id 2d70cff7b1841b4d9ca4e8e7726cd4b944c07fdc
                Module libnettle.so.8 with build-id 9a878e513c02007598fcf1e2e286c2203f13536e
                Module libtasn1.so.6 with build-id ee3429ca5e94718aea4fe5249fc859e0cd88e4e9
                Module libunistring.so.2 with build-id 015ac6d6bcb60b7d8bea31a80d1941b06e8636ab
                Module libidn2.so.0 with build-id 1ce2b50ad9f9821c2c629b521cf5a3c99593d332
                Module libp11-kit.so.0 with build-id f97c44b297b54185bbe3eb6ed6dab5d8967f1532
                Module libXi.so.6 with build-id 16603be937a02a7e61b0b0395d064be7efd86f49
                Module libpixman-1.so.0 with build-id 341f793dcada3a48a306a793d265a517e3f2e7d6
                Module libxcb-shm.so.0 with build-id fb797f299a446f559a95afcc168227482cc800d1
                Module libxcb-render.so.0 with build-id a37bdb37744b508be9dd29fd9ccb9bb0170d43e5
                Module libfreetype.so.6 with build-id 26c5f833068ff72660d1975cbc2074c3eb47fad8
                Module libfontconfig.so.1 with build-id 1103a641395c7d3b42e49b793d3a9ea927c77bf6
                Module libpng16.so.16 with build-id 2dc0bce07f199bf983c07a05fb95a6f4af83a9b3
                Module libharfbuzz.so.0 with build-id 1d9dee49dd99162c3f83eb3259c3c88c6b4cd7fe
                Module libthai.so.0 with build-id a7ac5010b4275c49308021200d23690533952702
                Module libfribidi.so.0 with build-id 79124bad061c2aab4ec89f25d067363d5b781114
                Module libstdc++.so.6 with build-id 9b5eeeb149bf3c4efe787fb398b44f00507aec87
                Module libwayland-server.so.0 with build-id 645526447334b85a6f4bf5a8b37737b27696365f
                Module libXrender.so.1 with build-id 97e0b9ab6ba96ebc86527cc2b3c3078aad8616b3
                Module libXdmcp.so.6 with build-id 8ca0792d23c8b8b4c0864297512349292bea5955
                Module libXau.so.6 with build-id 1c67764663e07bec24d8951e5fd93f4d165979ff
                Module libsystemd.so.0 with build-id 5e0c342d74b444cce6793925b41760cf298c417c
                Module libresolv.so.2 with build-id c915c72668282861a813f7ea3c0780f37b681dc0
                Module libmount.so.1 with build-id ff9a1d99d35cf640d0bfdaba294854372672c29b
                Module libgmodule-2.0.so.0 with build-id 34cabbd12d9baf397a0255f174e4c96165bc329b
                Module libz.so.1 with build-id 81bf6e728a6d6f5b105b0f8b25f6c614ce10452a
                Module libgnutls.so.30 with build-id 8c87466eacaec0041a370df713d0fd200358c94c
                Module libavahi-client.so.3 with build-id 1858551543958190c653b565cf0eb64609ad908a
                Module libavahi-common.so.3 with build-id 80fda945459a3476ccd1050783dfd5f5c17c479a
                Module libplc4.so with build-id 44dcd42fb72cc8aab586dbf4000293590bb19e67
                Module libplds4.so with build-id e915f74a1aff6a20d65b5f03f5ee2e0197153a33
                Module libpcre.so.1 with build-id 845483dd0acba86de9f0313102bebbaf3ce52767
                Module libffi.so.8 with build-id f90d8b734f6de9b25faedb8cbfab7054dafc0a42
                Module ld-linux-x86-64.so.2 with build-id 040cc3dd10461562f177df39e3be2f3704258c3c
                Module libc.so.6 with build-id 4b406737057708c0e4c642345a703c47a61c73dc
                Module libgcc_s.so.1 with build-id 7f8508bb914546ada778809b64b99d234337d835
                Module libatspi.so.0 with build-id de251156cf6f2f447c5e2b8721bd913d79995d4f
                Module libasound.so.2 with build-id b17fc1317a484842433c772360376623b64ec3d8
                Module libcairo.so.2 with build-id 06820af9cf79c2deb207d9533a61caf04e67a8ad
                Module libpango-1.0.so.0 with build-id 730a8183a36afae82dd6a5564c0e490fed239a40
                Module libxkbcommon.so.0 with build-id 1f1bc7527e57c886c3df5803068122e1971d4724
                Module libgbm.so.1 with build-id 8f461cda076ab0774a933494486b094130da86df
                Module libXrandr.so.2 with build-id d4e869b5c72541e1de8f96b456248987ea52d51b
                Module libXfixes.so.3 with build-id 0a05c7e8714522bfbdd7c0027c3e2a94965664b0
                Module libXext.so.6 with build-id d70f24beb4fad748d6becffdcc13e51be0a2ebfa
                Module libXdamage.so.1 with build-id a1d867e093c16944b2c0083be98050ef35c9e5c2
                Module libXcomposite.so.1 with build-id f1bb5ffb6203ab2907ac044a204ce3902a79f1c1
                Module libX11.so.6 with build-id 5ba5798d193c0065014b8c6252a0678671c8d478
                Module libm.so.6 with build-id 2b8fd1f869ecab4e0b55e92f2f151897f6818acf
                Module libxcb.so.1 with build-id 0d1ef11740a5daad2ee331e812a51aa6574af222
                Module libexpat.so.1 with build-id 16023a53e7b5bbdff92bd0bf2eebd36f9b5b879f
                Module libdbus-1.so.3 with build-id 74f2ab9c60512f3a93c932c3f627564d42e0b11e
                Module libdrm.so.2 with build-id 457a1a1bd25f1d5541a10d3f16c5dc1440d77c7d
                Module libgio-2.0.so.0 with build-id fc7ccd9c7c26cbb1e938b1c0879f078c2f47d803
                Module libcups.so.2 with build-id 68a2ef2ccefd545e68b78c5acb20bcb2818c5049
                Module libatk-bridge-2.0.so.0 with build-id 1161ebbcc5aa791075dfa026671875e5417287bd
                Module libatk-1.0.so.0 with build-id aacaa40363d304858b654728a893bc212a4ca119
                Module libnspr4.so with build-id c5d12234f7975d11a11e67646533657d014d9540
                Module libsmime3.so with build-id caced12c534af7e258c29547a53aaf3c93a9501a
                Module libnssutil3.so with build-id 0762279c689e9de8745f0a4c120a1d8559f849c2
                Module libnss3.so with build-id ad8cd43ed62aba11f3b40eabb482516773dd9cbc
                Module libglib-2.0.so.0 with build-id 8214b56e554b7cbead4034b6ba32c90bc8c674da
                Module libgobject-2.0.so.0 with build-id 3e451709a0a5772b9550d3a4c28dcb37a87028fa
                Module libpthread.so.0 with build-id 07c8f95b4f3251d08550217ad8a1f31066229996
                Module libdl.so.2 with build-id 5abc547e7b0949f89f3c0e21ab0c8331a7440a8a
                Module chrome with build-id dc2f8d794740d875f9cc1b3ed2b6715b5975a6fa
                Stack trace of thread 391251:
                #0  0x0000557285b3f1e2 n/a (chrome + 0x41a41e2)
                #1  0x0000557285bc1171 n/a (chrome + 0x4226171)
                #2  0x0000557285bc106f n/a (chrome + 0x422606f)
                #3  0x0000557285bc09f0 n/a (chrome + 0x42259f0)
                #4  0x0000557285bc0539 n/a (chrome + 0x4225539)
                #5  0x00005572852ffe95 n/a (chrome + 0x3964e95)
                #6  0x00005572852ff6bd n/a (chrome + 0x39646bd)
                #7  0x00005572852f36a5 n/a (chrome + 0x39586a5)
                #8  0x00005572852bcc92 n/a (chrome + 0x3921c92)
                #9  0x00005572852b9e83 ChromeMain (chrome + 0x391ee83)
                #10 0x00007f14f70aeb25 __libc_start_main (libc.so.6 + 0x27b25)
                #11 0x000055728bdfff7a _start (chrome + 0xa464f7a)

                Stack trace of thread 391274:
                #0  0x00007f14f718592e epoll_wait (libc.so.6 + 0xfe92e)
                #1  0x0000557283babefb n/a (chrome + 0x2210efb)
                #2  0x0000557285311149 n/a (chrome + 0x3976149)
                #3  0x0000557285310f1f n/a (chrome + 0x3975f1f)
                #4  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #5  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #6  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #7  0x00005572853f9fed n/a (chrome + 0x3a5efed)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391272:
                #0  0x00007f14f7152a2f wait4 (libc.so.6 + 0xcba2f)
                #1  0x0000557285964ceb n/a (chrome + 0x3fc9ceb)
                #2  0x000055728871b878 n/a (chrome + 0x6d80878)
                #3  0x0000557285126363 n/a (chrome + 0x378b363)
                #4  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #5  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391277:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391278:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391281:
                #0  0x00007f14f717d201 __select (libc.so.6 + 0xf6201)
                #1  0x000055728871cc65 n/a (chrome + 0x6d81c65)
                #2  0x0000557285126363 n/a (chrome + 0x378b363)
                #3  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #4  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391280:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4fa0d n/a (chrome + 0x22b4a0d)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391275:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391276:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557283c4ff25 n/a (chrome + 0x22b4f25)
                #5  0x0000557283c4f83d n/a (chrome + 0x22b483d)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391273:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31574 pthread_cond_timedwait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf574)
                #2  0x0000557283c510e0 n/a (chrome + 0x22b60e0)
                #3  0x0000557283c50acf n/a (chrome + 0x22b5acf)
                #4  0x0000557288712d87 n/a (chrome + 0x6d77d87)
                #5  0x0000557288712f68 n/a (chrome + 0x6d77f68)
                #6  0x0000557285126363 n/a (chrome + 0x378b363)
                #7  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #8  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391264:
                #0  0x00007f14f717ab2f __poll (libc.so.6 + 0xf3b2f)
                #1  0x00005572843e07c3 n/a (chrome + 0x2a457c3)
                #2  0x0000557285126363 n/a (chrome + 0x378b363)
                #3  0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #4  0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391282:
                #0  0x00007f14f7f378ca __futex_abstimed_wait_common64 (libpthread.so.0 + 0x158ca)
                #1  0x00007f14f7f31270 pthread_cond_wait@@GLIBC_2.3.2 (libpthread.so.0 + 0xf270)
                #2  0x0000557283c50c65 n/a (chrome + 0x22b5c65)
                #3  0x000055728428557e n/a (chrome + 0x28ea57e)
                #4  0x00005572886f0862 n/a (chrome + 0x6d55862)
                #5  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #6  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #7  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)

                Stack trace of thread 391279:
                #0  0x00007f14f718592e epoll_wait (libc.so.6 + 0xfe92e)
                #1  0x0000557283babefb n/a (chrome + 0x2210efb)
                #2  0x0000557285311149 n/a (chrome + 0x3976149)
                #3  0x0000557285310e0a n/a (chrome + 0x3975e0a)
                #4  0x00005572853fabe8 n/a (chrome + 0x3a5fbe8)
                #5  0x00005572853fa20a n/a (chrome + 0x3a5f20a)
                #6  0x00005572853fa048 n/a (chrome + 0x3a5f048)
                #7  0x0000557286fc4052 n/a (chrome + 0x5629052)
                #8  0x00005572852ad47c n/a (chrome + 0x391247c)
                #9  0x0000557285126363 n/a (chrome + 0x378b363)
                #10 0x00007f14f7f2b259 start_thread (libpthread.so.0 + 0x9259)
                #11 0x00007f14f71855e3 __clone (libc.so.6 + 0xfe5e3)
                ELF object binary architecture: AMD x86-64

GNU gdb (GDB) 11.1
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-pc-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from /opt/google/chrome/chrome...
(No debugging symbols found in /opt/google/chrome/chrome)

warning: Can't open file /usr/lib/libzstd.so.1.5.0 during file-backed mapping note processing
[New LWP 391251]
[New LWP 391274]
[New LWP 391272]
[New LWP 391277]
[New LWP 391278]
[New LWP 391281]
[New LWP 391280]
[New LWP 391275]
[New LWP 391276]
[New LWP 391273]
[New LWP 391264]
[New LWP 391282]
[New LWP 391279]

warning: .dynamic section for "/usr/lib/libzstd.so.1" is not at the expected address (wrong library or version mismatch?)
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
Core was generated by `/opt/google/chrome/chrome --enable-crashpad https://www.reddit.com/message/mess'.
Program terminated with signal SIGTRAP, Trace/breakpoint trap.
#0  0x0000557285b3f1e2 in ?? ()
[Current thread is 1 (Thread 0x7f14f5f18cc0 (LWP 391251))]
(gdb) bt
#0  0x0000557285b3f1e2 in  ()
#1  0x000055728c5e9088 in  ()
#2  0x00007ffd6a14d868 in  ()
#3  0x00001e66000842c0 in  ()
#4  0xaaaaaaaaaaaaaaaa in  ()
#5  0x00007ffd6a14d850 in  ()
#6  0x0000557285bc1171 in  ()
#7  0x00000000ffffff00 in  ()
#8  0x00001e6600144600 in  ()
#9  0x00007ffd6a14d880 in  ()
#10 0x0000557285bc106f in  ()
#11 0x00007ffd6a14d8d0 in  ()
#12 0x0000557285000000 in  ()
#13 0x00001e660051a040 in  ()
#14 0x00001e6600558000 in  ()
#15 0x00007ffd6a14d8d0 in  ()
#16 0x0000557285bc09f0 in  ()
#17 0x00001e660051a040 in  ()
#18 0xaaaaaaaaaaaaaaaa in  ()
#19 0x0000000000000000 in  ()
(gdb)

```
systemd, add the following setting in /etc/systemd/system.conf and run systemctl daemon-reexec.
Raw
DefaultLimitCORE=infinity
Now, add the below sysctl parameters.
Raw
fs.suid_dumpable=2
Raw
# sysctl -p

## What is a core file?
A core file is an image of a process that has crashed It contains all process information pertinent to debugging: contents of hardware registers, process status, and process data. Gdb will allow you use this file to determine where your program crashed.


When it starts up, you can use bt (for backtrace) to get a stack trace from the time of the crash. In the backtrace, each function invocation is given a number. You can use frame number (replacing number with the corresponding number in the stack trace) to select a particular stack frame.

You can then use list to see code around that function, and info locals to see the local variables. You can also use print name_of_variable (replacing "name_of_variable" with a variable name) to see its value.


## VSCODE

The C/C++ extension for VS Code also has the ability to debug memory dumps. To debug a memory dump, open your launch.json file and add the coreDumpPath (for GDB or LLDB) or dumpPath (for the Visual Studio Windows Debugger) property to the C++ Launch configuration, set its value to be a string containing the path to the memory dump. This will even work for x86 programs being debugged on an x64 machine.



##
The last line that gdb will print before the "(gdb)" prompt will be something like:

#0 0xef607e54 in main() at line 344 in main.cpp
This corresponds to the last statement that was attempted which likely caused the crash.
You can find out which function called the current function by using the "up" command which will print out a similar line. The "down" command does the opposite of the "up" command. Finally, to view the entire stack frame, use the "backtrace" command or it's abbreviation "bt".



## args

the core file contains the CLI arguments, no need to pass it again



If you want to use gdb without your core, consider

gdb --args ./my_prog arg
or else run just gdb ./my_prog then issue the set args command to gdb.

If your process is still running as pid 1234, you could with gdb ./my_prog 1234 attach the gdb to the running process.


#

the core file contains, among other things, the full stack and heap memory allocated.

Shouldn't that be pretty much constant for such a simple program (give or take a few bytes at the most), hence producing a consistent core between multiple instances?



4096 is the virtual memory page size. When the core dump is created, all of the vm pages assigned to the process will be dumped to the core file. The smaller file is 2933 pages, and the larger file is 2934 pages. So that's fairly consistent. – user3386109 Aug 1 '15 at 19:42





The programs got so large because they were not allocating physical memory, just virtual memory. When GLIBC's malloc() is given a large amount of memory to allocate it request to do so in another virtual memory page from the kernel. For some reason the core file is writing all of the memory, including bytes that never physically existed (this is weird since files in Linux with most file systems can leave file holes). – Veltas Aug 5 '15 at 23:33

- http://stackoverflow.com/questions/13982478/what-is-file-hole-and-how-can-it-be-used




----

The implementation of core dumping can be found in fs/binfmt_elf.c. I'll follow the code in 3.12 and above (it changed with commit 9b56d5438) but the logic is very similar.



The code initially decides how much to dump of a VMA (virtual memory area) in vma_dump_size. For an anonymous VMA such as the brk heap, it returns the full size of the VMA. During this step, the core limit is not involved.

好！

The first phase of writing the core dump then writes a PT_LOAD header for each VMA. This is basically a pointer that says where to find the data in the remainder of the ELF file. The actual data is written by a for loop, and is actually a second phase.



###



 dumped when the appropriate signal it triggered. To get the best results, we’d set the core file size limit everywhere to unlimited and be done with it, but what if you want to limit that to a certain size? I stumble to a small confusion lately when doing this for MySQL, so let me share quickly.

 First, for MySQL, mysqld_safe would use ulimit to set the core-file-size value you pass to it. Now remember according to the manual, this value should be in blocks (some documentation says its in chunks of 1024 bytes). However, according to my experience on CentOS 6, this is the physical block size of the device where your core_pattern is pointed to.
 [root@centos6 ~]# ulimit -a
 ...
 core file size          (blocks, -c) 0

 [root@centos6 ~]# cat /proc/sys/kernel/core_pattern
 /var/tmp/core


 $ cat /proc/sys/kernel/core_pattern
 |/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %h

 $ ll /var/lib/systemd/coredump/
 -rw-r-----+ 1 root root  3932881 Mar 18 19:16 core.offlineimap.1000.455227dc8b2b42969381aa81befa0fa1.13167.1584530161000000000000.lz4
 -rw-r-----+ 1 root root  3926468 Mar 20 08:14 core.offlineimap.1000.455227dc8b2b42969381aa81befa0fa1.549046.1584663241000000000000.lz4
 -rw-r-----+ 1 root root  1899617 Mar 18 16:44 core.pcmanfm.1000.455227dc8b2b42969381aa81befa0fa1.4629.1584521082000000000000.lz4
 -rw-r-----+ 1 root root 64522221 Mar 19 18:10 core.thunderbird.1000.455227dc8b2b42969381aa81befa0fa1.223214.1584612639000000000000.lz4



 [root@centos6 ~]# blockdev --getbsz /dev/sda2
 4096
 [root@centos6 ~]# blockdev --getpbsz /dev/sda2
 512
 1
 2
 3
 4
 5
 6
 7
 8
 9
 10
 11

  [root@centos6 ~]# ulimit -a
  ...
  core file size          (blocks, -c) 0

   [root@centos6 ~]# cat /proc/sys/kernel/core_pattern
   /var/tmp/core

    [root@centos6 ~]# blockdev --getbsz /dev/sda2
    4096
    [root@centos6 ~]# blockdev --getpbsz /dev/sda2
    512

    Based on the above, my core_pattern point to /var, which sits on sda2. This partition according to blockdev has a filesystem blocksize of 4K and a physical block size of 512B. Putting this to the test, say I configure MySQL to a core file size ulimit of 10240, then I would get:
    [root@centos6 ~]# cat /proc/`pidof mysqld`/limits
    Limit                     Soft Limit           Hard Limit           Units
    ...
    Max core file size        5242880              5242880              bytes
    1
    2
    3
    4

      [root@centos6 ~]# cat /proc/`pidof mysqld`/limits
      Limit                     Soft Limit           Hard Limit           Units
      ...
      Max core file size        5242880              5242880              bytes


# Core dump
A core dump is a file containing a process's address space (memory) when the process terminates unexpectedly. Core dumps may be produced on-demand (such as by a debugger), or automatically upon termination.

Core dumps are triggered by the kernel in response to program crashes, and may be passed to a helper program (such as systemd-coredump) for further processing.

# Disable setuid processes dumping their memory

The behavior can be altered with a sysctl key, or directly via the /proc file system.

For permanent settings, the sysctl command and configuration is typically used. A setting is called a ‘key’, which has a related value attached to it (also known as a key-value pair).

To disable program with the setuid bit to dump, set the fs.suid_dumpable to zero.

    echo `fs.suid_dumpable=0` >> /etc/sysctl.conf

Reload the sysctl configuration with the -p flag to activate any changes you made.

    sysctl -p

Just want to test without making permanent changes? Use sysctl -w followed by the key=value.

# Enable Core Dumps

The -c denotes the size of a core dump. `-S` for soft limit.

    ulimit -S -c 0

Allow all processes to use core dumps

    ulimit -S -c unlimited

Set system limit in /etc/security/limits.conf

    * soft core unlimited

# Disable Core Dumps
To disable core dumps for all users, edit /etc/security/limits.conf

    * hard core 0

Save and close the file. Once a hard limit is set, user cannot increase that limit within his own session.

    # echo 'fs.suid_dumpable = 0' >> /etc/sysctl.conf
    # sysctl -p

This will make sure that core dumps can never be made by setuid programs. Finally, add the following to /etc/profile to set a soft limit to stop the creation of core dump files for all users (which is default and must be disabled):

    # echo 'ulimit -S -c 0 > /dev/null 2>&1' >> /etc/profile

- sysctl fs.suid_dumpable key values

    0 - disabled
    1 - enabled
    2 - enabled with restrictions

## configure ulimit via profile
The values for ulimit can also be set via /etc/profile or a custom file in the /etc/profile.d directory. The latter is preferred when it is available. For example by creating a file named /etc/profile.d/disable-coredumps.sh.

    echo “ulimit -c 0 > /dev/null 2>&1` > /etc/profile.d/disable-coredumps.sh

This command adds the setting to a new file and sets both the soft and hard limit to zero. Each user gets this value when logging in.

# Steps to Reproduce
1. journalctl -f
2. systemctl start systemd-hostnamed
3. pkill -e -SEGV systemd-hostnam

Actual results:

journal shows no backtrace and coredumpctl shows no coredump.

Expected results:

Journal shows something like `Process 3271 (systemd-hostnam) of user 0 dumped core.` and a backtrace.


Additional info:

 * This works for `default namespace` processes, like so:
   sleep 100 &
   pkill -e -SEGV sleep
   Then you get a core dump.

 * This works once you disable SELinux (setenforce 0). However, there are no SELinux violations logged.

 * This is not dependent on systemd-coredump. You can do
```

# cat <<EOF > /tmp/core.sh
#!/bin/sh
echo `invoked core dump: $@` >> /tmp/log
cat > /tmp/core
echo `invoked core dump: $@ DONE` >> /tmp/log
EOF
# chmod 755 /tmp/core.sh
# echo `|/tmp/core.sh %P %u` > /proc/sys/kernel/core_pattern

```

# Create normal dump files
This particular setting is done via the sysctl kernel.core_pattern setting or /proc/sys/kernel/core_pattern. Most systems will have a pipe (|) in this setting to indicate that a program needs to take care of the generated data.

You can temporarily change this setting, by echoing `core` to that file, or use the sysctl utility.

    sysctl -w kernel.core_pattern=core

An important note is that this change might not be enough. It depends also on your fs.suid_dumpable setting. A warning will be logged to your kernel logger if that is the case.

> Sep 06 15:51:18 hardening kernel: Unsafe core_pattern used with suid_dumpable=2. Pipe handler or fully qualified core dump path required.

When needed set your core_pattern to a full path, optionally with variables defining who was running it, the PID, etc.

    sysctl -w kernel.core_pattern=/var/crash/core.%u.%e.%p

In this example, our dumps will contain the user id, program name, and process id.

# Change the way the core dump is written

Subsequent core dumps overwrite the previous instead of creating a new file.

Add these lines to /etc/sysctl.conf:

```
kernel.core_uses_pid = 0
kernel.core_pattern = core
```
And run sysctl -p.

Now the core dumps will be named simply core.

# Disable automatic core dumps
Users may wish to disable automatic core dumps for a number of reasons:

  - Performance: generating core dumps for memory-heavy processes can
    waste system resources and delay the cleanup of memory.
  - Disk space: core dumps of memory-heavy processes may consume disk
    space equal to, if not greater, than the process's memory footprint
    if not compressed.
  - Security: core dumps, although typically readable only by root, may
    contain sensitive data (such as passwords or cryptographic keys),
    which are written to disk following a crash.

## Using sysctl

`sysctl` can be used to set the `kernel.core_pattern` to nothing to disable core dump handling.

    cat /etc/sysctl.d/50-coredump.conf
    kernel.core_pattern=|!/bin/false

To apply the setting immediately:

    # sysctl -p /etc/sysctl.d/50-coredump.conf

- https://github.com/systemd/systemd/issues/659#issuecomment-328372788

## Using ulimit

The maximum core dump size is enforced by ulimit. Setting it to zero
disables core dumps entirely.

    cat /etc/security/limits.conf
    * hard core 0

## Using systemd
systemd by default is to generate core dumps for all processes in `/var/lib/systemd/coredump`.

This behavior can be overridden by creating a configuration snippet in the `/etc/systemd/coredump.conf.d/`

Set the Storage setting to ‘none’. Then configure ProcessSizeMax to limited the maximum size to zero.

    cat /etc/systemd/coredump.conf.d/custom.conf
    [[Coredump]]
    Storage=none
    ProcessSizeMax=0

Don't forget to include the `Coredump` section name, otherwise this option will be ignored

    $ sudo systemctl daemon-reload

You might need to override settings via /etc/sysctl.d/50-coredump.conf and define how and where you want to store your core dumps.

This method alone is usually sufficient to disable userspace core dumps,
so long as no other programs enable automatic core dumps on the system,
but the coredump is still generated in memory and systemd-coredump run.

# Systemd core dumps
## Core dump control in `systemd`
Put into `service` file.

    LimitCORE=infinity

When using systemd and the systemd-coredump service, change the coredump.conf file. This file is most likely located at /usr/lib/sysctl.d/50-coredump.conf. As systemd has a set of files, ensure to check the others like:

    /etc/systemd/coredump.conf
    /etc/systemd/coredump.conf.d/*.conf
    /run/systemd/coredump.conf.d/*.conf
    /usr/lib/systemd/coredump.conf.d/*.conf

```
cat /etc/systemd/coredump.conf
#  This file is part of systemd.
#
#  systemd is free software; you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; either version 2.1 of the License, or
#  (at your option) any later version.
#
# Entries in this file show the compile time defaults.
# You can change settings by editing this file.
# Defaults can be restored by simply deleting this file.
#
# See coredump.conf(5) for details.

[Coredump]
#Storage=external
#Compress=yes
#ProcessSizeMax=2G
#ExternalSizeMax=2G
#JournalSizeMax=767M
#MaxUse=
#KeepFree=
```

```
$ sudo apt install systemd-coredump
$ dpkg -L systemd-coredump | grep conf
    /etc/systemd/coredump.conf
    /usr/lib/sysctl.d/50-coredump.conf
    /usr/share/man/man5/coredump.conf.5.gz
    /usr/share/man/man5/coredump.conf.d.5.gz
```

## coredump.conf

```
cat /usr/lib/sysctl.d/50-coredump.conf
#  This file is part of systemd.
#
#  systemd is free software; you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; either version 2.1 of the License, or
#  (at your option) any later version.

# See sysctl.d(5) for the description of the files in this directory,
# and systemd-coredump(8) and core(5) for the explanation of the
# setting below.

kernel.core_pattern=|/lib/systemd/systemd-coredump %P %u %g %s %t 9223372036854775808 %h %e
```

- P: Process name
- u: UID
- g: Boot ID
- s: pid
- t: Time
- e: Ext

The default set might send all core dumps to journald as part of the system logs.

# Making a core dump

## kill a running process by SIGSEGV
SIGSEGV is short for segmentation violation and also known as a segmentation fault.

    kill -s SIGSEGV PID

If you replace PID with “$$` the current program (most likely your shell) will crash.

## Use `gdb`
Attach to the process:

    $ gdb -p 2071

    (gdb) generate-core-file
    Saved corefile core.2071
    (gdb) quit

The `kernel.core_pattern` `sysctl` decides where automatic core dumps go.

    $ cat /proc/sys/kernel/core_pattern
    |/usr/lib/systemd/systemd-coredump %p %u %g %s %t %e

    $ cat /proc/sys/kernel/core_pattern
    |/lib/systemd/systemd-coredump %P %u %g %s %t 9223372036854775808 %h %e

**Note**

If you do not have full-disk encryption, this means your program's memory will be written to raw disk! This is a potential information leak even if you have encrypted swap.

# Examining a core dump

Use *coredumpctl* to find the corresponding dump:

    # coredumpctl list

    TIME                            PID   UID   GID SIG COREFILE  EXE
    Mon 2018-08-13 17:04:29 CST     322  1000  1000   8 present   /path/to/as/a.out
    `
    Tue 2018-11-27 08:53:15 CST    9762  1000  1000  11 missing   /usr/bin/sogou-qimpanel


    'core.a\x2eout.1000.9842428dbdab46be81201ba3044c75e3.322.1534151068000000.lz4'

You need to uniquely identify the relevant dump. This is possible by specifying a `PID`, name of the executable, path to the executable or a journalctl predicate.

    # coredumpctl info $PID

               PID: 322 (a.out)
               UID: 1000 (as)
               GID: 1000 (as)
            Signal: 8 (FPE)
         Timestamp: Mon 2018-08-13 17:04:28 CST (2min 41s ago)
      Command Line: ./a.out
        Executable: /path/to/as/a.out
     Control Group: /user.slice/user-1000.slice/session-3.scope
              Unit: session-3.scope
             Slice: user-1000.slice
           Session: 3
         Owner UID: 1000 (as)
           Boot ID: 9842428dbdab46be81201ba3044c75e3
        Machine ID: f861ca6111b841899436fcdecf2db3e6
          Hostname: i3
           Storage: /var/lib/systemd/coredump/core.a\x2eout.1000.9842428dbdab46be81201ba3044c75e3.322.1534151068000000.lz4
           Message: Process 322 (a.out) of user 1000 dumped core.

                Stack trace of thread 322:
                #0  0x000055ab9c5a5134 main (a.out)
                #1  0x00007f91c9e62b17 __libc_start_main (libc.so.6)
                #2  0x000055ab9c5a506a _start (a.out)

Pay attention to `Signal` row, that helps to identify crash cause. For deeper analysis you can examine the backtrace using `gdb`:

    # coredumpctl gdb $PID

When `gdb` is started, use the `bt` command to print the backtrace:

    (gdb) bt

# Automatic Bug Reporting Tool (ABRT)
- https://fedorahosted.org/abrt/wiki/AbrtDeployment2

In short if abrtd deamon is running then it is what handles creation of core dump files. In this case, you need to configure abrtd deamon via /etc/abrt/abrt.conf.

You may use `BlackList` directive to exclude the binaries.

# Can script dump core?
Yes.

Analysis to be added here.

# Reference
- [american fuzzy lop](http://lcamtuf.coredump.cx/afl/) - An tool for
    automated tests of the kernel and programs
- [Filesystem fuzzing](https://lwn.net/Articles/637151/) - LWN article
    about testing filesystems for bugs
- https://www.freedesktop.org/software/systemd/man/coredump.conf.html
- https://www.freedesktop.org/software/systemd/man/systemd-coredump.html



## Multithread


It appears that your binary is multithreaded and crash happened in some auxiliary thread. You should therefore find main thread and switch to it. Here is an example of how to do it for Firefox with many threads:

(gdb) t a a bt -1

Thread 59 (Thread 0x7f691deff700 (LWP 25924)):
#12 0x00007f69dce93f6f in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:105
..........
..........
many threads are listed here
..........
..........
Thread 1 (Thread 0x7f69de01a740 (LWP 4143)):
#17 0x000056374cb38817 in main ()
(gdb) t 1
[Switching to thread 1 (Thread 0x7f69de01a740 (LWP 4143))]
#0  0x00007f69dce8800d in poll () at ../sysdeps/unix/syscall-template.S:84
84  T_PSEUDO (SYSCALL_SYMBOL, SYSCALL_NAME, SYSCALL_NARGS)
Now gdb is switched to main thread (Thread 1).





gdb <executable> <core-file> or gdb <executable> -c <core-file> or

gdb <executable>
...
(gdb) core <core-file>




$ gdb --args ./crash -p param1 -o param2
GNU gdb (GDB) 7.1-ubuntu
...
(gdb) r
Starting program: /home/@@@@/crash -p param1 -o param2

Program received signal SIGSEGV, Segmentation fault.
__strlen_ia32 () at ../sysdeps/i386/i686/multiarch/../../i586/strlen.S:99
99    ../sysdeps/i386/i686/multiarch/../../i586/strlen.S: No such file or directory.
    in ../sysdeps/i386/i686/multiarch/../../i586/strlen.S
(gdb)









(gdb) where
This will get you with the information, of the stack, where you can analayze the cause of the crash/fault. Other command, for the same purposes is:

...
(gdb) bt full
This is the same as above. By convention, it lists the whole stack information (which ultimately leads to the crash location).




## objdump -s core can be used to dump memory in bulk


##

    man core tells us:

Piping core dumps to a program

Since kernel 2.6.19, Linux supports an alternate syntax for the /proc/sys/kernel/core_pattern file. If the first character of this file is a pipe symbol (|), then the remainder of the line is interpreted as a program to be executed. Instead of being written to a disk file, the core dump is given as standard input to the program.

Note the following points:

The program must be specified using an absolute pathname (or a pathname relative to the root directory, /), and must immediately follow the '|' character.

The process created to run the program runs as user and group root.

Command-line arguments can be supplied to the program (since Linux 2.6.24), delimited by white space (up to a total line length of 128 bytes).

The command-line arguments can include any of the % specifiers listed above. For example, to pass the PID of the process that is being dumped, specify %p in an argument.

You can put a script there, like e.g.

| /path/to/myscript %p %s %c
You can detect which process is triggering the coredump: (man core):

       %%  a single % character
       %p  PID of dumped process
       %u  (numeric) real UID of dumped process
       %g  (numeric) real GID of dumped process
       %s  number of signal causing dump
       %t  time of dump, expressed as seconds since the Epoch,  1970-01-01
           00:00:00 +0000 (UTC)
       %h  hostname (same as nodename returned by uname(2))
       %e  executable filename (without path prefix)
       %E  pathname of executable, with slashes ('/') replaced by exclama‐
           tion marks ('!').
       %c  core file size soft resource limit of crashing  process  (since
           Linux 2.6.24)


Core dump files will be generated after an uncaught signal in a process (as a SIGSEGV or SIGQUIT), in the base directory where the program was executed, and named as `core` or `core.PID`.

For example:
$> ulimit -c unlimited
$> kill -s SIGSEGV $$

This will trigger a segmentation fault in your current shell (you probably guessed it after seeing that the shell session where you executed it was closed), and generate a core file in:
/home/user/core

Now… is it possible to change where that file is generated by default instead of the current directory? And is it possible to change the name of that generated file? The answer is YES! to both. Let’s see how we can get this.

# The Core Pattern in Kernel

Since some years ago, the kernel configuration includes a file named “core_pattern”:
/proc/sys/kernel/core_pattern

In my system, that file contains just this single word:
core

As expected, this pattern shows how the core file will be generated. Two things can be understood from the previous line: The filename of the core dump file generated will be “core”; and second, the current directory will be used to store it (as the path specified is completely relative to the current directory).

Now, if we change the contents of that file… (as root, of course)

$> mkdir -p /tmp/cores
$> chmod a+rwx /tmp/cores
$> echo "/tmp/cores/core.%e.%p.%h.%t" > /proc/sys/kernel/core_pattern

And we run the same as before:

$> cd /home/user
$> ulimit -c unlimited
$> $> kill -s SIGSEGV $$

We get… voilá!
/tmp/cores/core.bash.8539.drehbahn-mbp.1236975953

Not only the program name (“bash“) or the PID (“8539“), but also the hostname (“drehbahn-mbp“) and the unix time (“1236975953“) are appended in the name of the core file!! And of course, it is stored in the absolute path we specified (“/tmp/cores/“).

You can use the following pattern elements in the core_pattern file:

%p: pid
%: '%' is dropped
%%: output one '%'
%u: uid
%g: gid
%s: signal number
%t: UNIX time of dump
%h: hostname
%e: executable filename
%: both are dropped

Isn’t is great?! Imagine that you have a cluster of machines and you want to use a NFS directory to store all core files from all the nodes. You will be able to detect which node generated the core file (with the hostname), which program generated it (with the program name), and also when did it happen (with the unix time).



%p:       pid
%<NUL>:   '%' is dropped
%%:       output one '%'
%u:       uid
%g:       gid
%s:       signal number
%t:       UNIX time of dump
%h:       hostname
%e:       executable filename
%<OTHER>: both are dropped

If core_pattern does not include "%p" (default does not) and core_uses_pid is set, then .PID will be appended to the filename.

example:

    echo "core.%e.%p" > /proc/sys/kernel/core_pattern

produces files names

    core.<executable>.<pid>

to make the changes permanent, add the following line to /etc/sysctl.conf:

    kernel.core_pattern = core.%e.%p

# man 5 core

http://man7.org/linux/man-pages/man5/core.5.html

       The  default  action of certain signals is to cause a process to terminate and produce a core dump file, a disk file containing an image of the process's memory at the time of termination.  This image can be used in a debugger (e.g., gdb(1)) to inspect the state of the program at the time that it termi‐
       nated.  A list of the signals which cause a process to dump core can be found in signal(7).

       A process can set its soft RLIMIT_CORE resource limit to place an upper limit on the size of the core dump file that will be produced if it receives a "core dump" signal; see getrlimit(2) for details.

       There are various circumstances in which a core dump file is not produced:

       *  The process does not have permission to write the core file.  (By default, the core file is called core or core.pid, where pid is the ID of the process that dumped core, and is created in the current working directory.  See below for details on naming.)  Writing the core file fails if  the  directory
          in which it is to be created is nonwritable, or if a file with the same name exists and is not writable or is not a regular file (e.g., it is a directory or a symbolic link).

       *  A (writable, regular) file with the same name as would be used for the core dump already exists, but there is more than one hard link to that file.

       *  The filesystem where the core dump file would be created is full; or has run out of inodes; or is mounted read-only; or the user has reached their quota for the filesystem.

       *  The directory in which the core dump file is to be created does not exist.

       *  The RLIMIT_CORE (core file size) or RLIMIT_FSIZE (file size) resource limits for the process are set to zero; see getrlimit(2) and the documentation of the shell's ulimit command (limit in csh(1)).

       *  The binary being executed by the process does not have read permission enabled.

       *  The  process is executing a set-user-ID (set-group-ID) program that is owned by a user (group) other than the real user (group) ID of the process, or the process is executing a program that has file capabilities (see capabilities(7)).  (However, see the description of the prctl(2) PR_SET_DUMPABLE op‐
          eration, and the description of the /proc/sys/fs/suid_dumpable file in proc(5).)

       *  /proc/sys/kernel/core_pattern is empty and /proc/sys/kernel/core_uses_pid contains the value 0.  (These files are described below.)  Note that if /proc/sys/kernel/core_pattern is empty and /proc/sys/kernel/core_uses_pid contains the value 1, core dump files will have names of the form .pid, and  such
          files are hidden unless one uses the ls(1) -a option.

       *  (Since Linux 3.7) The kernel was configured without the CONFIG_COREDUMP option.

       In addition, a core dump may exclude part of the address space of the process if the madvise(2) MADV_DONTDUMP flag was employed.

       On systems that employ systemd(1) as the init framework, core dumps may instead be placed in a location determined by systemd(1).  See below for further details.

   Naming of core dump files
       By default, a core dump file is named core, but the /proc/sys/kernel/core_pattern file (since Linux 2.6 and 2.4.21) can be set to define a template that is used to name core dump files.  The template can contain % specifiers which are substituted by the following values when a core file is created:

           %%  a single % character
           %c  core file size soft resource limit of crashing process (since Linux 2.6.24)
           %d  dump mode—same as value returned by prctl(2) PR_GET_DUMPABLE (since Linux 3.7)
           %e  executable filename (without path prefix)
           %E  pathname of executable, with slashes ('/') replaced by exclamation marks ('!') (since Linux 3.0).
           %g  (numeric) real GID of dumped process
           %h  hostname (same as nodename returned by uname(2))
           %i  TID of thread that triggered core dump, as seen in the PID namespace in which the thread resides (since Linux 3.18)
           %I  TID of thread that triggered core dump, as seen in the initial PID namespace (since Linux 3.18)
           %p  PID of dumped process, as seen in the PID namespace in which the process resides
           %P  PID of dumped process, as seen in the initial PID namespace (since Linux 3.12)
           %s  number of signal causing dump
           %t  time of dump, expressed as seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC)
           %u  (numeric) real UID of dumped process

       A single % at the end of the template is dropped from the core filename, as is the combination of a % followed by any character other than those listed above.  All other characters in the template become a literal part of the core filename.  The template may include '/' characters, which are interpreted
       as delimiters for directory names.  The maximum size of the resulting core filename is 128 bytes (64 bytes in kernels before 2.6.19).  The default value in this file is "core".  For backward compatibility, if /proc/sys/kernel/core_pattern does not include %p and /proc/sys/kernel/core_uses_pid  (see  be‐
       low) is nonzero, then .PID will be appended to the core filename.

       Paths are interpreted according to the settings that are active for the crashing process.  That means the crashing process's mount namespace (see mount_namespaces(7)), its current working directory (found via getcwd(2)), and its root directory (see chroot(2)).

       Since  version  2.4,  Linux  has also provided a more primitive method of controlling the name of the core dump file.  If the /proc/sys/kernel/core_uses_pid file contains the value 0, then a core dump file is simply named core.  If this file contains a nonzero value, then the core dump file includes the
       process ID in a name of the form core.PID.

       Since Linux 3.6, if /proc/sys/fs/suid_dumpable is set to 2 ("suidsafe"), the pattern must be either an absolute pathname (starting with a leading '/' character) or a pipe, as defined below.

   Piping core dumps to a program
       Since kernel 2.6.19, Linux supports an alternate syntax for the /proc/sys/kernel/core_pattern file.  If the first character of this file is a pipe symbol (|), then the remainder of the line is interpreted as the command-line for a user-space program (or script) that is to be executed.  Instead of  being
       written to a disk file, the core dump is given as standard input to the program.  Note the following points:

       *  The program must be specified using an absolute pathname (or a pathname relative to the root directory, /), and must immediately follow the '|' character.

       *  The command-line arguments can include any of the % specifiers listed above.  For example, to pass the PID of the process that is being dumped, specify %p in an argument.

       *  The process created to run the program runs as user and group root.

       *  Running as root does not confer any exceptional security bypasses.  Namely, LSMs (e.g., SELinux) are still active and may prevent the handler from accessing details about the crashed process via /proc/[pid].

       *  The program pathname is interpreted with respect to the initial mount namespace as it is always executed there.  It is not affected by the settings (e.g., root directory, mount namespace, current working directory) of the crashing process.

       *  The process runs in the initial namespaces (PID, mount, user, and so on) and not in the namespaces of the crashing process.  One can utilize specifiers such as %P to find the right /proc/[pid] directory and probe/enter the crashing process's namespaces if needed.

       *  The process starts with its current working directory as the root directory.  If desired, it is possible change to the working directory of the dumping process by employing the value provided by the %P specifier to change to the location of the dumping process via /proc/[pid]/cwd.

       *  Command-line arguments can be supplied to the program (since Linux 2.6.24), delimited by white space (up to a total line length of 128 bytes).

       *  The RLIMIT_CORE limit is not enforced for core dumps that are piped to a program via this mechanism.

   /proc/sys/kernel/core_pipe_limit
       When collecting core dumps via a pipe to a user-space program, it can be useful for the collecting program to gather data about the crashing process from that process's /proc/[pid] directory.  In order to do this safely, the kernel must wait for the program collecting the core dump to exit, so as not to
       remove the crashing process's /proc/[pid] files prematurely.  This in turn creates the possibility that a misbehaving collecting program can block the reaping of a crashed process by simply never exiting.

       Since Linux 2.6.32, the /proc/sys/kernel/core_pipe_limit can be used to defend against this possibility.  The value in this file defines how many concurrent crashing processes may be piped to user-space programs in parallel.  If this value is exceeded, then those crashing processes above this value  are
       noted in the kernel log and their core dumps are skipped.

       A value of 0 in this file is special.  It indicates that unlimited processes may be captured in parallel, but that no waiting will take place (i.e., the collecting program is not guaranteed access to /proc/<crashing-PID>).  The default value for this file is 0.

   Controlling which mappings are written to the core dump
       Since kernel 2.6.23, the Linux-specific /proc/[pid]/coredump_filter file can be used to control which memory segments are written to the core dump file in the event that a core dump is performed for the process with the corresponding process ID.

       The value in the file is a bit mask of memory mapping types (see mmap(2)).  If a bit is set in the mask, then memory mappings of the corresponding type are dumped; otherwise they are not dumped.  The bits in this file have the following meanings:

           bit 0  Dump anonymous private mappings.
           bit 1  Dump anonymous shared mappings.
           bit 2  Dump file-backed private mappings.
           bit 3  Dump file-backed shared mappings.
           bit 4 (since Linux 2.6.24)
                  Dump ELF headers.
           bit 5 (since Linux 2.6.28)
                  Dump private huge pages.
           bit 6 (since Linux 2.6.28)
                  Dump shared huge pages.
           bit 7 (since Linux 4.4)
                  Dump private DAX pages.
           bit 8 (since Linux 4.4)
                  Dump shared DAX pages.

       By default, the following bits are set: 0, 1, 4 (if the CONFIG_CORE_DUMP_DEFAULT_ELF_HEADERS kernel configuration option is enabled), and 5.  This default can be modified at boot time using the coredump_filter boot option.

       The value of this file is displayed in hexadecimal.  (The default value is thus displayed as 33.)

       Memory-mapped I/O pages such as frame buffer are never dumped, and virtual DSO pages are always dumped, regardless of the coredump_filter value.

       A child process created via fork(2) inherits its parent's coredump_filter value; the coredump_filter value is preserved across an execve(2).

       It can be useful to set coredump_filter in the parent shell before running a program, for example:

           $ echo 0x7 > /proc/self/coredump_filter
           $ ./some_program

       This file is provided only if the kernel was built with the CONFIG_ELF_CORE configuration option.

   Core dumps and systemd
       On  systems  using the systemd(1) init framework, core dumps may be placed in a location determined by systemd(1).  To do this, systemd(1) employs the core_pattern feature that allows piping core dumps to a program.  One can verify this by checking whether core dumps are being piped to the systemd-core‐
       dump(8) program:

           $ cat /proc/sys/kernel/core_pattern
           |/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %e

       In this case, core dumps will be placed in the location configured for systemd-coredump(8), typically as lz4(1) compressed files in the directory /var/lib/systemd/coredump/.  One can list the core dumps that have been recorded by systemd-coredump(8) using coredumpctl(1):

         $ coredumpctl list | tail -5
         Wed 2017-10-11 22:25:30 CEST  2748 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:29:10 CEST  2716 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:30:50 CEST  2767 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:37:40 CEST  2918 1000 1000 3 present  /usr/bin/cat
         Thu 2017-10-12 08:13:07 CEST  2955 1000 1000 3 present  /usr/bin/cat

       The information shown for each core dump includes the date and time of the dump, the PID, UID, and GID  of the dumping process, the signal number that caused the core dump, and the pathname of the executable that was being run by the dumped process.  Various options to coredumpctl(1) allow  a  specified
       coredump file to be pulled from the systemd(1) location into a specified file.  For example, to extract the core dump for PID 2955 shown above to a file named core in the current directory, one could use:

           $ coredumpctl dump 2955 -o core

       For more extensive details, see the coredumpctl(1) manual page.

       To disable the systemd(1) mechanism that archives core dumps, restoring to something more like traditional Linux behavior, one can set an override for the systemd(1) mechanism, using something like:

         # echo "kernel.core_pattern=core.%p" > /etc/sysctl.d/50-coredump.conf
         # /lib/systemd/systemd-sysctl

NOTES
       The gdb(1) gcore command can be used to obtain a core dump of a running process.

       In  Linux versions up to and including 2.6.27, if a multithreaded process (or, more precisely, a process that shares its memory with another process by being created with the CLONE_VM flag of clone(2)) dumps core, then the process ID is always appended to the core filename, unless the process ID was al‐
       ready included elsewhere in the filename via a %p specification in /proc/sys/kernel/core_pattern.  (This is primarily useful when employing the obsolete LinuxThreads implementation, where each thread of a process has a different PID.)

示例处理程序展示了pipe语法。

    $ cc -o core_pattern_pipe_test core_pattern_pipe_test.c
    $ su
    Password:
    # echo "|$PWD/core_pattern_pipe_test %p UID=%u GID=%g sig=%s" > \
        /proc/sys/kernel/core_pattern
    # exit
    $ sleep 100
    ^\                     # type control-backslash
    Quit (core dumped)

    $ cat core.info
    argc=5
    argc[0]=</to/work/core_pattern_pipe_test>
    argc[1]=<9272>
    argc[2]=<UID=1000>
    argc[3]=<GID=1000>
    argc[4]=<sig=3>
    Total bytes in core dump: 393216

示例处理程序源代码如下。

       /* core_pattern_pipe_test.c */

       #define _GNU_SOURCE
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <limits.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>

       #define BUF_SIZE 1024

       int
       main(int argc, char *argv[])
       {
           int tot, j;
           ssize_t nread;
           char buf[BUF_SIZE];
           FILE *fp;
           char cwd[PATH_MAX];

           /* Change our current working directory to that of the
              crashing process */

           snprintf(cwd, PATH_MAX, "/proc/%s/cwd", argv[1]);
           chdir(cwd);

           /* Write output to file "core.info" in that directory */

           fp = fopen("core.info", "w+");
           if (fp == NULL)
               exit(EXIT_FAILURE);

           /* Display command-line arguments given to core_pattern
              pipe program */

           fprintf(fp, "argc=%d\n", argc);
           for (j = 0; j < argc; j++)
               fprintf(fp, "argc[%d]=<%s>\n", j, argv[j]);

           /* Count bytes in standard input (the core dump) */

           tot = 0;
           while ((nread = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
               tot += nread;
           fprintf(fp, "Total bytes in core dump: %d\n", tot);

           fclose(fp);
           exit(EXIT_SUCCESS);
       }


#

the core file contains, among other things, the full stack and heap memory allocated.

Shouldn't that be pretty much constant for such a simple program (give or take a few bytes at the most), hence producing a consistent core between multiple instances?



4096 is the virtual memory page size. When the core dump is created, all of the vm pages assigned to the process will be dumped to the core file. The smaller file is 2933 pages, and the larger file is 2934 pages. So that's fairly consistent. – user3386109 Aug 1 '15 at 19:42





The programs got so large because they were not allocating physical memory, just virtual memory. When GLIBC's malloc() is given a large amount of memory to allocate it request to do so in another virtual memory page from the kernel. For some reason the core file is writing all of the memory, including bytes that never physically existed (this is weird since files in Linux with most file systems can leave file holes). – Veltas Aug 5 '15 at 23:33

- http://stackoverflow.com/questions/13982478/what-is-file-hole-and-how-can-it-be-used




----

The implementation of core dumping can be found in fs/binfmt_elf.c. I'll follow the code in 3.12 and above (it changed with commit 9b56d5438) but the logic is very similar.



The code initially decides how much to dump of a VMA (virtual memory area) in vma_dump_size. For an anonymous VMA such as the brk heap, it returns the full size of the VMA. During this step, the core limit is not involved.

好！

The first phase of writing the core dump then writes a PT_LOAD header for each VMA. This is basically a pointer that says where to find the data in the remainder of the ELF file. The actual data is written by a for loop, and is actually a second phase.



###



 dumped when the appropriate signal it triggered. To get the best results, we’d set the core file size limit everywhere to unlimited and be done with it, but what if you want to limit that to a certain size? I stumble to a small confusion lately when doing this for MySQL, so let me share quickly.

 First, for MySQL, mysqld_safe would use ulimit to set the core-file-size value you pass to it. Now remember according to the manual, this value should be in blocks (some documentation says its in chunks of 1024 bytes). However, according to my experience on CentOS 6, this is the physical block size of the device where your core_pattern is pointed to.
 [root@centos6 ~]# ulimit -a
 ...
 core file size          (blocks, -c) 0

 [root@centos6 ~]# cat /proc/sys/kernel/core_pattern
 /var/tmp/core


 $ cat /proc/sys/kernel/core_pattern
 |/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %h

 $ ll /var/lib/systemd/coredump/
 -rw-r-----+ 1 root root  3932881 Mar 18 19:16 core.offlineimap.1000.455227dc8b2b42969381aa81befa0fa1.13167.1584530161000000000000.lz4
 -rw-r-----+ 1 root root  3926468 Mar 20 08:14 core.offlineimap.1000.455227dc8b2b42969381aa81befa0fa1.549046.1584663241000000000000.lz4
 -rw-r-----+ 1 root root  1899617 Mar 18 16:44 core.pcmanfm.1000.455227dc8b2b42969381aa81befa0fa1.4629.1584521082000000000000.lz4
 -rw-r-----+ 1 root root 64522221 Mar 19 18:10 core.thunderbird.1000.455227dc8b2b42969381aa81befa0fa1.223214.1584612639000000000000.lz4



 [root@centos6 ~]# blockdev --getbsz /dev/sda2
 4096
 [root@centos6 ~]# blockdev --getpbsz /dev/sda2
 512
 1
 2
 3
 4
 5
 6
 7
 8
 9
 10
 11

  [root@centos6 ~]# ulimit -a
  ...
  core file size          (blocks, -c) 0

   [root@centos6 ~]# cat /proc/sys/kernel/core_pattern
   /var/tmp/core

    [root@centos6 ~]# blockdev --getbsz /dev/sda2
    4096
    [root@centos6 ~]# blockdev --getpbsz /dev/sda2
    512

    Based on the above, my core_pattern point to /var, which sits on sda2. This partition according to blockdev has a filesystem blocksize of 4K and a physical block size of 512B. Putting this to the test, say I configure MySQL to a core file size ulimit of 10240, then I would get:
    [root@centos6 ~]# cat /proc/`pidof mysqld`/limits
    Limit                     Soft Limit           Hard Limit           Units
    ...
    Max core file size        5242880              5242880              bytes
    1
    2
    3
    4

      [root@centos6 ~]# cat /proc/`pidof mysqld`/limits
      Limit                     Soft Limit           Hard Limit           Units
      ...
      Max core file size        5242880              5242880              bytes


# Core dump
A core dump is a file containing a process's address space (memory) when the process terminates unexpectedly. Core dumps may be produced on-demand (such as by a debugger), or automatically upon termination.

Core dumps are triggered by the kernel in response to program crashes, and may be passed to a helper program (such as systemd-coredump) for further processing.

# Disable setuid processes dumping their memory

The behavior can be altered with a sysctl key, or directly via the /proc file system.

For permanent settings, the sysctl command and configuration is typically used. A setting is called a ‘key’, which has a related value attached to it (also known as a key-value pair).

To disable program with the setuid bit to dump, set the fs.suid_dumpable to zero.

    echo `fs.suid_dumpable=0` >> /etc/sysctl.conf

Reload the sysctl configuration with the -p flag to activate any changes you made.

    sysctl -p

Just want to test without making permanent changes? Use sysctl -w followed by the key=value.

# Enable Core Dumps

The -c denotes the size of a core dump. `-S` for soft limit.

    ulimit -S -c 0

Allow all processes to use core dumps

    ulimit -S -c unlimited

Set system limit in /etc/security/limits.conf

    * soft core unlimited

# Disable Core Dumps
To disable core dumps for all users, edit /etc/security/limits.conf

    * hard core 0

Save and close the file. Once a hard limit is set, user cannot increase that limit within his own session.

    # echo 'fs.suid_dumpable = 0' >> /etc/sysctl.conf
    # sysctl -p

This will make sure that core dumps can never be made by setuid programs. Finally, add the following to /etc/profile to set a soft limit to stop the creation of core dump files for all users (which is default and must be disabled):

    # echo 'ulimit -S -c 0 > /dev/null 2>&1' >> /etc/profile

- sysctl fs.suid_dumpable key values

    0 - disabled
    1 - enabled
    2 - enabled with restrictions

## configure ulimit via profile
The values for ulimit can also be set via /etc/profile or a custom file in the /etc/profile.d directory. The latter is preferred when it is available. For example by creating a file named /etc/profile.d/disable-coredumps.sh.

    echo “ulimit -c 0 > /dev/null 2>&1` > /etc/profile.d/disable-coredumps.sh

This command adds the setting to a new file and sets both the soft and hard limit to zero. Each user gets this value when logging in.

# Steps to Reproduce
1. journalctl -f
2. systemctl start systemd-hostnamed
3. pkill -e -SEGV systemd-hostnam

Actual results:

journal shows no backtrace and coredumpctl shows no coredump.

Expected results:

Journal shows something like `Process 3271 (systemd-hostnam) of user 0 dumped core.` and a backtrace.


Additional info:

 * This works for `default namespace` processes, like so:
   sleep 100 &
   pkill -e -SEGV sleep
   Then you get a core dump.

 * This works once you disable SELinux (setenforce 0). However, there are no SELinux violations logged.

 * This is not dependent on systemd-coredump. You can do
```

# cat <<EOF > /tmp/core.sh
#!/bin/sh
echo `invoked core dump: $@` >> /tmp/log
cat > /tmp/core
echo `invoked core dump: $@ DONE` >> /tmp/log
EOF
# chmod 755 /tmp/core.sh
# echo `|/tmp/core.sh %P %u` > /proc/sys/kernel/core_pattern

```

# Create normal dump files
This particular setting is done via the sysctl kernel.core_pattern setting or /proc/sys/kernel/core_pattern. Most systems will have a pipe (|) in this setting to indicate that a program needs to take care of the generated data.

You can temporarily change this setting, by echoing `core` to that file, or use the sysctl utility.

    sysctl -w kernel.core_pattern=core

An important note is that this change might not be enough. It depends also on your fs.suid_dumpable setting. A warning will be logged to your kernel logger if that is the case.

> Sep 06 15:51:18 hardening kernel: Unsafe core_pattern used with suid_dumpable=2. Pipe handler or fully qualified core dump path required.

When needed set your core_pattern to a full path, optionally with variables defining who was running it, the PID, etc.

    sysctl -w kernel.core_pattern=/var/crash/core.%u.%e.%p

In this example, our dumps will contain the user id, program name, and process id.

# Change the way the core dump is written

Subsequent core dumps overwrite the previous instead of creating a new file.

Add these lines to /etc/sysctl.conf:

```
kernel.core_uses_pid = 0
kernel.core_pattern = core
```
And run sysctl -p.

Now the core dumps will be named simply core.

# Disable automatic core dumps
Users may wish to disable automatic core dumps for a number of reasons:

  - Performance: generating core dumps for memory-heavy processes can
    waste system resources and delay the cleanup of memory.
  - Disk space: core dumps of memory-heavy processes may consume disk
    space equal to, if not greater, than the process's memory footprint
    if not compressed.
  - Security: core dumps, although typically readable only by root, may
    contain sensitive data (such as passwords or cryptographic keys),
    which are written to disk following a crash.

## Using sysctl

`sysctl` can be used to set the `kernel.core_pattern` to nothing to disable core dump handling.

    cat /etc/sysctl.d/50-coredump.conf
    kernel.core_pattern=|!/bin/false

To apply the setting immediately:

    # sysctl -p /etc/sysctl.d/50-coredump.conf

- https://github.com/systemd/systemd/issues/659#issuecomment-328372788

## Using ulimit

The maximum core dump size is enforced by ulimit. Setting it to zero
disables core dumps entirely.

    cat /etc/security/limits.conf
    * hard core 0

## Using systemd
systemd by default is to generate core dumps for all processes in `/var/lib/systemd/coredump`.

This behavior can be overridden by creating a configuration snippet in the `/etc/systemd/coredump.conf.d/`

Set the Storage setting to ‘none’. Then configure ProcessSizeMax to limited the maximum size to zero.

    cat /etc/systemd/coredump.conf.d/custom.conf
    [[Coredump]]
    Storage=none
    ProcessSizeMax=0

Don't forget to include the `Coredump` section name, otherwise this option will be ignored

    $ sudo systemctl daemon-reload

You might need to override settings via /etc/sysctl.d/50-coredump.conf and define how and where you want to store your core dumps.

This method alone is usually sufficient to disable userspace core dumps,
so long as no other programs enable automatic core dumps on the system,
but the coredump is still generated in memory and systemd-coredump run.

# Systemd core dumps
## Core dump control in `systemd`
Put into `service` file.

    LimitCORE=infinity

When using systemd and the systemd-coredump service, change the coredump.conf file. This file is most likely located at /usr/lib/sysctl.d/50-coredump.conf. As systemd has a set of files, ensure to check the others like:

    /etc/systemd/coredump.conf
    /etc/systemd/coredump.conf.d/*.conf
    /run/systemd/coredump.conf.d/*.conf
    /usr/lib/systemd/coredump.conf.d/*.conf

```
cat /etc/systemd/coredump.conf
#  This file is part of systemd.
#
#  systemd is free software; you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; either version 2.1 of the License, or
#  (at your option) any later version.
#
# Entries in this file show the compile time defaults.
# You can change settings by editing this file.
# Defaults can be restored by simply deleting this file.
#
# See coredump.conf(5) for details.

[Coredump]
#Storage=external
#Compress=yes
#ProcessSizeMax=2G
#ExternalSizeMax=2G
#JournalSizeMax=767M
#MaxUse=
#KeepFree=
```

```
$ sudo apt install systemd-coredump
$ dpkg -L systemd-coredump | grep conf
    /etc/systemd/coredump.conf
    /usr/lib/sysctl.d/50-coredump.conf
    /usr/share/man/man5/coredump.conf.5.gz
    /usr/share/man/man5/coredump.conf.d.5.gz
```

## coredump.conf

```
cat /usr/lib/sysctl.d/50-coredump.conf
#  This file is part of systemd.
#
#  systemd is free software; you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; either version 2.1 of the License, or
#  (at your option) any later version.

# See sysctl.d(5) for the description of the files in this directory,
# and systemd-coredump(8) and core(5) for the explanation of the
# setting below.

kernel.core_pattern=|/lib/systemd/systemd-coredump %P %u %g %s %t 9223372036854775808 %h %e
```

- P: Process name
- u: UID
- g: Boot ID
- s: pid
- t: Time
- e: Ext

The default set might send all core dumps to journald as part of the system logs.

# Making a core dump

## kill a running process by SIGSEGV
SIGSEGV is short for segmentation violation and also known as a segmentation fault.

    kill -s SIGSEGV PID

If you replace PID with “$$` the current program (most likely your shell) will crash.

## Use `gdb`
Attach to the process:

    $ gdb -p 2071

    (gdb) generate-core-file
    Saved corefile core.2071
    (gdb) quit

The `kernel.core_pattern` `sysctl` decides where automatic core dumps go.

    $ cat /proc/sys/kernel/core_pattern
    |/usr/lib/systemd/systemd-coredump %p %u %g %s %t %e

    $ cat /proc/sys/kernel/core_pattern
    |/lib/systemd/systemd-coredump %P %u %g %s %t 9223372036854775808 %h %e

**Note**

If you do not have full-disk encryption, this means your program's memory will be written to raw disk! This is a potential information leak even if you have encrypted swap.

# Examining a core dump

Use *coredumpctl* to find the corresponding dump:

    # coredumpctl list

    TIME                            PID   UID   GID SIG COREFILE  EXE
    Mon 2018-08-13 17:04:29 CST     322  1000  1000   8 present   /path/to/as/a.out
    `
    Tue 2018-11-27 08:53:15 CST    9762  1000  1000  11 missing   /usr/bin/sogou-qimpanel


    'core.a\x2eout.1000.9842428dbdab46be81201ba3044c75e3.322.1534151068000000.lz4'

You need to uniquely identify the relevant dump. This is possible by specifying a `PID`, name of the executable, path to the executable or a journalctl predicate.

    # coredumpctl info $PID

               PID: 322 (a.out)
               UID: 1000 (as)
               GID: 1000 (as)
            Signal: 8 (FPE)
         Timestamp: Mon 2018-08-13 17:04:28 CST (2min 41s ago)
      Command Line: ./a.out
        Executable: /path/to/as/a.out
     Control Group: /user.slice/user-1000.slice/session-3.scope
              Unit: session-3.scope
             Slice: user-1000.slice
           Session: 3
         Owner UID: 1000 (as)
           Boot ID: 9842428dbdab46be81201ba3044c75e3
        Machine ID: f861ca6111b841899436fcdecf2db3e6
          Hostname: i3
           Storage: /var/lib/systemd/coredump/core.a\x2eout.1000.9842428dbdab46be81201ba3044c75e3.322.1534151068000000.lz4
           Message: Process 322 (a.out) of user 1000 dumped core.

                Stack trace of thread 322:
                #0  0x000055ab9c5a5134 main (a.out)
                #1  0x00007f91c9e62b17 __libc_start_main (libc.so.6)
                #2  0x000055ab9c5a506a _start (a.out)

Pay attention to `Signal` row, that helps to identify crash cause. For deeper analysis you can examine the backtrace using `gdb`:

    # coredumpctl gdb $PID

When `gdb` is started, use the `bt` command to print the backtrace:

    (gdb) bt

# Automatic Bug Reporting Tool (ABRT)
- https://fedorahosted.org/abrt/wiki/AbrtDeployment2

In short if abrtd deamon is running then it is what handles creation of core dump files. In this case, you need to configure abrtd deamon via /etc/abrt/abrt.conf.

You may use `BlackList` directive to exclude the binaries.

# Can script dump core?
Yes.

Analysis to be added here.

# Reference
- [american fuzzy lop](http://lcamtuf.coredump.cx/afl/) - An tool for
    automated tests of the kernel and programs
- [Filesystem fuzzing](https://lwn.net/Articles/637151/) - LWN article
    about testing filesystems for bugs
- https://www.freedesktop.org/software/systemd/man/coredump.conf.html
- https://www.freedesktop.org/software/systemd/man/systemd-coredump.html



## Multithread


It appears that your binary is multithreaded and crash happened in some auxiliary thread. You should therefore find main thread and switch to it. Here is an example of how to do it for Firefox with many threads:

(gdb) t a a bt -1

Thread 59 (Thread 0x7f691deff700 (LWP 25924)):
#12 0x00007f69dce93f6f in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:105
..........
..........
many threads are listed here
..........
..........
Thread 1 (Thread 0x7f69de01a740 (LWP 4143)):
#17 0x000056374cb38817 in main ()
(gdb) t 1
[Switching to thread 1 (Thread 0x7f69de01a740 (LWP 4143))]
#0  0x00007f69dce8800d in poll () at ../sysdeps/unix/syscall-template.S:84
84  T_PSEUDO (SYSCALL_SYMBOL, SYSCALL_NAME, SYSCALL_NARGS)
Now gdb is switched to main thread (Thread 1).





gdb <executable> <core-file> or gdb <executable> -c <core-file> or

gdb <executable>
...
(gdb) core <core-file>




$ gdb --args ./crash -p param1 -o param2
GNU gdb (GDB) 7.1-ubuntu
...
(gdb) r
Starting program: /home/@@@@/crash -p param1 -o param2

Program received signal SIGSEGV, Segmentation fault.
__strlen_ia32 () at ../sysdeps/i386/i686/multiarch/../../i586/strlen.S:99
99    ../sysdeps/i386/i686/multiarch/../../i586/strlen.S: No such file or directory.
    in ../sysdeps/i386/i686/multiarch/../../i586/strlen.S
(gdb)









(gdb) where
This will get you with the information, of the stack, where you can analayze the cause of the crash/fault. Other command, for the same purposes is:

...
(gdb) bt full
This is the same as above. By convention, it lists the whole stack information (which ultimately leads to the crash location).




## objdump -s core can be used to dump memory in bulk


##

    man core tells us:

Piping core dumps to a program

Since kernel 2.6.19, Linux supports an alternate syntax for the /proc/sys/kernel/core_pattern file. If the first character of this file is a pipe symbol (|), then the remainder of the line is interpreted as a program to be executed. Instead of being written to a disk file, the core dump is given as standard input to the program.

Note the following points:

The program must be specified using an absolute pathname (or a pathname relative to the root directory, /), and must immediately follow the '|' character.

The process created to run the program runs as user and group root.

Command-line arguments can be supplied to the program (since Linux 2.6.24), delimited by white space (up to a total line length of 128 bytes).

The command-line arguments can include any of the % specifiers listed above. For example, to pass the PID of the process that is being dumped, specify %p in an argument.

You can put a script there, like e.g.

| /path/to/myscript %p %s %c
You can detect which process is triggering the coredump: (man core):

       %%  a single % character
       %p  PID of dumped process
       %u  (numeric) real UID of dumped process
       %g  (numeric) real GID of dumped process
       %s  number of signal causing dump
       %t  time of dump, expressed as seconds since the Epoch,  1970-01-01
           00:00:00 +0000 (UTC)
       %h  hostname (same as nodename returned by uname(2))
       %e  executable filename (without path prefix)
       %E  pathname of executable, with slashes ('/') replaced by exclama‐
           tion marks ('!').
       %c  core file size soft resource limit of crashing  process  (since
           Linux 2.6.24)


Core dump files will be generated after an uncaught signal in a process (as a SIGSEGV or SIGQUIT), in the base directory where the program was executed, and named as `core` or `core.PID`.

For example:
$> ulimit -c unlimited
$> kill -s SIGSEGV $$

This will trigger a segmentation fault in your current shell (you probably guessed it after seeing that the shell session where you executed it was closed), and generate a core file in:
/home/user/core

Now… is it possible to change where that file is generated by default instead of the current directory? And is it possible to change the name of that generated file? The answer is YES! to both. Let’s see how we can get this.

# The Core Pattern in Kernel

Since some years ago, the kernel configuration includes a file named “core_pattern”:
/proc/sys/kernel/core_pattern

In my system, that file contains just this single word:
core

As expected, this pattern shows how the core file will be generated. Two things can be understood from the previous line: The filename of the core dump file generated will be “core”; and second, the current directory will be used to store it (as the path specified is completely relative to the current directory).

Now, if we change the contents of that file… (as root, of course)

$> mkdir -p /tmp/cores
$> chmod a+rwx /tmp/cores
$> echo "/tmp/cores/core.%e.%p.%h.%t" > /proc/sys/kernel/core_pattern

And we run the same as before:

$> cd /home/user
$> ulimit -c unlimited
$> $> kill -s SIGSEGV $$

We get… voilá!
/tmp/cores/core.bash.8539.drehbahn-mbp.1236975953

Not only the program name (“bash“) or the PID (“8539“), but also the hostname (“drehbahn-mbp“) and the unix time (“1236975953“) are appended in the name of the core file!! And of course, it is stored in the absolute path we specified (“/tmp/cores/“).

You can use the following pattern elements in the core_pattern file:

%p: pid
%: '%' is dropped
%%: output one '%'
%u: uid
%g: gid
%s: signal number
%t: UNIX time of dump
%h: hostname
%e: executable filename
%: both are dropped

Isn’t is great?! Imagine that you have a cluster of machines and you want to use a NFS directory to store all core files from all the nodes. You will be able to detect which node generated the core file (with the hostname), which program generated it (with the program name), and also when did it happen (with the unix time).



%p:       pid
%<NUL>:   '%' is dropped
%%:       output one '%'
%u:       uid
%g:       gid
%s:       signal number
%t:       UNIX time of dump
%h:       hostname
%e:       executable filename
%<OTHER>: both are dropped

If core_pattern does not include "%p" (default does not) and core_uses_pid is set, then .PID will be appended to the filename.

example:

    echo "core.%e.%p" > /proc/sys/kernel/core_pattern

produces files names

    core.<executable>.<pid>

to make the changes permanent, add the following line to /etc/sysctl.conf:

    kernel.core_pattern = core.%e.%p

# man 5 core

http://man7.org/linux/man-pages/man5/core.5.html

       The  default  action of certain signals is to cause a process to terminate and produce a core dump file, a disk file containing an image of the process's memory at the time of termination.  This image can be used in a debugger (e.g., gdb(1)) to inspect the state of the program at the time that it termi‐
       nated.  A list of the signals which cause a process to dump core can be found in signal(7).

       A process can set its soft RLIMIT_CORE resource limit to place an upper limit on the size of the core dump file that will be produced if it receives a "core dump" signal; see getrlimit(2) for details.

       There are various circumstances in which a core dump file is not produced:

       *  The process does not have permission to write the core file.  (By default, the core file is called core or core.pid, where pid is the ID of the process that dumped core, and is created in the current working directory.  See below for details on naming.)  Writing the core file fails if  the  directory
          in which it is to be created is nonwritable, or if a file with the same name exists and is not writable or is not a regular file (e.g., it is a directory or a symbolic link).

       *  A (writable, regular) file with the same name as would be used for the core dump already exists, but there is more than one hard link to that file.

       *  The filesystem where the core dump file would be created is full; or has run out of inodes; or is mounted read-only; or the user has reached their quota for the filesystem.

       *  The directory in which the core dump file is to be created does not exist.

       *  The RLIMIT_CORE (core file size) or RLIMIT_FSIZE (file size) resource limits for the process are set to zero; see getrlimit(2) and the documentation of the shell's ulimit command (limit in csh(1)).

       *  The binary being executed by the process does not have read permission enabled.

       *  The  process is executing a set-user-ID (set-group-ID) program that is owned by a user (group) other than the real user (group) ID of the process, or the process is executing a program that has file capabilities (see capabilities(7)).  (However, see the description of the prctl(2) PR_SET_DUMPABLE op‐
          eration, and the description of the /proc/sys/fs/suid_dumpable file in proc(5).)

       *  /proc/sys/kernel/core_pattern is empty and /proc/sys/kernel/core_uses_pid contains the value 0.  (These files are described below.)  Note that if /proc/sys/kernel/core_pattern is empty and /proc/sys/kernel/core_uses_pid contains the value 1, core dump files will have names of the form .pid, and  such
          files are hidden unless one uses the ls(1) -a option.

       *  (Since Linux 3.7) The kernel was configured without the CONFIG_COREDUMP option.

       In addition, a core dump may exclude part of the address space of the process if the madvise(2) MADV_DONTDUMP flag was employed.

       On systems that employ systemd(1) as the init framework, core dumps may instead be placed in a location determined by systemd(1).  See below for further details.

   Naming of core dump files
       By default, a core dump file is named core, but the /proc/sys/kernel/core_pattern file (since Linux 2.6 and 2.4.21) can be set to define a template that is used to name core dump files.  The template can contain % specifiers which are substituted by the following values when a core file is created:

           %%  a single % character
           %c  core file size soft resource limit of crashing process (since Linux 2.6.24)
           %d  dump mode—same as value returned by prctl(2) PR_GET_DUMPABLE (since Linux 3.7)
           %e  executable filename (without path prefix)
           %E  pathname of executable, with slashes ('/') replaced by exclamation marks ('!') (since Linux 3.0).
           %g  (numeric) real GID of dumped process
           %h  hostname (same as nodename returned by uname(2))
           %i  TID of thread that triggered core dump, as seen in the PID namespace in which the thread resides (since Linux 3.18)
           %I  TID of thread that triggered core dump, as seen in the initial PID namespace (since Linux 3.18)
           %p  PID of dumped process, as seen in the PID namespace in which the process resides
           %P  PID of dumped process, as seen in the initial PID namespace (since Linux 3.12)
           %s  number of signal causing dump
           %t  time of dump, expressed as seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC)
           %u  (numeric) real UID of dumped process

       A single % at the end of the template is dropped from the core filename, as is the combination of a % followed by any character other than those listed above.  All other characters in the template become a literal part of the core filename.  The template may include '/' characters, which are interpreted
       as delimiters for directory names.  The maximum size of the resulting core filename is 128 bytes (64 bytes in kernels before 2.6.19).  The default value in this file is "core".  For backward compatibility, if /proc/sys/kernel/core_pattern does not include %p and /proc/sys/kernel/core_uses_pid  (see  be‐
       low) is nonzero, then .PID will be appended to the core filename.

       Paths are interpreted according to the settings that are active for the crashing process.  That means the crashing process's mount namespace (see mount_namespaces(7)), its current working directory (found via getcwd(2)), and its root directory (see chroot(2)).

       Since  version  2.4,  Linux  has also provided a more primitive method of controlling the name of the core dump file.  If the /proc/sys/kernel/core_uses_pid file contains the value 0, then a core dump file is simply named core.  If this file contains a nonzero value, then the core dump file includes the
       process ID in a name of the form core.PID.

       Since Linux 3.6, if /proc/sys/fs/suid_dumpable is set to 2 ("suidsafe"), the pattern must be either an absolute pathname (starting with a leading '/' character) or a pipe, as defined below.

   Piping core dumps to a program
       Since kernel 2.6.19, Linux supports an alternate syntax for the /proc/sys/kernel/core_pattern file.  If the first character of this file is a pipe symbol (|), then the remainder of the line is interpreted as the command-line for a user-space program (or script) that is to be executed.  Instead of  being
       written to a disk file, the core dump is given as standard input to the program.  Note the following points:

       *  The program must be specified using an absolute pathname (or a pathname relative to the root directory, /), and must immediately follow the '|' character.

       *  The command-line arguments can include any of the % specifiers listed above.  For example, to pass the PID of the process that is being dumped, specify %p in an argument.

       *  The process created to run the program runs as user and group root.

       *  Running as root does not confer any exceptional security bypasses.  Namely, LSMs (e.g., SELinux) are still active and may prevent the handler from accessing details about the crashed process via /proc/[pid].

       *  The program pathname is interpreted with respect to the initial mount namespace as it is always executed there.  It is not affected by the settings (e.g., root directory, mount namespace, current working directory) of the crashing process.

       *  The process runs in the initial namespaces (PID, mount, user, and so on) and not in the namespaces of the crashing process.  One can utilize specifiers such as %P to find the right /proc/[pid] directory and probe/enter the crashing process's namespaces if needed.

       *  The process starts with its current working directory as the root directory.  If desired, it is possible change to the working directory of the dumping process by employing the value provided by the %P specifier to change to the location of the dumping process via /proc/[pid]/cwd.

       *  Command-line arguments can be supplied to the program (since Linux 2.6.24), delimited by white space (up to a total line length of 128 bytes).

       *  The RLIMIT_CORE limit is not enforced for core dumps that are piped to a program via this mechanism.

   /proc/sys/kernel/core_pipe_limit
       When collecting core dumps via a pipe to a user-space program, it can be useful for the collecting program to gather data about the crashing process from that process's /proc/[pid] directory.  In order to do this safely, the kernel must wait for the program collecting the core dump to exit, so as not to
       remove the crashing process's /proc/[pid] files prematurely.  This in turn creates the possibility that a misbehaving collecting program can block the reaping of a crashed process by simply never exiting.

       Since Linux 2.6.32, the /proc/sys/kernel/core_pipe_limit can be used to defend against this possibility.  The value in this file defines how many concurrent crashing processes may be piped to user-space programs in parallel.  If this value is exceeded, then those crashing processes above this value  are
       noted in the kernel log and their core dumps are skipped.

       A value of 0 in this file is special.  It indicates that unlimited processes may be captured in parallel, but that no waiting will take place (i.e., the collecting program is not guaranteed access to /proc/<crashing-PID>).  The default value for this file is 0.

   Controlling which mappings are written to the core dump
       Since kernel 2.6.23, the Linux-specific /proc/[pid]/coredump_filter file can be used to control which memory segments are written to the core dump file in the event that a core dump is performed for the process with the corresponding process ID.

       The value in the file is a bit mask of memory mapping types (see mmap(2)).  If a bit is set in the mask, then memory mappings of the corresponding type are dumped; otherwise they are not dumped.  The bits in this file have the following meanings:

           bit 0  Dump anonymous private mappings.
           bit 1  Dump anonymous shared mappings.
           bit 2  Dump file-backed private mappings.
           bit 3  Dump file-backed shared mappings.
           bit 4 (since Linux 2.6.24)
                  Dump ELF headers.
           bit 5 (since Linux 2.6.28)
                  Dump private huge pages.
           bit 6 (since Linux 2.6.28)
                  Dump shared huge pages.
           bit 7 (since Linux 4.4)
                  Dump private DAX pages.
           bit 8 (since Linux 4.4)
                  Dump shared DAX pages.

       By default, the following bits are set: 0, 1, 4 (if the CONFIG_CORE_DUMP_DEFAULT_ELF_HEADERS kernel configuration option is enabled), and 5.  This default can be modified at boot time using the coredump_filter boot option.

       The value of this file is displayed in hexadecimal.  (The default value is thus displayed as 33.)

       Memory-mapped I/O pages such as frame buffer are never dumped, and virtual DSO pages are always dumped, regardless of the coredump_filter value.

       A child process created via fork(2) inherits its parent's coredump_filter value; the coredump_filter value is preserved across an execve(2).

       It can be useful to set coredump_filter in the parent shell before running a program, for example:

           $ echo 0x7 > /proc/self/coredump_filter
           $ ./some_program

       This file is provided only if the kernel was built with the CONFIG_ELF_CORE configuration option.

   Core dumps and systemd
       On  systems  using the systemd(1) init framework, core dumps may be placed in a location determined by systemd(1).  To do this, systemd(1) employs the core_pattern feature that allows piping core dumps to a program.  One can verify this by checking whether core dumps are being piped to the systemd-core‐
       dump(8) program:

           $ cat /proc/sys/kernel/core_pattern
           |/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %e

       In this case, core dumps will be placed in the location configured for systemd-coredump(8), typically as lz4(1) compressed files in the directory /var/lib/systemd/coredump/.  One can list the core dumps that have been recorded by systemd-coredump(8) using coredumpctl(1):

         $ coredumpctl list | tail -5
         Wed 2017-10-11 22:25:30 CEST  2748 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:29:10 CEST  2716 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:30:50 CEST  2767 1000 1000 3 present  /usr/bin/sleep
         Thu 2017-10-12 06:37:40 CEST  2918 1000 1000 3 present  /usr/bin/cat
         Thu 2017-10-12 08:13:07 CEST  2955 1000 1000 3 present  /usr/bin/cat

       The information shown for each core dump includes the date and time of the dump, the PID, UID, and GID  of the dumping process, the signal number that caused the core dump, and the pathname of the executable that was being run by the dumped process.  Various options to coredumpctl(1) allow  a  specified
       coredump file to be pulled from the systemd(1) location into a specified file.  For example, to extract the core dump for PID 2955 shown above to a file named core in the current directory, one could use:

           $ coredumpctl dump 2955 -o core

       For more extensive details, see the coredumpctl(1) manual page.

       To disable the systemd(1) mechanism that archives core dumps, restoring to something more like traditional Linux behavior, one can set an override for the systemd(1) mechanism, using something like:

         # echo "kernel.core_pattern=core.%p" > /etc/sysctl.d/50-coredump.conf
         # /lib/systemd/systemd-sysctl

NOTES
       The gdb(1) gcore command can be used to obtain a core dump of a running process.

       In  Linux versions up to and including 2.6.27, if a multithreaded process (or, more precisely, a process that shares its memory with another process by being created with the CLONE_VM flag of clone(2)) dumps core, then the process ID is always appended to the core filename, unless the process ID was al‐
       ready included elsewhere in the filename via a %p specification in /proc/sys/kernel/core_pattern.  (This is primarily useful when employing the obsolete LinuxThreads implementation, where each thread of a process has a different PID.)

示例处理程序展示了pipe语法。

    $ cc -o core_pattern_pipe_test core_pattern_pipe_test.c
    $ su
    Password:
    # echo "|$PWD/core_pattern_pipe_test %p UID=%u GID=%g sig=%s" > \
        /proc/sys/kernel/core_pattern
    # exit
    $ sleep 100
    ^\                     # type control-backslash
    Quit (core dumped)

    $ cat core.info
    argc=5
    argc[0]=</to/work/core_pattern_pipe_test>
    argc[1]=<9272>
    argc[2]=<UID=1000>
    argc[3]=<GID=1000>
    argc[4]=<sig=3>
    Total bytes in core dump: 393216

示例处理程序源代码如下。

       /* core_pattern_pipe_test.c */

       #define _GNU_SOURCE
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <limits.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>

       #define BUF_SIZE 1024

       int
       main(int argc, char *argv[])
       {
           int tot, j;
           ssize_t nread;
           char buf[BUF_SIZE];
           FILE *fp;
           char cwd[PATH_MAX];

           /* Change our current working directory to that of the
              crashing process */

           snprintf(cwd, PATH_MAX, "/proc/%s/cwd", argv[1]);
           chdir(cwd);

           /* Write output to file "core.info" in that directory */

           fp = fopen("core.info", "w+");
           if (fp == NULL)
               exit(EXIT_FAILURE);

           /* Display command-line arguments given to core_pattern
              pipe program */

           fprintf(fp, "argc=%d\n", argc);
           for (j = 0; j < argc; j++)
               fprintf(fp, "argc[%d]=<%s>\n", j, argv[j]);

           /* Count bytes in standard input (the core dump) */

           tot = 0;
           while ((nread = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
               tot += nread;
           fprintf(fp, "Total bytes in core dump: %d\n", tot);

           fclose(fp);
           exit(EXIT_SUCCESS);
       }
