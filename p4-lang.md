---
title: p4
date: 2016-04-22
---

p4 lang



```sh

# (master) aaron@x2:~/tutorials/vm
$ vagrant up
Bringing machine 'p4-tutorial' up with 'virtualbox' provider...
==> p4-tutorial: Box 'bento/ubuntu-16.04' could not be found. Attempting to find and install...
    p4-tutorial: Box Provider: virtualbox
    p4-tutorial: Box Version: >= 0
==> p4-tutorial: Loading metadata for box 'bento/ubuntu-16.04'
    p4-tutorial: URL: https://vagrantcloud.com/bento/ubuntu-16.04
==> p4-tutorial: Adding box 'bento/ubuntu-16.04' (v202212.11.0) for provider: virtualbox
    p4-tutorial: Downloading: https://vagrantcloud.com/bento/boxes/ubuntu-16.04/versions/202212.11.0/providers/virtualbox.box
Progress: 32% (Rate: 2131k/s, Estimated time remaining: 0:02:52)

==> p4-tutorial: Successfully added box 'bento/ubuntu-16.04' (v202212.11.0) for 'virtualbox'!
==> p4-tutorial: Importing base box 'bento/ubuntu-16.04'...
==> p4-tutorial: Matching MAC address for NAT networking...
==> p4-tutorial: Checking if box 'bento/ubuntu-16.04' version '202212.11.0' is up to date...
==> p4-tutorial: Setting the name of the VM: P4 Tutorial 2023-07-10
==> p4-tutorial: Clearing any previously set network interfaces...
==> p4-tutorial: Preparing network interfaces based on configuration...
    p4-tutorial: Adapter 1: nat
==> p4-tutorial: Forwarding ports...
    p4-tutorial: 22 (guest) => 2222 (host) (adapter 1)
==> p4-tutorial: Running 'pre-boot' VM customizations...
==> p4-tutorial: Booting VM...
==> p4-tutorial: Waiting for machine to boot. This may take a few minutes...
    p4-tutorial: SSH address: 127.0.0.1:2222
    p4-tutorial: SSH username: vagrant
    p4-tutorial: SSH auth method: private key
    p4-tutorial: 
    p4-tutorial: Vagrant insecure key detected. Vagrant will automatically replace
    p4-tutorial: this with a newly generated keypair for better security.
    p4-tutorial: 
    p4-tutorial: Inserting generated public key within guest...
    p4-tutorial: Removing insecure key from the guest if it's present...
    p4-tutorial: Key inserted! Disconnecting and reconnecting using new SSH key...
==> p4-tutorial: Machine booted and ready!
==> p4-tutorial: Checking for guest additions in VM...
    p4-tutorial: The guest additions on this VM do not match the installed version of
    p4-tutorial: VirtualBox! In most cases this is fine, but in rare cases it can
    p4-tutorial: prevent things such as shared folders from working properly. If you see
    p4-tutorial: shared folder errors, please make sure the guest additions within the
    p4-tutorial: virtual machine match the version of VirtualBox you have installed on
    p4-tutorial: your host and reload your VM.
    p4-tutorial: 
    p4-tutorial: Guest Additions Version: 6.1.40
    p4-tutorial: VirtualBox Version: 7.0
==> p4-tutorial: Setting hostname...
==> p4-tutorial: Running provisioner: file...
    p4-tutorial: p4-logo.png => /home/vagrant/p4-logo.png
==> p4-tutorial: Running provisioner: file...
    p4-tutorial: p4_16-mode.el => /home/vagrant/p4_16-mode.el
==> p4-tutorial: Running provisioner: file...
    p4-tutorial: p4.vim => /home/vagrant/p4.vim
==> p4-tutorial: Running provisioner: shell...
    p4-tutorial: Running: /tmp/vagrant-shell20230710-1818-z3eisu.sh
    p4-tutorial: + DEBIAN_FRONTEND=noninteractive
    p4-tutorial: + sudo add-apt-repository -y ppa:webupd8team/sublime-text-3
    p4-tutorial: gpg: keyring `/tmp/tmp0bl07d0e/secring.gpg' created
    p4-tutorial: gpg: keyring `/tmp/tmp0bl07d0e/pubring.gpg' created


    p4-tutorial: gpg: requesting key EEA14886 from hkp server keyserver.ubuntu.com
    p4-tutorial: gpg: /tmp/tmp0bl07d0e/trustdb.gpg: trustdb created
    p4-tutorial: gpg: key EEA14886: public key "Launchpad VLC" imported
    p4-tutorial: gpg: no ultimately trusted keys found
    p4-tutorial: gpg: Total number processed: 1
    p4-tutorial: gpg:               imported: 1  (RSA: 1)
    p4-tutorial: OK
    p4-tutorial: + DEBIAN_FRONTEND=noninteractive
    p4-tutorial: + sudo add-apt-repository -y ppa:webupd8team/atom
    p4-tutorial: gpg: keyring `/tmp/tmpcs7x0sf3/secring.gpg' created
    p4-tutorial: gpg: keyring `/tmp/tmpcs7x0sf3/pubring.gpg' created
    p4-tutorial: gpg: requesting key EEA14886 from hkp server keyserver.ubuntu.com
    p4-tutorial: gpg: /tmp/tmpcs7x0sf3/trustdb.gpg: trustdb created
    p4-tutorial: gpg: key EEA14886: public key "Launchpad VLC" imported
    p4-tutorial: gpg: no ultimately trusted keys found
    p4-tutorial: gpg: Total number processed: 1
    p4-tutorial: gpg:               imported: 1  (RSA: 1)
    p4-tutorial: OK
    p4-tutorial: + apt-get update
    p4-tutorial: Get:1 http://security.ubuntu.com/ubuntu xenial-security InRelease [99.8 kB]
    p4-tutorial: Get:2 http://ppa.launchpad.net/webupd8team/atom/ubuntu xenial InRelease [17.5 kB]
    p4-tutorial: Get:3 https://esm.ubuntu.com/infra/ubuntu xenial-infra-security InRelease [7,524 B]
    p4-tutorial: Get:4 https://esm.ubuntu.com/infra/ubuntu xenial-infra-updates InRelease [7,475 B]
    p4-tutorial: Hit:5 http://archive.ubuntu.com/ubuntu xenial InRelease
    p4-tutorial: Get:6 http://archive.ubuntu.com/ubuntu xenial-updates InRelease [99.8 kB]
    p4-tutorial: Get:7 http://ppa.launchpad.net/webupd8team/sublime-text-3/ubuntu xenial InRelease [17.6 kB]
    p4-tutorial: Get:8 https://esm.ubuntu.com/infra/ubuntu xenial-infra-security/main amd64 Packages [745 kB]
    p4-tutorial: Get:9 http://security.ubuntu.com/ubuntu xenial-security/main amd64 Packages [1,648 kB]
    p4-tutorial: Get:10 https://esm.ubuntu.com/infra/ubuntu xenial-infra-security/main i386 Packages [358 kB]
    p4-tutorial: Get:11 https://esm.ubuntu.com/infra/ubuntu xenial-infra-updates/main amd64 Packages [4,746 B]
    p4-tutorial: Get:12 https://esm.ubuntu.com/infra/ubuntu xenial-infra-updates/main i386 Packages [4,750 B]
    p4-tutorial: Get:13 http://security.ubuntu.com/ubuntu xenial-security/main i386 Packages [1,160 kB]
    p4-tutorial: Get:14 http://security.ubuntu.com/ubuntu xenial-security/universe amd64 Packages [786 kB]
    p4-tutorial: Get:15 http://security.ubuntu.com/ubuntu xenial-security/universe i386 Packages [666 kB]
    p4-tutorial: Get:16 http://security.ubuntu.com/ubuntu xenial-security/universe Translation-en [226 kB]
    p4-tutorial: Get:17 http://ppa.launchpad.net/webupd8team/atom/ubuntu xenial/main amd64 Packages [624 B]
    p4-tutorial: Get:18 http://ppa.launchpad.net/webupd8team/atom/ubuntu xenial/main i386 Packages [620 B]
    p4-tutorial: Get:19 http://ppa.launchpad.net/webupd8team/atom/ubuntu xenial/main Translation-en [332 B]
    p4-tutorial: Get:20 http://ppa.launchpad.net/webupd8team/sublime-text-3/ubuntu xenial/main amd64 Packages [532 B]
    p4-tutorial: Get:21 http://ppa.launchpad.net/webupd8team/sublime-text-3/ubuntu xenial/main i386 Packages [532 B]
    p4-tutorial: Get:22 http://ppa.launchpad.net/webupd8team/sublime-text-3/ubuntu xenial/main Translation-en [276 B]
    p4-tutorial: Get:23 http://archive.ubuntu.com/ubuntu xenial-backports InRelease [97.4 kB]
    p4-tutorial: Get:24 http://archive.ubuntu.com/ubuntu xenial-updates/main amd64 Packages [2,049 kB]
    p4-tutorial: Get:25 http://archive.ubuntu.com/ubuntu xenial-updates/main i386 Packages [1,525 kB]
    p4-tutorial: Get:26 http://archive.ubuntu.com/ubuntu xenial-updates/main Translation-en [461 kB]
    p4-tutorial: Get:27 http://archive.ubuntu.com/ubuntu xenial-updates/universe amd64 Packages [1,221 kB]
    p4-tutorial: Get:28 http://archive.ubuntu.com/ubuntu xenial-updates/universe i386 Packages [1,087 kB]
    p4-tutorial: Get:29 http://archive.ubuntu.com/ubuntu xenial-updates/universe Translation-en [359 kB]
    p4-tutorial: Get:30 http://archive.ubuntu.com/ubuntu xenial-updates/multiverse amd64 Packages [21.6 kB]
    p4-tutorial: Get:31 http://archive.ubuntu.com/ubuntu xenial-updates/multiverse i386 Packages [20.4 kB]
    p4-tutorial: Get:32 http://archive.ubuntu.com/ubuntu xenial-updates/multiverse Translation-en [8,440 B]
    p4-tutorial: Fetched 12.7 MB in 2min 25s (87.3 kB/s)
    p4-tutorial: Reading package lists...
    p4-tutorial: ++ uname -r
    p4-tutorial: + KERNEL=4.4.0-210-generic
    p4-tutorial: + DEBIAN_FRONTEND=noninteractive
    p4-tutorial: + apt-get -y -o Dpkg::Options::=--force-confdef -o Dpkg::Options::=--force-confold upgrade



    p4-tutorial: Skipping profile in /etc/apparmor.d/disable: usr.sbin.rsyslogd
    p4-tutorial: + apt-get install -y --no-install-recommends --fix-missing atom autoconf automake bison build-essential ca-certificates cmake cpp curl emacs24 flex git libboost-dev libboost-filesystem-dev libboost-iostreams1.58-dev libboost-program-options-dev libboost-system-dev libboost-test-dev libboost-thread-dev libc6-dev libevent-dev libffi-dev libfl-dev libgc-dev libgc1c2 libgflags-dev libgmp-dev libgmp10 libgmpxx4ldbl libjudy-dev libpcap-dev libreadline6 libreadline6-dev libssl-dev libtool linux-headers-4.4.0-210-generic lubuntu-desktop make mktemp pkg-config python python-dev python-ipaddr python-pip python-psutil python-scapy python-setuptools sublime-text-installer tcpdump unzip vim wget xcscope-el xterm
    p4-tutorial: Reading package lists...
    p4-tutorial: Building dependency tree...
    p4-tutorial: Reading state information...
    p4-tutorial: cpp is already the newest version (4:5.3.1-1ubuntu1).
    p4-tutorial: cpp set to manually installed.
    p4-tutorial: libgmp10 is already the newest version (2:6.1.0+dfsg-2).
    p4-tutorial: libreadline6 is already the newest version (6.3-8ubuntu2).
    p4-tutorial: ca-certificates is already the newest version (20210119~16.04.1).
    p4-tutorial: curl is already the newest version (7.47.0-1ubuntu2.19).
    p4-tutorial: git is already the newest version (1:2.7.4-0ubuntu1.10).
    p4-tutorial: python is already the newest version (2.7.12-1~16.04).
    p4-tutorial: python set to manually installed.
    p4-tutorial: tcpdump is already the newest version (4.9.3-0ubuntu0.16.04.1).
    p4-tutorial: vim is already the newest version (2:7.4.1689-3ubuntu1.5).
    p4-tutorial: wget is already the newest version (1.17.1-1ubuntu1.5).
    p4-tutorial: The following additional packages will be installed:
    p4-tutorial:   abiword abiword-common adwaita-icon-theme adwaita-icon-theme-full alsa-base
    p4-tutorial:   alsa-utils alsamixergui anacron app-install-data apport-gtk aptdaemon



```

