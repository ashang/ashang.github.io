---
title: php notes
weight: 2
date: 2016-11-18
update: 2021-21-11 13:00:00 CST
tags:
- php-fpm
- spawn-fcgi
---

## Q & A

### 如何查看 php.ini 文件路径？

新建一个 test.php 文件，内容如下：

```php
<?php
phpinfo();
?>
```

然后在浏览器使用 url 访问 test.php，会显示 php 相关的配置、插件等大量相关信息，在其中 `Loaded Configuration File` 一项即可找到所有生效的 php.ini 文件路径。

或者，更简单地可以直接运行命令输出以上信息（如果安装了多个版本的 php，那注意使用正确的 php 命令）：

```sh
php -r "phpinfo();"
```

### 本地运行一个 php 文件

```sh
php [-f] test.php
```

### 几种错误提示及对应的解决办法

提示：

```sh
PHP Fatal error: Uncaught Error: Call to undefined function socket_create()
```

解决办法：

在 php.ini 文件中配置启用扩展 php_curl.dll。

提示：

```sh
PHP Fatal error:  Uncaught Error: Call to undefined function curl_init()
```

解决办法：

在 php.ini 文件中配置启用扩展 php_curl.dll。

提示：

```sh
The openssl extension is required for SSL/TLS protection but is not available. If you can not enable the openssl extension, you can disable this error, at your own risk, by setting the 'disable-tls' option to true
```

解决办法：

在 php.ini 文件中配置启用扩展 php_openssl.dll。

### 在开发环境下直接在页面显示出错信息

修改 php.ini 文件，配置 `display_errors = On`。

### 安装 Memcache（not Memcached）for php7

当前（2016-10-19）Memcache 扩展并未有官方的支持办法，所以从源码编译安装。

步骤：

1. 下载解压源码

   ```sh
   wget https://github.com/websupport-sk/pecl-memcache/archive/NON_BLOCKING_IO_php7.zip
   unzip NON_BLOCKING_IO_php7.zip
   cd pecl-memcache-NON_BLOCKING_IO_php7
   ```

2. 编译

   ```sh
   /usr/local/php7/bin/phpize && ./configure --enable-memcache --with-php-config=/usr/local/php7/bin/php-config && make
   ```

   注意 phpize 和 php-config 要使用 php7 下的。

3. 放置 so 文件到正确位置

   ```sh
   cp modules/memcache.so /usr/local/php7/lib/php/extensions/no-debug-non-zts-20151012/memcache.so
   ```

   目标路径可以在 phpinfo() 的 `extension_dir` 字段找到。

4. 配置

   ```sh
   echo 'extension=memcache.so' > /usr/local/php7/etc/php.d/memcache.ini
   ```

   目标路径可以在 phpinfo() 的 `Scan this dir for addtional .ini files` 字段找到。

5. 重启服务使扩展生效

   ```sh
   service php-fpm restart
   ```

参考 [Memcache extension with PHP 7 on CentOS fails to install](http://stackoverflow.com/questions/37550910/memcache-extension-with-php-7-on-centos-fails-to-install)。

### 修改 php.ini 后让配置生效

```sh
service php-fpm restart
```
## php-fpm vs. spawn-fcgi

PHP-FPM (FastCGI Process Manager) is an alternative PHP FastCGI implementation with some additional features useful for sites of any size, especially busier sites.

These features include:

    * Adaptive process spawning (NEW!)
    * Basic statistics (ala Apache's mod_status) (NEW!)
    * Advanced process management with graceful stop/start
    * Ability to start workers with different uid/gid/chroot/environment and different php.ini (replaces safe_mode)
    * Stdout & stderr logging
    * Emergency restart in case of accidental opcode cache destruction
    * Accelerated upload support
    * Support for a "slowlog"
    * Enhancements to FastCGI, such as fastcgi_finish_request() - a special function to finish request & flush all data while continuing to do something time-consuming (video converting, stats processing, etc.)

... and much more.

It was not designed with virtual hosting in mind (large amounts of pools) however it can be adapted for any usage model.

## Guzzle

Guzzle is a PHP HTTP client that makes it easy to send HTTP requests and trivial to integrate with web services.

- Simple interface for building query strings, POST requests, streaming large uploads, streaming large downloads, using HTTP cookies, uploading JSON data, etc...
- Can send both synchronous and asynchronous requests using the same interface.
- Uses PSR-7 interfaces for requests, responses, and streams. This allows you to utilize other PSR-7 compatible libraries with Guzzle.
- Abstracts away the underlying HTTP transport, allowing you to write environment and transport agnostic code; i.e., no hard dependency on cURL, PHP streams, sockets, or non-blocking event loops.
- Middleware system allows you to augment and compose client behavior.

```php
$client = new GuzzleHttp\Client();
$res = $client->request('GET', 'https://api.github.com/user', [
    'auth' => ['user', 'pass']
]);
echo $res->getStatusCode();
// "200"
echo $res->getHeader('content-type')[0];
// 'application/json; charset=utf8'
echo $res->getBody();
// {"type":"User"...'

// Send an asynchronous request.
$request = new \GuzzleHttp\Psr7\Request('GET', 'http://httpbin.org');
$promise = $client->sendAsync($request)->then(function ($response) {
    echo 'I completed! ' . $response->getBody();
});
$promise->wait();
```

## Trouble shooting

```
PHP Fatal error:  Uncaught Error: Class 'GuzzleHttp\Client' not found in /mail/program/lib/Roundcube/rcube.php:271
Stack trace:
#0 /mail/program/lib/Roundcube/spellchecker/googie.php(67): rcube->get_http_client()
#1 /mail/program/lib/Roundcube/rcube_spellchecker.php(142): rcube_spellchecker_googie->check()
#2 /mail/program/actions/mail/send.php(157): rcube_spellchecker->check()
#3 /mail/program/include/rcmail.php(275): rcmail_action_mail_send->run()
#4 /mail/index.php(283): rcmail->action_handler()
#5 {main}
  thrown in /mail/program/lib/Roundcube/rcube.php on line 271
```

```
$ sudo -u http composer require guzzlehttp/guzzle
Cannot create cache directory /var/www/.cache/composer/repo/https---repo.packagist.org/, or directory is not writable. Proceeding without cache
Cannot create cache directory /var/www/.cache/composer/files/, or directory is not writable. Proceeding without cache
Using version ^7.4 for guzzlehttp/guzzle
./composer.json has been created
Cannot create cache directory /var/www/.cache/composer/repo/https---repo.packagist.org/, or directory is not writable. Proceeding without cache
Cannot create cache directory /var/www/.cache/composer/files/, or directory is not writable. Proceeding without cache
Running composer update guzzlehttp/guzzle
Loading composer repositories with package information
Updating dependencies
Lock file operations: 8 installs, 0 updates, 0 removals
  - Locking guzzlehttp/guzzle (7.4.1)
  - Locking guzzlehttp/promises (1.5.1)
  - Locking guzzlehttp/psr7 (2.1.0)
  - Locking psr/http-client (1.0.1)
  - Locking psr/http-factory (1.0.1)
  - Locking psr/http-message (1.0.1)
  - Locking ralouphie/getallheaders (3.0.3)
  - Locking symfony/deprecation-contracts (v2.5.0)
Writing lock file
Installing dependencies from lock file (including require-dev)
Package operations: 8 installs, 0 updates, 16 removals
  - Downloading symfony/deprecation-contracts (v2.5.0)
  - Downloading psr/http-message (1.0.1)
  - Downloading psr/http-client (1.0.1)
  - Downloading ralouphie/getallheaders (3.0.3)
  - Downloading psr/http-factory (1.0.1)
  - Downloading guzzlehttp/psr7 (2.1.0)
  - Downloading guzzlehttp/promises (1.5.1)
  - Downloading guzzlehttp/guzzle (7.4.1)
  - Removing roundcube/plugin-installer (0.1.9)
  - Removing pear/pear_exception (v1.0.0)
  - Removing pear/pear-core-minimal (v1.10.3)
  - Removing pear/net_socket (v1.2.1)
  - Removing pear/net_smtp (1.7.3)
  - Removing pear/net_sieve (1.4.3)
  - Removing pear/net_ldap2 (v2.2.0)
  - Removing pear/net_idna2 (v0.2.0)
  - Removing pear/mail_mime (1.10.2)
  - Removing pear/crypt_gpg (v1.6.3)
  - Removing pear/console_getopt (v1.4.1)
  - Removing pear/console_commandline (v1.2.2)
  - Removing pear/auth_sasl (v1.1.0)
  - Removing kolab/net_ldap3 (1.0.6)
  - Removing endroid/qr-code (1.6.6)
  - Removing composer/semver (1.4.2)
  - Installing symfony/deprecation-contracts (v2.5.0): Extracting archive
  - Installing psr/http-message (1.0.1): Extracting archive
  - Installing psr/http-client (1.0.1): Extracting archive
  - Installing ralouphie/getallheaders (3.0.3): Extracting archive
  - Installing psr/http-factory (1.0.1): Extracting archive
  - Installing guzzlehttp/psr7 (2.1.0): Extracting archive
  - Installing guzzlehttp/promises (1.5.1): Extracting archive
  - Installing guzzlehttp/guzzle (7.4.1): Extracting archive
2 package suggestions were added by new dependencies, use `composer suggest` to see details.
Generating autoload files
4 packages you are using are looking for funding.
Use the `composer fund` command to find out more!

$ grep guzzle /mail/composer.json
"guzzlehttp/guzzle": "^7.4"
```

The warnings were due to wrong permission of HTTP user home.

```
$ grep http /etc/passwd
http:x:33:33:http:/www:/usr/sbin/nologin
```

```
$ sudo -u http tail -f logs/errors.log

[15-Dec-2021 16:39:13 +0800]: <b4e2isb6> PHP Error: php_network_getaddresses: getaddrinfo failed: Name or service not known (POST /mail/?_task=mail&_unlock=loading1639557566934&_framed=1&_lang=en_GB&_action=send)
[15-Dec-2021 16:39:13 +0800]: <b4e2isb6> PHP Error: Failed to connect socket: php_network_getaddresses: getaddrinfo failed: Name or service not known (POST /mail/?_task=mail&_unlock=loading1639557566934&_framed=1&_lang=en_GB&_action=send)
[15-Dec-2021 16:39:13 +0800]: <b4e2isb6> SMTP Error: Connection failed: Failed to connect socket: php_network_getaddresses: getaddrinfo failed: Name or service not known in /mail/program/lib/Roundcube/rcube.php on line 1774 (POST /mail/?_task=mail&_unlock=loading1639557566934&_framed=1&_lang=en_GB&_action=send)
```

Root cause is that the smtp server is not resolvable.

```
$ sudo $EDITOR config/config.inc.php
$config['smtp_server'] = 'xxxx';
```

Still there were issues.

```
[15-Dec-2021 16:49:29 +0800]: <b4e2isb6> PHP Error: Connection refused (POST /mail/?_task=mail&_unlock=loading1639558183450&_framed=1&_lang=en_GB&_action=send)
[15-Dec-2021 16:49:29 +0800]: <b4e2isb6> PHP Error: Failed to connect socket: Connection refused (POST /mail/?_task=mail&_unlock=loading1639558183450&_framed=1&_lang=en_GB&_action=send)
[15-Dec-2021 16:49:29 +0800]: <b4e2isb6> SMTP Error: Connection failed: Failed to connect socket: Connection refused in /mail/program/lib/Roundcube/rcube.php on line 1774 (POST /mail/?_task=mail&_unlock=loading1639558183450&_framed=1&_lang=en_GB&_action=send)
[15-Dec-2021 16:50:07 +0800]: <b4e2isb6> PHP Error: Connection refused (POST /mail/?_task=mail&_unlock=loading1639558221753&_framed=1&_lang=en_GB&_action=send)
[15-Dec-2021 16:50:07 +0800]: <b4e2isb6> PHP Error: Failed to connect socket: Connection refused (POST /mail/?_task=mail&_unlock=loading1639558221753&_framed=1&_lang=en_GB&_action=send)
[15-Dec-2021 16:50:07 +0800]: <b4e2isb6> SMTP Error: Connection failed: Failed to connect socket: Connection refused in /mail/program/lib/Roundcube/rcube.php on line 1774 (POST /mail/?_task=mail&_unlock=loading1639558221753&_framed=1&_lang=en_GB&_action=send)

```

## Links

- <http://php-fpm.org/about/>
- <http://wiki.nginx.org/NinX%2BPHP%2BFPM%2Bremote>

## PHP is a general-purpose server-side scripting language to produce dynamic web pages.

# php-mysql

    sudo apt-get purge php7.0-mysql && sudo apt-get install php-mysql

    php -r 'phpinfo();' | grep -i mysqli

    phpenmod mysqli

# Phalcon

Phalcon is full stack framework for PHP written as a C-extension, optimized for
high performance.

The functionality is exposed as PHP classes ready for you to use.

Phalcon also is loosely coupled, allowing you to use its objects as glue
components based on the needs of your application.

#### PHP C-extension (Phalcon)

* C-extensions are loaded together with PHP one time on the web server’s daemon start process
* Classes and functions provided by the extension are ready to use for any application
* The code is compiled and isn’t interpreted because is already compiled to a specific platform and processor
* Thanks to its low-level architecture and optimizations Phalcon provides the lowest overhead for MVC-based applications

> https://docs.phalconphp.com/

# Zephir

Zephir, an open source, high-level language designed to ease the creation and maintainability of extensions for PHP with a focus on type and memory safety.

Zephir is a language that addresses the major needs of a PHP developer trying to write and compile code that can be executed by PHP. It is a dynamically/statically typed, some of its features can be familiar to PHP developers.

#### Type system

Zephir combines static and dynamic typing in a friendly language that is compiled down to machine code using the industry standard compilers.

#### Memory safety

Despite being a compiled language, it does not allow you to use pointers, it provides a garbage collector to avoid memory leaks and more.

#### Compilation model

Zephir takes advantage of the extension ecosystem available in PHP to allow you create your own extensions as shared libraries.

> http://docs.zephir-lang.com/
> http://docs.zephir-lang.com/en/latest/intro.html

    php -r 'echo "\n\nYour PHP installation is working fine.\n\n\n";'

    sudo apt-get install libapache2-mod-php5

unable to handle PHP files

any navigation to them is triggering downloading rather than parsing.

$ sudo apt-get install libapache2-mod-php5
[sudo] password for 28850410:
Reading package lists... Done
Building dependency tree
Reading state information... Done
The following extra packages will be installed:
  apache2-mpm-prefork
The following packages will be REMOVED:
  apache2-mpm-worker
The following NEW packages will be installed:
  apache2-mpm-prefork libapache2-mod-php5
0 upgraded, 2 newly installed, 1 to remove and 8 not upgraded.

sudo apt-get install --reinstall libapache2-mod-php5filter

   sudo lsusb -v|grep idVendor
   sudo lsusb -v|grep idVendor|column -c
   sudo lsusb -v|grep idVendor|column -x
   sudo lsusb -v|grep idVendor|column -n

   cat /etc/udev/rules.d/51-android.rules

   column /tmp/bb
   column -t /tmp/bb

### php -m

### Build from source

   Prerequisite knowledge and software for compiling:
     * Basic Unix skills (being able to operate "make" and a C compiler)
     * An ANSI C compiler
     * A web server
     * Any module specific components (such as GD, PDF libs, etc.)

   When  building  directly from Git sources or after custom modifications
   you might also need:
     * autoconf: 2.13+ (for PHP < 5.4.0), 2.59+ (for PHP >= 5.4.0)
     * automake: 1.4+
     * libtool: 1.4.x+ (except 1.4.2)
     * re2c: Version 0.13.4 or newer
     * flex: Version 2.5.4 (for PHP <= 5.2)
     * bison: Version 1.28 (preferred), 1.35, or 1.75


	which apxs
	whereis apxs
	sudo apt install apache2-dev
	which apxs
	sudo apt install automake autoconf libtool make gcc bison byacc flex libxml2-dev libmysqlclient-dev re2c

./configure --with-mysql --with-apxs2=/usr/bin/apxs

	+--------------------------------------------------------------------+
	|                        *** WARNING ***                             |
	|                                                                    |
	| You have built PHP for Apache's current non-threaded MPM.          |
	| If you change Apache to use a threaded MPM you must reconfigure    |
	| PHP with --enable-maintainer-zts                                   |
	+--------------------------------------------------------------------+

	make
	make install

       If  you decide to change your configure options after installation,
       you'll  need to re-run the configure, make, and make install steps.
       You  only need to restart apache for the new module to take effect.
       A recompile of Apache is not needed.
       Note  that  unless told otherwise, 'make install' will also install
       PEAR,  various  PHP  tools such as phpize, install the PHP CLI, and
       more.

    6. Setup your php.ini

	sudo cp php.ini-development /usr/local/lib/php.ini

       You  may  edit  your  .ini  file  to set PHP options. If you prefer
       having php.ini in another location, use
       --with-config-file-path=/some/path in step 5.
       If  you  instead  choose php.ini-production, be certain to read the
       list of changes within, as they affect how PHP behaves.
    7. Edit  your httpd.conf to load the PHP module. The path on the right
       hand side of the LoadModule statement must point to the path of the
       PHP  module  on  your  system. The make install from above may have
       already added this for you, but be sure to check.
LoadModule php5_module modules/libphp5.so
    8. Tell  Apache to parse certain extensions as PHP. For example, let's
       have  Apache  parse  .php  files  as PHP. Instead of only using the
       Apache  AddType  directive,  we want to avoid potentially dangerous
       uploads  and  created  files  such  as  exploit.php.jpg  from being
       executed   as   PHP.   Using  this  example,  you  could  have  any
       extension(s)  parse as PHP by simply adding them. We'll add .php to
       demonstrate.
<FilesMatch \.php$>
    SetHandler application/x-httpd-php
</FilesMatch>
       Or,  if we wanted to allow .php, .php2, .php3, .php4, .php5, .php6,
       and  .phtml files to be executed as PHP, but nothing else, we'd use
       this:
<FilesMatch "\.ph(p[2-6]?|tml)$">
    SetHandler application/x-httpd-php
</FilesMatch>
       And  to  allow  .phps files to be handled by the php source filter,
       and displayed as syntax-highlighted source code, use this:
<FilesMatch "\.phps$">
    SetHandler application/x-httpd-php-source
</FilesMatch>
       mod_rewrite  may  be  used  To  allow any arbitrary .php file to be
       displayed  as  syntax-highlighted  source  code,  without having to
       rename or copy it to a .phps file:
RewriteEngine On
RewriteRule (.*\.php)s$ $1 [H=application/x-httpd-php-source]
       The  php source filter should not be enabled on production systems,
       where it may expose confidential or otherwise sensitive information
       embedded in source code.



	make test

	Build complete.
	Don't forget to run 'make test'.


	=====================================================================
	PHP         : /home/aaron/php-5.3.27/sapi/cli/php
	PHP_SAPI    : cli
	PHP_VERSION : 5.3.27
	ZEND_VERSION: 2.3.0
	PHP_OS      : Linux - Linux mail 3.16.0-4-amd64 #1 SMP Debian 3.16.7-ckt11-1+deb8u3 (2015-08-04) x86_64
	INI actual  : /home/aaron/php-5.3.27/tmp-php.ini
	More .INIs  :
	CWD         : /home/aaron/php-5.3.27
	Extra dirs  :
	VALGRIND    : Not used


# sudo make install
	Installing PHP SAPI module:       apache2handler
	/usr/share/apache2/build/instdso.sh SH_LIBTOOL='/usr/share/apr-1.0/build/libtool' libphp5.la /usr/lib/apache2/modules
	/usr/share/apr-1.0/build/libtool --mode=install install libphp5.la /usr/lib/apache2/modules/
	libtool: install: install .libs/libphp5.so /usr/lib/apache2/modules/libphp5.so
	libtool: install: install .libs/libphp5.lai /usr/lib/apache2/modules/libphp5.la
	libtool: install: warning: remember to run `libtool --finish /home/aaron/php-5.3.27/libs'
	chmod 644 /usr/lib/apache2/modules/libphp5.so
	[preparing module `php5' in /etc/apache2/mods-available/php5.load]
	Enabling module php5.
	To activate the new configuration, you need to run:
		service apache2 restart
	Installing PHP CLI binary:        /usr/local/bin/
	Installing PHP CLI man page:      /usr/local/man/man1/
	Installing build environment:     /usr/local/lib/php/build/
	Installing header files:          /usr/local/include/php/
	Installing helper programs:       /usr/local/bin/
		program: phpize
		program: php-config
	Installing man pages:             /usr/local/man/man1/
		page: phpize.1
		page: php-config.1
	Installing PEAR environment:      /usr/local/lib/php/
	[PEAR] Archive_Tar    - installed: 1.3.11
	[PEAR] Console_Getopt - installed: 1.3.1
	warning: pear/PEAR requires package "pear/Structures_Graph" (recommended version 1.0.4)
	warning: pear/PEAR requires package "pear/XML_Util" (recommended version 1.2.1)
	[PEAR] PEAR           - installed: 1.9.4
	Wrote PEAR system config file at: /usr/local/etc/pear.conf
	You may want to add: /usr/local/lib/php to your php.ini include_path
	[PEAR] Structures_Graph- installed: 1.0.4
	[PEAR] XML_Util       - installed: 1.2.1
	/home/aaron/php-5.3.27/build/shtool install -c ext/phar/phar.phar /usr/local/bin
	ln -s -f /usr/local/bin/phar.phar /usr/local/bin/phar
	Installing PDO headers:          /usr/local/include/php/ext/pdo/


	NOTE:
	You may want to add: /usr/local/lib/php to your php.ini include_path


# Not fixed
./configure --enable-mbstring --enable-exif --enable-intl --with-openssl --with-mysql --with-apxs2=/usr/bin/apxs





/usr/bin/ld: ext/intl/msgformat/msgformat_helpers.o: undefined reference to symbol '__gxx_personality_v0@@CXXABI_1.3'
/usr/lib/x86_64-linux-gnu/libstdc++.so.6: error adding symbols: DSO missing from command line


-lstdc++ into EXTRA_LIBS.


Also if you change $(CC) to $(CXX) in BUILD_* vars in Makefile it seems to help too. Looks like if you use C++ anywhere in PHP the linker should be C++ or library should be added manually.



replacing the $(BUILD_CGI) and $(BUILD_CLI)
instances of $(CC) in the generated Makefile with $(CXX) fixes the
build.


(s/CC/CXX/ in BUILD_* vars)

sed -i '/EXTRA_LIBS = /s|$| -lstdc++|' Makefile




edit Makefile and found the rule of

ext/intl/msgformat/msgformat_helpers.cpp

change the $(CC) to $(CXX)

then run:

sed -i '/EXTRA_LIBS = /s|$| -lstdc++|' Makefile




This problem is cropping up on CentOS 7 x86_64 with PHP 5.3.29.

It looks like the PHP devs resolved this in later versions of PHP by adding PHP_ADD_LIBRARY macros to acinclude.m4 and aclocal.m4.

The odd thing is, on CentOS 6.5, the resulting sapi/cli/php binary properly links against libstdc++ even though it isn't passing -lstdc++ to the linker.  I'll need to figure out why that's possible at a later date.

To resolve this specific issue, I did the following.

1. Patch acinclude.m4 and aclocal.m4
2. re-run ./buildconf

This regenerates the configure script and ensures that the -lstdc++ is used to properly link sapi/cli/php.  However, it also ensures scripts/php-config is updated with the -lstdc++ library as well.  This update ensures all extensions that that are compiled against your PHP version also link against stdc++.

The patch:

commit 9fc87ffe4384306abb4454ced58b02a79114038e
Author: S. Kurt Newman <kurt.newman@cpanel.net>
Date:   Wed Feb 25 17:45:36 2015 -0600


    add stdc++ to acinclude and aclocal for php 5.3.29

diff --git a/acinclude.m4 b/acinclude.m4
index 2681b79..6ad028e 100644
--- a/acinclude.m4
+++ b/acinclude.m4
@@ -762,6 +762,7 @@ AC_DEFUN([PHP_REQUIRE_CXX],[
   if test -z "$php_cxx_done"; then
     AC_PROG_CXX
     AC_PROG_CXXCPP
+    PHP_ADD_LIBRARY(stdc++)
     php_cxx_done=yes
   fi
 ])
diff --git a/aclocal.m4 b/aclocal.m4
index 07b5e61..f3770e2 100644
--- a/aclocal.m4
+++ b/aclocal.m4
@@ -762,6 +762,7 @@ AC_DEFUN([PHP_REQUIRE_CXX],[
   if test -z "$php_cxx_done"; then
     AC_PROG_CXX
     AC_PROG_CXXCPP
+    PHP_ADD_LIBRARY(stdc++)
     php_cxx_done=yes
   fi
 ])


# intl

```php
/etc/php5/apache2/php.ini
[intl]
extension=php_intl.dll
;intl.default_locale =
; happens within intl functions. The value is the level of the error produced.
;intl.error_level = E_WARNING

```

Internationalization extension (further is referred as Intl) is a wrapper for » ICU library, enabling PHP programmers to perform various locale-aware operations including but not limited to formatting, transliteration, encoding conversion, calendar operations, » UCA-conformant collation, locating text boundaries and working with locale identifiers, timezones and graphemes,

It tends to closely follow ICU APIs, so that people having experience working with ICU in either C/C++ or Java could easily use the PHP API. Also, this way ICU documentation would be useful to understand various ICU functions.

Intl consists of several modules, each of them exposes the corresponding ICU API:

    Collator: provides string comparison capability with support for appropriate locale-sensitive sort orderings.
    Number Formatter: allows to display number according to the localized format or given pattern or set of rules, and to parse strings into numbers.
    Message Formatter: allows to create messages incorporating data (such as numbers or dates) formatted according to given pattern and locale rules, and parse messages extracting data from them. It can handle plurals, locale-aware numbers, currencies, conditions and much more.
    Normalizer: provides a function to transform text into one of the Unicode normalization forms, and provides a routine to test if a given string is already normalized.
    Locale: provides interaction with locale identifiers in the form of functions to get subtags from locale identifier; parse, compose, match(lookup and filter) locale identifiers.
    Calendar: provides a class which could be used for locale-aware calendar operations and getting various information such as timezone for locale chosen, first day of week or if it's daylight saving time now.
    Timezone: provides a wrapper around the » "Olson" database which has information about all the timezones around the world.
    Date formatter: allows to display date and time according to the localized format or given pattern or set of rules, and to parse strings into date and time.
    Transliterator: allows getting latin representation of strings in various languages.
    Transliterator: allows getting latin representation of strings in various languages.

# PECL
<acronym title="PHP Extension Community Library">PECL</acronym>
is a repository for PHP Extensions, providing a directory of all known
extensions and hosting facilities for downloading and development of PHP
extensions.

The packaging and distribution system used by PECL is shared with its
sister, <acronym title="PHP Extension and Application Repository"
>PEAR</acronym>.

./configure --enable-mbstring --enable-exif --enable-intl --with-openssl --with-mysql --with-pdo-mysql --with-apxs2=/usr/bin/apxs

# Running multiple versions of PHP

One of the great advantages of using Gentoo for PHP development is the version slotting. It is very simple to swap between multiple versions of PHP as well as run multiple versions simultaneously. This is all done with the eselect command provided by the app-eselect/eselect-php package which should get pulled in automatically by installing PHP. For example, selecting different versions of PHP can allow a system to run PHP 7.0 for the cli SAPI but PHP 5.6 for the system's web server. It also allows to quickly test an application on different versions of PHP.

To list the available versions for the cli SAPI use:
root #eselect php list cli

 [1]   php5.5
 [2]   php5.6 *
 [3]   php7.0

The version marked with the * is the current active version, and to check the other SAPIs simply replace cli with fpm,cgi or apache2.

To swap versions, use:
root #eselect php set cli 3

The number 3 in this example corresponds to the number in the output of the list sub-command used above. PHP version 7.0 is now used for the command-line:
root #php -v

PHP 7.0.10-pl0-gentoo (cli) (built: Aug 23 2016 12:38:44) ( NTS )

# FPM
PHP-FPM (FastCGI Process Manager) is an alternative PHP FastCGI implementation.

It provides additional features useful for sites bigger in size.

## Install PHP7-FPM

    apt install -y php-fpm php-mysql php-cli

Edit the respective php.ini file according to the installed PHP version.

    $EDITOR /etc/php/7.2/fpm/php.ini

PHP-FPM listens on the socket /var/run/php7.2-fpm.sock by default. To make PHP-FPM use a TCP connection, open the file /etc/php/7.2/fpm/pool.d/www.conf and change the listen parameter.

FROM:

    listen = /run/php/php7.2-fpm.sock
TO:

    listen = 127.0.0.1:9000

Restart PHP-FPM service.

    systemctl restart php7.2-fpm

### cgi.fix_pathinfo

value 1 will allow searching for the file that is as near to the requested file as possible which in turn may allow non-PHP files to be executed as PHP.

It is a possible security risk.

0 causes the PHP interpreter to only try the literal path given and to stop processing if the file is not found.

You can find more information https://www.nginx.com/resources/wiki/start/topics/tutorials/config_pitfalls/.

set cgi.fix_pathinfo to 0.

    cgi.fix_pathinfo=0

## Enable PHP-FPM Support on Virtual Host

Domain Name : web.site.local
Document Root : /srv/web.site.local

Create a virtual host configuration file for our domain: /etc/nginx/conf.d/web.site.local.conf.

```
server {
   server_name web.site.local;
   root /srv/web.site.local;

   location / {
       index index.html index.htm index.php;
   }

   location ~ \.php$ {
      include /etc/nginx/fastcgi_params;
      fastcgi_pass 127.0.0.1:9000;
      fastcgi_index index.php;
      fastcgi_param SCRIPT_FILENAME /srv/web.site.local$fastcgi_script_name;
   }
}
```
## Test PHP-FPM support on the Virtual Host

```
<?php phpinfo(); ?>
```

```
chown -R www-data:www-data /srv/web.site.local/
systemctl restart nginx
systemctl restart php7.2-fpm
systemctl enable php7.2-fpm
```

# php session

```
$ more /etc/cron.d/php
# /etc/cron.d/php@PHP_VERSION@: crontab fragment for PHP
#  This purges session files in session.save_path older than X,
#  where X is defined in seconds as the largest value of
#  session.gc_maxlifetime from all your SAPI php.ini files
#  or 24 minutes if not defined.  The script triggers only
#  when session.save_handler=files.
#
#  WARNING: The scripts tries hard to honour all relevant
#  session PHP options, but if you do something unusual
#  you have to disable this script and take care of your
#  sessions yourself.

# Look for and purge old sessions every 30 minutes
09,39 *     * * *     root   [ -x /usr/lib/php/sessionclean ] && /usr/lib/php/sessionclean
```

# PHP expect

These notes are NOT recommended to use in production environments.

Reference:
- http://php.net/manual/en/book.expect.php
- http://php.net/manual/en/expect.examples-usage.php


## Main Expect Functions
- expect_expectl
    - Waits until the output from a process matches one of the patterns, a specified time period has passed, or an EOF is seen
- expect_popen
    - Execute command via Bourne shell, and open the PTY stream to the process

## Example from the PHP manual

```php
#!/usr/bin/php -q

<?php
ini_set ("expect.loguser", "Off");
$stream = fopen ("expect://ssh root localhost uptime", "r");
$cases = array (
 array (0 => "assword:", 1 => PASSWORD)
);

switch (expect_expectl ($stream, $cases)) {
case PASSWORD: fwrite ($stream, "pass123\n"); break;
default: die ("Error was occurred while connecting to the remote host!\n");
}

while ($line = fgets ($stream)) { print $line; }
fclose ($stream);
?>
```

## Install needed packages
```bash
sudo apt install expect-dev
sudo apt install libtool
sudo apt install php-pear

...
checking specify path to Tcl needed by expect... yes, shared
checking for tcl version... configure: error: not found
ERROR: `/tmp/pear/temp/expect/configure' failed

```

### To phpize

```bash
sudo apt install php5-dev
```

### build expect

```bash
sudo pecl install expect

downloading expect-0.3.3.tgz ...
Starting to download expect-0.3.3.tgz (9,334 bytes)
.....done: 9,334 bytes
6 source files, building
running: phpize
Configuring for:
PHP Api Version:         20090626
Zend Module Api No:      20090626
Zend Extension Api No:   220090626
building in /tmp/pear/temp/pear-build-rootJFeTez/expect-0.3.3
running: /tmp/pear/temp/expect/configure
checking for grep that handles long lines and -e... /bin/grep
checking for egrep... /bin/grep -E
checking for a sed that does not truncate output... /bin/sed
checking for cc... cc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
...

Libraries have been installed in:
	/tmp/pear/temp/pear-build-rootJFeTez/expect-0.3.3/modules

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the `-LLIBDIR'
flag during linking and do at least one of the following:
	- add LIBDIR to the `LD_LIBRARY_PATH' environment variable
		during execution
	- add LIBDIR to the `LD_RUN_PATH' environment variable
		during linking
	- use the `-Wl,-rpath -Wl,LIBDIR' linker flag
	- have your system administrator add LIBDIR to `/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.

Build complete.
Don't forget to run 'make test'.


Installing shared extensions:     /tmp/pear/temp/pear-build-rootTu0wAr/install-expect-0.3.3/usr/lib/php5/20131226/
running: find "/tmp/pear/temp/pear-build-rootTu0wAr/install-expect-0.3.3" | xargs ls -dils
2097403  4 drwxr-xr-x 3 root root  4096 Feb 23 18:21 /tmp/pear/temp/pear-build-rootTu0wAr/install-expect-0.3.3
2097427  4 drwxr-xr-x 3 root root  4096 Feb 23 18:21 /tmp/pear/temp/pear-build-rootTu0wAr/install-expect-0.3.3/usr
2097428  4 drwxr-xr-x 3 root root  4096 Feb 23 18:21 /tmp/pear/temp/pear-build-rootTu0wAr/install-expect-0.3.3/usr/lib
2097429  4 drwxr-xr-x 3 root root  4096 Feb 23 18:21 /tmp/pear/temp/pear-build-rootTu0wAr/install-expect-0.3.3/usr/lib/php5
2097430  4 drwxr-xr-x 2 root root  4096 Feb 23 18:21 /tmp/pear/temp/pear-build-rootTu0wAr/install-expect-0.3.3/usr/lib/php5/20131226
2097425 72 -rwxr-xr-x 1 root root 70184 Feb 23 18:21 /tmp/pear/temp/pear-build-rootTu0wAr/install-expect-0.3.3/usr/lib/php5/20131226/expect.so

Build process completed successfully
Installing '/usr/lib/php5/20131226/expect.so'
install ok: channel://pecl.php.net/expect-0.3.3
configuration option "php_ini" is not set to php.ini location
You should add "extension=expect.so" to php.ini
```

### Configure `extension` directive in `php.ini`

Adding the `extension_dir` directive in `php.ini` does not actually load the modules contained within but just points to the place where they can be found.
```
extension_dir = "/usr/lib/php/modules"
```

Also add
```
extension="expect.so"
```
into `/etc/php.ini` underneath `extension_dir`.

Then, after restarted Apache the module is loaded and all works fine.


## You need to restart your webserver since the php.ini changed

```
sudo apache2ctl graceful
```
Or
```
sudo systemctl restart apache2.service
```

# Trouble shooting

## You are using different web SAPI PHP version than you have PHP CLI, f.e. you might have installed libapache2-mod-php5.6 with php7.0-cli

## Your Apache 2.x configuration contains different PHP FPM version (f.e. php5.6-fpm package) and Apache2 module (f.e. libapache2-mod-php7.0). Disable the FPM by running: a2disconf php5.5-fpm.

## The web SAPI, you are using for web has different configuration file and thus mysqli module is not loaded, to fix add extension=mysqli.so to this custom configuration file


## Fatal error: Undefined class constant 'MYSQL_ATTR_FOUND_ROWS'

- Solution

Install PDO.

## PECL: configuration option "php_ini" is not set to php.ini location

	configuration option "php_ini" is not set to php.ini location

	You should add "extension=expect.so" to php.ini

- Solution

```
sudo pear config-set php_ini /etc/php/php.ini
```

	config-set succeeded

```
sudo pecl config-set php_ini /etc/php/php.ini
```

	config-set succeeded

For phpenv

	pecl config-set php_ini ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini


## Warning: mysql_fetch_array() expects parameter 1 to be resource, boolean given in .php on line 120

Code inside of the while() loop is reusing the `$result` variable, so the next time the while() condition is evaluated, you have a TRUE/FALSE value instead of the original result resource.

Please be careful when reusing variables.

## Fatal error: Call to undefined function mysql_connect()

	PHP Fatal error: Uncaught Error: Call to undefined function mysql_connect() in connect.php:10\nStack trace:\n#0 index.php(4): include()\n#1 {main}\n thrown in...

- Solution
```
sudo apt install php5-mysql
```

## Fatal error: Call to undefined function mysqli_connect()

```
PHP Warning:  PHP Startup: Unable to load dynamic library '/usr/lib/php/20151012/mysqli.so' - /usr/lib/php/20151012/mysqli.so: undefined symbol: mysqlnd_connect in Unknown on line 0

Fatal error: Uncaught Error: Call to undefined function mysqli_connect() in ...
Stack trace:
#0 {main}


$ php -r 'phpinfo()'
PHP Warning:  PHP Startup: Unable to load dynamic library '/usr/lib/php/20151012/mysqli.so' - /usr/lib/php/20151012/mysqli.so: undefined symbol: mysqlnd_connect in Unknown on line 0

Parse error: syntax error, unexpected end of file in Command line code on line 1
```

- Solution
```
$ sudo phpenmod mysqli
WARNING: Directory /etc/php/7.0/cli/conf.d doesn't exist, not enabling the module
$ sudo mkdir /etc/php/7.0/cli
$ sudo mkdir /etc/php/7.0/cli/conf.d
$ sudo phpenmod mysqli
```

## PHP Fatal error: Call to undefined function expect_popen()

- Solution
Build expect.


## Disable errors/warnings
```ini
display_errors = Off
error_reporting = ~E_ALL

   ; Default Value: On (Suppress warnings)
   ; Development Value: Off (Issue warnings)
   ; Production Value: Off (Issue warnings)
   ; http://php.net/allow-call-time-pass-reference
   allow_call_time_pass_reference = On

error_reporting(E_ALL ^ E_WARNING);

error_reporting(E_ERROR | E_PARSE);


// Turn off all error reporting
        error_reporting(0);

```

# NOTES

First of all, most servers are configured by default to NOT allow remote root login via ssh.

Secondly, why not use SSH keyfiles to allow passwordless logins?

It is WAY more secure than storing your password.

Set up an account (for the case of this example, let's call it "automate") that has passwordless sudo access to the automation command (see the NOPASSWD flag on sudoers)

Use `ssh-keygen` to configure passwordless access to this account from the remote system

Instead of using expect:// to run the command, simply run the command directly:

```
ssh automate@10.1.2.3 sudo theCommand
```

## Trouble shooting

sudo apt-get install libapache2-mod-php5

unable to handle PHP files

any navigation to them is triggering downloading rather than parsing.


$ sudo apt-get install libapache2-mod-php5
[sudo] password for 28850410:
Reading package lists... Done
Building dependency tree
Reading state information... Done
The following extra packages will be installed:
  apache2-mpm-prefork
The following packages will be REMOVED:
  apache2-mpm-worker
The following NEW packages will be installed:
  apache2-mpm-prefork libapache2-mod-php5
0 upgraded, 2 newly installed, 1 to remove and 8 not upgraded.


sudo apt-get install --reinstall libapache2-mod-php5filter


 6967  lsusb -v|grep idVendor
 6968  sudo lsusb -v|grep idVendor
 6969  sudo lsusb -v|grep idVendor|column
 6970  sudo lsusb -v|grep idVendor|column -t
 6971  man column
 6972  sudo lsusb -v|grep idVendor|column -c
 6973  sudo lsusb -v|grep idVendor|column -x
 6974  sudo lsusb -v|grep idVendor|column -n
 6975  vi bench/priv/note/adb.mkd
 6976  sudo vi /etc/udev/rules.d/51-android.rules
 6977  cat /etc/udev/rules.d/51-android.rules
 6978  sudo vi /etc/udev/rules.d/51-android.rules
 6979  vi bench/priv/note/adb.mkd
 6980  vi /tmp/bb
 6981  column /tmp/bb
 6982  column -t /tmp/bb
 6983  vi bench/priv/note/adb.mkd
 6984  lt
 6985  cd bench/
 6986  cd priv/
 6987  ll
 6988  vi xxb.mkd
 6989  sudo apt-get install ruby
 6990  sudo apt-get install ruby rubygems
 6991  rails -v
 6992  sudo apt-get install rails
 6993  sudo gem install rack rake mongrel i18n mysql
 6994  sudo apt-get install sudo apt-get install libmysqlclient-dev
 6995  sudo apt-get install libmysqlclient-dev mysql-server
 6996  sudo gem install rack rake mongrel i18n mysql
 6997  lt
 6998  cd bench/
 6999  lt
 7000  ..
 7001  lt
 7002  ll redmine-2.6.0.zip
 7003  unzip -t redmine-2.6.0.zip
 7004  unzip redmine-2.6.0.zip
 7005  cd redmine-2.6.0/
 7006  ll
 7007  ..
 7008  ll /opt/
 7009  sudo mv redmine-2.6.0 /opt/mine
 7010  mysql
 7011  sudo service mysql restart
 7012  sudo service mysql stop
 7013  sudo apt-get install mysql-server
 7014  sudo apt-get install --reinstall mysql-server
 7015  mysql
 7016  sudo service mysql restart
 7017  eng prox
 7018  cd /var/run
 7019  ll mysqld/
 7020  cd
 7021  sudo grep mysqld /etc/mysql/*cnf
 7022  ll /var/lib/mysql/
 7023  sudo ln -ll /var/lib/mysql/
 7024  sudo ls -ll /var/lib/mysql/
 7025  sudo ls -ll /var/lib/mysql/mysql
 7026  dpkg -S /var/lib/mysql/mysql
 7027  sudo dpkg -S /var/lib/mysql/mysql
 7028*
 7029  sudo dpkg -S /var/lib/mysql
 7030  sudo apt-get autoremove --purge mysql-server-core-5.5
 7031  as akonadi-server
 7032  sudo apt-get install --reinstall mysql-server-core-5.5
 7033  sudo apt-get autoremove --purge
 7034  mysql
 7035  sudo apt-get install --reinstall mysql-server-core-5.5
 7036  sudo apt-get autoremove --purge mysql-server-5
 7037  sudo apt-get autoremove --purge
 7038  sudo apt-get install mysql-server
 7039  mysql
 7040  psg mysql
 7041  sudo ls -ll /var/lib/mysql/mysql
 7042*
 7043  sudo a2enmod
 7046  curl cnbjlx9076
 7047  unset http_proxy
 7048  curl cnbjlx9076
 7049  sudo vi /etc/apache2/conf.d/mediawiki.conf
 7050  diff /etc/apache2/conf.d/mediawiki.conf bench/priv/mediawiki.conf
 7051  ll bench/priv/ | grep conf
 7052  sudo vi /etc/apache2/apache2.conf
 7053  cd /etc/apache2/
 7054  ll
 7055  cd mods-enabled/
 7056  ll
 7057  ll|grep php
 7058  ..
 7059  ll mods-available/
 7060  ll mods-available/|grep php
 7061  as php
 7062  as php|grep mod
 7066  curl cnbjlx9076
 7067  history

 6963  ..
 6964  rm bbb/
 6965  lsusb -v
 6966  lsusb -v|grep -i vendor
 6967  lsusb -v|grep idVendor
 6968  sudo lsusb -v|grep idVendor
 6969  sudo lsusb -v|grep idVendor|column
 6970  sudo lsusb -v|grep idVendor|column -t
 6971  man column
 6972  sudo lsusb -v|grep idVendor|column -c
 6973  sudo lsusb -v|grep idVendor|column -x
 6974  sudo lsusb -v|grep idVendor|column -n
 6975  vi bench/priv/note/adb.mkd
 6976  sudo vi /etc/udev/rules.d/51-android.rules
 6977  cat /etc/udev/rules.d/51-android.rules
 6978  sudo vi /etc/udev/rules.d/51-android.rules
 6979  vi bench/priv/note/adb.mkd
 6980  vi /tmp/bb
 6981  column /tmp/bb
 6982  column -t /tmp/bb
 6983  vi bench/priv/note/adb.mkd
 6984  lt
 6985  cd bench/
 6986  cd priv/
 6987  ll
 6988  vi xxb.mkd
 6989  sudo apt-get install ruby
 6990  sudo apt-get install ruby rubygems
 6991  rails -v
 6992  sudo apt-get install rails
 6993  sudo gem install rack rake mongrel i18n mysql
 6994  sudo apt-get install sudo apt-get install libmysqlclient-dev
 6995  sudo apt-get install libmysqlclient-dev mysql-server
 6996  sudo gem install rack rake mongrel i18n mysql
 6997  lt
 6998  cd bench/
 6999  lt
 7000  ..
 7001  lt
 7002  ll redmine-2.6.0.zip
 7003  unzip -t redmine-2.6.0.zip
 7004  unzip redmine-2.6.0.zip
 7005  cd redmine-2.6.0/
 7006  ll
 7007  ..
 7008  ll /opt/
 7009  sudo mv redmine-2.6.0 /opt/mine
 7010  mysql
 7011  sudo service mysql restart
 7012  sudo service mysql stop
 7013  sudo apt-get install mysql-server
 7014  sudo apt-get install --reinstall mysql-server
 7015  mysql
 7016  sudo service mysql restart
 7017  eng prox
 7018  cd /var/run
 7019  ll mysqld/
 7020  cd
 7021  sudo grep mysqld /etc/mysql/*cnf
 7022  ll /var/lib/mysql/
 7023  sudo ln -ll /var/lib/mysql/
 7024  sudo ls -ll /var/lib/mysql/
 7025  sudo ls -ll /var/lib/mysql/mysql
 7026  dpkg -S /var/lib/mysql/mysql
 7027  sudo dpkg -S /var/lib/mysql/mysql
 7028*
 7029  sudo dpkg -S /var/lib/mysql
 7030  sudo apt-get autoremove --purge mysql-server-core-5.5
 7031  as akonadi-server
 7032  sudo apt-get install --reinstall mysql-server-core-5.5
 7033  sudo apt-get autoremove --purge
 7034  mysql
 7035  sudo apt-get install --reinstall mysql-server-core-5.5
 7036  sudo apt-get autoremove --purge mysql-server-5
 7037  sudo apt-get autoremove --purge
 7038  sudo apt-get install mysql-server
 7039  mysql
 7040  psg mysql
 7041  sudo ls -ll /var/lib/mysql/mysql
 7042*
 7043  sudo a2enmod
 7047  unset http_proxy
 7048  curl cnbjlx9076
 7049  sudo vi /etc/apache2/conf.d/mediawiki.conf
 7050  diff /etc/apache2/conf.d/mediawiki.conf bench/priv/mediawiki.conf
 7051  ll bench/priv/ | grep conf
 7052  sudo vi /etc/apache2/apache2.conf
 7053  cd /etc/apache2/
 7054  ll
 7055  cd mods-enabled/
 7056  ll
 7057  ll|grep php
 7058  ..
 7059  ll mods-available/
 7060  ll mods-available/|grep php
 7061  as php
 7062  as php|grep mod
 7066  curl cnbjlx9076
 7067  history
usb -v
 6966  lsusb -v|grep -i vendor
 6967  lsusb -v|grep idVendor
 6968  sudo lsusb -v|grep idVendor
 6969  sudo lsusb -v|grep idVendor|column
 6970  sudo lsusb -v|grep idVendor|column -t
 6971  man column
 6972  sudo lsusb -v|grep idVendor|column -c
 6973  sudo lsusb -v|grep idVendor|column -x
 6974  sudo lsusb -v|grep idVendor|column -n
 6975  vi bench/priv/note/adb.mkd
 6976  sudo vi /etc/udev/rules.d/51-android.rules
 6977  cat /etc/udev/rules.d/51-android.rules
 6978  sudo vi /etc/udev/rules.d/51-android.rules
 6979  vi bench/priv/note/adb.mkd
 6980  vi /tmp/bb
 6981  column /tmp/bb
 6982  column -t /tmp/bb
 6983  vi bench/priv/note/adb.mkd
 6984  lt
 6985  cd bench/
 6986  cd priv/
 6987  ll
 6988  vi xxb.mkd
 6989  sudo apt-get install ruby
 6990  sudo apt-get install ruby rubygems
 6991  rails -v
 6992  sudo apt-get install rails
 6993  sudo gem install rack rake mongrel i18n mysql
 6994  sudo apt-get install sudo apt-get install libmysqlclient-dev
 6995  sudo apt-get install libmysqlclient-dev mysql-server
 6996  sudo gem install rack rake mongrel i18n mysql
 6997  lt
 6998  cd bench/
 6999  lt
 7000  ..
 7001  lt
 7002  ll redmine-2.6.0.zip
 7003  unzip -t redmine-2.6.0.zip
 7004  unzip redmine-2.6.0.zip
 7005  cd redmine-2.6.0/
 7006  ll
 7007  ..
 7008  ll /opt/
 7009  sudo mv redmine-2.6.0 /opt/mine
 7010  mysql
 7011  sudo service mysql restart
 7012  sudo service mysql stop
 7013  sudo apt-get install mysql-server
 7014  sudo apt-get install --reinstall mysql-server
 7015  mysql
 7016  sudo service mysql restart
 7017  eng prox
 7018  cd /var/run
 7019  ll mysqld/
 7020  cd
 7021  sudo grep mysqld /etc/mysql/*cnf
 7022  ll /var/lib/mysql/
 7023  sudo ln -ll /var/lib/mysql/
 7024  sudo ls -ll /var/lib/mysql/
 7025  sudo ls -ll /var/lib/mysql/mysql
 7026  dpkg -S /var/lib/mysql/mysql
 7027  sudo dpkg -S /var/lib/mysql/mysql
 7028*
 7029  sudo dpkg -S /var/lib/mysql
 7030  sudo apt-get autoremove --purge mysql-server-core-5.5
 7031  as akonadi-server
 7032  sudo apt-get install --reinstall mysql-server-core-5.5
 7033  sudo apt-get autoremove --purge
 7034  mysql
 7035  sudo apt-get install --reinstall mysql-server-core-5.5
 7036  sudo apt-get autoremove --purge mysql-server-5
 7037  sudo apt-get autoremove --purge
 7038  sudo apt-get install mysql-server
 7039  mysql
 7040  psg mysql
 7041  sudo ls -ll /var/lib/mysql/mysql
 7042*
 7043  sudo a2enmod
 7049  sudo vi /etc/apache2/conf.d/mediawiki.conf
 7050  diff /etc/apache2/conf.d/mediawiki.conf bench/priv/mediawiki.conf
 7051  ll bench/priv/ | grep conf
 7052  sudo vi /etc/apache2/apache2.conf
 7053  cd /etc/apache2/
 7054  ll
 7055  cd mods-enabled/

<?php // PHP必须被包围于 <?php ?> 之中

// 如果你的文件中只有php代码，那么最好省略结束括号标记

// 这是单行注释的标志

# 井号也可以，但是//更常见

/*
     这是多行注释
*/

// 使用 "echo" 或者 "print" 来输出信息到标准输出
print('Hello '); // 输出 "Hello " 并且没有换行符

// () 对于echo和print是可选的
echo "World\n"; // 输出 "World" 并且换行
// (每个语句必须以分号结尾)

// 在 <?php 标签之外的语句都被自动输出到标准输出
?>Hello World Again!
<?php


/************************************
 * 类型与变量
 */

// 变量以$开始
// 变量可以以字母或者下划线开头，后面可以跟着数字、字母和下划线

// 布尔值是大小写无关的
$boolean = true;  // 或 TRUE 或 True
$boolean = false; // 或 FALSE 或 False

// 整型
$int1 = 12;   // => 12
$int2 = -12;  // => -12
$int3 = 012;  // => 10 (0开头代表八进制数)
$int4 = 0x0F; // => 15 (0x开头代表十六进制数)

// 浮点型 (即双精度浮点型)
$float = 1.234;
$float = 1.2e3;
$float = 7E-10;

// 算数运算
$sum        = 1 + 1; // 2
$difference = 2 - 1; // 1
$product    = 2 * 2; // 4
$quotient   = 2 / 1; // 2

// 算数运算的简写
$number = 0;
$number += 1;      // $number 自增1
echo $number++;    // 输出1 (运算后自增)
echo ++$number;    // 输出3 (自增后运算)
$number /= $float; // 先除后赋值给 $number

// 字符串需要被包含在单引号之中
$sgl_quotes = '$String'; // => '$String'

// 如果需要在字符串中引用变量，就需要使用双引号
$dbl_quotes = "This is a $sgl_quotes."; // => 'This is a $String.'

// 特殊字符只有在双引号中有用
$escaped   = "This contains a \t tab character.";
$unescaped = 'This just contains a slash and a t: \t';

// 可以把变量包含在一对大括号中
$money = "I have $${number} in the bank.";

// 自 PHP 5.3 开始, nowdocs 可以被用作多行非计算型字符串
$nowdoc = <<<'END'
Multi line
string
END;

// 而Heredocs则可以用作多行计算型字符串
$heredoc = <<<END
Multi line
$sgl_quotes
END;

// 字符串需要用 . 来连接
echo 'This string ' . 'is concatenated';


/********************************
 * 数组
 */

// PHP 中的数组都是关联型数组，也就是某些语言中的哈希表或字典

// 在所有PHP版本中均适用：
$associative = array('One' => 1, 'Two' => 2, 'Three' => 3);

// PHP 5.4 中引入了新的语法
$associative = ['One' => 1, 'Two' => 2, 'Three' => 3];

echo $associative['One']; // 输出 1

// 声明为列表实际上是给每个值都分配了一个整数键（key）
$array = ['One', 'Two', 'Three'];
echo $array[0]; // => "One"


/********************************
 * 输出
 */

echo('Hello World!');
// 输出到标准输出
// 此时标准输出就是浏览器中的网页

print('Hello World!'); // 和echo相同

// echo和print实际上也属于这个语言本身，所以我们省略括号
echo 'Hello World!';
print 'Hello World!';

$paragraph = 'paragraph';

echo 100;        // 直接输出标量
echo $paragraph; // 或者输出变量

// 如果你配置了短标签，或者使用5.4.0及以上的版本
// 你就可以使用简写的echo语法
?>
<p><?= $paragraph ?></p>
<?php

$x = 1;
$y = 2;
$x = $y; // $x 现在和 $y 的值相同
$z = &$y;
// $z 现在持有 $y 的引用. 现在更改 $z 的值也会更改 $y 的值，反之亦然
// 但是改变 $y 的值不会改变 $x 的值

echo $x; // => 2
echo $z; // => 2
$y = 0;
echo $x; // => 2
echo $z; // => 0


/********************************
 * 逻辑
 */
$a = 0;
$b = '0';
$c = '1';
$d = '1';

// 如果assert的参数为假，就会抛出警告

// 下面的比较都为真，不管它们的类型是否匹配
assert($a == $b); // 相等
assert($c != $a); // 不等
assert($c <> $a); // 另一种不等的表示
assert($a < $c);
assert($c > $b);
assert($a <= $b);
assert($c >= $d);

// 下面的比较只有在类型相同、值相同的情况下才为真
assert($c === $d);
assert($a !== $d);
assert(1 === '1');
assert(1 !== '1');

// 变量可以根据其使用来进行类型转换

$integer = 1;
echo $integer + $integer; // => 2

$string = '1';
echo $string + $string; // => 2 (字符串在此时被转化为整数)

$string = 'one';
echo $string + $string; // => 0
// 输出0，因为'one'这个字符串无法被转换为整数

// 类型转换可以将一个类型视作另一种类型

$boolean = (boolean) 1; // => true

$zero = 0;
$boolean = (boolean) $zero; // => false

// 还有一些专用的函数来进行类型转换
$integer = 5;
$string = strval($integer);

$var = null; // 空值


/********************************
 * 控制结构
 */

if (true) {
    print 'I get printed';
}

if (false) {
    print 'I don\'t';
} else {
    print 'I get printed';
}

if (false) {
    print 'Does not get printed';
} elseif(true) {
    print 'Does';
}

// 三元运算符
print (false ? 'Does not get printed' : 'Does');

$x = 0;
if ($x === '0') {
    print 'Does not print';
} elseif($x == '1') {
    print 'Does not print';
} else {
    print 'Does print';
}



// 下面的语法常用于模板中:
?>

<?php if ($x): ?>
This is displayed if the test is truthy.
<?php else: ?>
This is displayed otherwise.
<?php endif; ?>

<?php

// 用switch来实现相同的逻辑
switch ($x) {
    case '0':
        print 'Switch does type coercion';
        break; // 在case中必须使用一个break语句，
               // 否则在执行完这个语句后会直接执行后面的语句
    case 'two':
    case 'three':
        // 如果$variable是 'two' 或 'three'，执行这里的语句
        break;
    default:
        // 其他情况
}

// While, do...while 和 for 循环
$i = 0;
while ($i < 5) {
    echo $i++;
}; // 输出 "01234"

echo "\n";

$i = 0;
do {
    echo $i++;
} while ($i < 5); // 输出 "01234"

echo "\n";

for ($x = 0; $x < 10; $x++) {
    echo $x;
} // 输出 "0123456789"

echo "\n";

$wheels = ['bicycle' => 2, 'car' => 4];

// Foreach 循环可以遍历数组
foreach ($wheels as $wheel_count) {
    echo $wheel_count;
} // 输出 "24"

echo "\n";

// 也可以同时遍历键和值
foreach ($wheels as $vehicle => $wheel_count) {
    echo "A $vehicle has $wheel_count wheels";
}

echo "\n";

$i = 0;
while ($i < 5) {
    if ($i === 3) {
        break; // 退出循环
    }
    echo $i++;
} // 输出 "012"

for ($i = 0; $i < 5; $i++) {
    if ($i === 3) {
        continue; // 跳过此次遍历
    }
    echo $i;
} // 输出 "0124"


/********************************
 * 函数
 */

// 通过"function"定义函数:
function my_function () {
  return 'Hello';
}

echo my_function(); // => "Hello"

// 函数名需要以字母或者下划线开头,
// 后面可以跟着任意的字母、下划线、数字.

function add ($x, $y = 1) { // $y 是可选参数，默认值为 1
  $result = $x + $y;
  return $result;
}

echo add(4); // => 5
echo add(4, 2); // => 6

// $result 在函数外部不可访问
// print $result; // 抛出警告

// 从 PHP 5.3 起我们可以定义匿名函数
$inc = function ($x) {
  return $x + 1;
};

echo $inc(2); // => 3

function foo ($x, $y, $z) {
  echo "$x - $y - $z";
}

// 函数也可以返回一个函数
function bar ($x, $y) {
  // 用 'use' 将外部的参数引入到里面
  return function ($z) use ($x, $y) {
    foo($x, $y, $z);
  };
}

$bar = bar('A', 'B');
$bar('C'); // 输出 "A - B - C"

// 你也可以通过字符串调用函数
$function_name = 'add';
echo $function_name(1, 2); // => 3
// 在通过程序来决定调用哪个函数时很有用
// 或者，使用 call_user_func(callable $callback [, $parameter [, ... ]]);

/********************************
 * 文件包含
 */

<?php
// 被包含的php文件也必须以php开标签开始

include 'my-file.php';
// 现在my-file.php就在当前作用域中可见了
// 如果这个文件无法被包含（比如文件不存在），会抛出警告

include_once 'my-file.php';
// my-file.php中的代码在其他地方被包含了，那么就不会被再次包含
// 这会避免类的多重定义错误

require 'my-file.php';
require_once 'my-file.php';
// 和include功能相同，只不过如果不能被包含时，会抛出错误

// my-include.php的内容:
<?php

return 'Anything you like.';
// 文件结束

// Include和Require函数也有返回值
$value = include 'my-include.php';

// 被引入的文件是根据文件路径或者include_path配置来查找到的
// 如果文件最终没有被找到，那么就会查找当前文件夹。之后才会报错
/* */

/********************************
 * 类
 */

// 类是由class关键字定义的

class MyClass
{
    const MY_CONST      = 'value'; // 常量

    static $staticVar   = 'static';

    // 属性必须声明其作用域
    public $property    = 'public';
    public $instanceProp;
    protected $prot = 'protected'; // 当前类和子类可访问
    private $priv   = 'private';   // 仅当前类可访问

    // 通过 __construct 来定义构造函数
    public function __construct($instanceProp) {
        // 通过 $this 访问当前对象
        $this->instanceProp = $instanceProp;
    }

    // 方法就是类中定义的函数
    public function myMethod()
    {
        print 'MyClass';
    }

    final function youCannotOverrideMe()
    {
    }

    public static function myStaticMethod()
    {
        print 'I am static';
    }
}

echo MyClass::MY_CONST;    // 输出 'value';
echo MyClass::$staticVar;  // 输出 'static';
MyClass::myStaticMethod(); // 输出 'I am static';

// 通过new来新建实例
$my_class = new MyClass('An instance property');
// 如果不传递参数，那么括号可以省略

// 用 -> 来访问成员
echo $my_class->property;     // => "public"
echo $my_class->instanceProp; // => "An instance property"
$my_class->myMethod();        // => "MyClass"


// 使用extends来生成子类
class MyOtherClass extends MyClass
{
    function printProtectedProperty()
    {
        echo $this->prot;
    }

    // 方法覆盖
    function myMethod()
    {
        parent::myMethod();
        print ' > MyOtherClass';
    }
}

$my_other_class = new MyOtherClass('Instance prop');
$my_other_class->printProtectedProperty(); // => 输出 "protected"
$my_other_class->myMethod();               // 输出 "MyClass > MyOtherClass"

final class YouCannotExtendMe
{
}

// 你可以使用“魔术方法”来生成getter和setter方法
class MyMapClass
{
    private $property;

    public function __get($key)
    {
        return $this->$key;
    }

    public function __set($key, $value)
    {
        $this->$key = $value;
    }
}

$x = new MyMapClass();
echo $x->property; // 会使用 __get() 方法
$x->property = 'Something'; // 会使用 __set() 方法

// 类可以是被定义成抽象类 (使用 abstract 关键字) 或者
// 去实现接口 (使用 implements 关键字).
// 接口需要通过interface关键字来定义

interface InterfaceOne
{
    public function doSomething();
}

interface InterfaceTwo
{
    public function doSomethingElse();
}

// 接口可以被扩展
interface InterfaceThree extends InterfaceTwo
{
    public function doAnotherContract();
}

abstract class MyAbstractClass implements InterfaceOne
{
    public $x = 'doSomething';
}

class MyConcreteClass extends MyAbstractClass implements InterfaceTwo
{
    public function doSomething()
    {
        echo $x;
    }

    public function doSomethingElse()
    {
        echo 'doSomethingElse';
    }
}


// 一个类可以实现多个接口
class SomeOtherClass implements InterfaceOne, InterfaceTwo
{
    public function doSomething()
    {
        echo 'doSomething';
    }

    public function doSomethingElse()
    {
        echo 'doSomethingElse';
    }
}


/********************************
 * 特征
 */

// 特征 从 PHP 5.4.0 开始包括，需要用 "trait" 这个关键字声明

trait MyTrait
{
    public function myTraitMethod()
    {
        print 'I have MyTrait';
    }
}

class MyTraitfulClass
{
    use MyTrait;
}

$cls = new MyTraitfulClass();
$cls->myTraitMethod(); // 输出 "I have MyTrait"


/********************************
 * 命名空间
 */

// 这部分是独立于这个文件的
// 因为命名空间必须在一个文件的开始处。

<?php

// 类会被默认的放在全局命名空间中，可以被一个\来显式调用

$cls = new \MyClass();



// 为一个文件设置一个命名空间
namespace My\Namespace;

class MyClass
{
}

// (或者从其他文件中)
$cls = new My\Namespace\MyClass;

//或者从其他命名空间中
namespace My\Other\Namespace;

use My\Namespace\MyClass;

$cls = new MyClass();

// 你也可以为命名空间起一个别名

namespace My\Other\Namespace;

use My\Namespace as SomeOtherNamespace;

$cls = new SomeOtherNamespace\MyClass();

*/
