---
tile: wtmpdb / lastlog2 / lastlog / lastb
---

`wtmpdb` is a modern Linux utility designed to track system login, logout, and boot histories while completely replacing the traditional Unix `last` command.

Its primary purpose is to solve the Year 2038 problem (Y2038). Older Linux systems track login histories using a legacy file format (`wtmp`) that stores time using a 32-bit integer. On January 19, 2038, those 32-bit systems will run out of space to count time and break. `wtmpdb` avoids this crash entirely by using a modern 64-bit architecture.

`wtmpdb` is a Year 2038 (Y2038) safe replacement for the traditional Unix `wtmp` log file system, used to record and display system logins, logouts, and reboot history. Written primarily by Thorsten Kukuk, it replaces the legacy flat-file logging formats with a modern `SQLite3` database architecture (`/var/log/wtmp.db`) to handle time values properly past January 19, 2038.

Many major Linux distributions—including Debian, Ubuntu, and openSUSE—have transitioned to or included wtmpdb as their default platform logging standard.

## Core Architecture and Components

The wtmpdb framework functions as a multi-tier package:

- pam_wtmpdb.so: A Pluggable Authentication Module (PAM) that intercepts user session logins and logouts to commit them straight to the database.

- libwtmpdb.so: The underlying software library that applications or daemons use to interact programmatically with login/logout data.

- wtmpdb (CLI): The user-facing command-line tool utilized to read logs, script boot entries, or rotate databases.

- wtmpdbd: An optional background daemon used to securely gate write access to the SQLite database via `sd-varlink` so that only privileged processes can modify records.

## Key Command Line Tools & Syntax

The interface is designed to closely match the behavior of the traditional last utility.

### Display Login History

```bash
$ wtmpdb last
```

Displays a list of all logged-in and logged-out users, similar to running the legacy last command.

### Log System Boot/Shutdown Events

```bash
$ wtmpdb boot

$ wtmpdb shutdown
```

Typically executed by system scripts or systemd units at startup and power-off.

### Log Database Rotation

```bash
$ wtmpdb rotate --days 60
```

Exports entries older than a specified duration into a timestamped database file to manage file size.

Import Legacy Data:

```bash
$ wtmpdb import /var/log/wtmp
```

Migrates historical data from the old binary flat-file format into the modern SQLite structure.

## Query Modifiers for Analysis

The `wtmpdb last` command supports specialized flags to query historical user behavior effectively:

- -f, --file [FILE]: Point to an archived database file instead of the system live default.

- -n, --limit [NUMBER]: Cap output to the first N entries.-s, --since [TIME] / -u, --until [TIME]: Filter session visibility to narrow windows of time.

- --format [iso|full|short]: Customize timestamp reporting format rules.

## How It Works

- Database Backend: Instead of a raw, fragile binary log file, it uses an SQLite3 database (/var/lib/wtmpdb/wtmp.db or /var/log/wtmp.db) to record all events.

- PAM Module Integration: It collects login data automatically through a Pluggable Authentication Module (pam_wtmpdb.so). 
  - Every time a user logs in via SSH, desktop, or terminal, the system updates the database smoothly.

- Secure Access: It includes an optional background service (wtmpdbd) that relies on secure Unix sockets so only system administrators (root) can tamper with the logs.

- Common Commands
  - If your Linux distribution (like Debian Trixie, openSUSE, or Ubuntu) uses wtmpdb, you will typically use these basic commands:
  
  ```bash
  
  # Displays a list of all users who logged in and out (replaces the 'last' command)

  wtmpdb last

  # Displays system shutdown entries
  wtmpdb last --shutdown

  # Displays full dates and times for log entries
  wtmpdb last --full
  ```

将传统的旧版本 wtmp（32位二进制日志）完全替换为新一代的 wtmpdb（64位 SQLite3 数据库），主要需要完成数据迁移、系统服务接管、PAM认证配置以及命令替代。

迁移工作清单和操作步骤

1. 迁移历史数据旧的 /var/log/wtmp 记录了系统过去的登录历史，不能直接丢弃。需要将旧的二进制数据导入到新的数据库中。执行导入命令：使用 wtmpdb 自带的导入功能。

```bash
wtmpdb import /var/log/wtmp
```

该命令会自动读取旧文件，并将历史记录安全地写入到新的 /var/lib/wtmpdb/wtmp.db 中。

2. 配置 PAM 模块（让新登录写入数据库）wtmpdb 依赖 Pluggable Authentication Modules（PAM）来捕获用户的登录和登出事件。修改公共会话配置文件：在 /etc/pam.d/postlogin-session（通常适用于 openSUSE/SUSE）或 /etc/pam.d/common-session（通常适用于 Debian/Ubuntu）文件中增加以下内容：

    textsession optional pam_wtmpdb.so

特殊处理 OpenSSH（针对部分系统）：若 SSH 登录无法正确识别控制台终端（TTY），需要在 /etc/pam.d/sshd 中屏蔽该模块，或在公共配置中通过参数跳过：

```text
session optional pam_wtmpdb.so skip_if=sshd
```

3. 接管系统启动与关机事件

传统的 wtmp 由内核或 sysvinit/systemd 直接写入启动和关机标志，而 wtmpdb 需要通过独立的 systemd 服务来跟踪开关机状态。启动并启用开关机服务：

```bash
systemctl enable --now wtmpdb-update-boot.service
```

启用定期清理/轮转服务（防止数据库无限变大）：

```bash
systemctl enable --now wtmpdb-rotate.timer
```
4. 替换传统的 last 工具

新版 Linux 发行版（如 Debian Trixie 或较新的 openSUSE）中，原先由 util-linux 提供的老版本 last 命令可能已被移除或不再默认安装。

创建软链接（Symlink）：让用户的 last 命令无感切换到新工具。

```bash
# 如果老版本 last 还在，先重命名备份
mv /usr/bin/last /usr/bin/last.legacy

# 创建软链接指向 wtmpdb
ln -s /usr/bin/wtmpdb /usr/bin/last
```

由于 wtmpdb 的底层逻辑做了兼容设计，当它发现自己被以 last 的名字调用时，会自动执行 wtmpdb last 的行为。

⚠️ 迁移注意事项与后续工作

新旧并存期：在刚安装并配置好 wtmpdb 的一段时间内，部分不通过 PAM 认证的古老软件（例如使用 libutempter 的某些终端模拟器）可能依然会尝试写入 /var/log/wtmp。此时两个文件会并存更新。在确认所有核心服务都正常走 PAM 写入后，方可停止旧的日志维护并彻底删除旧文件。

审计与监控：如果有自研的运维脚本、安全审计工具曾直接读取 /var/log/wtmp 二进制文件，必须全部重写为通过 wtmpdb last 命令输出，或直接通过 sqlite3 命令行工具来读取 /var/lib/wtmpdb/wtmp.db。

传统的 Linux 架构中，写入 /var/log/wtmp 是一个分布式、各自为政的过程。不同程序通过直接调用 C 语言标准库中的 pututline() 或 updwtmp() 函数，直接向二进制文件里追加数据：

- 本地登录（控制台）：由 login 程序（util-linux 软件包的一部分）直接写入。
- 远程登录（SSH）：由 sshd 守护进程在用户认证成功、准备分配伪终端（PTY）时，自己编写代码直接写入 wtmp。
- 图形界面登录（GDM/LightDM）：由显示管理器（Display Manager）自己负责写入。
- 系统启动与关机：由 init（如早期的 SysVinit）或后来的 systemd 在系统引导和关闭时，直接向文件写入特殊的 BOOT_TIME 或 RUN_LEVEL 标记。
- 终端模拟器（Xterm/Screen）：通过辅助程序（如 libutempter）来安全地写入用户开启和关闭标签页的记录。

由于历史原因，上面提到的各种程序（sshd, gdm, systemd, login）内部用于读写旧 wtmp 的数据结构全部是固定的 32 位时间戳结构（struct utmp）。

如果要彻底解决 2038 年问题，原本需要把整个 Linux 生态里所有涉及登录的独立开源软件全部修改并重新编译，这几乎是不可能完成的任务。为了打破这个僵局，开源社区采用了 wtmpdb 的新方案：
- 统一入口： 不再去动 sshd 或 gdm 的原生代码。
- 利用 PAM 拦截： 因为几乎所有登录程序都会调用 PAM 来管理会话（Session），所以直接开发一个 pam_wtmpdb.so 模块。
- 数据库接管： 当任何程序通过 PAM 启动或结束用户会话时，pam_wtmpdb.so 就会自动被触发，直接把 64 位的高精度时间戳写入 SQLite3 数据库。

以前是各个登录软件自己直接写文件；而现在是通过 wtmpdb，把记录日志的权力统一收归到了 PAM 模块和 systemd 服务中。

## lastlog

除了时间戳溢出外，原先的 lastlog 还有一个极其糟糕的稀疏文件（Sparse File）设计问题：
- 旧的 lastlog 是根据用户的 UID（用户ID） 作为文件偏移量来存数据的。如果系统对接了 LDAP、Windows 域控或者使用了容器集群，某些用户的 UID 可能会非常大（例如 UID=2000000000）。这会导致 /var/log/lastlog 文件在磁盘上的名义大小膨胀到几百 GB 甚至数 TB！虽然它不占用实际磁盘空间，但在进行系统备份、拷贝或使用某些不支持稀疏文件的工具时，会导致磁盘瞬间被塞满或引发严重错误。
- lastlog2 改用 SQLite3 数据库，彻底解决了这个问题。数据库的大小只取决于系统中实际存在多少个用户，而与 UID 的大小完全无关。

## Migration

1. 将旧的最后登录数据导入到新的 SQLite 数据库中：

```bash
lastlog2 --import /var/log/lastlog
```

2. 配置 PAM 模块（启用 pam_lastlog2）

与 wtmpdb 类似，lastlog2 的数据也完全收归到 PAM 管理。需要在 session 阶段配置新的模块。在 /etc/pam.d/common-session 或对应的登录配置文件中，注释掉旧的 pam_lastlog.so（如果有的话），并增加新的模块：

```text
# 移除或注释旧模块
# session optional pam_lastlog.so silent

# 启用新模块（通常建议设为 optional，防止数据库锁死导致无法登录）
session optional pam_lastlog2.so
```

3. 使用新命令

现代系统上，当你输入 lastlog 时，系统通常已经通过软链接（Symlink）自动将其指向了 lastlog2。

查看所有用户最后登录：直接输入 lastlog 或 lastlog2。

新增的 -s 参数：

    lastlog2 -s

可以额外显示用户登录时使用的是哪个 PAM 服务（是通过 sshd 还是 gdm 登录的）。

## 避坑

- 老脚本失效：如果原先有自动化运维脚本是通过二进制读取 /var/log/lastlog 来审计僵尸账号的，这些脚本在升级后必须重写，改为解析 lastlog2 的输出，或者直接用 sqlite3 软连接读取 /var/lib/lastlog/lastlog2.db。
- lastb 消失：传统用于查看“登录失败记录”的 lastb 命令（读取 /var/log/btmp），在最新的 wtmpdb / lastlog2 体系中没有直接的完全对应替代品。现代 Linux 倾向于直接去 `journalctl -u ssh` 或系统的安全日志（/var/log/auth.log）中查看暴力破解和失败记录。