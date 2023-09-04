
```



    ┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ Configuring refind ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
    │                                                                                                                                                                                                                                                                 │
    │ It is necessary to install rEFInd to the EFI System Partition (ESP) for it to control the boot process.                                                                                                                                                         │
    │                                                                                                                                                                                                                                                                 │
    │ Not installing the new rEFInd binary on the ESP may leave the system in an unbootable state. Alternatives to automatically installing rEFInd include running /usr/sbin/refind-install by hand or installing the rEFInd binaries manually by copying them from   │
    │ subdirectories of /usr/share/refind-{version}.                                                                                                                                                                                                                  │
    │                                                                                                                                                                                                                                                                 │
    │ Automatically install rEFInd to the ESP?                                                                                                                                                                                                                        │
    │                                                                                                                                                                                                                                                                 │
    │                                                                                 <Y

```

```
root@Live-OS:/# refind-install
ShimSource is none
Installing rEFInd on Linux....
ESP was found at /boot/efi using vfat
Found rEFInd installation in /boot/efi/EFI/refind; upgrading it.
Installing driver for btrfs (btrfs_x64.efi)
Copied rEFInd binary files

Notice: Backed up existing icons directory as icons-backup.
Existing refind.conf file found; copying sample file as refind.conf-sample
to avoid overwriting your customizations.

EFI variables are not supported on this system.
EFI variables are not supported on this system.
EFI variables are not supported on this system.
Creating new NVRAM entry

ALERT: There were problems running the efibootmgr program! You may need to
rename the refind_x64.efi binary to the default name (EFI/BOOT/bootx64.efi
on x86-64 systems, EFI/BOOT/bootia32.efi on x86 systems, or
EFI/BOOT/bootaa64.efi on ARM64 systems) to have it run!

Existing //boot/refind_linux.conf found; not overwriting.
root@Live-OS:/#
```
