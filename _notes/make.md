
```
make VERBOSE=1 xconfig
...
  CHECK   qt
*
* Could not find Qt via pkg-config.
* Please install either Qt 4.8 or 5.x. and make sure it's in PKG_CONFIG_PATH
*
make[1]: *** No rule to make target 'scripts/kconfig/.tmp_qtcheck', needed by 'scripts/kconfig/qconf.o'.  Stop.
make: *** [Makefile:531: xconfig] Error 2
...
```

```
$ sudo apt-get install qttools5-dev
```



install -Dm6755 target/release/subsystemctl "${pkgdir}/usr/bin/subsystemctl"
~
~


# https://github.com/yychuyu/Cgames

# c-w c
#
# 设定 clone 深度
#
# Linux 从 v2.6.12 开始使用 Git 管理，到如今的 v5.2.2，经历过这么多年这么多版本，其变更记录本身巨大。如果对历史修改记录不是特别关心，可以通过 --depth 限定只获取部分修改记录，从而可以大幅减少 Git 仓库大小。
#
# 仅 clone 指定分支
#
# Git 1.7.10 及之后版本，使用 -b branch --single-branch 将只下载指定分支，对于有多个分支，而且差异很大的仓库而言，这个方法同样会节省大量下载时间。
#
# 通过 git init + git fetch 实现断点续传
#
# clone 不支持断点续传，对于大型的仓库，一旦出现网络故障，所有下载将全功尽弃，令人无比沮丧。所以，建议用 git init 先初始化一个空的仓库，然后用 git fetch 下载指定分支。这个即使网络中断，也是可以续传的。
#
#
#
#
# 切换窗口会成为一个麻烦，请在 ~/.vimrc 添加一个映射，用 Ctrl + Home/end 来做切换。
#
    # $ cat ~/.vimrc
        # :noremap <c-Right> <c-w>w
	    # :noremap <c-Left> <c-w>p
#
#
    # Ctrl + Shift + Right/Left/Up/Down：四个方向调整窗口大小
        # Ctrl + Shift + F：在当前窗口搜索字符串
	    # Ctrl + Shift + X：最大化当前窗口
	        # Ctrl + Shift + Z：切换显示所有窗口 or 仅显示当前窗口
#
# 3 tmux 分屏
#
# tmux 是另外一款分屏工具，有很多粉丝。
#
# 新建屏幕
#
    # 上下分屏：Ctrl + b, " (按 Shift + " 所在按键，很奇葩的设计，得按两次）
        # 左右分屏：Ctrl + b, % (按 Shift + % 所在按键）
#
# 关闭屏幕
#
    # Ctrl + b, x
#
# 切换屏幕
#
    # Ctrl + b, o
        # Ctrl + b, 空格：上下分屏与左右分屏切换
#
#
# $ git clone https://github.com/jthistle/SUDO.git

#
say_hello:
	@echo "Hello World"

SOURCE = $(wildcard *.c)

TARGETS = $(patsubst %.c, %, ${SOURCE})

CC = gcc
CFLAGS = -Wall -g

all:${TARGETS}

${TARGETS}:%:%.c
	${CC} $< ${CFLAGS} -o $@

.PHONY: clean all
clean:
	-rm -rf ${TARGETS}

