---
date: 2016-11-18
---

```
#$ cat /etc/apt/sources.list

# sudo apt-key add key.gpg

# wget URL –quiet -O - | sudo apt-key add -



# gpg –keyserver <a href="http://subkeys.pgp.net">subkeys.pgp.net</a> –recv KEY

# gpg –export –armor KEY | sudo apt-key add -



# Canonical's 'partner' repository

deb <a href="http://archive.canonical.com/">http://archive.canonical.com/</a> jaunty partner



deb <a href="http://ftp.sjtu.edu.cn/ubuntu">http://ftp.sjtu.edu.cn/ubuntu</a> jaunty main universe multiverse restricted

 deb <a href="http://ftp.sjtu.edu.cn/ubuntu/">http://ftp.sjtu.edu.cn/ubuntu/</a> jaunty-proposed main multiverse restricted universe

deb <a href="http://ftp.sjtu.edu.cn/ubuntu/">http://ftp.sjtu.edu.cn/ubuntu/</a> jaunty-security main multiverse restricted universe

 deb <a href="http://ftp.sjtu.edu.cn/ubuntu/">http://ftp.sjtu.edu.cn/ubuntu/</a> jaunty-updates main multiverse restricted universe



deb-src <a href="http://ftp.sjtu.edu.cn/ubuntu/">http://ftp.sjtu.edu.cn/ubuntu/</a> jaunty main multiverse restricted universe

 deb-src <a href="http://ftp.sjtu.edu.cn/ubuntu/">http://ftp.sjtu.edu.cn/ubuntu/</a> jaunty-proposed main multiverse restricted universe

deb-src <a href="http://ftp.sjtu.edu.cn/ubuntu/">http://ftp.sjtu.edu.cn/ubuntu/</a> jaunty-security main multiverse restricted universe

 deb-src <a href="http://ftp.sjtu.edu.cn/ubuntu/">http://ftp.sjtu.edu.cn/ubuntu/</a> jaunty-updates main multiverse restricted universe



deb <a href="http://mirror.lupaworld.com/ubuntu/">http://mirror.lupaworld.com/ubuntu/</a> jaunty main multiverse restricted universe

 deb <a href="http://mirror.lupaworld.com/ubuntu/">http://mirror.lupaworld.com/ubuntu/</a> jaunty-proposed main multiverse restricted universe

deb <a href="http://mirror.lupaworld.com/ubuntu/">http://mirror.lupaworld.com/ubuntu/</a> jaunty-security main multiverse restricted universe

 deb <a href="http://mirror.lupaworld.com/ubuntu/">http://mirror.lupaworld.com/ubuntu/</a> jaunty-updates main multiverse restricted universe



# deb <a href="http://mirror.lupaworld.com/ubuntu/ubuntu-cn/">http://mirror.lupaworld.com/ubuntu/ubuntu-cn/</a> jaunty main multiverse restricted universe

 # deb <a href="http://mirror.lupaworld.com/ubuntu/ubuntu-cn/">http://mirror.lupaworld.com/ubuntu/ubuntu-cn/</a> jaunty-proposed main multiverse restricted universe

# deb <a href="http://mirror.lupaworld.com/ubuntu/ubuntu-cn/">http://mirror.lupaworld.com/ubuntu/ubuntu-cn/</a> jaunty-security main multiverse restricted universe

 # deb <a href="http://mirror.lupaworld.com/ubuntu/ubuntu-cn/">http://mirror.lupaworld.com/ubuntu/ubuntu-cn/</a> jaunty-updates main multiverse restricted universe



# deb <a href="http://archive.ubuntu.org.cn/ubuntu-cn/">http://archive.ubuntu.org.cn/ubuntu-cn/</a> jaunty main multiverse restricted universe

 # deb <a href="http://archive.ubuntu.org.cn/ubuntu-cn/">http://archive.ubuntu.org.cn/ubuntu-cn/</a> jaunty-proposed main multiverse restricted universe

# deb <a href="http://archive.ubuntu.org.cn/ubuntu-cn/">http://archive.ubuntu.org.cn/ubuntu-cn/</a> jaunty-security main multiverse restricted universe

 # deb <a href="http://archive.ubuntu.org.cn/ubuntu-cn/">http://archive.ubuntu.org.cn/ubuntu-cn/</a> jaunty-updates main multiverse restricted universe



deb <a href="http://archive.ubuntu.com/ubuntu/">http://archive.ubuntu.com/ubuntu/</a> jaunty main multiverse restricted universe

 deb <a href="http://archive.ubuntu.com/ubuntu/">http://archive.ubuntu.com/ubuntu/</a> jaunty-proposed main multiverse restricted universe

deb <a href="http://archive.ubuntu.com/ubuntu/">http://archive.ubuntu.com/ubuntu/</a> jaunty-security main multiverse restricted universe

 deb <a href="http://archive.ubuntu.com/ubuntu/">http://archive.ubuntu.com/ubuntu/</a> jaunty-updates main multiverse restricted universe



#deb <a href="http://mirror.rootguide.org/ubuntu/">http://mirror.rootguide.org/ubuntu/</a> jaunty main restricted multiverse

 #deb <a href="http://mirror.rootguide.org/ubuntu/">http://mirror.rootguide.org/ubuntu/</a> jaunty-updates main restricted universe multiverse

#deb <a href="http://mirror.rootguide.org/ubuntu/">http://mirror.rootguide.org/ubuntu/</a> jaunty-security main restricted universe multiverse

 #deb <a href="http://mirror.rootguide.org/ubuntu/">http://mirror.rootguide.org/ubuntu/</a> jaunty-proposed main multiverse restricted universe



#deb <a href="http://mirrors.163.com/ubuntu/">http://mirrors.163.com/ubuntu/</a> jaunty main restricted universe multiverse

 #deb <a href="http://mirrors.163.com/ubuntu/">http://mirrors.163.com/ubuntu/</a> jaunty-updates main restricted universe multiverse

#deb <a href="http://mirrors.163.com/ubuntu/">http://mirrors.163.com/ubuntu/</a> jaunty-proposed main restricted universe multiverse

 #deb <a href="http://mirrors.163.com/ubuntu/">http://mirrors.163.com/ubuntu/</a> jaunty-security main restricted universe multiverse

#deb-src <a href="http://mirrors.163.com/ubuntu/">http://mirrors.163.com/ubuntu/</a> jaunty main restricted universe multiverse

 #deb-src <a href="http://mirrors.163.com/ubuntu/">http://mirrors.163.com/ubuntu/</a> jaunty-updates main restricted universe multiverse

#deb-src <a href="http://mirrors.163.com/ubuntu/">http://mirrors.163.com/ubuntu/</a> jaunty-proposed main restricted universe multiverse

 #deb-src <a href="http://mirrors.163.com/ubuntu/">http://mirrors.163.com/ubuntu/</a> jaunty-security main restricted universe multiverse



deb <a href="http://mirrors.shlug.org/ubuntu/">http://mirrors.shlug.org/ubuntu/</a>  jaunty main restricted universe multiverse

 deb <a href="http://mirrors.shlug.org/ubuntu/">http://mirrors.shlug.org/ubuntu/</a>  jaunty-security main restricted universe multiverse

deb <a href="http://mirrors.shlug.org/ubuntu/">http://mirrors.shlug.org/ubuntu/</a>  jaunty-updates main restricted universe multiverse

 deb <a href="http://mirrors.shlug.org/ubuntu/">http://mirrors.shlug.org/ubuntu/</a>  jaunty-proposed main restricted universe multiverse

#deb-src <a href="http://mirrors.shlug.org/ubuntu/">http://mirrors.shlug.org/ubuntu/</a>  jaunty main restricted universe multiverse

 #deb-src <a href="http://mirrors.shlug.org/ubuntu/">http://mirrors.shlug.org/ubuntu/</a>  jaunty-security main restricted universe multiverse

#deb-src <a href="http://mirrors.shlug.org/ubuntu/">http://mirrors.shlug.org/ubuntu/</a>  jaunty-updates main restricted universe multiverse

 #deb-src <a href="http://mirrors.shlug.org/ubuntu/">http://mirrors.shlug.org/ubuntu/</a>  jaunty-proposed main restricted universe multiverse



# deb <a href="http://ubuntu.cn99.com/ubuntu/">http://ubuntu.cn99.com/ubuntu/</a> jaunty main restricted universe multiverse

 # deb <a href="http://ubuntu.cn99.com/ubuntu/">http://ubuntu.cn99.com/ubuntu/</a> jaunty-security main restricted universe multiverse

# deb <a href="http://ubuntu.cn99.com/ubuntu/">http://ubuntu.cn99.com/ubuntu/</a> jaunty-updates main restricted universe multiverse

 # deb <a href="http://ubuntu.cn99.com/ubuntu/">http://ubuntu.cn99.com/ubuntu/</a> jaunty-proposed main restricted universe multiverse



#deb <a href="http://ubuntu.dormforce.net/ubuntu/">http://ubuntu.dormforce.net/ubuntu/</a> jaunty main multiverse restricted universe

 #deb <a href="http://ubuntu.dormforce.net/ubuntu/">http://ubuntu.dormforce.net/ubuntu/</a> jaunty-proposed main multiverse restricted universe

#deb <a href="http://ubuntu.dormforce.net/ubuntu/">http://ubuntu.dormforce.net/ubuntu/</a> jaunty-security main multiverse restricted universe

 #deb <a href="http://ubuntu.dormforce.net/ubuntu/">http://ubuntu.dormforce.net/ubuntu/</a> jaunty-updates main multiverse restricted universe



deb <a href="http://debian.ustc.edu.cn/ubuntu/">http://debian.ustc.edu.cn/ubuntu/</a> jaunty main restricted universe multiverse

 deb <a href="http://debian.ustc.edu.cn/ubuntu/">http://debian.ustc.edu.cn/ubuntu/</a> jaunty-updates main restricted universe multiverse

deb <a href="http://debian.ustc.edu.cn/ubuntu/">http://debian.ustc.edu.cn/ubuntu/</a> jaunty-security main restricted universe multiverse

 deb <a href="http://debian.ustc.edu.cn/ubuntu/">http://debian.ustc.edu.cn/ubuntu/</a> jaunty-proposed main multiverse restricted universe

#deb-src <a href="http://debian.ustc.edu.cn/ubuntu/">http://debian.ustc.edu.cn/ubuntu/</a> jaunty main multiverse restricted universe

 #deb-src <a href="http://debian.ustc.edu.cn/ubuntu/">http://debian.ustc.edu.cn/ubuntu/</a> jaunty-proposed main multiverse restricted universe

#deb-src <a href="http://debian.ustc.edu.cn/ubuntu/">http://debian.ustc.edu.cn/ubuntu/</a> jaunty-security main multiverse restricted universe

 #deb-src <a href="http://debian.ustc.edu.cn/ubuntu/">http://debian.ustc.edu.cn/ubuntu/</a> jaunty-updates main multiverse restricted universe



#deb <a href="http://mirror.rootguide.org/ubuntu/">http://mirror.rootguide.org/ubuntu/</a> jaunty main restricted universe multiverse

 #deb <a href="http://mirror.rootguide.org/ubuntu/">http://mirror.rootguide.org/ubuntu/</a> jaunty-updates main restricted universe multiverse

#deb <a href="http://mirror.rootguide.org/ubuntu/">http://mirror.rootguide.org/ubuntu/</a> jaunty-security main restricted universe multiverse

 #deb <a href="http://mirror.rootguide.org/ubuntu/">http://mirror.rootguide.org/ubuntu/</a> jaunty-proposed main multiverse restricted universe



# Medibuntu

# Please report any bug on <a href="https://bugs.launchpad.net/medibuntu/">https://bugs.launchpad.net/medibuntu/</a>

 # wget <a href="http://packages.medibuntu.org/medibuntu-key.gpg">http://packages.medibuntu.org/medibuntu-key.gpg</a> -O- | sudo apt-key add -

deb <a href="http://packages.medibuntu.org/">http://packages.medibuntu.org/</a> jaunty non-free free

 deb <a href="http://packages.medibuntu.org/">http://packages.medibuntu.org/</a> jaunty-staging non-free free



#deb <a href="http://repository.debuntu.org/">http://repository.debuntu.org/</a> jaunty multiverse

# wget <a href="http://repository.debuntu.org/GPG-Key-chantra.txt">http://repository.debuntu.org/GPG-Key-chantra.txt</a> -O- | sudo apt-key add -



#deb <a href="http://ftp.sjtu.edu.cn/debian">http://ftp.sjtu.edu.cn/debian</a> sid main contrib non-free

#deb <a href="http://ftp.sjtu.edu.cn/debian">http://ftp.sjtu.edu.cn/debian</a> proposed-updates main contrib non-free

 #

#deb <a href="http://anheng.com.cn/debian">http://anheng.com.cn/debian</a> sid main contrib non-free

#deb <a href="http://anheng.com.cn/debian">http://anheng.com.cn/debian</a> proposed-updates main contrib non-free

 #deb-src <a href="http://anheng.com.cn/debian">http://anheng.com.cn/debian</a> sid main contrib non-free

#

#deb <a href="http://ftp.debian.org/debian">http://ftp.debian.org/debian</a> sid main contrib non-free

#deb <a href="http://ftp.debian.org/debian">http://ftp.debian.org/debian</a> proposed-updates main contrib non-free

 #deb <a href="http://security.debian.org/">http://security.debian.org/</a> sid/updates main contrib non-free

#

#deb <a href="http://http.us.debian.org/debian">http://http.us.debian.org/debian</a> sid main contrib non-free

 #deb <a href="http://http.us.debian.org/debian">http://http.us.debian.org/debian</a> proposed-updates main contrib non-free

#

#deb <a href="http://debian.ustc.edu.cn/debian">http://debian.ustc.edu.cn/debian</a> sid main contrib non-free

 #deb <a href="http://debian.ustc.edu.cn/debian-security">http://debian.ustc.edu.cn/debian-security</a> sid/updates main contrib non-free

#deb <a href="http://debian.ustc.edu.cn/debian">http://debian.ustc.edu.cn/debian</a> proposed-updates main contrib non-free



#deb <a href="ftp://debian.ustc.edu.cn/debian-uo">ftp://debian.ustc.edu.cn/debian-uo</a> sid marillat ustc misc

#deb <a href="http://debian.ustc.edu.cn/debian-uo">http://debian.ustc.edu.cn/debian-uo</a> sid marillat ustc misc

 #

#deb-src <a href="http://debian.ustc.edu.cn/debian">http://debian.ustc.edu.cn/debian</a> sid main contrib non-free

#deb-src <a href="http://debian.ustc.edu.cn/debian-security">http://debian.ustc.edu.cn/debian-security</a> sid/updates main contrib non-free

 #deb-src <a href="http://debian.ustc.edu.cn/debian">http://debian.ustc.edu.cn/debian</a> proposed-updates main contrib non-free

#

#deb <a href="http://mirrors.geekbone.org/debian/">http://mirrors.geekbone.org/debian/</a> sid main contrib non-free

 #deb <a href="http://mirrors.geekbone.org/debian-security">http://mirrors.geekbone.org/debian-security</a> sid/updates main contrib non-free

#deb <a href="http://mirrors.geekbone.org/debian/">http://mirrors.geekbone.org/debian/</a> proposed-updates main contrib non-free


```
