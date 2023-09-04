---
title: front-end
date: 2022-03-03
---

## JavaScript 

函数是 JavaScript 唯一的 Local Scope




script(src="LAB.js" async)
$LAB.script("framework.js").wait()
    .script("plugin.framework.js")
    .script("myplugin.framework.js").wait()
    .script("init.js");



Sugar

$LAB
.script( [ "script1.js", "script2.js", "script3.js"] )
.wait(function(){ // wait for all scripts to execute first
    script1Func();
    script2Func();
    script3Func();
});




###  闭包

### IIFE

### this

### prototype 

### 一些底层实现（ES、VO、AO）

## ES6 已经问世，包括 class, module

### arrow function

## Ajax、JSON、HTTP 请求、GET/POST 差异、RESTful、URL hash/query、webSocket、常用的跨域方式（JSONP/CORS、HTTP 强缓存/协商缓存，以及如何利用 CDN 、静态网站/动态网站区别、服务器端渲染/前端渲染区别等等

## CSS

### CSS 3

用 Scss/Less 等编译到 CSS 的语言，使用 autoprefixer 等 PostCSS 工具，了解 CSS 在 Scope/Namespace 上的缺陷，你还可以学习 CSS Modules、CSS in JS 这些有趣的新玩意

你需要非常了解前端的模块化规范，可能在你学习到这里的时候，Require.js/AMD 已经再见了，但是 CommonJS 与 ES6 Modules 你必须要了解。（你可以观看我的分享《JavaScript Modularization Seven Day》 来学习 JS 模块化的历史）

你需要熟悉 Git 与 Shell 的使用，包括基于 git 的版本管理、分支管理与团队协作，包括简单的 Linux/Unix 命令、你要知道大部分程序员的工作可以通过 shell 更快更酷的完成，并且很多“软件”只能通过 shell 来使用。你还可以把你的代码放到 github 上与人分享，并且学习 github 上其他优秀的开源代码

你需要熟悉并且习惯使用 Node，包括了解 npm、使用 Grunt/Gulp/Browserify/Webpack 优化你的工作流、对你的代码进行打包、混淆、压缩、发布，你还可以使用 Express/Koa 配合 MongoDB/Redis 涉足到后端领域，或者尝试用 Node 做后端渲染优化你的首屏体验

你需要了解各种 HTML 5 的新 API，包括 <video>/<audio>，包括 Canvas，webGL、File API、App Cache、localStorage、IndexedDB、Drag & Drop、更高级的 DOM API、Fetch API 等等

你需要学习 JavaScript 的单线程与异步编程方法，因为它们非常非常常用、包括 setTimeout/setInterval，回调与回调地狱、事件与event loop、还有 Promise 甚至 Async/Await

你需要非常了解浏览器，包括主流浏览器的名称、内核与差异、包括私有属性与 -webkit- 等厂商前缀，你需要学习如何使用 Chrome DevTool，你需要了解浏览器渲染的 reflow/repaint 来避免 Jank 并进行有针对性的性能优化

你需要专门学习 Mobile Web，因为移动互联网是趋势。包括 viewport、CSS pixel、 touch 事件、iOS/Android 浏览器的差异与兼容、移动端的性能优化、300ms delay 等等…你还需要知道 Hybrid 是什么，包括 Cordova/Phonegap，更复杂的比如和 iOS/Android 通信的机制，比如 URI Scheme 或者 JS Bridge

你需要学习一些非常火热的前端框架/库，他们不但能帮助你更快的进行开发、更重要的是他们背后所蕴含的思想。包括 Backbone、Angular、Vue、React、Polymer 等等、了解它们背后的双向数据绑定、单向数据流、MVC/MVVM/Flux 思想、Web Component 与组件化等等

## Low-Code

## Bundleless 也随着 Snowpack，Vite 的发布越来越火热

frontend code refactor, the knowledge map will include:
1.Typescript
2.rxjs
3.Angular framework knowledge (also includes the best practice)
4.Apollo GQL client (client lib helps with the GQL request and it also supports Angular framework .https://www.apollographql.com/docs/angular/basics/mutations.html)

For the frontend style framework, Bootstrap-4.0 is in consideration.
Also some other frameworks which support Angular can also work well:
1. ant-design (open sourced by Alibaba, the Angular support version is called ng-zorro-antd
https://ng.ant.design/docs/introduce/en)
2. Angular Material Design (official framework with less features compared with ant-design. https://material.angular.io/)



I choose ng-alain, which is a out-of-box solution for enterprise app based on Angular, ant-design and ng-zorro-antd.
It supports many out-of-the-box components such as form, login page, layout with side-bar and header ...
See the details in https://netlify.ng-alain.com/en; Online demo : https://ng-alain.github.io/ng-alain/#/dashboard/v1

Currently I am focusing on checking the usage of these existing components and seeing what can be used in our refactor.
I already have a static page in my VM and will keep on working on it. See the screenshot below.

Leon, let's talk about this in our next sync-up. ng-alain is a single contributor project. We should try and stick with more main stream projects backed by established software development houses; better community support and long-term road-maps with transition options when migrating to newer technologies.


## FRONT-END FRAMEWORKS & LIBRARIES

### ANGULAR
TYPESCRIPT

### REACT
- JAVASCRIPT
- TYPESCRIPT

### VUE 3
JAVASCRIPT

# 爆栈
系统开发技术栈、Web前端开发技术栈、数据库技术栈、.NET技术栈！
http://overflowstack.github.io

# 本地化
English:
https://github.com/unruledboy/WebFrontEndStack/

中文博客:
http://www.cnblogs.com/unruledboy/p/WebFrontEndStack.html

Español:
https://github.com/unruledboy/WebFrontEndStack/blob/master/README.es-es.md


# Web前端技术栈
比较全面的浏览器、平台、类库、框架、工具等。

![Image of Web Front End Stack](Web Front End Stack.zh-cn.png)

# 自行生成预览图

## 准备环境
您应该安装Visual Studio 2010+。

1. 安装 [nodejs](https://nodejs.org).

2. 安装 [Phantomjs](http://phantomjs.org).

3. 安装 [Python 2.7](https://www.python.org/).

4. ``npm install``

如果出现错误，您可以检查 [phantomjs-node] 的依赖(https://github.com/sgentle/phantomjs-node/wiki), [node-gyp](https://github.com/TooTallNate/node-gyp#installation).

## 运行命令
``npm start`` 运行服务并直接打开主html文件。

``npm run build`` 生成预览图。


## 选项
```

  -h, --help                           Display this message.
  -p, --port number                    (Default: 3000) Set the port what express listening.
  -ues, --update_existed_stargazers    (Default: false) Update project's stargazers including existed.
  --phantomjs                          The task to generate the image.
  --readme                             The task to update readme.
  --updatestargazers                   The task to update the count of the stargazers.

```

# 为什么？
大家是否想过：
* Web前端开发究竟包含哪些技术呢？
* 我所掌握的技术这个子集，在Web前端技术大系这个超集里面占的比例是多少呢？
* 我究竟还没有掌握多少Web前端技术呢？
* 面试的时候会考哪些技术呢？


那么，Web前端开发是否也应该有这样的技术栈概览图呢？搜索了很久，没有找到一个符合我要求的“较为全面”地表述Web前端技术大系的图表。所以我们自行设计了这个Web前端技术栈。

这个图表里的分类未必准确，相关技术也难免会有遗漏，欢迎大家指点以便不断改进。

Web前端技术实在太繁多限于篇幅，，这里没有罗列一些技术。

您可以点击下面链接查看交互式预览图(用鼠标移动/缩放/点击节点打开相关网站)：

https://rawgit.com/unruledboy/WebFrontEndStack/master/ux/WebFrontEndStack.htm?locale=zh-cn


# Web前端技术栈
<!--BUILD_START-->

- Web前端开发技术栈
	- 浏览器
		- [Internet Explorer](http://windows.microsoft.com/en-us/internet-explorer/download-ie)
		- [Chrome](http://www.google.com/chrome/)
		- [Firefox](https://www.mozilla.org/)
		- [Safari](http://www.apple.com/safari/)
		- [Opera](http://www.opera.com/)
		- [Edge](https://www.microsoft.com/en-us/windows/microsoft-edge)
		- [Netscape ;-)](https://en.wikipedia.org/wiki/Netscape)
	- 协议
		- [HTTP/1.1](https://www.ietf.org/rfc/rfc2616.txt)
			- 链接
			- 会话
			- 授权
			- 请求
			- 响应
		- [HTTP/2](https://en.wikipedia.org/wiki/HTTP/2)
			- 压缩
			- 打包
			- 服务器端推送
		- WebSocket
	- Web三剑客
		- HTML (HyperText Markup Language)
		- CSS (Cascading Style Sheets)
		- JavaScript
	- 标准
		- W3C
			- HTML
			- CSS
			- XHTML
			- XML
	- 核心概念
		- HTML
			- [DOM](https://developer.mozilla.org/en-US/docs/Web/API/Document_Object_Model)
			- [Element](https://developer.mozilla.org/en-US/docs/Web/API/Element)
			- Attribute
		- JavaScript
			- [Prototype](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/prototype)
			- [Scope](https://developer.mozilla.org/en-US/docs/Glossary/Scope)
			- [Closure](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Closures)
			- [JSON (JavaSript Object Notation)](https://developer.mozilla.org/en-US/docs/Glossary/JSON)
			- [AJAX (Asynchronous JavaScript and XML)](https://developer.mozilla.org/en-US/docs/AJAX)
		- CSS
			- Selector
			- Priority
			- Specificity
			- Box Model
	- 渲染引擎
		- [Trident (IE)](https://en.wikipedia.org/wiki/Trident_(layout_engine))
		- [Blink / prev. WebKit (Chrome)](http://www.chromium.org/blink)
		- [Gecko (Firefox)](https://developer.mozilla.org/en-us/docs/Mozilla/Gecko)
		- [WebKit (Safari)](http://www.webkit.org/)
		- [Blink / prev. Presto (Opera)](http://www.chromium.org/blink)
		- [EdgeHTML (Edge)](https://en.wikipedia.org/wiki/EdgeHTML)
	- 脚本引擎
		- [JScript (IE8- / ASP)](https://en.wikipedia.org/wiki/JScript)
		- [Chakra (IE9+ / Edge)](https://en.wikipedia.org/wiki/Chakra_(JScript_engine))
		- [V8 (Chrome / Opera / Nodejs / MongoDB)](https://developers.google.com/v8/?hl=zh-CN) [[GitHub]](https://github.com/v8/v8/)
		- [SpiderMonkey (Firefox)]( https://developer.mozilla.org/en-us/docs/Mozilla/Projects/SpiderMonkey)
		- [JavaScriptCore (Safari)](https://en.wikipedia.org/wiki/WebKit#JavaScriptCore)
	- 运行时
		- Cookie
		- Local Cache
		- Session Storage
		- Local Storage
		- Components
			- Extensions
			- Plugins
		- Resources
			- Images
			- Icons
			- Fonts
			- Audios
			- Videos
	- 编辑器
		- [Sublime Text](http://www.sublimetext.com/)
		- [WebStorm](https://www.jetbrains.com/webstorm/)
		- [Atom](https://atom.io/) [[GitHub]](https://github.com/atom/atom/)
		- [Vim](http://www.vim.org/)
		- [Emacs](https://www.gnu.org/software/emacs/)
		- [Brackets](http://brackets.io/) [[GitHub]](https://github.com/adobe/brackets/)
		- [Light Table](http://lighttable.com/) [[GitHub]](https://github.com/LightTable/LightTable/)
		- [Visual Studio](https://www.visualstudio.com/)
		- [Visual Studio Code (Linux & Mac)](https://code.visualstudio.com/) [[GitHub]](https://github.com/Microsoft/vscode)
		- Dreamweaver ;-)
		- FrontPage / SharePoint Designer ;-)
	- 编译任务
		- 精简
		- 编译
		- 合并
		- 混淆
		- 图像优化
		- 单元测试
	- 编译工具
		- [Grunt](http://www.gruntjs.com/) [[GitHub]](https://github.com/cowboy/jquery-tiny-pubsub/)
		- [Gulp](http://gulpjs.com/) [[GitHub]](https://github.com/gulpjs/gulp/)
		- [Brunch](http://brunch.io/) [[GitHub]](https://github.com/brunch/brunch/)
		- [Yeoman](http://yeoman.io/)
		- Broccoli [[GitHub]](https://github.com/broccolijs/broccoli/)
	- 调试
		- [Developer Tools](https://developer.chrome.com/devtools)
		- [Firebug](http://getfirebug.com/) [[GitHub]](https://github.com/firebug/firebug/)
	- 基础工具
		- [Node.js](https://nodejs.org/) [[GitHub]](https://github.com/joyent/node/)
		- [Phantom.js](http://phantomjs.org/) [[GitHub]](https://github.com/ariya/phantomjs/)
		- [SpiderMonkey](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/SpiderMonkey)
	- 质量控制
		- [JSLint](http://www.jslint.com/) [[GitHub]](https://github.com/douglascrockford/JSLint/)
		- [JSHint](http://jshint.com/) [[GitHub]](https://github.com/jshint/jshint/)
		- [jscs](http://jscs.info/) [[GitHub]](https://github.com/jscs-dev/node-jscs)
		- [Closure Linter](https://developers.google.com/closure/utilities/)
	- 包管理
		- [npm](https://www.npmjs.com/) [[GitHub]](https://github.com/npm/npm/)
		- [Bower](http://bower.io/) [[GitHub]](https://github.com/bower/bower/)
	- 测试
		- 工具
			- [QUnit](https://qunitjs.com/) [[GitHub]](https://github.com/jquery/qunit/)
			- [Jasmine](http://jasmine.github.io/) [[GitHub]](https://github.com/jasmine/jasmine/)
			- [Mocha](https://mochajs.org/) [[GitHub]](https://github.com/mochajs/mocha/)
			- [Selenium](http://www.seleniumhq.org/) [[GitHub]](https://github.com/SeleniumHQ/selenium/)
			- [WebDriverIO](http://webdriver.io/) [[GitHub]](https://github.com/webdriverio/webdriverio/)
			- [Protractor](http://www.protractortest.org/)
			- [Chai](http://chaijs.com/) [[GitHub]](https://github.com/jfirebaugh/konacha/)
			- [Sinon.JS](http://sinonjs.org/) [[GitHub]](https://github.com/cjohansen/Sinon.JS/)
			- [Karma](http://karma-runner.github.io/) [[GitHub]](https://github.com/karma-runner/karma/)
			- nodeunit [[GitHub]](https://github.com/caolan/nodeunit/)
			- tape [[GitHub]](http://github.com/substack/tape)
			- [nightmare](http://nightmarejs.org/) [[GitHub]](https://github.com/segmentio/nightmare)
		- 在线工具
			- [Sauce Labs](https://saucelabs.com/)
			- [Browser Stack](https://www.browserstack.com/)
			- [Browser Shots](http://browsershots.org/)
			- [Browserling](https://www.browserling.com/)
			- [Browser Sandbox](https://spoon.net/browsers/)
			- [Cross Browser Testing](https://crossbrowsertesting.com/)
			- [Browsera](http://www.browsera.com/)
			- [SortSite](http://www.powermapper.com/products/sortsite/checks/browser-compatibility/)
	- 库 / 框架
		- 基础库
			- [jQuery](https://jquery.com/) [[GitHub]](https://github.com/jquery/jquery/)
			- [Prototype](http://prototypejs.org/) [[GitHub]](https://github.com/sstephenson/prototype/)
			- [Zepto](http://zeptojs.com/) [[GitHub]](https://github.com/madrobby/zepto/)
			- [MooTool](http://mootools.net/) [[GitHub]](https://github.com/mootools/mootools-core/)
		- 模块化
			- ES6 Module
			- CommonJS
				- [webpack](http://webpack.github.io/) [[GitHub]](https://github.com/webpack/webpack/)
				- [browserify](http://browserify.org/) [[GitHub]](https://github.com/substack/node-browserify/)
			- AMD
				- [RequireJS](http://requirejs.org/) [[GitHub]](https://github.com/jrburke/requirejs/)
			- UMD
				- umd [[GitHub]](https://github.com/umdjs/umd/)
		- 框架
			- [AngularJS](https://angularjs.org/) [[GitHub]](https://github.com/angular/angular.js/)
			- [Backbone](http://backbonejs.org/) [[GitHub]](https://github.com/jashkenas/backbone/)
			- [Knockout](http://knockoutjs.com/) [[GitHub]](https://github.com/SteveSanderson/knockout/)
			- [Ember](http://emberjs.com/) [[GitHub]](https://github.com/emberjs/ember.js/)
			- [React](http://facebook.github.io/react/) [[GitHub]](https://github.com/facebook/react/)
			- [polymer](https://www.polymer-project.org/) [[GitHub]](https://github.com/polymer/polymer/)
			- [Deft.js](http://deftjs.org/) [[GitHub]](https://github.com/deftjs/DeftJS/)
			- [Vue](http://vuejs.org/) [[GitHub]](https://github.com/yyx990803/vue/)
			- [Riot](http://riotjs.com/) [[GitHub]](https://github.com/riot/riot)
		- UI框架
			- [Bootstrap](http://getbootstrap.com/) [[GitHub]](https://github.com/twbs/bootstrap/)
			- [Semantic UI](http://semantic-ui.com/) [[GitHub]](https://github.com/Semantic-Org/Semantic-UI/)
			- [Foundation](http://foundation.zurb.com/) [[GitHub]](https://github.com/zurb/foundation/)
			- [Material UI](http://material-ui.com/) [[GitHub]](https://github.com/callemall/material-ui/)
			- [WinJS](https://dev.windows.com/en-us/develop/winjs) [[GitHub]](https://github.com/winjs/winjs)
			- [Pure](http://purecss.io/) [[GitHub]](https://github.com/yahoo/pure/)
			- [Amaze UI](http://amazeui.org/) [[GitHub]](https://github.com/allmobilize/amazeui)
		- WebSocket
			- [Socket.io](http://socket.io/) [[GitHub]](https://github.com/Automattic/socket.io/)
			- web-socket-js [[GitHub]](https://github.com/gimite/web-socket-js/)
		- 数据可视化
			- [D3](http://d3js.org/) [[GitHub]](https://github.com/mbostock/d3/wiki/Gallery/)
			- [Echarts](http://echarts.baidu.com) [[GitHub]](https://github.com/ecomfe/esl/)
			- [HighCharts](http://www.highcharts.com/) [[GitHub]](https://github.com/highslide-software/highcharts.com/)
			- [Vis.js](http://visjs.org/) [[GitHub]](https://github.com/almende/vis/)
			- [Flot](http://www.flotcharts.org/) [[GitHub]](https://github.com/flot/flot/)
		- WebGL
			- [Three.js](http://threejs.org/) [[GitHub]](https://github.com/mrdoob/three.js/)
			- [Babylon.js](http://www.babylonjs.com/) [[GitHub]](https://github.com/BabylonJS/Babylon.js/)
			- [Pixi.js](http://www.pixijs.com/) [[GitHub]](https://github.com/GoodBoyDigital/pixi.js/)
		- CSS3 动画
			- [Animate.css](https://daneden.github.io/animate.css/) [[GitHub]](https://github.com/daneden/animate.css/)
			- [bounce.js](http://bouncejs.com/) [[GitHub]](https://github.com/tictail/bounce.js/)
			- [Effeckt.css](https://h5bp.github.io/Effeckt.css/) [[GitHub]](https://github.com/h5bp/Effeckt.css/)
			- [move.js](https://visionmedia.github.io/move.js/) [[GitHub]](https://github.com/visionmedia/move.js/)
		- 流程控制
			- ES6
				- Promise
				- Generator
			- ES7
				- yield
				- await
			- async [[GitHub]](https://github.com/caolan/async/)
			- co [[GitHub]](https://github.com/tj/co/)
			- Promise
				- Bluebird [[GitHub]](https://github.com/petkaantonov/bluebird/)
				- q [[GitHub]](https://github.com/kriskowal/q/)
				- when.js [[GitHub]](https://github.com/cujojs/when/)
		- 函数式编程
			- [bacon.js](http://baconjs.github.io/) [[GitHub]](https://github.com/baconjs/bacon.js/)
			- [immutable.js](https://facebook.github.io/immutable-js/) [[GitHub]](https://github.com/facebook/immutable-js/)
			- [ramda](http://ramdajs.com/) [[GitHub]](http://github.com/ramda/ramda)
			- [underscore.js](http://underscorejs.org/) [[GitHub]](https://github.com/jashkenas/underscore)
			- [lodash](https://lodash.com/) [[GitHub]](https://github.com/lodash/lodash)
			- [ReactiveX](http://reactivex.io/) [[GitHub]](https://github.com/Reactive-Extensions/RxJS)
		- 手机 UI 框架
			- [jQuery Mobile](https://jquerymobile.com/) [[GitHub]](https://github.com/jquery/jquery-mobile/)
			- [Jo](http://joapp.com/) [[GitHub]](https://github.com/davebalmer/jo/)
			- [Dojo Mobile](https://dojotoolkit.org/reference-guide/1.10/dojox/mobile.html)
			- [Lungo](http://lungo.tapquo.com/) [[GitHub]](https://github.com/tapquo/Lungo.js/)
	- CSS 预处理器
		- LESS
			- [LESS](http://lesscss.org/) [[GitHub]](https://github.com/less/less.js/)
			- [Hat](http://lesshat.madebysource.com/) [[GitHub]](https://github.com/csshat/lesshat/)
		- Sass(SCSS)
			- [Compass](http://compass-style.org/) [[GitHub]](https://github.com/chriseppstein/compass/)
			- [Bourbon](http://bourbon.io/) [[GitHub]](https://github.com/thoughtbot/bourbon/)
			- [Gumby](http://www.gumbyframework.com/) [[GitHub]](https://github.com/GumbyFramework/Gumby/)
		- Stylus
			- nib [[GitHub]](https://github.com/tj/nib/)
	- 未来标准
		- [babel](https://babeljs.io/) [[GitHub]](https://github.com/babel/babel)
	- 模板引擎
		- [Handlebars](http://handlebarsjs.com/) [[GitHub]](https://github.com/wycats/handlebars.js/)
		- [Haml](http://haml.info/) [[GitHub]](https://github.com/haml/haml/)
		- [Slim](http://slim-lang.com/) [[GitHub]](https://github.com/slim-template/slim/)
		- [Jade](http://jade-lang.com/) [[GitHub]](https://github.com/jadejs/jade/)
		- [Ejs](http://www.embeddedjs.com/)
		- [Spacebars](http://meteorcapture.com/spacebars/)
		- [mustache](http://mustache.github.io/) [[GitHub]](https://github.com/janl/mustache.js/)
	- 统一化
		- [Normalize](http://necolas.github.io/normalize.css/) [[GitHub]](https://github.com/necolas/normalize.css/)
		- Reset
	- 最佳实践
		- [SEO](https://en.wikipedia.org/wiki/Search_engine_optimization)
		- Responsiveness
		- [CDN](https://en.wikipedia.org/wiki/Content_delivery_network)
	- 安全
		- Sandbox
		- [XSS](https://en.wikipedia.org/wiki/Cross-site_scripting)
		- [CORS](http://www.w3.org/TR/cors/)
	- 中间语言
		- [CoffeeScript](http://coffeescript.org/) [[GitHub]](https://github.com/jashkenas/coffeescript/)
		- [TypeScript](http://www.typescriptlang.org/) [[GitHub]](https://github.com/Microsoft/TypeScript/)
		- ClojureScript [[GitHub]](https://github.com/clojure/clojurescript/)
		- [JSX (Facebook)](http://facebook.github.io/react/docs/jsx-in-depth.html)
	- 移动应用开发
		- [PhoneGap / Cordova](https://cordova.apache.org/) [[GitHub]](https://github.com/apache/cordova-android/)
		- [MUI](http://dev.dcloud.net.cn/mui/) [[GitHub]](https://github.com/dcloudio/mui/)
		- [React Native](https://facebook.github.io/react-native/) [[GitHub]](https://github.com/facebook/react-native/)
		- [Ionic](http://ionicframework.com/) [[GitHub]](https://github.com/driftyco/ionic/)
	- 桌面应用开发
		- [Electron](http://electron.atom.io/) [[GitHub]](https://github.com/atom/electron)
		- [NW.js](http://nwjs.io/) [[GitHub]](https://github.com/nwjs/nw.js)

<!--BUILD_END-->
### 心动网络游戏前端评审要点

本文档列出心动网络游戏前端评审关注要点。

* 具备热更新能力

	- 具备不通过市场审核更新游戏内容或进行修正bug的能力
	- 每次热更的文件数可控或固定数量（5个文件内），如超过应该通过压缩包更新
	- 热更新必须使用数字（Int）版本号而不能使用字符串比较（例如 5.x.x）

* iOS 10+: 关于在游戏启动时检查网络

	客户端启动后第一时间应检查网络是否可用。如果不可用则等待，并进行友好的提示（iOS 10设置引导说明）。直到网络通畅。

* iOS和安卓系统权限请求

	下所有申请系统授权的提示，包括推送、地理位置、拍照、地理位置、发送通知、蓝牙权限、读取扩展卡等，
	均不应该启动时要求授权，而是根据用户行为需求来设计提示授权时机。
	提示授权时，应该先在游戏界面UI内提示用户是否授权，当用户给予肯定的答复后，获得用户同意后再触发系统提示申请授权。
	不能调用 IMEI 串号。

* iOS: SDK 和代码中不能出现 wechat alipay 微信支付 或任何直接或间接导向至平台外充值的功能，包括不显示的入口或任何有嫌疑的关键字都不能出现在代码和 SDK 中

* 弱网络性能

	具备心跳机制检测弱网络，并具备数据包队列机制防止重连丢包等体验或bug问题

* 错误（Crash）日志收集机制

	用于快速定位bug，若版本不稳定可后迅速修正。可以使用例如 [Bugly](http://bugly.qq.com/)、[BugSense](http://bugsense.com/) 或 [TestIn] 的服务

* 接入 TapDB 数据统计系统 SDK

	用于运营数据分析和运营维护

* 下载CDN资源时能正确支持302转向

* 多语言支持

	有多语言支持机制，包括但不限于：
	- 文本通过特定的方法包裹后输出，例如: `_T("确定", "Main") // 默认返回'确定' `
	- 图片资源特定的方法包裹后输出，例如: `_I("/logo.png", "Main") // 默认返回'logo.png' `
	- 有多语言文本、图片资源数据（表格）文件
	- format 支持序号，例如 format("%[1]s name is %[2]s", "his", "john")

* 压缩

	图片素材使用 [pngquant](https://pngquant.org/) 压缩
	声音使用 AAC-HEv2 32Kbps 或更高压缩比方式


#### Google Play

* 返回按钮的功能应该是返回上一层UI、关闭弹窗或暂停游戏。而不是退出游戏

* TargetSDK 为 23 或更高

* 尽可能支持 Google Play Services ，例如成就和排行榜

* 参考： http://api.txwy.com/sdk_api/android/tw/#advanced-section-kb

#### 其他

* 非心动SDK的iOS充值系统

	iOS充值获得收据后保证先本地存储落地、放入队列，并将保存在例如UserDefault这类持久化的存储区。然后不断的从队列提取并执行充值，直到成功后再从队列移除。充值队列具有定时重试机制。保证游戏断网或Crash均不掉单，确保充值流程的可靠。

* 体积

	安装包体积尽量小。资源整体如能控制是90M以下，则可以在无wifi时安装，有助于提高转化率。

* 关注运行时内存峰值

	可参考 [市场设备占有率指数](http://www.umindex.com/) 。如果占用小于200M可以兼容 iPhone4S。


#### 安全
参考 [心动网络游戏安全评议要点](security.md)


前端的生态也发生了一些变化， Low-Code 大行其道，Bundleless 也随着 Snowpack，Vite 的发布越来越火热

