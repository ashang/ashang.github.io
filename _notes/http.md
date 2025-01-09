
## HTTP cache

```shell
$ curl -I bing.com
HTTP/1.1 301 Moved Permanently
Content-Length: 0
Location: http://cn.bing.com/
X-MSEdge-Ref: Ref A: 146AF6B1456043D59588937646D7455F Ref B: HKG30EDGE0814 Ref C: 2022-02-11T06:25:15Z
Date: Fri, 11 Feb 2022 06:25:14 GMT

HTTP/1.1 200 OK
Cache-Control: private
Content-Length: 0
Content-Type: text/html; charset=utf-8
P3P: CP="NON UNI COM NAV STA LOC CURa DEVa PSAa PSDa OUR IND"
Set-Cookie: SUID=M; domain=.bing.com; expires=Sat, 12-Feb-2022 06:25:15 GMT; path=/; HttpOnly
Set-Cookie: MUID=316A5852811D61102525491A80CF60F4; domain=.bing.com; expires=Wed, 08-Mar-2023 06:25:15 GMT; path=/
Set-Cookie: MUIDB=316A5852811D61102525491A80CF60F4; expires=Wed, 08-Mar-2023 06:25:15 GMT; path=/; HttpOnly
Set-Cookie: _EDGE_S=F=1&SID=16C8F9609D246D3B39D9E8289CF66C36; domain=.bing.com; path=/; HttpOnly
Set-Cookie: _EDGE_V=1; domain=.bing.com; expires=Wed, 08-Mar-2023 06:25:15 GMT; path=/; HttpOnly
Set-Cookie: SRCHD=AF=NOFORM; domain=.bing.com; expires=Sun, 11-Feb-2024 06:25:15 GMT; path=/
Set-Cookie: SRCHUID=V=2&GUID=7688888AFE334518A81FE4A2E8685879&dmnchg=1; domain=.bing.com; expires=Sun, 11-Feb-2024 06:25:15 GMT; path=/
Set-Cookie: SRCHUSR=DOB=20220211; domain=.bing.com; expires=Sun, 11-Feb-2024 06:25:15 GMT; path=/
Set-Cookie: SRCHHPGUSR=SRCHLANG=zh-Hans; domain=.bing.com; expires=Sun, 11-Feb-2024 06:25:15 GMT; path=/
Set-Cookie: _SS=SID=16C8F9609D246D3B39D9E8289CF66C36; domain=.bing.com; path=/
Set-Cookie: ULC=; domain=.bing.com; expires=Thu, 10-Feb-2022 06:25:15 GMT; path=/
Set-Cookie: _HPVN=CS=eyJQbiI6eyJDbiI6MSwiU3QiOjAsIlFzIjowLCJQcm9kIjoiUCJ9LCJTYyI6eyJDbiI6MSwiU3QiOjAsIlFzIjowLCJQcm9kIjoiSCJ9LCJReiI6eyJDbiI6MSwiU3QiOjAsIlFzIjowLCJQcm9kIjoiVCJ9LCJBcCI6dHJ1ZSwiTXV0ZSI6dHJ1ZSwiTGFkIjoiMjAyMi0wMi0xMVQwMDowMDowMFoiLCJJb3RkIjowLCJHd2IiOjAsIkRmdCI6bnVsbCwiTXZzIjowLCJGbHQiOjAsIkltcCI6MX0=; domain=.bing.com; expires=Sun, 11-Feb-2024 06:25:15 GMT; path=/
X-SNR-Routing: 1
X-Cache: CONFIG_NOCACHE
X-MSEdge-Ref: Ref A: 982425DC633246189B9AA7FFDF126190 Ref B: BJ1EDGE0915 Ref C: 2022-02-11T06:25:15Z
Date: Fri, 11 Feb 2022 06:25:14 GMT
```

## HTTP compressing

 Brotli is a generic-purpose lossless compression algorithm
 that compresses data using a combination of a modern variant
 of the LZ77 algorithm, Huffman coding and 2nd order context modeling,
 with a compression ratio comparable to the best currently available
 general-purpose compression methods. It is similar in speed with
 deflate but offers more dense compression.

- https://github.com/google/brotli

HTTP数据在从服务器发送前就已压缩：兼容的浏览器将在下载所需的格式前宣告支持何种方法给服务器；不支持压缩方法的浏览器将下载未经压缩的数据。

常见的压缩方案包括brotil、gzip和Deflate，可用方案的完整列表由IANA维护。


在HTTP中有两种不同的方式可以完成压缩。在较低层级，Transfer-Encoding头可以指示HTTP消息的有效载荷被压缩。在较高层级，Content-Encoding头可以指示一个被转码、缓存或引用的资源已压缩。使用Content-Encoding的压缩比Transfer-Encoding有更广泛的支持，并且某些浏览器不宣告Transfer-Encoding压缩以避免触发服务器的缺陷。


在大多数情况中（不包括SDCH），协商使用两个步骤完成，这描述在RFC 2616：

1. 网页客户端在HTTP请求的头部通告其支持的压缩方案为一个标记列表（tokens）。对于Content-Encoding，这个列表称作Accept-Encoding；对于Transfer-Encoding，该字段被称为TE。

GET /encrypted-area HTTP/1.1
Host: www.example.com
Accept-Encoding: gzip, deflate
2. 如果服务器支持一种或多种压缩方案，输出的数据可能用一种或多种双方支持的方法压缩。如果是这种情况，服务器将在HTTP响应中添加一个Content-Encoding或Transfer-Encoding字段表明使用的方案，用逗号分隔。

HTTP/1.1 200 OK
Date: Tue, 27 Feb 2018 06:03:16 GMT
Server: Apache/1.3.3.7 (Unix)  (Red-Hat/Linux)
Last-Modified: Wed, 08 Jan 2003 23:11:55 GMT
Accept-Ranges: bytes
Content-Length: 438
Connection: close
Content-Type: text/html; charset=UTF-8
Content-Encoding: gzip
网页服务器本身没有义务使用任何压缩方法——这取决于网页服务器的内部设置，并可能依赖于网站的内部架构。

## SDCH

在SDCH的情况下，完成一份字典协商也是必须的，其中可能涉及额外的步骤，比如从外部服务器下载一个合适的字典。

SDCH（英語：Shared Dictionary Compression for HTTP）是Google基于VCDIFF（RFC 3284）创建的数据压缩算法。它已在最近版本的Google Chrome、Chromium和Android中支持，并被Google系列网站支持。[1][2]

SDCH使用预先协商的字典“热身”其编码或解码前的内部状态以达成其效果。字典内容可以已在本地存储，或者已从某个源上载并缓存。


## Content-Encoding标记

服务器和客户端的标记（token）的官方列表由IANA维护

gzip – GNU zip格式（定义于RFC 1952

非官方或非标准化的标记也已被一些服务器或客户端使用：

br – Brotli，一种新的开源压缩算法，专为HTTP内容的编码而设计，已在Mozilla Firefox 44中实现，并且Chromium正准备实施。
bzip2 – 基于自由格式bzip2的压缩，被lighttpd[7]
lzma – 基于原始LZMA的压缩，在Opera 20中可用，elinks使用一个编译时选项也可启用[8]
peerdist[9] – Microsoft对等端内容缓存和检索
sdch[10][11] – Google的面向HTTP共享字典压缩，基于VCDIFF（RFC 3284）


## 支持HTTP压缩的服务器
SAP NetWeaver
Microsoft IIS：内置或使用第三方模块
Apache HTTP Server，通过mod_deflate（页面存档备份，存于互联网档案馆）（正如其名，只支持gzip[15][self-published source?][16]）


lighttpd，通过mod_compress和较新的mod_deflate（1.5.x）
nginx – 内置
基于Tornado的应用程序，如果“compress_response”在应用设置中设置为True（对4.0之前的版本，设置“gzip”为True）



## Brotli基于LZ77算法的一个现代变体、霍夫曼编码和二阶上下文建模。

在Chrome、Opera和Firefox中，它已被用于加速万维网的传输速度。[6]类似Google的压缩算法zopfli，brotli这个名字来自瑞士的烘培产品brötli

Google软件工程师在2015年9月发布了包含通用无损数据压缩的Brotli增强版本，特别侧重于HTTP压缩。其中的编码器被部分改写以提高压缩比，编码器和解码器都提高了速度，流式API已被改进，增加更多压缩质量级别。新版本还展现了跨平台的性能改进，以及减少解码所需的内存。[7]

与常见的通用压缩算法不同，Brotli使用一个预定义的120千字节字典。该字典包含超过13000个常用单词、短语和其他子字符串，这些来自一个文本和HTML文档的大型语料库。[9][10]预定义的算法可以提升较小文件的压缩密度。

使用brotli取代deflate来对文本文件压缩通常可以增加20%的压缩密度，而压缩与解压缩速度则大致不变。使用Brotli进行流压缩的内容编码类型已被提议使用“br”




