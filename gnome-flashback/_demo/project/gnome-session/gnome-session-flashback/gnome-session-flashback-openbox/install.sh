#!/usr/bin/env bash


echo "sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-openbox.desktop /usr/share/xsessions/gnome-flashback-openbox.desktop"
sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-openbox.desktop /usr/share/xsessions/gnome-flashback-openbox.desktop

echo "sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-openbox /usr/libexec/gnome-flashback-openbox"
sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-openbox /usr/libexec/gnome-flashback-openbox

echo "sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-openbox.session /usr/share/gnome-session/sessions/gnome-flashback-openbox.session"
sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-openbox.session /usr/share/gnome-session/sessions/gnome-flashback-openbox.session

echo "sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-openbox-session.desktop /usr/share/applications/gnome-flashback-openbox-session.desktop"
sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-openbox-session.desktop /usr/share/applications/gnome-flashback-openbox-session.desktop

echo "sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-openbox-session /usr/bin/gnome-flashback-openbox-session"
sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-openbox-session /usr/bin/gnome-flashback-openbox-session
