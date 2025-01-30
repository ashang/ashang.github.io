---
title: Hello, Asahi
description: Experience in Building Modern Static Websites.
duration: "5min"
#layout: ../../layouts/notes.astro
tags: ["astro", "learning in public"]
author: Him
date: 2022-03-02
---

https://asahilinux.org/

```sh
$ curl https://alx.sh | sh
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  1808  100  1808    0     0   4002      0 --:--:-- --:--:-- --:--:--  4008

Bootstrapping installer:
  Checking version...
  Version: v0.7.6
  Downloading...
  Extracting...
  Initializing...

The installer needs to run as root.
Please enter your sudo password if prompted.
Password:

Welcome to the Asahi Linux installer!

This installer will guide you through the process of setting up
Asahi Linux on your Mac.

Please make sure you are familiar with our documentation at:
  https://alx.sh/w

Press enter to continue.


Collecting system information...
  Product name: MacBook Pro (16-inch, Nov 2023)
  SoC: Apple M3 Pro
  Device class: j516sap
  Product type: Mac15,7
  Board ID: 0x6
  Chip ID: 0x6030
  System firmware: iBoot-10151.121.1
  Boot UUID: 5B80D8A5-1AA2-4B53-BFF4-3029B857E024
  Boot VGID: 5B80D8A5-1AA2-4B53-BFF4-3029B857E024
  Default boot VGID: 5B80D8A5-1AA2-4B53-BFF4-3029B857E024
  Boot mode: macOS
  OS version: 14.5 (23F79)
  OS restore version: 23.6.79.0.0,0
  Main firmware version: 14.5 (23F79)
  No Fallback System Firmware / rOS
  SFR version: 23.6.79.0.0,0
  SystemRecovery version: 23.4.56.0.0,0 (14.3 23D56)
  Login user: aaron

This device is not supported yet!
Please check out the Asahi Linux Blog for updates on device support:

   https://asahilinux.org/blog/
```



## alx @1737449377

```sh
#!/bin/sh
# SPDX-License-Identifier: MIT

# Truncation guard
if true; then
    set -e

    if [ ! -e /System ]; then
        echo "You appear to be running this script from Linux or another non-macOS system."
        echo "Asahi Linux can only be installed from macOS (or recoveryOS)."
        exit 1
    fi

    export LC_ALL=en_US.UTF-8
    export LANG=en_US.UTF-8
    export PATH="/usr/bin:/bin:/usr/sbin:/sbin:$PATH"

    if ! curl --no-progress-meter file:/// &>/dev/null; then
        echo "Your version of cURL is too old. This usually means your macOS is very out"
        echo "of date. Installing Asahi Linux requires at least macOS version 13.5."
        exit 1
    fi

    export VERSION_FLAG=https://cdn.asahilinux.org/installer/latest
    export INSTALLER_BASE=https://cdn.asahilinux.org/installer
    export INSTALLER_DATA=https://github.com/AsahiLinux/asahi-installer/raw/prod/data/installer_data.json
    export INSTALLER_DATA_ALT=https://alx.sh/installer_data.json
    export REPO_BASE=https://cdn.asahilinux.org
    export REPORT=https://stats.asahilinux.org/report
    export REPORT_TAG=alx-prod

    #TMP="$(mktemp -d)"
    TMP=/tmp/asahi-install

    echo
    echo "Bootstrapping installer:"

    if [ -e "$TMP" ]; then
        mv "$TMP" "$TMP-$(date +%Y%m%d-%H%M%S)"
    fi

    mkdir -p "$TMP"
    cd "$TMP"

    echo "  Checking version..."

    PKG_VER="$(curl --no-progress-meter -L "$VERSION_FLAG")"
    echo "  Version: $PKG_VER"

    PKG="installer-$PKG_VER.tar.gz"

    echo "  Downloading..."

    curl --no-progress-meter -L -o "$PKG" "$INSTALLER_BASE/$PKG"
    if ! curl --no-progress-meter -L -O "$INSTALLER_DATA"; then
        echo "    Error downloading installer_data.json. GitHub might be blocked in your network."
        echo "    Please consider using a VPN if you experience issues."
        echo "    Trying workaround..."
        curl --no-progress-meter -L -O "$INSTALLER_DATA_ALT"
    fi

    echo "  Extracting..."

    tar xf "$PKG"

    echo "  Initializing..."
    echo

    if [ "$USER" != "root" ]; then
        echo "The installer needs to run as root."
        echo "Please enter your sudo password if prompted."
        exec caffeinate -dis sudo -E ./install.sh "$@"
    else
        exec caffeinate -dis ./install.sh "$@"
    fi
fi
```

```sh
$ bash alx.*

Bootstrapping installer:
  Checking version...
  Version: v0.7.7
  Downloading...
  Extracting...
  Initializing...


Welcome to the Asahi Linux installer!

This installer will guide you through the process of setting up
Asahi Linux on your Mac.

Please make sure you are familiar with our documentation at:
  https://alx.sh/w

Press enter to continue.


Collecting system information...
  Product name: MacBook Pro (16-inch, Nov 2023)
  SoC: Apple M3 Pro
  Device class: j516sap
  Product type: Mac15,7
  Board ID: 0x6
  Chip ID: 0x6030
  System firmware: iBoot-11881.61.3
  Boot UUID: 5B80D8A5-1AA2-4B53-BFF4-3029B857E024
  Boot VGID: 5B80D8A5-1AA2-4B53-BFF4-3029B857E024
  Default boot VGID: 5B80D8A5-1AA2-4B53-BFF4-3029B857E024
  Boot mode: macOS
  OS version: 15.2 (24C101)
  OS restore version: 24.3.101.0.0,0
  Main firmware version: 15.2 (24C101)
  No Fallback System Firmware / rOS
  SFR version: 24.3.101.0.0,0
  SystemRecovery version: 23.7.93.0.0,0 (14.6.1 23G93)
  Login user: aaron

This device is not supported yet!
Please check out the Asahi Linux Blog for updates on device support:

   https://asahilinux.org/blog/
```
