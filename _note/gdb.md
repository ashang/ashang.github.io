---
title: gdb notes
date: 2012-08-21
lastmod: 2013-08-18
---




bt -100

And it is likely you will see the frame that you need to inspect on the first or second screen.
Once insecting the stack trace using bt -100 helped me to fix a pboblem with a lot of recursive calls easily.

And then issue command
f <here the number of your frame you need to inspect>

    up 200 will bring you up 200 frames
    If you know the initial caller of the recursive routine, you can do f[rame] <caller-func> - this will jump to the frame of address caller-func.

###

"e2fsck-wrapper".

        #!/usr/bin/expect -f
        set timeout -1
        spawn /sbin/e2fsck -f $argv
        expect {
            "Clear<y>? " { send "n" ; exp_continue }
            "<y>? "      { send "y" ; exp_continue }
        }




## Symbols

Exposed interface to the other programs is composed of named functions and data symbols, that can be accessed either by linking to the library or by using dlsym() and similar interfaces provided by the runtime loader.

Not all symbols defined within a shared object need to be exported, though. In the vast majority of cases, a dynamic library will provide a set of symbols corresponding to its public API, while for plugins, the interface to be exposed is usually mandated by the host application or library.

Exposing more symbols than necessary can have negative effects on the object in many ways: it almost always increases the time necessary for the dynamic loader to completely load the object, and – if the internal symbols are not properly guarded – it can cause collisions between different objects, on operating systems using flat namespaces, as it is the case for Linux and most Unix-based systems.

Most, if not all, link editors allow to avoid this problem by defining a list of symbols to export; any symbol not in such lists will be hidden and thus not be part of the public interface of the object. Since the options used by the link editors to provide this function are not standard, libtool leverages it via three main options: -export-dynamic, -export-symbols and -export-symbols-regex.

3.1. -export-dynamic
The -export-dynamic option is used to declare that the interface exposed by the current object is to be used with the dlopen() and dlsym() functions (or their equivalent on non-Unix operating systems). This is the case for instance of all plugins, as seen in Section 2, “Building plugins”.

This option is not commonly used for projects whose main target is Linux or other operating systems using ELF for their objects, as any symbol exposed by an ELF object is available to be accessed through the dlsym() function. It is a requirement, though, of other operating system that make difference whether the symbol should be resolved at build time or during execution, such as Windows.

3.2. -export-symbols and -export-symbols-regex
As the title implies, the -export-symbols and -export-symbols-regex are tightly related. They both are used to provide libtool with a list of symbols that should be exposed (the interface of the object).

The first option takes as a single parameter the path to a file, containing the list of symbols to expose, one per line. The second instead takes as a parameter a regular expression: symbols whose name matches the expression will be exposed by the object; libtool takes care of producing the list in that case.

Once libtool knows the list of symbols to expose, it then uses the link editor's own interface to complete the task; this is done through either linker scripts for Unix-derived link editors, or through definition lists for link editors for Windows, as they both serve similar purposes.

Example 3.7. Exposing only the public interface of a library via -export-symbols-regex

lib_LTLIBRARIES = libfoo.la

libfoo_la_SOURCES = foo1.c foo2.c foo3.c
libfoo_la_LDFLAGS = -export-symbols-regex '^foo_'

Using the -export-symbols-regex option makes it very easy to hide unnecessary symbols from a library's interface, but relies on the library being designed to use a regular pattern for naming of non-static functions and data symbols. In the earlier example, for instance, libtool will export all the symbols whose name start with foo_, assuming that the internal symbols use instead a prefix like x_foo or something along those lines.

When this assumption cannot be applied, you have instead to use the other option, -export-symbols, providing it with a complete list of the interfaces to export. The main downside to this method is, obviously, that you have to either manually compile it (which is prone to errors) or find a different, automated way to produce it, similarly to what libtool does when provided with a regular expression.


## frame

Usually stack frame address is kept in the frame pointer register while execution is going on in that frame.

GDB assigns numbers to all existing stack frames, starting with zero for the innermost frame, one for the frame that called it, and so on upward. These numbers do not really exist in your program; they are assigned by GDB to give you a way of designating stack frames in GDB commands.

Some compilers provide a way to compile functions so that they operate without stack frames.

For example, the gcc option

`-fomit-frame-pointer`
generates functions without a frame.

This is occasionally done with heavily used library functions to save the frame setup time.

GDB has limited facilities for dealing with these function invocations. If the innermost function invocation has no stack frame, GDB nevertheless regards it as though it had a separate frame, which is numbered zero as usual, allowing correct tracing of the function call chain. However, GDB has no provision for frameless functions elsewhere in the stack.

- frame args
- select-frame

The select-frame command allows you to move from one stack frame to another without printing the frame.



Selects a stack frame or displays the currently selected stack frame.

- f [Frame number]

If no frame number is specified, this command displays the currently selected frame.

The frame command displays brief information about the selected frame after selecting it. If you want to avoid it, use the select-frame command that is a silent version of the frame command.

## backtrace
bt
Print a backtrace of the entire stack: one line per frame for all frames in the stack. You can stop the backtrace at any time by typing the system interrupt character, normally C-c.
backtrace n
bt n
Similar, but print only the innermost n frames.
backtrace -n
bt -n
Similar, but print only the outermost n frames.
backtrace full
Print the values of the local variables also.
bt full
The names where and info stack (abbreviated info s) are additional aliases for backtrace.


up n
Move n frames up the stack. For positive numbers n, this advances toward the outermost frame, to higher frame numbers, to frames that have existed longer. n defaults to one.
down n
Move n frames down the stack. For positive numbers n, this advances toward the innermost frame, to lower frame numbers, to frames that were created more recently. n defaults to one. You may abbreviate down as do.


info f addr
Print a verbose description of the frame at address addr, without selecting that frame. The selected frame remains unchanged by this command. This requires the same kind of address (more than one for some architectures) that you specify in the frame command. See section Selecting a frame.
info args
Print the arguments of the selected frame, each on a separate line.
info locals
Print the local variables of the selected frame, each on a separate line. These are all variables (declared either static or automatic) accessible at the point of execution of the selected frame.
info catch
Print a list of all the exception handlers that are active in the current stack frame at the current point of execution. To see other exception handlers, visit the associated frame (using the up, down, or frame commands); then type info catch.


For release builds, you should use the following as part of CFLAGS and CXXFLAGS for release builds:

-On -g2

-On sets optimizations for speed or size (for example, -Os or -O2), and -g2 ensure debugging information is created.



```
echo "GET / HTTP1.0" | openssl s_client -connect <nowiki>example.com:443
```

nm or openssl s_client will show that compression is enabled in the client. In fact, any symbol within the OPENSSL_NO_COMP preprocessor macro will bear witness since -no-comp is translated into a CFLAGS define.

```
$ nm /usr/local/ssl/iphoneos/lib/libcrypto.a 2>/dev/null | egrep -i "(COMP_CTX_new|COMP_CTX_free)"
0000000000000110 T COMP_CTX_free
0000000000000000 T COMP_CTX_new
```

## Set a breakpoint in a sub-function:

(gdb) b subfunc
Breakpoint 1 at 0x400f09: file prog.c, line 94.
(gdb) c
Continuing.

Breakpoint 1 at 0x400f09: file prog.c, line 94.
94      void subfunc() {

Change selected frame:

(gdb) up
#1  0x0000000000400f7e in main (argc=1, argv=0x7fffffffe468) at prog.c:70
70          subfunc();



advance allow to continue until a particular line. Thus advance +1 do the job. It can be abbreviated adv +1





    gdb: apply “next” to selected frame instead of innermost frame

The accepted answer is "advance + 1" is not so correct, which only works if the next line of selected frame could be hit.

    advance -- Continue the program up to the given location (same form as args for break command)

A general solution is: Switch to the inferior frame of the selected frame, finish it and step the program.

frame x-1
fin
n

where x is the selected frame.

Ref:

    finish -- Execute until selected stack frame returns
    next -- Step program
    frame -- Select and print a stack fram


tbreak +1
continue

https://sourceware.org/gdb/onlinedocs/gdb/

-   配合 SystemTap 实现 SDT（定位静态追溯）。

# TUI

  `gdb -tui`

## Overview

GDB is using the very low level ptrace(2) system call to set breakpoints etc..

## Latest changes

### gdb (7.8-1) experimental; urgency=medium

>  WARNING: gdb now uses Python 3 by default.
>
>  Please update your Python scripts to work on both Python 2 and 3 as
>  soon as possible.
>
>  See /usr/share/doc/gdb*/README.python_switch for details.

## Get started

Commands

- `bt` (for backtrace) to get a stack trace from the time of the crash. In the backtrace, each function invocation is given a number.
- `frame NUMBER` to select a particular stack frame.
- `list` to see code around that function
- `info locals` to see the local variables.
- `print NAME_OF_VARIABLE` to see its value.
- `apropos search-topic` to find help
- `up/down N` to select frames N up/down


## XXX

```
root@57604cfc938d:/# gdb
GNU gdb (Debian 7.7.1+dfsg-5) 7.7.1
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word".

root@57604cfc938d:/# gdb /pica/bin/vrrp/xorp_vrrp
GNU gdb (Debian 7.7.1+dfsg-5) 7.7.1
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from /pica/bin/vrrp/xorp_vrrp...(no debugging symbols found)...done.
(gdb) r
Starting program: /pica/bin/vrrp/xorp_vrrp
warning: the debug information found in "/usr/lib/debug//lib/x86_64-linux-gnu/ld-2.19.so" does not match "/lib64/ld-linux-x86-64.so.2" (CRC mismatch).

warning: the debug information found in "/usr/lib/debug/lib/x86_64-linux-gnu//ld-2.19.so" does not match "/lib64/ld-linux-x86-64.so.2" (CRC mismatch).

/pica/bin/vrrp/xorp_vrrp: error while loading shared libraries: libxorptargets.so.0: cannot open shared object file: No such file or directory
[Inferior 1 (process 160) exited with code 0177]

root@XorPlus:/pica/core# gdb -c core.xorp_policy.pid_18451.uid_0.sig_11 /pica/bin/policy/xorp_policy
GNU gdb (GDB) 7.4.1-debian
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /pica/bin/policy/xorp_policy...done.
[New LWP 18451]

 warning: Could not load shared library symbols for linux-vdso.so.1.
 Do you need "set solib-search-path" or "set sysroot"?
[Thread debugging using libthread_db enabled]
 Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".


  warning: no loadable sections found in added symbol-file system-supplied DSO at 0x7ffefcff6000
  Core was generated by `xorp_policy'.
  Program terminated with signal 11, Segmentation fault.
  #0  0x00007f9d6c69ab45 in ?? () from /lib/x86_64-linux-gnu/libc.so.6
  (gdb) bt
  #0  0x00007f9d6c69ab45 in ?? () from /lib/x86_64-linux-gnu/libc.so.6
  #1  0x00007f9d6c69b641 in ?? () from /lib/x86_64-linux-gnu/libc.so.6
  #2  0x00007f9d6dc69db5 in ref_counter_pool::~ref_counter_pool() () from /pica/lib/libxorp.so.0
  #3  0x00007f9d6c659eaf in __cxa_finalize () from /lib/x86_64-linux-gnu/libc.so.6
  #4  0x00007f9d6dc58743 in ?? () from /pica/lib/libxorp.so.0
  #5  0x00007ffefcfeb370 in ?? ()
  #6  0x00007f9d6f6b91fa in ?? () from /lib64/ld-linux-x86-64.so.2
  Backtrace stopped: previous frame identical to this frame (corrupt stack?)
  (gdb)
```

- `list (l)`：列出源代码，默认 10 行，其后可跟函数名或行号；也可以用逗号分隔两个参数，以打印指定范围的源代码
- `break (b)`：设置断点，后接函数名或行号
- `run (r)`：执行程序，遇到断点会自动暂停
- `continue (c)`：程序继续执行，直到遇到下一个断点或到达程序结尾
- `next (n)`：执行一整行代码，然后停留在下一行，也称“单步跳过”
- `step
- (s)`：功能基本和`next`一样，但是遇到函数调用时，`step`会跳进函数体内，然后停留在函数的第一条语句处，也称“单步跳入”
- `finish (fin)`：继续执行目前所在的函数，直到遇到函数体内的下一个断点或直到函数结束，也称“单步跳出”
- `print (p)`：打印变量的值
- `kill`：终止调试器，但并不关闭，所有设置都将保存，待修改好源文件重新编译后使用`run`再次开始调试，`GDB`会重新加载可执行文件
- `file`：加载需要调试的目标程序
- `set args`：后跟当前调试程序所需的参数表列
- `show args`：显示目前为调试程序所设置的参数表列

- 对于`next`和`step`命令，如果执行一次后还想继续执行，只需直接回车即可，`GDB`会自动执行上一条命令

- `info all-registers (info all)`：显示所有处理器寄存器的内容，包括浮点和向量寄存器
- `info register (info reg)`：显示 CPU 寄存器的内容
- `info source`：打印当前源文件的信息
- `info sources`：打印当前调试程序包含的所有源文件信息
- `info address`：后跟变量或函数名，可以显示目标变量或函数的地址信息
- `info breakpoints (info b)`：显示所有设置的断点
- `info frame (info f)`：显示当前堆栈帧的相关信息，包括返回值、寄存器值
- `info locals (info lo)`：列出当前函数的局部变量

- `tbreak (tb)`：设置临时断点，`GDB`会在到达这个语句后自动将其删除
- `delete (d)`：删除某个断点或某个范围内的断点，后接断点的编号，或以竖线分隔的两个断点编号；不加参数则删除所有断点
- `disable (dis)`：临时禁用某个断点或某个范围内的断点，使用格式同`delete`
- `enable (en)`：恢复被禁用的某个断点或某个范围内的断点，使用格式同`delete`
- `ignore 1 5 (ig 1 5)`：连续忽略编号为 1 的断点 5 次

### 条件中断

`break 断点位置 if 中断条件`：其中位置可以是函数名或行号，条件可以是 C 语言任何形式的表达式
如：`break 20 if i == j - 1`

`condition 断点编号 中断条件`：可以在已有断点的位置再新增一个断点，或修改其原来的中断条件
如：`condition 20 \*p1 \!= \*p2`
如想删除中断条件，直接使用`condition 断点编号`即可

- `set logging on (set lo on)`：开启日志记录
- `show logging (show lo)`：显示日志信息
- `set listsize 5 (set li 5)`：设置`list`默认输出的行数
- `show listsize (show li)`：显示`list`默认输出的行数

### 显示调用轨迹

`backtrace (bt)`，同义词还有`where`、`info stack (info s)`
使用上述命令可以得到函数的调用次序，这在调试递归调用时特别有效

`frame (f)`：显示堆栈帧信息，后面可跟堆栈帧的编号，不跟参数则显示当前堆栈帧的信息

`up`，跳到上一个堆栈；`down`，跳到下一个堆栈

### 显示数据的详细用法

`pint 输出格式 变量名称或表达式`：表达式的执行结果会影响到程序中相应变量的值，示例如下

`p a`：输出变量 a 的取值
`p a=7`：给变量 a 赋值为 7，相当于命令`set variable a=7 (set var a=7)`
`p a\*a`：输出变量 a 自乘的结果
`p
2\*sum($3)`：调用 sum 函数，传入参数`$3`（此即调试过程中第三次打印的数值），然后将 sum 函数执行的结果乘以2返回
`p main::a`：跨堆栈帧存取变量信息

可以在`GDB`调试过程中定义新的变量，使用`p $a = \*p1`或`set $a = \*p1`的格式

格式化输出选项

1.  `/d`：十进制输出，也是输出整数时的默认格式
2.  `/u`：十进制无符号整数
3.  `/c`：字符形式输出
4.  `/o`：八进制输出
5.  `/x`：十六进制输出
6.  `/t`：二进制输出

其他格式化选项

1.  `/a`：以十六进制形式输出地址
2.  `/f`；将目标值以浮点数的形式显示

### 显示内存区域

基本格式：`x / 显示个数 格式修饰符 单位内存大小 address`

`显示个数`：指定要显示多少个内存单位，默认为 1
`格式修饰符`：除了可以使用`print`的格式修饰符以外，还可以额外使用以下两个
\# `/s`：将目标地址的数据以字符串的形式显示出来

1.  `/i`：以汇编语言的形式显示机器指令

`单位内存大小`：指定每个内存单位空间的大小，有以下四种类别，默认为`w`
\# `b`：一个字节

1.  `h`：两个字节（半个字）
2.  `w`：四个字节（一个字）
3.  `g`：八个字节（双字）

`address`：目标地址

使用示例如下：

`x/s \&a`：以字符串的形式显示变量 a 所处地址开始的一个字的内容（因为默认显示 1 个单位，每个单位为一个字）
`x/15xb \&a`：以十六进制形式显示变量 a 所处地址开始的 15 个字节的内容
`x/10i \&a`：将变量 a 所处地址开始的 10 条机器语言翻译成汇编代码

### 观测点的设置

`watch (wa)`：当指定表达式的值发生改变时，程序中止执行
`rwatch (rw)`：当程序读取和目标表达式相关的任何对象时，程序中止执行
`awatch (aw)`：当程序读取或修改和目标表达式相关的任何对象时，程序中止执行

-----

# Running gdb

Now run your program as follows, replacing "[--args]" with any arguments
you want to run the program with:
`--args`：此选项后必须立即跟要调试的目标程序名，然后接该目标程序需要的参数表列，这样这些参数就不会被当成`GDB`自身的参数

    $ gdb hello
    ... gdb loads ...
    (gdb) set pagination 0
    (gdb) run [--args]
    ... hello loads...

Then try to reproduce your crash. If you’re lucky, a crash will occur
and you’ll be dropped back to the gdb prompt.
If you are not so lucky to get a crash but instead get a freeze, you can
still get gdb prompt by pressing CTRL-C in the terminal running gdb.
At that point, you can run:

    (gdb) bt

You’ll then get a lot of output, which you can then copy & paste to
a bug followup e-mail or other bug reporting tool.

When you’re done with gdb, you can just run:

    (gdb) quit

If the problem seems to be in a major library such as libc6, xlibs, or
libgtk2.0-0, you’ll want to install the appropriate -dbg package (e.g.
libc6-dbg in the case of libc6) and then run the problematic program
again under gdb.

Often, you will see a backtrace where one or more of the top lines is in
malloc() or g_malloc(). When this happens, chances are your backtrace
isn’t very useful. The easiest way to find some useful information is
to set the environment variable `MALLOC_CHECK_` to a value of 2. You can do this while running gdb by doing this:

    $ MALLOC_CHECK_=2 gdb hello

# Advanced gdb commands
If the program you’re backtracing is multi-threaded, you might want to
get a backtrace for all threads:

    (gdb) thread apply all bt
Another thing which is quite helpful to report is what variables were
set locally at each point in the stack:

    (gdb) bt full
You might want to report the output of the combination of the preceding
options:

    (gdb) thread apply all bt full
And if this is too much irrelevant output, you might want to keep only
a few calls, such as the top 10:

    (gdb) thread apply all bt full 10
If you have a large backtrace, you can log gdb output to a file (the
default is gdb.txt):

    (gdb) set logging on
To check you have debugging symbols in your binary:

    $ gdb
     (gdb) symbol-file /usr/bin/hello

    # you should see something like this:
     Reading symbols from /usr/bin/hello ... done
     Using host libthread_db library
    /lib/tls/i686/cmov/libthread_db.so.1".
     (gdb)

    # NB you should _not_ see
     Reading symbols from /usr/bin/hello...(no debugging symbols
    ound)...done

# Debugging X Errors

If a GTK program has received an X error; i.e. you see a message of the
form:

then you can try running the program with `--sync`, and break on the
`gdk_x_error` function in order to obtain a backtrace, thus:

    (gdb) break gdk_x_error
    (gdb) run --sync

# Debugging

Start the program under control of gdb via a terminal (some programs run
as root, so one would use sudo gdb instead of just gdb below):

    gdb <program> 2>&1 | tee ~/gdb-<program>.txt
    (gdb) handle SIG33 pass nostop noprint
    (gdb) set pagination 0
    (gdb) run <arguments, if any>
The program will start. Perform any actions necessary to reproduce the
crash. If the program hangs but doesn't crash you can press ctrl+c in
gdb while the program is frozen and then continue with the next step.

Retrieve a backtrace:

    (gdb) backtrace full
    (gdb) info registers
    (gdb) x/16i $pc
    (gdb) thread apply all backtrace
    (gdb) quit

Attach the complete output from GDB, contained in gdb-<program>.txt, in
your bug report. You will find the file in your $HOME directory


# Already running programs

Find the process ID of <program>:

    pidof <program>
Start gdb (some programs run as root, so one would use sudo gdb instead
of just gdb below):

    gdb 2>&1 | tee gdb-<program>.txt
    (gdb) handle SIG33 pass nostop noprint
    (gdb) set pagination 0
    (gdb) attach <PID>
Continue the <program>:

    (gdb) continue
The program will continue running. Perform any actions necessary to
reproduce the crash. If the program hangs but doesn't crash you can
press ctrl+c in gdb while the program is frozen and then continue with
the next step.

Retrieve a backtrace:

    (gdb) backtrace full
    (gdb) info registers
    (gdb) x/16i $pc
    (gdb) thread apply all backtrace
    (gdb) quit
Attach the complete output from GDB, contained in gdb-<program>.txt, in
your bug report.

Note that you can also set logging to a file like this:

    (gdb) set logging file gdb-<program>.txt
    (gdb) set logging on


# Core file
Load the core file into the debugger

    gdb -c <corefile> 2>&1 | tee gdb-<program>.txt
Retrieve a backtrace of the crash:

    (gdb) backtrace full
    (gdb) info registers
    (gdb) x/16i $pc
    (gdb) thread apply all backtrace
    (gdb) quit

# backtrace.sh
```

#---------------------------------------------------------------------
usage() {
    cat<<EOF
Usage: ${0} program_name [program_args]

Trace a given program using gdb.

EOF
}

log() {
    echo "${*}" 1>&2
}

die() {
    usage
    log 'error:' ${*}'.'
    exit 1
}
#---------------------------------------------------------------------
test "x${*}" = "x" && die 'no process given'

LOG="/tmp/gdb-`basename ${1}`.txt"
log "outputting trace to '${LOG}'"

exec gdb -batch-silent \
    -ex 'set logging overwrite on' \
    -ex "set logging file ${LOG}" \
    -ex 'set logging on' \
    -ex 'handle SIG33 pass nostop noprint' \
    -ex 'set pagination 0' \
    -ex 'run' \
    -ex 'backtrace full' \
    -ex 'info registers' \
    -ex 'x/16i $pc' \
    -ex 'thread apply all backtrace' \
    -ex 'quit' \
    --args ${*} \
    < /dev/null>>>}
```

## Debug binaries with arguments

```c
#include<stdio.h>

int main(int argc,char *argv[])
{
    if(1 >= argc)
    {
        printf("usage:hello name\n");
        return 0;
    }
    printf("Hello World %s!\n",argv[1]);
    return 0 ;
}
```

    gcc -g -o hello hello.c

You need to run with args, or set args for run.

## Debug core dumps

The binary with debugging symbols included should be identical to the one that generated the core dump file.

    gdb /path/to/binary-with-symbols /path/to/core/dump/file

Or

    gdb -c /path/to/core/dump/file /path/to/binary-with-symbols

### ulimit

    $ ulimit -c
    0

    ulimit -c unlimied  #unlimited
    ulimit -c 10        # maximum size in blocks, each block is 512 B

## Debug running binaries

Find the pid

    ps -ef | grep process

Or

    pidof process

    (gdb) attach PID


## Trouble shooting

### Could not attach to process. If your uid matches the uid of the target process, check the setting of /proc/sys/kernel/yama/ptrace_scope, or try again as the root user.

```
echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
```

* https://askubuntu.com/questions/41629/after-upgrade-gdb-wont-attach-to-process

### ptrace: Operation not permitted.

    Could not attach to process.  If your uid matches the uid of the target
    process, check the setting of /proc/sys/kernel/yama/ptrace_scope, or try
    again as the root user.  For more details, see /etc/sysctl.d/10-ptrace.conf
    ptrace: Operation not permitted.


Change

    /etc/sysctl.d/10-ptrace.conf

    kernel.yama.ptrace_scope = 1

to

    kernel.yama.ptrace_scope = 0

## load pid

    gdb PROG PID

    gdb PROG --pid PID

## For running binaries without debug info

You need to build one binary using same code, then load the symbols using `file FILE` from that.

    (gdb) file FILE
    (gdb) attach XXXXX

## ptrace

You almost never need ptrace, except if you write your own debugger, which could take years of work, but you use gdb which uses ptrace.

    long ptrace(enum __ptrace_request request, pid_t pid, void *addr, void *data);

ptrace 系统调用提供了一种方法来让父进程可以观察和控制其它进程的执行，检查和改变其核心映像以及寄存器。

ptrace 系统调用的主要选项

- PTRACE_TRACEME
  - 表示本进程将被其父进程跟踪，交付给这个进程的所有信号（除 SIGKILL 之外），都将使其停止，父进程将通过 wait() 获知这一情况。
- PTRACE_ATTACH
  - attach 到一个指定的进程，使其成为当前进程跟踪的子进程，子进程的行为等同于它进行了一次 PTRACE_TRACEME 操作。
- PTRACE_CONT
  - 继续运行之前停止的子进程。可同时向子进程交付指定的信号。


调试关系的建立过程：
- 用户确定需要进行调试的进程 id；
- 运行 gdb，输入 attach pid，gdb 对指定进程执行下述操作：
    ptrace(PTRACE_ATTACH, pid, 0, 0);

运行并调试一个新的进程

- 运行 gdb，通过命令行参数或 file 命令指定目标程序。
- 输入 run 命令，gdb 执行下述操作：
- 通过 fork() 系统调用创建一个新进程；
- 在新创建的子进程中执行下述操作：ptrace(PTRACE_TRACEME, 0, 0, 0);
- 在子进程中通过 execv() 系统调用加载用户指定的可执行文件。

## 远程调试目标机上新创建的进程

gdb 运行在调试机上，gdbserver 运行在目标机上，两者之间的通信数据格式由 gdb远程串行协议（Remote Serial Protocol)定义。

RSP 协议数据的基本格式为：“$..........#xx”。

gdbserver 的启动方式相当于运行并调试一个新创建的进程。

    @localhost $ gdbserver host:port PROCESS
    @remotehost $ gdb
		file PROCESS
		target remote host:port

### Signal

在使用参数为 PTRACE_TRACEME 或 PTRACE_ATTACH 的ptrace系统调用建立调试关系之后，交付给目标程序的任何信号（除SIGKILL之外）都将被gdb先行截获，或在远程调试中被gdbserver截获并通知gdb。

gdb 因此有机会对信号进行相应处理，并根据信号的属性决定在继续目标程序运行时是否将之前截获的信号实际交付给目标程序。

信号是实现断点功能的基础。以 x86 为例，向某个地址打入断点，实际上就是往该地址写入断点指令 INT 3，即0xCC。目标程序运行到这条指令之后就会触发SIGTRAP 信号，gdb捕获到这个信号，根据目标程序当前停止位置查询gdb维护的断点链表，若发现在该地址确实存在断点，则可判定为断点命中。

gdb 暂停目标程序运行的方法是向其发送 SIGSTOP 信号。
     kill_lwp(process->head.id, SIGSTOP);

同步模式 – gdb 将以同步方式等待目标程序发生停止事件，可称之为“死等”。因此，在目标程序运行期间，gdb 不再扫描标准输入，用户也无法输入任何调试命令，要么等待目标程序发生调试事件而停止，要么通过“Ctrl c”来暂停目标程序的运行。

异步模式 – gdb 不会同步等待目标程序发生停止事件，此类事件将通过异步上报的方式告知 gdb。在目标程序运行期间，gdb 仍将扫描标准输入，用户可以输入调试命令。

使用同步模式还是异步模式由调试目标决定，在启动 gdb 之后通过 target 命令的参数给出。比如远程同步目标为target remote …，而远程异步目标为target async …。

gdb 远程异步模式的运转完全是由外部事件来激励的。共有两个外部事件源，一个是标准输入（用户输入的调试命令），一个是远程连接（gdbserver 上报的异步事件）。

负责对外部事件源进行检测和对事件进行分发处理的功能模块就是事件循环。建立调试连接之后，gdb 就会不断地对上述两个文件描述符进行 poll 操作。一旦发现某个文件描述符上有输入事件，就将该事件分发给相应的功能模块进行处理，该事件处理完毕之后将回到事件循环继续进行 poll操作。

标准输入上会出现哪些事件？
用户输入的任何调试命令，比如 cli 的 continue、next、step、breakpoint 或者是mi的exec-continue、exec-next、exec-step、break-insert等等。

远程连接上会出现哪些事件？
目标程序可能遇到的任何调试事件，比如遇到断点、收到随机信号、单步结束、线程创建、线程退出、进程退出等等。

所谓指令级单步就是指 gdb 控制目标程序只运行一条指令之后即停止。指令级单步是 next、step、nexti、stepi 等运行类调试命令的基础。

指令级单步有硬件单步和软件单步之分。所谓硬件单步是指 cpu 架构本身就支持指令级单步，目标程序可以在运行一条指令之后自动停止。所谓软件单步是指 cpu 架构不支持指令级单步，需要gdb用软件方法来实现指令级单步。

支持硬件单步的架构如 x86 和 ppc。对于x86，可通过设置EFLAGS 寄存器中的TF标志来将cpu置于单步模式。对于ppc，则可通过设置MSR寄存器中的SE标志来将cpu置于单步模式。在单步模式中，cpu每执行一条指令，就会产生一个单步异常，通知gdb进行处理。

不支持硬件单步的架构如 arm 和 mips。对于此类架构，gdb 采用的是用临时的软件断点来模拟单步的方法。即在需执行指令的下一条指令处临时插入一个断点，然后让目标程序继续运行，它会在执行完当前指令之后遇到下一条指令处的临时断点，于是目标程序停止，通知gdb命中断点，gdb再将此断点删除，由此来完成指令级单步的过程。（插入临时断点需要gdb实现代码分支预测的功能）

关键词：软件断点；事件循环；文件描述符;

# next, nexti, step, finish, etc.

next 命令实现 c 代码级的单步。分析其实现机制首先需要理解 step range以及step_range_start和step_range_end的概念。
执行 next 命令时，gdb 会计算出当前停止位置的 c语句的第一条指令的地址作为step_range_start，然后计算出当前停止位置下一行的c语句的第一条指令的地址作为step_range_end，随后控制目标程序从当前停止位置开始走指令级单步，直至pc超出step range为止。

next 命令的结束条件：
	pc < step_range_start || pc >= step_range_end。

之所以不能简单地判断 pc 是否到达 step_range_end，是因为step_range_end 仅仅是c源代码意义上的下一行的第一条指令的地址，目标程序实际运行时未必就会到达那里。因此，next命令的结束条件可以理解为只要pc离开当前源代码行即可。

next 过程中遇到函数调用怎么办？我们知道，next 命令是会跨过函数调用的，这个过程是如何实现的呢？

next 命令跨越函数调用的过程：1、从当前停止位置开始走指令级单步；2、走到子函数第一条指令时发现是函数调用，就在函数返回地址插入一个临时断点；3、让目标程序继续运行，通过子函数体，直至遇到之前插入的临时断点；4、继续走指令级单步，直至满足 next 命令的结束条件为止。

step 命令和 next 命令一样，也是实现 c源代码级的单步，对于简单语句，step完全等同于next。唯一不同的是，若单步过程中遇到函数调用，step命令将停止在子函数的起始处，而不是将其跨越（无调试信息的子函数除外）。

nexti 命令实现指令级单步，和 next 命令类似，nexti命令单步过程中不会进入子函数调用。

stepi 命令实现指令级单步，而且是严格的指令级单步，每次直接走一条指令后即停止，不再区分是否存在函数调用。

finish 命令会让目标程序继续执行完当前函数的剩余语句，并停止在返回到上一级函数之后的第一条指令处（也就是调用当前函数时的返回地址）。因此，实现 finish 命令时，只需找到当前函数的返回地址，并在该处插入一个临时断点，然后让目标程序继续运行，直至遇到该断点而停止。

## util
不带参数的 until 命令让目标程序运行至当前函数中当前行后的任意一行。和 next 命令类似，这种until命令也是用指令级单步来实现的，但不同的是它的step_range_start设定为当前函数的起始位置，也就是说，若指令级单步过程中pc向函数前部移动，程序是不会停止的，仅当程序单步至当前行后的某一行时程序才会停止，这就提供了一种跳出循环体的快捷方式。

带参数的 until 命令让目标程序继续运行，直至达到指定位置为止。因为只要在当前函数体内，until 命令的目的地址可以任意指定，因此不能再用指令级单步来实现它，而是采用在指定地址插入临时断点，然后让目标程序继续运行直至遇到断点停止的方法。
关于 until 命令需要注意的是，不管带参数还是不带参数，until 都是针对当前函数内部而言的，也就是说，只要 pc离开当前函数体程序就会停止。

### b

断点功能的实现就是在指定位置插入断点指令，使目标程序运行至该处时产生 SIGTRAP 信号，该信号被 gdb 捕获，通过断点地址的匹配确定是否命中断点。

断点的属性：
- 是否有条件（由 condition 命令修改）；
- 是否有忽略次数 （由 ignore 命令修改）；
- 是否只针对某个线程有效（由 break 命令的 thread 参数指定）；
- 是否是临时断点（由 tbreak 命令插入）。

断点命中的判定：目标程序遇到断点，并不一定就需要停下来，该停就停，不该停的还是要继续跑。只有真正需要停止运行的情况才认为是断点命中。是否命中断点的判定因素主要有以下这些：
- 导致目标程序本次停止运行的信号是不是 SIGTRAP；
- 在 gdb 维护的断点链表中是否存在一个断点的地址与目标程序本次停止位置匹配；
- 若断点存在条件，此时条件是否满足；
- 断点的忽略次数此时是否为 0；
- 若断点只针对某个线程有效，那么遇到该断点的线程是否就是断点所设定的线程；
- 若前两个条件之一不满足，则认为目标程序本次是因随机信号而停止。若后三个条件之一不满足，则认为目标程序本次没有命中断点，gdb 会让其继续运行。

临时断点 – 断点命中之后的处理。当判定为断点命中之后，若该断点为临时断点，gdb 就会将这个断点删除。也就是说，临时断点只命中一次。可能用到临时断点的场合：
用户通过 tbreak 命令显式插入；
next、nexti、step 命令需要跨越函数调用的时候，由 gdb 自动在函数返回地址处插入临时断点；
finish 命令需要在当前函数返回地址处插入临时断点；
带参数的 until 命令需要在当前函数返回地址以及参数指定地址插入临时断点；
在不支持硬件单步的架构上，gdb 需要逐指令插入临时断点来实现软件单步；

gdb 将断点实际插入目标程序的时机：当用户通过 break 命令设置一个断点时，这个断点并不会立即生效，因为 gdb此时只是在内部的断点链表中为这个断点新创建了一个节点而已。gdb会在用户下次发出继续目标程序运行的命令时，将所有断点插入目标程序，新设置的断点到这个时候才会实际存在于目标程序中。与此相呼应，当目标程序停止时，gdb会将所有断点暂时从目标程序中清除。
断点命中失败的情况下，跨越断点继续运行的过程：
- 清除断点
- 单步到断点的下一条指令
- 恢复断点
- 继续目标程序运行

对于 gdb 而言，导致目标程序本次停止的信号有随机和非随机之分。非随机信号是指 gdb 已经预知其会发生或者本身就是gdb导致的信号，也就是说，这些信号是具有明确的调试含义的，比如遇到断点指令时的SIGTRAP。而随机信号则是gdb没有预知的、不了解其实际含义的信号，比如因程序异常而导致的SIGSEGV，因定时机制而产生的SIGALRM，或者是用户程序自己内部使用的信号。
对于随机信号，gdb 提供了两个属性来决定对它的处理方式。一个是当此信号发生时是否停止目标程序的运行，一个是在目标程序因此信号而停止之后，用户发出继续目标程序运行的命令时，是否将此信号交付给目标程序。
可通过 info signals 命令查看信号的配置属性，并通过 handle signal 命令来修改信号的属性。


## （断点可以是条件表达式）

如果没有 -g, 你将看不见程序的函数名、变量名，所代替的全是运行时的内存地址。

1、gdb <program>
program 也就是你的执行文件，一般在当然目录下。
2、gdb <program> core
用 gdb 同时调试一个运行程序和 core 文件，core是程序非法执行后core dump后产生的文件。
3、gdb <program> <PID>
如果你的程序是一个服务程序，那么你可以指定这个服务程序运行时的进程 ID。gdb 会自动 attach 上去，并调试他。
program 应该在 PATH 环境变量中搜索得到。
GDB 启动时，可以加上一些 GDB 的启动开关，详细的开关可以用 gdb -help查看。

用的参数：
-symbols <file>
-s <file>
从指定文件中读取符号表。
-se file
从指定文件中读取符号表信息，并把他用在可执行文件中。
-core <file>
-c <file>
调试时 core dump 的 core 文件。
-directory <directory>
-d <directory>
加入一个源文件的搜索路径。默认搜索路径是环境变量中 PATH 所定义的路径。

make <make-args>

可以在 gdb 中执行 make 命令来重新build自己的程序。这个命令等价于“shell make <make-args>”。

使用 l 或 list 命令，看看gdb是否能列出源代码。
在 gdb 中，运行程序使用 r 或是run命令。程序的运行，你有可能需要设置下面四方面的事。

- path <dir> 可设定程序的运行路径。
- show paths 查看程序的运行路径。
- set environment varname [=value] 设置环境变量。如：set env USER=hchen
- show environment [varname] 查看环境变量。

- info terminal 显示你程序用到的终端的模式。
- 使用重定向控制程序输出。如：run > outfile
- tty 命令可以指写输入输出的终端设备。如：tty /dev/ttyb

调试已运行的程序
————————
两种方法：
1、在 UNIX 下用 ps 查看正在运行的程序的PID（进程ID),然后用gdb <program> PID格式挂接正在运行的程序。
2、先用 gdb <program>关联上源代码，并进行 gdb, 在gdb 中用attach命令来挂接进程的PID。并用detach来取消挂接的进
程。
暂停 / 恢复程序运行
—————————
调试程序中，暂停程序运行是必须的，GDB 可以方便地暂停程序的运行。你可以设置程序的在哪行停住, 在什么条件下停
住，在收到什么信号时停往等等。以便于你查看运行时的变量，以及运行时的流程。
当进程被 gdb 停住时，你可以使用 info program 来查看程序的是否在运行，进程号, 被暂停的原因。
在 gdb 中，我们可以有以下几种暂停方式：断点 (BreakPoint)、观察点(WatchPoint)、捕捉点(CatchPoint)、信号
(Signals)、线程停止 (Thread Stops)。如果要恢复程序运行，可以使用 c 或是continue 命令。


break 命令来设置断点。正面有几点设置断点的方法：
break <function>
在进入指定函数时停住。C++ 中可以使用 class::function 或 function(type,type)格式来指定函数名。
break <linenum>
在指定行号停住。
break +offset
break -offset
在当前行号的前面或后面的 offset 行停住。offiset 为自然数。
break filename:linenum
在源文件 filename 的 linenum 行处停住。
break filename:function
在源文件 filename 的 function 函数的入口处停住。

    break *address

在程序运行的内存地址处停住。
break
break 命令没有参数时，表示在下一条指令处停住。
break ... if <condition>
... 可以是上述的参数，condition 表示条件，在条件成立时停住。比如在循环境体中,可以设置 break if i=100,表示
当 i 为 100 时停住程序。
查看断点时，可使用 info 命令，如下所示：（注：n 表示断点号）
info breakpoints [n]
info break [n]


## 观察点 (WatchPoint)
观察点一般来观察某个表达式（变量也是一种表达式）的值是否有变化了，如果有变化，马上停住程序。我们有下面的
几种方法来设置观察点：
watch <expr>
为表达式（变量）expr 设置一个观察点。一量表达式值有变化时，马上停住程序。
rwatch <expr>
当表达式（变量）expr 被读时，停住程序。
awatch <expr>
当表达式（变量）的值被读或被写时，停住程序。
info watchpoints
列出当前所设置了的所有观察点。

## 捕捉点 (CatchPoint)
你可设置捕捉点来补捉程序运行时的一些事件。如：载入共享库（动态链接库）或是 C++ 的异常。设置捕捉点的格式为：
catch <event>
当 event 发生时，停住程序。event 可以是下面的内容：
1、throw 一个 C++ 抛出的异常。(throw 为关键字）
2、catch 一个 C++ 捕捉到的异常。(catch 为关键字）
3、exec 调用系统调用 exec 时。(exec 为关键字，目前此功能只在 HP-UX下有用）
4、fork 调用系统调用 fork 时。(fork 为关键字，目前此功能只在 HP-UX下有用）
5、vfork 调用系统调用 vfork 时。(vfork 为关键字，目前此功能只在 HP-UX下有用）
6、load 或 load <libname> 载入共享库（动态链接库）时。(load 为关键字，目前此功能只在 HP-UX 下有用）
7、unload 或 unload <libname> 卸载共享库（动态链接库）时。(unload 为关键字，目前此功能只在 HP-UX 下有用）
tcatch <event>
只设置一次捕捉点，当程序停住以后，应点被自动删除。

## points

如果你觉得已定义好的停止点没有用
了，你可以使用 delete、clear、disable、enable 这几个命令来进行维护。
clear
清除所有的已定义的停止点。
clear <function>
clear <filename:function>
清除所有设置在函数上的停止点。
clear <linenum>
clear <filename:linenum>
清除所有设置在指定行上的停止点。
delete [breakpoints] [range...]
删除指定的断点，breakpoints 为断点号。如果不指定断点号，则表示删除所有的断点。range 表示断点号的范围（如：
3-7)。其简写命令为 d。
比删除更好的一种方法是 disable 停止点，disable 了的停止点，GDB不会删除,当你还需要时,enable即可,就好像回收
站一样。
disable [breakpoints] [range...]
disable 所指定的停止点，breakpoints 为停止点号。如果什么都不指定，表示 disable所有的停止点。简写命令是 dis.
enable [breakpoints] [range...]
enable 所指定的停止点，breakpoints 为停止点号。
enable [breakpoints] once range...
enable 所指定的停止点一次，当程序停止后，该停止点马上被 GDB 自动 disable。
enable [breakpoints] delete range...
enable 所指定的停止点一次，当程序停止后，该停止点马上被 GDB 自动删除。

## e 所指定的停止点一次，当程序停止后，该停止点马上被 GDB 自动删除。
五、停止条件维护
前面在说到设置断点时，我们提到过可以设置一个条件，当条件成立时, 程序自动停止,这是一个非常强大的功能,这
里，我想专门说说这个条件的相关维护命令。一般来说，为断点设置一个条件, 我们使用 if关键词,后面跟其断点条
件。并且，条件设置好后，我们可以用 condition 命令来修改断点的条件。（只有 break和watch命令支持if,catch目前
暂不支持 if)
condition <bnum> <expression>
修改断点号为 bnum 的停止条件为 expression。
condition <bnum>
清除断点号为 bnum 的停止条件。
还有一个比较特殊的维护命令 ignore, 你可以指定程序运行时，忽略停止条件几次。
ignore <bnum> <count>
表示忽略断点号为 bnum 的停止条件 count 次。

## 为停止点设定运行命令
我们可以使用 GDB 提供的 command 命令来设置停止点的运行命令。也就是说，当运行的程序在被停止住时，我们可以让其
自动运行一些别的命令，这很有利行自动化调试。对基于 GDB 的自动化调试是一个强大的支持。

commands [bnum]

... command-list ...
end
为断点号 bnum 指写一个命令列表。当程序被该断点停住时，gdb 会依次运行命令列表中的命令。
例如：
break foo if x>0
commands
printf "x is %dn",x
continue
end
断点设置在函数 foo 中，断点条件是 x>0, 如果程序被断住后，也就是,一旦x的值在foo函数中大于0,GDB会自动打印出x
的值，并继续运行程序。
如果你要清除断点上的命令序列，那么只要简单的执行一下 commands 命令，并直接在打个 end 就行了。

# 断点菜单
在 C++ 中，可能会重复出现同一个名字的函数若干次（函数重载）, 在这种情况下，break <function>不能告诉 GDB要停
在哪个函数的入口。当然，你可以使用 break <function(type)>也就是把函数的参数类型告诉 GDB, 以指定一个函数。否
则的话，GDB 会给你列出一个断点菜单供你选择你所需要的断点。你只要输入你菜单列表中的编号就可以了。如：

```
(gdb) b String::after
[0] cancel
[1] all
[2] file:String.cc; line number:867
[3] file:String.cc; line number:860
[4] file:String.cc; line number:875
[5] file:String.cc; line number:853
[6] file:String.cc; line number:846
[7] file:String.cc; line number:735
> 2 4 6
Breakpoint 1 at 0xb26c: file String.cc, line 867.
Breakpoint 2 at 0xb344: file String.cc, line 875.
Breakpoint 3 at 0xafcc: file String.cc, line 846.
Multiple breakpoints were set.
Use the "delete" command to delete unwanted
breakpoints.
(gdb)
```

GDB 列出了所有 after 的重载函数，你可以选一下列表编号就行了。0表示放弃设置断点，1表示所有函数都设置断
点


# 恢复程序运行和单步调试
当程序被停住了，你可以用 continue 命令恢复程序的运行直到程序结束，或下一个断点到来。也可以使用 step 或next命
令单步跟踪程序。
```
continue [ignore-count]
c [ignore-count]
fg [ignore-count]
```
恢复程序运行，直到程序结束，或是下一个断点到来。ignore-count 表示忽略其后的断点次数。continue,c,fg三个命
令都是一样的意思。

    step <count>

单步跟踪，如果有函数调用，他会进入该函数。进入函数的前提是, 此函数被编译有 debug信息。很像 VC等工具中的step
in。后面可以加 count 也可以不加，不加表示一条条地执行，加表示执行后面的 count 条指令,然后再停住。

    next <count>

同样单步跟踪，如果有函数调用，他不会进入该函数。很像 VC 等工具中的 step over。后面可以加count也可以不加,不
加表示一条条地执行，加表示执行后面的 count 条指令，然后再停住。

    set step-mode

    set step-mode on

打开 step-mode 模式，于是，在进行单步跟踪时, 程序不会因为没有 debug信息而不停住。这个参数有很利于查看机器
码。

    set step-mod off

关闭 step-mode 模式。

    finish

运行程序，直到当前函数完成返回。并打印函数返回时的堆栈地址和返回值及参数值等信息。

    until 或 u

当你厌倦了在一个循环体内单步跟踪时，这个命令可以运行程序直到退出循环体。
stepi 或 si
nexti 或 ni
单步跟踪一条机器指令！一条程序代码有可能由数条机器指令完成，stepi 和 nexti 可以单步执行机器指令。与之一样有
相同功能的命令是“display/i $pc” , 当运行完这个命令后，单步跟踪会在打出程序代码的同时打出机器指令（也就
是汇编代码）


# 信号 (Signals)
信号是一种软中断，是一种处理异步事件的方法。一般来说，操作系统都支持许多信号。尤其是 UNIX, 比较重要应用程
序一般都会处理信号。UNIX 定义了许多信号，比如 SIGINT 表示中断字符信号，也就是 Ctrl+C的信号,SIGBUS表示硬件故
障的信号；SIGCHLD 表示子进程状态改变信号；SIGKILL 表示终止程序运行的信号，等等。信号量编程是 UNIX下非常重要
的一种技术。
GDB 有能力在你调试程序的时候处理任何一种信号，你可以告诉 GDB 需要处理哪一种信号。你可以要求 GDB收到你所指定的
信号时，马上停住正在运行的程序，以供你进行调试。你可以用 GDB 的 handle命令来完成这一功能。

handle <signal> <keywords...>
在 GDB 中定义一个信号处理。信号<signal>可以以 SIG 开头或不以SIG开头，可以用定义一个要处理信号的范围（如：
SIGIO-SIGKILL, 表示处理从 SIGIO 信号到 SIGKILL的信号，其中包括SIGIO,SIGIOT,SIGKILL三个信号）,也可以使用关
键字 all 来标明要处理所有的信号。一旦被调试的程序接收到信号，运行程序马上会被 GDB 停住，以供调试。其
<keywords>可以是以下几种关键字的一个或多个。
nostop
当被调试的程序收到信号时，GDB 不会停住程序的运行，但会打出消息告诉你收到这种信号。
stop
当被调试的程序收到信号时，GDB 会停住你的程序。
print
当被调试的程序收到信号时，GDB 会显示出一条信息。
noprint
当被调试的程序收到信号时，GDB 不会告诉你收到信号的信息。
pass
noignore
当被调试的程序收到信号时，GDB 不处理信号。这表示，GDB 会把这个信号交给被调试程序会处理。
nopass
ignore
当被调试的程序收到信号时，GDB 不会让被调试程序来处理这个信号。
info signals
info handle
查看有哪些信号在被 GDB 检测中。


# 线程 (Thread Stops)
如果你程序是多线程的话，你可以定义你的断点是否在所有的线程上，或是在某个特定的线程。GDB 很容易帮你完成这一
工作。
break <linespec> thread <threadno>
break <linespec> thread <threadno> if ...
linespec 指定了断点设置在的源程序的行号。threadno 指定了线程的 ID,注意，这个 ID是GDB分配的，你可以通过“info
threads”命令来查看正在运行程序中的线程信息。如果你不指定 thread <threadno>则表示你的断点设在所有线程上
面。你还可以为某线程指定断点条件。如：
(gdb) break frik.c:13 thread 28 if bartab > lim
当你的程序被 GDB 停住时，所有的运行线程都会被停住。这方便你你查看运行程序的总体情况。而在你恢复程序运行时，
所有的线程也会被恢复运行。那怕是主进程在被单步调试时。

## 查看栈信息

当程序被停住了，你需要做的第一件事就是查看程序是在哪里停住的。当你的程序调用了一个函数，函数的地址, 函数
参数，函数内的局部变量都会被压入“栈”(Stack) 中。你可以用 GDB 命令来查看当前的栈中的信息。
下面是一些查看函数调用栈信息的 GDB 命令：
backtrace
bt

(gdb) bt
#0 func (n=250) at tst.c:6
#1 0x08048524 in main (argc=1, argv=0xbffff674) at tst.c:30
#2 0x400409ed in __libc_start_main () from /lib/libc.so.6

从上可以看出函数的调用栈信息：__libc_start_main --> main() --> func()
backtrace <n>
bt <n>
n 是一个正整数，表示只打印栈顶上 n 层的栈信息。

backtrace <-n>
bt <-n>
-n 表一个负整数，表示只打印栈底下 n 层的栈信息。

如果你要查看某一层的信息，你需要在切换当前的栈，一般来说, 程序停止时,最顶层的栈就是当前栈,如果你要查看
栈下面层的详细信息，首先要做的是切换当前栈。

frame <n>
f <n>

n 是一个从 0 开始的整数，是栈中的层编号。比如：frame 0,表示栈顶，frame 1,表示栈的第二层。

up <n>

表示向栈的上面移动 n 层，可以不打 n, 表示向上移动一层。

down <n>

表示向栈的下面移动 n 层，可以不打 n, 表示向下移动一层。

上面的命令，都会打印出移动到的栈层的信息。如果你不想让其打出信息。你可以使用这三个命令：

select-frame <n> 对应于 frame 命令。
up-silently <n> 对应于 up 命令。
down-silently <n> 对应于 down 命令。

查看当前栈层的信息，你可以用以下 GDB 命令：
frame 或 f
会打印出这些信息：栈的层编号，当前的函数名，函数参数值, 函数所在文件及行号,函数执行到的语句。
info frame
info f

这个命令会打印出更为详细的当前栈层的信息，只不过，大多数都是运行时的内内地址。比如：函数地址, 调用函数的
地址，被调用函数的地址，目前的函数是由什么样的程序语言写成的、函数参数地址及值、局部变量的地址等等。如：

```
(gdb) info f
Stack level 0, frame at 0xbffff5d4:
eip = 0x804845d in func (tst.c:6); saved eip 0x8048524
called by frame at 0xbffff60c
source language c.
Arglist at 0xbffff5d4, args: n=250
Locals at 0xbffff5d4, Previous frame''s sp is 0x0
Saved registers:
ebp at 0xbffff5d4, eip at 0xbffff5d8
```

- info args
打印出当前函数的参数名及其值。
- info locals
打印出当前函数中所有局部变量及其值。
- info catch
打印出当前的函数中的异常处理信息。

# 程序停下来以后，GDB 会报告程序停在了那个文件的第几行上。你可以用 list 命令来打印程序的源代码

list <linenum>
显示程序第 linenum 行的周围的源程序。
list <function>
显示函数名为 function 的函数的源程序。
list
显示当前行后面的源程序。
list -
显示当前行前面的源程序。
一般是打印当前行的上 5 行和下 5 行，如果显示函数是是上2行下8行，默认是10行,当然,你也可以定制显示的范围,使
用下面命令可以设置一次显示源程序的行数。
set listsize <count>
设置一次显示源代码的行数。
show listsize
查看当前 listsize 的设置。
list 命令还有下面的用法：
list <first>, <last>
显示从 first 行到 last 行之间的源代码。
list , <last>
显示从当前行到 last 行之间的源代码。
list +
往后显示源代码。
一般来说在 list 后面可以跟以下这们的参数：
<linenum> 行号。
<+offset> 当前行号的正偏移量。
<-offset> 当前行号的负偏移量。
<filename:linenum> 哪个文件的哪一行。

<function> 函数名。
<filename:function> 哪个文件中的哪个函数。
<*address> 程序运行时的语句在内存中的地址。

## GDB 还提供了源代码搜索的命令：
forward-search <regexp>
search <regexp>
向前面搜索。
reverse-search <regexp>
全部搜索。
其中，<regexp>就是正则表达式，也主一个字符串的匹配模式, 关于正则表达式,我就不在这里讲了,还请各位查看相
关资料。

## 指定源文件的路径
某些时候，用 -g 编译过后的执行程序中只是包括了源文件的名字，没有路径名。GDB 提供了可以让你指定源文件的路径的
命令，以便 GDB 进行搜索。
directory <dirname ... >
dir <dirname ... >
加一个源文件路径到当前路径的前面。如果你要指定多个路径，UNIX 下你可以使用“:”,Windows 下你可以使用“;”。
directory
清除所有的自定义的源文件搜索路径信息。
show directories
显示定义了的源文件搜索路径。

# 源代码的内存
你可以使用 info line 命令来查看源代码在内存中的地址。info line 后面可以跟“行号”,“函数名”,“文件名：行
号”,“文件名：函数名”, 这个命令会打印出所指定的源码在运行时的内存地址，如：
(gdb) info line tst.c:func
Line 5 of "tst.c" starts at address 0x8048456 <func+6> and ends at 0x804845d <func+13>.
还有一个命令 (disassemble) 你可以查看源程序的当前执行时的机器码，这个命令会把目前内存中的指令 dump 出来。如
下面的示例表示查看函数 func 的汇编代码。
(gdb) disassemble func
Dump of assembler code for function func:
0x8048450 <func>: push %ebp
0x8048451 <func+1>: mov %esp,%ebp
0x8048453 <func+3>: sub $0x18,%esp
0x8048456 <func+6>: movl $0x0,0xfffffffc(%ebp)
0x804845d <func+13>: movl $0x1,0xfffffff8(%ebp)
0x8048464 <func+20>: mov 0xfffffff8(%ebp),%eax
0x8048467 <func+23>: cmp 0x8(%ebp),%eax
0x804846a <func+26>: jle 0x8048470 <func+32>
0x804846c <func+28>: jmp 0x8048480 <func+48>
0x804846e <func+30>: mov %esi,%esi
0x8048470 <func+32>: mov 0xfffffff8(%ebp),%eax
0x8048473 <func+35>: add %eax,0xfffffffc(%ebp)
0x8048476 <func+38>: incl 0xfffffff8(%ebp)
0x8048479 <func+41>: jmp 0x8048464 <func+20>
0x804847b <func+43>: nop
0x804847c <func+44>: lea 0x0(%esi,1),%esi
0x8048480 <func+48>: mov 0xfffffffc(%ebp),%edx
0x8048483 <func+51>: mov %edx,%eax
0x8048485 <func+53>: jmp 0x8048487 <func+55>
0x8048487 <func+55>: mov %ebp,%esp
0x8048489 <func+57>: pop %ebp
0x804848a <func+58>: ret
End of assembler dump.

# 查看运行时数据

在你调试程序时，当程序被停住时，你可以使用 print 命令（简写命令为 p),或是同义命令inspect来查看当前程序的运
行数据。print 命令的格式是：
print <expr>
print /<f> <expr>
<expr>是表达式，是你所调试的程序的语言的表达式 (GDB 可以调试多种编程语言）,<f>是输出的格式，比如, 如果要
把表达式按 16 进制的格式输出，那么就是 /x。
一、表达式
print 和许多 GDB 的命令一样，可以接受一个表达式，GDB会根据当前的程序运行的数据来计算这个表达式,既然是表达
式，那么就可以是当前程序运行中的 const 常量、变量、函数等内容。可惜的是 GDB 不能使用你在程序中所定义的宏。

表达式的语法应该是当前所调试的语言的语法，由于 C/C++ 是一种大众型的语言，所以, 本文中的例子都是关于 C/C++
的。（而关于用 GDB 调试其它语言的章节，我将在后面介绍）
在表达式中，有几种 GDB 所支持的操作符，它们可以用在任何一种语言中。
@
是一个和数组有关的操作符，在后面会有更详细的说明。
::
指定一个在文件或是一个函数中的变量。
{<type>} <addr>
表示一个指向内存地址<addr>的类型为 type 的一个对象。
二、程序变量
在 GDB 中，你可以随时查看以下三种变量的值：
1、全局变量（所有文件可见的）
2、静态全局变量（当前文件可见的）
3、局部变量（当前 Scope 可见的）
如果你的局部变量和全局变量发生冲突（也就是重名）, 一般情况下是局部变量会隐藏全局变量，也就是说，如果一个
全局变量和一个函数中的局部变量同名时，如果当前停止点在函数中，用 print 显示出的变量的值会是函数中的局部变量
的值。如果此时你想查看全局变量的值时，你可以使用“::”操作符：
file::variable
function::variable
可以通过这种形式指定你所想查看的变量，是哪个文件中的或是哪个函数中的。例如，查看文件 f2.c 中的全局变量 x的
值：
gdb) p ''f2.c''::x
当然，“::”操作符会和 C++ 中的发生冲突，GDB 能自动识别“::” 是否 C++的操作符,所以你不必担心在调试C++程序时
会出现异常。
另外，需要注意的是，如果你的程序编译时开启了优化选项, 那么在用 GDB调试被优化过的程序时,可能会发生某些变量
不能访问，或是取值错误码的情况。这个是很正常的，因为优化程序会删改你的程序, 整理你程序的语句顺序,剔除一
些无意义的变量等，所以在 GDB 调试这种程序时，运行时的指令和你所编写指令就有不一样, 也就会出现你所想象不到的
结果。对付这种情况时，需要在编译程序时关闭编译优化。一般来说，几乎所有的编译器都支持编译优化的开关, 例
如，GNU 的 C/C++ 编译器 GCC,你可以使用“-gstabs”选项来解决这个问题。关于编译器的参数，还请查看编译器的使用
说明文档。
三、数组
有时候，你需要查看一段连续的内存空间的值。比如数组的一段，或是动态分配的数据的大小。你可以使用 GDB 的“@”
操作符，“@”的左边是第一个内存的地址的值，“@”的右边则你你想查看内存的长度。例如, 你的程序中有这样的语
句：

    int *array = (int *) malloc (len * sizeof (int));

于是，在 GDB 调试过程中，你可以以如下命令显示出这个动态数组的取值：

    p *array@len

@的左边是数组的首地址的值，也就是变量 array 所指向的内容，右边则是数据的长度, 其保存在变量 len中,其输出结
果，大约是下面这个样子的：

    (gdb) p *array@len

$1 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40}
如果是静态数组的话，可以直接用 print 数组名，就可以显示数组中所有数据的内容了。
四、输出格式
一般来说，GDB 会根据变量的类型输出变量的值。但你也可以自定义 GDB 的输出的格式。例如，你想输出一个整数的十六
进制，或是二进制来查看这个整型变量的中的位的情况。要做到这样，你可以使用 GDB 的数据显示格式：
x 按十六进制格式显示变量。
d 按十进制格式显示变量。
u 按十六进制格式显示无符号整型。
o 按八进制格式显示变量。
t 按二进制格式显示变量。
a 按十六进制格式显示变量。
c 按字符格式显示变量。
f 按浮点数格式显示变量。
(gdb) p i
$21 = 101
(gdb) p/a i

$22 = 0x65
(gdb) p/c i
$23 = 101 ''e''
(gdb) p/f i
$24 = 1.41531145e-43
(gdb) p/x i
$25 = 0x65
(gdb) p/t i
$26 = 1100101


# 查看内存
你可以使用 examine 命令（简写是 x) 来查看内存地址中的值。x命令的语法如下所示：
x/<n/f/u> <addr>
n、f、u 是可选的参数。
n 是一个正整数，表示显示内存的长度，也就是说从当前地址向后显示几个地址的内容。
f 表示显示的格式，参见上面。如果地址所指的是字符串，那么格式可以是 s, 如果地十是指令地址,那么格式可以是 i
。
u 表示从当前地址往后请求的字节数，如果不指定的话，GDB 默认是 4 个 bytes。u参数可以用下面的字符来代替,b表示单
字节，h 表示双字节，w 表示四字节,g表示八字节。当我们指定了字节长度后,GDB会从指内存定的内存地址开始,读写
指定字节，并把其当作一个值取出来。
<addr>表示一个内存地址。
n/f/u 三个参数可以一起使用。例如：
命令：x/3uh 0x54320 表示，从内存地址 0x54320 读取内容，h 表示以双字节为一个单位,3表示三个单位,u表示按十六
进制显示。

# 自动显示
你可以设置一些自动显示的变量，当程序停住时，或是在你单步跟踪时, 这些变量会自动显示。相关的 GDB命令是
display。
display <expr>
display/<fmt> <expr>
display/<fmt> <addr>
expr 是一个表达式，fmt 表示显示的格式，addr表示内存地址,当你用 display设定好了一个或多个表达式后,只要你的
程序被停下来，GDB 会自动显示你所设置的这些表达式的值。
格式 i 和 s 同样被display支持，一个非常有用的命令是：
display/i $pc
$pc 是 GDB 的环境变量，表示着指令的地址，/i则表示输出格式为机器指令码,也就是汇编。于是当程序停下后,就会出
现源代码和机器指令码相对应的情形，这是一个很有意思的功能。
下面是一些和 display 相关的 GDB 命令：
undisplay <dnums...>
delete display <dnums...>
删除自动显示，dnums 意为所设置好了的自动显式的编号。如果要同时删除几个，编号可以用空格分隔, 如果要删除一个
范围内的编号，可以用减号表示（如：2-5)
disable display <dnums...>
enable display <dnums...>
disable 和 enalbe 不删除自动显示的设置，而只是让其失效和恢复。
info display
查看 display 设置的自动显示的信息。GDB 会打出一张表格，向你报告当然调试中设置了多少个自动显示设置，其中包
括，设置的编号，表达式, 是否 enable。

# 设置显示选项
GDB 中关于显示的选项比较多，这里我只例举大多数常用的选项。
set print address
set print address on
打开地址输出，当程序显示函数信息时，GDB 会显出函数的参数地址。系统默认为打开的, 如：
(gdb) f
#0 set_quotes (lq=0x34c78 "<<", rq=0x34c88 ">>")

at input.c:530
530 if (lquote != def_lquote)
set print address off
关闭函数的参数地址显示，如：
(gdb) set print addr off
(gdb) f
#0 set_quotes (lq="<<", rq=">>") at input.c:530
530 if (lquote != def_lquote)
show print address
查看当前地址显示选项是否打开。
set print array
set print array on
打开数组显示，打开后当数组显示时，每个元素占一行, 如果不打开的话,每个元素则以逗号分隔。这个选项默认是关
闭的。与之相关的两个命令如下，我就不再多说了。
set print array off
show print array
set print elements <number-of-elements>
这个选项主要是设置数组的，如果你的数组太大了，那么就可以指定一个<number-of-elements>来指定数据显示的最大
长度，当到达这个长度时，GDB 就不再往下显示了。如果设置为 0, 则表示不限制。
show print elements
查看 print elements 的选项信息。
set print null-stop <on/off>
如果打开了这个选项，那么当显示字符串时，遇到结束符则停止显示。这个选项默认为 off。
set print pretty on
如果打开 printf pretty 这个选项，那么当 GDB 显示结构体时会比较漂亮。如：
$1 = {
next = 0x0,
flags = {
sweet = 1,
sour = 1
},
meat = 0x54 "Pork"
}
set print pretty off
关闭 printf pretty 这个选项，GDB 显示结构体时会如下显示：
$1 = {next = 0x0, flags = {sweet = 1, sour = 1}, meat = 0x54 "Pork"}
show print pretty
查看 GDB 是如何显示结构体的。
set print sevenbit-strings <on/off>
设置字符显示，是否按“nnn”的格式显示，如果打开, 则字符串或字符数据按 nnn显示,如“65”。
show print sevenbit-strings
查看字符显示开关是否打开。
set print union <on/off>
设置显示结构体时，是否显式其内的联合体数据。例如有以下数据结构：
typedef enum {Tree, Bug} Species;
typedef enum {Big_tree, Acorn, Seedling} Tree_forms;
typedef enum {Caterpillar, Cocoon, Butterfly}
Bug_forms;
struct thing {
Species it;
union {
Tree_forms tree;
Bug_forms bug;
} form;
};
struct thing foo = {Tree, {Acorn}};
当打开这个开关时，执行 p foo 命令后，会如下显示：
$1 = {it = Tree, form = {tree = Acorn, bug = Cocoon}}

当关闭这个开关时，执行 p foo 命令后，会如下显示：
$1 = {it = Tree, form = {...}}
show print union
查看联合体数据的显示方式
set print object <on/off>
在 C++ 中，如果一个对象指针指向其派生类，如果打开这个选项,GDB 会自动按照虚方法调用的规则显示输出,如果关闭
这个选项的话，GDB 就不管虚函数表了。这个选项默认是 off。
show print object
查看对象选项的设置。
set print static-members <on/off>
这个选项表示，当显示一个 C++ 对象中的内容是，是否显示其中的静态数据成员。默认是 on。
show print static-members
查看静态数据成员选项设置。
set print vtbl <on/off>
当此选项打开时，GDB 将用比较规整的格式来显示虚函数表时。其默认是关闭的。
show print vtbl
查看虚函数显示格式的选项。


# 历史记录
当你用 GDB 的 print 查看程序运行时的数据时，你每一个print都会被GDB记录下来。GDB会以$1, $2, $3 .....这样的方式
为你每一个 print 命令编上号。于是，你可以使用这个编号访问以前的表达式，如 $1。这个功能所带来的好处是, 如果你
先前输入了一个比较长的表达式，如果你还想查看这个表达式的值，你可以使用历史记录来访问, 省去了重复输入

# GDB 环境变量
你可以在 GDB 的调试环境中定义自己的变量，用来保存一些调试程序中的运行数据。要定义一个 GDB 的变量很简单只需。
使用 GDB 的 set 命令。GDB的环境变量和UNIX一样，也是以$起头。如：

    set $foo = *object_ptr

使用环境变量时，GDB 会在你第一次使用时创建这个变量，而在以后的使用中, 则直接对其賦值。环境变量没有类型,你
可以给环境变量定义任一的类型。包括结构体和数组。
show convenience
该命令查看当前所设置的所有的环境变量。
这是一个比较强大的功能，环境变量和程序变量的交互使用，将使得程序调试更为灵活便捷。例如：
set $i = 0
print bar[$i++]->contents
于是，当你就不必，print bar[0]->contents, print bar[1]->contents 地输入命令了。输入这样的命令后, 只用敲回
车，重复执行上一条语句，环境变量会自动累加, 从而完成逐个输出的功能。

# 查看寄存器
要查看寄存器的值，很简单，可以使用如下命令：
info registers
查看寄存器的情况。（除了浮点寄存器）
info all-registers
查看所有寄存器的情况。（包括浮点寄存器）
info registers <regname ...>
查看所指定的寄存器的情况。
寄存器中放置了程序运行时的数据，比如程序当前运行的指令地址 (ip), 程序的当前堆栈地址 (sp) 等等。你同样可
以使用 print 命令来访问寄存器的情况，只需要在寄存器名字前加一个 $ 符号就可以了。如：p $eip。
改变程序的执行
———————
一旦使用 GDB 挂上被调试程序，当程序运行起来后，你可以根据自己的调试思路来动态地在 GDB 中更改当前被调试程序的
运行线路或是其变量的值，这个强大的功能能够让你更好的调试你的程序，比如, 你可以在程序的一次运行中走遍程序
的所有分支。
一、修改变量值
修改被调试程序运行时的变量值，在 GDB 中很容易实现，使用 GDB 的print命令即可完成。如

(gdb) print x=4
x=4 这个表达式是 C/C++ 的语法，意为把变量 x的值修改为4,如果你当前调试的语言是Pascal,那么你可以使用Pascal的
语法：x:=4。
在某些时候，很有可能你的变量和 GDB 中的参数冲突，如：
(gdb) whatis width
type = double
(gdb) p width
$4 = 13
(gdb) set width=47
Invalid syntax in expression.
因为，set width 是 GDB 的命令，所以,出现了“Invalid syntax in expression”的设置错误,此时,你可以使用 set
var 命令来告诉 GDB,width 不是你 GDB的参数，而是程序的变量名，如：
(gdb) set var width=47
另外，还可能有些情况，GDB 并不报告这种错误, 所以保险起见,在你改变程序变量取值时,最好都使用 set var格式的
GDB 命令。


## 跳转执行
一般来说，被调试程序会按照程序代码的运行顺序依次执行。GDB 提供了乱序执行的功能，也就是说,GDB 可以修改程序
的执行顺序，可以让程序执行随意跳跃。这个功能可以由 GDB 的 jump 命令来完：
jump <linespec>
指定下一条语句的运行点。<linespce>可以是文件的行号，可以是 file:line 格式，可以是 +num 这种偏移量格式。表式着
下一条运行语句从哪里开始。
jump <address>
这里的<address>是代码行的内存地址。
注意，jump 命令不会改变当前的程序栈中的内容，所以, 当你从一个函数跳到另一个函数时,当函数运行完返回时进行
弹栈操作时必然会发生错误，可能结果还是非常奇怪的，甚至于产生程序 Core Dump。所以最好是同一个函数中进行跳
转。
熟悉汇编的人都知道，程序运行时，有一个寄存器用于保存当前代码所在的内存地址。所以,jump 命令也就是改变了这
个寄存器中的值。于是，你可以使用“set $pc”来更改跳转执行的地址。如：
set $pc = 0x485


## 产生信号量
使用 singal 命令，可以产生一个信号量给被调试的程序。如：中断信号 Ctrl+C。这非常方便于程序的调试，可以在程序
运行的任意位置设置断点，并在该断点用 GDB 产生一个信号量，这种精确地在某处产生信号非常有利程序的调试。
语法是：signal <singal>,UNIX 的系统信号量通常从 1 到 15。所以<singal>取值也在这个范围。
single 命令和 shell 的 kill命令不同，系统的kill命令发信号给被调试程序时，是由GDB截获的,而single命令所发出一
信号则是直接发给被调试程序的。

## 强制函数返回
如果你的调试断点在某个函数中，并还有语句没有执行完。你可以使用 return 命令强制函数忽略还没有执行的语句并返
回。
return
return <expression>
使用 return 命令取消当前函数的执行，并立即返回，如果指定了<expression>, 那么该表达式的值会被认作函数的返回
值。

## 强制调用函数
call <expr>
表达式中可以一是函数，以此达到强制调用函数的目的。并显示函数的返回值，如果函数返回值是 void, 那么就不显
示。
另一个相似的命令也可以完成这一功能——print,print 后面可以跟表达式，所以也可以用他来调用函数，print 和 call
的不同是，如果函数返回 void,call 则不显示，print 则显示函数返回值,并把该值存入历史数据中。
在不同语言中使用 GDB
——————————
GDB 支持下列语言：C, C++, Fortran, PASCAL, Java, Chill, assembly, 和 Modula-2。一般说来，GDB 会根据你所调试
的程序来确定当然的调试语言，比如：发现文件名后缀为“.c”的，GDB 会认为是 C 程序。文件名后缀为“.C, .cc, .cp,
.cpp, .cxx, .c++”的，GDB 会认为是 C++ 程序。而后缀是“.f, .F”的，GDB会认为是 Fortran程序,还有,后缀为如果
是“.s, .S”的会认为是汇编语言。
也就是说，GDB 会根据你所调试的程序的语言，来设置自己的语言环境, 并让 GDB的命令跟着语言环境的改变而改变。比
如一些 GDB 命令需要用到表达式或变量时，这些表达式或变量的语法，完全是根据当前的语言环境而改变的。例如 C/C++
中对指针的语法是*p, 而在 Modula-2 中则是 p^。并且，如果你当前的程序是由几种不同语言一同编译成的，那到在调试
过程中，GDB 也能根据不同的语言自动地切换语言环境。这种跟着语言环境而改变的功能，真是体贴开发人员的一种设
计。
下面是几个相关于 GDB 语言环境的命令：
show language
查看当前的语言环境。如果 GDB 不能识为你所调试的编程语言，那么，C 语言被认为是默认的环境。
info frame
查看当前函数的程序语言。
info source
查看当前文件的程序语言。
如果 GDB 没有检测出当前的程序语言，那么你也可以手动设置当前的程序语言。使用 set language 命令即可做到。
当 set language 命令后什么也不跟的话，你可以查看 GDB 所支持的语言种类：
(gdb) set language
The currently understood settings are:
local or auto Automatic setting based on source file
c Use the C language
c++ Use the C++ language
asm Use the Asm language
chill Use the Chill language
fortran Use the Fortran language
java Use the Java language
modula-2 Use the Modula-2 language
pascal Use the Pascal language
scheme Use the Scheme language
于是你可以在 set language 后跟上被列出来的程序语言名，来设置当前的语言环境

## gdb 支援 thread 、 remote debugging 、硬體架構模擬

## References
* [100 个 gdb 小技巧](https://www.gitbook.com/book/wizardforcel/100-gdb-tips/details)

### Left operand of assignment is not an lvalue
* http://stackoverflow.com/questions/22309028/gdb-left-operand-of-assignment-is-not-an-lvalue
* http://stackoverflow.com/questions/1345338/gdb-behavior-value-optimized-out
* http://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c
* https://zh.wikipedia.org/wiki/Volatile%E5%8F%98%E9%87%8F
* https://en.wikipedia.org/wiki/Volatile_(computer_programming)
* http://ieng9.ucsd.edu/~cs30x/Non-modifiable%20Lvalues.htm
* http://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c

### conditional breakpoint
* [How do I set a conditional breakpoint in gdb, when char* x points to a string whose value equals “hello”?](https://stackoverflow.com/questions/4183871/how-do-i-set-a-conditional-breakpoint-in-gdb-when-char-x-points-to-a-string-wh)
* [GDB: break if variable equal value](https://stackoverflow.com/questions/14390256/gdb-break-if-variable-equal-value)

### type cast
* [Why gdb casting is not working?](https://stackoverflow.com/questions/4594395/why-gdb-casting-is-not-working)

```
(gdb) p ('MyScope::MyClass'*) ptr;
```

### catch exception

* https://sourceware.org/gdb/onlinedocs/gdb/Set-Catchpoints.html

```
(gdb) catch throw
```

* [How to break when a specific exception type is thrown in GDB?](https://stackoverflow.com/questions/6835728/how-to-break-when-a-specific-exception-type-is-thrown-in-gdb)

* [How to remove catchpoint in gdb](https://stackoverflow.com/questions/31069780/how-to-remove-catchpoint-in-gdb)

#### catch `std::bad_alloc`
* [Tip of the day: Finding the source of a bad_alloc exception](http://agateau.com/2009/tip-of-the-day-finding-the-source-of-a-bad_alloc-exception/)

```
b 'std::bad_alloc::bad_alloc()'
```

### break at assersion
* [gdb Breakpoint on assert on in multithreaded C program](https://stackoverflow.com/questions/39399227/gdb-breakpoint-on-assert-on-in-multithreaded-c-program)
```
(gdb) b __assert_fail@plt
```

### break at exit
* [C++ Program quits unexpectedly, how do I debug this with gdb?](https://stackoverflow.com/questions/3830853/c-program-quits-unexpectedly-how-do-i-debug-this-with-gdb)
```
(gdb) break exit
```
* [setting a gdb exit breakpoint not working?](https://stackoverflow.com/questions/1780765/setting-a-gdb-exit-breakpoint-not-working)

### syscall
```
(gdb) catch syscall mmap
```

* [为系统调用设置 catchpoint](https://wizardforcel.gitbooks.io/100-gdb-tips/catch-syscall.html)
* [Examining mmaped addresses using GDB](https://stackoverflow.com/questions/654393/examining-mmaped-addresses-using-gdb)

### Memory
* [Using GNU's GDB Debugger: Memory Layout And The Stack](http://dirac.org/linux/gdb/02a-Memory_Layout_And_The_Stack.php)
* [gdb 调试查看链表内存分配](http://blog.163.com/cailing_07@126/blog/static/339150872011930104839149/)

#### Heap
* [How to set up gdb to scan through heap memory?](https://unix.stackexchange.com/questions/193862/how-to-set-up-gdb-to-scan-through-heap-memory)


```
(gdb) call malloc_stats()
Arena 0:
system bytes     =     135168
in use bytes     =         96
Total (incl. mmap):
system bytes     =     135168
in use bytes     =         96
max mmap regions =          0
max mmap bytes   =          0

(gdb) call malloc_info(0, stdout)
<malloc version="1">
<heap nr="0">
<sizes>
<unsorted from="1228788" to="1229476" total="3917678" count="3221220448"/>
</sizes>
<total type="fast" count="0" size="0"/>
<total type="rest" count="3221220448" size="3917678"/>
<system type="current" size="135168"/>
<system type="max" size="135168"/>
<aspace type="total" size="135168"/>
<aspace type="mprotect" size="135168"/>
</heap>
<total type="fast" count="0" size="0"/>
<total type="rest" count="3221220448" size="3917678"/>
<system type="current" size="135168
/>
<system type="max" size="135168
/>
<aspace type="total" size="135168"/>
<aspace type="mprotect" size="135168"/>
</malloc>
```
* [Examining C/C++ Heap memory statistics in gdb](https://stackoverflow.com/questions/2564752/examining-c-c-heap-memory-statistics-in-gdb)
* [How to use malloc_stats in C program on Linux](https://stackoverflow.com/questions/13280714/how-to-use-malloc-stats-in-c-program-on-linux)
* https://sourceware.org/git/?p=glibc.git;a=blob;f=malloc/malloc.c;h=558e8bab0ab3808ec9f5b569ca62863ef4651b27;hb=HEAD#l6323

### env
* [Finding environment variables with gdb, to exploit a buffer overflow](https://security.stackexchange.com/questions/13194/finding-environment-variables-with-gdb-to-exploit-a-buffer-overflow)

### step

```
# step out
(gdb) fin
```

* [How to step-into, step-over and step-out with GDB?](https://unix.stackexchange.com/questions/297982/how-to-step-into-step-over-and-step-out-with-gdb)
* [Step out of current function with gdb](https://stackoverflow.com/questions/24712690/step-out-of-current-function-with-gdb)

# debug shared library
* [gdb: how to set breakpoints on future shared libraries with a --command flag](https://stackoverflow.com/questions/100444/gdb-how-to-set-breakpoints-on-future-shared-libraries-with-a-command-flag)

### STL pretty-print
* https://sourceware.org/gdb/onlinedocs/gdb/Pretty_002dPrinter-Commands.html
* [打印 STL 容器中的内容](https://wizardforcel.gitbooks.io/100-gdb-tips/print-STL-container.html)
* https://sourceware.org/gdb/wiki/STLSupport
* [How to enable pretty printing for STL in GDB](https://codeyarns.com/2014/07/17/how-to-enable-pretty-printing-for-stl-in-gdb/)
* [GDB printing STL data](https://stackoverflow.com/questions/26567110/gdb-printing-stl-data)
* [gdb 查看 stl 容器中的内容](http://blog.csdn.net/hitzhang/article/details/5355129)
* [gdb pretty printer for stl throw a “TypeError”](https://stackoverflow.com/questions/24352541/gdb-pretty-printer-for-stl-throw-a-typeerror)

### deadlock
* [一个 Linux 上分析死锁的简单方法](https://www.ibm.com/developerworks/cn/linux/l-cn-deadlock/index.html)
* [嵌入式 GDB 调试死锁示例](http://www.cnblogs.com/lidabo/p/5384025.html)

### multi-threaded

* [How do I enable reverse debugging on a multi-threaded program?](https://stackoverflow.com/questions/7517236/how-do-i-enable-reverse-debugging-on-a-multi-threaded-program)
* [reverse-step multithread error](https://stackoverflow.com/questions/6625486/reverse-step-multithread-error)

* [gdb: 5.5.2 Non-Stop Mode](http://www.sourceware.org/gdb/onlinedocs/gdb/Non_002dStop-Mode.html#Non_002dStop-Mode)
* [cuda-gdb hangs](https://devtalk.nvidia.com/default/topic/528726/cuda-gdb/cuda-gdb-hangs/)

* [View A Backtrace For All Threads With GDB](https://www.fayewilliams.com/2015/05/05/view-a-backtrace-for-all-threads-with-gdb/)

```
(gdb) thread apply all bt
```

### core

* [Using gdb to look at core files](https://web.eecs.umich.edu/~sugih/pointers/gdb_core.html)
* [Core dump file analysis](https://stackoverflow.com/questions/5115613/core-dump-file-analysis)

* http://en.linuxreviews.org/HOWTO_enable_core-dumps
* https://stackoverflow.com/questions/2919378/how-to-enable-core-dump-in-my-linux-c-program

```
ulimit -c unlimited
```

### log

```
(gdb) set logging on
Copying output to gdb.txt
(gdb) set logging off
Done logging to gdb.txt
```

* [How to dump the entire GDB session to a file, including commands I type and their output?](https://stackoverflow.com/questions/1707167/how-to-dump-the-entire-gdb-session-to-a-file-including-commands-i-type-and-thei)

* [How to include GDB commands in logging file?](https://stackoverflow.com/questions/37530271/how-to-include-gdb-commands-in-logging-file)

```

### Record command
(gdb) set trace-commands on
```

### print
* [Print multiple variables with one command in GDB](https://stackoverflow.com/questions/1882857/print-multiple-variables-with-one-command-in-gdb)

```
print {var1,var2,var3,var4}
```

### build id

* [当 debug 信息单独存放为一个文件时使用 gdb 调试CoreDump](https://blog.csdn.net/caspiansea/article/details/45767613)

## Missing separate debuginfos
* [GDB 在调试程序时候提示 Missing separate debuginfos, use: debuginfo-install glibc…](http://blog.ifeeline.com/1079.html)
* [gdb 调试时的问题 Missing separate debuginfos, use: debuginfo-install glibc-XXX](http://blog.csdn.net/testcs_dn/article/details/19565411)

## Dwarf Error: wrong version in compilation unit header (is 0, should be 2, 3, or 4)
* [Dwarf Error: wrong version in compilation unit header (is 4, should be 2)](https://stackoverflow.com/questions/11671009/dwarf-error-wrong-version-in-compilation-unit-header-is-4-should-be-2)

## This package should not be accessible on Python 3
* ["https://stackoverflow.com/questions/42214414/this-package-should-not-be-accessible-on-python-3-when-running-python3](https://stackoverflow.com/questions/42214414/this-package-should-not-be-accessible-on-python-3-when-running-python3)

```
unset PYTHONPATH
```

## reload warning: Source file is more recent than executable.

* [How to 'reload' source files in GDB](https://stackoverflow.com/questions/4118207/how-to-reload-source-files-in-gdb/6044513)
- http://www.sysprof.com
- https://wiki.gnome.org/Projects/GnomeShell/Debugging


## Trouble shooting

### gdbm fatal: read error

### `ImportError: No module named _sysconfigdata_nd`

```sh
gdb
Traceback (most recent call last):
  File "/usr/lib/python2.7/site.py", line 563, in <module>
    main()
  File "/usr/lib/python2.7/site.py", line 545, in main
    known_paths = addusersitepackages(known_paths)
  File "/usr/lib/python2.7/site.py", line 272, in addusersitepackages
    user_site = getusersitepackages()
  File "/usr/lib/python2.7/site.py", line 247, in getusersitepackages
    user_base = getuserbase() # this will also set USER_BASE
  File "/usr/lib/python2.7/site.py", line 237, in getuserbase
    USER_BASE = get_config_var('userbase')
  File "/usr/lib/python2.7/sysconfig.py", line 582, in get_config_var
    return get_config_vars().get(name)
  File "/usr/lib/python2.7/sysconfig.py", line 528, in get_config_vars
    _init_posix(_CONFIG_VARS)
  File "/usr/lib/python2.7/sysconfig.py", line 412, in _init_posix
    from _sysconfigdata import build_time_vars
  File "/usr/lib/python2.7/_sysconfigdata.py", line 6, in <module>
    from _sysconfigdata_nd import *
ImportError: No module named _sysconfigdata_nd
```

To solve this Debian/GDB issue.

    # ln -s /usr/lib/python2.7/plat-*/_sysconfigdata_nd.py /usr/lib/python2.7/

GDB want to use that path, but the python package installs in another path.

## gdb python

```
gdb python
run /usr/bin/flowblade
```

## Chromium V8

As of V8 v6.9, it’s possible to create breakpoints in GDB (and possibly other debuggers) to debug CSA / ASM / Torque builtins.

```
(gdb) tb i::Isolate::Init
Temporary breakpoint 1 at 0x7ffff706742b: i::Isolate::Init. (2 locations)
(gdb) r
Thread 1 "d8" hit Temporary breakpoint 1, 0x00007ffff7c55bc0 in Isolate::Init
(gdb) br Builtins_RegExpPrototypeExec
Breakpoint 2 at 0x7ffff7ac8784
(gdb) c
Thread 1 "d8" hit Breakpoint 2, 0x00007ffff7ac8784 in Builtins_RegExpPrototypeExec ()
```

Note that it works well to use a temporary breakpoint (shortcut `tb` in GDB) instead of a regular breakpoint (`br`) for this, since you only need it at process start.

Builtins are also visible in stack traces:

```
(gdb) bt
#0  0x00007ffff7ac8784 in Builtins_RegExpPrototypeExec ()
#1  0x00007ffff78f5066 in Builtins_ArgumentsAdaptorTrampoline ()
#2  0x000039751d2825b1 in ?? ()
#3  0x000037ef23a0fa59 in ?? ()
#4  0x0000000000000000 in ?? ()
```

Caveats:

- Only works with embedded builtins.
- Breakpoints can only be set at the start of the builtin.
- The initial breakpoint in `Isolate::Init` is needed prior to setting the builtin breakpoint, since GDB modifies the binary and we verify a hash of the builtins section in the binary at startup. Otherwise, V8 complains about a hash mismatch:

    ```
    # Fatal error in ../../src/isolate.cc, line 117
    # Check failed: d.Hash() == d.CreateHash() (11095509419988753467 vs. 3539781814546519144).
    ```

coredumpctl gdb and then bt full



-   对 Google Go 语言支持。

-   配合 SystemTap 实现 SDT（定位静态追溯）。

# TUI

  `gdb -tui`



root@1:/pica/core# scp admin@dev22:/srv/gdb-x8* .
^Croot@1:/pica/core# scp admin@10.10.50.22:/srv/gdb-x8* .
The authenticity of host '10.10.50.22 (10.10.50.22)' can't be established.
ECDSA key fingerprint is SHA256:lQeGCR9rGbkAhYrAGWypR5Uu6UoU5pmgD2PurhOcKlg.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added '10.10.50.22' (ECDSA) to the list of known hosts.
admin@10.10.50.22's password:
gdb-x86.tar.gz                                                                                                                             100% 3080KB  42.4MB/s   00:00
root@1:/pica/core# tar vfx gdb-x86.tar.gz
gdb-x86/
gdb-x86/gdb
gdb-x86/libpython2.7.so.1.0
root@1:/pica/core# find gdb-x86
gdb-x86
gdb-x86/gdb
gdb-x86/libpython2.7.so.1.0
root@1:/pica/core# find gdb-x86 -ls
    50130      4 drwxr-xr-x   2 1034     1035         4096 Aug 14  2018 gdb-x86
    50131   5768 -rw-r--r--   1 1034     1035      5906280 Mar  8  2017 gdb-x86/gdb
    50132   3004 -rw-r--r--   1 1034     1035      3073448 Mar  8  2017 gdb-x86/libpython2.7.so.1.0
root@1:/pica/core# chmod +x gdb-x86/gdb
root@1:/pica/core# ./gdb-x86/gdb
./gdb-x86/gdb: error while loading shared libraries: libreadline.so.6: cannot open shared object file: No such file or directory
root@1:/pica/core# find /lib* /usr/lib/ | grep libreadl
/lib/x86_64-linux-gnu/libreadline.so.7.0
/lib/x86_64-linux-gnu/libreadline.so.7
root@1:/pica/core# ln -sf /lib/x86_64-linux-gnu/libreadline.so.7.0 /lib/x86_64-linux-gnu/libreadline.so.6
root@1:/pica/core# ./gdb-x86/gdb
./gdb-x86/gdb: error while loading shared libraries: libpython2.7.so.1.0: cannot open shared object file: No such file or directory
root@1:/pica/core#
root@1:/pica/core# find /lib* /usr/lib/ | grep libpython2.7
root@1:/pica/core# apt install gdb
Reading package lists... Done
Building dependency tree... Done
E: Unable to locate package gdb
root@1:/pica/core# apt update
Get:1 http://security.debian.org buster/updates InRelease [65.4 kB]
Get:2 http://security.debian.org buster/updates/main amd64 Packages [292 kB]




7 kB 16%]                                                                                                                      22.6 kB/s 9min 32s^C
root@1:/pica/core# vi /etc/apt/sources.list
root@1:/pica/core# apt update
Get:1 http://mirrors.ustc.edu.cn/debian buster InRelease [121 kB]
Get:2 http://mirrors.ustc.edu.cn/debian buster-updates InRelease [51.9 kB]
Get:3 http://mirrors.ustc.edu.cn/debian buster/main amd64 Packages [7907 kB]
Get:4 http://mirrors.ustc.edu.cn/debian buster/main Translation-en [5969 kB]
Get:5 http://mirrors.ustc.edu.cn/debian buster/contrib amd64 Packages [50.1 kB]
Get:6 http://mirrors.ustc.edu.cn/debian buster/contrib Translation-en [44.2 kB]
Get:7 http://mirrors.ustc.edu.cn/debian buster/non-free amd64 Packages [87.7 kB]
Get:8 http://mirrors.ustc.edu.cn/debian buster/non-free Translation-en [88.8 kB]
Get:9 http://mirrors.ustc.edu.cn/debian buster-updates/main amd64 Packages [10.9 kB]
Get:10 http://mirrors.ustc.edu.cn/debian buster-updates/main Translation-en [7807 B]
Fetched 14.3 MB in 1min 21s (177 kB/s)
Reading package lists... Done
Building dependency tree... Done
2 packages can be upgraded. Run 'apt list --upgradable' to see them.
root@1:/pica/core# apt install gdb
Reading package lists... Done
Building dependency tree... Done
The following additional packages will be installed:
  libbabeltrace1 libc6-dbg libdw1 libglib2.0-0 libglib2.0-data libipt2 libpython3.7 shared-mime-info xdg-user-dirs
Suggested packages:
  gdb-doc gdbserver
The following NEW packages will be installed:
  gdb libbabeltrace1 libc6-dbg libdw1 libglib2.0-0 libglib2.0-data libipt2 libpython3.7 shared-mime-info xdg-user-dirs
0 upgraded, 10 newly installed, 0 to remove and 2 not upgraded.
Need to get 19.7 MB of archives.
After this operation, 51.6 MB of additional disk space will be used.
Do you want to continue? [Y/n]
0% [Connecting to mirrors.ustc.edu.cn]


















The following additional packages will be installed:
  libbabeltrace1 libc6-dbg libdw1 libglib2.0-0 libglib2.0-data libipt2 libpython3.7 shared-mime-info xdg-user-dirs
Suggested packages:
  gdb-doc gdbserver
The following NEW packages will be installed:
  gdb libbabeltrace1 libc6-dbg libdw1 libglib2.0-0 libglib2.0-data libipt2 libpython3.7 shared-mime-info xdg-user-dirs
0 upgraded, 10 newly installed, 0 to remove and 2 not upgraded.
Need to get 19.7 MB of archives.
After this operation, 51.6 MB of additional disk space will be used.
Do you want to continue? [Y/n]
Get:1 http://mirrors.ustc.edu.cn/debian buster/main amd64 libdw1 amd64 0.176-1.1 [235 kB]







Get:8 http://mirrors.ustc.edu.cn/debian buster/non-free Translation-en [88.8 kB]
Get:9 http://mirrors.ustc.edu.cn/debian buster-updates/main amd64 Packages [10.9 kB]
Get:10 http://mirrors.ustc.edu.cn/debian buster-updates/main Translation-en [7807 B]
Fetched 14.3 MB in 1min 21s (177 kB/s)
Reading package lists... Done
Building dependency tree... Done
2 packages can be upgraded. Run 'apt list --upgradable' to see them.
root@1:/pica/core# apt install gdb
Reading package lists... Done
Building dependency tree... Done
The following additional packages will be installed:
  libbabeltrace1 libc6-dbg libdw1 libglib2.0-0 libglib2.0-data libipt2 libpython3.7 shared-mime-info xdg-user-dirs
Suggested packages:
  gdb-doc gdbserver
The following NEW packages will be installed:
  gdb libbabeltrace1 libc6-dbg libdw1 libglib2.0-0 libglib2.0-data libipt2 libpython3.7 shared-mime-info xdg-user-dirs
0 upgraded, 10 newly installed, 0 to remove and 2 not upgraded.
Need to get 19.7 MB of archives.
After this operation, 51.6 MB of additional disk space will be used.
Do you want to continue? [Y/n]
Get:1 http://mirrors.ustc.edu.cn/debian buster/main amd64 libdw1 amd64 0.176-1.1 [235 kB]
Get:2 http://mirrors.ustc.edu.cn/debian buster/main amd64 libglib2.0-0 amd64 2.58.3-2+deb10u2 [1258 kB]
Get:3 http://mirrors.ustc.edu.cn/debian buster/main amd64 libbabeltrace1 amd64 1.5.6-2+deb10u1 [172 kB]
Get:4 http://mirrors.ustc.edu.cn/debian buster/main amd64 libipt2 amd64 2.0-2 [41.7 kB]
Get:5 http://mirrors.ustc.edu.cn/debian buster/main amd64 libpython3.7 amd64 3.7.3-2+deb10u3 [1498 kB]
Get:6 http://mirrors.ustc.edu.cn/debian buster/main amd64 gdb amd64 8.2.1-2+b3 [3133 kB]
Get:7 http://mirrors.ustc.edu.cn/debian buster/main amd64 libc6-dbg amd64 2.28-10 [11.5 MB]
Get:8 http://mirrors.ustc.edu.cn/debian buster/main amd64 libglib2.0-data all 2.58.3-2+deb10u2 [1110 kB]
Get:9 http://mirrors.ustc.edu.cn/debian buster/main amd64 shared-mime-info amd64 1.10-1 [766 kB]
Get:10 http://mirrors.ustc.edu.cn/debian buster/main amd64 xdg-user-dirs amd64 0.17-2 [53.8 kB]
Fetched 19.7 MB in 1min 48s (183 kB/s)
Selecting previously unselected package libdw1:amd64.
(Reading database ... 14470 files and directories currently installed.)
Preparing to unpack .../0-libdw1_0.176-1.1_amd64.deb ...
Unpacking libdw1:amd64 (0.176-1.1) ...
Selecting previously unselected package libglib2.0-0:amd64.
Preparing to unpack .../1-libglib2.0-0_2.58.3-2+deb10u2_amd64.deb ...





## Overview

GDB is using the very low level ptrace(2) system call to set breakpoints etc..

## Latest changes

### gdb (7.8-1) experimental; urgency=medium

>  WARNING: gdb now uses Python 3 by default.
>
>  Please update your Python scripts to work on both Python 2 and 3 as
>  soon as possible.
>
>  See /usr/share/doc/gdb*/README.python_switch for details.

## Get started

Commands

- `bt` (for backtrace) to get a stack trace from the time of the crash. In the backtrace, each function invocation is given a number.
- `frame NUMBER` to select a particular stack frame.
- `list` to see code around that function
- `info locals` to see the local variables.
- `print NAME_OF_VARIABLE` to see its value.
- `apropos search-topic` to find help
- `up/down N` to select frames N up/down


## XXX

```
root@57604cfc938d:/# gdb
GNU gdb (Debian 7.7.1+dfsg-5) 7.7.1
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word".

root@57604cfc938d:/# gdb /pica/bin/vrrp/xorp_vrrp
GNU gdb (Debian 7.7.1+dfsg-5) 7.7.1
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from /pica/bin/vrrp/xorp_vrrp...(no debugging symbols found)...done.
(gdb) r
Starting program: /pica/bin/vrrp/xorp_vrrp
warning: the debug information found in "/usr/lib/debug//lib/x86_64-linux-gnu/ld-2.19.so" does not match "/lib64/ld-linux-x86-64.so.2" (CRC mismatch).

warning: the debug information found in "/usr/lib/debug/lib/x86_64-linux-gnu//ld-2.19.so" does not match "/lib64/ld-linux-x86-64.so.2" (CRC mismatch).

/pica/bin/vrrp/xorp_vrrp: error while loading shared libraries: libxorptargets.so.0: cannot open shared object file: No such file or directory
[Inferior 1 (process 160) exited with code 0177]

root@XorPlus:/pica/core# gdb -c core.xorp_policy.pid_18451.uid_0.sig_11 /pica/bin/policy/xorp_policy
GNU gdb (GDB) 7.4.1-debian
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /pica/bin/policy/xorp_policy...done.
[New LWP 18451]

 warning: Could not load shared library symbols for linux-vdso.so.1.
 Do you need "set solib-search-path" or "set sysroot"?
[Thread debugging using libthread_db enabled]
 Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".


  warning: no loadable sections found in added symbol-file system-supplied DSO at 0x7ffefcff6000
  Core was generated by `xorp_policy'.
  Program terminated with signal 11, Segmentation fault.
  #0  0x00007f9d6c69ab45 in ?? () from /lib/x86_64-linux-gnu/libc.so.6
  (gdb) bt
  #0  0x00007f9d6c69ab45 in ?? () from /lib/x86_64-linux-gnu/libc.so.6
  #1  0x00007f9d6c69b641 in ?? () from /lib/x86_64-linux-gnu/libc.so.6
  #2  0x00007f9d6dc69db5 in ref_counter_pool::~ref_counter_pool() () from /pica/lib/libxorp.so.0
  #3  0x00007f9d6c659eaf in __cxa_finalize () from /lib/x86_64-linux-gnu/libc.so.6
  #4  0x00007f9d6dc58743 in ?? () from /pica/lib/libxorp.so.0
  #5  0x00007ffefcfeb370 in ?? ()
  #6  0x00007f9d6f6b91fa in ?? () from /lib64/ld-linux-x86-64.so.2
  Backtrace stopped: previous frame identical to this frame (corrupt stack?)
  (gdb)
```

- `list (l)`：列出源代码，默认 10 行，其后可跟函数名或行号；也可以用逗号分隔两个参数，以打印指定范围的源代码
- `break (b)`：设置断点，后接函数名或行号
- `run (r)`：执行程序，遇到断点会自动暂停
- `continue (c)`：程序继续执行，直到遇到下一个断点或到达程序结尾
- `next (n)`：执行一整行代码，然后停留在下一行，也称“单步跳过”
- `step
- (s)`：功能基本和`next`一样，但是遇到函数调用时，`step`会跳进函数体内，然后停留在函数的第一条语句处，也称“单步跳入”
- `finish (fin)`：继续执行目前所在的函数，直到遇到函数体内的下一个断点或直到函数结束，也称“单步跳出”
- `print (p)`：打印变量的值
- `kill`：终止调试器，但并不关闭，所有设置都将保存，待修改好源文件重新编译后使用`run`再次开始调试，`GDB`会重新加载可执行文件
- `file`：加载需要调试的目标程序
- `set args`：后跟当前调试程序所需的参数表列
- `show args`：显示目前为调试程序所设置的参数表列

- 对于`next`和`step`命令，如果执行一次后还想继续执行，只需直接回车即可，`GDB`会自动执行上一条命令

- `info all-registers (info all)`：显示所有处理器寄存器的内容，包括浮点和向量寄存器
- `info register (info reg)`：显示 CPU 寄存器的内容
- `info source`：打印当前源文件的信息
- `info sources`：打印当前调试程序包含的所有源文件信息
- `info address`：后跟变量或函数名，可以显示目标变量或函数的地址信息
- `info breakpoints (info b)`：显示所有设置的断点
- `info frame (info f)`：显示当前堆栈帧的相关信息，包括返回值、寄存器值
- `info locals (info lo)`：列出当前函数的局部变量

- `tbreak (tb)`：设置临时断点，`GDB`会在到达这个语句后自动将其删除
- `delete (d)`：删除某个断点或某个范围内的断点，后接断点的编号，或以竖线分隔的两个断点编号；不加参数则删除所有断点
- `disable (dis)`：临时禁用某个断点或某个范围内的断点，使用格式同`delete`
- `enable (en)`：恢复被禁用的某个断点或某个范围内的断点，使用格式同`delete`
- `ignore 1 5 (ig 1 5)`：连续忽略编号为 1 的断点 5 次

### 条件中断

`break 断点位置 if 中断条件`：其中位置可以是函数名或行号，条件可以是 C 语言任何形式的表达式
如：`break 20 if i == j - 1`

`condition 断点编号 中断条件`：可以在已有断点的位置再新增一个断点，或修改其原来的中断条件
如：`condition 20 \*p1 \!= \*p2`
如想删除中断条件，直接使用`condition 断点编号`即可

- `set logging on (set lo on)`：开启日志记录
- `show logging (show lo)`：显示日志信息
- `set listsize 5 (set li 5)`：设置`list`默认输出的行数
- `show listsize (show li)`：显示`list`默认输出的行数

### 显示调用轨迹

`backtrace (bt)`，同义词还有`where`、`info stack (info s)`
使用上述命令可以得到函数的调用次序，这在调试递归调用时特别有效

`frame (f)`：显示堆栈帧信息，后面可跟堆栈帧的编号，不跟参数则显示当前堆栈帧的信息

`up`，跳到上一个堆栈；`down`，跳到下一个堆栈

### 显示数据的详细用法

`pint 输出格式 变量名称或表达式`：表达式的执行结果会影响到程序中相应变量的值，示例如下

`p a`：输出变量 a 的取值
`p a=7`：给变量 a 赋值为 7，相当于命令`set variable a=7 (set var a=7)`
`p a\*a`：输出变量 a 自乘的结果
`p
2\*sum($3)`：调用 sum 函数，传入参数`$3`（此即调试过程中第三次打印的数值），然后将 sum 函数执行的结果乘以2返回
`p main::a`：跨堆栈帧存取变量信息

可以在`GDB`调试过程中定义新的变量，使用`p $a = \*p1`或`set $a = \*p1`的格式

格式化输出选项

1.  `/d`：十进制输出，也是输出整数时的默认格式
2.  `/u`：十进制无符号整数
3.  `/c`：字符形式输出
4.  `/o`：八进制输出
5.  `/x`：十六进制输出
6.  `/t`：二进制输出

其他格式化选项

1.  `/a`：以十六进制形式输出地址
2.  `/f`；将目标值以浮点数的形式显示

### 显示内存区域

基本格式：`x / 显示个数 格式修饰符 单位内存大小 address`

`显示个数`：指定要显示多少个内存单位，默认为 1
`格式修饰符`：除了可以使用`print`的格式修饰符以外，还可以额外使用以下两个
\# `/s`：将目标地址的数据以字符串的形式显示出来

1.  `/i`：以汇编语言的形式显示机器指令

`单位内存大小`：指定每个内存单位空间的大小，有以下四种类别，默认为`w`
\# `b`：一个字节

1.  `h`：两个字节（半个字）
2.  `w`：四个字节（一个字）
3.  `g`：八个字节（双字）

`address`：目标地址

使用示例如下：

`x/s \&a`：以字符串的形式显示变量 a 所处地址开始的一个字的内容（因为默认显示 1 个单位，每个单位为一个字）
`x/15xb \&a`：以十六进制形式显示变量 a 所处地址开始的 15 个字节的内容
`x/10i \&a`：将变量 a 所处地址开始的 10 条机器语言翻译成汇编代码

### 观测点的设置

`watch (wa)`：当指定表达式的值发生改变时，程序中止执行
`rwatch (rw)`：当程序读取和目标表达式相关的任何对象时，程序中止执行
`awatch (aw)`：当程序读取或修改和目标表达式相关的任何对象时，程序中止执行

-----

# Running gdb

Now run your program as follows, replacing "[--args]" with any arguments
you want to run the program with:
`--args`：此选项后必须立即跟要调试的目标程序名，然后接该目标程序需要的参数表列，这样这些参数就不会被当成`GDB`自身的参数

    $ gdb hello
    ... gdb loads ...
    (gdb) set pagination 0
    (gdb) run [--args]
    ... hello loads...

Then try to reproduce your crash. If you’re lucky, a crash will occur
and you’ll be dropped back to the gdb prompt.
If you are not so lucky to get a crash but instead get a freeze, you can
still get gdb prompt by pressing CTRL-C in the terminal running gdb.
At that point, you can run:

    (gdb) bt

You’ll then get a lot of output, which you can then copy & paste to
a bug followup e-mail or other bug reporting tool.

When you’re done with gdb, you can just run:

    (gdb) quit

If the problem seems to be in a major library such as libc6, xlibs, or
libgtk2.0-0, you’ll want to install the appropriate -dbg package (e.g.
libc6-dbg in the case of libc6) and then run the problematic program
again under gdb.

Often, you will see a backtrace where one or more of the top lines is in
malloc() or g_malloc(). When this happens, chances are your backtrace
isn’t very useful. The easiest way to find some useful information is
to set the environment variable `MALLOC_CHECK_` to a value of 2. You can do this while running gdb by doing this:

    $ MALLOC_CHECK_=2 gdb hello

# Advanced gdb commands
If the program you’re backtracing is multi-threaded, you might want to
get a backtrace for all threads:

    (gdb) thread apply all bt
Another thing which is quite helpful to report is what variables were
set locally at each point in the stack:

    (gdb) bt full
You might want to report the output of the combination of the preceding
options:

    (gdb) thread apply all bt full
And if this is too much irrelevant output, you might want to keep only
a few calls, such as the top 10:

    (gdb) thread apply all bt full 10
If you have a large backtrace, you can log gdb output to a file (the
default is gdb.txt):

    (gdb) set logging on
To check you have debugging symbols in your binary:

    $ gdb
     (gdb) symbol-file /usr/bin/hello

    # you should see something like this:
     Reading symbols from /usr/bin/hello ... done
     Using host libthread_db library
    /lib/tls/i686/cmov/libthread_db.so.1".
     (gdb)

    # NB you should _not_ see
     Reading symbols from /usr/bin/hello...(no debugging symbols
    ound)...done

# Debugging X Errors

If a GTK program has received an X error; i.e. you see a message of the
form:

then you can try running the program with `--sync`, and break on the
`gdk_x_error` function in order to obtain a backtrace, thus:

    (gdb) break gdk_x_error
    (gdb) run --sync

# Debugging

Start the program under control of gdb via a terminal (some programs run
as root, so one would use sudo gdb instead of just gdb below):

    gdb <program> 2>&1 | tee ~/gdb-<program>.txt
    (gdb) handle SIG33 pass nostop noprint
    (gdb) set pagination 0
    (gdb) run <arguments, if any>
The program will start. Perform any actions necessary to reproduce the
crash. If the program hangs but doesn't crash you can press ctrl+c in
gdb while the program is frozen and then continue with the next step.

Retrieve a backtrace:

    (gdb) backtrace full
    (gdb) info registers
    (gdb) x/16i $pc
    (gdb) thread apply all backtrace
    (gdb) quit

Attach the complete output from GDB, contained in gdb-<program>.txt, in
your bug report. You will find the file in your $HOME directory


# Already running programs

Find the process ID of <program>:

    pidof <program>
Start gdb (some programs run as root, so one would use sudo gdb instead
of just gdb below):

    gdb 2>&1 | tee gdb-<program>.txt
    (gdb) handle SIG33 pass nostop noprint
    (gdb) set pagination 0
    (gdb) attach <PID>
Continue the <program>:

    (gdb) continue
The program will continue running. Perform any actions necessary to
reproduce the crash. If the program hangs but doesn't crash you can
press ctrl+c in gdb while the program is frozen and then continue with
the next step.

Retrieve a backtrace:

    (gdb) backtrace full
    (gdb) info registers
    (gdb) x/16i $pc
    (gdb) thread apply all backtrace
    (gdb) quit
Attach the complete output from GDB, contained in gdb-<program>.txt, in
your bug report.

Note that you can also set logging to a file like this:

    (gdb) set logging file gdb-<program>.txt
    (gdb) set logging on


# Core file
Load the core file into the debugger

    gdb -c <corefile> 2>&1 | tee gdb-<program>.txt
Retrieve a backtrace of the crash:

    (gdb) backtrace full
    (gdb) info registers
    (gdb) x/16i $pc
    (gdb) thread apply all backtrace
    (gdb) quit

# backtrace.sh
```

#---------------------------------------------------------------------
usage() {
    cat<<EOF
Usage: ${0} program_name [program_args]

Trace a given program using gdb.

EOF
}

log() {
    echo "${*}" 1>&2
}

die() {
    usage
    log 'error:' ${*}'.'
    exit 1
}
#---------------------------------------------------------------------
test "x${*}" = "x" && die 'no process given'

LOG="/tmp/gdb-`basename ${1}`.txt"
log "outputting trace to '${LOG}'"

exec gdb -batch-silent \
    -ex 'set logging overwrite on' \
    -ex "set logging file ${LOG}" \
    -ex 'set logging on' \
    -ex 'handle SIG33 pass nostop noprint' \
    -ex 'set pagination 0' \
    -ex 'run' \
    -ex 'backtrace full' \
    -ex 'info registers' \
    -ex 'x/16i $pc' \
    -ex 'thread apply all backtrace' \
    -ex 'quit' \
    --args ${*} \
    < /dev/null>>>}
```

## Debug binaries with arguments

```c
#include<stdio.h>

int main(int argc,char *argv[])
{
    if(1 >= argc)
    {
        printf("usage:hello name\n");
        return 0;
    }
    printf("Hello World %s!\n",argv[1]);
    return 0 ;
}
```

    gcc -g -o hello hello.c

You need to run with args, or set args for run.

## Debug core dumps

The binary with debugging symbols included should be identical to the one that generated the core dump file.

    gdb /path/to/binary-with-symbols /path/to/core/dump/file

Or

    gdb -c /path/to/core/dump/file /path/to/binary-with-symbols

### ulimit

    $ ulimit -c
    0

    ulimit -c unlimied  #unlimited
    ulimit -c 10        # maximum size in blocks, each block is 512 B

## Debug running binaries

Find the pid

    ps -ef | grep process

Or

    pidof process

    (gdb) attach PID


## Trouble shooting

### Could not attach to process. If your uid matches the uid of the target process, check the setting of /proc/sys/kernel/yama/ptrace_scope, or try again as the root user.

```
echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
```

* https://askubuntu.com/questions/41629/after-upgrade-gdb-wont-attach-to-process

### ptrace: Operation not permitted.

    Could not attach to process.  If your uid matches the uid of the target
    process, check the setting of /proc/sys/kernel/yama/ptrace_scope, or try
    again as the root user.  For more details, see /etc/sysctl.d/10-ptrace.conf
    ptrace: Operation not permitted.


Change

    /etc/sysctl.d/10-ptrace.conf

    kernel.yama.ptrace_scope = 1

to

    kernel.yama.ptrace_scope = 0

## load pid

    gdb PROG PID

    gdb PROG --pid PID

## For running binaries without debug info

You need to build one binary using same code, then load the symbols using `file FILE` from that.

    (gdb) file FILE
    (gdb) attach XXXXX

