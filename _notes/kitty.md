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

