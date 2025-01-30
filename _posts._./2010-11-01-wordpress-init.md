---
layout: post
title: WordPress init
date: 2010-11-01 10:47:17.000000000 +08:00
tags: []
meta:
  _edit_last: '17109838'
---

## Starting WordPress

- Get WordPress from: <a title="http://wordpress.org/latest.tar.gz" href="http://wordpress.org/latest.tar.gz" target="_blank">http://wordpress.org/latest.tar.gz</a> and explode it
to `your_target_install_path`

- Create database in MySQL:

```
$ mysql -u root -p
mysql> create database database_name;
mysql> grant all on db_name.* to db_user@localhost identified by 'passwd';
mysql> flush privileges;
mysql> exit
```

- `$ editor wp-config.php`

- Add to apache conf

```
Alias /weblog/ "/your_target_install_path/"
    <Directory /your_target_install_path/>
        DirectoryIndex index.php
        AllowOverride FileInfo Options
    </Directory>
```

- Done. Access URL: <a title="http://localhost/weblog" href="http://your.domain/weblog" target="_blank">http://your.domain/weblog</a>
