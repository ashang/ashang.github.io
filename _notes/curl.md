---
title: curl
date: 2021-04-22
---

curl -H 'Accept: text/plain' http://godoc.org/?q=sql

curl -sSf

curl -# -C - -f -O

(uname -s; uname -m; uname -r; uname -v) | \
curl https://api-ksplice.oracle.com/api/1/update-list/ \
-L -H "Accept: text/text" --data-binary @-


curl (7.32.0-1) unstable; urgency=low

  From this version the threaded DNS resolver will be used. This allows for
  asynchronous DNS queries and also fixes possible issues related to handling
  time outs of DNS lookups.

  The threaded resolver was chosen instead of the event-based one (which uses
  the c-ares library) because c-ares currently lacks somewhat important
  features, such as support for the Name Service Switch system.

$ curl -I localhost
HTTP/1.1 302 Found
Date: Fri, 03 Jul 2015 01:48:39 GMT
Server: Apache
x-rack-cache: miss
cache-control: no-cache
x-ua-compatible: IE=Edge,chrome=1
x-runtime: 0.010485
x-request-id: f11775d32b085917f47372b0be88fa42
Connection: close
X-Powered-By: Phusion Passenger 5.0.4
X-Frame-Options: SAMEORIGIN
location: http://localhost/login?back_url=http%3A%2F%2Flocalhost%2F
Status: 302 Found
Content-Type: text/html; charset=utf-8


$ curl -I 203.100.82.236
HTTP/1.1 503 Service Unavailable
Cache-Control: no-cache
Pragma: no-cache
Content-Type: text/html; charset=utf-8
Proxy-Connection: Keep-Alive
Connection: Keep-Alive
Content-Length: 778




(uname -s; uname -m; uname -r; uname -v) | \
curl https://api-ksplice.oracle.com/api/1/update-list/ \
-L -H "Accept: text/text" --data-binary @-


curl (7.32.0-1) unstable; urgency=low

  From this version the threaded DNS resolver will be used. This allows for
  asynchronous DNS queries and also fixes possible issues related to handling
  time outs of DNS lookups.

  The threaded resolver was chosen instead of the event-based one (which uses
  the c-ares library) because c-ares currently lacks somewhat important
  features, such as support for the Name Service Switch system.

```
$ curl -I git
HTTP/1.1 200 OK
Date: Wed, 24 May 2017 13:04:19 GMT
Server: Httpd
Cache-control: no-cache="set-cookie"
Content-type: text/html; charset=UTF-8
ETag: "90e-2888-56726263"
Content-length: 9094
Connection: close
Set-Cookie: _WebSessionId_=95b2387921278ff58e65053c2014b722; path=/;



curl -I http://www.frob.com/~roland/
HTTP/1.1 200 OK
Date: Fri, 29 Sep 2017 09:22:01 GMT
Server: Apache/2.2.15 (CentOS)
Last-Modified: Sun, 04 Jan 1998 01:18:16 GMT
ETag: "2a2583-f7c-323e1947d8600"
Accept-Ranges: bytes
Content-Length: 3964
Connection: close
Content-Type: text/html; charset=UTF-8

$ curl -I git:55555
HTTP/1.1 302 Found
Server: nginx
Date: Wed, 24 May 2017 05:12:28 GMT
Content-Type: text/html; charset=utf-8
Connection: keep-alive
Cache-Control: no-cache
Location: http://code
X-Content-Type-Options: nosniff
X-Frame-Options: DENY
X-Request-Id: 7117aed1-0bdc-4fa1-8ffc-f5d7cf2c3e9e
X-Runtime: 0.031390
X-Ua-Compatible: IE=edge
X-Xss-Protection: 1; mode=block
Strict-Transport-Security: max-age=31536000

HTTP/1.1 302 Found
Server: nginx
Date: Wed, 24 May 2017 05:12:28 GMT
Content-Type: text/html; charset=utf-8
Connection: keep-alive
Cache-Control: no-cache
Location: http://code/users/sign_in
Set-Cookie: _gitlab_session=34303e41cc65e4000f3714215c343a7f; path=/; HttpOnly
X-Content-Type-Options: nosniff
X-Frame-Options: SAMEORIGIN
X-Request-Id: ead746cb-4d6e-4158-bd2c-f4feff694b65
X-Runtime: 0.037874
X-Xss-Protection: 1; mode=block
Strict-Transport-Security: max-age=31536000

HTTP/1.1 200 OK
Server: nginx
Date: Wed, 24 May 2017 05:12:28 GMT
Content-Type: text/html; charset=utf-8
Connection: keep-alive
Cache-Control: max-age=0, private, must-revalidate
Etag: W/"4a91c6d242d0cb6a61847955ccab2c02"
Set-Cookie: _gitlab_session=71b3979aa05bbbc558e845e90fc147ef; path=/; HttpOnly
X-Content-Type-Options: nosniff
X-Frame-Options: DENY
X-Request-Id: a4bbb3fe-0798-40a3-9350-f5d22508a2c4
X-Runtime: 0.125638
X-Ua-Compatible: IE=edge
X-Xss-Protection: 1; mode=block
Strict-Transport-Security: max-age=31536000


$ curl -I localhost
HTTP/1.1 302 Found
Date: Fri, 03 Jul 2015 01:48:39 GMT
Server: Apache
x-rack-cache: miss
cache-control: no-cache
x-ua-compatible: IE=Edge,chrome=1
x-runtime: 0.010485
x-request-id: f11775d32b085917f47372b0be88fa42
Connection: close
X-Powered-By: Phusion Passenger 5.0.4
X-Frame-Options: SAMEORIGIN
location: http://localhost/login?back_url=http%3A%2F%2Flocalhost%2F
Status: 302 Found
Content-Type: text/html; charset=utf-8


$ curl -I 203.100.82.236
HTTP/1.1 503 Service Unavailable
Cache-Control: no-cache
Pragma: no-cache
Content-Type: text/html; charset=utf-8
Proxy-Connection: Keep-Alive
Connection: Keep-Alive
Content-Length: 778


```


curl -fLo /home/as/.config/nvim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
If you're behind an HTTP proxy, you may need to add --insecure option to the curl command. In that case, you also need to set  to true.




# make

```
  curl version:     7.47.0
  Host setup:       x86_64-pc-linux-gnu
  Install prefix:   /usr/local
  Compiler:         gcc
  SSL support:      enabled (OpenSSL)
  SSH support:      no      (--with-libssh2)
  zlib support:     enabled
  GSS-API support:  no      (--with-gssapi)
  TLS-SRP support:  enabled
  resolver:         default (--enable-ares / --enable-threaded-resolver)
  IPv6 support:     enabled
  Unix sockets support: enabled
  IDN support:      enabled
  Build libcurl:    Shared=yes, Static=yes
  Built-in manual:  enabled
  --libcurl option: enabled (--disable-libcurl-option)
  Verbose errors:   enabled (--disable-verbose)
  SSPI support:     no      (--enable-sspi)
  ca cert bundle:   /etc/ssl/certs/ca-certificates.crt
  ca cert path:     no
  LDAP support:     enabled (OpenLDAP)
  LDAPS support:    enabled
  RTSP support:     enabled
  RTMP support:     no      (--with-librtmp)
  metalink support: no      (--with-libmetalink)
  PSL support:      no      (libpsl not found)
  HTTP2 support:    disabled (--with-nghttp2)
  Protocols:        DICT FILE FTP FTPS GOPHER HTTP HTTPS IMAP IMAPS LDAP LDAPS POP3 POP3S RTSP SMB SMBS SMTP SMTPS TELNET TFTP

```
```
$ curl -I http://dev/notes
HTTP/1.1 301 Moved Permanently
Date: Tue, 23 May 2017 11:07:53 GMT
Server: Apache/2.4.18 (Ubuntu) PHP/5.4.45 OpenSSL/1.0.2g mod_wsgi/4.3.0 Python/2.7.12+ mod_perl/2.0.9 Perl/v5.22.2
Location: http://dev/notes/
Content-Type: text/html; charset=iso-8859-1

HTTP/1.1 200 OK
Date: Tue, 23 May 2017 11:07:53 GMT
Server: Apache/2.4.18 (Ubuntu) PHP/5.4.45 OpenSSL/1.0.2g mod_wsgi/4.3.0 Python/2.7.12+ mod_perl/2.0.9 Perl/v5.22.2
X-Powered-By: PHP/5.4.45
X-Content-Type-Options: nosniff
X-Frame-Options: sameorigin
Content-Type: text/html
```

```
$ curl -I http://dev/bugs
HTTP/1.1 301 Moved Permanently
Date: Tue, 23 May 2017 11:08:06 GMT
Server: Apache/2.4.18 (Ubuntu) PHP/5.4.45 OpenSSL/1.0.2g mod_wsgi/4.3.0 Python/2.7.12+ mod_perl/2.0.9 Perl/v5.22.2
Location: http://dev/bugs/
Content-Type: text/html; charset=iso-8859-1

HTTP/1.1 200 OK
Date: Tue, 23 May 2017 11:08:06 GMT
Server: Apache/2.4.18 (Ubuntu) PHP/5.4.45 OpenSSL/1.0.2g mod_wsgi/4.3.0 Python/2.7.12+ mod_perl/2.0.9 Perl/v5.22.2
Content-security-policy: default-src 'self'; script-src 'self' 'unsafe-inline' 'unsafe-eval'; style-src 'self' 'unsafe-inline'
X-content-security-policy: default-src 'self'; script-src 'self' 'unsafe-inline' 'unsafe-eval'; style-src 'self' 'unsafe-inline'
X-content-type-options: nosniff
X-frame-options: SAMEORIGIN
X-webkit-csp: default-src 'self'; script-src 'self' 'unsafe-inline' 'unsafe-eval'; style-src 'self' 'unsafe-inline'
X-xss-protection: 1; mode=block
Set-Cookie: Bugzilla_login_request_cookie=jvleqicLgi; domain=dev; path=/bugs/; HttpOnly
X-Content-Type-Options: nosniff
X-Frame-Options: sameorigin
Content-Type: text/html; charset=UTF-8
```


```
$ curl -I http://dev/cloud
HTTP/1.1 301 Moved Permanently
Date: Tue, 23 May 2017 11:09:17 GMT
Server: Apache/2.4.18 (Ubuntu) PHP/5.4.45 OpenSSL/1.0.2g mod_wsgi/4.3.0 Python/2.7.12+ mod_perl/2.0.9 Perl/v5.22.2
Location: http://dev/cloud/
Content-Type: text/html; charset=iso-8859-1

HTTP/1.1 503 Service Unavailable
Date: Tue, 23 May 2017 11:09:17 GMT
Server: Apache/2.4.18 (Ubuntu) PHP/5.4.45 OpenSSL/1.0.2g mod_wsgi/4.3.0 Python/2.7.12+ mod_perl/2.0.9 Perl/v5.22.2
X-Powered-By: PHP/5.4.45
Set-Cookie: ock4r7zs06g4=d0301b8e6c1452e733e574db5ac273c9; path=/cloud; HttpOnly
Expires: Thu, 19 Nov 1981 08:52:00 GMT
Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0
Pragma: no-cache
Set-Cookie: oc_sessionPassphrase=RG5%2Fm5V1fU2sGy9KEjKWMWBdhCWycK8SEl8vDfN4HJPi1pYMgqoDrq9g9lw4%2Bp10az7%2BCt0sK339sTGuTuRHXbYsjDyQ39AjopbAqaVk0H%2BBJ18O70GPBm%2FIxSpN3ujy; path=/cloud; httponly
Content-Security-Policy: default-src 'self'; script-src 'self' 'unsafe-eval'; style-src 'self' 'unsafe-inline'; frame-src *; img-src * data: blob:; font-src 'self' data:; media-src *; connect-src *
Set-Cookie: nc_sameSiteCookielax=true; path=/cloud; httponly;expires=Fri, 31-Dec-2100 23:59:59 GMT; SameSite=lax
Set-Cookie: nc_sameSiteCookiestrict=true; path=/cloud; httponly;expires=Fri, 31-Dec-2100 23:59:59 GMT; SameSite=strict
X-Content-Type-Options: nosniff
X-Frame-Options: SAMEORIGIN
X-XSS-Protection: 1; mode=block
X-Robots-Tag: none
X-Download-Options: noopen
X-Permitted-Cross-Domain-Policies: none
Connection: close
Content-Type: text/html; charset=UTF-8
```

## curl vs. wget

$ wget 'https://github-production-release-asset-2e65be.s3.amazonaws.com/45055693/4f5bd210-493f-11e8-9d67-d4a7ed067d4e?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWNJYAX4CSVEH53A%2F20180802%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20180802T152154Z&X-Amz-Expires=300&X-Amz-Signature=3a49b1fc8060ea0e876e083c7d5623829f98ebbcb8d08fa610a56d35660ad49f&X-Amz-SignedHeaders=host&actor_id=0&response-content-disposition=attachment%3B%20filename%3Detcher-electron-1.4.4-linux-x64.zip&response-content-type=application%2Foctet-stream'
--2018-08-02 23:25:21--  https://github-production-release-asset-2e65be.s3.amazonaws.com/45055693/4f5bd210-493f-11e8-9d67-d4a7ed067d4e?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWNJYAX4CSVEH53A%2F20180802%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20180802T152154Z&X-Amz-Expires=300&X-Amz-Signature=3a49b1fc8060ea0e876e083c7d5623829f98ebbcb8d08fa610a56d35660ad49f&X-Amz-SignedHeaders=host&actor_id=0&response-content-disposition=attachment%3B%20filename%3Detcher-electron-1.4.4-linux-x64.zip&response-content-type=application%2Foctet-stream
Resolving github-production-release-asset-2e65be.s3.amazonaws.com (github-production-release-asset-2e65be.s3.amazonaws.com)... 54.231.82.138
Connecting to github-production-release-asset-2e65be.s3.amazonaws.com (github-production-release-asset-2e65be.s3.amazonaws.com)|54.231.82.138|:443...

$ wget https://github.com/resin-io/etcher/releases/download/v1.4.4/etcher-electron-1.4.4-linux-x64.zip
--2018-08-02 23:26:08--  https://github.com/resin-io/etcher/releases/download/v1.4.4/etcher-electron-1.4.4-linux-x64.zip
Resolving github.com (github.com)... 13.229.188.59, 13.250.177.223, 52.74.223.119
Connecting to github.com (github.com)|13.229.188.59|:443... connected.
HTTP request sent, awaiting response... 302 Found
Location: https://github-production-release-asset-2e65be.s3.amazonaws.com/45055693/4f5bd210-493f-11e8-9d67-d4a7ed067d4e?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWNJYAX4CSVEH53A%2F20180802%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20180802T152613Z&X-Amz-Expires=300&X-Amz-Signature=72daf80e921bd157bec5fd8373f849eed41c95ebf8046852c82296a812f00c97&X-Amz-SignedHeaders=host&actor_id=0&response-content-disposition=attachment%3B%20filename%3Detcher-electron-1.4.4-linux-x64.zip&response-content-type=application%2Foctet-stream [following]
--2018-08-02 23:26:14--  https://github-production-release-asset-2e65be.s3.amazonaws.com/45055693/4f5bd210-493f-11e8-9d67-d4a7ed067d4e?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWNJYAX4CSVEH53A%2F20180802%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20180802T152613Z&X-Amz-Expires=300&X-Amz-Signature=72daf80e921bd157bec5fd8373f849eed41c95ebf8046852c82296a812f00c97&X-Amz-SignedHeaders=host&actor_id=0&response-content-disposition=attachment%3B%20filename%3Detcher-electron-1.4.4-linux-x64.zip&response-content-type=application%2Foctet-stream
Resolving github-production-release-asset-2e65be.s3.amazonaws.com (github-production-release-asset-2e65be.s3.amazonaws.com)... 54.231.121.75
Connecting to github-production-release-asset-2e65be.s3.amazonaws.com (github-production-release-asset-2e65be.s3.amazonaws.com)|54.231.121.75|:443... connected.
HTTP request sent, awaiting response... 403 Forbidden
The name is too long, 454 chars total.
Trying to shorten...
New name is 4f5bd210-493f-11e8-9d67-d4a7ed067d4e?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWNJYAX4CSVEH53A%2F20180802%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20180802T152613Z&X-Amz-Expires=300&X-Amz-Signature=72daf80e921bd157bec5fd8.
2018-08-02 23:26:15 ERROR 403: Forbidden.

alias wget='wget -U User-Agent -c --content-disposition'

$ curl -O https://github.com/resin-io/etcher/releases/download/v1.4.4/etcher-electron-1.4.4-linux-x64.zip
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100   625    0   625    0     0    264      0 --:--:--  0:00:02 --:--:--   264
  1 80.3M    1  866k    0     0   9239      0  2:32:02  0:01:36  2:30:26  3570

alias curl='curl -L -C -'

> -f, --fail
>        (HTTP)  Fail  silently (no output at all) on server errors. This is mostly done to better
>        enable scripts etc to better deal with failed attempts. In  normal  cases  when  an  HTTP
>        server  fails  to deliver a document, it returns an HTML document stating so (which often
>        also describes why and more). This flag will prevent curl from outputting that and return
>        error 22.
>
>        This  method is not fail-safe and there are occasions where non-successful response codes
>        will slip through, especially when authentication is involved  (response  codes  401  and
>        407).

