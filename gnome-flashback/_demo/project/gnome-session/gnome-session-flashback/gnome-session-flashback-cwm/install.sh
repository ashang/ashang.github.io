#!/usr/bin/env bash


echo "sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-cwm.desktop /usr/share/xsessions/gnome-flashback-cwm.desktop"
sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-cwm.desktop /usr/share/xsessions/gnome-flashback-cwm.desktop

echo "sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-cwm /usr/libexec/gnome-flashback-cwm"
sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-cwm /usr/libexec/gnome-flashback-cwm

echo "sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-cwm.session /usr/share/gnome-session/sessions/gnome-flashback-cwm.session"
sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-cwm.session /usr/share/gnome-session/sessions/gnome-flashback-cwm.session

echo "sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-cwm-session.desktop /usr/share/applications/gnome-flashback-cwm-session.desktop"
sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-cwm-session.desktop /usr/share/applications/gnome-flashback-cwm-session.desktop

echo "sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-cwm-session /usr/bin/gnome-flashback-cwm-session"
sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-cwm-session /usr/bin/gnome-flashback-cwm-session
