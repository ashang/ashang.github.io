---
layout: page
title: Tor
tags: about
---

## ABOUT TOR BROWSER

Tor Browser uses the Tor network to protect your privacy and anonymity. Using the Tor network has two main properties:

    Your internet service provider, and anyone watching your connection locally, will not be able to track your internet activity, including the names and addresses of the websites you visit.

    The operators of the websites and services that you use, and anyone watching them, will see a connection coming from the Tor network instead of your real Internet (IP) address, and will not know who you are unless you explicitly identify yourself.

In addition, Tor Browser is designed to prevent websites from "fingerprinting" or identifying you based on your browser configuration.

By default, Tor Browser does not keep any browsing history. Cookies are only valid for a single session (until Tor Browser is exited or a New Identity is requested).
HOW TOR WORKS

Tor is a network of virtual tunnels that allows you to improve your privacy and security on the Internet. Tor works by sending your traffic through three random servers (also known as relays) in the Tor network. The last relay in the circuit (the "exit relay") then sends the traffic out onto the public Internet.

How Tor works

The image above illustrates a user browsing to different websites over Tor. The green middle computers represent relays in the Tor network, while the three keys represent the layers of encryption between the user and each relay.

## TOR

Tor 浏览器专为大陆等网络环境加入了流量混淆的选项。首次打开浏览器时会弹出 Tor 状态检查，点击设置配置 Tor 网桥，勾选互联网提供商（ISP）是否对 Tor 网络连接进行了封锁或审查中的是，把下一步中的网桥类型选择meek-amazon或meek-azure。这两者在大陆没被完全封锁，因此可以用来做跳板网桥。

不过随着网络环境的恶化，Tor 提供的网桥类型都不可用时，就需要使用自己的 Shadowsocks 或 Lantern 代理了。

首次打开 Tor 浏览器，在 Tor 设置中勾选互联网提供商（ISP）是否对 Tor 网络连接进行了封锁或审查中的否，在下一步是否需要本地代理访问互联网？中选择是，下一步中设置你的代理：

    使用 Shadowsocks 则设置为 SOCKS5 类型的 127.0.0.1:1080；
        使用 Lantern 则设置为 HTTP/HTTPS 类型的 127.0.0.1:8787；


Package: tor
Status: install ok installed
Priority: optional
Section: net
Installed-Size: 4057
Maintainer: Peter Palfrader <weasel@debian.org>
Architecture: amd64
Version: 0.2.9.14-1
Depends: libc6 (>= 2.17), libevent-2.0-5 (>= 2.0.10-stable), libseccomp2 (>= 0.0.0~20120605), libssl1.1 (>= 1.1.0), libsystemd0, zlib1g (>= 1:1.1.4), adduser, init-system-helpers (>= 1.18~), lsb-base
Recommends: logrotate, tor-geoipdb, torsocks
Suggests: mixmaster, torbrowser-launcher, socat, tor-arm, apparmor-utils, obfsproxy, obfs4proxy
Conflicts: libssl0.9.8 (<< 0.9.8g-9)
Conffiles:
 /etc/apparmor.d/abstractions/tor bf88d45209243216901d7df09666f6aa
 /etc/apparmor.d/system_tor 2920c5c9e0dac3172176b998e4894767
 /etc/cron.weekly/tor 78214da84411cbfef01ed0c037514288
 /etc/default/tor 4eed467922fcd0eb49f8c2fa938d53c0
 /etc/init.d/tor fe0e4cf6bc15a6a7669ccc77cfcad6d1
 /etc/logrotate.d/tor 116b39ab9b06e24757a27fa47bc8c3ff
 /etc/tor/torrc 8bbeab709059e3cf743f029523baa661
Description: anonymizing overlay network for TCP
 Tor is a connection-based low-latency anonymous communication system.
 .
 Clients choose a source-routed path through a set of relays, and
 negotiate a "virtual circuit" through the network, in which each relay
 knows its predecessor and successor, but no others. Traffic flowing
 down the circuit is decrypted at each relay, which reveals the
 downstream relay.
 .
 Basically, Tor provides a distributed network of relays. Users bounce
 their TCP streams (web traffic, ftp, ssh, etc) around the relays, and
 recipients, observers, and even the relays themselves have difficulty
 learning which users connected to which destinations.
 .
 This package enables only a Tor client by default, but it can also be
 configured as a relay and/or a hidden service easily.
 .
 Client applications can use the Tor network by connecting to the local
 socks proxy interface provided by your Tor instance. If the application
 itself does not come with socks support, you can use a socks client
 such as torsocks.
 .
 Note that Tor does no protocol cleaning on application traffic. There
 is a danger that application protocols and associated programs can be
 induced to reveal information about the user. Tor depends on Torbutton
 and similar protocol cleaners to solve this problem. For best
 protection when web surfing, the Tor Project recommends that you use
 the Tor Browser Bundle, a standalone tarball that includes static
 builds of Tor, Torbutton, and a modified Firefox that is patched to fix
 a variety of privacy bugs.
Homepage: https://www.torproject.org/


# Whonix

```
Your Information
IP Address:	2a0b:f4c2::1  IPv6

Local IP:	Can't Resolve Private IP     Private IP
Hostname:	2a0b:f4c2::1
ISP:	ZWF
Location:	Dresden, Saxony DE DE Flag
Coords:	Lat 51.0609 , Lon 13.7396
Local:	08:36 am - Europe/Berlin
Language:	English (United States)
```

```
185.107.47.171
Netherlands

The geolocation information below is an estimation of the real-world geographical location for the host with IP address 185.107.47.171. The estimation is 99% accurate at country level and 60% to 80% accurate at city level as of March 30, 2020.

IP 	185.107.47.171
Hostname 	tor-exit.r2.darknet.dev
ASN 	AS43350
Organization 	NForce Entertainment B.V.
Country 	Netherlands (NL)
JSON 	185.107.47.171.json
Updated by 162.247.74.200 2 weeks ago

    Services
    WHOIS
    Traceroute

The information below is based on nmap scan report for 185.107.47.171 generated on Mar 22, 2019. It may not reflect the current services that are actually running on the host. If you wish to update this information, click on the "Scan host" button below.

PORT    STATE SERVICE    VERSION
53/tcp  open  tcpwrapped
80/tcp  open  http       h2o/2.3.0-DEV@5466d1cd
| fingerprint-strings: 
|   GetRequest, HTTPOptions: 
|     HTTP/1.1 302 Redirected
|     Connection: close
|     Content-Length: 98
|     Server: h2o/2.3.0-DEV@5466d1cd
|     location: https://r2.dtr.is/
|     content-type: text/html; charset=utf-8
|     x-xss-protection: 1; mode=block
|     x-content-type-options: nosniff
|     access-control-allow-origin: https://psychonautwiki.org
|     access-control-allow-headers: Origin, X-Requested-With, Content-Type, Accept
|     <!DOCTYPE html><TITLE>Moved</TITLE><P>The document has moved <A HREF="https://r2.dtr.is/">here</A>
|   RTSPRequest, X11Probe: 
|     HTTP/1.1 400 Bad Request
|     Connection: close
|     Content-Length: 11
|     Server: h2o/2.3.0-DEV@5466d1cd
|     content-type: text/plain; charset=utf-8
|     x-xss-protection: 1; mode=block
|     x-content-type-options: nosniff
|     access-control-allow-origin: https://psychonautwiki.org
|     access-control-allow-headers: Origin, X-Requested-With, Content-Type, Accept
|_    Request
|_http-server-header: h2o/2.3.0-DEV@5466d1cd
|_http-title: Did not follow redirect to https://r2.dtr.is/
443/tcp open  ssl
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port80-TCP:V=7.70%I=7%D=3/22%Time=5C93F412%P=x86_64-unknown-linux-gnu%r
SF:(GetRequest,1D3,"HTTP/1\.1\x20302\x20Redirected\r\nConnection:\x20close
SF:\r\nContent-Length:\x2098\r\nServer:\x20h2o/2\.3\.0-DEV@5466d1cd\r\nloc
SF:ation:\x20https://r2\.dtr\.is/\r\ncontent-type:\x20text/html;\x20charse
SF:t=utf-8\r\nx-xss-protection:\x201;\x20mode=block\r\nx-content-type-opti
SF:ons:\x20nosniff\r\naccess-control-allow-origin:\x20https://psychonautwi
SF:ki\.org\r\naccess-control-allow-headers:\x20Origin,\x20X-Requested-With
SF:,\x20Content-Type,\x20Accept\r\n\r\n<!DOCTYPE\x20html><TITLE>Moved</TIT
SF:LE><P>The\x20document\x20has\x20moved\x20<A\x20HREF=\"https://r2\.dtr\.
SF:is/\">here</A>")%r(HTTPOptions,1D3,"HTTP/1\.1\x20302\x20Redirected\r\nC
SF:onnection:\x20close\r\nContent-Length:\x2098\r\nServer:\x20h2o/2\.3\.0-
SF:DEV@5466d1cd\r\nlocation:\x20https://r2\.dtr\.is/\r\ncontent-type:\x20t
SF:ext/html;\x20charset=utf-8\r\nx-xss-protection:\x201;\x20mode=block\r\n
SF:x-content-type-options:\x20nosniff\r\naccess-control-allow-origin:\x20h
SF:ttps://psychonautwiki\.org\r\naccess-control-allow-headers:\x20Origin,\
SF:x20X-Requested-With,\x20Content-Type,\x20Accept\r\n\r\n<!DOCTYPE\x20htm
SF:l><TITLE>Moved</TITLE><P>The\x20document\x20has\x20moved\x20<A\x20HREF=
SF:\"https://r2\.dtr\.is/\">here</A>")%r(RTSPRequest,160,"HTTP/1\.1\x20400
SF:\x20Bad\x20Request\r\nConnection:\x20close\r\nContent-Length:\x2011\r\n
SF:Server:\x20h2o/2\.3\.0-DEV@5466d1cd\r\ncontent-type:\x20text/plain;\x20
SF:charset=utf-8\r\nx-xss-protection:\x201;\x20mode=block\r\nx-content-typ
SF:e-options:\x20nosniff\r\naccess-control-allow-origin:\x20https://psycho
SF:nautwiki\.org\r\naccess-control-allow-headers:\x20Origin,\x20X-Requeste
SF:d-With,\x20Content-Type,\x20Accept\r\n\r\nBad\x20Request")%r(X11Probe,1
SF:60,"HTTP/1\.1\x20400\x20Bad\x20Request\r\nConnection:\x20close\r\nConte
SF:nt-Length:\x2011\r\nServer:\x20h2o/2\.3\.0-DEV@5466d1cd\r\ncontent-type
SF::\x20text/plain;\x20charset=utf-8\r\nx-xss-protection:\x201;\x20mode=bl
SF:ock\r\nx-content-type-options:\x20nosniff\r\naccess-control-allow-origi
SF:n:\x20https://psychonautwiki\.org\r\naccess-control-allow-headers:\x20O
SF:rigin,\x20X-Requested-With,\x20Content-Type,\x20Accept\r\n\r\nBad\x20Re
SF:quest");

Scan host (may take up to 4 minutes)

The information below is based on WHOIS output for 185.107.47.171 generated on Apr 14, 2020. It may not reflect the current WHOIS record for the host. If you wish to update this information, click on the "WHOIS host" button below.

inetnum: 77.247.181.160 - 77.247.181.175
netname: ZWIEBELFREUNDE
descr: Customer 692 / Zwiebelfreunde e.V.
remarks: Sent abuse to: abuse@torservers.net
country: NL
admin-c: MB22990-RIPE
tech-c: MB22990-RIPE
status: ASSIGNED PA
mnt-by: MNT-NFORCE
mnt-lower: MNT-NFORCE
mnt-routes: MNT-NFORCE
created: 2015-02-04T09:09:24Z
last-modified: 2015-02-04T09:09:24Z
source: RIPE # Filtered

person: Moritz Bartl
address: Zwiebelfreunde e.V.
address: c/o DID Dresdner Institut fuer Datenschutz
address: Palaisplatz 3
address: 01097 Dresden
address: Germany
phone: +49-351-21296018
fax-no: +49-911-3084466748
remarks: ---------------------------------
remarks: This network is used for research
remarks: in anonymization services and
remarks: provides Tor exit nodes to end
remarks: users.
remarks: ---------------------------------
remarks: Dieser Netzblock wird zur
remarks: Erforschung von Anonymisierungs-
remarks: techniken genutzt und stellt
remarks: Endnutzern Tor zur Verfuegung.
remarks: ---------------------------------
remarks: http://www.torservers.net/abuse.html
remarks: ---------------------------------
nic-hdl: MB22990-RIPE
mnt-by: ZWIEBELFREUNDE
created: 2011-02-11T04:11:32Z
last-modified: 2017-10-30T22:12:54Z
source: RIPE # Filtered

route: 77.247.176.0/21
descr: NFOrce Entertainment BV - 77.247.176.0/21 route
origin: AS43350
mnt-by: MNT-NFORCE
created: 2007-07-28T17:50:49Z
last-modified: 2011-04-13T13:20:38Z
source: RIPE

WHOIS host (may take up to 60 seconds)

Traceroute output for 185.107.47.171 is not available yet. Click on the "Traceroute host" button below to launch a new traceroute to generate the output.

Traceroute host (may take up to 3 minutes)

    dazzlepod.com (default)
    Australia
    Switzerland
    Japan
    Russia
    United Kingdom
    United States


Source: dazzlepod.com
```





























debian-+     875  0.0  0.0  16944  3328 ?        Ss   Jul10   0:00 /usr/bin/tor --defaults-torrc /usr/share/tor/tor-service-defaults-torrc -f /etc/tor/torrc --RunAsDaemon 0




root         741  0.0  0.0  15348  3840 ?        Ss   Jul10   0:00 sshd: /usr/sbin/sshd -D [listener] 0 of 10-100 startups
root      888990  0.0  0.1  18240 10880 ?        Ss   09:38   0:00  \_ sshd: aaron [priv]
aaron     889038  0.0  0.0  18648  7368 ?        S    09:38   0:00      \_ sshd: aaron@pts/14
aaron     889039  0.0  0.1  18668 12092 pts/14   Ss   09:38   0:00          \_ -bash
aaron     889270  0.8  0.5 159240 44764 pts/14   Sl+  09:38   0:03              \_ lvim -u /aaron/.local/share/lunarvim/lvim/init.lua -p dent-os.md
aaron     891509  0.1  0.1 100488 12928 pts/14   S+   09:45   0:00                  \_ curl -H User-Agent: mason.nvim (+https://github.com/williamboman/mason.nvim) -fsSL -X GET https://github.com/mason-org/mason-r

aaron       1378  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c swayidle -w timeout 600 'swaymsg "output * dpms off"' resume 'swaymsg "output * dpms on"'
aaron       1379  0.0  0.0   6284  1536 ?        S    Jul10   0:00  \_ swayidle -w timeout 600 swaymsg "output * dpms off" resume swaymsg "output * dpms on"
aaron       1381  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c swayidle -w timeout 610 "swaylock -c 000000" resume 'swaymsg "output * dpms on"'
aaron       1382  0.0  0.0   6284  1536 ?        S    Jul10   0:00  \_ swayidle -w timeout 610 swaylock -c 000000 resume swaymsg "output * dpms on"
aaron       1384  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c swayidle -w timeout 10 'if pgrep swaylock; then swaymsg "output * dpms off"; fi' resume 'if pgrep swaylock; then swaymsg "output * dpms on";
aaron       1385  0.0  0.0   6284  1536 ?        S    Jul10   0:00  \_ swayidle -w timeout 10 if pgrep swaylock; then swaymsg "output * dpms off"; fi resume if pgrep swaylock; then swaymsg "output * dpms on"; fi
aaron       1393  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c tail -f $SWAYSOCK.wob | wob --border-color '#ffdcbb8c' --background-color '#cc3a3a3a' --bar-color '#ffdcbb8c'
aaron       1394  0.0  0.0   8744   256 ?        S    Jul10   0:00  \_ tail -f /run/user/1000/sway-ipc.1000.1181.sock.wob
aaron       1412  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c wl-paste -t text --watch clipman store
aaron       1414  0.0  0.0   2764   896 ?        S    Jul10   0:00  \_ wl-paste -t text --watch clipman store
aaron       1425  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c /usr/libexec/xdg-desktop-portal
aaron       1428  0.0  0.0 690284  7632 ?        Sl   Jul10   0:22  \_ /usr/libexec/xdg-desktop-portal
aaron       1429  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c python3 ~/.config/sway/swayfader.py
aaron       1431  0.0  0.1  98860 11648 ?        S    Jul10   0:10  \_ python3 /aaron/.config/sway/swayfader.py
aaron       1432  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c unclutter
aaron       1435  0.0  0.0   4396   896 ?        S    Jul10   0:07  \_ unclutter
aaron       1434  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c im-launch fcitx5
aaron       1437  0.0  0.5 595200 45616 ?        Sl   Jul10   1:34  \_ fcitx5
aaron       1438  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c dunst
aaron       1440  2.2  0.0 639104  5188 ?        Sl   Jul10  57:07  \_ dunst
aaron       1441  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c ~/.config/sway/inactive-windows-transparency.py -o 0.85
aaron       1442  0.0  0.1  26788 12416 ?        S    Jul10   0:03  \_ /usr/bin/python /aaron/.config/sway/inactive-windows-transparency.py -o 0.85


aaron       1476  0.3  0.5 388280 44128 tty1     Sl+  Jul10   7:55 Xwayland :0 -rootless -terminate -core -listenfd 29 -listenfd 30 -wm 70



aaron       1893  0.0  0.0   2732   256 ?        S    Jul10   0:00 sh -c wezterm
aaron       1894  2.2  2.1 3163768 170240 ?      Sl   Jul10  56:41  \_ /usr/bin/wezterm-gui
aaron       1900  0.0  0.1  18736  8788 pts/1    Ss   Jul10   0:00      \_ -bash
aaron      34302  0.0  0.0  11348  1920 pts/1    S+   Jul10   0:00      |   \_ tmux -2
aaron      10520  0.0  0.1  18728  9088 pts/30   Ss   Jul10   0:00      \_ -bash
aaron      29251  0.0  0.0  18388  3536 pts/30   S+   Jul10   2:28          \_ ssh -Y 10.10.50.50


root      874874  0.0  0.0  13964  5120 pts/10   S+   09:07   0:00  |   \_ sudo apt dist-upgrade
root      874875  0.0  0.0  13964  1736 pts/0    Ss   09:07   0:00  |       \_ sudo apt dist-upgrade
root      874876  0.0  0.8  85280 67092 pts/0    S+   09:07   0:01  |           \_ apt dist-upgrade
root      892061 71.4  0.9  79460 72096 pts/15   Rs+  09:46   0:16  |               \_ /usr/bin/dpkg --status-fd 49 --no-triggers --unpack --auto-deconfigure --recursive /tmp/apt-dpkg-install-Wu5dzf
root      892430  0.0  0.0  10576  2432 pts/15   S+   09:46   0:00  |                   \_ dpkg-deb --fsys-tarfile /tmp/apt-dpkg-install-Wu5dzf/13-linux-headers-6.2.0-25_6.2.0-25.25_all.deb
root      892431  0.1  0.0  10576   384 pts/15   S+   09:46   0:00  |                       \_ dpkg-deb --fsys-tarfile /tmp/apt-dpkg-install-Wu5dzf/13-linux-headers-6.2.0-25_6.2.0-25.25_all.deb
root      892432 10.2  0.1  19420 10624 pts/15   R+   09:46   0:01  |                       \_ dpkg-deb --fsys-tarfile /tmp/apt-dpkg-install-Wu5dzf/13-linux-headers-6.2.0-25_6.2.0-25.25_all.deb
aaron      79283  0.0  0.1  18688 10960 pts/11   Ss+  Jul10   0:02  \_ -bash
