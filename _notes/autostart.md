

$ cat ~/.config/autostart/no-lock-screen.desktop
[Desktop Entry]
Name=Deactive lock screen
Comment=Deactive the gnome lock screen in the live session
Type=Application
Icon=nautilus
Exec=sh -c "gsettings set org.gnome.desktop.screensaver lock-enabled false"


$ grep ^Exec= ~/.config/autostart/*.desktop
/home/aaron/.config/autostart/blueman.desktop:Exec=blueman-applet
/home/aaron/.config/autostart/fcitx.desktop:Exec=fcitx5 -d
/home/aaron/.config/autostart/guake.desktop:Exec=guake
/home/aaron/.config/autostart/kerneloops-applet.desktop:Exec=kerneloops-applet
/home/aaron/.config/autostart/pam_kwallet_init.desktop:Exec=/usr/share/libpam-kwallet-common/pam_kwallet_init

