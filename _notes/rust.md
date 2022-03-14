---
title: Rust notes
date: 2018-08-17
---

## The most loved language in 2020

当我们要使用多个线程编写高性能程序，同时又需要它非常快速且节省内存，那么 Rust 是理想的选择


Rust 最初是 Mozilla 为了解决软件在语言级别上无法真正利用多核计算带来的性能提升而创建的，这一点与 Go 有些类似。相比前辈 C++，Rust 在代码安全这一特性上下足了功夫。比如内存安全方面，Rust 在安全代码里不容许空指针、悬垂指针和数据竞争，这些问题在编译阶段就无法通过。Rust 社区核心开发者 Nichols 表示：“之前，我们只能使用 C 或者 C++ 才能编写具有较低内存占用空间的高质量代码。但是，在生产代码中使用这些语言需要你手动管理内存并了解可能导致未定义行为的所有方法。”Nichols 指出，不断扩展的 CVE 代码漏洞数据库证明，即使是最优秀的程序员也疲于应对层出不穷的代码漏洞。“为了确保你安全地使用内存，Rust 编译器非常严格，这样你就可以专注于你真正想要解决的问题。”

尽管 Rust 凭借其代码安全的特性获得了部分开发者的青睐，但由于其无论是在性能还是语法上，均不足以颠覆 C/C++，再加上其学习曲线并不平滑，因此与“家大业大”的 Go 相比，Rust 在前期的发展不温不火。直到去年 7 月，微软突然宣布将拥抱 Rust，探索用 Rust 作为 C/C++ 和其他语言的安全替代方案，以此来改善应用程序的安全状况。微软认为 Rust 是目前业界系统编程的最佳选择，原因不仅是它能够以内存安全的方式编写系统级程序，还在于其精密性。

微软此举让 Rust 在开发者中的地位直线上升，越来越多的企业和个人开始关注并重视代码安全的问题，从而重新审视这门新语言，这主要体现在 2020 年以来围绕 Rust 语言发生的几件事情：Linux 内核维护者表示愿意接受用 Rust 开发 Linux 驱动；AWS 宣布赞助 Rust；微软更进一步，在今年年初开发并开源了受 Rust 启发的新编程语言 Verona；最近，苹果也站出来拥抱它，计划将部分 C 代码移植到 Rust 。

2019 年的 StackOverflow 开发者调查显示，Rust 已连续四年蝉联“最受开发者喜爱的编程语言”。开发人员喜欢它，因为它的语法更简单，并且使用 Rust 编写的应用程序 bug 更少，因此开发人员可以专注于扩展他们的应用程序，而不是进行持续的维护工作。


当初你为什么会选择学习 Go 语言？有人告诉你，Go 的速度很快，而且它有很好的并发原语。现在，Rust 横空出世，每个人都在说，Rust 在各个方面都更好。他们是以前就说谎了呢，还是现在就在说谎呢？虽然没有单一的语言能够统治所有的语言，但你知道，人们仍然有可能做出错误的选择，最终陷入技术死胡同。毕竟，几年前你确实在其他语言中，选择了 Go 语言，你很高兴地加入圈子并融入其中，还问“为什么不用 Go 呢？”

虽然上面的故事完全是我虚构出来的，但毫无疑问的是，Rust 有一些拥趸，他们过于激进，觉得有义务向每一个迷失的灵魂灌输螃蟹大神的美德。（译注：Rust 语言的吉祥物就是一只螃蟹 Ferris，这是因为 Rust 开发者有一个名字，叫 Rustacean，因为这个是从甲壳纲动物这个单词 Crustacean [krʌ’steʃən]，去掉了首字母 C，而演变而来的。因为这里面包含 Rust 这四个字母。）这真的并不是 Rust 的错，每个成功的项目都会有行为不端的追随者，这是很难避免的。虽然每个人都必须与这些人打交道，但我觉得，Go 开发者特别容易受到他们行为的影响，因为 Rust 和 Go 的消息传递有太多的重叠。

Go 速度很快，但 Rust 速度更快。

Go 有一个高效的垃圾收集器，但 Rust 有静态内存管理。

Go 有很好的并发支持，但 Rust 有可证明的正确并发性。

Go 有接口，但 Rust 有特性和其他零成本的抽象。

如果你是一名 Go 开发者，你可能会有点上当受骗的感觉。相比之下，Python 开发者就不怎么特别担心 Rust。他们知道，Python 在很多方面，速度慢，效率低，但他们对此并不介意，因为他们知晓 Python 的角色：使代码易于编写，并在当性能很重要时，将其转到 C 语言来开发。

Go 语言怎么样呢？

Go 非常适合用来编写服务
Google 创建 Go 语言是为了解决 Google 的问题，这些问题主要涉及网络服务。Go 的并发模型非常适合服务器端应用程序，这些应用程序必须主要处理多个独立请求，而不是参与复杂的结果传递方案。这就是为什么给你的是 go 而不是 wait 的原因之一。

Go 对 HTTP 和相关协议有很好的支持，并且，编写一个令人满意的 Web 服务并不需要很长的时间。在我的个人项目中，Go 被证明是 Node.js 的很好替代方案，尤其是在我想要比编写惯用的 JavaScript 更明确地确定不同组件之间的接口的情况下。

除此之外，它还有强大的工具，可用来诊断并发性和性能问题，而且交叉编译使得 Go 在任何平台上部署都变得轻而易举。

Go 无可置辩地简单
Go 以提供了一组有限的内置语言功能而感到自豪。这使得 Go 易于学习，更重要的是，它确保了 Go 项目即使在规模不断扩大的情况下，代码仍然可以理解。Go 的创造者喜欢称之为一种“无聊”的语言。虽然我们可以争论这种语言是否可以使用一种或两种额外的东西，但事实证明，迫使人们“少花钱多办事”的想法是非常成功的。

在 Web 服务方面，Rust 确实可以做到和 Go 一样好，甚至更好，但就简单性方面而言，它确实不能与 Go 相比。而且 Go 不只是简单，它对其他语言通常比较宽松的东西也很严格。Go 不希望在同一个目录中有未使用的变量或导入、属于不同包的文件等等。它甚至曾经抱怨在 GOPATH 之外保存的项目（谢天谢地，现在不再是这样了）。

Go 也不希望在代码中留有任何“指纹”，因此它通过 go fmt 强制转换成单一的、通用的代码风格。


有很多初级开发者在工作中学习如何编程，但大多数人并没有幸运地找到一份能够真正教会他们任何东西的工作。在一些地方，当你被聘用后，就会被安排在 PluralSight 进行为期一周的培训，然后你就被认为已经为上岗做好了准备。

----

一个项目里，httpclient竟然出现了四种。

打接口请求响应日志，竟然不知道用拦截器。

打错误日志竟然不打上下文信息，每个人一种日志风格，千奇百怪。

许多重要的中间流程，居然不打日志。

idea、eclipse、myeclipse的配置文件竟然全部传到项目里去了。

该公司混了两年的程序员，跟快递公司做查询接口，竟然不知道加密运单号。

所有服务间通讯，都没有设requestId，导致跟踪会话很困难。

一个没什么qps的边缘接口，居然做消费者生产者+阻塞队列的异步模式。

不知道异步会增加维护成本，提高测试难度吗？

而且，任务队里没有考虑持久化，赶上发布，丢了好多任务。

读取一个小小的xml和exc配置文件，居然用流式解析，没见过这么二逼的，真是醉了。

做优化全靠拍脑门拍大腿，难道不会用excel分析日志，用jprofile扫项目？

一个100以内的常数集合遍历，他也要写个优化算法进去，算法跟业务还搅在一起，一团乱麻。

有枚举他不用，非要在每个页面上，把枚举值挨个儿写死，知道后面改代码多么费劲吗？

欺骗性的变量名，里面存储的是AES加密的，变量名后缀却写成了DES；里面存的是小写字母，却写成upperStr。

他们用mysql来做审计系统，出报表，有个报表要跑8分钟。

原来是有人用字符串来存多值（逗号分隔），sql里写了like，导致没有利用到索引。

为什么不用pg，pg在sql编程方面，功能更丰富，更适合做统计，它本身就支持数组。

当初公司起步的时候，整个项目都是几个初创程序员加班加点熬出来的，我知道你看过《代码大全》、《程序员修炼之道》、《Unix 编程艺术》，你对上面的准则信手拈来，你可否翻开床头柜上的这几本书，看看它们的出版时间呢？

是的，公司起步的时候，这几本书根本还没有出版，彼时中国互联网方兴未艾，大家都是摸着石头过河。现在你遇到问题，你可以问朋友、问导师、用谷歌、用栈溢出、用知乎，我们写程序那个年代，看的是谭浩强、严蔚敏，用的是 52k 拨号上网，语言只有 C，编辑器是没有语法高亮和实时编译的，编译器是没有智能准确的报错的，没有现在这么多知识、也没有这么多规范和好资源、好工具。不过我们还是把项目做出来了，把公司一步步推到了现在的位置。

不过这个问题是客观存在的问题，谁也不否认，但是你知道为什么你被分配到了一个『代码看上去一团糟也不够规范』的项目吗？我们需要新鲜血液来重构一些老代码，所以你会被分配到艰苦的岗位上。我们希望你是勇于战斗的战士，我们更希望你能成长为经验丰富的老兵，而把你放到这种岗位，是对你来说成长最快的方式。

你认为

一个项目里，httpclient竟然出现了四种。

一种是该公司研发部写的，

一种是老版本的开源项目，

一种是新版本的开源项目，

还有一种是开发人员造的轮子。

你不知道的是，我们最初用了开源软件（也就是你所说的『老版本』），它构成了我们早期项目的基石，随着业务复杂性增加，我们改进并最终切换到新版本。

这个软件跑老业务非常成熟，但是在一些新业务上有不可调和的矛盾，所以在痛苦的适配后，研发部的同事们自告奋勇用 20% 的时间写了新业务的组件——是的你没看错我们也有 20% 时间，我们鼓励工程师的创新。

至于你说的开发人员造的轮子——这说起来可真有趣，它其实是前年来的一个清华大学实习生写的。

当时他来了之后，针对他接手业务的需求，向我抱怨说现有的 3 种都不好，要写一个新的来『统一天下』，这话是他的原话，我记得非常清楚，因为以我多年经验来看这样的做法是不可取的，但是本着锻炼年轻人的心态（加上他的确是不可多得的天才），我同意了他的请求，于是我用自己的业余时间接管了他的大部分工作，全力支持他写一个新的组件，帮他挡住了所有上面的压力，后来的故事就是你看到的这样。

是的，他后来越深入、就越来越感到业务的复杂，不断推翻重构、拆东墙补西墙，但始终发现和自己想的根本完全不一样，受不了了就走了，留下来这个。

我们明年的规划中，就包括剔除这个组件的 codebase，因为它实在是太糟糕了。

你又说

打接口请求响应日志，竟然不知道用拦截器。

打错误日志竟然不打上下文信息，每个人一种日志风格，千奇百怪。

许多重要的中间流程，居然不打日志。

idea、eclipse、myeclipse的配置文件竟然全部传到项目里去了。

该公司混了两年的程序员，跟快递公司做查询接口，竟然不知道加密运单号。

所有服务间通讯，都没有设requestId，导致跟踪会话很困难。

拦截器并不如你所想的那班美好，也许你在自己的电脑上写过一些玩具代码，觉得这样很方便、酷炫，但是真正到了战场，你会发现没什么才是必须的、好的，只有适合的才是对的。

至于配置文件，这么说吧，IDE 的配置文件传到代码仓库是我定下的规矩，『怎么会有人定这样的规矩？』，是的你可能从软件工程的教科书上或者某些『知名博客』上读到了不能这样做，但实际上这样做在很多情况下是必须的。

原因何在？

这样可以确保代码克隆即可用，而不是让每个人都去设置一大堆无聊的东西，这样不仅节省时间，也确保了每个人的环境一致性，你想想这几年火热的 docker，应该明白了这样做的正确性和必要性了吧？

你可能会说即便如此、插件也不用上传到服务器保存，我告诉你这样是不行的，你要考虑到我们这个项目前后十余年，你觉得几个插件能坚挺十余年？很可能我们早期用的软件，现在你已经完全不可能找到了，所以保存一份备份是非常有必要的，决不能错误地认为是冗余。

教科书只会教你基本通用的原则，树立你基本正确的观念，但是如果只是死守教条，如何能拥抱日益复杂的变化呢？

你看的教科书，且不说时间上已经是二十多年前的了，在适用性上，也不说就是真理，IT 行业发展日新月异，几个月就是沧海桑田，为了适应这样的变化，认真地思考、总结、判断才是最重要的。

你觉得

一个没什么qps的边缘接口，居然做消费者生产者+阻塞队列的异步模式。

显得你技术少是不是。

不知道异步会增加维护成本，提高测试难度吗？

而且，任务队里没有考虑持久化，赶上发布，丢了好多任务。

读取一个小小的xml和exc配置文件，居然用流式解析，没见过这么二逼的，真是醉了。

你大概不知道，当初跑在你口中的「一个没什么qps的边缘接口」上面的业务带来了公司曾经 90% 的收入，所以我们用了复杂的设计以应对当时的需求，当然现在业务转变，老系统不再需要处理那么多业务了，但是更没有理由为一个『works perfectly well』并且不再重要的业务重构代码吧？

所以，不是我们秀技术，而是业务需求 + 业务变更使然，年轻人还需要多学习一个。

你抱怨

做优化全靠拍脑门拍大腿，难道不会用excel分析日志，用jprofile扫项目？

一个100以内的常数集合遍历，他也要写个优化算法进去，算法跟业务还搅在一起，一团乱麻。

每个人都在嚷嚷性能、算法、分布式计算……

几乎没有文档，全靠从代码反推逻辑。

有枚举他不用，非要在每个页面上，把枚举值挨个儿写死，知道后面改代码多么费劲吗？

欺骗性的变量名，里面存储的是AES加密的，变量名后缀却写成了DES；里面存的是小写字母，却写成upperStr。

一个方法十几个参数，有三分之一是极其简略的缩写，注释肯定也没有的。

一个类写到三四千行是常事。

我再强调一次——我们是全中国同类公司中技术能力第一的，你所说的问题，当然是不存在的。

我们有专门的 Hadoop 集群来分析日志，当然也就用不着 Excel 了。

对于我们这种体量的公司来说，不存在什么『常数集合』，代码必须用合适的数据结构——这是常识吧？

特殊的算法和业务掺杂以增加内聚性，这是我们多年的经验，的确，它和教科书上说的不一样，但是我前面说了，死守教条是不行的——想必你一定知道 OSI 7 层网络模型吧？

公司的技术氛围浓厚，是和公司的基因分不开的，我们公司最重要的原则就是——『拥抱变化』，从十几年前的机房托管单机到现在的庞大自建集群，技术跃迁了何止千万里，所以每个人都在学习新知识、每个人都沉浸在新知识的喜悦中。

你的问题，大多都是因为没有考虑到公司的庞大体量和十几年的技术跃迁才有的疑问，这点不再赘述，自行体会吧。

你想的是

开发自测，居然要把代码全丢到公共机器上，而且都是走svn，他们把svn当ftp用。

svn里面大量的无意义提交，一多半的提交连都编译不过去。

我看到有个应届生，改了两句话，马上提交，说是怕代码丢失。

一个运行了两年的项目，spring的包扫描明显配错了，有些bean根本扫不进来，居然没有人发现。

一半的bean在spring管理下，另一半的bean他们自己写单例模式来实例化。

其实那不是 SVN，那是我们公司自主研发的适应我们内部需求的 源代码管理系统 和 文件管理系统，你可以往里面放任何东西。

你所说的「无意义提交、一多半的提交连都编译不过去」其实只是表象，这套系统代号 TITAN，它自带 CIDD（持续继承、交付、部署），所以这些无法编译的提交都是不会有机会走到下一步流程的的。

如果你工作了一年，你就会发现这个需求是很重要的，改动、尤其是大型改动，中间会有很多非可用但有需要存档的步骤，现有的源代码管理系统都不能很好地支持这些需求，因此你也被教育了一套适应落后工具的思想。人啊，最重要的能力是改进工具，所以用 TITAN 的时候要拥抱全新思维，不要被落后思维捆绑。

如果你工作了几年，你可能还会问为什么我们没用 Jenkins、Travis 等工具，其实呀，就在 TITAN 之中呀，它凝结了公司最优秀的人才的十几年宝贵经验和心血。

By the way，我们最近正计划开源它，为中国开源社区做贡献，也希望提高业界的综合素质。欢迎你提交 PR 哦。

你最后说

他们用mysql来做审计系统，出报表，有个报表要跑8分钟。

原来是有人用字符串来存多值（逗号分隔），sql里写了like，导致没有利用到索引。

为什么不用pg，pg在sql编程方面，功能更丰富，更适合做统计，它本身就支持数组。

程序员们都是得过且过的态度，怎么把代码灌进去，跑的通测试，就算交差了。

为什么大型互联网公司，技术和管理这么差劲，是怎么形成的？

为什么不用 pg？如果你抱着这种想法，那用了 pg 也要被喷的，到时候就就会说 —— 「为什么不用 sqlite，轻量简单，搞这么复杂真的有必要吗？」，真的有必要。。。

这只是一个很简单的系统，做的事情也很简单，当初做这个系统的同事更熟悉 MySQL，当然 MySQL 是不二之选了，对于简单的东西，追求的是开发速度、使用便利性。

你觉得一个月跑一次的审计代码，8 分钟有什么问题吗？就算是一周跑一次，当然也是没问题的。

程序员的单位时间是如此宝贵，为了优化一段一个月跑一次的 8 分钟代码，值得花费数天的时间来做这件事吗？

重复一遍，你的问题，大多都是因为『没有考虑到公司的庞大体量和十几年的技术跃迁才有的疑问』，这点不再赘述，还请自行体会。

当然，年轻人乐于思考，这是好事，是希望，新鲜血液替换老旧部件系统才能健康发展成长，人如此、公司如此、国家也是如此。

希望你勤于思考，努力学习，有问题的话，我们公司是鼓励同事们向 CEO、CTO 写信的，不然也不会有 CEO、CTO 信箱了你说对吗？

当然，这样的技术性问题、你写给我就好，CEO 是船长，不需要关心底层锅炉房的细节。

另外我想补充一下我的想法，希望对你有所帮助。



 你看你都没说加班问题，我们公司没加班啊，这多好，怎么做到激烈竞争下还能不加班的？都亏了公司老领导和元老们的一手决策

 所以我想补充的不是技术问题，技术问题都不是问题，年轻人可以学习、交流，技术都会很快成长，毕竟年轻人的冲劲大、头脑灵活。


   你问我每行代码都多人多层人工 review 好不好？问我支不支持？我说好，review 我怎么能不支持呢？我今天在知乎这个公众平台我明确说了我支持。

   但是你也应该多学习一个，这个现实毕竟是现实，我们要兼顾各种考量。

   你今天在这里渲染「大公司技术和管理这么差劲」，是不对的、是失实的、是欠妥的、是缺乏认真思考的、是未加深入考量的。

   将来舆论出了偏差，你虽然不用负责任，但是你认识到自己的错误的时候，会后悔、会内疚、会难过的吧？

   何处乌托邦？或许……等下一代？

   总结就是，生产效率才是最重要的，世间万物最重要的是平衡。

   怎样取舍、如何妥协，这不仅是大自然的规律，也是我们前进、发展的准绳和仰仗的原则。



    下面是陈萌萌的回答：
    题主你看到了很多槽点，但我认为你不能只看到槽点和大概怎么解决。有没有想过怎么改进，如果是你的话你怎么做，这些项目里面临的主要挑战是什么，次要的挑战又是什么？

    不要只告诉我技术A弱爆了，用B就可以完爆这个项目了。你知道用B的优劣，B的适用场景以及适用B的成本吗？对于一间公司来说，成本是很重要的。我这里说的成本不是金钱。而是，假如你看不爽一份代码，你打算重构它，你觉得你需要投入多少时间，多少人力？重构之后，又要花费多少时间和人力去升级依赖这份代码的其他项目？不要以为开会无用，老板就只是在天天发邮件。如果你重构了一份代码，不能通过沟通说服其他组去升级他们的组件，又或者你只是重构了一份虽然很丑陋，但其实并没有多少程序依赖它的代码，又又或者你重构了代码只是让代码技术含量更高了，更好看了，却没给公司带来多少收入甚至KPI，那你的工作和成果就很尴尬了。

    其实上述也解释了为什么你身边的同事都眼睁睁地看着这些丑陋的shit存在而无动于衷。因为他们也是需要投入成本的。先不论他们个人技术水平高低，试问谁愿意挑一个又艰难，又不能产生多少效益的任务去做？当然，你会说，写好代码是程序员的节操。抱歉，节操多少钱一斤，北京三环商品房多少钱一平？

    编程高手都有真爱，但现实就是编程高手凤毛麟角。我们身边的大部分同事可能只是希望养家糊口，他们头上还挂着十几个bug等着修。我们数落他们没追求，但追求从来都不是嘴上说说，吐吐槽就能实现的。

    人心如此，公司也如是。

    矛盾分主次，公司的目标都是一样的：用最少的成本投入到最能产生效益的项目中去，或者投入大成本去解决公司最需要解决的问题，这间公司才能继续运作。

    所以题主你想想，在你吐槽的个案中，有多少是公司真正关心的？有哪些是你的老板认为可以创造最大效益的？有哪些才是主要矛盾或者挑战需要最牛逼的人挺身而出第一时间解决？去辨别，解决这些关键的问题吧，骚年。必要时带上（忽悠）一队人马（同事）跟你一起干，苟富贵，勿相忘。不要像祥林嫂一样，天天抱怨着生活，日日思考着辞职。得罪点说一句：“沦落”到要跟这样的人共事工作，难道自己身上就没有原因？

    这个世界有更好的公司，有更牛逼的人。如果你认为解决这间公司的这堆问题不值得，又或者同事实在太不给力，就远走高飞吧。

    我以前也跟题主一样，看我第一份正式工作的很多技术环节都相当不爽。这份代码写得丑，那个设计像大学生作品，重要的项目居然连单元测试都没有……但是我后来反观我自己，并没有发现比起那些丑陋代码和糟糕实现强悍多少。我跟我的同事没有质的区别。我笑话他们代码混乱bug不尽，我何尝不是少处理了一个field，倒腾错了一个片段的数据搞到要翻工重跑？在我心底里艹了隔壁组那个“我的程序好像不能跑，你帮我debug下”的同事一千次之后，带我做ML让我倒腾数据并且被我的程序搞坏了几份数据（当然后来搞好了）的T9君在会议上说：“她已经很努力了，我承认我有时候也逼得她太紧，她应该有多些时间的。”

----

Fuchsia OS 中国镜像
Fuchsia OS 中国镜像
一、准备工作
安装 curl git unzip

sudo apt-get install curl git unzip
下载 cipd jiri 工具（非官方工具）

mkdir fuchsia && cd fuchsia
curl --location --create-dirs --output .jiri_root/bin/cipd
https://fuchsia.fsf.org.cn/bootstrap/cipd-linux-amd64
curl --location --create-dirs --output .jiri_root/bin/jiri
https://fuchsia.fsf.org.cn/bootstrap/jiri-linux-amd64
chmod +x .jiri_root/bin/cipd .jiri_root/bin/jiri
export PATH=${PATH}:${PWD}/.jiri_root/bin:${PWD}/scripts
二、下载代码
从零使用镜像

manifest 文件自行从 https://fuchsia.fsf.org.cn/manifest/
选择，一个月以内的文件确保有效。

mkdir -p build && echo "internal_access = false" >build/cipd.gni
jiri init -keep-git-hooks=true
curl --location --output .jiri_manifest
https://fuchsia.fsf.org.cn/manifest/fuchsia-20060102.xml # 请将
fuchsia-20060102.xml 替换成相应文件
jiri update -run-hooks=false -v
echo "have_firmware = false" >zircon/prebuilt/config.gni
更新整个项目

删除掉 .jiri_manifest 文件并从 https://fuchsia.fsf.org.cn/manifest/
下载新的 manifest 文件。

rm -f .jiri_manifest
curl --location --output .jiri_manifest
https://fuchsia.fsf.org.cn/manifest/fuchsia-20060102.xml # 请将
fuchsia-20060102.xml 替换成相应文件
jiri update -run-hooks=false -v
切换国内镜像

先删除相关文件

rm -rf .jiri_manifest .jiri_root integration
下载 cipd jiri 工具并使用国内镜像，参见步骤 1 和 2。

恢复官方仓库

rm -rf .jiri_manifest .jiri_root integration
curl -s
https://fuchsia.googlesource.com/jiri/+/master/scripts/bootstrap_jiri?format=TEXT
| base64 --decode | bash -s ${PWD}
jiri init -keep-git-hooks=true
jiri import -name=integration flower
https://fuchsia.googlesource.com/integration
jiri update -v
三、问题反馈
电子邮箱 lzb.fuchsia@outlook.com
Copyleft © 2021 fuchsia.fsf.org.cn 渝ICP备15007658号-4



----




cargo build --target x86_64-unknown-linux-musl.



RUSTFLAGS="-C linker=~/x-tools/x86_64-unknown-linux-gnu/bin/x86_64-unknown-linux-gnu-gcc" cargo build --release



sudo bash chromeos-install.sh -src ChromeOS_recovery.img -dst /mnt/chromeos.img -s 32

sudo bash chromeos-install.sh -src ChromeOS_recovery.img -dst /dev/sdb



    options=acpi_power_button,sysfs_tablet_mode
        第一个框架选项让按下电源键弹出关机菜单
        第二个框架选项允许通过控制系统文件系统来切换平板模式（翻折YOGA暂不能激活平板模式）
    enforce_hyperthreading=1
        启用英特尔超线程（最近的安全漏洞使得Chrome OS默认禁用了超线程），更好的性能（可能有安全隐患）
    psmouse.synaptics_intertouch=1
        Synaptic触控板多指手势控制



使用Brunch框架运行的Chrome OS更新也需要对Brunch框架进行更新（理论上来说，你也可以仅更新Chrome OS而不更新Brunch框架，但是可能会出现一些兼容性问题）。更新不会清除原本的个人数据，但并不能简单地透过内建的OTA实现“空中更新”，手动倒也不难。和安装类似，需要下载新版本的Brunch框架和恢复镜像，解压缩恢复镜像zip文件（提取.bin出来），然后打开Crosh终端（浏览器按下Ctrl + Alt + T，然后键入shell回车）：
1
2
3

cd ~/Downloads
# 恢复镜像和Brunch框架压缩包文件名可能不同，仅作示范
sudo chromeos-update -r chromeos_13505.63.0_rammus_recovery_stable-channel_mp-v2.bin -f brunch_r87_stable_20201216.tar.gz

稍等片刻，提示完成后关闭选项卡并重启电脑，新版本便升级完成！
Author:





nstall Termux from FDroid. Don’t install it from Google Play. The version in Google Play store is outdated and will not receive any updates until the author has figured a way to target newer Android APIs. Once you’ve done that, open Termux and install proot-distro and use it to install Fedora 33 (check other distributions it supports by proot-distro list)
1
2

pkg install proot-distro
proot-distro install fedora-33

Now we can log into the proot environment and it is Fedora!
1
2
3
4

proot-distro login fedora-33
# the commands below are executed in fedora proot
dnf update
dnf install mate-session-manager mate-desktop mate-themes mate-terminal pluma caja marco glibc-langpack-en firefox

Now you’ve installed some packages for MATE desktop environment and should be ready to have a basic graphical desktop up running. Not so fast yet… Android doesn’t have an X11 server nor a wayland compositor. We then have two choices here:

    VNC/RDP remote desktop
    “Remote” X11

I’m going for the second option here. Mainly because all the VNC clients on Android I’ve tried so far don’t have perfect experience (albeit perfectly usable). To do that, install “XServer XSDL” from Google Play store on the same Android device. Launch it and configure the screen resolution if you need, then we can head back to Termux task and tell Fedora to start a MATE session with a “remote” X server.
1
2

export DISPLAY=localhost:0 PULSE_SERVER=tcp:localhost:4713
mate-session

Remember to acquire wakelock for Termux in the notification area, otherwise Android might kill Termux process to save battery. Now you can head to the XServer XSDL task again, wait for a couple of seconds and you should be greeted by a MATE session (as shown in the screenshot below).
Logging as a Non-root User

You might be struck down by a number of applications that refuse to run in privileged mode (by default, proot logins as root). To solve that and login as a non-root user, you need the good old friends useradd and usermod commands to create a new user in the proot environment:
1
2
3

useradd -m user1  # create a new user with login ID user1
groups root  # check what groups we might need to add
usermod -aG aid_inet user1  # add aid_inet group to user1

Now in the future when you want to login as this user, you can do:
1

proot-distro login fedora-33 --user user1

However it seems that some configuration files are not correctly sorted so you might not be able to use sudo to gain root privilege. The workaround would be to execute those commands in another Termux tab as root.
Locale and Timezone

The system is up running now but it’s been really configured as a bare minimal OS. You might find quite a few things out of the place. Here we’re going to correct the locale and the timezone.

The locale would’ve been configured to the fallback “C”. To make it worse, there is no language pack installed for glibc by default (in the Setup section, we installed English language pack ourselves). Once you’ve installed the language pack you need (and potentially the fonts required), you should be able to see a good candidate in the output of locale -a, pick one and set the LANG environment variable in .bashrc, for example, setting it to British English:
1

export LANG="en_GB.utf8"

Now let’s look at the timezone which is UTC by default, that’s fine on the CLI but might be confusing in a graphical desktop environment. To fix that, run tzselect and edit .bashrc file to add the environment variable for TZ:
1

export TZ="Europe/London"

For example, this sets the timezone to London, UK.
Conclusion







adb shell ime set com.google.android.inputmethod.latin/com.android.inputmethod.latin.LatinIME




----

https://github.com/rust-lang/www.rust-lang.org/

Rust is all about reliability, performance, and security.

# Overview

- 函数式
- 並行式
- 过程式
- 面向对象

# 内存安全

為了提供記憶體安全，它的設計不允許空指標和懸空指標 [25] [26]。 指針只能透過固定的初始化形態來建構，而所有這些形態都要求它們的輸入已經分析過了 [27]。Rust 有一個檢查指標生命期間和指標凍結的系統，可以用來預防在 C++ 中許多的型別錯誤，甚至是用了智慧指標功能之後會發生的型別錯誤。

# 内存管理

Rust 1.0 已不再使用垃圾回收器，而是全面改用基于引用计数的智能指针来管理内存。

# Type

型別系統直接地模仿了 Haskell 語言的类型类概念，並把它稱作「traits」，可以把它看成是一種特设多态。Rust 的作法是透過在宣告型別變數（type variable）的時候，在上面加上限制條件。至於 Haskell 的高階型別變數（Higher-kinded polymorphism）則還未支援。

型別推導也是 Rust 提供的特性之一，使用 let 語法宣告的變數可以不用宣告型別，亦不需要初始值來推斷型別。但如果在稍後的程式中從未指派任何值到該變數，編譯器會發出編譯時（compile time）錯誤 [28]。 函數可以使用泛型化參數（generics），但是必須綁定 Trait。沒有任何方法可以使用方法或運算子，又不宣告它們的型別，每一項都必確明確定義。

Rust 的物件系統是基於三樣東西之上的，即實作（implementation）、Trait 以及結構化資料（如 struct）。實作的角色類似提供 Class 關鍵字的程式語言所代表的意義，並使用 impl 關鍵字。繼承和多型則透過 Trait實現，它們使得方法（method）可以在實作中被定義。結構化資料用來定義欄位。實作和（trait）都無法定義欄位，並且只有（trait）可以提供繼承，藉以躲避C++的「鑽石繼承問題」（菱型缺陷）。

# Hello World

fn main() {
    println!("Hello, World!");
}

階乘

下面是三個不同版本的階乘函數，分別以遞迴、迴圈和反覆運算器的方法寫成：

// 這個函數的 if-else 語句中展示了 Rust 中可選的隱式返回值，可用於寫出更像函數式程式設計風格的代碼
// 與 C++ 和其他類似的語言不同，Rust 中的 if-else 結構不是語句而是運算式，有返回值
fn recursive_factorial(n: u32) -> u32 {
    if n <= 1 {
        1
    } else {
        n * recursive_factorial(n - 1)
    }
}

fn iterative_factorial(n: u32) -> u32 {
    // 變數用`let`定義，`mut`關鍵字使得變數可以變化
    let mut i = 1u32;
    let mut result = 1u32;
    while i <= n {
        result *= i;
        i += 1;
    }
    result // 顯式返回值，與上一個函數不同
}

fn iterator_factorial(n: u32) -> u32 {
    // 反覆運算器有多種用於變換的函數
    // |accum, x| 定義了一個匿名函數
    // 內聯展開等優化方法會消去區間和 fold，使本函數的運行效率和上一個函數相近
    (1..n + 1).fold(1, |accum, x| accum * x)
}

fn main() {
    println!("Recursive result: {}", recursive_factorial(10));
    println!("Iterative result: {}", iterative_factorial(10));
    println!("Iterator result: {}", iterator_factorial(10));
}

併發

一個簡單的 Rust 併發示例：

use std::thread;

// 這個函數將創建十個同時併發運行的執行緒
// 若要驗證這一點，可多次運行這個程式，觀察各執行緒輸出順序的隨機性
fn main() {
    // 這個字串是不可變的，因此可以安全地同時被多個執行緒訪問
    let greeting = "Hello";

    let mut threads = Vec::new();
    // `for`迴圈可用於任何實現了`iterator`特性的類型
    for num in 0..10 {
        threads.push(thread::spawn(move || {
            // `println!`是一個可以靜態檢查格式字串類型的巨集
            // Rust 的巨集是基於結構的（如同 Scheme）而不是基於文本的（如同 C）
            println!("{} from thread number {}", greeting, num);
        }));
    }

    // 收集所有執行緒，保證它們在程式退出前全部結束
    for thread in threads {
        thread.join().unwrap();
    }
}
```


```
下面的代码在 Rust 1.3 中测试通过。
Hello World

fn main() {
    println!("Hello, World!");
}

階乘

下面是三個不同版本的階乘函數，分別以遞迴、迴圈和反覆運算器的方法寫成：

// 這個函數的 if-else 語句中展示了 Rust 中可選的隱式返回值，可用於寫出更像函數式程式設計風格的代碼
// 與 C++ 和其他類似的語言不同，Rust 中的 if-else結構不是語句而是運算式，有返回值
fn recursive_factorial(n: u32) -> u32 {
    if n <= 1 {
        1
    } else {
        n * recursive_factorial(n - 1)
    }
}

fn iterative_factorial(n: u32) -> u32 {
    // 變數用`let`定義，`mut`關鍵字使得變數可以變化
    let mut i = 1u32;
    let mut result = 1u32;
    while i <= n {
        result *= i;
        i += 1;
    }
    result // 顯式返回值，與上一個函數不同
}

fn iterator_factorial(n: u32) -> u32 {
    // 反覆運算器有多種用於變換的函數
    // |accum, x| 定義了一個匿名函數
    // 內聯展開等優化方法會消去區間和 fold，使本函數的運行效率和上一個函數相近
    (1..n + 1).fold(1, |accum, x| accum * x)
}

fn main() {
    println!("Recursive result: {}", recursive_factorial(10));
    println!("Iterative result: {}", iterative_factorial(10));
    println!("Iterator result: {}", iterator_factorial(10));
}

併發

一個簡單的 Rust 併發示例：

use std::thread;

// 這個函數將創建十個同時併發運行的執行緒
// 若要驗證這一點，可多次運行這個程式，觀察各執行緒輸出順序的隨機性
fn main() {
    // 這個字串是不可變的，因此可以安全地同時被多個執行緒訪問
    let greeting = "Hello";

    let mut threads = Vec::new();
    // `for`迴圈可用於任何實現了`iterator`特性的類型
    for num in 0..10 {
        threads.push(thread::spawn(move || {
            // `println!`是一個可以靜態檢查格式字串類型的巨集
            // Rust 的巨集是基於結構的（如同 Scheme）而不是基於文本的（如同 C）
            println!("{} from thread number {}", greeting, num);
        }));
    }

    // 收集所有執行緒，保證它們在程式退出前全部結束
    for thread in threads {
        thread.join().unwrap();
    }
}

```

# 内存安全
## 空指针
## 悬垂指针
## 数据竞争

# Get started

```bash
curl https://sh.rustup.rs -sSf | sh
info: downloading installer

Welcome to Rust!

This will download and install the official compiler for the Rust programming
language, and its package manager, Cargo.

It will add the cargo, rustc, rustup and other commands to Cargo's bin
directory, located at:

  /as/.cargo/bin

This path will then be added to your PATH environment variable by modifying the
profile file located at:

  /as/.profile

You can uninstall at any time with rustup self uninstall and these changes will
be reverted.

Current installation options:

   default host triple: x86_64-unknown-linux-gnu
     default toolchain: stable
  modify PATH variable: yes

1) Proceed with installation (default)
2) Customize installation
3) Cancel installation
1

info: syncing channel updates for 'stable-x86_64-unknown-linux-gnu'
info: downloading component 'rustc'
  9.7 MiB /  35.9 MiB ( 27 %) 147.2 KiB/s ETA: 182 s                error: component download failed for rustc-x86_64-unknown-linux-gnu
info: caused by: could not download file from 'https://static.rust-lang.org/dist/2017-01-31/rustc-1.15.0-x86_64-unknown-linux-gnu.tar.gz' to '/as/.rustup/tmp/xhgfgryisvn69mj6_file
info: caused by: error during download
info: caused by: [28] Timeout was reached (Operation too slow. Less than 10 bytes/sec transferred the last 30 seconds)
rustup: command failed: /tmp/tmp.oF6vd1RryK/rustup-init


...

info: syncing channel updates for 'stable-x86_64-unknown-linux-gnu'
142.1 KiB / 142.1 KiB (100 %) 127.2 KiB/s ETA:   0 s
info: downloading component 'rustc'
 35.9 MiB /  35.9 MiB (100 %) 167.2 KiB/s ETA:   0 s
info: downloading component 'rust-std'
 49.2 MiB /  49.2 MiB (100 %) 441.6 KiB/s ETA:   0 s
info: downloading component 'cargo'
  4.4 MiB /   4.4 MiB (100 %) 192.0 KiB/s ETA:   0 s
info: installing component 'rustc'
info: installing component 'rust-std'
info: installing component 'cargo'
info: default toolchain set to 'stable'

  stable installed - rustc 1.15.0 (10893a9a3 2017-01-19)

Rust is installed now. Great!

To get started you need Cargo's bin directory in your PATH environment
variable. Next time you log in this will be done automatically.

To configure your current shell run source $HOME/.cargo/env


# Hello Rust
```
$ curl -sSf https://static.rust-lang.org/rustup.sh | sh
```

```
~/.cargo/bin/cargo new hello-rust --bin
```

```
cd hello-rust/
[ashang@i3 hello-rust]$ tree
├── Cargo.toml
└── src
    └── main.rs
```

```
# Cargo.toml
[package]
name = "hello-rust"
version = "0.1.0"
authors = ["Aaron Shang <aaronshang@gmail.com>"]

[dependencies]
```

```
# src/main.rs

fn main() {
    println!("Hello, world!");
}
```


```
~/.cargo/bin/cargo build
[ashang@i3 hello-rust]$ tree
.
├── Cargo.lock
├── Cargo.toml
├── src
│   └── main.rs
└── target
    └── debug
        ├── build
        ├── deps
        │   └── hello_rust-79029cc8d2d35ec6
        ├── examples
        ├── hello-rust
        └── native
```

```
./target/debug/hello-rust
~/.cargo/bin/cargo run
```


```
~/.cargo/bin/cargo clean
```

# Install

curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

$ curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
info: downloading installer

Welcome to Rust!

This will download and install the official compiler for the Rust
programming language, and its package manager, Cargo.

It will add the cargo, rustc, rustup and other commands to
Cargo's bin directory, located at:

  /home/aaron/.cargo/bin

This can be modified with the CARGO_HOME environment variable.

Rustup metadata and toolchains will be installed into the Rustup
home directory, located at:

  /home/aaron/.rustup

This can be modified with the RUSTUP_HOME environment variable.

This path will then be added to your PATH environment variable by
modifying the profile files located at:

  /home/aaron/.profile
/home/aaron/.bash_profile

You can uninstall at any time with rustup self uninstall and
these changes will be reverted.

Current installation options:


   default host triple: x86_64-unknown-linux-gnu
     default toolchain: stable
               profile: default
  modify PATH variable: yes

1) Proceed with installation (default)
2) Customize installation
3) Cancel installation

info: profile set to 'default'
info: default host triple is x86_64-unknown-linux-gnu
info: updating existing rustup installation


Rust is installed now. Great!

To get started you need Cargo's bin directory ($HOME/.cargo/bin) in your PATH
environment variable. Next time you log in this will be done
automatically.

To configure your current shell run source $HOME/.cargo/env

# Links
- https://zhuanlan.zhihu.com/p/101118828
- https://www.tuicool.com/articles/ZBf6ZnF






Rust 的异步⽣态：重点介绍 Tokio（运⾏时、框架以及⼯具链）

----

1. Rust?

    在 Go 上的尝试
        Sonic，Frugal

    性能和安全的结合
        接近 C 性能和编译时保证内存安全
        举例：AWS， Discord

2. Rust 服务开发实战

    项⽬背景
        代理服务
        技术栈：Tokio，Thrift
    成本和收益（投⼊产出）
        数据
    如何优化
        编译优化
        ⽕焰图
        观测组件：Console，Metrics




----


curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

rustup

Rust is installed and managed by the rustup tool.

 In the Rust development environment, all tools are installed to the ~/.cargo/bin directory, and this is where you will find the Rust toolchain, including rustc, cargo, and rustup.

## Cargo: the Rust build tool and package manager

When you install Rustup you’ll also get the latest stable version of the Rust build tool and package manager, also known as Cargo. Cargo does lots of things:

    build your project with cargo build
    run your project with cargo run
    test your project with cargo test
    build documentation for your project with cargo doc
    publish a library to crates.io with cargo publish

Generating a new project

cargo new hello-rust

This will generate a new directory called hello-rust with the following files:

hello-rust
|- Cargo.toml
|- src
  |- main.rs

Cargo.toml is the manifest file for Rust. It’s where you keep metadata for your project, as well as dependencies.

src/main.rs is where we’ll write our application code.

cargo new generates a "Hello, world!" project for us! We can run this program by moving into the new directory that we made and running this in our terminal:

cargo run

You should see this in your terminal:

$ cargo run
   Compiling hello-rust v0.1.0 (/Users/ag_dubs/rust/hello-rust)
    Finished dev [unoptimized + debuginfo] target(s) in 1.34s
     Running `target/debug/hello-rust`
Hello, world!

Adding dependencies

Let’s add a dependency to our application. You can find all sorts of libraries on crates.io, the package registry for Rust. In Rust, we often refer to packages as “crates.”

In this project, we’ll use a crate called ferris-says.

In our Cargo.toml file we’ll add this information (that we got from the crate page):

[dependencies]
ferris-says = "0.2"

Now we can run:

cargo build

...and Cargo will install our dependency for us.

You’ll see that running this command created a new file for us, Cargo.lock. This file is a log of the exact versions of the dependencies we are using locally.

To use this dependency, we can open main.rs, remove everything that’s in there (it’s just another example), and add this line to it:

use ferris_says::say;

This line means that we can now use the say function that the ferris-says crate exports for us.

Now let’s write a small application with our new dependency. In our main.rs, add the following code:

use ferris_says::say; // from the previous step
use std::io::{stdout, BufWriter};

fn main() {
    let stdout = stdout();
    let message = String::from("Hello fellow Rustaceans!");
    let width = message.chars().count();

    let mut writer = BufWriter::new(stdout.lock());
    say(message.as_bytes(), width, &mut writer).unwrap();
}

cargo run

Assuming everything went well, you should see your application print this to the screen:

----------------------------
< Hello fellow Rustaceans! >
----------------------------
              \
               \
                 _~^~^~_
             \) /  o o  \ (/
               '_   -   _'
               / '-----' \

cargo new <project_name>
cargo build  # compile.
cargo run  # compile & run.
cargo check  # check, but not compile into binary (faster than aboves).
cargo build --release  # building for release.
cargo update  # update all the dependent crates.
cargo doc --open

[package]
name = "hello_cargo"
version = "0.1.0"
authors = ["Becavalier <yhorg@hotmail.com\>"]
edition = "2018"

[dependencies]

https://blog.rust-lang.org/2014/10/30/Stability.html

https://doc.rust-lang.org/nightly/rustc/platform-support.html

https://github.com/rust-lang/rust-by-example

https://doc.rust-lang.org/std/

https://doc.rust-lang.org/stable/rust-by-example/hello.html


https://www.yhspy.com/2021/03/23/%E3%80%8AThe-Rust-Programming-Language%E3%80%8B%E8%AF%BB%E4%B9%A6%E7%AC%94%E8%AE%B0%EF%BC%88%E7%AC%AC-1-6-%E7%AB%A0%EF%BC%89/


----


       --add-gnu-debuglink=path-to-file
           Creates a .gnu_debuglink section which contains a reference to path-to-file and adds it to the output file.  Note: the file at path-to-file must exist.
           Part of the process of adding the .gnu_debuglink section involves embedding a checksum of the contents of the debug info file into the section.

           If the debug info file is built in one location but it is going to be installed at a later time into a different location then do not use the path to the
           installed location.  The --add-gnu-debuglink option will fail because the installed file does not exist yet.  Instead put the debug info file in the
           current directory and use the --add-gnu-debuglink option without any directory components, like this:

                    objcopy --add-gnu-debuglink=foo.debug

           At debug time the debugger will attempt to look for the separate debug info file in a set of known locations.  The exact set of these locations varies
           depending upon the distribution being used, but it typically includes:

           "* The same directory as the executable."
           "* A sub-directory of the directory containing the executable"
               called .debug

           "* A global debug directory such as /usr/lib/debug."

           As long as the debug info file has been installed into one of these locations before the debugger is run everything should work correctly.




