## Restart X

```shell
startx -- -keeptty -nolisten tcp > $HOME/.xorg.log 2>&1
```

## Use [Xephyr](https://wikipedia.org/wiki/Xephyr):

```shell
# set screen size as you like
Xephyr :1 -screen 1280x800 2> stdout.txt & DISPLAY=:1 awesome
```
