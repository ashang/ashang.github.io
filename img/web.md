
## HTTP request

PUT方法

跟POST方法很像，提交数据。但是，它们之间有不同。PUT指定了资源在服务器上的位置，而POST没有

OPTIONS方法

它用于获取当前URL所支持的方法。如果请求成功，会有一个Allow的头包含类似“GET,POST”这样的信息
TRACE方法

TRACE方法被用于激发一个远程的，应用层的请求消息回路
CONNECT方法

把请求连接转换到透明的TCP/IP通道




## SEO
合理的title、description、keywords：搜索引擎对着这项的权重逐个减小，title值强调重点即可，重要关键词出现不要超过2次，而且要靠前，不同页面title要有所不同；description把页面内容高度概括，长度合适，不可过分堆砌关键词，不同页面description有所不同；keywords列举出重要关键词即可
语义化的HTML代码，符合W3C规范：语义化代码让搜索引擎容易理解网页
重要内容HTML代码放在最前：搜索引擎抓取HTML顺序是从上到下，有的搜索引擎对抓取长度有限制，保证重要内容一定会被抓取
重要内容不要用js输出：爬虫不会执行js获取内容
少用iframe：搜索引擎不会抓取iframe中的内容
非装饰性图片必须加alt
提高网站速度：网站速度是搜索引擎排序的一个重要指标



## url到显示页面的步骤
基础版本

浏览器根据请求的URL交给DNS域名解析，找到真实IP，向服务器发起请求；
服务器交给后台处理完成后返回数据，浏览器接收文件（HTML、JS、CSS、图象等）；
浏览器对加载到的资源（HTML、JS、CSS等）进行语法解析，建立相应的内部数据结构（如HTML的DOM）；
载入解析到的资源文件，渲染页面，完成。
详细版

在浏览器地址栏输入URL
浏览器查看缓存，如果请求资源在缓存中并且新鲜，跳转到转码步骤
如果资源未缓存，发起新请求
如果已缓存，检验是否足够新鲜，足够新鲜直接提供给客户端，否则与服务器进行验证。
检验新鲜通常有两个HTTP头进行控制Expires和Cache-Control：
HTTP1.0提供Expires，值为一个绝对时间表示缓存新鲜日期
HTTP1.1增加了Cache-Control: max-age=,值为以秒为单位的最大新鲜时间
浏览器解析URL获取协议，主机，端口，path
浏览器组装一个HTTP（GET）请求报文
浏览器获取主机ip地址，过程如下：
浏览器缓存
本机缓存
hosts文件
路由器缓存
ISP DNS缓存
DNS递归查询（可能存在负载均衡导致每次IP不一样）
打开一个socket与目标IP地址，端口建立TCP链接，三次握手如下：
客户端发送一个TCP的SYN=1，Seq=X的包到服务器端口
服务器发回SYN=1， ACK=X+1， Seq=Y的响应包
客户端发送ACK=Y+1， Seq=Z
TCP链接建立后发送HTTP请求
服务器接受请求并解析，将请求转发到服务程序，如虚拟主机使用HTTP Host头部判断请求的服务程序
服务器检查HTTP请求头是否包含缓存验证信息如果验证缓存新鲜，返回304等对应状态码
处理程序读取完整请求并准备HTTP响应，可能需要查询数据库等操作
服务器将响应报文通过TCP连接发送回浏览器
浏览器接收HTTP响应，然后根据情况选择关闭TCP连接或者保留重用，关闭TCP连接的四次握手如下：
主动方发送Fin=1， Ack=Z， Seq= X报文
被动方发送ACK=X+1， Seq=Z报文
被动方发送Fin=1， ACK=X， Seq=Y报文
主动方发送ACK=Y， Seq=X报文
浏览器检查响应状态吗：是否为1XX，3XX， 4XX， 5XX，这些情况处理与2XX不同
如果资源可缓存，进行缓存
对响应进行解码（例如gzip压缩）
根据资源类型决定如何处理（假设资源为HTML文档）
解析HTML文档，构件DOM树，下载资源，构造CSSOM树，执行js脚本，这些操作没有严格的先后顺序，以下分别解释
构建DOM树：
Tokenizing：根据HTML规范将字符流解析为标记
Lexing：词法分析将标记转换为对象并定义属性和规则
DOM construction：根据HTML标记关系将对象组成DOM树
解析过程中遇到图片、样式表、js文件，启动下载
构建CSSOM树：
Tokenizing：字符流转换为标记流
Node：根据标记创建节点
CSSOM：节点创建CSSOM树
根据DOM树和CSSOM树构建渲染树 

从DOM树的根节点遍历所有可见节点，不可见节点包括：1）script,meta这样本身不可见的标签。2)被css隐藏的节点，如display: none
对每一个可见节点，找到恰当的CSSOM规则并应用
发布可视节点的内容和计算样式
js解析如下：
浏览器创建Document对象并解析HTML，将解析到的元素和文本节点添加到文档中，此时document.readystate为loading
HTML解析器遇到没有async和defer的script时，将他们添加到文档中，然后执行行内或外部脚本。这些脚本会同步执行，并且在脚本下载和执行时解析器会暂停。这样就可以用document.write()把文本插入到输入流中。同步脚本经常简单定义函数和注册事件处理程序，他们可以遍历和操作script和他们之前的文档内容
当解析器遇到设置了async属性的script时，开始下载脚本并继续解析文档。脚本会在它下载完成后尽快执行，但是解析器不会停下来等它下载。异步脚本禁止使用document.write()，它们可以访问自己script和之前的文档元素
当文档完成解析，document.readState变成interactive
所有defer脚本会按照在文档出现的顺序执行，延迟脚本能访问完整文档树，禁止使用document.write()
浏览器在Document对象上触发DOMContentLoaded事件
此时文档完全解析完成，浏览器可能还在等待如图片等内容加载，等这些内容完成载入并且所有异步脚本完成载入和执行，document.readState变为complete，window触发load事件
显示页面（HTML解析过程中会逐步显示页面）
详细简版

从浏览器接收url到开启网络请求线程（这一部分可以展开浏览器的机制以及进程与线程之间的关系）

开启网络线程到发出一个完整的HTTP请求（这一部分涉及到dns查询，TCP/IP请求，五层因特网协议栈等知识）

从服务器接收到请求到对应后台接收到请求（这一部分可能涉及到负载均衡，安全拦截以及后台内部的处理等等）

后台和前台的HTTP交互（这一部分包括HTTP头部、响应码、报文结构、cookie等知识，可以提下静态资源的cookie优化，以及编码解码，如gzip压缩等）

单独拎出来的缓存问题，HTTP的缓存（这部分包括http缓存头部，ETag，catch-control等）

浏览器接收到HTTP数据包后的解析流程（解析html-词法分析然后解析成dom树、解析css生成css规则树、合并成render树，然后layout、painting渲染、复合图层的合成、GPU绘制、外链资源的处理、loaded和DOMContentLoaded等）

CSS的可视化格式模型（元素的渲染规则，如包含块，控制框，BFC，IFC等概念）

JS引擎解析过程（JS的解释阶段，预处理阶段，执行阶段生成执行上下文，VO，作用域链、回收机制等等）

其它（可以拓展不同的知识模块，如跨域，web安全，hybrid模式等等内容）

#5 如何进行网站性能优化
content方面

减少HTTP请求：合并文件、CSS精灵、inline Image
减少DNS查询：DNS缓存、将资源分布到恰当数量的主机名
减少DOM元素数量
Server方面

使用CDN
配置ETag
对组件使用Gzip压缩
Cookie方面

减小cookie大小
css方面

将样式表放到页面顶部
不使用CSS表达式
使用<link>不使用@import
Javascript方面

将脚本放到页面底部
将javascript和css从外部引入
压缩javascript和css
删除不需要的脚本
减少DOM访问
图片方面

优化图片：根据实际颜色需要选择色深、压缩
优化css精灵
不要在HTML中拉伸图片
你有用过哪些前端性能优化的方法？

减少http请求次数：CSS Sprites, JS、CSS源码压缩、图片大小控制合适；网页Gzip，CDN托管，data缓存 ，图片服务器。
前端模板 JS+数据，减少由于HTML标签导致的带宽浪费，前端用变量保存AJAX请求结果，每次操作本地变量，不用请求，减少请求次数
用innerHTML代替DOM操作，减少DOM操作次数，优化javascript性能。
当需要设置的样式很多时设置className而不是直接操作style
少用全局变量、缓存DOM节点查找的结果。减少IO读取操作
避免使用CSS Expression（css表达式)又称Dynamic properties(动态属性)
图片预加载，将样式表放在顶部，将脚本放在底部 加上时间戳
避免在页面的主体布局中使用table，table要等其中的内容完全下载之后才会显示出来，显示比div+css布局慢
谈谈性能优化问题

代码层面：避免使用css表达式，避免使用高级选择器，通配选择器
缓存利用：缓存Ajax，使用CDN，使用外部js和css文件以便缓存，添加Expires头，服务端配置Etag，减少DNS查找等
请求数量：合并样式和脚本，使用css图片精灵，初始首屏之外的图片资源按需加载，静态资源延迟加载
请求带宽：压缩文件，开启GZIP
前端性能优化最佳实践？

性能评级工具（PageSpeed 或 YSlow）
合理设置 HTTP 缓存：Expires 与 Cache-control
静态资源打包，开启 Gzip 压缩（节省响应流量）
CSS3 模拟图像，图标base64（降低请求数）
模块延迟(defer)加载/异步(async)加载
Cookie 隔离（节省请求流量）
localStorage（本地存储）
使用 CDN 加速（访问最近服务器）
启用 HTTP/2（多路复用，并行加载）
前端自动化（gulp/webpack）
#6 HTTP状态码及其含义
1XX：信息状态码
100 Continue 继续，一般在发送post请求时，已发送了http header之后服务端将返回此信息，表示确认，之后发送具体参数信息
2XX：成功状态码
200 OK 正常返回信息
201 Created 请求成功并且服务器创建了新的资源
202 Accepted 服务器已接受请求，但尚未处理
3XX：重定向
301 Moved Permanently 请求的网页已永久移动到新位置。
302 Found 临时性重定向。
303 See Other 临时性重定向，且总是使用 GET 请求新的 URI。
304 Not Modified 自从上次请求后，请求的网页未修改过。
4XX：客户端错误
400 Bad Request 服务器无法理解请求的格式，客户端不应当尝试再次使用相同的内容发起请求。
401 Unauthorized 请求未授权。
403 Forbidden 禁止访问。
404 Not Found 找不到如何与 URI 相匹配的资源。
5XX: 服务器错误
500 Internal Server Error 最常见的服务器端错误。
503 Service Unavailable 服务器端暂时无法处理请求（可能是过载或维护）
#7 语义化的理解
用正确的标签做正确的事情！
HTML语义化就是让页面的内容结构化，便于对浏览器、搜索引擎解析；
在没有样式CSS情况下也以一种文档格式显示，并且是容易阅读的。
搜索引擎的爬虫依赖于标记来确定上下文和各个关键字的权重，利于 SEO。
使阅读源代码的人对网站更容易将网站分块，便于阅读维护理解
#

https://github.com/poetries/FE-Interview-Questions/issues/2
