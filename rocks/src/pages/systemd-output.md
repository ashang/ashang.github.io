---
title: "Systemd Output"
date: 2021-06-15T13:10:56+08:00
Categories: ""
---

easy way to print a prompt message when start/stop a service with systemd.


```
$ systemctl stop snmpd
Failed to allocate directory watch: Too many open files
```

sysctl fs.inotify.max_user_instances  # 最大用户实例数
sysctl fs.inotify.max_user_watches    # 单个用户可监控的文件/目录数

#### **临时提高限制**（重启失效）：

bash

复制

sudo sysctl -w fs.inotify.max_user_instances=1024
sudo sysctl -w fs.inotify.max_user_watches=1048576

#### **永久修改限制**：

编辑 `/etc/sysctl.conf`，添加以下行：

ini

复制

fs.inotify.max_user_instances = 1024
fs.inotify.max_user_watches = 1048576

保存后执行：

bash

复制

sudo sysctl -p  # 重新加载配置

-----

### **检查文件描述符限制**

系统或用户的文件描述符（FD）限制过低可能导致资源耗尽。

#### **查看当前限制**：

bash

复制

ulimit -n        # 当前用户的 FD 限制
cat /proc/sys/fs/file-max  # 系统全局 FD 限制

#### **永久提高用户限制**：

编辑 `/etc/security/limits.conf`，添加：

ini

复制

* soft nofile 65535
* hard nofile 65535



#### **查找占用 inotify 的进程**：

bash

复制

sudo lsof | grep inotify | awk '{print $1}' | sort | uniq -c | sort -nr

#### **查找打开文件数最多的进程**：


```bash
$ sudo lsof | awk '{print $1}' | sort | uniq -c | sort -nr | head

 237708 container
  65478 dockerd
  19075 bash
  17544 su
   3126 sshd
    481 nscd
    448 systemd
    330 memcached
    294 (sd-pam)
    270 ssh

$ sudo lsof | grep inotify | awk '{print $1}' | sort | uniq -c | sort -nr
   1462 container
     27 systemd
     13 nscd
      1 systemd-u
      1 systemd-l
      1 dbus-daem
      1 agetty

```

### **检查 systemd 服务配置**

确保 `snmpd` 的 systemd 单元文件未限制资源。检查 `/etc/systemd/system/snmpd.service` 或 `/lib/systemd/system/snmpd.service`，确认是否存在以下配置：

ini

复制

[Service]
LimitNOFILE=65535  # 确保未限制文件描述符

修改后执行：

bash

复制

sudo systemctl daemon-reload


watch -n 1 "cat /proc/sys/fs/inotify/max_user_watches && cat /proc/sys/fs/inotify/max_user_instances"



fs.file-max = 200000
fs.inotify.max_user_instances = 1024
fs.inotify.max_user_watches=5242880


```bash
# 临时生效（仅当前终端会话有效）
ulimit -n 65535

# 所有网络服务的最大并发连接队列长度（直接影响TCP连接数上限）
sudo sysctl -w net.core.somaxconn=65535
# FD
sudo sysctl -w fs.file-max=65535
```


#### 修改用户限制（`/etc/security/limits.conf`）

conf

```conf
# 添加以下行（根据需要调整数值）
* soft nofile 65535
* hard nofile 65535
snmpd soft nofile 65535
snmpd hard nofile 65535
```

```conf
# /etc/snmp/snmpd.conf
listen-address 127.0.0.1       # 本地回环地址
# 注释掉不必要的监听地址
```

