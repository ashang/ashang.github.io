---
layout: post
title: 如何理解 <code>document</code> 对象是 <code>HTMLDocument</code> 的实例？
subtitle: Why is <code>document</code> an instance of <code>HTMLDocument</code>?
header-style: text
tags:
  - Web
---

http://localhost:1126/ios9-safari-web/

> 这篇文章转载自[我在知乎上的回答](https://www.zhihu.com/question/57601873/answer/155685476)

lib.dom.d.ts

https://en-academic.com/dic.nsf/enwiki/1980879
https://github.com/yihleego/robotic-process-automation

https://typedoc.org/

https://www.typescriptlang.org/docs/handbook/dom-manipulation.html

https://www.zhihu.com/question/47456978/answer/328800045

  https://www.zhihu.com/question/37361845/answer/327880455

http://localhost:1126/pwa-in-my-pov/

## viewport、native app、webview

iPad Pro 的 viewport 为 1024px

Universal Links 可以让应用的拥有者在 iOS 内部“占有”自己的域名。因此，访问 yourdomain.com 将会打开你的应用（类似 Android 的 Intents 机制）

https://blog.poetries.top/node-learning-notes/notes/base/01-%E7%8E%AF%E5%A2%83%E6%90%AD%E5%BB%BA.html#node-js-%E6%A8%A1%E5%9D%97

https://github.com/moby/moby/issues/9983

https://medium.freecodecamp.com/angular-2-versus-react-there-will-be-blood-66595faafd51#.v4y4euy1r

https://github.com/opencontainers/runc

webview 并不会与浏览器共享 cookies，sessions，autofill（自动填充）与 bookmark（书签），为了解决这些问题，就有了 Safari View Controller。

现在，native app 可以使用 Safari View Controller 来打开网站，它提供与 Safari 完全一致的隐私政策、local storage，cookies、sessions 同时让用户留在你的 app 中，它通过一个 “Done”（完成）按钮使用户可以回到 native app 的上一个 controller。这个全新的 controller 还可以让我们在 Share（分享）按钮上添加自定义的操作，这些操作在用户使用 Safari 应用时并不会出现。同时，native app 对这个自定义 Safari 实例具有完全的内容控制，你可以屏蔽不想被渲染的内容。

当你需要基于 web 的鉴权，比如 OAuth 时，使用 Safari View Controller 同样是一个好主意，这样就不再需要打开浏览器再重定向回你的应用。不过注意了，Safari View Controller 只适用于在线、公开的 web 内容。如果你的 web 内容假设在本地或者私服，那么 WKWebView 仍然是最推荐的选择。

WKWebView 正在取代它的位置。一个最受期待的特性现在终于推出：加载本地文件到 WKWebView。因此，现在 Apache Cordova 应用与其他 web 内容都可以直接从 iOS 包中使用本地文件了，不再需要各种诡异的 hack 了。

此外，还有一些新特性也一并推出。比如说，通过 WKWebsiteDataStore，Objective-C 或 Swift 有能力查询与管理 webview 的本地存储（比如 localStorage 或 IndexedDB）。这就允许我们将原有的数据存储替换成新的某些东西，比如说替换成一个不永久的（Chrome for iOS 的隐身模式就需要这种东西）

Universal Links（通用链接）
如果你既有一个网站，又有一个 native app，你现在可以通过 Universal Links 来增强用户体验。它允许你在操作系统内“占有”自己的域名，这样，一切指向你网站的链接都会被重定向到你的 app。

目前，所有的 app 都是通过自定义 URI 来达到这个效果的，比如 comgooglemaps:// 就可以用来从网站或者其他原生 iOS 应用中打开 Google Maps。

想要提供这个特性的话，你首先需要在 native app 中实现 Deep Linking（深度链接），让应用中的内容与 Safari 的 URL 吻合。然后，你需要在 Apple 的网站上关联你的域名，取得这个域名的 SSL 认证并且把签名后的 JSON 部署到该域名上。这是为了防止第三方的应用“占据”了属于你而不属于他们的域名，比如说 twitter.com 被非 Twitter 的其他应用占据掉。

首先要理解的是 DOM 是 API，是一组无关编程语言的接口（Interfaces）而非实现（Implementation）。前端平时常说的 DOM 其实只是浏览器通过 ECMAScript（JavaScript）对 DOM 接口的一种实现。

其次要知道的是，DOM 既是为 HTML 制定的，也是为 XML 制定的。而两者各有一些特异的部分，所以作为 DOM 标准基石的 DOM Level 1 其实分为 Core 与 HTML 两个部分。Core 定义了 fundamental interfaces 与 extended interfaces，分别是共用的基础接口与 「XML 拓展包」，而 HTML 部分则全都是「HTML 拓展包」。题主所问到的 Document 接口被定义在 Core 的 fundamental interfaces 中，而 HTMLDocument 接口则定义在 HTML 部分中，且「接口继承」于 Document。

这种继承关系当然是可以在 JavaScript 的 DOM 实现中体现出来的：

```js
// document 是 HTMLDocument 的实例
document instanceof HTMLDocument // true

// document 的 [[prototype]] 指向 HTMLDocument 的原型
document.__proto__ === HTMLDocument.prototype // true

// HTMLDocument 伪类继承于 Document
HTMLDocument.prototype instanceof Document // true
HTMLDocument.prototype.__proto__ === Document.prototype // true
```

至于 Document 与 HTMLDocument 这两个构造函数，跟 Array、Object 一样都是 built-in 的：

```js
> Document
< function Document() { [native code] }
> HTMLDocument
< function HTMLDocument() { [native code] }
```

虽然是 native code，但一个有意思的现象是，这两个构造函数之间也是存在原型链的：

```js
// HTMLDocument 的 [[prototype]] 是指向 Document 的
HTMLDocument.__proto__ == Document

// 同理
Document.__proto__ == Node
Node.__proto__ == EventTarget
```

其作用是实现对静态成员的继承。（ ES6 Class 的行为与此完全一致，但这个行为在更早之前就是这样了。）

好了扯远了，总结一下，**在 JavaScript 的 DOM 实现中**

*   document 是 HTMLDocument 的实例
*   HTMLDocument 继承于 Document

留一个课后作业，有兴趣的话可以看看 Document.prototype 与 HTMLDocument.prototype 里分别都有什么？在不同浏览器里都试试。

以上。
