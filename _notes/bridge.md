
```
ifconfig docker0 down
brctl delbr docker0

# 开始创建自定义网桥，并绑定宿主机实体网卡，这种方式docker不认这个网段
brctl addbr br0
ifconfig br0 10.10.200.172 netmask 255.255.255.0
brctl addif br0 eth1

# docker 添加网络
docker network create -d bridge sdx # 新建虚拟网络
# 例子
docker run -itd --name suse11 --network sdx opensuse /bin/bash


#创建自定义网桥
docker network create br0 -d bridge -o com.docker.network.bridge.name='br0' \
--subnet=10.10.200.0/24 --ip-range=10.10.200.0/24 --gateway=10.10.200.172

# 下面绑定网卡，通过桥接的方式实现不同宿主机上容器的互通
# 下面这两步必须做，否则将来容器不互通。而做了这步之后，实体网卡上的IP地址就不通了。
ifconfig eth1 0.0.0.0    # 将物理网卡IP值空
brctl addif docker0 eth1 # 将docker0 桥接到 eth1 上
```

# 容器分配固定IP

```
# 用固定IP启动容器
docker run -itd --name ctos83.1 --network br0 --ip=10.10.200.39 centos

# 容器带特权启动
docker run -itd --name suse.43 --network br0 --ip=10.10.200.43 
--privileged sdx/opensuse42.3

# 容器启动systemd
docker run -itd --name=suse153-13-49 -h=suse153-13-49 --network=br0 --ip=10.10.13.49 
--restart=always --privileged --volume /sys/fs/cgroup:/sys/fs/cgroup:ro 
-v /data/data49:/home/bmc 10.10.200.11:5000/suse153.nodejs.14.17 /sbin/init

# 进入容器
docker exec -it suse.43 /bin/bash

# 给容器添加第二块网卡
# 先创建一个网桥br0，然后给指定容器添加网桥br0，立刻回在容器中看到多了一块虚拟网卡。
docker network connect br0 ctos83.1 [--ip=172.10.200.xxx] # 添加网桥[并指定 IP]
docker network disconnect br0 ctos83.1 # 删除网卡
参考：

https://tsov.net/uupee/22859/

https://blog.csdn.net/qwertyupoiuytr/article/details/54142055

已经给容器分配的IP如何修改？
大家可以用docker inspect ctos83.162命令来查看配置信息。这里的配置信息是可以更改的，比如我们的容器/home/dockerRoot/containers/...目录中有如下的文件：

 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
.
├── xxx...xxx-json.log
├── checkpoints
├── config.v2.json
├── hostconfig.json
├── hostname
├── hosts
├── mounts
│   └── shm
├── resolv.conf
└── resolv.conf.hash

#vi config.v2.json 可以修改其中的IP地址
注意

这里要特别提醒，直接修改配置没那么容易，修改的配置在镜像重启之后就又被还原了。有效的办法是先关闭 docker.service服务，再修改配置文件，最后再启动docker.service服务，重启容器看看里面的IP变化没有。

下面典型的配置示例（centos系统）
 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
14
15
# 启动容器（挂载主机目录）
docker run -itd --name ctos83.190 --privileged=true -v /oradata/data190:/home/bmc 
	dxhj/ctos83.mysql8:210401 /usr/sbin/init

# 主机添加网桥
docker network create br200 -d bridge -o com.docker.network.bridge.name='br200' 
	--subnet=10.10.200.0/24 --ip-range=10.10.200.0/24 --gateway=10.10.200.1

# 容器启动systemd
docker run -itd --name=suse153-13-49 -h=suse153-13-49 --network=br0 --ip=10.10.13.49 
--restart=always --privileged --volume /sys/fs/cgroup:/sys/fs/cgroup:ro 
-v /data/data49:/home/bmc 10.10.200.11:5000/suse153.nodejs.14.17 /sbin/init

# 给容器添加一个固定IP
docker network connect br200 ctos83.190 --ip=10.10.200.190

```
