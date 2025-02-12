---
title: var-tracking
date: 2022-03-03
---

According to official documentation from GCC:

-fvar-tracking-assignments: Annotate assignments to user variables early in the compilation and attempt to carry the annotations over throughout the compilation all the way to the end, in an attempt to improve debug information while optimizing. Use of -gdwarf-4 is recommended along with it. It can be enabled even if var-tracking is disabled, in which case annotations are created and maintained, but discarded at the end. By default, this flag is enabled together with -fvar-tracking, except when selective scheduling is enabled.


From the internet as well: On note: variable tracking size limit exceeded with -fvar-tracking-assignments, retrying without: This is just a note from the compiler that the debug info for the particular function will have lower quality, because your code of function is too large/complex so variable tracking reached limit of hash table slots.



## Variable Tracking at Assignments

Variable Tracking at Assignments (VTA) is a new infrastructure included in GCC used to improve variable tracking during optimizations.
This allows GCC to produce more precise, meaningful, and useful debugging information for GDB, SystemTap, and other debugging tools.

When GCC compiles code with optimizations enabled, variables are renamed, moved around, or even removed altogether. As such, optimized compiling can cause a debugger to report that some variables have been `optimized out`.

With VTA enabled, optimized code is internally annotated to ensure that optimization passes to transparently keep track of each variable's value, regardless of whether the variable is moved or removed. The effect of this is more parameter and variable values available, even for the optimized (gcc -O2 -g built) code. It also displays the `optimized out` message less.

VTA's benefits are more pronounced when debugging applications with inlined functions. Without VTA, optimization could completely remove some arguments of an inlined function, preventing the debugger from inspecting its value. With VTA, optimization will still happen, and appropriate debugging information will be generated for any missing arguments.

VTA is enabled by default when compiling code with optimizations and debugging information enabled (that is, gcc -O -g or, more commonly, gcc -O2 -g).

To disable VTA during such builds, add the `-fno-var-tracking-assignments`. In addition, the VTA infrastructure includes the new gcc option `-fcompare-debug`.
This option tests code compiled by GCC with debug information and without debug information: the test passes if the two binaries are identical. This test ensures that executable code is not affected by any debugging options, which further ensures that there are no hidden bugs in the debug code. Note that -fcompare-debug adds significant cost in compilation time.

- https://gcc.gnu.org/wiki/Var_Tracking_Assignments

- https://www.rowleydownload.co.uk/arm/documentation/gnu/gcc/Optimize-Options.html

## variable tracking size limit

```c
lcmgr_base.cc: In member function ‘void XrlLcmgrTargetBase::add_handlers()’:
lcmgr_base.cc:22221:1: note: variable tracking size limit exceeded with -fvar-tracking-assignments, retrying without
 XrlLcmgrTargetBase::add_handlers()
 ^~~~~~~~~~~~~~~~~~
sif_base.cc: In member function ‘void XrlSifTargetBase::add_handlers()’:
sif_base.cc:59472:1: note: variable tracking size limit exceeded with -fvar-tracking-assignments, retrying without
 XrlSifTargetBase::add_handlers()
 ^~~~~~~~~~~~~~~~
libtool: compile:  x86_64-linux-gnu-g++ -DHAVE_CONFIG_H -I. -I../.. -I../../../xorp/ -I../../include -O2 -g -pipe -O2 -fno-omit-frame-pointer -std=c++11 -Wno-deprecated -MT libtargets_la-lcmgr_base.lo -MD -MP -MF .deps/libtargets_la-lcmgr_base.Tpo -c lcmgr_base.cc -o libtargets_la-lcmgr_base.o >/dev/null 2>&1
sif_base.cc: In member function ‘void XrlSifTargetBase::remove_handlers()’:
sif_base.cc:67018:1: note: variable tracking size limit exceeded with -fvar-tracking-assignments, retrying without
 XrlSifTargetBase::remove_handlers()
 ^~~~~~~~~~~~~~~~
```

