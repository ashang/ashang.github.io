
$ \curl -fsSL https://download.docker.com/linux/debian/gpg | gpg --dearmor | sudo dd of=/usr/share/keyrings/docker-archive-keyring.gpg
5+1 records in
5+1 records out
2760 bytes (2.8 kB, 2.7 KiB) copied, 0.512704 s, 5.4 kB/s

$ echo 'deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/debian bullseye stable' | sudo tee /etc/apt/sources.list.d/docker.list

