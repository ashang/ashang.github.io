
```sh
$ setxkbmap -query
WARNING: Running setxkbmap against an XWayland server
rules:      evdev
model:      pc105
layout:     cn

$ setxkbmap -print -verbose
WARNING: Running setxkbmap against an XWayland server
Trying to build keymap using the following components:
keycodes:   evdev+aliases(qwerty)
types:      complete
compat:     complete
symbols:    pc+cn+inet(evdev)
geometry:   pc(pc105)
xkb_keymap {
        xkb_keycodes  { include "evdev+aliases(qwerty)" };
        xkb_types     { include "complete"      };
        xkb_compat    { include "complete"      };
        xkb_symbols   { include "pc+cn+inet(evdev)"     };
        xkb_geometry  { include "pc(pc105)"     };
};
```
