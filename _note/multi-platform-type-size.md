---
title: Multi-platform coding and 'printf'
date: 2011-11-20
---

C99 `/usr/include/inttypes.h`
provides '#define' names for what the string literals should be and use in `printf` like calls.

```c
# if __WORDSIZE == 64
#  define __PRI64_PREFIX        "l"
#  define __PRIPTR_PREFIX       "l"
# else
#  define __PRI64_PREFIX        "ll"
#  define __PRIPTR_PREFIX
# endif

///

/* Unsigned integers.  */
# define PRIu8          "u"
# define PRIu16         "u"
# define PRIu32         "u"
# define PRIu64         __PRI64_PREFIX "u"

///

/* Signed decimal notation.  */
# define SCNi8          "hhi"
# define SCNi16         "hi"
# define SCNi32         "i"
# define SCNi64         __PRI64_PREFIX "i"
```

`CC` this with '-Wall -Werror'.

```c
#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t n = 123;
    printf("%lu", n);
    printf("%u",  n);
}
```

## PICO / TCC, etc

```c
#if PICO
  #include "pico/stdlib.h"
#else
  #if TCC
    #include <stdint.h>
  #else
    typedef unsigned           char     uint8_t;
    typedef unsigned short     int      uint16_t;
    typedef unsigned long      int      uint32_t;
    typedef unsigned long long int      uint64_t;
    typedef signed             char     int8_t;
    typedef signed   short     int      int16_t;
    typedef signed   long      int              int32_t_shadow;
    #define                             int32_t int32_t_shadow
    typedef signed   long long int      int64_t;
  #endif
#endif

    uint8_t  u8  = 0xFF;                 print("%x   \t %u"   CRLF, u8,  u8);
    uint16_t u16 = 0xFFFF;               print("%x   \t %u"   CRLF, u16, u16);
    uint32_t u32 = 0xFFFF1234;           print("%lx  \t %lu"  CRLF, u32, u32);
    uint64_t u64 = 0xFFFF1234ABCD5678LL; print("%llx \t %llu" CRLF, u64, u64);

    int8_t   i8  = 0x7F;                 print("%x   \t %i"   CRLF, i8,  i8);
    int16_t  i16 = 0x7FFF;               print("%x   \t %i"   CRLF, i16, i16);
    int32_t  i32 = 0x7FFF1234;           print("%lx  \t %li"  CRLF, i32, i32);
    int64_t  i64 = 0x7FFF1234ABCD5678LL; print("%llx \t %lli" CRLF, i64, i64);
```

`stdint.h`
has fixed-width integer types since C99 (<https://en.wikipedia.org/wiki/C_data_types#stdint.h>).

GCC seems ships with this feature since 4.5 (<https://gcc.gnu.org/c99status.html>).

Rather than making assumptions about the mapping to platform-dependent types we should leave them up to the standard library. Also technically `long long` is part of C99/C++11.

## Using `%zu`

Using `%zu` as well as the format-string macros for fixed-size integer types defined by `inttypes.h` seems consequent and the most portable solution.

```c
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    printf("%zu\n", sizeof(int64_t));
    printf("%s\n", PRId64);
    printf("%+"PRId64"\n", INT64_MIN);
    printf("%+"PRId64"\n", INT64_MAX);

    int64_t n = 7;
    printf("%+"PRId64"\n", n);
}
```

Possible output:

```text
8
lld
-9223372036854775808
+9223372036854775807
+7
```

`CC` in c89:

```c
main.cpp: In function 'main':

main.cpp:6:12: warning: ISO C90 does not support the 'z' gnu_printf length modifier [-Wformat=]

    6 |     printf("%zu\n", sizeof(int64_t));
      |            ^~~~~~~

main.cpp:11:5: error: ISO C90 forbids mixed declarations and code [-Wdeclaration-after-statement]

   11 |     int64_t n = 7;
      |     ^~~~~~~

main.cpp:13:1: warning: control reaches end of non-void function [-Wreturn-type]

   13 | }
      | ^
```

C99 is OK.

## __WORDSIZE

Compiler internal value.

```c
#include<stdio.h>

int main()
{
    printf("Word size : %d\n",__WORDSIZE);
}
```

```sh
$ gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/11/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 11.3.0-1ubuntu1~22.04' --with-bugurl=file:///usr/share/doc/gcc-11/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-11 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-11-xKiWfi/gcc-11-11.3.0/debian/tmp-nvptx/usr,amdgcn-amdhsa=/build/gcc-11-xKiWfi/gcc-11-11.3.0/debian/tmp-gcn/usr --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 11.3.0 (Ubuntu 11.3.0-1ubuntu1~22.04)

$ clang --version
Ubuntu clang version 14.0.0-1ubuntu1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin

$ clang -v
Ubuntu clang version 14.0.0-1ubuntu1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/11
Selected GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/11
Candidate multilib: .;@m64
Selected multilib: .;@m64
```

```sh
cat /usr/include/x86_64-linux-gnu/bits/wordsize.h
```

```c
/* Determine the wordsize from the preprocessor defines.  */

#if defined __x86_64__ && !defined __ILP32__
# define __WORDSIZE     64
#else
# define __WORDSIZE     32
#define __WORDSIZE32_SIZE_ULONG         0
#define __WORDSIZE32_PTRDIFF_LONG       0
#endif

#ifdef __x86_64__
# define __WORDSIZE_TIME64_COMPAT32     1
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# define __SYSCALL_WORDSIZE             64
#else
# define __WORDSIZE_TIME64_COMPAT32     0
#endif
```

```c
$ cat /usr/arm-linux-gnueabi/include/bits/wordsize.h
#define __WORDSIZE                      32
#define __WORDSIZE_TIME64_COMPAT32      0
#define __WORDSIZE32_SIZE_ULONG         0
#define __WORDSIZE32_PTRDIFF_LONG       0
```

## Links

- <https://en.cppreference.com/w/c/types/integer>



ISO C99 includes the inttypes.h header file that includes a number of macros for use in platform-independent printf coding. These must be outside double-quotes, e.g. printf("%" PRId64 "\n", t);

Example macros include:

    Macro 	Description
    PRId32 	Typically equivalent to I32d (Win32/Win64) or d
    PRId64 	Typically equivalent to I64d (Win32/Win64), lld (32-bit platforms) or ld (64-bit platforms)
    PRIi32 	Typically equivalent to I32i (Win32/Win64) or i
    PRIi64 	Typically equivalent to I64i (Win32/Win64), lli (32-bit platforms) or li (64-bit platforms)
    PRIu32 	Typically equivalent to I32u (Win32/Win64) or u
    PRIu64 	Typically equivalent to I64u (Win32/Win64), llu (32-bit platforms) or lu (64-bit platforms)
    PRIx32 	Typically equivalent to I32x (Win32/Win64) or x
    PRIx64 	Typically equivalent to I64x (Win32/Win64), llx (32-bit platforms) or lx (64-bit platforms)

The syntax for a format placeholder is

    %[parameter][flags][width][.precision][length]type

Length
z 	For integer types, causes printf to expect a size_t-sized integer argument.
j 	For integer types, causes printf to expect a intmax_t-sized integer argument.

