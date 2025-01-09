# deno




Eich 的原型是在 SGI Indy Unix 工作站 [Netfreak 2019] 上开发的，使用了一个手写的词法分析器和递归下降解析器。这个解析器发出的是字节码指令，而不是语法分析树（parse tree）。字节码解释器g简单而缓慢9。

字节码特性源于 Netscape LiveWire 服务器10的需求，其开发人员甚至在将 Mocha 原型化之前就希望将其嵌入。这支团队的前 Borland 管理和工程人员都坚信动态脚本语言的未来，但他们希望使用字节码而非源码解析的方式，加快服务器应用的加载速度。


所有人都认可 Mocha 将会「基于对象」但没有类。因为支持类将花费很长时间，并有与 Java 竞争的风险。出于对 Self 的认可，Eich 选择使用带有单个原型链接的委托g机制，来创建动态的对象模型。他认为这样可以节省实现成本，但最后还是没有足够时间在 Mocha 原型中暴露该机制。

对象是通过为构造函数g应用 new 运算符的方式创建的。名为 Object 的默认对象构造函数，与其他内建对象一起内置在环境中。每个对象由零个或多个属性组成。每个属性g都有一个名称（也叫属性键g）和一个值，该值可以是函数g、对象或其他几种内建数据类型之一。可以通过为未使用的属性键赋值的方式，来创建出新属性。属性没有可见性或赋值限制，构造函数还可以提供一组初始属性。创建对象后，也可以将其他属性添加上去。



> A secure runtime for JavaScript and TypeScript.

- Run a JavaScript or TypeScript file:

`deno run {{path/to/file.ts}}`

- Run a file with network access enabled:

`deno run --allow-net {{path/to/file.ts}}`

- Run a file from a URL:

`deno run {{https://deno.land/std/examples/welcome.ts}}`

- Install an executable script from a URL:

`deno install {{https://deno.land/std/examples/colors.ts}}`

# Deno

```
$ proxychains sh install.sh
[proxychains] config file found: /aaron/.proxychains/proxychains.conf
[proxychains] preloading /usr/lib/x86_64-linux-gnu/libproxychains.so.4
################################################################################################### 100.0%
Archive:  /aaron/.deno/bin/deno.zip
  inflating: /aaron/.deno/bin/deno
Deno was installed successfully to /aaron/.deno/bin/deno
Manually add the directory to your $HOME/.bashrc (or similar)
  export DENO_INSTALL="/aaron/.deno"
  export PATH="$DENO_INSTALL/bin:$PATH"
Run '/aaron/.deno/bin/deno --help' to get started

Stuck? Join our Discord https://discord.gg/deno

$ curl -fsSL https://deno.land/x/install/install.sh | sh
######################################################################## 100.0%-#O#- #   #
Archive:  /home/aaron/.deno/bin/deno.zip
  inflating: deno
Deno was installed successfully to /home/aaron/.deno/bin/deno
Manually add the directory to your $HOME/.bash_profile (or similar)
  export DENO_INSTALL="/home/aaron/.deno"
  export PATH="$DENO_INSTALL/bin:$PATH"
Run '/home/aaron/.deno/bin/deno --help' to get started
```

```
$ ~/.deno/bin/deno install --unstable --allow-read --allow-write --allow-net --name=pagic https://deno.land/x/pagic/mod.ts
Warning Implicitly using latest version (v1.6.3) for https://deno.land/x/pagic/mod.ts
error: error sending request for url (https://esm.sh/react@18.2.0): error trying to connect: tcp connect error: Connection timed out (os error 110)
    at https://deno.land/x/pagic@v1.6.3/deps.ts:11:24

$ proxychains ~/.deno/bin/deno install --unstable --allow-read --allow-write --allow-net --name=pagic https://deno.land/x/pagic/mod.ts
[proxychains] config file found: /aaron/.proxychains/proxychains.conf
[proxychains] preloading /usr/lib/x86_64-linux-gnu/libproxychains.so.4
✅ Successfully installed pagic
/aaron/.deno/bin/pagic
ℹ️  Add /aaron/.deno/bin to PATH
    export PATH="/aaron/.deno/bin:$PATH"

```


https://en.wikipedia.org/wiki/Ryan_Dahl

Deno is more than just being first-aid to Node. It is slowly progressing to be everything that Node was supposed to be in the first place. Node was created to introduce the concept of event-driven I/O & HTTP servers using JavaScript. And while Node may have been able to achieve that, in hindsight, it came with a lot of baggage (or package, literally!).

It started defying the principles of the very language it was built on top of. Eventually, Node reached a point of 'no return' and became too bulky and massive for the creator to just modify the core without breaking millions of Node projects.

Node vs Deno
Node and Deno were built to serve the same purpose. That provides us a foundational common ground for comparison.


Deno is a secure runtime for JavaScript and TypeScript. Imagine if you could write TypeScript without any config files, and bundle it all together into a single ES Module where both the TypeScript support and bundler are present in the core. That’s what it feels like when you get started with Deno.

It’s a modern and secure runtime for JavaScript and TypeScript that uses V8 and is built in Rust. Whereas Node.js is written in C++ and JavaScript.

Fun fact: Deno is an anagram of Node. If you sort() node it becomes deno🦕.

Deno ships with many features required for writing modern JavaScript & TypeScript, and WebAssembly code.

📦 bundler
🐛 debugger
🤖 test runner
🧶 code formatter
📖 docs generator
🧵 WebAssembly support
Deno has some interesting features
Secure by default. No file, network, or environment access, unless explicitly enabled.
Single Executable. Ships only a single executable file.
TypeScript Support Deno ships with out of the box TypeScript compiler.
Module system No package.json, no node_modules. Source files can be imported using a relative path, an absolute path or a fully qualified URL of a source file:
  import { test } from "https://unpkg.com/deno_testing@0.0.5/testing.ts"
  import { log } from "./util.ts"
What are the main issues with Node.js?
Any program can write to the filesystem and the network
This might be a security problem, especially when intalling untrusted packages from npm. The [crossenv](https://blog.npmjs.org/post/163723642530/crossenv-malware-on-the-npm-registry) incident is an example. If crossenvhad not had writing permissions, this would not have happened.

The build system (GYP)
Using GYP to build a module that links to a C library is a big pain. In order to have a sane DX you’ll have to use node-gyp (a layer on top of GYP) and maybe other layers (like [nan](https://www.npmjs.com/package/nan)).

The module system and npm
The main problem here is that the module system isn’t compatible with browsers so our code isn’t fully isomorphic. This is mainly caused by two reasons: storing dependencies in node_modules and having a package.json.

Let's get started with installing Deno
Using PowerShell (Windows):
iwr https://deno.land/x/install/install.ps1 -useb | iex
With Shell:
curl -fsSL https://deno.land/x/install/install.sh | sh
With Homebrew:
brew install deno
Now check if deno was installed by running the deno --version command in your terminal.

Simple http server
This example contains a simple http server (app.ts):
 import  { serve }  from  "https://deno.land/std@0.50.0/http/server.ts";
 const s =  serve({ port:  8000  });
 console.log("http://localhost:8000/");
 for  await  (const req of s)  {
    req.respond({ body:  "Hello World\n"  });
 }
Run the code:
 deno run app.ts
This results into permission error
 error: Uncaught PermissionDenied: read access to "http/server.ts", run  again with the --allow-read flag

 ► $deno$/dispatch_json.ts:40:11
 at DenoError ($deno$/errors.ts:20:5)
 ...
This is because deno allows you to control the granularity of permissions. To run above application you need set some flags indicating deno that particular permission are allowed.
 deno run --allow-net app.ts
 > http://localhost:8000/
Now open up your browser at localhost:8000. You will be see the Hello World text.
Okay this was just a basic demonstration of how you could create simple http server using deno.

See more example here

I have created User REST API in deno feel free to check it out here. Clone the Repo and play around. Contribution are always welcome🎉

😕 You're a beginner, and confused which one to pick up.
If you're a beginner, it's optional to care about Deno at this point. You might think that if Node and Deno serve the same purpose and if Deno is newer and better, then why learn Node at all? That's a great question. And for the most part, you're correct. You can actually dive into Deno without indulging in Node. But! - hear me out. You only get to appreciate the beauty of an upgrade, when you've experienced its predecessor. It makes you realise what you had been missing out on. It gives you perspective and enhances your sense of understanding and belonging. I personally feel that these things are crucial when you're serious about a language and see a future with it. It's an investment, of time, energy, efforts and so much more. Choose wisely!

😫 You recently picked up Node and were serious about it.
Seriously, keep going! You don't have to care about Deno. I'm sure you were enjoying Node and having a great time experimenting with it when suddenly Deno launched and you were bombarded with articles, tutorials, tweets and crash courses, resulting in you facing a dilemma and landing here. Avoid jumping aboard the 'Deno Hype Train' and keep following your original plan. Work with Node, understand it's nuances, build a few servers/projects etc. When you feel that the time is right, and you're capable of taking a sound decision without any hype or peer-pressure clouding your judgment, switch to Deno and be absolutely amazed!

🤔 You're an intermediate and have been working with Node for the past few years.
You're thoroughly aware of the ins and outs of Node. You've used Node to build college or hackathon projects. You've interned/freelanced somewhere, using Node to innovate and rapidly build prototypes, APIs, servers etc. Switching to Deno definitely deserves your consideration. Think about it, take your time. Retrospect whether you've learnt everything about Node that you planned to or whether you have achieved everything that you wanted to, when you started. If yes, you know what to do. Otherwise, hang in there.

🤓 You're an expert and you live/breathe in Node.
You have used Node in production. Built customer/developer facing APIs/SDKs and can solve Node bugs in your sleep. Chances are that you aren't reading this blog and you have already started working in Deno. Godspeed! You should definitely care about Deno. But! - even though Deno has released a stable version, it might not be the best time to do a full switch. The community still needs time to grow. If you run into an issue/error, you might be the first one to experience it. Even StackOverflow might not help. But that's exciting, isn't it? 🤩

Frequently Asked Questions
A few questions that you might hear a lot. Providing explicit closure to those questions here. I'll keep adding to this as well. Do your bit and comment relevant questions.

1. Is Deno going to replace Node?
Nope. Node is in a very stable state and there is a whole community dependant on it. Node is in it for the longer run. No need to worry.

2. Is Deno going to merge with Node or vice-versa?
Nope. Deno and Node are going to function parallel to each other with ongoing cross-transitions over time.

3. Is Deno going to support Node apps?
Yes. Deno currently supports a very nascent compatibility layer at this point which, will slowly become stable.

4. Is Deno better than Node?
Yes and No. Think of it this way. What TypeScript is to JavaScript, that is what Deno is to Node. A superset. There's no good or bad. Just a time, place and requirement to use either of them.

5. Do I have to learn TypeScript to work with Deno?
Not necessarily. It is optional. You can also use JavaScript to work with Deno. Although, that would be counter-productive.

Fin!
That's all folks. I hope this blog was able to help you understand your position in the Node/Deno ecosystem and provide you with some closure at the same time. I myself started working with Deno about a week ago and I have a lot of exciting Deno related content coming up very soon. I understand that I did not talk much about Deno, its features, how to get started etc, but that wasn't the point of this blog. We'll talk about that in the upcoming blogs. Watch this space for more. Follow me to never miss an update. If something feels off or wrong, do comment with your problems/concerns/suggestions.


# Links
- https://cnodejs.org/topic/5c4a82dcf9075c1ef7137f6e
- https://zhuanlan.zhihu.com/p/57632707
- https://blog.csdn.net/BennyShi1998/article/details/104186708
- https://dev.to/azure/angular-rust-webassembly-node-js-serverless-and-the-new-azure-static-web-apps-cnb


aaron    2526689  0.1  1.7 1381896 141656 pts/7  Sl+  16:44   0:10  |   \_ deno run --allow-read --allow-write --allow-net --unstable --no-config https://deno.land/x/pagic/mod.ts build --serve --watch
aaron    2559600  0.0  0.0   9572  2304 pts/21   S+   18:24   0:00      \_ grep -E -s -I --color=auto --exclude-dir=.cache --exclude-dir=.git --exclude-dir=.idea --exclude-dir=.tox --exclude-dir=_site deno


## Deno makes programming easy. We make it possible to use JavaScript outside of the browser to build all types of software. Our free open source runtime is one of the most popular projects on Github. Our business is hosting JavaScript servers at the edge with the Deno Deploy serverless runtime. Try it out — you ought to be able to deploy a server world-wide in less than 5 minutes.

About the company

Deno is founded by the same engineers who built Node.js, the JavaScript runtime used by millions of developers and used by nearly all websites in one form or another. Deno is a continuation of the ideas in Node; a modern take on server-side JavaScript development. The open source project has already secured itself among the ranks of the most popular projects on GitHub.

Our commercial product is cloud service for hosting JavaScript servers. It is one of just a handful of implementations of serverless at edge in existence. By repurposing web browser technology for server software, we aim to accelerate a new generation of extreme low-latency edge applications.

We are fully remote with employees all over the world. Don't assume this means we're not a real company; our investors include Sequoia Capital, Nat Friedman, Netlify, and Wordpress..

Responsibilities

    Build asynchronous servers in Rust

    Build microservices that run on top of Kubernetes

    Develop system software - implementing code that talks to the frontend

    Review code and architecture proposals and participate in design discussions

    Communicate internally and externally about your work

Qualifications

    5+ years of experience

    Must have experience developing with Rust

    Intimate knowledge of internet and web standards (DNS, TCP, TLS, HTTP, DOM)

    A passion to make software infrastructure simpler

    Prior involvement in defining the architecture of a cloud native software platform

    Experience building distributed systems in GCP / AWS including Kubernetes & Terraform

    Nice to have: experience with C++, TypeScript and JavaScript

    Nice to have: knowledge of load balancers and web servers

We Offer

    A competitive full-time salary and early-stage stock options

    100% remote work from anywhere in the world

    Autonomous work - we work collaboratively on projects, but you set your own pace

    Flexible vacation time

    Hardware and office allowances

    Company off-sites three times a year

Process

    Once you've submitted your application, the team will review your submission and reach out for a screening interview over video call. If you pass this screen, you will be invited to up to four follow up interviews. These calls usually take between 30-60 minutes each depending on the interviewer. Once the interviews are over, our hiring team will meet to discuss several roles and candidates. We may ask one or two follow-up questions over email or a quick call before making an offer.

# Comparison

---| --- | ---
Features	Node	Deno
Uses	JavaScript	TypeScript
Written in	C++ & Libuv	Rust & Tokio
Security	full-access	explicit-access
Package Managing	npm	absolute url-based
Importing with Extensions	optional; non-explicit	mandatory; explicit
Module Ecosystem	CommonJS	ES moduling
Browser Support	ambiguous; vague	supported
Native Async Programming	Callbacks	Promises
Unhandled Promises	uncaught exceptions	dies immediately
ECMAScript Support	not built-in	built-in
TypeScript Support	not built-in	built-in
Code Formatting	not built-in	built-in
Top-Level Await	not built-in	built-in

Deno與Node.js的相同之處：

    皆運行於V8上。
    擁有相同的事件循環。
    提供CLI讓用戶可以執行手稿語言。
    龐大的實用程式。

Deno與Node.js的不同之處[6]：

    預設模組系統是使用ES Module，而不是CommonJS。
    使用URL載入本地端或遠端的dependencies。
    使用內建的套件管理器來抓取資源，因此不需要NPM。
    使用具有緩存機制的快照TypeScript編譯器，因此Typescript也能開箱即用。
    相容具有廣泛Web API的瀏覽器。
    允許控制檔案系統與網絡存取，以執行沙盒內的程式碼。
    重新利用Promise、ES6、Typescript來設計API。
    最小化核心API的大小，同時提供許多的標準函數庫，因此不需要再使用外部的dependencies。
    使用訊息傳遞通道來呼叫特權系統API。

Hello World

命令: deno run hello-world.js

/**
 * hello-world.js
 */
function capitalize(word) {
  return word.charAt(0).toUpperCase() + word.slice(1);
}

function hello(name) {
  return "Hello " + capitalize(name);
}

console.log(hello("john"));
console.log(hello("Sarah"));
console.log(hello("kai"));

/**
 * Output:
 *
 * Hello John
 * Hello Sarah
 * Hello Kai
 */

Unix cat程式

在這個程式中，每個命令列參數都被假定為一個檔名，檔案被打開，並列印到stdout（例如控制台）。

/**
 * cat.ts
 */
import { copy } from "https://deno.land/std@0.167.0/streams/conversion.ts";
for (const filename of Deno.args) {
  const file = await Deno.open(filename);
  await copy(file, Deno.stdout);
  file.close();
}

執行該程式：

deno run --allow-read https://deno.land/std@0.167.0/examples/cat.ts /etc/passwd

HTTP網絡伺服器

webserver.ts:

import { serve } from "https://deno.land/std@0.167.0/http/server.ts";

const port = 8080;

const handler = (request: Request): Response => {
  const body = `Your user-agent is:\n\n${
    request.headers.get("user-agent") ?? "Unknown"
  }`;

  return new Response(body, { status: 200 });
};

console.log(`HTTP webserver running. Access it at: http://localhost:8080/`);
await serve(handler, { port });

然後用以下方式執行這個：

deno run --allow-net webserver.ts





# Deno在單個可執行檔中扮演執行環境和套件管理系統的角色，不需要將其分開。 [6] [7]


Deno於2018年瑞安·達爾的演講「我爲Node.js感到後悔的十件事」中宣佈。[5]在這場演講中，達爾提到他後悔Node.js的設計，例如沒有在API中使用JavaScript的Promise、GYP建構系統、省略檔案的副檔名、node_modules與package.json、使用index.js進行模組解析、V8的沙盒環境等等[8]。他在演講的最後提出了Deno的原型，Deno旨在透過如Protocol Buffers之類的序列化工具傳遞訊息來實現綁定系統的呼叫，並提供命令列介面來存取控制。

Deno初始版本是使用Go語言編寫，並使用Protocol Buffers來實作特權（Go）與非特權（V8）之間的序列化[9]。然而因顧慮到雙重運行與垃圾蒐集，Go在不久後就被Rust取代[10]。

爲了讓Deno擁有非同步的事件觸發環境，Tokio也被引進來取代原本的libuv[11]。

Deno原本採用Flatbuffers以進行更快的零複製序列化與反序列化[12]，在2019年4月發佈序列化的標準之後[13]，2019年8月被移除[14]。

2018年11月建立了一個以Go標準函數庫爲基底的標準函數庫，並提供了廣泛的工具，解決部分Node.js的dependency問題。[15]

Deno於2020年5月13日正式發佈。[16]

Deno Deploy，受Cloudflare Workers[17]的啟發，於2021年6月23日釋出。[18] 於2022年5月4日宣佈Beta 4改進了儀錶板並增加了計費功能。Deno Deploy預計在2022年第三季度正式釋出。[19]

Deno Fresh 1.0於2022年6月28日宣佈。[20] 它是一個新的全棧Web框架，用於Deno，它不向客戶端傳送任何JavaScript。該框架沒有構建步驟，這使得部署時間可以提高一個數量級。1.1版本於2022年9月8日釋出。[21]

Deno SaaSKit beta於2023年4月4日宣佈。[22] 它是一個開源的、現代的SaaS模板，使用Fresh和Deno構建。
概覽
Deno目標是成爲對目前的工程師來說最具有生產力的的指令碼環境[6]。Deno強調事件觸發架構，並提供一套非阻塞IO與阻塞IO。 

## Deno ( /ˈdiːnoʊ/ , 发音 dee-no) 是一个 JavaScript/TypeScript 的运行时，默认使用安全环境执行代码，有着卓越的开发体验。

Deno 建立在 V8、Rust 和 Tokio 的基础上。
功能亮点

    尽可能的兼容 Web 规范 ，例如使用 ES modules、支持 fetch() 等。
    默认安全。代码不能访问文件、网络、环境变量等（除非显式开启）。
    支持开箱即用的 TypeScript 的环境。
    只发布一个独立的可执行文件 (deno)。
    有着内置的 工具箱 ，比如代码格式化工具 ( deno fmt )，a linter ( deno lint )，( deno test ) 和 编辑器 LSP 。
    有一组经过审计的 标准模块 ，保证能在 Deno 上工作。
    脚本代码能被 打包 为单独的 JavaScript 文件，也可以编译为 可执行文件 。

哲学

Deno 旨在为现代程序员提供高效、安全的脚本环境。

Deno 将始终作为单个可执行文件分发。给定一个 Deno 程序的 URL，您应该能够用 压缩后 31MB 左右的 Deno 可执行文件 运行它。Deno 明确地承担了运行时和包管理器的角色。它使用标准的浏览器兼容协议(URL)来加载模块。

对于过去用 Bash 或 Python 编写的工具脚本来说，Deno 是一个优秀的替代品。
目标

    只分发一个独立的可执行文件 (deno)。
    默认安全。
        除非显式开启，否则脚本代码不能访问文件、网络、环境变量。
    浏览器兼容。
        完全用 JavaScript 编写且不使用全局 Deno 命名空间(或功能测试)的程序是 Deno 程序的子集，能够直接在现代浏览器中运行而无需更改。
    提供内置工具来提升开发体验。
        比如单元测试、代码格式化、代码检查。
    不把 V8 的概念泄露到用户空间。
    能够高效地提供 HTTP 服务。

与 Node.js 的比较

    Deno 不使用 npm。
        Deno 使用 URL 或文件路径引用模块。

    Deno 在模块解析算法中不使用 package.json。

    Deno 中的所有异步操作返回 promise，因此 Deno 提供与 Node 不同的 API。

    Deno 需要显式指定文件、网络和环境变量的访问权限。

    当遇到未捕获的错误发生时，Deno 总是会异常退出。

    使用 ES 模块，不支持 require()。第三方模块通过 URL 导入：

    import * as log from "https://deno.land/std@$STD_VERSION/log/mod.ts";

其他关键行为

    远程代码在第一次运行时获取并缓存，直到代码通过 --reload 选项运行。（所以 Deno 在飞行模式也能正常工作）



pyang

$ lnctool --model ./turing-machine.yang transapi --paths ./paths_file
