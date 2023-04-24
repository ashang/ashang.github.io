#!/usr/bin/env bash


echo "sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-berrywm.desktop /usr/share/xsessions/gnome-flashback-berrywm.desktop"
sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-berrywm.desktop /usr/share/xsessions/gnome-flashback-berrywm.desktop

echo "sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-berrywm /usr/libexec/gnome-flashback-berrywm"
sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-berrywm /usr/libexec/gnome-flashback-berrywm

echo "sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-berrywm.session /usr/share/gnome-session/sessions/gnome-flashback-berrywm.session"
sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-berrywm.session /usr/share/gnome-session/sessions/gnome-flashback-berrywm.session

echo "sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-berrywm-session.desktop /usr/share/applications/gnome-flashback-berrywm-session.desktop"
sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-berrywm-session.desktop /usr/share/applications/gnome-flashback-berrywm-session.desktop

echo "sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-berrywm-session /usr/bin/gnome-flashback-berrywm-session"
sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-berrywm-session /usr/bin/gnome-flashback-berrywm-session
