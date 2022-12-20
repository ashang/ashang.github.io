---
title: timesyncd
layout: post
tags: [timesyncd]
date: 2022-12-19
---

## Sync time using ntp

timedatectl set-ntp true
timedatectl status

Proposal: remove ntp/ntpdate, use systemd built-in timesyncd

Change to use modern, graceful way to sync time.

This plan is related to current NTP issue, but it had been discussed for
a long time.

It is just for future plan, perhaps in future minor releases, such as 4.2.0, or 4.3.0.

## Why the change

NTP had been responsible for most of the largest ever scale of DDoS.

Also in our Bugzilla db, there had been a dozen of issues related to NTP.

At first, we use `ntpdate` as a client to sync time with NTP servers.
That needs a cron task to help run it regularly.

At some point, with no clear reason, we added `ntpd` server into rootfs,
using its service mode to sync time, without using its server function.

We had been using systemd as PID 1 from Debian 8.
Systemd has a built-in time syncing service `timesyncd`, which can sync time
as a daemon. It is very light at runtime, as very tiny, built-in.

## What it is like

Although it is built-in, the service won't start if it detect the existence of often used time daemons.

    admin@Xorplus:~$ cat /lib/systemd/system/systemd-timesyncd.service.d/disable-with-time-daemon.conf
    [Unit]
    # don't run timesyncd if we have another NTP daemon installed
    ConditionFileIsExecutable=!/usr/sbin/ntpd
    ConditionFileIsExecutable=!/usr/sbin/openntpd
    ConditionFileIsExecutable=!/usr/sbin/chronyd
    ConditionFileIsExecutable=!/usr/sbin/VBoxService

After we removed ntp, it will run and keep time sync.

    admin@Xorplus:~$ sudo apt autoremove --purge ntp
    admin@Xorplus:~$ systemctl daemon-reload
    admin@Xorplus:~$ sudo systemctl restart systemd-timesyncd
    admin@Xorplus:~$ sudo systemctl status systemd-timesyncd
    * systemd-timesyncd.service - Network Time Synchronization
       Loaded: loaded (/lib/systemd/system/systemd-timesyncd.service; enabled; vendor preset: enabled)
      Drop-In: /lib/systemd/system/systemd-timesyncd.service.d
               `-disable-with-time-daemon.conf
       Active: active (running) since Tue 2021-07-20 09:39:31 UTC; 42s ago
         Docs: man:systemd-timesyncd.service(8)
     Main PID: 2295 (systemd-timesyn)
       Status: "Synchronized to time server for the first time 134.76.249.102:123 (0.debian.pool.ntp.org)."
        Tasks: 2 (limit: 4915)
       Memory: 1.6M
       CGroup: /system.slice/systemd-timesyncd.service
               `-2295 /lib/systemd/systemd-timesyncd

    Jul 20 09:39:36 Xorplus systemd-timesyncd[2295]: Synchronized to time server for the first time 134.76.24

The output is nice.

To check system time status.

    admin@Xorplus:~$ timedatectl status
                   Local time: Tue 2021-07-20 10:10:10 UTC
               Universal time: Tue 2021-07-20 10:10:10 UTC
                     RTC time: Tue 2021-07-20 10:10:10
                    Time zone: UTC (UTC, +0000)
    System clock synchronized: yes
                  NTP service: active
              RTC in local TZ: no

Or if you want to have output message as what the `ntpq -p` had been showing as below.

    admin@Xorplus:~$ timedatectl timesync-status
           Server: 80.249.145.122 (0.debian.pool.ntp.org)
    Poll interval: 8min 32s (min: 32s; max 34min 8s)
             Leap: normal
          Version: 4
          Stratum: 2
        Reference: 596DFB18
        Precision: 1us (-23)
    Root distance: 38.803ms (max: 5s)
           Offset: -5.086ms
            Delay: 273.384ms
           Jitter: 10month 2w 1d 13h 28min 23.169258s
     Packet count: 17
        Frequency: -0.870ppm

To toggle ntp service on/off, start/stop.

    admin@Xorplus:~$ timedatectl set-ntp true
    admin@Xorplus:~$ timedatectl set-ntp false

Thus we can remove scripts we had maintained to operate ntp services.

Actually we had used that for current timezone processing from release 3.x.

## What next

Do very little change to keep almost same input/output as before.

The CLI can keep unchanged.

Remove ntp/ntpdate, to save 3MB rootfs.

    sudo apt autoremove --purge ntp
    sudo apt autoremove --purge ntpdate

## Others

If we want to provide NTP service outside, just forget the above.
It's better to keep using existing setup, although there had been
other NTP implementations besides this old official one.

## Reference
- Time daemons
  - https://chrony.tuxfamily.org/comparison.html
- timedatectl
    - https://man7.org/linux/man-pages/man1/timedatectl.1.html
- timesyncd.service
    - https://man7.org/linux/man-pages/man8/systemd-timesyncd.service.8.html
- A command called hwclock can set them accordingly by --hctosys/--systohc
  - https://man7.org/linux/man-pages/man8/hwclock.8.html





dbus: [system] Failed to activate service 'org.freedesktop.login1': timed out


/etc/group-:ntp:x:103:
/etc/shadow-:ntp:*:17344:0:99999:7:::
/etc/systemd/timesyncd.conf:#FallbackNTP=0.debian.pool.ntp.org 1.debian.pool.ntp.org 2.debian.pool.ntp.org 3.debian.pool.ntp.org
/etc/gshadow-:ntp:!::
/etc/ssl/certs/ca-certificates.crt:MIIFwzCCA6ugAwIBAgIUCn6m30tEntpqJIWe5rgV0xZ/u7EwDQYJKoZIhvcNAQEL
/etc/services:nntp              119/tcp         readnews untp   # USENET News Transfer Protocol
/etc/services:ntp               123/udp                         # Network Time Protocol
/etc/services:nntps             563/tcp         snntp           # NNTP over SSL
/etc/init.d/umountroot: if mountpoint -q /usr; then
/etc/init.d/mountnfs.sh:        for mountpt in $waitnfs; do
/etc/init.d/mountnfs.sh:                log_action_begin_msg "Waiting for $mountpt"
/etc/init.d/mountnfs.sh:                while ! mountpoint -q $mountpt; do
/etc/init.d/mountall.sh:                if mountpoint -q /usr; then
/etc/init.d/udev:  if mountpoint -q /dev/pts/; then
/etc/init.d/udev:  if mountpoint -q /dev/shm/; then
/etc/init.d/udev:    if ! mountpoint -q /dev/; then
/etc/init.d/dbus:  if ! mountpoint -q /proc/ ; then
/etc/init.d/checkroot.sh:               ddev="$(mountpoint -qx $rootdev)"
/etc/init.d/checkroot.sh:               rdev="$(mountpoint -d /)"
/etc/init.d/checkroot.sh:                       if [ "$(mountpoint -qx /dev/root)" = "4:0" ]
/etc/dhcp/dhclient-exit-hooks.d/timesyncd:        if [ -e $TIMESYNCD_CONF ] && [ "$new_ntp_servers" = "$old_ntp_servers" ]; then
/etc/dhcp/dhclient-exit-hooks.d/timesyncd:        if [ -z "$new_ntp_servers" ]; then
/etc/dhcp/dhclient-exit-hooks.d/timesyncd:NTP=$new_ntp_servers
/etc/dhcp/dhclient.conf:        rfc3442-classless-static-routes, ntp-servers;
/etc/dhcp/debug:                               ntp_servers \
/etc/passwd-:ntp:x:100:103::/home/ntp:/bin/false
/etc/netd.conf:#enable_ntp = True


