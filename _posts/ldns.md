---
layout: page
title: ldns
date: 2018-06-01
---

## drill

drill is a tool like dig from BIND Utilities designed to get all sorts of information out of the DNS.

ldns-config

shows compiler and linker flags for ldns usage

REQUIREMENTS
- OpenSSL (Optional, but needed for features like DNSSEC)
  - OpenSSL >= 0.9.7f for DANE support
  - OpenSSL >= 1.0.0  for ECDSA and GOST support
- libpcap (Optional, but needed for examples/ldns-dpa)

./configure --with-examples --with-drill
   (optionally compile python bindings too with: --with-pyldns)

* Building from repository

If you are building from the repository you will need to have (gnu)
autotools like libtool and autoreconf installed. A list of all the commands
needed to build everything can be found in README.git.

* pyldns
Compiling pyldns produces many ``unused parameter'' warnings.  Those are
harmless and may safely be ignored.
Also, when building with SWIG older than 2.0.4, compiling
pyldns produces many ``missing initializer'' warnings. Those are harmless
too.

- TSIG support
- DNSSEC support; signing and verification

