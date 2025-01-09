# System Info:
1.  `uname -a`:

        Linux i54 5.10.86-1-MANJARO #1 SMP PREEMPT Thu Dec 16 20:59:51 UTC 2021 x86_64 GNU/Linux

2.  `lsb_release`:

    `lsb_release` not found.

3.  `/etc/lsb-release`:

    `/etc/lsb-release` not found.

4.  `/etc/os-release`:

        NAME="Manjaro Linux"
        ID=manjaro
        ID_LIKE=arch
        BUILD_ID=rolling
        PRETTY_NAME="Manjaro Linux"
        ANSI_COLOR="32;1;24;144;200"
        HOME_URL="https://manjaro.org/"
        DOCUMENTATION_URL="https://wiki.manjaro.org/"
        SUPPORT_URL="https://manjaro.org/"
        BUG_REPORT_URL="https://bugs.manjaro.org/"
        LOGO=manjarolinux

5.  Desktop Environment:

    Desktop environment is `gnome3`.

6.  Bash Version:

        BASH_VERSION='5.1.12(1)-release'

# Environment:
1.  DISPLAY:

        DISPLAY=':0'


        WAYLAND_DISPLAY=''

2.  Keyboard Layout:

    1.  `setxkbmap`:

            xkb_keymap {
            	xkb_keycodes  { include "evdev+aliases(qwerty)"	};
            	xkb_types     { include "complete"	};
            	xkb_compat    { include "complete"	};
            	xkb_symbols   { include "pc+us+us:2+inet(evdev)+compose(caps)"	};
            	xkb_geometry  { include "pc(pc105)"	};
            };

    2.  `xprop`:

            _XKB_RULES_NAMES(STRING) = "evdev", "pc105", "us,us", ",", "compose:caps"

3.  Locale:

    1.  All locale:

            C
            en_HK.utf8
            POSIX
            zh_CN.utf8

    2.  Current locale:

            LANG=en_HK.UTF-8
            LC_CTYPE="en_HK.UTF-8"
            LC_NUMERIC="en_HK.UTF-8"
            LC_TIME="en_HK.UTF-8"
            LC_COLLATE="en_HK.UTF-8"
            LC_MONETARY="en_HK.UTF-8"
            LC_MESSAGES="en_HK.UTF-8"
            LC_PAPER="en_HK.UTF-8"
            LC_NAME="en_HK.UTF-8"
            LC_ADDRESS="en_HK.UTF-8"
            LC_TELEPHONE="en_HK.UTF-8"
            LC_MEASUREMENT="en_HK.UTF-8"
            LC_IDENTIFICATION="en_HK.UTF-8"
            LC_ALL=en_HK.UTF-8

4.  Directories:

    1.  Home:

            /home/aaron

    2.  `${XDG_CONFIG_HOME}`:

        Environment variable `XDG_CONFIG_HOME` is not set.

        Current value of `XDG_CONFIG_HOME` is `~/.config` (`/home/aaron/.config`).

    3.  Fcitx5 Settings Directory:

        Current fcitx5 settings directory is `~/.config/fcitx5` (`/home/aaron/.config/fcitx5`).

5.  Current user:

    The script is run as aaron (1000).

# Fcitx State:
1.  executable:

    Found fcitx5 at `/usr/bin/fcitx5`.

2.  version:

    Fcitx version: `5.0.11`

3.  process:

    Found 1 fcitx5 process:

           2376 fcitx5

4.  `fcitx5-remote`:

    `fcitx5-remote` works properly.

5.  DBus interface:

    Using `dbus-send` to check dbus.

    Owner of DBus name `org.fcitx.Fcitx5` is `:1.51`.

    PID of DBus name `org.fcitx.Fcitx5` owner is `2376`.

    Debug information from dbus:

           Group [x11::0] has 3 InputContext(s)
          IC [e8c0681ce7e54c87867b5ffb74347d1e] program:lxterminal frontend:dbus cap:6000000012 focus:0
          IC [5555afbb8caa4260a5fbb7e90964cc11] program:qterminal frontend:dbus cap:6000800072 focus:1
          IC [6a34aa8906d346a692dba93077c79fc5] program: frontend:ibus cap:52 focus:0
        Input Context without group

# Fcitx Configure UI:
1.  Config Tool Wrapper:

    Found fcitx5-configtool at `/usr/bin/fcitx5-configtool`.

2.  Config GUI for qt:

    Found `fcitx5-config-qt` at `/usr/bin/fcitx5-config-qt`.

3.  Config GUI for kde:

    Found fcitx5 kcm module.

        kcm_fcitx5               - Configure Input Method

# Frontends setup:
## Xim:
1.  `${XMODIFIERS}`:

    Environment variable XMODIFIERS is set to "@im=fcitx" correctly.
    Xim Server Name from Environment variable is fcitx.

2.  XIM_SERVERS on root window:

    Xim server name is the same with that set in the environment variable.

## Qt:
1.  qt4 - `${QT4_IM_MODULE}`:

    Environment variable QT_IM_MODULE is set to "fcitx" correctly.

2.  qt5 - `${QT_IM_MODULE}`:

    Environment variable QT_IM_MODULE is set to "fcitx" correctly.

3.  Qt IM module files:

    Found fcitx5 im module for qt6: `/usr/lib/qt6/plugins/platforminputcontexts/libfcitx5platforminputcontextplugin.so`.
    Found unknown fcitx qt module: `/usr/lib/qt/plugins/kcms/kcm_fcitx5.so`.
    Found fcitx5 im module for qt: `/usr/lib/qt/plugins/platforminputcontexts/libfcitx5platforminputcontextplugin.so`.
    Found fcitx5 qt5 module: `/usr/lib/fcitx5/qt5/libfcitx-quickphrase-editor5.so`.
    **Cannot find fcitx5 input method module for Qt4.**

## Gtk:
1.  gtk - `${GTK_IM_MODULE}`:

    Environment variable GTK_IM_MODULE is set to "fcitx" correctly.

2.  `gtk-query-immodules`:

    1.  gtk 2:

        Found `gtk-query-immodules` for gtk `2.24.33` at `/usr/bin/gtk-query-immodules-2.0`.
        Version Line:

            # Created by /usr/bin/gtk-query-immodules-2.0 from gtk+-2.24.33

        Found fcitx5 im modules for gtk `2.24.33`.

            "/usr/lib/gtk-2.0/2.10.0/immodules/im-fcitx5.so" 
            "fcitx" "Fcitx5 (Flexible Input Method Framework5)" "fcitx5" "/usr/locale" "ja:ko:zh:*" 
            "fcitx5" "Fcitx5 (Flexible Input Method Framework5)" "fcitx5" "/usr/locale" "ja:ko:zh:*" 

    2.  gtk 3:

        Found `gtk-query-immodules` for gtk `3.24.30` at `/usr/bin/gtk-query-immodules-3.0`.
        Version Line:

            # Created by /usr/bin/gtk-query-immodules-3.0 from gtk+-3.24.30

        Found fcitx5 im modules for gtk `3.24.30`.

            "/usr/lib/gtk-3.0/3.0.0/immodules/im-fcitx5.so" 
            "fcitx" "Fcitx5 (Flexible Input Method Framework5)" "fcitx5" "/usr/locale" "ja:ko:zh:*" 
            "fcitx5" "Fcitx5 (Flexible Input Method Framework5)" "fcitx5" "/usr/locale" "ja:ko:zh:*" 

3.  Gtk IM module cache:

    1.  gtk 2:

        Found immodules cache for gtk `2.24.33` at `/usr/lib/gtk-2.0/2.10.0/immodules.cache`.
        Version Line:

            # Created by /usr/bin/gtk-query-immodules-2.0 from gtk+-2.24.33

        Found fcitx5 im modules for gtk `2.24.33`.

            "/usr/lib/gtk-2.0/2.10.0/immodules/im-fcitx5.so" 
            "fcitx" "Fcitx5 (Flexible Input Method Framework5)" "fcitx5" "/usr/locale" "ja:ko:zh:*" 
            "fcitx5" "Fcitx5 (Flexible Input Method Framework5)" "fcitx5" "/usr/locale" "ja:ko:zh:*" 

    2.  gtk 3:

        Found immodules cache for gtk `3.24.30` at `/usr/lib/gtk-3.0/3.0.0/immodules.cache`.
        Version Line:

            # Created by /usr/bin/gtk-query-immodules-3.0 from gtk+-3.24.30

        Found fcitx5 im modules for gtk `3.24.30`.

            "/usr/lib/gtk-3.0/3.0.0/immodules/im-fcitx5.so" 
            "fcitx" "Fcitx5 (Flexible Input Method Framework5)" "fcitx5" "/usr/locale" "ja:ko:zh:*" 
            "fcitx5" "Fcitx5 (Flexible Input Method Framework5)" "fcitx5" "/usr/locale" "ja:ko:zh:*" 

    3.  gtk 4:

        Found immodules cache for gtk `4` at `/usr/lib/gtk-4.0/4.0.0/immodules/giomodule.cache`.
        Found fcitx5 im modules for gtk `4`.

            libim-fcitx5.so: gtk-im-module

4.  Gtk IM module files:

    1.  gtk 2:

        All found Gtk 2 immodule files exist.

    2.  gtk 3:

        All found Gtk 3 immodule files exist.

    3.  gtk 4:

        All found Gtk 4 immodule files exist.

# Configuration:
## Fcitx Addons:
1.  Addon Config Dir:

    Found fcitx5 addon config directory: `/usr/share/fcitx5/addon`.

2.  Addon List:

    1.  Found 27 enabled addons:

            Simplified and Traditional Chinese Translation 5.0.9
            Classic User Inteface 5.0.11
            Clipboard 5.0.11
            Cloud Pinyin 5.0.9
            DBus 5.0.11
            DBus Frontend 5.0.11
            Emoji 5.0.11
            Fcitx4 Frontend 5.0.11
            Full width character 5.0.9
            IBus Frontend 5.0.11
            Input method selector 5.0.11
            Keyboard 5.0.11
            KDE Input Method Panel 5.0.11
            Status Notifier 5.0.11
            Notification 5.0.11
            Pinyin 5.0.9
            Extra Pinyin functionality 5.0.9
            Punctuation 5.0.9
            Quick Phrase 5.0.11
            Rime 5.0.9
            Spell 5.0.11
            Table 5.0.9
            Unicode 5.0.11
            Wayland 5.0.11
            Wayland Input method frontend 5.0.11
            XCB 5.0.11
            X Input Method Frontend 5.0.11

    2.  Found 0 disabled addons:

3.  Addon Libraries:

    All libraries for all addons are found.

4.  User Interface:

    Found 2 enabled user interface addons:

        Classic User Inteface
        KDE Input Method Panel

## Input Methods:
1.  `/home/aaron/.config/fcitx5/profile`:

        [Groups/0]
        # Group Name
        Name=Default
        # Layout
        Default Layout=cn-altgr-pinyin
        # Default Input Method
        DefaultIM=rime

        [Groups/0/Items/0]
        # Name
        Name=keyboard-cn-altgr-pinyin
        # Layout
        Layout=

        [Groups/0/Items/1]
        # Name
        Name=rime
        # Layout
        Layout=

        [GroupOrder]
        0=Default

# Log:
1.  `date`:

        Monday, December 20, 2021 PM04:00:56 HKT

2.  `/home/aaron/.config/fcitx5/crash.log`:

    `/crash.log` not found.

**Warning: the output of fcitx5-diagnose contains sensitive information, including the distribution name, kernel version, name of currently running programs, etc.**

**Though such information can be helpful to developers for diagnostic purpose, please double check and remove as necessary before posting it online publicly.**
