


If the bug is a crash or a hang and is repeatable, please follow the following steps to generate a backtrace.

1. Install debug symbols if possible.

Flatpak

    Run: flatpak install flathub org.gnome.Geary.Debug org.gnome.Sdk.Debug

Fedora

    Run: sudo dnf debuginfo-install geary glib2 gtk3

Ubuntu

    Follow the Ubuntu wiki instructions for installing dbgsym packages, then run: sudo apt install geary-dbgsym libglib2.0-0-dbgsym libgtk-3-0-dbgsym

2. Run Geary under GDB.

If you have installed Geary using Flatpak, run the following command first before proceeding:

flatpak run --devel --command=sh org.gnome.Geary

Launch GDB:

G_DEBUG=fatal-criticals gdb --args geary --debug

At the (gdb) prompt, enter the following two commands:

handle SIGUSR1 noprint
run


3. Make the crash happen or in the case of a hang, press Ctrl-C to return to the GDB console.

In GDB, generate a backtrace by entering the following command:

backtrace full

This will print out a stack trace

