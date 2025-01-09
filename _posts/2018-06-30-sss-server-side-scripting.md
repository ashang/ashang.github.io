

React 使用客户端渲染（CSR）。React 应用程序在客户端处理 DOM，也就是在浏览器中。

每当我们加载一个 React 应用程序，所有的 UI 组件都会在浏览器上动态生成。

Next.js 和 SSR 如何工作？
如果你做了我们之前做的同样的事情，但用 Next.js 应用程序，你会得到不同的东西



Next.js 应用程序的源代码。我们看到整个内容，如 HTML、CSS 和 JavaScript。

这意味着，当 Next.js 应用程序加载时，我们在用户界面上看到的网络上的内容已经生成。而这是在服务器上发生的。这是因为 Next.js 利用了服务器端渲染（或 SSR），也被称为预渲染。

什么是 Pre-Rendering（预渲染）？
预渲染是服务器端渲染的一个例子，在浏览器上加载应用程序或网站之前，内容已经生成。

为什么使用 Pre-Rendering（预渲染）？
服务器端渲染（或预渲染）使应用程序的加载速度加快。这是因为我们将要看到的输出已经在服务器端生成。



React可用作开发具有Next.js等框架的单页、手机或服务器渲染应用程序的基础。然而，React只专注状态管理和将状态渲染到DOM，因此创建React应用程序通常需要使用额外的工具库来进行路由实现，以及某些客户端功能。


使用JSX和JavaScript在HTML中使用React的基本示例。

import React from "react";

const Greeting = () => {
  return (
    <div className="hello_world">
      <h1> Hello, world! </h1>
    </div>
  );
};

export default Greeting;
Greeting函数是一个React组件，渲染的结果为“Hello, world”。

在网页浏览器中显示时，结果将是以下内容的渲染：

<div class="hello_world">
  <h1>Hello, world!</h1>
</div>


[edit source]
React采取宣告式程序撰写范型。开发人员为应用程序的每个状态设计视图，React会在资料更改时更新和呈现组件。这与命令式程序撰写不同。



组件[edit source]
React代码由称为组件的实体组成。这些组件是可重复利用的，并且必须遵循大写驼峰命名法（Pascal Case）作为其命名规则，也就是大写版本的驼峰式命名法（camelCase）在src文件夹中形成。可以使用React DOM工具库将组件渲染到DOM中的特定元素。渲染组件时，可以通过“props”在组件之间传递参数值：[10]

import React from "react";
import Tool from "./Tool";
const Example = () => {
  return (
    <>
      <div className="app">
        <Tool name="Gulshan" />
      </div>
    </>
  );
};
  
export default Example;
在上面的示例中，值为“Gulshan”的name属性已从Example组件传递到Tool组件。

此外，return部分被包装在一个名为return的标签中，因为只能返回一个值。所以所有JSX元素和组件都绑定到一个标签中。

在React中宣告组件的两种主要方式是通过函数组件和基于类别组件。

函数组件[edit source]
函数组件用一个函数声明，然后返回一些JSX。

const Greeter = () => <div>Hello World</div>;
类别组件[edit source]
基于类的组件是使用ES6类声明。

class ParentComponent extends React.Component {
  state = { color: 'green' };
  render() {
    return (
      <ChildComponent color={this.state.color} />
    );
  }
}
类别组件都是关于类别的使用和生命周期方法的，而功能组件有Hooks来处理在React中编写代码时出现的状态管理和其他问题。

虚拟DOM[edit source]
另一个值得注意的特性是使用虚拟文档对象模型或虚拟DOM。React创建一个存储器数据结构暂存，计算结果差异，然后有效地更新浏览器显示的DOM。[11]这个过程称为reconciliation。这允许程序工程师撰写代码，就好像每次更改都会渲染整个页面，而React只渲染实际更改的子组件。这种选择性渲染提供了主要的性能提升。[12]节省了重新计算CSS样式、页面排版和渲染整个页面的工作量。[12]

生命周期方法[edit source]
基于类别组件的生命周期方法使用一种挂钩（Hooking）形式，允许在组件生命周期内的设置点执行代码。

shouldComponentUpdate 允许开发人员通过在不需要渲染时返回false来防止不必要的组件重新渲染。
componentDidMount只要一旦组件“挂载（mounted）”（组件已在用户界面中创建，通常通过将其与DOM节点关系），就会被调用。这通常用于通过API触发从远程数据源加载资料。
componentWillUnmount 在组件被移除或“卸载”（unmounted）之前立即被调用。通常用于清除对组件的资源需求相依性模块，这相依性模块不会随着组件的卸载而容易地被删除（例如，删除与组件相关的任何 setInterval() ，或设置于“文件”的“事件监听”（eventListener），因为组件的存在）。
render是最重要的生命周期方法，也是任何组件中唯一需要的方法。它通常在每次组件状态更新时调用，也就是应该反映在用户界面中。
JSX[edit source]
JSX或JavaScript语法扩展，是JavaScript语言语法的扩展。[13] 在外表上与HTML类似，JSX提供了一种使用许多开发人员熟悉的语法来构建组件渲染的方法。React组件通常使用JSX撰写，尽管它们并非必须如此（组件也可以使用纯JavaScript撰写）。JSX类似于Facebook为PHP创建的另一个扩展语法，称为XHP。

JSX代码示例：

class App extends React.Component {
  render() {
    return (
      <div>
        <p>Header</p>
        <p>Content</p>
        <p>Footer</p>
      </div>
    );
  }
}
HTML之外的架构[edit source]
React的基本架构不仅适用于在浏览器中呈现HTML。例如，Facebook有渲染到<canvas>标签，[14] Netflix 和 PayPal 使用通用加载于服务器和客户端上渲染相同的HTML。[15][16]

React hooks[edit source]
Hooks是让开发人员从函数组件中“钩入（Hook into）”React状态和生命周期特性的函数。Hooks在类别组件无法作用——它们让你在没用类别组件情况下使用React。[17]

React提供了一些内置的Hook，例如 useState,[18]useContext、useReducer、useMemo 与useEffect。[19] 其他的记录在Hooks API参考中。[20] useState 与useEffect，也就是最常用，分别用于状态和副作用的控制。

Hooks的使用规范[edit source]
下面有一些Hooks规范[21] 描述了钩子（Hooks）的特征代码模式，也是现今使用React处理状态方式。

Hooks只能在顶层调用（而不是在循环或if语句内）。
Hooks只能从React函数组件和自定义Hooks调用，而不是普通函数或类别组件。
虽然这些规范不能在执行时强制执行，但可以设置代码分析工具（例如linter）来侦测开发过程中的许多错误。

这些规范适用于Hooks的使用和自定义Hooks的实现，[22] 也就是可能会调用其他Hooks。

常用惯用语[edit source]
React并不刻意提供一个完整的“应用程序工具库”。专为构建用户界面而设计，因此不包含一些开发人员可能认为构建应用程序所必需的许多任务具。这也允许选择开发人员喜欢的任何工具库来完成诸如执行网络访问或本地资料存储等任务。随着工具库的成熟，常见的使用模式已经出现。

单向资料流[edit source]
为了支持React的单向资料流概念（可能与 AngularJS 的双向资料流形成对比），Flux架构被开发为流行的模型-视图-控制器架构的替代方案。Flux具有通过中央调度程序发送到存储区（Store）的操作，并且对存储区的更改被传递回视图。[23] 当与React一起使用时，这种传递是通过组件属性完成的。从Flux的概念开始，Flux就被Redux和MobX等工具库所取代。[24]

Flux可以被认为是观察者模式的一种变体。[25]

Flux架构下的React组件不应直接修改传递给它的任何props，而应传递回调函数，这些回调函数创建由调度程序发送的用于修改存储的操作。动作（Action）是一个对象，负责描述发生的事情：例如，描述一个用户“关注”另一个用户的动作可能包含用户ID、目标用户ID和类型USER_FOLLOWED_ANOTHER_USER。可以将存储视为模型，可以根据从调度程序接收到的操作来改变自己。

这种模式有时表示为“属性（Properties）向下流动，动作（Actions）向上流动”。Flux的许多实现从一开始就被创建了，也许最著名的是Redux，它具有单一存储，通常称为单一资料源。[26]



Next.js是一个构建于 Node.js 之上的开源 Web 开发框架，支持基于 React 的 Web 应用程序功能，例如服务端渲染和生成静态网站。 React 于官方文件内的“推荐的工具链”中提及 Next.js，建议将其作为“使用 Node.js 构建服务器渲染网站”的解决方案。[5] 传统的 React 应用程序只能在客户端浏览器中渲染内容，Next.js 扩展了此功能以包括在服务端渲染的应用程序。



背景
Next.js 是一个 React 框架，它支持一些额外的功能，包括服务端渲染和静态网站生成。[8] React 是一个 JavaScript 库，传统上用于构建使用 JavaScript 在客户端浏览器中渲染的网页应用程序。[9] 然而开发者意识到这种策略存在一些问题，例如无法满足无法访问或禁用 JavaScript 的用户、潜在的安全问题、明显延长页面加载时间以及可能损害网站的整体搜索引擎优化。[9] 诸如 Next.js 之类的框架利用允许在发送到客户端之前在服务端渲染部分或全部网站来避开这些问题。[9][10] Next.js 是最流行的 React 框架之一。[11] 它是启动新应用程序时可用的几个推荐“工具链”之一，所有这些都提供了一个抽象层来协助完成常见的任务。[12] Next.js 需要 Node.js 而且可以利用 Node Package Manager 进行启动。

Google 已向 Next.js 项目捐款，在 2019 年贡献了 43 个拉取请求（Pull request），协助修剪了未使用的 JavaScript、减少了加载时间与增加了改进指针。[13] 截至 2020 年 3 月，该框架已被许多大型网站使用，包括 Netflix、GitHub、Uber、Ticketmaster 和星巴克。[9] 2020 年初，Vercel宣布募得了 2100 万美元的 A 轮融资，用来支持软件的改进。[1] 该框架的原作者 Guillermo Rauch 目前是 Vercel 的 CEO，该项目的开发主管是 Tim Neutkens。[14]

发展历程
Next.js 于 2016 年 10 月 25 日首次在 GitHub 上作为开放源代码项目发布。.[3] 它最初是基于六个原则开发的：开箱即用的功能，无需设置，JavaScript 无处不在，所有功能都用 JavaScript 编写，自动代码拆分和服务器渲染，可配置的资料获取，预测请求和简化部署.[15] Next.js 2.0 于 2017 年 3 月发布，其中包括多项改善，使小型网站开发变得更加容易。 还提高了构建效率并提高了热模块更换功能的可扩展性。[16] 7.0 版于 2018 年 9 月发布，改进了错误处理并支持 React 的上下文 API 以改进动态路由处理。也是第一个升级到 webpack 4 的版本。[17] 8.0 版于 2019 年 2 月发布，是第一个提供无服务器应用程序部署的版本，其中代码被拆分为按需运行的匿名函数（Lambda function）。 该版本还减少了静态导出所需的时间和资源，并提高了预取性能。[18] 9.3 版于 2020 年 3 月发布，包括各种优化以及全局 Sass 和 CSS 模块支持。[19] 于2020 年 7 月 27 日，Next.js 9.5 版发布，增加了包括增量静态再生（incremental static regeneration ISR）、重新写入和重定向支持在内的新功能。[20]于 2021 年 6 月 15 日 Next.js 第 11 版发布，其中包括：Webpack 5 支持、实时协作编码功能预览“Next.js Live”，以及从 Create React App 自动转换为 Next.js 的实验性功能兼容形式“Create React App Migration”。[21] 2021 年 10 月 26 日，Next.js 12 发布，增加了 Rust 编译器，使编译速度更快，支持 AVIF，Edge Functions & 中间件，原生 ESM & URL 输入。[22]

样式和功能
Next.js 支持 CSS 样式以及预编译的 SCSS 和 SASS、CSS-in-JS 和Styled JSX。[12] 此外，它也利用 TypeScript 支持和智能捆绑构建。[23] 开放源代码编译器 Babel 用于将代码转换和编译成浏览器可用的 JavaScript。 Webpack，是另一个开放源代码工具，用于在之后打包模块。所有这些工具都在指令终端中与 NPM 一起使用。[13]

Next.js 的主要特点是使用服务端渲染来减轻网页浏览器的负担并提供增强安全性。 这可以针对应用程序的任何部分或整个项目完成，从而允许将内容丰富的页面单独挑出来用于服务端渲染。[9] 也可以仅针对首次访客进行，以减轻尚未下载任何网站资产的网络浏览器的负载。[10] “热重载（Hot reloading）”功能会在更改发生时侦测更改并重新渲染适当的页面，因此服务器也避免重启。 允许对应用程序的代码所做的更改立即反映在网页浏览器中，尽管某些浏览器会要求刷新。[9] 该软件使用基于文件系统的路由让开发更便利，与包括对动态路由的支持。其他功能包括热模块替换，以便可以实时替换模块，自动代码拆分，仅包括加载页面所需的代码，以及页面预取减少加载时间。[9]

Next.js 还支持增量静态再生 (ISR)[24] 和静态站点生成 (SSG) - 网站的编译版本通常会在构建期间构建并以.next 文件夹的型式存储。 当用户提出请求时，作为静态 HTML 页面的预构建版本将被缓存并发提交去。 这会使得加载时间非常快速，但它并非适合每个网站，尤其是对于经常更改并利用大量用户输入的交互式网站将会变得不适合。




Server-side scripting is a technique used in web development which involves employing scripts on a web server which produces a response customized for each user's (client's) request to the website. The alternative is for the web server itself to deliver a static web page. Scripts can be written in any of a number of server-side scripting languages that are available (see below). Server-side scripting is distinguished from client-side scripting where embedded scripts, such as JavaScript, are run client-side in a web browser, but both techniques are often used together.

Server-side scripting is often used to provide a customized interface for the user. These scripts may assemble client characteristics for use in customizing the response based on those characteristics, the user's requirements, access rights, etc. Server-side scripting also enables the website owner to hide the source code that generates the interface, whereas, with client-side scripting, the user has access to all the code received by the client. A downside to the use of server-side scripting is that the client needs to make further requests over the network to the server in order to show new information to the user via the web browser. These requests can slow down the experience for the user, place more load on the server, and prevent the use of the application when the user is disconnected from the server.

When the server serves data in a commonly used manner, for example, according to the HTTP or FTP protocols, users may have their choice of a number of client programs (most modern web browsers can request and receive data using both of those protocols). In the case of more specialized applications, programmers may write their own server, client, and communications protocol, that can only be used with one another.

Programs that run on a user's local computer without ever sending or receiving data over a network are not considered clients, and so the operations of such programs would not be considered client-side operations.


Contents
1	History
2	Explanation
3	Server-side rendering
4	Server-side generation
5	Languages
6	See also
7	References
8	External links
History
Netscape introduced an implementation of JavaScript for server-side scripting with Netscape Enterprise Server, first released in December, 1994 (soon after releasing JavaScript for browsers).[1][2]

Server-side scripting was later used in early 1995 by Fred Dufresne while developing the first website for Boston, MA television station WCVB. The technology is described in US patent 5835712. The patent was issued in 1998 and is now owned by Open Invention Network (OIN). In 2010 OIN named Fred DuFresne a "Distinguished Inventor" for his work on server-side scripting.

Explanation
In the earlier days of the web, server-side scripting was almost exclusively performed by using a combination of C programs, Perl scripts, and shell scripts using the Common Gateway Interface (CGI). Those scripts were executed by the operating system, and the results were served back by the webserver. Many modern web servers can directly execute on-line scripting languages such as ASP, JSP, Perl, PHP and Ruby either by the web server itself or via extension modules (e.g. mod_perl or mod_php) to the webserver. For example, WebDNA includes its own embedded database system. Either form of scripting (i.e., CGI or direct execution) can be used to build up complex multi-page sites, but direct execution usually results in less overhead because of the lower number of calls to external interpreters.

Dynamic websites sometimes use custom web application servers, such as Glassfish, Plack and Python's "Base HTTP Server" library, although some may not consider this to be server-side scripting. When using dynamic web-based scripting techniques, developers must have a keen understanding of the logical, temporal, and physical separation between the client and the server. For a user's action to trigger the execution of server-side code, for example, a developer working with classic ASP must explicitly cause the user's browser to make a request back to the webserver.

Server-side scripts are completely processed by the servers instead of clients. When clients request a page containing server-side scripts, the application server processes the scripts and returns an HTML page to the client.

## Server-side rendering

In the beginning of the web, content was generated purely on the back end. After the big adoption of front end single-page applications, a new approach was introduced to generate the HTML using the client application, but on the back end. Examples of frameworks that use SSR are Next.js, Nuxt.js and Nest.js. They use React.js, Vue.js, and Angular, respectively, to generate the content of the server.

## Server-side generation

Another similar to SSR technique of generating content for a website is using Server-side generation. This technique use application that create static html pages and then those files are send to the server. File generation can happen on completely different computer for example using continuous delivery. Example of SSG tools are Jekyll, Gatsby or Eleventy. Those sites are often hosted on Netlify or GitHub pages. GitHub also supports Jekyll projects where it automatically build the site when changes are added to git.

## Server-side scripting languages

- Go (*.go)
- JavaScript using Server-side JavaScript (*.ssjs, *.js) (example: Node.js)
- Python (*.py) (examples: Pyramid, Flask, Django)


