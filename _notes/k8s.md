---
date: 2017-09-08
render_with_liquid: false
---

Kubernetes（在希腊语意為“舵手”或“驾驶员”。

該系統的开发和设计都深受谷歌的 Borg 系统的影响，在谷歌内部，Kubernetes的原始代号曾经是Seven，即星际迷航中的Borg（博格人）。Kubernetes标识中舵轮有七个轮辐就是对该项目代号的致意。

#
Kubernetes 在設計結構上定义了一系列的构建模块，其目的是為了提供一個可以共同提供部署、维护和扩展应用程序的机制。组成 Kubernetes的组件设计概念为松耦合和可扩展的，这样可以使之满足多种不同的工作负载。可扩展性在很大程度上由Kubernetes API提供，此API主要被作为扩展的内部组件以及Kubernetes上运行的容器來使用。

Pod

Kubernetes 的基本调度单元称为“pod”。通過該種抽象類別可以把更高级别的抽象内容增加到容器化组件。一个 pod一般包含一个或多个容器，这样可以保证它们一直位于主机上，并且可以共享资源。

Kubernetes 中的每个 pod都被分配一个唯一的（在集群内的）IP地址这样就可以允许应用程序使用同一端口，而避免了發生冲突的問題。

Pod 可以定义一个卷，例如本地磁盘目录或网络磁盘，并将其暴露在 pod中的一个容器之中。

pod 可以通过 Kubernetes API手动管理，也可以委托给控制器来實現自動管理。

标签和选择器
Kubernetes 使客户端（用户或内部组件）将称为“标签”的键值对附加到系统中的任何 API对象，如pod和节点。相应地，“标签选择器”是针对匹配对象的标签的查询方法。

标签和选择器是 Kubernetes 中的主要分组机制，用于确定操作适用的组件。

例如，如果应用程序的 Pods 具有系统的标签 tier （比如"front-end"、"back-end") 和一个 release_track (比如"canary"、"production")，那么对所有"back-end" 和 "canary" 节点的操作可以使用如下所示的标签选择器：

tier=back-end AND release_track=canary

控制器
控制器是通过管理一组 pod 来实现來将实际集群状态转移到所需集群状态的对帐循环機制。

一种控制器指的是一組具有相同特徵的“复制控制器”，控制器通过在集群中运行指定数量的 pod 副本来处理复制和缩放。在基础节点出现故障的情況下，它还可以用於处理创建替换pod。

其它控制器也是核心 Kubernetes 系统的一部分，包括“DaemonSet控制器”为每台机器（或机器的一些子集）上运行的單個pod，和用于运行pod的“作业控制器”。

控制器管理的 pod 組由作为控制器定义的部分的标签选择器來确定。

服务
Kubernetes 服务本質是一组协同工作的 pod，類同多层架构应用中的一层。构成服务的pod组通过标签选择器来定义。

Kubernetes 通过给服务分配静态 IP地址和域名来提供服务发现机制，并且以轮循调度的方式将流量负载均衡到能与选择器匹配的pod的IP地址的网络连接上（即使是故障导致pod从一台机器移动到另一台机器）。

默认情况下，服务任務会暴露在集群中（例如，多个后端 pod 可能被分组成一个服务，前端pod的请求在它们之间负载平衡）；除此以外，服务任務也可以暴露在集群外部（例如，从客户端访问前端pod）。

建构

Kubernetes 控制平面的各种組件如下：

etcd
etcd （页面存档备份，存于互联网档案馆） 是由 CoreOS 开发，用于可靠地存储集群的配置数据的一种持久性，轻量型的，分布式的键-值数据存储組件。該組件可表示在任何给定时间点处的集群的整体状态。其他组件在注意到存储的变化之后，会变成相应的状态。

API 服务器
API 服务器是一个关键组件 并使用 Kubernetes API 和 JSON over HTTP來提供了 Kubernetes的内部和外部接口。

API 服务器处理和验证 REST请求并更新 API 对象的状态 etcd （页面存档备份，存于互联网档案馆），从而允许客户端在Worker节点之间配置工作负载和容器。

调度器
T 调度程序是可插拔式组件，其基于资源可用性来选择未调度的 pod（由调度程序管理的基本实体）应该运行哪个节点。调度程序跟踪每个节点上的资源利用率，以确保工作负载不会超过可用资源。为此，调度程序必须知道资源需求，资源可用性以及各种其他用户提供的约束和策略指令，例如服务质量，亲和力/反关联性要求，数据位置等。实质上，调度程序的作用是将资源“供应”与工作负载“需求”相匹配以維持系統的穩定和可靠。

控制器管理
控制器管理器是核心 Kubernetes 控制器，其包括DaemonSet控制器和复制控制器等。該控制器可与API服务器進行通信以在需要時创建，更新和删除他们管理的资源（pod，服务端点等）

Kubernetes 节点
Node 也称为 Worker或Minion，是部署容器（工作负载）的单机器（或虚拟机）。集群中的每个节点都必须具备容器的运行环境（runtime） ——比如 Docker，以及下面提到的其他组件，以便与这些容器的网络配置进行通信。

Kubelet
Kubelet 负责每个节点的运行状态（即确保节点上的所有容器都正常运行）。它按照控制面板的指示来处理启动，停止和维护应用程序容器（按组织到 pod中）。

Kubelet 會监视 pod的状态，如果不处于所需状态，则pod将被重新部署到同一个节点。节点状态每隔几秒就會傳遞消息至中继主机。主控器检测到节点故障后，复制控制器将观察此状态更改，并在其他健康节点上启动pod。

容器
容器从属于 pod。在运行应用、库及其依赖的微服务中，容器是最低层级的。通过绑定一个外部IP，容器可以被外网访问。

Kube 代理
Kube 代理是网络代理和负载均衡的实现，支持服务抽象以及其他网络操作。
根据传入请求的 IP 和端口，該組件會将流量转发到指定的合适的容器中。

cAdvisor
cAdvisor 是监视和收集例如每个节点上的容器的 CPU，内存，文件和网络使用情况等的资源使用情况和性能指标的代理組件。

## snap

     snap install microk8s --channel=1.14/beta --classic


容器是微服务的最佳载体，Kubernetes 是微服务的最佳运行平台，Istio 是 Kubernetes 上最佳的 service mesh。

## 容器

历史上，第一个容器提供的仅仅是root file system的隔离（通过chroot），再加上FreeBSD jails提供额外的例如process ID这样的namespaces。Solaris后来成为先锋并且做了很多加强的探索。Linux control groups（cgroups）运用了很多这些想法，在这个领域的发展一直延续到今天。

## 应用环境

Linux内核里的cgroup、chroot和namespace的原本是为了保护应用不受周边杂乱邻里的影响。把这些和容器镜像组合起来创建一个抽象事物把应用从运行它们的（纷杂的）操作系统里隔离出来，提高了部署可靠性，也通过减少不一致性和冲突而加快了开发速度。

能让这个抽象事物得以实现的关键在于有一个自包含的镜像，它把一个应用几乎所有的依赖环境都打包然后部署在一个容器里。如果这个过程做的正确，本地的外部环境就只剩下Linux内核的system-call interface. 这个有限制的interface极大提高了镜像的便携性，它并不完美：应用仍然暴露给了OS interface，尤其是在socket选项的广泛表面上、/proc、和给ioctl call的所传参数上。我们希望后面类似Open Container Initiative（OCI: https://www.opencontainers.org/）的努力能继续把容器抽象的表层能理清。

# Docker启动的时候，可以使用--network参数指定使用的网络

bridge： 默认情况下启动的Docker容器，都是使用 bridge，Docker安装时创建的桥接网络，每次Docker容器重启时，会按照顺序获取对应的IP地址，这个就导致重启下，Docker的IP地址就变了

host：Docker 容器的网络会附属在主机上，两者是互通的。

搭建一些集群软件的时候，组件和组件之间需要进行网络通信，这个时候如果每次重启IP都发生变化会很不方便，因此希望能够将容器的IP固定下来，这也是可以实现的，具体参考下面的方法。

1.创建自定义网络

```
$ docker network create --subnet=172.18.0.0/16 es-network
1e3e1eb702176df3e44111970292deaf5def7564135439fae21be489d6a8dcef
$ docker network ls
NETWORK ID          NAME                DRIVER              SCOPE
6bdc00ad2a8d        bridge              bridge              local
1e3e1eb70217        es-network          bridge              local
e373574073e9        host                host                local
d3d47c52f57b        none                null                local
```

2.创建Docker容器

```
docker run -e ES_JAVA_OPTS="-Xms256m -Xmx256m" -d -p 9202:9202 -p 9302:9302 -v ~/Projects/elk/elk-cluster/data3/es3.yml:/usr/share/elasticsearch/config/elasticsearch.yml -v ~/Projects/elk/elk-cluster/data3:/usr/share/elasticsearch/data --name ES03 --net=es-network --ip=172.18.0.12 --hostname=es-node3 docker.elastic.co/elasticsearch/elasticsearch:6.7.0
```

使用docker inspect container-id可以看到当前容器分配的IP就是固定IP了。

docker自定义ip操作

```
docker network create --subnet=x.x.x.0/24 netBridgeName(网桥名称，随便写即可) ---创建自定义网桥

docker run -itd --network=netBridgeName --ip x.x.x.8 --name containerName imageName ---创建容器且指定网络ip

docker network list ----查看docker下网络模式

docker network rm netBridgeName ----删除创建的网桥

$ route
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
default         10.10.50.1      0.0.0.0         UG    0      0        0 eth0
10.10.50.0      *               255.255.255.0   U     0      0        0 eth0
10.10.51.0      10.10.50.1      255.255.255.0   UG    0      0        0 eth0
172.17.0.0      *               255.255.0.0     U     0      0        0 docker0


p route
default via 10.10.50.1 dev eth0
10.10.50.0/24 dev eth0  proto kernel  scope link  src 10.10.50.22
10.10.51.0/24 via 10.10.50.1 dev eth0
172.17.0.0/16 dev docker0  proto kernel  scope link  src 172.17.0.1


aaron@dd9079117fa0:~$ ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
429: eth0@if430: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default
    link/ether 02:42:ac:11:00:b9 brd ff:ff:ff:ff:ff:ff link-netnsid 0
    inet 172.17.0.185/16 brd 172.17.255.255 scope global eth0
       valid_lft forever preferred_lft forever
aaron@dd9079117fa0:~$ brctl
-bash: brctl: command not found
aaron@dd9079117fa0:~$ brctl show
-bash: brctl: command not found

$ brctl show
bridge name     bridge id               STP enabled     interfaces
docker0         8000.02420d6d7c35       no              veth066a8ce
                                                        veth2c44cde
                                                        veth41aeb2d
                                                        veth4c0d907
                                                        veth605a57d
                                                        veth60dc66c
                                                        veth71c08dd
                                                        veth83d8896
                                                        veth8736563



in container:

$ route
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
default         172.17.0.1      0.0.0.0         UG    0      0        0 eth0
172.17.0.0      *               255.255.0.0     U     0      0        0 eth0


aaron@a88556dc6e9a:~$ ip route
default via 172.17.0.1 dev eth0
172.17.0.0/16 dev eth0 proto kernel scope link src 172.17.0.185
```

# -> 容器1内部 ping 容器2

```
$ ping 172.17.0.3
PING 172.17.0.3 (172.17.0.3): 56 data bytes
64 bytes from 172.17.0.3: seq=0 ttl=64 time=0.142 ms
64 bytes from 172.17.0.3: seq=1 ttl=64 time=0.096 ms
```

我们看到，在一个容器内部ping另外一个容器的ip，是可以ping通的。也就意味着，这两个容器是可以互相通信的。

在容器1里访问容器2的地址，这个时候目的IP地址会匹配到容器1的第二条路由规则，这条路由规则的Gateway是0.0.0.0，意味着这是一条直连规则，也就是说凡是匹配到这个路由规则的请求，会直接通过eth0网卡，通过二层网络发往目的主机。而要通过二层网络到达容器2，就需要127.17.0.3对应的MAC地址。所以，容器1的网络协议栈就需要通过eth0网卡来发送一个ARP广播，通过IP找到MAC地址。

所谓ARP（Address Resolution Protocol），就是通过三层IP地址找到二层的MAC地址的协议。这里说到的eth0，就是Veth Pair的一端，另一端则插在了宿主机的docker0网桥上。eth0这样的虚拟网卡插在docker0上，也就意味着eth0变成docker0网桥的“从设备”。从设备会降级成docker0设备的端口，而调用网络协议栈处理数据包的资格全部交给docker0网桥。

所以，在收到ARP请求之后，docker0就会扮演二层交换机的角色，把ARP广播发给其它插在docker0网桥的虚拟网卡上，这样，127.17.0.3就会收到这个广播，并把其MAC地址返回给容器1。有了这个MAC地址，容器1的eth0的网卡就可以把数据包发送出去。 这个数据包会经过Veth Pair在宿主机的另一端veth26cf2cc，直接交给docker0。

docker0转发的过程，就是继续扮演二层交换机，docker0根据数据包的目标MAC地址，在CAM表查到对应的端口为veth8762ad2，然后把数据包发往这个端口。而这个端口，就是容器2的Veth Pair在宿主机的另一端，这样，数据包就进入了容器2的Network Namespace，最终容器2将响应（Ping）返回给容器1。在真实的数据传递中，Linux内核Netfilter/Iptables也会参与其中，这里不再赘述。

CAM就是交换机通过MAC地址学习维护端口和MAC地址的对应表

## 跨主通信

好了，这里不禁问个问题，到目前为止只是单主机内部的容器间通信，那跨主机网络呢？ 在Docker默认配置下，一台宿主机的docker0网桥是无法和其它宿主机连通的，它们之间没有任何关联，所以这些网桥上的容器，自然就没办法多主机之间互相通信。但是无论怎么变化，道理都是一样的，如果我们创建一个公共的网桥，是不是集群中所有容器都可以通过这个公共网桥去连接？

当然在正常的情况下，节点与节点的通信往往可以通过NAT的方式，但是，这个在互联网发展的今天，在容器化环境下未必适用。例如在向注册中心注册实例的时候，肯定会携带IP，在正常物理机内的应用当然没有问题，但是容器化环境却未必，容器内的IP很可能就是上文所说的172.17.0.2，多个节点都会存在这个IP，大概率这个IP是冲突的。

如果我们想避免这个问题，就会携带宿主机的IP和映射的端口去注册。但是这又带来一个问题，即容器内的应用去意识到这是一个容器，而非物理机，当在容器内，应用需要去拿容器所在的物理机的IP，当在容器外，应用需要去拿当前物理机的IP。显然，这并不是一个很好的设计，这需要应用去配合配置。所以，基于此，我们肯定要寻找其他的容器网络解决方案。

在我们已有的主机网络上，通过软件构建一个覆盖在多个主机之上，且能把所有容器连通的虚拟网络。这种就是Overlay Network（覆盖网络）。

关于这些具体的网络解决方案，例如Flannel、Calico等

##docker的网络概念

docker受一个github上的issue启发，引入了容器网络模型（container network model，CNM）[1]，容器网络模型主要包含了3个概念

network：网络，可以理解为一个Driver，是一个第三方网络栈，包含多种网络模式，下文也会详细描述

单主机网络模式（none、host、bridge，joined container）
多主机网络模式（overlay、macvlan、flannel）
sandbox：沙盒，它定义了容器内的虚拟网卡、DNS和路由表，是network namespace的一种实现，是容器的内部网络栈

endpoint：端点，用于连接sandbox和network

可以类比传统网络模型，将network比作交换机，sandbox比作网卡，endpoint比作接口和网线

另外，docker在创建容器时，先调用控制器创建sandbox对象，再调用容器运行时为容器创建network namespace

二、docker的网络模式

这里我们先讨论docker的单主机网络模式，它包括以下4类：

host
bridge
none
joined-container

2.1 host

docker不会为容器创建独有的network namespace；

使用宿主机的默认网络命名空间，共享一个网络栈；

表现为容器内和宿主机的IP一致；

这种模式用于网络性能较高的场景，但安全隔离性相对差一些。

2.2 bridge

桥接模式，有点类型VM-NAT，dockerd进程启动时会创建一个docker0网桥，容器内的数据通过这个网卡设备与宿主机进行数据传输。

￼
docker会为容器创建独有的network namespace，也会为这个命名空间配置好虚拟网卡，路由，DNS，IP地址与iptables规则（也就是sandbox的内容）。

2.3 none

none模式可以说是桥接模式的一种特例，docker会为容器创建独有的network namespace ，但不会为这个命名空间准备虚拟网卡，IP地址，路由等，需要用户自己配置。

2.4 joined-container

容器共享模式，这种模式是host模式的一种延伸，一组容器共享一个network namespace；

对外表现为他们有共同的IP地址，共享一个网络栈；

kubernetes的pod就是使用的这一模式。

关于跨主机的docker网络通信，包含overlay、macvaln，又包含calico、flannel、weave等方案，不过跨主机的docker网络管理更多的是交给kubernetes或swarm等编排工具去实现了。

```
vagrant ssh docker-node1
ip a
```

# K8s

可以实现容器集群的自动化部署、自动扩缩容、维护等功能。

通过Kubernetes你可以：

快速部署应用
快速扩展应用
无缝对接新的应用功能
节省资源，优化硬件资源的使用


K8s集群至少有一个工作节点，节点上运行 K8s 所管理的容器化应用。


在Master通常上包括 kube-apiserver、etcd 存储、kube-controller-manager、cloud-controller-manager、kube-scheduler 和用于 K8s 服务的 DNS 服务器（插件）。这些对集群做出全局决策(比如调度)，以及检测和响应集群事件的组件集合也称为控制平面。

大多数安装工具（kubeadm）或者脚本为了架构更明了会把控制平面中的组件安装到一台机器上即Master机器，并且不会在此机器上运行用户容器。

在Node上组件包括 kubelet 、kube-porxy 以及服务于pod的容器运行时(runtime)。外部storage与registry用于为容器提供存储与镜像仓库服务。


K8s的基本工作流程：

- kubectl 将CLI命令转化为RESTful的API调用，然后发送到kube-apiserver。
- kube-apiserver 在验证这些 API 后，将任务元信息存储到etcd，调用 kube-scheduler 决策一个用于作业的Node节点。
- 一旦 kube-scheduler 返回一个适合调度的目标节点后，kube-apiserver 就把任务的节点信息存入etcd，并创建任务。
- 此时目标节点中的 kubelet正监听apiserver，当监听到有新任务需要调度到本节点后，kubelet通过本地runtime创建任务容器，执行作业。
- 接着kubelet将任务状态等信息返回给apiserver存储到etcd。
- 这样我们的任务已经在运行了，此时control-manager发挥作用保证任务一直是我们期望的状态。

# k8s组件

## 控制平面组件

Kubernetes 的 Master 包含四个主要的组件：API Server、Controller、Scheduler 以及 etcd。如下图所示：

### kube-apiserver

API服务器为K8s集群资源操作提供唯一入口，并提供认证、授权、访问控制、API 注册和发现机制。

Kubernetes API 服务器的主要实现是 kube-apiserver。 kube-apiserver 设计上考虑了水平伸缩，也就是说，它可通过部署多个实例进行伸缩。你可以运行 kube-apiserver 的多个实例，并在这些实例之间进行流量平衡。

Kubernetes API 是由 **HTTP+JSON **组成的：用户访问的方式是 HTTP，访问的 API 中 content 的内容是 JSON 格式的。

Kubernetes 的 kubectl 也就是 command tool，Kubernetes UI，或者有时候用 curl，直接与 Kubernetes 进行沟通，都是使用 HTTP + JSON 这种形式。

下面有个例子：比如说，对于这个 Pod 类型的资源，它的 HTTP 访问的路径，就是 API，然后是 apiVesion: V1, 之后是相应的 Namespaces，以及 Pods 资源，最终是 Podname，也就是 Pod 的名字

Spec 也就是我们希望 Pod 达到的一个预期的状态。比如说它内部需要有哪些 container 被运行；比如说这里面有一个 nginx 的 container，它的 image 是什么？它暴露的 port 是什么？

当我们从 Kubernetes API 中去获取这个资源的时候，一般来讲在 Spec 下面会有一个项目叫 status，它表达了这个资源当前的状态；比如说一个 Pod 的状态可能是正在被调度、或者是已经 running、或者是已经被 terminates，就是被执行完毕了。

刚刚在 API 之中，我们讲了一个比较有意思的 metadata 叫做“label”，这个 label 可以是一组 KeyValuePair。

比如下图的第一个 pod 中，label 就可能是一个 color 等于 red，即它的颜色是红颜色。当然你也可以加其他 label，比如说 size: big 就是大小，定义为大的，它可以是一组 label。

这些 label 是可以被 selector，也就是选择器所查询的。这个能力实际上跟我们的 sql 类型的 select 语句是非常相似的，比如下图中的三个 Pod 资源中，我们就可以进行 select。name color 等于 red，就是它的颜色是红色的，我们也可以看到，只有两个被选中了，因为只有他们的 label 是红色的，另外一个 label 中写的 color 等于 yellow，也就是它的颜色是黄色，是不会被选中的。


通过 label，kubernetes 的 API 层就可以对这些资源进行一个筛选，那这些筛选也是 kubernetes 对资源的集合所表达默认的一种方式。



例如说，我们刚刚介绍的 Deployment，它可能是代表一组的 Pod，它是一组 Pod 的抽象，一组 Pod 就是通过 label selector 来表达的。当然我们刚才讲到说 service 对应的一组 Pod，就是一个 service 要对应一个或者多个的 Pod，来对它们进行统一的访问，这个描述也是通过 label selector 来进行 select 选取的一组 Pod。

### API 与 Kubernetes Operator

Kubernetes Operator 是一种利用 API 借助 kubectl 工具来封装、部署和管理应用的方法。

在 Kubernetes 中，Operator 是一种特定于应用的控制器，它可以扩展 Kubernetes API 的功能，从而代表用户创建、配置和管理复杂应用的实例。通过包含特定于域或应用的信息，Operator 可以让 Kubernetes 在所管理软件的整个生命周期内实现自动化。

### etcd

etcd 是兼具一致性和高可用性的键值数据库，可以作为保存 Kubernetes 所有集群数据的后台数据库(例如 Pod 的数量、状态、命名空间等）、API 对象和服务发现细节。 在生产级k8s中etcd通常会以集群的方式存在，安全原因，它只能从 API 服务器访问。

### kube-scheduler

kube-scheduler 负责监视新创建、未指定运行Node的 Pods，决策出一个让pod运行的节点。

例如，如果应用程序需要 1GB 内存和 2 个 CPU 内核，那么该应用程序的 pod 将被安排在至少具有这些资源的节点上。每次需要调度 pod 时，调度程序都会运行。调度程序必须知道可用的总资源以及分配给每个节点上现有工作负载的资源。

调度决策考虑的因素包括单个 Pod 和 Pod 集合的资源需求、硬件/软件/策略约束、亲和性和反亲和性规范、数据位置、工作负载间的干扰和最后时限。

### kube-controller-manager

k8s在后台运行许多不同的控制器进程，当服务配置发生更改时（例如，替换运行 pod 的镜像，或更改配置 yaml 文件中的参数），控制器会发现更改并开始朝着新的期望状态工作。

从逻辑上讲，每个控制器都是一个单独的进程， 但是为了降低复杂性，它们都被编译到同一个可执行文件，并在一个进程中运行。

控制器包括:

- 节点控制器（Node Controller）: 负责在节点出现故障时进行通知和响应
- 任务控制器（Job controller）: 监测代表一次性任务的 Job 对象，然后创建 Pods 来运行这些任务直至完成
- 端点控制器（Endpoints Controller）: 填充端点(Endpoints)对象(即加入 Service 与 Pod)
- 服务帐户和令牌控制器（Service Account & Token Controllers）: 为新的命名空间创建默认帐户和 API 访问令牌

### cloud-controller-manager

云控制器管理器使得你可以将你的集群连接到云提供商的 API 之上， 同时可以将云平台交互组件与本地集群中组件分离。

cloud-controller-manager 仅运行特定于云平台的控制回路。 如果我们在自己的环境中运行 Kubernetes，大多数时候非混合云环境是用不到这个组件的。

与 kube-controller-manager 类似，cloud-controller-manager 将若干逻辑上独立的 控制回路组合到同一个可执行文件中，供你以同一进程的方式运行。 你可以对其执行水平扩容（运行不止一个副本）以提升性能或者增强容错能力。

下面的控制器都包含对云平台驱动的依赖：

- 节点控制器（Node Controller）: 用于在节点终止响应后检查云提供商以确定节点是否已被删除
- 路由控制器（Route Controller）: 用于在底层云基础架构中设置路由
- 服务控制器（Service Controller）: 用于创建、更新和删除云提供商负载均衡器

## some some

OS 上去创建容器所需要运行的环境，最终把容器或者 Pod 运行起来，也需要对存储跟网络进行管理。Kubernetes 并不会直接进行网络存储的操作，他们会靠 Storage Plugin 或者是网络的 Plugin 来进行操作。用户自己或者云厂商都会去写相应的 Storage Plugin 或者 Network Plugin，去完成存储操作或网络操作。

在 Kubernetes 自己的环境中，也会有 Kubernetes 的 Network，它是为了提供 Service network 来进行搭网组网的。（等一下我们也会去介绍“service”这个概念。）真正完成 service 组网的组件的是 Kube-proxy，它是利用了 iptable 的能力来进行组建 Kubernetes 的 Network，就是 cluster network，以上就是 Node 上面的四个组件。

Kubernetes 的 Node 并不会直接和 user 进行 interaction，它的 interaction 只会通过 Master。而 User 是通过 Master 向节点下发这些信息的。Kubernetes 每个 Node 上，都会运行我们刚才提到的这几个组件。

通过 UI 或者 CLI 提交一个 Pod 给 Kubernetes 进行部署，这个 Pod 请求首先会通过 CLI 或者 UI 提交给 Kubernetes API Server，下一步 API Server 会把这个信息写入到它的存储系统 etcd，之后 Scheduler 会通过 API Server 的 watch 或者叫做 notification 机制得到这个信息：有一个 Pod 需要被调度。

这个时候 Scheduler 会根据它的内存状态进行一次调度决策，在完成这次调度之后，它会向 API Server report 说：“OK！这个 Pod 需要被调度到某一个节点上。”

这个时候 API Server 接收到这次操作之后，会把这次的结果再次写到 etcd 中，然后 API Server 会通知相应的节点进行这次 Pod 真正的执行启动。相应节点的 kubelet 会得到这个通知，kubelet 就会去调 Container runtime 来真正去启动配置这个容器和这个容器的运行环境，去调度 Storage Plugin 来去配置存储，network Plugin 去配置网络。

## Pod

Pod 是 Kubernetes 的一个最小调度以及资源单元。用户可以通过 Kubernetes 的 Pod API 生产一个 Pod，让 Kubernetes 对这个 Pod 进行调度，也就是把它放在某一个 Kubernetes 管理的节点上运行起来。一个 Pod 简单来说是对一组容器的抽象，它里面会包含一个或多个容器。

在 Pod 里面，我们也可以去定义容器所需要运行的方式。比如说运行容器的 Command，以及运行容器的环境变量等等。Pod 这个抽象也给这些容器提供了一个共享的运行环境，它们会共享同一个网络环境，这些容器可以用 localhost 来进行直接的连接。而 Pod 与 Pod 之间，是互相有 isolation 隔离的。

Deployment 是在 Pod 这个抽象上更为上层的一个抽象，它可以定义一组 Pod 的副本数目、以及这个 Pod 的版本。一般大家用 Deployment 这个抽象来做应用的真正的管理，而 Pod 是组成 Deployment 最小的单元。

Kubernetes 是通过 Controller，也就是我们刚才提到的控制器去维护 Deployment 中 Pod 的数目，它也会去帮助 Deployment 自动恢复失败的 Pod。

比如说我可以定义一个 Deployment，这个 Deployment 里面需要两个 Pod，当一个 Pod 失败的时候，控制器就会监测到，它重新把 Deployment 中的 Pod 数目从一个恢复到两个，通过再去新生成一个 Pod。通过控制器，我们也会帮助完成发布的策略。比如说进行滚动升级，进行重新生成的升级，或者进行版本的回滚。

## 3.Pod

运行于Node节点上，若干相关容器的组合。Pod内包含的容器运行在同一宿主机上，使用相同的网络命名空间、IP地址和端口，可以经过localhost进行通。Pod是Kurbernetes进行建立、调度和管理的最小单位，它提供了比容器更高层次的抽象，使得部署和管理更加灵活。一个Pod能够包含一个容器或者多个相关容器。

Pod其实有两种类型：普通Pod和静态Pod，后者比较特殊，它并不存在Kubernetes的etcd存储中，而是存放在某个具体的Node上的一个具体文件中，而且只在此Node上启动。普通Pod一旦被建立，就会被放入etcd存储中，随后会被Kubernetes Master调度到摸个具体的Node上进行绑定，随后该Pod被对应的Node上的kubelet进程实例化成一组相关的Docker容器冰启动起来，在。在默认状况下，当Pod里的某个容器中止时，Kubernetes会自动检测到这个问起而且重启这个Pod（重启Pod里的全部容器），若是Pod所在的Node宕机，则会将这个Node上的全部Pod从新调度到其余节点上。

4.Replication Controller

Replication Controller用来管理Pod的副本，保证集群中存在指定数量的Pod副本。集群中副本的数量大于指定数量，则会中止指定数量以外的多余容器数量，反之，则会启动少于指定数量个数的容器，保证数量不变。Replication Controller是实现弹性伸缩、动态扩容和滚动升级的核心。

5.Service

Service定义了Pod的逻辑集合和访问该集合的策略，是真实服务的抽象。Service提供了一个统一的服务访问入口以及服务代理和发现机制，关联多个相同Label的Pod，用户不须要了解后台Pod是如何运行。

外部系统访问Service的问题

首先须要弄明白Kubernetes的三种IP这个问题

Node IP：Node节点的IP地址

Pod IP： Pod的IP地址

Cluster IP：Service的IP地址

首先,Node IP是Kubernetes集群中节点的物理网卡IP地址，全部属于这个网络的服务器之间都能经过这个网络直接通讯。这也代表Kubernetes集群以外的节点访问Kubernetes集群以内的某个节点或者TCP/IP服务的时候，必须经过Node IP进行通讯

其次，Pod IP是每一个Pod的IP地址，他是Docker Engine根据docker0网桥的IP地址段进行分配的，一般是一个虚拟的二层网络。

最后Cluster IP是一个虚拟的IP，但更像是一个伪造的IP网络，缘由有如下几点

Cluster IP仅仅做用于Kubernetes Service这个对象，并由Kubernetes管理和分配P地址
Cluster IP没法被ping，他没有一个“实体网络对象”来响应
Cluster IP只能结合Service Port组成一个具体的通讯端口，单独的Cluster IP不具有通讯的基础，而且他们属于Kubernetes集群这样一个封闭的空间。
Kubernetes集群以内，Node IP网、Pod IP网于Cluster IP网之间的通讯，采用的是Kubernetes本身设计的一种编程方式的特殊路由规则。

6.Label

Kubernetes中的任意API对象都是经过Label进行标识，Label的实质是一系列的Key/Value键值对，其中key于value由用户本身指定。Label能够附加在各类资源对象上，如Node、Pod、Service、RC等，一个资源对象能够定义任意数量的Label，同一个Label也能够被添加到任意数量的资源对象上去。Label是Replication Controller和Service运行的基础，两者经过Label来进行关联Node上运行的Pod。

咱们能够经过给指定的资源对象捆绑一个或者多个不一样的Label来实现多维度的资源分组管理功能，以便于灵活、方便的进行资源分配、调度、配置等管理工做。

一些经常使用的Label以下：

版本标签：“release”:“stable”,“release”:“canary”…
环境标签：“environment”:“dev”,“environment”:“qa”,“environment”:“production”
架构标签：“tier”:“frontend”,“tier”:“backend”,“tier”:“middleware”
分区标签：“partition”:“customerA”,“partition”:“customerB”
质量管控标签：“track”:“daily”,“track”:“weekly”
　　Label至关于咱们熟悉的标签，给某个资源对象定义一个Label就至关于给它大了一个标签，随后能够经过Label Selector（标签选择器）查询和筛选拥有某些Label的资源对象，Kubernetes经过这种方式实现了相似SQL的简单又通用的对象查询机制。

Label Selector在Kubernetes中重要使用场景以下:

kube-Controller进程经过资源对象RC上定义Label Selector来筛选要监控的Pod副本的数量，从而实现副本数量始终符合预期设定的全自动控制流程

kube-proxy进程经过Service的Label Selector来选择对应的Pod，自动创建起每一个Service岛对应Pod的请求转发路由表，从而实现Service的智能负载均衡

经过对某些Node定义特定的Label，而且在Pod定义文件中使用Nodeselector这种标签调度策略，kuber-scheduler进程能够实现Pod”定向调度“的特性

#

Service 提供了一个或者多个 Pod 实例的稳定访问地址。

比如在上面的例子中，我们看到：一个 Deployment 可能有两个甚至更多个完全相同的 Pod。对于一个外部的用户来讲，访问哪个 Pod 其实都是一样的，所以它希望做一次负载均衡，在做负载均衡的同时，我只想访问某一个固定的 VIP，也就是 Virtual IP 地址，而不希望得知每一个具体的 Pod 的 IP 地址。

我们刚才提到，这个 pod 本身可能 terminal go（终止），如果一个 Pod 失败了，可能会换成另外一个新的。

对一个外部用户来讲，提供了多个具体的 Pod 地址，这个用户要不停地去更新 Pod 地址，当这个 Pod 再失败重启之后，我们希望有一个抽象，把所有 Pod 的访问能力抽象成一个第三方的一个 IP 地址，实现这个的 Kubernetes 的抽象就叫 Service。

实现 Service 有多种方式，Kubernetes 支持 Cluster IP，上面我们讲过的 kuber-proxy 的组网，它也支持 nodePort、 LoadBalancer 等其他的一些访问的能力。

Service是分布式集群架构的核心，一个Service对象拥有以下关键特征：

拥有一个惟一指定的名字
拥有一个虚拟IP（Cluster IP、Service IP、或VIP）和端口号
可以体统某种远程服务能力
被映射到了提供这种服务能力的一组容器应用上
　　Service的服务进程目前都是基于Socket通讯方式对外提供服务，好比Redis、Memcache、MySQL、Web Server，或者是实现了某个具体业务的一个特定的TCP Server进程，虽然一个Service一般由多个相关的服务进程来提供服务，每一个服务进程都有一个独立的Endpoint（IP+Port）访问点，但Kubernetes可以让咱们经过服务链接到指定的Service上。有了Kubernetes内奸的透明负载均衡和故障恢复机制，无论后端有多少服务进程，也无论某个服务进程是否会因为发生故障而从新部署到其余机器，都不会影响咱们队服务的正常调用，更重要的是这个Service自己一旦建立就不会发生变化，意味着在Kubernetes集群中，咱们不用为了服务的IP地址的变化问题而头疼了。

容器提供了强大的隔离功能，全部有必要把为Service提供服务的这组进程放入容器中进行隔离。为此，Kubernetes设计了Pod对象，将每一个服务进程包装到相对应的Pod中，使其成为Pod中运行的一个容器。为了创建Service与Pod间的关联管理，Kubernetes给每一个Pod贴上一个标签Label，好比运行MySQL的Pod贴上name=mysql标签，给运行PHP的Pod贴上name=php标签，而后给相应的Service定义标签选择器Label Selector，这样就能巧妙的解决了Service于Pod的关联问题。

在集群管理方面，Kubernetes将集群中的机器划分为一个Master节点和一群工做节点Node，其中，在Master节点运行着集群管理相关的一组进程kube-apiserver、kube-controller-manager和kube-scheduler，这些进程实现了整个集群的资源管理、Pod调度、弹性伸缩、安全控制、系统监控和纠错等管理能力，而且都是全自动完成的。Node做为集群中的工做节点，运行真正的应用程序，在Node上Kubernetes管理的最小运行单元是Pod。Node上运行着Kubernetes的kubelet、kube-proxy服务进程，这些服务进程负责Pod的建立、启动、监控、重启、销毁以及实现软件模式的负载均衡器。

在Kubernetes集群中，它解决了传统IT系统中服务扩容和升级的两大难题。你只需为须要扩容的Service关联的Pod建立一个Replication Controller简称（RC），则该Service的扩容及后续的升级等问题将迎刃而解。在一个RC定义文件中包括如下3个关键信息。

目标Pod的定义
目标Pod须要运行的副本数量（Replicas）
要监控的目标Pod标签（Label）
　　在建立好RC后，Kubernetes会经过RC中定义的的Label筛选出对应Pod实例并实时监控其状态和数量，若是实例数量少于定义的副本数量，则会根据RC中定义的Pod模板来建立一个新的Pod，而后将新Pod调度到合适的Node上启动运行，知道Pod实例的数量达到预约目标，这个过程彻底是自动化。

## Namespace

Namespace 是用来做一个集群内部的逻辑隔离的，它包括鉴权、资源管理等。Kubernetes 的每个资源，比如刚才讲的 Pod、Deployment、Service 都属于一个 Namespace，同一个 Namespace 中的资源需要命名的唯一性，不同的 Namespace 中的资源可以重名。

Namespace 一个用例，比如像在阿里巴巴，我们内部会有很多个 business units，在每一个 business units 之间，希望有一个视图上的隔离，并且在鉴权上也不一样，在 cuda 上面也不一样，我们就会用 Namespace 来去给每一个 BU 提供一个他所看到的这么一个看到的隔离的机制。

# Node中组件

节点组件在每个节点上运行，维护运行的 Pod 并提供 Kubernetes 运行环境。

### kubelet

一个在集群中每个node上运行的代理。 它保证容器都 运行在 Pod 中。kubelet 定期接收新的或修改过的 pod 规范 PodSpecs（主要通过 kube-apiserver）并确保 pod 及容器健康并以所需状态运行。该组件还向 kube-apiserver 报告运行它的主机的健康状况。

kubelet 不会管理不是由 Kubernetes 创建的容器。

- Container Runtime Interface：简称CRI（容器运行时接口），提供容器运行时通用插件接口服务。CRI定义了容器和镜像服务的接口。CRI将kubelet组件与容器运行时进行解耦，将原来完全面向Pod级别的内部接口拆分成面向Sandbox和Container的gRPC接口，并将镜像管理和容器管理分离给不同的服务。
- Container Network Interface：简称CNI（容器网络接口），提供网络通用插件接口服务。CNI定义了Kubernetes网络插件的基础，容器创建时通过CNI插件配置网络。
- Container Storage Interface：简称CSI（容器存储接口），提供存储通用插件接口服务。CSI定义了容器存储卷标准规范，容器创建时通过CSI插件配置存储卷。

### kube-proxy

kube-proxy 是集群中每个节点上运行的网络代理， 实现 Kubernetes 服务（Service） 概念的一部分。用于处理单个主机子网划分并向外部世界公开服务。它跨集群中的各种隔离网络将请求转发到正确的 pod/容器。

kube-proxy 维护节点上的网络规则。这些网络规则允许从集群内部或外部的网络会话与 Pod 进行网络通信。

如果操作系统提供了数据包过滤层并可用的话，kube-proxy 会通过它来实现网络规则。否则， kube-proxy 仅转发流量本身。

kube-proxy组件，作为节点上的网络代理，运行在每个Kubernetes节点上。它监控kube-apiserver的服务和端点资源变化，并通过iptables/ipvs等配置负载均衡器，为一组Pod提供统一的TCP/UDP流量转发和负载均衡功能。

kube-proxy组件是参与管理Pod-to-Service和External-to-Service网络的最重要的节点组件之一。kube-proxy组件相当于代理模型，对于某个IP:Port的请求，负责将其转发给专用网络上的相应服务或应用程序。但是，kube-proxy组件与其他负载均衡服务的区别在于，kube-proxy代理只向Kubernetes服务及其后端Pod发出请求。

### 容器运行时（Container Runtime）

容器运行时负责创建容器运行环境。

Kubernetes 支持多个容器运行时: Docker（即将被废弃）、containerd、rkt, CRI-O以及任何实现 Kubernetes CRI (容器运行环境接口)的runtime。

# k8s 核心的功能：

- 服务的发现与负载的均衡；
- 容器的自动装箱，我们也会把它叫做 scheduling，就是“调度”，把一个容器放到一个集群的某一个机器上，Kubernetes 会帮助我们去做存储的编排，让存储的声明周期与容器的生命周期能有一个连接；
- Kubernetes 会帮助我们去做自动化的容器的恢复。在一个集群中，经常会出现宿主机的问题或者说是 OS 的问题，导致容器本身的不可用，Kubernetes 会自动地对这些不可用的容器进行恢复；
- Kubernetes 会帮助我们去做应用的自动发布与应用的回滚，以及与应用相关的配置密文的管理；
- 对于 job 类型任务，Kubernetes 可以去做批量的执行；
- 为了让这个集群、这个应用更富有弹性，Kubernetes 也支持水平的伸缩。

Kubernetes 有一个节点健康检查的功能，它会监测这个集群中所有的宿主机，当宿主机本身出现故障，或者软件出现故障的时候，这个节点健康检查会自动对它进行发现。

Kubernetes 有业务负载检查的能力，它会监测业务上所承担的负载，如果这个业务本身的 CPU 利用率过高，或者响应时间过长，它可以对这个业务进行一次扩容。

#

Kubernetes一个核心的特点就是能够自主的管理容器来保证云平台中的容器按照用户的期望状态运行着（比如用户想让apache一直运行，用户不需要关心怎么去做，Kubernetes会自动去监控，然后去重启，新建，总之，让apache一直提供服务）


管理员可以加载一个微型服务，让规划器来找到合适的位置，同时，Kubernetes也系统提升工具以及人性化方面，让用户能够方便的部署自己的应用


Kubenetes中，所有的容器均在Pod中运行,一个Pod可以承载一个或者多个相关的容器，在后边的案例中，同一个Pod中的容器会部署在同一个物理机器上并且能够共享资源。一个Pod也可以包含O个或者多个磁盘卷组（volumes）,这些卷组将会以目录的形式提供给一个容器，或者被所有Pod中的容器共享，对于用户创建的每个Pod,系统会自动选择那个健康并且有足够容量的机器，然后创建类似容器的容器,当容器创建失败的时候，容器会被node agent自动的重启,这个node agent叫kubelet,但是，如果是Pod失败或者机器，它不会自动的转移并且启动，除非用户定义了 replication controller。

用户可以自己创建并管理Pod,Kubernetes将这些操作简化为两个操作：基于相同的Pod配置文件部署多个Pod复制品；创建可替代的Pod当一个Pod挂了或者机器挂了的时候。而Kubernetes API中负责来重新启动，迁移等行为的部分叫做“replication controller”，它根据一个模板生成了一个Pod,然后系统就根据用户的需求创建了许多冗余，这些冗余的Pod组成了一个整个应用，或者服务，或者服务中的一层。一旦一个Pod被创建，系统就会不停的监控Pod的健康情况以及Pod所在主机的健康情况，如果这个Pod因为软件原因挂掉了或者所在的机器挂掉了，replication controller 会自动在一个健康的机器上创建一个一摸一样的Pod,来维持原来的Pod冗余状态不变，一个应用的多个Pod可以共享一个机器。

我们经常需要选中一组Pod，例如，我们要限制一组Pod的某些操作，或者查询某组Pod的状态，作为Kubernetes的基本机制，用户可以给Kubernetes Api中的任何对象贴上一组 key:value的标签，然后，我们就可以通过标签来选择一组相关的Kubernetes Api 对象，然后去执行一些特定的操作，每个资源额外拥有一组（很多） keys 和 values,然后外部的工具可以使用这些keys和vlues值进行对象的检索，这些Map叫做annotations（注释）。

# Docker by default uses bridge network.

Or if you are using kubernetes, for instance, to manage your Docker containers, let it handle the IP Addresses for you kubernetes-expose-external-ip-address ?.

https://kubernetes.io/docs/tutorials/stateless-application/expose-external-ip-address/

By default docker compose sets up a single network for your app. And your app’s network is given a name based on the “project name”, originated from the name of the directory it lives in.

How to Get A Docker Container IP Address - examples

 --format option of inspect comes to the rescue.

Modern Docker client syntax is:

```shell
$ docker inspect -f '{{range.NetworkSettings.Networks}}{{.IPAddress}}{{end}}' container_name_or_id
Old Docker client syntax is:

$ docker inspect --format '{{ .NetworkSettings.IPAddress }}' container_name_or_id
```

//// he new format is specific to the container and follows the form {{ .NetworkSettings.Networks.$network.IPAddress }}. The default appears to be bridge, but under docker-compose this will be a specific name that depends on the name of your app (I think from the --project-name flag, though that's also going to depend on what type of networking config you have set up)

 use docker inspect <container id>.

For example:

CID=$(docker run -d -p 4321 base nc -lk 4321);
docker inspect $CID

like docker inspect $CID | grep IPAddress | cut -d '"' -f 4, it works fine

Now, you can get the IP

```bash
$ docker inspect -format '{{ .NetworkSettings.IPAddress }}' ${CID}
```

Bash script to get a table of IP addresses from all containers running under docker-compose.

```shell
function docker_container_names() {
    docker ps -a --format "{{.Names}}" | xargs
}

# Get the IP address of a particular container
dip() {
    local network
    network='YOUR-NETWORK-HERE'
    docker inspect --format "{{ .NetworkSettings.Networks.$network.IPAddress }}" "$@"
}

dipall() {
    for container_name in $(docker_container_names);
    do
        local container_ip=$(dip $container_name)
        if [[ -n "$container_ip" ]]; then
            echo $(dip $container_name) " $container_name"
        fi
    done | sort -t . -k 3,3n -k 4,4n
}
```

1. Using Docker Inspect

Docker inspect is a great way to retrieve low-level information on Docker objects. You can pick out any field from the returned JSON in a fairly straightforward manner.

So shall we use it to get the IP Address from the dockerhive_datanode?

```shell
$ docker inspect -f \
'{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' \
75000c343eb7

172.18.0.5

docker network inspect -f '{{range .IPAM.Config}}{{.Subnet}}{{end}}' pro_default
172.18.0.0/16

$ docker network inspect -f \
'{{json .Containers}}' 9f6bc3c15568 | \
jq '.[] | .Name + ":" + .IPv4Address'
```

1. Using Docker exec

In the following example we will work with the dockerhive_namenode.

$ docker exec dockerhive_namenode cat /etc/hosts

127.0.0.1       localhost
::1     localhost ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
172.18.0.3      607b00c25f29

1. Inside the Docker Container

```
$ docker exec -it dockerhive_namenode /bin/bash

# running inside the dockerhive_namenode container
ip -4 -o address

7: eth0    inet 172.18.0.3/16 brd 172.18.255.255 scope global eth0

https://icons8.com/

https://tehnoblog.org/ip-tools/ip-address-in-cidr-range/

docker-compose.yml

version: "3"

services:
  namenode:
    image: bde2020/hadoop-namenode:2.0.0-hadoop2.7.4-java8
    volumes:
      - namenode:/hadoop/dfs/name
    environment:
      - CLUSTER_NAME=test
    env_file:
      - ./hadoop-hive.env
    ports:
      - "50070:50070"
  datanode:
    image: bde2020/hadoop-datanode:2.0.0-hadoop2.7.4-java8
    volumes:
      - datanode:/hadoop/dfs/data
    env_file:
      - ./hadoop-hive.env
    environment:
      SERVICE_PRECONDITION: "namenode:50070"
    ports:
      - "50075:50075"
  hive-server:
    image: bde2020/hive:2.3.2-postgresql-metastore
    env_file:
      - ./hadoop-hive.env
    environment:
      HIVE_CORE_CONF_javax_jdo_option_ConnectionURL: "jdbc:postgresql://hive-metastore/metastore"
      SERVICE_PRECONDITION: "hive-metastore:9083"
    ports:
      - "10000:10000"
  hive-metastore:
    image: bde2020/hive:2.3.2-postgresql-metastore
    env_file:
      - ./hadoop-hive.env
    command: /opt/hive/bin/hive --service metastore
    environment:
      SERVICE_PRECONDITION: "namenode:50070 datanode:50075 hive-metastore-postgresql:5432"
    ports:
      - "9083:9083"
  hive-metastore-postgresql:
    image: bde2020/hive-metastore-postgresql:2.3.0

volumes:
  namenode:
  datanode:
```

# minikube

```
minikube start --image-mirror-country='cn'
minikube 提供了非常多的配置参数，

```
> --driver=*** 从1.5.0版本开始，Minikube缺省使用系统优选的驱动来创建Kubernetes本地环境，比如您已经安装过Docker环境，minikube 将使用 docker 驱动
> --cpus=2: 为minikube虚拟机分配CPU核数
> --memory=2048mb: 为minikube虚拟机分配内存数
> --registry-mirror=*** 为了提升拉取Docker Hub镜像的稳定性，可以为 Docker daemon 配置镜像加速，参考阿里云镜像服务
> --kubernetes-version=***: minikube 虚拟机将使用的 kubernetes 版本
```

比如， 创建 minikube 环境并且调整默认资源配置

minikube start --image-mirror-country='cn' --cpus=4 --memory=4096mb
```

使用Minikube
用户使用Minikube CLI管理虚拟机上的Kubernetes环境，比如：启动，停止，删除，获取状态等。一旦Minikube虚拟机启动，用户就可以使用熟悉的Kubectl CLI在Kubernetes集群上执行操作。

Minikube 也提供了丰富的 Addon 组件

$ minikube addons list


----

# CNCF

CNCF自创立以来已经拥有非常多的高质量项目，其中包括Kubernetes、Prometheus、gRPC、CoreDNS等。

云原生系统的设计理念如下:

- 面向分布式设计（Distribution）：容器、微服务、API 驱动的开发；
- 面向配置设计（Configuration）：一个镜像，多个环境配置；
- 面向韧性设计（Resistancy）：故障容忍和自愈；
- 面向弹性设计（Elasticity）：弹性扩展和对环境变化（负载）做出响应；
- 面向交付设计（Delivery）：自动拉起，缩短交付时间；
- 面向性能设计（Performance）：响应式，并发和资源高效利用；
- 面向自动化设计（Automation）：自动化的 DevOps；
- 面向诊断性设计（Diagnosability）：集群级别的日志、metric 和追踪；
- 面向安全性设计（Security）：安全端点、API Gateway、端到端加密；

是实现云原生应用程序所需特性的常用方法：

微服务
健康报告
遥测数据
弹性
声明式的，而不是命令式的


## 提供健康检查的应用程序示例包括 Zookeeper 的 ruok 命令和 etcd 的 HTTP / 健康端点。




## 遥测数据
遥测数据是进行决策所需的信息。确实，遥测数据可能与健康报告重叠，但它们有不同的用途。健康报告通知我们应用程序生命周期状态，而遥测数据通知我们应用程序业务目标。

您测量的指标有时称为服务级指标（SLI）或关键性能指标（KPI）。这些是特定于应用程序的数据，可以确保应用程序的性能处于服务级别目标（SLO）内。如果您需要更多关于这些术语的信息以及它们与您的应用程序、业务需求的关系，我们推荐你阅读来自 Site Reliability Engineering（O'Reilly）的第 4 章。

遥测和度量标准用于解决以下问题：

应用程序每分钟收到多少请求？
有没有错误？
什么是应用程序延迟？
订购需要多长时间？
通常会将数据刮取或推送到时间序列数据库（例如 Prometheus 或 InfluxDB）进行聚合。遥测数据的唯一要求是它将被收集数据的系统格式化。

至少，可能最好实施度量标准的 RED 方法，该方法收集应用程序的速率，错误和执行时间。

请求率

收到了多少个请求

错误

应用程序有多少错误

时间

多久才能收到回复



## 声明式，非反应式
因为云原生应用程序被设计为在云环境中运行，所以它们与基础设施以及相关依赖应用程序的交互方式不同于传统应用程序。在云原生应用程序中，与任何事物的通信都需要通过网络来进行。很多时候，网络通信是通过 RESTful HTTP 调用完成的，但是也可以通过其他接口实现，比如远程过程调用 (RPC)。

传统的应用程序会通过向消息队列发送消息、在共享存储上写入文件或触发本地 shell 脚本来执行自动化任务。通信方法基于发生的事件作出反应（例如，如果用户单击提交，运行提交脚本）并且通常需要存在于同一物理或虚拟服务器上的信息。

Serverless

无服务器平台是云原生化的，并被设计为对事件做出反应。他们在云中工作得很好的原因是他们通过 HTTP API 进行通信，（这些 API）是单一用途的函数，并且在它们的调用中是声明性的。该平台还使它们可伸缩并可从云内访问。

传统应用程序中的反应式通信通常是构建弹性的一种尝试。如果应用程序（以反应式的方式）在磁盘上或消息队列中写入了一个文件，然后应用程序死亡，那么该消息或文件的结果仍然可以完成。

这里并不是说不应该使用像消息队列这样的技术，而是说在动态且经常出现故障的系统中，不能将它们作为惟一的弹性层来依赖。从根本上说，在云原生环境之中，应用程序之间的通信方法应该有所变化 - 这不仅是因为还存在其他方法来构建通信弹性（请参阅附录 A），而且还因为如果要让传统的通信方法在云中实现复制，我们往往需要做更多工作。

当应用程序可以信任通信的弹性时，它们应该放弃反应式并使用声明式。声明式通信信任网络会将消息送达。它也相信应用程序将返回成功或错误。这并不是说让应用程序观察变化不重要。Kubernetes 的控制器对 API 服务器做的就是这个。但是，一旦发现变更，他们就会声明一个新的状态，并相信 API 服务器和 kubelets 会做必要的事情。

声明式通信模型由于多种原因而变得更加健壮。最重要的是，它规范了通信模型，并且它将（如何从某种状态到达期望状态的）功能实现从应用程序转移到远程 API 或服务端点。这有助于简化应用程序，并使它们彼此的行为更具可预测性。


# katacoda

Configure Git Repository for Scenarios
Scenarios are stored within a Git repository. This allows teams to collaborate and share ideas around the Katacoda content.


Visit https://www.katacoda.com/ashang to view the profile and interactive scenarios

Writing Scenarios
Visit https://www.katacoda.com/docs to learn more about creating Katacoda scenarios

For examples, visit https://github.com/katacoda/scenario-example



npm install katacoda-cli




# $ docker run -ti appropriate/tcpdump -i any -U -w -



# Istio 服务网格
Istio 使用功能强大的 Envoy 服务代理扩展了 Kubernetes，以建立一个可编程的、可感知的应用程序网络。Istio 与 Kubernetes 和传统工作负载一起使用，为复杂的部署带来了标准的通用流量管理、遥测和安全性。



服务网格介绍
现代应用程序通常被设计成微服务的分布式集合，每个服务执行一些离散的业务功能。服务网格是专门的基础设施层，包含了组成这类体系结构的微服务网络。 服务网格不仅描述了这个网络，而且还描述了分布式应用程序组件之间的交互。所有在服务之间传递的数据都由服务网格控制和路由。

随着分布式服务的部署——比如基于 Kubernetes 的系统——规模和复杂性的增长，它可能会变得更加难以理解和管理。需求可以包括发现、负载平衡、故障恢复、度量和监视。微服务体系结构通常还有更复杂的操作需求，比如 A/B 测试、canary 部署、速率限制、访问控制、加密和端到端身份验证。

服务到服务的通信使分布式应用成为可能。在应用程序集群内部和跨应用程序集群路由这种通信变得越来越复杂。 Istio 有助于减少这种复杂性，同时减轻开发团队的压力。

Istio 介绍
Istio 是一个开源服务网格，它透明地分层到现有的分布式应用程序上。 Istio 强大的特性提供了一种统一和更有效的方式来保护、连接和监视服务。 Istio 是实现负载平衡、服务到服务身份验证和监视的路径——只需要很少或不需要更改服务代码。它强大的控制平面带来了重要的特点，包括：

使用 TLS 加密、强身份认证和授权的集群内服务到服务的安全通信
自动负载均衡的 HTTP, gRPC, WebSocket，和 TCP 流量
通过丰富的路由规则、重试、故障转移和故障注入对流量行为进行细粒度控制
一个可插入的策略层和配置 API，支持访问控制、速率限制和配额
对集群内的所有流量(包括集群入口和出口)进行自动度量、日志和跟踪
Istio 是为可扩展性而设计的，可以处理不同范围的部署需求。Istio 的控制平面运行在 Kubernetes 上，您可以将部署在该集群中的应用程序添加到您的网格中，将网格扩展到其他集群，甚至连接 VM 或运行在 Kubernetes 之外的其他端点。

一个由贡献者、合作伙伴、集成商和分销商组成的庞大生态系统将 Istio 扩展和利用到各种各样的场景中。

您可以自己安装 Istio，或者许多供应商都有集成 Istio 并为您管理它的产品。

工作说明
Istio 由两个部分组成：控制平面和数据平面。

数据平面是业务之间的通信平面。如果没有一个服务网格，网络就无法理解正在发送的流量，也无法根据它是哪种类型的流量，或者它从谁那里来，到谁那里去做出任何决定。

服务网格使用代理拦截所有的网络流量，允许根据您设置的配置提供广泛的应用程序感知功能。

代理与您在集群中启动的每个服务一起部署，或者与运行在虚拟机上的服务一起运行。

控制平面获取您所需的配置和服务视图，并动态地对代理服务器进行编程，随着规则或环境的变化更新它们。

## 概念
流量管理
Istio 的流量路由规则可以让您轻松地控制服务之间的流量和 API 调用。 Istio 简化了服务级别属性(如断路器、超时和重试)的配置，并使设置重要任务(如 A/B 测试、canary 部署和基于百分比的流量分割的分阶段部署)变得容易。 它还提供了开箱即用的故障恢复特性，帮助您的应用程序更健壮地应对依赖服务或网络的故障。

可观测性
Istio 为服务网格内的所有通信生成详细的遥测数据。这种遥测技术提供了服务行为的可观测性，使运营商能够排除故障、维护和优化其应用。 更好的是，它不会给服务开发人员带来任何额外的负担。通过 Istio，操作人员可以全面了解被监视的服务如何与其他服务以及 Istio 组件本身交互。

Istio 的遥测技术包括详细的指标、分布式跟踪和完整的访问日志。有了 Istio，您就可以得到全面全面的服务网格可观察性。

安全性能
微服务有特殊的安全需求，包括防止中间人攻击、灵活的访问控制、审计工具和相互的 TLS。 Istio 包括一个全面的安全解决方案，使运营商能够解决所有这些问题。 它提供了强大的身份、强大的策略、透明的 TLS 加密，以及验证、授权和审计（AAA）工具来保护您的服务和数据。

Istio 的安全模型是基于默认安全的，旨在提供深度防御，允许您部署安全的应用程序，甚至跨不可信的网络。


#  Dockerfile

在项目根目录中添加一个Dockerfile文件（文件名就叫Dockerfile），定义如何构建Docker镜像，以Spring Boot项目为例：

```dockerfile
FROM frolvlad/alpine-java:jdk8-slim
在build镜像时可以通过 --build-args profile=xxx 进行修改
ARG profile
ENV SPRING_PROFILES_ACTIVE=${profile}
项目的端口
EXPOSE 8000
WORKDIR /mnt
修改时区
&& apk add --no-cache tzdata \
&& ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime \
&& echo "Asia/Shanghai" > /etc/timezone \
&& apk del tzdata \
&& rm -rf /var/cache/apk/* /tmp/* /var/tmp/* $HOME/.cache

COPY ./target/your-project-name-1.0-SNAPSHOT.jar ./app.jar
ENTRYPOINT ["java", "-jar", "/mnt/app.jar"]

将SPRING_PROFILES_ACTIVE通过参数profile暴露出来，在构建的时候可以通过--build-args profile=xxx来进行动态设定，以满足不同环境的镜像构建要求。

SPRING_PROFILES_ACTIVE本可以在Docker容器启动时通过docker run -e SPRING_PROFILES_ACTIVE=xxx来设定，因这里使用Helm进行部署不直接通过docker run运行，因此通过ARG在镜像构建时指定

RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.ustc.edu.cn/g' /etc/apk/repositories \
```

Helm配置文件
Helm是Kubernetes的包管理工具，将应用部署相关的Deployment，Service，Ingress等打包进行发布与管理（可以像Docker镜像一样存储于仓库中）。

# 搭建 k8s 环境

主机名解析
为了集群节点间的直接调用，我们需要配置一下主机名解析，分别在三台服务器上编辑 /etc/hosts

同步时间
集群中的时间必须要精确一致，我们可以直接使用chronyd服务从网络同步时间，三台服务器需做同样的操作

禁用iptables和firewalld服务
kubernetes和docker在运行中会产生大量的iptables规则，为了不让系统规则跟它们混淆，直接关闭系统的规则

需要修改linux的内核参数，添加网桥过滤和地址转发功能，编辑/etc/sysctl.d/kubernetes.conf文件，添加如下配置:

net.bridge.bridge-nf-call-ip6tables = 1
net.bridge.bridge-nf-call-iptables = 1
net.ipv4.ip_forward = 1
添加后进行以下操作：

# 重新加载配置

[root@master ~]# sysctl -p

# 加载网桥过滤模块

[root@master ~]# modprobe br_netfilter

# 查看网桥过滤模块是否加载成功
[root@master ~]# lsmod | grep br_netfilter



配置 ipvs 功能
在kubernetes中service有两种代理模型，一种是基于iptables的，一种是基于ipvs的
相比较的话，ipvs的性能明显要高一些，但是如果要使用它，需要手动载入ipvs模块

# 安装ipset和ipvsadm
[root@master ~]# yum install ipset ipvsadmin -y

# 添加需要加载的模块写入脚本文件
[root@master ~]# cat <<EOF > /etc/sysconfig/modules/ipvs.modules
#!/bin/bash
modprobe -- ip_vs
modprobe -- ip_vs_rr
modprobe -- ip_vs_wrr
modprobe -- ip_vs_sh
modprobe -- nf_conntrack_ipv4
EOF
# 为脚本文件添加执行权限
[root@master ~]# chmod +x /etc/sysconfig/modules/ipvs.modules
# 执行脚本文件
[root@master ~]# /bin/bash /etc/sysconfig/modules/ipvs.modules
# 查看对应的模块是否加载成功
[root@master ~]# lsmod | grep -e ip_vs -e nf_conntrack_ipv4


# Docker在默认情况下使用的Cgroup Driver为cgroupfs，而kubernetes推荐使用systemd来代替cgroupfs


集群初始化
1、由于 kubernetes 的镜像源在国外，速度比较慢，因此我们需要切换成国内的镜像源

# 编辑 /etc/yum.repos.d/kubernetes.repo 添加一下配置
[root@master ~]# vim /etc/yum.repos.d/kubernetes.repo
[kubernetes]
name=Kubernetes
baseurl=http://mirrors.aliyun.com/kubernetes/yum/repos/kubernetes-el7-x86_64
enabled=1
gpgcheck=0
repo_gpgcheck=0
gpgkey=http://mirrors.aliyun.com/kubernetes/yum/doc/yum-key.gpg
http://mirrors.aliyun.com/kubernetes/yum/doc/rpm-package-key.gpg
￼

2、然后安装kubeadm、kubelet和kubectl 三个组件

yum install --setopt=obsoletes=0 kubeadm-1.17.4-0 kubelet-1.17.4-0
kubectl-1.17.4-0 -y


3、配置 kubelet 的group

# 编辑 /etc/sysconfig/kubelet，添加下面的配置
KUBELET_CGROUP_ARGS="--cgroup-driver=systemd"
KUBE_PROXY_MODE="ipvs"
￼

4、这步是来初始化集群的，因此只需在 master 服务器上执行即可，上面那些是每个服务器都需要执行！

# 创建集群
# 由于默认拉取镜像地址 k8s.gcr.io 国内无法访问，这里指定阿里云镜像仓库地址
[root@master ~]# kubeadm init \
--apiserver-advertise-address=192.168.108.100 \
--image-repository registry.aliyuncs.com/google_containers \
--kubernetes-version=v1.17.4 \
--pod-network-cidr=10.244.0.0/16 \
--service-cidr=10.96.0.0/12

#使用 kubectl 工具
[root@master ~]# mkdir -p $HOME/.kube
[root@master ~]# sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
[root@master ~]# sudo chown $(id -u):$(id -g) $HOME/.kube/config
￼

然后我们需要将node 节点加入集群中，在 node 服务器 上执行上述红框的命令：

[root@master ~]# kubeadm join 192.168.108.100:6443 --token xxx \
--discovery-token-ca-cert-hash sha256:xxx
便可在 master 节点 获取到节点信息：

￼

但是我们这个时候查看集群状态都是为NotReady，这是因为还没有配置网络插件

5、安装网络插件

kubernetes支持多种网络插件，比如flannel、calico、canal等等，这里选择使用flanne



https://github.com/flannel-io/flannel/releases/


下载完成后，上传至 master 服务器 执行以下命令

docker load < flanneld-v0.13.0-amd64.docker
执行完成后便可看到多了个 flannel 镜像：



然后我们需要获取flannel的配置文件来部署 flannel 服务

[root@master ~]# wget https://raw.githubusercontent.com/coreos/flannel/master/Documentation/kube-flannel.yml

# 使用配置文件启动fannel
[root@master ~]# kubectl apply -f kube-flannel.yml

# 再次查看集群节点的状态
[root@master ~]# kubectl get nodes


这个时候所有节点的状态都是Ready 的状态，到此为止，我们的 k8s 集群就算搭建完成了！

5）集群功能验证
接下来就是我们的验证时间，之前我们学 docker 的时候往往会启动一个 nginx 容器来测试是否可用，k8s 我们也同样来部署一个 nginx 来测试下服务是否可用~

（下面例子为测试例子，如果不清楚每个指令的作用也不要紧，后面我们会出篇 k8s 的教学文章来说明 k8s 如果使用！）

首先我们创建一个 deployment
[root@master ~]# kubectl create deployment nginx --image=nginx:1.14-alpine
deployment.apps/nginx created

[root@master ~]# kubectl get deploy
NAME    READY   UP-TO-DATE   AVAILABLE   AGE
nginx   1/1     1            1           31s
然后创建一个 service 来让外界能够访问到我们 nginx 服务
[root@master ~]# kubectl expose deploy nginx --port=80 --target-port=80 --type=NodePort
service/nginx exposed

[root@master ~]# kubectl get svc
NAME         TYPE        CLUSTER-IP       EXTERNAL-IP   PORT(S)        AGE
nginx        NodePort    10.110.224.214   <none>        80:31771/TCP   5s
然后我们通过 node 节点的 IP 加上service 暴露出来的 nodePort 来访问我们的 nginx 服务：


也可以直接在集群中通过 service 的 IP 加上映射出来的 port 来访问我们的服务：

从结果上看两种访问都是可用的，说明我们的 nginx 服务部署成功，

kubernetes 启动后，无论是 master 节点 亦或者 node 节点，都会将自身的信息存储到 etcd 数据库中
创建 nginx 服务，首先会将安装请求发送到 master 节点上的 apiServer 组件中
apiServer 组件会调用 scheduler 组件来决定应该将该服务安装到哪个 node 节点上。这个时候就需要用到 etcd 数据库了，scheduler会从 etcd 中读取各个 node 节点的信息，然后按照一定的算法进行选择，并将结果告知给 apiServer
apiServer 调用 controllerManager 去调度 node 节点，并安装 nginx 服务
node 节点上的 kubelet 组件接收到指令后，会通知docker，然后由 docker 来启动一个 nginx 的pod

pod 是 kubernetes 中的最小操作单元，容器都是跑在 pod 中
以上步骤完成后，nginx 服务便运行起来了，如果需要访问 nginx，就需要通过 kube-proxy 来对 pod 产生访问的代理，这样外部用户就能访问到这个 nginx 服务

