--- layout: post title: adb no such file date: 2012-09-18 14:21:00.000000000 +08:00 type: post published: true status: publish categories: \[\] tags: \[\] meta: \_oembed\_17449c0ccd4c296396f7b80301328020: "{{unknown}}" blogger\_blog: www.ashang.org blogger\_author: Aaron Shang blogger\_d06f7f5bcdfeb296283c00dcf750b675\_permalink: '316852128156199786' \_oembed\_db40a44b94672de8384641f1bd691e6d: "{{unknown}}" \_oembed\_16fb653129e469f0e3999a201888362d: "{{unknown}}" \_oembed\_5a3a0ceafe762a086fae28f81cea744f: "{{unknown}}" \_oembed\_d23eafb2fd8c27df46affabafe0796f7: "{{unknown}}" \_oembed\_b6425fc5d8278204d9b056bf3ae721fd: "{{unknown}}" author: login: aaronshang email: aaronshang@gmail.com display\_name: Aaron first\_name: '' last\_name: '' ---

**Common adb errors and solutions**
-----------------------------------

#### **No such file or directory**

/path/to/android-sdk-linux/platform-tools/adb: No such file or directory

Solution:

$ sudo apt-get install ia32-libs

Links:
<https://bugs.launchpad.net/ubuntu/+source/ia32-libs/+bug/852101>
<http://askubuntu.com/questions/73491/no-such-file-or-directory-for-existing-executable>
<http://kenno.wordpress.com/2011/10/27/ubuntu-11-10-32-bit-applications-do-not-run-64-bit/>

#### insufficient permissions for device

$ adb shell df
error: insufficient permissions for device

$ sudo adb kill-server
\[sudo\] password for aaron:

$ adb shell df
\* daemon not running. starting it now on port 5037 \*
\* daemon started successfully \*
Filesystem Size Used Free Blksize
/dev 338.7M 64.0K 338.7M 4096
/mnt/asec 338.7M 0.0K 338.7M 4096
/mnt/obb 338.7M 0.0K 338.7M 4096
/system 1007.9M 550.9M 457.0M 4096
/data 4.0G 172.8M 3.8G 4096
/cache 246.1M 4.1M 241.9M 4096
/mnt/sdcard 21.2G 912.8M 20.3G 32768
/mnt/secure/asec: Permission denied

"adb start-server " is automatically run.

$ adb kill-server ;  sudo adb start-server ; adb devices
When to use "sudo" for adb? never needed?

1
  adb kill-server ;  sudo adb start-server ; adb shell df

2
 adb kill-server ;  adb start-server ; adb shell df

3
 adb kill-server ;  sudo adb shell df

Result 1 equals 3

2 will give
 error: insufficient permissions for device
