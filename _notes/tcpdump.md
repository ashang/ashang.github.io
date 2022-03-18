---
title: tcpdump
date: 2016-10-15
---

```shell
tcpdump -i <interfacename> src host 10.132.52.10 -w <dump-file>

tcpdump -i vlan.3 -nev arp and icmp

tcpdump -i eth0 host 10.132.36.9 -w /home/admin/snmp.pcap

tcpdump -i vlan.3 -w /home/admin/lacp.pcap

tcpdump -n -i ens192  port bootps or port bootpc -v

tcpdump -n -s 4096 -w 1.log port 80
```

- strace/dtruss: 系统调用跟踪工具
- lsof: 列出文件打开情况
- valgrind: 查内存泄露
- ltrace: 查询库调用

```shell
tcpdump -n -i eth0 |grep 8.8.8.8.53
```

```shell
# tcpdump -c 9
tcpdump: verbose output suppressed, use -v or -vv for full protocol decode
listening on wlo1, link-type EN10MB (Ethernet), capture size 262144 bytes
15:33:06.562311 IP i5.perm.35176 > 10.10.50.50.ssh: Flags [P.], seq 403708645:403708681, ack 4233143953, win 12337, options [nop,nop,TS val 1676976373 ecr 1482916223], length 36
15:33:06.562335 IP 10.10.50.50.ssh > i5.perm.35176: Flags [.], seq 1:1449, ack 4294967260, win 2002, options [nop,nop,TS val 1482916223 ecr 1676976298], length 1448
15:33:06.562903 IP 10.10.50.50.ssh > i5.perm.35176: Flags [.], seq 1449:2897, ack 4294967260, win 2002, options [nop,nop,TS val 1482916223 ecr 1676976298], length 1448
15:33:06.562914 IP i5.perm.35176 > 10.10.50.50.ssh: Flags [.], ack 2897, win 12337, options [nop,nop,TS val 1676976374 ecr 1482916223], length 0
15:33:06.565757 IP 10.10.50.50.ssh > i5.perm.35176: Flags [.], seq 2897:8689, ack 4294967260, win 2002, options [nop,nop,TS val 1482916226 ecr 1676976301], length 5792
15:33:06.565777 IP i5.perm.35176 > 10.10.50.50.ssh: Flags [.], ack 8689, win 12337, options [nop,nop,TS val 1676976377 ecr 1482916226], length 0
15:33:06.565811 IP 10.10.50.50.ssh > i5.perm.35176: Flags [.], seq 8689:10137, ack 4294967260, win 2002, options [nop,nop,TS val 1482916226 ecr 1676976302], length 1448
15:33:06.566295 IP 10.10.50.50.ssh > i5.perm.35176: Flags [.], seq 10137:11585, ack 4294967260, win 2002, options [nop,nop,TS val 1482916226 ecr 1676976302], length 1448
15:33:06.566304 IP i5.perm.35176 > 10.10.50.50.ssh: Flags [.], ack 11585, win 12337, options [nop,nop,TS val 1676976377 ecr 1482916226], length 0
9 packets captured
328 packets received by filter
292 packets dropped by kernel
```

不作网络管理用途的计算机上不应该运行这一类的网络分析软件，为了屏蔽它们，可以屏蔽内核中的 bpfilter 伪设备。一般情况下网络硬件和TCP/IP堆栈不支持接收或发送与本计算机无关的数据包，为了接收这些数据包，就必须使用网卡的混杂模式，并绕过标准的TCP/IP堆栈才行。在FreeBSD下，这就需要内核支持伪设备bpfilter。因此，在内核中取消bpfilter支持，就能屏蔽tcpdump之类的网络分析工具。
            并且当网卡被设置为混杂模式时，系统会在控制台和日志文件中留下记录，提醒管理员留意这台系统是否被用作攻击同网络的其他计算机的跳板。

    May 15 16:27:20 host1 /kernel: fxp0: promiscuous mode enabled
                    虽然网络分析工具能将网络中传送的数据记录下来，但是网络中的数据流量相当大，如何对这些数据进行分析、分类统计、发现并报告错误却是更关键的问题。网络中的数据包属于不同的协议，而不同协议数据包的格式也不同。因此对捕获的数据进行解码，将包中的信息尽可能的展示出来，对于协议分析工具来讲更为重要。昂贵的商业分析工具的优势就在于它们能支持很多种类的应用层协议，而不仅仅只支持 tcp、udp 等低层协议。

tcpdump对截获的数据并没有进行彻底解码，数据包内的大部分内容是使用十六进制的形式直接打印输出的。显然这不利于分析网络故障，通常的解决办法是先使用带-w参数的tcpdump 截获数据并保存到文件中，然后再使用其他程序进行解码分析。当然也应该定义过滤规则，以避免捕获的数据包填满整个硬盘。FreeBSD提供的一个有效的解码程序为tcpshow，它可以通过Packages Collection来安装。

```shell
# pkg_add /cdrom/packages/security/tcpshow*
# tcpdump -c 3 -w tcpdump.out
tcpdump: listening on fxp0
# tcpshow < tcpdump.out
---------------------------------------------------------------------------
Packet 1
TIME:12:00:59.984829
LINK:00:10:7B:08:3A:56 -> 01:80:C2:00:00:00 type=0026
<*** No decode support for encapsulated protocol ***>
---------------------------------------------------------------------------
Packet 2
TIME:12:01:01.074513 (1.089684)
LINK:00:A0:C9:AB:3C:DF -> FF:FF:FF:FF:FF:FF type=ARP
ARP:htype=Ethernet ptype=IP hlen=6 plen=4 op=request
sender-MAC-addr=00:A0:C9:AB:3C:DF sender-IP-address=202.102.245.3
target-MAC-addr=00:00:00:00:00:00 target-IP-address=202.102.245.3
---------------------------------------------------------------------------
Packet 3
TIME:12:01:01.985023 (0.910510)
LINK:00:10:7B:08:3A:56 -> 01:80:C2:00:00:00 type=0026
<*** No decode support for encapsulated protocol ***>
```

Ethereal运行在X Window 下

Sniffit使用字符窗口形式。

为了防止数据被滥用的网络分析工具截获，关键还是要在网络的物理结构上解决。

常用的方法是使用交换机或网桥将信任网络和不信任网络分隔开，可以防止外部网段窃听内部数据传输，但仍然不能解决内部网络与外部网络相互通信时的数据安全问题。

如果没有足够的经费将网络上的共享集线器升级为以太网交换机，可以使用FreeBSD系统执行网桥任务。

这需要使用option BRIDGE编译选项重新定制内核，此后使用bridge命令启动网桥功能。

```shell
tcpdump [ -adeflnNOpqStvx ] [ -c 数量 ] [ -F 文件名 ]
    [ -i 网络接口 ] [ -r 文件名』 [ -s snaplen ]
    [ -T 类型 ] [ -w 文件名 ] 『表达式 ]
```

```shell
-a 　　　将网络地址和广播地址转变成名字；
-d 　　　将匹配信息包的代码以人们能够理解的汇编格式给出；
-dd 　　 将匹配信息包的代码以 c 语言程序段的格式给出；
-ddd 　　将匹配信息包的代码以十进制的形式给出；
-e 　　　在输出行打印出数据链路层的头部信息；
-f 　　　将外部的 Internet 地址以数字的形式打印出来；
-l 　　　使标准输出变为缓冲行形式；
-n 　　　不把网络地址转换成名字；
-t 　　　在输出的每一行不打印时间戳；
-v 　　　输出一个稍微详细的信息，例如在 ip 包中可以包括ttl和服务类型的信息；
-vv 　　 输出详细的报文信息；
-c 　　　在收到指定的包的数目后，tcpdump 就会停止；
-F 　　　从指定的文件中读取表达式，忽略其它的表达式；
-i 　　　指定监听的网络接口；
-r 　　　从指定的文件中读取包（这些包一般通过 -w 选项产生）；
-w 　　　直接将包写入文件中，并不分析和打印出来；
-T 　　　将监听到的包直接解释为指定的类型的报文，常见的类型有 rpc （远程过程调用）和snmp（简单网络管理协议；）
```

第一种是关于类型的关键字，主要包括 host，net，port, 例如 host 210.27.48.2，指明 210.27.48.2 是一台主机，net 202.0.0.0 指明 202.0.0.0是一个网络地址，port 23 指明端口号是23。如果没有指定类型，缺省的类型是host.

第二种是确定传输方向的关键字，主要包括 src , dst ,dst or src, dst and src , 这些关键字指明了传输的方向。举例说明，src 210.27.48.2 ,指明ip包中源地址是210.27.48.2 , dst net 202.0.0.0 指明目的网络地址是202.0.0.0 。如果没有指明方向关键字，则缺省是src or dst关键字。

第三种是协议的关键字，主要包括 fddi,ip,arp,rarp,tcp,udp 等类型。Fddi指明是在FDDI（分布式光纤数据接口网络）上的特定的网络协议，实际上它是"ether"的别名，fddi和ether具有类似的源地址和目的地址，所以可以将fddi协议包当作ether的包进行处理和分析。其他的几个关键字就是指明了监听的包的协议内容。如果没有指定任何协议，则tcpdump将会监听所有协议的信息包。
                                                        除了这三种类型的关键字之外，其他重要的关键字如下：gateway, broadcast,less,greater, 还有三种逻辑运算，取非运算是 'not ' '! ', 与运算是'and','&&';或运算 是'or' ,'││'；这些关键字可以组合起来构成强大的组合条件来满足人们的需要，下面举几个例子来说明。

A 想要截获所有 210.27.48.1 的主机收到的和发出的所有的数据包：

#tcpdump host 210.27.48.1

B 想要截获主机 210.27.48.1 和主机210.27.48.2 或210.27.48.3的通信

#tcpdump host 210.27.48.1 and \(210.27.48.2 or 210.27.48.3 \)

C 如果想要获取主机 210.27.48.1除了和主机210.27.48.2之外所有主机通信的ip包

#tcpdump ip host 210.27.48.1 and ! 210.27.48.2

D 如果想要获取主机 210.27.48.1接收或发出的telnet包，使用如下命令：

#tcpdump tcp port 23 host 210.27.48.1

#tcpdump --e host ice

ice 是一台装有 linux 的主机，她的MAC地址是0：90：27：58：AF：1A
H219 是一台装有 SOLARIC的SUN工作站，它的MAC地址是8：0：20：79：5B：46

21:50:12.847509 eth0 < 8:0:20:79:5b:46 0:90:27:58:af:1a ip 60: h219.33357 > ice.telne
t 0:0(0) ack 22535 win 8760 (DF)

eth0 《表示从网络接口eth0 接受该数据包，eth0 >表示从网络接口设备发送数据包，8:0:20:79:5b:46是主机H219的MAC地址,它表明是从源地址H219发来的数据包。0:90:27:58:af:1a是主机ICE的MAC地址,表示该数据包的目的地址是ICE . ip 是表明该数据包是IP数据包,60 是数据包的长度, h219.33357 > ice.telnet 表明该数据包是从主机H219的33357端口发往主机ICE的TELNET(23)端口. ack 22535 表明对序列号是222535的包进行响应

B,ARP 包的 TCPDUMP输出信息

## tcpdump arp

```log
# tcpdump arp
ARP, Request who-has tracy.mysite tell mfp-m228.mysite, length 46
ARP, Request who-has 10.10.50.108 tell 10.10.50.8, length 46
ARP, Request who-has 10.10.50.95 tell 10.10.50.8, length 46
ARP, Request who-has 10.10.50.91 tell 10.10.50.8, length 46
ARP, Request who-has 10.10.50.88 tell 10.10.50.8, length 46
ARP, Request who-has HNR_9X-573faf003efed848.mysite tell 10.10.50.8, length 46
ARP, Request who-has 10.10.50.78 tell 10.10.50.8, length 46
```

22:32:42.802509 eth0 > arp who-has route tell ice (0:90:27:58:af:1a)
22:32:42.802902 eth0 < arp reply route is-at 0:90:27:12:10:66 (0:90:27:58:af:1a)

src > dst: flags data-seqno ack window urgent options
src > dst: 表明从源地址到目的地址，flags是 TCP包中的标志信息,S 是SYN标志, F (FIN), P (PUSH) , R (RST) "." （没有标记）; data-seqno是数据包中的数据的顺序号, ack是下次期望的顺序号, window是接收缓存的窗口大小, urgent表明数据包中是否有紧急指针。Options是选项.

UDP 包的输出信息

```log
# tcpdump port 53
IP dev12.mysite.49232 > dev10.mysite.domain: 25252+ A? dev18.mysite. (35)
IP dev12.mysite.52130 > dev10.mysite.domain: 60600+ AAAA? dev18.mysite. (35)
IP dev10.mysite.domain > dev12.mysite.49232: 25252* 1/0/0 A 10.10.50.18 (51)
IP dev10.mysite.domain > dev12.mysite.52130: 60600 0/0/0 (35)
IP dev12.mysite.40430 > dev10.mysite.domain: 19512+ PTR? 18.50.10.10.in-addr.arpa. (42)
IP dev12.mysite.44877 > dev10.mysite.domain: 255+ PTR? 10.50.10.10.in-addr.arpa. (42)
IP dev10.mysite.domain > dev12.mysite.40430: 19512* 1/0/0 PTR dev18.mysite. (73)
IP dev10.mysite.domain > dev12.mysite.44877: 255* 1/0/0 PTR dev10.mysite. (73)
IP dev12.mysite.57506 > dev10.mysite.domain: 51324+ PTR? 12.50.10.10.in-addr.arpa. (42)
IP dev10.mysite.domain > dev12.mysite.57506: 51324* 1/0/0 PTR dev12.mysite. (73)
IP dev12.mysite.40179 > dev10.mysite.domain: 46509+ A? optimizationguide-pa.googleapis.com. (53)
IP dev10.mysite.domain > dev12.mysite.40179: 46509 1/0/0 A 142.251.42.234 (69)
```

## Flags

- . ack
- P
- R rst
- S syn

## BPF Filters

- and, or, not
- port, by default both tcp and udp
- host
- src, dst

## tshark

## Incatation to wireshark

```
$ ssh remote.host tcpdump -pni any -w - -s0 -U port 8888 | wireshark -k -i -
```

## DNS

```
$ tcpdump -n -i any port 12345
$ tcpdump -n port 12345 and host 1.2.3.4
```

```
$ tcpdump udp[11] & 0xf==3 # Failed DNS queries, NX DOMAIN
$ tcpdump -w packets.pcap
```

```
$ tcpdump -n -i any port 53
tcpdump: data link type LINUX_SLL2
tcpdump: verbose output suppressed, use -v[v]... for full protocol decode
listening on any, link-type LINUX_SLL2 (Linux cooked v2), snapshot length 262144 bytes
14:27:29.381265 wlo1  In  IP 10.10.50.10.53 > 10.10.50.13.41462: 63669 1/0/0 A 77.88.21.37 (49)
14:27:29.405404 wlo1  In  IP 10.10.50.10.53 > 10.10.50.13.41462: 15564 1/0/0 AAAA 2a02:6b8::a4 (61)

14:27:40.867691 wlo1  Out IP 10.10.50.13.49594 > 10.10.50.10.53: 20017+ A? mmbiz.qpic.cn. (31)
14:27:40.867702 wlo1  Out IP 10.10.50.13.49594 > 10.10.50.10.53: 50483+ AAAA? mmbiz.qpic.cn. (31)
14:27:40.869760 wlo1  In  IP 10.10.50.10.53 > 10.10.50.13.49594: 20017 12/0/0 CNAME mmbiz.qpic.tc.qq.com., CNAME mmbiz.mid.tdnsv6.com., CNAME mmbiz.qpic.cn.sched.legopic1-dk.tdnsv6.com., A 150.138.190.142, A 42.81.85.245, A 150.138.190.18, A 150.138.190.220, A 150.138.190.97, A 150.138.190.230, A 150.138.190.229, A 1.183.73.92, A 59.49.91.65 (299)
14:27:40.874591 wlo1  In  IP 10.10.50.10.53 > 10.10.50.13.49594: 50483 10/0/0 CNAME mmbiz.qpic.tc.qq.com., CNAME mmbiz.mid.tdnsv6.com., CNAME mmbiz.qpic.cn.sched.legopic1-dk.tdnsv6.com., AAAA 240e:944:e:3:28::, AAAA 240e:944:e:3:66::, AAAA 240e:944:e:3:50::, AAAA 240e:944:e:3:30::, AAAA 240e:918:1a00:101:40::2, AAAA 240e:944:e:3:27::, AAAA 240e:944:e:3:35:: (338)
14:27:46.051330 wlo1  Out IP 10.10.50.13.43003 > 10.10.50.10.53: 27010+ A? res-1.cdn.office.net. (38)
14:27:46.051353 wlo1  Out IP 10.10.50.13.43003 > 10.10.50.10.53: 9349+ AAAA? res-1.cdn.office.net. (38)
14:27:46.068955 wlo1  In  IP 10.10.50.10.53 > 10.10.50.13.43003: 27010 4/0/0 CNAME res-1.cdn.office.net-c.edgekey.net., CNAME res-1.cdn.office.net-c.edgekey.net.globalredir.akadns.net., CNAME e1875.ca.s.tl88.net., A 72.247.12.249 (197)
14:27:46.069472 wlo1  In  IP 10.10.50.10.53 > 10.10.50.13.43003: 9349 3/1/0 CNAME res-1.cdn.office.net-c.edgekey.net., CNAME res-1.cdn.office.net-c.edgekey.net.globalredir.akadns.net., CNAME e1875.ca.s.tl88.net. (243)

28 packets captured
28 packets received by filter
0 packets dropped by kernel
```

## Tcpdump in docker
This simple image runs a tcpdump and writes dumps to the volume /data. It will keep at max 10x 1GB files and overwrite the oldest one.

To capture on the hosts network interfaces, you need to run the container by using the host networking mode:

$ docker run --net=host corfr/tcpdump
To specify filters or interface, you can use this image as you would use tcpdump, but this will override default parameters:

$ docker run --net=host corfr/tcpdump -i eth2 port 80
If you want storage to happen on your host: (the important part is to mount the volume using docker -v, and to write data in that volume using tcpdump -w)

$ docker run --net=host -v $PWD:/data corfr/tcpdump -i any -w /data/dump.pcap "icmp"



To analyze the stream live remotely from wireshark: (don't forget to filter out traffic on port 22)

$ ssh root@remote-host "docker run --rm --net=host corfr/tcpdump -i any -w - not port 22 2>/dev/null" |wireshark -k -i -



docker run --cpus 1 -it corfr/tcpdump -i eth1 -e -v -n



Dockerfile



FROM ubuntu
MAINTAINER Johannes 'fish' Ziemke <docker@freigeist.org>

VOLUME  [ "/dumps" ]
RUN apt-get update &&  apt-get -y -q install tcpdump

ENTRYPOINT [ "/usr/sbin/tcpdump", "-C", "1000", "-W", "100", \
             "-v", "-w", "/dumps/dump" ]



>>

VOLUME  [ "/data" ]

CMD [ "-C", "1000", "-W", "100", "-v", "-w", "/data/dump" ]
ENTRYPOINT [ "/usr/sbin/tcpdump" ]



FROM alpine

RUN apk add --no-cache tcpdump





When tcpdump utility is available you can record the traffic using
tcpdump -i any -s 0 -w file.pcap
or
tcpdump –i any -s 0 -A tcp port 9000

# kaazing/tcpdump

Dockerfile
```
FROM alpine

RUN apk add --update --no-cache tcpdump && rm -rf /var/cache/apk/*

VOLUME  [ "/tcpdump" ]

ENTRYPOINT [ "/usr/sbin/tcpdump" ]

CMD [ "-C", "1000", "-v", "-i", "any", "-w", "/tcpdump/tcpdump.pcap" ]

```

 $ docker run --rm --net=host -v $PWD/tcpdump:/tcpdump kaazing/tcpdump
This will save network traffic in tcpdump/tcpdump.pcap of the current directory.

If you want to save to a different location, change $PWD/tcpdump volume to a directory where you'd like the dumpfile to be saved. On Linux and Mac you can use the $PWD to refer to the current directory. Docker expects an absolute path here, which is why you can't use ./.

You can watch the traffic live in Wireshark using the following command as you run your scenario. This will open Wireshark where you can see the packets, apply filters, etc:

 tail -c +1 -f tcpdump/tcpdump.pcap | wireshark -k -i -

##  with Docker Compose
Add the following service to your docker-compose.yml file.

   tcpdump:
     image: kaazing/tcpdump
     network_mode: "host"
     volumes:
       - ./tcpdump:/tcpdump
    command: [ "-C", "100", "-W", "2", "-v", "-i", "any", "-w", "/tcpdump/myapp.pcap" ]

Start your Docker Compose suite.

The tcpdump service will save network traffic in tcpdump/tcpdump.pcap of the current directory.


#
So I have a docker-compose file in which I defined my own my-custom-network and some containers that are joined to that network. I start the containers normally using docker-compose up and then I ran the following code to capture network packets

docker run --rm --net=my-custom-network -v $PWD/tcpdump:/tcpdump kaazing/tcpdump

This works in capturing all the network traffic from all the containers.



View help and version
$ docker run --rm moncho/tcpdump --help
Examine the host network
$ docker run --rm --net=host -v ~/pcap:/pcap moncho/tcpdump
Examine the TCP traffic on the host network with Wireshark
$ docker run --rm --net=host moncho/tcpdump -i any -w - | wireshark -k -i -
Examine the traffic of Docker container foo with Wireshark
$ docker run --rm --net=container:foo moncho/tcpdump -i any --immediate-mode -w - | wireshark -k -i -
docker run --network=container:pauseId --entrypoint=sh -ti corfr/tcpdump



 to record a day’s worth of traffic into 15 minute chunks.:
tcpdump -G 900 -w '%Y-%m-%d_%H:%M:%S.pcap' -W 96




 dockerfile:
FROM debian
RUN apt-get update && apt-get install -y \
tcpdump
RUN mkdir /pcap
RUN cd /pcap
WORKDIR /pcap
CMD tcpdump -G 900 -w '%Y-%m-%d_%H:%M:%S.pcap' -W 96

From here if you wanted to display the PCAPs in a browser for easy access all you need to do is run
docker run -h tccdumpweb -p 1337:80 -v ~/pcap:/var/www/html/ -d eboraas/apache



#
FROM alpine

# Maintainer
# ----------------------------------------------------------------------
LABEL maintainer="stefan.oehrli@trivadis.com"

# Environment variables required for this build (do NOT change)
# -------------------------------------------------------------
ENV TCPDUMP="/tcpdump"

# RUN as user root
# ----------------------------------------------------------------------
# - install a package used to run tcpdump
RUN apk add --update --no-cache tcpdump && \
    mkdir -p ${TCPDUMP} && \
    rm -rf /var/cache/apk/*

# define a volume for the tcpdump files
VOLUME  [ "${TCPDUMP}" ]

# set workding directory
WORKDIR ${TCPDUMP}

# set the ENTRYPOINT
ENTRYPOINT [ "/usr/sbin/tcpdump" ]

# Define default command for tcpdump
CMD [ "-G", "900", "-v", "-i", "any", "-w", "tcpdump_%Y-%m-%d_%H:%M:%S.pcap", "-W","96"]


# K8s
Service 用于暴露 httpbin，方便发起 HTTP 请求。

apiVersion: v1
kind: Pod
metadata:
  name: tcpdump-demo
  labels:
    app: tcpdump-demo
spec:
  containers:
    - name: httpbin
      image: kennethreitz/httpbin
      ports:
        - containerPort: 80
    - name: tcpdump
      image: corfr/tcpdump
---
apiVersion: v1
kind: Service
metadata:
  name: tcpdump-demo
  labels:
    app: tcpdump-demo
spec:
  ports:
    - port: 80
      protocol: TCP
  selector:
    app: tcpdump-demo
  type: NodePort
你可以通过执行 curl 命令，触发一段测试流量。

curl http://<node-ip>:<node-port>/get
然后，执行如下命令把流量文件拷贝出来，在 Wireshark 等软件中打开。

kubectl cp tcpdump-demo:/data/dump00 ./dump00 -c tcpdump


##
Worker Node
外部流量流入 Pod 前，必须经过 worker node。也就是说，在 worker node 上也可以捕获应用流量。

优点：可以捕获 Pod 启动前的流量

缺点：可能需要指定端口、网卡以避免捕获过多的流量。而查询端口、网卡操作比较麻烦。另外 worker node 上也未必有/允许安装 tcpdump。

tcpdump -C 1000 -W 100 -v -w dump.cap
容器内部执行 tcpdump 命令
直接 kubectl exec -it ...-- bash 进容器，以普通方法执行 tpcdump 命令也是一个可选的方法（大概）。

优点：可以避免容器重启丢失现场

缺点：我不觉得成熟的生产环境应用会开放 root 权限安装 tcpdump...

zypper in -y tcpdump # 或者通过其他系统的包管理工具安装 tcpdump
tcpdump -C 1000 -W 100 -v -w /tmp/dump.cap
之后把流量文件复制出来

kubectl cp tcpdump-demo:/tmp/dump.cap ./dump.cap



#
https://krew.sigs.k8s.io/docs/user-guide/setup/install/

(
  set -x; cd "$(mktemp -d)" &&
  curl -fsSLO "https://github.com/kubernetes-sigs/krew/releases/latest/download/krew.{tar.gz,yaml}" &&
  tar zxvf krew.tar.gz &&
  KREW=./krew-"$(uname | tr '[:upper:]' '[:lower:]')_amd64" &&
  "$KREW" install --manifest=krew.yaml --archive=krew.tar.gz &&
  "$KREW" update
)

然后，记得加到环境变量里面
export PATH="${KREW_ROOT:-$HOME/.krew}/bin:$PATH"
$ kubectl sniff --help
Perform network sniffing on a container running in a kubernetes cluster.
Usage:
  sniff pod [-n namespace] [-c container] [-f filter] [-o output-file] [-l local-tcpdump-path] [-r remote-tcpdump-path] [flags]
Examples:
kubectl sniff hello-minikube-7c77b68cff-qbvsd -c hello-minikube
Flags:
  -c, --container string             container (optional)  # 可选参数，建议显式声明下，不加的话默认就是抓取的第一个container
  -f, --filter string                tcpdump filter (optional)   # 可选参数，等效于tcpdump里面的filter过滤
  -h, --help                         help for sniff
      --image string                 the privileged container image (optional) (default "docker")
  -i, --interface string             pod interface to packet capture (optional) (default "any")   #抓取的网卡接口，建议保持默认的全部接口
  -l, --local-tcpdump-path string    local static tcpdump binary path (optional)
  -n, --namespace string             namespace (optional) (default "default")   # 待抓取的pod所在namespace
  -o, --output-file string           output file path, tcpdump output will be redirect to this file instead of wireshark (optional) ('-' stdout)   # 抓包数据输出的路径或文件
  -p, --privileged                   if specified, ksniff will deploy another pod that have privileges to attach target pod network namespace  # 是否要使用特权模式的ksniff pod进行抓包
  -r, --remote-tcpdump-path string   remote static tcpdump binary path (optional) (default "/tmp/static-tcpdump")
  -v, --verbose                      if specified, ksniff output will include debug information (optional)




原理： 启动一个pod，共享待抓包的pod的网络空间，然后上传一个static-tcpdump(预编译好的tcpdump文件）到待抓包pod的/tmp/目录下，然后启动tcpdump进行抓包。整个过程简单粗暴干脆！

通常的pod的抓包：

$ kubectl sniff -n default nginx-test-69b668b75c-w8pxr -c nginx  -o ./sb-test.cap      # 导出为文件
$ kubectl sniff -n default nginx-test-69b668b75c-w8pxr -c nginx   -o  - | tshark -r -   # tshark需要安装wireshark

# 说明： 启动上面的命令后，会自动在对应的namespace下起一个ksniff-xxxx 的pod，它不会自动销毁，需要我们在抓包完后人工去delete掉这个pod
无特权的pod的抓包：

原理：带有-p这一参数之后，查询目标 Pod 所在节点，然后在该节点上利用节点亲和性创建共享节点网络的特权 Pod，然后在新 Pod 上对流量进行监控。

kubectl sniff -n lens-metrics prometheus-0 -c prometheus  -p -o ./sb-123.cap
kubectl sniff -n lens-metrics prometheus-0 -c prometheus  -p   -o  - | tshark -r -



$ kubectl sniff -n lens-metrics node-exporter-7sgzd -c node-exporter  -p -o - | tshark -r -

$ kubectl get pods   -n lens-metrics -o wide




#  Kubernetes 环境中，针对 Pod 进行抓包是个常规操作，在 Pod 中、在 Node 中都能够完成，抓出文件之后现场查看或者拷贝回来喂给 Wireshark 也都不难。Ksniff工具的作用是，把这些常规步骤组织起来，用一个简单的 kubectl 插件命令，就能完成这一系列的操作。

Ksniff 有几个很有意思的特色：

可以使用 krew 方便的进行安装。
能够自动把 Pod 的 TCP Dump 数据输出给 Wireshark。
能够方便的处理非特权 Pod 的抓包工作。
无需触碰 Node。
安装
使用 Krew 能够很方便的安装 Ksniff：

$ kubectl krew install sniff
Updated the local copy of plugin index.
Installing plugin: sniff
CAVEATS:
\
 |  This plugin needs the following programs:
 |  * wireshark (optional, used for live capture)
/
Installed plugin: sniff
抓包到 Wireshark
部署一个简单的 httpbin 服务：

apiVersion: v1
kind: Service
metadata:
  name: httpbin
  labels:
    app: httpbin
spec:
  ports:
  - name: http
    port: 8000
    targetPort: 80
  selector:
    app: httpbin
---
apiVersion: extensions/v1beta1
kind: Deployment
metadata:
  name: httpbin
spec:
  replicas: 1
  template:
    metadata:
      labels:
        app: httpbin
        version: v1
    spec:
      containers:
      - image: docker.io/kennethreitz/httpbin
        imagePullPolicy: IfNotPresent
        name: httpbin
        ports:
        - containerPort: 80
服务启动之后，再启动一个客户端：

apiVersion: extensions/v1beta1
kind: Deployment
metadata:
  name: sleep
spec:
  replicas: 1
  template:
    metadata:
      labels:
        app: sleep
        version: v1
    spec:
      containers:
        - name: sleep
          image: dustise/sleep
          imagePullPolicy: IfNotPresent
然后就可以启动 ksniff 插件来对 httpbin 的 Pod 进行监听了，例如：

$ kubectl sniff httpbin-5fc7cf895d-lr89b
...
INFO[0000] sniffing method: upload static tcpdump
...
INFO[0000] using tcpdump path at: '/Users/dustise/.krew/store/sniff/

。。。INFO[0002] executing command: '[/tmp/static-tcpdump -i any -U -w - ]' on container: 'httpbin', pod: 'httpbin-5fc7cf895d-lr89b', namespace: 'default'
不难看出，ksniff 非常粗暴的将一个 tcpdump 上传到了被抓包的 Pod 上直接运行。并且命令执行后，直接启动了 Wireshark 进行监听。

下面从 sleep Pod 上给被监听 Pod 制造一点流量。

$ kubectl exec -it sleep-69bd44b5bb-tk6vn -- curl http://httpbin:8000/ip
{
  "origin": "10.244.0.19"
}
在 Wireshark 中会看到相应的数据包：

wireshark

查看一下被监听 Pod 的进程：

$ kubectl exec -it httpbin-5fc7cf895d-lr89b -- ps aux
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.0  0.6  85980 25100 ?        Ss   15:42   0:01 /usr/bin/python
root         8  0.0  0.8 130364 35164 ?        S    15:42   0:01 /usr/bin/python
root        35  0.0  0.0   6392  3568 ?        Ss   15:50   0:00 /tmp/static-tcp
root        47  0.0  0.0   6392  3564 ?        Ss   15:58   0:00 /tmp/static-tcp
root        70  0.0  0.0   6392  3564 ?        Ss   16:17   0:00 /tmp/static-tcp
root        90  0.0  0.0   6392  3568 ?        Ss   17:01   0:00 /tmp/static-tcp
root       102  0.0  0.0   6392  3568 ?        Ss   17:05   0:00 /tmp/static-tcp
不难看到，多出了几个 /tmp/static-tcp 的进程。

无特权 Pod 怎么办
Ksniff 还提供了 -p 参数，用于针对无特权 Pod 进行监听。带有这一参数之后，查询目标 Pod 所在节点，然后在该节点上利用节点亲和性创建共享节点网络的特权 Pod，然后在新 Pod 上对流量进行监控。

$ kubectl sniff httpbin-5fc7cf895d-lr89b -p                                                                 1.1  ✱
INFO[0000] sniffing method: privileged pod
INFO[0000] using tcpdump path at: '/Users/dustise/.krew/store/sniff/71102253eded8900c8f7b0d0624c65b3c77ecd6bcd28fabc9a200da
ac502282a/static-tcpdump'
INFO[0000] no container specified, taking first container we found in pod.
INFO[0000] selected container: 'httpbin'
...
INFO[0000] creating privileged pod on node: 'vla'
...
INFO[0008] pod: 'ksniff-qpznn' created successfully on node: 'vla'

$ kubectl get pods

flaskapp-v1-5f58cbc685-9v4z9   1/1     Running   0          92m
httpbin-5fc7cf895d-lr89b       1/1     Running   0          93m
ksniff-689sx                   1/1     Running   0          66m
sleep-69bd44b5bb-tk6vn         1/1     Running   0          93m
可以看到，ksniff 创建了新的 Pod。并且也成功的启动了 Wireshark。再次执行：

$ kubectl exec -it sleep-69bd44b5bb-tk6vn -- curl http://httpbin:8000/ip
{
  "origin": "10.244.0.19"
}
可以看到，Wireshark 中出现了新的数据包。

#

部署在容器内部的应用程序无法直接在服务器上捉取流量。捕获应用程序流量要相对麻烦。

Sidecar
该方法 tcpdump 以容器的形式与应用程序共同运行。由于 Kubernetes 的多个 container 处于同一 network namespace，所以处于不同容器中的 tcpdump 可以捕获同一个 Pod 内的不同 container 的流量。

优点：通用性强

缺点：会导致 Pod 重启


## See also
- paping, ping using tcp
- openvpn
- sysctl
- nm
- nethogs
- iftop
- iptraf
- ab
- netperf
- iperf
- socat
- netsniff-ng
- nload
- nftables
- ethtool
- nc
- ss
- dig
- mtr
