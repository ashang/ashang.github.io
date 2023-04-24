---
title: chromium
date: 2014-12-20
---

### Audit usage of navigator.userAgent, navigator.appVersion, and navigator.platform

A page or script is accessing at least one of navigator.userAgent, navigator.appVersion, and navigator.platform. Starting in Chrome 101, the amount of information available in the User Agent string will be reduced.

To fix this issue, replace the usage of navigator.userAgent, navigator.appVersion, and navigator.platform with feature detection, progressive enhancement, or migrate to navigator.userAgentData.

---

Depot Tools is a set of scripts/utilities that:

Manage all checkouts in the Chromium source tree
Generate the build files for your platform
Upload your changes to Gerrit for review

Common utilities:
gclient - syncs your source tree and creates build files.
git-cl - integration with code review and tryjobs

  $ git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
  $ export PATH=`pwd`/depot_tools:"$PATH"


gclient attempts to update itself each run and can fail here
gclient sync both updates your source code, and regenerates build files (implicitly doing gclient runhooks)

- https://chromium.googlesource.com/chromium/src/+/HEAD/docs/linux/debugging.md

- https://chromium.googlesource.com/chromium/src.git

- https://chromium.googlesource.com/chromium/src/+/main/docs/linux/build_instructions.md

- https://chromium.googlesource.com/chromium/src/+/main/docs/linux/build_instructions.md

## The Difference between Google Chrome and Chromium on Linux

Google Chrome is the Chromium open source project built, packaged, and
distributed by Google.

### Google Chrome

*   Colorful logo
*   [Reports crashes](linux_crash_dumping.md) only if turned on.
    Please include symbolized backtraces in bug reports if you don't have crash
    reporting turned on.
*   User metrics only if turned on
*   Video and Audio codecs (may vary by distro)
    *   AAC, H.264, MP3, Opus, Theora, Vorbis, VP8, VP9, and WAV
*   Sandboxed PPAPI (non-free) Flash plugin included in release
*   Code is tested by Chrome developers
*   Sandbox is always on
*   Single deb/rpm package
*   Profile is kept in `~/.config/google-chrome`
*   Cache is kept in `~/.cache/google-chrome`
*   New releases are tested before being sent to users
*   Google API keys are added by Google

### Chromium

*   Blue logo
*   Does not ever [report crashes](linux_crash_dumping.md). Please include
    symbolized backtraces in bug reports.
*   User metrics are never reported.
*   Video and Audio codecs (may vary by distro)
    *   Opus, Theora, Vorbis, VP8, VP9, and WAV by default
*   Supports NPAPI (unsandboxed) Flash plugins, including the one from Adobe in
    Chrome 34 and below
*   Code may be modified by distributions
*   Sandbox depends on the distribution (navigate to about:sandbox to confirm)
*   Packaging depends on the distribution
*   Profile is kept in `~/.config/chromium`
*   Cache is kept in `~/.cache/chromium`
*   New release testing depends on the distribution
    *   Distributions are encouraged to track stable channel releases: see
        http://googlechromereleases.blogspot.com/, http://omahaproxy.pspot.com/
        and http://gsdview.appspot.com/chromium-browser-official/
*   Google API keys depend on the distribution
    *   See http://www.chromium.org/developers/how-tos/api-keys

$ google-chrome --ozone-platform-hint=auto
[3531127:3531127:1230/092422.642314:ERROR:gpu_init.cc(523)] Passthrough is not supported, GL is egl, ANGLE is
[3531079:3531117:1230/092422.749859:ERROR:token_service_table.cc(139)] Failed to decrypt token for service AccountId-118034960111961848735
[3531079:3531152:1230/092423.634523:ERROR:nss_util.cc(349)] After loading Root Certs, loaded==false: NSS error code: -8018
[3531079:3531079:1230/092427.618047:ERROR:password_sync_bridge.cc(1043)] Passwords datatype error was encountered: Failed to get encryption key during database cleanup.
[3531079:3531109:1230/093426.761030:ERROR:connection_factory_impl.cc(472)] ConnectionHandler failed with net error: -2


## NO GPU


google-chrome --use-gl=osmesa --disable-gl-drawing-for-tests



chromium-browser
[247109:247109:1209/144440.081685:ERROR:sandbox_linux.cc(369)] InitializeSandbox() called with multiple threads in process gpu-process.
[247077:247457:1209/144441.077133:ERROR:token_service_table.cc(141)] Failed to decrypt token for service AccountId-116622199695860203423
[247109:247109:1209/144441.822265:ERROR:buffer_manager.cc(488)] [.DisplayCompositor]GL ERROR :GL_INVALID_OPERATION : glBufferData: <- error from previous GL command
[247113:247125:1209/144442.928176:ERROR:nss_util.cc(748)] After loading Root Certs, loaded==false: NSS error code: -8018
[247077:247077:1209/144443.668001:ERROR:account_tracker.cc(240)] AccessTokenFetched error: Invalid credentials (credentials rejected by server).
[247109:247109:1209/144449.408207:ERROR:buffer_manager.cc(488)] [.DisplayCompositor]GL ERROR :GL_INVALID_OPERATION : glBufferData: <- error from previous GL command
[247109:247109:1209/144450.651805:ERROR:buffer_manager.cc(488)] [.DisplayCompositor]GL ERROR :GL_INVALID_OPERATION : glBufferData: <- error from previous GL command
[247109:247109:1209/144454.003693:ERROR:buffer_manager.cc(488)] [.DisplayCompositor]GL ERROR :GL_INVALID_OPERATION : glBufferData: <- error from previous GL command
[247109:247109:1209/144505.820098:ERROR:buffer_manager.cc(488)] [.DisplayCompositor]GL ERROR :GL_INVALID_OPERATION : glBufferData: <- error from previous GL command
[247113:247126:1209/144948.159833:ERROR:ssl_client_socket_impl.cc(943)] handshake failed; returned -1, SSL error code 1, net_error -200
[247113:247126:1209/144948.923616:ERROR:ssl_client_socket_impl.cc(943)] handshake failed; returned -1, SSL error code 1, net_error -200
[247113:247126:1209/144950.738823:ERROR:ssl_client_socket_impl.cc(943)] handshake failed; returned -1, SSL error code 1, net_error -200
[247113:247126:1209/144951.807107:ERROR:ssl_client_socket_impl.cc(943)] handshake failed; returned -1, SSL error code 1, net_error -200
[247113:247126:1209/145007.679966:ERROR:ssl_client_socket_impl.cc(943)] handshake failed; returned -1, SSL error code 1, net_error -200



https://cs.chromium.org/chromium/src/content/public/common/content_switches.cc?q=kDisableGpu

    Disables GPU hardware acceleration. If software renderer is not in place, then the GPU process won't launch

https://cs.chromium.org/chromium/src/content/public/common/content_switches.cc?q=kDisableSoftwareRasterizer

    Disables the use of a 3D software rasterizer


# [247109:247109:1209/144440.081685:ERROR:sandbox_linux.cc(369)] InitializeSandbox() called with multiple threads in process gpu-process.

This happens whenever mesa
drivers are used since threads are used in their GLSL shader
implementation.  This does have a consequence, chromium's GPU driver
will not be sandboxed.  You can see this in about:gpu.

Also seen upstream, it should be possible to work around the problem
by setting MESA_GLSL_CACHE_DISABLE=true.

https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=918433



$ MESA_GLSL_CACHE_DISABLE=true chromium-browser --disable-gpu --disable-software-rasterizer

--user-data-dir=/home/antergos/.config/chromium/Default --homepage=http://antergos.com

# chrome commands


Clear history/cookie/data
This is done via menu access, or in the browser address bar: chrome://settings/clearBrowserData and use "From beginning of time". More info is found here.

Clear host cache
Type in browser address bar: chrome://net-internals/#dns and click "Clear Host Cache".

## Close and flush sockets
Type in browser address bar: chrome://net-internals/#sockets and click "Close Idle Sockets" and "Flush Socket Pools".

Flush Sockets
There are two methods two flush sockets


chrome://net-internals/#events&q=type:SPDY_SESSION%20is:active

现在已经不支持了。

The net-internals events viewer and related functionality has been removed. Please use chrome://net-export to save netlogs and the external catapult netlog_viewer to view them.

chrome://net-export/

chrome://net-internals/#sockets


## Clear DNS cache
If you are using Windows, run as administrator the Command Prompt (cmd) and enter the commands : ipconfig /flushdns and ipconfig /release.

Clear Host Cache and DNS Cache
To clear hosts cache of chrome Open chrome nrowser and visit to following url and click on the clear host Cache Button.

chrome://net-internals/#dns

To Clear the DNS Cache Run the command prompt with administrator rights. To do so run command prompt by right clicking and selecting option “Run as Administrator” and run the following command on command prompt

ipconfig /flushdns
ipconfig /release



#

chrome://flags/    ##实验性功能设置

QUIC



 chrome://plugins/    ## 插件设置
 about:cache   ##缓存地址
 about:memory  ##内存使用情况
 about:histograms   ##内部性能指标的直方图
 about:dns   ##显示一些网站主机的DNS记录
 about:crash   ##显示崩溃画面

 常见问题

    启动chrome,出现Chrome”无法正确打开您的配置文件”错误

方法一:终端执行:

 rm ~/.config/google-chrome/Default/Web\ Data

方法二:终端执行:

 rm ~/.config/google-chrome

注意:推荐使用方法一,方法一失效后才使用方法二,方法二会删除所以chrome的数据,包括书签和拓展等!

    Chrome启动总询问密钥环的处理

    方法一:取消自动登录
    方法二:终端执行：

 sudo apt-get install seahorse

安装好后运行seahorse 密码下面有一个login的，右击，更改密码 旧密码输入自己的密码，新密码留空，确定会问你是否使用不安全密钥什么的，点使用不安全密钥环就行了，以后不会再问你密钥环密码了

    Chrome在线文字.视频花屏或者乱码

chrome地址栏输入以下地址:

 chrome://plugins/    ## 插件设置

展开详细详细.定位到Adobe Flash Player,禁用类型为PPAPI（进程外插件）的Flash即可

 PPAPI的是chrome自带的，有沙箱，占内存略少，默认优先使用这个插件
 NPAPI的是Adobe官方的非IEflash，无沙箱，占内存略多，但在用某些需要检测referer的视频网站外链时不会403

注释:chrome自带flash插件,deepin默认也安装falsh插件,所以chrome有两个flash插件,但是自带插件错误较多,禁用内部插件,使用外部插件较少问题.

    制作本地程序

1：先打开网页应用，然后点击chrome浏览器的菜单---工具---创建应用快捷方式，桌面就会生成快捷图标。

2：替换图标,由于生成的图标普遍分辨率十分低，我们可以替换图标，打开主文件夹下的.icons文件夹，找到这些快捷方式图标所在的地方，然后把要替换的新图标放进去，并改成快捷方式图标的名称，删掉快捷方式图标。

3：回到桌面右击要替换的网页应用--属性，然后在出现的属性框左上角点击那个图标，这时出现选择界面，找到刚才准备好的新图标，选择确定就OK了

    无法删除Chrome浏览器，apt会循环安装不同版本

这个问题是由于谷歌浏览器添加了自己的源，当你卸载chrome浏览器的同时。apt依据源会安装上其他版本的chrome。解决方法终端执行：

 sudo gedit /etc/apt/sources.list

页搜索chrome删除chrome源，然后需要刷新列表和删除chrome，终端执行：

 sudo apt-get update
 sudo aptitude remove google-chrome-*




Created new window in existing browser session.
[30087:30116:1106/143448.433347:ERROR:browser_gpu_channel_host_factory.cc(108)] Failed to launch GPU process.



systemd-+-NetworkManager---3*[{NetworkManager}]
        |-avahi-daemon---avahi-daemon
        |-bash---chromium-+-chrome-sandbox---chromium---chromium-+-6*[chromium---11*[{chromium}]]
        |                 |                                      |-50*[chromium---12*[{chromium}]]
        |                 |                                      |-7*[chromium---13*[{chromium}]]
        |                 |                                      `-2*[chromium---14*[{chromium}]]
        |                 `-33*[{chromium}]
        |-bluetoothd
        |-crond
        |-dbus-daemon
        |-dockerd-+-docker-containe---16*[{docker-containe}]
        |         `-15*[{dockerd}]
        |-lvmetad
        |-master-+-pickup
        |        `-qmgr
        |-polkitd---11*[{polkitd}]
        |-rtkit-daemon---2*[{rtkit-daemon}]
        |-sddm-+-Xorg---{Xorg}
        |      |-sddm-helper---sddm-greeter---4*[{sddm-greeter}]
        |      |-sddm-helper---sway-+-Xwayland
        |      |                    |-sway
        |      |                    |-swaybar---sh---sleep
        |      |                    `-swaybg
        |      `-{sddm}
        |-snapd---11*[{snapd}]
        |-ssh-agent
        |-sshd
        |-systemd-+-(sd-pam)
        |         `-dbus-daemon
        |-systemd-+-(sd-pam)
        |         |-at-spi-bus-laun-+-dbus-daemon
        |         |                 `-3*[{at-spi-bus-laun}]
        |         |-at-spi2-registr---2*[{at-spi2-registr}]
        |         |-dbus-daemon
        |         |-dconf-service---2*[{dconf-service}]
        |         |-gvfs-afc-volume---3*[{gvfs-afc-volume}]
        |         |-gvfs-gphoto2-vo---2*[{gvfs-gphoto2-vo}]
        |         |-gvfs-mtp-volume---2*[{gvfs-mtp-volume}]
        |         |-gvfs-udisks2-vo---2*[{gvfs-udisks2-vo}]
        |         |-gvfsd-+-gvfsd-computer---2*[{gvfsd-computer}]
        |         |       |-gvfsd-dnssd---2*[{gvfsd-dnssd}]
        |         |       |-gvfsd-network---3*[{gvfsd-network}]
        |         |       |-gvfsd-trash---2*[{gvfsd-trash}]
        |         |       `-2*[{gvfsd}]
        |         |-gvfsd-fuse---5*[{gvfsd-fuse}]
        |         |-gvfsd-metadata---2*[{gvfsd-metadata}]
        |         |-pulseaudio---2*[{pulseaudio}]
        |         |-2*[xdg-desktop-por---3*[{xdg-desktop-por}]]
        |         |-xdg-document-po---6*[{xdg-document-po}]
        |         `-xdg-permission----2*[{xdg-permission-}]
        |-systemd-journal
        |-systemd-logind
        |-systemd-resolve
        |-systemd-timesyn---{systemd-timesyn}
        |-systemd-udevd
        |-terminator-+-bash---pstree
        |            |-bash
        |            |-bash---tmux: client
        |            `-3*[{terminator}]
        |-thermald---{thermald}
        |-tmux: server-+-bash---ss-local
        |              |-2*[bash]
        |              `-bash---more
        |-udisksd---4*[{udisksd}]
        |-vsftpd
        `-wpa_supplicant



```
[15041:15041:0629/135302.087170:ERROR:shared_image_manager.cc(212)] SharedImageManager::ProduceSkia: Trying to Produce a Skia representation from a non-existent mailbox.
[15041:15041:0629/135302.087748:ERROR:shared_image_manager.cc(212)] SharedImageManager::ProduceSkia: Trying to Produce a Skia representation from a non-existent mailbox.
[15041:15041:0629/135302.090631:ERROR:shared_image_manager.cc(212)] SharedImageManager::ProduceSkia: Trying to Produce a Skia representation from a non-existent mailbox.
[15041:15041:0629/135324.345793:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 1 times!
[15041:15041:0629/135324.378042:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 2 times!
[15041:15041:0629/135324.444928:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 3 times!
[15041:15041:0629/135324.505483:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 4 times!
[15041:15041:0629/135324.544686:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 5 times!
[15041:15041:0629/135324.645598:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 6 times!
[15041:15041:0629/135324.745072:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 7 times!
[15041:15041:0629/135324.758827:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 8 times!
[15041:15041:0629/135324.765813:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 9 times!
[15041:15041:0629/135324.845284:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 10 times!
[15041:15041:0629/135324.944670:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 11 times!
[15041:15041:0629/135325.013116:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 12 times!
[15041:15041:0629/135325.045442:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 13 times!
[15041:15041:0629/135325.145119:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 14 times!
[15041:15041:0629/135325.244990:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 15 times!
[15041:15041:0629/135325.344696:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 16 times!
[15041:15041:0629/135325.442148:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 17 times!
[15041:15041:0629/135325.448489:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 18 times!
[15041:15041:0629/135325.514918:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 19 times!
[15004:15025:0629/135335.631937:ERROR:socket_stream.cc(218)] Closing stream with result -2
[15041:15041:0629/135401.436162:ERROR:gl_surface_presentation_helper.cc(259)] GetVSyncParametersIfAvailable() failed for 256 times!
Received signal 11 SEGV_MAPERR 000000000090
#0 0x55654b9685a9 (/usr/lib/chromium/chromium+0x52485a8)
#1 0x55654b8cdac3 (/usr/lib/chromium/chromium+0x51adac2)
#2 0x55654b968131 (/usr/lib/chromium/chromium+0x5248130)
#3 0x7f97a2dd9110 (/usr/lib/x86_64-linux-gnu/libpthread-2.30.so+0x1410f)
#4 0x5565497df2a7 (/usr/lib/chromium/chromium+0x30bf2a6)
#5 0x5565497da2f9 (/usr/lib/chromium/chromium+0x30ba2f8)
#6 0x5565497360fb (/usr/lib/chromium/chromium+0x30160fa)
#7 0x55654973b4c0 (/usr/lib/chromium/chromium+0x301b4bf)
#8 0x55654973ea29 (/usr/lib/chromium/chromium+0x301ea28)
#9 0x55654973e839 (/usr/lib/chromium/chromium+0x301e838)
#10 0x55654973eb64 (/usr/lib/chromium/chromium+0x301eb63)
#11 0x556549735e1e (/usr/lib/chromium/chromium+0x3015e1d)
#12 0x55654973c9cf (/usr/lib/chromium/chromium+0x301c9ce)
#13 0x55654b918442 (/usr/lib/chromium/chromium+0x51f8441)
#14 0x55654b928139 (/usr/lib/chromium/chromium+0x5208138)
#15 0x55654b927ed5 (/usr/lib/chromium/chromium+0x5207ed4)
#16 0x55654b8e3daa (/usr/lib/chromium/chromium+0x51c3da9)
#17 0x55654b9289e9 (/usr/lib/chromium/chromium+0x52089e8)
#18 0x55654b900c84 (/usr/lib/chromium/chromium+0x51e0c83)
#19 0x55654b93caa9 (/usr/lib/chromium/chromium+0x521caa8)
#20 0x55654b97846e (/usr/lib/chromium/chromium+0x525846d)
#21 0x7f97a2dcdf27 start_thread
#22 0x7f979df7631f clone
  r8: 00005565497df310  r9: 0000000000000000 r10: 0000000000000000 r11: 0000000000000246
 r12: 00007f978801f5b0 r13: 000055655257d2a0 r14: 00007f975400b690 r15: 00007f975400b760
  di: 00007f975400b690  si: 0000000000008000  bp: 00007f9750e1f9e0  bx: 000055655254d0d0
  dx: 0000000000000000  ax: 0000000000000001  cx: 0000000000000000  sp: 00007f9750e1f9c0
  ip: 00005565497df2a7 efl: 0000000000010202 cgf: 002b000000000033 erf: 0000000000000006
 trp: 000000000000000e msk: 0000000000000000 cr2: 0000000000000090
[end of stack trace]
Calling _exit(1). Core file will not be generated.

```

# Debug

chrome://serviceworker-internals


# How to manually install extensions from local offline.

Go to settings, and extension page.

chrome://extensions/

Check on the "Developer mode".

Drag the .crx file and drop it onto the extensions page.




http://www.chromium.org/user-experience/user-data-directory


What kind of extension is it? Is it a .CRX file? A (possibly ZIP’d) folder? A .JS user-script? The process differs for each.

CRX:
* Drag and drop the .CRX file onto the page chrome://extensions
* Click the Install button in the prompt at the bottom of the screen

Folder:
* If it is ZIP’d, extract the contents somewhere
* In Chrome, open chrome://extensions/
* Click + Developer mode
* Click Load unpacked extension…
* Navigate to the extension’s folder and click OK
* Delete the (extracted) folder (the extension was copied)

User Script:
* Exit Chrome (all windows)
* Copy the .JS file to the User Scripts folder in your User Data folder
* Run Chrome

# Linux Chromium Packages


| **Distro** | **Contact** | **URL for packages** | **URL for distro-specific patches** |
|:-----------|:------------|:---------------------|:------------------------------------|
| Ubuntu     | Chad Miller `chad.miller@canonical.com` | https://launchpad.net/ubuntu/+source/chromium-browser | https://code.launchpad.net/ubuntu/+source/chromium-browser |
| Debian     | [see package page](http://packages.debian.org/sid/chromium) | in standard repo     | [debian patch tracker](http://patch-tracker.debian.org/package/chromium-browser/) |
| openSUSE   | Raymond Wooninck  `tittiatcoke@gmail.com` | http://software.opensuse.org/search?baseproject=ALL&p=1&q=chromium | ??                                  |
| Arch       | Evangelos Foutras `evangelos@foutrelis.com` | http://www.archlinux.org/packages/extra/x86_64/chromium/ | [link](http://projects.archlinux.org/svntogit/packages.git/tree/trunk?h=packages/chromium) |
| Gentoo     | [project page](http://www.gentoo.org/proj/en/desktop/chromium/index.xml) | Available in portage, [www-client/chromium](http://packages.gentoo.org/package/www-client/chromium) | http://sources.gentoo.org/viewcvs.py/gentoo-x86/www-client/chromium/files/ |
| ALT Linux  | Andrey Cherepanov (Андрей Черепанов) `cas@altlinux.org` | http://packages.altlinux.org/en/Sisyphus/srpms/chromium | http://git.altlinux.org/gears/c/chromium.git?a=tree |
| Mageia     | Dexter Morgan `dmorgan@mageia.org` | http://svnweb.mageia.org/packages/cauldron/chromium-browser-stable/current/SPECS/ | http://svnweb.mageia.org/packages/cauldron/chromium-browser-stable/current/SOURCES/ |
| NixOS      | aszlig `"^[0-9]+$"@regexmail.net` | http://hydra.nixos.org/search?query=pkgs.chromium | https://github.com/NixOS/nixpkgs/tree/master/pkgs/applications/networking/browsers/chromium |

## Unofficial packages

Packages in this section are not part of the distro's official repositories.

| **Distro** | **Contact** | **URL for packages** | **URL for distro-specific patches** |
|:-----------|:------------|:---------------------|:------------------------------------|
| Fedora     | Tom Callaway `tcallawa@redhat.com` | http://repos.fedorapeople.org/repos/spot/chromium/ | ??                                  |
| Slackware  | Eric Hameleers `alien@slackware.com` | http://www.slackware.com/~alien/slackbuilds/chromium/ | http://www.slackware.com/~alien/slackbuilds/chromium/ |

## Other Unixes

| **System** | **Contact** | **URL for packages** | **URL for patches** |
|:-----------|:------------|:---------------------|:--------------------|
| FreeBSD    | http://lists.freebsd.org/mailman/listinfo/freebsd-chromium | http://wiki.freebsd.org/Chromium | http://trillian.chruetertee.ch/chromium |
| OpenBSD    | Robert Nagy `robert@openbsd.org` | http://openports.se/www/chromium | http://www.openbsd.org/cgi-bin/cvsweb/ports/www/chromium/patches/ |

## Updating the list

Are you packaging Chromium for a Linux distro? Is the information above out of
date? Please contact `thestig@chromium.org` with updates.

Before emailing, please note:

*   This is not a support email address
*   If you ask about a Linux distro that is not listed above, the answer will be
    "I don't know"
*   Linux distros supported by Google Chrome are listed here:
    https://support.google.com/chrome/answer/95411


### libva error: vaGetDriverNameByIndex() failed with unknown libva error, driver_name = (null)

```sh
$ google-chrome
libva error: vaGetDriverNameByIndex() failed with unknown libva error, driver_name = (null)
[687616:687650:1117/103942.456991:ERROR:token_service_table.cc(139)] Failed to decrypt token for service AccountId-116800134236702867495
[687616:687650:1117/103942.457064:ERROR:token_service_table.cc(139)] Failed to decrypt token for service AccountId-118034960111961848735
[687616:687616:1117/103943.490302:ERROR:account_info_fetcher.cc(62)] OnGetTokenFailure: Invalid credentials (credentials missing).
[687616:687732:1117/103943.586065:ERROR:nss_util.cc(349)] After loading Root Certs, loaded==false: NSS error code: -8018
[687663:687663:1117/103945.407048:ERROR:gl_surface_presentation_helper.cc(260)] GetVSyncParametersIfAvailable() failed for 1 times!
[687663:687663:1117/103945.428917:ERROR:gl_surface_presentation_helper.cc(260)] GetVSyncParametersIfAvailable() failed for 2 times!
[687663:687663:1117/103945.850862:ERROR:gl_surface_presentation_helper.cc(260)] GetVSyncParametersIfAvailable() failed for 3 times!
[687672:687689:1117/103950.220775:ERROR:ssl_client_socket_impl.cc(982)] handshake failed; returned -1, SSL error code 1, net_error -100
[687672:687689:1117/103951.255937:ERROR:ssl_client_socket_impl.cc(982)] handshake failed; returned -1, SSL error code 1, net_error -100
[687672:687689:1117/104009.568269:ERROR:ssl_client_socket_impl.cc(982)] handshake failed; returned -1, SSL error code 1, net_error -100
[687672:687689:1117/104010.688782:ERROR:ssl_client_socket_impl.cc(982)] handshake failed; returned -1, SSL error code 1, net_error -100
Fontconfig error: Cannot load default config file: No such file: (null)
[687672:687689:1117/104016.253037:ERROR:ssl_client_socket_impl.cc(982)] handshake failed; returned -1, SSL error code 1, net_error -100
[687672:687689:1117/104017.264142:ERROR:ssl_client_socket_impl.cc(982)] handshake failed; returned -1, SSL error code 1, net_error -100
[687672:687689:1117/104045.219773:ERROR:ssl_client_socket_impl.cc(982)] handshake failed; returned -1, SSL error code 1, net_error -100
[687672:687689:1117/104046.243847:ERROR:ssl_client_socket_impl.cc(982)] handshake failed; returned -1, SSL error code 1, net_error -100
xdg-settings: $BROWSER is set and can't be changed with xdg-settings
Error in cpuinfo: failed to parse processor information from /proc/cpuinfo
[687663:687663:1117/104419.342437:ERROR:shared_image_manager.cc(189)] SharedImageManager::ProduceSkia: Trying to Produce a Skia representation from a non-existent mailbox.
[687663:687663:1117/104419.342933:ERROR:shared_image_manager.cc(189)] SharedImageManager::ProduceSkia: Trying to Produce a Skia representation from a non-existent mailbox.
```
