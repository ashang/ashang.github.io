---
date: 2018-09-12
update: 2016-11-11 11:00:00 CST
---

```
while true; do nc -l -p 80 < index.html; done
```

```
ruby -e "require 'sinatra' "
```

monkey

```
alias webserver="ruby -rwebrick -e\"s = WEBrick::HTTPServer.new(:Port => 8888, :DocumentRoot => Dir.pwd); trap('INT') { s.shutdown }; s.start\""
```

## Webserver in bash

And not using perl or any of that fancy stuff. It's the inane things that keep me awake at night.

Getting nc to behave turned out to be the most difficult part. It won't exit until both ends of the connection are closed. Correction, making blogger not mangle this code was the most difficult part.

```shell
#!/bin/bash
# web.sh -- http://localhost:9000/hello?world

RESP=/tmp/webresp
[ -p $RESP ] || mkfifo $RESP

while true ; do
( cat $RESP ) | nc -l -p 9000 | (
REQ=`while read L && [ " " "<" "$L" ] ; do echo "$L" ; done`
echo "[`date '+%Y-%m-%d %H:%M:%S'`] $REQ" | head -1
cat >$RESP <<EOF
HTTP/1.0 200 OK
Cache-Control: private
Content-Type: text/plain
Server: bash/2.0
Connection: Close
Content-Length: ${#REQ}

$REQ
EOF
)
done
```

Update: Fixed script so that it also work in Linux, where tr lacks the -u option.

