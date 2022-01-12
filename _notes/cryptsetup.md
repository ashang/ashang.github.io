
    ~/go/src  ls /home/barn                                                                                                                            ✔
    ~/go/src  sudo cryptsetup luksOpen /dev/sda barn                                                                                                   ✔
Enter passphrase for /dev/sda:
device-mapper: reload ioctl on barn (254:1) failed: No such file or directory
    ~/go/src   

 sudo pacman -S device-mapper                                                                                                    4 ✘  4s 
warning: device-mapper-2.03.14-2 is up to date -- reinstalling
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
    ~/go/src   


#  1.6G  100K  1.6G   1% /run/user/1000
    ~  sudo cryptsetup luksOpen /dev/sda barn
  ✔
 [sudo] password for aaron:
 Enter passphrase for /dev/sda:
 device-mapper: reload ioctl on barn (254:1) failed: No such file or directory
     ~  cd  /




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
    ~   



