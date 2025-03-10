
systemd 中，shutdown, halt, poweroff, reboot 都是指向 systemctl 的链接。

```
lrwxrwxrwx 1 root root 14 Feb 22 07:10 /sbin/shutdown -> /bin/systemctl
lrwxrwxrwx 1 root root 14 Feb 22 07:10 /sbin/reboot -> /bin/systemctl
lrwxrwxrwx 1 root root 14 Feb 22 07:10 /sbin/poweroff -> /bin/systemctl
lrwxrwxrwx 1 root root 14 Feb 22 07:10 /sbin/halt -> /bin/systemctl
```

其中，shutdown指令与另外三个不同，halt, poweroff, reboot 的 systemd 实现尽量与SysV对应的halt, poweroff, reboot命令兼容，增加了额外的功能。

# 4个指令不带参数的默认行为

`reboot` 与 `shutdown -r` 是等价的。

`halt` ` 与 `shutdown -H` 是等价的。

`poweroff` 与 `shutdown -h/-P` 是等价的。

`shutdown` 默认的行为即 `poweroff`。

# shutdown

注意如果想看help的话，不要`shutdown -h`，那样是poweroff。

`shutdown` 的第一个参数可以是一个时间值，格式可以是`hh:mm`，以24小时制，也可以是 `+m` 的形式，指定以分钟为单位的即时。`now` 等价于 `+0` 。默认是 `+1` 。

如果要以`-k` 参数发送wall信息，必须指定时间值。如果指定了时间，则在此时间前的5分钟内，`/run/nologin` 文件会被创建，以阻止新的登录。

主要参数

    -H --halt      Halt the machine
    -r --reboot    Reboot the machine
    -P, --poweroff Power-off the machine (the default).
    -h
        Equivalent to --poweroff, unless --halt is specified.

如果参数同时包含 `-h` 和 `--halt` ，则执行halt动作，不poweroff。

# `halt`, `reboot`, `poweroff`

主要参数

    -p, --poweroff
    --reboot

    -n, --no-sync
        Don't sync hard disks/storage media before halt, power-off, reboot.
    这个可以增加执行的速度，因为慢速的设备上大量的写数据的sync耗费不少时间。

    -f, --force
    在执行 halt, poweroff, reboot,  kexec 的时候，如果指定参数 `-f` , 那么不会停止其他unit，但所有进程会被强制kill，文件系统被卸载或挂为只读，如果 `-ff` ，那么halt、poweroff、reboot都立即执行，不会通知kill任何进程或卸载文件系统。
    如果使用 `-ff` ，那么 systemctl 不会与 system manager 通信。

    halt
        Shut down and halt the system. This is mostly equivalent to systemctl start halt.target --job-mode=replace-irreversibly --no-block, but also prints a wall message to all users. This command is asynchronous; it will return after the halt operation is enqueued,
        without waiting for it to complete. Note that this operation will simply halt the OS kernel after shutting down, leaving the hardware powered on. Use systemctl poweroff for powering off the system (see below).

        If combined with --force, shutdown of all running services is skipped, however all processes are killed and all file systems are unmounted or mounted read-only, immediately followed by the system halt. If --force is specified twice, the operation is immediately
        executed without terminating any processes or unmounting any file systems. This may result in data loss. Note that when --force is specified twice the halt operation is executed by systemctl itself, and the system manager is not contacted. This means the command
        should succeed even when the system manager has crashed.

    poweroff
        Shut down and power-off the system. This is mostly equivalent to systemctl start poweroff.target --job-mode=replace-irreversibly --no-block, but also prints a wall message to all users. This command is asynchronous; it will return after the power-off operation is
        enqueued, without waiting for it to complete.

        If combined with --force, shutdown of all running services is skipped, however all processes are killed and all file systems are unmounted or mounted read-only, immediately followed by the powering off. If --force is specified twice, the operation is immediately
        executed without terminating any processes or unmounting any file systems. This may result in data loss. Note that when --force is specified twice the power-off operation is executed by systemctl itself, and the system manager is not contacted. This means the
        command should succeed even when the system manager has crashed.

    reboot [arg]
        Shut down and reboot the system. This is mostly equivalent to systemctl start reboot.target --job-mode=replace-irreversibly --no-block, but also prints a wall message to all users. This command is asynchronous; it will return after the reboot operation is
        enqueued, without waiting for it to complete.

        If combined with --force, shutdown of all running services is skipped, however all processes are killed and all file systems are unmounted or mounted read-only, immediately followed by the reboot. If --force is specified twice, the operation is immediately
        executed without terminating any processes or unmounting any file systems. This may result in data loss. Note that when --force is specified twice the reboot operation is executed by systemctl itself, and the system manager is not contacted. This means the command
        should succeed even when the system manager has crashed.

        If the optional argument arg is given, it will be passed as the optional argument to the reboot(2) system call. The value is architecture and firmware specific. As an example, "recovery" might be used to trigger system recovery, and "fota" might be used to trigger
        a “firmware over the air” update.

    kexec
        Shut down and reboot the system via kexec. This is equivalent to systemctl start kexec.target --job-mode=replace-irreversibly --no-block. This command is asynchronous; it will return after the reboot operation is enqueued, without waiting for it to complete.

        If combined with --force, shutdown of all running services is skipped, however all processes are killed and all file systems are unmounted or mounted read-only, immediately followed by the reboot.

以上参考 `systemd 241` 的手册。

```
# halt -r
halt: invalid option -- 'r'

# halt -P
halt: invalid option -- 'P'

# shutdown -p
shutdown: invalid option -- 'p'
```

更多内容参见 `man systemctl` 。

