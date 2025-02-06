---
title: "df: /run/user/1000/doc: Operation not permitted"
date: 2021-02-22T20:16:39+08:00
---

Whats up?

```
$ df
df: /run/user/1000/doc: Operation not permitted
...
```

check

```
dr-x------ 2 aaron aaron 0 Jan  1  1970 /run/user/1000/doc
```

and

```
drwx------ 10 aaron aaron 300 Jun  8 17:50 /run/user/1000
```
any ps doc?

```
root        4003  0.0  0.2 1826056 15800 ?       Ssl  May27  13:13 /usr/sbin/dockerd -H fd://
aaron       3724  0.0  0.0 683664   596 ?        Ssl  May27   0:01 /usr/libexec/xdg-document-portal
```

xdg?

```
aaron       3719  0.0  0.0 601976   924 ?        Ssl  May27   0:01 /usr/libexec/xdg-desktop-portal
aaron       3724  0.0  0.0 683664   596 ?        Ssl  May27   0:01 /usr/libexec/xdg-document-portal
aaron       3728  0.0  0.0 240396    96 ?        Ssl  May27   0:00 /usr/libexec/xdg-permission-store
aaron     963837  0.0  0.0   2600    48 ?        S    Jun07   0:00 /bin/sh /bin/xdg-open https://github.com/balena-io/etcher/blob/master/SUPPORT.md
```

Workaround:

```shell
$ sudo killall xdg-document-portal
```

OK now.

# Upstream solutions

- https://github.com/coreutils/gnulib/pull/11

> This corrects a problem that affects users with fuse.portal mounts

> This is a significant problem for users who depend on df not returning an error exit code in their scripts.

gnulib/lib/mountlist.c

```diff
 #define ME_DUMMY_0(Fs_name, Fs_type)            \
   (strcmp (Fs_type, "autofs") == 0              \
+   || strcmp (Fs_type, "devtmpfs") == 0         \
+   || strcmp (Fs_type, "fuse.portal") == 0      \
    || strcmp (Fs_type, "proc") == 0             \
+   || strcmp (Fs_type, "squashfs") == 0         \
    || strcmp (Fs_type, "subfs") == 0            \
    /* for Linux 2.6/3.x */                      \
    || strcmp (Fs_type, "debugfs") == 0          \
```

# Related

- https://bugs.launchpad.net/ubuntu/+source/xdg-desktop-portal/+bug/1905623

> /run/user/1000/doc is a fuse.portal mount point, but statfs() return EPERM, hence df produces an error message.

and

> The upstream bug is closed as working-as-designed, but this is impactful to anything that expects ```df``` to exit 0 as a non-root user.

and

> You can silence this with `df -x fuse.portal`

> xdg-desktop-portal isn't tied to flatpak.

and

> Whatever is putting the mountpoint there (it's not my choice) should be putting it there in such a way that this does not happen. I *own* the mountpoint directory and file-system. Why should I get an EPERM error that I cannot remove?

and

> If you don't want to this fuse fs to be created then either remove xdg-desktop-portal package or mask xdg-document-portal.service with:

>     systemctl --user mask xdg-document-portal.service

and at last

> This bug was fixed in the package coreutils - 8.32-4ubuntu2

> coreutils (8.32-4ubuntu2) hirsute; urgency=medium
>
>   * d/p/treat-devtmpfs-and-squashfs-as-dummy-filesystems.patch:
>     - Extend default filesystem exlusion to fuse.portal (LP: #1905623)
>
>  -- Julian Andres Klode <juliank@ubuntu.com> Sat, 05 Dec 2020 21:55:44 +0100

- https://git.launchpad.net/ubuntu/+source/coreutils/commit/?id=6cba9c1011aa2010aadc46c2b288e9fd8ba781c5

Patch to debian/patches/treat-devtmpfs-and-squashfs-as-dummy-filesystems.patch

```patch
coreutils/lib/mountlist.c
  #define ME_DUMMY_0(Fs_name, Fs_type)            \
    (strcmp (Fs_type, "autofs") == 0              \
 +   || strcmp (Fs_type, "devtmpfs") == 0         \
++   || strcmp (Fs_type, "fuse.portal") == 0      \
     || strcmp (Fs_type, "proc") == 0             \
 +   || strcmp (Fs_type, "squashfs") == 0         \
     || strcmp (Fs_type, "subfs") == 0            \
```

- https://github.com/flatpak/xdg-desktop-portal/issues/512

The fetal thing is that:
> Various system automation scripts break down as the result (scripts relying on df returning code 0).

more
> I get the error on /root/.cache/doc, not just /run/user/1000/doc. Looking at the pstree, I see a process with parent id 1 xdg-document-portal:

```
root     1836537       1  0 Sep29 ?        00:00:00 /usr/libexec/xdg-document-portal
root     1836549 1836537  0 Sep29 ?        00:00:00 fusermount -o rw,nosuid,nodev,fsname=portal,auto_unmount,subtype=portal -- /root/.cache/doc
```

> Doing a systemctl status on that PID shows it is associated with my normal user session, not with any type of root session:

```
# systemctl status 1836537
● session-3.scope - Session 3 of user raman
     Loaded: loaded (/run/systemd/transient/session-3.scope; transient)
  Transient: yes
     Active: active (running) since Fri 2020-09-25 14:14:52 EDT; 1 weeks 4 days ago
      Tasks: 4031
     Memory: 33.9G
        CPU: 1w 2d 5h 34min 12.490s
     CGroup: /user.slice/user-1000.slice/session-3.scope
...
```

same to me

> Just a random user here, and I can confirm. I got this error when I tried running my script which uses df.

> I stopped the service:

>    systemctl --user stop xdg-document-portal.service and df -hT worked fine.

> Particular case, but since I don't use flatpak here I will be removing it.

```bash
# mount | fgrep doc
portal on /root/.cache/doc type fuse.portal (rw,nosuid,nodev,relatime,user_id=0,group_id=0)
```

- https://github.com/flatpak/xdg-desktop-portal/issues/553

> Ubuntu is going to fix this in df

- https://github.com/flatpak/flatpak/issues/3660#issuecomment-665967687

> What happens here is that df tries to use statfs call on all mountpoints but that's being denied in default config for fuse filesystems which is what /run/user/1000/doc is. There is no bug here, just things working as expected.

> You may easily reproduce it with `stat -f /run/user/1000/doc`.

> If you desperately want to get rid of Operation not permitted message then run df as root, i.e. sudo df

# Update

- https://git.savannah.gnu.org/gitweb/?p=gnulib.git;a=blob;f=lib/mountlist.c

Latest gnulib/lib/mountlist.c

```c
 164 #define ME_DUMMY_0(Fs_name, Fs_type)            \
 165   (strcmp (Fs_type, "autofs") == 0              \
 166    || strcmp (Fs_type, "proc") == 0             \
 167    || strcmp (Fs_type, "subfs") == 0            \
 168    /* for Linux 2.6/3.x */                      \
 169    || strcmp (Fs_type, "debugfs") == 0          \
 170    || strcmp (Fs_type, "devpts") == 0           \
 171    || strcmp (Fs_type, "fusectl") == 0          \
 172    || strcmp (Fs_type, "fuse.portal") == 0      \
 173    || strcmp (Fs_type, "mqueue") == 0           \
 174    || strcmp (Fs_type, "rpc_pipefs") == 0       \
 175    || strcmp (Fs_type, "sysfs") == 0            \
 176    /* FreeBSD, Linux 2.4 */                     \
 177    || strcmp (Fs_type, "devfs") == 0            \
 178    /* for NetBSD 3.0 */                         \
 179    || strcmp (Fs_type, "kernfs") == 0           \
 180    /* for Irix 6.5 */                           \
 181    || strcmp (Fs_type, "ignore") == 0)
 182
 183 /* Historically, we have marked as "dummy" any file system of type "none",
 184    but now that programs like du need to know about bind-mounted directories,
 185    we grant an exception to any with "bind" in its list of mount options.
 186    I.e., those are *not* dummy entries.  */
 187 #ifdef MOUNTED_GETMNTENT1
 188 # define ME_DUMMY(Fs_name, Fs_type, Bind)       \
 189   (ME_DUMMY_0 (Fs_name, Fs_type)                \
 190    || (strcmp (Fs_type, "none") == 0 && !Bind))
 191 #else
 192 # define ME_DUMMY(Fs_name, Fs_type)             \
 193   (ME_DUMMY_0 (Fs_name, Fs_type) || strcmp (Fs_type, "none") == 0)
 194 #endif
```

- https://unix.stackexchange.com/a/162911/100768

> /run/user/$uid is created by pam_systemd and used for storing files used by running processes for that user. These might be things such as your keyring daemon, pulseaudio, etc.
>
> Prior to systemd, these applications typically stored their files in /tmp. They couldn't use a location in /home/$user as home directories are often mounted over network filesystems, and these files should not be shared among hosts. /tmp was the only location specified by the FHS which is local, and writable by all users.
>
> However storing all these files in /tmp is problematic as /tmp is writable by everyone, and while you can change the ownership & mode on the files being created, it's more difficult to work with.
>
> So systemd came along and created /run/user/$uid. This directory is local to the system and only accessible by the target user. So applications looking to store their files locally no longer have to worry about access control. > It also keeps things nice and organized. When a user logs out, and no active sessions remain, pam_systemd will wipe the /run/user/$uid directory out. With various files scattered around /tmp, you couldn't do this.
>
