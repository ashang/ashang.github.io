---
#layout: page
title: Thermal
---

```
$ cat /sys/class/thermal/thermal_zone*/temp
/sys/class/thermal/thermal_zone0/temp
77000
/sys/class/thermal/thermal_zone1/temp
79000
```

```
$ acpi -t
Thermal 0: ok, 76.0 degrees C
```

```
$ paste <(cat /sys/class/thermal/thermal_zone*/type) <(cat /sys/class/thermal/thermal_zone*/temp) | column -s $'\t' -t | sed 's/\(.\)..$/.\1°C/'
acpitz        76.0°C
x86_pkg_temp  78.0°C
```

```
$ sensors
thinkpad-isa-0000
Adapter: ISA adapter
fan1:        4716 RPM
CPU:          +79.0°C
GPU:           +0.0°C
temp3:         +0.0°C
temp4:         +0.0°C
temp5:         +0.0°C
temp6:         +0.0°C
temp7:         +0.0°C
temp8:         +0.0°C

BAT0-acpi-0
Adapter: ACPI interface
in0:          11.87 V

coretemp-isa-0000
Adapter: ISA adapter
Package id 0:  +80.0°C  (high = +87.0°C, crit = +105.0°C)
Core 0:        +76.0°C  (high = +87.0°C, crit = +105.0°C)
Core 1:        +80.0°C  (high = +87.0°C, crit = +105.0°C)

BAT1-acpi-0
Adapter: ACPI interface
in0:          12.28 V

acpitz-acpi-0
Adapter: ACPI interface
temp1:        +79.0°C  (crit = +200.0°C)
```

```
$ sudo sensors-detect
# sensors-detect version 3.6.0
# System: LENOVO 20AHS00000 [ThinkPad X230s] (laptop)
# Kernel: 6.2.0-23-generic x86_64
# Processor: Intel(R) Core(TM) i5-3337U CPU @ 1.80GHz (6/58/9)

This program will help you determine which kernel modules you need
to load to use lm_sensors most effectively. It is generally safe
and recommended to accept the default answers to all questions,
unless you know what you're doing.

Some south bridges, CPUs or memory controllers contain embedded sensors.
Do you want to scan for them? This is totally safe. (YES/no): yes
Module cpuid loaded successfully.
Silicon Integrated Systems SIS5595...                       No
VIA VT82C686 Integrated Sensors...                          No
VIA VT8231 Integrated Sensors...                            No
AMD K8 thermal sensors...                                   No
AMD Family 10h thermal sensors...                           No
AMD Family 11h thermal sensors...                           No
AMD Family 12h and 14h thermal sensors...                   No
AMD Family 15h thermal sensors...                           No
AMD Family 16h thermal sensors...                           No
AMD Family 17h thermal sensors...                           No
AMD Family 15h power sensors...                             No
AMD Family 16h power sensors...                             No
Hygon Family 18h thermal sensors...                         No
Intel digital thermal sensor...                             Success!
    (driver `coretemp')
Intel AMB FB-DIMM thermal sensor...                         No
Intel 5500/5520/X58 thermal sensor...                       No
VIA C7 thermal sensor...                                    No
VIA Nano thermal sensor...                                  No

Some Super I/O chips contain embedded sensors. We have to write to
standard I/O ports to probe them. This is usually safe.
Do you want to scan for Super I/O sensors? (YES/no): yes
Probing for Super-I/O at 0x2e/0x2f
Trying family `National Semiconductor/ITE'...               No
Trying family `SMSC'...                                     No
Trying family `VIA/Winbond/Nuvoton/Fintek'...               No
Trying family `ITE'...                                      No
Probing for Super-I/O at 0x4e/0x4f
Trying family `National Semiconductor/ITE'...               No
Trying family `SMSC'...                                     Yes
Found unknown chip with ID 0x0b03

Some hardware monitoring chips are accessible through the ISA I/O ports.
We have to write to arbitrary I/O ports to probe them. This is usually
safe though. Yes, you do have ISA I/O ports even if you do not have any
ISA slots! Do you want to scan the ISA I/O ports? (YES/no): yes
Probing for `National Semiconductor LM78' at 0x290...       No
Probing for `National Semiconductor LM79' at 0x290...       No
Probing for `Winbond W83781D' at 0x290...                   No
Probing for `Winbond W83782D' at 0x290...                   No

Lastly, we can probe the I2C/SMBus adapters for connected hardware
monitoring devices. This is the most risky part, and while it works
reasonably well on most systems, it has been reported to cause trouble
on some systems.
Do you want to probe the I2C/SMBus adapters now? (YES/no): yes
Using driver `i2c-i801' for device 0000:00:1f.3: Intel Panther Point (PCH)

Next adapter: SMBus I801 adapter at efa0 (i2c-0)
Do you want to scan it? (YES/no/selectively): yes
Client found at address 0x50
Handled by driver `at24' (already loaded), chip type `spd'
    (note: this is probably NOT a sensor chip!)
Client found at address 0x5c
Probing for `Analog Devices ADT7462'...                     No
Probing for `SMSC EMC1072'...                               No
Probing for `SMSC EMC1073'...                               No
Probing for `SMSC EMC1074'...                               No

Next adapter: i915 gmbus ssc (i2c-1)
Do you want to scan it? (yes/NO/selectively): yes

Next adapter: i915 gmbus vga (i2c-2)
Do you want to scan it? (yes/NO/selectively): yes

Next adapter: i915 gmbus panel (i2c-3)
Do you want to scan it? (yes/NO/selectively): yes

Next adapter: i915 gmbus dpc (i2c-4)
Do you want to scan it? (yes/NO/selectively): yes

Next adapter: i915 gmbus dpb (i2c-5)
Do you want to scan it? (yes/NO/selectively): yes
Client found at address 0x49
Probing for `National Semiconductor LM75'...                No
Probing for `National Semiconductor LM75A'...               No
Probing for `Dallas Semiconductor DS75'...                  No
Probing for `National Semiconductor LM77'...                No
Probing for `Analog Devices ADT7410/ADT7420'...             No
Probing for `Maxim MAX6642'...                              No
Probing for `Texas Instruments TMP435'...                   No
Probing for `National Semiconductor LM73'...                No
Probing for `National Semiconductor LM92'...                No
Probing for `National Semiconductor LM76'...                No
Probing for `Maxim MAX6633/MAX6634/MAX6635'...              No
Probing for `NXP/Philips SA56004'...                        No
Probing for `SMSC EMC1023'...                               No
Probing for `SMSC EMC1043'...                               No
Probing for `SMSC EMC1053'...                               No
Probing for `SMSC EMC1063'...                               No

Next adapter: i915 gmbus dpd (i2c-6)
Do you want to scan it? (yes/NO/selectively): ye

Next adapter: AUX A/DP A (i2c-7)
Do you want to scan it? (yes/NO/selectively): y

Next adapter: AUX B/DP B (i2c-8)
Do you want to scan it? (yes/NO/selectively): y


Now follows a summary of the probes I have just done.
Just press ENTER to continue:

Driver `coretemp':
  * Chip `Intel digital thermal sensor' (confidence: 9)

To load everything that is needed, add this to /etc/modules:
#----cut here----
# Chip drivers
coretemp
#----cut here----
If you have some drivers built into your kernel, the list above will
contain too many modules. Skip the appropriate ones!

Do you want to add these lines automatically to /etc/modules? (yes/NO)y
Successful!

Monitoring programs won't work until the needed modules are
loaded. You may want to run '/etc/init.d/kmod start'
to load them.

Unloading cpuid... OK
```