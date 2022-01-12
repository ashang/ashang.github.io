---
title: container
date: 2017-07-30
update: 2016-11-11 11:00:00 CST
---

Workload Orchestration Made Easy

A simple and flexible workload orchestrator to deploy and manage containers and non-containerized applications across on-prem and clouds at scale.

Why Nomad?
Simple and Lightweight
Simple and Lightweight

Single binary that integrates into existing infrastructure. Easy to operate on-prem or in the cloud with minimal overhead.
Flexible Workload Support
Flexible Workload Support

Orchestrate applications of any type - not just containers. First class support for Docker, Windows, Java, VMs, and more.
Modernize Legacy Applications without Rewrite
Modernize Legacy Applications without Rewrite

Bring orchestration benefits to existing services. Achieve zero downtime deployments, improved resilience, higher resource utilization, and more without containerization.
Easy Federation at Scale
Easy Federation at Scale

Single command for multi-region, multi-cloud federation. Deploy applications globally to any region using Nomad as a single unified control plane.
Deploy and Scale with Ease
Deploy and Scale with Ease

Deploy to bare metal with the same ease as in cloud environments. Scale globally without complexity. Read the 2 Million Container Challenge.
Native Integrations with Terraform, Consul, and Vault
Native Integrations with Terraform, Consul, and Vault

Nomad integrates seamlessly with Terraform, Consul and Vault for provisioning, service networking, and secrets management.

## Nomad

Nomad, borrowing terminology from Google’s Borg scheduler, refers to its basic unit of work as a job. Each job is composed of many tasks. A task is an application to run, which is a Docker container in this test. Nomad can also schedule other tasks such as VMs, binaries, etc, but only Docker containers were used as part of C2M.

## Nomad vs. Kubernetes

Kubernetes is an orchestration system for containers originally designed by Google, now governed by the Cloud Native Computing Foundation (CNCF) and developed by Google, Red Hat, and many others. Kubernetes and Nomad support similar core use cases for application deployment and management, but they differ in a few key ways. Kubernetes aims to provide all the features needed to run Linux container-based applications including cluster management, scheduling, service discovery, monitoring, secrets management and more. Nomad only aims to focus on cluster management and scheduling and is designed with the Unix philosophy of having a small scope while composing with tools like Consul for service discovery/service mesh and Vault for secret management.

The following characteristics generally differentiate Nomad from Kubernetes:
»Simplicity

Kubernetes is designed as a collection of more than a half-dozen interoperating services which together provide the full functionality. Coordination and storage is provided by etcd at the core. The state is wrapped by API controllers which are consumed by other services that provide higher level APIs for features like scheduling. Kubernetes supports running in a highly available configuration but is operationally complex to setup.

Nomad is architecturally much simpler. Nomad is a single binary, both for clients and servers, and requires no external services for coordination or storage. Nomad combines a lightweight resource manager and a sophisticated scheduler into a single system. By default, Nomad is distributed, highly available, and operationally simple.
»Flexible Workload Support

While Kubernetes is specifically focused on Linux containers, Nomad is more general purpose. Nomad supports virtualized, containerized and standalone applications, including Docker, Java, IIS on Windows, Qemu, etc. Nomad is designed with extensible drivers and support will be extended to all common drivers.
»Consistent Deployment

A full Kubernetes installation for a production environment is time consuming, operationally complex, and resource intensive. An increasing number of implementations are created by the Kubernetes community to mitigate these challenges, such as minikube, kubeadm, k3s, and more. These trimmed versions of Kubernetes offer easier adoption for development and testing, but lead to inconsistency in capabilities, configuration, and management when moving into production.

In contrast to Kubernetes' fragmented distributions, Nomad as a single lightweight binary can be deployed in local dev, production, on-prem, at the edge, and in the cloud in a consistent manner, and provides the same operational ease-of-use across all environments.
»Scalability

Kubernetes documentation states that they support clusters up to 5,000 nodes and 300,000 total containers. As the environment grows, the interoperating components with different constraints compound the operational complexity. Even operators at Google revealed the significant challenges of managing the system at scale. The lack of maturity in the Federation project and the additional overhead of managing a centralized management plane also make it a hard experience to deploy a distributed system that spans multiple clusters.

Nomad has been proven to scale to cluster sizes that exceed 10,000 nodes in real-world production environments. It can be deployed across multiple availability zones, regions, and data centers with a single cluster or multiple clusters. Nomad is designed to natively handle multi-cluster deployments without the overhead of running clusters on clusters. This makes it easier to scale the application deployment across multiple datacenters, regions, and clouds with no additional complexity.

# https://www.hashicorp.com/resources/nomad-ci-cd-developer-workflows-and-integrations

https://www.nomadproject.io/docs/drivers/external/containerd

https://www.nomadproject.io/docs/drivers/external/jail-task-driver

# Runtime options with Memory, CPUs, and GPUs

Estimated reading time: 16 minutes

By default, a container has no resource constraints and can use as much of a given resource as the host’s kernel scheduler allows. Docker provides ways to control how much memory, or CPU a container can use, setting runtime configuration flags of the docker run command. This section provides details on when you should set such limits and the possible implications of setting them.

```
$ docker info
Got permission denied while trying to connect to the Docker daemon socket at unix:///var/run/docker.sock: Get http://%2Fvar%2Frun%2Fdocker.sock/v1.39/info: dial unix /var/run/docker.sock: connect: permission denied
$ sudo docker info
Containers: 10
 Running: 0
 Paused: 0
 Stopped: 10
Images: 4
Server Version: 18.09.1
Storage Driver: overlay2
 Backing Filesystem: extfs
 Supports d_type: true
 Native Overlay Diff: true
Logging Driver: json-file
Cgroup Driver: cgroupfs
Plugins:
 Volume: local
 Network: bridge host macvlan null overlay
 Log: awslogs fluentd gcplogs gelf journald json-file local logentries splunk syslog
Swarm: inactive
Runtimes: runc
Default Runtime: runc
Init Binary: docker-init
containerd version: 9754871865f7fe2f4e74d43e2fc7ccd237edcbce
runc version: 1.0.0~rc6+dfsg1-3
init version: v0.18.0 (expected: fec3683b971d9c3ef73f284f176672c44b448662)
Security Options:
 seccomp
  Profile: default
Kernel Version: 5.4.105
Operating System: Debian GNU/Linux 10 (buster)
OSType: linux
Architecture: x86_64
CPUs: 4
Total Memory: 15.61GiB
Name: sulporx
ID: 6JW5:BRFY:LCEM:ALDI:C3PD:P6KX:AP6L:KGM7:TRCL:HVBF:BEKH:TV46
Docker Root Dir: /udata/docker
Debug Mode (client): false
Debug Mode (server): false
Registry: https://index.docker.io/v1/
Labels:
Experimental: false
Insecure Registries:
 10.10.50.24:5000
 127.0.0.0/8
Live Restore Enabled: false

WARNING: No swap limit support
WARNING: No cpu cfs quota support
WARNING: No cpu cfs period support
```

# 按照docker官方的方式，并使用阿里云镜像安装：

```
dnf -y install dnf-plugins-core

dnf config-manager --add-repo
https://mirrors.aliyun.com/docker-ce/linux/fedora
/docker-ce.repo

dnf install docker-ce docker-ce-cli containerd.io
dnf install grubby   (官方没写，我的fedora31
安装完成后没有grubby命令，需要安装一下)

grubby --update-kernel=ALL --args="systemd.unified_cgroup_hierarchy=0"
```

 2.改变docker储存路径，daocoloud镜像（可选）

 因为我的fedora装在NUC上，NUC是只有4G板载EMMC，装了fedora后没什么空间了，另挂的硬盘挂载在
 /storage
 所以，我要把docker的镜像存再/storage上。要更改存储路径，一般人都不用的。

 Docker 版本在 1.12 或更高
 创建或修改 /etc/docker/daemon.json 文件，修改为如下形式 （请将 加速地址
 替换为在加速器页面获取的专属地址）

```
{
 	    "registry-mirrors": ["http://**************.daocloud.io"],
 	        "graph": "/storage/docker"
}
```

## Understand the risks of running out of memory

 It is important not to allow a running container to consume too much of the
 host machine’s memory. On Linux hosts, if the kernel detects that there is
 not enough memory to perform important system functions, it throws an OOME,
 or Out Of Memory Exception, and starts killing processes to free up memory.
 Any process is subject to killing, including Docker and other important
 applications. This can effectively bring the entire system down if the wrong
 process is killed.

 Docker attempts to mitigate these risks by adjusting the OOM priority on the
 Docker daemon so that it is less likely to be killed than other processes on
 the system. The OOM priority on containers is not adjusted. This makes it
 more likely for an individual container to be killed than for the Docker
 daemon or other system processes to be killed. You should not try to
 circumvent these safeguards by manually setting --oom-score-adj to an extreme
 negative number on the daemon or a container, or by setting
 --oom-kill-disable on a container.


  Memory
  Understand the risks of running out of memory

  It is important not to allow a running container to consume too much of the
  host machine’s memory. On Linux hosts, if the kernel detects that there is
  not enough memory to perform important system functions, it throws an OOME,
  or Out Of Memory Exception, and starts killing processes to free up memory.
  Any process is subject to killing, including Docker and other important
  applications. This can effectively bring the entire system down if the wrong
  process is killed.

  Docker attempts to mitigate these risks by adjusting the OOM priority on the
  Docker daemon so that it is less likely to be killed than other processes on
  the system. The OOM priority on containers is not adjusted. This makes it
  more likely for an individual container to be killed than for the Docker
  daemon or other system processes to be killed. You should not try to
  circumvent these safeguards by manually setting --oom-score-adj to an
  extreme negative number on the daemon or a container, or by setting
  --oom-kill-disable on a container.

```

You can mitigate the risk of system instability due to OOME by:

    Perform tests to understand the memory requirements of your application before placing it into production.
    Ensure that your application runs only on hosts with adequate resources.
    Limit the amount of memory your container can use, as described below.
    Be mindful when configuring swap on your Docker hosts. Swap is slower and less performant than memory but can provide a buffer against running out of system memory.
    Consider converting your container to a service, and using service-level constraints and node labels to ensure that the application runs only on hosts with enough memory




                                         `:setup. ```
                                         ```


                                         The CFS is the Linux kernel CPU
                                         scheduler for normal Linux processes.
                                         Several runtime flags allow you to
                                         configure the amount of access to CPU
                                         resources your container has. When
                                         you use these settings, Docker
                                         modifies the settings for the
                                         container’s cgroup on the host
                                         machine.




--cpuset-cpus 	Limit the specific CPUs or cores a container can use. A comma-separated list or hyphen-separated range of CPUs a container can use, if you have more than one CPU. The first CPU is numbered 0. A valid value might be 0-3 (to use the first, second, third, and fourth CPU) or 1,3 (to use the second and fourth CPU).

--cpus=<value> 	Specify how much of the available CPU resources a container can use. For instance, if the host machine has two CPUs and you set --cpus="1.5", the container is guaranteed at most one and a half of the CPUs.



If you have 1 CPU, each of the following commands guarantees the container at most 50% of the CPU every second.

 docker run -it --cpus=".5" ubuntu /bin/bash


Verify that CONFIG_RT_GROUP_SCHED is enabled in the Linux kernel by running zcat /proc/config.gz | grep CONFIG_RT_GROUP_SCHED


Configure the Docker daemon

To run containers using the realtime scheduler, run the Docker daemon with the --cpu-rt-runtime flag set to the maximum number of microseconds reserved for realtime tasks per runtime period. For instance, with the default period of 1000000 microseconds (1 second), setting --cpu-rt-runtime=950000 ensures that containers using the realtime scheduler can run for 950000 microseconds for every 1000000-microsecond period, leaving at least 50000 microseconds available for non-realtime tasks. To make this configuration permanent on systems which use systemd, see Control and configure Docker with systemd.

$ zcat /proc/config.gz | grep CFS
# CONFIG_CFS_BANDWIDTH is not set

# Access an NVIDIA GPU

Install nvidia-container-runtime

Follow the instructions at (https://nvidia.github.io/nvidia-container-runtime/) and then run this command:

 apt-get install nvidia-container-runtime

 Ensure the nvidia-container-runtime-hook is accessible from $PATH.

  which nvidia-container-runtime-hook

  Restart the Docker daemon.
  Expose GPUs for use

  Include the --gpus flag when you start a container to access GPU resources. Specify how many GPUs to use. For example:

   docker run -it --rm --gpus all ubuntu nvidia-smi



Use the device option to specify GPUs. For example:

 docker run -it --rm --gpus device=GPU-3a23c669-1f69-c64e-cf85-44e9b07e7a2a ubuntu nvidia-smi

 Exposes that specific GPU.

  docker run -it --rm --gpus '"device=0,2"' ubuntu nvidia-smi




     Set NVIDIA capabilities

     You can set capabilities manually. For example, on Ubuntu you can run the following:

      docker run --gpus 'all,capabilities=utility' --rm ubuntu nvidia-smi

      This enables the utility driver capability which adds the nvidia-smi tool to the container.

# Deploy services to a swarm

Estimated reading time: 40 minutes

Swarm services use a declarative model, which means that you define the desired state of the service, and rely upon Docker to maintain this state. The state includes information such as (but not limited to):

    the image name and tag the service containers should run
    how many containers participate in the service
    whether any ports are exposed to clients outside the swarm
    whether the service should start automatically when Docker starts
    the specific behavior that happens when the service is restarted (such as whether a rolling restart is used)
    characteristics of the nodes where the service can run (such as resource constraints and placement preferences)

## Swarm

The cluster management and orchestration features embedded in the Docker
Engine are built using swarmkit. Swarmkit is a separate project which
implements Docker’s orchestration layer and is used directly within Docker.

A swarm consists of multiple Docker hosts which run in swarm mode and act as
managers (to manage membership and delegation) and workers (which run swarm
services). A given Docker host can be a manager, a worker, or perform both
roles. When you create a service, you define its optimal state (number of
replicas, network and storage resources available to it, ports the service
exposes to the outside world, and more). Docker works to maintain that desired
state. For instance, if a worker node becomes unavailable, Docker schedules
that node’s tasks on other nodes. A task is a running container which is part
of a swarm service and managed by a swarm manager, as opposed to a standalone
container.

One of the key advantages of swarm services over standalone containers is that
you can modify a service’s configuration, including the networks and volumes
it is connected to, without the need to manually restart the service. Docker
will update the configuration, stop the service tasks with the out of date
configuration, and create new ones matching the desired configuration.

When Docker is running in swarm mode, you can still run standalone containers
on any of the Docker hosts participating in the swarm, as well as swarm
services. A key difference between standalone containers and swarm services is
that only swarm managers can manage a swarm, while standalone containers can
be started on any daemon. Docker daemons can participate in a swarm as
managers, workers, or both.

In the same way that you can use Docker Compose to define and run containers,
you can define and run Swarm service stacks.


```
$ docker run -it --memory="1g" ubuntu
```

```
WARNING: No swap limit support
WARNING: No kernel memory limit support
WARNING: No kernel memory TCP limit support
WARNING: No oom kill disable support
WARNING: No cpu cfs quota support
WARNING: No cpu cfs period support
WARNING: No cpu shares support
```

安装grubby 并配置一下即可解决这些警告。并顺利启动docker的内存，CPU限制功能。

dnf install grubby   (官方没写，我的fedora31 安装完成后没有grubby命令，需要安装一下)

grubby --update-kernel=ALL --args="systemd.unified_cgroup_hierarchy=0"

