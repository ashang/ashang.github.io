```sh
$ proxychains4 ruby-install --install-dir ~/.rbenv/versions/3.4.1 ruby-3.4.1
[proxychains] config file found: /Users/aaron/.proxychains/proxychains.conf
[proxychains] preloading /opt/homebrew/Cellar/proxychains-ng/4.17/lib/libproxychains4.dylib
>>> Installing ruby 3.4.1 into /Users/aaron/.rbenv/versions/3.4.1 ...
>>> Installing dependencies for ruby 3.4.1 ...
Warning: xz 5.6.3 is already installed and up-to-date.
To reinstall 5.6.3, run:
  brew reinstall xz
Warning: automake 1.17 is already installed and up-to-date.
To reinstall 1.17, run:
  brew reinstall automake
Warning: bison 3.8.2 is already installed and up-to-date.
To reinstall 3.8.2, run:
  brew reinstall bison
Warning: readline 8.2.13 is already installed and up-to-date.
To reinstall 8.2.13, run:
  brew reinstall readline
Warning: libyaml 0.2.5 is already installed and up-to-date.
To reinstall 0.2.5, run:
  brew reinstall libyaml
Warning: gdbm 1.24 is already installed and up-to-date.
To reinstall 1.24, run:
  brew reinstall gdbm
Warning: libffi 3.4.6 is already installed and up-to-date.
To reinstall 3.4.6, run:
  brew reinstall libffi
Warning: openssl@3 3.4.0 is already installed and up-to-date.
To reinstall 3.4.0, run:
  brew reinstall openssl@3
>>> Downloading https://cache.ruby-lang.org/pub/ruby/3.4/ruby-3.4.1.tar.xz into /Users/aaron/src ...
>>> Verifying ruby-3.4.1.tar.xz ...
>>> Extracting ruby-3.4.1.tar.xz to /Users/aaron/src/ruby-3.4.1 ...
>>> Configuring ruby 3.4.1 ...
checking for ruby... /Users/aaron/.rubies/ruby-3.4.1/bin/ruby
tool/config.guess already exists
tool/config.sub already exists
checking build system type... aarch64-apple-darwin24.2.0
checking host system type... aarch64-apple-darwin24.2.0
checking target system type... aarch64-apple-darwin24.2.0
checking for cl.exe... no
checking for clang... clang
checking for ld... ld
checking for ar... ar
checking for clang++... clang++
checking for nm... nm
checking for objcopy... no
checking for objdump... objdump
checking for ranlib... ranlib
checking for strip... strip
checking for gcc... (cached) clang
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables...
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether the compiler supports GNU C... yes
checking whether clang accepts -g... yes
checking for clang option to enable C11 features... none needed
checking whether the compiler supports GNU C++... yes
checking whether clang++ accepts -g... yes
checking for clang++ option to enable C++11 features... -std=gnu++11
checking how to run the C preprocessor... clang -E
checking for gas... no
checking for as... as
checking for gobjcopy... (cached) :
checking for stdio.h... yes
checking for stdlib.h... yes
checking for string.h... yes
checking for inttypes.h... yes
checking for stdint.h... yes
checking for strings.h... yes
checking for sys/stat.h... yes
checking for sys/types.h... yes
checking for unistd.h... yes
checking for wchar.h... yes
checking for minix/config.h... no
checking for vfork.h... no
checking whether it is safe to define __EXTENSIONS__... yes
checking whether _XOPEN_SOURCE should be defined... no
checking if minimum required OS X version is supported... yes
checking whether the linker is GNU ld... no
checking whether clang -E accepts -o... yes
checking for clang linker warning... no
checking for real target cpu... arm64
checking arch option... -arch arm64
checking for ar flags... rcu
checking whether ln -s works... yes
checking whether make sets $(MAKE)... yes
checking for a BSD-compatible install... /usr/bin/install -c
checking for a race-free mkdir -p... mkdir -p
checking for dtrace... dtrace
checking for dot... no
checking for doxygen... no
checking for pkg-config... pkg-config
checking whether it is Android... no
checking for cd using physical directory... cd -P
checking whether CFLAGS is valid... yes
checking whether LDFLAGS is valid... yes
checking whether ELF binaries are produced... no
checking whether -Wl,-rpath,. is accepted as LDFLAGS... yes
checking whether -fdeclspec is accepted as LDFLAGS... yes
checking whether -fdeclspec is accepted as CXXFLAGS... yes
checking whether -Wextra-tokens is accepted as CFLAGS... yes
checking whether -Wdeprecated-declarations is accepted as CFLAGS... yes
checking whether -Wdivision-by-zero is accepted as CFLAGS... yes
checking whether -Wdiv-by-zero is accepted as CFLAGS... yes
checking whether -Wduplicated-cond is accepted as CFLAGS... no
checking whether -Wimplicit-function-declaration is accepted as CFLAGS... yes
checking whether -Wimplicit-int is accepted as CFLAGS... yes
checking whether -Wpointer-arith is accepted as CFLAGS... yes
checking whether -Wshorten-64-to-32 is accepted as CFLAGS... yes
checking whether -Wwrite-strings is accepted as CFLAGS... yes
checking whether -Wold-style-definition is accepted as CFLAGS... yes
checking whether -Wimplicit-fallthrough=0 is accepted as CFLAGS... no
checking whether -Wmissing-noreturn is accepted as CFLAGS... yes
checking whether -Wno-cast-function-type is accepted as CFLAGS... yes
checking whether -Wno-constant-logical-operand is accepted as CFLAGS... yes
checking whether -Wno-long-long is accepted as CFLAGS... yes
checking whether -Wno-missing-field-initializers is accepted as CFLAGS... yes
checking whether -Wno-overlength-strings is accepted as CFLAGS... yes
checking whether -Wno-packed-bitfield-compat is accepted as CFLAGS... no
checking whether -Wno-parentheses-equality is accepted as CFLAGS... yes
checking whether -Wno-self-assign is accepted as CFLAGS... yes
checking whether -Wno-tautological-compare is accepted as CFLAGS... yes
checking whether -Wno-unused-parameter is accepted as CFLAGS... yes
checking whether -Wno-unused-value is accepted as CFLAGS... yes
checking whether -Wsuggest-attribute=format is accepted as CFLAGS... no
checking whether -Wsuggest-attribute=noreturn is accepted as CFLAGS... no
checking whether -Wunused-variable is accepted as CFLAGS... yes
checking whether -diag-disable=175,188,1684,2259,2312 is accepted as CFLAGS... no
checking whether -Wno-maybe-uninitialized is accepted as CFLAGS... no
checking whether -Wmisleading-indentation is accepted as CFLAGS... yes
checking whether -Wundef is accepted as CFLAGS... yes
checking whether -Wall -Wextra is accepted as CFLAGS... yes
checking whether -Qunused-arguments is accepted as CFLAGS... yes
checking whether -O3 -D_FORTIFY_SOURCE=2 is accepted as CFLAGS... yes
checking whether -fstack-protector-strong is accepted as CFLAGS... yes
checking whether -fstack-protector-strong is accepted as LDFLAGS... yes
checking for -fstack-protector... -fstack-protector-strong
checking for a broken LLVM libunwind that cannot unwind code with RA signing... yes
checking whether -Wl,--compress-debug-sections=zlib is accepted as LDFLAGS... no
checking whether -fno-strict-overflow is accepted as CFLAGS... yes
checking whether -ggdb3 is accepted as LDFLAGS... yes
checking whether -fvisibility=hidden is accepted as CFLAGS... yes
checking whether -fno-fast-math is accepted as CFLAGS... yes
checking whether -fexcess-precision=standard is accepted as CFLAGS... yes
checking whether -fp-model precise is accepted as CFLAGS... no
checking whether compiler has statement and declarations in expressions... yes
checking for pthread.h... yes
checking for pthread_create in -lthr... no
checking for pthread_create in -lpthread... yes
checking for pthread_np.h... no
checking thread model... pthread
checking whether syscall(2) is deprecated... yes
checking for broken crypt with 8bit chars... yes
checking for codesign... codesign
checking for dsymutil... dsymutil
checking for crt_externs.h... yes
checking whether CXXFLAGS is valid... yes
checking for crypt in -lcrypt... (cached) no
checking for dlopen in -ldl... yes
checking for shutdown in -lsocket... no
checking for dirent.h that defines DIR... yes
checking for library containing opendir... none required
checking for _Bool... yes
checking for stdbool.h that conforms to C99... yes
checking for sys/wait.h that is POSIX.1 compatible... yes
checking for afunix.h... no
checking for atomic.h... no
checking for copyfile.h... yes
checking for direct.h... no
checking for grp.h... yes
checking for fcntl.h... yes
checking for float.h... yes
checking for ieeefp.h... no
checking for intrinsics.h... no
checking for langinfo.h... yes
checking for limits.h... yes
checking for locale.h... yes
checking for malloc.h... no
checking for malloc/malloc.h... yes
checking for malloc_np.h... no
checking for net/socket.h... no
checking for process.h... no
checking for pwd.h... yes
checking for sanitizer/asan_interface.h... yes
checking for sanitizer/msan_interface.h... yes
checking for setjmpex.h... no
checking for stdalign.h... yes
checking for stdio.h... (cached) yes
checking for sys/attr.h... yes
checking for sys/eventfd.h... no
checking for sys/fcntl.h... yes
checking for sys/file.h... yes
checking for sys/id.h... no
checking for sys/ioctl.h... yes
checking for sys/mkdev.h... no
checking for sys/param.h... yes
checking for sys/prctl.h... no
checking for sys/random.h... yes
checking for sys/resource.h... yes
checking for sys/select.h... yes
checking for sys/sendfile.h... no
checking for sys/socket.h... yes
checking for sys/syscall.h... (cached) no
checking for sys/sysmacros.h... no
checking for sys/time.h... yes
checking for sys/times.h... yes
checking for sys/uio.h... yes
checking for sys/utime.h... no
checking for syscall.h... (cached) no
checking for time.h... yes
checking for ucontext.h... yes
checking for utime.h... yes
checking for sys/epoll.h... no
checking for sys/event.h... yes
checking for stdckdint.h... no
checking for stdatomic.h... yes
checking for gmp.h... no
checking for special C compiler options needed for large files... no
checking for _FILE_OFFSET_BITS value needed for large files... no
checking whether byte ordering is bigendian... no
checking for an ANSI C-conforming const... yes
checking whether char is unsigned... no
checking for inline... inline
checking for working volatile... yes
checking for typeof syntax and keyword spelling... typeof
checking for C/C++ restrict keyword... __restrict__
checking for long long... yes
checking for off_t... yes
checking char bit... 8
checking size of int... 4
checking size of short... 2
checking size of long... 8
checking size of long long... 8
checking size of __int64... 0
checking size of __int128... 16
checking size of off_t... 8
checking size of void*... 8
checking size of float... 4
checking size of double... 8
checking size of time_t... 8
checking size of clock_t... 8
checking word size... 8
checking packed struct attribute... x __attribute__((packed))
checking whether -Wno-address-of-packed-member is accepted as CFLAGS... yes
checking for printf prefix for long long... ll
checking for pid_t... yes
checking for convertible type of pid_t... INT
checking for uid_t... yes
checking for convertible type of uid_t... UINT
checking for gid_t... yes
checking for convertible type of gid_t... UINT
checking for time_t... yes
checking for convertible type of time_t... LONG
checking for dev_t... yes
checking for convertible type of dev_t... INT
checking for mode_t... yes
checking for convertible type of mode_t... USHORT
checking for rlim_t... yes
checking for convertible type of rlim_t... ULL
checking for off_t... (cached) yes
checking for convertible type of off_t... LL
checking for clockid_t... yes
checking for convertible type of clockid_t... UINT
checking for variable length macro... yes
checking if _Alignof() works... yes
checking for CONSTFUNC function attribute... __attribute__ ((__const__)) x
checking for PUREFUNC function attribute... __attribute__ ((__pure__)) x
checking for NORETURN function attribute... __attribute__ ((__noreturn__)) x
checking for DEPRECATED function attribute... __attribute__ ((__deprecated__)) x
checking for DEPRECATED_BY function attribute... __attribute__ ((__deprecated__("by "#n))) x
checking for NOINLINE function attribute... __attribute__ ((__noinline__)) x
checking for ALWAYS_INLINE function attribute... __attribute__ ((__always_inline__)) x
checking for NO_SANITIZE function attribute... __attribute__ ((__no_sanitize__(san))) x
checking for NO_SANITIZE_ADDRESS function attribute... __attribute__ ((__no_sanitize_address__)) x
checking for NO_ADDRESS_SAFETY_ANALYSIS function attribute... __attribute__ ((__no_address_safety_analysis__)) x
checking for WARN_UNUSED_RESULT function attribute... __attribute__ ((__warn_unused_result__)) x
checking for MAYBE_UNUSED function attribute... __attribute__ ((__unused__)) x
checking for ERRORFUNC function attribute... __attribute__ ((__error__ mesg)) x
checking for WARNINGFUNC function attribute... __attribute__ ((__warning__ mesg)) x
checking for WEAK function attribute... __attribute__ ((__weak__)) x
checking for __attribute__((__deprecated__(msg))) in C++... yes
checking for std::nullptr_t... yes
checking for FUNC_STDCALL function attribute... x
checking for FUNC_CDECL function attribute... __attribute__ ((__cdecl__)) x
checking for FUNC_FASTCALL function attribute... x
checking for FUNC_UNOPTIMIZED function attribute... x
checking for FUNC_MINIMIZED function attribute... x
checking for function alias... no
checking for __atomic builtins... yes
checking for __sync builtins... yes
checking for __builtin_unreachable... yes
checking for __assume... no
checking for exported function attribute... __attribute__ ((__visibility__("default")))
checking for RUBY_FUNC_NONNULL function attribute... __attribute__ ((__nonnull__(n))) x
checking for function name string predefined identifier... __func__
checking if enum over int is allowed... yes
checking for clang options needed to detect all undeclared functions... none needed
checking whether sys_nerr is declared... yes
checking whether getenv is declared... yes
checking for size_t... yes
checking size of size_t... 8
checking size of ptrdiff_t... 8
checking size of dev_t... 4
checking for printf prefix for size_t... z
checking for printf prefix for ptrdiff_t... t
checking for struct stat.st_blksize... yes
checking for struct stat.st_blocks... yes
checking for struct stat.st_rdev... yes
checking size of struct stat.st_size... SIZEOF_OFF_T
checking size of struct stat.st_blocks... SIZEOF_OFF_T
checking size of struct stat.st_ino... SIZEOF_LONG
checking size of struct stat.st_dev... SIZEOF_DEV_T
checking size of struct stat.st_rdev... SIZEOF_DEV_T
checking for struct stat.st_atim... no
checking for struct stat.st_atimespec... yes
checking for struct stat.st_atimensec... no
checking for struct stat.st_mtim... no
checking for struct stat.st_mtimespec... yes
checking for struct stat.st_mtimensec... no
checking for struct stat.st_ctim... no
checking for struct stat.st_ctimespec... yes
checking for struct stat.st_ctimensec... no
checking for struct stat.st_birthtimespec... yes
checking for struct timeval... yes
checking size of struct timeval.tv_sec... SIZEOF_TIME_T
checking for struct timespec... yes
checking for struct timezone... yes
checking for fd_mask... yes
checking for int8_t... yes
checking size of int8_t... 1
checking for uint8_t... yes
checking size of uint8_t... 1
checking for int16_t... yes
checking size of int16_t... 2
checking for uint16_t... yes
checking size of uint16_t... 2
checking for int32_t... yes
checking size of int32_t... 4
checking for uint32_t... yes
checking size of uint32_t... 4
checking for int64_t... yes
checking size of int64_t... 8
checking for uint64_t... yes
checking size of uint64_t... 8
checking for int128_t... __int128
checking for uint128_t... unsigned __int128
checking for intptr_t... yes
checking size of intptr_t... 8
checking for uintptr_t... yes
checking size of uintptr_t... 8
checking for printf prefix for intptr_t... l
checking for ssize_t... yes
checking size of ssize_t... 8
checking for printf prefix for int64_t... ll
checking for stack end address... no
checking for grep that handles long lines and -e... /usr/bin/grep
checking for egrep... /usr/bin/grep -E
checking for uid_t in sys/types.h... (cached) yes
checking type of array argument to getgroups... (cached) gid_t
checking for working alloca.h... yes
checking for alloca... yes
checking for dynamic size alloca... ok
checking for working memcmp... yes
checking for dup... yes
checking for dup2... yes
checking for acosh... yes
checking for cbrt... yes
checking for crypt... yes
checking for erf... yes
checking for explicit_bzero... no
checking for ffs... yes
checking for flock... yes
checking for hypot... yes
checking for lgamma_r... yes
checking for memmove... yes
checking for nan... yes
checking for nextafter... yes
checking for setproctitle... no
checking for strchr... yes
checking for strerror... yes
checking for strlcat... yes
checking for strlcpy... yes
checking for strstr... yes
checking for tgamma... yes
checking for sys/pstat.h... no
checking for pid_t... (cached) yes
checking for fork... yes
checking for vfork... (cached) no
checking for working fork... yes
checking for __syscall... (cached) no
checking for _longjmp... yes
checking for arc4random_buf... yes
checking for atan2l... yes
checking for atan2f... yes
checking whether atomic_signal_fence is declared... yes
checking for chmod... yes
checking for chown... yes
checking for chroot... yes
checking for chsize... no
checking for clock_gettime... yes
checking for copy_file_range... no
checking for cosh... yes
checking for crypt_r... no
checking for daemon... (cached) no
checking for dirfd... yes
checking for dl_iterate_phdr... no
checking for dlopen... yes
checking for dladdr... yes
checking for dup3... no
checking for eaccess... no
checking for endgrent... yes
checking for eventfd... no
checking for execl... yes
checking for execle... yes
checking for execv... yes
checking for execve... yes
checking for explicit_memset... no
checking for fcopyfile... yes
checking for fchdir... yes
checking for fchmod... yes
checking for fchown... yes
checking for fcntl... yes
checking for fdatasync... (cached) no
checking for fdopendir... yes
checking for fgetattrlist... yes
checking for fmod... yes
checking for fstatat... yes
checking for fsync... yes
checking for ftruncate... yes
checking for ftruncate64... no
checking for getattrlist... yes
checking for getcwd... yes
checking for getegid... yes
checking for getentropy... yes
checking for geteuid... yes
checking for getgid... yes
checking for getgidx... no
checking for getgrnam... yes
checking for getgrnam_r... yes
checking for getgroups... yes
checking for getlogin... yes
checking for getlogin_r... yes
checking for getpgid... yes
checking for getpgrp... yes
checking for getppid... yes
checking for getpriority... yes
checking for getpwnam... yes
checking for getpwnam_r... yes
checking for getpwuid... yes
checking for getpwuid_r... yes
checking for getrandom... no
checking for getresgid... no
checking for getresuid... no
checking for getrlimit... yes
checking for getsid... yes
checking for gettimeofday... yes
checking for getuid... yes
checking for getuidx... no
checking for gmtime_r... yes
checking for initgroups... yes
checking for ioctl... yes
checking for isfinite... no
checking for issetugid... yes
checking for kill... yes
checking for killpg... yes
checking for lchmod... yes
checking for lchown... yes
checking for link... yes
checking for llabs... yes
checking for lockf... yes
checking for log2... yes
checking for lstat... yes
checking for lutimes... yes
checking for malloc_usable_size... no
checking for malloc_size... yes
checking for malloc_trim... no
checking for mblen... yes
checking for memalign... no
checking for memset_s... yes
checking for writev... yes
checking for memrchr... no
checking for memmem... yes
checking for mkfifo... yes
checking for mknod... yes
checking for mktime... yes
checking for mmap... yes
checking for mremap... no
checking for openat... yes
checking for pclose... yes
checking for pipe... yes
checking for pipe2... no
checking for poll... yes
checking for popen... yes
checking for posix_fadvise... no
checking for posix_madvise... yes
checking for posix_memalign... yes
checking for ppoll... no
checking for pread... yes
checking for pwrite... yes
checking for qsort_r... yes
checking for qsort_s... no
checking for readlink... yes
checking for realpath... yes
checking for round... yes
checking for sched_getaffinity... no
checking for seekdir... yes
checking for select_large_fdset... no
checking for sendfile... yes
checking for setegid... yes
checking for setenv... yes
checking for seteuid... yes
checking for setgid... yes
checking for setgroups... yes
checking for setpgid... yes
checking for setpgrp... yes
checking for setregid... yes
checking for setresgid... no
checking for setresuid... no
checking for setreuid... yes
checking for setrgid... yes
checking for setrlimit... yes
checking for setruid... yes
checking for setsid... yes
checking for setuid... yes
checking for shutdown... yes
checking for sigaction... yes
checking for sigaltstack... yes
checking for sigprocmask... yes
checking for sinh... yes
checking for snprintf... yes
checking for spawnv... no
checking for symlink... yes
checking for syscall... (cached) no
checking for sysconf... yes
checking for system... yes
checking for tanh... yes
checking for telldir... yes
checking for timegm... yes
checking for times... yes
checking for truncate... yes
checking for truncate64... no
checking for tzset... yes
checking for umask... yes
checking for unsetenv... yes
checking for utimensat... yes
checking for utimes... yes
checking for wait4... yes
checking for waitpid... yes
checking for __cospi... yes
checking for __sinpi... yes
checking if getcwd allocates buffer if NULL is given... yes
checking for __builtin_alloca_with_align... yes
checking for __builtin_assume_aligned... yes
checking for __builtin_bswap16... yes
checking for __builtin_bswap32... yes
checking for __builtin_bswap64... yes
checking for __builtin_popcount... yes
checking for __builtin_popcountll... yes
checking for __builtin_clz... yes
checking for __builtin_clzl... yes
checking for __builtin_clzll... yes
checking for __builtin_ctz... yes
checking for __builtin_ctzll... yes
checking for __builtin_constant_p... yes
checking for __builtin_choose_expr... yes
checking for __builtin_choose_expr_constant_p... yes
checking for __builtin_types_compatible_p... yes
checking for __builtin_trap... yes
checking for __builtin_expect... yes
checking for __builtin_add_overflow... yes
checking for __builtin_add_overflow_p... no
checking for __builtin_add_overflow with long long arguments... yes
checking for __builtin_sub_overflow... yes
checking for __builtin_sub_overflow_p... no
checking for __builtin_sub_overflow with long long arguments... yes
checking for __builtin_mul_overflow... yes
checking for __builtin_mul_overflow_p... no
checking for __builtin_mul_overflow with long long arguments... yes
checking whether qsort_r is GNU version... no
checking whether qsort_r is BSD version... yes
checking whether atan2 handles Inf as C99... yes
checking for clock_getres... yes
checking for timer_create in -lrt... no
checking for timer_settime in -lrt... no
checking for unsetenv returns a value... yes
checking whether struct tm is in sys/time.h or time.h... time.h
checking for struct tm.tm_zone... yes
checking for struct tm.tm_gmtoff... yes
checking for external int daylight... yes
checking for negative time_t for gmtime(3)... yes
checking for localtime(3) overflow correctly... yes
checking for sig_t... yes
checking whether right shift preserve sign bit... yes
checking for copy_file_range... no
checking whether _SC_CLK_TCK is supported... yes
checking stack growing direction on arm64... -1
checking native coroutine implementation for arm64-darwin24... arm64
checking whether pthread_t is scalar type... yes
checking for sched_yield... yes
checking for pthread_attr_setinheritsched... yes
checking for pthread_attr_get_np... no
checking for pthread_attr_getstack... yes
checking for pthread_attr_getguardsize... yes
checking for pthread_get_stackaddr_np... yes
checking for pthread_get_stacksize_np... yes
checking for thr_stksegment... no
checking for pthread_stackseg_np... no
checking for pthread_getthrds_np... no
checking for pthread_condattr_setclock... no
checking for pthread_setname_np... yes
checking for pthread_set_name_np... no
checking for pthread_sigmask... yes
checking for pthread_getattr_np... no
checking arguments of pthread_setname_np... (name)
checking for thread-local storage specifier... _Thread_local
checking if mcontext_t is a pointer... yes
checking for getcontext... (cached) no
checking for setcontext... (cached) no
checking if fork works with pthread... yes
checking for sys/user.h... yes
checking whether PAGE_SIZE is compile-time const... no
checking ioctl request type... unsigned long
checking for mach-o/loader.h... yes
checking whether OS depend dynamic link works... yes
checking whether -Wl,-multiply_defined,suppress is accepted as LDFLAGS... no
checking whether -Wl,-undefined,dynamic_lookup is accepted as LDFLAGS... yes
checking whether -Wl,-undefined,dynamic_lookup is accepted for bundle... yes
checking for libproc.h... yes
checking for execinfo.h... yes
checking for backtrace in -lexecinfo... no
checking for libunwind.h... yes
checking for mach/task.h... yes
checking for mach/mach_init.h... yes
checking for mach/mach_port.h... yes
checking for backtrace... yes
checking for broken backtrace... yes
checking for valgrind/memcheck.h... no
checking for strip flags... -A -n
checking whether -fPIE is accepted as CFLAGS... yes
checking whether -pie is accepted as LDFLAGS... no
checking whether -Wl,-pie is accepted as LDFLAGS... yes
checking whether wrapper for DYLD_LIBRARY_PATH is needed... yes
checking whether dtrace USDT is available... yes(-xnolibs)
checking whether dtrace needs post processing... no
checking for __builtin_setjmp... (cached) no
checking for _setjmpex as a macro or function... no
checking for _setjmp as a macro or function... yes
checking for setjmp type... _setjmp
checking if building with modular GC support... no
checking for rustc... no
checking for prefix of external symbols... _
checking whether -pipe is accepted as CFLAGS... yes
checking whether Security framework is needed... no
checking if make is GNU make... yes
.ext/include/arm64-darwin24/ruby/config.h unchanged
configure: ruby library version = 3.4.0
configure: creating ./config.status
config.status: creating GNUmakefile
config.status: creating Makefile
---
Configuration summary for ruby version 3.4.1

   * Installation prefix: /Users/aaron/.rbenv/versions/3.4.1
   * exec prefix:         ${prefix}
   * arch:                arm64-darwin24
   * site arch:           ${arch}
   * RUBY_BASE_NAME:      ruby
   * ruby lib prefix:     ${libdir}/${RUBY_BASE_NAME}
   * site libraries path: ${rubylibprefix}/${sitearch}
   * vendor path:         ${rubylibprefix}/vendor_ruby
   * target OS:           darwin24
   * compiler:            clang
   * with thread:         pthread
   * with coroutine:      arm64
   * with modular GC:     no
   * enable shared libs:  no
   * dynamic library ext: bundle
   * CFLAGS:              ${hardenflags} -fdeclspec  ${optflags} \
                          ${debugflags} ${warnflags}
   * LDFLAGS:             -L. -fstack-protector-strong \
                          -L/opt/homebrew/Cellar/readline/8.2.13/lib \
                          -L/opt/homebrew/Cellar/libyaml/0.2.5/lib \
                          -L/opt/homebrew/Cellar/gdbm/1.24/lib
   * DLDFLAGS:            -L/opt/homebrew/Cellar/readline/8.2.13/lib \
                          -L/opt/homebrew/Cellar/libyaml/0.2.5/lib \
                          -L/opt/homebrew/Cellar/gdbm/1.24/lib \
                          -Wl,-undefined,dynamic_lookup
   * optflags:            -O3 -fno-fast-math
   * debugflags:          -ggdb3
   * warnflags:           -Wall -Wextra -Wextra-tokens \
                          -Wdeprecated-declarations -Wdivision-by-zero \
                          -Wdiv-by-zero -Wimplicit-function-declaration \
                          -Wimplicit-int -Wpointer-arith -Wshorten-64-to-32 \
                          -Wwrite-strings -Wold-style-definition \
                          -Wmissing-noreturn -Wno-cast-function-type \
                          -Wno-constant-logical-operand -Wno-long-long \
                          -Wno-missing-field-initializers \
                          -Wno-overlength-strings -Wno-parentheses-equality \
                          -Wno-self-assign -Wno-tautological-compare \
                          -Wno-unused-parameter -Wno-unused-value \
                          -Wunused-variable -Wmisleading-indentation -Wundef
   * hardenflags:         -fstack-protector-strong -U_FORTIFY_SOURCE \
                          -D_FORTIFY_SOURCE=2
   * strip command:       strip -A -n
   * install doc:         rdoc
   * YJIT support:        no
   * RJIT support:        yes
   * man page type:       doc
   * BASERUBY -v:         ruby 3.4.1 (2024-12-25 revision 48d4efcb85) \
                          +PRISM [arm64-darwin24]

---
>>> Cleaning ruby 3.4.1 ...
file2lastrev.rb: does not seem to be under a vcs: .
cleaning rdoc
cleaning HTML
cleaning capi
for gc in gc/*/; do (cd -P $gc && exec /Library/Developer/CommandLineTools/usr/bin/make TARGET_SO_DIR=./ clean); done || :
make[1]: *** No rule to make target `clean'.  Stop.
make[1]: *** No rule to make target `clean'.  Stop.
cleaning encodings
find: ./exe: No such file or directory
cd libyaml && /Library/Developer/CommandLineTools/usr/bin/make clean
/bin/sh: line 0: cd: libyaml: No such file or directory
make[2]: [clean-so] Error 1 (ignored)
cleaning ext/-test-/RUBY_ALIGNOF
cleaning .bundle/gems/bigdecimal-3.1.8/ext/bigdecimal
cleaning ext/-test-/abi
cleaning ext/-test-/arith_seq/beg_len_step
cleaning .bundle/gems/debug-1.10.0/ext/debug
cleaning ext/-test-/arith_seq/extract
cleaning .bundle/gems/nkf-0.2.0/ext/nkf
cleaning ext/-test-/array/concat
cleaning .bundle/gems/racc-1.8.1/ext/racc/cparse
cleaning ext/-test-/array/resize
cleaning .bundle/gems/rbs-3.8.0/ext/rbs_extension
cleaning ext/-test-/asan
cleaning ext/-test-/bignum
cleaning .bundle/gems/syslog-0.2.0/ext/syslog
cleaning ext/-test-/bug-14834
cleaning ext/-test-/bug-3571
cleaning ext/-test-/bug-5832
cleaning ext/-test-/bug_reporter
cleaning ext/-test-/class
cleaning ext/-test-/cxxanyargs
cleaning ext/-test-/debug
cleaning ext/-test-/dln/empty
cleaning ext/-test-/econv
cleaning ext/-test-/ensure_and_callcc
cleaning ext/-test-/enumerator_kw
cleaning ext/-test-/eval
cleaning ext/-test-/exception
cleaning ext/-test-/fatal
cleaning ext/-test-/file
cleaning ext/-test-/float
cleaning ext/-test-/funcall
cleaning ext/-test-/gvl/call_without_gvl
cleaning ext/-test-/hash
cleaning ext/-test-/integer
cleaning ext/-test-/iseq_load
cleaning ext/-test-/iter
cleaning ext/-test-/load/dot.dot
cleaning ext/-test-/load/protect
cleaning ext/-test-/load/resolve_symbol_resolver
cleaning ext/-test-/load/resolve_symbol_target
cleaning ext/-test-/load/stringify_symbols
cleaning ext/-test-/load/stringify_target
cleaning ext/-test-/marshal/compat
cleaning ext/-test-/marshal/internal_ivar
cleaning ext/-test-/marshal/usr
cleaning ext/-test-/memory_status
cleaning ext/-test-/memory_view
cleaning ext/-test-/method
cleaning ext/-test-/notimplement
cleaning ext/-test-/num2int
cleaning ext/-test-/path_to_class
cleaning ext/-test-/popen_deadlock
cleaning ext/-test-/postponed_job
cleaning ext/-test-/printf
cleaning ext/-test-/proc
cleaning ext/-test-/public_header_warnings
cleaning ext/-test-/random
cleaning ext/-test-/rational
cleaning ext/-test-/rb_call_super_kw
cleaning ext/-test-/recursion
cleaning ext/-test-/regexp
cleaning ext/-test-/scan_args
cleaning ext/-test-/st/foreach
cleaning ext/-test-/st/numhash
cleaning ext/-test-/st/update
cleaning ext/-test-/string
cleaning ext/-test-/struct
cleaning ext/-test-/symbol
cleaning ext/-test-/thread/id
cleaning ext/-test-/thread/instrumentation
cleaning ext/-test-/thread/lock_native_thread
cleaning ext/-test-/thread_fd
cleaning ext/-test-/time
cleaning ext/-test-/tracepoint
cleaning ext/-test-/typeddata
cleaning ext/-test-/vm
cleaning ext/-test-/wait
cleaning ext/cgi/escape
cleaning ext/continuation
cleaning ext/coverage
cleaning ext/date
cleaning ext/digest
cleaning ext/digest/bubblebabble
cleaning ext/digest/md5
cleaning ext/digest/rmd160
cleaning ext/digest/sha1
cleaning ext/digest/sha2
cleaning ext/erb/escape
cleaning ext/etc
cleaning ext/fcntl
cleaning ext/fiddle
cleaning ext/io/console
cleaning ext/io/nonblock
cleaning ext/io/wait
cleaning ext/json
cleaning ext/json/generator
cleaning ext/json/parser
cleaning ext/monitor
cleaning ext/objspace
cleaning ext/openssl
cleaning ext/pathname
cleaning ext/psych
cd libyaml && /Library/Developer/CommandLineTools/usr/bin/make clean
/bin/sh: line 0: cd: libyaml: No such file or directory
make[1]: [clean-so] Error 1 (ignored)
cleaning ext/pty
cleaning ext/rbconfig/sizeof
cleaning ext/ripper
cleaning ext/rubyvm
cleaning ext/socket
cleaning ext/stringio
cleaning ext/strscan
cleaning ext/zlib
>>> Compiling ruby 3.4.1 ...
file2lastrev.rb: does not seem to be under a vcs: .
        BASERUBY = /Users/aaron/.rubies/ruby-3.4.1/bin/ruby --disable=gems
        CC = clang
        LD = ld
        LDSHARED = clang -dynamiclib
        CFLAGS = -fstack-protector-strong -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2 -fdeclspec  -O3 -fno-fast-math -ggdb3 -Wall -Wextra -Wextra-tokens -Wdeprecated-declarations -Wdivision-by-zero -Wdiv-by-zero -Wimplicit-function-declaration -Wimplicit-int -Wpointer-arith -Wshorten-64-to-32 -Wwrite-strings -Wold-style-definition -Wmissing-noreturn -Wno-cast-function-type -Wno-constant-logical-operand -Wno-long-long -Wno-missing-field-initializers -Wno-overlength-strings -Wno-parentheses-equality -Wno-self-assign -Wno-tautological-compare -Wno-unused-parameter -Wno-unused-value -Wunused-variable -Wmisleading-indentation -Wundef  -pipe -arch arm64
        XCFLAGS = -fno-strict-overflow -fvisibility=hidden -fexcess-precision=standard -DRUBY_EXPORT -fPIE -I. -I.ext/include/arm64-darwin24 -I./include -I. -I./prism -I./enc/unicode/15.0.0 -I/opt/homebrew/Cellar/readline/8.2.13/include -I/opt/homebrew/Cellar/libyaml/0.2.5/include -I/opt/homebrew/Cellar/gdbm/1.24/include  -Dmodular_gc_dir=
        CPPFLAGS = -D_XOPEN_SOURCE -D_DARWIN_C_SOURCE -D_DARWIN_UNLIMITED_SELECT -D_REENTRANT
        DLDFLAGS = -L/opt/homebrew/Cellar/readline/8.2.13/lib -L/opt/homebrew/Cellar/libyaml/0.2.5/lib -L/opt/homebrew/Cellar/gdbm/1.24/lib -Wl,-undefined,dynamic_lookup -fstack-protector-strong -Wl,-pie -framework CoreFoundation  -arch arm64
        SOLIBS = -ldl -lobjc -lpthread
        LANG = en_US.UTF-8
        LC_ALL = en_US.UTF-8
        LC_CTYPE =
        MFLAGS = - --jobserver-fds=3,4 -j
        RUSTC = no
        YJIT_RUSTC_ARGS = --crate-name=yjit --crate-type=staticlib --edition=2021 -g -C lto=thin -C opt-level=3 -C overflow-checks=on '--out-dir=/Users/aaron/src/ruby-3.4.1/yjit/target/release/' ./yjit/src/lib.rs
Apple clang version 16.0.0 (clang-1600.0.26.6)
Target: arm64-apple-darwin24.2.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
compiling ./main.c
compiling dmydln.c
compiling miniinit.c
translating probes probes.d
compiling ast.c
compiling bignum.c
compiling class.c
compiling compar.c
. ./vm_opts.h
compiling compile.c
compiling complex.c
compiling cont.c
compiling debug.c
compiling debug_counter.c
compiling dir.c
compiling dln_find.c
compiling encoding.c
compiling enum.c
compiling enumerator.c
compiling error.c
compiling eval.c
compiling file.c
compiling gc.c
compiling hash.c
compiling inits.c
compiling imemo.c
compiling io.c
compiling io_buffer.c
compiling iseq.c
compiling load.c
compiling marshal.c
compiling math.c
compiling memory_view.c
compiling rjit.c
compiling rjit_c.c
compiling node.c
compiling node_dump.c
compiling numeric.c
compiling object.c
compiling pack.c
compiling parse.c
compiling parser_st.c
compiling proc.c
compiling process.c
compiling ractor.c
compiling random.c
compiling range.c
compiling rational.c
compiling re.c
compiling regcomp.c
compiling regenc.c
compiling regerror.c
compiling regexec.c
compiling regparse.c
compiling regsyntax.c
compiling ruby.c
compiling ruby_parser.c
compiling scheduler.c
compiling shape.c
compiling signal.c
compiling sprintf.c
compiling st.c
compiling strftime.c
compiling string.c
compiling struct.c
compiling symbol.c
compiling thread.c
compiling time.c
compiling transcode.c
compiling util.c
compiling variable.c
revision.h unchanged
compiling vm.c
compiling vm_backtrace.c
compiling vm_dump.c
compiling vm_sync.c
compiling vm_trace.c
compiling weakmap.c
compiling ./missing/explicit_bzero.c
compiling ./missing/setproctitle.c
compiling addr2line.c
compiling dln.c
compiling localeinit.c
compiling dmyext.c
compiling dmyenc.c
compiling array.c
compiling version.c
compiling prism/api_node.c
/bin/sh ./tool/ifchange "--timestamp=.rbconfig.time" rbconfig.rb rbconfig.tmp
compiling prism/api_pack.c
rbconfig.rb updated
compiling prism/diagnostic.c
compiling prism/encoding.c
compiling prism/extension.c
compiling prism/node.c
compiling prism/options.c
compiling prism/pack.c
compiling prism/prettyprint.c
compiling prism/regexp.c
compiling prism/serialize.c
compiling prism/static_literals.c
compiling prism/token_type.c
compiling prism/util/pm_buffer.c
compiling prism/util/pm_char.c
compiling prism/util/pm_constant_pool.c
compiling prism/util/pm_integer.c
compiling prism/util/pm_list.c
compiling prism/util/pm_memchr.c
compiling prism/util/pm_newline_list.c
compiling prism/util/pm_string.c
compiling prism/util/pm_strncasecmp.c
compiling prism/util/pm_strpbrk.c
compiling prism/prism.c
compiling prism_init.c
assembling coroutine/arm64/Context.S
compiling enc/ascii.c
compiling enc/us_ascii.c
compiling enc/unicode.c
compiling enc/utf_8.c
compiling enc/trans/newline.c
generating encdb.h
generating arm64-darwin24-fake.rb
encdb.h updated
creating verconf.h
verconf.h updated
compiling loadpath.c
arm64-darwin24-fake.rb updated
generating enc.mk
making srcs under enc
make[1]: Nothing to be done for `srcs'.
generating transdb.h
transdb.h updated
linking miniruby
builtin_binary.inc updated
169edae11c0ebbe20fea4d2d58fa29188d954d17354830ee647ab25db709e953  builtin_binary.inc
compiling builtin.c
linking static-library libruby.3.4-static.a
generating makefiles ext/configure-ext.mk
making enc
making trans
compiling ./enc/trans/transdb.c
compiling ./enc/encdb.c
compiling ./enc/big5.c
compiling ./enc/cesu_8.c
compiling ./enc/trans/big5.c
compiling ./enc/trans/cesu_8.c
compiling ./enc/trans/chinese.c
ext/configure-ext.mk unchanged
compiling ./enc/cp949.c
compiling ./enc/emacs_mule.c
compiling ./enc/trans/ebcdic.c
compiling ./enc/trans/emoji.c
configuring cgi/escape
configuring -test-/RUBY_ALIGNOF
compiling ./enc/trans/emoji_iso2022_kddi.c
configuring continuation
compiling ./enc/euc_jp.c
compiling ./enc/trans/emoji_sjis_docomo.c
configuring coverage
compiling ./enc/euc_kr.c
configuring date
configuring digest
configuring digest/bubblebabble
configuring digest/md5
compiling ./enc/euc_tw.c
configuring erb/escape
compiling ./enc/trans/emoji_sjis_kddi.c
configuring -test-/abi
configuring -test-/arith_seq/beg_len_step
configuring -test-/arith_seq/extract
configuring -test-/array/concat
configuring -test-/array/resize
compiling ./enc/gb2312.c
configuring -test-/asan
configuring -test-/bignum
configuring -test-/bug-14834
configuring -test-/bug-3571
configuring -test-/bug-5832
configuring -test-/bug_reporter
configuring -test-/class
configuring -test-/cxxanyargs
compiling ./enc/gb18030.c
compiling ./enc/trans/emoji_sjis_softbank.c
configuring etc
configuring -test-/debug
configuring -test-/dln/empty
configuring -test-/econv
configuring -test-/ensure_and_callcc
configuring -test-/enumerator_kw
configuring -test-/eval
configuring -test-/exception
configuring -test-/fatal
configuring -test-/file
compiling ./enc/gbk.c
configuring digest/rmd160
compiling ./enc/iso_8859_1.c
configuring fcntl
compiling ./enc/trans/escape.c
compiling ./enc/iso_8859_2.c
compiling ./enc/trans/gb18030.c
configuring digest/sha1
configuring fiddle
compiling ./enc/iso_8859_3.c
configuring digest/sha2
compiling ./enc/iso_8859_4.c
configuring io/console
compiling ./enc/trans/gbk.c
compiling ./enc/iso_8859_5.c
compiling ./enc/trans/iso2022.c
compiling ./enc/iso_8859_6.c
compiling ./enc/iso_8859_7.c
configuring json
configuring json/generator
compiling ./enc/iso_8859_8.c
libffi_version: 3.4.0
compiling ./enc/trans/japanese.c
configuring monitor
compiling ./enc/iso_8859_9.c
configuring json/parser
configuring objspace
compiling ./enc/trans/japanese_euc.c
compiling ./enc/iso_8859_10.c
configuring openssl
configuring -test-/float
configuring -test-/funcall
configuring -test-/gvl/call_without_gvl
configuring -test-/hash
configuring -test-/integer
configuring -test-/iseq_load
configuring -test-/iter
configuring -test-/load/dot.dot
configuring -test-/load/protect
configuring -test-/load/resolve_symbol_resolver
configuring -test-/load/resolve_symbol_target
configuring -test-/load/stringify_symbols
configuring -test-/load/stringify_target
configuring -test-/marshal/compat
configuring -test-/marshal/internal_ivar
configuring -test-/marshal/usr
configuring -test-/memory_status
configuring -test-/memory_view
configuring -test-/method
configuring -test-/notimplement
compiling ./enc/iso_8859_11.c
configuring -test-/num2int
configuring -test-/path_to_class
configuring -test-/popen_deadlock
configuring -test-/postponed_job
configuring -test-/printf
configuring -test-/proc
configuring -test-/public_header_warnings
compiling ./enc/iso_8859_13.c
compiling ./enc/iso_8859_14.c
configuring -test-/random
configuring -test-/rational
configuring -test-/rb_call_super_kw
configuring -test-/recursion
configuring -test-/regexp
configuring -test-/scan_args
configuring -test-/st/foreach
configuring -test-/st/numhash
configuring -test-/st/update
configuring -test-/string
configuring -test-/struct
configuring -test-/symbol
compiling ./enc/iso_8859_15.c
compiling ./enc/iso_8859_16.c
configuring -test-/thread/id
compiling ./enc/koi8_r.c
compiling ./enc/trans/japanese_sjis.c
compiling ./enc/koi8_u.c
compiling ./enc/shift_jis.c
configuring -test-/thread/instrumentation
configuring -test-/thread/lock_native_thread
configuring -test-/thread_fd
configuring -test-/time
configuring -test-/tracepoint
configuring -test-/typeddata
configuring -test-/vm
configuring -test-/wait
configuring pathname
compiling ./enc/trans/korean.c
compiling ./enc/utf_16be.c
configuring psych
compiling ./enc/utf_16le.c
compiling ./enc/utf_32be.c
compiling ./enc/utf_32le.c
compiling ./enc/windows_31j.c
compiling ./enc/trans/single_byte.c
compiling ./enc/windows_1250.c
compiling ./enc/windows_1251.c
compiling ./enc/trans/utf8_mac.c
compiling ./enc/windows_1252.c
configuring pty
compiling ./enc/windows_1253.c
compiling ./enc/windows_1254.c
compiling ./enc/windows_1257.c
compiling ./enc/trans/utf_16_32.c
linking encoding encdb.bundle
linking transcoder transdb.bundle
linking encoding big5.bundle
linking transcoder big5.bundle
linking encoding cesu_8.bundle
linking transcoder cesu_8.bundle
linking encoding cp949.bundle
linking transcoder chinese.bundle
linking encoding emacs_mule.bundle
linking transcoder ebcdic.bundle
linking encoding euc_jp.bundle
linking transcoder emoji.bundle
linking encoding euc_kr.bundle
linking transcoder emoji_iso2022_kddi.bundle
linking encoding euc_tw.bundle
configuring rbconfig/sizeof
linking transcoder emoji_sjis_docomo.bundle
linking encoding gb2312.bundle
configuring ripper
linking transcoder emoji_sjis_kddi.bundle
linking encoding gb18030.bundle
linking transcoder emoji_sjis_softbank.bundle
configuring rubyvm
configuring socket
linking encoding gbk.bundle
linking transcoder escape.bundle
linking encoding iso_8859_1.bundle
linking transcoder gb18030.bundle
linking transcoder gbk.bundle
linking encoding iso_8859_2.bundle
configuring stringio
linking transcoder iso2022.bundle
linking encoding iso_8859_3.bundle
configuring strscan
linking transcoder japanese.bundle
linking encoding iso_8859_4.bundle
linking transcoder japanese_euc.bundle
linking encoding iso_8859_5.bundle
linking transcoder japanese_sjis.bundle
linking encoding iso_8859_6.bundle
linking transcoder korean.bundle
linking encoding iso_8859_7.bundle
linking transcoder single_byte.bundle
linking encoding iso_8859_8.bundle
linking encoding iso_8859_9.bundle
linking transcoder utf8_mac.bundle
linking transcoder utf_16_32.bundle
linking encoding iso_8859_10.bundle
linking encoding iso_8859_11.bundle
linking encoding iso_8859_13.bundle
linking encoding iso_8859_14.bundle
linking encoding iso_8859_15.bundle
linking encoding iso_8859_16.bundle
configuring zlib
linking encoding koi8_r.bundle
configuring bigdecimal-3.1.8/ext/bigdecimal
linking encoding koi8_u.bundle
linking encoding shift_jis.bundle
linking encoding utf_16be.bundle
linking encoding utf_16le.bundle
linking encoding utf_32be.bundle
linking encoding utf_32le.bundle
linking encoding windows_31j.bundle
linking encoding windows_1250.bundle
linking encoding windows_1251.bundle
linking encoding windows_1252.bundle
linking encoding windows_1253.bundle
linking encoding windows_1254.bundle
configuring debug-1.10.0/ext/debug
linking encoding windows_1257.bundle
configuring nkf-0.2.0/ext/nkf
configuring racc-1.8.1/ext/racc/cparse
making encs
configuring rbs-3.8.0/ext/rbs_extension
configuring syslog-0.2.0/ext/syslog
make[1]: Nothing to be done for `encs'.
configuring io/nonblock
configuring io/wait
generating makefile exts.mk
exts.mk unchanged
compiling asan.c
compiling c.c
compiling beg_len_step.c
compiling to_ary_concat.c
compiling extract.c
compiling resize.c
compiling big2str.c
compiling bug-14834.c
compiling cpp.cpp
linking linking shared-object -test-/array/resize.bundle
shared-object -test-/asan.bundle
linking shared-object -test-/array/to_ary_concat.bundle
linking shared-object -test-/arith_seq/extract.bundle
linking shared-object -test-/arith_seq/beg_len_step.bundle
linking shared-object -test-/bug_14834.bundle
compiling bigzero.c
compiling div.c
compiling init.c
compiling bug.c
compiling intpack.c
compiling bug.c
compiling mul.c
compiling bug_reporter.c
linking shared-object -test-/RUBY_ALIGNOF.bundle
compiling class2name.c
linking shared-object -test-/bug_3571.bundle
linking shared-object -test-/bug_5832.bundle
compiling cxxanyargs.cpp
compiling init.c
compiling str2big.c
linking shared-object -test-/bug_reporter.bundle
compiling init.c
compiling empty.c
compiling append.c
linking shared-object -test-/class.bundle
linking shared-object -test-/bignum.bundle
compiling inspector.c
compiling init.c
linking shared-object -test-/dln/empty.bundle
compiling profile_frames.c
compiling ensure_and_callcc.c
compiling enumerator_kw.c
linking shared-object -test-/econv.bundle
compiling eval.c
compiling dataerror.c
compiling enc_raise.c
linking shared-object -test-/debug.bundle
linking shared-object -test-/cxxanyargs.bundle
linking shared-object -test-/ensure_and_callcc.bundle
linking shared-object -test-/enumerator_kw.bundle
linking shared-object -test-/eval.bundle
compiling init.c
compiling invalid.c
compiling ensured.c
compiling rb_fatal.c
compiling init.c
compiling fs.c
compiling init.c
compiling init.c
compiling nextafter.c
compiling funcall.c
linking shared-object -test-/fatal.bundle
compiling call_without_gvl.c
linking shared-object -test-/exception.bundle
compiling newline_conv.c
compiling stat.c
compiling delete.c
linking shared-object -test-/float.bundle
linking shared-object -test-/funcall.bundle
linking shared-object -test-/gvl/call_without_gvl.bundle
compiling core_ext.c
compiling init.c
compiling init.c
linking shared-object -test-/file.bundle
compiling iseq_load.c
compiling my_integer.c
compiling break.c
compiling init.c
compiling dot.dot.c
compiling yield.c
linking shared-object -test-/hash.bundle
linking shared-object -test-/iseq_load.bundle
linking shared-object -test-/integer.bundle
compiling resolve_symbol_resolver.c
compiling protect.c
compiling resolve_symbol_target.c
linking shared-object -test-/load/dot.dot.bundle
linking shared-object -test-/iter.bundle
compiling stringify_symbols.c
compiling stringify_target.c
linking shared-object -test-/load/resolve_symbol_resolver.bundle
compiling usrcompat.c
linking shared-object -test-/load/protect.bundle
linking shared-object -test-/load/resolve_symbol_target.bundle
compiling internal_ivar.c
compiling usrmarshal.c
linking shared-object -test-/load/stringify_target.bundle
linking shared-object -test-/load/stringify_symbols.bundle
linking shared-object -test-/marshal/compat.bundle
compiling memory_status.c
compiling memory_view.c
compiling arity.c
linking shared-object -test-/marshal/internal_ivar.bundle
linking shared-object -test-/marshal/usr.bundle
compiling bug.c
compiling num2int.c
compiling init.c
compiling path_to_class.c
linking shared-object -test-/memory_status.bundle
compiling postponed_job.c
linking shared-object -test-/memory_view.bundle
compiling printf.c
linking shared-object -test-/method.bundle
linking shared-object -test-/notimplement.bundle
linking shared-object -test-/num2int.bundle
linking shared-object -test-/path_to_class.bundle
compiling init.c
compiling receiver.c
linking shared-object -test-/postponed_job.bundle
compiling super.c
linking shared-object -test-/printf.bundle
compiling bad_version.c
compiling rat.c
compiling rb_call_super_kw.c
compiling init.c
compiling recursion.c
linking shared-object -test-/proc.bundle
compiling loop.c
linking shared-object -test-/rational.bundle
compiling init.c
compiling scan_args.c
linking shared-object -test-/rb_call_super_kw.bundle
compiling foreach.c
linking shared-object -test-/recursion.bundle
linking shared-object -test-/random.bundle
compiling parse_depth_limit.c
compiling numhash.c
compiling update.c
compiling capacity.c
linking shared-object -test-/st/foreach.bundle
compiling data.c
linking shared-object -test-/regexp.bundle
compiling coderange.c
linking shared-object -test-/st/update.bundle
linking shared-object -test-/st/numhash.bundle
linking shared-object -test-/scan_args.bundle
compiling duplicate.c
compiling cstr.c
compiling init.c
compiling len.c
compiling init.c
compiling ellipsize.c
compiling instrumentation.c
compiling lock_native_thread.c
compiling member.c
compiling type.c
compiling thread_fd.c
compiling enc_associate.c
compiling init.c
compiling gc_hook.c
linking shared-object -test-/struct.bundle
linking shared-object -test-/thread/lock_native_thread.bundle
linking shared-object -test-/symbol.bundle
linking shared-object -test-/thread/instrumentation.bundle
compiling leap_second.c
linking shared-object -test-/thread_fd.bundle
compiling enc_dummy.c
compiling tracepoint.c
compiling new.c
compiling typeddata.c
compiling enc_str_buf_cat.c
compiling fstring.c
compiling at_exit.c
compiling init.c
compiling wait.c
linking shared-object -test-/tracepoint.bundle
linking shared-object -test-/time.bundle
linking shared-object -test-/typeddata.bundle
linking shared-object -test-/wait.bundle
compiling escape.c
linking shared-object -test-/vm/at_exit.bundle
compiling continuation.c
compiling modify.c
compiling new.c
compiling coverage.c
compiling nofree.c
compiling date_core.c
installing default coverage libraries
linking shared-object continuation.bundle
compiling digest.c
compiling normalize.c
linking shared-object cgi/escape.bundle
compiling qsort.c
compiling escape.c
compiling rb_interned_str.c
compiling etc.c
linking shared-object coverage.bundle
compiling rb_str_dup.c
compiling date_parse.c
linking shared-object erb/escape.bundle
compiling fcntl.c
linking shared-object digest.bundle
compiling set_len.c
compiling closure.c
linking shared-object etc.bundle
linking shared-object fcntl.bundle
compiling date_strftime.c
linking shared-object -test-/string.bundle
installing digest libraries
installing default digest libraries
compiling conversions.c
compiling date_strptime.c
compiling console.c
compiling nonblock.c
compiling fiddle.c
installing default date_core libraries
compiling function.c
linking shared-object io/nonblock.bundle
compiling wait.c
installing default console libraries
linking shared-object io/console.bundle
compiling monitor.c
compiling handle.c
linking shared-object io/wait.bundle
compiling object_tracing.c
installing default monitor libraries
compiling objspace.c
compiling openssl_missing.c
compiling memory_view.c
compiling ossl.c
linking shared-object monitor.bundle
compiling pathname.c
compiling ossl_asn1.c
compiling objspace_dump.c
installing default pathname libraries
compiling ossl_bio.c
compiling pinned.c
compiling ossl_bn.c
compiling pointer.c
compiling psych.c
installing default objspace libraries
compiling pty.c
linking shared-object pathname.bundle
linking shared-object objspace.bundle
compiling psych_emitter.c
compiling sizes.c
compiling eventids1.c
installing default fiddle libraries
installing default pty libraries
compiling ossl_cipher.c
linking shared-object pty.bundle
compiling limits.c
linking shared-object fiddle.bundle
compiling psych_parser.c
compiling eventids2.c
ld: warning: ignoring duplicate libraries: '-lffi'
linking shared-object date_core.bundle
compiling ossl_config.c
compiling psych_to_ruby.c
linking shared-object rbconfig/sizeof.bundle
compiling ripper.c
installing default libraries
compiling psych_yaml_tree.c
compiling ossl_digest.c
compiling ripper_init.c
compiling init.c
compiling ossl_engine.c
compiling stringio.c
compiling constants.c
compiling ossl_hmac.c
compiling strscan.c
compiling ossl_kdf.c
compiling basicsocket.c
linking shared-object psych.bundle
compiling zlib.c
ld: warning: ignoring duplicate libraries: '-lyaml'
checking ../.././parse.y and ../.././ext/ripper/eventids2.c
compiling ossl_ns_spki.c
linking shared-object stringio.bundle
linking shared-object strscan.bundle
compiling socket.c
compiling ossl_ocsp.c
installing default ripper libraries
compiling ipsocket.c
installing default strscan libraries
compiling ossl_pkcs12.c
compiling ossl_pkcs7.c
compiling bigdecimal.c
compiling ossl_pkey.c
compiling missing.c
compiling debug.c
compiling tcpsocket.c
compiling nkf.c
linking shared-object zlib.bundle
compiling iseq_collector.c
compiling tcpserver.c
compiling ossl_pkey_dh.c
linking shared-object debug/debug.bundle
compiling cparse.c
compiling sockssocket.c
compiling ossl_pkey_dsa.c
compiling udpsocket.c
compiling ossl_pkey_ec.c
compiling linking shared-object ../../../../.././.bundle/gems/rbs-3.8.0/ext/rbs_extension/../../src/constants.c
racc/cparse.bundle
compiling unixsocket.c
compiling ossl_pkey_rsa.c
compiling ../../../../.././.bundle/gems/rbs-3.8.0/ext/rbs_extension/../../src/ruby_objs.c
compiling unixserver.c
compiling syslog.c
compiling lexer.c
compiling option.c
compiling ossl_provider.c
compiling lexstate.c
linking shared-object syslog_ext.bundle
linking shared-object bigdecimal.bundle
compiling ancdata.c
compiling location.c
compiling ossl_rand.c
compiling raddrinfo.c
compiling ifaddr.c
compiling main.c
linking shared-object nkf.bundle
compiling ossl_ssl.c
compiling parser.c
compiling ossl_ssl_session.c
compiling bubblebabble.c
compiling parserstate.c
compiling ossl_ts.c
linking shared-object digest/bubblebabble.bundle
compiling ossl_x509.c
compiling unescape.c
compiling md5init.c
installing default socket libraries
linking shared-object socket.bundle
compiling ossl_x509attr.c
compiling ossl_x509cert.c
compiling ossl_x509crl.c
linking shared-object digest/md5.bundle
compiling ossl_x509ext.c
linking shared-object rbs_extension.bundle
compiling rmd160init.c
compiling ossl_x509name.c
compiling rmd160.c
compiling ossl_x509req.c
compiling ossl_x509revoked.c
compiling ossl_x509store.c
compiling sha1init.c
compiling sha2init.c
linking shared-object digest/rmd160.bundle
linking shared-object digest/sha1.bundle
compiling generator.c
linking shared-object digest/sha2.bundle
compiling parser.c
installing default sha2 libraries
installing default openssl libraries
linking shared-object openssl.bundle
linking shared-object ripper.bundle
linking shared-object json/ext/generator.bundle
linking shared-object json/ext/parser.bundle
file2lastrev.rb: does not seem to be under a vcs: .
revision.h unchanged
config.status: creating ruby-runner.h
ln -sf ../../rbconfig.rb .ext/arm64-darwin24/rbconfig.rb
linking ruby
ld: warning: ignoring duplicate libraries: '-ldl', '-lobjc', '-lpthread'
make[1]: Nothing to be done for `note'.
>>> Installing ruby 3.4.1 ...
file2lastrev.rb: does not seem to be under a vcs: .
        BASERUBY = /Users/aaron/.rubies/ruby-3.4.1/bin/ruby --disable=gems
        CC = clang
        LD = ld
        LDSHARED = clang -dynamiclib
        CFLAGS = -fstack-protector-strong -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2 -fdeclspec  -O3 -fno-fast-math -ggdb3 -Wall -Wextra -Wextra-tokens -Wdeprecated-declarations -Wdivision-by-zero -Wdiv-by-zero -Wimplicit-function-declaration -Wimplicit-int -Wpointer-arith -Wshorten-64-to-32 -Wwrite-strings -Wold-style-definition -Wmissing-noreturn -Wno-cast-function-type -Wno-constant-logical-operand -Wno-long-long -Wno-missing-field-initializers -Wno-overlength-strings -Wno-parentheses-equality -Wno-self-assign -Wno-tautological-compare -Wno-unused-parameter -Wno-unused-value -Wunused-variable -Wmisleading-indentation -Wundef  -pipe -arch arm64
        XCFLAGS = -fno-strict-overflow -fvisibility=hidden -fexcess-precision=standard -DRUBY_EXPORT -fPIE -I. -I.ext/include/arm64-darwin24 -I./include -I. -I./prism -I./enc/unicode/15.0.0 -I/opt/homebrew/Cellar/readline/8.2.13/include -I/opt/homebrew/Cellar/libyaml/0.2.5/include -I/opt/homebrew/Cellar/gdbm/1.24/include  -Dmodular_gc_dir=
        CPPFLAGS = -D_XOPEN_SOURCE -D_DARWIN_C_SOURCE -D_DARWIN_UNLIMITED_SELECT -D_REENTRANT
        DLDFLAGS = -L/opt/homebrew/Cellar/readline/8.2.13/lib -L/opt/homebrew/Cellar/libyaml/0.2.5/lib -L/opt/homebrew/Cellar/gdbm/1.24/lib -Wl,-undefined,dynamic_lookup -fstack-protector-strong -Wl,-pie -framework CoreFoundation  -arch arm64
        SOLIBS = -ldl -lobjc -lpthread
        LANG = en_US.UTF-8
        LC_ALL = en_US.UTF-8
        LC_CTYPE =
        MFLAGS = - --jobserver-fds=3,4 -j
        RUSTC = no
        YJIT_RUSTC_ARGS = --crate-name=yjit --crate-type=staticlib --edition=2021 -g -C lto=thin -C opt-level=3 -C overflow-checks=on '--out-dir=/Users/aaron/src/ruby-3.4.1/yjit/target/release/' ./yjit/src/lib.rs
Apple clang version 16.0.0 (clang-1600.0.26.6)
Target: arm64-apple-darwin24.2.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
revision.h unchanged
generating arm64-darwin24-fake.rb
arm64-darwin24-fake.rb updated
generating enc.mk
making srcs under enc
making enc
make[1]: Nothing to be done for `enc'.
make[1]: Nothing to be done for `srcs'.
generating transdb.h
transdb.h unchanged
generating makefiles ext/configure-ext.mk
making trans
make[1]: Nothing to be done for `trans'.
making encs
ext/configure-ext.mk unchanged
make[1]: Nothing to be done for `encs'.
generating makefile exts.mk
exts.mk unchanged
file2lastrev.rb: does not seem to be under a vcs: .
revision.h unchanged
make[1]: Nothing to be done for `note'.
Generating RDoc documentation
Parsing sources...
100% [847/847]  yjit.rb

Generating RI format into /Users/aaron/src/ruby-3.4.1/.ext/rdoc...

You can visit the home page at: file:///Users/aaron/src/ruby-3.4.1/.ext/rdoc/index.html

  Files:        847

  Classes:     1162 ( 249 undocumented)
  Modules:      201 (  60 undocumented)
  Constants:   2404 ( 542 undocumented)
  Attributes:  1140 ( 205 undocumented)
  Methods:    12740 (1900 undocumented)

  Total:      17647 (2956 undocumented)
   83.25% documented

  Elapsed: 15.5s

SDKROOT= ./miniruby -I./lib -I. -I.ext/common  ./tool/runruby.rb --extout=.ext  -- --disable-gems -r./arm64-darwin24-fake ./tool/rbinstall.rb --make="/Library/Developer/CommandLineTools/usr/bin/make" --dest-dir="" --extout=".ext" --ext-build-dir="./ext" --mflags="- --jobserver-fds=3,4 -j" --make-flags=" --jobserver-fds=3,4 -j" --data-mode=0644 --prog-mode=0755 --installed-list .installed.list --mantype="doc"  --gnumake --install=all --rdoc-output=".ext/rdoc" --html-output=".ext/html"
installing binary commands:         /Users/aaron/.rbenv/versions/3.4.1/bin
installing base libraries:          /Users/aaron/.rbenv/versions/3.4.1/lib
installing arch files:              /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/3.4.0/arm64-darwin24
installing pkgconfig data:          /Users/aaron/.rbenv/versions/3.4.1/lib/pkgconfig
installing extension objects:       /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/3.4.0/arm64-darwin24
installing extension objects:       /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/site_ruby/3.4.0/arm64-darwin24
installing extension objects:       /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/vendor_ruby/3.4.0/arm64-darwin24
installing extension headers:       /Users/aaron/.rbenv/versions/3.4.1/include/ruby-3.4.0/arm64-darwin24
installing extension scripts:       /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/3.4.0
installing extension scripts:       /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/site_ruby/3.4.0
installing extension scripts:       /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/vendor_ruby/3.4.0
installing extension headers:       /Users/aaron/.rbenv/versions/3.4.1/include/ruby-3.4.0/ruby
installing rdoc:                    /Users/aaron/.rbenv/versions/3.4.1/share/ri/3.4.0/system
installing html-docs:               /Users/aaron/.rbenv/versions/3.4.1/share/doc/ruby
installing capi-docs:               /Users/aaron/.rbenv/versions/3.4.1/share/doc/ruby
installing command scripts:         /Users/aaron/.rbenv/versions/3.4.1/bin
installing library scripts:         /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/3.4.0
installing common headers:          /Users/aaron/.rbenv/versions/3.4.1/include/ruby-3.4.0
installing manpages:                /Users/aaron/.rbenv/versions/3.4.1/share/man/man1
installing default gems from lib:   /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/gems/3.4.0
                                    benchmark 0.4.0
                                    bundler 2.6.2
                                    cgi 0.4.1
                                    delegate 0.4.0
                                    did_you_mean 2.0.0
                                    english 0.8.0
                                    erb 4.0.4
                                    error_highlight 0.7.0
                                    fileutils 1.7.3
                                    find 0.2.0
                                    forwardable 1.3.3
                                    ipaddr 1.2.7
                                    irb 1.14.3
                                    logger 1.6.4
                                    net-http 0.6.0
                                    net-protocol 0.2.2
                                    open-uri 0.5.0
                                    open3 0.2.1
                                    optparse 0.6.0
                                    ostruct 0.6.1
                                    pp 0.6.2
                                    prettyprint 0.2.0
                                    prism 1.2.0
                                    pstore 0.1.4
                                    rdoc 6.10.0
                                    readline 0.0.4
                                    reline 0.6.0
                                    resolv 0.6.0
                                    ruby2_keywords 0.0.5
                                    securerandom 0.4.1
                                    set 1.1.1
                                    shellwords 0.2.2
                                    singleton 0.3.0
                                    syntax_suggest 2.0.2
                                    tempfile 0.3.1
                                    time 0.4.1
                                    timeout 0.4.3
                                    tmpdir 0.3.1
                                    tsort 0.2.0
                                    un 0.3.0
                                    uri 1.0.2
                                    weakref 0.1.3
                                    yaml 0.4.0
installing default gems from ext:   /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/gems/3.4.0
                                    date 3.4.1
                                    digest 3.2.0
                                    etc 1.4.5
                                    fcntl 1.2.0
                                    fiddle 1.1.6
                                    io-console 0.8.0
                                    io-nonblock 0.3.1
                                    io-wait 0.3.1
                                    json 2.9.1
                                    openssl 3.3.0
                                    pathname 0.4.0
                                    psych 5.2.2
                                    stringio 3.1.2
                                    strscan 3.1.2
                                    zlib 3.2.1
installing bundled gems:            /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/gems/3.4.0
                                    minitest 5.25.4
                                    power_assert 2.0.5
                                    rake 13.2.1
                                    test-unit 3.6.7
                                    rexml 3.4.0
                                    rss 0.3.1
                                    net-ftp 0.3.8
                                    net-imap 0.5.4
                                    net-pop 0.1.2
                                    net-smtp 0.5.0
                                    matrix 0.4.2
                                    prime 0.1.3
                                    rbs 3.8.0
                                    typeprof 0.30.1
                                    debug 1.10.0
                                    racc 1.8.1
                                    mutex_m 0.3.0
                                    getoptlong 0.2.1
                                    base64 0.2.0
                                    bigdecimal 3.1.8
                                    observer 0.1.2
                                    abbrev 0.1.2
                                    resolv-replace 0.1.1
                                    rinda 0.2.0
                                    drb 2.2.1
                                    nkf 0.2.0
                                    syslog 0.2.0
                                    csv 3.3.2
                                    repl_type_completor 0.1.9
installing bundled gem cache:       /Users/aaron/.rbenv/versions/3.4.1/lib/ruby/gems/3.4.0/cache
>>> Successfully installed ruby 3.4.1 into /Users/aaron/.rbenv/versions/3.4.1
```
