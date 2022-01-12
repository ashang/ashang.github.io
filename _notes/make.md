
```
make VERBOSE=1 xconfig
...
  CHECK   qt
*
* Could not find Qt via pkg-config.
* Please install either Qt 4.8 or 5.x. and make sure it's in PKG_CONFIG_PATH
*
make[1]: *** No rule to make target 'scripts/kconfig/.tmp_qtcheck', needed by 'scripts/kconfig/qconf.o'.  Stop.
make: *** [Makefile:531: xconfig] Error 2
...
```

```
$ sudo apt-get install qttools5-dev
```



install -Dm6755 target/release/subsystemctl "${pkgdir}/usr/bin/subsystemctl"
~
~

