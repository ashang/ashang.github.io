
# Bootloader


Bootloader in smartphone & rationale of BL locking/Unlocking

Boot-Loader in Smartphones
Bootloader, is like BOIS to windows. It is the first thing that runs when you boot up your     android device.
It packages the instructions to boot operating system kernel and most of them are specifically designed to run their own de-bugging or modification environment.
This low-level code contains the instructions that tell a device how to startup and find the system kernel.

Xiaomi's policy about Boot-Loader:
From year 2016, Xiaomi decided to lock bootloader of their smartphones citing/experiencing

1. Complaints from Xiaomi phone owners about receiving fake mi phones through re-sellers, weird ROM installed in new phones, even in China few users reported about financial loss incurred citing malware presence in new phones with custom roms resulting in financial losses

2. No security or tracking available for device if it get lost or stolen, a person who got device would easily flash new rom & IMEI and makes its impossible to track it down & getting back.


In case if your device is unlocked you will get following message

fastboot oem device-info

If you need to lock device again, then type following command

fastboot oem lock



# Backup

On most devices shipping with Android 6.0 or higher, the device maker has enabled dm-verity as a security measure. The device will signature check blocks of data on the system partition during boot at the block level. The usage of dm-verity prevents TWRP from being able to successfully restore a normal system backup. On most of these devices, you will see an option on the backup page for System Image. A system image backup takes up more space than a regular system backup, but the system image backup is a bit-perfect backup that, when restored, will not break dm-verity (assuming that you don't break dm-verity before making the backup). On a handful of devices, you may also find a Vendor and Vendor Image backup option. The same rules apply with regards to dm-verity. If you need a perfect "go back to completely stock" backup then you should be using System Image (and Vendor Image, when available) instead of just system.


# ADB Sideload

ADB sideload is a different ADB mode that you can use to push and install a zip using one command from your computer.

# Install recovery

Fastboot Install Method (No Root Required):
You will need the platform-tools from the Android SDK on your computer. Find the Android command line tools section on the page linked and install the SDK tools package. From the SDK Manager, download only the platform-tools to get adb and fastboot binaries.

On your device, go into Settings -> About and find the Build Number and tap on it 7 times to enable developer settings. Press back and go into Developer Options and enable USB debugging. From your computer, open a command prompt and type:

adb reboot bootloader

You should now be in fastboot mode.

Download the correct image file and copy the file into the same folder as your adb and fastboot binaries. Rename the image to twrp.img and type:

fastboot flash recovery twrp.img

fastboot reboot

Note many devices will replace your custom recovery automatically during first boot. To prevent this, use Google to find the proper key combo to enter recovery. After typing fastboot reboot, hold the key combo and boot to TWRP. Once TWRP is booted, TWRP will patch the stock ROM to prevent the stock ROM from replacing TWRP. If you don't follow this step, you will have to repeat the install.

#

To Bypass device encryption you have to format user data.

    fastboot format userdata

Google SafetyNet is a software that protects the device from any modifications to the core system; as and when a modification is detected it blocks certain apps from functioning efficiently.

This has emerged as the major hurdle for all enthusiasts who root their Android devices.

Magisk can help.


```
$ ./flash_all.sh

...
OKAY [  0.040s]
writing 'partition:4'...
OKAY [  0.924s]
finished. total time: 1.074s
OKAY [  0.110s]
writing 'tz'...
OKAY [  0.110s]
OKAY [  0.064s]
finished. total time: 0.144s
target reported max download size of 536870912 bytes
sending 'pmic' (41 KB)...
OKAY [  0.040s]
writing 'pmic'...
OKAY [  0.024s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'pmicbak' (41 KB)...
OKAY [  0.040s]
writing 'pmicbak'...
OKAY [  0.024s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'devcfg' (50 KB)...
OKAY [  0.050s]
writing 'devcfg'...
OKAY [  0.024s]
finished. total time: 0.074s
target reported max download size of 536870912 bytes
sending 'bluetooth' (396 KB)...
OKAY [  0.050s]
writing 'bluetooth'...
OKAY [  0.030s]
finished. total time: 0.080s
target reported max download size of 536870912 bytes
sending 'cmnlib' (200 KB)...
OKAY [  0.060s]
writing 'cmnlib'...
OKAY [  0.027s]
finished. total time: 0.087s
target reported max download size of 536870912 bytes
sending 'cmnlibbak' (200 KB)...
OKAY [  0.040s]
writing 'cmnlibbak'...
OKAY [  0.028s]
finished. total time: 0.068s
target reported max download size of 536870912 bytes
sending 'cmnlib64' (254 KB)...
OKAY [  0.060s]
writing 'cmnlib64'...
OKAY [  0.025s]
finished. total time: 0.085s
target reported max download size of 536870912 bytes
sending 'cmnlib64bak' (254 KB)...
OKAY [  0.040s]
writing 'cmnlib64bak'...
OKAY [  0.030s]
finished. total time: 0.070s
target reported max download size of 536870912 bytes
sending 'modem' (100268 KB)...
OKAY [ 11.475s]
writing 'modem'...
OKAY [  0.671s]
finished. total time: 12.146s
target reported max download size of 536870912 bytes
sending 'dsp' (16384 KB)...
OKAY [  1.241s]
writing 'dsp'...
OKAY [  0.159s]
finished. total time: 1.400s
target reported max download size of 536870912 bytes
sending 'keymaster' (352 KB)...
OKAY [  0.050s]
writing 'keymaster'...
OKAY [  0.031s]
finished. total time: 0.081s
target reported max download size of 536870912 bytes
sending 'keymasterbak' (352 KB)...
OKAY [  0.040s]
writing 'keymasterbak'...
OKAY [  0.030s]
finished. total time: 0.070s
target reported max download size of 536870912 bytes
sending 'misc' (8 KB)...
OKAY [  0.050s]
writing 'misc'...
OKAY [  0.022s]
finished. total time: 0.072s
target reported max download size of 536870912 bytes
erasing 'system'...
OKAY [  0.012s]
sending sparse 'system' 1/6 (524278 KB)...
OKAY [103.702s]
writing 'system' 1/6...
OKAY [  6.218s]
sending sparse 'system' 2/6 (521826 KB)...
OKAY [ 78.307s]
writing 'system' 2/6...
OKAY [  7.704s]
sending sparse 'system' 3/6 (501363 KB)...
OKAY [108.696s]
writing 'system' 3/6...
OKAY [  9.650s]
sending sparse 'system' 4/6 (516194 KB)...
OKAY [139.587s]
writing 'system' 4/6...
OKAY [  4.102s]
sending sparse 'system' 5/6 (516790 KB)...
OKAY [103.047s]
writing 'system' 5/6...
OKAY [  9.145s]
sending sparse 'system' 6/6 (129041 KB)...
OKAY [  8.837s]
writing 'system' 6/6...
OKAY [  1.091s]
finished. total time: 580.098s
target reported max download size of 536870912 bytes
erasing 'cache'...
OKAY [  0.022s]
sending 'cache' (6248 KB)...
OKAY [  0.458s]
writing 'cache'...
OKAY [  0.093s]
finished. total time: 0.573s
target reported max download size of 536870912 bytes
erasing 'userdata'...
OKAY [  0.025s]
sending 'userdata' (169486 KB)...
OKAY [ 34.011s]
writing 'userdata'...
OKAY [  1.283s]
finished. total time: 35.320s
target reported max download size of 536870912 bytes
sending 'recovery' (28705 KB)...
OKAY [  4.121s]
writing 'recovery'...
OKAY [  0.230s]
finished. total time: 4.351s
target reported max download size of 536870912 bytes
sending 'splash' (151 KB)...
OKAY [  0.050s]
writing 'splash'...
OKAY [  0.027s]
finished. total time: 0.077s
target reported max download size of 536870912 bytes
sending 'logo' (728 KB)...
OKAY [  0.090s]
writing 'logo'...
OKAY [  0.035s]
finished. total time: 0.125s
erasing 'boot'...
OKAY [  0.022s]
finished. total time: 0.022s
erasing 'sec'...
OKAY [  0.022s]
finished. total time: 0.022s
erasing 'switch'...
OKAY [  0.022s]
finished. total time: 0.022s
erasing 'mdtp'...
OKAY [  0.022s]
finished. total time: 0.022s
target reported max download size of 536870912 bytes
sending 'boot' (24057 KB)...
OKAY [  4.221s]
writing 'boot'...
OKAY [  0.189s]
finished. total time: 4.410s
target reported max download size of 536870912 bytes
sending 'cust' (219215 KB)...
OKAY [ 59.107s]
writing 'cust'...
OKAY [  2.119s]
finished. total time: 61.226s
rebooting...

finished. total time: 0.371s
```


```
$ fastboot flash recovery twrp-3.2.3-0-scorpio.img
< waiting for any device >
target reported max download size of 536870912 bytes
sending 'recovery' (25240 KB)...
OKAY [  0.702s]
writing 'recovery'...
OKAY [  0.185s]
finished. total time: 0.887s
```

```
$ fastboot reboot
rebooting...

finished. total time: 0.371s
```
```
$ cat flash_all_except_storage.sh

fastboot $* getvar product 2>&1 | grep "^product: *MSM8996_A7"
if [ $? -ne 0 ] ; then echo "Missmatching image and device"; exit 1; fi
fastboot $* flash xbl `dirname $0`/images/xbl.elf
if [ $? -ne 0 ] ; then echo "Flash xbl error"; exit 1; fi
fastboot $* flash tz `dirname $0`/images/tz.mbn
if [ $? -ne 0 ] ; then echo "Flash tz error"; exit 1; fi
fastboot $* flash tzbak `dirname $0`/images/tz.mbn
if [ $? -ne 0 ] ; then echo "Flash tzbak error"; exit 1; fi
fastboot $* flash hyp `dirname $0`/images/hyp.mbn
if [ $? -ne 0 ] ; then echo "Flash hyp error"; exit 1; fi
fastboot $* flash hypbak `dirname $0`/images/hyp.mbn
if [ $? -ne 0 ] ; then echo "Flash hypbak error"; exit 1; fi
fastboot $* flash rpm `dirname $0`/images/rpm.mbn
if [ $? -ne 0 ] ; then echo "Flash rpm error"; exit 1; fi
fastboot $* flash rpmbak `dirname $0`/images/rpm.mbn
if [ $? -ne 0 ] ; then echo "Flash rpmbak error"; exit 1; fi
fastboot $* flash aboot `dirname $0`/images/emmc_appsboot.mbn
if [ $? -ne 0 ] ; then echo "Flash aboot error"; exit 1; fi
fastboot $* flash abootbak `dirname $0`/images/emmc_appsboot.mbn
if [ $? -ne 0 ] ; then echo "Flash abootbak error"; exit 1; fi
fastboot $* flash pmic `dirname $0`/images/pmic.elf
if [ $? -ne 0 ] ; then echo "Flash pmic error"; exit 1; fi
fastboot $* flash pmicbak `dirname $0`/images/pmic.elf
if [ $? -ne 0 ] ; then echo "Flash pmicbak error"; exit 1; fi
fastboot $* flash devcfg `dirname $0`/images/devcfg.mbn
if [ $? -ne 0 ] ; then echo "Flash devcfg error"; exit 1; fi
fastboot $* flash bluetooth `dirname $0`/images/BTFM.bin
if [ $? -ne 0 ] ; then echo "Flash bluetooth error"; exit 1; fi
fastboot $* flash cmnlib `dirname $0`/images/cmnlib.mbn
if [ $? -ne 0 ] ; then echo "Flash cmnlib error"; exit 1; fi
fastboot $* flash cmnlibbak `dirname $0`/images/cmnlib.mbn
if [ $? -ne 0 ] ; then echo "Flash cmnlibbak error"; exit 1; fi
fastboot $* flash cmnlib64 `dirname $0`/images/cmnlib64.mbn
if [ $? -ne 0 ] ; then echo "Flash cmnlib64 error"; exit 1; fi
fastboot $* flash cmnlib64bak `dirname $0`/images/cmnlib64.mbn
if [ $? -ne 0 ] ; then echo "Flash cmnlib64bak error"; exit 1; fi
fastboot $* flash modem `dirname $0`/images/NON-HLOS.bin
if [ $? -ne 0 ] ; then echo "Flash modem error"; exit 1; fi
fastboot $* flash dsp `dirname $0`/images/adspso.bin
if [ $? -ne 0 ] ; then echo "Flash dsp error"; exit 1; fi
fastboot $* flash keymaster `dirname $0`/images/keymaster.mbn
if [ $? -ne 0 ] ; then echo "Flash keymaster error"; exit 1; fi
fastboot $* flash keymasterbak `dirname $0`/images/keymaster.mbn
if [ $? -ne 0 ] ; then echo "Flash keymasterbak error"; exit 1; fi
fastboot $* flash misc `dirname $0`/images/misc.img
if [ $? -ne 0 ] ; then echo "Flash misc error"; exit 1; fi
fastboot $* flash system `dirname $0`/images/system.img
if [ $? -ne 0 ] ; then echo "Flash system error"; exit 1; fi
fastboot $* flash cache `dirname $0`/images/cache.img
if [ $? -ne 0 ] ; then echo "Flash cache error"; exit 1; fi
fastboot $* flash recovery `dirname $0`/images/recovery.img
if [ $? -ne 0 ] ; then echo "Flash recovery error"; exit 1; fi
fastboot $* flash splash `dirname $0`/images/splash.img
if [ $? -ne 0 ] ; then echo "Flash splash error"; exit 1; fi
fastboot $* flash logo `dirname $0`/images/logo.img
if [ $? -ne 0 ] ; then echo "Flash logo error"; exit 1; fi
fastboot $* erase boot
if [ $? -ne 0 ] ; then echo "Erase boot error"; exit 1; fi
fastboot $* erase sec
if [ $? -ne 0 ] ; then echo "Erase sec error"; exit 1; fi
fastboot $* erase switch
if [ $? -ne 0 ] ; then echo "Erase switch error"; exit 1; fi
fastboot $* erase mdtp
if [ $? -ne 0 ] ; then echo "Erase mdtp error"; exit 1; fi
fastboot $* flash boot `dirname $0`/images/boot.img
if [ $? -ne 0 ] ; then echo "Flash boot error"; exit 1; fi
fastboot $* flash cust `dirname $0`/images/cust.img
if [ $? -ne 0 ] ; then echo "Flash cust error"; exit 1; fi
fastboot $* reboot
if [ $? -ne 0 ] ; then echo "Reboot error"; exit 1; fi
```

```
$ bash flash_all_except_storage.sh
product: MSM8996_A7
OKAY [  3.243s]
finished. total time: 3.340s
OKAY [  0.035s]
finished. total time: 0.123s
OKAY [  0.034s]
finished. total time: 0.122s
OKAY [  0.025s]
finished. total time: 0.065s
OKAY [  0.025s]
finished. total time: 0.065s
OKAY [  0.025s]
finished. total time: 0.065s
OKAY [  0.025s]
finished. total time: 0.064s
OKAY [  0.042s]
finished. total time: 0.139s
OKAY [  0.022s]
finished. total time: 0.062s
target reported max download size of 536870912 bytes
sending 'devcfg' (50 KB)...
OKAY [  0.040s]
writing 'devcfg'...
OKAY [  0.022s]
finished. total time: 0.062s
target reported max download size of 536870912 bytes
sending 'bluetooth' (396 KB)...
OKAY [  0.050s]
writing 'bluetooth'...
OKAY [  0.028s]
finished. total time: 0.078s
target reported max download size of 536870912 bytes
sending 'cmnlib' (200 KB)...
OKAY [  0.040s]
writing 'cmnlib'...
OKAY [  0.024s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'cmnlibbak' (200 KB)...
OKAY [  0.040s]
writing 'cmnlibbak'...
OKAY [  0.024s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'cmnlib64' (254 KB)...
OKAY [  0.039s]
writing 'cmnlib64'...
OKAY [  0.025s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'cmnlib64bak' (254 KB)...
OKAY [  0.039s]
writing 'cmnlib64bak'...
OKAY [  0.025s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'modem' (100012 KB)...
OKAY [  3.570s]
writing 'modem'...
OKAY [  0.760s]
finished. total time: 4.330s
target reported max download size of 536870912 bytes
sending 'dsp' (16384 KB)...
OKAY [  0.600s]
writing 'dsp'...
OKAY [  0.135s]
finished. total time: 0.735s
target reported max download size of 536870912 bytes
sending 'keymaster' (352 KB)...
OKAY [  0.049s]
writing 'keymaster'...
OKAY [  0.026s]
finished. total time: 0.075s
target reported max download size of 536870912 bytes
sending 'keymasterbak' (352 KB)...
OKAY [  0.049s]
writing 'keymasterbak'...
OKAY [  0.027s]
finished. total time: 0.076s
target reported max download size of 536870912 bytes
sending 'misc' (8 KB)...
OKAY [  0.040s]
writing 'misc'...
OKAY [  0.021s]
finished. total time: 0.061s
target reported max download size of 536870912 bytes
erasing 'system'...
OKAY [  0.009s]
sending sparse 'system' 1/5 (524196 KB)...
OKAY [ 19.703s]
writing 'system' 1/5...
OKAY [  4.908s]
sending sparse 'system' 2/5 (524270 KB)...
OKAY [ 19.520s]
writing 'system' 2/5...
OKAY [  5.478s]
sending sparse 'system' 3/5 (520533 KB)...
OKAY [ 25.620s]
writing 'system' 3/5...
OKAY [  5.985s]
sending sparse 'system' 4/5 (524235 KB)...
OKAY [ 18.845s]
writing 'system' 4/5...
OKAY [  6.939s]
sending sparse 'system' 5/5 (463268 KB)...
OKAY [ 16.930s]
writing 'system' 5/5...
OKAY [  5.223s]
finished. total time: 129.160s
target reported max download size of 536870912 bytes
erasing 'cache'...
OKAY [  0.013s]
sending 'cache' (6248 KB)...
OKAY [  0.249s]
writing 'cache'...
OKAY [  0.077s]
finished. total time: 0.340s
target reported max download size of 536870912 bytes
sending 'recovery' (24693 KB)...
OKAY [  0.898s]
writing 'recovery'...
OKAY [  0.206s]
finished. total time: 1.104s
target reported max download size of 536870912 bytes
sending 'splash' (151 KB)...
OKAY [  0.040s]
writing 'splash'...
OKAY [  0.023s]
finished. total time: 0.063s
target reported max download size of 536870912 bytes
sending 'logo' (728 KB)...
OKAY [  0.058s]
writing 'logo'...
OKAY [  0.030s]
finished. total time: 0.088s
erasing 'boot'...
OKAY [  0.021s]
finished. total time: 0.021s
erasing 'sec'...
OKAY [  0.021s]
finished. total time: 0.021s
erasing 'switch'...
OKAY [  0.021s]
finished. total time: 0.021s
erasing 'mdtp'...
OKAY [  0.021s]
finished. total time: 0.021s
target reported max download size of 536870912 bytes
sending 'boot' (22873 KB)...
OKAY [  0.859s]
writing 'boot'...
OKAY [  0.188s]
finished. total time: 1.047s
target reported max download size of 536870912 bytes
sending 'cust' (194294 KB)...
OKAY [  6.705s]
writing 'cust'...
OKAY [  2.129s]
finished. total time: 8.834s
rebooting...

finished. total time: 0.352s
```
```
$ fastboot devices -l
1c5202e2               fastboot usb:2-1.2
```

```
$ cat flash_all_except_storage.sh

fastboot $* getvar product 2>&1 | grep "^product: *MSM8996_A7"
if [ $? -ne 0 ] ; then echo "Missmatching image and device"; exit 1; fi
fastboot $* flash xbl `dirname $0`/images/xbl.elf
if [ $? -ne 0 ] ; then echo "Flash xbl error"; exit 1; fi
fastboot $* flash tz `dirname $0`/images/tz.mbn
if [ $? -ne 0 ] ; then echo "Flash tz error"; exit 1; fi
fastboot $* flash tzbak `dirname $0`/images/tz.mbn
if [ $? -ne 0 ] ; then echo "Flash tzbak error"; exit 1; fi
fastboot $* flash hyp `dirname $0`/images/hyp.mbn
if [ $? -ne 0 ] ; then echo "Flash hyp error"; exit 1; fi
fastboot $* flash hypbak `dirname $0`/images/hyp.mbn
if [ $? -ne 0 ] ; then echo "Flash hypbak error"; exit 1; fi
fastboot $* flash rpm `dirname $0`/images/rpm.mbn
if [ $? -ne 0 ] ; then echo "Flash rpm error"; exit 1; fi
fastboot $* flash rpmbak `dirname $0`/images/rpm.mbn
if [ $? -ne 0 ] ; then echo "Flash rpmbak error"; exit 1; fi
fastboot $* flash aboot `dirname $0`/images/emmc_appsboot.mbn
if [ $? -ne 0 ] ; then echo "Flash aboot error"; exit 1; fi
fastboot $* flash abootbak `dirname $0`/images/emmc_appsboot.mbn
if [ $? -ne 0 ] ; then echo "Flash abootbak error"; exit 1; fi
fastboot $* flash pmic `dirname $0`/images/pmic.elf
if [ $? -ne 0 ] ; then echo "Flash pmic error"; exit 1; fi
fastboot $* flash pmicbak `dirname $0`/images/pmic.elf
if [ $? -ne 0 ] ; then echo "Flash pmicbak error"; exit 1; fi
fastboot $* flash devcfg `dirname $0`/images/devcfg.mbn
if [ $? -ne 0 ] ; then echo "Flash devcfg error"; exit 1; fi
fastboot $* flash bluetooth `dirname $0`/images/BTFM.bin
if [ $? -ne 0 ] ; then echo "Flash bluetooth error"; exit 1; fi
fastboot $* flash cmnlib `dirname $0`/images/cmnlib.mbn
if [ $? -ne 0 ] ; then echo "Flash cmnlib error"; exit 1; fi
fastboot $* flash cmnlibbak `dirname $0`/images/cmnlib.mbn
if [ $? -ne 0 ] ; then echo "Flash cmnlibbak error"; exit 1; fi
fastboot $* flash cmnlib64 `dirname $0`/images/cmnlib64.mbn
if [ $? -ne 0 ] ; then echo "Flash cmnlib64 error"; exit 1; fi
fastboot $* flash cmnlib64bak `dirname $0`/images/cmnlib64.mbn
if [ $? -ne 0 ] ; then echo "Flash cmnlib64bak error"; exit 1; fi
fastboot $* flash modem `dirname $0`/images/NON-HLOS.bin
if [ $? -ne 0 ] ; then echo "Flash modem error"; exit 1; fi
fastboot $* flash dsp `dirname $0`/images/adspso.bin
if [ $? -ne 0 ] ; then echo "Flash dsp error"; exit 1; fi
fastboot $* flash keymaster `dirname $0`/images/keymaster.mbn
if [ $? -ne 0 ] ; then echo "Flash keymaster error"; exit 1; fi
fastboot $* flash keymasterbak `dirname $0`/images/keymaster.mbn
if [ $? -ne 0 ] ; then echo "Flash keymasterbak error"; exit 1; fi
fastboot $* flash misc `dirname $0`/images/misc.img
if [ $? -ne 0 ] ; then echo "Flash misc error"; exit 1; fi
fastboot $* flash system `dirname $0`/images/system.img
if [ $? -ne 0 ] ; then echo "Flash system error"; exit 1; fi
fastboot $* flash cache `dirname $0`/images/cache.img
if [ $? -ne 0 ] ; then echo "Flash cache error"; exit 1; fi
fastboot $* flash recovery `dirname $0`/images/recovery.img
if [ $? -ne 0 ] ; then echo "Flash recovery error"; exit 1; fi
fastboot $* flash splash `dirname $0`/images/splash.img
if [ $? -ne 0 ] ; then echo "Flash splash error"; exit 1; fi
fastboot $* flash logo `dirname $0`/images/logo.img
if [ $? -ne 0 ] ; then echo "Flash logo error"; exit 1; fi
fastboot $* erase boot
if [ $? -ne 0 ] ; then echo "Erase boot error"; exit 1; fi
fastboot $* erase sec
if [ $? -ne 0 ] ; then echo "Erase sec error"; exit 1; fi
fastboot $* erase switch
if [ $? -ne 0 ] ; then echo "Erase switch error"; exit 1; fi
fastboot $* erase mdtp
if [ $? -ne 0 ] ; then echo "Erase mdtp error"; exit 1; fi
fastboot $* flash boot `dirname $0`/images/boot.img
if [ $? -ne 0 ] ; then echo "Flash boot error"; exit 1; fi
fastboot $* flash cust `dirname $0`/images/cust.img
if [ $? -ne 0 ] ; then echo "Flash cust error"; exit 1; fi
fastboot $* reboot
if [ $? -ne 0 ] ; then echo "Reboot error"; exit 1; fi
```

```
$ bash flash_all_except_storage.sh
product: MSM8996_A7
target reported max download size of 536870912 bytes
sending 'xbl' (1787 KB)...
OKAY [  0.076s]
writing 'xbl'...
OKAY [  3.242s]
finished. total time: 3.317s
target reported max download size of 536870912 bytes
sending 'tz' (1628 KB)...
OKAY [  0.075s]
writing 'tz'...
OKAY [  0.035s]
finished. total time: 0.110s
target reported max download size of 536870912 bytes
sending 'tzbak' (1628 KB)...
OKAY [  0.087s]
writing 'tzbak'...
OKAY [  0.034s]
finished. total time: 0.121s
target reported max download size of 536870912 bytes
sending 'hyp' (257 KB)...
OKAY [  0.030s]
writing 'hyp'...
OKAY [  0.025s]
finished. total time: 0.056s
target reported max download size of 536870912 bytes
sending 'hypbak' (257 KB)...
OKAY [  0.040s]
writing 'hypbak'...
OKAY [  0.025s]
finished. total time: 0.065s
target reported max download size of 536870912 bytes
sending 'rpm' (224 KB)...
OKAY [  0.027s]
writing 'rpm'...
OKAY [  0.025s]
finished. total time: 0.052s
target reported max download size of 536870912 bytes
sending 'rpmbak' (224 KB)...
OKAY [  0.040s]
writing 'rpmbak'...
OKAY [  0.025s]
finished. total time: 0.065s
target reported max download size of 536870912 bytes
sending 'aboot' (1848 KB)...
OKAY [  0.078s]
writing 'aboot'...
OKAY [  0.043s]
finished. total time: 0.121s
target reported max download size of 536870912 bytes
sending 'abootbak' (1848 KB)...
OKAY [  0.087s]
writing 'abootbak'...
OKAY [  0.036s]
finished. total time: 0.123s
target reported max download size of 536870912 bytes
sending 'pmic' (41 KB)...
OKAY [  0.040s]
writing 'pmic'...
OKAY [  0.022s]
finished. total time: 0.062s
target reported max download size of 536870912 bytes
sending 'pmicbak' (41 KB)...
OKAY [  0.040s]
writing 'pmicbak'...
OKAY [  0.022s]
finished. total time: 0.062s
target reported max download size of 536870912 bytes
sending 'devcfg' (50 KB)...
OKAY [  0.040s]
writing 'devcfg'...
OKAY [  0.023s]
finished. total time: 0.062s
target reported max download size of 536870912 bytes
sending 'bluetooth' (396 KB)...
OKAY [  0.038s]
writing 'bluetooth'...
OKAY [  0.027s]
finished. total time: 0.065s
target reported max download size of 536870912 bytes
sending 'cmnlib' (200 KB)...
OKAY [  0.029s]
writing 'cmnlib'...
OKAY [  0.024s]
finished. total time: 0.053s
target reported max download size of 536870912 bytes
sending 'cmnlibbak' (200 KB)...
OKAY [  0.040s]
writing 'cmnlibbak'...
OKAY [  0.024s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'cmnlib64' (254 KB)...
OKAY [  0.031s]
writing 'cmnlib64'...
OKAY [  0.026s]
finished. total time: 0.057s
target reported max download size of 536870912 bytes
sending 'cmnlib64bak' (254 KB)...
OKAY [  0.040s]
writing 'cmnlib64bak'...
OKAY [  0.024s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'modem' (100012 KB)...
OKAY [  3.215s]
writing 'modem'...
OKAY [  0.736s]
finished. total time: 3.951s
target reported max download size of 536870912 bytes
sending 'dsp' (16384 KB)...
OKAY [  0.540s]
writing 'dsp'...
OKAY [  0.142s]
finished. total time: 0.682s
target reported max download size of 536870912 bytes
sending 'keymaster' (352 KB)...
OKAY [  0.037s]
writing 'keymaster'...
OKAY [  0.033s]
finished. total time: 0.071s
target reported max download size of 536870912 bytes
sending 'keymasterbak' (352 KB)...
OKAY [  0.049s]
writing 'keymasterbak'...
OKAY [  0.027s]
finished. total time: 0.076s
target reported max download size of 536870912 bytes
sending 'misc' (8 KB)...
OKAY [  0.040s]
writing 'misc'...
OKAY [  0.021s]
finished. total time: 0.061s
target reported max download size of 536870912 bytes
erasing 'system'...
OKAY [  0.011s]
sending sparse 'system' 1/6 (515097 KB)...
OKAY [ 18.031s]
writing 'system' 1/6...
OKAY [  4.457s]
sending sparse 'system' 2/6 (504774 KB)...
OKAY [ 18.140s]
writing 'system' 2/6...
OKAY [  5.973s]
sending sparse 'system' 3/6 (522648 KB)...
OKAY [ 18.195s]
writing 'system' 3/6...
OKAY [  7.701s]
sending sparse 'system' 4/6 (523748 KB)...
OKAY [ 18.097s]
writing 'system' 4/6...
OKAY [  6.480s]
sending sparse 'system' 5/6 (518168 KB)...
OKAY [ 18.027s]
writing 'system' 5/6...
OKAY [  4.657s]
sending sparse 'system' 6/6 (404139 KB)...
OKAY [ 14.305s]
writing 'system' 6/6...
OKAY [  4.055s]
finished. total time: 138.128s
target reported max download size of 536870912 bytes
erasing 'cache'...
OKAY [  0.007s]
sending 'cache' (6248 KB)...
OKAY [  0.229s]
writing 'cache'...
OKAY [  0.081s]
finished. total time: 0.317s
target reported max download size of 536870912 bytes
sending 'recovery' (24693 KB)...
OKAY [  0.808s]
writing 'recovery'...
OKAY [  0.207s]
finished. total time: 1.015s
target reported max download size of 536870912 bytes
sending 'splash' (151 KB)...
OKAY [  0.024s]
writing 'splash'...
OKAY [  0.034s]
finished. total time: 0.057s
target reported max download size of 536870912 bytes
sending 'logo' (728 KB)...
OKAY [  0.042s]
writing 'logo'...
OKAY [  0.029s]
finished. total time: 0.071s
erasing 'boot'...
OKAY [  0.021s]
finished. total time: 0.021s
erasing 'sec'...
OKAY [  0.021s]
finished. total time: 0.021s
erasing 'switch'...
OKAY [  0.021s]
finished. total time: 0.021s
erasing 'mdtp'...
OKAY [  0.021s]
finished. total time: 0.021s
target reported max download size of 536870912 bytes
sending 'boot' (22873 KB)...
OKAY [  0.749s]
writing 'boot'...
OKAY [  0.187s]
finished. total time: 0.937s
target reported max download size of 536870912 bytes
sending 'cust' (329329 KB)...
OKAY [ 10.508s]
writing 'cust'...
OKAY [  2.503s]
finished. total time: 13.011s
rebooting...

finished. total time: 0.360s
```

```
$ bash flash_all.sh
product: MSM8996_A7
target reported max download size of 536870912 bytes
sending 'xbl' (1787 KB)...
OKAY [  0.087s]
writing 'xbl'...
OKAY [  3.240s]
finished. total time: 3.327s
target reported max download size of 536870912 bytes
sending 'tz' (1628 KB)...
OKAY [  0.087s]
writing 'tz'...
OKAY [  0.035s]
finished. total time: 0.122s
target reported max download size of 536870912 bytes
sending 'tzbak' (1628 KB)...
OKAY [  0.089s]
writing 'tzbak'...
OKAY [  0.034s]
finished. total time: 0.123s
target reported max download size of 536870912 bytes
sending 'hyp' (257 KB)...
OKAY [  0.039s]
writing 'hyp'...
OKAY [  0.025s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'hypbak' (257 KB)...
OKAY [  0.040s]
writing 'hypbak'...
OKAY [  0.025s]
finished. total time: 0.065s
target reported max download size of 536870912 bytes
sending 'rpm' (224 KB)...
OKAY [  0.039s]
writing 'rpm'...
OKAY [  0.025s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'rpmbak' (224 KB)...
OKAY [  0.039s]
writing 'rpmbak'...
OKAY [  0.025s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'aboot' (1848 KB)...
OKAY [  0.097s]
writing 'aboot'...
OKAY [  0.049s]
finished. total time: 0.146s
target reported max download size of 536870912 bytes
sending 'abootbak' (1848 KB)...
OKAY [  0.087s]
writing 'abootbak'...
OKAY [  0.035s]
finished. total time: 0.122s
target reported max download size of 536870912 bytes
sending 'pmic' (41 KB)...
OKAY [  0.040s]
writing 'pmic'...
OKAY [  0.022s]
finished. total time: 0.062s
target reported max download size of 536870912 bytes
sending 'pmicbak' (41 KB)...
OKAY [  0.040s]
writing 'pmicbak'...
OKAY [  0.022s]
finished. total time: 0.062s
target reported max download size of 536870912 bytes
sending 'devcfg' (50 KB)...
OKAY [  0.040s]
writing 'devcfg'...
OKAY [  0.023s]
finished. total time: 0.062s
target reported max download size of 536870912 bytes
sending 'bluetooth' (396 KB)...
OKAY [  0.049s]
writing 'bluetooth'...
OKAY [  0.026s]
finished. total time: 0.076s
target reported max download size of 536870912 bytes
sending 'cmnlib' (200 KB)...
OKAY [  0.039s]
writing 'cmnlib'...
OKAY [  0.024s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'cmnlibbak' (200 KB)...
OKAY [  0.039s]
writing 'cmnlibbak'...
OKAY [  0.025s]
finished. total time: 0.065s
target reported max download size of 536870912 bytes
sending 'cmnlib64' (254 KB)...
OKAY [  0.039s]
writing 'cmnlib64'...
OKAY [  0.025s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'cmnlib64bak' (254 KB)...
OKAY [  0.039s]
writing 'cmnlib64bak'...
OKAY [  0.025s]
finished. total time: 0.064s
target reported max download size of 536870912 bytes
sending 'modem' (100012 KB)...
OKAY [  3.344s]
writing 'modem'...
OKAY [  0.746s]
finished. total time: 4.090s
target reported max download size of 536870912 bytes
sending 'dsp' (16384 KB)...
OKAY [  0.564s]
writing 'dsp'...
OKAY [  0.143s]
finished. total time: 0.707s
target reported max download size of 536870912 bytes
sending 'keymaster' (352 KB)...
OKAY [  0.049s]
writing 'keymaster'...
OKAY [  0.026s]
finished. total time: 0.075s
target reported max download size of 536870912 bytes
sending 'keymasterbak' (352 KB)...
OKAY [  0.049s]
writing 'keymasterbak'...
OKAY [  0.027s]
finished. total time: 0.076s
target reported max download size of 536870912 bytes
sending 'misc' (8 KB)...
OKAY [  0.040s]
writing 'misc'...
OKAY [  0.021s]
finished. total time: 0.061s
target reported max download size of 536870912 bytes
erasing 'system'...
OKAY [  0.004s]
sending sparse 'system' 1/5 (524196 KB)...
OKAY [ 17.580s]
writing 'system' 1/5...
OKAY [  5.016s]
sending sparse 'system' 2/5 (524270 KB)...
OKAY [ 17.879s]
writing 'system' 2/5...
OKAY [  5.443s]
sending sparse 'system' 3/5 (520533 KB)...
OKAY [ 17.652s]
writing 'system' 3/5...
OKAY [  5.712s]
sending sparse 'system' 4/5 (524235 KB)...
OKAY [ 17.903s]
writing 'system' 4/5...
OKAY [  6.813s]
sending sparse 'system' 5/5 (463268 KB)...
OKAY [ 15.740s]
writing 'system' 5/5...
OKAY [  5.191s]
finished. total time: 114.933s
target reported max download size of 536870912 bytes
erasing 'cache'...
OKAY [  0.013s]
sending 'cache' (6248 KB)...
OKAY [  0.240s]
writing 'cache'...
OKAY [  0.083s]
finished. total time: 0.335s
target reported max download size of 536870912 bytes
erasing 'userdata'...
OKAY [  0.006s]
sending 'userdata' (141463 KB)...
OKAY [  4.713s]
writing 'userdata'...
OKAY [  1.212s]
finished. total time: 5.932s
target reported max download size of 536870912 bytes
sending 'recovery' (24693 KB)...
OKAY [  0.832s]
writing 'recovery'...
OKAY [  0.219s]
finished. total time: 1.051s
target reported max download size of 536870912 bytes
sending 'splash' (151 KB)...
OKAY [  0.039s]
writing 'splash'...
OKAY [  0.024s]
finished. total time: 0.063s
target reported max download size of 536870912 bytes
sending 'logo' (728 KB)...
OKAY [  0.059s]
writing 'logo'...
OKAY [  0.035s]
finished. total time: 0.094s
erasing 'boot'...
OKAY [  0.021s]
finished. total time: 0.021s
erasing 'sec'...
OKAY [  0.021s]
finished. total time: 0.021s
erasing 'switch'...
OKAY [  0.021s]
finished. total time: 0.021s
erasing 'mdtp'...
OKAY [  0.021s]
finished. total time: 0.021s
target reported max download size of 536870912 bytes
sending 'boot' (22873 KB)...
OKAY [  0.773s]
writing 'boot'...
OKAY [  0.198s]
finished. total time: 0.972s
target reported max download size of 536870912 bytes
sending 'cust' (194294 KB)...
OKAY [  6.520s]
writing 'cust'...
OKAY [  2.138s]
finished. total time: 8.658s
rebooting...

finished. total time: 0.411s

```
