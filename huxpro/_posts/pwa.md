---
#layout: post
title: PWA(Progressive Web App)
header-style: text
tags:
  - Web
  - PWA
---

[PWA ](https://zhuanlan.zhihu.com/p/25167289)

[实践者](https://zhuanlan.zhihu.com/p/27853228)

PWA 的商业案例至今为止，我感到 legit（正当）的仍然只有 twitter，是真正在按一个「给所有用户都能用」的标准来做的。Airbnb/Pinterest/Spotify 可能能及格，而其他的则要么是商业互吹（吹一波走人），要么就是利益（市场导向）一致（Instagram 以及逐年增多的印度系产品）。

PWA 的期待本来是作为 RN/Flutter 等跨平台开发的 alternatives（替代品），

Addy Osmani

Alex Russell

![](https://pic4.zhimg.com/80/v2-82770d1b0366904c2254908d097e0a60_720w.jpg?source=1940ef5c)

他们在乎的是「下一个十亿用户」，中国显然不在其中呢

*   PWA 目前主要靠 Google 推动是客观事实，且 PWA 的发展必须依赖平台（浏览器）的参与。
*   小程序: webview
- Wechat Mini-Program

[《一天世界》博客：微信并不是在「管理」外部链接，因为微信公众号在事实上（de facto）不允许任何外部链接 - 不鳥萬通讯 - 知乎专栏](https://zhuanlan.zhihu.com/p/20747514) 里他写到：

> 中文世界一直混淆[互联网](https://en.wikipedia.org/wiki/Internet)（internet）和[万维网](https://en.wikipedia.org/wiki/World_Wide_Web)（web）。人们念兹在兹的「互联网开放精神」，实乃万维网的开放精神。万维网的开放主要就体现在一点：**任何万维网上的文章之间都可以通过网址随意互相链接**。如果我想在文章里介绍 UbuWeb 这个网站，我就可以直接在 [UbuWeb](https://ubu.com/) 这六个字母上添加它的网址 ubu.com。妳或许觉得这是废话，但在微信公众号的文章里妳做不到；妳只能添加微信生态圈内的链接，比如这个：[https://weixin.qq.com/cgi-bin/readtemplate?t=weixin_external_links_content_management_specification](https://weixin.qq.com/cgi-bin/readtemplate%3Ft%3Dweixin_external_links_content_management_specification)（即上述《规范》的链接）

[黄玄：下一代 Web 应用模型 — Progressive Web App​zhuanlan.zhihu.com!](https://zhuanlan.zhihu.com/p/25167289)

React Native 的出现则无疑让部分人的信仰崩塌，然后是 Weex，然后可能是你们猜的微信。

[Regressive Web Apps](https://adactio.com/journal/10708) 的 Jeremy Keith

Chrome 产品 Leader Rahul 也在 I/O 上说过得：

Web 的 Dicoverable、Linkable、Low Friction、Broad Reach 等等，这些都不是 Web 的本质，**Web 的本质是 Open（开放）与 Decentralized （去中心化），这才是万维网（WWW）的初衷，这才是所有这些特性能成立的前提。**



PWA 中最引入注目的核心新特性，Service Worker，实质上是为 Web 应用带来了一种安全而又低功耗的后台处理能力。无论是用于实现离线 Web 应用所需要的缓存读写与网络代理，还是用于提升 Web 应用能力的推送通知、后台同步，其实都得益于这种新的并发能力。

> PWA实战：面向下一代的Progressive Web APP: 
>
> 本书原著非常详实且不失生动地涵盖了 PWA 的方方面面。作者不但通过一个贯穿全书的案例将 PWA 的各项技术串起，还把它们所要解决的问题与可以带来的产品价值也一一娓娓道来。书中讨论到的策略与模式非常实用，既可以帮助你快速上手 PWA，也能帮助你对 Web 应用的工程化有更好的理解。

