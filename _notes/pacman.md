```
 go
zsh: correct 'go' to 'gio' [nyae]? n
The application go is not installed. It may be found in the following packages:
  core/gcc-go 11.1.0-1          /usr/bin/go
  community/go 2:1.17.3-1       /usr/bin/go
  community/go 2:1.17.3-1       /usr/lib/go/bin/go
Do you want to Install package gcc-go? (y/N)  y
Executing command: pamac install gcc-go
Preparing...
==== AUTHENTICATING FOR org.manjaro.pamac.commit ====
Authentication is required to install, update, or remove packages
Authenticating as: aaron
Password:
==== AUTHENTICATION COMPLETE ====
Synchronizing package databases...
Resolving dependencies...
Checking inter-conflicts...

To install (1):
  gcc-go  11.1.0-1    core  31.6 MB

Total download size: 31.6 MB
Total installed size: 186.7 MB

Apply transaction ? [y/N] y
Download of gcc-go (11.1.0-1) started
Download of gcc-go (11.1.0-1) finished
Checking keyring...                                                                                               [1/1]
Checking integrity...                                                                                             [1/1]
Loading packages files...                                                                                         [1/1]
Checking file conflicts...                                                                                        [1/1]
Checking available disk space...                                                                                  [1/1]
Installing gcc-go (11.1.0-1)...                                                                                   [1/1]
Running post-transaction hooks...
Arming ConditionNeedsUpdate...                                                                                    [1/2]
Updating the info directory file...                                                                               [2/2]
Transaction successfully finished.

 kubectl
The application kubectl is not installed. It may be found in the following packages:
  community/kubectl 1.22.3-1    /usr/bin/kubectl
Do you want to Install package kubectl? (y/N)  y
Executing command: pamac install kubectl

Preparing...
==== AUTHENTICATING FOR org.manjaro.pamac.commit ====
Authentication is required to install, update, or remove packages
Authenticating as: aaron
Password:
==== AUTHENTICATION COMPLETE ====
Synchronizing package databases...
Resolving dependencies...
Checking inter-conflicts...

To install (1):
  kubectl  1.22.3-1    community  14.1 MB

Total download size: 14.1 MB
Total installed size: 68.2 MB

Apply transaction ? [y/N] y
Download of kubectl (1.22.3-1) started
Download of kubectl (1.22.3-1) finished
Checking keyring...                                                                                                                [1/1]
Checking integrity...                                                                                                              [1/1]
Loading packages files...                                                                                                          [1/1]
Checking file conflicts...                                                                                                         [1/1]
Checking available disk space...                                                                                                   [1/1]
Installing kubectl (1.22.3-1)...                                                                                                   [1/1]
Transaction successfully finished.

 minikube
zsh: correct 'minikube' to '.minikube' [nyae]? n
The application minikube is not installed. It may be found in the following packages:
  community/minikube 1.24.0-1   /usr/bin/minikube
Do you want to Install package minikube? (y/N)  y
Executing command: pamac install minikube
Preparing...

Choose optional dependencies for minikube:
1:  virtualbox: to use --vm-driver=virtualbox

Enter a selection (default=none):

==== AUTHENTICATING FOR org.manjaro.pamac.commit ====
Authentication is required to install, update, or remove packages
Authenticating as: aaron
Password:
==== AUTHENTICATION COMPLETE ====
Synchronizing package databases...
Resolving dependencies...
Checking inter-conflicts...

To install (1):
  minikube  1.24.0-1    community  12.8 MB

Total download size: 12.8 MB
Total installed size: 63.8 MB

Apply transaction ? [y/N] y
Download of minikube (1.24.0-1) started
Download of minikube (1.24.0-1) finished
Checking keyring...                                                                                                                [1/1]
Checking integrity...                                                                                                              [1/1]
Loading packages files...                                                                                                          [1/1]
Checking file conflicts...                                                                                                         [1/1]
Checking available disk space...                                                                                                   [1/1]
Installing minikube (1.24.0-1)...                                                                                                  [1/1]
Transaction successfully finished.

$ virtualbox
zsh: correct 'virtualbox' to '_virtualbox' [nyae]? n
The application virtualbox is not installed. It may be found in the following packages:
  community/virtualbox 6.1.28-3 /usr/bin/virtualbox
Do you want to Install package virtualbox? (y/N)  y
Executing command: pamac install virtualbox
Preparing...

Choose optional dependencies for virtualbox:
1:  vde2: Virtual Distributed Ethernet support
2:  virtualbox-guest-iso: Guest Additions CD image
3:  virtualbox-ext-vnc: VNC server support
4:  virtualbox-sdk: Developer kit

Enter a selection (default=none): 1,2

==== AUTHENTICATING FOR org.manjaro.pamac.commit ====
Authentication is required to install, update, or remove packages
Authenticating as: aaron
Password:
==== AUTHENTICATION COMPLETE ====
Synchronizing package databases...
Choose a provider for VIRTUALBOX-HOST-MODULES:
 1:  linux414-virtualbox-host-modules     6.1.28-4  extra
 2:  linux419-virtualbox-host-modules     6.1.28-5  extra
 3:  linux44-virtualbox-host-modules      6.1.28-4  extra
 4:  linux49-virtualbox-host-modules      6.1.28-4  extra
 5:  linux510-virtualbox-host-modules     6.1.28-5  extra
 6:  linux513-virtualbox-host-modules     6.1.28-1  extra
 7:  linux514-virtualbox-host-modules     6.1.28-5  extra
 8:  linux515-virtualbox-host-modules     6.1.28-6  extra
 9:  linux54-virtualbox-host-modules      6.1.28-5  extra
10:  linux510-rt-virtualbox-host-modules  6.1.28-2  community
11:  linux515-rt-virtualbox-host-modules  6.1.28-2  community
12:  virtualbox-host-dkms                 6.1.28-3  community

Enter a number (default=1): 12

Resolving dependencies...
Checking inter-conflicts...

To install (6):
  virtualbox-guest-iso  6.1.28-1                                           community  44.3 MB
  sdl                   1.2.15+387+gfbfcca32-1  (Required By: virtualbox)  community  377.0 kB
  dkms                  3.0.1-1                 (Required By: virtualbox)  extra      36.9 kB
  virtualbox-host-dkms  6.1.28-3                (Required By: virtualbox)  community  725.5 kB
  virtualbox            6.1.28-3                                           community  37.0 MB
  vde2                  2.3.2-16                                           extra      221.2 kB

Total download size: 82.6 MB
Total installed size: 244.1 MB

Apply transaction ? [y/N] y
Download of dkms (3.0.1-1) started
Download of virtualbox-host-dkms (6.1.28-3) started
Download of dkms (3.0.1-1) finished
Download of sdl (1.2.15+387+gfbfcca32-1) started
Download of virtualbox-host-dkms (6.1.28-3) finished
Download of sdl (1.2.15+387+gfbfcca32-1) finished
Download of virtualbox (6.1.28-3) started
Download of virtualbox-guest-iso (6.1.28-1) started
Download of virtualbox (6.1.28-3) finished
Download of virtualbox-guest-iso (6.1.28-1) finished
Download of vde2 (2.3.2-16) started
Download of vde2 (2.3.2-16) finished
Checking keyring...                                                                                                                [6/6]
Checking integrity...                                                                                                              [6/6]
Loading packages files...                                                                                                          [6/6]
Checking file conflicts...                                                                                                         [6/6]
Checking available disk space...                                                                                                   [6/6]
Installing dkms (3.0.1-1)...                                                                                                       [1/6]
Installing virtualbox-host-dkms (6.1.28-3)...                                                                                      [2/6]
Installing virtualbox-guest-iso (6.1.28-1)...                                                                                      [3/6]

===> virtualbox-guest-iso post install message:
===>
===> Redistribution of VBoxGuestAdditions.iso from the binary packages
===> on www.virtualbox.org with Arch Linux has been granted by
===> InnoTek Systemberatung GmbH.
===>
===> By using this package you accept
===> the VirtualBox Personal Use and Evaluation License (PUEL)
===> which can be found here: http://virtualbox.org/wiki/VirtualBox_PUEL
===>
===> If you do not accept this license, you must remove the package immediately.
===>

Installing sdl (1.2.15+387+gfbfcca32-1)...                                                                                         [4/6]
Installing virtualbox (6.1.28-3)...                                                                                                [5/6]
Installing vde2 (2.3.2-16)...                                                                                                      [6/6]
vde config files should be placed in /etc/vde, sample files are provided.
iptables and dhcpd sample files have been installed to '/usr/share/vde2'.
Merge those examples, if needed to the according config files.
Running post-transaction hooks...
Creating system user accounts...                                                                                                   [1/8]
Creating group vboxusers with gid 108.
Reloading system manager configuration...                                                                                          [2/8]
Reloading device manager configuration...                                                                                          [3/8]
Arming ConditionNeedsUpdate...                                                                                                     [4/8]
Install DKMS modules                                                                                                               [5/8]
==> ERROR: Missing crypto_keyfile.bin kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing sys kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing rootfs-pkgs.txt kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing proc kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing barn kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing opt kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing boot kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing run kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing var kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing lib kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing mnt kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing lost+found kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing bin kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing usr kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing sbin kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing root kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing lib64 kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing dev kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing home kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing tmp kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing etc kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing srv kernel headers for module vboxhost/6.1.28_OSE.
==> ERROR: Missing desktopfs-pkgs.txt kernel headers for module vboxhost/6.1.28_OSE.
Updating icon theme caches...                                                                                                      [6/8]
Updating the desktop file MIME type cache...                                                                                       [7/8]
Updating the MIME type database...                                                                                                 [8/8]
Transaction successfully finished.

```

```

REMOVE OPTIONS (APPLY TO -R)
       -c, --cascade
           Remove all target packages, as well as all packages that depend on one or more target packages. This
           operation is recursive and must be used with care, since it can remove many potentially needed packages.

       -n, --nosave
           Instructs pacman to ignore file backup designations. Normally, when a file is removed from the system,
           the database is checked to see if the file should be renamed with a .pacsave extension.

       -s, --recursive
           Remove each target specified including all of their dependencies, provided that (A) they are not
           required by other packages; and (B) they were not explicitly installed by the user. This operation is
           recursive and analogous to a backwards --sync operation, and it helps keep a clean system without
           orphans. If you want to omit condition (B), pass this option twice.

       -u, --unneeded
           Removes targets that are not required by any other packages. This is mostly useful when removing a group
           without using the -c option, to avoid breaking any dependencies.

SYNC OPTIONS (APPLY TO -S)
       -c, --clean
           Remove packages that are no longer installed from the cache as well as currently unused sync databases
           to free up disk space. When pacman downloads packages, it saves them in a cache directory. In addition,
           databases are saved for every sync DB you download from and are not deleted even if they are removed
           from the configuration file pacman.conf(5). Use one --clean switch to only remove packages that are no
           longer installed; use two to remove all files from the cache. In both cases, you will have a yes or no
           option to remove packages and/or unused downloaded databases.

           If you use a network shared cache, see the CleanMethod option in pacman.conf(5).


```
