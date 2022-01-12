---
title: virt-manager
date: 2016-12-13
---

- QEMU/KVM：底层虚拟化技术
- libvirt：提供 API 支撑及命令行客户端
- Packer：自动化安装 OS，并创建镜像
- Vagrant ：管理虚拟机
- Podman (Obsolete)
- Buildah (Obsolete)
- Skopeo (Obsolete)

## virt-manager

The virt-manager application is a desktop user interface for managing virtual machines through libvirt.

It primarily targets KVM VMs, but also manages Xen and LXC (linux containers).

It presents a summary view of running domains, their live performance & resource utilization statistics.

Wizards enable the creation of new domains, and configuration & adjustment of a domain’s resource allocation & virtual hardware. An embedded VNC and SPICE client viewer presents a full graphical console to the guest domain.

# virt-manager’s supporting tools

- virt-bootstrap is a command line tool providing an easy way to setup the root file system for libvirt-based containers.
- virt-install is a command line tool which provides an easy way to provision operating systems into virtual machines.
- virt-viewer is a lightweight UI interface for interacting with the graphical display of virtualized guest OS. It can display VNC or SPICE, and uses libvirt to lookup the graphical connection details.


