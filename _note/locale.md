---
title: locale
layout: post
tags: [locale]
date: 2022-12-19
---


locale相关（环境）变量生效的优先顺序：[1]

    LANGUAGE 指定个人对语言环境值的主次偏好，例如zh_CN:en_US:en
    LC_ALL 这不是一个环境变量，是一个可被C语言库函数setlocale设置的宏，其值可覆盖所有其他的locale设定。因此缺省时此值为空
    LC_xxx 可设定locale各方面（category）的值，可以覆盖LANG的值。
    LANG 指定默认使用的locale值

可以把上述环境变量设在/etc/profile 或 /etc/environment等系统初始文件中。值得注意的是，若LANG或LC_ALL被设定为 "C"，那么LANGUAGE的值将被忽视。 [2]

除 C 和 POSIX这两个locale名称外，locale的名称并未标准化。Linux平台与Windows系统的locale名称有很大不同。Linux名称的命名规则为：

 language[_territory[.codeset]][@modifier]

其中language是ISO 639-1标准中定义的双字母的语言代码，territory是ISO 3166-1标准中定义的双字母的国家和地区代码，codeset是字符集的名称 (如 UTF-8等)，而 modifier 则是某些 locale 变体的修正符。

bash中的使用示例：

$ LC_TIME=en_US.UTF-8 date
Fri Oct 31 19:51:16 CST 2014
$ LC_TIME=fi_FI.UTF-8 date
pe 31.10.2014 19.52.00 +0800
$ LC_TIME=zh_CN.UTF-8 date
2014年 10月 31日 星期五 19:53:07 CST

相关系统文件：

    在文件/usr/share/i18n/SUPPORTED中，列出了当前系统支持的所有locale与字符集的名字。
    在目录/var/lib/locales/supported.d/下，列出了当前系统已经生成的所有locale的名字。
    在文件/var/lib/locales/supported.d/local中，列出了所有想要生成或已经生成的locale的名字
    在目录/usr/lib/locale/<locale_name>/LC_*，用locale-gen编译出的locale文件
    在文件/usr/lib/locale/locale-archive中，包含了很多本地已经生成的locale的具体内容，因此这个文件往往很大。使用命令localedef管理这一文件。使用locale-gen命令编译出来的locale内容默认写入该文件中。
    在文件/etc/default/locale中，可以手动配置locale环境变量，LC_CTYPE之类
    在目录/usr/share/i18n/charmaps下，缺省的charmap存放路径
    在目录/usr/share/i18n/locales下，缺省的locale source file存放路径

相关系统命令：

    locale 列出当前采用的各项本地策略，这些由LC_*环境变量定义
    locale charmap 列出系统当前使用的字符集
    locale -a 列出系统中已经安装的所有locale
    locale -m 列出系统中已经安装的所有charmap
    locale-gen --purge 将/usr/lib/locale/里面的locale支持文件删掉
    编辑文件/var/lib/locales/supported.d/local，增加需要的locale与字符集名字，如：

en_US.UTF-8 UTF-8
cs_CZ.UTF-8 UTF-8
cs_CZ.iso88592 iso88592
zh_CN.UTF-8 UTF-8
zh_CN.GBK GBK
zh_CN.GB2312 GB2312
zh_CN.GB18030 GB18030

保存并关闭此文件。运行sudo dpkg-reconfigure --force locales，则重新生成字符集。

    或者使用命令sudo locale-gen en_US.UTF-8，生成制定的locale en_US.UTF-8，并把这个locale名字加入文件/var/lib/locales/supported.d/local中
    或者使用命令sudo locale-gen，生成所有列在文件/var/lib/locales/supported.d/local中的locale
    或者

cd /usr/share/locales
sudo ./install-language-pack zh_CN

也可以安装zh_CN的相关语言包。

    或者使用命令localedef -f UTF-8 -i zh_CN zh_CN.UTF8，从字符映射文件UTF-8，locale源文件zh_CN，编译出locale称为zh_CN.UTF8，存放入文件/usr/lib/locale/locale-archive中
    使用命令localedef --list-archive，列出文件/usr/lib/locale/locale-archive中所有可用的locale的名字
    sudo apt-get install language-selector language-env language-pack-zh-hans language-pack-zh-hant 安装中文语言包


----

警告： 不推荐在 /etc/locale.conf 里把全局的 LANG locale 设置成中文 LANG=zh_CN.UTF-8，这会导致 tty 乱码。在 tty 下显示和输入中文需要安装 zhconAUR 或其他软件包。


# X config

.xinitrc：每次使用 startx 或 SLiM 来启动 X 窗口系统时会应用此处的设置。
.xprofile：每次使用 GDM 等显示管理器时会应用此处的设置。
.xsession

linked to one file.

export LANG=zh_CN.UTF-8
export LANGUAGE=zh_CN:en_US
警告： 若欲将此两行放至 ~/.xinitrc 中，请注意将其放在 exec _example_WM_or_DE_ 行之前


注意： 不推荐使用 export LC_ALL 来覆盖所有 locale 设置，LC_ALL 应该仅用于诊断调试，全局设置 LC_ALL 会为诊断语言设置问题带来不必要的困难。



这是因为每个程序中可以设置不同的默认字体，比如 Arial 或者 Tohamo，而这些字体的属性由 fontconfig 控制，其使用顺序是据地区代码以 A-Z 字母表顺序成默认排序，由于 ja-JP 在 zh_{CN,HK,SG,TW} 之前，故优先显示日文字形。



在 locale.conf 中添加 LANG=zh_CN.UTF-8，以将简体中文设置为默认语言。由于对 Locale 定义了框架内地区（即 CJK 优先度），使得默认的优先级被忽略。





<fontconfig>
  <alias>
    <family>sans-serif</family>
    <prefer>
      <family>Noto Sans CJK SC</family>
      <family>Noto Sans CJK TC</family>
      <family>Noto Sans CJK JP</family>
    </prefer>
  </alias>
  <alias>
    <family>monospace</family>
    <prefer>
      <family>Noto Sans Mono CJK SC</family>
      <family>Noto Sans Mono CJK TC</family>
      <family>Noto Sans Mono CJK JP</family>
    </prefer>
  </alias>
</fontconfig>


优先级，将中文字形调整到日文字形之前


<fontconfig>
  <alias>
    <family>sans-serif</family>
    <prefer>
      <family>Source Han Sans SC</family>
      <family>Source Han Sans TC</family>
      <family>Source Han Sans HW</family>
      <family>Source Han Sans K</family>
    </prefer>
  </alias>
  <alias>
    <family>monospace</family>
    <prefer>
      <family>Source Han Sans SC</family>
      <family>Source Han Sans TC</family>
      <family>Source Han Sans HW</family>
      <family>Source Han Sans K</family>
    </prefer>
  </alias>
</fontconfig>


# The C locale

## glibc 和应用程序、函数库库使用 区域设置 显示本地化的文字、货币、时间、日期、特殊字符等包含地域属性的内容。

区域设置的名称通常用 [language][_TERRITORY][.CODESET][@modifier] 的格式表示，language 是 ISO 639 语言代码, territory 是 ISO 3166 国家代码, codeset 是 字符集 或 ISO-8859-1、UTF-8 这样的编码方式。请参考 setlocale(3)。

要列出所有启用的区域设置，使用：

$ locale -a

    ~  locale -a                                                                                                                                                                                                                        ✔
C
en_HK.utf8
POSIX
zh_CN.utf8





可能其它文件设置了本该由 locale.conf 设置的区域设置（例如 ~/.pam_environment），详见 定义环境变量。

如果使用了桌面环境，可能是被桌面环境修改。例如 GNOME 的语言设置会覆盖 locale.conf 中的设置。






    ~  locale -a                                                                                               ✔
locale: Cannot set LC_CTYPE to default locale: No such file or directory
locale: Cannot set LC_MESSAGES to default locale: No such file or directory
locale: Cannot set LC_COLLATE to default locale: No such file or directory
C
POSIX
en_HK.utf8
en_US.utf8



locale-gen also runs with every update of glibc. [1]



    ~  localedef --list-archive                                                                                ✔
en_HK.utf8
en_US.utf8



                                                                                     ✔
    ~  localectl list-locales                                                                           ✔  3s 

en_HK.UTF-8
en_US.UTF-8


```
$ cat /etc/profile.d/locale.sh                                                                           ✔
```

```
#!/bin/sh

# load locale.conf in XDG paths.
# /etc/locale.conf loads and overrides by kernel command line is done by systemd
# But we override it here, see FS#56688
if [ -z "$LANG" ]; then
  if [ -n "$XDG_CONFIG_HOME" ] && [ -r "$XDG_CONFIG_HOME/locale.conf" ]; then
    . "$XDG_CONFIG_HOME/locale.conf"
  elif [ -n "$HOME" ] && [ -r "$HOME/.config/locale.conf" ]; then
    . "$HOME/.config/locale.conf"
  elif [ -r /etc/locale.conf ]; then
    . /etc/locale.conf
  fi
fi

# define default LANG to C if not already defined
LANG=${LANG:-C}

# export all locale (7) variables when they exist
export LANG LANGUAGE LC_CTYPE LC_NUMERIC LC_TIME LC_COLLATE LC_MONETARY \
       LC_MESSAGES LC_PAPER LC_NAME LC_ADDRESS LC_TELEPHONE LC_MEASUREMENT \
       LC_IDENTIFICATION
```

```
cat ~/.pam_environment                                                                                  ✔
# ~/.pam_environment
# read by the pam_env module for all logins, including both X11 and Wayland sessions.
# See pam_env(8) and pam_env.conf(5)

GTK_IM_MODULE DEFAULT=ibus
QT_IM_MODULE  DEFAULT=ibus
XMODIFIERS    DEFAULT=\@im=ibus

LANGUAGE=en_GB:en
LANG=en_GB.UTF-8
LC_NUMERIC=en_GB.UTF-8
LC_TIME=en_GB.UTF-8
LC_MONETARY=en_GB.UTF-8
LC_PAPER=en_GB.UTF-8
LC_NAME=en_GB.UTF-8
LC_ADDRESS=en_GB.UTF-8
LC_TELEPHONE=en_GB.UTF-8
LC_MEASUREMENT=en_GB.UTF-8
LC_IDENTIFICATION=en_GB.UTF-8
PAPERSIZE=a4

```

LC_ALL和LANG。它们之间有一个优先级的关系： LC_ALL>LC_>LANG 可以这么说，LC_ALL是最上级设定或者强制设定，而LANG是默认设定值。 1、如果你设定了LC_ALL＝zh_CN.UTF-8，那么不管LC_和LANG设定成什么值，它们都会被强制服从 LC_ALL的设定，成为 zh_CN.UTF-8。 2、假如你设定了LANG＝zh_CN.UTF-8，而其他的LC_=en_US.UTF-8，并且没有设定LC_ALL的话，那么系统的locale 设定以LC_=en_US.UTF-8。 3、假如你设定了LANG＝zh_CN.UTF-8，而其他的LC_，和LC_ALL均未设定的话，系统会将LC_设定成默认值，也就是LANG的值 zh_CN.UTF-8 。 4、假如你设定了 LANG＝zh_CN.UTF-8，而其他的LC_CTYPE=en_US.UTF-8，其他的LC_，和LC_ALL均未设定的话，那么系统的 locale设定将是：LC_CTYPE=en_US.UTF-8，其余的 LC_COLLATE，LC_MESSAGES等等均会采用默认值，也就是 LANG的值，也就是LC_COLLATE＝LC_MESSAGES＝……＝ LC_PAPER＝LANG＝zh_CN.UTF-8。

所以，locale是这样设定的： 1、如果你需要一个纯中文的系统的话，设定LC_ALL= zh_CN.XXXX，或者LANG= zh_CN.XXXX都可以，当然你可以两个都设定，但正如上面所讲，LC_ALL的值将覆盖所有其他的locale设定，不要作无用功。 2、如果你只想要一个可以输入中文的环境，而保持菜单、标题，系统信息等等为英文界面，那么只需要设定LC_CTYPE＝zh_CN.XXXX，LANG = en_US.XXXX就可以了。这样LC_CTYPE＝zh_CN.XXXX，而LC_COLLATE＝LC_MESSAGES＝……＝ LC_PAPER＝LANG＝en_US.XXXX。 3、假如你高兴的话，可以把12个LC_一一设定成你需要的值，打造一个古灵精怪的系统： LC_CTYPE＝zh_CN.GBK/GBK(使用中文编码内码GBK字符集)； LC_NUMERIC=en_GB.ISO-8859-1(使用大不列颠的数字系统) LC_MEASUREMEN=de_DE@euro.ISO-8859-15(德国的度量衡使用ISO-8859-15字符集) 罗马的地址书写方式，美国的纸张设定……。估计没人这么干吧。 4、假如你什么也不做的话，也就是LC_ALL，LANG和LC_均不指定特定值的话，系统将采用POSIX作为lcoale，也就是C locale。

```
$ cat /etc/profile.d/01-locale-fix.sh
# Make sure the locale variables are set to valid values.
eval $(/usr/bin/locale-check C.UTF-8)
```


```
/etc/init.d/cron:# there because it should be in /etc/default/locale.
/etc/init.d/cron:    for ENV_FILE in /etc/environment /etc/default/locale; do
/etc/init.d/cron:                 log_warning_msg "/etc/environment has been deprecated for locale information; use /etc/default/locale for $var=$value instead"
/etc/init.d/lightdm:if [ -r /etc/default/locale ]; then
/etc/init.d/lightdm:  . /etc/default/locale
/etc/pam.d/sshd:# /etc/default/locale, so read that as well.
/etc/pam.d/sshd:session    required     pam_env.so user_readenv=1 envfile=/etc/default/locale
/etc/pam.d/cron:session       required   pam_env.so envfile=/etc/default/locale
/etc/pam.d/lightdm-greeter:session      required pam_env.so readenv=1 envfile=/etc/default/locale
/etc/pam.d/polkit-1:session       required   pam_env.so readenv=1 envfile=/etc/default/locale user_readenv=0
/etc/pam.d/su:# locale variables are also kept into /etc/default/locale in etch
/etc/pam.d/su:session       required   pam_env.so readenv=1 envfile=/etc/default/locale
/etc/pam.d/login:# locale variables are also kept into /etc/default/locale in etch
/etc/pam.d/login:session       required   pam_env.so readenv=1 envfile=/etc/default/locale
/etc/pam.d/lightdm:session      required pam_env.so readenv=1 envfile=/etc/default/locale
/etc/pam.d/lightdm-autologin:session      required pam_env.so readenv=1 envfile=/etc/default/locale

```

`LANGUAGE` determines output in locale.

```
$ hello
Hello, world!

$ LANGUAGE=zh_CN hello
世界你好！


export LANGUAGE=zh_CN.UTF-8

$ locale
LANG=en_US.UTF-8
LANGUAGE=zh_CN.UTF-8
LC_CTYPE="en_US.UTF-8"
LC_NUMERIC="en_US.UTF-8"
LC_TIME="en_US.UTF-8"
LC_COLLATE="en_US.UTF-8"
LC_MONETARY="en_US.UTF-8"
LC_MESSAGES="en_US.UTF-8"
LC_PAPER="en_US.UTF-8"
LC_NAME="en_US.UTF-8"
LC_ADDRESS="en_US.UTF-8"
LC_TELEPHONE="en_US.UTF-8"
LC_MEASUREMENT="en_US.UTF-8"
LC_IDENTIFICATION="en_US.UTF-8"
LC_ALL=en_US.UTF-8

$ hello
世界你好！

```


字符库编码信息位于 /usr/share/i18n目录下面，其中SUPPORTED中包含可用的所用字符集，格式如下：
。。。
zh_HK BIG5-HKSCS
zh_SG.UTF-8 UTF-8
zh_SG.GBK GBK
zh_SG GB2312
zh_TW.EUC-TW EUC-TW
zh_TW.UTF-8 UTF-8
。。。。
其中的charmaps存的每种字符集的映射信息，可以称为最初文件（可能有术语，不管这么多啦）。使用localedef可以生成字符集，就是 locales里面那些东东。
但这些并不是系统中能用的字符集。刚才描述的这些/usr/share/i18n里面的文件只能算是可用的字符集，locale -m可以看到列表。
由于Linux中包含的字符集有几十种，而用户一般能用到的最多就是多种，没必要把所有字符集都集成到系统里。系统里面只使用部分字符集。另外为了让系统能使用，
原始的/usr/share/i18n中德文件要经过处理（complile），能用的字符编码在/usr/lib/locale/下面，成为complied字符集。
2。使用locale-gen可以把原始的/usr/share/i18n中的文件complie成系统能用的/usr/lib/locale/地字符集。locale-gen的参数是要使用的字符集列表，可在在终端下
制定。不然会自动在./var/lib/locales/supported.d/下寻找。编译产生的字符集可以两类方式存在: a.archive file: /usr/lib/locale/locale-archive b.分目录存储。详见man locale-gen
3. /usr/share/i18n里面的东西操作系统无关，不同体系结构不同系统可以通用，若有缺失，从其他地方复制来便可。


    /etc/default/locale
        LANG=”en_US.UTF-8″
        LANGUAGE=”en_US:en”

    $ locale-gen -en_US:en


    LANGUAGE=en_US
    LANG=en_US.UTF-8




# warning: setlocale: LC_ALL: cannot change locale (en_US.UTF-8)

    -bash: warning: setlocale: LC_ALL: cannot change locale (en_US.UTF-8)


    locale

    locale: Cannot set LC_CTYPE to default locale: No such file or directory
    locale: Cannot set LC_MESSAGES to default locale: No such file or directory
    locale: Cannot set LC_ALL to default locale: No such file or directory
    LANG=en_US.utf-8
    LANGUAGE=en_US.utf-8
    LC_CTYPE="en_US.UTF-8"
    LC_NUMERIC="en_US.UTF-8"
    LC_TIME="en_US.UTF-8"
    LC_COLLATE="en_US.UTF-8"
    LC_MONETARY="en_US.UTF-8"
    LC_MESSAGES="en_US.UTF-8"
    LC_PAPER="en_US.UTF-8"
    LC_NAME="en_US.UTF-8"
    LC_ADDRESS="en_US.UTF-8"
    LC_TELEPHONE="en_US.UTF-8"
    LC_MEASUREMENT="en_US.UTF-8"
    LC_IDENTIFICATION="en_US.UTF-8"
    LC_ALL=en_US.UTF-8


Solution

    dpkg-reconfig locales




#  busybox 添加字体与字符集

1.添加字体
    $ mkdir  -p  rootfs/usr/share/fonts/wqy       //在busybox 文件系统里创建目录存放wqy 字体
    $ cp /usr/share/fonts/misc/wenquanyi*  rootfs/usr/share/fonts/wqy
    //复制pc机系统里的字体到busybox 文件系统
    $ cp /etc/fonts/font.conf  rootfs/etc/fonts
    $ cp /etc/fonts/font.dtd rootfs/etc/fonts
    $ vim  rootfs/etc/fonts/font.conf


    /usr/share/fonts/zh_CN

    usr/share/fonts/wqy
          // 此处添加寻找字体的路径
    复制 mkfontscale mkfontdir fc-cache fc-list 命令及相应的库到 busybox 文件系统，以下的操作在运行busybox文件系统的板子上执行
    $ cd /usr/share/fonts/wqy
    $ mkfontscale      // 生成 fonts.alias 文件
    $ mkfontdir      //生成 fonts.dir  文件
    $ fc-cache -vf
    //更新字体缓冲 会在 /var/cache/fontconfig(由/etc/fonts/font.conf 指定生成缓存文件的存储路径) 下生成新字体缓冲文件
    $ fc-list       查看当前系统里拥有的字体

2.添加字符集
在linux 系统中安装 glibc 时便会安装 locale,localedef 命令，想要添加字体集得安装 locales 软件包
    $ cp /usr/bin/locale  rootfs/usr/bin
    $ cp /usr/sbin/localedef rootfs/usr/bin
    $ cp /usr/sbin/locale-gen rootfs/usr/sbin
    $ cp /etc/locale.alias  rootfs/etc/
    $ cp /etc/locale.gen rootfs/etc
    $ vi rootfs/etc/locale.gen
    找到你想要添加的字符集，去除前面的 "#"

    以下的操作在运行busybox文件系统的板子上执行
    $ locale-gen   //产生字符集 这里以 zh_CN.GBK 为例
    zh_CN.GBK character map file `zh_CN.GBK' not found: No such file or directory
    复制 /usr/share/i18n/charmaps/GBK.gz  到文件系统对应的目录

    zh_CN.GBK cannot open locale definition file 'zh_CN' no such file or directory
    原来是/usr/share/i18n/locales/文件夹下的zh_*都没有了，复制过来，再更新OK

    zh_CN.GBK cannot open locale definition file 'i18n' no such file or directory
    zh_CN.GBK cannot open locale definition file 'iso14651_t1_pinyin' no such file or directory
    zh_CN.GBK cannot open locale definition file 'iso14651_t1_common' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_neutral' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_combining' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_circle' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_cjk_compat' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_compat' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_font' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_fraction' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_narrow' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_small' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_wide' no such file or directory
    到/usr/share/i18n/locales/i18n 目录下复制对的文件 到文件系统对应的目录

    zh_CN.GBK cannot create temporary file : No such file or directory
    $ mkdir  -p /usr/lib/locale/     //locale-gen 执行成功之后会在此目录生成locale-archive 文件
    $ locale   //查看当前所设置的字符集
    locale: Cannot set LC_CTYPE to default locale: No such file or directory
    locale: Cannot set LC_MESSAGES to default locale: No such file or directory
    locale: Cannot set LC_ALL to default locale: No such file or directory
    LANG=zh_CN.UTF-8
    LC_CTYPE="zh_CN.UTF-8"
    LC_NUMERIC="zh_CN.UTF-8"
    LC_TIME="zh_CN.UTF-8"
    LC_COLLATE="zh_CN.UTF-8"
    LC_MONETARY="zh_CN.UTF-8"
    LC_MESSAGES="zh_CN.UTF-8"
    LC_PAPER="zh_CN.UTF-8"
    LC_NAME="zh_CN.UTF-8"
    LC_ADDRESS="zh_CN.UTF-8"
    LC_TELEPHONE="zh_CN.UTF-8"
    LC_MEASUREMENT="zh_CN.UTF-8"
    LC_IDENTIFICATION="zh_CN.UTF-8"
    LC_ALL=
出现在上面的提示，是因为在执行locale命令时，会根据所设置的$LANG, $LC_ALL环境变量去/usr/share/locale 目录下面找对应的语言包目录，这里由于没有 zh_CN.UTF-8 目录(没有安装zh_CN.UTF-8语言包)，所以会有以上提示,复制主机文件系统里 /usr/share/locale/zh_CN.UTF-8 到busybox 文件系统对应的目录就好了

    $ locale -a
    C
    POSIX
    zh_CN.gbk   //这是后添加的，busybox 默认只有支持 C，POSIX 字符集
    zh_CN.utf8






#    locale

    LANG=en_US.UTF-8
    LANGUAGE=en_US.UTF-8
    LC_CTYPE="en_US.UTF-8"
    LC_NUMERIC=zh_CN.UTF-8
    LC_TIME=zh_CN.UTF-8
    LC_COLLATE="en_US.UTF-8"
    LC_MONETARY=zh_CN.UTF-8
    LC_MESSAGES=en_US.UTF-8
    LC_PAPER=zh_CN.UTF-8
    LC_NAME=zh_CN.UTF-8
    LC_ADDRESS=zh_CN.UTF-8
    LC_TELEPHONE=zh_CN.UTF-8
    LC_MEASUREMENT=zh_CN.UTF-8
    LC_IDENTIFICATION=zh_CN.UTF-8
    LC_ALL=


thunderbird

firefox

launch from system menu, or launcher from Alt+F2,

system locale.


## File names mounting other FS

/dev/sdxx /media/win ntfs defaults,iocharset=utf8 0 0


## The minimal installation (with glibc-minimal-langpack) does not support the en_US.UTF-8 locale.

OpenSSH defaults to transfer that from the client.






/default/locale
#  File generated by update-locale
LANG="zh_CN.UTF-8"
LANGUAGE="zh_CN:zh"
LC_NUMERIC="zh_TW.UTF-8"
LC_TIME="zh_TW.UTF-8"
LC_MONETARY="zh_TW.UTF-8"
LC_PAPER="zh_TW.UTF-8"
LC_NAME="zh_TW.UTF-8"
LC_ADDRESS="zh_TW.UTF-8"
LC_TELEPHONE="zh_TW.UTF-8"
LC_MEASUREMENT="zh_TW.UTF-8"
LC_IDENTIFICATION="zh_TW.UTF-8"

# LANGUAGE="zh_CN:zh"
诸如
$ ll
总用量 52

$ sudo apt update
[sudo] aaron 的密码：
获取:1 http://10.10.50.12/debian jessie InRelease [2,417 B]
已下载 2,417 B，耗时 0秒 (18.9 kB/s)
正在读取软件包列表... 完成
正在分析软件包的依赖关系树
正在读取状态信息... 完成
所有软件包均为最新。

# LANG="zh_CN.UTF-8"

# locale.gen

/locale.alias:japanese      ja_JP.eucJP
/locale.alias:japanese.euc  ja_JP.eucJP
/locale.alias:ja_JP         ja_JP.eucJP
/locale.alias:ja_JP.ujis    ja_JP.eucJP
/locale.alias:japanese.sjis ja_JP.SJIS
/locale.gen:# ja_JP.EUC-JP EUC-JP
/locale.gen:# ja_JP.UTF-8 UTF-8



字符库编码信息位于 /usr/share/i18n目录下面，其中SUPPORTED中包含可用的所用字符集，格式如下：
。。。
zh_HK BIG5-HKSCS
zh_SG.UTF-8 UTF-8
zh_SG.GBK GBK
zh_SG GB2312
zh_TW.EUC-TW EUC-TW
zh_TW.UTF-8 UTF-8
。。。。
其中的charmaps存的每种字符集的映射信息，可以称为最初文件（可能有术语，不管这么多啦）。使用localedef可以生成字符集，就是 locales里面那些东东。
但这些并不是系统中能用的字符集。刚才描述的这些/usr/share/i18n里面的文件只能算是可用的字符集，locale -m可以看到列表。
由于Linux中包含的字符集有几十种，而用户一般能用到的最多就是多种，没必要把所有字符集都集成到系统里。系统里面只使用部分字符集。另外为了让系统能使用，
原始的/usr/share/i18n中德文件要经过处理（complile），能用的字符编码在/usr/lib/locale/下面，成为complied字符集。
2。使用locale-gen可以把原始的/usr/share/i18n中的文件complie成系统能用的/usr/lib/locale/地字符集。locale-gen的参数是要使用的字符集列表，可在在终端下
制定。不然会自动在./var/lib/locales/supported.d/下寻找。编译产生的字符集可以两类方式存在: a.archive file: /usr/lib/locale/locale-archive b.分目录存储。详见man locale-gen
3. /usr/share/i18n里面的东西操作系统无关，不同体系结构不同系统可以通用，若有缺失，从其他地方复制来便可。


    /etc/default/locale
        LANG=”en_US.UTF-8″
        LANGUAGE=”en_US:en”

    $ locale-gen -en_US:en


    LANGUAGE=en_US
    LANG=en_US.UTF-8




## warning: setlocale: LC_ALL: cannot change locale (en_US.UTF-8)

    -bash: warning: setlocale: LC_ALL: cannot change locale (en_US.UTF-8)


    locale

    locale: Cannot set LC_CTYPE to default locale: No such file or directory
    locale: Cannot set LC_MESSAGES to default locale: No such file or directory
    locale: Cannot set LC_ALL to default locale: No such file or directory
    LANG=en_US.utf-8
    LANGUAGE=en_US.utf-8
    LC_CTYPE="en_US.UTF-8"
    LC_NUMERIC="en_US.UTF-8"
    LC_TIME="en_US.UTF-8"
    LC_COLLATE="en_US.UTF-8"
    LC_MONETARY="en_US.UTF-8"
    LC_MESSAGES="en_US.UTF-8"
    LC_PAPER="en_US.UTF-8"
    LC_NAME="en_US.UTF-8"
    LC_ADDRESS="en_US.UTF-8"
    LC_TELEPHONE="en_US.UTF-8"
    LC_MEASUREMENT="en_US.UTF-8"
    LC_IDENTIFICATION="en_US.UTF-8"
    LC_ALL=en_US.UTF-8


Solution

    dpkg-reconfig locales




#  busybox 添加字体与字符集

1.添加字体
    $ mkdir  -p  rootfs/usr/share/fonts/wqy       //在busybox 文件系统里创建目录存放wqy 字体
    $ cp /usr/share/fonts/misc/wenquanyi*  rootfs/usr/share/fonts/wqy
    //复制pc机系统里的字体到busybox 文件系统
    $ cp /etc/fonts/font.conf  rootfs/etc/fonts
    $ cp /etc/fonts/font.dtd rootfs/etc/fonts
    $ vim  rootfs/etc/fonts/font.conf


    /usr/share/fonts/zh_CN

    usr/share/fonts/wqy
          // 此处添加寻找字体的路径
    复制 mkfontscale mkfontdir fc-cache fc-list 命令及相应的库到 busybox 文件系统，以下的操作在运行busybox文件系统的板子上执行
    $ cd /usr/share/fonts/wqy
    $ mkfontscale      // 生成 fonts.alias 文件
    $ mkfontdir      //生成 fonts.dir  文件
    $ fc-cache -vf
    //更新字体缓冲 会在 /var/cache/fontconfig(由/etc/fonts/font.conf 指定生成缓存文件的存储路径) 下生成新字体缓冲文件
    $ fc-list       查看当前系统里拥有的字体

2.添加字符集
在linux 系统中安装 glibc 时便会安装 locale,localedef 命令，想要添加字体集得安装 locales 软件包
    $ cp /usr/bin/locale  rootfs/usr/bin
    $ cp /usr/sbin/localedef rootfs/usr/bin
    $ cp /usr/sbin/locale-gen rootfs/usr/sbin
    $ cp /etc/locale.alias  rootfs/etc/
    $ cp /etc/locale.gen rootfs/etc
    $ vi rootfs/etc/locale.gen
    找到你想要添加的字符集，去除前面的 "#"

    以下的操作在运行busybox文件系统的板子上执行
    $ locale-gen   //产生字符集 这里以 zh_CN.GBK 为例
    zh_CN.GBK character map file `zh_CN.GBK' not found: No such file or directory
    复制 /usr/share/i18n/charmaps/GBK.gz  到文件系统对应的目录

    zh_CN.GBK cannot open locale definition file 'zh_CN' no such file or directory
    原来是/usr/share/i18n/locales/文件夹下的zh_*都没有了，复制过来，再更新OK

    zh_CN.GBK cannot open locale definition file 'i18n' no such file or directory
    zh_CN.GBK cannot open locale definition file 'iso14651_t1_pinyin' no such file or directory
    zh_CN.GBK cannot open locale definition file 'iso14651_t1_common' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_neutral' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_combining' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_circle' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_cjk_compat' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_compat' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_font' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_fraction' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_narrow' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_small' no such file or directory
    zh_CN.GBK cannot open locale definition file 'translit_wide' no such file or directory
    到/usr/share/i18n/locales/i18n 目录下复制对的文件 到文件系统对应的目录

    zh_CN.GBK cannot create temporary file : No such file or directory
    $ mkdir  -p /usr/lib/locale/     //locale-gen 执行成功之后会在此目录生成locale-archive 文件
    $ locale   //查看当前所设置的字符集
    locale: Cannot set LC_CTYPE to default locale: No such file or directory
    locale: Cannot set LC_MESSAGES to default locale: No such file or directory
    locale: Cannot set LC_ALL to default locale: No such file or directory
    LANG=zh_CN.UTF-8
    LC_CTYPE="zh_CN.UTF-8"
    LC_NUMERIC="zh_CN.UTF-8"
    LC_TIME="zh_CN.UTF-8"
    LC_COLLATE="zh_CN.UTF-8"
    LC_MONETARY="zh_CN.UTF-8"
    LC_MESSAGES="zh_CN.UTF-8"
    LC_PAPER="zh_CN.UTF-8"
    LC_NAME="zh_CN.UTF-8"
    LC_ADDRESS="zh_CN.UTF-8"
    LC_TELEPHONE="zh_CN.UTF-8"
    LC_MEASUREMENT="zh_CN.UTF-8"
    LC_IDENTIFICATION="zh_CN.UTF-8"
    LC_ALL=
出现在上面的提示，是因为在执行locale命令时，会根据所设置的$LANG, $LC_ALL环境变量去/usr/share/locale 目录下面找对应的语言包目录，这里由于没有 zh_CN.UTF-8 目录(没有安装zh_CN.UTF-8语言包)，所以会有以上提示,复制主机文件系统里 /usr/share/locale/zh_CN.UTF-8 到busybox 文件系统对应的目录就好了

    $ locale -a
    C
    POSIX
    zh_CN.gbk   //这是后添加的，busybox 默认只有支持 C，POSIX 字符集
    zh_CN.utf8






#    locale

    LANG=en_US.UTF-8
    LANGUAGE=en_US.UTF-8
    LC_CTYPE="en_US.UTF-8"
    LC_NUMERIC=zh_CN.UTF-8
    LC_TIME=zh_CN.UTF-8
    LC_COLLATE="en_US.UTF-8"
    LC_MONETARY=zh_CN.UTF-8
    LC_MESSAGES=en_US.UTF-8
    LC_PAPER=zh_CN.UTF-8
    LC_NAME=zh_CN.UTF-8
    LC_ADDRESS=zh_CN.UTF-8
    LC_TELEPHONE=zh_CN.UTF-8
    LC_MEASUREMENT=zh_CN.UTF-8
    LC_IDENTIFICATION=zh_CN.UTF-8
    LC_ALL=


## firefox

### launch from terminal, from system menu, or launcher from Alt+F2 run menu.

## system locale.

## 转到 zh_CN.UTF-8 的一些问题和解决方法

**0、支持 Unicode 的 Terminal 工具**

我选择 Terminal
工具的[原则](http://ihome.ust.hk/blogs/home/josephwu/GNU_slash_Linux/2006/03/23/Wanted-a-terminal-emulator-substitute.html)是：轻量（占用系统资源小）且强大。基于之前我的一个[简单评测](http//ihome.ust.hk/blogs/home/josephwu/GNU_slash_Linux/2006/03/24/Terminal-Emulator-Comparison.html)，我现在用的
Terminal 工具是
[rxvt-unicode](http://software.schmorp.de/pkg/rxvt-unicode.html) 加
[screen](http://www.gnu.org/software/screen/)。xterm 对 unicode
的支持可能是最差的，除此之外，mlterm、GNOME-terminal
等工具虽然都能很好的支持 unicode，不过 mlterm 的 multi tab
功能在我更习惯于使用"screen"来做 multi tab 这点上显得有点多余；而
gnome-terminal 则太过于耗资源。rxvt-unicode 则刚好合我的胃口，尤其是它的
server+client 的模式可以在开启多个 Terminal 的时候节省大量的系统资源。:)

**1、文件内容的编码检测及转换**

文件内容的编码转换可以结合 2 个工具来完成。

a.如果你不知道你所要转换的文件的编码格式，你可以通过
[enca](http://trific.ath.cx/software/enca/)
这个工具来检测编码。举例如下：

`joseph@PeT43: ~ > enca foo.txt`

`Universal transformation format 8 bits; UTF-8`

b.如果你事先已经知道了文件的编码或者通过检测知道了文件的编码，可以通过
GNU 的 [iconv](http://www.gnu.org/software/libiconv/)
来进行编码转换。以下是一个例子用来把文件的编码从 GB2312 转换成 UTF-8：

`joseph@PeT43: ~ > iconv -f gb2312 -t utf-8 foo.txt > foot.txt.utf-8`

提醒：iconv 的输出默认是直接输出到标准输出(standard
output)，通常就是你的屏幕上。所以，你需要使用">"的重定向符号来把输出转存到一个"新"的文件里面去。切不可在">"后面使用你的原始的输入文件名作为输出文件名，因为">"操作，会首先将其后面的文件清空，然后再运行
">"前面的操作。也就是说，除了原始的输入文件被清空之外，你什么也得不到。这是很多
Linux 新用户经常会犯的一个"致命"错误。特此提醒。

**2、文件名的编码转换**

上述的 2
个工具只能对文件的内容进行编码的检测和转换，如果需要对文件名进行编码转换，则需要
[convmv](http://j3e.de/linux/convmv/man/) 来完成。convmv 的用法大致和
iconv 相似，以下是一个例子用来将"music"这个目录下的所有以 GB2312
编码的文件名的文件和子目录下的文件，转换成以 UTF-8 编码的文件名：

`joseph@PeT43: ~ > convmv -f gb2312 -t utf-8 -notest -r music`

请注意这里的"-notest"选项：如果不提供这个选项，该命令只会做一个转换的测试，并不会真正的转换。因为这个命令有一定的"破坏性"，所以，当你用这个程序的时候，最好是先不用"-notest"这个选项来做一遍测试，根据程序运行输出的信息来确定是否有个别的文件需要手动进行调整。

**3、MP3 的 ID3 tag 编码转换**

一个比较扰人的问题是，MP3 里面的 ID3(v1/v2) Tag
信息不能象普通的文本文件那样来用 iconv 进行编码转换。好在这个问题 [Feng
Zhou](http://www.cs.berkeley.edu/~zf/) 也碰到了，他写了一个 java 的程序
[ID3iconv](http://www.cs.berkeley.edu/~zf/id3iconv/) 来处理这些 MP3
文件的 ID tag 编码转换。

略有不足的是，这个程序没有提供一个类似于上面提及的 convmv
的"-r"(recursive)的选项可以来对某一个目录下的所有文件和子目录下的文件进行递归的处理。当然，我们可以用万能的“find”命令来弥补这个缺陷，以下是一个例子，用来对"music"
目录里面的所有 mp3 文件（含子目录下的文件）进行 ID3 tag 的转换:

`joseph@PeT43: ~ > find . -name '*.mp3' -exec java -jar /usr/local/bin/id3iconv-0.2.1.jar -e gb2312 '{}' \;`

这个命令利用到了"find"命令的"-exec"选项来对所有找到的文件进行指定的操作，这里“指定的操作”就是对该文件调用
id3iconv 这个 java 的程序来进行 ID3 tag 的编码格式转换。详情请参考 find
的 manual (man find)。

**4、在 rxvt-unicode terminal 中实时改变 locale 设置**

我所碰到的一个比较扰人的问题是，虽然现在日常的操作多数是在 UTF-8 的
locale 下进行的，但是很多时候我又需要一个基于 GB2312 的 rxvt- unicode
来跑原来的一些实验。简单的在一个现有的 rxvt-unicode session
下通过"export LC\_CTYPE=zh\_CN.GB2312"其实并不奏效。因为那只是告诉你的
bash 程序，此后的 locale 变成了 zh\_CN.GB2312，而 rxvt-unicode
程序本身却依然工作在它启动时候的 zh\_CN.UTF-8 的 locale
下。所以，即使改变了 bash 的 locale 设置，但如果在该 rxvt-unicode 中用
cat 或者 more 这样的命令来查看一个以 zh\_CN.GB2312
的文件，依然看到是一堆乱码。

在这种情况下，一种不需要重新设置 X 系统的 locale，实时修改运行状态下的
rxvt-unicode 本身的 locale 设置的解决方案是使用 rxvt-unicode
内置的"escape sequence"来实现。

如下的 2 个命令组合，先更改 bash 的 locale 设置，然后通过"escape
sequence"通知 rxvt-unicode 程序，现在这个 session 的 locale
设置已经被改成了 zh\_CN.GB2312：

`joseph@PeT43: ~ > export LC_CTYPE=zh_CN.gb2312; printf "\33]701;$LC_CTYPE\007"`

这样，你就实时的得到一个 zh\_CN.GB2312 的环境，可以对 zh\_CN.GB2312
的文件进行正确的显式和操作了。

如果需要转回到 zh\_CN.UTF-8 的模式，则可以通过如下的命令来实现：

`joseph@PeT43: ~ > export LC_CTYPE=zh_CN.utf8; printf "\33]701;$LC_CTYPE\007"`

当然，每次敲这么长的命令挺烦人的，我用的方法是把上面的这 2
个命令集合分别存成 .bash.gb 和 .bash.utf-8 两个文件，放到我的 home
目录。

如果我需要实时得到一个 GB2312 的 rxvt-unicode session，我就运行：

`joseph@PeT43:  somewhere > source ~/.bash.gb`

如果我需要实时得到一个 UTF-8 的 rxvt-unicode session，我就运行：

`joseph@PeT43: somewhere > source  ~/.bash.utf-8`

这样就省却了很多敲键盘或者 copy/paste 的时间。:)

这个方法是从
[rxvt-unicode](http://software.schmorp.de/pkg/rxvt-unicode.html) 的
[FAQ](http://cvs.schmorp.de/rxvt-unicode/doc/rxvt.7.html)
中学来的。这个"701"的 escape sequence 是 rxvt-unicode 对 xterm 的 escape
sequence 的扩展，只在 rxvt-unicode 中有效。

[在 GNOME Terminal 里面可以通过菜单里面的"Terminal|Set Character
Encoding"来实时更改 locale。]

**5、VIM 配置文件的更新**

我是一个 VIMmer，以下是一些我在 UTF-8 环境下的 vim 的配置：

`set encoding=utf-8 " set default encoding as UTF-8`

`set fileencodings=ucs-bom,utf-8,cp936,latin1 " fileconding detection order`

`set termencoding=utf-8 " support Chinese display in rxvt-unicode`

**6、Misc**

以下是一些小技巧，简单罗列在下面。

a. 在做编码转换的时候，如果你的源格式设定为 GB2312 的话，而且在转换成
UTF-8 的时候，发现程序会报“illegal input sequence at position
xxxx"的错误。这是由于你之前的做的假定有问题。[GB2312](http://zh.wikipedia.org/wiki/GB_2312)
是国标里面一个最小也是最早的中文编码标准。其中，只涵盖了 6,763
个汉字。所以你需要转换的文件的原始的格式可能并不是 GB2312
编码。这个时候，你可以用 GB18030
做为源格式来进行转换。[GB18030](http://zh.wikipedia.org/wiki/GB_18030)
是最新的国家标准，包含了 27,564 个汉字，而且向下兼容 GB2312 和 GBK。

b.另外，支持 Unicode 且 Free
的中文字库我推荐使用"[文泉驿](http://wqy.sourceforge.net/cgi-bin/index.cgi)"。这好像也是目前为止，唯一的一个以支持
Unicode 为出发点的 Free 的中文字库。

**7、一些有用的参考：**

a. [Markus Kuhn](http://www.cl.cam.ac.uk/~mgk25/) 的"[UTF-8 and Unicode
FAQ for
Unix/Linux](http://www.cl.cam.ac.uk/~mgk25/unicode.html)"。最为详尽的
FAQ。

b. [Unicode Home Page](http://www.unicode.org/)。Unicode 的官方网站。

c. [A Quick Primer On Unicode and Software Internationalization Under
Linux and UNIX](http://eyegene.ophthy.med.umich.edu/unicode/)。 [Ed
Trager](mailto:ehtrager@umich.edu) 提供的一个关于如何在 Linux 下使用
Unicode 的 tutorial，涵盖了一些我没有提及的内容。推荐阅读。

[撰文/[Zhaojun](http://ihome.ust.hk/blogs/home/josephwu/)]

## C.UTF-8

There is a movement towards C.UTF-8 for small images (containers and
VMs). C.UTF-8 has both size and performance improvements over the more
traditional en_US.UTF-8 locale.

Notes on terminal and UTF-8

https://undeadly.org/cgi?action=article&sid=20160308204011

$ sudo locale-gen en_US en_US.UTF-8
/bin/bash: warning: setlocale: LC_ALL: cannot change locale (en_US.UTF-8)
Generating locales (this might take a while)...
  en_US.ISO-8859-1... done
  en_US.UTF-8... done
Generation complete.

