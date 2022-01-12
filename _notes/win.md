---
title: windows notes
date: 2019-04-02
--- 



bootrec /fixmbr
bootrec /fixboot
bootrec /rebuildbcd
Chkdsk /f
Chkdsk C:/f


If you get error in any above method try this: bootsect /ntfs60 C: (replace drive letter with your boot drive letter) and again try the command which failed.




"bootrec" command sometimes has problems finding proper boot device and windows installation to fix.

Use "bcdboot" command to fix boot (bcdboot requires that partitions are specified explicitly!)

bcdboot C:\windows
bcdboot C:\windows /s S:

specifies C: as Windows partition, S: as system partition.

Use "diskpart" or "mountvol" commands to map system partition.

diskpart
list disk

select disk xxxx
list vol
assign letter=S:
S:
bcdboot C:\windows /s S: /f UEFI


