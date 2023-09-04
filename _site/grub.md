

set gfxpayload=text # ~= vga='normal'
  # isofile_abspath is relative to LiveUSB root.
  set isofile_abspath='/ISOs/clonezilla-live-2.4.2-10-i586.iso'
  # isofile_devpath is relative to (and begins with) "/dev"
  set isofile_devpath="${devroot}${isofile_abspath}"
  # "mount" the ISO
  loopback loop "(${root})${isofile_abspath}"
  # Following (single!) line adapted from ISO's menuentry='Clonezilla Live (Failsafe mode)' and
  # from https://wiki.archlinux.org/index.php/Multiboot_USB_drive#GParted_Live
  linux '(loop)/live/vmlinuz' boot='live' union='overlay' username='user' config components noswap edd='on' nomodeset nodmraid noeject locales='' keyboard-layouts='' ocs_live_run='ocs-live-general' ocs_live_extra_param='' ocs_live_batch='no' ip='' acpi='off'irqpoll noapic noapm nodma nomce nolapic nosmp nomodeset nosplash findiso="${isofile_abspath}"
  # start RAMdisk from device=loop
  initrd '(loop)/live/initrd.img'





linux '(loop)/live/vmlinuz' boot='live' union='overlay' username='user' config components noswap noeject toram='filesystem.squashfs' ip='' nosplash findiso="${isofile_abspath}"
  


linux (loop)/isolinux/rescue64 setkmap=us isoloop=$isofile





grub-install --force --removable --no-floppy --boot-directory=/mnt/target/boot --efi-directory=/mnt/target/EFI/BOOT "$2"
grub-install --force --removable --no-floppy --boot-directory=/mnt/target/boot "$2"




menuentry "Ubuntu 23.04 desktop ISO" {
   set isofile="/home/<username>/Downloads/ubuntu-23.04-desktop-amd64.iso"
   # or set isofile="/<username>/Downloads/ubuntu-23.04-desktop-amd64.iso"
   # if you use a single partition for your $HOME
   rmmod tpm
   loopback loop (hd0,5)$isofile
   linux (loop)/casper/vmlinuz boot=casper layerfs-path=minimal.standard.live.squashfs iso-scan/filename=$isofile
   initrd (loop)/casper/initrd
}



linux /casper/vmlinuz boot=casper iso-scan/filename=/<ISO-name.iso> noprompt noeject toram --












Pull requests
Repositories
Projects
Search


install_resizable_encrypted_LMDE
Source
Commits
Branches
Pull requests
Pipelines
Deployments
Issues
Jira issues
Security
Wiki
Downloads

Tom Roche
Untitled project
install_resizable_encrypted_LMDE
create_LMDE_liveUSB.rst

Pull requests

Check out
extend the Linux Mint Debian Edition installer to create resizable, encrypted partitions/volumes


Source

source:master


ecc716a
Full commit
install_resizable_encrypted_lmde/
create_LMDE_liveUSB.rst


Edit

Create a LiveUSB with bootable utilities
Table of Contents

summary
glossary
preparation
checking downloaded ISOs
check correctness
check provenance
configure target
get target drive designator
lsblk
inxi
fdisk
blank target
create target partitions
GUI
commandline
install GRUB2 on target
populate target ISO directory
inspect internal structure of ISOs
create target grub.cfg
target grub.cfg
test target
test procedure
test results
TODOs
summary
The following instructs how to make a LiveUSB on a USB drive (aka, the target) containing several, independently-bootable ISO files, including

Clonezilla
GParted
LMDE2/Betsy for Cinnamon and MATE
Mint Rebecca for XFCE. (XFCE not currently available for LMDE, IIUC)
This version uses GRUB2 to boot the ISOs, and is expanded from a Mint tutorial. To add an ISO to the LiveUSB,

Copy the ISO file to your specified directory on your LiveUSB's filesystem.
Add a stanza appropriate to that ISO (and how you wish to boot it) to your grub.cfg.
glossary
target: the USB-connected harddrive which you want to transform into a LiveUSB, i.e., you want it to allow an attached host to boot from it.
host: the LMDE workstation to which the target will be attached while you make the target into a LiveUSB. (The host is assumed to run LMDE below, but probably any Debian flavor will work, and these instructions should be easily translatable to other Linux distros.)
drive designator (or physical drive designator): a path to a device file representing, in this case, your target. It will start with /dev/; the second/final segment of the path will probably begin with sd and end with a single lowercase letter. In my examples below, the drive designator is /dev/sdb. Note that this physical drive designator must be distinguished from the logical partitions or filesystems which reside on the drive: these are designated by a path to a device file that ends with a digit. If /dev/sdb has only one partition (as is assumed in the examples below), that filesystem is designated by /dev/sdb1; additional partitions would be designated /dev/sdb2, /dev/sdb3, and so on.
preparation
Find the ISOs you want to be able to boot. This task is beyond the scope of this article.

Get a target onto which to install which

is empty (or make it so)
contains enough space for all the ISOs you want to {boot from, host on} it. Note that, as of mid-2015, LMDE2 ISO files each (for all versions, regardless of width (32- or 64-bit) or desktop manager) have size ~= 1.5 GB.
Prepare your host. In addition to running LMDE (or similar Debian-based OS), the host will need the following commands:

Various standard utilities, such as fdisk, less, umount, etc. Your host should already have these.

fdisk requires root, so test for it (and any other command that requires root) with sudo which
gparted, provided by package=gparted (also requires root)

grub-install, provided by package=grub2-common (requires root)

Older systems may instead require package=grub-legacy, which conflicts with package= grub2-common
(recommended but not required) inxi, provided by package=inxi (only since Jessie)

udisks, provided by package=udisks

Get good networking. You'll want a network connection that

does not have a bandwidth limit (e.g., 10 GB/mo).
is fast (though your source mirror or torrent may not support much more than 1 MB/s)
Mount the target on the host--normally it will automount after you attach it to your host's USB port.

checking downloaded ISOs
You obviously don't want corrupted or hacked ISOs, so you should verify their provenance (via PGP signatures) and correctness (via hashes or checksums). One well-worked example for verifying both is provided by Apache. Following I provide a bash example for GParted, since the GParted download page makes necessary information readily available, but does so slightly differently than Apache (above).

check correctness
Download the GParted hashes file locally. For this example, I will use declare -r DOWNLOAD_DIR='/tmp/gparted' (change as desired):

# set these as needed
declare -r GPARTED_HASHES_URI='https://gparted.sourceforge.io/gparted-live/stable/CHECKSUMS.TXT'
declare -r DOWNLOAD_DIR='/tmp/gparted'

# these are calculated from previous: don't touch!
declare -r GPARTED_HASHES_FN="$(basename "${GPARTED_HASHES_URI}")"
declare -r GPARTED_HASHES_FP="${DOWNLOAD_DIR}/${GPARTED_HASHES_FN}"

# actual work
mkdir -p "${DOWNLOAD_DIR}/"
curl --location --continue-at - --output "${GPARTED_HASHES_FP}" "${GPARTED_HASHES_URI}"
ls -al "${GPARTED_HASHES_FP}"
Create a correct hashfile for your previously-downloaded ISO file. Change following as needed:

# set these as needed
declare -r ISO_FN='gparted-live-1.0.0-5-amd64.iso'

# don't touch this: GParted structures their file-of-hashes so as to make this difficult to calculate
declare -r ISO_HASH_FULL='sha512'

# these are calculated from previous: don't touch!
declare -r ISO_FP="${DOWNLOAD_DIR}/${ISO_FN}"
declare -r ISO_HASH_N="${ISO_HASH_FULL#sha}"
declare -r ISO_HASH_FP="${ISO_FP}.${ISO_HASH_FULL}"

# populate the particular ISO's hashfile correctly from the file of all hashes.
# the `tail` call is necessary to match method=sha512 specified above.
fgrep -e "${ISO_FN}" "${GPARTED_HASHES_FP}" | tail -n 1 > "${ISO_HASH_FP}"
ls -al "${ISO_HASH_FP}"
cat "${ISO_HASH_FP}"
Verify the ISO using the hashfile:

# note this fails!
# shasum --algorithm "${ISO_HASH_N}" --check "${ISO_HASH_FP}"
# instead gotta do
pushd "${DOWNLOAD_DIR}/"
shasum --algorithm "${ISO_HASH_N}" --check "${ISO_HASH_FN}"
popd
You should get (after slight delay, depending on your local compute power) result like

gparted-live-1.0.0-5-amd64.iso: OK
check provenance
DON'T USE YET! THIS IS BROKEN! I AM CONFUSED!

Download the GParted hashes file and the GParted hashes-file signature file locally. This example uses same DOWNLOAD_DIR as above (change as desired):

declare -r GPARTED_HASHES_URI='https://gparted.sourceforge.io/gparted-live/stable/CHECKSUMS.TXT'
declare -r GPARTED_HASHES_SIG_URI='https://gparted.sourceforge.io/gparted-live/stable/CHECKSUMS.TXT.gpg'
declare -r DOWNLOAD_DIR='/tmp/gparted'

declare -r GPARTED_HASHES_FN="$(basename "${GPARTED_HASHES_URI}")"
declare -r GPARTED_HASHES_FP="${DOWNLOAD_DIR}/${GPARTED_HASHES_FN}"
declare -r GPARTED_HASHES_SIG_FN="$(basename "${GPARTED_HASHES_SIG_URI}")"
declare -r GPARTED_HASHES_SIG_FP="${DOWNLOAD_DIR}/${GPARTED_HASHES_SIG_FN}"

mkdir -p "${DOWNLOAD_DIR}/"
curl --location --continue-at - --output "${GPARTED_HASHES_FP}" "${GPARTED_HASHES_URI}"
ls -al "${GPARTED_HASHES_FP}"
curl --location --continue-at - --output "${GPARTED_HASHES_SIG_FP}" "${GPARTED_HASHES_SIG_URI}"
ls -al "${GPARTED_HASHES_SIG_FP}"
Get the GParted maintainer's signature file from his public key: I'll use the openpgp.org public-key link since it's usually more responsive. Browse to that link, download the signature file to DOWNLOAD_DIR, and change the following as needed:

declare -r GPARTED_SIG_FP='/tmp/gparted/EB1DD5BF6F88820BBCF5356C8E94C9CD163E3FB0.asc'
declare -r GPARTED_SIG_FN="$(basename "${GPARTED_SIG_FP}")"
declare -r KEY_FINGERPRINT="${GPARTED_SIG_FN%%.asc}"
gpg --verify "${GPARTED_SIG_FP}" ...... FAIL! I am confused ......
configure target
get target drive designator
Be sure your host is modifying the target, not one of its own drives! You should be able to determine the target's physical drive designator this by running either of the following (as well as many other standard utilities)

lsblk
lsblk is a standard tool that gives useful drive-usage and -layout information in a relatively compressed format. E.g., on one of my current devices (with some clarifying notes added (manually) inside square brackets):

me@it:~ $ lsblk
NAME                  MAJ:MIN RM   SIZE RO TYPE  MOUNTPOINT
sda                     8:0    0 465.8G  0 disk
├─sda1                  8:1    0  16.6G  0 part  [pre-installed Windows system drive]
├─sda2                  8:2    0  97.7G  0 part  [pre-installed Windows apps drive]
├─sda3                  8:3    0   500M  0 part  /boot
└─sda5                  8:5    0   351G  0 part
  └─LVM2_crypt        254:0    0   351G  0 crypt
    ├─LVM2_crypt-swap 254:1    0   3.9G  0 lvm
    ├─LVM2_crypt-root 254:2    0    20G  0 lvm   / [all but {/boot , /home , swap}]
    └─LVM2_crypt-home 254:3    0 327.1G  0 lvm   /home
sr0                    11:0    1  1024M  0 rom
inxi
inxi -Dpl -c0 has the advantage of showing both the mount point(s) (currently, under /media by default) for the target's partition(s) as well as its drive designator, allowing for a bit more certainty in definition. (Note that we're assuming you've mounted your target.) For this example, we can determine the target's drive designator= /dev/sdb from the relevant output fragment:

Drives:    HDD Total Size: 580.1GB (52.1% used) 1: id: /dev/sda model: ST9500420AS size: 500.1GB
           2: USB id: /dev/sdb model: 0G9AT00 size: 80.0GB
Partition: ID: / size: 20G used: 7.6G (41%) fs: ext4 dev: /dev/dm-2 label: root
           ID: /boot size: 485M used: 33M (8%) fs: ext2 dev: /dev/sda3 label: boot
           ID: /home size: 322G used: 248G (78%) fs: ext4 dev: /dev/dm-3 label: home
           ID: /media/me/LaCie_USB2 size: 75G used: 27G (36%) fs: fuseblk dev: /dev/sdb1 label: LaCie_USB2
           ID: swap-1 size: 4.19GB used: 0.39GB (9%) fs: swap dev: /dev/dm-1 label: swap
inxi helpfully guesses which drive is USB, noting its drive designator= /dev/sdb. We confirm that designation by noting the partition device path= /dev/sdb1 matching the target's mount point= /media/me/LaCie_USB2 also matches the drive designator with a digit appended.

fdisk
sudo fdisk -l | less gives lots output, so scroll through it. Devices listed at the beginning (typically Disk /dev/sda) are probably drives fixed on the host (e.g., the "non-removable" harddrive installed on your laptop). For this example, the relevant output (towards the end) is

Disk /dev/sdb: 80.0 GB, 80026361856 bytes
255 heads, 63 sectors/track, 9729 cylinders, total 156301488 sectors
Units = sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disk identifier: 0x12345678

   Device Boot      Start         End      Blocks   Id  System
/dev/sdb1              63   156296384    78148161    7  HPFS/NTFS/exFAT
Again, my target's drive designator= /dev/sdb.

blank target
This section

is optional. However it can prevent subsequent problems, but it also ...
is dangerous--be sure you know your target's drive designator! You very much do not want to blank your host's hard drive(s).
may be unduly time-consuming. Ensure that you can allocate enough time for the operation to finish without (e.g.) sleeping your host or disconnecting your target.
Edit and run the following bash scriptlet:

TARGET_DRIVE_DESIGNATOR='/dev/sdb' # edit this appropriately!
TARGET_BLOCK_SIZE='4096' # edit appropriately, but note that 4096==4kb is the standard block size for ext* filesystems on x86 hardware

if   [[ -z "${TARGET_DRIVE_DESIGNATOR}" ]] ; then
    echo -e 'ERROR: TARGET_DRIVE_DESIGNATOR not defined, exiting ...'
# note `-b` assumes that target is a block device
elif [[ ! -b "${TARGET_DRIVE_DESIGNATOR}" ]] ; then
    echo -e "ERROR: target drive designator='${TARGET_DRIVE_DESIGNATOR}' not found, exiting ..."
else
    TARGET_START="$(date)"
    echo -e "START=${TARGET_START}"

    # Checks your target. Remove this stanza if you lack `inxi`.
    for CMD in \
        "inxi -Dpl -c0 | fgrep -e ${TARGET_DRIVE_DESIGNATOR}" \
    ; do
        echo -e "${CMD}"
        eval "${CMD}"
    done

    # The payload: this writes 0-bytes all over your target drive.
    for CMD in \
        "sudo dd if=/dev/zero of=${TARGET_DRIVE_DESIGNATOR} bs=${TARGET_BLOCK_SIZE}" \
    ; do
        echo -e "${CMD}"
        # uncomment following line only AFTER you see appropriate output from `inxi` AND an appropriate commandline
        # eval "${CMD}"
    done

    # Crude timing, for future reference.
    echo # newline
    echo -e "  END=$(date)"
    echo -e "START=${TARGET_START}"
fi
My 80 GB USB2 target took ~45 min to blank: output from scriptlet above ended with

dd: error writing ‘/dev/sdb’: No space left on device
19537687+0 records in
19537686+0 records out
80026361856 bytes (80 GB) copied, 2769.8 s, 28.9 MB/s

  END=Sat Jun  6 18:56:31 EDT 2015
START=Sat Jun  6 18:10:21 EDT 2015
Check to see that the target is blanked by

Ensure the target is unmounted, e.g.,

me@host:~$ umount /media/me/LaCie_USB2
umount: /media/me/LaCie_USB2 is not in the fstab (and you are not root)
Disconnect the target from the host, then reconnect: you should not see the usual mount behavior.

Check that both

the target is still found as a physical device
the target's partition(s) no longer exist
e.g.,

me@host:~$ inxi -Dpl -c0
Drives:    HDD Total Size: 580.1GB (47.3% used) 1: id: /dev/sda model: ST9500420AS size: 500.1GB
           2: USB id: /dev/sdb model: 0G9AT00 size: 80.0GB
Partition: ID: / size: 20G used: 7.6G (41%) fs: ext4 dev: /dev/dm-2 label: root
           ID: /boot size: 485M used: 33M (8%) fs: ext2 dev: /dev/sda3 label: boot
           ID: /home size: 322G used: 248G (78%) fs: ext4 dev: /dev/dm-3 label: home
           ID: swap-1 size: 4.19GB used: 0.39GB (9%) fs: swap dev: /dev/dm-1 label: swap
create target partitions
Be sure to edit the following commands appropriately for your situation. In this example, I seek to create a single partition= /dev/sdb1 on target drive designator= /dev/sdb.

GUI
GParted is quite possibly the standard graphical tool for tasks such as this, and has a well-deserved reputation for excellence. It does not provide all the options that commandline tools do (see next section), but what one loses in flexibility one gains in ease of use.

Run GParted with, e.g., gksudo gparted &

In the dropdown @ upper right of the GUI, pulldown to select your target's drive designator.

In the partition table (large area at bottom of GUI), there should be only one record (i.e., row) corresponding to a partition (better, unallocated space) on your target. Click on the record to select it.

Ensure it is unmounted by right-clicking on the record. If the resulting context menu contains item= Unmount, click that; otherwise exit.

Create a new partition table on the target. From the GParted main menu (@ top of GUI), select Device > Create Partition Table and take the default partition table type= msdos. Click button= Apply.

Create a new partition. Right-click on the record; from the resulting context menu, choose New. In the resulting dialog title= Create new Partition,

choose File system:= ext2. That's the default: you probably want to choose a non-journaling filesystem to maximize the target's useful lifetime. However ext2 is increasingly obsolete: consider using another tool to create a non-journaling ext4 as described here.
allow that partition to consume all available space
give the drive a label: I'll use label= LiveUSBmultiISO
You should see 1 operation pending in the GParted statusline (@ bottom left of the GUI). Commit that operation: from the GParted main menu, choose Edit > Apply All Operations, and wait for the operation to complete. (This took ~1 min on my 80 GB USB2 target.) Close the resulting dialog.

Right-click the resulting record (now for partition= /dev/sdb1) and choose from the resulting context menu Manage Flags. In the resulting dialog, select flag= boot and close the dialog.

By this point, you may notice that the label you previously set has disappeared from the record (and therefore from the partition). If so,

Right-click the record, and choose= Label from the resulting context menu.
In the resulting dialog, enter your label, and click button= OK.
You should see 1 operation pending in the GParted statusline; commit the operation, and close the resulting dialog.
Exit GParted with, e.g., C-q.

Disconnect the target from the host.

commandline
The following scripts do much the same work as the GUI procedure above, but

use the commandline parted tool rather than GParted (which itself usually delegates to parted)
allow the user to turn off journalling on the target filesystem
are significantly more dangerous if not performed assiduously and correctly
Your first task is to get your target drive's designator, which you have presumably done already.

install GRUB2 on target
Be sure to edit the following commands appropriately for your situation. In this example,

the target drive designator= /dev/sdb has a single empty partition= /dev/sdb1 (created in previous step)
I (host account/ID= me) set the target drive's partition's label= LiveUSBmultiISO, causing my host to mount it at mount point= /media/me/LiveUSBmultiISO
I'll be installing GRUB2 to a directory/folder= /boot under that mount point.
Mount the target partition. You can probably just reconnect the target to the host; if that does not produce "the usual" automounting behavior, try, e.g., udisks --mount /dev/sdb1

Make directory= /boot with, e.g., sudo mkdir -p /media/me/LiveUSBmultiISO/boot

Install GRUB2 with sudo grub-install --boot-directory=/media/me/LiveUSBmultiISO/boot /dev/sdb . You should get the result

Installation finished. No error reported.
Own the target with, e.g., sudo chown -R me:me /media/me/LiveUSBmultiISO

populate target ISO directory
Be sure to edit the following commands appropriately for your situation. In this example,

I (host account/ID= me) have configured my target drive's partition such that my host mounts it at mount point= /media/me/LiveUSBmultiISO
I'll be populating a directory/folder= /ISOs (under that mount point) with the ISOs I want to be able to boot.
Create the target ISO directory with, e.g., mkdir -p /media/me/LiveUSBmultiISO/ISOs
{Copy, download, move} your ISOs to that target ISO directory as appropriate for your situation.
inspect internal structure of ISOs
For your target's grub.cfg, each ISO menu entry (more below) must specify some valid information about the internal structure of the ISO (which is itself a filesystem) it seeks to boot. Particularly it will need the ISO-internal paths to

the bootable Linux kernel, usually named vmlinuz
the initial RAMdisk image, usually named initrd* (e.g., initrd.lz)
To browse the contents of an ISO on your host, mount the ISO as a loop device, and inspect it using normal filesystem tools (commandline or graphical). E.g.,:

### Note following requires `sudo`, so get that first.
### E.g., do `sudo foo` at commandline, just to give password to `sudo`.

TARGET_ISO_FILENAME='lmde-2-201503-mate-32bit.iso' # filename of ISO to mount
TARGET_ISO_MOUNT_POINT_NAME='MATE-32bit'           # mount point name != mount point path
USERID='me'                                        # for convenience below
TARGET_DRIVE_LABEL='LiveUSBmultiISO'         # presuming your host mounts using drive label
TARGET_ISO_DIR="/media/${USERID}/${TARGET_DRIVE_LABEL}/ISOs"   # path to ISO container
TARGET_ISO_FILEPATH="${TARGET_ISO_DIR}/${TARGET_ISO_FILENAME}" # ISO/filesystem to mount
TARGET_ISO_MOUNT_POINT_PATH="/media/${USERID}/${TARGET_ISO_MOUNT_POINT_NAME}" # where to mount it

if   [[ -z "${TARGET_ISO_FILEPATH}" ]] ; then
    echo -e 'ERROR: TARGET_ISO_FILEPATH not defined, exiting ...'
elif [[ ! -f "${TARGET_ISO_FILEPATH}" ]] ; then
    echo -e "ERROR: ISO to mount='${TARGET_ISO_FILEPATH}' not found, exiting ..."
elif [[ -z "${TARGET_ISO_MOUNT_POINT_PATH}" ]] ; then
    echo -e 'ERROR: TARGET_ISO_MOUNT_POINT_PATH not defined, exiting ...'
elif [[ ! -d "${TARGET_ISO_MOUNT_POINT_PATH}" ]] ; then
    # create mount point
    for CMD in \
        "sudo mkdir -p ${TARGET_ISO_MOUNT_POINT_PATH}" \
    ; do
        echo -e "${CMD}"
        eval "${CMD}"
    done
fi
echo # newline

if   [[ ! -d "${TARGET_ISO_MOUNT_POINT_PATH}" ]] ; then
    echo -e "ERROR: ISO mount point='${TARGET_ISO_MOUNT_POINT_PATH}' not found, exiting ..."
else
    # Mount the ISO, inspect using desired tool(s).
    # To remove the mount after inspection, add the following lines to the end of the loop:
    #  "sudo umount ${TARGET_ISO_MOUNT_POINT_PATH}" \
    #  "sudo rm -fr ${TARGET_ISO_MOUNT_POINT_PATH}" \
    # Otherwise,
    for CMD in \
        "sudo mount -o loop ${TARGET_ISO_FILEPATH} ${TARGET_ISO_MOUNT_POINT_PATH}" \
        "ls -al ${TARGET_ISO_MOUNT_POINT_PATH}/" \
        "find ${TARGET_ISO_MOUNT_POINT_PATH}/ -name 'vmlinuz'" \
        "find ${TARGET_ISO_MOUNT_POINT_PATH}/ -name 'initrd*'" \
        "find ${TARGET_ISO_MOUNT_POINT_PATH}/ -name 'grub*'" \
    ; do
        echo -e "${CMD}"
        eval "${CMD}"
        echo # newline
    done
fi
I get results like

sudo mount -o loop /media/me/LiveUSBmultiISO/ISOs/lmde-2-201503-mate-32bit.iso /media/me/MATE-32bit
mount: block device /media/me/LiveUSBmultiISO/ISOs/lmde-2-201503-mate-32bit.iso is write-protected, mounting read-only

ls -al /media/me/MATE-32bit/
total 43
dr-xr-xr-x  8 root root  2048 Apr  6 13:19 .
drwxr-x---+ 4 root root  4096 Jun  6 23:55 ..
dr-xr-xr-x  3 root root  2048 Apr  6 13:18 boot
dr-xr-xr-x  2 root root  2048 Apr  6 13:19 .disk
dr-xr-xr-x  3 root root  2048 Apr  6 13:18 dists
dr-xr-xr-x  2 root root  2048 Apr  6 13:19 isolinux
dr-xr-xr-x  2 root root  2048 Apr  6 13:19 live
-r--r--r--  1 root root 24872 Apr  6 13:19 MD5SUMS
dr-xr-xr-x  5 root root  2048 Apr  6 13:18 pool

find /media/me/MATE-32bit/ -name 'vmlinuz'
/media/me/MATE-32bit/live/vmlinuz

find /media/me/MATE-32bit/ -name 'initrd*'
/media/me/MATE-32bit/live/initrd.lz

find /media/me/MATE-32bit/ -name 'grub*'
/media/me/MATE-32bit/boot/grub/grub.cfg
create target grub.cfg
Be sure to edit the following commands appropriately for your situation. In this example,

My target's drive designator= /dev/sdb (set by my host).
My target has a single boot partition= /dev/sdb1 (created above).
I (host account/ID= me) have configured my target drive's partition such that my host mounts it at mount point= /media/me/LiveUSBmultiISO
I have installed GRUB2 to directory/folder= /media/me/LiveUSBmultiISO/boot
I want to create a grub.cfg in ./grub/grub.cfg relative to the GRUB2 install (i.e., at /media/me/LiveUSBmultiISO/boot/grub/grub.cfg )
Every ISO file that I want to be able to boot is contained within directory/folder= /media/me/LiveUSBmultiISO/ISOs
grub.cfg is the canonical name for the file directly controlling GRUB2 behavior. Ordinarily, one would not edit or create a grub.cfg directly, but would instead use update-grub after editing the host's /etc/default/grub (or other files in /etc/grub.d/). This is inappropriate for our usecase, so we will create /media/me/LiveUSBmultiISO/boot/grub/grub.cfg directly.

Creating a correct grub.cfg mostly means creating correct menu entries for your ISOs. For more information about this, see (e.g.)

The grub.cfg contained within the ISO that you want to boot!

Mount the ISO
Find its grub.cfg.
Read its grub.cfg: usually that will have all the information you need to minimally boot the ISO (though you may want to add enhancements like toram as appropriate for your hosts.
this Ubuntu community page and pages linked from it

A few tips:

Before testing your grub.cfg lint it with grub-script-check! Especially grub-script-check /path/to/your/grub.cfg if strange things seem to be hapening at boottime (e.g., a newly-added menuentry does not show in the GRUB2 menu).

The property= root must be set appropriately for your target's boot partition when it boots on its host. Since you will be booting that host from the target, the target's boottime drive designator will almost certainly be /dev/sda, with your target's boot partition numbered from there. The syntax for root values can be inferred from the following:

/dev/sda1, the appropriate value for property= root is (hd0,1)
/dev/sdb1, the appropriate value for property= root is (hd1,1)
/dev/sdc2, the appropriate value for property= root is (hd2,2)
... and so on.
Each menuentry in your grub.cfg

corresponds to one way to boot an ISO

should display as an item in your GRUB2 menu at boottime

has text (quoted after the literal menuentry) for display in the GRUB2 menu, which can be set as desired (to inform you and other users).

must have property= linux specifying how to boot the ISO. This will be ISO- and OS-specific, and is beyond the scope of this article.

The first item after the property name= linux must be the boottime path inside the ISO to the bootable image: see information above regarding how to inspect internal structure of ISOs.
If your host has RAM larger than any of your ISOs, and you are willing to tradeoff increased boottime for decreased runtime, append option= toram to the ISO's property= linux : loading the ISO to RAM will make the subsequent run much more performant.
must have property= initrd giving a path to the image for the boottime RAMdisk. This will be ISO- and OS-specific, and is beyond the scope of this article (though it is usually "just a path")

can be painful to debug. One thing that might help is to set pager=1, which will pipe console spew through more.

target grub.cfg
For my example, I created /media/me/LiveUSBmultiISO/boot/grub/grub.cfg with the following contents:

# begin /boot/grub/grub.cfg
# Created from instructions @ https://bitbucket.org/tlroche/install_resizable_encrypted_lmde/src/HEAD/create_LMDE_liveUSB.rst?at=master

set default='0'
set timeout='30'

# Consider using another non-journaling filesystem (see note above), but
# following entry must match filesystem set on this disk (by, e.g., GParted).
set diskfs='ext2'
# Label set on this disk (by, e.g., GParted)
set disklabel='LiveUSBmultiISO'

# This LiveUSB (which we assume will be the first drive at boottime) boots from its first/only partition.
set root='(hd0,1)' # special envvar in GRUB2
# devroot is relative to (and begins with) '/dev'
set devroot="/dev/disk/by-label/${disklabel}"

# Current versions to use
#set clonezilla_version='2.4.2-10'
set clonezilla_version='2.4.2-61'
#set gparted_version='0.22.0-2'
set gparted_version='0.24.0-2'

insmod "${diskfs}"

menuentry 'Clonezilla 32-bit (i586, no PAE) ISO' {
    set gfxpayload=text # ~= vga='normal'
    # isofile_abspath is relative to LiveUSB root.
    set isofile_abspath="/ISOs/clonezilla-live-${clonezilla_version}-i586.iso"
    # isofile_devpath is relative to (and begins with) "/dev"
    set isofile_devpath="${devroot}${isofile_abspath}"
    # "mount" the ISO
    loopback loop "(${root})${isofile_abspath}"

    echo -e 'About to boot kernel ...'
    # Following line adapted from ISO's menuentry='Clonezilla Live (Failsafe mode)' and from https://wiki.archlinux.org/index.php/Multiboot_USB_drive#GParted_Live
    linux '(loop)/live/vmlinuz' boot='live' union='overlay' username='user' config components noswap edd='on' nomodeset nodmraid noeject locales='' keyboard-layouts='' ocs_live_run='ocs-live-general' ocs_live_extra_param='' ocs_live_batch='no' ip='' acpi='off'irqpoll noapic noapm nodma nomce nolapic nosmp nomodeset nosplash findiso="${isofile_abspath}"
    echo -e 'Done boot kernel.'

    echo -e 'About to boot RAMdisk ...'
    initrd '(loop)/live/initrd.img'
}

menuentry 'Clonezilla 64-bit/amd64 ISO' {
    set gfxpayload=text # ~= vga='normal'
    # isofile_abspath is relative to LiveUSB root.
    set isofile_abspath="/ISOs/clonezilla-live-${clonezilla_version}-amd64.iso"
    # isofile_devpath is relative to (and begins with) "/dev"
    set isofile_devpath="${devroot}${isofile_abspath}"
    # "mount" the ISO
    loopback loop "(${root})${isofile_abspath}"

    echo -e 'About to boot kernel ...'
    # Following line adapted from ISO's menuentry='Clonezilla Live (Failsafe mode)' and from https://wiki.archlinux.org/index.php/Multiboot_USB_drive#GParted_Live (below)
    linux '(loop)/live/vmlinuz' boot='live' union='overlay' username='user' config components noswap edd='on' nomodeset nodmraid noeject locales='' keyboard-layouts='' ocs_live_run='ocs-live-general' ocs_live_extra_param='' ocs_live_batch='no' ip='' acpi='off'irqpoll noapic noapm nodma nomce nolapic nosmp nomodeset nosplash findiso="${isofile_abspath}"
    echo -e 'Done boot kernel.'

    echo -e 'About to boot RAMdisk ...'
    initrd '(loop)/live/initrd.img'
}

menuentry 'GParted 32-bit ISO (most reliable)' {
    set gfxpayload=text # ~= vga='normal'
    # isofile_abspath is relative to LiveUSB root.
    set isofile_abspath="/ISOs/gparted-live-${gparted_version}-i586.iso"
    # isofile_devpath is relative to (and begins with) '/dev'
    set isofile_devpath="${devroot}${isofile_abspath}"
    # "mount" the ISO
    loopback loop "(${root})${isofile_abspath}"
    echo -e 'About to boot kernel ...'
    # Following line adapted from https://wiki.archlinux.org/index.php/Multiboot_USB_drive#GParted_Live
    linux '(loop)/live/vmlinuz' boot='live' union='overlay' username='user' config components noswap noeject toram='filesystem.squashfs' ip='' nosplash findiso="${isofile_abspath}"
    echo -e 'Done boot kernel.'
    echo -e 'About to boot RAMdisk ...'
    initrd '(loop)/live/initrd.img'
}

menuentry 'GParted 64-bit ISO (supports uEFI)' {
    set gfxpayload=text # ~= vga='normal'
    # isofile_abspath is relative to LiveUSB root.
    set isofile_abspath="/ISOs/gparted-live-${gparted_version}-amd64.iso"
    # isofile_devpath is relative to (and begins with) '/dev'
    set isofile_devpath="${devroot}${isofile_abspath}"
    # "mount" the ISO
    loopback loop "(${root})${isofile_abspath}"
    # Following line adapted from https://wiki.archlinux.org/index.php/Multiboot_USB_drive#GParted_Live
    linux '(loop)/live/vmlinuz' boot='live' union='overlay' username='user' config components noswap noeject toram='filesystem.squashfs' ip='' nosplash findiso="${isofile_abspath}"
    initrd '(loop)/live/initrd.img'
}

menuentry "LMDE2/Betsy 64-bit Cinnamon ISO" {
    # isofile_abspath is relative to LiveUSB root.
    set isofile_abspath='/ISOs/lmde-2-201503-cinnamon-64bit.iso'
    # isofile_devpath is relative to (and begins with) '/dev'
    set isofile_devpath="${devroot}${isofile_abspath}"
    # "mount" the ISO
    loopback loop "(${root})${isofile_abspath}"
    # following line boots ...
    linux '(loop)/live/vmlinuz' boot='live' live-config fromiso="${isofile_devpath}" toram='filesystem.squashfs' noprompt quiet
    # ... but causes this error message (possibly several times):
    # > Warning : device for bootoption fromiso= (/dev/disk/by-label/LiveUSBmultiISO/ISOs/lmde-2-201503-cinnamon-64bit.iso) not found.
    # By contrast, use of following line seems to cause unrecoverable halt:
    # linux (loop)/live/vmlinuz boot=live live-config toram=filesystem.squashfs noprompt quiet
    initrd '(loop)/live/initrd.lz'
}

menuentry "LMDE2/Betsy 32-bit MATE ISO" {
    # isofile_abspath is relative to LiveUSB root
    set isofile_abspath='/ISOs/lmde-2-201503-mate-32bit.iso'
    # isofile_devpath is relative to (and begins with) "/dev"
    set isofile_devpath="${devroot}${isofile_abspath}"
    # "mount" the ISO
    loopback loop "(${root})${isofile_abspath}"
    linux '(loop)/live/vmlinuz' boot='live' live-config fromiso="${isofile_devpath}" toram='filesystem.squashfs' noprompt quiet
    initrd '(loop)/live/initrd.lz'
}

menuentry "LMDE2/Betsy 64-bit MATE ISO" {
    # isofile_abspath is relative to LiveUSB root.
    set isofile_abspath='/ISOs/lmde-2-201503-mate-64bit.iso'
    # isofile_devpath is relative to (and begins with) "/dev"
    set isofile_devpath="${devroot}${isofile_abspath}"
    # "mount" the ISO
    loopback loop "(${root})${isofile_abspath}"
    linux '(loop)/live/vmlinuz' boot='live' live-config fromiso="${isofile_devpath}" toram='filesystem.squashfs' noprompt quiet
    initrd '(loop)/live/initrd.lz'
}

menuentry "Mint 17.1 32-bit XFCE ISO" {
    # isofile_abspath is relative to LiveUSB root.
    set isofile_abspath='/ISOs/linuxmint-17.1-xfce-32bit.iso'
    # isofile_devpath is relative to (and begins with) "/dev"
    set isofile_devpath="${devroot}${isofile_abspath}"
    # "mount" the ISO
    loopback loop "(${root})${isofile_abspath}"

    echo -e "About to twiddle video ..."
    set menu_color_normal='white/black'
    set menu_color_highlight='black/light-gray'
    set gfxpayload='keep'
    echo -e "Done twiddling video."

    linux '(loop)/casper/vmlinuz' file='/cdrom/preseed/linuxmint.seed' boot='casper' iso-scan/filename="${isofile_abspath}" noprompt noeject toram
    initrd '(loop)/casper/initrd.lz'
}

# end /boot/grub/grub.cfg
test target
test procedure
Unmount the target from the current host.

Disconnect the target from the current host.

Connect the target to another host that is

definitely shutdown (since you'll want to boot it)
preferably not the current host (in case you need to make changes!)
Boot the target's host.

Host may require you to do something at boottime to make it boot the external drive.
test results
The above grub.cfg currently (13 Jun 2015) passes when tested with the following equipment:

target LiveUSB==~5-year-old USB2-only 80 GB external spinning-disk HD
32-bit host==10-year-old IBM (one of the last) ThinkPad Z61t, legacy BIOS, encrypted hard drive (LUKS + LVM2). Requires boottime keystrokes to boot USB drive.
64-bit host==6-year-old System76 Pangolin Performance (PanP5, aka Clevo M762TUN), legacy BIOS, encrypted HD. USB drive first in boot order, hence will boot first menuentry on attached LiveUSB with no boottime intervention.
That grub.cfg boots the following {host, menuentry} tuples:

32-bit host: boots Clonezilla 32-bit

64-bit host: boots Clonezilla 32-bit and 64-bit

64-bit host: boots GParted 32-bit and 64-bit

64-bit host: boots LMDE2/Betsy 64-bit Cinnamon

while kernel toraming, gives error regarding option= fromiso (which it correctly reads):

Warning : device for bootoption fromiso= (/dev/disk/by-label/LiveUSBmultiISO/ISOs/lmde-2-201503-cinnamon-64bit.iso) not found.
64-bit host: boots LMDE2/Betsy 64-bit MATE

same fromiso error while kernel toraming (as item#=1 above, but correct path to different ISO), except error is displayed twice
64-bit host: boots LMDE2/Betsy 32-bit MATE

same fromiso error while kernel toraming (as item#=1 above, but correct path to different ISO), except error is displayed 7 times ?!?
64-bit host: boots Rebecca 32-bit XFCE

fails to find file to loadfont
almost appears to hang when toraming: does not give progress control, but does give useful message before it starts.
32-bit host: boots LMDE2/Betsy 32-bit MATE

Firefox renders the default (Mint) startpage oddly (though not unusably): much text has black background, instead of the intended page background. Only seems to affect startpage, though. Weirder still, I don't observe this rendering with any other {host,target} tuples.
32-bit host: boots Rebecca 32-bit XFCE

fails to find file to loadfont
appears to hang when (IIUC) toraming: does not give progress control or useful message.
TODOs
Move all following to this project's Issues.
Investigate using /boot/grub/custom.cfg per MagicMint's comment to another Mint tutorial.
Investigate using target UUID in grub.cfg::linux lines per Laurent85's LMDE2 forum post.




```
root@Live-OS:/# grub-install
Installing for x86_64-efi platform.
grub-install: warning: EFI variables are not supported on this system..
Installation finished. No error reported.

root@Live-OS:/# grub-install --force --removable --no-floppy --boot-directory=/boot --efi-directory=/boot/efi /dev/sda
Installing for x86_64-efi platform.
Installation finished. No error reported.
```

