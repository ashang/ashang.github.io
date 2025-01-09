---
title: netfilter and nftables
---

$ sudo iptables -A INPUT -p icmp --icmp-type echo-request -j REJECT

$ sudo iptables -A INPUT -p icmp --icmp-type echo-request -j DROP
$ sudo iptables -A OUTPUT -p icmp --icmp-type echo-reply -j DROP


iptables -A OUTPUT -p icmp -o eth0 -j ACCEPT
iptables -A INPUT -p icmp --icmp-type echo-reply -s 0/0 -i eth0 -j ACCEPT
iptables -A INPUT -p icmp --icmp-type destination-unreachable -s 0/0 -i eth0 -j ACCEPT
iptables -A INPUT -p icmp --icmp-type time-exceeded -s 0/0 -i eth0 -j ACCEPT
iptables -A INPUT -p icmp -i eth0 -j DROP



For IPv6 you would need something like ip6tables -I INPUT -p icmpv6 --icmp-type
8 -j DROP.



net.ipv4.icmp_echo_ignore_all = 1

this will tell kernel to not respond any ping response, after this run sysctl
-p on shell to implement the changes without reboot.

For more info please refer:
http://www.trickylinux.net/disable-ping-response-linux/


https://www.netfilter.org/projects/nftables/index.html

-j {ACCEPT|REJECT|DROP} : Tell Linux what to do if the packet matches it. The
ACCEPT means to let the packet through. The DROP or REJECT means to drop the
packet on the floor. Use the REJECT when you want the other end (client or host
or bot) to know the port is unreachable and use the DROP for connections to
hosts you do not want people/bots/client to see.



iptables -A {INPUT|OUTPUT} -p icmp -j {ACCEPT|REJECT|DROP}
iptables -A {INPUT|OUTPUT} -p icmp --icmp-type {0|8}  -j {ACCEPT|REJECT|DROP}
iptables -A {INPUT|OUTPUT} -p icmp --icmp-type {echo-reply|echo-request} -j
{ACCEPT|REJECT|DROP}
iptables -A {INPUT|OUTPUT} -p icmp --icmp-type {echo-reply|echo-request} -m
state --state NEW,ESTABLISHED,RELATED -j {ACCEPT|REJECT|DROP}

-m state --state NEW,ESTABLISHED,RELATED : Extended icmp packet matching using
the --ctstate or -m state option. The values are:

    INVALID : The packet is associated with no known connection.
	    NEW : The packet has started a new connection or otherwise associated
		with a connection which has not seen packets in both directions.
		    ESTABLISHED : The packet is associated with a connection which has
			seen packets in both directions.
			    RELATED : The packet is starting a new connection, but is
				associated with an existing connection, such as an FTP data
				transfer or an ICMP error.



sudo iptables -t filter -L INPUT -v
sudo iptables --table filter --list INPUT --verbose


sudo iptables -t filter -L INPUT -v --line-numbers

sudo iptables --table filter --list INPUT --verbose --line-numbers




Rule to enable ICMP ping incoming client request ( assuming that default
iptables policy is to drop all INPUT and OUTPUT packets):
Iptables allow icmp syntax:
1
2
3
4
5
6

	## Server SERVER IP HERE ##
	SERVER_IP="202.54.10.20"

	 ## Now allow ping request ##
	 iptables -A INPUT -p icmp --icmp-type 8 -s 0/0 -d "$SERVER_IP" -m state
	 --state NEW,ESTABLISHED,RELATED -j ACCEPT
	 iptables -A OUTPUT -p icmp --icmp-type 0 -s "$SERVER_IP" -d 0/0 -m state
	 --state ESTABLISHED,RELATED -j ACCEPT
	 Task: Allow or enable outgoing ping request

	 To enable ICMP ping outgoing request use following iptables rule:
	 1
	 2
	 3

		SERVER_IP="202.54.10.20"
		iptables -A OUTPUT -p icmp --icmp-type 8 -s $SERVER_IP -d 0/0 -m state
		--state NEW,ESTABLISHED,RELATED -j ACCEPT
		iptables -A INPUT -p icmp --icmp-type 0 -s 0/0 -d $SERVER_IP -m state
		--state ESTABLISHED,RELATED -j ACCEPT



# Syntax rate limit icmp ping #
iptables -A INPUT -p icmp --icmp-type 8 -m limit --limit {NUMBER}/sec
--limit-burst {NUMBER} -j ACCEPT

 # Examples rate limiting ICMP ping #
 iptables -A INPUT -p icmp --icmp-type 8 -m limit --limit 30/minute
 --limit-burst 120 -j ACCEPT

  # Log icmp floor
  iptables -A INPUT -p icmp --icmp-type 8 -m limit --limit 1/minute
  --limit-burst 2 -j LOG --log-prefix " PING-PONG-FLOOD "

   # DROP it
   iptables -A INPUT -p icmp --icmp-type 8 -j DROP

	# Verify after some time both LOG and DROP
	iptables -L -n -v


Where

    --limit rate[/second|/minute|/hour|/day] : Maximum average matching rate:
	specified as a number, with an optional `/second’, `/minute’, `/hour’, or
	`/day’ suffix; the default is 3/hour.
	    --limit-burst number : Maximum initial number of packets to match: this
		number gets recharged by one every time the limit specified above is
		not reached, up to this number; the default is 5.





Here is how counters look, run:

sudo iptables -L INPUT -n -v

Outputs:
Chain INPUT (policy ACCEPT 12973 packets, 1292K bytes)
 pkts bytes target     prot opt in     out     source               destination
   182 15288 ACCEPT     icmp --  *      *       0.0.0.0/0            0.0.0.0/0
   icmptype 8 limit: avg 30/min burst 120
       4   336 LOG        icmp --  *      *       0.0.0.0/0
	   0.0.0.0/0            icmptype 8 limit: avg 1/min burst 2 LOG flags 0
	   level 4 prefix " PING-PONG-FLOOD "
	   11834  994K DROP       icmp --  *      *       0.0.0.0/0
	   0.0.0.0/0            icmptype 8




To list all IPv4 rules:
sudo iptables -S
Get list of all IPv6 rules:
sudo ip6tables -S
To list all tables rules:
sudo iptables -L -v -n | more
Just list all rules for INPUT tables:
sudo iptables -L INPUT -v -n
sudo iptables -S INPUT



Viewing all iptables rules in Linux

The syntax is:

iptables -S
iptables --list
iptables -L
iptables -S TABLE_NAME
iptables --table NameHere --list
iptables -t NameHere -L -n -v --line-numbers

Print all rules in the selected chain

The command syntax is as follows for IPv4 rules:
sudo iptables -S
sudo iptables -S INPUT
iptables -S OUTPUT



https://www.cyberciti.biz/faq/debian-10-set-up-wireguard-vpn-server/?utm_source=Cmd_Table&utm_medium=tips&utm_campaign=Apr_22_2022_EOP


http://ww25.trickylinux.net/ping-single-ip-linux/?subid1=20220613-0024-14d3-bfa0-350f76e70511


https://en.wikipedia.org/wiki/Sockstress


https://en.wikipedia.org/wiki/Netfilter

https://www.worldhello.net/2019/03/17/goconfig.html

https://www.worldhello.net/2012/08/14/git-quiz-released-on-github.html


https://en.wikipedia.org/wiki/Nftables


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html

Git测验（A卷）



filter表是默认的表，如果不指明表则使用此表。其通常用于过滤数据包。其中的内建链包括：

    INPUT，输入链。发往本机的数据包通过此链。
	    OUTPUT，输出链。从本机发出的数据包通过此链。
		    FORWARD，转发链。本机转发的数据包通过此链。

			nat表

			nat表如其名，用于地址转换操作。其中的内建链包括：

			    PREROUTING，路由前链，在处理路由规则前通过此链，通常用于目的地址转换（DNAT）。
				    POSTROUTING，路由后链，完成路由规则后通过此链，通常用于源地址转换（SNAT）。
					    OUTPUT，输出链，类似PREROUTING，但是处理本机发出的数据包。

						mangle表

						mangle表用于处理数据包。其和nat表的主要区别在于，nat表侧重连接而mangle表侧重每一个数据包。[4]其中内建链列表如下。

						    PREROUTING
							    OUTPUT
								    FORWARD
									    INPUT
										    POSTROUTING

											raw表

											raw表用于处理异常，有如下两个内建链：

											    PREROUTING
												    OUTPUT


Netfilter平台中制定了五個封包的掛載點（Hook），分別是PRE_ROUTING、INPUT、OUTPUT、FORWARD與POST_ROUTING。




http://www.gray-world.net/papers/ipccc.pdf



https://www.linkedin.com/in/1391




https://en.wikipedia.org/wiki/Return-to-libc_attack



https://en.wikipedia.org/wiki/Buffer_overflow#Heap-based_exploitation




https://www.cve.org/CVERecord?id=CVE-2015-0235



https://www.offensive-security.com/kali-linux-nethunter-download/


https://stats.nethunter.com/nethunter-images.html

https://www.kali.org/get-kali/

https://www.whonix.org/


	https://en.wikipedia.org/wiki/Xpra



	https://en.wikipedia.org/wiki/Niels_Provos


	https://www.kali.org/docs/nethunter/#20-nethunter-supported-devices-and-roms


用 Git 维护博客？酷！

http://10.10.50.50:9000/kb/#feature_scope_project_management_etc

https://www.worldhello.net/2012/08/14/git-quiz-released-on-github.html


https://en.wikipedia.org/wiki/Nftables


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html

Git测验（A卷）



filter表是默认的表，如果不指明表则使用此表。其通常用于过滤数据包。其中的内建链包括：

    INPUT，输入链。发往本机的数据包通过此链。
	    OUTPUT，输出链。从本机发出的数据包通过此链。
		    FORWARD，转发链。本机转发的数据包通过此链。

			nat表

			nat表如其名，用于地址转换操作。其中的内建链包括：

			    PREROUTING，路由前链，在处理路由规则前通过此链，通常用于目的地址转换（DNAT）。
				    POSTROUTING，路由后链，完成路由规则后通过此链，通常用于源地址转换（SNAT）。
					    OUTPUT，输出链，类似PREROUTING，但是处理本机发出的数据包。

						mangle表

						mangle表用于处理数据包。其和nat表的主要区别在于，nat表侧重连接而mangle表侧重每一个数据包。[4]其中内建链列表如下。

						    PREROUTING
							    OUTPUT
								    FORWARD
									    INPUT
										    POSTROUTING

											raw表

											raw表用于处理异常，有如下两个内建链：

											    PREROUTING
												    OUTPUT


Netfilter平台中制定了五個封包的掛載點（Hook），分別是PRE_ROUTING、INPUT、OUTPUT、FORWARD與POST_ROUTING。




http://www.gray-world.net/papers/ipccc.pdf



https://www.linkedin.com/in/1391




https://en.wikipedia.org/wiki/Return-to-libc_attack



https://en.wikipedia.org/wiki/Buffer_overflow#Heap-based_exploitation




https://www.cve.org/CVERecord?id=CVE-2015-0235



https://www.offensive-security.com/kali-linux-nethunter-download/


https://stats.nethunter.com/nethunter-images.html

https://www.kali.org/get-kali/

https://www.whonix.org/


	https://en.wikipedia.org/wiki/Xpra



	https://en.wikipedia.org/wiki/Niels_Provos


	https://www.kali.org/docs/nethunter/#20-nethunter-supported-devices-and-roms


用 Git 维护博客？酷！

http://10.10.50.50:9000/kb/#feature_scope_project_management_etc

https://www.worldhello.net/2012/08/14/git-quiz-released-on-github.html


https://en.wikipedia.org/wiki/Nftables


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html

Git测验（A卷）



filter表是默认的表，如果不指明表则使用此表。其通常用于过滤数据包。其中的内建链包括：

    INPUT，输入链。发往本机的数据包通过此链。
	    OUTPUT，输出链。从本机发出的数据包通过此链。
		    FORWARD，转发链。本机转发的数据包通过此链。

			nat表

			nat表如其名，用于地址转换操作。其中的内建链包括：

			    PREROUTING，路由前链，在处理路由规则前通过此链，通常用于目的地址转换（DNAT）。
				    POSTROUTING，路由后链，完成路由规则后通过此链，通常用于源地址转换（SNAT）。
					    OUTPUT，输出链，类似PREROUTING，但是处理本机发出的数据包。

						mangle表

						mangle表用于处理数据包。其和nat表的主要区别在于，nat表侧重连接而mangle表侧重每一个数据包。[4]其中内建链列表如下。

						    PREROUTING
							    OUTPUT
								    FORWARD
									    INPUT
										    POSTROUTING

											raw表

											raw表用于处理异常，有如下两个内建链：

											    PREROUTING
												    OUTPUT


Netfilter平台中制定了五個封包的掛載點（Hook），分別是PRE_ROUTING、INPUT、OUTPUT、FORWARD與POST_ROUTING。




http://www.gray-world.net/papers/ipccc.pdf



https://www.linkedin.com/in/1391




https://en.wikipedia.org/wiki/Return-to-libc_attack



https://en.wikipedia.org/wiki/Buffer_overflow#Heap-based_exploitation




https://www.cve.org/CVERecord?id=CVE-2015-0235



https://www.offensive-security.com/kali-linux-nethunter-download/


https://stats.nethunter.com/nethunter-images.html

https://www.kali.org/get-kali/

https://www.whonix.org/


	https://en.wikipedia.org/wiki/Xpra



	https://en.wikipedia.org/wiki/Niels_Provos


	https://www.kali.org/docs/nethunter/#20-nethunter-supported-devices-and-roms


用 Git 维护博客？酷！

http://10.10.50.50:9000/kb/#feature_scope_project_management_etc

https://www.worldhello.net/2012/08/14/git-quiz-released-on-github.html


https://en.wikipedia.org/wiki/Nftables


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html

Git测验（A卷）



filter表是默认的表，如果不指明表则使用此表。其通常用于过滤数据包。其中的内建链包括：

    INPUT，输入链。发往本机的数据包通过此链。
	    OUTPUT，输出链。从本机发出的数据包通过此链。
		    FORWARD，转发链。本机转发的数据包通过此链。

			nat表

			nat表如其名，用于地址转换操作。其中的内建链包括：

			    PREROUTING，路由前链，在处理路由规则前通过此链，通常用于目的地址转换（DNAT）。
				    POSTROUTING，路由后链，完成路由规则后通过此链，通常用于源地址转换（SNAT）。
					    OUTPUT，输出链，类似PREROUTING，但是处理本机发出的数据包。

						mangle表

						mangle表用于处理数据包。其和nat表的主要区别在于，nat表侧重连接而mangle表侧重每一个数据包。[4]其中内建链列表如下。

						    PREROUTING
							    OUTPUT
								    FORWARD
									    INPUT
										    POSTROUTING

											raw表

											raw表用于处理异常，有如下两个内建链：

											    PREROUTING
												    OUTPUT


Netfilter平台中制定了五個封包的掛載點（Hook），分別是PRE_ROUTING、INPUT、OUTPUT、FORWARD與POST_ROUTING。




http://www.gray-world.net/papers/ipccc.pdf



https://www.linkedin.com/in/1391




https://en.wikipedia.org/wiki/Return-to-libc_attack



https://en.wikipedia.org/wiki/Buffer_overflow#Heap-based_exploitation




https://www.cve.org/CVERecord?id=CVE-2015-0235



https://www.offensive-security.com/kali-linux-nethunter-download/


https://stats.nethunter.com/nethunter-images.html

https://www.kali.org/get-kali/

https://www.whonix.org/


	https://en.wikipedia.org/wiki/Xpra



	https://en.wikipedia.org/wiki/Niels_Provos


	https://www.kali.org/docs/nethunter/#20-nethunter-supported-devices-and-roms


用 Git 维护博客？酷！

http://10.10.50.50:9000/kb/#feature_scope_project_management_etc

https://www.worldhello.net/2012/08/14/git-quiz-released-on-github.html


https://en.wikipedia.org/wiki/Nftables


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html

Git测验（A卷）



filter表是默认的表，如果不指明表则使用此表。其通常用于过滤数据包。其中的内建链包括：

    INPUT，输入链。发往本机的数据包通过此链。
	    OUTPUT，输出链。从本机发出的数据包通过此链。
		    FORWARD，转发链。本机转发的数据包通过此链。

			nat表

			nat表如其名，用于地址转换操作。其中的内建链包括：

			    PREROUTING，路由前链，在处理路由规则前通过此链，通常用于目的地址转换（DNAT）。
				    POSTROUTING，路由后链，完成路由规则后通过此链，通常用于源地址转换（SNAT）。
					    OUTPUT，输出链，类似PREROUTING，但是处理本机发出的数据包。

						mangle表

						mangle表用于处理数据包。其和nat表的主要区别在于，nat表侧重连接而mangle表侧重每一个数据包。[4]其中内建链列表如下。

						    PREROUTING
							    OUTPUT
								    FORWARD
									    INPUT
										    POSTROUTING

											raw表

											raw表用于处理异常，有如下两个内建链：

											    PREROUTING
												    OUTPUT


Netfilter平台中制定了五個封包的掛載點（Hook），分別是PRE_ROUTING、INPUT、OUTPUT、FORWARD與POST_ROUTING。




http://www.gray-world.net/papers/ipccc.pdf



https://www.linkedin.com/in/1391




https://en.wikipedia.org/wiki/Return-to-libc_attack



https://en.wikipedia.org/wiki/Buffer_overflow#Heap-based_exploitation




https://www.cve.org/CVERecord?id=CVE-2015-0235



https://www.offensive-security.com/kali-linux-nethunter-download/


https://stats.nethunter.com/nethunter-images.html

https://www.kali.org/get-kali/

https://www.whonix.org/


	https://en.wikipedia.org/wiki/Xpra



	https://en.wikipedia.org/wiki/Niels_Provos


	https://www.kali.org/docs/nethunter/#20-nethunter-supported-devices-and-roms


用 Git 维护博客？酷！

http://10.10.50.50:9000/kb/#feature_scope_project_management_etc

https://www.worldhello.net/2012/08/14/git-quiz-released-on-github.html


https://en.wikipedia.org/wiki/Nftables


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html


file:///aaron/qrcode/World%20Hello%20-%20Git%E6%B5%8B%E9%AA%8C%EF%BC%88A%E5%8D%B7%EF%BC%89.html

Git测验（A卷）



filter表是默认的表，如果不指明表则使用此表。其通常用于过滤数据包。其中的内建链包括：

    INPUT，输入链。发往本机的数据包通过此链。
	    OUTPUT，输出链。从本机发出的数据包通过此链。
		    FORWARD，转发链。本机转发的数据包通过此链。

			nat表

			nat表如其名，用于地址转换操作。其中的内建链包括：

			    PREROUTING，路由前链，在处理路由规则前通过此链，通常用于目的地址转换（DNAT）。
				    POSTROUTING，路由后链，完成路由规则后通过此链，通常用于源地址转换（SNAT）。
					    OUTPUT，输出链，类似PREROUTING，但是处理本机发出的数据包。

						mangle表

						mangle表用于处理数据包。其和nat表的主要区别在于，nat表侧重连接而mangle表侧重每一个数据包。[4]其中内建链列表如下。

						    PREROUTING
							    OUTPUT
								    FORWARD
									    INPUT
										    POSTROUTING

											raw表

											raw表用于处理异常，有如下两个内建链：

											    PREROUTING
												    OUTPUT


Netfilter平台中制定了五個封包的掛載點（Hook），分別是PRE_ROUTING、INPUT、OUTPUT、FORWARD與POST_ROUTING。




http://www.gray-world.net/papers/ipccc.pdf



https://www.linkedin.com/in/1391




https://en.wikipedia.org/wiki/Return-to-libc_attack



https://en.wikipedia.org/wiki/Buffer_overflow#Heap-based_exploitation




https://www.cve.org/CVERecord?id=CVE-2015-0235



https://www.offensive-security.com/kali-linux-nethunter-download/


https://stats.nethunter.com/nethunter-images.html

https://www.kali.org/get-kali/

https://www.whonix.org/


	https://en.wikipedia.org/wiki/Xpra



	https://en.wikipedia.org/wiki/Niels_Provos


	https://www.kali.org/docs/nethunter/#20-nethunter-supported-devices-and-roms


用 Git 维护博客？酷！

http://10.10.50.50:9000/kb/#feature_scope_project_management_etc




