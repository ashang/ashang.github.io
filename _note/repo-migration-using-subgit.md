---
title: repo migration using subgit
tags: Tale
---

# repo migration using subgit

```shell
JAVA_HOME=/usr/lib/jvm/default-java/jre/ subgit configure --layout directory svn://svnserver/repo/utils-debian/ ~/utils-debian.git

# make sure you're acting on behalf of the same user you use to serve Subversion repository

$ vi ~/utils-debian.git/subgit/passwd
$ vi ~/utils-debian.git/subgit/authors.txt

JAVA_HOME=/usr/lib/jvm/default-java/jre/ subgit install ~/utils-debian.git

SubGit version 3.2.4 ('Bobique') build #3670

Translating Subversion revisions to Git commits...

    Subversion revisions translated: 25434.
    Total time: 22 seconds.

INSTALLATION SUCCESSFUL

git clone utils-debian.git utils-debian
```
