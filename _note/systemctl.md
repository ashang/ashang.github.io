---
title: systemctl list-unit-files | grep NetworkManager
Page_Order: 8
date: 2018-01-29T00:52:12+08:00
---


$ sudo systemctl -q restart logrotate.service && df

> http://10.10.50.50/repo/pica8/-/commit/d9d8e8c530f6fdbf01120fc1da7eda636c78c289


## systemctl mask a service

This is like disabling a service, but on steroids. It not only makes sure that service is not started automatically anymore, but even ensures that a service cannot even be started manually anymore. This is a bit of a hidden feature in systemd, since it is not commonly useful and might be confusing the user. But here's how you do it:

$ ln -s /dev/null /etc/systemd/system/ntpd.service
$ systemctl daemon-reload
By symlinking a service file to /dev/null you tell systemd to never start the service in question and completely block its execution. Unit files stored in /etc/systemd/system override those from /lib/systemd/system that carry the same name. The former directory is administrator territory, the latter terroritory of your package manager. By installing your symlink in /etc/systemd/system/ntpd.service you hence make sure that systemd will never read the upstream shipped service file /lib/systemd/system/ntpd.service.

systemd will recognize units symlinked to /dev/null and show them as masked. If you try to start such a service manually (via systemctl start for example) this will fail with an error.

A similar trick on SysV systems does not (officially) exist. However, there are a few unofficial hacks, such as editing the init script and placing an exit 0 at the top, or removing its execution bit. However, these solutions have various drawbacks, for example they interfere with the package manager.

Masking a service is a permanent change, much like disabling a service.



# systemctl list-unit-files | grep NetworkManager

systemctl --type=service



    It is important to understand how resolv.conf and systemd-resolved interact to properly configure the DNS that will be used

systemd-resolved is required if DNS entries are specified in .network files.
systemd-resolved is also required if you want to obtain DNS addresses from DHCP servers or IPv6 router advertisements.

(by setting (DHCP= and/or IPv6AcceptRA= in the [Network] section, and UseDNS=yes (the default) in the corresponding section(s) [DHCPv4], [DHCPv6], [IPv6AcceptRA]

## systemd-networkd-wait-online

Enabling systemd-networkd.service also enables systemd-networkd-wait-online.service, which is a oneshot system service that waits for the network to be configured. The latter has WantedBy=network-online.target, so it will be started only when network-online.target itself is enabled or pulled in by some other unit.

By default, systemd-networkd-wait-online.service waits for all links it is aware of and which are managed by systemd-networkd to be fully configured or failed, and for at least one link to be online.

If your system has multiple network interfaces, but some are not expected to be connected all the time (e.g. if you have a dual-port Ethernet card, but only one cable plugged in), starting systemd-networkd-wait-online.service will fail after the default timeout of 2 minutes. This may cause an unwanted delay in the startup process. To change the behaviour to wait for any interface rather than all interfaces to become online, edit the service and add the --any parameter to the ExecStart line:

/etc/systemd/system/systemd-networkd-wait-online.service.d/wait-for-only-one-interface.conf

[Service]
ExecStart=
ExecStart=/usr/lib/systemd/systemd-networkd-wait-online --any

Other behaviour such as which specific interface(s) to wait for or the operational state can be configured as well.




$ sudo systemctl disable containerd
Removed /etc/systemd/system/multi-user.target.wants/containerd.service.

$ sudo systemctl disable snmpd
snmpd.service is not a native service, redirecting to systemd-sysv-install
Executing /lib/systemd/systemd-sysv-install disable snmpd
insserv: warning: current start runlevel(s) (empty) of script `snmpd' overrides LSB defaults (2 3 4 5).
insserv: warning: current stop runlevel(s) (0 1 2 3 4 5 6) of script `snmpd' overrides LSB defaults (0 1 6).

$ sudo systemctl disable vsftpd
Synchronizing state for vsftpd with sysvinit using update-rc.d...
Executing /usr/sbin/update-rc.d vsftpd defaults
update-rc.d: using dependency based boot sequencing
update-rc.d: warning: default stop runlevel arguments (0 1 6) do not match vsftpd Default-Stop values (1)
Executing /usr/sbin/update-rc.d vsftpd disable
update-rc.d: using dependency based boot sequencing
insserv: warning: current start runlevel(s) (empty) of script `vsftpd' overrides LSB defaults (2 3 4 5).
insserv: warning: current stop runlevel(s) (1 2 3 4 5) of script `vsftpd' overrides LSB defaults (1).


> $ systemctl enable docker
Synchronizing state of docker.service with SysV service script with /lib/systemd/systemd-sysv-install.
Executing: /lib/systemd/systemd-sysv-install enable docker
insserv: fopen(.depend.stop): Permission denied
insserv: fopen(.depend.stop): Permission denied
Failed to enable unit: Access denied


> $ sudo systemctl enable docker
Synchronizing state of docker.service with SysV service script with /lib/systemd/systemd-sysv-install.
Executing: /lib/systemd/systemd-sysv-install enable docker



```
# The service we want to check (according to systemctl)
SERVICE=openvpn@smileytown.service
# Where to send the restart mail to
MAILBOX=spam@m00nie.com

if [ "`systemctl is-active $SERVICE`" != "active" ]
then
    echo "$SERVICE wasnt running so attempting restart"
    systemctl restart $SERVICE
    echo "Mailing $MAILBOX with current status"
    systemctl status $SERVICE | mail -s "$SERVICE was restarted" $MAILBOX
    exit 0
fi
echo "$SERVICE is currently running"
exit 0
Next simply add a crontab entry to run the script as often as you like. I run the script every 5 minutes.

# Check OpenVPN is running
*/15 * * * * /usr/bin/SCheck > /dev/null
Now every 15 minutes the script should run, check the service is running and if not restart it for you. You will only be mailed when it has been restarted.
```
