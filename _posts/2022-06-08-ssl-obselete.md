---
title: SSL updates
layout: post
---

Issues happen in Debian Jessie.

```log
$ git clone https://git.lighttpd.net/lighttpd/lighttpd1.4.git
Cloning into 'lighttpd1.4'...
error: gnutls_handshake() failed: A TLS packet with unexpected length was received. while
accessing https://git.lighttpd.net/lighttpd/lighttpd1.4.git/info/refs
fatal: HTTP request failed

$ curl -O https://download.lighttpd.net/lighttpd/releases-1.4.x/lighttpd-1.4.65.tar.gz
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0
  curl: (60) SSL certificate problem: certificate has expired
More details here: http://curl.haxx.se/docs/sslcerts.html

curl performs SSL certificate verification by default, using a "bundle"
 of Certificate Authority (CA) public keys (CA certs). If the default
 bundle file isn't adequate, you can specify an alternate file
 using the --cacert option.
If this HTTPS server uses a certificate signed by a CA represented in
 the bundle, the certificate verification probably failed due to a
 problem with the certificate (it might be expired, or the name might
 not match the domain name in the URL).
If you'd like to turn off curl's verification of the certificate, use
 the -k (or --insecure) option.
```

Debian bullseye has no such issues.