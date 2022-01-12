
Luet uses Container technologies ( Docker, img  ) to build packages. It provides an abstraction over the Dockerfile format introducing relation and versioning of images.


Zero-deps installer
The installer can run in "from scratch" environment - your system will be always recoverable - everything which was built from containers can be installed locally.



SAT Solver

Luet uses SAT Solving techniques to compute the dependencies graph. This allows to refer to docker images by using semver constraints.

No Relational db is involved.


 Reconstruct images

 Thanks to its SAT core, Luet can reconstruct images defined by dependencies and version constraints.



It has zero dependencies and it is well suitable for "from scratch" environments. It can also version entire rootfs and enables delivery of OTA-alike updates, making it a perfect fit for the Edge computing era and IoT embedded devices.




It offers a simple specfile format in YAML notation to define both packages and rootfs. As it is based on containers, it can be also used to build stages for Linux From Scratch installations and it can build and track updates for those systems.

It is written entirely in Golang and where used as package manager, it can run in from scratch environment, with zero dependencies.


In a glance

    Luet can reuse Gentoo's portage tree hierarchy, and it is heavily inspired from it.
    It builds from containers, but installs, uninstalls and perform upgrades on machines
    Installer doesn't depend on anything ( 0 dep installer !), statically built
    You can install it aside also with your current distro package manager, and start building and distributing your packages
    Support for packages as "layers"
    It uses SAT solving techniques to solve the deptree ( Inspired by OPIUM )
    Support for collections and templated package definitions
    Can be extended with Plugins and Extensions
    Can build packages in Kubernetes (experimental)
    Uses containerd/go-containerregistry to manipulate images - works also daemonless with the img backend


# Build from source

```
$ make build
CGO_ENABLED=0 go build -ldflags '-X "github.com/mudler/luet/cmd.BuildTime=2021-11-18 05:48:55 UTC" -X "github.com/mudler/luet/cmd.BuildCommit=df2be8acfe908013a90010d9cf73b3f2b8903602"'
/bin/sh: line 1: go: command not found
make: *** [Makefile:62: build] Error 127
```

```
$ sudo dnf install go
Last metadata expiration check: 2:45:58 ago on Thu 18 Nov 2021 11:03:09 AM CST.
Dependencies resolved.
===========================================================
 Package       Arch      Version          Repository  Size
===========================================================
Installing:
 golang        x86_64    1.16.8-1.fc34    updates    609 k
Installing dependencies:
 golang-bin    x86_64    1.16.8-1.fc34    updates     82 M
 golang-src    noarch    1.16.8-1.fc34    updates    7.3 M
Installing weak dependencies:
 mercurial     x86_64    5.7.1-1.fc34     fedora     5.0 M

Transaction Summary
===========================================================
Install  4 Packages

Total download size: 94 M
Installed size: 381 M
Is this ok [y/N]: y
Downloading Packages:
(1/4): golang-1.16.8-1.fc3 151 kB/s | 609 kB     00:04
(2/4): mercurial-5.7.1-1.f 622 kB/s | 5.0 MB     00:08
(3/4): golang-src-1.16.8-1 659 kB/s | 7.3 MB     00:11
(4/4): golang-bin-1.16.8-1 1.7 MB/s |  82 MB     00:46
-----------------------------------------------------------
Total                      1.9 MB/s |  94 MB     00:48
Running transaction check
Transaction check succeeded.
Running transaction test
Transaction test succeeded.
Running transaction
  Running scriptlet: golang-1.16.8-1.fc34.x86_64       1/1
  Preparing        :                                   1/1
  Installing       : golang-src-1.16.8-1.fc34.noarch   1/4
  Installing       : mercurial-5.7.1-1.fc34.x86_64     2/4
  Installing       : golang-1.16.8-1.fc34.x86_64       3/4
  Installing       : golang-bin-1.16.8-1.fc34.x86_64   4/4
  Running scriptlet: golang-bin-1.16.8-1.fc34.x86_64   4/4
  Verifying        : mercurial-5.7.1-1.fc34.x86_64     1/4
  Verifying        : golang-1.16.8-1.fc34.x86_64       2/4
  Verifying        : golang-bin-1.16.8-1.fc34.x86_64   3/4
  Verifying        : golang-src-1.16.8-1.fc34.noarch   4/4

Installed:
  golang-1.16.8-1.fc34.x86_64
  golang-bin-1.16.8-1.fc34.x86_64
  golang-src-1.16.8-1.fc34.noarch
  mercurial-5.7.1-1.fc34.x86_64

Complete!
```

```
$ make build
CGO_ENABLED=0 go build -ldflags '-X "github.com/mudler/luet/cmd.BuildTime=2021-11-18 05:50:36 UTC" -X "github.com/mudler/luet/cmd.BuildCommit=df2be8acfe908013a90010d9cf73b3f2b8903602"'
```

```
$ ./luet search busybox
 INFO   --- Search results (busybox): ---
```

# Install from site

```
$ curl -O https://get.mocaccino.org/luet/get_luet_root.sh
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  1365  100  1365    0     0   1400      0 --:--:-- --:--:-- --:--:--  1398

$ vi get_luet_root.sh

$ sudo bash -x get_luet_root.sh
++ id -u
+ '[' 0 -ne 0 ']'
+ set -ex
+ export LUET_NOLOCK=true
+ LUET_NOLOCK=true
+ LUET_VERSION=0.19.1
+ LUET_ROOTFS=/
+ LUET_DATABASE_PATH=/var/luet/db
+ LUET_DATABASE_ENGINE=boltdb
+ LUET_CONFIG_PROTECT=1
+ curl -L https://github.com/mudler/luet/releases/download/0.19.1/luet-0.19.1-linux-amd64 --output luet
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100   631  100   631    0     0    322      0  0:00:01  0:00:01 --:--:--   322
...
+ chmod +x luet
+ mkdir -p /etc/luet/repos.conf.d
+ mkdir -p /var/luet/db
+ mkdir -p /var/tmp/luet
+ '[' 1 = 1 ']'
+ mkdir -p /etc/luet/config.protect.d
+ curl -L https://raw.githubusercontent.com/mudler/luet/master/contrib/config/config.protect.d/01_etc.yml.example --output /etc/luet/config.protect.d/01_etc.yml
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed

+ curl -L https://raw.githubusercontent.com/mocaccinoOS/repository-index/master/packages/mocaccino-repository-index.yml --output /etc/luet/repos.conf.d/mocaccino-repository-index.yml
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
...
+ cat
+ ./luet install -y repository/luet repository/mocaccino-repository-index
            ██      ██    ██ ███████ ████████
            ██      ██    ██ ██         ██
            ██      ██    ██ █████      ██
            ██      ██    ██ ██         ██
            ███████  ██████  ███████    ██


          Luet - 0-deps container-based package m
          anager


0.19.1-g4d60795fdcfee6fed6b87b51ca1e79e159fbb89a 2021-10-22 17:47:25 UTC
      Luet Copyright (C) 2019-2021 Ettore Di Giacinto
      This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it under certain conditions.

  Install

 INFO   Downloaded repository.yaml of 0.00 MB ( 0.00 MiB/s )
 INFO   Downloaded tree.tar.gz of 0.00 MB ( 0.00 MiB/s )
 INFO   Downloaded repository.meta.yaml.tar.gz of 0.00 MB ( 0.00 MiB/s )
 INFO   🏠  Repository mocaccino-repository-index revision: 1 (2021-10-23 07:29:50 +0800 CST)
 INFO   ℹ  Repository: mocaccino-repository-index Priority: 1 Type: http
 INFO   Packages that are going to be installed in the system:

Program Name                          | Version  | License | Repository
repository/luet                       | 20200717 |         | mocaccino-repository-index
repository/mocaccino-repository-index | 20201005 |         | mocaccino-repository-index

 INFO   Downloaded luet-repository-20200717.package.tar.gz of 0.00 MB ( 0.00 MiB/s )
 SUCCESS   📦  Package  repository/luet-20200717 downloaded
 INFO   Downloaded mocaccino-repository-index-repository-20201005.package.tar.gz of 0.00 MB ( 0.00 MiB/s )
 SUCCESS   📦  Package  repository/mocaccino-repository-index-20201005 downloaded
 INFO   Checking for file conflicts..
 INFO   📦  Package  repository/luet-20200717 installed
 INFO   📦  Package  repository/mocaccino-repository-index-20201005 installed
+ ./luet install -y system/luet
                                          ██      ██    ██ ███████ ████████
                                          ██      ██    ██ ██         ██
                                          ██      ██    ██ █████      ██
                                          ██      ██    ██ ██         ██
                                          ███████  ██████  ███████    ██


                                     Luet - 0-deps container-based package manager


                       0.19.1-g4d60795fdcfee6fed6b87b51ca1e79e159fbb89a 2021-10-22 17:47:25 UTC
                                    Luet Copyright (C) 2019-2021 Ettore Di Giacinto
                                    This program comes with ABSOLUTELY NO WARRANTY.
                This is free software, and you are welcome to redistribute it under certain conditions.

  Install

  ERROR    Error: Failed syncing repository: luet: Error reading file : open : no such file or directory

$ sudo ./luet install dev-vcs/gogs
                                          ██      ██    ██ ███████ ████████
                                          ██      ██    ██ ██         ██
                                          ██      ██    ██ █████      ██
                                          ██      ██    ██ ██         ██
                                          ███████  ██████  ███████    ██


                                     Luet - 0-deps container-based package manager


                       0.19.1-g4d60795fdcfee6fed6b87b51ca1e79e159fbb89a 2021-10-22 17:47:25 UTC
                                    Luet Copyright (C) 2019-2021 Ettore Di Giacinto
                                    This program comes with ABSOLUTELY NO WARRANTY.
                This is free software, and you are welcome to redistribute it under certain conditions.

  Install

 INFO   Downloaded repository.yaml of 0.00 MB ( 0.00 MiB/s )
 INFO   Downloaded tree.tar.zst of 0.00 MB ( 0.00 MiB/s )
 INFO   Downloaded repository.meta.yaml.tar.zst of 0.00 MB ( 0.00 MiB/s )
 INFO   🏠  Repository luet-official revision: 1 (2021-11-16 05:54:00 +0800 CST)
 INFO   ℹ  Repository: luet Priority: 1 Type: http
 INFO   Downloaded repository.yaml of 0.00 MB ( 0.00 MiB/s )
 INFO   Repository mocaccino-repository-index is already up to date.
 INFO   ℹ  Repository: mocaccino-repository-index Priority: 1 Type: http
 INFO   🤔  Checking for available upgrades
 INFO   Nothing to upgrade
 INFO   No packages to install

```


