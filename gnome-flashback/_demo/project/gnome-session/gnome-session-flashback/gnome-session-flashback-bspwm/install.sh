#!/usr/bin/env bash


echo "sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-bspwm.desktop /usr/share/xsessions/gnome-flashback-bspwm.desktop"
sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-bspwm.desktop /usr/share/xsessions/gnome-flashback-bspwm.desktop

echo "sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-bspwm /usr/libexec/gnome-flashback-bspwm"
sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-bspwm /usr/libexec/gnome-flashback-bspwm

echo "sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-bspwm.session /usr/share/gnome-session/sessions/gnome-flashback-bspwm.session"
sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-bspwm.session /usr/share/gnome-session/sessions/gnome-flashback-bspwm.session

echo "sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-bspwm-session.desktop /usr/share/applications/gnome-flashback-bspwm-session.desktop"
sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-bspwm-session.desktop /usr/share/applications/gnome-flashback-bspwm-session.desktop

echo "sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-bspwm-session /usr/bin/gnome-flashback-bspwm-session"
sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-bspwm-session /usr/bin/gnome-flashback-bspwm-session
