

The device mapper is a framework provided by the Linux kernel for mapping physical block devices onto higher-level virtual block devices. It forms the foundation of the logical volume manager (LVM), software RAIDs and dm-crypt disk encryption, and offers additional features such as file system snapshots.[1]

Device mapper works by passing data from a virtual block device, which is provided by the device mapper itself, to another block device. Data can be also modified in transition, which is performed, for example, in the case of device mapper providing disk encryption or simulation of unreliable hardware behavior.



[edit]
Applications (like LVM2 and Enterprise Volume Management System (EVMS)) that need to create new mapped devices talk to the device mapper via the libdevmapper.so shared library, which in turn issues ioctls to the /dev/mapper/control device node.[4] Configuration of the device mapper can be also examined and configured interactively‍—‌or from shell scripts‍—‌by using the dmsetup(8) utility.[5][6]

Both of these two userspace components have their source code maintained alongside the LVM2 source.[7]

Docker – uses device mapper to create copy-on-write storage for software containers


Linux version of TrueCrypt



DRBD (Distributed Replicated Block Device)



cryptsetup – utility used to conveniently setup disk encryption based on dm-crypt
dm-crypt/LUKS – mapping target that provides volume encryption
dm-cache – mapping target that allows creation of hybrid volumes



