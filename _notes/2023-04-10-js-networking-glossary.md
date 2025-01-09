---
layout:       post
title:        Networking
tags:
    - Web
    - JavaScript
---

access port

## DHCP Snooping

## DHCP Snooping database or file

DAI only inspect ARP traffic, this goes thru the CPU.IPSG inspect ALL ingress traffic to make sure the source is not spoofed.

Cisco ARP ACL is part of DAI, you can regard ARP ACL is the static configuration of DAI.

there is no any different between physical L2 port and LAG/MLAG. One important use case is binding important server MAC/IP in network, but typical server will connect to network with LAG and MLAG

When IP source guard is enabled, all traffic is blocked except for DHCP packets. Once the host gets an IP address through DHCP, only the DHCP-assigned source IP address is permitted.

Current DHCP Snooping already implemented a Binding feature to tie IP and MAC together. We can extend the Binding feature to include Port.

## RoCE (RDMA over Converged Ethernet) refers to the capability of the switch to handle and support RDMA traffic over Ethernet networks. RoCE allows RDMA operations to be performed between devices connected to the switch, enabling efficient and low-latency data transfers.

For a switch to support RoCE, it needs to meet certain requirements. These include:

1.   Ethernet Protocol Support: The switch must support the Ethernet protocols used for RoCE, including Ethernet encapsulation of RDMA packets.

2.   Lossless Ethernet: RoCE requires a lossless Ethernet network to ensure that RDMA traffic is not dropped or affected by congestion. The switch should support features like priority flow control (PFC) or Data Center Bridging (DCB) to enable lossless transmission.

3.   Quality of Service (QoS): The switch should have QoS capabilities to prioritize RDMA traffic over other types of network traffic. This ensures that RDMA packets receive preferential treatment and low latency.

4.   Congestion Management: The switch should have mechanisms to detect and manage network congestion to prevent performance degradation for RDMA traffic.

5.   Jumbo Frame Support: RoCE benefits from the use of jumbo frames, which allow larger packet sizes. The switch should support jumbo frames to accommodate RDMA traffic efficiently.

By supporting RoCE, a switch enables efficient RDMA communication between devices connected to the network, such as servers, storage systems, and other networked resources. It plays a crucial role in providing the necessary network infrastructure and features for RDMA operations to be performed reliably and with high performance.


 

Enhanced Transmission Selection (ETS) is a transmission selection algorithm (TSA) that is specified by the IEEE 802.1Qaz draft standard. This standard is part of the framework for the IEEE 802.1 Data Center Bridging (DCB) interface.

Transmission selection based solely on IEEE 802.1p priority levels can lead to situations in which higher-priority traffic blocks lower-priority traffic. ETS ensures fairness by allowing a minimum amount of bandwidth to be allocated to traffic classes that are assigned to different 802.1p priority levels.

Each traffic class is allocated a percentage of the available bandwidth on the data link between directly connected peers. If a traffic class doesn't use its allocated bandwidth, ETS allows other traffic classes to use the available bandwidth that the traffic class is not using.


The full name of WFQ is Weighted Fair Queuing. It is similar to WRR. The only difference between WFQ and WRR is that the scheduling mode in WFQ supports a minimum bandwidth guarantee, making this scheduling scheme more flexible. Configuring a minimum guaranteed bandwidth assures that every queue working in WFQ mode has a minimum bandwidth guarantee. In addition, the bandwidth available for distribution allocates according to the weighted proportion in the corresponding queue.
