

The program is in sources/autokernconf/. It consists of two files:

kdetect.sh
a shell script with detect the actual hardware. It doesn't try to direct probe the harware, but it look for what the kernel know (attached on the various busses), so it should be safe.
autokernconf.sh
a shell script that compare the result of the just discussed kdetect.sh, with the LKDDb database, to find some needed drivers.
We choose to use two programs, so that user can run the detection on a target machine, and compile the kernel in an other machine. This choice allow also to make multiple (in time) detections, i.e. to attach new devices (i.e. for USB devices if the USB slot was not enough, docked and undocked laptop modes, ...).

usage:
./kdetect.sh

to detect actual hardware. Now the program heavily depends on the /sys/ filesystem, so you need a recent Linux kernel (a 2.6 linux kernel). Using the /sys simplify the detection: there are no direct hardware probes, so there is no (I hope) risk of crashes.

./autokernconf.sh

This program will read the lkddb.list and the kdetect.list. It will create an config.auto which includes the detected kernel configuration items.

NOTE: You need a lkddb.list hardware list from sources/lkddb/.

The autokernconf.sh is a slow shell script, because now it execute a probe for every database entry, and usually this probe requires a new call of grep shell utility. Probably it should be rewritten in a more efficient way, but still portable. How?


