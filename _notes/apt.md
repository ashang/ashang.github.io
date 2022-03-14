

```shell
$ \curl -fsSL https://download.docker.com/linux/debian/gpg | gpg --dearmor | sudo dd of=/usr/share/keyrings/docker-archive-keyring.gpg
5+1 records in
5+1 records out
2760 bytes (2.8 kB, 2.7 KiB) copied, 0.512704 s, 5.4 kB/s

$ echo 'deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/debian bullseye stable' | sudo tee /etc/apt/sources.list.d/docker.list
```

```shell
$ apt-cache policy linux-image-amd64
linux-image-amd64:
  Installed: 5.10.70-1
  Candidate: 5.10.70-1
  Version table:
 *** 5.10.70-1 500
        500 https://mirrors.ustc.edu.cn/debian bullseye/main amd64 Packages
        100 /var/lib/dpkg/status
```

```shell
# wget URL –quiet -O - | sudo apt-key add -

# gpg –keyserver <a href="http://subkeys.pgp.net">subkeys.pgp.net</a> –recv KEY

# gpg –export –armor KEY | sudo apt-key add -

```
