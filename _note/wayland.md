---
title: wayland
date: 2018-07-02
tags: [programming]
---

Wayland运用既有的Linux核心技术，像是Direct Rendering Manager（DRM），Kernel Mode-Setting（KMS）以及Graphics Execution Manager（GEM）以提供一個最小化的显示管理服务。Wayland混合器（compositor）在2010年6月已从桌面常用的OpenGL改为OpenGL ES[12]。這個專案也開發支援Wayland顯示的Qt，而不需要X。大部分應用程式都有望獲得透過函式庫，無需修改程式即可支援Wayland。

近些年来，GNU/Linux桌面图形开发者将许多与渲染有关的接口从X server移动到内核中。现在，已经有许多功能被移入内核（内存管理、任务调度、模式设置（KMS）等等）或是程序库（cairo、pixman、freetype、fontconfig、pango等等），所以窗口系统需要做的事情大大减少了。



>Wayland is a protocol for a compositor to talk to its clients as well as a C library implementation of that protocol. The compositor can be a standalone display server running on Linux kernel modesetting and evdev input devices, an X application, or a Wayland client itself. The clients can be traditional applications, X servers (rootless or fullscreen) or other display servers.

Wayland is a replacement for the X11 window system protocol and architecture with the aim to be easier to develop, extend, and maintain.

Wayland is a communication protocol that specifies the communication between a display server and its clients, as well as a C library implementation of that protocol.

A display server using the Wayland protocol is a Wayland compositor, because it also performs the task of a compositing window manager.

A core part of Wayland architecture is libwayland: an inter-process communication library that translates a protocol definition in XML to a C language API.

This library merely encodes and decodes Wayland messages. The actual implementations are in the compositor and application toolkit projects.

A Wayland compositor could be a standalone display server running on Linux kernel modesetting and evdev input devices or on other operating systems, or a nested compositor that itself is an X11 or Wayland application (client). Wayland can even be in application-internal communication as is in some web browsers.




The Wayland protocol follows a client–server model in which clients are the graphical applications requesting the display of pixel buffers on the screen, and the server (compositor) is the service provider controlling the display of these buffers.

The Wayland reference implementation has been designed as a two-layer protocol:[22]

    A low-level layer or wire protocol that handles the inter-process communication between the two involved processes‍—‌client and compositor‍—‌and the marshalling of the data that they interchange. This layer is message-based and usually implemented using the kernel IPC services, specifically Unix domain sockets in the case of Linux and Unix-like operating systems.[23]: 9 
    A high-level layer built upon it, that handles the information that client and compositor need to exchange to implement the basic features of a window system. This layer is implemented as "an asynchronous object-oriented protocol".[23]: 9 

While the low-level layer was written manually in C, the high-level layer is automatically generated from a description of the elements of the protocol stored in XML format.[24] Every time the protocol description of this XML file changes, the C source code that implements such protocol can be regenerated to include the new changes, allowing a very flexible, extensible and error-proof protocol.

The reference implementation of Wayland protocol is split in two libraries: a library to be used by Wayland clients called libwayland-client and a library to be used by Wayland compositors called libwayland-server.



## X Clients under Wayland (XWayland)

XWayland is an X Server running as a Wayland client, and thus is capable of displaying native X11 client applications in a Wayland compositor environment.

With xwayland, Xorg server can use wayland input devices for input and forward either the root window or individual top-level windows as wayland surfaces.

The server still runs the same 2D driver with the same acceleration code as it does when it runs natively. The main difference is that wayland handles presentation of the windows instead of KMS.


```
aaron 1151  0.0  0.0 156708  5580 tty2     Ssl+ 19:34   0:00 /usr/libexec/gdm-wayland-session /usr/bin/gnome-session --session=gnome
aaron 1503  0.0  0.4 126620 33992 ?        Sl   19:34   0:06 /usr/bin/Xwayland :0 -rootless -noreset -accessx -core -auth /run/user/1000/.mutter-Xwaylandauth.I2Q7B1 -listen 4 -listen 5 -displayfd 6 -initfd 7
```

```toml
XDG_SEAT=seat0
XDG_SESSION_TYPE=wayland
XDG_SESSION_CLASS=user
XDG_VTNR=2
XDG_SESSION_ID=11
XDG_RUNTIME_DIR=/run/user/1000
XDG_DATA_DIRS=/aaron/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share/:/usr/share/
I3SOCK=/run/user/1000/sway-ipc.1000.6788.sock
XDG_SESSION_TYPE=wayland
SWAYSOCK=/run/user/1000/sway-ipc.1000.6788.sock
WAYLAND_DISPLAY=wayland-1
```

```
aaron       6788  1.7  0.5 1560856 91348 tty2    Ssl+ 21:23   0:18  \_ sway
aaron      15488  0.1  0.0 715464  5736 pts/2    Sl+  21:39   0:00  |           \_ fzf --preview echo {} | grep -q '^list' && echo 'etc/ etc/sway/ etc/sway/config etc/sway/config.d/ etc/sway/config.d/50-systemd-user.conf usr/ usr/bin/ usr/bin/sway usr/bin/swaybar usr/bin/swaymsg usr/bin/swaynag usr/share/ usr/share/backgrounds/ usr/share/backgrounds/sway/ usr/share/backgrounds/sway/Sway_Wallpaper_Blue_1136x640.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_1136x640_Portrait.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_1366x768.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_1920x1080.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_2048x1536.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_2048x1536_Portrait.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_768x1024.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_768x1024_Portrait.png usr/share/bash-completion/ usr/share/bash-completion/completions/ usr/share/bash-completion/completions/sway usr/share/bash-completion/completions/swaybar usr/share/bash-completion/completions/swaymsg usr/share/fish/ usr/share/fish/vendor_completions.d/ usr/share/fish/vendor_completions.d/sway.fish usr/share/fish/vendor_completions.d/swaymsg.fish usr/share/fish/vendor_completions.d/swaynag.fish usr/share/licenses/ usr/share/licenses/sway/ usr/share/licenses/sway/LICENSE usr/share/man/ usr/share/man/man1/ usr/share/man/man1/sway.1.gz usr/share/man/man1/swaymsg.1.gz usr/share/man/man1/swaynag.1.gz usr/share/man/man5/ usr/share/man/man5/sway-bar.5.gz usr/share/man/man5/sway-input.5.gz usr/share/man/man5/sway-output.5.gz usr/share/man/man5/sway.5.gz usr/share/man/man5/swaynag.5.gz usr/share/man/man7/ usr/share/man/man7/sway-ipc.7.gz usr/share/man/man7/swaybar-protocol.7.gz usr/share/sway/ usr/share/sway/scripts/ usr/share/sway/scripts/autoname-workspaces.py usr/share/sway/scripts/grimshot usr/share/sway/scripts/inactive-windows-transparency.py usr/share/wayland-sessions/ usr/share/wayland-sessions/sway.desktop usr/share/zsh/ usr/share/zsh/site-functions/ usr/share/zsh/site-functions/_sway usr/share/zsh/site-functions/_swaymsg'                                     || echo 'Repository      : community Name            : sway Version         : 1:1.7-10 Description     : Tiling Wayland compositor and replacement for the i3 window manager Architecture    : x86_64 URL             : https://swaywm.org/ Licenses        : MIT Groups          : None Provides        : None Depends On      : cairo  gdk-pixbuf2  libevdev.so=2-64  libinput  libjson-c.so=5-64  libudev.so=1-64  libwayland-server.so=0-64  libwlroots.so=10-64  libxcb  libxkbcommon.so=0-64  pango  pcre  ttf-font Optional Deps   : bemenu: Wayland-native alternative to dmenu                   dmenu: Application launcher used in default config                   foot: Terminal emulator used in the default configuration                   i3status: Status line generation                   mako: Lightweight notification daemon                   polkit: System privilege control. Required if not using seatd service                   swaybg: Wallpaper tool for sway                   swayidle: Idle management daemon                   swaylock: Screen locker                   waybar: Highly customizable bar                   xorg-xwayland: X11 support Conflicts With  : None Replaces        : None Download Size   : 5.05 MiB Installed Size  : 5.59 MiB Packager        : Brett Cornwall <brett@i--b.com> Build Date      : Mon 31 Oct 2022 08:35:40 AM CST Validated By    : MD5 Sum  SHA-256 Sum  Signature' --prompt Action ("esc" to abort): --header "sway" may be found in package "community/sway" Shift up or down to scroll the preview
aaron      16369  0.0  0.0   9668  2520 pts/5    S+   21:40   0:00      \_ grep -E --color=auto --exclude-dir=_site --exclude-dir=.git -s -I sway
gdm         5777  0.0  0.0 155196  7368 tty1     Ssl+ 21:23   0:00      \_ /usr/lib/gdm-wayland-session dbus-run-session -- gnome-session --autostart /usr/share/gdm/greeter/autostart
gdm         6239  0.0  0.4 863852 72776 tty1     Sl+  21:23   0:00                  |   \_ /usr/bin/Xwayland :1024 -rootless -noreset -accessx -core -auth /run/user/120/.mutter-Xwaylandauth.EY8WV1 -listenfd 4 -listenfd 5 -displayfd 6 -initfd 7
aaron       7194  0.9  0.5 877676 83616 tty2     Sl+  21:23   0:10 Xwayland :0 -rootless -terminate -core -listenfd 29 -listenfd 30 -wm 66
aaron      15488  0.1  0.0 715464  5736 pts/2    Sl+  21:39   0:00  |           \_ fzf --preview echo {} | grep -q '^list' && echo 'etc/ etc/sway/ etc/sway/config etc/sway/config.d/ etc/sway/config.d/50-systemd-user.conf usr/ usr/bin/ usr/bin/sway usr/bin/swaybar usr/bin/swaymsg usr/bin/swaynag usr/share/ usr/share/backgrounds/ usr/share/backgrounds/sway/ usr/share/backgrounds/sway/Sway_Wallpaper_Blue_1136x640.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_1136x640_Portrait.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_1366x768.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_1920x1080.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_2048x1536.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_2048x1536_Portrait.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_768x1024.png usr/share/backgrounds/sway/Sway_Wallpaper_Blue_768x1024_Portrait.png usr/share/bash-completion/ usr/share/bash-completion/completions/ usr/share/bash-completion/completions/sway usr/share/bash-completion/completions/swaybar usr/share/bash-completion/completions/swaymsg usr/share/fish/ usr/share/fish/vendor_completions.d/ usr/share/fish/vendor_completions.d/sway.fish usr/share/fish/vendor_completions.d/swaymsg.fish usr/share/fish/vendor_completions.d/swaynag.fish usr/share/licenses/ usr/share/licenses/sway/ usr/share/licenses/sway/LICENSE usr/share/man/ usr/share/man/man1/ usr/share/man/man1/sway.1.gz usr/share/man/man1/swaymsg.1.gz usr/share/man/man1/swaynag.1.gz usr/share/man/man5/ usr/share/man/man5/sway-bar.5.gz usr/share/man/man5/sway-input.5.gz usr/share/man/man5/sway-output.5.gz usr/share/man/man5/sway.5.gz usr/share/man/man5/swaynag.5.gz usr/share/man/man7/ usr/share/man/man7/sway-ipc.7.gz usr/share/man/man7/swaybar-protocol.7.gz usr/share/sway/ usr/share/sway/scripts/ usr/share/sway/scripts/autoname-workspaces.py usr/share/sway/scripts/grimshot usr/share/sway/scripts/inactive-windows-transparency.py usr/share/wayland-sessions/ usr/share/wayland-sessions/sway.desktop usr/share/zsh/ usr/share/zsh/site-functions/ usr/share/zsh/site-functions/_sway usr/share/zsh/site-functions/_swaymsg'                                     || echo 'Repository      : community Name            : sway Version         : 1:1.7-10 Description     : Tiling Wayland compositor and replacement for the i3 window manager Architecture    : x86_64 URL             : https://swaywm.org/ Licenses        : MIT Groups          : None Provides        : None Depends On      : cairo  gdk-pixbuf2  libevdev.so=2-64  libinput  libjson-c.so=5-64  libudev.so=1-64  libwayland-server.so=0-64  libwlroots.so=10-64  libxcb  libxkbcommon.so=0-64  pango  pcre  ttf-font Optional Deps   : bemenu: Wayland-native alternative to dmenu                   dmenu: Application launcher used in default config                   foot: Terminal emulator used in the default configuration                   i3status: Status line generation                   mako: Lightweight notification daemon                   polkit: System privilege control. Required if not using seatd service                   swaybg: Wallpaper tool for sway                   swayidle: Idle management daemon                   swaylock: Screen locker                   waybar: Highly customizable bar                   xorg-xwayland: X11 support Conflicts With  : None Replaces        : None Download Size   : 5.05 MiB Installed Size  : 5.59 MiB Packager        : Brett Cornwall <brett@i--b.com> Build Date      : Mon 31 Oct 2022 08:35:40 AM CST Validated By    : MD5 Sum  SHA-256 Sum  Signature' --prompt Action ("esc" to abort): --header "sway" may be found in package "community/sway" Shift up or down to scroll the preview
aaron      16624  0.0  0.0   9668  2540 pts/5    S+   21:41   0:00      \_ grep -E --color=auto --exclude-dir=_site --exclude-dir=.git -s -I wayl
```

```c
info: main.c:421: version: 1.13.1 +pgo +ime +graphemes -assertions
info: main.c:428: arch: Linux x86_64/64-bit
info: main.c:440: locale: C
warn: main.c:458: 'C' is not a UTF-8 locale, using 'C.UTF-8' instead
info: config.c:3003: loading configuration from /aaron/.config/foot/foot.ini
info: fcft.c:338: fcft: 3.1.5 +graphemes +runs +svg(nanosvg) -assertions
info: fcft.c:377: fontconfig: 2.14.1, freetype: 2.12.1, harfbuzz: 5.3.1, utf8proc: 2.8.0 (Unicode 15.0.0)
info: fcft.c:838: /usr/share/fonts/WOFF2/CascadiaCode.woff2: size=8.00pt/8px, dpi=75.00
 err: wayland.c:1281: failed to connect to wayland; no compositor running?
info: main.c:680: goodbye
```

This is a good one.

```toml
XDG_MENU_PREFIX=gnome-
XDG_SESSION_DESKTOP=sway
XDG_SESSION_TYPE=wayland
XDG_CURRENT_DESKTOP=sway
XDG_SESSION_CLASS=user
XDG_RUNTIME_DIR=/run/user/1000
XDG_DATA_DIRS=/aaron/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share/:/usr/share/
```
[325 21:48:28.194565] [glfw error 65544]: Wayland: Failed to connect to display
GLFW initialization failed

Failed to create wl_display (No such file or directory)
qt.qpa.plugin: Could not load the Qt platform plugin "wayland" in "" even though it was found.
This application failed to start because no Qt platform plugin could be initialized. Reinstalling the application may fix this problem.

Available platform plugins are: eglfs, linuxfb, minimal, minimalegl, offscreen, vnc, wayland-egl, wayland, wayland-xcomposite-egl, wayland-xcomposite-glx, xcb.

```sh
info: main.c:421: version: 1.13.1 +pgo +ime +graphemes -assertions
info: main.c:428: arch: Linux x86_64/64-bit
info: main.c:440: locale: C.UTF-8
info: config.c:3003: loading configuration from /aaron/.config/foot/foot.ini
info: fcft.c:338: fcft: 3.1.5 +graphemes +runs +svg(nanosvg) -assertions
info: fcft.c:377: fontconfig: 2.14.1, freetype: 2.12.1, harfbuzz: 5.3.1, utf8proc: 2.8.0 (Unicode 15.0.0)
info: fcft.c:838: /usr/share/fonts/WOFF2/FiraCode-Regular.woff2: size=8.00pt/8px, dpi=75.00
info: wayland.c:1353: X11-1: 1920x1000+0x0@0Hz 11.0 0.00" scale=1 PPI=0x0 (physical) PPI=0x0 (logical), DPI=0.00
info: wayland.c:1509: requesting SSD decorations
info: fcft.c:838: /usr/share/fonts/liberation/LiberationMono-BoldItalic.ttf: size=12.00pt/16px, dpi=96.00
info: fcft.c:838: /usr/share/fonts/WOFF2/FiraCode-Regular.woff2: size=12.00pt/16px, dpi=96.00
info: fcft.c:838: /usr/share/fonts/liberation/LiberationMono-Italic.ttf: size=12.00pt/16px, dpi=96.00
info: fcft.c:838: /usr/share/fonts/WOFF2/FiraCode-Bold.woff2: size=12.00pt/16px, dpi=96.00
info: terminal.c:700: cell width=10, height=20
info: terminal.c:588: using 8 rendering threads
info: wayland.c:859: using SSD decorations
info: main.c:680: goodbye
```

## X architecture diagram

    The kernel gets an event from an input device and sends it to X through the evdev input driver. The kernel does all the hard work here by driving the device and translating the different device specific event protocols to the linux evdev input event standard.
    The X server determines which window the event affects and sends it to the clients that have selected for the event in question on that window. The X server doesn't actually know how to do this right, since the window location on screen is controlled by the compositor and may be transformed in a number of ways that the X server doesn't understand (scaled down, rotated, wobbling, etc).
    The client looks at the event and decides what to do. Often the UI will have to change in response to the event - perhaps a check box was clicked or the pointer entered a button that must be highlighted. Thus the client sends a rendering request back to the X server.
    When the X server receives the rendering request, it sends it to the driver to let it program the hardware to do the rendering. The X server also calculates the bounding region of the rendering, and sends that to the compositor as a damage event.
    The damage event tells the compositor that something changed in the window and that it has to recomposite the part of the screen where that window is visible. The compositor is responsible for rendering the entire screen contents based on its scenegraph and the contents of the X windows. Yet, it has to go through the X server to render this.
    The X server receives the rendering requests from the compositor and either copies the compositor back buffer to the front buffer or does a pageflip. In the general case, the X server has to do this step so it can account for overlapping windows, which may require clipping and determine whether or not it can page flip. However, for a compositor, which is always fullscreen, this is another unnecessary context switch.

As suggested above, there are a few problems with this approach. The X server doesn't have the information to decide which window should receive the event, nor can it transform the screen coordinates to window-local coordinates. And even though X has handed responsibility for the final painting of the screen to the compositing manager, X still controls the front buffer and modesetting. Most of the complexity that the X server used to handle is now available in the kernel or self contained libraries (KMS, evdev, mesa, fontconfig, freetype, cairo, Qt, etc). In general, the X server is now just a middle man that introduces an extra step between applications and the compositor and an extra step between the compositor and the hardware.
X中：

    内核捕获鼠标点击事件并发送给X server。
    X server会计算该把这一事件发送给哪个窗口（事实上，窗口位置是由Compositor控制的，X server并不能够正确的计算Compositor做过特效变化之后的按钮的正确位置）。
    应用程序对此事件进行处理（将引发按钮更新动作）。但是，在此之前它得向X server发送绘制请求。
    X server接收到这条绘制请求，然后把它发给视频驱动来渲染。X还计算了更新区域，并且这条「垃圾信息」发送给了Compositor。
    这时，Compositor知道它必须要重新合成屏幕上的一块区域。当然，这还是要向X server发送绘制请求的。
    开始绘制。但是X server还会去做一些不必要的本职工作（窗口重叠计算、窗口剪裁计算等）。

Wayland架构

在Wayland中：

    内核捕获鼠标点击事件并发送给Wayland Compositor。
    由于是直接发给Wayland Compositor的，所以Wayland Compositor会正确地计算出按钮的位置。同时它会把这一事件发送给按钮所在的应用程序来处理。
    应用程序直接渲染，无需向Wayland Compositor请求。只需在绘制完成之后向Wayland Compositor发送一条信息表明这块区域被更新了。
    Wayland Compositor收到这条信息后，立即重新合成整个桌面

In wayland the compositor is the display server. We transfer the control of KMS and evdev to the compositor. The wayland protocol lets the compositor send the input events directly to the clients and lets the client send the damage event directly to the compositor:

Wayland architecture diagram

    The kernel gets an event and sends it to the compositor. This is similar to the X case, which is great, since we get to reuse all the input drivers in the kernel.
    The compositor looks through its scenegraph to determine which window should receive the event. The scenegraph corresponds to what's on screen and the compositor understands the transformations that it may have applied to the elements in the scenegraph. Thus, the compositor can pick the right window and transform the screen coordinates to window-local coordinates, by applying the inverse transformations. The types of transformation that can be applied to a window is only restricted to what the compositor can do, as long as it can compute the inverse transformation for the input events.
    As in the X case, when the client receives the event, it updates the UI in response. But in the wayland case, the rendering happens in the client, and the client just sends a request to the compositor to indicate the region that was updated.
    The compositor collects damage requests from its clients and then recomposites the screen. The compositor can then directly issue an ioctl to schedule a pageflip with KMS.





Most Wayland compositors only work on systems using Kernel mode setting. Wayland by itself does not provide a graphical environment.

