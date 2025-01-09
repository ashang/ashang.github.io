---
title: NIC bonding and teaming
---

## bond 绑定聚合

将多条以太网物理链路捆绑在一起成为一条逻辑链路，从而实现增加链路带宽的目的。同时，这些捆绑在一起的链路通过相互间的动态备份，可以有效地提高链路的可靠性。

功能：

- 增加了带宽---将多个链路的容量组合到一个逻辑链路中。
- 自动故障转移/故障恢复---将来自故障链路的通信转移到聚合中的工作链路。
- 负载均衡---传入和外发通信都是根据用户选择的负载均衡策略（如源和目标 MAC 或 IP 地址）进行分配的。
- 改进了管理---所有接口作为一个单元进行管理。
- 减少了网络地址池消耗---可以将一个 IP 地址指定给整个聚合。

### bond 模式

bond 提供了（0-6）共7种工作模式：
- mode=0 round-robin轮询策略（balance-rr）
- mode=1 active-backup主备策略（active-backup）
- mode=2 load balancing (xor)异或策略(balance-xor)
- mode=3 fault-tolerance (broadcast)广播策略(broadcast)
- mode=4 lacp IEEE 802.3ad 动态链路聚合(IEEE 802.3ad Dynamic link aggregation) （802.3ad）
- mode=5 transmit load balancing适配器传输负载均衡（balance-tlb）
- mode=6 adaptive load balancing适配器负载均衡（balance-alb）

mode=0（balance-rr）
表示负载分担round-robin，并且是轮询的方式比如第一个包走eth0，第二个包走eth1，直到数据包发送完毕。

优点：流量提高一倍

缺点：需要接入交换机做端口聚合，否则可能无法使用

mode=1（active-backup）
表示主备模式，即同时只有1块网卡在工作。

优点：冗余性高

缺点：链路利用率低，两块网卡只有1块在工作

mode=2(balance-xor)(平衡策略)

表示XOR Hash负载分担，和交换机的聚合强制不协商方式配合。（需要xmit_hash_policy，需要交换机配置port channel）

特点：基于指定的传输HASH策略传输数据包。缺省的策略是：(源MAC地址 XOR 目标MAC地址) % slave数量。其他的传输策略可以通过xmit_hash_policy选项指定，此模式提供负载平衡和容错能力

mode=3(broadcast)(广播策略)

表示所有包从所有网络接口发出，这个不均衡，只有冗余机制，但过于浪费资源。此模式适用于金融行业，因为他们需要高可靠性的网络，不允许出现任何问题。需要和交换机的聚合强制不协商方式配合。

特点：在每个slave接口上传输每个数据包，此模式提供了容错能力

mode=4(802.3ad)(IEEE 802.3ad 动态链接聚合)

表示支持802.3ad协议，和交换机的聚合LACP方式配合（需要xmit_hash_policy）.标准要求所有设备在聚合操作时，要在同样的速率和双工模式，而且，和除了balance-rr模式外的其它bonding负载均衡模式一样，任何连接都不能使用多于一个接口的带宽。

特点：创建一个聚合组，它们共享同样的速率和双工设定。根据802.3ad规范将多个slave工作在同一个激活的聚合体下。外出流量的slave选举是基于传输hash策略，该策略可以通过xmit_hash_policy选项从缺省的XOR策略改变到其他策略。需要注意的是，并不是所有的传输策略都是802.3ad适应的，尤其考虑到在802.3ad标准43.2.4章节提及的包乱序问题。不同的实现可能会有不同的适应性。

必要条件：

    条件1：ethtool支持获取每个slave的速率和双工设定

    条件2：switch(交换机)支持IEEE802.3ad Dynamic link aggregation

    条件3：大多数switch(交换机)需要经过特定配置才能支持802.3ad模式

mode=5(balance-tlb)(适配器传输负载均衡)

是根据每个slave的负载情况选择slave进行发送，接收时使用当前轮到的slave。该模式要求slave接口的网络设备驱动有某种ethtool支持；而且ARP监控不可用。

特点：不需要任何特别的switch(交换机)支持的通道bonding。在每个slave上根据当前的负载（根据速度计算）分配外出流量。如果正在接受数据的slave出故障了，另一个slave接管失败的slave的MAC地址。

必要条件：

    ethtool支持获取每个slave的速率

mode=6(balance-alb)(适配器适应性负载均衡)

在5的tlb基础上增加了rlb(接收负载均衡receiveload balance).不需要任何switch(交换机)的支持。接收负载均衡是通过ARP协商实现的.

特点：该模式包含了balance-tlb模式，同时加上针对IPV4流量的接收负载均衡(receiveload balance, rlb)，而且不需要任何switch(交换机)的支持。接收负载均衡是通过ARP协商实现的。bonding驱动截获本机发送的ARP应答，并把源硬件地址改写为bond中某个slave的唯一硬件地址，从而使得不同的对端使用不同的硬件地址进行通信。来自服务器端的接收流量也会被均衡。当本机发送ARP请求时，bonding驱动把对端的IP信息从ARP包中复制并保存下来。当ARP应答从对端到达时，bonding驱动把它的硬件地址提取出来，并发起一个ARP应答给bond中的某个slave。使用ARP协商进行负载均衡的一个问题是：每次广播 ARP请求时都会使用bond的硬件地址，因此对端学习到这个硬件地址后，接收流量将会全部流向当前的slave。这个问题可以通过给所有的对端发送更新（ARP应答）来解决，应答中包含他们独一无二的硬件地址，从而导致流量重新分布。当新的slave加入到bond中时，或者某个未激活的slave重新激活时，接收流量也要重新分布。接收的负载被顺序地分布（round robin）在bond中最高速的slave上当某个链路被重新接上，或者一个新的slave加入到bond中，接收流量在所有当前激活的slave中全部重新分配，通过使用指定的MAC地址给每个 client发起ARP应答。下面介绍的updelay参数必须被设置为某个大于等于switch(交换机)转发延时的值，从而保证发往对端的ARP应答不会被switch(交换机)阻截。

```sh
$ grep BONDING= /boot/config-5.*
/boot/config-5.17.15-76051715-generic:CONFIG_BONDING=m
/boot/config-5.18.10-76051810-generic:CONFIG_BONDING=m

nmcli connection add con-name bond0 ifname bond0 mode active-backup ip4 172.25.254.177/24 ##添加一个BOND，并设置ip和子网掩码

ping 172.25.254.177 ##此时可以Ping通自己，但ping不同不可以其它主机（因为没有添加有效的物理网卡）

nmcil connection add con-name eth0 ifname eth0 type bond-slave master bond0 ##在bond里面添加eth0卡网

nmcli connection add con-name eth1 ifname eth1 type bond-slave master bond0 ##在bond中添加eth1

ping 172.25.254.77 ##此时，是通这的（主机177和77均可以）

watch -n 1 cat /proc/net/bonding/bond0 ##查看当前bond0的工作状态（是eth0工作，并且eth0和eth1均处于up状态）

#关闭eth0，此时eth1会工作
ifdown eth0

#使eth0开启
ifup eth0

mcli connection show ##查看已有的链接设备

nmcli connection delete bond0 ##删除bond0

nmcli connection delete eth0 ##删除bond0上的eth0

nmcli connection delete eth1 ##删除bond0上的eth1
```

7种工作模式的定义如下：

mode=0 round-robin轮询策略(balance-rr)
cat /proc/net/bonding/bond0 
Bonding Mode: load balancing (round-robin)
此模式下，链路处于负载均衡状态，数据以轮询方式向每条链路发送报文，基于per packet方式发送。即每条链路各一个数据包。这模式好处在于增加了带宽，同时支持容错能力，当有链路出问题，会把流量切换到正常的链路上。该模式下，交换机端需要配置聚合口，在cisco交换机上叫port channel。

mode0工作模式图如下：



mode=1 active-backup主备策略（active-backup)
cat /proc/net/bonding/bond0
Bonding Mode: fault-tolerance (active-backup) 
此模式下，一个端口处于主状态，一个处于备状态，所有流量都在主链路上发出和接收，备用链路不会有任何流量。当主链路端口down掉时，备用端口立即启动接管主状态，从而达到链路冗余热备目的。这种模式接入不需要交换机端支持。

mode1工作模式图如下：



mode=2 load balancing (xor)异或策略(balance-xor)
cat /proc/net/bonding/bond0
Bonding Mode: load balancing (xor) 
在此模式下，通过源和目标mac做hash因子来做xor算法来选择链路，这样就使得到达特定对端的流量总是从同一个接口上发出。和balance-rr一样，交换机端口需要配置为“port channel”。需要注意的是，若选择这种模式，如果所有流量源和目标mac都固定了，例如使用“网关模式”，即所有对外的数据传输均固定走一个网关，那么根据该模式的描述，分发算法算出的线路就一直是同一条，另外一条链路不会有任何数据流，那么这种模式就没有多少意义了。

mode2模式拓补图同mode0、mode1

mode=3 fault-tolerance (broadcast)广播策略
cat /proc/net/bonding/bond0
Bonding Mode: fault-tolerance (broadcast)
这种模式的特点是一个报文会复制两份往bond下的两个接口分别发送出去。当有对端交换机失效，我们感觉不到任何丢包。这个模式也需要交换机配置聚合口。如下图，带dup的行即是重复发往第2个网卡的数据。



mode3模式的拓扑图如下所示：



mode=4 lacp IEEE 802.3ad 动态链路聚合（802.3ad）
该模式拓扑结构与mode1模式相同

cat /proc/net/bonding/bond0
Bonding Mode: IEEE 802.3ad Dynamic link aggregation
该模式是基于IEEE 802.3ad Dynamic link aggregation（动态链接聚合）协议。在该模式下，操作系统和交换机都会创建一个聚合组，在同一聚合组下的网口共享同样的速率和双工设定。操作系统根据802.3ad 协议将多个slave 网卡绑定在一个聚合组下。聚合组向外发送数据选择哪一块儿网卡是基于传输hash 策略，该策略可以通过xmit_hash_policy 选项从缺省的XOR 策略改变到其他策略。

该模式的必要条件：

1、ethtool 支持获取每个slave 的速率和双工设定；

2、交换机支持IEEE 802.3ad Dynamic link aggregation（动态链路聚合）。大多数交换机需要经过特定配置才能支持802.3ad模式。

mode=5 transmit load balancing适配器传输负载均衡（balance-tlb）
cat /proc/net/bonding/bond0
Bonding Mode: transmit load balancing
这种模式相较mode2异或策略及mode4 LACP模式的hash策略相对智能，会主动根据对端的MAC地址上的流量，智能的分配流量从哪个网卡发出。但不足之处在于，仍使用一块网卡接收数据。存在的问题与load balancing (xor)也是一样的一样，如果对端MAC地址是唯一的，那么策略就会失效。这个模式下bond成员使用各自的mac，而不是上面几种模式是使用bond0接口的mac。此模式无需交换机支持。

此模式拓扑图如下：



mode=6 adaptive load balancing适配器负载均衡（balance-alb）
此模式拓扑结构与mode5相同。

cat /proc/net/bonding/bond0
Bonding Mode: adaptive load balancing
该模式除了balance-tlb适配器传输负载均衡模式的功能外，同时加上针对IPV4流量接收的负载均衡。接收负载均衡是通过ARP协商实现的。在进行ARP协商的过程中，bond模块将对端和本地的mac地址进行绑定，这样从同一端发出的数据，在本地也会一直使用同一块网卡来接收。若是网络上发出的广播包，则由不同网卡轮询的方式来进行接收。通过这种方式实现了接收的负载均衡。该模式同样无需交换机支持。

注意：在网卡绑定的七种模式下，其中mode=0、2、3需要交换机支持EtherChannel，mode=4需要交换机同时支持EtherChannel和LACP，mode=1、5、6不需要交换机配置支持。

以上7种工作模式，可以根据实际生产环境中的业务场景需求来灵活的选择配置。

Linux多网卡bond配置
1、手动创建配置文件方式

创建bond0网卡配置文件
[root@centos6 ~]#vim /etc/sysconfig/network-scripts/ifcfg-bond0 
DEVICE=bond0                           #虚拟网卡设备名称
BOOTPROTO=none                         #使用静态IP
BONDING_OPTS="mode=1 miimon=100"   #bond模式设定，此例使用mode1模式 miimon=100 为每隔100ms监控主网卡的状态
IPADDR=192.168.20.100    #IP地址
PREFIX=24                #子网掩码
GATEWAY=192.168.20.2     #默认网关
DNS1=114.114.114.114     #DNS服务器

修改第一块网卡配置文件
vim /etc/sysconfig/network-scripts/ifcfg-eth0
DEVICE=eth0
BOOTPROTO=none
MASTER=bond0
SLAVE=yes

修改第二块网卡配置文件
vim /etc/sysconfig/network-scripts/ifcfg-eth1
DEVICE=eth1
BOOTPROTO=none
MASTER=bond0
SLAVE=yes

将所有物理网卡启用
[root@centos6 ~]#cd /etc/sysconfig/network-scripts/
ifconfig eth0 up
ifconfig eth1 up

重启网络服务
[root@centos6 ~]#/etc/init.d/network restart
Shutting down interface bond0:                             [  OK  ]
Shutting down loopback interface:                          [  OK  ]
Bringing up loopback interface:                            [  OK  ]
Bringing up interface bond0:  Determining if ip address 192.168.20.100 is already in use for device bond0...
                                                           [  OK  ]
[root@centos6 ~]#

可以看到bond0网络已成功启动并获得IP地址=
查看一下当前bond0网卡的工作状态

[root@centos6 ~]#cat /proc/net/bonding/bond0 
Ethernet Channel Bonding Driver: v3.7.1 (April 27, 2011)

Bonding Mode: fault-tolerance (active-backup)
Primary Slave: None
Currently Active Slave: eth0
MII Status: up
MII Polling Interval (ms): 100
Up Delay (ms): 0
Down Delay (ms): 0

Slave Interface: eth0
MII Status: up
Speed: 1000 Mbps
Duplex: full
Link Failure Count: 0
Permanent HW addr: 00:0c:29:54:90:f2
Slave queue ID: 0

Slave Interface: eth1
MII Status: up
Speed: 1000 Mbps
Duplex: full
Link Failure Count: 0
Permanent HW addr: 00:0c:29:54:90:fc
Slave queue ID: 0
[root@centos6 ~]#

可以看到当前工作在mode1模式，且eth0网卡为活动的主网卡，eth1处于备用状态

注意：在centos6系统下，由于NetworkManager服务于network会存在相互干扰问题，建议将NetworkManager服务停止，否则容易导致发生以下错误。


禁用NetworkManager服务

[root@centos6 network-scripts]#/etc/init.d/NetworkManager stop
[root@centos6 network-scripts]#chkconfig NetworkManager off

2、通过nmcli命令配置网卡bond

在centos7下，可以通过nmctl命名来创建多网卡bond配置。

创建bond接口并设置IP地址信息
[root@centos7 ~]#nmcli connection add type bond con-name bond0 ifname bond0 mode active-backup ipv4.method manual ipv4.addresses 192.168.20.100/24 ipv4.gateway 192.168.20.2 ipv4.dns 192.168.20.2
Connection 'bond0' (24e90eef-a160-4cc0-af86-9e13259696ba) successfully added.
[root@centos7 ~]#

将物理网卡添加到bond0作为从属接口
[root@centos7 ~]#nmcli connection add type bond-slave ifname eth0 master bond0 
Connection 'bond-slave-eth0' (bb89e659-a59e-4611-8fbb-a97a99840b66) successfully added.
[root@centos7 ~]#nmcli connection add type bond-slave ifname eth1 master bond0 
Connection 'bond-slave-eth1' (7081209c-09d0-4fb9-aaa9-2564613590b9) successfully added.
[root@centos7 ~]#

启动从属接口
[root@centos7 ~]#nmcli connection up bond-slave-eth0
Connection successfully activated (D-Bus active path: /org/freedesktop/NetworkManager/ActiveConnection/46)

[root@centos7 ~]#nmcli connection up bond-slave-eth1 
Connection successfully activated (D-Bus active path: /org/freedesktop/NetworkManager/ActiveConnection/50)


启动bond0
[root@centos7 ~]#nmcli connection up bond0

查看bond连接状态
[root@centos7 ~]#nmcli connection show 
NAME             UUID                                  TYPE      DEVICE 
bond0            24e90eef-a160-4cc0-af86-9e13259696ba  bond      bond0  
bond-slave-eth0  bb89e659-a59e-4611-8fbb-a97a99840b66  ethernet  eth0   
bond-slave-eth1  7081209c-09d0-4fb9-aaa9-2564613590b9  ethernet  eth1   
virbr0           08a6c628-bae9-4157-a4c3-d954bf07fbb9  bridge    virbr0 
eth0             f82cab29-1dd2-4e17-9c66-4a8726b8dd89  ethernet      

查看一下bond0运行模式状态
[root@centos7 ~]#cat /proc/net/bonding/bond0 
Ethernet Channel Bonding Driver: v3.7.1 (April 27, 2011)

Bonding Mode: fault-tolerance (active-backup)
Primary Slave: None
Currently Active Slave: eth0
MII Status: up
MII Polling Interval (ms): 100
Up Delay (ms): 0
Down Delay (ms): 0

Slave Interface: eth0
MII Status: up
Speed: 1000 Mbps
Duplex: full
Link Failure Count: 0
Permanent HW addr: 00:0c:29:d3:63:8c
Slave queue ID: 0

Slave Interface: eth1
MII Status: up
Speed: 1000 Mbps
Duplex: full
Link Failure Count: 0
Permanent HW addr: 00:0c:29:d3:63:96
Slave queue ID: 0
[root@centos7 ~]#

----
从软件的角度来看，多网卡绑定实际上只需要提供一个额外的bond驱动程序即可，通过该虚拟网卡驱动程序可以将实际多块网卡屏蔽，对TCP/IP协议层而言只存在一个Bond网卡。

二、   Linux网卡绑定七种模式详解
Linux网卡绑定共七种模式，分别是如下模式：
- mode=0  round-robin轮询策略(Round-robin policy)

- mode=1  active-backup主备策略(Active-backup policy)

- mode=2  load balancing (xor)异或策略(XOR policy)
- mode=3  fault-tolerance (broadcast)广播策略(Broadcast policy)

- mode=4  lacp IEEE 802.3ad 动态链路聚合(IEEE 802.3ad Dynamic link aggregation)

- mode=5  transmit load balancing适配器传输负载均衡(Adaptive transmit load balancing)
- mode=6  adaptive load balancing适配器负载均衡(Adaptive load balancing)

接下来，我们一一来看每种模式的含义。
1.    round-robin轮询策略

cat /proc/net/bonding/bond0
Bonding Mode: load balancing (round-robin)
该模式下，链路处于负载均衡状态，数据以轮询方式向每条链路发送报文，基于per packet方式发送。即每条链路各一个数据包。这模式好处在于增加了带宽，同时支持容错能力，当有链路出问题，会把流量切换到正常的链路上。该模式下，交换机端需要配置聚合口，在cisco交换机上叫port channel


2.active-backup主备策略

该模式拓扑图与上图相同
cat /proc/net/bonding/bond0
Bonding Mode: fault-tolerance (active-backup)
在该模式下，一个端口处于主状态，一个处于备状态，所有流量都在主链路上发出和接收，备链路不会有任何流量。当主端口down掉时，备端口接管主状态。同时可以设置primary网卡，若primary网卡出现故障，切换至备网卡，primary网卡回复后，流量自动回切。这种模式接入不需要交换机端支持。

3.load balancing (xor)异或策略

该模式拓扑图与上图相同
cat /proc/net/bonding/bond0
Bonding Mode: load balancing (xor)
在该模式下，通过源和目标mac做hash因子来做xor算法来选择链路，这样就使得到达特定对端的流量总是从同一个接口上发出。和balance-rr一样，交换机端口需要能配置为“port channel”。
值得注意的是，若选择这种模式，如果所有流量源和目标mac都固定了，例如使用“网关模式”，即所有对外的数据传输均固定走一个网关，那么根据该模式的描述，分发算法算出的线路就一直是同一条，另外一条链路不会有任何数据流，那么这种模式就没有多少意义了。

4.fault-tolerance (broadcast)广播策略

cat /proc/net/bonding/bond0
Bonding Mode: fault-tolerance (broadcast)
这种模式的特点是一个报文会复制两份往bond下的两个接口分别发送出去。当有对端交换机失效，我们感觉不到任何丢包。这个模式也需要交换机配置聚合口。
拓扑图如下所示：

当一条链路出现故障是不会影响服务器另一条链路正常工作的。而且故障过程是0丢包。下面展示了这种模式下ping信息：

从这个ping信息可以看到，这种模式的特点是，同一个报文服务器会复制两份分别往两条线路发送，导致回复两份重复报文，虽然这种模式不能起到增加网络带宽的效果，反而给网络增加负担，但对于一些需要高可用的环境下，例如RAC的心跳网络，还是有一定价值的。

5.lacp IEEE 802.3ad 动态链路聚合

该模式拓扑结构与主备模式相同
cat /proc/net/bonding/bond0
Bonding Mode: IEEE 802.3ad Dynamic link aggregation
该模式是基于IEEE 802.3ad Dynamic link aggregation（动态链接聚合）协议，针对该协议的介绍，在公众号之前的文章中有所涉及。
在该模式下，操作系统和交换机都会创建一个聚合组，在同一聚合组下的网口共享同样的速率和双工设定。操作系统根据802.3ad 协议将多个slave 网卡绑定在一个聚合组下。聚合组向外发送数据选择哪一块儿网卡是基于传输hash 策略，该策略可以通过xmit_hash_policy 选项从缺省的XOR 策略改变到其他策略。
该模式的必要条件：
- ethtool 支持获取每个slave 的速率和双工设定；
- 交换机支持IEEE 802.3ad Dynamic link aggregation。
大多数交换机需要经过特定配置才能支持802.3ad 模式。

6.transmit load balancing适配器传输负载均衡

cat /proc/net/bonding/bond0
Bonding Mode: transmit load balancing
这种模式相较load balancing (xor)异或策略及LACP模式的hash策略相对智能，会主动根据对端的MAC地址上的流量，智能的分配流量从哪个网卡发出。但不足之处在于，仍使用一块网卡接收数据。存在的问题与load balancing (xor)也是一样的一样，如果对端MAC地址是唯一的，那么策略就会失效。这个模式下bond成员使用各自的mac，而不是上面几种模式是使用bond0接口的mac。无需交换机支持
该模式拓扑图如下：


7.adaptive load balancing适配器负载均衡

该模式拓扑结构与上图一致。
cat /proc/net/bonding/bond0
Bonding Mode: adaptive load balancing
该模式除了balance-tlb适配器传输负载均衡模式的功能外，同时加上针对IPV4流量接收的负载均衡。接收负载均衡是通过ARP协商实现的。在进行ARP协商的过程中，bond模块将对端和本地的mac地址进行绑定，这样从同一端发出的数据，在本地也会一直使用同一块网卡来接收。若是网络上发出的广播包，则由不同网卡轮询的方式来进行接收。通过这种方式实现了接收的负载均衡。该模式同样无需交换机支持。

三、小结
在网卡绑定的七种模式下，其中mode=0、2、3、4需要交换机支持，mode=1、5、6不需要交换机配置支持
-----------------------------------

## team

team也是链路聚合的一种方式
本质上也是一个虚拟的网卡驱动（networkdevicedriver）， 只不过并没有真实的物理网卡与之对应，而是由这个虚拟网卡去“管辖”一系列的真实的物理网卡， 它的代码结构和一般网卡驱动的代码结构非常类似。

- 最多支持8块网卡
- 支持模式
- 广播
- 论旬
- 主备
- 负载均衡

聚合组内的成员端口具有以下两种状态：

>选中状态：此状态下的成员端口可以参与用户数据的转发，处于此状态的成员端口简称为“选中端口”。

>非选中状态：此状态下的成员端口不能参与用户数据的转发，处于此状态的成员端口简称为“非选中端口”。

### team支持的runner方式

- broadcast 广播容错
- roundrobin 平衡轮叫
- activebackup 主备
- loadbalance 负载均衡
- lacp (implements the 802.3ad Link Aggregation Control Protocol)

网络组相关特性

启动网络组接口不会自动启动网络组中的port接口

启动网络组接口中的port接口总会自动启动网络组接口

禁用网络组接口会自动禁用网络组中的port接口

没有port接口的网络组接口可以启动静态IP连接

启用DHCP连接时，没有port接口的网络组会等待port接口的加入

配置：
1、通过nmctl命令创建

创建网络接口组
[root@centos7 ~]#nmcli connection add type team con-name team0 ifname team0 config '{"runner":{"name":"activebackup"}}'
Connection 'team0' (b59f80dc-c425-4fa6-b1ef-2935d290fa6a) successfully added.

创建port接口
[root@centos7 ~]#nmcli connection add type team-slave con-name team0-eth0 ifname eth0 master team0 
Connection 'team0-eth0' (5d7e5824-4d87-449c-8fff-42b2f20bc877) successfully added.
[root@centos7 ~]#nmcli connection add type team-slave con-name team0-eth1 ifname eth1 master team0 
Connection 'team0-eth1' (920f9f03-9f24-40bc-89eb-509e44ee606f) successfully added.

启动team接口
[root@centos7 network-scripts]#nmcli connection up team0 
[root@centos7 network-scripts]#nmcli connection up team0-eth0
[root@centos7 network-scripts]#nmcli connection up team0-eth1

查看team连接状态
[root@centos7 ~]#teamdctl team0 stat
setup:
  runner: activebackup
ports:
  eth0
    link watches:
      link summary: up
      instance[link_watch_0]:
        name: ethtool
        link: up
        down count: 0
  eth1
    link watches:
      link summary: up
      instance[link_watch_0]:
        name: ethtool
        link: up
        down count: 0
runner:
  active port: eth1

2、手动创建配置文件

创建team0接口配置文件
vim /etc/sysconfig/network-scripts/ifcfg-team0
DEVICE=team0
DEVICETYPE=Team
TEAM_CONFIG="{\"runner\": {\"name\": \"broadcast\"}}"
BOOTPROTO=none
IPADDR0=172.16.0.100
PREFIX0=24
NAME=team0
ONBOOT=yes

创建port接口配置文件

/etc/sysconfig/network-scripts/ifcfg-team0-eth0
DEVICE=eth0
DEVICETYPE=TeamPort
TEAM_MASTER=team0
NAME=team0-eth0
ONBOOT=yes

/etc/sysconfig/network-scripts/ifcfg-team0-eth1
DEVICE=eth1
DEVICETYPE=TeamPort
TEAM_MASTER=team0
NAME=team0-eth1
ONBOOT=yes

启动team接口
[root@centos7 ~]#nmcli connection up team0
Connection successfully activated (master waiting for slaves) (D-Bus active path: /org/freedesktop/NetworkManager/ActiveConnection/69)



### 配置

```sh
$ grep NET_TEAM= /boot/config-5.*
/boot/config-5.17.15-76051715-generic:CONFIG_NET_TEAM=m
/boot/config-5.18.10-76051810-generic:CONFIG_NET_TEAM=m

#添加team0，且方式为主备
nmcli connection add con-name team0 ifname team0 type team config '{"runner":{"name":"activebackup"}}' ip4 172.25.254.177/24
watch -n 1 teamdctl team0 state

#在team0中添加物理网卡eth0
nmcli connection add con-name eth0 ifname eth0 type team-slave master team0
watch -n 1 teamdctl team0 state

#在team0中添加物理网卡eth1
nmcli connection add con-name eth1 ifname eth1 type team-slave master team0
watch -n 1 teamdctl team0 state

ping 172.25.254.77

#当eth0关闭的时候，此时eth1工作(77主机一直是通的状态)
watch -n 1 teamdctl team0 stat
ifconfig eth0 down
watch -n 1 teamdctl team0 stat

# 当eth0开启的时候，还是eth1工作；除非eth1关闭，才会启动eth0.
ifconfig eth0 up
watch -n 1 teamdctl team0 stat

nmcli connection delete team0
watch -n 1 teamdctl team0 stat

nmcli connection delete eth0
watch -n 1 teamdctl team0 stat

nmcli connection delete eth1
watch -n 1 teamdctl team0 stat
```

## 网桥

网桥工作在数据链路层，可以将两个局域网链连接起来，实现数据的快速传输。

```sh
# 查看网桥
brctl show

brctl addbr br0

ifconfig br0 172.25.254.177/24

#此时没有物理网卡
ping 172.25.254.77

brctl addif br0 eth0

ping 172.25.254.77
brctl show

brctl delif br0 eth0

ifconfig br0 down

brctl delbr br0
```

## Links

- <https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/networking_guide/sec-comparison_of_network_teaming_to_bonding>
- <https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/networking_guide/sec-converting_a_bond_to_a_team>

Regarding the Mode 4 Link Aggregation Control Protocol (LACP) teaming mode, requires configuring the switch to aggregate the links. For more details, see <https://www.kernel.org/doc/Documentation/networking/bonding.txt>

