---
layout: post
title: logrotate
tags: [logrotate, log]
---

Week 47 remote work summary.

## W47.4

- Trouble shooting YD ovs web issues.
    - OVS web build depends on 

- Check cases for verizon project as to when host fingerprints may change. Result (1) Any new install or (2) /etc/ssh/ssh_host_* didn't exist during bin package upgrade.
    - New keys would be generated using `ssh-keygen -A` with key strength from `/etc/ssl/openssl.cnf`.

## W47.5

- Set up Nessus for Henry to generate scan results


```text
rotating pattern: /var/log/wtmp  5242880 bytes (1 rotations)
empty log files are rotated, log files >= 5 are rotated earlier, old logs are removed
switching euid to 1000 and egid to 1
considering log /var/log/wtmp
  log needs rotating
rotating log /var/log/wtmp, log->rotateCount is 1
dateext suffix '-19700101'
glob pattern '-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'
previous log /var/log/wtmp.1 does not exist
renaming /var/log/wtmp.1.gz to /var/log/wtmp.2.gz (rotatecount 1, logstart 1, i 1),
old log /var/log/wtmp.1.gz does not exist
renaming /var/log/wtmp.0.gz to /var/log/wtmp.1.gz (rotatecount 1, logstart 1, i 0),
old log /var/log/wtmp.0.gz does not exist
log /var/log/wtmp.2.gz doesn't exist -- won't try to dispose of it
renaming /var/log/wtmp to /var/log/wtmp.1
error: failed to rename /var/log/wtmp to /var/log/wtmp.1: Permission denied
switching euid to 0 and egid to 1
...
rotating pattern: /var/log/wtmp  5242880 bytes (1 rotations)
empty log files are rotated, log files >= 5 are rotated earlier, old logs are removed
considering log /var/log/wtmp
  log needs rotating
rotating log /var/log/wtmp, log->rotateCount is 1
dateext suffix '-19700101'
glob pattern '-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'
previous log /var/log/wtmp.1 does not exist
renaming /var/log/wtmp.1.gz to /var/log/wtmp.2.gz (rotatecount 1, logstart 1, i 1),
old log /var/log/wtmp.1.gz does not exist
renaming /var/log/wtmp.0.gz to /var/log/wtmp.1.gz (rotatecount 1, logstart 1, i 0),
old log /var/log/wtmp.0.gz does not exist
log /var/log/wtmp.2.gz doesn't exist -- won't try to dispose of it
renaming /var/log/wtmp to /var/log/wtmp.1
creating new /var/log/wtmp mode = 0664 uid = 0 gid = 43


rotating pattern: /var/log/wtmp  5242880 bytes (1 rotations)
empty log files are rotated, log files >= 5 are rotated earlier, old logs are removed
considering log /var/log/wtmp
  log needs rotating
rotating log /var/log/wtmp, log->rotateCount is 1
dateext suffix '-19700101'
glob pattern '-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'
compressing log with: /bin/gzip
renaming /var/log/wtmp.1.gz to /var/log/wtmp.2.gz (rotatecount 1, logstart 1, i 1),
renaming /var/log/wtmp.0.gz to /var/log/wtmp.1.gz (rotatecount 1, logstart 1, i 0),
old log /var/log/wtmp.0.gz does not exist
renaming /var/log/wtmp to /var/log/wtmp.1
creating new /var/log/wtmp mode = 0664 uid = 0 gid = 43
removing old log /var/log/wtmp.2.gz


rotating pattern: /var/log/wtmp  5242880 bytes (1 rotations)
empty log files are rotated, log files >= 5 are rotated earlier, old logs are removed
considering log /var/log/wtmp
  log needs rotating
rotating log /var/log/wtmp, log->rotateCount is 2
dateext suffix '-19700101'
glob pattern '-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'
compressing log with: /bin/gzip
renaming /var/log/wtmp.2.gz to /var/log/wtmp.3.gz (rotatecount 2, logstart 1, i 2),
old log /var/log/wtmp.2.gz does not exist
renaming /var/log/wtmp.1.gz to /var/log/wtmp.2.gz (rotatecount 2, logstart 1, i 1),
renaming /var/log/wtmp.0.gz to /var/log/wtmp.1.gz (rotatecount 2, logstart 1, i 0),
old log /var/log/wtmp.0.gz does not exist
log /var/log/wtmp.3.gz doesn't exist -- won't try to dispose of it
renaming /var/log/wtmp to /var/log/wtmp.1
creating new /var/log/wtmp mode = 0664 uid = 0 gid = 43

```


```
#!/bin/sh

# skip in favour of systemd timer
if [ -d /run/systemd/system ]; then
    exit 0
fi

# this cronjob persists removals (but not purges)
if [ ! -x /usr/sbin/logrotate ]; then
    exit 0
fi

/usr/sbin/logrotate /etc/logrotate.conf
EXITVALUE=$?
if [ $EXITVALUE != 0 ]; then
    /usr/bin/logger -t logrotate "ALERT exited abnormally with [$EXITVALUE]"
fi
exit $EXITVALUE
```

```
# Clean non existent log file entries from status file
cd /var/lib/logrotate
test -e status || touch status
head -1 status > status.clean
sed 's/"//g' status | while read logfile date
do
    [ -e "$logfile" ] && echo "\"$logfile\" $date"
done >> status.clean
mv status.clean status

test -x /usr/sbin/logrotate || exit 0
/usr/sbin/logrotate /etc/logrotate.conf
```

```
# cat /etc/logrotate.conf
# see "man logrotate" for details
# rotate log files weekly
weekly

# use the adm group by default, since this is the owning group
# of /var/log/syslog.
su root adm

# keep 4 weeks worth of backlogs
rotate 4

# create new (empty) log files after rotating old ones
create

# use date as a suffix of the rotated file
#dateext

# uncomment this if you want your log files compressed
#compress

# packages drop log rotation information into this directory
include /etc/logrotate.d

# system-specific logs may be also be configured here.
```

```
# cat /etc/logrotate.d/apt
/var/log/apt/term.log {
  rotate 120
  monthly
  compress
  missingok
  notifempty
}

/var/log/apt/history.log {
  rotate 12
  monthly
  compress
  missingok
  notifempty
}

```


```
#!/bin/sh

# skip in favour of systemd timer
if [ -d /run/systemd/system ]; then
    exit 0
fi

# this cronjob persists removals (but not purges)
if [ ! -x /usr/sbin/logrotate ]; then
    exit 0
fi

/usr/sbin/logrotate /etc/logrotate.conf
EXITVALUE=$?
if [ $EXITVALUE != 0 ]; then
    /usr/bin/logger -t logrotate "ALERT exited abnormally with [$EXITVALUE]"
fi
exit $EXITVALUE
```

```
# Clean non existent log file entries from status file
cd /var/lib/logrotate
test -e status || touch status
head -1 status > status.clean
sed 's/"//g' status | while read logfile date
do
    [ -e "$logfile" ] && echo "\"$logfile\" $date"
done >> status.clean
mv status.clean status

test -x /usr/sbin/logrotate || exit 0
/usr/sbin/logrotate /etc/logrotate.conf
```

```
# cat /etc/logrotate.conf
# see "man logrotate" for details
# rotate log files weekly
weekly

# use the adm group by default, since this is the owning group
# of /var/log/syslog.
su root adm

# keep 4 weeks worth of backlogs
rotate 4

# create new (empty) log files after rotating old ones
create

# use date as a suffix of the rotated file
#dateext

# uncomment this if you want your log files compressed
#compress

# packages drop log rotation information into this directory
include /etc/logrotate.d

# system-specific logs may be also be configured here.
```

```
# cat /etc/logrotate.d/apt
/var/log/apt/term.log {
  rotate 120
  monthly
  compress
  missingok
  notifempty
}

/var/log/apt/history.log {
  rotate 12
  monthly
  compress
  missingok
  notifempty
}

```
```
$ cat /etc/rsyslog.d/bash.conf
local6.*    /var/log/commands.log
```

```
 {
        rotate 4
        weekly
@@ -33,6 +32,6 @@
        delaycompress
        sharedscripts
        postrotate
-               reload rsyslog >/dev/null 2>&1 || true
+               /usr/lib/rsyslog/rsyslog-rotate
        endscript
 }
```




```
/var/log/syslog
{
	rotate 7
	daily
	missingok
	notifempty
	delaycompress
	compress
	postrotate
		reload rsyslog >/dev/null 2>&1 || true
	endscript
}

/var/log/mail.info
/var/log/mail.warn
/var/log/mail.err
/var/log/mail.log
/var/log/daemon.log
/var/log/kern.log
/var/log/auth.log
/var/log/user.log
/var/log/lpr.log
/var/log/cron.log
/var/log/debug
/var/log/messages
/var/log/commands.log
{
	rotate 4
	weekly
	missingok
	notifempty
	compress
	delaycompress
	sharedscripts
	postrotate
		reload rsyslog >/dev/null 2>&1 || true
	endscript
}

$ more /etc/logrotate.d/dpkg
/var/log/dpkg.log {
	monthly
	rotate 12
	compress
	delaycompress
	missingok
	notifempty
	create 644 root root
}

```


```
#!/bin/sh

# skip in favour of systemd timer
if [ -d /run/systemd/system ]; then
    exit 0
fi

# this cronjob persists removals (but not purges)
if [ ! -x /usr/sbin/logrotate ]; then
    exit 0
fi

/usr/sbin/logrotate /etc/logrotate.conf
EXITVALUE=$?
if [ $EXITVALUE != 0 ]; then
    /usr/bin/logger -t logrotate "ALERT exited abnormally with [$EXITVALUE]"
fi
exit $EXITVALUE
```

```
# Clean non existent log file entries from status file
cd /var/lib/logrotate
test -e status || touch status
head -1 status > status.clean
sed 's/"//g' status | while read logfile date
do
    [ -e "$logfile" ] && echo "\"$logfile\" $date"
done >> status.clean
mv status.clean status

test -x /usr/sbin/logrotate || exit 0
/usr/sbin/logrotate /etc/logrotate.conf
```

```
# cat /etc/logrotate.conf
# see "man logrotate" for details
# rotate log files weekly
weekly

# use the adm group by default, since this is the owning group
# of /var/log/syslog.
su root adm

# keep 4 weeks worth of backlogs
rotate 4

# create new (empty) log files after rotating old ones
create

# use date as a suffix of the rotated file
#dateext

# uncomment this if you want your log files compressed
#compress

# packages drop log rotation information into this directory
include /etc/logrotate.d

# system-specific logs may be also be configured here.
```

```
# cat /etc/logrotate.d/apt
/var/log/apt/term.log {
  rotate 120
  monthly
  compress
  missingok
  notifempty
}

/var/log/apt/history.log {
  rotate 12
  monthly
  compress
  missingok
  notifempty
}

```
