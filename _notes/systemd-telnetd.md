---
title: "telnetd systemd"
date: 2017-08-07
---

Start telnet server on boot.

```
systemctl start telnet.socket
systemctl enable telnet.socket
```


```
telnet.socket
[Unit]
Description=Telnet Server Activation Socket
Documentation=man:telnetd(8)

[Socket]
ListenStream=23
Accept=true

[Install]
WantedBy=sockets.target
```

telnet@.service

```
[Unit]
Description=Telnet Server
After=local-fs.target

[Service]
ExecStart=-/usr/sbin/in.telnetd
StandardInput=socket

```
