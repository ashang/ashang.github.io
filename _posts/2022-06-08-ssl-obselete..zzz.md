---
title: SSL updates
layout: post
---

Issues happen in Debian Jessie.

```sh
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

## SSL_ERROR_UNSUPPORTED_VERSION

Since Firefox version 78, the minimum TLS version allowed by default is TLS 1.2. Websites that don't support TLS version 1.2 or higher will display a Secure Connection Failed error page with Error code: SSL_ERROR_UNSUPPORTED_VERSION.

> Secure Connection Failed
>
> An error occurred during a connection to 10.10.61.1:8080. Peer using unsupported version of security protocol.
>
> Error code: SSL_ERROR_UNSUPPORTED_VERSION
>
>     The page you are trying to view cannot be shown because the authenticity of the received data could not be verified.
>     Please contact the website owners to inform them of this problem.
>
> This website might not support the TLS 1.2 protocol, which is the minimum version supported by Firefox.

Note: The option to enable TLS 1.0 and 1.1 has been removed from the error page in Firefox version 97.





TLS 1.2 was published ten years ago to address weaknesses in TLS 1.0 and 1.1 and has enjoyed wide adoption since then. These old versions of TLS rely on MD5 and SHA-1, both now broken, and contain other flaws. TLS 1.0 is no longer PCI-DSS compliant and the TLS working group has adopted a document to deprecate TLS 1.0 and TLS 1.1.
Documentation

    https://security.googleblog.com/2018/10/modernizing-transport-security.html
        https://blog.chromium.org/2019/10/chrome-ui-for-deprecating-legacy-tls.html



https://datatracker.ietf.org/doc/html/rfc8996


security.tls.version.min


## SSH

$ \ssh hillstone@10.10.61.1 -p 8082
Unable to negotiate with 10.10.61.1 port 8082: no matching host key type found. Their offer: ssh-rsa,ssh-dss


## SSL_ERROR_NO_CYPHER_OVERLAP

## SSL_ERROR_RX_RECORD_TOO_LONG

## Modern TLS

        An ECDHE- and AEAD-based cipher suite. AEAD-based cipher suites are those using AES-GCM or ChaCha20-Poly1305. ECDHE_RSA_WITH_AES_128_GCM_SHA256 is the recommended option for most sites.
            The server signature should use SHA-2. Note this is not the signature in the certificate, made by the CA. Rather, it is the signature made by the server itself, using its private key.

            The older options—CBC-mode cipher suites, RSA-encryption key exchange, and SHA-1 online signatures—all have known cryptographic flaws. Each has been removed in the newly-published TLS 1.3,


