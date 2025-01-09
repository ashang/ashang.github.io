---
title: X11 forwarding request failed
---


```

ssh -Y 

$ ssh code
X11 forwarding request failed
Last login: Thu Aug 31 14:52:32 2023 from 10.10.50.14
```


wget -O- https://www.virtualbox.org/download/oracle_vbox_2016.asc | sudo gpg --dearmor --yes --output /usr/share/keyrings/oracle-virtualbox-2016.gpg

echo "deb [arch=amd64 signed-by=/usr/share/keyrings/oracle-virtualbox-2016.gpg] http://download.virtualbox.org/virtualbox/debian $(lsb_release -cs) contrib" | sudo tee /etc/apt/sources.list.d/virtualbox.list


W: https://mirrors.ustc.edu.cn/docker-ce/linux/debian/dists/bullseye/InRelease: Key is stored in legacy trusted.gpg keyring (/etc/apt/trusted.gpg), see the DEPRECATION section in apt-key(8) for details.






[2023-08-30 11:15:12] DEBUG close: 10.10.50.14:33202
[2023-08-30 11:15:24] DEBUG close: 10.10.50.14:50482
[2023-08-30 17:59:23] DEBUG accept: 10.10.50.14:48456
[2023-08-30 17:59:23] DEBUG Jekyll::Commands::Serve::Servlet is invoked.
[2023-08-30 17:59:54] DEBUG close: 10.10.50.14:48456
^C[2023-08-31 15:11:19] DEBUG close TCPSocket(10.10.50.50, 1124)
[2023-08-31 15:11:19] INFO  going to shutdown ...
[2023-08-31 15:11:19] INFO  WEBrick::HTTPServer#start done.





$ vboxmanage -v | cut -dr -f1
7.0.10
# aaron@code:~/4t/4t




wget https://download.virtualbox.org/virtualbox/7.0.2/Oracle_VM_VirtualBox_Extension_Pack-7.0.2.vbox-extpack


sudo vboxmanage extpack install Oracle_VM_VirtualBox_Extension_Pack-7.0.2.vbox-extpack




swap 0 0

VBoxManage startvm "VM name" --type headless


127.0.0.2:3391


127.0.0.2:3391





aaron    tty2     -                28:36m Xwayland :1 -rootless -terminate -core -listenfd 29 -listenfd 30 -wm 70
aaron    tty3     -                28:36m /usr/libexec/gnome-session-binary --session=gnome
aaron    pts/13   tmux(10892).%21  10:09  lvim -u /home/aaron/.local/share/lunarvim/lvim/init.lua -p x-forwarding.md






