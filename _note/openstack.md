---
title: OpenStack 部署和开发
date: 2014-08-21
tags: ["Offline"]
---

## Juju

如何去使用它将是一个新的挑战，如果还按照以前的模式，只是把每个虚拟机当作一台实体机器来使用的话，我们并没有充分享受到云计算带给我们的好处，所以
Juju 的出现是希望能帮助开发运维人员充分利用云计算的工具。


bluebox

    https://www.bluebox.net/

    https://www.bluebox.net/products/pricing

    https://www.bluebox.net/resources/datasheets

# Debian in Open Stack

The files here are qcow2 or raw images, ready to use.

Once you have downloaded the image, you would typically need to upload it to Glance, using a command like this one:

glance image-create --name="Debian Jessie 64-bit" \
	--disk-format=qcow2 --container-format=bare \
	--property architecture=x86_64 \
        --progress \
	--file debian-8.0.0-openstack-amd64.qcow2

Then you can boot a new virtual machine instance using the uploaded image ID.
Will the image work on another cloud platform than OpenStack?

If your platform supports the EC2 style metadata server (which is contacted by cloud-init), and also supports an HDD image (using either raw or qcow2 format), then most likely it will work. Note that it will not work on Amazon EC2 if you are not using the HVM mode.
How can I verify my download is correct and exactly what has been created by Debian?

There are files here (SHA1SUMS, SHA256SUMS, etc.) which contain checksums of the images. These checksum files are also signed - see SHA1SUMS.sign, SHA256SUMS.sign, etc. Once you've downloaded an image, you can check:

    that its checksum matches that expected from the checksum file; and
    that the checksum file has not been tampered with.

For more information about how to do these steps, read the verification guide.
Logging into the image

The default login account for this image is "debian". It is in this account that cloud-init will write the public key to allow ssh logins.



Neutron 社区每周记，里面的 Upcoming Release 有很多重要 feature 啊，我们可别重复建设，必要的时候积极跟进啊，像 native DHCP, 各种 NAT，iptables 的取代，


 HA 和 Scalability，依然是最需求的


 一个问题，ODL/OVN 这几家没有融合的可能吗？




https://docs.openstack.org/nova/zed/admin/live-migration-usage.html#top



以 Python 编程语言编写
集成 Tornado 网页服务器、Nebula 运算平台
使用 Twisted 软件框架
遵循 Open Virtualization Format、AMQP、SQLAlchemy 等标准
虚拟机软件支持包括：KVM、Xen、VirtualBox、VMware、Hyper-V


Nova 运算项目[3]
Keystone - 提供身份验证机制
Glance 虚拟机磁盘映像档（Virtual Machine Image）发送服务[4] [5]
Cinder - 提供 Block 数据访问
Neutron - 提供网络管理功能
Swift 面向对象数据存贮项目[6]
Horizon－ 提供简易 Web 界面和管理控制台[7]
Trove - 提供数据库管理功能
Sahara - 提供海量数据运算布署功能
Ceilometer - 提供计量与监控功能
Heat - 提供自动延展虚拟机功能


# Debian

cloud.debian.org/images/
 OpenStack Victoria（随 bullseye 提供）需要 cgroup v1 以用于块设备 QoS。因 bullseye 同时变更为默认使用 cgroupv2（参见 第 2.2.4 节 “控制组 v2”），在 /sys/fs/cgroup 中的 sysfs 树将不再包含 cgroup v1 的功能，如 /sys/fs/cgroup/blkio；这将导致 cgcreate -g blkio:foo 命令运行失败。对正在运行 nova-compute 或 cinder-volume 软件包的 OpenStack 节点，强烈建议将 systemd.unified_cgroup_hierarchy=false 和 systemd.legacy_systemd_cgroup_controller=false 的参数加入内核命令行中以覆盖默认配置并恢复旧有的 cgroup 层级结构。
 5.1.10. OpenStack API 策略文件

 跟随上游的建议，随 bullseye 发布的 OpenStack Victoria 将 OpenStack API 切换到了使用新的 YAML 格式。这导致大多数 OpenStack 服务，包括 Nova、Glance 和 Keystone，将无法和以 policy.json 格式文件编写的 API 策略共同工作。因此，软件包现在提供了 /etc/PROJECT/policy.d 文件夹和其中的 00_default_policy.yaml 文件，其中所有策略内容都默认处于注释状态。

 为了免旧有的 policy.json 文件处于活动状态，Debian 的 OpenStack 软件包会将该文件重命名为 disabled.policy.json.old。在某些没有更好的升级策略的场景下，升级甚至会直接删除 policy.json 文件。所以在升级系统之前，我们强烈建议您事先备份已部署机器上的 policy.json 文件。


Once you have downloaded the image, you would typically need to upload it to Glance, using a command like this one for amd64:

openstack image create \
        --container-format bare \
        --disk-format qcow2 \
        --file debian-9-openstack-amd64.qcow2 \
        debian-9-openstack-amd64

or this one for arm64:

openstack image create \
        --container-format bare \
        --disk-format qcow2 \
        --file debian-9-openstack-arm64.qcow2 \
        --property hw_firmware_type=uefi \
        --property os_command_line="console=ttyAMA0" \
        --property hw_disk_bus=scsi \
        --property hw_scsi_model=virtio-scsi \
        debian-9-openstack-arm64

Then you can boot a new virtual machine instance using the uploaded image ID.
Will the image work on another cloud platform than OpenStack?

If your platform supports the EC2 style metadata server (which is contacted by cloud-init), and also supports an HDD image (using either raw or qcow2 format), then most likely it will work. Note that it will not work on Amazon EC2 if you are not using the HVM mode.


	--file debian-8.0.0-openstack-amd64.qcow2

Then you can boot a new virtual machine instance using the uploaded image ID.
Will the image work on another cloud platform than OpenStack?

If your platform supports the EC2 style metadata server (which is contacted by cloud-init), and also supports an HDD image (using either raw or qcow2 format), then most likely it will work. Note that it will not work on Amazon EC2 if you are not using the HVM mode.
How can I verify my download is correct and exactly what has been created by Debian?

There are files here (SHA1SUMS, SHA256SUMS, etc.) which contain checksums of the images. These checksum files are also signed - see SHA1SUMS.sign, SHA256SUMS.sign, etc. Once you've downloaded an image, you can check:

    that its checksum matches that expected from the checksum file; and
    that the checksum file has not been tampered with.

For more information about how to do these steps, read the verification guide.
Logging into the image

The default login account for this image is "debian". It is in this account that cloud-init will write the public key to allow ssh logins.



Neutron 社区每周记，里面的 Upcoming Release 有很多重要 feature 啊，我们可别重复建设，必要的时候积极跟进啊，像 native DHCP, 各种 NAT，iptables 的取代，


 HA 和 Scalability，依然是最需求的


 一个问题，ODL/OVN 这几家没有融合的可能吗？

