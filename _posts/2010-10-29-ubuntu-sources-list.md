---
author: aaronshang
comments: true
date: 2010-10-29 10:28:29+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/10/29/ubuntu-sources-list/
slug: ubuntu-sources-list
title: ubuntu sources.list
wordpress_id: 40
tags:
- sources.list
- ubuntu
---

# /etc/apt/sources.list

deb http://mirrors.163.com/ubuntu-cn/shutter/ppa/ubuntu/ maverick main

deb http://mirrors.163.com/ubuntu/ maverick main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ maverick-updates main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ maverick-proposed main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ maverick-security main restricted universe multiverse

deb-src http://mirrors.163.com/ubuntu/ maverick main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ maverick-updates main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ maverick-proposed main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ maverick-security main restricted universe multiverse


deb http://mirror.bjtu.edu.cn/ubuntu/ maverick main restricted universe multiverse
deb http://mirror.bjtu.edu.cn/ubuntu/ maverick-updates main restricted universe multiverse
deb http://mirror.bjtu.edu.cn/ubuntu/ maverick-proposed main restricted universe multiverse
deb http://mirror.bjtu.edu.cn/ubuntu/ maverick-security main restricted universe multiverse

#deb http://ftp.sjtu.edu.cn/ubuntu maverick main universe multiverse restricted
#deb http://ftp.sjtu.edu.cn/ubuntu/ maverick-proposed main multiverse restricted universe
#deb http://ftp.sjtu.edu.cn/ubuntu/ maverick-security main multiverse restricted universe
#deb http://ftp.sjtu.edu.cn/ubuntu/ maverick-updates main multiverse restricted universe

# wget -q -O- http://archive.getdeb.net/getdeb-archive.key | sudo apt-key add -
#deb http://archive.getdeb.net/ubuntu maverick-getdeb apps
#deb http://archive.getdeb.net/ubuntu maverick-getdeb games

deb http://archive.canonical.com/ maverick partner
deb http://archive.canonical.com/ubuntu/ maverick partner
deb http://archive.canonical.com/ maverick-updates partner
deb http://archive.canonical.com/ maverick-proposed partner
deb http://archive.canonical.com/ maverick-security partner

#deb http://archive.ubuntu.com/ubuntu/ maverick main restricted universe multiverse
#deb http://archive.ubuntu.com/ubuntu/ maverick-updates main restricted universe multiverse
#deb http://archive.ubuntu.com/ubuntu/ maverick-proposed main restricted universe multiverse
#deb http://security.ubuntu.com/ubuntu/ maverick-security main restricted universe multiverse

#deb-src http://archive.ubuntu.com/ubuntu/ maverick-updates main universe multiverse restricted
#deb-src http://archive.ubuntu.com/ubuntu/ maverick main universe multiverse restricted
#deb-src http://security.ubuntu.com/ubuntu maverick-security main universe multiverse restricted
#deb-src http://archive.ubuntu.com/ubuntu/ maverick-proposed main universe multiverse restricted
#deb-src http://archive.ubuntu.com/ubuntu/ maverick-backports main restricted universe multiverse

# Google software repository http://www.google.com/linuxrepositories/apt.html
# wget -q -O - https://dl-ssl.google.com/linux/linux_signing_key.pub | sudo apt-key add -
# or (gpg --keyserver subkeys.pgp.net --recv A040830F7FAC5991 && gpg --export --armor A040830F7FAC5991 | sudo apt-key add - )

# Google software repository
#deb http://dl.google.com/linux/deb/ testing non-free

#$ gpg --keyserver keyserver.ubuntu.com --recv-key 428D7C01
#gpg: requesting key 428D7C01 from hkp server keyserver.ubuntu.com
#gpg: key 428D7C01: public key "Ubuntu Debug Symbol Archive Automatic Signing Key " imported
#gpg: no ultimately trusted keys found
#gpg: Total number processed: 1
#gpg:               imported: 1
#$ gpg --check-sigs 428D7C01
#pub 1024D/428D7C01 2008-09-02
#uid Ubuntu Debug Symbol Archive Automatic Signing Key 
#sig!3        428D7C01 2008-09-02  Ubuntu Debug Symbol Archive Automatic Signing Key 
#sub   2048g/A2C2A7A5 2008-09-02
#sig!         428D7C01 2008-09-02  Ubuntu Debug Symbol Archive Automatic Signing Key 
#
#1 signature not checked due to a missing key
#
#$ gpg -o - --export 428D7C01 | sudo apt-key add -

# sudo apt-key add key.gpg

# wget -q http://packages.medibuntu.org/medibuntu-key.gpg -O- | sudo apt-key add -
#deb http://packages.medibuntu.org/ maverick free non-free
#deb http://packages.medibuntu.org/ maverick-staging non-free free

#deb http://mirrors.sohu.com/ubuntu/ maverick main restricted universe multiverse
#deb http://mirrors.sohu.com/ubuntu/ maverick-security main restricted universe multiverse
#deb http://mirrors.sohu.com/ubuntu/ maverick-updates main restricted universe multiverse
#deb http://mirrors.sohu.com/ubuntu/ maverick-proposed main restricted universe multiverse
#deb http://mirrors.sohu.com/ubuntu/ maverick-backports main restricted universe multiverse
#deb-src http://mirrors.sohu.com/ubuntu/ maverick main restricted universe multiverse
#deb-src http://mirrors.sohu.com/ubuntu/ maverick-security main restricted universe multiverse
#deb-src http://mirrors.sohu.com/ubuntu/ maverick-updates main restricted universe multiverse
#deb-src http://mirrors.sohu.com/ubuntu/ maverick-proposed main restricted universe multiverse
#deb-src http://mirrors.sohu.com/ubuntu/ maverick-backports main restricted universe multiverse


deb http://ppa.launchpad.net/puredyne-team/ppa/ubuntu maverick main
deb http://packages.medibuntu.org/ maverick free non-free
deb http://akirad.cinelerra.org akirad-maverick main
