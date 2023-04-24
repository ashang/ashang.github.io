#!/usr/bin/env bash


echo "sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-xfwm4.desktop /usr/share/xsessions/gnome-flashback-xfwm4.desktop"
sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-xfwm4.desktop /usr/share/xsessions/gnome-flashback-xfwm4.desktop

echo "sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-xfwm4 /usr/libexec/gnome-flashback-xfwm4"
sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-xfwm4 /usr/libexec/gnome-flashback-xfwm4

echo "sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-xfwm4.session /usr/share/gnome-session/sessions/gnome-flashback-xfwm4.session"
sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-xfwm4.session /usr/share/gnome-session/sessions/gnome-flashback-xfwm4.session

echo "sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-xfwm4-session.desktop /usr/share/applications/gnome-flashback-xfwm4-session.desktop"
sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-xfwm4-session.desktop /usr/share/applications/gnome-flashback-xfwm4-session.desktop

echo "sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-xfwm4-session /usr/bin/gnome-flashback-xfwm4-session"
sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-xfwm4-session /usr/bin/gnome-flashback-xfwm4-session
