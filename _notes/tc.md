
http://www.linuxvirtualserver.org/

Linux 虚拟服务器是由一个 Linux 系统的负载均衡器把多
个真实服务器组织起来，成为一个高度可伸缩、高可靠服务器方案。对于
最终用户而言，集群的内部结构识完全透明的，他们只能看到一个单一的
虚拟服务器。
简单地说，无论你针对哪一层流量和是否需要负载均衡，LVS 总有方法来
实现。他们的一些技术非常绝妙！比如，让同一网段上的几台机器使用相
同的 IP，但是关闭它们的 ARP。只有 LVS 服务器才使用 ARP——由它来
决定哪个后端服务器来处理到来的数据包，然后把它发送给对应后端服务
器的 MAC 地址。出去的数据包则直接发给路由器，而不必经过 LVS 机器，
也就是 LVS 不会看到你那发到全世界的 5Gbps 数据流，从而避免了成为
瓶颈。
LVS 在 Linux2.0 和 2.2 上以内核补丁的方式实现，而在 2.4/2.5 上则以
Netfilter 模块的方式实现，不需要内核补丁。他们的 2.4 支持尚处在早期
开发，希望大家捧场并给出回馈和补丁。

# VRRP

虚拟路由器冗余协议的实现(网站)
这纯粹是为了冗余。两台机器，用他们各自的 IP 地址和 MAC 地址构造
出第三个虚拟的 IP 地址和 MAC 地址。最初纯粹为需要固定 MAC 地址的
路由器而设计，其实也可以用在服务器上。
它的可爱之处在于配置异常简单。不需要补丁和编译内核，全是用户级的。
在共同提供一个服务的服务器上运行：
# vrrpd -i eth0 -v 50 10.0.0.22
就可以用了！10.0.0.22 现在代表你的一台服务器，可能是运行 vrrp 守护
程序的第一台机器。现在把这台机器从网络上断开，令一台机器会迅速接
管 10.0.0.22 这个地址及其 MAC 地址。
我这里做了一个试验，并持续运行了 1 分钟。不知为什么，总是 drop my 缺
省网关，但是可以用-n 选项避免。
这就是失效恢复现场：
64 bytes from 10.0.0.22: icmp_seq=3 ttl=255 time=0.2 ms
64 bytes from 10.0.0.22: icmp_seq=6 ttl=255 time=1.8 ms
64 bytes from 10.0.0.22: icmp_seq=7 ttl=255 time=1.7 ms

# 大多数 Linux 发行版和绝大多数 UNIX 都使用古老的 arp, ifconfig 和
route 命令。虽然这些工具能够工作，但它们在 Linux2.2 和更高版本的内核上显
得有一些落伍。比如，现在 GRE 隧道已经成为了路由的一个主要概念，但却不
能通过上述工具来配置。
使用了 iproute2，隧道的配置与其他部分完全集成了。
2.2 和更高版本的 Linux 内核包含了一个经过彻底重新设计的网络子系统。这些
新的代码让 Linux 在操作系统的竞争中取得了功能和性能上的优势。实际上，
Linux 新的路由、过滤和分类代码，从功能和性能上都不弱于现有的那些专业的
路由器、防火墙和流量整形产品。
随着新的网络概念的提出，人们在现有操作系统的现有体系上修修补补来实现他
们。这种固执的行为导致了网络代码中充斥着怪异的行为，这有点像人类的语言。
过去，Linux 模仿了 SunOS 的许多处理方式，并不理想。
这个新的体系则有可能比以往任何一个版本的 Linux 都更善于清晰地进行功能
表达。

确认一下你的内核支持 netlink ，Iproute2 需要它

# ip a

3764: ppp0: <POINTOPOINT,MULTICAST,NOARP,UP> mtu 1492 qdisc pfifo_fast qlen 10
 link/ppp
 inet 212.64.94.251 peer 212.64.94.1/32 scope global ppp0

ppp0地址是 212.64.94.251，不带子网掩码。这意味着这是一个点到点的连接，而且除了
212.64.94.251 之外的地址是对端的。当然，还有很多信息。它还告诉我们这个链
路的另一端只有一个地址：212.64.94.1。/32 意思是说没有表示网络的 bit。


 ip a                                                                                           127 ✘
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host
       valid_lft forever preferred_lft forever
2: wlo1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default qlen 1000
    link/ether b4:69:21:53:28:c0 brd ff:ff:ff:ff:ff:ff
    altname wlp0s20f3
    inet 10.10.50.13/24 brd 10.10.50.255 scope global dynamic noprefixroute wlo1
       valid_lft 29005sec preferred_lft 29005sec
    inet6 fe80::a49c:2ce3:9ab1:dde5/64 scope link noprefixroute
       valid_lft forever preferred_lft forever
3: docker0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default
    link/ether 02:42:32:bf:1c:f1 brd ff:ff:ff:ff:ff:ff
    inet 172.17.0.1/16 brd 172.17.255.255 scope global docker0
       valid_lft forever preferred_lft forever
7: br-a80da0ac7f38: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default
    link/ether 02:42:1b:b8:0e:7e brd ff:ff:ff:ff:ff:ff
    inet 192.168.58.1/24 brd 192.168.58.255 scope global br-a80da0ac7f38
       valid_lft forever preferred_lft forever
8: br-d3426515317e: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN group default
    link/ether 02:42:af:c4:5e:a2 brd ff:ff:ff:ff:ff:ff
    inet 172.18.0.1/16 brd 172.18.255.255 scope global br-d3426515317e
       valid_lft forever preferred_lft forever
    ~/home  ip r                                                                                               ✔
default via 10.10.50.1 dev wlo1 proto dhcp metric 600
10.10.50.0/24 dev wlo1 proto kernel scope link src 10.10.50.13 metric 600
172.17.0.0/16 dev docker0 proto kernel scope link src 172.17.0.1 linkdown
172.18.0.0/16 dev br-d3426515317e proto kernel scope link src 172.18.0.1 linkdown
192.168.58.0/24 dev br-a80da0ac7f38 proto kernel scope link src 192.168.58.1 linkdown

通过“via”这个词断定这是一个网关，我们要把数据包交给它。

世界的其它部分可以通过我们的缺省网关 212.64.94.1 找到


## ARP

删除 espa043 的 ARP 缓冲：
[root@espa041 /home/src/iputils]# ip neigh delete 9.3.76.43 dev eth0
[root@espa041 /home/src/iputils]# ip neigh show
9.3.76.43 dev eth0 nud failed
9.3.76.42 dev eth0 lladdr 00:60:08:3f:e9:f9 nud reachable
9.3.76.1 dev eth0 lladdr 00:06:29:21:73:c8 nud stale

"stale"状态。这意味着 MAC 地址仍然是在册，但是接下来第一次通讯的时候
需要确认一下。


                                                                               ✔
    ~/home  ip rule                                                                                            ✔
0:      from all lookup local
32766:  from all lookup main
32767:  from all lookup default

所有的规则都应用到了所有的包上
(“from all”)。我们前面已经看到了 "main" 表，就是“ip route ls”命令的输出，
但是“local”和“default”是初次见到。


 ip route list table local                                                                      255 ✘
broadcast 10.10.50.0 dev wlo1 proto kernel scope link src 10.10.50.13
local 10.10.50.13 dev wlo1 proto kernel scope host src 10.10.50.13
broadcast 10.10.50.255 dev wlo1 proto kernel scope link src 10.10.50.13
broadcast 127.0.0.0 dev lo proto kernel scope link src 127.0.0.1
local 127.0.0.0/8 dev lo proto kernel scope host src 127.0.0.1
local 127.0.0.1 dev lo proto kernel scope host src 127.0.0.1
broadcast 127.255.255.255 dev lo proto kernel scope link src 127.0.0.1
broadcast 172.17.0.0 dev docker0 proto kernel scope link src 172.17.0.1 linkdown
local 172.17.0.1 dev docker0 proto kernel scope host src 172.17.0.1
broadcast 172.17.255.255 dev docker0 proto kernel scope link src 172.17.0.1 linkdown
broadcast 172.18.0.0 dev br-d3426515317e proto kernel scope link src 172.18.0.1 linkdown
local 172.18.0.1 dev br-d3426515317e proto kernel scope host src 172.18.0.1
broadcast 172.18.255.255 dev br-d3426515317e proto kernel scope link src 172.18.0.1 linkdown
broadcast 192.168.58.0 dev br-a80da0ac7f38 proto kernel scope link src 192.168.58.1 linkdown
local 192.168.58.1 dev br-a80da0ac7f38 proto kernel scope host src 192.168.58.1
broadcast 192.168.58.255 dev br-a80da0ac7f38 proto kernel scope link src 192.168.58.1 linkdown


 ip route list table main                                                                           ✔
default via 10.10.50.1 dev wlo1 proto dhcp metric 600
10.10.50.0/24 dev wlo1 proto kernel scope link src 10.10.50.13 metric 600
172.17.0.0/16 dev docker0 proto kernel scope link src 172.17.0.1 linkdown
172.18.0.0/16 dev br-d3426515317e proto kernel scope link src 172.18.0.1 linkdown
192.168.58.0/24 dev br-a80da0ac7f38 proto kernel scope link src 192.168.58.1 linkdown


 more /etc/iproute2/rt_tables                                                                       ✔
#
# reserved values
#
255     local
254     main
253     default
0       unspec
#
# local
#
#1      inr.ruhep


以向 /etc/iproute2/rt_tables 文件中添加数
字与名字的关联：
# echo 200 John >> /etc/iproute2/rt_tables
# ip rule add from 10.0.0.10 table John
# ip rule ls
0: from all lookup local
32765: from 10.0.0.10 lookup John
32766: from all lookup main
32767: from all lookup default

现在，剩下的事情就是为 John 的路由表创建路由项了。别忘了刷新路由缓存：
# ip route add default via 195.96.98.253 dev ppp2 table John
# ip route flush cache

至于如何在 ip-up 阶段实现就留给读者自己去研究吧

# Tunneling

