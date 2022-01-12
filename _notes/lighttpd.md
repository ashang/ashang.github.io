---
title: "Lighty Lighttpd notes"
tags: ["Apps"]
date: 2017-02-04
update: 2012-02-09T16:52:29+08:00
---

## [Lighttpd](http://www.lighttpd.net/) basic configuration

- Configuration files: /etc/lighttpd/
- CGI module: "lighty-enable-mod cgi".
- Log files are placed in /var/log/lighttpd. The frequency of rotation can be easily changed by editing /etc/logrotate.d/lighttpd.
- The default directory index is index.html, meaning that requests for a directory /foo/bar/ will give the contents of the file /var/www/foo/bar/index.html if it exists (assuming that /var/www is your DocumentRoot).
- You can enable user directories by using command "lighty-enable-mod userdir"
```

## Enable accesslog

```
$ sudo lighttpd-enable-mod accesslog
$ sudo /etc/init.d/lighttpd force-reload
```

Got

```
Duplicate config variable in conditional 0 global: accesslog.filename
(configfile.c.1316) source: /etc/lighttpd/conf-enabled/10-accesslog.conf line: 4 pos: 1 parser failed somehow near here: (EOL)
(configfile.c.1316) source: /usr/share/lighttpd/include-conf-enabled.pl line: 2 pos: 1 parser failed somehow near here: (EOL)
(configfile.c.1316) source: /etc/lighttpd/lighttpd.conf line: 71 pos: 1 parser failed somehow near here: (EOL)
```

Correct the settings.

```
$ sudo vi /etc/lighttpd/conf-enabled/10-accesslog.conf
```

To have lines.

```
server.modules += ( "mod_accesslog"  )
accesslog.filename = "/var/log/lighttpd/access.log"
```

```
$ sudo /etc/init.d/lighttpd force-reload
$ sudo tail -f /var/log/lighttpd/access.log
```

```
10.10.10.22 - [12/Nov/2021:15:17:57 +0800] "GET /build/debian10_gdb/ HTTP/1.1" 200 6621 "http://10.10.10.22/build/" "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4482.0 Safari/537.36 Edg/92.0.878.0"
```

Hah, this is from a user of Edge browser.

## URL rewrite

```
2021-11-12 15:17:38: (server.c.936) [note] graceful shutdown started
2021-11-12 15:17:38: (server.c.1970) server stopped by UID = 0 PID = 7048
2021-11-12 15:17:38: (server.c.1488) server started (lighttpd/1.4.56-devel-lighttpd-1.4.55-1-g2230b08e)
2021-11-12 15:17:38: (server.c.1517) WARNING: unknown config-key: url.redirect-simple (ignored)
```

Correct settings.

```
url.rewrite = (
    "^/gdb" => "/build/gdb/",
    "^/toolchain" => "/build/toolchainic/"
)
```

## xcache

```
$ cat xcache.ini | sudo tee -a /usr/local/php-5.3.3/lib/php.ini

$ cat php.ini
[xcache-common]
;; install as zend extension (recommended), normally
"$extension_dir/xcache.so"
;zend_extension =
/usr/local/lib/php/extensions/non-debug-non-zts-xxx/xcache.so
; zend_extension_ts =
	/usr/local/lib/php/extensions/non-debug-zts-xxx/xcache.so
	;开启下面行也可以
	;zend_extension=/usr/local/php-5.3.3/lib/php/extensions/no-debug-non-zts-20090626/xcache.so
	;; For windows users, replace xcache.so with php_xcache.dll
	;zend_extension_ts = c:/php/extensions/php_xcache.dll
	;; or install as extension, make sure your extension_dir setting is correct
	;这行开启也可以，均能够添加xcache模块，修改只有记得重启fpm
	extension = xcache.so
```

#

```diff
*** 10-ssl.conf (Y/I/N/O/D/Z) [default=N] ? d
--- /etc/lighttpd/conf-available/10-ssl.conf    2018-11-01 11:17:52.371378874 +0800
+++ /etc/lighttpd/conf-available/10-ssl.conf.dpkg-new   2019-02-23 14:35:48.000000000 +0800
@@ -1,9 +1,9 @@
 # /usr/share/doc/lighttpd/ssl.txt

+server.modules += ( "mod_openssl" )
+
 $SERVER["socket"] == "0.0.0.0:443" {
        ssl.engine  = "enable"
-       ssl.pemfile = "/etc/lighttpd/ssl/acip.pem"
-
-       ssl.cipher-list = "ECDHE-RSA-AES256-SHA384:AES256-SHA256:RC4:HIGH:!MD5:!aNULL:!EDH:!AESGCM"
-       ssl.honor-cipher-order = "enable"
+       ssl.pemfile = "/etc/lighttpd/server.pem"
+       ssl.cipher-list = "HIGH"
 }

```

```
--- /etc/lighttpd/lighttpd.conf 2018-11-01 11:01:43.033564918 +0800
+++ /etc/lighttpd/lighttpd.conf.dpkg-new        2019-01-28 19:33:22.000000000 +0800
@@ -1,9 +1,8 @@
 server.modules = (
+       "mod_indexfile",
        "mod_access",
        "mod_alias",
-       "mod_compress",
        "mod_redirect",
-       "mod_openssl",
 )

 server.document-root        = "/var/www/html"
@@ -14,8 +13,25 @@
 server.groupname            = "www-data"
 server.port                 = 80

+# strict parsing and normalization of URL for consistency and security
+# https://redmine.lighttpd.net/projects/lighttpd/wiki/Server_http-parseoptsDetails
+# (might need to explicitly set "url-path-2f-decode" = "disable"
+#  if a specific application is encoding URLs inside url-path)
+server.http-parseopts = (
+  "header-strict"           => "enable",# default
+  "host-strict"             => "enable",# default
+  "host-normalize"          => "enable",# default
+  "url-normalize-unreserved"=> "enable",# recommended highly
+  "url-normalize-required"  => "enable",# recommended
+  "url-ctrls-reject"        => "enable",# recommended
+  "url-path-2f-decode"      => "enable",# recommended highly (unless breaks app)
+ #"url-path-2f-reject"      => "enable",
+  "url-path-dotseg-remove"  => "enable",# recommended
+ #"url-path-dotseg-reject"  => "enable",
+ #"url-query-20-plus"       => "enable",# consistency in query string
+)

-index-file.names            = ( "index.php", "index.html", "index.lighttpd.html" )
+index-file.names            = ( "index.php", "index.html" )
 url.access-deny             = ( "~", ".inc" )
 static-file.exclude-extensions = ( ".php", ".pl", ".fcgi" )

@@ -24,6 +40,12 @@

 # default listening port for IPv6 falls back to the IPv4 port
 include_shell "/usr/share/lighttpd/use-ipv6.pl " + server.port
-include_shell "/usr/share/lighttpd/create-mime.assign.pl"
-include_shell "/usr/share/lighttpd/include-conf-enabled.pl"
+include_shell "/usr/share/lighttpd/create-mime.conf.pl"
+include "/etc/lighttpd/conf-enabled/*.conf"

+#server.compat-module-load   = "disable"
+server.modules += (
+       "mod_compress",
+       "mod_dirlisting",
+       "mod_staticfile",
+)

```


```
dir-listing.activate      = "enable"
dir-listing.hide-dotfiles = "disable"
dir-listing.exclude       = ( "~$" )
dir-listing.encoding = "UTF-8"
dir-listing.hide-header-file = "disable"
dir-listing.show-header = "disable"
dir-listing.hide-readme-file = "disable"
dir-listing.show-readme = "disable"
```

```
server.modules = (
	"mod_access",
	"mod_alias",
	"mod_compress",
 	"mod_redirect",
##       "mod_rewrite",
)

#server.document-root        = "/var/www"
server.document-root        = "/srv"
server.upload-dirs          = ( "/var/cache/lighttpd/uploads" )
server.errorlog             = "/var/log/lighttpd/error.log"
server.pid-file             = "/var/run/lighttpd.pid"
server.username             = "www-data"
server.groupname            = "www-data"
server.port                 = 80


index-file.names            = ( "index.php", "index.html", "index.lighttpd.html" )
## dir-listing.activate = "enable"
dir-listing.activate = "enable"

url.access-deny             = ( "~", ".inc" )
static-file.exclude-extensions = ( ".php", ".pl", ".fcgi" )

compress.cache-dir          = "/var/cache/lighttpd/compress/"
compress.filetype           = ( "application/javascript", "text/css", "text/html", "text/plain" )

## default listening port for IPv6 falls back to the IPv4 port
include_shell "/usr/share/lighttpd/use-ipv6.pl " + server.port
include_shell "/usr/share/lighttpd/create-mime.assign.pl"
include_shell "/usr/share/lighttpd/include-conf-enabled.pl"
```

```
# variables
var.basedir  = "/var/www/localhost"
var.logdir   = "/var/log/lighttpd"
var.statedir = "/var/lib/lighttpd"
#

# modules
## At the very least, mod_access and mod_accesslog should be enabled.
## All other modules should only be loaded if necessary.
## NOTE: the order of modules is important.
server.modules = (
##    "mod_rewrite",
##    "mod_redirect",
##    "mod_alias",
    "mod_access",
##    "mod_cml",
##    "mod_trigger_b4_dl",
##    "mod_auth",
##    "mod_status",
##    "mod_setenv",
##    "mod_proxy",
##    "mod_simple_vhost",
##    "mod_evhost",
##    "mod_userdir",
##    "mod_compress",
##    "mod_ssi",
##    "mod_usertrack",
##    "mod_expire",
##    "mod_secdownload",
##    "mod_rrdtool",
##    "mod_webdav",
    "mod_accesslog"
)
#

# includes
include "mime-types.conf"
## fcgi and cgi are included below
#

# server settings
server.username      = "lighttpd"
server.groupname     = "lighttpd"

server.document-root = var.basedir + "/htdocs"
server.pid-file      = "/var/run/lighttpd.pid"

server.errorlog      = var.logdir  + "/error.log"
## log errors to syslog instead
##   server.errorlog-use-syslog = "enable"

server.indexfiles    = ("index.php", "index.html",
						"index.htm", "default.htm")

## server.tag           = "lighttpd"

server.follow-symlink = "enable"

## event handler (defaults to "poll")
## see performance.txt
#
## for >= linux-2.4
##   server.event-handler = "linux-rtsig"
## for >= linux-2.6
##   server.event-handler = "linux-sysepoll"
## for FreeBSD
##   server.event-handler = "freebsd-kqueue"

## chroot to directory (defaults to no chroot)
## server.chroot      = "/"

## bind to port (defaults to 80)
## server.port          = 81

## bind to name (defaults to all interfaces)
## server.bind          = "grisu.home.kneschke.de"

## error-handler for status 404
## server.error-handler-404 = "/error-handler.html"
## server.error-handler-404 = "/error-handler.php"

## Format: <errorfile-prefix><status-code>.html
## -> ..../status-404.html for 'File not found'
## server.errorfile-prefix    = var.basedir + "/error/status-"

## FAM support for caching stat() calls
## requires that lighttpd be built with USE=fam
##   server.stat-cache-engine = "fam"
#

# mod_staticfile

## which extensions should not be handled via static-file transfer
## (extensions that are usually handled by mod_cgi, mod_fastcgi, etc).
static-file.exclude-extensions = (".php", ".pl", ".cgi", ".fcgi")
#

# mod_accesslog
accesslog.filename   = var.logdir + "/access.log"
#

# mod_dirlisting
## enable directory listings
##   dir-listing.activate      = "enable"
#
## don't list hidden files/directories
##   dir-listing.hide-dotfiles = "enable"
#
## use a different css for directory listings
##   dir-listing.external-css  = "/path/to/dir-listing.css"
#
## list of regular expressions.  files that match any of the
## specified regular expressions will be excluded from directory
## listings.
##   dir-listing.exclude = ("^\.", "~$")
#

# mod_access
## see access.txt

url.access-deny = ("~", ".inc")
#

# mod_userdir
## see userdir.txt
#
## userdir.path = "public_html"
## userdir.exclude-user = ("root")
#

# mod_ssi
## see ssi.txt
#
## ssi.extension = (".shtml")
#

# mod_ssl
## see ssl.txt
#
## ssl.engine    = "enable"
## ssl.pemfile   = "server.pem"
#

# mod_status
## see status.txt
#
## status.status-url  = "/server-status"
## status.config-url  = "/server-config"
#

# mod_simple_vhost
## see simple-vhost.txt
#
##  If you want name-based virtual hosting add the next three settings and load
##  mod_simple_vhost
#
## document-root =
##   virtual-server-root + virtual-server-default-host + virtual-server-docroot
## or
##   virtual-server-root + http-host + virtual-server-docroot
#
## simple-vhost.server-root   = "/home/weigon/wwwroot/servers/"
## simple-vhost.default-host  = "grisu.home.kneschke.de"
## simple-vhost.document-root = "/pages/"
#

# mod_compress
## see compress.txt
#
## compress.cache-dir   = var.statedir + "/cache/compress"
## compress.filetype    = ("text/plain", "text/html")
#

# mod_proxy
## see proxy.txt
#
## proxy.server               = ( ".php" =>
##                               ( "localhost" =>
##                                 (
##                                   "host" => "192.168.0.101",
##                                   "port" => 80
##                                 )
##                               )
##                             )
#

# mod_auth
## see authentication.txt
#
## auth.backend               = "plain"
## auth.backend.plain.userfile = "lighttpd.user"
## auth.backend.plain.groupfile = "lighttpd.group"

## auth.backend.ldap.hostname = "localhost"
## auth.backend.ldap.base-dn  = "dc=my-domain,dc=com"
## auth.backend.ldap.filter   = "(uid=$)"

## auth.require               = ( "/server-status" =>
##                               (
##                                 "method"  => "digest",
##                                 "realm"   => "download archiv",
##                                 "require" => "user=jan"
##                               ),
##                               "/server-info" =>
##                               (
##                                 "method"  => "digest",
##                                 "realm"   => "download archiv",
##                                 "require" => "valid-user"
##                               )
##                             )
#

# mod_rewrite
## see rewrite.txt
#
## url.rewrite = (
#	"^/$"		=>		"/server-status"
## )
#

# mod_redirect
## see redirect.txt
#
## url.redirect = (
#	"^/wishlist/(.+)"		=>		"http://www.123.org/$1"
## )
#

# mod_evhost
## define a pattern for the host url finding
## %% => % sign
## %0 => domain name + tld
## %1 => tld
## %2 => domain name without tld
## %3 => subdomain 1 name
## %4 => subdomain 2 name
#
## evhost.path-pattern        = "/home/storage/dev/www/%3/htdocs/"
#

# mod_expire
## expire.url = (
#	"/buggy/"		=>		"access 2 hours",
#	"/asdhas/"		=>		"access plus 1 seconds 2 minutes"
## )
#

# mod_rrdtool
## see rrdtool.txt
#
## rrdtool.binary  = "/usr/bin/rrdtool"
## rrdtool.db-name = var.statedir + "/lighttpd.rrd"
#

# mod_setenv
## see setenv.txt
#
## setenv.add-request-header  = ( "TRAV_ENV" => "mysql://user@host/db" )
## setenv.add-response-header = ( "X-Secret-Message" => "42" )
#

# mod_trigger_b4_dl
## see trigger_b4_dl.txt
#
## trigger-before-download.gdbm-filename = "/home/weigon/testbase/trigger.db"
## trigger-before-download.memcache-hosts = ( "127.0.0.1:11211" )
## trigger-before-download.trigger-url = "^/trigger/"
## trigger-before-download.download-url = "^/download/"
## trigger-before-download.deny-url = "http://127.0.0.1/index.html"
## trigger-before-download.trigger-timeout = 10
#

## mod_cml

See cml.txt

```
## don't forget to add index.cml to server.indexfiles
cml.extension               = ".cml"
cml.memcache-hosts          = ( "127.0.0.1:11211" )
```

## mod_webdav

See webdav.txt
```
$HTTP["url"] =~ "^/dav($|/)" {
    webdav.activate = "enable"
    webdav.is-readonly = "enable"
}

# set Content-Encoding and reset Content-Type for browsers that
# support decompressing on-thy-fly (requires mod_setenv)
$HTTP["url"] =~ "\.gz$" {
    setenv.add-response-header = ("Content-Encoding" => "x-gzip")
    mimetype.assign = (".gz" => "text/plain")
}

$HTTP["url"] =~ "\.bz2$" {
    setenv.add-response-header = ("Content-Encoding" => "x-bzip2")
    mimetype.assign = (".bz2" => "text/plain")
}

debug.log-request-header   = "enable"
debug.log-response-header  = "enable"
debug.log-request-handling = "enable"
debug.log-file-not-found   = "enable"

## cgi includes

# uncomment for cgi support
include "mod_cgi.conf"
# uncomment for php/fastcgi support
include "mod_fastcgi.conf"

# vim: set ft=conf foldmethod=marker et :
```
