---
title: locale
date: 2018-12-06
--- 

# The C locale

#

glibc 和应用程序、函数库库使用 区域设置 显示本地化的文字、货币、时间、日期、特殊字符等包含地域属性的内容。

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
