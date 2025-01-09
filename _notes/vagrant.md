---
title: Vagrant
date: 2017-05-30
---

vagrant - Tool for building and distributing virtualized development environments

```
$ vagrant box add hahaha ~/box/precise64.box

$ vagrant init hahaha
```

Vagrant 默认是使用端口映射方式将虚拟机的端口映射本地从而实现类似 http://localhost:80 这种访问方式，这种方式比较麻烦，新开和修改端口的时候都得编辑。相比较而言，host-only 模式显得方便多了。打开 Vagrantfile，将下面这行的注释去掉（移除 #）并保存：

```
>config.vm.network :private_network, ip: "192.168.33.10"
```

重启虚拟机，这样我们就能用 192.168.33.10 访问这台机器了，你可以把 IP 改成其他地址，只要不产生冲突就行。

## 打包分发

当你配置好开发环境后，退出并关闭虚拟机。在终端里对开发环境进行打包：

```
$ vagrant package
```

打包完成后会在当前目录生成一个 package.box 的文件，将这个文件传给其他用户，其他用户只要添加这个 box 并用其初始化自己的开发目录就能得到一个一模一样的开发环境了。

## 注意事项

使用 Apache/Nginx 时会出现诸如图片修改后但页面刷新仍然是旧文件的情况，是由于静态文件缓存造成的。需要对虚拟机里的 Apache/Nginx 配置文件进行修改：

### Apache 配置添加:

```
EnableSendfile off
```

### Nginx 配置添加:

```
sendfile off;
```

## Troubleshooting

Most of the Vagrant related problems can be fixed by the following steps:

- Destroying the vagrant environment with vagrant destroy
- Killing any orphaned VMs with virtualbox UI or VBoxManage command line tool
- Cleaning the repository of build artifacts and other intermediate output with git clean -fdx
- Bringing up the vagrant environment with vagrant up

### Hash Sum mismatch issue

To avoid the annoying Hash Sum mismatch issue, due to ISP, modify the `/etc/hosts` file to map the built-in repo server to use the local mirror repo
```
LOCAL-MIRROR-IP archive.ubuntu.com
```

That's a dirty workaround, but it just works.

Now, `vagrant up` is OK.

## Local boxes

Modify `Vagrantfile` to use the local copy.

```
your_box.vm.box_url = "http://dev/ftp/box/trusty-server-cloudimg-amd64-vagrant-disk1.box"
```

## Log

```
$ mkdir box
$ cd box/
$ vagrant init xenial64
/usr/bin/vagrant:57: warning: Insecure world writable dir /home/aaron/.local in PATH, mode 040777
/usr/lib/ruby/vendor_ruby/vagrant/pre-rubygems.rb:33: warning: Insecure world writable dir /home/aaron/.local in PATH, mode 040777
/usr/lib/ruby/vendor_ruby/bundler/runtime.rb:222: warning: Insecure world writable dir /home/aaron/.local in PATH, mode 040777

A `Vagrantfile` has been placed in this directory. You are now
ready to `vagrant up` your first virtual environment! Please read
the comments in the Vagrantfile as well as documentation on
`vagrantup.com` for more information on using Vagrant.
```

$ chmod og-rxw .local/
mode of ‘.local/’ changed from 0777 (rwxrwxrwx) to 0700 (rwx------)

$ vagrant up
The provider 'virtualbox' that was requested to back the machine
'default' is reporting that it isn't usable on this system. The
reason is shown below:

Vagrant could not detect VirtualBox! Make sure VirtualBox is properly installed.
Vagrant uses the `VBoxManage` binary that ships with VirtualBox, and requires
this to be available on the PATH. If VirtualBox is installed, please find the
`VBoxManage` binary and add it to the PATH environmental variable.

$ vagrant up
VirtualBox is complaining that the installation is incomplete. Please
run `VBoxManage --version` to see the error message which should contain
instructions on how to fix this error.

$ VBoxManage --version
WARNING: The character device /dev/vboxdrv does not exist.
   Please install the virtualbox-dkms package and the appropriate
   headers, most likely linux-headers-amd64.

   You will not be able to start VMs until this problem is fixed.
5.1.6_Debianr110634
```

## Architecture

Vagrant uses "Provisioners" and "Providers" as building blocks to manage the development environments.

### Provisioners are tools that allow users to customize the configuration of virtual environments. Puppet and Chef are the two most widely used provisioners in the Vagrant ecosystem.

Vagrant ships with default support for automated provisioning. Using the automated provisioning feature, a vagrant box, i.e.a vagrant machine will automatically have a set of software's installed every time it is booted up using vagrant up. In order to preload the software, a shell script can be written and added in the vagrant file so that it runs whenever the vagrant box boots up. Vagrant will run the provisioners only on the first bootup. Hence vagrant reload --provision needs to be executed in order to instruct vagrant to reload the provisioners. For complex provisioning scripts, it may be more efficient to package a custom Vagrant box with those packages pre-installed instead of building them each time. This topic is not covered in the getting started guide, but can be found in the packaging custom boxes documentation.

Vagrant plugins also exist, including vagrant-libvirt that adds support for libvirt,[11] vagrant-lxc that adds support for lxc,

VagrantFile. This file is written using Ruby syntax, and hence the scope of customizing the box is as large as the scope of Ruby. The following activities can be performed:
* Configuration of shared folders.
* Changing permissions of files.
* Port forwarding to access the instance from a local server.
* Changing the host name of the machine.
* Setup of network configuration to access the guest virtual machine from a computer on the same network.

### Providers are the services that Vagrant uses to set up and create virtual environments. Some of the most widely used Providers are VirtualBox, Amazon AWS, VMWare, and Docker.

Vagrant sits on top of virtualization software as a wrapper and helps the developer interact easily with the providers. It automates the configuration of virtual environments using Chef or Puppet, and the user does not have to directly use any other virtualization software. Machine and software requirements are written in a file called "Vagrantfile" to execute necessary steps in order to create a development ready box. Box is a format and an extension ( .box) for Vagrant environments that is copied to another machine in order to replicate the same environment.

## Packer

Packer is free and open-source software for creating identical machine images or containers for multiple platforms from a single source configuration. It is used primarily to automate the creation of machine images which have a particular operating system and pre-installed software in it.

Packer can act as a component in a continuous integration workflow. The images that Packer creates can easily be turned into Vagrant boxes. Any updates to an image become available to the users through Vagrant cloud (a cloud service also from Hashicorp) or Atlas. The users can then update their copies of the image by running certain Vagrant commands. The Hashicorp Terraform system deployment product can use Packer as a container, and the Hashicorp Atlas workflow tool includes Vagrant, Packer, Serf, and Terraform as component tools.


## Consul is distributed peer-to-peer software that provides service discovery, health checking, and key-value stores for services running in a cluster of compute resources.

### Architecture
The basic architecture is based off a Consul Agent, Consul Client, Consul Server, Datacenters, a Consensus protocol, Gossip protocols, and RPC.
* Agent - An agent is the long running daemon on every member of the Consul cluster. It is started by running consul agent. The agent is able to run in eitherclient or server mode. Since all nodes must be running an agent, it is simpler to refer to the node as being either a client or server, but there are other instances of the agent. All agents can run the DNS or HTTP interfaces, and are responsible for running checks and keeping services in sync.
* Client - A client is an agent that forwards all RPCs to a server. The client is relatively stateless. The only background activity a client performs is taking part in the LAN gossip pool. This has a minimal resource overhead and consumes only a small amount of network bandwidth.
* Server - A server is an agent with an expanded set of responsibilities including participating in the Raft quorum, maintaining cluster state, responding to RPC queries, exchanging WAN gossip with other datacenters, and forwarding queries to leaders or remote datacenters.
* Datacenter - While the definition of a datacenter seems obvious, there are subtle details that must be considered. For example, in EC2, are multiple availability zones considered to comprise a single datacenter? We define a datacenter to be a networking environment that is private, low latency, and high bandwidth. This excludes communication that would traverse the public internet, but for our purposes multiple availability zones within a single EC2 region would be considered part of a single datacenter.
* Consensus - When used in our documentation we use consensus to mean agreement upon the elected leader as well as agreement on the ordering of transactions. Since these transactions are applied to a finite-state machine, our definition of consensus implies the consistency of a replicated state machine.
* Gossip - Consul is built on top of Serf which provides a full gossip protocol that is used for multiple purposes. Serf provides membership, failure detection, and event broadcast. Our use of these is described more in the gossip documentation. It is enough to know that gossip involves random node-to-node communication, primarily over UDP.
  * LAN Gossip - Refers to the LAN gossip pool which contains nodes that are all located on the same local area network or datacenter.
  * WAN Gossip - Refers to the WAN gossip pool which contains only servers. These servers are primarily located in different datacenters and over the internet or wide area network.
  * RPC - Remote Procedure Call. This is a request / response mechanism allowing a client to make a request of a server.

### Health Checks

Consul provides a way to implement health checks of programs (services) running on the cluster. There are five different kinds of checks:[5]
* Script - These checks depend on invoking an external application that performs the health check, exits with an appropriate exit code, and potentially generates some output.
* HTTP - These checks make an HTTP GET request every Interval (e.g. every 30 seconds) to the specified URL. The status of the service depends on the HTTP response code: any 2xx code is considered passing, a 429 Too Many Requests is a warning, and anything else is a failure.
* TCP - These checks make an TCP connection attempt every Interval (e.g. every 30 seconds) to the specified IP/hostname and port.
* Time To Live (TTL) - These checks retain their last known state for a given TTL.
* Docker - These checks depend on invoking an external application which is packaged within a Docker Container.

```
$ vagrant init hashicorp/precise64
A `Vagrantfile` has been placed in this directory. You are now
ready to `vagrant up` your first virtual environment! Please read
the comments in the Vagrantfile as well as documentation on
`vagrantup.com` for more information on using Vagrant.

$ vagrant up
Bringing machine 'default' up with 'virtualbox' provider...
==> default: Box 'hashicorp/precise64' could not be found. Attempting to find and install...
    default: Box Provider: virtualbox
    default: Box Version: >= 0
==> default: Loading metadata for box 'hashicorp/precise64'
    default: URL: https://vagrantcloud.com/hashicorp/precise64
==> default: Adding box 'hashicorp/precise64' (v1.1.0) for provider: virtualbox
    default: Downloading: https://vagrantcloud.com/hashicorp/boxes/precise64/versions/1.1.0/providers/virtualbox.box
==> default: Successfully added box 'hashicorp/precise64' (v1.1.0) for 'virtualbox'!
==> default: Importing base box 'hashicorp/precise64'...
==> default: Matching MAC address for NAT networking...
==> default: Checking if box 'hashicorp/precise64' is up to date...
==> default: Setting the name of the VM: acip_default_1542772461950_37697
Vagrant is currently configured to create VirtualBox synced folders with
the `SharedFoldersEnableSymlinksCreate` option enabled. If the Vagrant
guest is not trusted, you may want to disable this option. For more
information on this option, please refer to the VirtualBox manual:

  https://www.virtualbox.org/manual/ch04.html#sharedfolders

This option can be disabled globally with an environment variable:

  VAGRANT_DISABLE_VBOXSYMLINKCREATE=1

or on a per folder basis within the Vagrantfile:

  config.vm.synced_folder '/host/path', '/guest/path', SharedFoldersEnableSymlinksCreate: false
==> default: Clearing any previously set network interfaces...
==> default: Preparing network interfaces based on configuration...
    default: Adapter 1: nat
==> default: Forwarding ports...
    default: 22 (guest) => 2222 (host) (adapter 1)
==> default: Booting VM...
==> default: Waiting for machine to boot. This may take a few minutes...
    default: SSH address: 127.0.0.1:2222
    default: SSH username: vagrant
    default: SSH auth method: private key
    default:
    default: Vagrant insecure key detected. Vagrant will automatically replace
    default: this with a newly generated keypair for better security.
    default:
    default: Inserting generated public key within guest...
    default: Removing insecure key from the guest if it's present...
    default: Key inserted! Disconnecting and reconnecting using new SSH key...
==> default: Machine booted and ready!
==> default: Checking for guest additions in VM...
    default: The guest additions on this VM do not match the installed version of
    default: VirtualBox! In most cases this is fine, but in rare cases it can
    default: prevent things such as shared folders from working properly. If you see
    default: shared folder errors, please make sure the guest additions within the
    default: virtual machine match the version of VirtualBox you have installed on
    default: your host and reload your VM.
    default:
    default: Guest Additions Version: 4.2.0
    default: VirtualBox Version: 5.2
==> default: Mounting shared folders...
    default: /vagrant => /home/aaron/acip

$ vagrant up
Bringing machine 'default' up with 'virtualbox' provider...
==> default: Checking if box 'hashicorp/precise64' is up to date...
==> default: Machine already provisioned. Run `vagrant provision` or use the `--provision`
==> default: flag to force provisioning. Provisioners marked to run always will still run.

$ vagrant ssh

$ vagrant destroy
    default: Are you sure you want to destroy the 'default' VM? [y/N] y
==> default: Forcing shutdown of VM...
==> default: Destroying VM and associated drives...

> The vagrant destroy command does not actually remove the downloaded box file. To completely remove the box file, you can use the vagrant box remove command.

$ vagrant reload --provision
==> default: Attempting graceful shutdown of VM...
==> default: Checking if box 'geerlingguy/ubuntu1604' is up to date...
==> default: Clearing any previously set forwarded ports...
==> default: Fixed port collision for 22 => 2222. Now on port 2200.
==> default: Clearing any previously set network interfaces...
==> default: Preparing network interfaces based on configuration...
    default: Adapter 1: nat
==> default: Forwarding ports...
    default: 80 (guest) => 4567 (host) (adapter 1)
    default: 22 (guest) => 2200 (host) (adapter 1)
==> default: Booting VM...
==> default: Waiting for machine to boot. This may take a few minutes...
    default: SSH address: 127.0.0.1:2200
    default: SSH username: vagrant
    default: SSH auth method: private key
==> default: Machine booted and ready!
==> default: Checking for guest additions in VM...
==> default: Mounting shared folders...
    default: /vagrant => /home/aaron/geerlingguy
==> default: Running provisioner: shell...
    default: Running: /tmp/vagrant-shell20181122-25975-i6nwf3.sh
    default: Hit:1 http://us.archive.ubuntu.com/ubuntu bionic InRelease
    default: Get:2 http://us.archive.ubuntu.com/ubuntu bionic-updates InRelease [88.7 kB]
    default: Get:3 http://security.ubuntu.com/ubuntu bionic-security InRelease [83.2 kB]
    default: Get:4 http://us.archive.ubuntu.com/ubuntu bionic-backports InRelease [74.6 kB]
    default: Fetched 247 kB in 3s (93.5 kB/s)
    default: Reading package lists...
    default: Reading package lists...
    default: Building dependency tree...
    default: Reading state information...
    default: The following additional packages will be installed:
    default:   apache2-bin apache2-data apache2-utils libapr1 libaprutil1
    default:   libaprutil1-dbd-sqlite3 libaprutil1-ldap liblua5.2-0 ssl-cert
    default: Suggested packages:
    default:   www-browser apache2-doc apache2-suexec-pristine | apache2-suexec-custom
    default:   openssl-blacklist
    default: The following NEW packages will be installed:
    default:   apache2 apache2-bin apache2-data apache2-utils libapr1 libaprutil1
    default:   libaprutil1-dbd-sqlite3 libaprutil1-ldap liblua5.2-0 ssl-cert
    default: 0 upgraded, 10 newly installed, 0 to remove and 0 not upgraded.
    default: Need to get 1,730 kB of archives.
    default: After this operation, 6,985 kB of additional disk space will be used.
    default: Get:1 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 libapr1 amd64 1.6.3-2 [90.9 kB]
    default: Get:2 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 libaprutil1 amd64 1.6.1-2 [84.4 kB]
    default: Get:3 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 libaprutil1-dbd-sqlite3 amd64 1.6.1-2 [10.6 kB]
    default: Get:4 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 libaprutil1-ldap amd64 1.6.1-2 [8,764 B]
    default: Get:5 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 liblua5.2-0 amd64 5.2.4-1.1build1 [108 kB]
    default: Get:6 http://us.archive.ubuntu.com/ubuntu bionic-updates/main amd64 apache2-bin amd64 2.4.29-1ubuntu4.4 [1,071 kB]
    default: Get:7 http://us.archive.ubuntu.com/ubuntu bionic-updates/main amd64 apache2-utils amd64 2.4.29-1ubuntu4.4 [83.5 kB]
    default: Get:8 http://us.archive.ubuntu.com/ubuntu bionic-updates/main amd64 apache2-data all 2.4.29-1ubuntu4.4 [160 kB]
    default: Get:9 http://us.archive.ubuntu.com/ubuntu bionic-updates/main amd64 apache2 amd64 2.4.29-1ubuntu4.4 [95.1 kB]
    default: Get:10 http://us.archive.ubuntu.com/ubuntu bionic/main amd64 ssl-cert all 1.0.39 [17.0 kB]
    default: dpkg-preconfigure: unable to re-open stdin: No such file or directory
    default: Fetched 1,730 kB in 3s (665 kB/s)
    default: Selecting previously unselected package libapr1:amd64.
    default: (Reading database ...
    default: (Reading database ... 5%
    default: (Reading database ... 10%
    default: (Reading database ... 15%
    default: (Reading database ... 20%
    default: (Reading database ... 25%
    default: (Reading database ... 30%
    default: (Reading database ... 35%
    default: (Reading database ... 40%
    default: (Reading database ... 45%
    default: (Reading database ... 50%
    default: (Reading database ... 55%
    default: (Reading database ... 60%
    default: (Reading database ... 65%
    default: (Reading database ... 70%
    default: (Reading database ... 75%
    default: (Reading database ... 80%
    default: (Reading database ... 85%
    default: (Reading database ... 90%
    default: (Reading database ... 95%
    default: (Reading database ... 100%
    default: (Reading database ...
    default: 70845 files and directories currently installed.)
    default: Preparing to unpack .../0-libapr1_1.6.3-2_amd64.deb ...
    default: Unpacking libapr1:amd64 (1.6.3-2) ...
    default: Selecting previously unselected package libaprutil1:amd64.
    default: Preparing to unpack .../1-libaprutil1_1.6.1-2_amd64.deb ...
    default: Unpacking libaprutil1:amd64 (1.6.1-2) ...
    default: Selecting previously unselected package libaprutil1-dbd-sqlite3:amd64.
    default: Preparing to unpack .../2-libaprutil1-dbd-sqlite3_1.6.1-2_amd64.deb ...
    default: Unpacking libaprutil1-dbd-sqlite3:amd64 (1.6.1-2) ...
    default: Selecting previously unselected package libaprutil1-ldap:amd64.
    default: Preparing to unpack .../3-libaprutil1-ldap_1.6.1-2_amd64.deb ...
    default: Unpacking libaprutil1-ldap:amd64 (1.6.1-2) ...
    default: Selecting previously unselected package liblua5.2-0:amd64.
    default: Preparing to unpack .../4-liblua5.2-0_5.2.4-1.1build1_amd64.deb ...
    default: Unpacking liblua5.2-0:amd64 (5.2.4-1.1build1) ...
    default: Selecting previously unselected package apache2-bin.
    default: Preparing to unpack .../5-apache2-bin_2.4.29-1ubuntu4.4_amd64.deb ...
    default: Unpacking apache2-bin (2.4.29-1ubuntu4.4) ...
    default: Selecting previously unselected package apache2-utils.
    default: Preparing to unpack .../6-apache2-utils_2.4.29-1ubuntu4.4_amd64.deb ...
    default: Unpacking apache2-utils (2.4.29-1ubuntu4.4) ...
    default: Selecting previously unselected package apache2-data.
    default: Preparing to unpack .../7-apache2-data_2.4.29-1ubuntu4.4_all.deb ...
    default: Unpacking apache2-data (2.4.29-1ubuntu4.4) ...
    default: Selecting previously unselected package apache2.
    default: Preparing to unpack .../8-apache2_2.4.29-1ubuntu4.4_amd64.deb ...
    default: Unpacking apache2 (2.4.29-1ubuntu4.4) ...
    default: Selecting previously unselected package ssl-cert.
    default: Preparing to unpack .../9-ssl-cert_1.0.39_all.deb ...
    default: Unpacking ssl-cert (1.0.39) ...
    default: Setting up libapr1:amd64 (1.6.3-2) ...
    default: Processing triggers for ufw (0.35-5) ...
    default: Processing triggers for ureadahead (0.100.0-20) ...
    default: Setting up apache2-data (2.4.29-1ubuntu4.4) ...
    default: Setting up ssl-cert (1.0.39) ...
    default: Processing triggers for libc-bin (2.27-3ubuntu1) ...
    default: Setting up libaprutil1:amd64 (1.6.1-2) ...
    default: Processing triggers for systemd (237-3ubuntu10.9) ...
    default: Processing triggers for man-db (2.8.3-2ubuntu0.1) ...
    default: Setting up liblua5.2-0:amd64 (5.2.4-1.1build1) ...
    default: Setting up libaprutil1-ldap:amd64 (1.6.1-2) ...
    default: Setting up libaprutil1-dbd-sqlite3:amd64 (1.6.1-2) ...
    default: Setting up apache2-utils (2.4.29-1ubuntu4.4) ...
    default: Setting up apache2-bin (2.4.29-1ubuntu4.4) ...
    default: Setting up apache2 (2.4.29-1ubuntu4.4) ...
    default: Enabling module mpm_event.
    default: Enabling module authz_core.
    default: Enabling module authz_host.
    default: Enabling module authn_core.
    default: Enabling module auth_basic.
    default: Enabling module access_compat.
    default: Enabling module authn_file.
    default: Enabling module authz_user.
    default: Enabling module alias.
    default: Enabling module dir.
    default: Enabling module autoindex.
    default: Enabling module env.
    default: Enabling module mime.
    default: Enabling module negotiation.
    default: Enabling module setenvif.
    default: Enabling module filter.
    default: Enabling module deflate.
    default: Enabling module status.
    default: Enabling module reqtimeout.
    default: Enabling conf charset.
    default: Enabling conf localized-error-pages.
    default: Enabling conf other-vhosts-access-log.
    default: Enabling conf security.
    default: Enabling conf serve-cgi-bin.
    default: Enabling site 000-default.
    default: Created symlink /etc/systemd/system/multi-user.target.wants/apache2.service -> /lib/systemd/system/apache2.service.
    default: Created symlink /etc/systemd/system/multi-user.target.wants/apache-htcacheclean.service -> /lib/systemd/system/apache-htcacheclean.service.
    default: Processing triggers for libc-bin (2.27-3ubuntu1) ...
    default: Processing triggers for ureadahead (0.100.0-20) ...
    default: Processing triggers for systemd (237-3ubuntu10.9) ...
    default: Processing triggers for ufw (0.35-5) ...
```

## kali-vagrant

### Setup

First, install [packer](https://www.packer.io/) and [VirtualBox](https://www.virtualbox.org/).

On Kali Linux, this can be accomplished by running
```
apt install packer virtualbox virtuabox-ext-pack
```

Then `cp kali-vars.json.template kali-vars.json` and fill the values.

### Running the build

```
packer build -var-file=kali-vars.json config.json
```

This will upload to the Vagrant cloud.
To avoid doing that and keeping the build local, remove the `vagrant-cloud` post-processor from the config file.

### Running the build (headless)

To run headless builds, you will need to ensure you have the Extension Pack installed and then edit the config.json file to add
```
"headless": "1",
```
In the `"builders"` section before `"boot_command"`

### kali-light

To build kali-light, it is possible to simply replace the variables inside `kali-vars.json`.
The `kali-light-vars.json.template` file is only provided as convenience for building the 2 versions without having to change the var file between the builds.

## Vagrant HOST Steps

The following steps are preformed on the *host* that runs Vagrant.

### Installing Vagrant and Downloading Armbian

#### Virtualbox Version

**WARNING:** We'll be using [Virtualbox as a virtualization provider for Vagrant](https://www.vagrantup.com/docs/virtualbox/). Virtualbox has [documented issues running Xenial under heavy disk IO](https://bugs.launchpad.net/cloud-images/+bug/1616794). Please make sure your version of Virtualbox is >= 5.1.12 where the issue, ["Storage: fixed a problem with the LsiLogic SCSI controller where requests could be lost with SMP guests"](https://www.virtualbox.org/wiki/Changelog), appears to have been resolved.

```
vagrant plugin install vagrant-disksize
```

Now we'll need to [install git](https://git-scm.com/downloads) and clone the Armbian repo. While this might seem obvious, we rely on it being there when we use Vagrant to bring up our guest-build box.

```
$ git clone --depth 1 https://github.com/armbian/build

$ vagrant box add ubuntu/xenial64

$ vagrant box update
```

### Armbian Directory Structure

Before we bring up the box, take note of the [directory structure]( https://docs.armbian.com/Developer-Guide_Build-Process/#directory-structure) used by the Armbian build tool. When you read the Vagrantfile you'll see that Vagrant will mount local *output* and *userpatches* directories. This is helpful as it enables you to easily retrieve your images from the host once built, and [customize the build process](https://docs.armbian.com/Developer-Guide_User-Configurations/).

### Creating the Vagrant Guest Box Used to Build
Let's bring the box up. This might take a minute or two depending on your bandwidth and hardware.

	# We have to be in the same directory as the Vagrant file.
	cd build

	# And now we simply let vagrant create our box and bring it up.
	vagrant up

	# When the box has been installed we can get access via ssh.
	# (No need for passwords, Vagrant installs the keys we'll need.)
	vagrant ssh

## Important note

It is strongly recommended to halt and restart the Vagrant box after building an image. Check [this](https://github.com/armbian/build/issues/751) issue for details.

## Vagrant GUEST Steps

The following steps are all run on the *guest* Vagrant created for us.

Once it's finally up and you're logged in, it works much like any of the other install methods (NOTE: again, these commands are run on the *guest* box).

	# Let's get building!
	cd build
	sudo ./compile.sh

## More Vagrant HOST Steps

Wrap up your vagrant box when no longer needed (log out of the guest before running these commands on the *host* system):

	# Shutdown, but leave the box around for more building at a later time:
	vagrant halt

	# Trash the box and remove all the related storage devices.
	vagrant destroy

```
$ cd vagrant-machine/

$ vagrant up
Bringing machine 'default' up with 'virtualbox' provider...
==> default: Box 'debian/buster64' could not be found. Attempting to find and install...
    default: Box Provider: virtualbox
    default: Box Version: >= 0
==> default: Loading metadata for box 'debian/buster64'
    default: URL: https://vagrantcloud.com/debian/buster64
==> default: Adding box 'debian/buster64' (v10.20211018.1) for provider: virtualbox
    default: Downloading: https://vagrantcloud.com/debian/boxes/buster64/versions/10.20211018.1/providers/virtualbox.box
Download redirected to host: vagrantcloud-files-production.s3-accelerate.amazonaws.com
==> default: Successfully added box 'debian/buster64' (v10.20211018.1) for 'virtualbox'!
==> default: Importing base box 'debian/buster64'...
==> default: Matching MAC address for NAT networking...
==> default: Checking if box 'debian/buster64' version '10.20211018.1' is up to date...
==> default: Setting the name of the VM: vagrant-machine_default_1636953380753_32641
==> default: Clearing any previously set network interfaces...
==> default: Preparing network interfaces based on configuration...
    default: Adapter 1: nat
==> default: Forwarding ports...
    default: 22 (guest) => 2222 (host) (adapter 1)
==> default: Booting VM...
==> default: Waiting for machine to boot. This may take a few minutes...
    default: SSH address: 127.0.0.1:2222
    default: SSH username: vagrant
    default: SSH auth method: private key
    default:
    default: Vagrant insecure key detected. Vagrant will automatically replace
    default: this with a newly generated keypair for better security.
    default:
    default: Inserting generated public key within guest...
    default: Removing insecure key from the guest if it's present...
    default: Key inserted! Disconnecting and reconnecting using new SSH key...
==> default: Machine booted and ready!
==> default: Checking for guest additions in VM...
    default: The guest additions on this VM do not match the installed version of
    default: VirtualBox! In most cases this is fine, but in rare cases it can
    default: prevent things such as shared folders from working properly. If you see
    default: shared folder errors, please make sure the guest additions within the
    default: virtual machine match the version of VirtualBox you have installed on
    default: your host and reload your VM.
    default:
    default: Guest Additions Version: 5.2.0 r68940
    default: VirtualBox Version: 6.1
==> default: Installing rsync to the VM...
The following SSH command responded with a non-zero exit status.
Vagrant assumes that this means the command failed!

            apt-get -yqq update
            apt-get -yqq install rsync

Stdout from the command:

Stderr from the command:

W: Failed to fetch http://security.debian.org/debian-security/dists/buster/updates/main/i18n/Translation-en  Cannot initiate the connection to security.debian.org:80 (2a04:4e42::644). - connect (101: Network is unreachable) Cannot initiate the connection to security.debian.org:80 (2a04:4e42:200::644). - connect (101: Network is unreachable) Cannot initiate the connection to security.debian.org:80 (2a04:4e42:400::644). - connect (101: Network is unreachable) Cannot initiate the connection to security.debian.org:80 (2a04:4e42:600::644). - connect (101: Network is unreachable) [IP: 151.101.2.132 80]
W: Failed to fetch http://deb.debian.org/debian/dists/buster/main/i18n/Translation-en  Cannot initiate the connection to deb.debian.org:80 (2a04:4e42:11::644). - connect (101: Network is unreachable) [IP: 151.101.74.132 80]
W: Failed to fetch http://deb.debian.org/debian/dists/buster-updates/main/i18n/Translation-en  Cannot initiate the connection to deb.debian.org:80 (2a04:4e42:11::644). - connect (101: Network is unreachable) [IP: 151.101.74.132 80]
W: Failed to fetch http://deb.debian.org/debian/dists/buster-backports/main/source/Sources  Cannot initiate the connection to deb.debian.org:80 (2a04:4e42:11::644). - connect (101: Network is unreachable) [IP: 151.101.74.132 80]
W: Failed to fetch http://deb.debian.org/debian/dists/buster-backports/main/binary-amd64/Packages  Cannot initiate the connection to deb.debian.org:80 (2a04:4e42:11::644). - connect (101: Network is unreachable) [IP: 151.101.74.132 80]
W: Failed to fetch http://deb.debian.org/debian/dists/buster-backports/main/i18n/Translation-en  Cannot initiate the connection to deb.debian.org:80 (2a04:4e42:11::644). - connect (101: Network is unreachable) [IP: 151.101.74.132 80]
W: Some index files failed to download. They have been ignored, or old ones used instead.
E: Unable to locate package rsync
```

```
$ vagrant ssh
Linux buster 4.19.0-18-amd64 #1 SMP Debian 4.19.208-1 (2021-09-29) x86_64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
-bash: warning: setlocale: LC_ALL: cannot change locale (en_US.UTF-8)
vagrant@buster:~$
```

- vagrant init: creates a vagrant configuration file (Vagrantfile) which will be read to initialize the vagrant machine to setup. The file contains the box on which the machine should be based on, the cpu, networking, etc
- vagrant up: downloads or imports the box to run the vagrant machine. It will read the content of the Vagrantfile and executes line in order to set up the machine according to the environment that is specified in the file
- vagrant ssh: by default it helps you to access your vagrant machine but unlike the normal ssh command, you have to be in the current folder where your machine (Vagrantfile) is stored. When you want to leave the vagrant machine, just use the exit command to return to the host
- vagrant suspend: to suspend the vagrant machine
- vagrant resume: to resume a vagrant machine which has been suspended
- vagrant halt: to stop a vagrant machine like the shutdown. But you can use the linux shutdown command inside the vagrant machine to stop it also as it works like a normal machine.
- vagrant reload: helps to stop and start your vagrant machine like a restart but it will not read again the new instructions that you provided in the Vagrantfile
- vagrant destroy: this command will stop the vagrant machine and destroy all the configuration that you did
- vagrant status: it gives you the state of the current vagrant machine, if it's running, stopped or suspended.

Now it will be also useful for your to know the vagrant command which will help you to operate on your boxes.
- vagrant box add: helps to download the box specified after the command. The box will be stored in the default folder ~/.vagrant.d
- vagrant box list: shows you a list of all the boxes that you have downloaded
- vagrant box update: updates the box of the current vagrant machine. If you want to update a specific box without being in folder of the vagrant machine, use the --box followed by the name of the box
- vagrant box remove: deletes the specified box following the command

```
$ vagrant box add centos/7
==> box: Loading metadata for box 'centos/7'
    box: URL: https://vagrantcloud.com/centos/7
This box can work with multiple providers! The providers that it
can work with are listed below. Please review the list and choose
the provider you will be working with.
1) hyperv
2) libvirt
3) virtualbox
4) vmware_desktop
Enter your choice: 3
==> box: Adding box 'centos/7' (v1902.01) for provider: virtualbox
    box: Downloading: https://vagrantcloud.com/centos/boxes/7/versions/1902.01/providers/virtualbox.box
During the process it will download and store the boxes in the default folder ~/.vagrant.d. You can use the same command to download the others boxes that you can need from the official link
Now let us try to run the vagrant machine based on centos 7. First let’s create a directory and initialize our machine
$ mkdir centos7 && cd centos7
$ vagrant init centos/7
A `Vagrantfile` has been placed in this directory. You are now
ready to `vagrant up` your first virtual environment! Please read
the comments in the Vagrantfile as well as documentation on
`vagrantup.com` for more information on using Vagrant.
Now let’s run the machine,

$ vagrant up
Bringing machine 'default' up with 'virtualbox' provider...
==> default: Importing base box 'centos/7'...
==> default: Matching MAC address for NAT networking...
==> default: Checking if box 'centos/7' version '1902.01' is up to date...
==> default: Setting the name of the VM: centos7_default_1553955605013_87107
==> default: Fixed port collision for 22 => 2222. Now on port 2200.
....
....
==> default: Machine booted and ready!
....
```

# Trouble shooting

```
config.vm.box = “ubuntu/bionic64”: box setting, it’s as the template of the box to use.
config.vm.box_check_update = false: to enable or disable the fact that vagrant should check if the box is up to date
config.vm.network “forwarded_port”, guest: 80, host: 8080: configure the port forwarding between the guest and the host. This means that a web application on the port 80 of your vagrant machine is accessible through the port 8080 of your physical machine.
config.vm.network “private_network”, ip: “192.168.33.10”: to create a private network for the vagrant machine with a host-only access.
config.vm.network “public_network”: creates public network working as a bridged so that you vagrant-machine will work as an independent node of the network
config.vm.synced_folder “../data”, “/vagrant_data”: works like shared folders, so there is the possibility to synchronize a folder in your vagrant machine and a folder of your physical machine like sharing a folder between the guest and the host
config.vm.provider “virtualbox” do |vb|…end: this is the block of information for the provider that your vagrant machine is using. Most of the time it’s useful for graphical debug if an error occurs when you start your vagrant machine
config.vm.provision “shell”, inline: <<-SHELL…end: this block defines the provision method (automation tool) that you want to use to automate some process on your vagrant machine during the boot. The provision method used here is the shell. You can use another provision method like chef, ansible, etc.
```

try our docker-compose repo: https://github.com/zammad/zammad-docker-compose

See the docs @ https://docs.zammad.org/en/latest/contributing-install-vagrant.html

* [Automating the Setup of the Local Developer Machine](https://www.red-gate.com/simple-talk/sysadmin/general/automating-setup-local-developer-machine/)


* https://stackoverflow.com/questions/31644222/vagrant-not-starting-up-user-that-created-vm-doesnt-match-current-user

## Basic operations

```
$ vagrant up
$ vagrant halt
$ vagrant destroy


$ vagrant ssh prod
Welcome to Ubuntu 14.04.5 LTS (GNU/Linux 3.13.0-98-generic x86_64)

 * Documentation:  https://help.ubuntu.com/

  System information as of Thu Oct 13 03:02:33 UTC 2016

  System load:  0.0               Processes:           75
  Usage of /:   3.7% of 39.34GB   Users logged in:     0
  Memory usage: 7%                IP address for eth0: 10.0.2.15
  Swap usage:   0%                IP address for eth1: 10.100.198.201

  Graph this data and manage this system at:
    https://landscape.canonical.com/

  Get cloud support with Ubuntu Advantage Cloud Guest:
    http://www.ubuntu.com/business/services/cloud

0 packages can be updated.
0 updates are security updates.


Last login: Thu Oct 13 03:02:35 2016 from 10.0.2.2
vagrant@prod:~$
```

