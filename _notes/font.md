---
#layout: page
layout: post
title:  "Font plex"
date:   2016-07-08
---

https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/securing_networks/configuring-a-vpn-with-ipsec_securing-networks


https://podman.io/get-started


https://medium.com/@mohit2501tyagi/lets-walk-through-podman-37636cf223c5

https://www.admin-magazine.com/Articles/Managing-containers-with-Podman/(offset)/3

https://www.redhat.com/sysadmin/image-stores-podman


https://docs.oracle.com/en/operating-systems/oracle-linux/podman/podman-ConfiguringStorageforPodman.html#podman-install-storage


> When you arise in the morning think of what a privilege it is to be alive, to think, to enjoy, to love ...”
> -- Marcus Aurelius

* ToC
{:toc}

## Images

![A diagram of the Ikigai concept.](index.assets/Ikigai@2x.png)

# Use the most recent version of jekyll-sass-converter, to force Dart Sass
```
gem "sass-embedded"
gem "jekyll-sass-converter", github: "jekyll/jekyll-sass-converter"
```

```
titles_from_headings:
  enabled: true
  strip_title: true
  collections: true
```

## Usage

To change the label of the mobile navigation menu, add this to your `_config.yml`:

```yaml
miniplex:
  mobile_nav_menu_title: "Menü"
```

## Features

- [ ] In-page navigation
- [ ] Footer
- [ ] Maximizable tables
- [ ] Breadcrumbs, if possible
- [ ] Side notes, if possible

- Responsive.
- Table reformatting for very small screens.
- Hamburger menu at the bottom right, easy to reach.

- [X] Dark mode
- [X] Print CSS
- [X] Mobile nav bugfixing
- [X] Post author & date flexibility
- [X] Add a post's date to the page layout, or to a separate post layout

```css
font-family: 'IBM Plex Mono', 'Menlo', 'DejaVu Sans Mono', 'Bitstream Vera Sans Mono', Courier, monospace;
font-family: 'IBM Plex Sans', 'Helvetica Neue', Arial, sans-serif;
font-family: 'IBM Plex Sans Condensed', 'Helvetica Neue', Arial, sans-serif;
font-family: 'IBM Plex Serif', 'Georgia', Times, serif;
```

<style>
  @import url('https://fonts.googleapis.com/css2?family=IBM+Plex+Mono:ital@0;1&family=IBM+Plex+Sans:ital,wght@1,100&display=swap');
</style>

font-family: 'IBM Plex Mono', monospace;
font-family: 'IBM Plex Sans', sans-serif;

<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=IBM+Plex+Mono:ital@0;1&family=IBM+Plex+Sans:ital,wght@1,100&display=swap" rel="stylesheet">

| Country                                                     | Capital | Population | Currency             |
| ----------------------------------------------------------- | ------- | ---------: | -------------------- |
| Switzerland (*Schweizerische Eidgenossenschaft* )           | Berne   |  8,636,896 | Swiss Franc (CHF)    |
| Germany (*Bundesrepublik Deutschland*)                      | Berlin  | 83,695,430 | Euro (EUR)           |
| France (*République française*)                             | Paris   | 67,897,000 | Euro (EUR)           |
| Italy (*Repubblica Italiana*)                               | Rome    | 61,095,551 | Euro (EUR)           |
| UK (*United Kingdom of Great Britain and Northern Ireland*) | London  | 67,791,400 | Pound sterling (GBP) |



## BPF CO-RE

 (Compile Once – Run Everywhere)

- https://nakryiko.com/posts/bpf-portability-and-co-re/




https://web.archive.org/web/20200630214856/https://medium.com/airbnb-engineering/sunsetting-react-native-1868ba28e30a


React只专注状态管理和将状态渲染到DOM，因此创建React应用程序通常需要使用额外的工具库来进行路由实现，以及某些客户端功能


React采取宣告式程序撰写范型。开发人员为应用程序的每个状态设计视图，React会在资料更改时更新和呈现组件。这与命令式程序撰写不同。[9]





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

函数组件
函数组件用一个函数声明，然后返回一些JSX。

const Greeter = () => <div>Hello World</div>;
类别组件
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

虚拟DOM
另一个值得注意的特性是使用虚拟文档对象模型或虚拟DOM。React创建一个存储器数据结构暂存，计算结果差异，然后有效地更新浏览器显示的DOM。[11]这个过程称为reconciliation。这允许程序工程师撰写代码，就好像每次更改都会渲染整个页面，而React只渲染实际更改的子组件。这种选择性渲染提供了主要的性能提升。[12]节省了重新计算CSS样式、页面排版和渲染整个页面的工作量。[12]

生命周期方法
基于类别组件的生命周期方法使用一种挂钩（Hooking）形式，允许在组件生命周期内的设置点执行代码。

shouldComponentUpdate 允许开发人员通过在不需要渲染时返回false来防止不必要的组件重新渲染。
componentDidMount只要一旦组件“挂载（mounted）”（组件已在用户界面中创建，通常通过将其与DOM节点关系），就会被调用。这通常用于通过API触发从远程数据源加载资料。
componentWillUnmount 在组件被移除或“卸载”（unmounted）之前立即被调用。通常用于清除对组件的资源需求相依性模块，这相依性模块不会随着组件的卸载而容易地被删除（例如，删除与组件相关的任何 setInterval() ，或设置于“文件”的“事件监听”（eventListener），因为组件的存在）。
render是最重要的生命周期方法，也是任何组件中唯一需要的方法。它通常在每次组件状态更新时调用，也就是应该反映在用户界面中。
JSX
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
HTML之外的架构
React的基本架构不仅适用于在浏览器中呈现HTML。例如，Facebook有渲染到<canvas>标签，[14] Netflix 和 PayPal 使用通用加载于服务器和客户端上渲染相同的HTML。[15][16]

React hooks
Hooks是让开发人员从函数组件中“钩入（Hook into）”React状态和生命周期特性的函数。Hooks在类别组件无法作用——它们让你在没用类别组件情况下使用React。[17]

React提供了一些内置的Hook，例如 useState,[18]useContext、useReducer、useMemo 与useEffect。[19] 其他的记录在Hooks API参考中。[20] useState 与useEffect，也就是最常用，分别用于状态和副作用的控制。

Hooks的使用规范
下面有一些Hooks规范[21] 描述了钩子（Hooks）的特征代码模式，也是现今使用React处理状态方式。

Hooks只能在顶层调用（而不是在循环或if语句内）。
Hooks只能从React函数组件和自定义Hooks调用，而不是普通函数或类别组件。
虽然这些规范不能在执行时强制执行，但可以设置代码分析工具（例如linter）来侦测开发过程中的许多错误。

这些规范适用于Hooks的使用和自定义Hooks的实现，[22] 也就是可能会调用其他Hooks。

常用惯用语
React并不刻意提供一个完整的“应用程序工具库”。专为构建用户界面而设计，因此不包含一些开发人员可能认为构建应用程序所必需的许多任务具。这也允许选择开发人员喜欢的任何工具库来完成诸如执行网络访问或本地资料存储等任务。随着工具库的成熟，常见的使用模式已经出现。

单向资料流
为了支持React的单向资料流概念（可能与 AngularJS 的双向资料流形成对比），Flux架构被开发为流行的模型-视图-控制器架构的替代方案。Flux具有通过中央调度程序发送到存储区（Store）的操作，并且对存储区的更改被传递回视图。[23] 当与React一起使用时，这种传递是通过组件属性完成的。从Flux的概念开始，Flux就被Redux和MobX等工具库所取代。[24]

Flux可以被认为是观察者模式的一种变体。[25]

Flux架构下的React组件不应直接修改传递给它的任何props，而应传递回调函数，这些回调函数创建由调度程序发送的用于修改存储的操作。动作（Action）是一个对象，负责描述发生的事情：例如，描述一个用户“关注”另一个用户的动作可能包含用户ID、目标用户ID和类型USER_FOLLOWED_ANOTHER_USER。可以将存储视为模型，可以根据从调度程序接收到的操作来改变自己。

这种模式有时表示为“属性（Properties）向下流动，动作（Actions）向上流动”。Flux的许多实现从一开始就被创建了，也许最著名的是Redux，它具有单一存储，通常称为单一资料源。[26]

React Native 于2015年2月在Facebook的React Conf上宣布，并于2015年3月开放源代码，支持使用React进行原生Android、iOS和UWP开发。

2017年4月18日，Facebook发布了React Fiber，这是一套新的内部渲染算法，与React的旧渲染算法Stack不同。React Fiber将成为React工具库未来任何改进和功能开发的基础。[33][已过时] 使用React程序撰写的实际语法不会改变；只有语法的执行方式发生了变化。[34] React的旧渲染系统Stack是在不了解系统对动态变化的关注点的时候开发的。Stack绘制复杂动画的速度很缓慢，例如，试图在一个块中完成所有动画。Fiber将动画分解为可以分布在多个帧上的片段。同样，一个页面的结构可以分解为可以单独维护和更新的片段。JavaScript函数和虚拟DOM对像被称为“纤程”，每个都可以单独操作和更新，从而实现更流畅的屏幕渲染。[35]




React 于官方文件内的“推荐的工具链”中提及 Next.js，建议将其作为“使用 Node.js 构建服务器渲染网站”的解决方案。[5] 传统的 React 应用程序只能在客户端浏览器中渲染内容，Next.js 扩展了此功能以包括在服务端渲染的应用程序。



Next.js 是一个 React 框架，它支持一些额外的功能，包括服务端渲染和静态网站生成。[8] React 是一个 JavaScript 库，传统上用于构建使用 JavaScript 在客户端浏览器中渲染的网页应用程序。[9] 然而开发者意识到这种策略存在一些问题，例如无法满足无法访问或禁用 JavaScript 的用户、潜在的安全问题、明显延长页面加载时间以及可能损害网站的整体搜索引擎优化。[9] 诸如 Next.js 之类的框架利用允许在发送到客户端之前在服务端渲染部分或全部网站来避开这些问题。[9][10] Next.js 是最流行的 React 框架之一。[11] 它是启动新应用程序时可用的几个推荐“工具链”之一，所有这些都提供了一个抽象层来协助完成常见的任务





> When you arise in the morning think of what a privilege it is to be alive, to think, to enjoy, to love ...”
> -- Marcus Aurelius

* ToC
{:toc}

## Images

![A diagram of the Ikigai concept.](index.assets/Ikigai@2x.png)

# Use the most recent version of jekyll-sass-converter, to force Dart Sass
```
gem "sass-embedded"
gem "jekyll-sass-converter", github: "jekyll/jekyll-sass-converter"
```

```
titles_from_headings:
  enabled: true
  strip_title: true
  collections: true
```

## Usage

To change the label of the mobile navigation menu, add this to your `_config.yml`:

```yaml
miniplex:
  mobile_nav_menu_title: "Menü"
```

## Features

- [ ] In-page navigation
- [ ] Footer
- [ ] Maximizable tables
- [ ] Breadcrumbs, if possible
- [ ] Side notes, if possible

- Responsive.
- Table reformatting for very small screens.
- Hamburger menu at the bottom right, easy to reach.

- [X] Dark mode
- [X] Print CSS
- [X] Mobile nav bugfixing
- [X] Post author & date flexibility
- [X] Add a post's date to the page layout, or to a separate post layout

```css
font-family: 'IBM Plex Mono', 'Menlo', 'DejaVu Sans Mono', 'Bitstream Vera Sans Mono', Courier, monospace;
font-family: 'IBM Plex Sans', 'Helvetica Neue', Arial, sans-serif;
font-family: 'IBM Plex Sans Condensed', 'Helvetica Neue', Arial, sans-serif;
font-family: 'IBM Plex Serif', 'Georgia', Times, serif;
```

<style>
  @import url('https://fonts.googleapis.com/css2?family=IBM+Plex+Mono:ital@0;1&family=IBM+Plex+Sans:ital,wght@1,100&display=swap');
</style>

font-family: 'IBM Plex Mono', monospace;
font-family: 'IBM Plex Sans', sans-serif;

<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=IBM+Plex+Mono:ital@0;1&family=IBM+Plex+Sans:ital,wght@1,100&display=swap" rel="stylesheet">

| Country                                                     | Capital | Population | Currency             |
| ----------------------------------------------------------- | ------- | ---------: | -------------------- |
| Switzerland (*Schweizerische Eidgenossenschaft* )           | Berne   |  8,636,896 | Swiss Franc (CHF)    |
| Germany (*Bundesrepublik Deutschland*)                      | Berlin  | 83,695,430 | Euro (EUR)           |
| France (*République française*)                             | Paris   | 67,897,000 | Euro (EUR)           |
| Italy (*Repubblica Italiana*)                               | Rome    | 61,095,551 | Euro (EUR)           |
| UK (*United Kingdom of Great Britain and Northern Ireland*) | London  | 67,791,400 | Pound sterling (GBP) |



## BPF CO-RE

 (Compile Once – Run Everywhere)

- https://nakryiko.com/posts/bpf-portability-and-co-re/










o



@import url('https://fonts.googleapis.com/css2?family=Recursive:CASL,CRSV,MONO@0.5,0,1&display=swap');





<link href="https://fonts.googleapis.com/css2?family=Recursive:CASL,CRSV,MONO@0.5,0,1&display=swap" rel="stylesheet">



font-family: 'Recursive', monospace;




@font-face {
 font-family: 'Recursive';
 src: url('path/to/font/<UPDATE_SPECIFIC_FONT_PATH>.woff2') format('woff2-variations');
 font-weight: 300 1000;
}




```

<link rel="stylesheet" href="https://cdn.bootcdn.net/ajax/libs/lxgw-wenkai-webfont/1.6.0/style.min.css" />
<link rel="stylesheet" href="https://cdn.bootcdn.net/ajax/libs/lxgw-wenkai-screen-webfont/1.7.0/style.min.css" />

<!-- 霞鹜文楷 Regular -->
<link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/satouriko/LxgwWenKai_Webfonts@v1.101/dist/LXGWWenKai-Regular.css" />
<!-- 霞鹜文楷 Lite -->
<link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/satouriko/LxgwWenKai_Webfonts@v1.101/dist/LXGWWenKai-Light.css" />
<!-- 霞鹜文楷 Bold -->
<link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/satouriko/LxgwWenKai_Webfonts@v1.101/dist/LXGWWenKai-Bold.css" />
<!-- 霞鹜文楷 Mono Regular -->
<link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/satouriko/LxgwWenKai_Webfonts@v1.101/dist/LXGWWenKaiMono-Regular.css" />
<!-- 霞鹜文楷 Mono Lite -->
<link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/satouriko/LxgwWenKai_Webfonts@v1.101/dist/LXGWWenKaiMono-Light.css" />
<!-- 霞鹜文楷 Mono Bold -->
<link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/satouriko/LxgwWenKai_Webfonts@v1.101/dist/LXGWWenKaiMono-Bold.css" />


/* 霞鹜文楷 */
body {
  font-family: LXGWWenKai sans-serif;
}
body {
  font-family: "LXGW WenKai Screen R", sans-serif;
}

/* 霞鹜文楷 Mono */
pre, code {
  font-family: LXGWWenKaiMono monospace;
}


@import url("https://cdnjs.cloudflare.com/ajax/libs/lxgw-wenkai-screen-webfont/1.7.0/lxgwwenkaiscreenr.css");

```
