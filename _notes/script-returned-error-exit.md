---
date: 2018-03-22
title: script returned error exit
---

dpkg error:

/var/lib/dpkg/info/XXX.postrm: 24: update-inetd: not found
dpkg: warning - old post-removal script returned error exit status 127
dpkg - trying script from the new package instead ...
/var/lib/dpkg/[tmp.ci/postrm](http://tmp.ci/postrm): /var/lib/dpkg/[tmp.ci/postrm](http://tmp.ci/postrm): 24: update-inetd: not found
dpkg: error processing /var/cache/apt/archives/XXX.deb (--unpack):
subprocess new post-removal script returned error exit status 127
/var/lib/dpkg/[tmp.ci/postrm](http://tmp.ci/postrm): /var/lib/dpkg/[tmp.ci/postrm](http://tmp.ci/postrm): 24: update-inetd: not found
dpkg: error while cleaning up:
subprocess post-removal script returned error exit status 127
Errors were encountered while processing:
/var/cache/apt/archives/XXX.deb
E: Sub-process /usr/bin/dpkg returned an error code (1)

A dirty workaround for such cases to let return true:

cd /usr/sbin
mv update-inetd update-inetd.save
ln -s /bin/true update-inetd
