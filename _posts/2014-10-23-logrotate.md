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
