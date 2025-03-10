---
title: systemd-timeout
date: 2022-03-03
---




/lib/systemd/system/networking.service.d/timeout.conf
[Service]
TimeoutStartSec=180s



Usual DHCP lease can succeed in less than 5 seconds.



We now had no idea why the dhclient ( in this case, -6 , called by ifup ) failed to quit gracefully.



Will continue look into refine that.



In some later Linux releases, ifup/ifdown had been seen obsoleted, and given up it in favor of iproute2 series. We will consider the situation in the future.



In my instance of Ubuntu, the service has a Timeout setting as 5min, but in my observation, there are no so long waiting when there is no DHCP servers.



$ cat /lib/systemd/system/networking.service 
[Unit]
Description=Raise network interfaces
Documentation=man:interfaces(5)
DefaultDependencies=no
Requires=ifupdown-pre.service
Wants=network.target
After=local-fs.target network-pre.target apparmor.service systemd-sysctl.service systemd-modules-load.service ifupdown-pre.service
Before=network.target shutdown.target network-online.target
Conflicts=shutdown.target

[Install]
WantedBy=multi-user.target
WantedBy=network-online.target

[Service]
Type=oneshot
EnvironmentFile=-/etc/default/networking
ExecStart=/sbin/ifup -a --read-environment
ExecStop=/sbin/ifdown -a --read-environment --exclude=lo
RemainAfterExit=true
TimeoutStartSec=5min


