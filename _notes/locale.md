---
title: locale
date: 2018-12-06
---


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

