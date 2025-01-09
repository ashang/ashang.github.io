

DENT Project dentOS

dentOS is a SwitchDev based NOS built on top of Open Network Linux

container-id

python2
# -*- python -*-

import re
import sys

for line in open('/proc/self/cgroup').readlines():
    m = re.search(r'docker-(?P<id>[0-9a-f]{64})', line)
    if m:
        print m.group('id')[0:12]
        sys.exit(0)

sys.exit(1)





## build ONL behind an HTTP Proxy

Many corporate environments don't provide native access to the Internet and instead all access must go through an HTTP proxy. Since the ONL build process dynamically pulls lots of things, this can be a pain. While everyone's setup is different, hopefully these directions help reduce that pain.

    Make sure you have apt-cacher-ng installed in your host (non-docker) environment and that docker starts it. Next, configure it to use your proxy:

    $ grep Proxy /etc/apt-cacher-ng/acng.conf
    Proxy: http://myproxy.mycompany.com:8080
    $ sudo /etc/init.d/apt-cacher-ng restart

Make sure your git config is configured correctly for proxies:

$ cat ~/.gitconfig
[https]
     proxy = myproxy.mycompany.com:8080
[https]
     proxy = myproxy.mycompany.com:8080



## 
ONL is a part of the Open Compute Project and is a component in a growing number of commercial NOS stacks and open source projects like CoRD & Stratum





Open Network Linux
C/O Big Switch Networks
3111 Coronado Drive
Santa Clara, CA 95054






##




The DENT project, an open source network operating system utilizing the Linux Kernel, Switchdev

`

https://dent.dev/announcements/2023/04/18/dent-network-operating-system-collaborates-with-ocp-to-integrate-switch-abstraction-interface-sai/


Industry Support




Edgecore

“We are glad to see the Linux Foundation collaborating with OCP to help grow the marketplace for DENT switch platforms. Edgecore Networks will be able to promote the open platforms that we have contributed to OCP to a wider market.” said name, title, Edgecore Networks.



Ecosystem Support for DentOS 3.0:


“We are pleased to be part of DENT’s third major release, bringing even more features that enable more streamlined operations across multiple devices at the edge,” said Larry Ho, VP of Software Engineering at Edgecore. “DENT has established a strong foundational platform for Linux and open source based network operations that is only possible via collaborative development.” 



### 


ONIE:/ # scp admin@10.10.50.22:/tmp/DENTOS-HEAD_ONL-OS9_2023-06-22.2143-d97c46b_
AMD64_INSTALLED_INSTALLER .

Host '10.10.50.22' is not in the trusted hosts file.
(ecdsa-sha2-nistp256 fingerprint md5 a4:ad:2f:98:83:e0:7b:0d:9d:14:16:1a:b2:88:db:e6)
Do you want to continue connecting? (y/n) y
admin@10.10.50.22's password:
Could not chdir to home directory /disk/build: Permission denied
bash: /disk/build/.bashrc: Permission denied
DENTOS-HEAD_ONL-OS9_2023-06-22.2143-d97c46b_A 100%  246MB  20.5MB/s   00:12
ONIE:/ # onie-nos-install DENTOS-HEAD_ONL-OS9_2023-06-22.2143-d97c46b_AMD64_INST
ALLED_INSTALLER
discover: Rescue mode detected. No discover stopped.
ONIE: Executing installer: DENTOS-HEAD_ONL-OS9_2023-06-22.2143-d97c46b_AMD64_INSTALLED_INSTALLER
installer: computing checksum of original archive
installer: checksum is OK
installer: extracting pad
1+0 records in
1+0 records out
512 bytes (512B) copied, 0.000014 seconds, 34.9MB/s
installer: copying file before resetting pad
installer: resetting pad
1+0 records in
1+0 records out
512 bytes (512B) copied, 0.000013 seconds, 37.6MB/s
installer: extracting shar into /tmp/sfx-SNDLhX
installer: invoking installer installer.sh
Found installer tmpfs on /tmp/sfx-SNDLhX (/tmp) using opts rw,noatime
Unpacking ONL installer files...
Extracting from /tmp/sfx-SNDLhX/onie-installer.zip: onl-loader-initrd-amd64.cpio.gz ...
Archive:  /tmp/sfx-SNDLhX/onie-installer.zip
  inflating: onl-loader-initrd-amd64.cpio.gz
Extracting initrd to /tmp/sfx-SNDLhX/initrd-XXhIfv
64769 blocks
Setting up /dev
Setting up /run
Setting up mounts
Launching ONL installer
Unmounting /mnt/onie-boot (--force)
Extracting from /tmp/sfx-SNDLhX/onie-installer.zip: preinstall.sh ...
Archive:  /tmp/sfx-SNDLhX/onie-installer.zip
  inflating: preinstall.sh
Invoking pre-install actions
Hello from preinstall
Chroot is /tmp/sfx-SNDLhX/initrd-XXhIfv
Examining /dev/sda7 --> User-Data
Examining /dev/sda6 --> PicOS2
Examining /dev/sda5 --> PicOS
Examining /dev/sda4 --> PICOS-GRUB
Examining /dev/sda3 --> ACCTON-DIAG
Examining /dev/sda2 --> ONIE-BOOT
Found ONIE boot partition at /dev/sda2
Found a clean GPT partition table
Traceback (most recent call last):
  File "/usr/bin/onl-install", line 6, in <module>
    import onl.install.App
  File "/usr/lib/python2.7/dist-packages/onl/install/App.py", line 21, in <module>
    import ConfUtils, BaseInstall
  File "/usr/lib/python2.7/dist-packages/onl/install/ConfUtils.py", line 14, in <module>
    from onl.sysconfig import sysconfig
  File "/usr/lib/python2.7/dist-packages/onl/sysconfig/__init__.py", line 13, in <module>
    from onl.platform.current import OnlPlatform
  File "/usr/lib/python2.7/dist-packages/onl/platform/current.py", line 81, in <module>
    OnlPlatform = import_subsystem_platform_class()
  File "/usr/lib/python2.7/dist-packages/onl/platform/current.py", line 76, in import_subsystem_platform_class
    m = importlib.import_module('%s.platform.%s' % (subsystem, platform_module))
  File "/usr/lib/python2.7/importlib/__init__.py", line 37, in import_module
    __import__(name)
ImportError: No module named x86_64_accton_as7726_32x_r0
Install failed.
Jan  1 00:02:35 onie local0.info onie: Starting: klogd...
Jan  1 00:02:35 onie local0.info onie:  done.
Jan  1 00:02:35 onie local0.info onie: Starting: dropbear ssh daemon...
Jan  1 00:02:35 onie local0.info onie:  done.
Jan  1 00:02:35 onie local0.info onie: Starting: telnetd...
Jan  1 00:02:35 onie local0.info onie:  done.
Jan  1 00:05:18 onie local0.info onie-exec: ONIE: Executing installer: DENTOS-HEAD_ONL-OS9_2023-06-22.2143-d97c46b_AMD64_INSTALLED_INSTALLER
Jan  1 00:05:18 onie local0.info os-install: installer: computing checksum of original archive
Jan  1 00:05:19 onie local0.info os-install: installer: checksum is OK
Jan  1 00:05:19 onie local0.info os-install: installer: extracting pad
Jan  1 00:05:19 onie local0.info os-install: 1+0 records in
Jan  1 00:05:19 onie local0.info os-install: 1+0 records out
Jan  1 00:05:19 onie local0.info os-install: 512 bytes (512B) copied, 0.000014 seconds, 34.9MB/s
Jan  1 00:05:19 onie local0.info os-install: installer: copying file before resetting pad
Jan  1 00:05:19 onie local0.info os-install: installer: resetting pad
Jan  1 00:05:19 onie local0.info os-install: 1+0 records in
Jan  1 00:05:19 onie local0.info os-install: 1+0 records out
Jan  1 00:05:19 onie local0.info os-install: 512 bytes (512B) copied, 0.000013 seconds, 37.6MB/s
Jan  1 00:05:19 onie local0.info os-install: installer: extracting shar into /tmp/sfx-SNDLhX
Jan  1 00:05:19 onie local0.info os-install: installer: invoking installer installer.sh
Jan  1 00:05:19 onie local0.info os-install: Archive:  /tmp/sfx-SNDLhX/onie-installer.zip
Jan  1 00:05:19 onie local0.info os-install:   inflating: onl-loader-initrd-amd64.cpio.gz
Jan  1 00:05:20 onie local0.info os-install: 64769 blocks
Jan  1 00:05:20 onie local0.info os-install: Archive:  /tmp/sfx-SNDLhX/onie-installer.zip
Jan  1 00:05:20 onie local0.info os-install:   inflating: preinstall.sh
Jan  1 00:05:20 onie local0.info os-install: Hello from preinstall
Jan  1 00:05:20 onie local0.info os-install: Chroot is /tmp/sfx-SNDLhX/initrd-XXhIfv
Jan  1 00:05:20 onie local0.info os-install: Traceback (most recent call last):
Jan  1 00:05:20 onie local0.info os-install:   File "/usr/bin/onl-install", line 6, in <module>
Jan  1 00:05:20 onie local0.info os-install:     import onl.install.App
Jan  1 00:05:20 onie local0.info os-install:   File "/usr/lib/python2.7/dist-packages/onl/install/App.py", line 21, in <module>
Jan  1 00:05:20 onie local0.info os-install:     import ConfUtils, BaseInstall
Jan  1 00:05:20 onie local0.info os-install:   File "/usr/lib/python2.7/dist-packages/onl/install/ConfUtils.py", line 14, in <module>
Jan  1 00:05:20 onie local0.info os-install:     from onl.sysconfig import sysconfig
Jan  1 00:05:20 onie local0.info os-install:   File "/usr/lib/python2.7/dist-packages/onl/sysconfig/__init__.py", line 13, in <module>
Jan  1 00:05:20 onie local0.info os-install:     from onl.platform.current import OnlPlatform
Jan  1 00:05:20 onie local0.info os-install:   File "/usr/lib/python2.7/dist-packages/onl/platform/current.py", line 81, in <module>
Jan  1 00:05:20 onie local0.info os-install:     OnlPlatform = import_subsystem_platform_class()
Jan  1 00:05:20 onie local0.info os-install:   File "/usr/lib/python2.7/dist-packages/onl/platform/current.py", line 76, in import_subsystem_platform_class
Jan  1 00:05:20 onie local0.info os-install:     m = importlib.import_module('%s.platform.%s' % (subsystem, platform_module))
Jan  1 00:05:20 onie local0.info os-install:   File "/usr/lib/python2.7/importlib/__init__.py", line 37, in import_module
Jan  1 00:05:20 onie local0.info os-install:     __import__(name)
Jan  1 00:05:20 onie local0.info os-install: ImportError: No module named x86_64_accton_as7726_32x_r0
Install failed. See log messages above for details



