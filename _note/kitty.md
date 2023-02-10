---
title: "Hello kitty the terminal"
date: 2018-08-11
---


```shell
$ kitty --debug-config
kitty 0.19.3 created by Kovid Goyal
Linux o302 5.13.0-19-generic #19-Ubuntu SMP Thu Oct 7 21:58:00 UTC 2021 x86_64
Ubuntu 21.10 \n \l
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=21.10
DISTRIB_CODENAME=impish
DISTRIB_DESCRIPTION="Ubuntu 21.10"
Loaded config files: /etc/xdg/kitty/kitty.conf, /aaron/.config/kitty/kitty.conf
Your Wayland compositor does not support server side window decorations, disabling Wayland. You can force Wayland support using the linux_display_server option in kitty.conf See https://drewdevault.com/2018/01/27/Sway-and-client-side-decorations.html for more information.
Running under: X11

Config options different from defaults:
font_family           Liberation Mono
font_size             12.0
update_check_interval 0.0
```


    sudo update-alternatives --config x-terminal-emulator

Or

    sudo update-alternatives --set x-terminal-emulator /usr/bin/kitty

---
date: 2016-11-07
---

```log
$ kitty
[347 15:45:09.843591] Failed to set locale with LANG: en_GB.UTF-8
[347 15:45:09.843620] Failed to set locale with no LANG
[347 15:45:09.845381] Ignoring unknown config key: open_url_modifiers
[347 15:45:09.845437] Ignoring unknown config key: rectangle_select_modifiers
[347 15:45:09.845448] Ignoring unknown config key: terminal_select_modifiers
xkbcommon: ERROR: Couldn't read Compose file /usr/share/X11/locale/: No such device
[347 15:45:12.386352] [glfw error 65544]: Failed to create XKB compose table for locale
xkbcommon: ERROR: Couldn't read Compose file /usr/share/X11/locale/: No such device
[347 15:45:13.488681] [glfw error 65544]: Failed to create XKB compose table for locale
[347 15:45:22.257959] [PARSE ERROR] Unrecognized DCS code: 0x7a
[347 15:45:22.257982] [PARSE ERROR] Unknown CSI code: 'm' with start_modifier: '' and end_modifier: '%' and parameters: '0'
```

```sh
$ kitty --debug-font-fallback
[084 18:44:40.192114] Preloaded font faces:
[084 18:44:40.192159] normal face: /usr/share/fonts/truetype/firacode/FiraCode-Regular.ttf:0
[084 18:44:40.192185] bold face: /usr/share/fonts/truetype/firacode/FiraCode-Bold.ttf:0
[084 18:44:40.192209] italic face: /usr/share/fonts/truetype/firacode/FiraCode-Regular.ttf:0
[084 18:44:40.192221] bi face: /usr/share/fonts/truetype/firacode/FiraCode-Bold.ttf:0
```



```
$ kitty
[004 21:46:56.451850] Failed to set locale with LANG: en_US.utf8
[004 21:46:56.451896] Failed to set locale with no LANG
[004 21:46:56.453014] [glfw error 65544]: Wayland: Failed to connect to display
GLFW initialization failed

$ locale
locale: Cannot set LC_MESSAGES to default locale: No such file or directory
locale: Cannot set LC_ALL to default locale: No such file or directory
LANG=en_US.utf8
```

$ kitty --debug-font-fallback
[084 18:44:40.192114] Preloaded font faces:
[084 18:44:40.192159] normal face: /usr/share/fonts/truetype/firacode/FiraCode-Regular.ttf:0
[084 18:44:40.192185] bold face: /usr/share/fonts/truetype/firacode/FiraCode-Bold.ttf:0
[084 18:44:40.192209] italic face: /usr/share/fonts/truetype/firacode/FiraCode-Regular.ttf:0
[084 18:44:40.192221] bi face: /usr/share/fonts/truetype/firacode/FiraCode-Bold.ttf:0

