#!/usr/bin/env bash


echo "sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-compiz.desktop /usr/share/xsessions/gnome-flashback-compiz.desktop"
sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-compiz.desktop /usr/share/xsessions/gnome-flashback-compiz.desktop

echo "sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-compiz /usr/libexec/gnome-flashback-compiz"
sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-compiz /usr/libexec/gnome-flashback-compiz

echo "sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-compiz.session /usr/share/gnome-session/sessions/gnome-flashback-compiz.session"
sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-compiz.session /usr/share/gnome-session/sessions/gnome-flashback-compiz.session

echo "sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-compiz-session.desktop /usr/share/applications/gnome-flashback-compiz-session.desktop"
sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-compiz-session.desktop /usr/share/applications/gnome-flashback-compiz-session.desktop

echo "sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-compiz-session /usr/bin/gnome-flashback-compiz-session"
sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-compiz-session /usr/bin/gnome-flashback-compiz-session
