---
title: netlink
date: 2017-04-30
--- 


Netlink套接字家族（英語：Netlink socket family）是一組Linux核心介面（Linux kernel interfaces），可用於行程間通訊，Linux内核与用户空间的进程间、用户进程间的通讯。然而它并不像网络套接字可以用于主机间通讯，Netlink只能用于同一主机上进程通讯，并通过PID来标识它们。

Netlink被设计为在Linux内核与用户空间进程传送各种网络信息。网络工具iproute2利用 Netlink从用户空间与内核进行通讯。Netlink由一个在用户空间的标准的Socket接口和内核模块 提供的内核API组成。Netlink的设计比ioctl更加灵活，Netlink使用了AF_NETLINK Socket 家族。

[编辑]
Netlink用于替代复杂和不够灵活的ioctl通讯方式，ioctl方法主要用设定和取得外部socket， 为了提供向后兼容，ioctl将一直被Linux内核所支持，用法如下：

error = ioctl(ip_socket, ioctl_type, &value_result);


[编辑]
不像BSD套接字存取互联网协议那样，头信息中的标识和目的地都是自动生成（如TCP）， Netlink消息头（结构体nlmsghdr）必须由发送方准备好，就像socket工作在SOCK_RAW模式下 一样。尽管SOCK_DGRAM被用于创建它。



[编辑]
AF_NETLINK协议家族提供了多个子协议。每个接口连接不同的内核组件并且有各自的消息集。 如：

int socket(AF_NETLINK, SOCK_DGRAM or SOCK_RAW, protocol)


Netlink协议[编辑]
Netlink所支持的协议如下（并不完全）： NETLINK_ROUTE NETLINK_ROUTE提供路由和连接信息。这些信息主要被用户空间的路由守护进程使用。对于这个 协议，Linux声明了大量的子消息：

链路层：RTM_NEWLINK, RTM_DELLINK, RTM_GETLINK, RTM_SETLINK
地址设定：RTM_NEWADDR, RTM_DELADDR, RTM_GETADDR
路由表：RTM_NEWROUTE, RTM_DELROUTE, RTM_GETROUTE
邻居缓存（Neighbor Cache）：RTM_NEWNEIGH, RTM_DELNEIGH, RTM_GETNEIGH
路由规则：RTM_NEWRULE, RTM_DELRULE, RTM_GETRULE
Queuing Discipline Settings: RTM_NEWQDISC, RTM_DELQDISC, RTM_GETQDISC
Traffic Classes used with Queues: RTM_NEWTCLASS, RTM_DELTCLASS, RTM_GETTCLASS
流量过滤：RTM_NEWTFILTER, RTM_DELTFILTER, RTM_GETTFILTER


