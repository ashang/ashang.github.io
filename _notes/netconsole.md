---
title: netconsole
date: 2018-06-26
--- 

The netconsole kernel module enables logging of kernel messages over the network to another computer. It allows kernel debugging when disk logging fails or when using the serial console is not possible.



To configure rsyslogd to listen on the 514/UDP port and receive messages from the network, uncomment the following lines in the MODULES section of /etc/rsyslog.conf:
$ModLoad imudp
$UDPServerRun 514
Restart the rsyslogd service for the changes to take effect:
]# service rsyslog restart
To verify that rsyslogd is listening on the 514/udp port, use the following command:
]# netstat -l | grep syslog
udp        0      0 *:syslog                    *:*                                     
udp        0      0 *:syslog                    *:*
The 0 *:syslog value in the netstat -l output mean that rsyslogd is listening on default netconsole port, which is defined in the /etc/services file:
]$ cat /etc/services | grep syslog
syslog          514/udp
syslog-conn     601/tcp                 # Reliable Syslog Service
syslog-conn     601/udp                 # Reliable Syslog Service
syslog-tls      6514/tcp                # Syslog over TLS
Configuring a Sending Machine
In Red Hat Enterprise Linux 6, netconsole is configured using the file /etc/sysconfig/netconsole, which is part of the initscripts package. This package is installed by default and it also provides the netconsole service.
To configure a sending machine, set the value of the SYSLOGADDR variable in the /etc/sysconfig/netconsole file to match the IP address of the syslogd server, for example:
SYSLOGADDR=192.168.0.1
Restart the netconsole service so the changes take effect. Then, use the chkconfig command to ensure netconsole service starts automatically after next reboot:
]# service netconsole restart
Initializing netconsole                                    [  OK  ]	
]# chkconfig netconsole on
By default, the rsyslogd server writes the netconsole messages from the client in /var/log/messages or in the file specified in rsyslog.conf.
Note

To set rsyslogd and netconsole to use a different port, change the following line in /etc/rsyslog.conf to the desired port number:
$UDPServerRun <PORT>
On the sending machine, uncomment and edit the following line in the /etc/sysconfig/netconsole file:
SYSLOGPORT=514


