
```
$ ruby -e "require 'sinatra' "                                                                     [NORMAL]
[2021-12-24 17:14:30] INFO  WEBrick 1.7.0
[2021-12-24 17:14:30] INFO  ruby 3.0.3 (2021-11-24) [x86_64-linux]
== Sinatra (v1.4.8) has taken the stage on 4567 for development with backup from WEBrick
[2021-12-24 17:14:30] INFO  WEBrick::HTTPServer#start: pid=2843174 port=4567
::1 - - [24/Dec/2021:17:14:35 +0800] "GET / HTTP/1.1" 404 462 0.0099
::1 - - [24/Dec/2021:17:14:35 HKT] "GET / HTTP/1.1" 404 462
- -> /
```

```
Sinatra doesn’t know this ditty.

Try this:
get '/' do
  "Hello World"
end
```

```
$ cat sinatra.rb
```

```
require 'sinatra'

get '/' do
    'Hello world!'
end

get '/frank-says' do
  'Put this in your pipe & smoke it!'
end
```

```
$ ruby sinatra.rb
[2021-12-24 17:16:05] INFO  WEBrick 1.7.0
[2021-12-24 17:16:05] INFO  ruby 3.0.3 (2021-11-24) [x86_64-linux]
== Sinatra (v1.4.8) has taken the stage on 4567 for development with backup from WEBrick
[2021-12-24 17:16:05] INFO  WEBrick::HTTPServer#start: pid=2844346 port=4567
::1 - - [24/Dec/2021:17:16:10 +0800] "GET / HTTP/1.1" 200 12 0.0143
::1 - - [24/Dec/2021:17:16:10 HKT] "GET / HTTP/1.1" 200 12
- -> /

::1 - - [24/Dec/2021:17:17:49 +0800] "GET /frank-says HTTP/1.1" 200 33 0.0005
::1 - - [24/Dec/2021:17:17:49 HKT] "GET /frank-says HTTP/1.1" 200 33
- -> /frank-says
```


