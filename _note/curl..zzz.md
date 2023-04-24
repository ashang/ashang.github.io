---
title: curl
tags: curl
date: 2020-03-09
---

curl -sSf

curl -# -C - -f -O



```sh
$ curl -O https://mirrors/debian/pool/main/g/gdb/gdb_10.1-1.7_armel.deb
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:--  0:00:15 --:--:--     0
curl: (60) SSL certificate problem: certificate is not yet valid
More details here: https://curl.se/docs/sslcerts.html

curl failed to verify the legitimacy of the server and therefore could not
establish a secure connection to it. To learn more about this situation and
how to fix it, please visit the web page mentioned above.
```

SSL is the old name. It is called TLS these days.

$ curl -V
curl 7.74.0 (arm-unknown-linux-gnueabi) libcurl/7.74.0 OpenSSL/1.1.1n zlib/1.2.11 brotli/1.0.9 libidn2/2.3.0 libpsl/0.21.0 (+libidn2/2.3.0) libssh2/1.9.0 nghttp2/1.43.0 librtmp/2.3
Release-Date: 2020-12-09
Protocols: dict file ftp ftps gopher http https imap imaps ldap ldaps mqtt pop3 pop3s rtmp rtsp scp sftp smb smbs smtp smtps telnet tftp
Features: alt-svc AsynchDNS brotli GSS-API HTTP2 HTTPS-proxy IDN IPv6 Kerberos Largefile libz NTLM NTLM_WB PSL SPNEGO SSL TLS-SRP UnixSockets


$ curl --etag-compare etag.txt --etag-save etag.txt --remote-name https://curl.se/ca/cacert.pem






##

+ /usr/bin/curl -L -q --retry 5 --retry-delay 10 --retry-max-time 60 -x '' -R -H 'Cache-Control: no-cache' -o /tmp/tmp.pNxRLtYRyD/v2ray-linux-64.zip https://github.com/v2fly/v2ray-core/releases/download/v5.1.0/v2ray-linux-64.zip


# [cURL](https://curl.haxx.se/)

A command line tool and library for transferring data with URLs.

下载文件，内容输出到屏幕

```
curl www.example.com
```

下载文件，内容输出到文件

```
curl -o example.html www.example.com
```

下载文件，内容输出到文件，使用原来的文件名，J 表示使用 Content-Disposition 给的文件名

```
curl -O www.example.com/file.html
curl -OJ www.example.com/file.html
```

自动访问重定向后的地址

```
curl -L www.example.com/file.html
```

断点续传

```
curl -L -O -C - FILE_URL
```

匹配和下载多个地址的文件，[]指定范围，{}指定列表，可组合起来使用

```
curl -O -O http://example.com/{web,mail}-log[0-6].txt
```

下载文件，使用 SOCKS5 代理

```
curl --socks5 127.0.0.1:1080 -O www.example.com/file.html
```

输出响应消息的状态行、消息报头、空行和响应正文

```
curl -i http://httpbin.org/get
```

输出请求消息报头，响应消息的状态行、消息报头、空行和响应正文

```
curl -v http://httpbin.org/get
```

设置请求消息报头

```
curl -i --url http://httpbin.org/get --header "Apikey: ENTER_KEY_HERE"
```

使用 POST 方法

```
curl -i -X POST --url http://httpbin.org/post --data 'name=value'
```

发送 JSON 请求

```
curl -i -X POST \
  --url http://httpbin.org/post \
  --header "Content-Type: application/json" \
  --data '{"key1":"value1", "key2":"value2"}'
```

读取并发送文件内容

```
curl --data-binary @file.txt https://paste.rs/
```

提交表单(multipart formpost)

```
curl -F person=anonymous -F secret=@file.txt http://example.com/submit.cgi
```

记录和发送 cookie

```
curl -c cookies.txt https://paste.rs/
```

统计用时

```
curl -o /dev/null -s -w 'Establish Connection: %{time_connect}s\nTTFB: %{time_starttransfer}s\nTotal: %{time_total}s\n'  https://www.google.com
```

查询自己的 IP 地址

```
curl https://api.myip.com
wget -qO- https://api.myip.com
```

在控制台阅读技术文档

```
curl cheat.sh
curl cheat.sh/lua/:learn | less -R
```
## Options

### Options

```bash
-o <file>    # --output: write to file
-u user:pass # --user: Authentication
```

```bash
-v           # --verbose
-vv          # Even more verbose
-s           # --silent: don't show progress meter or errors
-S           # --show-error: when used with --silent (-sS), show errors but no progress meter
```

```bash
-i           # --include: Include the HTTP-header in the output
-I           # --head: headers only
```

### Request

```bash
-X POST          # --request
-L               # follow link if page redirects
-F               # --form: HTTP POST data for multipart/form-data
```

### Data

```bash
-d 'data'    # --data: HTTP post data, URL encoded (eg, status="Hello")
-d @file     # --data via file
-G           # --get: send -d data via get
```

### Headers

```bash
-A <str>         # --user-agent
-b name=val      # --cookie
-b FILE          # --cookie
-H "X-Foo: y"    # --header
--compressed     # use deflate/gzip
```

### SSL

```bash
    --cacert <file>
    --capath <dir>
```

```bash
-E, --cert <cert>     # --cert: Client cert file
    --cert-type       # der/pem/eng
-k, --insecure        # for self-signed certs
```

## Examples
{: .-one-column}

```bash
# Post data:
curl -d password=x http://x.com/y
```

```bash
# Auth/data:
curl -u user:pass -d status="Hello" http://twitter.com/statuses/update.xml
```

```bash
# multipart file upload
curl -v -include --form key1=value1 --form upload=@localfilename URL

# multipart form: send data from text field and upload file
curl -F person=anonymous -F secret=@file.txt http://example.com/submit.cgi
```

```bash
# Use Curl to Check if a remote resource is available
# details: https://matthewsetter.com/check-if-file-is-available-with-curl/
curl -o /dev/null --silent -Iw "%{http_code}" https://example.com/my.remote.tarball.gz
```

```sh
$ curl -O https://events.prace-ri.eu/event/549/sessions/1683/attachments/473/686/JAN-MEINKE-GPU-CUDATools.pdf
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0
curl: (60) SSL certificate problem: unable to get local issuer certificate
More details here: https://curl.se/docs/sslcerts.html

curl failed to verify the legitimacy of the server and therefore could not
establish a secure connection to it. To learn more about this situation and
how to fix it, please visit the web page mentioned above.

$ wget https://events.prace-ri.eu/event/549/sessions/1683/attachments/473/686/JAN-MEINKE-GPU-CUDATools.pdf
--2022-08-15 14:28:15--  https://events.prace-ri.eu/event/549/sessions/1683/attachments/473/686/JAN-MEINKE-GPU-CUDATools.pdf
Resolving events.prace-ri.eu (events.prace-ri.eu)... 193.224.0.105, 2001:738:0:51b:f816:3eff:feef:d13
Connecting to events.prace-ri.eu (events.prace-ri.eu)|193.224.0.105|:443... connected.
ERROR: cannot verify events.prace-ri.eu's certificate, issued by ‘CN=DigiCert TLS RSA SHA256 2020 CA1,O=DigiCert Inc,C=US’:
  Unable to locally verify the issuer's authority.
To connect to events.prace-ri.eu insecurely, use `--no-check-certificate'.

$ wget --no-check-certificate https://events.prace-ri.eu/event/549/sessions/1683/attachments/473/686/JAN-MEINKE-GPU-CUDATools.pdf
--2022-08-15 14:28:25--  https://events.prace-ri.eu/event/549/sessions/1683/attachments/473/686/JAN-MEINKE-GPU-CUDATools.pdf
Resolving events.prace-ri.eu (events.prace-ri.eu)... 193.224.0.105, 2001:738:0:51b:f816:3eff:feef:d13
Connecting to events.prace-ri.eu (events.prace-ri.eu)|193.224.0.105|:443... connected.
WARNING: cannot verify events.prace-ri.eu's certificate, issued by ‘CN=DigiCert TLS RSA SHA256 2020 CA1,O=DigiCert Inc,C=US’:
  Unable to locally verify the issuer's authority.
HTTP request sent, awaiting response... 400 BAD REQUEST
2022-08-15 14:28:26 ERROR 400: BAD REQUEST.
```

```sh
$ curl -H 'Accept: text/plain' http://godoc.org/?q=sql
database/sql Package sql provides a generic interface around SQL (or SQL-like) databases.
github.com/go-sql-driver/mysql Package mysql provides a MySQL driver for Go's database/sql package.
github.com/lib/pq Package pq is a pure Go Postgres driver for the database/sql package.
database/sql/driver Package driver defines interfaces to be implemented by database drivers as used by package sql.
github.com/jmoiron/sqlx Package sqlx provides general purpose extensions to database/sql.
github.com/go-gorp/gorp Package gorp provides a simple way to marshal Go structs to and from SQL databases.
github.com/coopernurse/gorp Package gorp provides a simple way to marshal Go structs to and from SQL databases.
github.com/Masterminds/squirrel Package squirrel provides a fluent SQL generator.
github.com/go-xorm/core Lightweight & Compitable wrapper of database/sql
github.com/cockroachdb/cockroach/pkg/sql/sem/tree
github.com/pingcap/parser/ast Package ast is the abstract syntax tree parsed from a SQL statement by parser.
github.com/cockroachdb/cockroach/pkg/sql Package sql provides the user-facing API for access to a Cockroach datastore.
github.com/denisenkom/go-mssqldb package mssql implements the TDS protocol used to connect to MS SQL Server (sqlserver) database servers.
github.com/rubenv/sql-migrate SQL Schema migration tool for Go.
vitess.io/vitess/go/sqltypes Package sqltypes implements interfaces and types that represent SQL values.
github.com/cockroachdb/cockroach/pkg/sql/parser
github.com/cockroachdb/cockroach/pkg/sql/pgwire/pgerror
github.com/ziutek/mymysql/godrv Package godrv implements database/sql MySQL driver.
github.com/cloudflare/cfssl/certdb/sql
github.com/youtube/vitess/go/sqltypes Package sqltypes implements interfaces and types that represent SQL values.
github.com/cockroachdb/cockroach/pkg/workload Package workload provides an abstraction for generators of sql query loads (and requisite initial data) as well as tools for working with these generators.
github.com/russross/meddler conversion between sql and structs in go
github.com/cockroachdb/cockroach/pkg/sql/types
github.com/cockroachdb/cockroach/pkg/sql/pgwire/pgcode Package pgcode defines the PostgreSQL 5-character support codes used throughout the CockroachDB source tree.
github.com/guregu/null Package null contains SQL types that consider zero input and null input as separate values, with convenient support for JSON and text marshaling.
github.com/cockroachdb/cockroach/pkg/sql/catalog/descpb
gopkg.in/gorp.v1 Package gorp provides a simple way to marshal Go structs to and from SQL databases.
github.com/pingcap/parser A MySQL Compatible SQL Parser
gopkg.in/guregu/null.v3 Package null contains SQL types that consider zero input and null input as separate values, with convenient support for JSON and text marshaling.
github.com/cockroachdb/cockroach/pkg/sql/sqlutil
github.com/kisielk/sqlstruct Package sqlstruct provides some convenience functions for using structs with the Go standard library's database/sql package.
github.com/cockroachdb/cockroach/pkg/sql/privilege
github.com/jackc/pgx/stdlib Package stdlib is the compatibility layer from pgx to database/sql.
www.velocidex.com/golang/vfilter The veloci-filter (vfilter) library implements a generic SQL like query language.
github.com/ory/x/sqlcon Package sqlcon provides helpers for dealing with SQL connectivity.
github.com/cockroachdb/cockroach/pkg/sql/catalog/colinfo Package colinfo contains type information and related structures for dealing with columns returned from sql operations.
github.com/cockroachdb/cockroach/pkg/sql/sessiondata
gopkg.in/src-d/go-vitess.v1/sqltypes Package sqltypes implements interfaces and types that represent SQL values.
github.com/cockroachdb/cockroach/pkg/sql/catalog
github.com/cznic/ql/driver Package driver registers QL sql/drivers named "ql", "ql2" and a memory driver named "ql-mem".
github.com/xo/dburl Package dburl provides a standard, URL style mechanism for parsing and opening SQL database connection strings for Go.
github.com/gocraft/dbr Package dbr provides additions to Go's database/sql for super fast performance and convenience.
github.com/cockroachdb/cockroach/pkg/sql/rowenc
github.com/cockroachdb/cockroach/pkg/sql/sem/builtins
github.com/chrislusf/gleam/sql/util/types
github.com/go-xorm/builder Package builder is a simple and powerful sql builder for Go.
github.com/mattermost/gorp Package gorp provides a simple way to marshal Go structs to and from SQL databases.
github.com/lann/squirrel Package squirrel provides a fluent SQL generator.
google.golang.org/api/sqladmin/v1beta4 Package sqladmin provides access to the Cloud SQL Admin API.
github.com/eaigner/hood Package hood provides a database agnostic, transactional ORM for the sql package
github.com/cockroachdb/cockroach/pkg/sql/lex
xorm.io/builder Package builder is a simple and powerful sql builder for Go.
github.com/dolthub/go-mysql-server/sql
github.com/cockroachdb/cockroach/pkg/sql/execinfra
github.com/cockroachdb/cockroach/pkg/sql/execinfrapb
github.com/cockroachdb/cockroach/pkg/sql/catalog/tabledesc Package tabledesc provides concrete implementations of catalog.TableDesc.
gopkg.in/go-gorp/gorp.v2 Package gorp provides a simple way to marshal Go structs to and from SQL databases.
github.com/araddon/qlbridge/vm VM implements the virtual machine runtime evaluator for the SQL, FilterQL, and Expression evalutors.
github.com/cockroachdb/cockroach/pkg/sql/catalog/catalogkv Package catalogkv provides functions for interacting with the system catalog tables using the kv client.
github.com/gitql/vitess/go/sqltypes Package sqltypes implements interfaces and types that represent SQL values.
github.com/araddon/qlbridge/lex Package Lex is a Lexer for QLBridge which is more of a lex-toolkit and implements 4 Dialects {SQL, FilterQL, Json, Expressions}.
github.com/cayleygraph/cayley/graph/sql
github.com/guregu/null/zero Package zero contains SQL types that consider zero input and null input to be equivalent with convenient support for JSON and text marshaling.
github.com/lann/squirrel Package squirrel provides a fluent SQL generator.
github.com/cockroachdb/cockroach/pkg/sql/opt Package opt contains the Cockroach SQL optimizer.
github.com/cockroachdb/cockroach/pkg/sql/pgwire
github.com/cockroachdb/cockroach/pkg/sql/catalog/catalogkeys
github.com/xwb1989/sqlparser SQL Parser implemented in Go
github.com/cockroachdb/cockroach/pkg/sql/opt/cat Package cat contains interfaces that are used by the query optimizer to avoid including specifics of sqlbase structures in the opt code.
github.com/knq/dburl Package dburl provides a standard, URL style mechanism for parsing and opening SQL database connection strings for Go.
github.com/araddon/qlbridge/rel Package rel are the AST Structures and Parsers for the SQL, FilterQL, and Expression dialects.
github.com/mattn/go-adodb Microsoft ActiveX Object DataBase driver for go that using exp/sql
github.com/cockroachdb/cockroach/pkg/sql/sqlerrors Package sqlerrors exports errors which can occur in the sql package.
github.com/cockroachdb/cockroach/pkg/sql/catalog/typedesc Package typedesc contains the concrete implementations of catalog.TypeDescriptor.
github.com/src-d/go-mysql-server/sql
github.com/cockroachdb/cockroach/pkg/sql/catalog/descs Package descs provides abstractions for dealing with sets of descriptors.
upper.io/db.v3/lib/sqlbuilder Package sqlbuilder provides tools for building custom SQL queries.
github.com/lxc/lxd/lxd/db/query Package query implements helpers around database/sql to execute various kinds of very common SQL queries.
github.com/cockroachdb/cockroach/pkg/sql/catalog/systemschema
gopkg.in/gorp.v2 Package gorp provides a simple way to marshal Go structs to and from SQL databases.
github.com/cockroachdb/cockroach/pkg/sql/stats
github.com/cockroachdb/cockroach/pkg/sql/sqltelemetry Package sqltelemetry contains telemetry counter definitions for various SQL features.
github.com/cockroachdb/cockroach/pkg/sql/catalog/lease Package lease provides functionality to create and manage sql schema leases.
github.com/cockroachdb/cockroach/pkg/sql/row
github.com/fragmenta/query An SQL query builder for golang
github.com/cockroachdb/cockroach/pkg/sql/sem/transform
github.com/daiguadaidai/parser/ast Package ast is the abstract syntax tree parsed from a SQL statement by parser.
github.com/chrislusf/gleam/sql/util/charset
github.com/cockroachdb/cockroach/pkg/sql/catalog/schemaexpr Package schemaexpr provides utilities for dealing with expressions with table schemas, such as check constraints, computed columns, and partial index predicates.
github.com/cube2222/octosql OctoSQL is a query tool that allows you to join, analyse and transform data from multiple databases and file formats using SQL.
github.com/gobuffalo/nulls A collection of null types for the sql package
github.com/dolthub/go-mysql-server/sql/expression
github.com/cockroachdb/cockroach/pkg/sql/catalog/catconstants
github.com/araddon/qlbridge/exec Package exec contains execution tasks to run each of the separate tasks (Source, Project, Where, Having, etc) of a SQL data of tasks.
github.com/snowflakedb/gosnowflake Package gosnowflake is a pure Go Snowflake driver for the database/sql package.
github.com/mattn/go-oci8 Oracle driver for Go using database/sql
github.com/cznic/ql Package ql implements a pure Go embedded SQL database engine.
contrib.go.opencensus.io/integrations/ocsql OpenCensus SQL database driver wrapper for Go
gopkg.in/guregu/null.v4 Package null contains SQL types that consider zero input and null input as separate values, with convenient support for JSON and text marshaling.
github.com/pydio/cells/common/sql Package sql provides tools and DAOs for speaking SQL as well as managing tables migrations
```

```sh
HTTP/2 200
server: GitHub.com
content-type: text/html; charset=utf-8
last-modified: Wed, 25 May 2022 11:15:24 GMT
access-control-allow-origin: *
etag: "628e0fcc-c92"
expires: Wed, 27 Jul 2022 02:10:02 GMT
cache-control: max-age=600
x-proxy-cache: MISS
x-github-request-id: B102:08F1:2E908:35135:62E09C22
accept-ranges: bytes
date: Wed, 27 Jul 2022 02:00:02 GMT
via: 1.1 varnish
age: 0
x-served-by: cache-tyo11976-TYO
x-cache: MISS
x-cache-hits: 0
x-timer: S1658887202.035512,VS0,VE151
vary: Accept-Encoding
x-fastly-request-id: f2f30d08b9c3d12e7a24bb69d3ea2c832f21c98f
content-length: 3218
```

```sh
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
```

```sh
$ curl -I 203.100.82.236
HTTP/1.1 503 Service Unavailable
Cache-Control: no-cache
Pragma: no-cache
Content-Type: text/html; charset=utf-8
Proxy-Connection: Keep-Alive
Connection: Keep-Alive
Content-Length: 778


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



#
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




curl -H 'Accept: text/plain' http://godoc.org/?q=sql


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
Location: http://code/repo/apex/boards
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



```sh
$ curl -I http://u.sb/ -A Mozilla
HTTP/1.1 301 Moved Permanently
Date: Thu, 01 Sep 2022 05:48:37 GMT
Content-Type: text/html
Content-Length: 162
Connection: keep-alive
Location: https://u.sb/
Server: Windows 11

HTTP/1.1 200 OK
Date: Thu, 01 Sep 2022 05:48:37 GMT
Content-Type: text/html; charset=UTF-8
Connection: keep-alive
Vary: Accept-Encoding
Server: u.sb
Referrer-Policy: strict-origin-when-cross-origin
Strict-Transport-Security: max-age=31536000; includeSubDomains; preload
X-Frame-Options: SAMEORIGIN
X-Content-Type-Options: nosniff
X-XSS-Protection: 1; mode=block
Report-To: {"group":"default","max_age":31536000,"endpoints":[{"url":"https://showfom.report-uri.com/a/d/g"}],"include_subdomains":true}
NEL: {"report_to":"default","max_age":31536000,"include_subdomains":true}
Permissions-Policy: accelerometer=(), camera=(), geolocation=(), gyroscope=(), magnetometer=(), microphone=(), payment=(), usb=()
Expect-CT: max-age=604800, report-uri="https://showfom.report-uri.com/r/d/ct/enforce"
Feature-Policy: accelerometer 'none'; camera 'none'; geolocation 'none'; gyroscope 'none'; magnetometer 'none'; microphone 'none'; payment 'none'; usb 'none'
Content-Security-Policy: default-src 'self' data: 'unsafe-inline' https://*.u.sb https://*.rsb.net https://shou.si; script-src 'self' 'unsafe-inline' 'unsafe-eval' https://*.u.sb https://*.rsb.net https://shou.si; style-src 'self' data: 'unsafe-inline' https://*.u.sb https://*.rsb.net https://shou.si; img-src 'self' data: https://*.u.sb https://*.rsb.net https://shou.si; font-src 'self' data: https://*.u.sb https://*.rsb.net https://shou.si; connect-src 'self' https://*.u.sb https://*.rsb.net https://shou.si; media-src 'self' https://*.u.sb https://*.rsb.net https://shou.si; object-src 'self' https://*.u.sb https://*.rsb.net https://shou.si; prefetch-src 'self'; frame-src 'self'; worker-src 'self'; frame-ancestors 'self'; form-action 'self' https://*.u.sb https://*.rsb.net https://shou.si; upgrade-insecure-requests; block-all-mixed-content; manifest-src 'self' https://*.u.sb https://*.rsb.net https://shou.si; report-uri https://showfom.report-uri.com/r/d/csp/enforce
```

```
root@git:/var/opt/gitlab/backups# curl -I https://grapheneos.org/install/cli
HTTP/2 200
server: nginx
date: Mon, 05 Sep 2022 05:21:26 GMT
content-type: text/html; charset=utf-8
content-length: 25815
last-modified: Mon, 05 Sep 2022 05:15:54 GMT
vary: Accept-Encoding
etag: "6315860a-64d7"
strict-transport-security: max-age=63072000; includeSubDomains; preload
x-content-type-options: nosniff
referrer-policy: no-referrer
cross-origin-opener-policy: same-origin
cross-origin-embedder-policy: require-corp
origin-agent-cluster: ?1
x-frame-options: DENY
x-xss-protection: 0
content-security-policy: default-src 'none'; connect-src 'self' https://releases.grapheneos.org/; font-src 'self'; img-src 'self'; manifest-src 'self'; script-src 'self'; style-src 'self'; form-action 'none'; frame-ancestors 'none'; block-all-mixed-content; base-uri 'none'; require-trusted-types-for 'script'; trusted-types 'none'
permissions-policy: accelerometer=(), ambient-light-sensor=(), autoplay=(), battery=(), camera=(), clipboard-read=(), clipboard-write=(), display-capture=(), document-domain=(), encrypted-media=(), fullscreen=(), gamepad=(), geolocation=(), gyroscope=(), hid=(), idle-detection=(), interest-cohort=(), magnetometer=(), microphone=(), midi=(), payment=(), picture-in-picture=(), publickey-credentials-get=(), screen-wake-lock=(), serial=(), speaker-selection=(), sync-xhr=(), usb=(), xr-spatial-tracking=()
cross-origin-resource-policy: same-origin
cache-control: public, no-cache
link: </4ed2f591.main.css>; rel=preload; as=style; integrity=sha256-TtL1kYPxBwG8TuDFejy69lt7uYjWhwZ1tikoAkVRDQM=, </fonts/roboto-v29-regular-latin.woff2>; rel=preload; as=font; crossorigin, </fonts/roboto-v29-bold-latin.woff2>; rel=preload; as=font; crossorigin, </780febcc.mask-icon.svg>; rel=preload; as=image, </js/f2319062.redirect.js>; rel=modulepreload; integrity=sha256-8jGQYn8UcJbAw8WFbVaUeFb37Tul+R5rbSiUJqZUGtg=
set-cookie: __Host-push=1; HttpOnly; Secure; SameSite=Lax; Path=/
accept-ranges: bytes
```

```
curl -L -O "https://github.com/yous/whiteglass/raw/master/{index.html,about.md,archives.md,feed.xml,robots.txt}"
curl -L --create-dirs -o _data/#1 "https://github.com/yous/whiteglass/raw/master/_data/{navigation.yml,i18n.yml}
```
