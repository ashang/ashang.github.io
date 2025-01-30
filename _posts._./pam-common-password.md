---
title: pam.d/common-password
tags:
  - pam
warning: true
date: 2015-08-31 21:06:02
---

```
$ diff os-dev/rootfs-debian/x86/etc/pam.d/common-password rootfs/common/etc/pam.d/common-password
9,16c9,16
< # The "yescrypt" option enables
< #hashed passwords using the yescrypt algorithm, introduced in Debian
< #11.  Without this option, the default is Unix crypt.  Prior releases
< #used the option "sha512"; if a shadow password hash will be shared
< #between Debian 11 and older releases replace "yescrypt" with "sha512"
< #for compatibility .  The "obscure" option replaces the old
< #`OBSCURE_CHECKS_ENAB' option in login.defs.  See the pam_unix manpage
< #for other options.
---
> #
> # The "sha512" option enables salted SHA512 passwords.  Without this option,
> # the default is Unix crypt.  Prior releases used the option "md5".
> #
> # The "obscure" option replaces the old `OBSCURE_CHECKS_ENAB' option in
> # login.defs.
> #
> # See the pam_unix manpage for other options.
25c25,27
< password      [success=1 default=ignore]      pam_unix.so obscure yescrypt
---
> #password     sufficient                      pam_tacplus.so
> password required pam_unix.so try_first_pass obscure sha512
>
27c29
< password      requisite                       pam_deny.so
---
> #password     requisite                       pam_deny.so
31c33
< password      required                        pam_permit.so
---
> #password     required                        pam_permit.so
```


```diff
$ diff /usr/share/pam/common-password /etc/pam.d/common-password
25c25,27
< $password_primary
---
> password      requisite                       pam_pwquality.so retry=3
> password      [success=2 default=ignore]      pam_unix.so obscure use_authtok try_first_pass yescrypt
> password      sufficient                      pam_sss.so use_authtok
33c35
< $password_additional
---
> password      optional        pam_gnome_keyring.so
```

```patch
$ diff /usr/share/pam/common-password /etc/pam.d/common-password
25c25,27
< $password_primary
---
> password      requisite                       pam_pwquality.so retry=3
> password      [success=2 default=ignore]      pam_unix.so obscure use_authtok try_first_pass yescrypt
> password      sufficient                      pam_sss.so use_authtok
33c35
< $password_additional
---
> password      optional        pam_gnome_keyring.so
```




────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
                                                                   ┌─────────────────────────────────────────────────────PAM configuration───────────────────────────────────────────────────────┐
                                                                   │ Pluggable Authentication Modules (PAM) determine how authentication, authorization, and password changing are handled on    │
                                                                   │ the system, as well as allowing configuration of additional actions to take when starting user sessions.                    │
                                                                   │                                                                                                                             │
                                                                   │ Some PAM module packages provide profiles that can be used to automatically adjust the behavior of all PAM-using            │
                                                                   │ applications on the system. Please indicate which of these behaviors you wish to enable.                                    │
                                                                   │                                                                                                                             │
                                                                   │ PAM profiles to enable:                                                                                                     │
                                                                   │ ┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐ │
                                                                   │ │                           [*] Unix authentication                                                                       │ │
                                                                   │ │                           [*] Register user sessions in the systemd control group hierarchy                             │ │
                                                                   │ │                           [ ] Create home directory on login                                                            │ │
                                                                   │ └─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘ │
                                                                   ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
                                                                   │                                           <  OK  >                      <Cancel>                                            │
                                                                   └─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘



```
diff -x.git -ur /etc/pam.d/common-account code/pam.d/common-account
--- /etc/pam.d/common-account	2023-02-27 22:47:00.343689760 +0800
+++ code/pam.d/common-account	2022-12-13 14:14:58.840957390 +0800
@@ -22,6 +22,4 @@
 # since the modules above will each just jump around
 account	required			pam_permit.so
 # and here are more per-package modules (the "Additional" block)
-account	sufficient			pam_localuser.so
-account	[default=bad success=ok user_unknown=ignore]	pam_sss.so
 # end of pam-auth-update config
diff -x.git -ur /etc/pam.d/common-auth code/pam.d/common-auth
--- /etc/pam.d/common-auth	2023-02-27 22:47:00.315689306 +0800
+++ code/pam.d/common-auth	2022-12-13 14:14:58.832957432 +0800
@@ -14,8 +14,7 @@
 # pam-auth-update(8) for details.

 # here are the per-package modules (the "Primary" block)
-auth	[success=2 default=ignore]	pam_unix.so nullok
-auth	[success=1 default=ignore]	pam_sss.so use_first_pass
+auth	[success=1 default=ignore]	pam_unix.so nullok
 # here's the fallback if no module succeeds
 auth	requisite			pam_deny.so
 # prime the stack with a positive return value if there isn't one already;
diff -x.git -ur /etc/pam.d/common-password code/pam.d/common-password
--- /etc/pam.d/common-password	2023-02-27 22:47:00.351689889 +0800
+++ code/pam.d/common-password	2022-12-13 14:14:58.844957369 +0800
@@ -23,8 +23,7 @@

 # here are the per-package modules (the "Primary" block)
 password	requisite			pam_pwquality.so retry=3
-password	[success=2 default=ignore]	pam_unix.so obscure use_authtok try_first_pass yescrypt
-password	sufficient			pam_sss.so use_authtok
+password	[success=1 default=ignore]	pam_unix.so obscure use_authtok try_first_pass yescrypt
 # here's the fallback if no module succeeds
 password	requisite			pam_deny.so
 # prime the stack with a positive return value if there isn't one already;
@@ -32,5 +31,4 @@
 # since the modules above will each just jump around
 password	required			pam_permit.so
 # and here are more per-package modules (the "Additional" block)
-password	optional	pam_gnome_keyring.so
 # end of pam-auth-update config
diff -x.git -ur /etc/pam.d/common-session code/pam.d/common-session
--- /etc/pam.d/common-session	2023-02-27 22:47:00.387690472 +0800
+++ code/pam.d/common-session	2022-12-13 14:14:58.848957348 +0800
@@ -27,6 +27,6 @@
 session optional			pam_umask.so
 # and here are more per-package modules (the "Additional" block)
 session	required	pam_unix.so
-session	optional			pam_sss.so
 session	optional	pam_systemd.so
+session	optional			pam_mkhomedir.so
 # end of pam-auth-update config

Only in code/pam.d/: polkit-1
Only in /etc/pam.d: slock
diff -x.git -ur /etc/pam.d/sudo code/pam.d/sudo
--- /etc/pam.d/sudo	2023-01-18 23:19:23.000000000 +0800
+++ code/pam.d/sudo	2021-02-27 16:28:03.000000000 +0800
@@ -1,8 +1,5 @@
 #%PAM-1.0

-# Set up user limits from /etc/security/limits.conf.
-session    required   pam_limits.so
```




$ gd
diff --git a/linux b/linux
index 300d20fc9c..90563ced3c 160000
--- a/linux
+++ b/linux
@@ -1 +1 @@
-Subproject commit 300d20fc9c7db31b6db8e357ac52e41fc356b71f
+Subproject commit 90563ced3cf1f055457beb96dea4b8deba19dc3d
diff --git a/os-dev/rootfs-debian/arm/var/lib/pam/account b/os-dev/rootfs-debian/arm/var/lib/pam/account
index e4c3954286..8e951c9662 100644
--- a/os-dev/rootfs-debian/arm/var/lib/pam/account
+++ b/os-dev/rootfs-debian/arm/var/lib/pam/account
@@ -1,4 +1,2 @@
-Module: tacplus
-sufficient                     pam_tacplus.so
 Module: unix
[success=end new_authtok_reqd=done default=ignore]     pam_unix.so
diff --git a/os-dev/rootfs-debian/arm/var/lib/pam/auth b/os-dev/rootfs-debian/arm/var/lib/pam/auth
index 949c169c1a..e8839e9abf 100644
--- a/os-dev/rootfs-debian/arm/var/lib/pam/auth
+++ b/os-dev/rootfs-debian/arm/var/lib/pam/auth
@@ -1,4 +1,2 @@
lines 1-21
diff --git a/linux b/linux
index 300d20fc9c..90563ced3c 160000
--- a/linux
+++ b/linux
@@ -1 +1 @@
-Subproject commit 300d20fc9c7db31b6db8e357ac52e41fc356b71f
+Subproject commit 90563ced3cf1f055457beb96dea4b8deba19dc3d
diff --git a/os-dev/rootfs-debian/arm/var/lib/pam/account b/os-dev/rootfs-debian/arm/var/lib/pam/account
index e4c3954286..8e951c9662 100644
diff --git a/os-dev/rootfs-debian/arm/var/lib/pam/account b/os-dev/rootfs-debian/arm/var/lib/pam/account
index e4c3954286..8e951c9662 100644
--- a/os-dev/rootfs-debian/arm/var/lib/pam/account
+++ b/os-dev/rootfs-debian/arm/var/lib/pam/account
@@ -1,4 +1,2 @@
-Module: tacplus
-sufficient                     pam_tacplus.so
 Module: unix
[success=end new_authtok_reqd=done default=ignore]     pam_unix.so
diff --git a/os-dev/rootfs-debian/arm/var/lib/pam/auth b/os-dev/rootfs-debian/arm/var/lib/pam/auth
index 949c169c1a..e8839e9abf 100644
--- a/os-dev/rootfs-debian/arm/var/lib/pam/auth
+++ b/os-dev/rootfs-debian/arm/var/lib/pam/auth
@@ -1,4 +1,2 @@
-Module: tacplus
-sufficient                     pam_tacplus.so
 Module: unix
-[success=end default=ignore]   pam_unix.so nullok_secure try_first_pass
+[success=end default=ignore]   pam_unix.so nullok
diff --git a/os-dev/rootfs-debian/arm/var/lib/pam/password b/os-dev/rootfs-debian/arm/var/lib/pam/password
index 401d9cae0f..dbe622eef3 100644
--- a/os-dev/rootfs-debian/arm/var/lib/pam/password
+++ b/os-dev/rootfs-debian/arm/var/lib/pam/password
@@ -1,4 +1,2 @@
-Module: tacplus
-sufficient                     pam_tacplus.so
 Module: unix
-[success=end default=ignore]   pam_unix.so obscure use_authtok try_first_pass sha512
+[success=end default=ignore]   pam_unix.so obscure yescrypt
diff --git a/os-dev/rootfs-debian/arm/var/lib/pam/seen b/os-dev/rootfs-debian/arm/var/lib/pam/seen
index f5d3e8635b..d21a69a07c 100644
--- a/os-dev/rootfs-debian/arm/var/lib/pam/seen
+++ b/os-dev/rootfs-debian/arm/var/lib/pam/seen
@@ -1,2 +1,3 @@
-tacplus
 unix
+systemd
+mkhomedir
diff --git a/os-dev/rootfs-debian/arm/var/lib/pam/session b/os-dev/rootfs-debian/arm/var/lib/pam/session
index 8ee84c2698..d84502a685 100644
--- a/os-dev/rootfs-debian/arm/var/lib/pam/session
+++ b/os-dev/rootfs-debian/arm/var/lib/pam/session
@@ -1,6 +1,6 @@
 Module: null
[default=1]                    pam_permit.so
-Module: tacplus
-optional                       pam_tacplus.so
 Module: unix
 required       pam_unix.so
+Module: systemd
+optional       pam_systemd.so
diff --git a/os-dev/rootfs-debian/arm/var/lib/pam/session-noninteractive b/os-dev/rootfs-debian/arm/var/lib/pam/session-noninteractive
index 8ee84c2698..8fbb3b9323 100644
--- a/os-dev/rootfs-debian/arm/var/lib/pam/session-noninteractive
+++ b/os-dev/rootfs-debian/arm/var/lib/pam/session-noninteractive
@@ -1,6 +1,4 @@
 Module: null
[default=1]                    pam_permit.so
-Module: tacplus
-optional                       pam_tacplus.so
 Module: unix
 required       pam_unix.so
diff --git a/os-dev/rootfs-debian/x86/var/lib/pam/auth b/os-dev/rootfs-debian/x86/var/lib/pam/auth
index ca1478d544..e8839e9abf 100644
--- a/os-dev/rootfs-debian/x86/var/lib/pam/auth
+++ b/os-dev/rootfs-debian/x86/var/lib/pam/auth
@@ -1,2 +1,2 @@
 Module: unix
-[success=end default=ignore]   pam_unix.so nullok_secure
+[success=end default=ignore]   pam_unix.so nullok
diff --git a/os-dev/rootfs-debian/x86/var/lib/pam/password b/os-dev/rootfs-debian/x86/var/lib/pam/password
index 9a378fa00a..dbe622eef3 100644
--- a/os-dev/rootfs-debian/x86/var/lib/pam/password
+++ b/os-dev/rootfs-debian/x86/var/lib/pam/password
@@ -1,2 +1,2 @@
 Module: unix
-[success=end default=ignore]   pam_unix.so obscure sha512
+[success=end default=ignore]   pam_unix.so obscure yescrypt



```






admin@PICOS:~$ sudo ntpdate 10.10.50.10
 3 Mar 05:38:33 ntpdate[3163]: step time server 10.10.50.10 offset +17941883.526869 sec
admin@PICOS:~$ sudo apt update
Get:1 https://mirrors.ustc.edu.cn/debian bullseye InRelease [116 kB]
Get:2 https://mirrors.ustc.edu.cn/debian bullseye-updates InRelease [44.1 kB]
Get:3 https://mirrors.ustc.edu.cn/debian bullseye-backports InRelease [49.0 kB]
Get:4 https://mirrors.ustc.edu.cn/debian-security bullseye-security InRelease [48.4 kB]
Get:5 https://mirrors.ustc.edu.cn/debian bullseye/main amd64 Packages [8183 kB]
Get:6 https://mirrors.ustc.edu.cn/debian bullseye/main Translation-en [6240 kB]
Get:7 https://mirrors.ustc.edu.cn/debian bullseye/contrib amd64 Packages [50.6 kB]
Get:8 https://mirrors.ustc.edu.cn/debian bullseye/contrib Translation-en [46.9 kB]
Get:9 https://mirrors.ustc.edu.cn/debian bullseye/non-free amd64 Packages [97.8 kB]
Get:10 https://mirrors.ustc.edu.cn/debian bullseye/non-free Translation-en [92.4 kB]
Get:11 https://mirrors.ustc.edu.cn/debian bullseye-updates/main amd64 Packages [14.6 kB]
Get:12 https://mirrors.ustc.edu.cn/debian bullseye-updates/main Translation-en [7929 B]
Get:13 https://mirrors.ustc.edu.cn/debian bullseye-backports/main amd64 Packages [399 kB]
Get:14 https://mirrors.ustc.edu.cn/debian bullseye-backports/main Translation-en [332 kB]
Get:15 https://mirrors.ustc.edu.cn/debian bullseye-backports/contrib amd64 Packages [5688 B]
Get:16 https://mirrors.ustc.edu.cn/debian bullseye-backports/contrib Translation-en [5832 B]
Get:17 https://mirrors.ustc.edu.cn/debian bullseye-backports/non-free amd64 Packages [14.3 kB]
Get:18 https://mirrors.ustc.edu.cn/debian bullseye-backports/non-free Translation-en [26.6 kB]
Get:19 https://mirrors.ustc.edu.cn/debian-security bullseye-security/main amd64 Packages [229 kB]
Get:20 https://mirrors.ustc.edu.cn/debian-security bullseye-security/main Translation-en [150 kB]
Get:21 https://mirrors.ustc.edu.cn/debian-security bullseye-security/non-free amd64 Packages [528 B]
Get:22 https://mirrors.ustc.edu.cn/debian-security bullseye-security/non-free Translation-en [344 B]
Fetched 15.9 MB in 21s (746 kB/s)
Reading package lists... Done
Building dependency tree... Done
3 packages can be upgraded. Run 'apt list --upgradable' to see them.
admin@PICOS:~$
admin@PICOS:~$ sudo apt upgrade
Reading package lists... Done
Building dependency tree... Done
Calculating upgrade... Done
The following packages have been kept back:
  libpam-radius-auth
The following packages will be upgraded:
  curl libcurl4
2 upgraded, 0 newly installed, 0 to remove and 1 not upgraded.
Need to get 617 kB of archives.
After this operation, 0 B of additional disk space will be used.
Do you want to continue? [Y/n]
Get:1 https://mirrors.ustc.edu.cn/debian-security bullseye-security/main amd64 curl amd64 7.74.0-1.3+deb11u7 [270 kB]
Get:2 https://mirrors.ustc.edu.cn/debian-security bullseye-security/main amd64 libcurl4 amd64 7.74.0-1.3+deb11u7 [346 kB]
Fetched 617 kB in 11s (57.9 kB/s)
debconf: delaying package configuration, since apt-utils is not installed
(Reading database ... 14813 files and directories currently installed.)
Preparing to unpack .../curl_7.74.0-1.3+deb11u7_amd64.deb ...
Unpacking curl (7.74.0-1.3+deb11u7) over (7.74.0-1.3+deb11u5) ...
Preparing to unpack .../libcurl4_7.74.0-1.3+deb11u7_amd64.deb ...
Unpacking libcurl4:amd64 (7.74.0-1.3+deb11u7) over (7.74.0-1.3+deb11u5) ...
Setting up libcurl4:amd64 (7.74.0-1.3+deb11u7) ...
Setting up curl (7.74.0-1.3+deb11u7) ...
Processing triggers for libc-bin (2.31-13+deb11u5) ...
admin@PICOS:~$ sudo apt install libpam-pwquality
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
The following additional packages will be installed:
  cracklib-runtime libcrack2 libpwquality-common libpwquality1 wamerican
The following NEW packages will be installed:
  cracklib-runtime libcrack2 libpam-pwquality libpwquality-common libpwquality1 wamerican
0 upgraded, 6 newly installed, 0 to remove and 1 not upgraded.
Need to get 504 kB of archives.
After this operation, 2425 kB of additional disk space will be used.
Do you want to continue? [Y/n]
Get:1 https://mirrors.ustc.edu.cn/debian bullseye/main amd64 wamerican all 2019.10.06-1 [215 kB]
Get:2 https://mirrors.ustc.edu.cn/debian bullseye/main amd64 libcrack2 amd64 2.9.6-3.4 [56.0 kB]
Get:3 https://mirrors.ustc.edu.cn/debian bullseye/main amd64 cracklib-runtime amd64 2.9.6-3.4 [155 kB]
Get:4 https://mirrors.ustc.edu.cn/debian bullseye/main amd64 libpwquality-common all 1.4.4-1 [50.3 kB]
Get:5 https://mirrors.ustc.edu.cn/debian bullseye/main amd64 libpwquality1 amd64 1.4.4-1 [13.9 kB]
Get:6 https://mirrors.ustc.edu.cn/debian bullseye/main amd64 libpam-pwquality amd64 1.4.4-1 [13.8 kB]
Fetched 504 kB in 11s (47.5 kB/s)
debconf: delaying package configuration, since apt-utils is not installed
Selecting previously unselected package wamerican.
(Reading database ... 14813 files and directories currently installed.)
Preparing to unpack .../0-wamerican_2019.10.06-1_all.deb ...
Unpacking wamerican (2019.10.06-1) ...
Selecting previously unselected package libcrack2:amd64.
Preparing to unpack .../1-libcrack2_2.9.6-3.4_amd64.deb ...
Unpacking libcrack2:amd64 (2.9.6-3.4) ...
Selecting previously unselected package cracklib-runtime.
Preparing to unpack .../2-cracklib-runtime_2.9.6-3.4_amd64.deb ...
Unpacking cracklib-runtime (2.9.6-3.4) ...
Selecting previously unselected package libpwquality-common.
Preparing to unpack .../3-libpwquality-common_1.4.4-1_all.deb ...
Unpacking libpwquality-common (1.4.4-1) ...
Selecting previously unselected package libpwquality1:amd64.
Preparing to unpack .../4-libpwquality1_1.4.4-1_amd64.deb ...
Unpacking libpwquality1:amd64 (1.4.4-1) ...
Selecting previously unselected package libpam-pwquality:amd64.
Preparing to unpack .../5-libpam-pwquality_1.4.4-1_amd64.deb ...
Unpacking libpam-pwquality:amd64 (1.4.4-1) ...
Setting up libpwquality-common (1.4.4-1) ...
Setting up wamerican (2019.10.06-1) ...
Setting up libcrack2:amd64 (2.9.6-3.4) ...
Setting up cracklib-runtime (2.9.6-3.4) ...
Setting up libpwquality1:amd64 (1.4.4-1) ...
Setting up libpam-pwquality:amd64 (1.4.4-1) ...

Progress: [ 92%] [#####################################################################################################.........]
 Package configuration
 ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
┌──────────────────────────────────────────────────────PAM configuration────────────────────────────────────────────────────────┐
│ One or more of the files /etc/pam.d/common-{auth,account,password,session} have been locally modified. Please indicate        │
│ whether these local changes should be overridden using the system-provided configuration. If you decline this option, you     │
│ will need to manage your system's authentication configuration by hand.                                                       │
│                                                                                                                               │
│ Override local changes to /etc/pam.d/common-*?                                                                                │
│                                                                                                                               │
│                                                                                                                               │
├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│                                             < Yes >                       < No  >                                             │
└───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

 Package configuration
 ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
 ┌─────────────────────────────────────────────────────PAM configuration───────────────────────────────────────────────────────┐
 │ Pluggable Authentication Modules (PAM) determine how authentication, authorization, and password changing are handled on    │
 │ the system, as well as allowing configuration of additional actions to take when starting user sessions.                    │
 │                                                                                                                             │
 │ Some PAM module packages provide profiles that can be used to automatically adjust the behavior of all PAM-using            │
 │ applications on the system. Please indicate which of these behaviors you wish to enable.                                    │
 │                                                                                                                             │
 │                                                                                                                             │
 ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
 │                                                         <  OK  >                                                            │
 └─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘








 ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
                                  ┌────────────────────PAM configuration──────────────────────┐
                                  │ PAM profiles to enable:                                   │
                                  │ ┌───────────────────────────────────────────────────────┐ │
                                  │ │[*] Pwquality password strength checking               │ │
                                  │ │[*] Unix authentication                                │ │
                                  │ │[*] Register user sessions in the systemd control group│ │
                                  │ │[ ] Create home directory on login                     │ │
                                  │ └───────────────────────────────────────────────────────┘ │
                                  ├───────────────────────────────────────────────────────────┤
                                  │                 <  OK  >         <Cancel>                 │
                                  └───────────────────────────────────────────────────────────┘



