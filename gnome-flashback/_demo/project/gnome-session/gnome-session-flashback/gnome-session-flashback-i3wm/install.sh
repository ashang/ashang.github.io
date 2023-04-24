#!/usr/bin/env bash


echo "sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-i3.desktop /usr/share/xsessions/gnome-flashback-i3.desktop"
sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-i3.desktop /usr/share/xsessions/gnome-flashback-i3.desktop

echo "sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-i3 /usr/libexec/gnome-flashback-i3"
sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-i3 /usr/libexec/gnome-flashback-i3

echo "sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-i3.session /usr/share/gnome-session/sessions/gnome-flashback-i3.session"
sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-i3.session /usr/share/gnome-session/sessions/gnome-flashback-i3.session

echo "sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-i3-session.desktop /usr/share/applications/gnome-flashback-i3-session.desktop"
sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-i3-session.desktop /usr/share/applications/gnome-flashback-i3-session.desktop

echo "sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-i3-session /usr/bin/gnome-flashback-i3-session"
sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-i3-session /usr/bin/gnome-flashback-i3-session
