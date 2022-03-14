

- 资源
- DNS查询
- 内容压缩


负载均衡
数据库

避免空等待
- 感觉变快
- 成功的任务
- 有回应
- 进度
- 有意义的信息提示



所有的东西都应该在版本控制之下
交换机的配置文件
路由器的配置文件
防火墙的配置文件
系统的配置文件
应用的配置文件
监视程序的配置文件
文档
程序代码
数据库表结构
所有一切



Failure

如何把它转化成正面反应
开放 & 透明化
响应而不是回避
建立信任
沟通渠道
公开的健康状况仪表盘



部署
Facebook和Twitter都使用BitTorrent
Facebook：1分钟完成全球的部署（几百兆的文件、上万台服务器）
Twitter ：30~60秒更新超过1千台服务器（Python + libtorrent）
监控 & 工具
CFengine
Puppet
Chef
Ganglia
Nagios
编写适用于自己的
自动化，自动化，自动化
准备好应付故障
规划好容量而不是做消防员

通过统计分析产生有意义的结果

## JS

并不是每个动作都需要Javascript
这是加快性能与用户体验的一个机会
在底端加载Javascript吗？
动态加载的脚本不会阻塞页面加载
预测性加载
工具
Firebug
JSMeter


## CSS

没有gzip压缩（42%）
有2个以上的外部CSS文件（44%）
CSS文件带有cookie（56%）
没有最小化（62%）
使用YUI Compressor
CSS文件超过100K（21%）

## Tools

YSlow
Page Speed
Closure Compiler
Show Slow
dynaTrace
HttpWatch
AOL Pagetest
Speed Tracer
Fiddler


## gzip

15%的客户端没有开启gzip压缩
Proxy
安全软件
爬虫
强制gzip压缩
如果没有Accept-Encoding头
判断User-Agent是否是一个modern的浏览器
如果没有一个特殊的cookie
测试看其能否解压缩gzip内容
如果成功，则发送gzip的内容

## HTTP parallel

Facebook的BigPipe
页片（pagelet）
流水线（pipeline）
模板
JSON返回内容
刷新方式
- singleflush
- pipeline
- parallel
- prepare
效果对比
- http://www.facebook.com/home.php?big_pipe=pipeline
- http://www.facebook.com/home.php?big_pipe=singleflush


## Assets

不要阻塞住绘制或者加载
Iframe
Script tag
不要影响用户体验



## Storage

Openstoragepod.org
backblaze


## Design

前面的几个包
- 保持Cookie小
- 让小的assets先下载


## TCP

对TCP的优化
TCP快速开始（加大初始拥塞窗口大小）
Google提高了12%的性能

## SSL

False Start
减少握手中的一个来回
Google的SSL应用快了10%

## SPDY

头部压缩
流多路复用
快了25%

## CDN

软件
- Squid
- Traffic Server

技术
Cache Peering
- RFC  2186/2756
Cache-Control
- stale-while-revalidate
- Cache-Control: stale-if-error
- RFC 5861



## DB

MySQL
- Drizzle，云时代的MySQL替换品
- FlockDB
NoSQL
- Memcached
- Cassandra
- Hadoop



