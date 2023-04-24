#!/usr/bin/env bash


echo "sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-herbstluftwm.desktop /usr/share/xsessions/gnome-flashback-herbstluftwm.desktop"
sudo install -Dm644 pkg-root/usr/share/xsessions/gnome-flashback-herbstluftwm.desktop /usr/share/xsessions/gnome-flashback-herbstluftwm.desktop

echo "sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-herbstluftwm /usr/libexec/gnome-flashback-herbstluftwm"
sudo install -Dm755 pkg-root/usr/libexec/gnome-flashback-herbstluftwm /usr/libexec/gnome-flashback-herbstluftwm

echo "sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-herbstluftwm.session /usr/share/gnome-session/sessions/gnome-flashback-herbstluftwm.session"
sudo install -Dm644 pkg-root/usr/share/gnome-session/sessions/gnome-flashback-herbstluftwm.session /usr/share/gnome-session/sessions/gnome-flashback-herbstluftwm.session

echo "sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-herbstluftwm-session.desktop /usr/share/applications/gnome-flashback-herbstluftwm-session.desktop"
sudo install -Dm644 pkg-root/usr/share/applications/gnome-flashback-herbstluftwm-session.desktop /usr/share/applications/gnome-flashback-herbstluftwm-session.desktop

echo "sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-herbstluftwm-session /usr/bin/gnome-flashback-herbstluftwm-session"
sudo install -Dm755 pkg-root/usr/bin/gnome-flashback-herbstluftwm-session /usr/bin/gnome-flashback-herbstluftwm-session
