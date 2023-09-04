---
title: cryptsetup with LUKS
date: 2019-04-10
---

- Initialize a LUKS volume (overwrites all data on the partition):

`cryptsetup luksFormat {{/dev/sdx8}}`

- Open a LUKS volume and create a decrypted mapping at `/dev/mapper/{{target}}`:

`cryptsetup luksOpen {{/dev/sdx8}} {{target}}`

- Remove an existing mapping:

`cryptsetup luksClose {{target}}`

- Change the LUKS volume's passphrase:

`cryptsetup luksChangeKey {{/dev/sdx8}}`

```sh
# aaron@code:~/4t
$ sudo cryptsetup luksFormat /dev/sdb
WARNING: Device /dev/sdb already contains a 'gpt' partition signature.

WARNING!
========
This will overwrite data on /dev/sdb irrevocably.

Are you sure? (Type 'yes' in capital letters): yes
Operation aborted.

# aaron@code:~/4t
$ sudo cryptsetup luksFormat /dev/sdb
WARNING: Device /dev/sdb already contains a 'gpt' partition signature.

WARNING!
========
This will overwrite data on /dev/sdb irrevocably.

Are you sure? (Type 'yes' in capital letters): YES
Enter passphrase for /dev/sdb:
Verify passphrase:
Cannot exclusively open /dev/sdb, device in use.
# aaron@code:~/4t
$ df
Filesystem     Type   1K-blocks        Used Available Use% Mounted on
/dev/sdb3      ext4 13530436560 11957490104 890976588  94% /
/dev/sdb4      vfat      466680         320    466360   1% /boot/efi
# aaron@code:~/4t
$ sudo cryptsetup luksFormat /dev/sda
WARNING: Device /dev/sda already contains a 'gpt' partition signature.

WARNING!
========
This will overwrite data on /dev/sda irrevocably.

Are you sure? (Type 'yes' in capital letters): YES
Enter passphrase for /dev/sda:
Verify passphrase:
# aaron@code:~/4t
$ sudo cryptsetup luksOpen /dev/sda oooo
Enter passphrase for /dev/sda:
# aaron@code:~/4t
$ df
Filesystem     Type   1K-blocks        Used Available Use% Mounted on
/dev/sdb3      ext4 13530436560 11957490248 890976444  94% /
/dev/sdb4      vfat      466680         320    466360   1% /boot/efi
# aaron@code:~/4t
$ sudo moun
mount             mount.fuse        mount.lowntfs-3g  mount.ntfs-3g
mount.exfat-fuse  mount.fuse3       mount.ntfs        mountpoint
# aaron@code:~/4t
$ sudo mount /dev/mapper/oooo /mnt/
mount: /mnt: wrong fs type, bad option, bad superblock on /dev/mapper/oooo, missing codepage or helper program, or other error.
       dmesg(1) may have more information after failed mount system call.
# aaron@code:~/4t
$ sudo mkfs.e /dev/mapper/oooo
mkfs.exfat  mkfs.ext2   mkfs.ext3   mkfs.ext4
# aaron@code:~/4t
$ sudo mkfs.ext4 /dev/mapper/oooo
mke2fs 1.47.0 (5-Feb-2023)
Creating filesystem with 976750549 4k blocks and 244195328 inodes
Filesystem UUID: 620766af-8e55-4d68-a70b-0c2dd6ef5c76
Superblock backups stored on blocks:
        32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632, 2654208,
        4096000, 7962624, 11239424, 20480000, 23887872, 71663616, 78675968,
        102400000, 214990848, 512000000, 550731776, 644972544

Allocating group tables: done
Writing inode tables: done
Creating journal (262144 blocks): done
Writing superblocks and filesystem accounting information: done

# aaron@code:~/4t
$ sudo mount /dev/mapper/oooo /mnt/
# aaron@code:~/4t
$ sudo rsyn
rsync      rsync-ssl
# aaron@code:~/4t
$ sudo rsync -av . /mnt/
sending incremental file list
./
pix/00.jpg
...
```

6.2 How do I backup a LUKS header?

While you could just copy the appropriate number of bytes from the start
of the LUKS partition, the best way is to use command option
"luksHeaderBackup" of cryptsetup.  This protects also against errors
when non-standard parameters have been used in LUKS partition creation.
Example:

    cryptsetup luksHeaderBackup --header-backup-file <file> <device>
To restore, use the inverse command, i.e.

    cryptsetup luksHeaderRestore --header-backup-file <file> <device>
If you are unsure about a header to be restored, make a backup of the
current one first!  You can also test the header-file without restoring
it by using the --header option for a detached header like this:

    cryptsetup --header <file> luksOpen <device> </dev/mapper/name>
If that unlocks your key-slot, you are good. Do not forget to close
the device again.
Under some circumstances (damaged header), this fails.  Then use the
following steps in case it is LUKS1:
First determine the volume (volume) key size:

    cryptsetup luksDump <device>
gives a line of the form

    MK bits:        <bits>
with bits equal to 256 for the old defaults and 512 for the new
defaults.  256 bits equals a total header size of 1'052'672 Bytes and
512 bits one of 2MiB.  (See also Item 6.12) If luksDump fails, assume
2MiB, but be aware that if you restore that, you may also restore the
first 1M or so of the filesystem.  Do not change the filesystem if you
were unable to determine the header size!  With that, restoring a
too-large header backup is still safe.
Second, dump the header to file. There are many ways to do it, I
prefer the following:

    head -c 1052672 <device>  >  header_backup.dmp
or

    head -c 2M <device>  >  header_backup.dmp
for a 2MiB header. Verify the size of the dump-file to be sure.
To restore such a backup, you can try luksHeaderRestore or do a more
basic

    cat header_backup.dmp  >  <device>

6.3 How do I test for a LUKS header?

Use

    cryptsetup -v isLuks <device>
on the device.  Without the "-v" it just signals its result via
exit-status.  You can also use the more general test

    blkid -p <device>
which will also detect other types and give some more info.  Omit
"-p" for old versions of blkid that do not support it.

6.4 How do I backup a LUKS or dm-crypt partition?

There are two options, a sector-image and a plain file or filesystem
backup of the contents of the partition.  The sector image is already
encrypted, but cannot be compressed and contains all empty space.  The
filesystem backup can be compressed, can contain only part of the
encrypted device, but needs to be encrypted separately if so desired.
A sector-image will contain the whole partition in encrypted form, for
LUKS the LUKS header, the keys-slots and the data area.  It can be done
under Linux e.g.  with dd_rescue (for a direct image copy) and with
"cat" or "dd".  Examples:

    cat /dev/sdx80 > sdx80.img
    dd_rescue /dev/sdx80 sdx80.img
You can also use any other backup software that is capable of making a
sector image of a partition.  Note that compression is ineffective for
encrypted data, hence it does not make sense to use it.
For a filesystem backup, you decrypt and mount the encrypted partition
and back it up as you would a normal filesystem.  In this case the
backup is not encrypted, unless your encryption method does that.  For
example you can encrypt a backup with "tar" as follows with GnuPG:

    tar cjf - <path> | gpg --cipher-algo AES -c - > backup.tbz2.gpg
And verify the backup like this if you are at "path":

    cat backup.tbz2.gpg | gpg - | tar djf -
Note: Always verify backups, especially encrypted ones!
There is one problem with verifying like this: The kernel may still have
some files cached and in fact verify them against RAM or may even verify
RAM against RAM, which defeats the purpose of the exercise.  The
following command empties the kernel caches:

    echo 3 > /proc/sys/vm/drop_caches
Run it after backup and before verify.
In both cases GnuPG will ask you interactively for your symmetric key.
The verify will only output errors.  Use "tar dvjf -" to get all
comparison results.  To make sure no data is written to disk
unencrypted, turn off swap if it is not encrypted before doing the
backup.
Restore works like certification with the 'd' ('difference') replaced
by 'x' ('eXtract').  Refer to the man-page of tar for more explanations
and instructions.  Note that with default options tar will overwrite
already existing files without warning.  If you are unsure about how
to use tar, experiment with it in a location where you cannot do damage.
You can of course use different or no compression and you can use an
asymmetric key if you have one and have a backup of the secret key that
belongs to it.
A second option for a filesystem-level backup that can be used when the
backup is also on local disk (e.g.  an external USB drive) is to use a
LUKS container there and copy the files to be backed up between both
mounted containers.  Also see next item.

## 10.4  Why use Argon2 in LUKS 2 instead of PBKDF2?

LUKS tries to be secure with not-so-good passwords.  Bad passwords need to
be protected in some way against an attacker that just tries all possible
combinations.  (For good passwords, you can just wait for the attacker to
die of old age...) The situation with LUKS is not quite the same as with a
password stored in a database, but there are similarities.
LUKS does not store passwords on disk.  Instead, the passwords are used to
decrypt the volume-key with it and that one is stored on disk in encrypted
form.  If you have a good password, with, say, more than 80 bits of
entropy, you could just put the password through a single crypto-hash (to
turn it into something that can be used as a key) and that would be secure.
This is what plain dm-crypt does.
If the password has lower entropy, you want to make this process cost some
effort, so that each try takes time and resources and slows the attacker
down.  LUKS1 uses PBKDF2 for that, adding an iteration count and a salt.
The iteration count is per default set to that it takes 1 second per try on
the CPU of the device where the respective passphrase was set.  The salt is
there to prevent precomputation.
The problem with that is that if you use a graphics card, you can massively
speed up these computations as PBKDF2 needs very little memory to compute
it.  A graphics card is (grossly simplified) a mass of small CPUs with some
small very fast local memory per CPU and a large slow memory (the 4/6/8 GB
a current card may have).  If you can keep a computation in the small,
CPU-local memory, you can gain a speed factor of 1000 or more when trying
passwords with PBKDF2.
Argon2 was created to address this problem.  It adds a "large memory
property" where computing the result with less memory than the memory
parameter requires is massively (exponentially) slowed down.  That means,
if you set, for example, 4GB of memory, computing Argon2 on a graphics card
with around 100kB of memory per "CPU" makes no sense at all because it is
far too slow.  An attacker has hence to use real CPUs and furthermore is
limited by main memory bandwidth.
Hence the large amount of memory used is a security feature and should not
be turned off or reduced.  If you really (!) understand what you are doing
and can assure good passwords, you can either go back to PBKDF2 or set a
low amount of memory used for Argon2 when creating the header.

10.5 LUKS2 is insecure! It uses less memory than the Argon2 RFC say!

Well, not really.  The RFC recommends 6GiB of memory for use with disk
encryption.  That is a bit insane and something clearly went wrong in the
standardization process here.  First, that makes Argon2 unusable on any 32
bit Linux and that is clearly a bad thing.  Second, there are many small
Linux devices around that do not have 6GiB of RAM in the first place.  For
example, the current Raspberry Pi has 1GB, 2GB or 4GB of RAM, and with the
RFC recommendations, none of these could compute Argon2 hashes.
Hence LUKS2 uses a more real-world approach.  Iteration is set to a
minimum of 4 because there are some theoretical attacks that work up to an
iteration count of 3.  The thread parameter is set to 4.  To achieve 2
second/slot unlock time, LUKS2 adjusts the memory parameter down if
needed.  In the other direction, it will respect available memory and not
exceed it.  On a current PC, the memory parameter will be somewhere around
1GB, which should be quite generous.  The minimum I was able to set in an
experiment with "-i 1" was 400kB of memory and that is too low to be
secure.  A Raspberry Pi would probably end up somewhere around 50MB (have
not tried it) and that should still be plenty.
That said, if you have a good, high-entropy passphrase, LUKS2 is secure
with any memory parameter



----

cryptsetup -s 512 --batch-mode --force-password --type luks2 luksFormat /dev/md126p2
cryptsetup -s 512 --batch-mode --force-password --type luks2 luksFormat /dev/md126p2
cryptsetup -s 512 --batch-mode --force-password --type luks2 luksFormat /dev/md126p2
cryptsetup -s 512 --batch-mode --force-password --type luks2 luksFormat /dev/md126p2

cryptsetup luksFormat /dev/sdc3

cryptsetup open /dev/sdc3 lilybackup

最后的参数是一个名字，它会是解密后的设备在 /dev/mapper 下的文件名。

如果一切完毕，要记得（在卸载文件系统之后）关闭该设备：

cryptsetup luksClose lilybackup

dm-crypt 是块设备级的加密。我们还要在其上建立文件系统：

mkfs.btrfs /dev/mapper/lilybackup


```
# cryptsetup luksOpen /dev/sda barn
Enter passphrase for /dev/sda:
device-mapper: reload ioctl on barn (254:1) failed: No such file or directory

# pacman -S device-mapper
resolving dependencies...
looking for conflicting packages...

Packages (1) device-mapper-2.03.14-2

Total Installed Size:  0.83 MiB
Net Upgrade Size:      0.00 MiB

:: Proceed with installation? [Y/n]
(1/1) checking keys in keyring                                                                  [########################################################] 100%
(1/1) checking package integrity                                                                [########################################################] 100%
(1/1) loading package files                                                                     [########################################################] 100%
(1/1) checking for file conflicts                                                               [########################################################] 100%
(1/1) checking available disk space                                                             [########################################################] 100%
:: Processing package changes...
(1/1) reinstalling device-mapper                                                                [########################################################] 100%
:: Running post-transaction hooks...
(1/4) Reloading system manager configuration...
(2/4) Reloading device manager configuration...
(3/4) Arming ConditionNeedsUpdate...
(4/4) Updating linux initcpios...
==> Building image from preset: /etc/mkinitcpio.d/linux510.preset: 'default'
  -> -k /boot/vmlinuz-5.10-x86_64 -c /etc/mkinitcpio.conf -g /boot/initramfs-5.10-x86_64.img
==> Starting build: 5.10.86-1-MANJARO
  -> Running build hook: [base]
  -> Running build hook: [udev]
  -> Running build hook: [autodetect]
  -> Running build hook: [modconf]
  -> Running build hook: [block]
  -> Running build hook: [keyboard]
  -> Running build hook: [keymap]
  -> Running build hook: [encrypt]
  -> Running build hook: [filesystems]
  -> Running build hook: [fsck]
==> Generating module dependencies
==> Creating gzip-compressed initcpio image: /boot/initramfs-5.10-x86_64.img
==> Image generation successful
==> Building image from preset: /etc/mkinitcpio.d/linux510.preset: 'fallback'
  -> -k /boot/vmlinuz-5.10-x86_64 -c /etc/mkinitcpio.conf -g /boot/initramfs-5.10-x86_64-fallback.img -S autodetect
==> Starting build: 5.10.86-1-MANJARO
  -> Running build hook: [base]
  -> Running build hook: [udev]
  -> Running build hook: [modconf]
  -> Running build hook: [block]
  -> Running build hook: [keyboard]
  -> Running build hook: [keymap]
  -> Running build hook: [encrypt]
  -> Running build hook: [filesystems]
  -> Running build hook: [fsck]
==> Generating module dependencies
==> Creating gzip-compressed initcpio image: /boot/initramfs-5.10-x86_64-fallback.img
==> Image generation successful
```

```
# cryptsetup luksOpen /dev/sda barn
 Enter passphrase for /dev/sda:
 device-mapper: reload ioctl on barn (254:1) failed: No such file or directory
```

```
Default compiled-in metadata format is LUKS2 (for luksFormat action).

LUKS2 external token plugin support is compiled-in.
LUKS2 external token plugin path: /usr/lib/cryptsetup.

Default compiled-in key and passphrase parameters:
        Maximum keyfile size: 8192kB, Maximum interactive passphrase length 512 (characters)
Default PBKDF for LUKS1: pbkdf2, iteration time: 2000 (ms)
Default PBKDF for LUKS2: argon2id
        Iteration time: 2000, Memory required: 1048576kB, Parallel threads: 4

Default compiled-in device cipher parameters:
        loop-AES: aes, Key 256 bits
        plain: aes-cbc-essiv:sha256, Key: 256 bits, Password hashing: ripemd160
        LUKS: aes-xts-plain64, Key: 256 bits, LUKS header hashing: sha256, RNG: /dev/urandom
        LUKS: Default keysize with XTS mode (two internal keys) will be doubled.
```


    Copy NOS rootfs and NOS kernel and initrd to flash inside the switch;
    Create NOS partitions in USB drive;
    Start NOS kernel and mount initrd;
    Encrypt NOS partitions in USB driver by using cryptsetup with the unique ID as passphrase;
    Mount encrypted NOS partitions;
    Extract NOS rootfs tarball to NOS partitions;
    Change root to NOS rootfs;

Keep the passphrase key in a separate partition on the internal flash

This way the key stays constant across active and standby partitions on the usb and upgrade workflows.

My recommendation is to not generate it using any algorithm, that is akin to a system with default login password. Use a random 256 byte passphrase.

## cryptsetup

: cryptsetup-luks

 /etc/default/cryptdisks 756141f7eacf1a272a2f6e51646b3aa4
 /etc/init.d/cryptdisks 20b58baefc1aed5021a28e2fb9439edd
 /etc/init.d/cryptdisks-early 9c58f4b1314fe50c79ec0caff22bf298
 /etc/init/cryptdisks-udev.conf ed789690d1770e3f3a2682c11e359bb6
 /etc/init/cryptdisks.conf e5527ceb5c020174a6464b81126bb5f7

 Cryptsetup provides an interface for configuring encryption on block
 devices (such as /home or swap partitions), using the Linux kernel
 device mapper target dm-crypt. It features integrated Linux Unified Key
 Setup (LUKS) support.
 .
 Cryptsetup is backwards compatible with the on-disk format of cryptoloop,
 but also supports more secure formats. This package includes support for
 automatically configuring encrypted devices at boot time via the config
 file /etc/crypttab. Additional features are cryptoroot support through
 initramfs-tools and several supported ways to read a passphrase or key.
Homepage: http://code.google.com/p/cryptsetup/
Original-Maintainer: Debian Cryptsetup Team <pkg-cryptsetup-devel@lists.alioth.debian.org>
