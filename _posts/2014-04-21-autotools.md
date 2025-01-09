


AC_ARG_WITH([feature],
  [AS_HELP_STRING([--with-feature],
                 [enable or disable this feature])],
  [enable_feature=$withval],
  [enable_feature=yes])

AC_DEFINE([ENABLE_FEATURE], [$enable_feature],
  [Define if the feature is enabled])


#

#ifdef is a preprocessor directive that checks whether a macro has been defined.

#ifdef DEBUG
// Code included only if DEBUG is defined
printf("Debugging is enabled\n");
#endif



The defined() operator is used in conjunction with the #if or #elif directives to check if a macro is defined or not.

It is typically used in more complex conditional compilation expressions.

Example:

c
Copy code
#if defined(DEBUG) && DEBUG > 0
// Code included only if DEBUG is defined and its value is greater than 0
printf("Debugging is enabled with level %d\n", DEBUG);
#endif


Note that when using #if defined(), the parentheses are optional, so you can also write it as #if defined DEBUG. However, when using defined() in a standalone expression, the parentheses are required, like defined(DEBUG).


## a macro that takes one parameter x. When the macro is used in code, the x will be replaced by the actual argument provided when the macro is invoked.

Here's an example of how you might use this macro:

c
Copy code
#define module_init(x)   init_##x

// Usage of the macro
module_init(MyModule);
After preprocessing, the above usage of the macro would be transformed into:

c
Copy code
init_MyModule;
So, in the context of #define module_init(x), x is a placeholder for a name or identifier,



#

Autoconf is a tool that makes your packages more portable by performing tests to discover system characteristics before the package is compiled. Your source code can then adapt to these differences.

Automake is a tool for generating ‘Makefile’s—descriptions of what to build—that conform to a number of standards. Automake substantially simplifies the process of describing the organization of a package and performs additional functions such as dependency tracking between source files.

Libtool is a command line interface to the compiler and linker that makes it easy to portably generate static and shared libraries, regardless of the platform it is running on. 

##


* autoscan (autoconf): 扫描源代码以搜寻普通的可移植性问题，比如检查编译器，库，头文件等，生成文件configure.scan,它是configure.ac的一个雏形。

    your source files --> [autoscan*] --> [configure.scan] --> configure.ac

    $ dpkg -S /usr/bin/autoscan 
    autoconf: /usr/bin/autoscan


* aclocal (automake):

根据已经安装的宏，用户定义宏和acinclude.m4文件中的宏将configure.ac文件所需要的宏集中定义到文件 aclocal.m4中。

use aclocal --print to see where aclocal is looking for .m4 files



Because ‘configure.in’ contains macro invocations which are not known to autoconf itself–AM_INIT_AUTOMAKE being a case in point, it is necessary to collect all of the macro definitions for autoconf to use when generating ‘configure’. 

This is done using the aclocal program, so called because it generates ‘aclocal.m4’.

If you were to examine the contents of ‘aclocal.m4’, you would find the definition of the AM_INIT_AUTOMAKE macro contained within.

After running autoconf, you will find a ‘configure’ script in the current directory. 

It is important to run aclocal first because automake relies on the contents of ‘configure.in’ and ‘aclocal.m4’. 

    configure.ac + acinclude.m4 --> [aclocal] --> aclocal.m4


    aclocal - create aclocal.m4 by scanning configure.ac

    $ dpkg -S /usr/bin/aclocal-1.15 
    automake: /usr/bin/aclocal-1.15

    $ file /usr/bin/aclocal-1.15 
    /usr/bin/aclocal-1.15: a /usr/bin/perl -w script, ASCII text executable


```
user input files   optional input     process          output files
================   ==============     =======          ============

                    acinclude.m4 - - - - -.
                                          V
                                      .-------,
configure.ac ------------------------>|aclocal|
                 {user macro files} ->|       |------> aclocal.m4

```


* autoheader(autoconf): 根据configure.ac中的某些宏，比如cpp宏定义，运行m4，声称config.h.in

    configure.ac + aclocal.m4 --> [autoheader] --> autoconfig.h.in

    $ dpkg -S /usr/bin/autoheader 
    autoconf: /usr/bin/autoheader



```
user input files    optional input     process          output files
================    ==============     =======          ============

                    aclocal.m4 - - - - - - - .
                                             |
                                             V
                                     .----------,
configure.ac ----------------------->|autoheader|----> autoconfig.h.in

```

* automake: automake将Makefile.am中定义的结构建立Makefile.in，然后configure脚本将生成的Makefile.in文件转换为Makefile。

如果在configure.ac中定义了一些特殊的宏，比如AC_PROG_LIBTOOL，它会调用libtoolize，否则它 会自己产生config.guess和config.sub

    configure.ac + Makefile.am --> [automake] --> COPYING
                                                  INSTALL
                                                  install-sh
                                                  missing
                                                  mkinstalldirs
                                                  Makefile.in
                                                  stamp-h.in
                                                  config.sub
                                                  config.guess

                           [libtoolize] --> config.sub
                                            config.guess
                                            ltmain.sh
                                            ltconfig
                                            

```
user input files   optional input   processes          output files
================   ==============   =========          ============

                                     .--------,
                                     |        | - - -> COPYING
                                     |        | - - -> INSTALL
                                     |        |------> install-sh
                                     |        |------> missing
                                     |automake|------> mkinstalldirs
configure.ac ----------------------->|        |
Makefile.am  ----------------------->|        |------> Makefile.in
                                     |        |------> stamp-h.in
                                 .---+        | - - -> config.guess
                                 |   |        | - - -> config.sub
                                 |   `------+-'
                                 |          | - - - -> config.guess
                                 |libtoolize| - - - -> config.sub
                                 |          |--------> ltmain.sh
                                 |          |--------> ltconfig
                                 `----------'

```




* autoconf:将configure.ac中的宏展开，生成configure脚本。这个过程可能要用到aclocal.m4中定义的宏。

    configure.ac + aclocal.m4 --> [autoconf] --> configure
                  + autoconfig.h.in


```
user input files   optional input   processes          output files
================   ==============   =========          ============

aclocal.m4 ,autoconfig.h.in - - - - - - -.
                                         V
                                     .--------,
configure.ac ----------------------->|autoconf|------> configure

```


* configure

    configure ------------------ --> config.log
                                |  \ config.cache
                                \
    config.h.in + Makefile.in --> config.status
                                | \
                                |  autoconfig.h
                                 \ Makefile


```
                                           .-------------> [config.cache]
     configure* --------------------------+-------------> config.log
                                          |
              [config.h.in] -.            v            .--> [autoconfig.h]
                             +-------> config.status* -+                   
              Makefile.in ---'                         `-->   Makefile

```

* make

```
[autoconfig.h] -.
                     +--> make* --->  程序
        Makefile   ---'

 

.---------,
                   config.site - - ->|         |
                  config.cache - - ->|configure| - - -> config.cache
                                     |         +-,
                                     `-+-------' |
                                       |         |----> config.status
                   config.h.in ------->|config-  |----> config.h
                   Makefile.in ------->|  .status|----> Makefile
                                       |         |----> stamp-h
                                       |         +--,
                                     .-+         |  |
                                     | `------+--'  |
                   ltmain.sh ------->|ltconfig|-------> libtool
                                     |        |     |
                                     `-+------'     |
                                       |config.guess|
                                       | config.sub |
                                       `------------'

 

.--------,
                   Makefile ------>|        |
                   config.h ------>|  make  |
{project sources} ---------------->|        |--------> {project targets}
                                 .-+        +--,
                                 | `--------'  |
                                 |   libtool   |
                                 |   missing   |
                                 |  install-sh |
                                 |mkinstalldirs|
                                 `-------------'




```


# example

```
$ more hello.c
#include <stdio.h>

int main(int argc, char** argv)
{
    printf("Hello, world!\n");
    return 0;
}
```

```
autoscan
mv configure.scan configure.ac
```

```
EDITOR configure.ac

$ more configure.ac 
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.


AC_PREREQ([2.69])
AC_INIT([my-hello], [0.1])
AC_CONFIG_SRCDIR([hello.c])
#AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AM_INIT_AUTOMAKE

AC_OUTPUT(Makefile)

```

```
aclocal

autoconf

EDITOR Makefile.am

AUTOMAKE_OPTIONS= foreign
bin_PROGRAMS= hello
hello_SOURCES= hello.c
```

```
automake
automake --add-missing
```

```
./configure

make
```

# overview

# configure.ac
configure.ac文件内容是一系列GNU m4 的宏，这些宏经autoconf处理后会变成检查系统特性的shell scripts。

configure.ac 内宏的顺序并没有特别的规定，但是每一个configure.ac 文件必須在所有宏前加入 AC_INIT 宏，然后在所有宏的最后加上 AC_OUTPUT宏。

可先用 autoscan 扫描原始文件以产生一个 configure.scan 文件，再对 configure.scan 做些修改成 configure.ac 文件。

* dnl                                     这个宏后面的字不会被处理，可以视为注释 
* AC_INIT(FILE)                           检查源代码所在路径，autoscan 自动产生。
* AM_INIT_AUTOMAKE(PACKAGE,VERSION) 是automake 所必备的宏
* AC_PROG_CC                检查系统可用的C编译器，若源代码是用C写的就需要这个宏。
* AC_OUTPUT(FILE)       设置 configure 所要产生的文件，若是Makefile ，configure 便会把它检查出来的结果带入  Makefile.in 文件后产生合适的 Makefile。 

实际上，使用 automake 时，还需要一些其他的宏，这些额外的宏我们用 aclocal来帮助产生。

執行 aclocal会产生aclocal.m4 文件，如果无特别的用途，可以不需要修改它，用 aclocal 所产生的宏会告诉 Automake如何动作。 

有了 configure.ac 及 aclocal.m4两个文件以后，便可以执行 autoconf来产生 configure 文件了。


# Makefile.am
    automake 会根据 configure.ac 中的宏把Makefile.am 转成 Makefile.in 文件。

Makefile.am 文件定义所要产生的目标： 
* AUTOMAKE_OPTIONS                            设置 automake 的选项。

在执行 automake 时，会检查目录下是否存在标准 GNU 软件中应具备的文件，例如 'NEWS'、'AUTHOR'、'ChangeLog' 等文件。

GNU对自己发布的软件有严格的规范, 比如必须附带许可证声明文件COPYING等, 否则automake执行时会报错. 

automake提供了3中软件等级:foreign, gnu和gnits, 供用户选择. 默认级别是gnu. 

foreign等级, 它只检测必须的文件.



* bin_PROGRAMS       定义要产生的执行文件名。如果要产生多个执行文件，每个文件名用空白符隔开。 
* hello_SOURCES      定义执行程序所需要的原始文件。如果这个程序是由多个原始文件所产生，必須把它所用到的所有原始文件都列出来，以空白符隔开。


如果定义多个执行文件，则对每个执行程序都要定义相对的filename_SOURCES。

编辑好 Makefile.am 文件，就可以用 automake --add-missing来产生 Makefile.in。

--add-missiing让automake自动添加一些必须的脚本文件.


Automake产生生出來的 Makefile.in 文件是完全符合 GNU Makefile 的惯例，只要执行 configure这个shell script 便可以产生合适的 Makefile 文件了。

#

GNU M4 is a prerequisite for Autoconf.

Perl is a prerequisite for Autoconf.

GNU Automake uses Autoconf.

GNU Libtool also uses Autoconf.


Autoconf

Autoconf is an extensible package of M4 macros that produce shell scripts to automatically configure software source code packages. These scripts can adapt the packages to many kinds of UNIX-like systems without manual user intervention. Autoconf creates a configuration script for a package from a template file that lists the operating system features that the package can use, in the form of M4 macro calls.

Producing configuration scripts using Autoconf requires GNU M4. You should install GNU M4 (at least version 1.4.6, although 1.4.13 or later is recommended) before configuring Autoconf, so that Autoconf's configure script can find it. The configuration scripts produced by Autoconf are self-contained, so their users do not need to have Autoconf (or GNU M4). 


Automake

* http://www.gnu.org/software/automake/manual/index.html
* http://www.gnu.org/software/automake/manual/automake.html


Automake is a tool for automatically generating `Makefile.in' files compliant with the GNU Coding Standards. 

http://sources.redhat.com/automake/



automake所產生的Makefile符合GNU編程標準。

automake是由Perl語言所寫的，必須和GNU autoconf一併使用。automake包含了以下命令：

    * aclocal
    * automake

aclocal是個泛用的程式，對於autoconf使用者是相當有用的。舉例而言，GNU Compiler Collection使用aclocal，即使Makefile是手寫的。

就像autoconf，automake並非完全向下相容的。


Automake目标是让使用者透过高阶语言来写makefile，而不是透过纯手工的方式来写整个makefile。在简单的情况下，它能提供：

    * source档案的列表;
    * 传给编译器的command-line选项列表(比如标头档置于哪个路径);
    * 传给链结器的command-line选项列表(程是需要哪些程式库以及它们的路径)。

经由这些资讯，Automake产生makefile能够让使用者：

    * 编译程式;
    * clean (清除，删除编译过程中所产生的档案);
    * 将程式安装于标准路径;
    * 将程式反安装(从安装的地方移除);
    * create a source distribution archive (commonly called a tarball);
    * test that this archive is self-sufficient, and in particular that the program can be compiled in a directory other than the one where the sources are deployed.

[edit] 依存性资讯的产生

Automake能够自动生成依存性的资讯，因此，当一个source文件被修改，下次呼叫make命令的时候就会知道哪些source文件需要重新编译。如果编译器允许， Automake会试着让依存性系统保持动态：无论何时source文件被编译，都会要求编译器重新产生依存性列表更新该文件的依存性。换句话说，依存性追踪是编译过程的一种边际效应。

这企图避免一些静态依存性系统的问题，比如依存性只会在程式员开始专案时才会被侦测到。在这种情况下，如果源文件获得一个新的依存性(例如，如果程式员增加了一个新的＃ include指令在C语言的source文件)，这样在真实的依存性和编译系统所使用的依存性之间就会产生差异。程式员应该重新产生依存性，但很有可能忘了那样做。 在一般情况下， automake透过随附的depcomp脚本生成依存性，这会适当的呼叫编译器或是回到makedepend。如果gcc编译器的版本够新的话，automake将会inline依存性生成码，直接呼叫gcc。

Automake can also help with the compilation of libraries by automatically generating makefiles that will invoke GNU Libtool. 

The programmer is thus exempted from having to know how to call Libtool directly, and the project benefits from the use of a portable library creation tool.





configure.in

是configure脚本的输入文件，为了解决在不同unix变种之间移植程序的问题：库名可能不同，应用程序名可能不同，结构和常量的定义可能不同……

configure脚本完成autoconf与automake的初始化工作，为不同的平台定义相应的宏，检测并指定适当的程序名、库名、结构和常量名等等，指定要为哪些目录输出Makefile文件。总之，为编译程序做好一切准备工作。




configure.in的八股文

基本初始化部分：包括AC_INIT (必须第一个出现), AM_INIT_AUTOMAKE(程序包名，版本号), AC_CONFIG_HEADER
可选宏：如AC_ARG_ENABLE
检测某些程序的存在性
检查程序用到的库
检查某些头文件是否存在。
检查Typedefs and structures。
检查Functions。
指定在哪些目录输出Makefile。

autoscan will do most of the work for you.


# Makefile.am

指定要生成什么目标，它由什么源文件生成，要安装到什么目录。

可执行文件：
bin_PROGRAMS = foo
foo_SOURCES = foo1.c foo1.h foo2.c
foo_LDADD = foo3.o -lm foo4.a
foo_LDFLAGS = -L<lib_path>
foo_DEPENDENCIES = 

对静态库：
lib_LIBRARIES = libfoo.a
foo_a_SOURCES =
foo_a_LDADD =  
foo_a_LIBADD =
foo_a_LDFLAGS = 

只在make时做静态连接用，不安装的库：
noinst_LIBRARIES = libfoo.a

对头文件：include_HEADERS = foo.h
对数据文件：data_DATA = data1 data2 


全局变量(对所有目标都适用)
INCLUDES = -I/dir1 -I/dir2
LDFLAGS = -L/dir1 -L/dir2
LDADD = foo.o foo.a -lfoo
EXTRA_DIST = file1 file2 源程序和一些默认的文件自动打入.tar.gz包，其它文件若要进入.tar.gz包可以用这种办法，比如配置文件, 数据文件等等。
SUBDIRS = dir1 dir2 在处理本目录之前要递归处理哪些子目录


标准安装路径
$(prefix) = /usr/local 是所有安装目录的默认前缀，可以通过./configure --prefix=<new_prefix>的方法覆盖。
其它的预定义目录如：bindir = $(prefix)/bin, libdir = $(prefix)/lib, datadir = $(prefix)/share, sysconfdir = $(prefix)/etc, …
想定义一个新的安装路径？比如config, 可定义
confdir = $(prefix)/config,  然后conf_DATA = file1 file2，则file1, file2会作为数据文件安装到$(prefix)/config目录下。


尽量用相对路径引用源程序的位置，以下两个变量是预定义好的：
$(top_srcdir)无论在哪个目录层次，该变量定义了包含src目录的目录位置，用于引用源程序；
$(top_builddir)定义了生成目标文件上最上层目录，用于引用.o等编译出来的目标文件。


configure脚本生成的Makefile中已经带了很多常用的目标如：check, all, install, uninstall, clean, dist, distcheck, distclean, tags, maintainerclean.
If configure or make did it, make distclean undoes it.
If make did it, make clean undoes it.
If make install did it, make uninstall undoes it.
If you did it, make maintainer-clean undoes it.


# libtool

libtoolize

The libtoolize program provides a standard way to add libtool support to your package. In the future, it may implement better usage checking, or other features to make libtool even easier to use.


生成各种程序库的方便工具。
提供一个统一的接口，程序员不用关心各种烦人的底层细节：不同的平台的库可能要求不同的后缀，不同平台对库的安装方法不同，有些平台不支持动态库等等。
生成高层次的库，称为libtool library，后缀是.la。用它连接时，默认产生动态连接库，也可以用-static参数指定生成静态连接库。
既可单独使用又可与automake和autoconf一起使用更加强大、方便。


在configure.in文件中加上AC_PROG_LIBTOOL宏，如果原来有AC_PROG_RANLIB宏，删去它。

在Makefile.am文件中：
   lib_LTLIBRARIES = libshell.la 
   libshell_la_SOURCES = object.c subr.c symbol.c 
    与原来的写法非常相似！

.la库只能连入.lo(使用libtool生成的目标文件)
   libshell_la_LDADD = xmalloc.lo @LTLIBOBJS@ 

传入库的版本号：
    libshell_la_LDFLAGS = -version-info 1:0:1 

与其它目标文件连接时用LDFLAGS指定连接的方式(默认是动态方式）：-static, --all-static指定静态连接。


# ltmain, autogen, bootstrap, etc.

Libtool comes with a tool called libtoolize that will install libtool’s supporting files into a package. Running this command will install ltmain.sh. You should execute it before aclocal and automake.

Since Automake 1.6, it has been decided that running libtoolize was none of Automake’s business. Instead, that functionality has been moved into the autoreconf command (see Using autoreconf in The Autoconf Manual). If you do not want to remember what to run and when, just learn the autoreconf command. Hopefully, replacing existing bootstrap.sh or autogen.sh scripts by a call to autoreconf should also free you from any similar incompatible change in the future. 



# Autoreconf

       Run `autoconf' (and `autoheader', `aclocal', `automake', `autopoint' (formerly `gettextize'), and `libtoolize' where appropriate) repeatedly to remake the GNU
       Build System files in specified DIRECTORIES and their subdirectories (defaulting to `.').

       By default, it only remakes those files that are older than their sources.  If you install new versions of the GNU Build System,  you  can  make  `autoreconf'
       remake all of the files by giving it the `--force' option.

# Usual steps

    autoreconf --install
    ./configure
    make

run ./configure after autoreconf -fi (which is recommended over autogen.sh/bootstrap.sh-like scripts)



# Why no autoreconf?
	

The software developer who creates the tarball (or who checks out the sources from a version control system) will usually invoke autoreconf from a script called bootstrap.sh or autogen.sh which may do other stuff. autoreconf might be invoked by Makefile as well (like when configure.ac has changed).

Most users will never need to run autoreconf, even those who are making some modifications to source (e.g. patches). Only those who need to make modifications to the package itself (making changes to configure.ac and/or Makefile.am) will need autoreconf.




# Using autoreconf to Update configure Scripts

Installing the various components of the GNU Build System can be tedious: running autopoint for Gettext, automake for Makefile.in etc. in each directory. It may be needed either because some tools such as automake have been updated on your system, or because some of the sources such as configure.ac have been updated, or finally, simply in order to install the GNU Build System in a fresh tree.

autoreconf runs autoconf, autoheader, aclocal, automake, libtoolize, and autopoint (when appropriate) repeatedly to update the GNU Build System in the specified directories and their subdirectories (see Subdirectories). By default, it only remakes those files that are older than their sources. The environment variables AUTOM4TE, AUTOCONF, AUTOHEADER, AUTOMAKE, ACLOCAL, AUTOPOINT, LIBTOOLIZE, M4, and MAKE may be used to override the invocation of the respective tools.

If you install a new version of some tool, you can make autoreconf remake all of the files by giving it the --force option.

See Automatic Remaking, for Make rules to automatically rebuild configure scripts when their source files change. That method handles the timestamps of configuration header templates properly, but does not pass --autoconf-dir=dir or --localdir=dir. 



# I have downloaded a macro from Autoconf Archive, and I want to use it. What do I have to put in my configure.ac file to make use this macro?

You may want to add AC_CONFIG_MACRO_DIR to configure.ac to the directory where the macro is:

    AC_CONFIG_MACRO_DIR([path/to/macros])

You'll need to invoke the macro somewhere in this file also.

and in Makefile.am you'll probably need to set up ACLOCAL_AMFLAGS (if you are using automake):

    ACLOCAL_AMFLAGS         = -I path/to/macros

Then invoke autoreconf -fvi and you should be set.




	add m4 as AC_CONFIG_MACRO_DIR to your configure.ac
	rm aclocal.m4  if it exists
	mkdir m4       if it does not exist
	# copy some dummy files into the folder 
	# or some versions of autoconf  won't work   
	autoreconf -i --install    



----




I'm not using automake, so the only way I've found is to use the m4_include macro to suck in each .m4 file individually. I found this approach here:

http://www.flameeyes.eu/autotools-mythbuster/autoconf/macros.html

Hope this helps. (Considering how long autoconf has been around, it boggles my mind somewhat that there's no built-in way to just specify a directory in the .ac file. Seems like it would be an awefully common use case. Oh, well.)









# References

- The Goat Book, GNU Autoconf, Automake and Libtool, by Gary V. Vaughan, Ben Elliston, Tom Tromey and Ian Lance Taylor
    - https://www.sourceware.org/autobook/


- http://www.dwheeler.com/autotools/

When you are first learning how to use the autotools, avoid anything written about the autotools before around 2006. Things are just too different today, and you will waste a lot of time. You can tell that autotools information is obsolete if it talks about creating “configure.in” (the modern conventional name is “configure.ac”), fails to emphasize using autoreconf and “autoreconf -i” (and instead talks a lot about invoking by hand various tools, such as aclocal or autoheader), or fails to talk about creating an “m4” subdirectory (and instead talks about creating an aclocal.m4 file).




The autobook is not up to date anymore and more difficult to read. However it still contains interesting chapters like Writing Portable Bourne Shell.

    - https://autotools.io/
    - http://www.freesoftwaremagazine.com/books/autotools_a_guide_to_autoconf_automake_libtool



- Managing Projects with GNU Make, Third Edition By Robert Mecklenburg
    - http://www.oreilly.com/openbook/make3/book/index.csp
- Programming from the Ground Up Book
    - http://savannah.nongnu.org/projects/pgubook/
- How to Run a Successful Free Software Project
    - http://producingoss.com/
- Think Python, How to Think Like a Computer Scientist
    - http://www.greenteapress.com/thinkpython/thinkpython.html
- Documentation for binutils 2.27
    - https://sourceware.org/binutils/docs-2.27/
