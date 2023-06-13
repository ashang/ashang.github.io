---
title: bpf
tags: [bpf]
date: 2022-12-19
---

5.1.15. Linux 默认禁用无特权的 bpf() 调用

从 Linux 5.10 开始，Debian 默认禁用非特权用户的 bpf() 调用。然而，如有需要，管理员仍可通过向 kernel.unprivileged_bpf_disabled sysctl 写入 0 或者 1 来改变此设定。

如果您希望仍然启用无特权的 bpf() 调用，请设置如下 sysctl 参数：

kernel.unprivileged_bpf_disabled = 0

BPF 全称是 「Berkeley Packet Filter」，翻译过来是 「伯克利包过滤器」。

经典 BPF 于 1997 年进入 Linux 内核版本 2.1.75，是一个功能有限的虚拟机。它有两个寄存器，一个由 16 个内存槽位组成的临时存储区域和一个程序计数器，用于在内核实现高性能的网络数据包过滤。

而后 Alexei Starovoitov 创造了扩展版 BPF（eBPF）。这是 20 年来 BPF 的第一次重大更新，此举也将 BPF 扩展为一个通用的虚拟机。扩展版的 BPF 中增加了更多寄存器，并将字长从 32 位增至 64 位，创建了灵活的 BPF 映射型存储（map），并允许调用一些受限制的内核功能。同时，eBPF 被设计为可以使用即时编译（JIT），机器指令与寄存器可以一对一映射。

BPF 虚拟机的实现既包括一个解释器，又包括一个 JIT 编译器 ：JIT 编译器负责生成处理器可直接执行的机器指令。验证器会拒绝那些不安全的操作，这包括针对无界循环的检查 ：BPF 程序必须在有限的时间内完成。

> “Super powers have finally come to Linux” — Brendan Gregg

- BPF Hooks
  从文件打开、创建 TCP 链接、Socket 链接到发送系统消息等几乎所有的系统调用，加上用户空间的各种动态信息，都能加载 BPF 程序，可以说是无所不能。
- BPF Map
  可以利用 BPF Map 持久化数据，在不丢失重要数据的同时，更新 BPF 程序逻辑，实现在不同程序之间共享信息，在收集统计信息或指标等场景下，尤其有用。
- BPF Helper Function
  操作 BPF 程序和 BPF Map 的工具类函数，隐藏后端的内核函数的变化，形成稳定 API 接口。

https://ebpf.io


toolbox/Linux/bpf.md


伯克利包过滤器（Berkeley Packet Filter，缩写 BPF），是类Unix系统上数据链路层的一种原始接口，提供原始链路层封包的收发。除此之外，如果网卡驱动支持混杂模式，那么它可以让网卡处于此种模式，这样可以收到网络上的所有包，不管他们的目的地是不是所在主机。

另外，BPF支持过滤数据包——用户态的进程可以提供一个过滤程序来声明它想收到哪些数据包。通过这种过滤可以避免从操作系统内核向用户态复制其他对用户态程序无用的数据包，从而极大地提高性能。

BPF有时也只表示过滤机制，而不是整个接口。一些系统，比如Linux和Tru64 Unix，提供了数据链路层的原始接口，而不是BPF的接口，但使用了BPF的过滤机制。

BSD 内核实现例程如 bpf_mtap()和 bpf_tap()，以BPF_MTAP()和 BPF_TAP()等宏定义的形式进行包裹由网卡驱动(以及伪驱动pseudo-drivers) 向BPF机制发送进出的封包。



网络监控程序运行在用户态，数据包必须被拷贝来通过内核与用户态之间的边界。可以通过使用一种被称为“数据包过滤器”的内核代理来减少拷贝的数量，它会尽量早地丢弃不想要的数据包。早先的数据包过滤器被实现为基于栈的虚拟机，在RISC CPU上性能不佳。BPF使用了一种新的基于寄存器(Register)的虚拟机，在性能上有显著提升。


2007年，Robert Watson与Christian Peron为FreeBSD操作系统中BPF的实现加入了zero-copy buffer extension，使得驱动程序中断处理器中的内核封包抓取能直接向用户内存写，以避免BPF设备收到的所有封包数据的两次复制需要，一份副本存在于用户进程的接收路径中，这保证了不同BPF设备调用者的独立性，同时使得只把封包头部放入BPF缓冲区，而不是复制整个封包数据。

从3.18版本开始，Linux 内核提供了一种扩展的BPF虚拟机，被称为“extended BPF”，简称为eBPF。它能够被用于非网络相关的功能，比如附在不同的tracepoints上，从而获取当前内核运行的许多信息。

Linux 4.x系列版本中又添加了对于kprobes、uprobes、tracepoints以及perf_events的支持。




Linux内核通过各个系统调用支持零复制，例如sys/socket.h的sendfile、sendfile64以及splice。



##
Jump to navigation
Jump to search
XDPOriginal author(s)	Brenden Blanco,
Tom Herbert
Developer(s)	Open source community, Google, Amazon, Intel, Microsoft[1]
Initial release	2016; 6 years ago
Written in	C
Operating system	Linux, Windows
Type	Packet filtering
License	Linux: GPL
Windows: MIT License

XDP (eXpress Data Path) is an eBPF-based high-performance data path used to send and receive network packets at high rates by bypassing most of the operating system networking stack. It is merged in the Linux kernel since version 4.8.


Data path
Packet flow paths in the Linux kernel. XDP bypasses the networking stack and memory allocation for packet metadata.

The idea behind XDP is to add an early hook in the RX path of the kernel, and let a user supplied eBPF program decide the fate of the packet. The hook is placed in the network interface controller (NIC) driver just after the interrupt processing, and before any memory allocation needed by the network stack itself, because memory allocation can be an expensive operation. Due to this design, XDP can drop 26 million packets per second per core with commodity hardware.[4]

The eBPF program must pass a preverifier test[5] before being loaded, to avoid executing malicious code in kernel space. The preverifier checks that the program contains no out-of-bounds accesses, loops or global variables.

The program is allowed to edit the packet data and, after the eBPF program returns, an action code determines what to do with the packet:

    XDP_PASS: let the packet continue through the network stack
    XDP_DROP: silently drop the packet
    XDP_ABORTED: drop the packet with trace point exception
    XDP_TX: bounce the packet back to the same NIC it arrived on
    XDP_REDIRECT: redirect the packet to another NIC or user space socket via the AF_XDP address family

XDP requires support in the NIC driver but, as not all drivers support it, it can fallback to a generic implementation, which performs the eBPF processing in the network stack, though with slower performance.[6]

XDP has infrastructure to offload the eBPF program to a network interface controller which supports it, reducing the CPU load. At the time only Netronome cards supports it,[7] with Intel and Mellanox working on it.[8]

Microsoft is partnering with other companies and adding support for XDP in the MsQuic protocol.[1]
AF_XDP
Along with XDP, a new address family entered in the Linux kernel starting 4.18.[9] AF_XDP, formerly known as AF_PACKETv4 (which was never included in the mainline kernel),[10] is a raw socket optimized for high performance packet processing and allows zero-copy between kernel and applications. As the socket can be used for both receiving and transmitting, it supports high performance network applications purely in user space.

https://upload.wikimedia.org/wikipedia/commons/3/37/Netfilter-packet-flow.svg



