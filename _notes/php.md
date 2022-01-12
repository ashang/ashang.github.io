---
title: php notes
weight: 2
date: 2016-11-18
update: 2021-21-11 13:00:00 CST
tags:
- php-fpm
- spawn-fcgi
---

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
