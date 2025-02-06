---
title: User-Agent Thoughts after a day of work
date: 2020-07-01
# published: false
tags:
- User-Agent
---


    User-Agent: <product> / <product-version> <comment>

```
User-Agent: Mozilla/5.0 (<system-information>) <platform> (<platform-details>) <extensions>
```

            Mozilla/5.0 (platform; rv:geckoversion) Gecko/geckotrail Firefox/firefoxversion

Gecko/geckotrail 表示浏览器基于 Gecko 引擎。（在桌面平台上，geckotrail 始终是固定的字符串 20100101

    Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:47.0) Gecko/20100101 Firefox/47.0

    Mozilla/5.0 (Macintosh; Intel Mac OS X x.y; rv:42.0) Gecko/20100101 Firefox/42.0

Chrome（Chromium 或 Blink 引擎）

    Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36

Opera

    Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.106 Safari/537.36 OPR/38.0.2220.41

Edge

    Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36 Edg/91.0.864.59

Safari

    Mozilla/5.0 (iPhone; CPU iPhone OS 13_5_1 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.1.1 Mobile/15E148 Safari/604.1


    用户代理字符串可以在客户端通过 JavaScript 使用 navigator.userAgent 属性进行访问。


        User-Agent = product *( RWS ( product / comment ) )

        因此，为获取更好的网页，绝大多数网页浏览器使用的User-Agent值如下：

    Mozilla/[version] ([system and browser information]) [platform] ([platform details]) [extensions]。

例如，iPad上的Safari使用的就是下述：

    Mozilla/5.0 (iPad; U; CPU OS 3_2_1 like Mac OS X; en-us) AppleWebKit/531.21.10 (KHTML, like Gecko) Mobile/7B405


Mozilla/5.0 (Macintosh; U; PPC Mac OS X; de-de) AppleWebKit/85.7 (KHTML, like Gecko) Safari/85.5；Google开发的基于Webkit的产品Chrome和 Chromium及派生的渲染引擎Blink，使用的是：Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) AppleWebKit/525.13 (KHTML, like Gecko) Chrome/0.2.149.27 Safari/525.13。

特例的是，Opera同时使用标识兼容于多个渲染引擎（或网页浏览器）和自己独有渲染引擎Presto的用户代理字符串，类似于： Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; en) Opera 9.51、Mozilla/5.0 (Windows NT 6.0; U; en; rv:1.8.1) Gecko/20061208 Firefox/2.0.0 Opera 9.51、Opera/9.60 (Windows NT 6.0; U; en) Presto/2.1.1


## robots.txt协议并不是一个规范，而只是约定俗成的，所以并不能保证网站的隐私。注意robots.txt是用字符串比较来确定是否获取URL，所以目录末尾有与没有斜杠“/”表示的是不同的URL。robots.txt允许使用类似“Disallow: *.gif”这样的通配符[1][2]。

其他的影响搜索引擎的行为的方法包括使用robots元数据：

<meta name="robots" content="noindex,nofollow" />

这个协议也不是一个规范，而只是约定俗成的，有些搜索引擎会遵守这一规范，有些则不然。通常搜索引擎会识别这个元数据，不索引这个页面，以及这个页面的链出页面。

特定的机器人：（name_spider用真实名字代替）

User-agent: name_spider
Allow:

拦截所有的机器人：

User-agent: *
Disallow: /

禁止所有机器人访问特定目录：

User-agent: *
Disallow: /cgi-bin/
Disallow: /images/
Disallow: /tmp/
Disallow: /private/

仅禁止坏爬虫访问特定目录（BadBot用真实的名字代替）：

User-agent: BadBot
Disallow: /private/

禁止所有机器人访问特定文件类型[2]：

User-agent: *
Disallow: /*.php$
Disallow: /*.js$
Disallow: /*.inc$
Disallow: /*.css$

非标准扩展协议
自动发现Sitemaps文件

Sitemap指令被几大搜索引擎支持（包括Google、Yahoo、Bing和Ask），指定了网站Sitemaps文件的位置。Sitemaps文件包含了网站页面所在的URL的一个列表。Sitemap指令并不受User-agent指令的限制，所以它可以放在robots.txt文件中的任意位置。[3] 唯一要注意的就是要使用网站地图指令，<sitemap_location>,并将URL的“location”值换成网站地图的地址，例如，下面就是一个网站地图指令的例子：

Sitemap: <http://www.example.com/sitemap.xml>

如何编写Sitemaps文件，请参考sitemaps.org（页面存档备份，存于互联网档案馆）（英文）上的说明。
Crawl-delay指令

几大抓取工具支持Crawl-delay参数，设置为多少秒，以等待同服务器之间连续请求：[4][5]

User-agent: *
Crawl-delay: 10



User-agent: *
Disallow: /cgi-bin/
Disallow: /tmp/
Disallow: /junk/

This example tells all robots to stay away from one specific file:

User-agent: *
Disallow: /directory/file.html



This example tells two specific robots not to enter one specific directory:

User-agent: BadBot # replace 'BadBot' with the actual user-agent of the bot
User-agent: Googlebot
Disallow: /private/



包含HTML 4.01和XHTML的HTML，有四个有效的属性：content、http-equiv、name和scheme。在HTML 5下，现在有五个有效的属性，添加了charset。http-equiv用于模拟HTTP标题，并用name来嵌入元数据。无论哪种情况，语句的值都包含在content属性中，除非给出charset，否则这是唯一必需的属性。charset用于指示文档的字符集，可用于HTML5。

这些元素必须作为标签放置在HTML或XHTML文档的head一节。

该元素的两个不同部分是：

    标题标签
    元描述


    Firefox 中，你可以通过 about:config 修改 general.useragent.override 偏好设置来更改用户代理。一些 Firefox 扩展程序也会这样做；然而，这只会更改发送的 HTTP 标头以及 navigator.userAgent 返回的内容。此外，还可能存在其他利用 JavaScript 代码来识别浏览器的办法


    alert(window.navigator.userAgent);
// 弹出“Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:124.0) Gecko/20100101 Firefox/124.0”



- <https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Browser_detection_using_the_user_agent>



fetch("https://httpbin.org/get", {
  headers: {
    Date: new Date().toUTCString(),
  },
});


- <https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Headers/User-Agent/Firefox>

