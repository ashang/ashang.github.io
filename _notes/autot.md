
# AC_ARG_ENABLE

用AC_ARG_ENABLE来定义一个命令行选项。

AC_ARG_ENABLE(feature, help-string [, action-if-given [, action-if-not-given]])

宏参数

1. flag_base: the flag would be --enable-[option base]
2. help string
3. 当configure带该选项运行时所执行的代码，代码中的命令行变量enableval被设为此选项的值
4. default value

选项不带参数时等效于带参数yes
--disable-server与--enable-server=no等效
当不带--enable-server运行时的缺省值为true。

```
AC_ARG_ENABLE(server,
    [AC_HELP_STRING([--enable-server],
                    [enable server build])],
    [ case "${enableval}" in
          yes) server=true ;;
          no) server=false ;;
          *) AC_MSG_ERROR(bad value ${enableval} for --enable-server) ;;
      esac ],
    [server=true]
)
```

```
AC_ARG_ENABLE([eventfd],
    [AS_HELP_STRING([--disable-eventfd], [disable eventfd [default=no]])],
    [zmq_enable_eventfd=$enableval],
    [zmq_enable_eventfd=yes]
)

if test "x$zmq_enable_eventfd" = "xyes"; then
    # Check if we have eventfd.h header file.
    AC_CHECK_HEADERS(sys/eventfd.h,
        [AC_DEFINE(ZMQ_HAVE_EVENTFD, 1, [Have eventfd extension.])])
fi
```

```
AC_ARG_ENABLE(debug,
    AS_HELP_STRING(--enable-debug, debug, syslog or xyz),
    If test "x$enableval" == "xsyslog"; then
        AC_DEFINE(SYSLOG)
    elif test "x$enableval" == "xdebug"; then
        AC_DEFINE(DEBUG)
    fi,
    AC_DEFINE(XYZ)
)
```

```
AC_ARG_ENABLE(states-type,
    [--enable-states-type[=state type] Specify the states type:
                      compact [default]: Compact States
                      debug: Debug States (very slow)
                      indirect: Indirect Stack States],
    [ if test "x$enableval" = "xcompact" ; then
          states_type=compact
      elif test "x$enableval" = "xdebug" ; then
          states_type=debug
      elif test "x$enableval" = "xindirect" ; then
          states_type=indirect
      else
          echo
          echo "Error!"
          echo "Unknown states' type"
          exit -1
      fi]
)
```

# AC_DEFINE

AC_DEFINE(VARIABLE, VALUE, DESCRIPTION)

这个宏会在AC_CONFIG_HEADERS定义的头文件中增加一个定义项。例如：

/* DESCRIPTION */
#define VARIABLE VALUE 

The macro AC_DEFINE can be used anywhere in the script, to define a C preprocessor macro.

It accepts an optional argument indicating the value of the macro.

If you want to do shell expansion for the value, use AC_DEFINE_UNQUOTED instead.

```
AC_DEFINE(HELLO)

AC_DEFINE(VERSION, "5.6")

myvar="foo"
othervar="bar"
AC_DEFINE_UNQUOTED(TEST, "${myvar}${othervar}")
```

# AC_CHECK_HEADERS([headers])

AC_CHECK_HEADERS([unistd.h windows.h])

这个宏将在当前建造环境下检查unistd.h,windows.h是否存在。并将两个参数写入到配置头文件中。一般是config.h，你可以使用AC_CONFIG_HEADERS([headers])来指定。

```
AC_CONFIG_HEADERS([config.h])
```

如果存在就会出现在config.h中例如下面:

```
/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <windows.h> header file. */
#define HAVE_WINDOWS_H 1
```

# AC_CHECK_FUNC

AC_CHECK_FUNC (function, [action-if-found], [action-if-not-found])
AC_CHECK_FUNCS (function…, [action-if-found], [action-if-not-found])

检查函数是否存在，如果存在执行动作action-if-found,没有发现执行动作action-if-not-found。
如果你没给出action-if-found和action-if-not-found，在发现函数的时候回定义对应的变量，以HAVE_开头，函数的名称都转换成大写。例如：

AC_CHECK_FUNCS(perror gettimeofday clock_gettime memset socket getifaddrs freeifaddrs fork)

如果发现clock_gettime将会定义变量#define HAVE_CLOCK_GETTIME 1在对应的配置头文件中。
如果没发现将不会定义。但是也会有一个注释行/* #undef HAVE_CLOCK_GETTIME */

# AC_ARG_WITH

AC_ARG_WITH (package, help-string, [action-if-given], [action-if-not-given])

这个宏可以给configure增加–with-package这样模式的参数。

```
AC_ARG_WITH([militant],
    [AS_HELP_STRING([--with-militant],
                    [Enable militant API assertions])],
    [zmq_militant="yes"],
    []
)

if test "x$zmq_militant" = "xyes"; then
    AC_DEFINE(ZMQ_ACT_MILITANT, 1, [Enable militant API assertions])
fi
```

返回值 withval

例如：--with-libcurl=/usr/local
则$withval=/usr/local

配置google protocol buffer 的例子：

libpb_prefix="/usr/local"

AC_ARG_WITH([protobuf], [AC_HELP_STRING([[--with-protobuf[=DIR]]], [Specify path to protobuf installation])],,[withval="no"])

AC_MSG_CHECKING([check for protobuf installation]) 


if test "$withval" != "no" -a "$withval" != ""; then
    libpb_prefix="$withval"
else
    AC_MSG_RESULT([no])
    AC_MSG_ERROR([please specify protobuf install path])
fi

#下面是初始化一些库路径，并简单检查库的目录是否存在

libpb_include="$libpb_prefix/include"
libpb_lib="$libpb_prefix/lib"
libpb_ok="yes"
pb_ldflag=""

if test -d "$libpb_prefix"; then
    if test ! -d "$libpb_include"; then
        libpb_ok="no"
    fi
else
    libpb_ok="no"
fi

#下面是检测后的处理

if test "$libpb_ok" == "yes"; then
    AC_MSG_RESULT([yes])
    CPPFLAGS="$CPPFLAGS -I$libpb_include"
    LDFLAGS="$LDFLAGS -L$libpb_lib"

    pb_ldflag="-lprotobuf"
    AC_SUBST(pb_ldflag) #AC_SUBST设置输出变量，能够在makefile.am文件里面使用。

else
    AC_MSG_RESULT([no])
    AC_MSG_ERROR([protobuf not found])
fi

下面看下Makefile.am的配置片段：

bin_PROGRAMS = serverd

serverd_SOURCES = server.cpp

serverd_LDADD =  $(pb_ldflag)  #这里引用configure输出的变量。

PS: 实际上，可以把连接选项配置在configure.ac里面的LIBS变量，区别就是一个全局的一个局部的


# 共享库和静态库

编译动态库或者静态库，你需要再你的configure.ac中加入下面的宏：

```
LT_PREREQ([2.4.0])
LT_INIT([disable-static win32-dll dlopen])
AC_PROG_LIBTOOL
```

LT_PREREQ给出一个版本需求检查。LT_INIT可以实现一些配置，例如win32-dll允许建造动态库，disable-static默认关闭静态库的建造。默认动态库和静态库是同时打开的。

AC_PROG_LIBTOOL检查libtool脚本。做完这些在你的configure中会增加一些选项–enable-static , –enable-shared。


# 自定义的测试程序

AC_RUN_IFELSE (input, [action-if-true], [action-if-false], [action-if-cross-compiling = ‘AC_MSG_FAILURE’])

编译运行input程序，如果程序成功运行返回0,执行action-if-true，否则执行action-if-false。如果交叉编译打开，那么编译出来的代码不能在本机执行，这是其他的动作都不会执行，如果action-if-cross-compiling存在将被执行。
另外这里的input必须是有一个宏指定的源代码。

AC_LANG_PROGRAM (prologue, body)

[AC_LANG_PROGRAM([[const char hw[] = "Hello, World\n";]],
                      [[fputs (hw, stdout);]])])

将被展开为下面的代码：

     #define PACKAGE_NAME "Hello"
     #define PACKAGE_TARNAME "hello"
     #define PACKAGE_VERSION "1.0"
     #define PACKAGE_STRING "Hello 1.0"
     #define PACKAGE_BUGREPORT "bug-hello@example.org"
     #define PACKAGE_URL "http://www.example.org/"
     #define HELLO_WORLD "Hello, World\n"

     const char hw[] = "Hello, World\n";
     int
     main ()
     {
     fputs (hw, stdout);
       ;
       return 0;
     }

下面看一个完整的例子：

AC_MSG_CHECKING([if TIPC is available and supports nonblocking connect])

AC_RUN_IFELSE(
    [AC_LANG_PROGRAM([[
            #include <stdlib.h>
            #include <string.h>
            #include <fcntl.h>
            #include <errno.h>
            #include <sys/socket.h>
            #include <linux/tipc.h>
        ]],[[
            struct sockaddr_tipc topsrv;
            int sd = socket(AF_TIPC, SOCK_SEQPACKET, 0);
            if (sd == -EAFNOSUPPORT) {
                return 1;
            }
            memset(&topsrv, 0, sizeof(topsrv));
            topsrv.family = AF_TIPC;
            topsrv.addrtype = TIPC_ADDR_NAME;
            topsrv.addr.name.name.type = TIPC_TOP_SRV;
            topsrv.addr.name.name.instance = TIPC_TOP_SRV;
            fcntl(sd, F_SETFL, O_NONBLOCK);
            if (connect(sd, (struct sockaddr *)&topsrv, sizeof(topsrv)) != 0) {
                if (errno != EINPROGRESS)
                    return -1;
            }
        ]])
    ],
    [libzmq_tipc_support=yes],
    [libzmq_tipc_support=no],
    [libzmq_tipc_support=no])

AC_MSG_RESULT([$libzmq_tipc_support])

AC_MSG_CHECKING和AC_MSG_RESULT共同显示一个检查信息。这些信息将显示在执行configure脚本时。
上面的宏在编译执行完给定代码后，如何成功就执行libzmq_tipc_support=yes，这同样导致configure打印一个信息if TIPC is available and supports nonblocking connect : yes

下面你可以使用libzmq_tipc_support来定义一个宏到头文件中。

```
if test "x$libzmq_tipc_support" = "xyes"; then
    AC_DEFINE(ZMQ_HAVE_TIPC, 1, [Have TIPC support])
fi
```

# 支持 --enable-debug 选项和--disable-debug选项。

当使用--enable-debug时，将在config.h里定义宏DEBUG为1。
当使用-- disable-debug或者不使用 --enable-debug也不使用--disable-debug时，在config.h里面定义宏DEBUG为0。

```
AC_ARG_ENABLE([debug],
    [AS_HELP_STRING([--enable-debug],[output debug log (default is no)])],
    [if test "$enableval" == "yes"; then
        AC_DEFINE([DEBUG],[1],[Define if --enable-debug])
    else
        AC_DEFINE([DEBUG],[0],[Define if --disable-debug])
    fi
    ],
    [AC_DEFINE([DEBUG],[0],[Define if need to output debug log])]
)
```

```
AC_ARG_ENABLE([debug],
    [AS_HELP_STRING([--enable-debug],[debug program(default is no)])],
    [CFLAGS="${CFLAGS} -DDEBUG -g"],
    [CFLAGS="-O2"]
)
```

```
AC_ARG_ENABLE([debug],
	[AC_HELP_STRING([--enable-debug], [compile for debugging])],
	[CXXFLAGS="-DDEBUG -g -O0"],
	[CXXFLAGS="-O2 -minline-all-stringops -fomit-frame-pointer"]
)


```





