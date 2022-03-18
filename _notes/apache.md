---
title: apache
weight: 2
date: 2017-09-27
update: 2016-01-06
---

```
# pacman -S apache
resolving dependencies...
looking for conflicting packages...

Packages (3) apr-1.7.0-3  apr-util-1.6.1-9  apache-2.4.51-2

Total Download Size:   2.11 MiB
Total Installed Size:  8.25 MiB

:: Proceed with installation? [Y/n]
:: Retrieving packages...
 apache-2.4.51-2-...  1714.1 KiB  2.89 MiB/s 00:01 [#####################] 100%
 apr-1.7.0-3-x86_64    279.5 KiB  3.14 MiB/s 00:00 [#####################] 100%
 apr-util-1.6.1-9...   168.6 KiB  2007 KiB/s 00:00 [#####################] 100%
 Total (3/3)             2.1 MiB  2.48 MiB/s 00:01 [#####################] 100%
(3/3) checking keys in keyring                     [#####################] 100%
(3/3) checking package integrity                   [#####################] 100%
(3/3) loading package files                        [#####################] 100%
(3/3) checking for file conflicts                  [#####################] 100%
(3/3) checking available disk space                [#####################] 100%
:: Processing package changes...
(1/3) installing apr                               [#####################] 100%
(2/3) installing apr-util                          [#####################] 100%
Optional dependencies for apr-util
    gdbm: enable gdbm support [installed]
    libldap: enable ldap support [installed]
    unixodbc: enable odbc support
    mariadb-libs: enable mysql/mariadb support
    postgresql-libs: enable postgres support
    db: enable berkley db support [installed]
    sqlite: enable sqlite support [installed]
    nss: enable nss crypto support [installed]
    openssl: enable openssl crypto support [installed]
(3/3) installing apache                            [#####################] 100%
Optional dependencies for apache
    lua: for mod_lua module [installed]
    libxml2: for mod_proxy_html, mod_xml2enc modules [installed]
    curl: for mod_md module [installed]
    jansson: for mod_md module [installed]
    brotli: for mod_brotli module [installed]
    uwsgi: for mod_proxy_uwsgi module
    lynx: apachectl status
    perl: for apxs and dbmmanage [installed]
:: Running post-transaction hooks...
(1/3) Reloading system manager configuration...
(2/3) Creating temporary files...
Detected unsafe path transition /usr/bin (owned by aaron) → /usr/bin/postdrop (owned by root) during canonicalization of /usr/bin/postdrop.
Detected unsafe path transition /usr/bin (owned by aaron) → /usr/bin/postqueue (owned by root) during canonicalization of /usr/bin/postqueue.
error: command failed to execute correctly
(3/3) Arming ConditionNeedsUpdate...

# systemctl restart httpd.service

# apachectl -l
Compiled in modules:
  core.c
  mod_so.c
  http_core.c
```

## Required modules: dir_module, php_module

## php

### libphp

```
/etc/httpd/conf/extra/php_module.conf

<IfModule dir_module>
	<IfModule php_module>
		DirectoryIndex index.php index.html
		<FilesMatch "\.php$">
			SetHandler application/x-httpd-php
		</FilesMatch>
		<FilesMatch "\.phps$">
			SetHandler application/x-httpd-php-source
		</FilesMatch>
	</IfModule>
</IfModule>
```

## Trouble shooting

### core:error: Permission denied

```
[core:error] [pid 1980342] (13)Permission denied: [client 127.0.0.1:33240] AH00035: access to /web/a.php denied (filesystem path '/home/aaron/w') because search permissions are missing on a component of the path
```

```
Require all granted
```

### authz_core:error: client denied by server configuration

```
[authz_core:error] [pid 1980343] [client 127.0.0.1:33258] AH01630: client denied by server configuration: /home/aaron/w/a.php
```

```
AllowOverride FileInfo Options
```
