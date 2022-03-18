---
title: docker
render_with_liquid: false
date: 2019-03-02
update: 2021-12-21 21:20:02 CST
---

```
# apt-get install linux-image-extra-$(uname -r) linux-image-extra-virtual

# modprobe aufs

$ more /etc/apt/sources.list.d/docker.list
deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/debian bullseye stable

# systemctl enable docker
Synchronizing state of docker.service with SysV service script with /lib/systemd/systemd-sysv-install.
Executing: /lib/systemd/systemd-sysv-install enable docker

ExecStart=/usr/bin/dockerd -H fd:// --insecure-registry 10.10.50.24:5000
```

# security

```
WARNING: Access to the remote API on a privileged Docker daemon is equivalent [65/65]
         to root access on the host. Refer to the 'Docker daemon attack surface'
         documentation for details: https://docs.docker.com/go/attack-surface/
```

```
# systemctl stop docker Copy the contents of /var/lib/docker to a temporary location.

$ cp -au /var/lib/docker /var/lib/docker.bk

Edit /etc/docker/daemon.json. If it does not yet exist, create it. Assuming that the file was empty, add the following contents.

{ "storage-driver": "overlay2" }
```

```
# systemctl start docker
```

Verify that the daemon is using the overlay/overlay2 storage driver. $ sudo docker info

After this I was able to run docker container on my "16.04.2 LTS (Xenial Xerus)" sudo docker run -dit ubuntu

Docker CE

For Docker CE, only some configurations are tested, and your operating system’s kernel may not support every storage driver. In general, the following configurations work on recent versions of the Linux distribution:



```
$ docker save build | pv | \ssh dev docker load
8.88GB 0:03:02 [49.8MB/s] [     <=>
]
Loaded image: build:debian-buster
Loaded image: build:debian-good
Loaded image: build:debian-jessie
```

```
# dockerd -D
INFO[2021-12-16T18:32:23.792059363+08:00] Starting up
failed to start daemon: pid file found, ensure docker is not running or delete /var/run/docker.pid

# systemctl stop docker.service
Warning: Stopping docker.service, but it can still be activated by:
  docker.socket

# dockerd -D
INFO[2021-12-16T18:32:49.501399896+08:00] Starting up
DEBU[2021-12-16T18:32:49.501673667+08:00] Listener created for HTTP on unix (/var/run/docker.sock)
DEBU[2021-12-16T18:32:49.501685092+08:00] Containerd not running, starting daemon managed containerd
INFO[2021-12-16T18:32:49.501986272+08:00] libcontainerd: started new containerd process  pid=38344
INFO[2021-12-16T18:32:49.502005191+08:00] parsed scheme: "unix"                         module=grpc
INFO[2021-12-16T18:32:49.502011145+08:00] scheme "unix" not registered, fallback to default scheme  module=grpc
INFO[2021-12-16T18:32:49.502025432+08:00] ccResolverWrapper: sending update to cc: {[{unix:///var/run/docker/containerd/containerd.sock  <nil> 0 <nil>}] <nil> <nil>}  module=grpc
INFO[2021-12-16T18:32:49.502036039+08:00] ClientConn switching balancer to "pick_first"  module=grpc
WARN[0000] deprecated version : `1`, please switch to version `2`
INFO[2021-12-16T18:32:49.514176011+08:00] starting containerd                           revision=1e5ef943eb76627a6d3b6de8cd1ef6537f393a71.m version=v1.5.8
INFO[2021-12-16T18:32:49.530887698+08:00] loading plugin "io.containerd.content.v1.content"...  type=io.containerd.content.v1
INFO[2021-12-16T18:32:49.530943471+08:00] loading plugin "io.containerd.snapshotter.v1.aufs"...  type=io.containerd.snapshotter.v1
INFO[2021-12-16T18:32:49.532062961+08:00] skip loading plugin "io.containerd.snapshotter.v1.aufs"...  error="aufs is not supported (modprobe aufs failed: exit status 1 \"modprobe: FATAL: Module aufs not found in directory /lib/modules/5.10.85-1-MANJARO\\n\"): skip plugin" type=io.containerd.snapshotter.v1
INFO[2021-12-16T18:32:49.532087040+08:00] loading plugin "io.containerd.snapshotter.v1.btrfs"...  type=io.containerd.snapshotter.v1
INFO[2021-12-16T18:32:49.532180391+08:00] skip loading plugin "io.containerd.snapshotter.v1.btrfs"...  error="path /var/lib/docker/containerd/daemon/io.containerd.snapshotter.v1.btrfs (ext4) must be a btrfs filesystem to be used with the btrfs snapshotter: skip plugin" type=io.containerd.snapshotter.v1
INFO[2021-12-16T18:32:49.532194311+08:00] loading plugin "io.containerd.snapshotter.v1.devmapper"...  type=io.containerd.snapshotter.v1
WARN[2021-12-16T18:32:49.532211227+08:00] failed to load plugin io.containerd.snapshotter.v1.devmapper  error="devmapper not configured"
INFO[2021-12-16T18:32:49.532220603+08:00] loading plugin "io.containerd.snapshotter.v1.native"...  type=io.containerd.snapshotter.v1
INFO[2021-12-16T18:32:49.532238690+08:00] loading plugin "io.containerd.snapshotter.v1.overlayfs"...  type=io.containerd.snapshotter.v1
INFO[2021-12-16T18:32:49.532300692+08:00] loading plugin "io.containerd.snapshotter.v1.zfs"...  type=io.containerd.snapshotter.v1
INFO[2021-12-16T18:32:49.532377626+08:00] skip loading plugin "io.containerd.snapshotter.v1.zfs"...  error="path /var/lib/docker/containerd/daemon/io.containerd.snapshotter.v1.zfs must be a zfs filesystem to be used with the zfs snapshotter: skip plugin" type=io.containerd.snapshotter.v1
INFO[2021-12-16T18:32:49.532391237+08:00] loading plugin "io.containerd.metadata.v1.bolt"...  type=io.containerd.metadata.v1
WARN[2021-12-16T18:32:49.532402963+08:00] could not use snapshotter devmapper in metadata plugin  error="devmapper not configured"
INFO[2021-12-16T18:32:49.532410963+08:00] metadata content store policy set             policy=shared
INFO[2021-12-16T18:32:49.532459134+08:00] loading plugin "io.containerd.differ.v1.walking"...  type=io.containerd.differ.v1
INFO[2021-12-16T18:32:49.532474790+08:00] loading plugin "io.containerd.gc.v1.scheduler"...  type=io.containerd.gc.v1
INFO[2021-12-16T18:32:49.532499130+08:00] loading plugin "io.containerd.service.v1.introspection-service"...  type=io.containerd.service.v1
INFO[2021-12-16T18:32:49.532520580+08:00] loading plugin "io.containerd.service.v1.containers-service"...  type=io.containerd.service.v1
INFO[2021-12-16T18:32:49.532531216+08:00] loading plugin "io.containerd.service.v1.content-service"...  type=io.containerd.service.v1
INFO[2021-12-16T18:32:49.532544619+08:00] loading plugin "io.containerd.service.v1.diff-service"...  type=io.containerd.service.v1
INFO[2021-12-16T18:32:49.532559465+08:00] loading plugin "io.containerd.service.v1.images-service"...  type=io.containerd.service.v1
INFO[2021-12-16T18:32:49.532571035+08:00] loading plugin "io.containerd.service.v1.leases-service"...  type=io.containerd.service.v1
INFO[2021-12-16T18:32:49.532582566+08:00] loading plugin "io.containerd.service.v1.namespaces-service"...  type=io.containerd.service.v1
INFO[2021-12-16T18:32:49.532592973+08:00] loading plugin "io.containerd.service.v1.snapshots-service"...  type=io.containerd.service.v1
INFO[2021-12-16T18:32:49.532602869+08:00] loading plugin "io.containerd.runtime.v1.linux"...  type=io.containerd.runtime.v1
INFO[2021-12-16T18:32:49.532647682+08:00] loading plugin "io.containerd.runtime.v2.task"...  type=io.containerd.runtime.v2
INFO[2021-12-16T18:32:49.532682275+08:00] loading plugin "io.containerd.monitor.v1.cgroups"...  type=io.containerd.monitor.v1
INFO[2021-12-16T18:32:49.532826911+08:00] loading plugin "io.containerd.service.v1.tasks-service"...  type=io.containerd.service.v1
INFO[2021-12-16T18:32:49.532844022+08:00] loading plugin "io.containerd.internal.v1.restart"...  type=io.containerd.internal.v1
INFO[2021-12-16T18:32:49.532875179+08:00] loading plugin "io.containerd.grpc.v1.containers"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.532890566+08:00] loading plugin "io.containerd.grpc.v1.content"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.532901103+08:00] loading plugin "io.containerd.grpc.v1.diff"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.532911819+08:00] loading plugin "io.containerd.grpc.v1.events"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.532921492+08:00] loading plugin "io.containerd.grpc.v1.healthcheck"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.532933441+08:00] loading plugin "io.containerd.grpc.v1.images"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.532946358+08:00] loading plugin "io.containerd.grpc.v1.leases"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.532956540+08:00] loading plugin "io.containerd.grpc.v1.namespaces"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.532967473+08:00] loading plugin "io.containerd.internal.v1.opt"...  type=io.containerd.internal.v1
INFO[2021-12-16T18:32:49.532990775+08:00] loading plugin "io.containerd.grpc.v1.snapshots"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.533002606+08:00] loading plugin "io.containerd.grpc.v1.tasks"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.533013257+08:00] loading plugin "io.containerd.grpc.v1.version"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.533022728+08:00] loading plugin "io.containerd.grpc.v1.introspection"...  type=io.containerd.grpc.v1
INFO[2021-12-16T18:32:49.533123792+08:00] serving...                                    address=/var/run/docker/containerd/containerd-debug.sock
INFO[2021-12-16T18:32:49.533165233+08:00] serving...                                    address=/var/run/docker/containerd/containerd.sock.ttrpc
INFO[2021-12-16T18:32:49.533191282+08:00] serving...                                    address=/var/run/docker/containerd/containerd.sock
DEBU[2021-12-16T18:32:49.533202248+08:00] sd notification                               error="<nil>" notified=false state="READY=1"
INFO[2021-12-16T18:32:49.533211707+08:00] containerd successfully booted in 0.019906s
DEBU[2021-12-16T18:32:49.543024853+08:00] Created containerd monitoring client          address=/var/run/docker/containerd/containerd.sock
DEBU[2021-12-16T18:32:49.543688350+08:00] Started daemon managed containerd
DEBU[2021-12-16T18:32:49.544107965+08:00] Golang's threads limit set to 112950
INFO[2021-12-16T18:32:49.544286136+08:00] parsed scheme: "unix"                         module=grpc
INFO[2021-12-16T18:32:49.544298699+08:00] scheme "unix" not registered, fallback to default scheme  module=grpc
DEBU[2021-12-16T18:32:49.544306045+08:00] metrics API listening on /var/run/docker/metrics.sock
INFO[2021-12-16T18:32:49.544316918+08:00] ccResolverWrapper: sending update to cc: {[{unix:///var/run/docker/containerd/containerd.sock  <nil> 0 <nil>}] <nil> <nil>}  module=grpc
INFO[2021-12-16T18:32:49.544382046+08:00] ClientConn switching balancer to "pick_first"  module=grpc
INFO[2021-12-16T18:32:49.544963957+08:00] parsed scheme: "unix"                         module=grpc
INFO[2021-12-16T18:32:49.544981715+08:00] scheme "unix" not registered, fallback to default scheme  module=grpc
INFO[2021-12-16T18:32:49.544999711+08:00] ccResolverWrapper: sending update to cc: {[{unix:///var/run/docker/containerd/containerd.sock  <nil> 0 <nil>}] <nil> <nil>}  module=grpc
INFO[2021-12-16T18:32:49.545008992+08:00] ClientConn switching balancer to "pick_first"  module=grpc
DEBU[2021-12-16T18:32:49.545407228+08:00] Using default logging driver json-file
DEBU[2021-12-16T18:32:49.545493240+08:00] processing event stream                       module=libcontainerd namespace=plugins.moby
DEBU[2021-12-16T18:32:49.545553130+08:00] [graphdriver] priority list: [btrfs zfs overlay2 fuse-overlayfs aufs overlay devicemapper vfs]
DEBU[2021-12-16T18:32:51.410349009+08:00] garbage collected                             d=1.776714983s
DEBU[2021-12-16T18:32:51.433800976+08:00] backingFs=extfs, projectQuotaSupported=false, indexOff="index=off,", userxattr=""  storage-driver=overlay2
INFO[2021-12-16T18:32:51.433817584+08:00] [graphdriver] using prior storage driver: overlay2
DEBU[2021-12-16T18:32:51.433829219+08:00] Initialized graph driver overlay2
DEBU[2021-12-16T18:32:51.436993271+08:00] No quota support for local volumes in /var/lib/docker/volumes: Filesystem does not support, or has not enabled quotas
DEBU[2021-12-16T18:32:51.454702660+08:00] Max Concurrent Downloads: 3
DEBU[2021-12-16T18:32:51.454716533+08:00] Max Concurrent Uploads: 5
DEBU[2021-12-16T18:32:51.454720869+08:00] Max Download Attempts: 5
INFO[2021-12-16T18:32:51.454729514+08:00] Loading containers: start.
DEBU[2021-12-16T18:32:51.455031225+08:00] processing event stream                       module=libcontainerd namespace=moby
DEBU[2021-12-16T18:32:51.455477995+08:00] loaded container                              container=18460144d5b4a23bb0dff86250af5b6aaa1718e3e979c50599604222b28a1fdd paused=false running=false
DEBU[2021-12-16T18:32:51.455478272+08:00] loaded container                              container=8358d04a2a27a091359ef2248a15cfe311521f7f30ee9e0982eaf78a36e81697 paused=false running=false
DEBU[2021-12-16T18:32:51.455500689+08:00] loaded container                              container=874cb089abff4aa6778e761747b3fa004909a2884038577a5251096366fc821b paused=false running=false
DEBU[2021-12-16T18:32:51.455515773+08:00] loaded container                              container=8486f016f633f957fe331110bdd5a847ca3cfd0ff57c648de3d3ea9c0b1fe2cd paused=false running=false
DEBU[2021-12-16T18:32:51.455535522+08:00] loaded container                              container=53faf7896e38dc623e91fc9aa62b0363282b917b4b901a9f567a4f601b2f4b01 paused=false running=false
DEBU[2021-12-16T18:32:51.455527470+08:00] loaded container                              container=5dda8c3d7a2889610cf609232f0caab691d9e6e6d127c8e44ea3d909421ba89b paused=false running=false
DEBU[2021-12-16T18:32:51.455541386+08:00] loaded container                              container=76fe1d2b435657edbee23a3038aa5409147308154f6c2e1eab05ebb765d7757e paused=false running=false
DEBU[2021-12-16T18:32:51.455558376+08:00] loaded container                              container=5f74931d2861125305a3ff050ec93d2b69f9b81385687fd6408ddb5e243c3460 paused=false running=false
DEBU[2021-12-16T18:32:51.455585257+08:00] loaded container                              container=5d0ffb6b5c283b3460166b80f55ce02a6712b2c0a4c6c2666cf83bc417af6145 paused=false running=false
DEBU[2021-12-16T18:32:51.455611856+08:00] loaded container                              container=6c312c1ff29949838bbee3f7e4a7542aeaa2e65acc20adf9603e376b3779833d paused=false running=false
DEBU[2021-12-16T18:32:51.527473653+08:00] restoring container                           container=53faf7896e38dc623e91fc9aa62b0363282b917b4b901a9f567a4f601b2f4b01 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527494827+08:00] restoring container                           container=76fe1d2b435657edbee23a3038aa5409147308154f6c2e1eab05ebb765d7757e paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527513445+08:00] restoring container                           container=6c312c1ff29949838bbee3f7e4a7542aeaa2e65acc20adf9603e376b3779833d paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527504942+08:00] restoring container                           container=874cb089abff4aa6778e761747b3fa004909a2884038577a5251096366fc821b paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527546936+08:00] restoring container                           container=8358d04a2a27a091359ef2248a15cfe311521f7f30ee9e0982eaf78a36e81697 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527583267+08:00] restoring container                           container=8486f016f633f957fe331110bdd5a847ca3cfd0ff57c648de3d3ea9c0b1fe2cd paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527842707+08:00] alive: false                                  container=6c312c1ff29949838bbee3f7e4a7542aeaa2e65acc20adf9603e376b3779833d paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527858990+08:00] alive: false                                  container=8486f016f633f957fe331110bdd5a847ca3cfd0ff57c648de3d3ea9c0b1fe2cd paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527880897+08:00] done restoring container                      container=8486f016f633f957fe331110bdd5a847ca3cfd0ff57c648de3d3ea9c0b1fe2cd paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527885301+08:00] alive: false                                  container=874cb089abff4aa6778e761747b3fa004909a2884038577a5251096366fc821b paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527898581+08:00] done restoring container                      container=874cb089abff4aa6778e761747b3fa004909a2884038577a5251096366fc821b paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527863789+08:00] alive: false                                  container=53faf7896e38dc623e91fc9aa62b0363282b917b4b901a9f567a4f601b2f4b01 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527911407+08:00] done restoring container                      container=53faf7896e38dc623e91fc9aa62b0363282b917b4b901a9f567a4f601b2f4b01 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527867098+08:00] done restoring container                      container=6c312c1ff29949838bbee3f7e4a7542aeaa2e65acc20adf9603e376b3779833d paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527849664+08:00] alive: false                                  container=76fe1d2b435657edbee23a3038aa5409147308154f6c2e1eab05ebb765d7757e paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527928284+08:00] done restoring container                      container=76fe1d2b435657edbee23a3038aa5409147308154f6c2e1eab05ebb765d7757e paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527872427+08:00] alive: false                                  container=8358d04a2a27a091359ef2248a15cfe311521f7f30ee9e0982eaf78a36e81697 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.527939561+08:00] done restoring container                      container=8358d04a2a27a091359ef2248a15cfe311521f7f30ee9e0982eaf78a36e81697 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.535549123+08:00] restoring container                           container=5d0ffb6b5c283b3460166b80f55ce02a6712b2c0a4c6c2666cf83bc417af6145 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.535571040+08:00] restoring container                           container=5dda8c3d7a2889610cf609232f0caab691d9e6e6d127c8e44ea3d909421ba89b paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.535577931+08:00] restoring container                           container=18460144d5b4a23bb0dff86250af5b6aaa1718e3e979c50599604222b28a1fdd paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.535582744+08:00] restoring container                           container=5f74931d2861125305a3ff050ec93d2b69f9b81385687fd6408ddb5e243c3460 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.535924215+08:00] alive: false                                  container=5f74931d2861125305a3ff050ec93d2b69f9b81385687fd6408ddb5e243c3460 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.535950177+08:00] done restoring container                      container=5f74931d2861125305a3ff050ec93d2b69f9b81385687fd6408ddb5e243c3460 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.535952811+08:00] alive: false                                  container=18460144d5b4a23bb0dff86250af5b6aaa1718e3e979c50599604222b28a1fdd paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.535978089+08:00] done restoring container                      container=18460144d5b4a23bb0dff86250af5b6aaa1718e3e979c50599604222b28a1fdd paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.535944329+08:00] alive: false                                  container=5dda8c3d7a2889610cf609232f0caab691d9e6e6d127c8e44ea3d909421ba89b paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.536007562+08:00] done restoring container                      container=5dda8c3d7a2889610cf609232f0caab691d9e6e6d127c8e44ea3d909421ba89b paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.535931634+08:00] alive: false                                  container=5d0ffb6b5c283b3460166b80f55ce02a6712b2c0a4c6c2666cf83bc417af6145 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.536030605+08:00] done restoring container                      container=5d0ffb6b5c283b3460166b80f55ce02a6712b2c0a4c6c2666cf83bc417af6145 paused=false restarting=false running=false
DEBU[2021-12-16T18:32:51.536057941+08:00] Option Experimental: false
DEBU[2021-12-16T18:32:51.536067734+08:00] Option DefaultDriver: bridge
DEBU[2021-12-16T18:32:51.536073386+08:00] Option DefaultNetwork: bridge
DEBU[2021-12-16T18:32:51.536079444+08:00] Network Control Plane MTU: 1500
DEBU[2021-12-16T18:32:51.538741443+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -j DOCKER-ISOLATION]
DEBU[2021-12-16T18:32:51.539232271+08:00] /usr/bin/iptables, [--wait -t nat -D PREROUTING -m addrtype --dst-type LOCAL -j DOCKER]
DEBU[2021-12-16T18:32:51.540009664+08:00] /usr/bin/iptables, [--wait -t nat -D OUTPUT -m addrtype --dst-type LOCAL ! --dst 127.0.0.0/8 -j DOCKER]
DEBU[2021-12-16T18:32:51.540602574+08:00] /usr/bin/iptables, [--wait -t nat -D OUTPUT -m addrtype --dst-type LOCAL -j DOCKER]
DEBU[2021-12-16T18:32:51.541147187+08:00] /usr/bin/iptables, [--wait -t nat -D PREROUTING]
DEBU[2021-12-16T18:32:51.541594192+08:00] /usr/bin/iptables, [--wait -t nat -D OUTPUT]
DEBU[2021-12-16T18:32:51.542030174+08:00] /usr/bin/iptables, [--wait -t nat -F DOCKER]
DEBU[2021-12-16T18:32:51.542438916+08:00] /usr/bin/iptables, [--wait -t nat -X DOCKER]
DEBU[2021-12-16T18:32:51.542855965+08:00] /usr/bin/iptables, [--wait -t filter -F DOCKER]
DEBU[2021-12-16T18:32:51.543284829+08:00] /usr/bin/iptables, [--wait -t filter -X DOCKER]
DEBU[2021-12-16T18:32:51.543701811+08:00] /usr/bin/iptables, [--wait -t filter -F DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.544124743+08:00] /usr/bin/iptables, [--wait -t filter -X DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.544565509+08:00] /usr/bin/iptables, [--wait -t filter -F DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.544994652+08:00] /usr/bin/iptables, [--wait -t filter -X DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.545407673+08:00] /usr/bin/iptables, [--wait -t filter -F DOCKER-ISOLATION]
DEBU[2021-12-16T18:32:51.545841765+08:00] /usr/bin/iptables, [--wait -t filter -X DOCKER-ISOLATION]
DEBU[2021-12-16T18:32:51.546317247+08:00] /usr/bin/iptables, [--wait -t nat -n -L DOCKER]
DEBU[2021-12-16T18:32:51.546915881+08:00] /usr/bin/iptables, [--wait -t nat -N DOCKER]
DEBU[2021-12-16T18:32:51.547790875+08:00] /usr/bin/iptables, [--wait -t filter -n -L DOCKER]
DEBU[2021-12-16T18:32:51.548458318+08:00] /usr/bin/iptables, [--wait -t filter -n -L DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.548957274+08:00] /usr/bin/iptables, [--wait -t filter -n -L DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.549472043+08:00] /usr/bin/iptables, [--wait -t filter -N DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.550076605+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-1 -j RETURN]
DEBU[2021-12-16T18:32:51.550603472+08:00] /usr/bin/iptables, [--wait -A DOCKER-ISOLATION-STAGE-1 -j RETURN]
DEBU[2021-12-16T18:32:51.551141944+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-2 -j RETURN]
DEBU[2021-12-16T18:32:51.551643107+08:00] /usr/bin/iptables, [--wait -A DOCKER-ISOLATION-STAGE-2 -j RETURN]
DEBU[2021-12-16T18:32:51.554116174+08:00] /usr/bin/iptables, [--wait -t nat -C POSTROUTING -s 172.18.0.0/16 ! -o br-d3426515317e -j MASQUERADE]
DEBU[2021-12-16T18:32:51.554809875+08:00] /usr/bin/iptables, [--wait -t nat -C DOCKER -i br-d3426515317e -j RETURN]
DEBU[2021-12-16T18:32:51.555294395+08:00] /usr/bin/iptables, [--wait -t nat -I DOCKER -i br-d3426515317e -j RETURN]
DEBU[2021-12-16T18:32:51.555754754+08:00] /usr/bin/iptables, [--wait -D FORWARD -i br-d3426515317e -o br-d3426515317e -j DROP]
DEBU[2021-12-16T18:32:51.556216344+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -i br-d3426515317e -o br-d3426515317e -j ACCEPT]
DEBU[2021-12-16T18:32:51.556660259+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -i br-d3426515317e ! -o br-d3426515317e -j ACCEPT]
DEBU[2021-12-16T18:32:51.557161356+08:00] /usr/bin/iptables, [--wait -t nat -C PREROUTING -m addrtype --dst-type LOCAL -j DOCKER]
DEBU[2021-12-16T18:32:51.557682115+08:00] /usr/bin/iptables, [--wait -t nat -A PREROUTING -m addrtype --dst-type LOCAL -j DOCKER]
DEBU[2021-12-16T18:32:51.558257761+08:00] /usr/bin/iptables, [--wait -t nat -C OUTPUT -m addrtype --dst-type LOCAL -j DOCKER ! --dst 127.0.0.0/8]
DEBU[2021-12-16T18:32:51.558819335+08:00] /usr/bin/iptables, [--wait -t nat -A OUTPUT -m addrtype --dst-type LOCAL -j DOCKER ! --dst 127.0.0.0/8]
DEBU[2021-12-16T18:32:51.559390801+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o br-d3426515317e -j DOCKER]
DEBU[2021-12-16T18:32:51.559897428+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o br-d3426515317e -j DOCKER]
DEBU[2021-12-16T18:32:51.560356152+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o br-d3426515317e -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.560857477+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o br-d3426515317e -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.561461423+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.562129403+08:00] /usr/bin/iptables, [--wait -D FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.562876298+08:00] /usr/bin/iptables, [--wait -I FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.563570716+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-1 -i br-d3426515317e ! -o br-d3426515317e -j DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.564152735+08:00] /usr/bin/iptables, [--wait -t filter -I DOCKER-ISOLATION-STAGE-1 -i br-d3426515317e ! -o br-d3426515317e -j DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.564682206+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-2 -o br-d3426515317e -j DROP]
DEBU[2021-12-16T18:32:51.565172441+08:00] /usr/bin/iptables, [--wait -t filter -I DOCKER-ISOLATION-STAGE-2 -o br-d3426515317e -j DROP]
DEBU[2021-12-16T18:32:51.565713337+08:00] Network (d342651) restored
DEBU[2021-12-16T18:32:51.565844549+08:00] /usr/bin/iptables, [--wait -t nat -C POSTROUTING -s 172.17.0.0/16 ! -o docker0 -j MASQUERADE]
DEBU[2021-12-16T18:32:51.566387569+08:00] /usr/bin/iptables, [--wait -t nat -C DOCKER -i docker0 -j RETURN]
DEBU[2021-12-16T18:32:51.566908178+08:00] /usr/bin/iptables, [--wait -t nat -I DOCKER -i docker0 -j RETURN]
DEBU[2021-12-16T18:32:51.567444107+08:00] /usr/bin/iptables, [--wait -D FORWARD -i docker0 -o docker0 -j DROP]
DEBU[2021-12-16T18:32:51.567891749+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -i docker0 -o docker0 -j ACCEPT]
DEBU[2021-12-16T18:32:51.568393979+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -i docker0 ! -o docker0 -j ACCEPT]
DEBU[2021-12-16T18:32:51.568851831+08:00] /usr/bin/iptables, [--wait -t nat -C PREROUTING -m addrtype --dst-type LOCAL -j DOCKER]
DEBU[2021-12-16T18:32:51.569402492+08:00] /usr/bin/iptables, [--wait -t nat -C PREROUTING -m addrtype --dst-type LOCAL -j DOCKER]
DEBU[2021-12-16T18:32:51.569936780+08:00] /usr/bin/iptables, [--wait -t nat -C OUTPUT -m addrtype --dst-type LOCAL -j DOCKER ! --dst 127.0.0.0/8]
DEBU[2021-12-16T18:32:51.570448437+08:00] /usr/bin/iptables, [--wait -t nat -C OUTPUT -m addrtype --dst-type LOCAL -j DOCKER ! --dst 127.0.0.0/8]
DEBU[2021-12-16T18:32:51.570950466+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o docker0 -j DOCKER]
DEBU[2021-12-16T18:32:51.571406928+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o docker0 -j DOCKER]
DEBU[2021-12-16T18:32:51.571871491+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o docker0 -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.572388750+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o docker0 -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.572913109+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.573387223+08:00] /usr/bin/iptables, [--wait -D FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.573868133+08:00] /usr/bin/iptables, [--wait -I FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.574403269+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-1 -i docker0 ! -o docker0 -j DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.574927338+08:00] /usr/bin/iptables, [--wait -t filter -I DOCKER-ISOLATION-STAGE-1 -i docker0 ! -o docker0 -j DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.575448325+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-2 -o docker0 -j DROP]
DEBU[2021-12-16T18:32:51.575903580+08:00] /usr/bin/iptables, [--wait -t filter -I DOCKER-ISOLATION-STAGE-2 -o docker0 -j DROP]
DEBU[2021-12-16T18:32:51.576527190+08:00] Network (84129c0) restored
DEBU[2021-12-16T18:32:51.576664007+08:00] /usr/bin/iptables, [--wait -t nat -C POSTROUTING -s 192.168.58.0/24 ! -o br-a80da0ac7f38 -j MASQUERADE]
DEBU[2021-12-16T18:32:51.577179330+08:00] /usr/bin/iptables, [--wait -t nat -C DOCKER -i br-a80da0ac7f38 -j RETURN]
DEBU[2021-12-16T18:32:51.577956367+08:00] /usr/bin/iptables, [--wait -t nat -I DOCKER -i br-a80da0ac7f38 -j RETURN]
DEBU[2021-12-16T18:32:51.578642277+08:00] /usr/bin/iptables, [--wait -D FORWARD -i br-a80da0ac7f38 -o br-a80da0ac7f38 -j DROP]
DEBU[2021-12-16T18:32:51.579203968+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -i br-a80da0ac7f38 -o br-a80da0ac7f38 -j ACCEPT]
DEBU[2021-12-16T18:32:51.579691160+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -i br-a80da0ac7f38 ! -o br-a80da0ac7f38 -j ACCEPT]
DEBU[2021-12-16T18:32:51.580209537+08:00] /usr/bin/iptables, [--wait -t nat -C PREROUTING -m addrtype --dst-type LOCAL -j DOCKER]
DEBU[2021-12-16T18:32:51.580724962+08:00] /usr/bin/iptables, [--wait -t nat -C PREROUTING -m addrtype --dst-type LOCAL -j DOCKER]
DEBU[2021-12-16T18:32:51.581252129+08:00] /usr/bin/iptables, [--wait -t nat -C OUTPUT -m addrtype --dst-type LOCAL -j DOCKER ! --dst 127.0.0.0/8]
DEBU[2021-12-16T18:32:51.581799618+08:00] /usr/bin/iptables, [--wait -t nat -C OUTPUT -m addrtype --dst-type LOCAL -j DOCKER ! --dst 127.0.0.0/8]
DEBU[2021-12-16T18:32:51.582286610+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o br-a80da0ac7f38 -j DOCKER]
DEBU[2021-12-16T18:32:51.582811664+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o br-a80da0ac7f38 -j DOCKER]
DEBU[2021-12-16T18:32:51.583259666+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o br-a80da0ac7f38 -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.583756582+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o br-a80da0ac7f38 -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.584325039+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.584823326+08:00] /usr/bin/iptables, [--wait -D FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.585367700+08:00] /usr/bin/iptables, [--wait -I FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.585872630+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-1 -i br-a80da0ac7f38 ! -o br-a80da0ac7f38 -j DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.586362357+08:00] /usr/bin/iptables, [--wait -t filter -I DOCKER-ISOLATION-STAGE-1 -i br-a80da0ac7f38 ! -o br-a80da0ac7f38 -j DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.586961915+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-2 -o br-a80da0ac7f38 -j DROP]
DEBU[2021-12-16T18:32:51.587451187+08:00] /usr/bin/iptables, [--wait -t filter -I DOCKER-ISOLATION-STAGE-2 -o br-a80da0ac7f38 -j DROP]
DEBU[2021-12-16T18:32:51.587964552+08:00] Network (a80da0a) restored
DEBU[2021-12-16T18:32:51.588540525+08:00] Allocating IPv4 pools for network minikube (a80da0ac7f389eaaf693da3b90c06725489664d68b5aa9a78ea7c26f2a08b605)
DEBU[2021-12-16T18:32:51.588551763+08:00] RequestPool(LocalDefault, 192.168.58.0/24, , map[], false)
DEBU[2021-12-16T18:32:51.588569731+08:00] RequestAddress(LocalDefault/192.168.58.0/24, 192.168.58.1, map[RequestAddressType:com.docker.network.gateway])
DEBU[2021-12-16T18:32:51.588584062+08:00] Request address PoolID:192.168.58.0/24 App: ipam/default/data, ID: LocalDefault/192.168.58.0/24, DBIndex: 0x0, Bits: 256, Unselected: 254, Sequence: (0x80000000, 1)->(0x0, 6)->(0x1, 1)->end Curr:0 Serial:false PrefAddress:192.168.58.1
DEBU[2021-12-16T18:32:51.588615978+08:00] Allocating IPv4 pools for network homeland-docker_default (d3426515317ef470ffa717754e05f15cd4f9af74f96190439206629b6eafb05d)
DEBU[2021-12-16T18:32:51.588623681+08:00] RequestPool(LocalDefault, 172.18.0.0/16, , map[], false)
DEBU[2021-12-16T18:32:51.588634833+08:00] RequestAddress(LocalDefault/172.18.0.0/16, 172.18.0.1, map[RequestAddressType:com.docker.network.gateway])
DEBU[2021-12-16T18:32:51.588643405+08:00] Request address PoolID:172.18.0.0/16 App: ipam/default/data, ID: LocalDefault/172.18.0.0/16, DBIndex: 0x0, Bits: 65536, Unselected: 65534, Sequence: (0x80000000, 1)->(0x0, 2046)->(0x1, 1)->end Curr:0 Serial:false PrefAddress:172.18.0.1
DEBU[2021-12-16T18:32:51.588688830+08:00] Allocating IPv4 pools for network bridge (84129c0068266bf82d6351ee63564312f7988a0e84f749551fbf693a7a6033a5)
DEBU[2021-12-16T18:32:51.588696400+08:00] RequestPool(LocalDefault, 172.17.0.0/16, , map[], false)
DEBU[2021-12-16T18:32:51.588707310+08:00] RequestAddress(LocalDefault/172.17.0.0/16, 172.17.0.1, map[RequestAddressType:com.docker.network.gateway])
DEBU[2021-12-16T18:32:51.588717352+08:00] Request address PoolID:172.17.0.0/16 App: ipam/default/data, ID: LocalDefault/172.17.0.0/16, DBIndex: 0x0, Bits: 65536, Unselected: 65534, Sequence: (0x80000000, 1)->(0x0, 2046)->(0x1, 1)->end Curr:0 Serial:false PrefAddress:172.17.0.1
DEBU[2021-12-16T18:32:51.597421758+08:00] /usr/bin/iptables, [--wait -t nat -C POSTROUTING -s 172.17.0.0/16 ! -o docker0 -j MASQUERADE]
DEBU[2021-12-16T18:32:51.598174625+08:00] /usr/bin/iptables, [--wait -t nat -D POSTROUTING -s 172.17.0.0/16 ! -o docker0 -j MASQUERADE]
DEBU[2021-12-16T18:32:51.598775519+08:00] /usr/bin/iptables, [--wait -t nat -C DOCKER -i docker0 -j RETURN]
DEBU[2021-12-16T18:32:51.599444673+08:00] /usr/bin/iptables, [--wait -t nat -D DOCKER -i docker0 -j RETURN]
DEBU[2021-12-16T18:32:51.599902676+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -i docker0 -o docker0 -j ACCEPT]
DEBU[2021-12-16T18:32:51.600348953+08:00] /usr/bin/iptables, [--wait -D FORWARD -i docker0 -o docker0 -j ACCEPT]
DEBU[2021-12-16T18:32:51.600848292+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -i docker0 ! -o docker0 -j ACCEPT]
DEBU[2021-12-16T18:32:51.601334229+08:00] /usr/bin/iptables, [--wait -D FORWARD -i docker0 ! -o docker0 -j ACCEPT]
DEBU[2021-12-16T18:32:51.601864041+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o docker0 -j DOCKER]
DEBU[2021-12-16T18:32:51.602414327+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o docker0 -j DOCKER]
DEBU[2021-12-16T18:32:51.602946678+08:00] /usr/bin/iptables, [--wait -D FORWARD -o docker0 -j DOCKER]
DEBU[2021-12-16T18:32:51.603445192+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o docker0 -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.603963128+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o docker0 -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.604499936+08:00] /usr/bin/iptables, [--wait -D FORWARD -o docker0 -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.605038962+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-1 -i docker0 ! -o docker0 -j DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.605507707+08:00] /usr/bin/iptables, [--wait -t filter -D DOCKER-ISOLATION-STAGE-1 -i docker0 ! -o docker0 -j DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.605982325+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-2 -o docker0 -j DROP]
DEBU[2021-12-16T18:32:51.606447063+08:00] /usr/bin/iptables, [--wait -t filter -D DOCKER-ISOLATION-STAGE-2 -o docker0 -j DROP]
DEBU[2021-12-16T18:32:51.616106651+08:00] releasing IPv4 pools from network bridge (84129c0068266bf82d6351ee63564312f7988a0e84f749551fbf693a7a6033a5)
DEBU[2021-12-16T18:32:51.616129805+08:00] ReleaseAddress(LocalDefault/172.17.0.0/16, 172.17.0.1)
DEBU[2021-12-16T18:32:51.616167637+08:00] Released address PoolID:LocalDefault/172.17.0.0/16, Address:172.17.0.1 Sequence:App: ipam/default/data, ID: LocalDefault/172.17.0.0/16, DBIndex: 0x0, Bits: 65536, Unselected: 65533, Sequence: (0xc0000000, 1)->(0x0, 2046)->(0x1, 1)->end Curr:0
DEBU[2021-12-16T18:32:51.616176545+08:00] ReleasePool(LocalDefault/172.17.0.0/16)
DEBU[2021-12-16T18:32:51.624946978+08:00] cleanupServiceDiscovery for network:84129c0068266bf82d6351ee63564312f7988a0e84f749551fbf693a7a6033a5
DEBU[2021-12-16T18:32:51.624965428+08:00] cleanupServiceBindings for 84129c0068266bf82d6351ee63564312f7988a0e84f749551fbf693a7a6033a5
INFO[2021-12-16T18:32:51.642748766+08:00] Default bridge (docker0) is assigned with an IP address 172.17.0.0/16. Daemon option --bip can be used to set a preferred IP address
DEBU[2021-12-16T18:32:51.642780099+08:00] Allocating IPv4 pools for network bridge (1e8e6f6c2ca91b73d2a3c69585e2d462027ea968c8c01890817e923ebfa9377b)
DEBU[2021-12-16T18:32:51.642792523+08:00] RequestPool(LocalDefault, 172.17.0.0/16, , map[], false)
DEBU[2021-12-16T18:32:51.642820735+08:00] RequestAddress(LocalDefault/172.17.0.0/16, 172.17.0.1, map[RequestAddressType:com.docker.network.gateway])
DEBU[2021-12-16T18:32:51.642836120+08:00] Request address PoolID:172.17.0.0/16 App: ipam/default/data, ID: LocalDefault/172.17.0.0/16, DBIndex: 0x0, Bits: 65536, Unselected: 65534, Sequence: (0x80000000, 1)->(0x0, 2046)->(0x1, 1)->end Curr:0 Serial:false PrefAddress:172.17.0.1
DEBU[2021-12-16T18:32:51.643033976+08:00] /usr/bin/iptables, [--wait -t nat -C POSTROUTING -s 172.17.0.0/16 ! -o docker0 -j MASQUERADE]
DEBU[2021-12-16T18:32:51.643668458+08:00] /usr/bin/iptables, [--wait -t nat -I POSTROUTING -s 172.17.0.0/16 ! -o docker0 -j MASQUERADE]
DEBU[2021-12-16T18:32:51.644264326+08:00] /usr/bin/iptables, [--wait -t nat -C DOCKER -i docker0 -j RETURN]
DEBU[2021-12-16T18:32:51.644942465+08:00] /usr/bin/iptables, [--wait -t nat -I DOCKER -i docker0 -j RETURN]
DEBU[2021-12-16T18:32:51.645564476+08:00] /usr/bin/iptables, [--wait -D FORWARD -i docker0 -o docker0 -j DROP]
DEBU[2021-12-16T18:32:51.646190093+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -i docker0 -o docker0 -j ACCEPT]
DEBU[2021-12-16T18:32:51.646701022+08:00] /usr/bin/iptables, [--wait -I FORWARD -i docker0 -o docker0 -j ACCEPT]
DEBU[2021-12-16T18:32:51.647200329+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -i docker0 ! -o docker0 -j ACCEPT]
DEBU[2021-12-16T18:32:51.647697181+08:00] /usr/bin/iptables, [--wait -I FORWARD -i docker0 ! -o docker0 -j ACCEPT]
DEBU[2021-12-16T18:32:51.648168317+08:00] /usr/bin/iptables, [--wait -t nat -C PREROUTING -m addrtype --dst-type LOCAL -j DOCKER]
DEBU[2021-12-16T18:32:51.648698856+08:00] /usr/bin/iptables, [--wait -t nat -C PREROUTING -m addrtype --dst-type LOCAL -j DOCKER]
DEBU[2021-12-16T18:32:51.649189513+08:00] /usr/bin/iptables, [--wait -t nat -C OUTPUT -m addrtype --dst-type LOCAL -j DOCKER ! --dst 127.0.0.0/8]
DEBU[2021-12-16T18:32:51.649711585+08:00] /usr/bin/iptables, [--wait -t nat -C OUTPUT -m addrtype --dst-type LOCAL -j DOCKER ! --dst 127.0.0.0/8]
DEBU[2021-12-16T18:32:51.650276226+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o docker0 -j DOCKER]
DEBU[2021-12-16T18:32:51.650926761+08:00] /usr/bin/iptables, [--wait -I FORWARD -o docker0 -j DOCKER]
DEBU[2021-12-16T18:32:51.651574287+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -o docker0 -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.652161460+08:00] /usr/bin/iptables, [--wait -I FORWARD -o docker0 -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT]
DEBU[2021-12-16T18:32:51.652779971+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.653237261+08:00] /usr/bin/iptables, [--wait -D FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.653697042+08:00] /usr/bin/iptables, [--wait -I FORWARD -j DOCKER-ISOLATION-STAGE-1]
DEBU[2021-12-16T18:32:51.654220485+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-1 -i docker0 ! -o docker0 -j DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.654782721+08:00] /usr/bin/iptables, [--wait -t filter -I DOCKER-ISOLATION-STAGE-1 -i docker0 ! -o docker0 -j DOCKER-ISOLATION-STAGE-2]
DEBU[2021-12-16T18:32:51.655324814+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-ISOLATION-STAGE-2 -o docker0 -j DROP]
DEBU[2021-12-16T18:32:51.655762533+08:00] /usr/bin/iptables, [--wait -t filter -I DOCKER-ISOLATION-STAGE-2 -o docker0 -j DROP]
DEBU[2021-12-16T18:32:51.716298005+08:00] /usr/bin/iptables, [--wait -t filter -n -L DOCKER-USER]
DEBU[2021-12-16T18:32:51.717127196+08:00] /usr/bin/iptables, [--wait -t filter -C DOCKER-USER -j RETURN]
DEBU[2021-12-16T18:32:51.717647307+08:00] /usr/bin/iptables, [--wait -t filter -C FORWARD -j DOCKER-USER]
DEBU[2021-12-16T18:32:51.718141609+08:00] /usr/bin/iptables, [--wait -D FORWARD -j DOCKER-USER]
DEBU[2021-12-16T18:32:51.718607419+08:00] /usr/bin/iptables, [--wait -I FORWARD -j DOCKER-USER]
INFO[2021-12-16T18:32:51.736928591+08:00] Loading containers: done.
WARN[2021-12-16T18:32:51.876429431+08:00] Not using native diff for overlay2, this may cause degraded performance for building images: kernel has CONFIG_OVERLAY_FS_REDIRECT_DIR enabled  storage-driver=overlay2
INFO[2021-12-16T18:32:51.876571746+08:00] Docker daemon                                 commit=459d0dfbbb graphdriver(s)=overlay2 version=20.10.12
INFO[2021-12-16T18:32:51.876605450+08:00] Daemon has completed initialization
DEBU[2021-12-16T18:32:51.895427776+08:00] Registering routers
DEBU[2021-12-16T18:32:51.895451803+08:00] Registering GET, /containers/{name:.*}/checkpoints
DEBU[2021-12-16T18:32:51.895561305+08:00] Registering POST, /containers/{name:.*}/checkpoints
DEBU[2021-12-16T18:32:51.895637406+08:00] Registering DELETE, /containers/{name}/checkpoints/{checkpoint}
DEBU[2021-12-16T18:32:51.895832108+08:00] Registering HEAD, /containers/{name:.*}/archive
DEBU[2021-12-16T18:32:51.895892150+08:00] Registering GET, /containers/json
DEBU[2021-12-16T18:32:51.895930781+08:00] Registering GET, /containers/{name:.*}/export
DEBU[2021-12-16T18:32:51.895983619+08:00] Registering GET, /containers/{name:.*}/changes
DEBU[2021-12-16T18:32:51.896071781+08:00] Registering GET, /containers/{name:.*}/json
DEBU[2021-12-16T18:32:51.896113565+08:00] Registering GET, /containers/{name:.*}/top
DEBU[2021-12-16T18:32:51.896146148+08:00] Registering GET, /containers/{name:.*}/logs
DEBU[2021-12-16T18:32:51.896182047+08:00] Registering GET, /containers/{name:.*}/stats
DEBU[2021-12-16T18:32:51.896210750+08:00] Registering GET, /containers/{name:.*}/attach/ws
DEBU[2021-12-16T18:32:51.896246703+08:00] Registering GET, /exec/{id:.*}/json
DEBU[2021-12-16T18:32:51.896273212+08:00] Registering GET, /containers/{name:.*}/archive
DEBU[2021-12-16T18:32:51.896301278+08:00] Registering POST, /containers/create
DEBU[2021-12-16T18:32:51.896320854+08:00] Registering POST, /containers/{name:.*}/kill
DEBU[2021-12-16T18:32:51.896360692+08:00] Registering POST, /containers/{name:.*}/pause
DEBU[2021-12-16T18:32:51.896405205+08:00] Registering POST, /containers/{name:.*}/unpause
DEBU[2021-12-16T18:32:51.896433272+08:00] Registering POST, /containers/{name:.*}/restart
DEBU[2021-12-16T18:32:51.896473451+08:00] Registering POST, /containers/{name:.*}/start
DEBU[2021-12-16T18:32:51.896499971+08:00] Registering POST, /containers/{name:.*}/stop
DEBU[2021-12-16T18:32:51.896525605+08:00] Registering POST, /containers/{name:.*}/wait
DEBU[2021-12-16T18:32:51.896554108+08:00] Registering POST, /containers/{name:.*}/resize
DEBU[2021-12-16T18:32:51.896595867+08:00] Registering POST, /containers/{name:.*}/attach
DEBU[2021-12-16T18:32:51.896623306+08:00] Registering POST, /containers/{name:.*}/copy
DEBU[2021-12-16T18:32:51.896653346+08:00] Registering POST, /containers/{name:.*}/exec
DEBU[2021-12-16T18:32:51.896682462+08:00] Registering POST, /exec/{name:.*}/start
DEBU[2021-12-16T18:32:51.896718072+08:00] Registering POST, /exec/{name:.*}/resize
DEBU[2021-12-16T18:32:51.896758668+08:00] Registering POST, /containers/{name:.*}/rename
DEBU[2021-12-16T18:32:51.896797223+08:00] Registering POST, /containers/{name:.*}/update
DEBU[2021-12-16T18:32:51.896830415+08:00] Registering POST, /containers/prune
DEBU[2021-12-16T18:32:51.896854597+08:00] Registering POST, /commit
DEBU[2021-12-16T18:32:51.896871264+08:00] Registering PUT, /containers/{name:.*}/archive
DEBU[2021-12-16T18:32:51.896905512+08:00] Registering DELETE, /containers/{name:.*}
DEBU[2021-12-16T18:32:51.896943331+08:00] Registering GET, /images/json
DEBU[2021-12-16T18:32:51.896962500+08:00] Registering GET, /images/search
DEBU[2021-12-16T18:32:51.896982734+08:00] Registering GET, /images/get
DEBU[2021-12-16T18:32:51.897003851+08:00] Registering GET, /images/{name:.*}/get
DEBU[2021-12-16T18:32:51.897034882+08:00] Registering GET, /images/{name:.*}/history
DEBU[2021-12-16T18:32:51.897068694+08:00] Registering GET, /images/{name:.*}/json
DEBU[2021-12-16T18:32:51.897093794+08:00] Registering POST, /images/load
DEBU[2021-12-16T18:32:51.897114029+08:00] Registering POST, /images/create
DEBU[2021-12-16T18:32:51.897136350+08:00] Registering POST, /images/{name:.*}/push
DEBU[2021-12-16T18:32:51.897166557+08:00] Registering POST, /images/{name:.*}/tag
DEBU[2021-12-16T18:32:51.897196857+08:00] Registering POST, /images/prune
DEBU[2021-12-16T18:32:51.897216856+08:00] Registering DELETE, /images/{name:.*}
DEBU[2021-12-16T18:32:51.897242091+08:00] Registering OPTIONS, /{anyroute:.*}
DEBU[2021-12-16T18:32:51.897266864+08:00] Registering GET, /_ping
DEBU[2021-12-16T18:32:51.897290195+08:00] Registering HEAD, /_ping
DEBU[2021-12-16T18:32:51.897313476+08:00] Registering GET, /events
DEBU[2021-12-16T18:32:51.897329668+08:00] Registering GET, /info
DEBU[2021-12-16T18:32:51.897344942+08:00] Registering GET, /version
DEBU[2021-12-16T18:32:51.897367296+08:00] Registering GET, /system/df
DEBU[2021-12-16T18:32:51.897441298+08:00] Registering POST, /auth
DEBU[2021-12-16T18:32:51.897466404+08:00] Registering GET, /volumes
DEBU[2021-12-16T18:32:51.897485746+08:00] Registering GET, /volumes/{name:.*}
DEBU[2021-12-16T18:32:51.897526197+08:00] Registering POST, /volumes/create
DEBU[2021-12-16T18:32:51.897552295+08:00] Registering POST, /volumes/prune
DEBU[2021-12-16T18:32:51.897576786+08:00] Registering DELETE, /volumes/{name:.*}
DEBU[2021-12-16T18:32:51.897602737+08:00] Registering POST, /build
DEBU[2021-12-16T18:32:51.897617924+08:00] Registering POST, /build/prune
DEBU[2021-12-16T18:32:51.897650907+08:00] Registering POST, /build/cancel
DEBU[2021-12-16T18:32:51.897684859+08:00] Registering POST, /session
DEBU[2021-12-16T18:32:51.897712774+08:00] Registering POST, /swarm/init
DEBU[2021-12-16T18:32:51.897753631+08:00] Registering POST, /swarm/join
DEBU[2021-12-16T18:32:51.897790629+08:00] Registering POST, /swarm/leave
DEBU[2021-12-16T18:32:51.897828198+08:00] Registering GET, /swarm
DEBU[2021-12-16T18:32:51.897855170+08:00] Registering GET, /swarm/unlockkey
DEBU[2021-12-16T18:32:51.897885258+08:00] Registering POST, /swarm/update
DEBU[2021-12-16T18:32:51.897985167+08:00] Registering POST, /swarm/unlock
DEBU[2021-12-16T18:32:51.898020041+08:00] Registering GET, /services
DEBU[2021-12-16T18:32:51.898049589+08:00] Registering GET, /services/{id}
DEBU[2021-12-16T18:32:51.898091289+08:00] Registering POST, /services/create
DEBU[2021-12-16T18:32:51.898125825+08:00] Registering POST, /services/{id}/update
DEBU[2021-12-16T18:32:51.898193669+08:00] Registering DELETE, /services/{id}
DEBU[2021-12-16T18:32:51.898263312+08:00] Registering GET, /services/{id}/logs
DEBU[2021-12-16T18:32:51.898314635+08:00] Registering GET, /nodes
DEBU[2021-12-16T18:32:51.898343687+08:00] Registering GET, /nodes/{id}
DEBU[2021-12-16T18:32:51.898384581+08:00] Registering DELETE, /nodes/{id}
DEBU[2021-12-16T18:32:51.898425878+08:00] Registering POST, /nodes/{id}/update
DEBU[2021-12-16T18:32:51.898479910+08:00] Registering GET, /tasks
DEBU[2021-12-16T18:32:51.898509235+08:00] Registering GET, /tasks/{id}
DEBU[2021-12-16T18:32:51.898552799+08:00] Registering GET, /tasks/{id}/logs
DEBU[2021-12-16T18:32:51.898603922+08:00] Registering GET, /secrets
DEBU[2021-12-16T18:32:51.898635098+08:00] Registering POST, /secrets/create
DEBU[2021-12-16T18:32:51.898662216+08:00] Registering DELETE, /secrets/{id}
DEBU[2021-12-16T18:32:51.898692589+08:00] Registering GET, /secrets/{id}
DEBU[2021-12-16T18:32:51.898729195+08:00] Registering POST, /secrets/{id}/update
DEBU[2021-12-16T18:32:51.898756925+08:00] Registering GET, /configs
DEBU[2021-12-16T18:32:51.898776302+08:00] Registering POST, /configs/create
DEBU[2021-12-16T18:32:51.898802699+08:00] Registering DELETE, /configs/{id}
DEBU[2021-12-16T18:32:51.898835493+08:00] Registering GET, /configs/{id}
DEBU[2021-12-16T18:32:51.898868349+08:00] Registering POST, /configs/{id}/update
DEBU[2021-12-16T18:32:51.898904586+08:00] Registering GET, /plugins
DEBU[2021-12-16T18:32:51.898924593+08:00] Registering GET, /plugins/{name:.*}/json
DEBU[2021-12-16T18:32:51.898955590+08:00] Registering GET, /plugins/privileges
DEBU[2021-12-16T18:32:51.898988511+08:00] Registering DELETE, /plugins/{name:.*}
DEBU[2021-12-16T18:32:51.899020428+08:00] Registering POST, /plugins/{name:.*}/enable
DEBU[2021-12-16T18:32:51.899051148+08:00] Registering POST, /plugins/{name:.*}/disable
DEBU[2021-12-16T18:32:51.899084947+08:00] Registering POST, /plugins/pull
DEBU[2021-12-16T18:32:51.899106014+08:00] Registering POST, /plugins/{name:.*}/push
DEBU[2021-12-16T18:32:51.899147058+08:00] Registering POST, /plugins/{name:.*}/upgrade
DEBU[2021-12-16T18:32:51.899184091+08:00] Registering POST, /plugins/{name:.*}/set
DEBU[2021-12-16T18:32:51.899214831+08:00] Registering POST, /plugins/create
DEBU[2021-12-16T18:32:51.899281953+08:00] Registering GET, /distribution/{name:.*}/json
DEBU[2021-12-16T18:32:51.899602838+08:00] Registering POST, /grpc
DEBU[2021-12-16T18:32:51.899666854+08:00] Registering GET, /networks
DEBU[2021-12-16T18:32:51.899722583+08:00] Registering GET, /networks/
DEBU[2021-12-16T18:32:51.899786420+08:00] Registering GET, /networks/{id:.+}
DEBU[2021-12-16T18:32:51.899866636+08:00] Registering POST, /networks/create
DEBU[2021-12-16T18:32:51.899927792+08:00] Registering POST, /networks/{id:.*}/connect
DEBU[2021-12-16T18:32:51.900034830+08:00] Registering POST, /networks/{id:.*}/disconnect
DEBU[2021-12-16T18:32:51.900112160+08:00] Registering POST, /networks/prune
DEBU[2021-12-16T18:32:51.900168126+08:00] Registering DELETE, /networks/{id:.*}
INFO[2021-12-16T18:32:51.900476419+08:00] API listen on /var/run/docker.sock

^CINFO[2021-12-16T18:32:59.233777200+08:00] Processing signal 'interrupt'
DEBU[2021-12-16T18:32:59.233845343+08:00] daemon configured with a 15 seconds minimum shutdown timeout
DEBU[2021-12-16T18:32:59.233856690+08:00] start clean shutdown of all containers with a 15 seconds timeout...
DEBU[2021-12-16T18:32:59.234101653+08:00] found 0 orphan layers
DEBU[2021-12-16T18:32:59.234333298+08:00] Unix socket /var/run/docker/libnetwork/cbafe945be1b.sock doesn't exist. cannot accept client connections
DEBU[2021-12-16T18:32:59.234355982+08:00] Cleaning up old mountid : start.
INFO[2021-12-16T18:32:59.234404432+08:00] stopping event stream following graceful shutdown  error="<nil>" module=libcontainerd namespace=moby
DEBU[2021-12-16T18:32:59.234479990+08:00] Cleaning up old mountid : done.
DEBU[2021-12-16T18:32:59.234566884+08:00] Clean shutdown succeeded
INFO[2021-12-16T18:32:59.234581248+08:00] Daemon shutdown complete
INFO[2021-12-16T18:32:59.234590510+08:00] stopping healthcheck following graceful shutdown  module=libcontainerd
INFO[2021-12-16T18:32:59.234601809+08:00] stopping event stream following graceful shutdown  error="context canceled" module=libcontainerd namespace=plugins.moby
DEBU[2021-12-16T18:32:59.234649792+08:00] received signal                               signal=terminated
DEBU[2021-12-16T18:32:59.234692166+08:00] sd notification                               error="<nil>" notified=false state="STOPPING=1"
WARN[2021-12-16T18:33:00.234877892+08:00] grpc: addrConn.createTransport failed to connect to {unix:///var/run/docker/containerd/containerd.sock  <nil> 0 <nil>}. Err :connection error: desc = "transport: Error while dialing dial unix:///var/run/docker/containerd/containerd.sock: timeout". Reconnecting...  module=grpc
```

```
However, my previous statement was partly wrong: even though Debian has announced that they will stop distributing AUFS, the module is still included in the Ubuntu kernel on which the proxmox kernel is built, and the module can be selected as module apparently with no issue.

In order to test I have been compiling kernels the whole week-end, and finally managed to recompile the Ubuntu-5.11.0-41.45 kernel that is used as base for the pve-kernel-5.11.22-7 package, using the same config (as found in /boot), but with the addition of the aufs module AND ZFS (the latter is a bit tricky, the only solution I found was to compile ZFS as a separate project after recompiling the Ubuntu kernel, and then inject and repackage the zfs module(s) in the kernel .deb package).
```

```
$ docker run cmd.cat/ethtool ethtool
Unable to find image 'cmd.cat/ethtool:latest' locally
latest: Pulling from ethtool
97518928ae5f: Already exists
855023b9a688: Pull complete
dbc368251d6c: Pull complete
561542343955: Pull complete
Digest: sha256:d45a8aa2a60df199410b14c2e311603eca51c0f1885247a090fe05c251fa612f
Status: Downloaded newer image for cmd.cat/ethtool:latest
docker: Error response from daemon: failed to create endpoint frosty_lovelace on network bridge: failed to add the host (veth8b07dba) <=> sandbox (veth20feac9) pair interfaces: operation not supported.

# docker run cmd.cat/ethtool ethtool
docker: Error response from daemon: failed to create endpoint lucid_shirley on network bridge: failed to add the host (vethcab6880) <=> sandbox (vethd9c8666) pair interfaces: operation not supported.
ERRO[0000] error waiting for container: context canceled
```

# AUFS was the first storage driver in use with Docker.

AUFS has several features that make it a good choice for Docker. These features enable:

Fast container startup times.
Efficient use of storage.
Efficient use of memory.
Despite its capabilities and long history with Docker, some Linux distributions do not support AUFS. This is usually because AUFS is not included in the mainline (upstream) Linux kernel.

AUFS is a unification filesystem. This means that it takes multiple directories on a single Linux host, stacks them on top of each other, and provides a single unified view. To achieve this, AUFS uses a union mount.

AUFS stacks multiple directories and exposes them as a unified view through a single mount point. All of the directories in the stack, as well as the union mount point, must all exist on the same Linux host. AUFS refers to each directory that it stacks as a branch.

Within Docker, AUFS union mounts enable image layering. The AUFS storage driver implements Docker image layers using this union mount system. AUFS branches correspond to Docker image layers.


 The union mount point provides the unified view of all layers. As of Docker 1.10, image layer IDs do not correspond to the names of the directories that contain their data.


Docker leverages AUFS CoW technology to enable image sharing and minimize the use of disk space. AUFS works at the file level. This means that all AUFS CoW operations copy entire files - even if only a small part of the file is being modified. This behavior can have a noticeable impact on container performance, especially if the files being copied are large, below a lot of image layers, or the CoW operation must search a deep directory tree.


The AUFS storage driver deletes a file from a container by placing a whiteout file in the container's top layer. The whiteout file effectively obscures the existence of the file in the read-only image layers below.

```
$ cat /proc/filesystems
nodev   sysfs
nodev   tmpfs
nodev   bdev
nodev   proc
nodev   cgroup
nodev   cgroup2
nodev   cpuset
nodev   devtmpfs
nodev   binfmt_misc
nodev   configfs
nodev   debugfs
nodev   tracefs
nodev   securityfs
nodev   sockfs
nodev   bpf
nodev   pipefs
nodev   ramfs
nodev   hugetlbfs
nodev   devpts
nodev   autofs
nodev   efivarfs
nodev   mqueue
nodev   binder
nodev   pstore
        ext3
        ext2
        ext4
        fuseblk
nodev   fuse
nodev   fusectl
        vfat
        btrfs
nodev   overlay
```

```
# docker daemon --storage-driver=aufs &
```

Alternatively, you can edit the Docker config file and add the --storage-driver=aufs option to the DOCKER_OPTS line.

```
# Use DOCKER_OPTS to modify the daemon startup options.
DOCKER_OPTS="--storage-driver=aufs"
```

## Containers

Running containers are mounted below /var/lib/docker/aufs/mnt/<container-id>. This is where the AUFS union mount point that exposes the container and all underlying image layers as a single unified view exists. If a container is not running, it still has a directory here but it is empty. This is because AUFS only mounts a container when it is running. With Docker 1.10 and higher, container IDs no longer correspond to directory names under /var/lib/docker/aufs/mnt/<container-id>.

Container metadata and various config files that are placed into the running container are stored in /var/lib/docker/containers/<container-id>. Files in this directory exist for all containers on the system, including ones that are stopped. However, when a container is running the container's log files are also in this directory.

A container's thin writable layer is stored in a directory under /var/lib/docker/aufs/diff/. With Docker 1.10 and higher, container IDs no longer correspond to directory names. However, the containers thin writable layer still exists under here and is stacked by AUFS as the top writable layer and is where all changes to the container are stored. The directory exists even if the container is stopped. This means that restarting a container will not lose changes made to it. Once a container is deleted, it's thin writable layer in this directory is deleted.


## AUFS and Docker performance
To summarize some of the performance related aspects already mentioned:

The AUFS storage driver is a good choice for PaaS and other similar use-cases where container density is important. This is because AUFS efficiently shares images between multiple running containers, enabling fast container start times and minimal use of disk space.

The underlying mechanics of how AUFS shares files between image layers and containers uses the systems page cache very efficiently.

The AUFS storage driver can introduce significant latencies into container write performance. This is because the first time a container writes to any file, the file has be located and copied into the containers top writable layer. These latencies increase and are compounded when these files exist below many image layers and the files themselves are large.

```
$ docker
The application docker is not installed. It may be found in the following packages:
  community/docker 1:20.10.10-1         /usr/bin/docker
  community/podman-docker 3.4.2-1       /usr/bin/docker
Do you want to Install package docker? (y/N)  y
Executing command: pamac install docker

Preparing...

Choose optional dependencies for docker:
1:  pigz: parallel gzip compressor support

Enter a selection (default=none): 1

==== AUTHENTICATING FOR org.manjaro.pamac.commit ====
Authentication is required to install, update, or remove packages
Password:
==== AUTHENTICATION COMPLETE ====
Synchronizing package databases...
Resolving dependencies...
Checking inter-conflicts...

To install (5):
  pigz          2.6-1                                community  82.6 kB
  bridge-utils  1.7.1-1       (Required By: docker)  extra      17.0 kB
  runc          1.0.2-2       (Required By: docker)  community  3.0 MB
  containerd    1.5.7-1       (Required By: docker)  community  19.8 MB
  docker        1:20.10.10-1                         community  40.6 MB

Total download size: 63.5 MB
Total installed size: 300.8 MB

Apply transaction ? [y/N] y
Download of docker (1:20.10.10-1) started
Download of containerd (1.5.7-1) started
Download of containerd (1.5.7-1) finished
Download of pigz (2.6-1) started
Download of pigz (2.6-1) finished
Download of bridge-utils (1.7.1-1) started
Download of bridge-utils (1.7.1-1) finished
Download of runc (1.0.2-2) started
Download of runc (1.0.2-2) finished
Download of docker (1:20.10.10-1) finished
Checking keyring...                                                                                                [5/5]
Checking integrity...                                                                                              [5/5]
Loading packages files...                                                                                          [5/5]
Checking file conflicts...                                                                                         [5/5]
Checking available disk space...                                                                                   [5/5]
Installing bridge-utils (1.7.1-1)...                                                                               [1/5]
Installing runc (1.0.2-2)...                                                                                       [2/5]
Installing containerd (1.5.7-1)...                                                                                 [3/5]
Installing docker (1:20.10.10-1)...                                                                                [4/5]
Installing pigz (2.6-1)...                                                                                         [5/5]
Running post-transaction hooks...
Creating system user accounts...                                                                                   [1/4]
Creating group docker with gid 966.
Reloading system manager configuration...                                                                          [2/4]
Reloading device manager configuration...                                                                          [3/4]
Arming ConditionNeedsUpdate...                                                                                     [4/4]
Transaction successfully finished.

$ docker run -d -P nginx:alpine
docker: Cannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?.
See 'docker run --help'.
# systemctl status docker
○ docker.service - Docker Application Container Engine
     Loaded: loaded (/usr/lib/systemd/system/docker.service; disabled; vendor preset: disabled)
     Active: inactive (dead)
TriggeredBy: ○ docker.socket
       Docs: https://docs.docker.com
# systemctl enable --now docker
Created symlink /etc/systemd/system/multi-user.target.wants/docker.service → /usr/lib/systemd/system/docker.service.
$ docker run -d -P nginx:alpine
docker: Got permission denied while trying to connect to the Docker daemon socket at unix:///var/run/docker.sock: Post "http://%2Fvar%2Frun%2Fdocker.sock/v1.24/containers/create": dial unix /var/run/docker.sock: connect: permission denied.
See 'docker run --help'.
# docker run -d -P nginx:alpine
Unable to find image 'nginx:alpine' locally
alpine: Pulling from library/nginx
97518928ae5f: Pull complete
a4e156412037: Pull complete
e0bae2ade5ec: Pull complete
3f3577460f48: Pull complete
e362c27513c3: Pull complete
a2402c2da473: Pull complete
Digest: sha256:12aa12ec4a8ca049537dd486044b966b0ba6cd8890c4c900ccb5e7e630e03df0
Status: Downloaded newer image for nginx:alpine
53faf7896e38dc623e91fc9aa62b0363282b917b4b901a9f567a4f601b2f4b01
    ~  docker logs                                                                          ✔  39s   aaron@i54
"docker logs" requires exactly 1 argument.
See 'docker logs --help'.

Usage:  docker logs [OPTIONS] CONTAINER

Fetch the logs of a container
    ~  docker logs 53faf789                                                                       1 ✘  aaron@i54
Got permission denied while trying to connect to the Docker daemon socket at unix:///var/run/docker.sock: Get "http://%2Fvar%2Frun%2Fdocker.sock/v1.24/containers/53faf789/json": dial unix /var/run/docker.sock: connect: permission denied
    ~  sudo docker logs 53faf789                                                                  1 ✘  aaron@i54
/docker-entrypoint.sh: /docker-entrypoint.d/ is not empty, will attempt to perform configuration
/docker-entrypoint.sh: Looking for shell scripts in /docker-entrypoint.d/
/docker-entrypoint.sh: Launching /docker-entrypoint.d/10-listen-on-ipv6-by-default.sh
10-listen-on-ipv6-by-default.sh: info: Getting the checksum of /etc/nginx/conf.d/default.conf
10-listen-on-ipv6-by-default.sh: info: Enabled listen on IPv6 in /etc/nginx/conf.d/default.conf
/docker-entrypoint.sh: Launching /docker-entrypoint.d/20-envsubst-on-templates.sh
/docker-entrypoint.sh: Launching /docker-entrypoint.d/30-tune-worker-processes.sh
/docker-entrypoint.sh: Configuration complete; ready for start up
2021/12/08 02:05:19 [notice] 1#1: using the "epoll" event method
2021/12/08 02:05:19 [notice] 1#1: nginx/1.21.4
2021/12/08 02:05:19 [notice] 1#1: built by gcc 10.3.1 20210424 (Alpine 10.3.1_git20210424)
2021/12/08 02:05:19 [notice] 1#1: OS: Linux 5.10.79-1-MANJARO
2021/12/08 02:05:19 [notice] 1#1: getrlimit(RLIMIT_NOFILE): 1048576:1048576
2021/12/08 02:05:19 [notice] 1#1: start worker processes
2021/12/08 02:05:19 [notice] 1#1: start worker process 32
2021/12/08 02:05:19 [notice] 1#1: start worker process 33
2021/12/08 02:05:19 [notice] 1#1: start worker process 34
2021/12/08 02:05:19 [notice] 1#1: start worker process 35
2021/12/08 02:05:19 [notice] 1#1: start worker process 36
2021/12/08 02:05:19 [notice] 1#1: start worker process 37
2021/12/08 02:05:19 [notice] 1#1: start worker process 38
2021/12/08 02:05:19 [notice] 1#1: start worker process 39
    ~  sudo docker container ls -l                                                                  ✔  aaron@i54
CONTAINER ID   IMAGE          COMMAND                  CREATED              STATUS              PORTS                                     NAMES
53faf7896e38   nginx:alpine   "/docker-entrypoint.…"   About a minute ago   Up About a minute   0.0.0.0:49153->80/tcp, :::49153->80/tcp   sad_keller
    ~  sudo docker run -d -p 8888:80 nginx:alpine                                                   ✔  aaron@i54

6c312c1ff29949838bbee3f7e4a7542aeaa2e65acc20adf9603e376b3779833d
    ~                                                                                        ✔  8s   aaron@i54
    ~  sudo docker logs 6c312c1ff                                                                   ✔  aaron@i54
/docker-entrypoint.sh: /docker-entrypoint.d/ is not empty, will attempt to perform configuration
/docker-entrypoint.sh: Looking for shell scripts in /docker-entrypoint.d/
/docker-entrypoint.sh: Launching /docker-entrypoint.d/10-listen-on-ipv6-by-default.sh
10-listen-on-ipv6-by-default.sh: info: Getting the checksum of /etc/nginx/conf.d/default.conf
10-listen-on-ipv6-by-default.sh: info: Enabled listen on IPv6 in /etc/nginx/conf.d/default.conf
/docker-entrypoint.sh: Launching /docker-entrypoint.d/20-envsubst-on-templates.sh
/docker-entrypoint.sh: Launching /docker-entrypoint.d/30-tune-worker-processes.sh
/docker-entrypoint.sh: Configuration complete; ready for start up
2021/12/08 02:07:21 [notice] 1#1: using the "epoll" event method
2021/12/08 02:07:21 [notice] 1#1: nginx/1.21.4
2021/12/08 02:07:21 [notice] 1#1: built by gcc 10.3.1 20210424 (Alpine 10.3.1_git20210424)
2021/12/08 02:07:21 [notice] 1#1: OS: Linux 5.10.79-1-MANJARO
2021/12/08 02:07:21 [notice] 1#1: getrlimit(RLIMIT_NOFILE): 1048576:1048576
2021/12/08 02:07:21 [notice] 1#1: start worker processes
2021/12/08 02:07:21 [notice] 1#1: start worker process 32
2021/12/08 02:07:21 [notice] 1#1: start worker process 33
2021/12/08 02:07:21 [notice] 1#1: start worker process 34
2021/12/08 02:07:21 [notice] 1#1: start worker process 35
2021/12/08 02:07:21 [notice] 1#1: start worker process 36
2021/12/08 02:07:21 [notice] 1#1: start worker process 37
2021/12/08 02:07:21 [notice] 1#1: start worker process 38
2021/12/08 02:07:21 [notice] 1#1: start worker process 39
    ~  sudo docker container ls -l                                                                  ✔  aaron@i54
CONTAINER ID   IMAGE          COMMAND                  CREATED          STATUS          PORTS                                   NAMES
6c312c1ff299   nginx:alpine   "/docker-entrypoint.…"   26 seconds ago   Up 17 seconds   0.0.0.0:8888->80/tcp, :::8888->80/tcp   condescending_shaw
    ~  sudo docker logs 6c312c1ff                                                                   ✔  aaron@i54
/docker-entrypoint.sh: /docker-entrypoint.d/ is not empty, will attempt to perform configuration
/docker-entrypoint.sh: Looking for shell scripts in /docker-entrypoint.d/
/docker-entrypoint.sh: Launching /docker-entrypoint.d/10-listen-on-ipv6-by-default.sh
10-listen-on-ipv6-by-default.sh: info: Getting the checksum of /etc/nginx/conf.d/default.conf
10-listen-on-ipv6-by-default.sh: info: Enabled listen on IPv6 in /etc/nginx/conf.d/default.conf
/docker-entrypoint.sh: Launching /docker-entrypoint.d/20-envsubst-on-templates.sh
/docker-entrypoint.sh: Launching /docker-entrypoint.d/30-tune-worker-processes.sh
/docker-entrypoint.sh: Configuration complete; ready for start up
2021/12/08 02:07:21 [notice] 1#1: using the "epoll" event method
2021/12/08 02:07:21 [notice] 1#1: nginx/1.21.4
2021/12/08 02:07:21 [notice] 1#1: built by gcc 10.3.1 20210424 (Alpine 10.3.1_git20210424)
2021/12/08 02:07:21 [notice] 1#1: OS: Linux 5.10.79-1-MANJARO
2021/12/08 02:07:21 [notice] 1#1: getrlimit(RLIMIT_NOFILE): 1048576:1048576
2021/12/08 02:07:21 [notice] 1#1: start worker processes
2021/12/08 02:07:21 [notice] 1#1: start worker process 32
2021/12/08 02:07:21 [notice] 1#1: start worker process 33
2021/12/08 02:07:21 [notice] 1#1: start worker process 34
2021/12/08 02:07:21 [notice] 1#1: start worker process 35
2021/12/08 02:07:21 [notice] 1#1: start worker process 36
2021/12/08 02:07:21 [notice] 1#1: start worker process 37
2021/12/08 02:07:21 [notice] 1#1: start worker process 38
2021/12/08 02:07:21 [notice] 1#1: start worker process 39
10.10.50.13 - - [08/Dec/2021:02:08:10 +0000] "GET / HTTP/1.1" 200 615 "-" "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.45 Safari/537.36" "-"
10.10.50.13 - - [08/Dec/2021:02:08:10 +0000] "GET /favicon.ico HTTP/1.1" 404 555 "http://10.10.50.103:8888/" "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.45 Safari/537.36" "-"
2021/12/08 02:08:10 [error] 33#33: *1 open() "/usr/share/nginx/html/favicon.ico" failed (2: No such file or directory), client: 10.10.50.13, server: localhost, request: "GET /favicon.ico HTTP/1.1", host: "10.10.50.103:8888", referrer: "http://10.10.50.103:8888/"
    ~ 


-p 则可以指定要映射的端口，并且，在一个指定端口上只可以绑定一个容器。支持的格式有 ip:hostPort:containerPort | ip::containerPort | hostPort:containerPort。
映射所有接口地址
使用 hostPort:containerPort 格式本地的 80 端口映射到容器的 80 端口，可以执行
1
$ docker run -d -p 80:80 nginx:alpine
Copied!
此时默认会绑定本地所有接口上的所有地址。
映射到指定地址的指定端口
可以使用 ip:hostPort:containerPort 格式指定映射使用一个特定地址，比如 localhost 地址 127.0.0.1
1
$ docker run -d -p 127.0.0.1:80:80 nginx:alpine
Copied!
映射到指定地址的任意端口
使用 ip::containerPort 绑定 localhost 的任意端口到容器的 80 端口，本地主机会自动分配一个端口。
1
$ docker run -d -p 127.0.0.1::80 nginx:alpine
Copied!
还可以使用 udp 标记来指定 udp 端口
1
$ docker run -d -p 127.0.0.1:80:80/udp nginx:alpine
Copied!
查看映射端口配置
使用 docker port 来查看当前映射的端口配置，也可以查看到绑定的地址
1
$ docker port fa 80
2
0.0.0.0:32768
Copied!
注意：
容器有自己的内部网络和 ip 地址（使用 docker inspect 查看，Docker 还可以有一个可变的网络配置。）
-p 标记可以多次使用来绑定多个端口
例如
1
$ docker run -d \
2
    -p 80:80 \
3
    -p 443:443 \
4
    nginx:alpine


# 创建一个新的 Docker 网络。

$ docker network create -d bridge my-net

-d 参数指定 Docker 网络类型，有 bridge overlay。其中 overlay 网络类型用于 Swarm mode，

运行一个容器并连接到新建的 my-net 网络

$ docker run -it --rm --name busybox1 --network my-net busybox sh

打开新的终端，再运行一个容器并加入到 my-net 网络

$ docker run -it --rm --name busybox2 --network my-net busybox sh

再打开一个新的终端查看容器信息

$ docker container ls


CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES

b47060aca56b        busybox             "sh"                11 minutes ago      Up 11 minutes                           busybox2

8720575823ec        busybox             "sh"                16 minutes ago      Up 16 minutes                           busybox1

ping 来证明 busybox1 容器和 busybox2 容器建立了互联关系。

# DNS


如何自定义配置容器的主机名和 DNS 呢？秘诀就是 Docker 利用虚拟文件来挂载容器的 3 个相关配置文件。
在容器中使用 mount 命令可以看到挂载信息：
1
$ mount
2
/dev/disk/by-uuid/1fec...ebdf on /etc/hostname type ext4 ...
3
/dev/disk/by-uuid/1fec...ebdf on /etc/hosts type ext4 ...
4
tmpfs on /etc/resolv.conf type tmpfs ...
Copied!
这种机制可以让宿主主机 DNS 信息发生更新后，所有 Docker 容器的 DNS 配置通过 /etc/resolv.conf 文件立刻得到更新。
配置全部容器的 DNS ，也可以在 /etc/docker/daemon.json 文件中增加以下内容来设置。
1
{
2
  "dns" : [
3
    "114.114.114.114",
4
    "8.8.8.8"
5
  ]
6
}



使用 docker run 命令启动容器时加入如下参数：
-h HOSTNAME 或者 --hostname=HOSTNAME 设定容器的主机名，它会被写到容器内的 /etc/hostname 和 /etc/hosts。但它在容器外部看不到，既不会在 docker container ls 中显示，也不会在其他的容器的 /etc/hosts 看到。
--dns=IP_ADDRESS 添加 DNS 服务器到容器的 /etc/resolv.conf 中，让容器用这个服务器来解析所有不在 /etc/hosts 中的主机名。
--dns-search=DOMAIN 设定容器的搜索域，当设定搜索域为 .example.com 时，在搜索一个名为 host 的主机时，DNS 不仅搜索 host，还会搜索 host.example.com。
注意：如果在容器启动时没有指定最后两个参数，Docker 会默认用主机上的 /etc/resolv.conf 来配置容器。


些命令选项只有在 Docker 服务启动的时候才能配置，而且不能马上生效。
-b BRIDGE 或 --bridge=BRIDGE 指定容器挂载的网桥
--bip=CIDR 定制 docker0 的掩码
-H SOCKET... 或 --host=SOCKET... Docker 服务端接收命令的通道
--icc=true|false 是否支持容器之间进行通信
--ip-forward=true|false 请看下文容器之间的通信
--iptables=true|false 是否允许 Docker 添加 iptables 规则
--mtu=BYTES 容器网络中的 MTU

这些选项只有在 docker run 执行时使用，因为它是针对容器的特性内容。
-h HOSTNAME 或 --hostname=HOSTNAME 配置容器主机名
--link=CONTAINER_NAME:ALIAS 添加到另一个容器的连接
--net=bridge|none|container:NAME_or_ID|host 配置容器的桥接模式
-p SPEC 或 --publish=SPEC 映射容器端口到宿主主机
-P or --publish-all=true|false 映射容器所有端口到宿主主机



eltas: 100% (1726/1726), done.


## 容器的访问控制，主要通过 Linux 上的 iptables 防火墙来进行管理和实现



容器访问外部网络
容器要想访问外部网络，需要本地系统的转发支持。在Linux 系统中，检查转发是否打开。
1
$sysctl net.ipv4.ip_forward
2
net.ipv4.ip_forward = 1
Copied!
如果为 0，说明没有开启转发，则需要手动打开。
1
$sysctl -w net.ipv4.ip_forward=1
Copied!
如果在启动 Docker 服务的时候设定 --ip-forward=true, Docker 就会自动设定系统的 ip_forward 参数为 1。
容器之间访问
容器之间相互访问，需要两方面的支持。
容器的网络拓扑是否已经互联。默认情况下，所有容器都会被连接到 docker0 网桥上。
本地系统的防火墙软件 -- iptables 是否允许通过。
访问所有端口
当启动 Docker 服务（即 dockerd）的时候，默认会添加一条转发策略到本地主机 iptables 的 FORWARD 链上。策略为通过（ACCEPT）还是禁止（DROP）取决于配置--icc=true（缺省值）还是 --icc=false。当然，如果手动指定 --iptables=false 则不会添加 iptables 规则。
可见，默认情况下，不同容器之间是允许网络互通的。如果为了安全考虑，可以在 /etc/docker/daemon.json 文件中配置 {"icc": false} 来禁止它。
访问指定端口
在通过 -icc=false 关闭网络访问后，还可以通过 --link=CONTAINER_NAME:ALIAS 选项来访问容器的开放端口。
例如，在启动 Docker 服务时，可以同时使用 icc=false --iptables=true 参数来关闭允许相互的网络访问，并让 Docker 可以修改系统中的 iptables 规则。
此时，系统中的 iptables 规则可能是类似
1
# iptables -nL
2
...
3
Chain FORWARD (policy ACCEPT)
4
target     prot opt source               destination
5
DROP       all  --  0.0.0.0/0            0.0.0.0/0
6
...
Copied!
之后，启动容器（docker run）时使用 --link=CONTAINER_NAME:ALIAS 选项。Docker 会在 iptable 中为 两个容器分别添加一条 ACCEPT 规则，允许相互访问开放的端口（取决于 Dockerfile 中的 EXPOSE 指令）。
当添加了 --link=CONTAINER_NAME:ALIAS 选项后，添加了 iptables 规则。
1
# iptables -nL
2
...
3
Chain FORWARD (policy ACCEPT)
4
target     prot opt source               destination
5
ACCEPT     tcp  --  172.17.0.2           172.17.0.3           tcp spt:80
6
ACCEPT     tcp  --  172.17.0.3           172.17.0.2           tcp dpt:80
7
DROP       all  --  0.0.0.0/0            0.0.0.0/0
Copied!
注意：--link=CONTAINER_NAME:ALIAS 中的 CONTAINER_NAME 目前必须是 Docker 分配的名字，或使用 --name 参数指定的名字。主机名则不会被识别。


##
默认情况下，容器可以主动访问到外部网络的连接，但是外部网络无法访问到容器。
容器访问外部实现
容器所有到外部网络的连接，源地址都会被 NAT 成本地系统的 IP 地址。这是使用 iptables 的源地址伪装操作实现的。
查看主机的 NAT 规则。
1
# iptables -t nat -nL
2
...
3
Chain POSTROUTING (policy ACCEPT)
4
target     prot opt source               destination
5
MASQUERADE  all  --  172.17.0.0/16       !172.17.0.0/16
6
...
Copied!
其中，上述规则将所有源地址在 172.17.0.0/16 网段，目标地址为其他网段（外部网络）的流量动态伪装为从系统网卡发出。MASQUERADE 跟传统 SNAT 的好处是它能动态从网卡获取地址。
外部访问容器实现
容器允许外部访问，可以在 docker run 时候通过 -p 或 -P 参数来启用。
不管用那种办法，其实也是在本地的 iptable 的 nat 表中添加相应的规则。
使用 -P 时：
1
$ iptables -t nat -nL
2
...
3
Chain DOCKER (2 references)
4
target     prot opt source               destination
5
DNAT       tcp  --  0.0.0.0/0            0.0.0.0/0            tcp dpt:49153 to:172.17.0.2:80
Copied!
使用 -p 80:80 时：
1
$ iptables -t nat -nL
2
Chain DOCKER (2 references)
3
target     prot opt source               destination
4
DNAT       tcp  --  0.0.0.0/0            0.0.0.0/0            tcp dpt:80 to:172.17.0.2:80
Copied!
注意：
这里的规则映射了 0.0.0.0，意味着将接受主机来自所有接口的流量。用户可以通过 -p IP:host_port:container_port 或 -p IP::port 来指定允许访问容器的主机上的 IP、接口等，以制定更严格的规则。
如果希望永久绑定到某个固定的 IP 地址，可以在 Docker 配置文件 /etc/docker/daemon.json 中添加如下内容。
1
{
2
  "ip": "0.0.0.0"
3
}


## 自定义网桥
除了默认的 docker0 网桥，用户也可以指定网桥来连接各个容器。
在启动 Docker 服务的时候，使用 -b BRIDGE或--bridge=BRIDGE 来指定使用的网桥。
如果服务已经运行，那需要先停止服务，并删除旧的网桥。
1
# systemctl stop docker
2
# ip link set dev docker0 down
3
# brctl delbr docker0
Copied!
然后创建一个网桥 bridge0。
1
# brctl addbr bridge0
2
# ip addr add 192.168.5.1/24 dev bridge0
3
# ip link set dev bridge0 up
Copied!
查看确认网桥创建并启动。
1
$ ip addr show bridge0
2
4: bridge0: <BROADCAST,MULTICAST> mtu 1500 qdisc noop state UP group default
3
    link/ether 66:38:d0:0d:76:18 brd ff:ff:ff:ff:ff:ff
4
    inet 192.168.5.1/24 scope global bridge0
5
       valid_lft forever preferred_lft forever
Copied!
在 Docker 配置文件 /etc/docker/daemon.json 中添加如下内容，即可将 Docker 默认桥接到创建的网桥上。
1
{
2
  "bridge": "bridge0",
3
}
Copied!
启动 Docker 服务。
新建一个容器，可以看到它已经桥接到了 bridge0 上。
可以继续用 brctl show 命令查看桥接的信息。另外，在容器中可以使用 ip addr 和 ip route 命令来查看 IP 地址配置和路由信息。

# Tools

pipework
Jérôme Petazzoni 编写了一个叫 pipework 的 shell 脚本，可以帮助用户在比较复杂的场景中完成容器的连接。
playground
Brandon Rhodes 创建了一个提供完整的 Docker 容器网络拓扑管理的 Python库，包括路由、NAT 防火墙；以及一些提供 HTTP SMTP POP IMAP Telnet SSH FTP 的服务器。

## 编辑网络配置文件
Docker 1.2.0 开始支持在运行中的容器里编辑 /etc/hosts, /etc/hostname 和 /etc/resolv.conf 文件。
但是这些修改是临时的，只在运行的容器中保留，容器终止或重启后并不会被保存下来，也不会被 docker commit 提交。


## 实例：创建一个点到点连接
默认情况下，Docker 会将所有容器连接到由 docker0 提供的虚拟子网中。
用户有时候需要两个容器之间可以直连通信，而不用通过主机网桥进行桥接。
解决办法很简单：创建一对 peer 接口，分别放到两个容器中，配置成点到点链路类型即可。
首先启动 2 个容器：
1
$ docker run -i -t --rm --net=none base /bin/bash
2
root@1f1f4c1f931a:/#
3
$ docker run -i -t --rm --net=none base /bin/bash

找到进程号，然后创建网络命名空间的跟踪文件。

```
$ docker inspect -f '{{.State.Pid}}' 1f1f4c1f931a
2989

$ docker inspect -f '{{.State.Pid}}' 12e343489d2f
3004

# mkdir -p /var/run/netns
# ln -s /proc/2989/ns/net /var/run/netns/2989
# ln -s /proc/3004/ns/net /var/run/netns/3004
```

创建一对 peer 接口，然后配置路由

```
# ip link add A type veth peer name B
# ip link set A netns 2989
# ip netns exec 2989 ip addr add 10.1.1.1/32 dev A
# ip netns exec 2989 ip link set A up
# ip netns exec 2989 ip route add 10.1.1.2/32 dev A
# ip link set B netns 3004
# ip netns exec 3004 ip addr add 10.1.1.2/32 dev B
# ip netns exec 3004 ip link set B up
# ip netns exec 3004 ip route add 10.1.1.1/32 dev B
```

现在这 2 个容器就可以相互 ping 通，并成功建立连接。点到点链路不需要子网和子网掩码。
此外，也可以不指定 --net=none 来创建点到点链路。这样容器还可以通过原先的网络来通信。
利用类似的办法，可以创建一个只跟主机通信的容器。但是一般情况下，更推荐使用 --icc=false 来关闭容器之间的通信。



# etcd 在设计的时候重点考虑了下面四个要素：

简单：具有定义良好、面向用户的 API (gRPC (opens new window))

安全：支持 HTTPS 方式的访问

快速：支持并发 10 k/s 的写操作

可靠：支持分布式结构，基于 Raft 的一致性算法

Apache ZooKeeper 是一套知名的分布式系统中进行同步和一致性管理的工具。

doozer 是一个一致性分布式数据库。

Raft (opens new window)是一套通过选举主节点来实现分布式系统一致性的算法，相比于大名鼎鼎的 Paxos 算法，它的过程更容易被人理解，由 Stanford 大学的 Diego Ongaro 和 John Ousterhout 提出。更多细节可以参考 raftconsensus.github.io (opens new window)。

一般情况下，用户使用 etcd 可以在多个节点上启动多个实例，并添加它们为一个集群。同一个集群中的 etcd 实例将会保持彼此信息的一致性。




etcd 是服务主文件，etcdctl 是提供给用户的命令客户端，其他文件是支持文档。

下面将 etcd etcdctl 文件放到系统可执行目录（例如 /usr/local/bin/）。

￼
# cp etcd* /usr/local/bin/
1
默认 2379 端口处理客户端的请求，2380 端口用于集群各成员间的通信。启动 etcd 显示类似如下的信息：

￼
$ etcd
...
2017-12-03 11:18:34.411579 I | embed: listening for peers on http://localhost:2380
2017-12-03 11:18:34.411938 I | embed: listening for client requests on localhost:2379
1
2
3
4
此时，可以使用 etcdctl 命令进行测试，设置和获取键值 testkey: "hello world"，检查 etcd 服务是否启动成功：

￼
$ ETCDCTL_API=3 etcdctl member list
8e9e05c52164694d, started, default, http://localhost:2380, http://localhost:2379

$ ETCDCTL_API=3 etcdctl put testkey "hello world"
OK

$ etcdctl get testkey
testkey
hello world
1
2
3
4
5
6
7
8
9
说明 etcd 服务已经成功启动了。

#


Docker 镜像方式运行
镜像名称为 quay.io/coreos/etcd，可以通过下面的命令启动 etcd 服务监听到 2379 和 2380 端口。

￼
$ docker run \
-p 2379:2379 \
-p 2380:2380 \
--mount type=bind,source=/tmp/etcd-data.tmp,destination=/etcd-data \
--name etcd-gcr-v3.4.0 \
quay.io/coreos/etcd:v3.4.0 \
/usr/local/bin/etcd \
--name s1 \
--data-dir /etcd-data \
--listen-client-urls http://0.0.0.0:2379 \
--advertise-client-urls http://0.0.0.0:2379 \
--listen-peer-urls http://0.0.0.0:2380 \
--initial-advertise-peer-urls http://0.0.0.0:2380 \
--initial-cluster s1=http://0.0.0.0:2380 \
--initial-cluster-token tkn \
--initial-cluster-state new \
--log-level info \
--logger zap \
--log-outputs stderr
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
16
17
18
19
打开新的终端按照上一步的方法测试 etcd 是否成功启动。




# Swarm Mode[编辑]
当说到 Docker Swarm 时，一般是指单独项目 Docker Swarm。而在Docker 1.12时，将swarm mode集成到Docker 引擎中，可用Docker引擎API 和 CLI 命令直接使用。官方推荐用户使用集成的 swarm mode [15]。

Swarm Mode 内置 kv 存储功能，提供了众多的新特性，比如：具有容错能力的去中心化设计、内置服务发现、负载均衡、路由网格、动态伸缩、滚动更新、安全传输等。使得 Docker 原生的 Swarm 集群具备与 Mesos、Kubernetes 竞争的实力。[16]

cluster(中文：集群)，Docker将集群定义为：一群共同作业并提供高可用性的机器[17] 。swarm(中文：群[18])，是指一个集群的Docker引擎以swarm mode形式运行[19]。swarm mode是指Docker引擎内嵌的集群管理和编排功能。当你初始化了一个swarm(cluster)或者将节点加入一个swarm时，其Docker引擎就会以swarm mode的形式运行。[20]




[编辑]
swarm中的Docker机器中分为 managers（管理者） 和 workers（员工），管理者用于处理集群的关系和委派，员工则用于执行 swarm服务。[21] 当你创建swarm服务时，你可以为其增加各种额外的状态（如：数量、网络、端口、存储资源等等）。Docker会去维持用户想要的状态。如：一个工作节点如果挂了，那么Docker会去把这个节点的任务给另外一个节点。此处的任务（task）是指：被swarm管理者管理的一个运行中的容器。[21]

swarm服务比单独容器好在，修改swarm服务的配置之后不用重启。同时，Docker以swarm mode形式运行时，也可以选择直接启动单独的容器。另外，swarm mode下，你也可以通过 docker stack deploy 使用 Compose file 部署应用栈。[22][21] swarm服务分为两种，一种是replicated services ，可以指定节点任务的总数量；global services，则是每个节点都会运行一个指定任务。[23] swarm管理员使用 ingress 负载均衡使服务可被外部接触。 swarm管理员会自动地给服务分配PublishedPort（或者手动配置）。外部组件，如云负载均衡器能通过集群中任何节点上的PublishedPort去接入服务（不管该服务是否启动）。另外 swarm mode有内部DNS组件，它会为每个服务分配一个DNS条目。swarm管理员使用 internal load balancing 去分发请求时，就是依靠这个DNS组件。[24]

swarm mode的功能是由swarmkit(一个独立项目)提供的，它实现了Docker的编排层。swarm可以直接被Docker使用。[21]



## Dockerfile[编辑]
Docker 可以依照 Dockerfile 的内容，自动化地构建镜像。 Dockerfile 是包含着用户想要如何构建镜像的所有命令的文本。[26]

FROM ubuntu:18.04
COPY . /app
RUN make /app
CMD python /app/app.py
关键词：

RUN。RUN会在当前镜像的顶层上添加新的一层(layer)，并在该层上执行命令，执行结果将会被提交。提交后的结果将会用于Dockerfile的下一步。[27]
ENTRYPOINT，入口点。ENTRYPOINT允许你配置容器，使之成为可执行程序。[28]即，ENTRYPOINT允许你为容器增加一个入口点。ENTRYPOINT和CMD类似，均在容器启动时执行，但是ENTRYPOINT为了提供稳定且不可被覆盖的操作。[29]通过在命令行中指定--entrypoint 命令的方式，可在运行时将Dockerfile文件中的ENTRYPOINT覆盖。
CMD，是command的缩写。CMD用于为已创建的镜像提供默认的操作，当不想要用默认操作时候，可用docker run IMAGE[:TAG|@DIGEST] [COMMAND] 进行替换 。但当Dockerfile拥有入口点时，CMD用于赋予入口点参数。[30]
Compose文件[编辑]
Compose文件 是一个YAML文件，定义了服务（service）、网络、卷（volume）。

服务（service）定义 各容器的配置，定义内容将以命令行参数的方式 传给 docker run 命令。
网络（network），类似地，将定义内容传给 docker network create 命令 。
卷（volume），类似地，将定义内容传给 docker volume create 命令。
docker run 命令中有一些选项，和 Dockerfile文件中的指令效果一样（如：CMD, EXPOSE, VOLUME, ENV），如果Dockerfile文件中使用这些指令，那么这些指令就会被视为默认参数，所以开发者无需特意在 Compose文件中再指定一次。[31]

Compose文件 可使用 Shell变量（Variable），如：[32]

db:
  image: "postgres:${POSTGRES_VERSION}"
Compose文件 可通过自身的ARGS变量，将参数传给Dockerfile的 ARGS 指令。[33]



# 数据管理[编辑]
Docker默认下，所有文件将会存储在容器里的可写的容器层（container layer）。[42]

数据与容器为一体。随着容器消失，数据将消失；难以与其他程序（容器）共享。
由于容器的写入层是与宿主机器紧紧耦合。所以你难以移动数据到其他机器。
容器的写入层的是通过 存储驱动（页面存档备份，存于互联网档案馆）（storage driver） 管理文件系统。存储驱动（页面存档备份，存于互联网档案馆） 会使用Linux内核的 链合文件系统（union filesystem）进行挂载。相比起直接操作于宿主机器文件系统的 数据卷，这额外的抽象层将会降低性能。
容器有两种永久化存储方式：卷（volumes）和 绑定挂载（bind mounts）。另外，Linux用户还可使用 tmpfs 进行挂载；Window用户还可以使用 命名管道（named pipe）。在容器中，不管是哪种永久化存储，表现形式都是一样的。[42]

卷[编辑]
卷（volumes）是宿主机器的文件系统的一部分，由Docker进行管理（ 在Linux，存储于/var/lib/docker/volumes/）。非Docker程序不应该去修改这些文件。Docker推荐使用 卷 进行持久化数据。 卷 可支持 卷驱动（volume drivers），该驱动允许用户将数据存储到 远程主机 或 云服务商（cloud provider）或 其他。[42]

没有名字的卷叫匿名卷（anonymous volume），有名字的卷叫命名卷（named volume）。匿名卷没有明确的名字，当被初始化时，会被赋予一个随机名字。[42]

绑定挂载[编辑]
绑定挂载（bind mounts）通过将宿主机器的路径挂载到容器里的这种方式，从而数据持续化，因此绑定挂载可将数据存储在宿主机器的文件系统的任何地方。非Docker程序可修改这些文件。 绑定挂载是Docker早期就存在的，相比起卷，绑定挂载十分简单明了。[42] 在开发Docker应用时，应使用命名卷（named volume）代替绑定挂载，因为用户不能对绑定挂载进行 Docker CLI 命令操作。[42]

绑定挂载常用于：[43]

同步配置文件，如： 将 宿主主机的DNS配置文件（/etc/resolv.conf）同步至容器中
在开发程序时，将 源代码 或 Artifact 同步至容器中。[43] 这种用法与 Vagrant 类似。
tmpfs[编辑]
tmpfs 挂载（tmpfs mounts），仅仅存储于内存中，并不操作 宿主机器的文件系统（不持久化于磁盘）。它可用于存储一些 非持久化状态、敏感数据。 举例，swarm服务 通过tmpfs 将 secrets（页面存档备份，存于互联网档案馆）（密码、密钥、证书等）存储到swarm服务。 [42]

命名管道[编辑]
命名管道（named pipes），通过 npipe 挂载的形式，使 Docker主机 和 容器 之间能互相通讯。常见用例是在容器内运行第三方工具，并使用命名管道连接到Docker Engine API。[42][44]

覆盖问题[编辑]
当挂载 空的卷 至一个目录中，目录中的内容会被复制于卷中（不会覆盖）。如果挂载 非空的卷 或 绑定挂载 至一个目录中，那么该目录的内容将会被隐藏（obscured ），当卸载后内容将会恢复显示。[45]

日志[编辑]
在Linux和UNIX中，常见的 I/O流（英語：I/O streams） 分为三种：STDIN（输入 ）、 STDOUT（正常输出）、STDERR（错误输出）。[46]

默认配置下，Docker的日志（如：docker logs、docker service log）所记载的是命令行的输出结果（STDOUT和STDERR）。而STDOUT 和 STDERR 对应的文件路径分别是 /dev/stderr和/dev/stdout。[46] 另外，也可以在宿主主机上查看容器的日志，使用以下命令可以查看到容器的日志位置。[47]

```
$ docker inspect --format='{{.LogPath}}' $INSTANCE_ID
```

#
docker exec -it ${name}/${id} /bin/bash

示例：
docker exec -it centOS1 /bin/bash「注：」 在容器内使用 「exit」 退出容器时，「容器不会停止」



4. 删除镜像
「删除单个：」

docker rmi ${image_name} (or ${id})

「删除多个：」

docker rmi ${image_name}/${id} ${image_name}/${id} ...

「删除所有：」

docker rmi 「`docker images -q`」

5. 查看镜像元数据
```
docker inspect ${image_name}

docker inspect -f ='{{.NetworkSettings.IPAddress}}' ${image_name}
```

「-f」：可用 「-format」 代替



「查看最后一次运行的容器」
docker ps -l






6. 删除容器
「删除一个容器」
docker rm ${name}/${id}

「删除多个容器」
docker rm ${name1}/${id1} ${name2}/${id2} ...

「删除多个容器」
docker rm 「` docker ps -a -q`」

7. 查看容器元数据
```
docker inspect ${name}

docker inspect -f ='{{.NetworkSettings.IPAddress}}' ${name}
```

「-f」：可用 「-format」 代替
8. 查看容器日志
docker logs ${name}/${id}

9. 文件拷贝
docker cp 需要拷贝的文件或目录 容器名称:容器目录

「示例：」docker cp 1.txt c2:/root



目录挂载
目录挂载就是将宿主机的目录与容器内的努力进行映射，这样我们改变宿主机挂载目录下的内容时，容器内对应挂载目录里面的目录也会改变

「语句：」 使用 「-v」 进行挂载docker run ‐id ‐‐name=centOS1 ‐v /opt/:/usr/local centos

如果权限不足，我们应当使用：

docker run ‐id ‐‐privileged=true ‐‐name=c4 ‐v /opt/:/usr/local/myhtml centos

三、镜像制作
我们不仅仅可以从 「Docker Hub」 上拉取镜像进行创建容器，我们还可以手动定制 「docker」 系统镜像，目前构建镜像的方式有两种：

使用 docker commit 命令
使用 docker build 配合 Dockerfile 文件
1. docker commit




我们正在运行的容器提交为一个新的镜像

docker commit centOS1 cbucImage




# 「端口映射」
「步骤1」
启动容器：docker run ‐itd ‐‐name=t1 ‐p 8888:8080 cbucImage /bin/bash

「步骤2」
运行tomcat：docker exec t1 /usr/local/apache‐tomcat‐7.0.47/bin/startup.sh

这样子我们就可以通过 http://ip:port 来访问页面了





# 「Dockerfile」使用基本的基于「DSL」语法的指令来构建一个Docker镜像，之后使用「docker」「builder」命令基于该「Dockerfile」中的指令构建一个新的镜像

1）「DSL 语法」
关键词	解释
FROM	基础镜像
MAINTAINER	维护者信息
RUN	安装软件
ADD	COPY 文件，会自动解压
WORKEDIR	cd 切换工作目录
VOLUME	目录挂载
EXPOSE	内部服务端口
CMD	执行 Dockerfile 中的命令
ENV	设置环境变量
「解析：」

「1. FROM」
指定基础 「image」。必须指定且需要在「Dockerfile」其他指令的前面。后续的指令都依赖于该指令指定的「image」。「FROM」指令指定的基础image可以是官方远程仓库中的，也可以位于本地仓库。FROM命令告诉「docker」我们构建的镜像是以哪个(发行版)镜像为基础的。如果在同一个「Dockerfile」中创建多个镜像时，可以使用多个 「FROM」 指令。

「格式：」

FROM <image> 或者 FROM <image>:<tag>

「2. MAINTAINER」
指定镜像创建者信息。用于将「image」的制作者相关的信息写入到「image」中。当我们对该「image」执行「docker inspect」命令时，输出中有相应的字段记录该信息。

「格式：」

MAINTAINER <name>

「3. RUN」
安装软件使用。可以运行任何被基础image「支持的命令」。如基础「image」选择了「ubuntu」，那么软 件管理部分只能使用「ubuntu」的命令。

「格式：」

RUN <command>

「4. CMD」
设置 「container」 启动时执行的操作。该操作可以是执行自定义脚本，也可以是执行系统命令。该指令只能在文件中存在一次，如果有多个，则只执行最后一条。

「格式：」

CMD command param1 param2

「5. ENTRYPOINT」
设置「container」启动时执行的操作，可以多次设置，但是只有最后一个有效。

「格式：」ENTRYPOINT command param1 param2

「场景1：」

独自使用时，如果你还使用了「CMD」命令且「CMD」是一个完整的可执行的命令，那么「CMD」指令和「ENTRYPOINT」会互相覆盖，只有最后一个「CMD」或者「ENTRYPOINT」有效。

例：这个时候只有 「ENTRYPOINT」 会执行

CMD ls -l
ENTRYPOINT ls ‐l
「场景2：」

和「CMD」指令配合使用来指定「ENTRYPOINT」的默认参数，这时「CMD」指令不是一个完整的可执行命令，仅仅是参数部分。「ENTRYPOINT」指令只能使用「JSON」方式指定执行命令，而不能指定参数。

例：

CMD ["‐l"]
ENTRYPOINT ["/usr/bin/ls"]
「6. USER」
设置 「container」 容器的用户，默认是 「root」 用户

「格式：」

# 指定memcached的运行用户
ENTRYPOINT ["memcached"]
USER daemon
或者
ENTRYPOINT ["memcached", "‐u", "daemon"]
「7. EXPOSE」
指定容器需要映射到宿主机器的端口。当你需要访问容器的时候，可以不是用容器的「IP」地址而是使用宿主机器的「IP」地址和映射后的端口。要完成整个操作需要两个步骤，首先在Dockerfile使用「EXPOSE」设置需要映射的容器端口，然后在运行容器的时候指定 「‐p」 选项加上「EXPOSE」设置的端口，这样「EXPOSE」设置的端口号会被随机映射成宿主机器中的一个端口号。也可以指定需要映射到宿主机器的那个端口，这时要确保宿主机器上的端口号没有被使用。「EXPOSE」指令可以一次设置多个端口号，相应的运行容器的时候，可以配套的多次使用 「‐p」 选项。

「格式：」

EXPOSE <port> [<port>...]
# 映射一个端口
EXPOSE port1
# 相应的运行容器使用的命令
docker run ‐p port1 image
# 映射多个端口
EXPOSE port1 port2 port3
# 相应的运行容器使用的命令
docker run ‐p port1 ‐p port2 ‐p port3 image
# 还可以指定需要映射到宿主机器上的某个端口号
docker run ‐p host_port1:port1 ‐p host_port2:port2 ‐p host_port3:port3 image
「8. ENV」
用于设置环境变量。设置了后，后续的「RUN」命令都可以使用，「container」启动后，可以通过「docker inspect」 查看这个环境变量，也可以通过在「docker run ‐‐env key=value」时设置或修改环境变量。

「格式：」

ENV <key> <value>
# 假如你安装了JAVA程序，需要设置JAVA_HOME，那么可以在Dockerfile中这样写：
ENV JAVA_HOME /path/java/jdk
「9. ADD」
从「src」复制文件到「container」的 「dest」 路径。主要用于将宿主机中的文件添加到镜像中。

「格式：」

# <src> 是相对被构建的源目录的相对路径，可以是文件或目录的路径，也可以是一个远程的文件url; <dest> 是container中的绝对路径
ADD <src> <dest>
「10. VOLUMN」
指定挂载点。使容器中的一个目录具有持久化存储数据的功能，该目录可以被容器本身使用， 也可以共享给其他容器使用。

「格式：」

VOLUME ["<mountpoint>"]
# 例：VOLUME ["/tmp/data"]
运行通过该「Dockerfile」生成「image」的容器，「/tmp/data」目录中的数据在容器关闭后，里面的数据还存在。

「11. WORKDIR」
切换目录，可以多次切换(相当于「cd」命令)，对「RUN，CMD，ENTRYPOINT」生效。

「格式：」

WORKDIR /path/to/workdir
# 在/p1, /p2下执行vim a.txt
WORKDIR /p1 WORKDIR p2 RUN vim a.txt
「12. ONBUILD」
在子镜像中执行

「格式：」

# 指定的命令在构建镜像时并不执行，而是在它的子镜像中执行
ONBUILD <Dockerfile关键字>
2）「创建镜像」
我们编辑好 「Dockerfile」 文件后，在 「Dockerfile」 所在目录输入指令：

docker build ‐t cbucImage:v1.0.0 ‐‐rm=true .
「注：」

「‐t」 表示选择指定生成镜像的用户名，仓库名和tag

「‐‐rm=true」 表示指定在生成镜像过程中删除中间产生的临时容器。

上面构建命令中最后的 「.」 符号不要漏了，表示使用当前目录下的「Dockerfile」构建镜像

3. 运行镜像
我们创建好镜像后，便可以使用以下指令运行：

docker run ‐itd ‐‐name centos1 ‐p 8888:80 cbucImage /bin/bash
使用以下命令进入容器：

docker exec -it centos1 /bin/bash
「[END]」

#  容器互联

要让一个容器连接到另外一个容器，可以在容器通过docker create或docker run创建时通过--link选项进行配置。

例如，创建一个MySQL容器，将运行Web应用的容器连接到这个MySQL容器上，打通两个容器间的网络，实现它们之间的网络互通。

docker run -d --name mysql -e MYSQL_RANDOM_ROOT_PASSWORD=yes mysql
docker run -d --name webapp --link mysql webapp:latest


String url = "jdbc:mysql://mysql:3306/webapp";
连接地址中的mysql类似域名解析，Docker会将其指向MySQL容器的IP地址。Docker在容器互通中不再需要真实的知道另外一个容器的IP地址就能进行连接。

eltas: 100% (1726/1726), done.


端口的暴露可以通过Docker镜像进行定义，也可以在容器创建时进行定义。在容器创建时进行定义的方法是借助--expose选项。

docker run -d --name mysql -e MYSQL_RANDOM_ROOT_PASSWORD=yes --expose 13306 --expose 23306 mysql:5.7








通过--link让处于另外一个网络的容器连接到这个容器上，结果不能正常启动，Docker提醒两个容器处于不同的网络，之间不能相互连接引用。

通过--network，可以修改加入的网络，修改为individual就可以成功建立容器间的网络连接了。

docker run -d --name webapp --link mysql --network individual webapp:latest




# 用docker内部的ip 互相ping
也就是docker1的172.17.0.2 ping一下docker2的172.17.0.3 其实是ping不通的，因为他们不在同一个网络，如果想通信有没有方式，其实暴露端口的方式-p 也是可以的，还有一个更好的方式 就是通过vxlan的方式。
什么是VXLAN？
VXLAN-Virtual eXtensible Local Area Network（虚拟化可扩展局域网）
VXLAN是NVO3（Network Virtualization over Layer3）中的一种网络虚拟化技术，通过将VM或物理服务器发出的数据包封装在UDP中，并使用物理网络的IP/MAC作为报文头进行封装，然后在IP网络上传输，到达目的地后由隧道终结点解封装并将数据发送给目标虚拟机或物理服务器。
这里不讲解VXLAN啦，我也不太熟悉，现在说的分布式存储的方式来完成docker1内部的容器和docker2内部的容器之间的通信。通过的技术是：etcd的分布式存储方式来完成。
etcd的2台机器安装
随着CoreOS和Kubernetes等项目在开源社区日益火热，它们项目中都用到的etcd组件作为一个高可用、强一致性的服务发现存储仓库，渐渐为开发人员所关注。在云计算时代，如何让服务快速透明地接入到计算集群中，如何让共享配置信息快速被集群中的所有机器发现，更为重要的是，如何构建这样一套高可用、安全、易于部署以及响应快速的服务集群，已经成为了迫切需要解决的问题。etcd为解决这类问题带来了福音。
分布式主要就是为了多台机器，每个机器里面的容器分到的ip都不相同，这样让这些容器组织成一个网络的话，他们之前就可以进行通信了，因为ip和名称都是唯一的。不会带来冲突。

nohup ./etcd --name docker-node1 --initial-advertise-peer-urls http://172.28.128.3:2380 \
--listen-peer-urls http://172.28.128.3:2380 \
--listen-client-urls http://172.28.128.3:2379,http://127.0.0.1:2379 \
--advertise-client-urls http://172.28.128.3:2379 \
--initial-cluster-token etcd-cluster \
--initial-cluster docker-node1=http://172.28.128.3:2380,docker-node2=http://172.28.128.4:2380 \
--initial-cluster-state new&



nohup ./etcd --name docker-node1 --initial-advertise-peer-urls http://172.28.128.4:2380 \
--listen-peer-urls http://172.28.128.4:2380 \
--listen-client-urls http://172.28.128.4:2379,http://127.0.0.1:2379 \
--advertise-client-urls http://172.28.128.4:2379 \
--initial-cluster-token etcd-cluster \
--initial-cluster docker-node1=http://172.28.128.3:2380,docker-node2=http://172.28.128.4:2380 \
--initial-cluster-state new&


docker-node1 和 docker-node2 共同操作查看状态
./etcdctl cluster-heallth
# service docker stop


docker-node1 和docker-node2 分别操作
docker-node1
# /usr/bin/dockerd -H tcp://0.0.0.0:2375 -H unix:///var/run/docker.sock --cluster-store=etcd://172.28.128.3:2379 --cluster-advertise=172.28.128.3:2375&
exit
vagrant ssh docker-node1
# docker network ls
docker-node2
# /usr/bin/dockerd -H tcp://0.0.0.0:2375 -H unix:///var/run/docker.sock --cluster-store=etcd://172.28.128.4:2379 --cluster-advertise=172.28.128.4:2375&
exit
vagrant ssh docker-node2
# docker network ls


docker-node1
# docker network create -d overlay demo
# docker network ls
docker-node2
#docker-node1创建了overlay网络后，node2也创建了。这是为什么呢？其实这就是etcd帮咱们做的。
# docker network ls



docker-node1 查看网络信息
# docker network inspect demo





创建连接demo网络的容器
创建docker-node1内部的容器tes11t1
# docker run -d --name tes11t1--net demo busybox sh -c "while true; do sleep 3600; done"
# docker ps


创建docker-node2内部的容器tes11t1
#说有相同容器已经存在了，不允许创建。如果在同一台docker机器上不允许名称一样的，说明这2个docker-node1 和docker-node2 已经在同一个网络空间内了
# docker run -d --name tes11t1--net demo busybox sh -c "while true; do sleep 3600; done"

#更改一个名称，可以成功创建
# docker run -d --natme test111--net demo busybox sh -c "while true; do sleep 3600; done"
# docker ps




docker-node1中的容器，查看tes11t1的ip地址
# docker exec tes11t1 ip a
docker-node2中的容器，查看tes11t1的ip地址
# docker exec test111 ip a





查看下demo的network
# docker network inspect demo





试试2个容器能否互相ping通
docker-node2
# docker exec test111 ping 10.0.0.2
# docker exec test111 ping tes11t1
docker-node1

# docker exec tes11t1 ping 10.0.0.3
# docker exec tes11t1 ping test111





PS：本次通过第三方工具etcd分布式的方式完成2台机器，2个容器组件网络，实现相互的访问，这里只是通过ping的方式，如果按照上次说的 flask-redis，可以一台是redis 一台是flask 应该也是可以通信的。多机的方式基本就是这样

# 在 Linux 环境下，我们可以通过修改 /etc/docker/daemon.json ( 如果文件不存在，你可以直接创建它 ) 这个 Docker 服务的配置文件达到效果

{
    "registry-mirrors": [
        "https://registry.docker-cn.com"
    ]
}


# 挂载方式
基于底层存储实现，Docker 提供了三种适用于不同场景的文件系统挂载方式：Bind Mount、Volume 和 Tmpfs Mount



Bind Mount 能够直接将宿主操作系统中的目录和文件挂载到容器内的文件系统中，通过指定容器外的路径和容器内的路径，就可以形成挂载映射关系，在容器内外对文件的读写，都是相互可见的。
Volume 也是从宿主操作系统中挂载目录到容器内，只不过这个挂载的目录由 Docker 进行管理，我们只需要指定容器内的目录，不需要关心具体挂载到了宿主操作系统中的哪里。
Tmpfs Mount 支持挂载系统内存中的一部分到容器的文件系统里，不过由于内存和容器的特征，它的存储并不是持久的，其中的内容会随着容器的停止而消失…
8.3 挂载文件到容器
要将宿主操作系统中的目录挂载到容器之后，我们可以在容器创建的时候通过传递 -v 或 –volume 选项来指定内外挂载的对应目录或文件

# docker run -d --name nginx -v /webapp/html:/usr/share/nginx/html nginx:1.12
使用 -v或 --volume 来挂载宿主操作系统目录的形式是 -v <host-path>:<container-path> 或 --volume <host-path>:<container-path>，其中 host-path 和 container-path 分别代表宿主操作系统中的目录和容器中的目录。这里需要注意的是，为了避免混淆，Docker这里强制定义目录时必须使用绝对路径，不能使用相对路径。
我们能够指定目录进行挂载，也能够指定具体的文件来挂载，具体选择何种形式来挂载，大家可以根据具体的情况来选择。
当挂载了目录的容器启动后，我们可以看到我们在宿主操作系统中的文件已经出现在容器中了…
# docker exec nginx ls /usr/share/nginx/html
index.html
在 docker inspect 的结果里，我们可以看到有关容器数据挂载相关的信息

# docker inspect nginx
[
    {
## ......
        "Mounts": [
            {
                "Type": "bind",
                "Source": "/webapp/html",
                "Destination": "/usr/share/nginx/html",
                "Mode": "",
                "RW": true,
                "Propagation": "rprivate"
            }
        ],
## ......
    }
]...
在关于挂载的信息中我们可以看到一个 RW 字段，这表示挂载目录或文件的读写性 ( Read and Write )。实际操作中，Docker 还支持以只读的方式挂载，通过只读方式挂载的目录和文件，只能被容器中的程序读取，但不接受容器中程序修改它们的请求。在挂载选项 -v后再接上 :ro 就可以只读挂载了…

# docker run -d --name nginx -v /webapp/html:/usr/share/nginx/html:ro nginx:1.12
8.4 挂载临时文件目录
Tmpfs Mount 是一种特殊的挂载方式，它主要利用内存来存储数据。由于内存不是持久性存储设备，所以其带给 Tmpfs Mount 的特征就是临时性挂载。
与挂载宿主操作系统目录或文件不同，挂载临时文件目录要通过 --tmpfs 这个选项来完成。由于内存的具体位置不需要我们来指定，这个选项里我们只需要传递挂载到容器内的目录即可。…
# docker run -d --name webapp --tmpfs /webapp/cache webapp:latest
容器已挂载的临时文件目录我们也可以通过 docker inspect 命令查看。

# docker inspect webapp
[
    {
## ......
         "Tmpfs": {
            "/webapp/cache": ""
        },
## ......
    }
]...
挂载临时文件首先要注意它不是持久存储这一特性，在此基础上，它有几种常见的适应场景。
应用中使用到，但不需要进行持久保存的敏感数据，可以借助内存的非持久性和程序隔离性进行一定的安全保障。
读写速度要求较高，数据变化量大，但不需要持久保存的数据，可以借助内存的高读写速度减少操作的时间…
8.5 使用数据卷
除了与其他虚拟机工具近似的宿主操作系统目录挂载的功能外，Docker 还创造了数据卷 ( Volume ) 这个概念。数据卷的本质其实依然是宿主操作系统上的一个目录，只不过这个目录存放在Docker 内部，接受 Docker的管理。
在使用数据卷进行挂载时，我们不需要知道数据具体存储在了宿主操作系统的何处，只需要给定容器中的哪个目录会被挂载即可。
我们依然可以使用 -v或 --volume 选项来定义数据卷的挂载。…
# docker run -d --name webapp -v /webapp/storage webapp:latest
数据卷挂载到容器后，我们可以通过 docker inspect 看到容器中数据卷挂载的信息。

# docker inspect webapp
[
    {
## ......
        "Mounts": [
            {
                "Type": "volume",
                "Name": "2bbd2719b81fbe030e6f446243386d763ef25879ec82bb60c9be7ef7f3a25336",
                "Source": "/var/lib/docker/volumes/2bbd2719b81fbe030e6f446243386d763ef25879ec82bb60c9be7ef7f3a25336/_data",
                "Destination": "/webapp/storage",
                "Driver": "local",
                "Mode": "",
                "RW": true,
                "Propagation": ""
            }
        ],
## ......
    }
]...
这里我们所得到的信息与绑定挂载有所区别，除了 Type 中的类型不一样之外，在数据卷挂载中，我们还要关注一下Name 和 Source 这两个信息。
其中 Source 是 Docker 为我们分配用于挂载的宿主机目录，其位于 Docker 的资源区域 ( 这里是默认的/var/lib/docker ) 内。当然，我们并不需要关心这个目录，一切对它的管理都已经在 Docker内实现了。
为了方便识别数据卷，我们可以像命名容器一样为数据卷命名，这里的 Name 就是数据卷的命名。在我们未给出数据卷命名的时候，Docker会采用数据卷的 ID 命名数据卷。我们也可以通过 -v <name>:<container-path> 这种形式来命名数据卷…
# docker run -d --name webapp -v appdata:/webapp/storage webapp:latest
由于 -v 选项既承载了 Bind Mount 的定义，又参与了 Volume 的定义，所以其传参方式需要特别留意。前面提到了，-v 在定义绑定挂载时必须使用绝对路径，其目的主要是为了避免与数据卷挂载中命名这种形式的冲突。


#  runc 是一个 Linux 命令行工具，用于根据 OCI容器运行时规范 创建和运行容器。

containerd 是一个守护程序，它管理容器生命周期，提供了在一个节点上执行容器和管理镜像的最小功能集。

进程独立于宿主和其它的隔离的进程，因此也称其为容器。最初实现是基于 LXC，从 0.7 版本以后开始去除 LXC，转而使用自行开发的 libcontainer，从 1.11 开始，则进一步演进为使用 runC 和 containerd。




#
最常使用的 Registry 公开服务是官方的 Docker Hub，这也是默认的 Registry，并拥有大量的高质量的官方镜像。除此以外，还有 Red Hat 的 Quay.io；Google 的 Google Container Registry，Kubernetes 的镜像使用的就是这个服务。


#

docker run -it --network  mac_net1 --ip=100.100.100.100 --mac-address=10:10:24:10:10:10 ubuntu:16.04 /bin/bash


# A pluggable storage driver architecture
Docker has a pluggable storage driver architecture. This gives you the flexibility to "plug in" the storage driver that is best for your environment and use-case. Each Docker storage driver is based on a Linux filesystem or volume manager. Further, each storage driver is free to implement the management of image layers and the container layer in its own unique way. This means some storage drivers perform better than others in different circumstances.

Once you decide which driver is best, you set this driver on the Docker daemon at start time. As a result, the Docker daemon can only run one storage driver, and all containers created by that daemon instance use the same storage driver.



You can set the storage driver by passing the --storage-driver=<name> option to
the docker daemon command line, or by setting the option on the DOCKER_OPTS
line in the /etc/default/docker file.

$ docker daemon --storage-driver=devicemapper &
```
