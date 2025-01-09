
# dmesg

```
[254243.417977] usb 1-1: new low-speed USB device number 9 using xhci_hcd
[254243.563700] usb 1-1: New USB device found, idVendor=1bcf, idProduct=0002, bcdDevice= 1.12
[254243.563708] usb 1-1: New USB device strings: Mfr=0, Product=2, SerialNumber=0
[254243.563712] usb 1-1: Product: USB Optical Wheel Mouse
[254243.567991] input: USB Optical Wheel Mouse as /devices/pci0000:00/0000:00:14.0/usb1/1-1/1-1:1.0/0003:1BCF:0002.000E/input/input67
[254243.568308] hid-generic 0003:1BCF:0002.000E: input,hidraw0: USB HID v1.11 Mouse [USB Optical Wheel Mouse] on usb-0000:00:14.0-1/input0
[254243.981318] usb 1-2: new high-speed USB device number 10 using xhci_hcd
[254244.123018] usb 1-2: New USB device found, idVendor=14cd, idProduct=6116, bcdDevice= 2.20
[254244.123025] usb 1-2: New USB device strings: Mfr=1, Product=3, SerialNumber=2
[254244.123029] usb 1-2: Product: USB Mass Storage Device
[254244.123032] usb 1-2: Manufacturer: Generic
[254244.123035] usb 1-2: SerialNumber: 116AC2101219
[254244.124312] usb-storage 1-2:1.0: USB Mass Storage device detected
[254244.124993] scsi host1: usb-storage 1-2:1.0
[254245.145626] scsi 1:0:0:0: Direct-Access        Mass  Storage Device        PQ: 0 ANSI: 0
[254245.147007] sd 1:0:0:0: [sdb] 30932990 512-byte logical blocks: (15.8 GB/14.7 GiB)
[254245.147204] sd 1:0:0:0: [sdb] Write Protect is off
[254245.147212] sd 1:0:0:0: [sdb] Mode Sense: 03 00 00 00
[254245.147387] sd 1:0:0:0: [sdb] No Caching mode page found
[254245.147393] sd 1:0:0:0: [sdb] Assuming drive cache: write through
[254245.166559] Alternate GPT is invalid, using primary GPT.
[254245.166578]  sdb: sdb1 sdb2
[254245.205236] sd 1:0:0:0: [sdb] Attached SCSI disk
[254245.485357] BTRFS: device fsid 2ee39518-6538-4990-b3c2-73ab117ce711 devid 1 transid 5714126 /dev/sdb2 scanned by systemd-udevd (2200174)
...

[1173462.568790] usb 1-3: new full-speed USB device number 17 using xhci_hcd
[1173462.718635] usb 1-3: New USB device found, idVendor=05ac, idProduct=024f, bcdDevice= 1.23
[1173462.718639] usb 1-3: New USB device strings: Mfr=1, Product=2, SerialNumber=0
[1173462.718641] usb 1-3: Product: USB DEVICE
[1173462.718642] usb 1-3: Manufacturer: SONiX
[1173534.392098] usb 1-5: new low-speed USB device number 18 using xhci_hcd
[1173534.545167] usb 1-5: New USB device found, idVendor=1bcf, idProduct=0002, bcdDevice= 1.12
[1173534.545181] usb 1-5: New USB device strings: Mfr=0, Product=2, SerialNumber=0
[1173534.545187] usb 1-5: Product: USB Optical Wheel Mouse
[1173534.549008] input: USB Optical Wheel Mouse as /devices/pci0000:00/0000:00:14.0/usb1/1-5/1-5:1.0/0003:1BCF:0002.000F/input/input22
[1173534.549286] hid-generic 0003:1BCF:0002.000F: input,hidraw0: USB HID v1.11 Mouse [USB Optical Wheel Mouse] on usb-0000:00:14.0-5/input0
[1173566.917314] usb 1-3: USB disconnect, device number 17
[1173570.719762] usb 1-6: new full-speed USB device number 19 using xhci_hcd
[1173570.869142] usb 1-6: New USB device found, idVendor=05ac, idProduct=024f, bcdDevice= 1.23
[1173570.869146] usb 1-6: New USB device strings: Mfr=1, Product=2, SerialNumber=0
[1173570.869148] usb 1-6: Product: USB DEVICE
[1173570.869149] usb 1-6: Manufacturer: SONiX
[1173604.367483] usb 1-3: new full-speed USB device number 20 using xhci_hcd
[1173604.517812] usb 1-3: New USB device found, idVendor=258a, idProduct=002a, bcdDevice=90.36
[1173604.517817] usb 1-3: New USB device strings: Mfr=1, Product=2, SerialNumber=0
[1173604.517818] usb 1-3: Product: Gaming KB
[1173604.517819] usb 1-3: Manufacturer: SINO WEALTH
[1173604.521269] input: SINO WEALTH Gaming KB  as /devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.0/0003:258A:002A.0012/input/input23
[1173604.579659] hid-generic 0003:258A:002A.0012: input,hidraw1: USB HID v1.11 Keyboard [SINO WEALTH Gaming KB ] on usb-0000:00:14.0-3/input0
[1173604.582218] input: SINO WEALTH Gaming KB  System Control as /devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.1/0003:258A:002A.0013/input/input24
[1173604.639835] input: SINO WEALTH Gaming KB  Consumer Control as /devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.1/0003:258A:002A.0013/input/input25
[1173604.639917] input: SINO WEALTH Gaming KB  Keyboard as /devices/pci0000:00/0000:00:14.0/usb1/1-3/1-3:1.1/0003:258A:002A.0013/input/input26
[1173604.640114] hid-generic 0003:258A:002A.0013: input,hiddev0,hidraw2: USB HID v1.11 Keyboard [SINO WEALTH Gaming KB ] on usb-0000:00:14.0-3/input1
[1173671.061163] usb 1-6: USB disconnect, device number 19
[1173686.130713] usb 1-4: new full-speed USB device number 21 using xhci_hcd
[1173686.280893] usb 1-4: New USB device found, idVendor=05ac, idProduct=024f, bcdDevice= 1.23
[1173686.280908] usb 1-4: New USB device strings: Mfr=1, Product=2, SerialNumber=0
[1173686.280914] usb 1-4: Product: USB DEVICE
[1173686.280918] usb 1-4: Manufacturer: SONiX
```

# lsusb

```
Bus 004 Device 002: ID 8087:8000 Intel Corp. Integrated Rate Matching Hub
Bus 004 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 003 Device 002: ID 8087:8008 Intel Corp. Integrated Rate Matching Hub
Bus 003 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 001 Device 018: ID 1bcf:0002 Sunplus Innovation Technology Inc. USB Optical Wheel Mouse
Bus 001 Device 021: ID 05ac:024f Apple, Inc. Aluminium Keyboard (ANSI)
Bus 001 Device 020: ID 258a:002a SINO WEALTH Gaming KB
Bus 001 Device 002: ID 0781:5571 SanDisk Corp. Cruzer Fit
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
```
