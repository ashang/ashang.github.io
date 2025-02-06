


service

If you want to sync your files automatically, enable and start the systemd service:

systemctl --user enable onedrive
systemctl --user start onedrive

To see the logs run:

journalctl --user-unit onedrive -f


