---
title: timestamp
tags: [timestamp]
date: 2022-12-19
---


入口机器有大量的反向代理,端口经常不够用,所以开启了TIME_WAIT 端口重用

开启了 TIME_WAIT 端口重用后,服务端要求同一个IP的SYN 包 timestamp 必须是顺序的

nginx 高版本已经支持 keep-alive
- 升级 nginx, 启用 keep-alive, 降低端口占用
- 关闭端口重用,并加强端口数的监控和报警

海恩法则: 每一起严重事故的背后,必然有29次轻微事故和300起未遂先兆以及1000起事故隐患

发出的请求是否正确: URL, 方法, 参数, Accept, Cookie
期望的返回值是什么?
Request-Id
- 对每次请求产生一个唯一的Id
该 Id 以 HTTP Response Header 的方式发送到客户端
- 可以在 nginx 层面实现或者在业务逻辑层面实现

服务端日志看什么?
四要素
- 时间: 开始时间,总耗时
- 谁: 用户Id, Session-Id, Request-Id
- 做什么: URL, 方法,XHR?, format, 参数(注意保护密码)
- 结果是什么?




