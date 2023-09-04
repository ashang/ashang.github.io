---
title: "Fix Arch Linux Network after Rebooting LiveCD"
layout: post
---

So...I was following the steps on the [Arch Linux Installation Guide][1]...

[1]: https://wiki.archlinux.org/index.php/installation_guide

Things seemed to be going along well.  In fact, very early on after you've
started up the LiveCD it has a section for "Configure your network connection".  There it says:

> DHCP - dynamic IP address and DNS server assignment (provided by
> systemd-networkd and systemd-resolved) should work out of the box for
> wired and wireless network interfaces.

*"Should work out of the box"*--that inspires confidence!  Especially when it
suggests testing with `ping archlinux.org`, which went just fine.

Following the  steps I managed to get a filesystem on my `/dev/sda1` partition
and a bootloader onto `/dev/sda` (notice which goes where!).  The base packages
from the internet were installed, and I'd reached the moment of truth where I
could reboot!

But when I logged in, the installed system had no network connectivity:

    [root@nemesis ~]# ping archlinux.org
    ping: archlinux.org: Temporary failure in name resolution

The first advice I found for fixing the problem was someone suggesting to
use the **dhcpcd** package.  *(That stands for DHCP "Client Daemon", fyi.)*
But this wasn't installed:

    [root@nemesis ~]# dhcpcd
    -bash: dhcpcd: command not found

Furthermore, *I could no longer use pacman without a network connection*, so
I couldn't try that fix.  There were a lot of other suggestions I could not
run either, due to missing diagnostic tools.

Many other people seemed to be in the same boat, but why?


## Read The Fine (?) Print

Once the base install finishes (`pacstrap /mnt base linux linux-firmware`)
the instructions actually say something *rather important*:

> The base package does not include all tools from the live installation,
> so installing other packages may be necessary for a fully functional
> base system.

They then mention you might need "software necessary for networking".  But
these give hyperlinks to some rather oblique pages that are not written in
a "step-by-step" style.  It's easy to think you've already seen the network
configuration step--and it worked out of the box, so all that must be
[Somebody Else's Problem][2].

[2]: https://en.wikipedia.org/wiki/Somebody_else%27s_problem

This points out something about the Arch Linux documentation: *it does not
account for psychology*.  They show you working networking and give you the
seeming comfort of "should work out of the box".  Then later, in a very
subtle way, it says "...NOT!"


## Generalized Solution: Do the LiveCD Shuffle!

In any case, now you're dead-end booted into a system with no network.  How do
you go back in time and install what you need?

You don't have to start the install guide from the beginning.  You just need
to boot back into the LiveCD, and re-run these two steps:

    mount /dev/sda1 /mnt  # Substitute /dev/sda1 with your target disk
    arch-chroot /mnt

Just remember...

* **Before this step**, your `pacman` installs will be forgotten on the reboot.
You're putting the files onto the very limited space of the RAMdisk the LiveCD
booted on.

* **After this step**, you will be installing to your target drive.  You'll
notice that some things (like vim and nano) don't come with the base system
and go missing when you do the change.  So you have to install them
(e.g. `pacman -S vim`).

Assuming you have done the switcheroo, you could get something like dhcpcd with:

    pacman -S dhcpcd

But to test it on your system, you'll have to reboot again.

**You still need to tell the system to start dhcpcd when you boot, and what
network adapter to use.**

Network adapters have names like `eth0` or `enp0s3`.  To get the list of
devices you have, use `ip link`.  Once you find the device name, enable the
service:

    systemctl enable --now dhcpcd@enp0s3  # or whatever your device was called


## Specialized Solution: Use Already Installed Systemd.Networkd

Knowing how to go back and forth with the LiveCD is important for anyone who
is going to tinker with Arch setup.  *But you might not need to.*

I assumed that dhcpcd must have been what the LiveCD did, since you can find it
in the [list of packages it ships with][3].

[3]: https://gitlab.archlinux.org/archlinux/archiso/-/blob/master/configs/releng/packages.x86_64

But going back to retrace the steps, *I found this isn't what the LiveCD uses*.
It has the dhcpcd executable, but you won't find it running in the active
services.  (Use `systemctl list-units --full` to see this list.)

Watching the systemd debug output during LiveCD boot, you should see these
lines shuffled around somewhere in startup process:

             Starting Network Service...
    [  OK  ] Started Network Service.
             Starting Wait for Network to be Configured...
             Starting Network Name Resolution...
    [  OK  ] Finished Wait for Network to be Configured.
    [  OK  ] Started Network Name Resolution.
    [  OK  ] Reached Target Host and Network Name Lookups.
             Starting Wireless Service...
    [  OK  ] Started Wireless Service.
    [  OK  ] Reached Target Network.
    [  OK  ] Reached Target Network is Online.

You'll only see this in the LiveCD--not when your base Arch boots.  But turning
it on is good: edit `/etc/default/grub` to remove the `quiet` option, then
`grub-mkconfig -o /boot/grub/grub.cfg`.  (For more instructions, including
how to not clear the terminal when the login prompt comes up, see the
[Arch systemd FAQ][4]).

[4]: https://wiki.archlinux.org/index.php/Systemd/FAQ#How_do_I_get_more_verbose_output_during_boot?

The "Network Service" mentioned is **systemd-networkd**, and the "Network Name
Resolution" comes from **systemd-resolved** ("D" at the end is for "Daemon").
You can set those services to be run at boot with `systemctl enable`, and
also get the effect of `systemctl start` with the --now option:

    systemctl enable --now systemd-networkd
    systemctl enable --now systemd-resolved

It may look like these services start up properly, but you'll likely see a
new error message from a failing ping:

    [root@nemesis ~]# ping archlinux.org
    ping: archlinux.org: Name or service not known

The LiveCD still has something you don't: files in `/etc/systemd/network`.
One is `20-ethernet.network`:

    # /etc/systemd/network/20-ethernet.network

    [Match]
    Name=en*
    Name=eth*

    [Network]
    DHCP=yes
    IPv6PrivacyExtensions=yes

    [DHCP]
    RouteMetric=512

For me, making this file was enough to get the network running on reboot.
(There's also a file called `20-wireless-network`, but getting Wi-Fi to work
involves packages additional to systemd...like `wpa_supplicant`.  I didn't need
it, but there are other guides that cover that.)


## Could This Be Clearer?

I mention that I'm not the only one who hit this problem on the Internet.  Is
there a way the Install Guide could have been clearer?

I'd argue probably remove the language "work out of the box" under what seems
like a "Step" that says "Configure your network connection."  Like I said,
that makes you feel like you've taken care of it.  Wording that was more
circumspect and warned you about what to come would be good.

It might even be better if the LiveCD did not do anything automatic that the
base system did not do.  What if instead of making things run "automagically"
from hidden startup settings, they happened due to scripts that were in the
LiveCD that you could easily apply on your system?

For instance, the install steps could have you run something like:

    # start-network.sh
    #
    copy /arch-premade-files/etc/systemd/network/* /etc/systemd/network
    systemctl enable --now systemd-networkd
    systemctl enable --now systemd-resolved

Anyway, I hope some of this is useful.
