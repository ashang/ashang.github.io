#!/usr/bin/env bash


echo "sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-awesomewm.desktop /usr/share/xsessions/gnome-flashback-awesomewm.desktop"
sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-awesomewm.desktop /usr/share/xsessions/gnome-flashback-awesomewm.desktop

echo "sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-awesomewm /usr/libexec/gnome-flashback-awesomewm"
sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-awesomewm /usr/libexec/gnome-flashback-awesomewm

echo "sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-awesomewm.session /usr/share/gnome-session/sessions/gnome-flashback-awesomewm.session"
sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-awesomewm.session /usr/share/gnome-session/sessions/gnome-flashback-awesomewm.session

echo "sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-awesomewm-session.desktop /usr/share/applications/gnome-flashback-awesomewm-session.desktop"
sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-awesomewm-session.desktop /usr/share/applications/gnome-flashback-awesomewm-session.desktop

echo "sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-awesomewm-session /usr/bin/gnome-flashback-awesomewm-session"
sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-awesomewm-session /usr/bin/gnome-flashback-awesomewm-session
