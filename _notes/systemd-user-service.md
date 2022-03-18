---
title: systemd user unit files
date: 2015-05-25
updated: 2018-08-08
---

## Systemd units

These unit files are meant to be used in the user session. You may drop them
into `/etc/systemd/user` or `${XDG_DATA_HOME}/systemd/user` followed by
`systemctl --user daemon-reload` to have systemd aware of the unit files.

These files are meant to be triggered either manually using `systemctl --user
start offlineimap.service` or by enabling the timer unit using `systemctl --user
enable offlineimap-oneshot.timer`. Additionally, specific accounts may be
triggered by using `offlineimap@myaccount.timer` or
`offlineimap-oneshot@myaccount.service`.

If the defaults provided by these units doesn't suit your setup, any of the
values may be overridden by using `systemctl --user edit offlineimap.service`.
This'll prevent having to copy-and-edit the original file.



## mbsync



service

If you want to sync your files automatically, enable and start the systemd service:

systemctl --user enable onedrive
systemctl --user start onedrive

To see the logs run:

journalctl --user-unit onedrive -f


