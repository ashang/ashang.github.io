---
date: 2016-02-11
title: CSS
tags:
  - "margin, padding, border"
  - "div, .class, #id, [attr]"
  - "font, background"
  - "display: block, inline, flex"
  - Selectors
  - Properties
---

HTML负责确定网页中有哪些内容，CSS确定以何种外观(大小、粗细、颜色、对齐和位置)展现这些元素。CSS可以用于设定页面布局、设定页面元素样式、设定适用于所有网页的全局样式。CSS可以零散地直接添加在要应用样式的网页元素上，也可以集中化内置于网页、链接式引入网页以及导入式引入网页。[1]

CSS最重要的目标是将文件的内容与它的显示分隔开来。在CSS出现前，几乎所有的HTML文件内都包含文件显示的信息，比如字体的颜色、背景应该是怎样的、如何排列、边缘、连线等等都必须一一在HTML文件内列出，有时重复列出。CSS使作者可以将这些信息中的大部分隔离出来，简化HTML文件，这些信息被放在一个辅助的，用CSS语言写的文件中。HTML文件中只包含结构和内容的信息，CSS文件中只包含样式的信息。


由于CSS的优点，W3C现在正在考虑将HTML中的许多显示用的指令废弃掉。

	
	HTML只表达文章的结构，CSS表达所有的显示。CSS可以指示颜色、字形、排列、大小以及其他许多非视觉的表达方式，比如将一篇文件的内容读出来。

CSS样式信息可以包含在一个附件中或包含在HTML文件内。读者可以使用多个样式表，在重复的情况下他可以选择其中之一。不同的介质可以使用不同的样式表。比如一个文件在荧光屏上的显示可以与在打印机中打印出来的显示不同。这样作者可以为不同的媒体设计最佳的显示方式。此外CSS的目标之一是让读者有更大的控制显示的自由。假如一个读者觉得斜体字的标题读起来很困难，他可以使用自己的样式表文件，这个样式表可以“层叠”使用，他可以只改变红色斜体字这个样式而保留所有其他的样式。


主要内容

CSS由多组“规则”组成。每个规则由“选择器”（selector）、“属性”（property）和“值”（value）组成：

    选择器（Selector）：多个选择器可以半角逗号（,）隔开。
    属性（property）：CSS1、CSS2、CSS3规定了许多的属性，目的在控制选择器的样式。
    值（value）：指属性接受的设置值，多个关键字时大都以空格隔开。

属性和值之间用半角冒号（:）隔开，属性和值合称为“特性”。多个特性间用“;”隔开，最后用“{ }”括起来。
选择器

要针对没有标签定义范围进行样式设置时，可利用<div>与<span>标签

CSS里现在共有5种基本选择器（Basic Selectors）[2]和2种伪选择器。不同选择器的优先级别和运作性能往往存在差异。[3]
基本选择器

    标签选择器（h1，p等）——elementname
    类别选择器（class）——.elementname
    ID选择器（ID）——#elementname
    万用选择器——* ns|* *|*
    属性选择器（也翻译为“通配符选择器”）——[attribute]

属性选择器

属性选择器允许用户自定义属性名称，而不仅仅限于id，class属性。属性选择器共有7种[4][5]。
代码 	说明
[attribute] 	元素有attribute的属性。
[attribute="value"] 	属性attribute里是value
[attribute~="value"] 	属性attribute里使用空白分开的字符串里其中一个是value
[attribute|="value"] 	属性attribute里是value或者以value-开头的字符串
[attribute^="value"] 	属性attribute里最前的是value
[attribute$="value"] 	属性attribute里最后的是value
[attribute*="value"] 	属性attribute里有value出现过至少一次
组合选择器

CSS里现在共有4种组合选择符（Combinators）：[2]
符号 	说明
A > B 	子代选择器，选择A下一层的元素B
A ~ B 	兄弟选择器，选择与A同层的元素B
A + B 	相邻兄弟选择器，选择与A相邻的元素B（不能被任何元素相隔）
A B 	后代选择器，包含选择符





引入CSS规则的多种方式及其层叠性

CSS可以有多种引入方式，一个网页可以引入多个CSS文件，同一种CSS规则可以被反复多次添加。这使得CSS的使用方式非常灵活，但也会频繁地出现规则冲突。同时对一个网页元素设定无法并存的2种样式时，就会引起冲突。CSS的特色之一就是其解决规则冲突的方案。CSS的规则冲突可以分为不同来源之间的规则冲突和同一来源内部的规则冲突。CSS分层次、立体化的比较不同规则的优先级的方式，就是所谓层叠性(cascading)的体现。

首先说来源的多样性，CSS信息可以来自：

    作者样式
        作者可以在他的HTML文件中确定一个外来的、独立的CSS文件（外部样式表），其优先级最低
        作者可以将CSS信息包含在HTML文件内（内部样式表）
        作者可以在一个HTML指令内结合CSS指令（内联样式），其优先级最高。一般这样做是为了在特殊情况下，把上面来源的CSS抵消掉

    客户端自定义样式（client-side style sheet）
        浏览网页的用户可以自己在本地计算机上自己写1个CSS文件，然后就可以在浏览器内通过设置好特定选项，来加载自己的CSS文件。这个CSS文件可以用在所有的HTML文件上。当网页作者没有设定某项规则，但存在对应的用户自定义规则时，用户的规则就会起作用。假如作者的CSS文件与读者的相冲突，浏览器会采用作者的规则。如果读者有特殊要求，可以通过在自定义规则末尾添加!important提升自定义规则的显示优先权。(网页作者也可以使用!important给规则提升权限，但是优先级别比不过由用户写的!important声明，!important对于网页作者的意义仅在于网页开发阶段的规则冲突测试)

    浏览器样式
        假如外部没有特别指定一个样式的话，一般浏览器自己有一个内在的样式。由于不同浏览器的默认样式并不一致，所以讲究美观的网页的设计者一般喜欢去掉这个默认的样式。

其次还需知道规则特殊性(specificity)的概念。某个规则的特殊性也常被称为该规则的具体程度。规则特殊性的高低次序如下（依次递减）：

    行内样式
    ID选择器
    class选择器
    标签选择器
    通用选择器（也就是通配符选择器，用得少）

特殊性优先原则

特殊性优先原则是最重要的优先级比较规则。当引起冲突的2种规则的特殊性存在差异时（例如一个是通过ID选择器指定样式，另一个是通过class选择器指定样式），引擎将优先采用特殊性更高的样式。规则的特殊性的比较是最优先的。如果能直接判断出特殊性的差异，就无需考虑其它规则了。
不同来源的规则优先性

不同来源的规则之间的优先原则是第二重要的。当规则来源相同时（同为外部样式或同为内部样式），下一步就需要比较不同类型来源的优先级别。总地来说，记住“行内样式优先于内部样式，内部样式又优先于外部样式”即可应对多数常见的情形。像网页浏览者自定义样式表的优先级别如何，只有浏览器的设计者才需要考虑，与网页设计者的关系不大。

如果考虑有可能出现的更复杂的来源冲突，内容就比较多了。但一般在写样式时，应尽可能避免这些复杂情形的出现。具体来说，一般情形下的采纳样式效果的优先级顺序为：[6]

    行内样式
    内部样式
    在HTML中通过<link>标签直接引入的外部样式表
    在CSS中通过@import语句间接引入的外部样式表
    浏览网页的用户自己定义的样式表（需要手动加载）
    浏览器默认的样式（如标题有默认大小、段落之间有默认间距等，不同浏览器的默认样式不完全一样）

CSS中还有用!important修饰的重要性声明。如果计入重要性声明，那么在以上规则的最前面还需要加上2条规则：

    用户从本地加载的重要自定义样式
    网页设计者设定的重要样式

设计重要性声明是为部分特殊用户和所有开发者提供方便。一方面，用户可以通过设置自己的色彩方案，并对其使用重要性声明来提升浏览体验。另一方面，网页的设计者难免会遇到因规则冲突而导致特定样式规则失效的情形，设计者可以通过给不知何故不起作用的规则增加重要性声明，看看是否有样式变化来确定是否是不小心导致了规则冲突而引起特定规则被覆盖失效。
权重分数比较机制

有时还会遇到选择器优先级无法直接判断，而且规则的来源也相同的情形。如果网页设计者很少使用层次比较复杂的选择器（比如多级的后代选择器），那么必须比较权重的情况一般不会遇到（一般要么是可以直接根据前面的规则判断出优先性结果，或者是起冲突的2条规则的权重完全一样，只能继续去看后一条比较出现次序的机制）。此时，CSS还有一套分数加权(或者说是分数累积)的机制用于解决此类规则冲突。先列出基本的分值：

    1个行内样式占1000分
    1个id选择器占100分
    1个class选择器占10分
    1个标签选择器占1分

组合使用多个基本选择器时，不同选择器的得分会累加到一起。最终得分高的选择器，其指定的样式会胜出。

举例：
.type1 #id3{color: green; font-size: 20px;}
div p #id3{color: blue; background-color: grey;}
假设这2行代码都能够选中同一个ID为“id3”的元素，且都是出自同一来源的样式表。可以看到，二者使用的优先级最高的选择器都是ID选择器，起冲突的样式设置是字体颜色。一个给此元素设置字体颜色为绿色，另一个给此元素设置字体颜色为蓝色。按照评分规则，因为前一种代码使用了1个类选择器和1个id选择器，所以得分为10+100=110分；后一种代码使用了2个标签选择器和1个id选择器，所以得分为1+1+100=102分。因为110分>102分，所以前一种规则胜出，目标元素的最终文字颜色应该是绿色。
靠后者优先原则
当权重比较仍然不能分出优先级胜负时，最后就是把守关底的“靠后优先”的原则了，也就是后定义的样式优先级较高。如果起冲突的规则来源相同，而且得分也相同，那么最后的冲突解决法则就是看CSS代码出现的先后顺序。后出现的规则会覆盖掉与之优先级相当的先出现的规则。也可称作“后发制人”、“后来者居上”或“后浪推前浪”原则，随便你怎么称呼。这种原则的适用情形很常见，所以此规则也很重要。 




HTML规范虽然规定了网页中的标题、段落应该使用的标签，但是没有涉及这些内容应该以何种样式(比如大小、位置、间距、缩进等属性)呈现在浏览器中。从1990年代初HTML被发明开始，样式表就以各种形式出现了。不同的浏览器结合了它们各自的样式语言，读者(也就是浏览网页的用户)可以使用这些样式语言来调节网页的显示方式。一开始样式表是给读者用的，最初的HTML版本只含有很少的显示属性，读者来决定网页应该怎样被显示。

1993年，Robert Raisch提出了一种名为“RRP”的样式规则建议。但这个RRP只允许网页使用1个样式表，不像现在的CSS能支持同时加载多个。不久后出现的Mosaic浏览器就采用增加新种类的HTML标签实现样式的表达，以满足设计师的要求，这也与现在的CSS设计原则不符。随着HTML自带的样式功能的增加，外来定义样式的语言逐渐减弱了。1993年发布的这个Mosaic浏览器是第一款用户界面，并支持书签、图标按钮和图片显示。[8]之前的浏览器都是纯文字浏览器。即使在今天，只使用操作系统命令行自带的Telnet命令，也可以查看网页的源代码。[9]

后来，台湾人魏培源开发的ViolaWWW浏览器使用了一种规则具有层次嵌套性的样式表，并第1个支持通过<link>标签引用外部样式表。FOSI最早支持以相对尺寸值来表示字体大小。函数式风格的DSSSL语言支持在样式表中进行定义变量、继承变量、定义函数等功能，但是语法复杂。1994年，万维网之父蒂姆·伯纳斯-李在欧美众多高能物理研究者和技术人员的支持下，于美国麻省理工学院创立了万维网联盟（W3C），其职责是提供网络标准化建议。[10]1994年，Håkon W Lie提出层叠HTML样式表（Cascading HTML Style Sheets，CHSS）。CHSS既支持用户自定义样式表，也支持网页作者样式表，而且可以满足不同规则以百分比的方式组合使用。它的权重规则计算方式不够直观，当不同规则混合时会得到什么实际效果并不容易从代码中看出。1996年，出现了与CSS语法很像的表现指明语言（Presentation Specification Language，简称"PSL 96"）。PSL 96除表达样式外，也支持条件判断等功能，还可根据对浏览器信息的判断来使用不同的样式，但未获得青睐。
CSS的诞生与发展

1994年，哈肯·维姆·莱提出了CSS的最初建议。伯特·波斯当时正在设计一个叫做Argo的浏览器，他们决定一起合作设计CSS。当时已经有过一些样式表语言的建议了，但CSS是第一个含有“层叠”的主意的。在CSS中，一个文件的样式可以从其他的样式表中继承下来。读者在有些地方可以使用他自己更喜欢的样式，在其他地方则继承，或“层叠”作者的样式。这种层叠的方式使作者和读者都可以灵活地加入自己的设计，混合各人的爱好。哈肯·莱于1994年在芝加哥的一次会议上第一次展示了CSS的建议，1995年他与波斯一起再次展示这个建议。当时W3C刚刚创建，W3C对CSS的发展很感兴趣，它为此组织了一次讨论会。哈肯、波斯和其他一些人（比如微软的托马斯·里尔登）是这个项目的主要技术负责人。1996年底，CSS已经完成。1996年12月[来源请求]，哈肯·莱与伯特·波斯发布了CSS规范的第1个版本。这也成了哈肯·莱的博士论文的一部分。当时已有的主流浏览器的内核架构完全不适合解析CSS的语法，加上早年设计师滥用HTML标签来表达样式(这导致“标签汤”(tagsoup)这一骂名的出现)、且漠不关心代码校验[11]，所以CSS等到几年之后才流行起来。1998年，浏览器市场份额被微软公司的Internet Explorer 4和网景公司的Netscape Navigator 4两大浏览器巨头所占据。[10]CSS出现后，微软的IE浏览器走在了逐步实现CSS第1版标准的前列。但是因为不重视问题修补，导致遗留Bug很多，这也使得IE浏览器长期为人们诟病。网景则把重心放在了网页脚本语言的开发上，但很快被微软模仿。网景在90年代末和微软展开的浏览器大战中最终一败涂地，走向破产边缘，但网景也成功推出了日后广泛流行于网页设计中的JavaScript语言。浏览器大战使得网页设计人员深受其害，因为不同浏览器支持的语法规则不太一样，网页设计人员不得不为IE浏览器和网景浏览器的浏览器分别设计一套网页。[10]新成立的民间设计人员团体“网页标准计划”(WaSP)发动水军将W3C的建议宣扬为标准，并批评还未加盟W3C标准的业界厂商。[10]

1997年初，W3C组织了专门管CSS的工作组，其负责人是克里斯·里雷。这个工作组开始讨论第1版中没有涉及到的问题，其结果是1998年5月出版的第2版规则。网页标准计划的7位成员成立了“CSS武士团”（CSS Samurai），指出Opera浏览器和IE浏览器在支持CSS方面存在的诸多问题。Opera公司着手解决了问题，但微软并未解决。网页标准计划也积极劝说网景公司和Macromedia公司分别改进其产品对CSS标准的支持。2003年，Dave Shea推出了一个名为“CSS禅意花园”("CSS Zen Garden")的站点，向人们展示出仅通过应用不同页面样式规则，就可以实现对网页艺术风格的焕然一新。这个网站在网页设计相关人群中产生了不小影响。[10]

从2006年到2009年，“DIV+CSS”布局逐步取代缺乏灵活性的传统表格布局，无表格网页设计成为网页内容布局的主流方案。此时也出现了一些为了跟风而滥用DIV布局的情况，比如将<h1>和<h2>等本身已有语义的标签也改用<div>标签替代。[12]

CSS3引入的简单动画功能使得CSS也开始涉足以往只应由JavaScript负责的效果交互工作。到2017年为止，第3版规则还未完备。



	


浏览器内核主要负责解析网页内容样式以及进行脚本处理（现在分别由浏览器内部的页面渲染引擎和JavaScript引擎分工）。其中页面渲染就是正确识别出CSS代码并在窗口中显示出对应的内容样式。开发一个可支持CSS语法解析的浏览器并非易事，CSS规则繁杂，尤其是需要考虑不同的CSS规则之间会存在相互影响的问题。自从Mozilla基金会将Gecko排版引擎单独发布后，现在有众多浏览器厂商采用由第三方发布的页面渲染引擎，独立开发新页面渲染引擎的机构很少。

首先是标准实现程度的问题。尽管CSS1标准在1996年就制订完成了，但一直到3年后还没有一个浏览器实现了其中的全部语法规则。上市的各个浏览器都只是实现了对一部分规则的支持。2000年3月，由微软在麦金塔电脑平台上发布的5.0版Internet Explorer (IE)是第1个全部实现CSS1的浏览器。此后许多其他浏览器也实现了CSS1和CSS2的一部分。但到2004年为止还没有一个浏览器实现了全部CSS2规则。尤其aural和paged等特性是被支持得最差的。

其次，支持某种特性，不代表用起来就没有问题。旧IE版本就以Bug多而闻名。其中声名狼藉的IE 6存在元素堆叠Bug、幽灵字符，方块神秘消失等稀奇古怪的设计缺陷。[22]微软自从在第1轮浏览器大战中胜出后，就依仗独霸市场的优势，轻视修补IE Bug的呼声，导致其市场份额后来又逐渐被其它浏览器蚕食，产生第2轮浏览器大战。

另外还有代码跨浏览器兼容性的问题。“能够在任何浏览器中显示”并不意味着“在任何一个浏览器中显示的效果相同”。[11]即使是彻底实现了CSS1的浏览器也遇到了许多困难。许多CSS的实现机制互相矛盾、有错或有其它稀奇古怪的地方。为了使他们的页面在任意系统上的任意浏览器中的显示效果一致，网页作者往往要被迫写出繁琐的代码或使用各种奇技淫巧。一个最著名的错误涉及到显示方形的宽度，在IE浏览器中方形的宽度的显示有错误，其结果是方形的宽度在许多浏览器中被正确地显示，但在IE上方形的宽度太窄。虽然这个错误有解决的办法，但它限制了其他一些功能（IE 8.0已经改善方形宽度显示问题）。旧版IE还有与其它浏览器计算方式不一样的方盒模型。






    垂直控制的局限

        元素的水平放置普遍地易于控制，垂直控制则不然。简单来说，垂直地围绕一个元素、页脚的放置不能高于可见视窗（viewport，视窗或屏幕的可见范围[25]）的底部范围。这需要复杂的样式规则，或是规则简单，但不被广泛支持。

    没有算术功能

        直至CSS 2.1的CSS没有办法明确简单地进行计算（例如：margin-left: 10% - 3em + 4px;）。计算功能在很多情况下都是非常有用的，例如：总字段中计算字段的尺寸限制。无论如何，CSS WG[26]发表了CSS局限性的草案。IE 5至IE 7提供expression()函数（即所谓的CSS表达式）来执行计算功能，例如left: expression（document.body.offsetWidth - 110 + "px"）; 。为了与CSS标准看齐，并且该函数性能差，微软从IE 8开始停止支持此函数。
        CSS 3中具有calc()表达式以执行计算功能[27][28]。

p {
    margin: calc (1rem - 2px) calc (1rem - 1px) 
}

    缺乏唯一性

        同样的效果可以用不同的属性来完成，这对不少的CSS编写人员造成困扰。例如position、display与float定义了不同的配置方式，而且不能有效的交替使用。一个display: table-cell元素不能指定float或是position: relative，因为指定float: left的元素不应该受到display效果的影响。再者，没有考虑到新创建属性所造成的影响，例如在表格中你应该使用border-spacing而不是margin-*来指定表格元素。这是因为依照CSS准则，表格内部元素是没有边界（margin）的。






## @content

```css
@mixin ie6 { * html & { @content } }

#logo {
  background-image: url("/images/logo.png");
  @include ie6 {
    background-image: url("/images/logo.gif");
  }
}
#logo {
  background-image: url("/images/logo.png");
}
* html #logo {
  background-image: url("/images/logo.gif");
}
```

## Compared with `block comment`, `line comment` is easy for tuning around back and forth.



Update: Whoops, got my own CSS syntax wrong. Sorry, winkybarf ({};), you're no good.

You can avoid this by ending your text comment with a {} (if you're outside of a rule) or a ; (if you're around some declarations), to let the CSS engine know that you're just kidding around:

// Do some stuff {}
.foo { animation: bar 1s infinite; }
/* Success! */
The astute among you will have noticed (or already known) that using // like this isn't really "commenting out" anything at all. Instead, it's just putting an invalid value into the stylesheet and relying on CSS's error-recovery rules to kill the next construct on the page and then recover gracefully. Because CSS's error recovery is well-defined, you can rely on every browser that implements it correctly to work in the expected way.


CSS does actually already allow you to use //, after a fashion. It's not quite a line comment, but a next construct comment.

//@keyframes foo {
from, to { width: 500px; }
50% { width: 400px; }
}

This will comment out the whole construct.

# gtk.css:253:4: Expected semicolon


## Basics

### Selectors

```css
.class {
  font-weight: bold;
}
```

| Selector          | Description  |
| ----------------- | ------------ |
| `*`               | All elements |
| `div`             | Element      |
| `.class`          | Class        |
| `#id`             | ID           |
| `[disabled]`      | Attribute    |
| `[role="dialog"]` | Attribute    |

### Combinators

| Selector            | Description       |
| ------------------- | ----------------- |
| `.parent .child`    | Descendant        |
| `.parent > .child`  | Direct descendant |
| `.child + .sibling` | Adjacent sibling  |
| `.child ~ .sibling` | Far sibling       |
| `.class1.class2`    | Have both classes |

### Attribute selectors

| Selector           | Description                         |
| ------------------ | ----------------------------------- |
| `[role="dialog"]`  | `=` Exact                           |
| `[class~="box"]`   | `~=` Has word                       |
| `[class|="box"]`   | `|=` Exact or prefix (eg, `value-`) |
| `[href$=".doc"]`   | `$=` Ends in                        |
| `[href^="/index"]` | `^=` Begins with                    |
| `[class*="-is-"]`  | `*=` Contains                       |

### Pseudo-classes

| Selector             | Description                                |
| -------------------- | ------------------------------------------ |
| `:target`            | eg, `h2#foo:target`                        |
| ---                  | ---                                        |
| `:disabled`          |                                            |
| `:focus`             |                                            |
| `:active`            |                                            |
| ---                  | ---                                        |
| `:nth-child(3)`      | 3rd child                                  |
| `:nth-child(3n+2)`   | 2nd child in groups of 3                   |
| `:nth-child(-n+4)`   |                                            |
| ---                  | ---                                        |
| `:nth-last-child(2)` |                                            |
| `:nth-of-type(2)`    |                                            |
| ---                  | ---                                        |
| `:checked`           | Checked inputs                             |
| `:disabled`          | Disabled elements                          |
| `:default`           | Default element in a group                 |
| ---                  | ---                                        |
| `:empty`             | Elements without children                  |

### Pseudo-class variations

| Selector          |
| ----------------- |
| `:first-of-type`  |
| `:last-of-type`   |
| `:nth-of-type(2)` |
| `:only-of-type`   |
| ---               |
| `:first-child`    |
| `:last-child`     |
| `:nth-child(2)`   |
| `:only-child`     |

## Fonts

### Properties

| Property           | Description                          |
| ------------------ | ------------------------------------ |
| `font-family:`     | `<font>, <fontN>`                    |
| `font-size:`       | `<size>`                             |
| `letter-spacing:`  | `<size>`                             |
| `line-height:`     | `<number>`                           |
| ---                | ---                                  |
| `font-weight:`     | `bold` `normal`                      |
| `font-style:`      | `italic` `normal`                    |
| `text-decoration:` | `underline` `none`                   |
| ---                | ---                                  |
| `text-align:`      | `left` `right` `center` `justify`    |
| `text-transform:`  | `capitalize` `uppercase` `lowercase` |

### Shorthand

|         | style    | weight | size (required) |     | line-height | family            |
| ------- | -------- | ------ | --------------- | --- | ----------- | ----------------- |
| `font:` | `italic` | `400`  | `14px`          | `/` | `1.5`       | `sans-serif`      |
|         | style    | weight | size (required) |     | line-height | family (required) |

### Example

```css
font-family: Arial;
font-size: 12pt;
line-height: 1.5;
letter-spacing: 0.02em;
color: #aa3322;
```

### Case

```css
text-transform: capitalize; /* Hello */
text-transform: uppercase; /* HELLO */
text-transform: lowercase; /* hello */
```

## Background

### Properties

| Property                 | Description                              |
| ------------------------ | ---------------------------------------- |
| `background:`            | _(Shorthand)_                            |
| ---                      | ---                                      |
| `background-color:`      | `<color>`                                |
| `background-image:`      | `url(...)`                               |
| `background-position:`   | `left/center/right` `top/center/bottom`  |
| `background-size:`       | `cover` `X Y`                            |
| `background-clip:`       | `border-box` `padding-box` `content-box` |
| `background-repeat:`     | `no-repeat` `repeat-x` `repeat-y`        |
| `background-attachment:` | `scroll` `fixed` `local`                 |

### Shorthand

|               | color  | image         | positionX | positionY |     | size           | repeat      | attachment |
| ------------- | ------ | ------------- | --------- | --------- | --- | -------------- | ----------- | ---------- |
| `background:` | `#ff0` | `url(bg.jpg)` | `left`    | `top`     | `/` | `100px` `auto` | `no-repeat` | `fixed;`   |
| `background:` | `#abc` | `url(bg.png)` | `center`  | `center`  | `/` | `cover`        | `repeat-x`  | `local;`   |
|               | color  | image         | positionX | positionY |     | size           | repeat      | attachment |

### Multiple backgrounds

```css
background: linear-gradient(to bottom, rgba(0, 0, 0, 0.5), rgba(0, 0, 0, 0.5)),
  url('background.jpg') center center / cover, #333;
```

## Animation

### Properties

| Property                     | Value                                                    |
| ---------------------------- | -------------------------------------------------------- |
| `animation:`                 | _(shorthand)_                                            |
| `animation-name:`            | `<name>`                                                 |
| `animation-duration:`        | `<time>ms`                                               |
| `animation-timing-function:` | `ease` `linear` `ease-in` `ease-out` `ease-in-out`       |
| `animation-delay:`           | `<time>ms`                                               |
| `animation-iteration-count:` | `infinite` `<number>`                                    |
| `animation-direction:`       | `normal` `reverse` `alternate` `alternate-reverse`       |
| `animation-fill-mode:`       | `none` `forwards` `backwards` `both` `initial` `inherit` |
| `animation-play-state:`      | `normal` `reverse` `alternate` `alternate-reverse`       |

### Shorthand

|              | name     | duration | timing-function | delay   | count      | direction           | fill-mode | play-state |
| ------------ | -------- | -------- | --------------- | ------- | ---------- | ------------------- | --------- | ---------- |
| `animation:` | `bounce` | `300ms`  | `linear`        | `100ms` | `infinite` | `alternate-reverse` | `both`    | `reverse`  |
|              | name     | duration | timing-function | delay   | count      | direction           | fill-mode | play-state |

### Example

```css
animation: bounce 300ms linear 0s infinite normal;
animation: bounce 300ms linear infinite;
animation: bounce 300ms linear infinite alternate-reverse;
animation: bounce 300ms linear 2s infinite alternate-reverse forwards normal;
```

### Event

```js
.one('webkitAnimationEnd oanimationend msAnimationEnd animationend')
```

### 样式表的优先级（从高到低）：

1.  标签内书写的`行内样式`
2.  当前文件里面定义的`内部样式`
3.  引入进来的`外部样式`
4.  浏览器默认规则

行内样式：`\< p style="text-align: center; color: red" \> \</ p \>`

内部样式：`\< style type="text/css" \> CSS 代码 \</ style \>`

外部样式（`rel`属性不能省略）：`\< link rel="stylesheet" type="text/css"
href="test.css" \>`


### 编码基础

`CSS`基本组成：`选择器`、`属性`、`值`，如 `body {color: black}`

`CSS`注释和`C/C++/Java`的多行注释一致，如 `/\* CSS 注释 \*/`

如果值由多个单词组成，则需要用双引号括起，如 `p {font-family: "sans serif"}`

多个属性使用分号间隔（可以每个属性一行，但分号不能省略），如 `p {text-align: center; color: red}`

多个标签使用同一样式，使用逗号分隔，如 `h1, h2, h3 {color: green}`


### 规则详解

`1`、`类选择器`

通过 `.` 号来选择性渲染有`class`标识的元素，每一个`HTML`元素最多只能有一个`class`属性，如
`p.cat {text-align: center}`

`类选择器`可以没有标签名，这将匹配所有`class`属性和选择器名一致的元素，如 `.cat {text-align:
center}`

`2`、`id 选择器`

通过 `\#` 号来选择性渲染有`id`标识的元素，通常在每一个`HTML`页面中不应有重复的`id`，如 `p\#cat
{color: red}`

`id 选择器`同样也可以没有标签名，这将匹配所有`id`属性和选择器名一致的元素，如 `\#cat {color: red}`

3、`链接样式`

对于`\< a \> \</ a \>`标签，有四种不同的形态：

1.  `a:link`：链接还没有任何操作的时候
2.  `a:hover`：鼠标放在链接上面的时候
3.  `a:active`：鼠标点击了链接，但还没有松开的时候
4.  `a:visited`：链接已经被访问过的时候



[Simple CSS](http://www.hostm.com/css/)
不仅可以从零开始编写
CSS，而且也能导入存在的样式表，并重新修改它。Simple CSS
是免费软件，目前支持 CSS2 规范。

[![Simple
CSS](http://i.linuxtoy.org/i/2007/04/simple-css_s.png)](http//i.linuxtoy.org/i/2007/04/simple-css.png)

- [Download Simple CSS 1.21](http://www.hostm.com/simplecss-download.m)
# CSS 操作

CSS 与 JavaScript 是两个有着明确分工的领域，前者负责页面的视觉效果，后者负责与用户的行为互动。但是，它们毕竟同属网页开发的前端，因此不可避免有着交叉和互相配合。本章介绍如何通过 JavaScript 操作 CSS。

## HTML 元素的 style 属性

操作 CSS 样式最简单的方法，就是使用网页元素节点的`getAttribute()`方法、`setAttribute()`方法和`removeAttribute()`方法，直接读写或删除网页元素的`style`属性。

```javascript
div.setAttribute(
  'style',
  'background-color:red;' + 'border:1px solid black;'
);
```

上面的代码相当于下面的 HTML 代码。

```html
<div style="background-color:red; border:1px solid black;" />
```

`style`不仅可以使用字符串读写，它本身还是一个对象，部署了 CSSStyleDeclaration 接口（详见下面的介绍），可以直接读写个别属性。

```javascript
e.style.fontSize = '18px';
e.style.color = 'black';
```

## CSSStyleDeclaration 接口

### 简介

CSSStyleDeclaration 接口用来操作元素的样式。三个地方部署了这个接口。

- 元素节点的`style`属性（`Element.style`）
- `CSSStyle`实例的`style`属性
- `window.getComputedStyle()`的返回值

CSSStyleDeclaration 接口可以直接读写 CSS 的样式属性，不过，连词号需要变成骆驼拼写法。

```javascript
var divStyle = document.querySelector('div').style;

divStyle.backgroundColor = 'red';
divStyle.border = '1px solid black';
divStyle.width = '100px';
divStyle.height = '100px';
divStyle.fontSize = '10em';

divStyle.backgroundColor // red
divStyle.border // 1px solid black
divStyle.height // 100px
divStyle.width // 100px
```

上面代码中，`style`属性的值是一个 CSSStyleDeclaration 实例。这个对象所包含的属性与 CSS 规则一一对应，但是名字需要改写，比如`background-color`写成`backgroundColor`。改写的规则是将横杠从 CSS 属性名中去除，然后将横杠后的第一个字母大写。如果 CSS 属性名是 JavaScript 保留字，则规则名之前需要加上字符串`css`，比如`float`写成`cssFloat`。

注意，该对象的属性值都是字符串，设置时必须包括单位，但是不含规则结尾的分号。比如，`divStyle.width`不能写为`100`，而要写为`100px`。

另外，`Element.style`返回的只是行内样式，并不是该元素的全部样式。通过样式表设置的样式，或者从父元素继承的样式，无法通过这个属性得到。元素的全部样式要通过`window.getComputedStyle()`得到。

### CSSStyleDeclaration 实例属性

**（1）CSSStyleDeclaration.cssText**

`CSSStyleDeclaration.cssText`属性用来读写当前规则的所有样式声明文本。

```javascript
var divStyle = document.querySelector('div').style;

divStyle.cssText = 'background-color: red;'
  + 'border: 1px solid black;'
  + 'height: 100px;'
  + 'width: 100px;';
```

注意，`cssText`的属性值不用改写 CSS 属性名。

删除一个元素的所有行内样式，最简便的方法就是设置`cssText`为空字符串。

```javascript
divStyle.cssText = '';
```

**（2）CSSStyleDeclaration.length**

`CSSStyleDeclaration.length`属性返回一个整数值，表示当前规则包含多少条样式声明。

```javascript
// HTML 代码如下
// <div id="myDiv"
//   style="height: 1px;width: 100%;background-color: #CA1;"
// ></div>
var myDiv = document.getElementById('myDiv');
var divStyle = myDiv.style;
divStyle.length // 3
```

上面代码中，`myDiv`元素的行内样式共包含 3 条样式规则。

**（3）CSSStyleDeclaration.parentRule**

`CSSStyleDeclaration.parentRule`属性返回当前规则所属的那个样式块（CSSRule 实例）。如果不存在所属的样式块，该属性返回`null`。

该属性只读，且只在使用 CSSRule 接口时有意义。

```javascript
var declaration = document.styleSheets[0].rules[0].style;
declaration.parentRule === document.styleSheets[0].rules[0]
// true
```

### CSSStyleDeclaration 实例方法

**（1）CSSStyleDeclaration.getPropertyPriority()**

`CSSStyleDeclaration.getPropertyPriority`方法接受 CSS 样式的属性名作为参数，返回一个字符串，表示有没有设置`important`优先级。如果有就返回`important`，否则返回空字符串。

```javascript
// HTML 代码为
// <div id="myDiv" style="margin: 10px!important; color: red;"/>
var style = document.getElementById('myDiv').style;
style.margin // "10px"
style.getPropertyPriority('margin') // "important"
style.getPropertyPriority('color') // ""
```

上面代码中，`margin`属性有`important`优先级，`color`属性没有。

**（2）CSSStyleDeclaration.getPropertyValue()**

`CSSStyleDeclaration.getPropertyValue`方法接受 CSS 样式属性名作为参数，返回一个字符串，表示该属性的属性值。

```javascript
// HTML 代码为
// <div id="myDiv" style="margin: 10px!important; color: red;"/>
var style = document.getElementById('myDiv').style;
style.margin // "10px"
style.getPropertyValue("margin") // "10px"
```

**（3）CSSStyleDeclaration.item()**

`CSSStyleDeclaration.item`方法接受一个整数值作为参数，返回该位置的 CSS 属性名。

```javascript
// HTML 代码为
// <div id="myDiv" style="color: red; background-color: white;"/>
var style = document.getElementById('myDiv').style;
style.item(0) // "color"
style.item(1) // "background-color"
```

上面代码中，`0`号位置的 CSS 属性名是`color`，`1`号位置的 CSS 属性名是`background-color`。

如果没有提供参数，这个方法会报错。如果参数值超过实际的属性数目，这个方法返回一个空字符值。

**（4）CSSStyleDeclaration.removeProperty()**

`CSSStyleDeclaration.removeProperty`方法接受一个属性名作为参数，在 CSS 规则里面移除这个属性，返回这个属性原来的值。

```javascript
// HTML 代码为
// <div id="myDiv" style="color: red; background-color: white;">
//   111
// </div>
var style = document.getElementById('myDiv').style;
style.removeProperty('color') // 'red'
// HTML 代码变为
// <div id="myDiv" style="background-color: white;">
```

上面代码中，删除`color`属性以后，字体颜色从红色变成默认颜色。

**（5）CSSStyleDeclaration.setProperty()**

`CSSStyleDeclaration.setProperty`方法用来设置新的 CSS 属性。该方法没有返回值。

该方法可以接受三个参数。

- 第一个参数：属性名，该参数是必需的。
- 第二个参数：属性值，该参数可选。如果省略，则参数值默认为空字符串。
- 第三个参数：优先级，该参数可选。如果设置，唯一的合法值是`important`，表示 CSS 规则里面的`!important`。

```javascript
// HTML 代码为
// <div id="myDiv" style="color: red; background-color: white;">
//   111
// </div>
var style = document.getElementById('myDiv').style;
style.setProperty('border', '1px solid blue');
```

上面代码执行后，`myDiv`元素就会出现蓝色的边框。

## CSS 模块的侦测

CSS 的规格发展太快，新的模块层出不穷。不同浏览器的不同版本，对 CSS 模块的支持情况都不一样。有时候，需要知道当前浏览器是否支持某个模块，这就叫做“CSS 模块的侦测”。

一个比较普遍适用的方法是，判断元素的`style`对象的某个属性值是否为字符串。

```javascript
typeof element.style.animationName === 'string';
typeof element.style.transform === 'string';
```

如果该 CSS 属性确实存在，会返回一个字符串。即使该属性实际上并未设置，也会返回一个空字符串。如果该属性不存在，则会返回`undefined`。

```javascript
document.body.style['maxWidth'] // ""
document.body.style['maximumWidth'] // undefined
```

上面代码说明，这个浏览器支持`max-width`属性，但是不支持`maximum-width`属性。

注意，不管 CSS 属性名的写法带不带连词线，`style`属性上都能反映出该属性是否存在。

```javascript
document.body.style['backgroundColor'] // ""
document.body.style['background-color'] // ""
```

另外，使用的时候，需要把不同浏览器的 CSS 前缀也考虑进去。

```javascript
var content = document.getElementById('content');
typeof content.style['webkitAnimation'] === 'string'
```

这种侦测方法可以写成一个函数。

```javascript
function isPropertySupported(property) {
  if (property in document.body.style) return true;
  var prefixes = ['Moz', 'Webkit', 'O', 'ms', 'Khtml'];
  var prefProperty = property.charAt(0).toUpperCase() + property.substr(1);

  for(var i = 0; i < prefixes.length; i++){
    if((prefixes[i] + prefProperty) in document.body.style) return true;
  }

  return false;
}

isPropertySupported('background-clip')
// true
```

## CSS 对象

浏览器原生提供 CSS 对象，为 JavaScript 操作 CSS 提供一些工具方法。

这个对象目前有两个静态方法。

### CSS.escape()

`CSS.escape`方法用于转义 CSS 选择器里面的特殊字符。

```html
<div id="foo#bar">
```

上面代码中，该元素的`id`属性包含一个`#`号，该字符在 CSS 选择器里面有特殊含义。不能直接写成`document.querySelector('#foo#bar')`，只能写成`document.querySelector('#foo\\#bar')`。这里必须使用双斜杠的原因是，单引号字符串本身会转义一次斜杠。

`CSS.escape`方法就用来转义那些特殊字符。

```javascript
document.querySelector('#' + CSS.escape('foo#bar'))
```

### CSS.supports()

`CSS.supports`方法返回一个布尔值，表示当前环境是否支持某一句 CSS 规则。

它的参数有两种写法，一种是第一个参数是属性名，第二个参数是属性值；另一种是整个参数就是一行完整的 CSS 语句。

```javascript
// 第一种写法
CSS.supports('transform-origin', '5px') // true

// 第二种写法
CSS.supports('display: table-cell') // true
```

注意，第二种写法的参数结尾不能带有分号，否则结果不准确。

```javascript
CSS.supports('display: table-cell;') // false
```

## window.getComputedStyle()

行内样式（inline style）具有最高的优先级，改变行内样式，通常会立即反映出来。但是，网页元素最终的样式是综合各种规则计算出来的。因此，如果想得到元素实际的样式，只读取行内样式是不够的，需要得到浏览器最终计算出来的样式规则。

`window.getComputedStyle`方法，就用来返回浏览器计算后得到的最终规则。它接受一个节点对象作为参数，返回一个 CSSStyleDeclaration  实例，包含了指定节点的最终样式信息。所谓“最终样式信息”，指的是各种 CSS 规则叠加后的结果。

```javascript
var div = document.querySelector('div');
var styleObj = window.getComputedStyle(div);
styleObj.backgroundColor
```

上面代码中，得到的背景色就是`div`元素真正的背景色。

注意，CSSStyleDeclaration 实例是一个活的对象，任何对于样式的修改，会实时反映到这个实例上面。另外，这个实例是只读的。

`getComputedStyle`方法还可以接受第二个参数，表示当前元素的伪元素（比如`:before`、`:after`、`:first-line`、`:first-letter`等）。

```javascript
var result = window.getComputedStyle(div, ':before');
```

下面的例子是如何获取元素的高度。

```javascript
var elem = document.getElementById('elem-container');
var styleObj = window.getComputedStyle(elem, null)
var height = styleObj.height;
// 等同于
var height = styleObj['height'];
var height = styleObj.getPropertyValue('height');
```

上面代码得到的`height`属性，是浏览器最终渲染出来的高度，比其他方法得到的高度更可靠。由于`styleObj`是 CSSStyleDeclaration 实例，所以可以使用各种 CSSStyleDeclaration 的实例属性和方法。

有几点需要注意。

- CSSStyleDeclaration 实例返回的 CSS 值都是绝对单位。比如，长度都是像素单位（返回值包括`px`后缀），颜色是`rgb(#, #, #)`或`rgba(#, #, #, #)`格式。
- CSS 规则的简写形式无效。比如，想读取`margin`属性的值，不能直接读，只能读`marginLeft`、`marginTop`等属性；再比如，`font`属性也是不能直接读的，只能读`font-size`等单个属性。
- 如果读取 CSS 原始的属性名，要用方括号运算符，比如`styleObj['z-index']`；如果读取骆驼拼写法的 CSS 属性名，可以直接读取`styleObj.zIndex`。
- 该方法返回的 CSSStyleDeclaration 实例的`cssText`属性无效，返回`undefined`。

## CSS 伪元素

CSS 伪元素是通过 CSS 向 DOM 添加的元素，主要是通过`:before`和`:after`选择器生成，然后用`content`属性指定伪元素的内容。

下面是一段 HTML 代码。

```html
<div id="test">Test content</div>
```

CSS 添加伪元素`:before`的写法如下。

```css
#test:before {
  content: 'Before ';
  color: #FF0;
}
```

节点元素的`style`对象无法读写伪元素的样式，这时就要用到`window.getComputedStyle()`。JavaScript 获取伪元素，可以使用下面的方法。

```javascript
var test = document.querySelector('#test');

var result = window.getComputedStyle(test, ':before').content;
var color = window.getComputedStyle(test, ':before').color;
```

此外，也可以使用 CSSStyleDeclaration 实例的`getPropertyValue`方法，获取伪元素的属性。

```javascript
var result = window.getComputedStyle(test, ':before')
  .getPropertyValue('content');
var color = window.getComputedStyle(test, ':before')
  .getPropertyValue('color');
```

## StyleSheet 接口

### 概述

`StyleSheet`接口代表网页的一张样式表，包括`<link>`元素加载的样式表和`<style>`元素内嵌的样式表。

`document`对象的`styleSheets`属性，可以返回当前页面的所有`StyleSheet`实例（即所有样式表）。它是一个类似数组的对象。

```javascript
var sheets = document.styleSheets;
var sheet = document.styleSheets[0];
sheet instanceof StyleSheet // true
```

如果是`<style>`元素嵌入的样式表，还有另一种获取`StyleSheet`实例的方法，就是这个节点元素的`sheet`属性。

```javascript
// HTML 代码为 <style id="myStyle"></style>
var myStyleSheet = document.getElementById('myStyle').sheet;
myStyleSheet instanceof StyleSheet // true
```

严格地说，`StyleSheet`接口不仅包括网页样式表，还包括 XML 文档的样式表。所以，它有一个子类`CSSStyleSheet`表示网页的 CSS 样式表。我们在网页里面拿到的样式表实例，实际上是`CSSStyleSheet`的实例。这个子接口继承了`StyleSheet`的所有属性和方法，并且定义了几个自己的属性，下面把这两个接口放在一起介绍。

### 实例属性

`StyleSheet`实例有以下属性。

**（1）StyleSheet.disabled**

`StyleSheet.disabled`返回一个布尔值，表示该样式表是否处于禁用状态。手动设置`disabled`属性为`true`，等同于在`<link>`元素里面，将这张样式表设为`alternate stylesheet`，即该样式表将不会生效。

注意，`disabled`属性只能在 JavaScript 脚本中设置，不能在 HTML 语句中设置。

**（2）Stylesheet.href**

`Stylesheet.href`返回样式表的网址。对于内嵌样式表，该属性返回`null`。该属性只读。

```javascript
document.styleSheets[0].href
```

**（3）StyleSheet.media**

`StyleSheet.media`属性返回一个类似数组的对象（`MediaList`实例），成员是表示适用媒介的字符串。表示当前样式表是用于屏幕（screen），还是用于打印（print）或手持设备（handheld），或各种媒介都适用（all）。该属性只读，默认值是`screen`。

```javascript
document.styleSheets[0].media.mediaText
// "all"
```

`MediaList`实例的`appendMedium`方法，用于增加媒介；`deleteMedium`方法用于删除媒介。

```javascript
document.styleSheets[0].media.appendMedium('handheld');
document.styleSheets[0].media.deleteMedium('print');
```

**（4）StyleSheet.title**

`StyleSheet.title`属性返回样式表的`title`属性。

**（5）StyleSheet.type**

`StyleSheet.type`属性返回样式表的`type`属性，通常是`text/css`。

```javascript
document.styleSheets[0].type  // "text/css"
```

**（6）StyleSheet.parentStyleSheet**

CSS 的`@import`命令允许在样式表中加载其他样式表。`StyleSheet.parentStyleSheet`属性返回包含了当前样式表的那张样式表。如果当前样式表是顶层样式表，则该属性返回`null`。

```javascript
if (stylesheet.parentStyleSheet) {
  sheet = stylesheet.parentStyleSheet;
} else {
  sheet = stylesheet;
}
```

**（7）StyleSheet.ownerNode**

`StyleSheet.ownerNode`属性返回`StyleSheet`对象所在的 DOM 节点，通常是`<link>`或`<style>`。对于那些由其他样式表引用的样式表，该属性为`null`。

```javascript
// HTML 代码为
// <link rel="StyleSheet" href="example.css" type="text/css" />
document.styleSheets[0].ownerNode // [object HTMLLinkElement]
```

**（8）CSSStyleSheet.cssRules**

`CSSStyleSheet.cssRules`属性指向一个类似数组的对象（`CSSRuleList`实例），里面每一个成员就是当前样式表的一条 CSS 规则。使用该规则的`cssText`属性，可以得到 CSS 规则对应的字符串。

```javascript
var sheet = document.querySelector('#styleElement').sheet;

sheet.cssRules[0].cssText
// "body { background-color: red; margin: 20px; }"

sheet.cssRules[1].cssText
// "p { line-height: 1.4em; color: blue; }"
```

每条 CSS 规则还有一个`style`属性，指向一个对象，用来读写具体的 CSS 命令。

```javascript
cssStyleSheet.cssRules[0].style.color = 'red';
cssStyleSheet.cssRules[1].style.color = 'purple';
```

**（9）CSSStyleSheet.ownerRule**

有些样式表是通过`@import`规则输入的，它的`ownerRule`属性会返回一个`CSSRule`实例，代表那行`@import`规则。如果当前样式表不是通过`@import`引入的，`ownerRule`属性返回`null`。

### 实例方法

**（1）CSSStyleSheet.insertRule()**

`CSSStyleSheet.insertRule`方法用于在当前样式表的插入一个新的 CSS 规则。

```javascript
var sheet = document.querySelector('#styleElement').sheet;
sheet.insertRule('#block { color: white }', 0);
sheet.insertRule('p { color: red }', 1);
```

该方法可以接受两个参数，第一个参数是表示 CSS 规则的字符串，这里只能有一条规则，否则会报错。第二个参数是该规则在样式表的插入位置（从 0 开始），该参数可选，默认为 0（即默认插在样式表的头部）。注意，如果插入位置大于现有规则的数目，会报错。

该方法的返回值是新插入规则的位置序号。

注意，浏览器对脚本在样式表里面插入规则有很多[限制](https://drafts.csswg.org/cssom/#insert-a-css-rule)。所以，这个方法最好放在`try...catch`里使用。

**（2）CSSStyleSheet.deleteRule()**

`CSSStyleSheet.deleteRule`方法用来在样式表里面移除一条规则，它的参数是该条规则在`cssRules`对象中的位置。该方法没有返回值。

```javascript
document.styleSheets[0].deleteRule(1);
```

## 实例：添加样式表

网页添加样式表有两种方式。一种是添加一张内置样式表，即在文档中添加一个`<style>`节点。

```javascript
// 写法一
var style = document.createElement('style');
style.setAttribute('media', 'screen');
style.innerHTML = 'body{color:red}';
document.head.appendChild(style);

// 写法二
var style = (function () {
  var style = document.createElement('style');
  document.head.appendChild(style);
  return style;
})();
style.sheet.insertRule('.foo{color:red;}', 0);
```

另一种是添加外部样式表，即在文档中添加一个`<link>`节点，然后将`href`属性指向外部样式表的 URL。

```javascript
var linkElm = document.createElement('link');
linkElm.setAttribute('rel', 'stylesheet');
linkElm.setAttribute('type', 'text/css');
linkElm.setAttribute('href', 'reset-min.css');

document.head.appendChild(linkElm);
```

## CSSRuleList 接口

CSSRuleList 接口是一个类似数组的对象，表示一组 CSS 规则，成员都是 CSSRule 实例。

获取 CSSRuleList 实例，一般是通过`StyleSheet.cssRules`属性。

```javascript
// HTML 代码如下
// <style id="myStyle">
//   h1 { color: red; }
//   p { color: blue; }
// </style>
var myStyleSheet = document.getElementById('myStyle').sheet;
var crl = myStyleSheet.cssRules;
crl instanceof CSSRuleList // true
```

CSSRuleList 实例里面，每一条规则（CSSRule 实例）可以通过`rules.item(index)`或者`rules[index]`拿到。CSS 规则的条数通过`rules.length`拿到。还是用上面的例子。

```javascript
crl[0] instanceof CSSRule // true
crl.length // 2
```

注意，添加规则和删除规则不能在 CSSRuleList 实例操作，而要在它的父元素 StyleSheet 实例上，通过`StyleSheet.insertRule()`和`StyleSheet.deleteRule()`操作。

## CSSRule 接口

### 概述

一条 CSS 规则包括两个部分：CSS 选择器和样式声明。下面就是一条典型的 CSS 规则。

```css
.myClass {
  color: red;
  background-color: yellow;
}
```

JavaScript 通过 CSSRule 接口操作 CSS 规则。一般通过 CSSRuleList 接口（`StyleSheet.cssRules`）获取 CSSRule 实例。

```javascript
// HTML 代码如下
// <style id="myStyle">
//   .myClass {
//     color: red;
//     background-color: yellow;
//   }
// </style>
var myStyleSheet = document.getElementById('myStyle').sheet;
var ruleList = myStyleSheet.cssRules;
var rule = ruleList[0];
rule instanceof CSSRule // true
```

### CSSRule 实例的属性

**（1）CSSRule.cssText**

`CSSRule.cssText`属性返回当前规则的文本，还是使用上面的例子。

```javascript
rule.cssText
// ".myClass { color: red; background-color: yellow; }"
```

如果规则是加载（`@import`）其他样式表，`cssText`属性返回`@import 'url'`。

**（2）CSSRule.parentStyleSheet**

`CSSRule.parentStyleSheet`属性返回当前规则所在的样式表对象（StyleSheet 实例），还是使用上面的例子。

```javascript
rule.parentStyleSheet === myStyleSheet // true
```

**（3）CSSRule.parentRule**

`CSSRule.parentRule`属性返回包含当前规则的父规则，如果不存在父规则（即当前规则是顶层规则），则返回`null`。

父规则最常见的情况是，当前规则包含在`@media`规则代码块之中。

```javascript
// HTML 代码如下
// <style id="myStyle">
//   @supports (display: flex) {
//     @media screen and (min-width: 900px) {
//       article {
//         display: flex;
//       }
//     }
//  }
// </style>
var myStyleSheet = document.getElementById('myStyle').sheet;
var ruleList = myStyleSheet.cssRules;

var rule0 = ruleList[0];
rule0.cssText
// "@supports (display: flex) {
//    @media screen and (min-width: 900px) {
//      article { display: flex; }
//    }
// }"

// 由于这条规则内嵌其他规则，
// 所以它有 cssRules 属性，且该属性是 CSSRuleList 实例
rule0.cssRules instanceof CSSRuleList // true

var rule1 = rule0.cssRules[0];
rule1.cssText
// "@media screen and (min-width: 900px) {
//   article { display: flex; }
// }"

var rule2 = rule1.cssRules[0];
rule2.cssText
// "article { display: flex; }"

rule1.parentRule === rule0 // true
rule2.parentRule === rule1 // true
```

**（4）CSSRule.type**

`CSSRule.type`属性返回一个整数值，表示当前规则的类型。

最常见的类型有以下几种。

- 1：普通样式规则（CSSStyleRule 实例）
- 3：`@import`规则
- 4：`@media`规则（CSSMediaRule 实例）
- 5：`@font-face`规则

### CSSStyleRule 接口

如果一条 CSS 规则是普通的样式规则（不含特殊的 CSS 命令），那么除了 CSSRule 接口，它还部署了 CSSStyleRule 接口。

CSSStyleRule 接口有以下两个属性。

**（1）CSSStyleRule.selectorText**

`CSSStyleRule.selectorText`属性返回当前规则的选择器。

```javascript
var stylesheet = document.styleSheets[0];
stylesheet.cssRules[0].selectorText // ".myClass"
```

注意，这个属性是可写的。

**（2）CSSStyleRule.style**

`CSSStyleRule.style`属性返回一个对象（CSSStyleDeclaration 实例），代表当前规则的样式声明，也就是选择器后面的大括号里面的部分。

```javascript
// HTML 代码为
// <style id="myStyle">
//   p { color: red; }
// </style>
var styleSheet = document.getElementById('myStyle').sheet;
styleSheet.cssRules[0].style instanceof CSSStyleDeclaration
// true
```

CSSStyleDeclaration 实例的`cssText`属性，可以返回所有样式声明，格式为字符串。

```javascript
styleSheet.cssRules[0].style.cssText
// "color: red;"
styleSheet.cssRules[0].selectorText
// "p"
```

### CSSMediaRule 接口

如果一条 CSS 规则是`@media`代码块，那么它除了 CSSRule 接口，还部署了 CSSMediaRule 接口。

该接口主要提供`media`属性和`conditionText`属性。前者返回代表`@media`规则的一个对象（MediaList 实例），后者返回`@media`规则的生效条件。

```javascript
// HTML 代码如下
// <style id="myStyle">
//   @media screen and (min-width: 900px) {
//     article { display: flex; }
//   }
// </style>
var styleSheet = document.getElementById('myStyle').sheet;
styleSheet.cssRules[0] instanceof CSSMediaRule
// true

styleSheet.cssRules[0].media
//  {
//    0: "screen and (min-width: 900px)",
//    appendMedium: function,
//    deleteMedium: function,
//    item: function,
//    length: 1,
//    mediaText: "screen and (min-width: 900px)"
// }

styleSheet.cssRules[0].conditionText
// "screen and (min-width: 900px)"
```

## window.matchMedia()

### 基本用法

`window.matchMedia()`方法用来将 CSS 的[`Media Query`](https://developer.mozilla.org/en-US/docs/DOM/Using_media_queries_from_code)条件语句，转换成一个 MediaQueryList 实例。

```javascript
var mdl = window.matchMedia('(min-width: 400px)');
mdl instanceof MediaQueryList // true
```

上面代码中，变量`mdl`就是 mediaQueryList 的实例。

注意，如果参数不是有效的`MediaQuery`条件语句，`window.matchMedia`不会报错，依然返回一个 MediaQueryList 实例。

```javascript
window.matchMedia('bad string') instanceof MediaQueryList // true
```

### MediaQueryList 接口的实例属性

MediaQueryList 实例有三个属性。

**（1）MediaQueryList.media**

`MediaQueryList.media`属性返回一个字符串，表示对应的 MediaQuery 条件语句。

```javascript
var mql = window.matchMedia('(min-width: 400px)');
mql.media // "(min-width: 400px)"
```

**（2）MediaQueryList.matches**

`MediaQueryList.matches`属性返回一个布尔值，表示当前页面是否符合指定的 MediaQuery 条件语句。

```javascript
if (window.matchMedia('(min-width: 400px)').matches) {
  /* 当前视口不小于 400 像素 */
} else {
  /* 当前视口小于 400 像素 */
}
```

下面的例子根据`mediaQuery`是否匹配当前环境，加载相应的 CSS 样式表。

```javascript
var result = window.matchMedia("(max-width: 700px)");

if (result.matches){
  var linkElm = document.createElement('link');
  linkElm.setAttribute('rel', 'stylesheet');
  linkElm.setAttribute('type', 'text/css');
  linkElm.setAttribute('href', 'small.css');

  document.head.appendChild(linkElm);
}
```

**（3）MediaQueryList.onchange**

如果 MediaQuery 条件语句的适配环境发生变化，会触发`change`事件。`MediaQueryList.onchange`属性用来指定`change`事件的监听函数。该函数的参数是`change`事件对象（MediaQueryListEvent 实例），该对象与 MediaQueryList 实例类似，也有`media`和`matches`属性。

```javascript
var mql = window.matchMedia('(max-width: 600px)');

mql.onchange = function(e) {
  if (e.matches) {
    /* 视口不超过 600 像素 */
  } else {
    /* 视口超过 600 像素 */
  }
}
```

上面代码中，`change`事件发生后，存在两种可能。一种是显示宽度从 600 像素以上变为以下，另一种是从 600 像素以下变为以上，所以在监听函数内部要判断一下当前是哪一种情况。

### MediaQueryList 接口的实例方法

MediaQueryList 实例有两个方法`MediaQueryList.addListener()`和`MediaQueryList.removeListener()`，用来为`change`事件添加或撤销监听函数。

```javascript
var mql = window.matchMedia('(max-width: 600px)');

// 指定监听函数
mql.addListener(mqCallback);

// 撤销监听函数
mql.removeListener(mqCallback);

function mqCallback(e) {
  if (e.matches) {
    /* 视口不超过 600 像素 */
  } else {
    /* 视口超过 600 像素 */
  }
}
```

注意，`MediaQueryList.removeListener()`方法不能撤销`MediaQueryList.onchange`属性指定的监听函数。

## CSS 代码风格

### 2.1 文件


#### 〖建议〗 `CSS` 文件使用无 `BOM` 的 `UTF-8` 编码。

解释：

UTF-8 编码具有更广泛的适应性。BOM 在使用程序或工具处理文件时可能造成不必要的干扰。

### 2.2 缩进


#### 〖强制〗 使用 `4` 个空格做为一个缩进层级，不允许使用 `2` 个空格 或 `tab` 字符。


示例：

```css
.selector {
    margin: 0;
    padding: 0;
}
```

### 2.3 空格


#### 〖强制〗 `选择器` 与 `{` 之间必须包含空格。

示例：

```css
.selector {
}
```

#### 〖强制〗 `属性名` 与之后的 `:` 之间不允许包含空格， `:` 与 `属性值` 之间必须包含空格。

示例：

```css
margin: 0;
```

#### 〖强制〗 `列表型属性值` 书写在单行时，`,` 后必须跟一个空格。

示例：

```css
font-family: Arial, sans-serif;
```

### 2.4 行长度


#### 〖强制〗 每行不得超过 `120` 个字符，除非单行不可分割。

解释：

常见不可分割的场景为 URL 超长。


#### 〖建议〗 对于超长的样式，在样式值的 `空格` 处或 `,` 后换行，建议按逻辑分组。

示例：

```css
/* 不同属性值按逻辑分组 */
background:
    transparent url(aVeryVeryVeryLongUrlIsPlacedHere)
    no-repeat 0 0;

/* 可重复多次的属性，每次重复一行 */
background-image:
    url(aVeryVeryVeryLongUrlIsPlacedHere)
    url(anotherVeryVeryVeryLongUrlIsPlacedHere);

/* 类似函数的属性值可以根据函数调用的缩进进行 */
background-image: -webkit-gradient(
    linear,
    left bottom,
    left top,
    color-stop(0.04, rgb(88,94,124)),
    color-stop(0.52, rgb(115,123,162))
);
```

### 2.5 选择器


#### 〖强制〗 当一个 rule 包含多个 selector 时，每个选择器声明必须独占一行。

示例：

```css
/* good */
.post,
.page,
.comment {
    line-height: 1.5;
}

/* bad */
.post, .page, .comment {
    line-height: 1.5;
}
```

#### 〖强制〗 `>`、`+`、`~` 选择器的两边各保留一个空格。

示例：

```css
/* good */
main > nav {
    padding: 10px;
}

label + input {
    margin-left: 5px;
}

input:checked ~ button {
    background-color: #69C;
}

/* bad */
main>nav {
    padding: 10px;
}

label+input {
    margin-left: 5px;
}

input:checked~button {
    background-color: #69C;
}
```

#### 〖强制〗 属性选择器中的值必须用双引号包围。

解释：

不允许使用单引号，不允许不使用引号。


示例：

```css
/* good */
article[character="juliet"] {
    voice-family: "Vivien Leigh", victoria, female
}

/* bad */
article[character='juliet'] {
    voice-family: "Vivien Leigh", victoria, female
}
```

### 2.6 属性


#### 〖强制〗 属性定义必须另起一行。

示例：

```css
/* good */
.selector {
    margin: 0;
    padding: 0;
}

/* bad */
.selector { margin: 0; padding: 0; }
```

#### 〖强制〗 属性定义后必须以分号结尾。

示例：

```css
/* good */
.selector {
    margin: 0;
}

/* bad */
.selector {
    margin: 0
}
```






## 3 通用




### 3.1 选择器


#### 〖强制〗 如无必要，不得为 `id`、`class` 选择器添加类型选择器进行限定。

解释：

在性能和维护性上，都有一定的影响。


示例：


```css
/* good */
#error,
.danger-message {
    font-color: #c00;
}

/* bad */
dialog#error,
p.danger-message {
    font-color: #c00;
}
```

#### 〖建议〗 选择器的嵌套层级应不大于 3 级，位置靠后的限定条件应尽可能精确。

示例：

```css
/* good */
#username input {}
.comment .avatar {}

/* bad */
.page .header .login #username input {}
.comment div * {}
```



### 3.2 属性缩写



#### 〖建议〗 在可以使用缩写的情况下，尽量使用属性缩写。

示例：

```css
/* good */
.post {
    font: 12px/1.5 arial, sans-serif;
}

/* bad */
.post {
    font-family: arial, sans-serif;
    font-size: 12px;
    line-height: 1.5;
}
```

#### 〖建议〗 使用 `border` / `margin` / `padding` 等缩写时，应注意隐含值对实际数值的影响，确实需要设置多个方向的值时才使用缩写。

解释：

border / margin / padding 等缩写会同时设置多个属性的值，容易覆盖不需要覆盖的设定。如某些方向需要继承其他声明的值，则应该分开设置。


示例：

```css
/* centering <article class="page"> horizontally and highlight featured ones */
article {
    margin: 5px;
    border: 1px solid #999;
}

/* good */
.page {
    margin-right: auto;
    margin-left: auto;
}

.featured {
    border-color: #69c;
}

/* bad */
.page {
    margin: 5px auto; /* introducing redundancy */
}

.featured {
    border: 1px solid #69c; /* introducing redundancy */
}
```


### 3.3 属性书写顺序


#### 〖建议〗 同一 rule set 下的属性在书写时，应按功能进行分组，并以 **Formatting Model（布局方式、位置） > Box Model（尺寸） > Typographic（文本相关） > Visual（视觉效果）** 的顺序书写，以提高代码的可读性。

解释：

- Formatting Model 相关属性包括：`position` / `top` / `right` / `bottom` / `left` / `float` / `display` / `overflow` 等
- Box Model 相关属性包括：`border` / `margin` / `padding` / `width` / `height` 等
- Typographic 相关属性包括：`font` / `line-height` / `text-align` / `word-wrap` 等
- Visual 相关属性包括：`background` / `color` / `transition` / `list-style` 等

另外，如果包含 `content` 属性，应放在最前面。


示例：

```css
.sidebar {
    /* formatting model: positioning schemes / offsets / z-indexes / display / ...  */
    position: absolute;
    top: 50px;
    left: 0;
    overflow-x: hidden;

    /* box model: sizes / margins / paddings / borders / ...  */
    width: 200px;
    padding: 5px;
    border: 1px solid #ddd;

    /* typographic: font / aligns / text styles / ... */
    font-size: 14px;
    line-height: 20px;

    /* visual: colors / shadows / gradients / ... */
    background: #f5f5f5;
    color: #333;
    -webkit-transition: color 1s;
       -moz-transition: color 1s;
            transition: color 1s;
}
```


### 3.4 清除浮动



#### 〖建议〗 当元素需要撑起高度以包含内部的浮动元素时，通过对伪类设置 `clear` 或触发 `BFC` 的方式进行 `clearfix`。尽量不使用增加空标签的方式。

解释：

触发 BFC 的方式很多，常见的有：

* float 非 none
* position 非 static
* overflow 非 visible

如希望使用更小副作用的清除浮动方法，参见 [A new micro clearfix hack](http://nicolasgallagher.com/micro-clearfix-hack/) 一文。

另需注意，对已经触发 BFC 的元素不需要再进行 clearfix。


### 3.5 !important


#### 〖建议〗 尽量不使用 `!important` 声明。


#### 〖建议〗 当需要强制指定样式且不允许任何场景覆盖时，通过标签内联和 `!important` 定义样式。

解释：

必须注意的是，仅在设计上 `确实不允许任何其它场景覆盖样式` 时，才使用内联的 `!important` 样式。通常在第三方环境的应用中使用这种方案。下面的 z-index 章节是其中一个特殊场景的典型样例。



### 3.6 z-index



#### 〖建议〗 将 `z-index` 进行分层，对文档流外绝对定位元素的视觉层级关系进行管理。

解释：

同层的多个元素，如多个由用户输入触发的 Dialog，在该层级内使用相同的 `z-index` 或递增 `z-index`。

建议每层包含 100 个 `z-index` 来容纳足够的元素，如果每层元素较多，可以调整这个数值。


#### 〖建议〗 在可控环境下，期望显示在最上层的元素，`z-index` 指定为 `999999`。

解释：

可控环境分成两种，一种是自身产品线环境；还有一种是可能会被其他产品线引用，但是不会被外部第三方的产品引用。

不建议取值为 `2147483647`。以便于自身产品线被其他产品线引用时，当遇到层级覆盖冲突的情况，留出向上调整的空间。


#### 〖建议〗 在第三方环境下，期望显示在最上层的元素，通过标签内联和 `!important`，将 `z-index` 指定为 `2147483647`。

解释：

第三方环境对于开发者来说完全不可控。在第三方环境下的元素，为了保证元素不被其页面其他样式定义覆盖，需要采用此做法。




## 4 值与单位


### 4.1 文本


#### 〖强制〗 文本内容必须用双引号包围。

解释：

文本类型的内容可能在选择器、属性值等内容中。


示例：

```css
/* good */
html[lang|="zh"] q:before {
    font-family: "Microsoft YaHei", sans-serif;
    content: "“";
}

html[lang|="zh"] q:after {
    font-family: "Microsoft YaHei", sans-serif;
    content: "”";
}

/* bad */
html[lang|=zh] q:before {
    font-family: 'Microsoft YaHei', sans-serif;
    content: '“';
}

html[lang|=zh] q:after {
    font-family: "Microsoft YaHei", sans-serif;
    content: "”";
}
```

### 4.2 数值


#### 〖强制〗 当数值为 0 - 1 之间的小数时，省略整数部分的 `0`。

示例：

```css
/* good */
panel {
    opacity: .8
}
```

opacity

Adjusts the opacity of the selected

element’s presentation on screen.

Takes values between 0.0 (fully

transparent) and 1.0 (fully

opaque)


RGBA Color

Like RGB color definitions, but

allows a fourth field, defining the

alpha value of the color being

applied.



HSL/A Color

HSL color definitions accept three

arguments: hue is a degree on a

color wheel (0-360), saturation

is a percentage, and lightness is a

percentage.

div { color: hsl(240,50%,50%); }

div { color: hsla(240,50%,50%,0.5); }

HSLA is like HSL color, but

allows a fourth field, defining the

alpha value of the color being

applied. See RGBA.











### 4.3 url()


#### 〖强制〗 `url()` 函数中的路径不加引号。

示例：

```css
body {
    background: url(bg.png);
}
```


#### 〖建议〗 `url()` 函数中的绝对路径可省去协议名。


示例：

```css
body {
    background: url(//baidu.com/img/bg.png) no-repeat 0 0;
}
```


### 4.4 长度


#### 〖强制〗 长度为 `0` 时须省略单位。 （也只有长度单位可省）

示例：

```css
/* good */
body {
    padding: 0 5px;
}

/* bad */
body {
    padding: 0px 5px;
}
```


### 4.5 颜色


#### 〖强制〗 RGB 颜色值必须使用十六进制记号形式 `#rrggbb`。不允许使用 `rgb()`。

解释：

带有 alpha 的颜色信息可以使用 `rgba()`。使用 `rgba()` 时每个逗号后必须保留一个空格。


示例：

```css
/* good */
.success {
    box-shadow: 0 0 2px rgba(0, 128, 0, .3);
    border-color: #008000;
}

/* bad */
.success {
    box-shadow: 0 0 2px rgba(0,128,0,.3);
    border-color: rgb(0, 128, 0);
}
```

#### 〖强制〗 颜色值可以缩写时，必须使用缩写形式。

示例：

```css
/* good */
.success {
    background-color: #aca;
}

/* bad */
.success {
    background-color: #aaccaa;
}
```

#### 〖强制〗 颜色值不允许使用命名色值。

示例：

```css
/* good */
.success {
    color: #90ee90;
}

/* bad */
.success {
    color: lightgreen;
}
```

#### 〖建议〗 颜色值中的英文字符采用小写。如不用小写也需要保证同一项目内保持大小写一致。


示例：

```css
/* good */
.success {
    background-color: #aca;
    color: #90ee90;
}

/* good */
.success {
    background-color: #ACA;
    color: #90EE90;
}

/* bad */
.success {
    background-color: #ACA;
    color: #90ee90;
}
```


### 4.6 2D 位置


#### 〖强制〗 必须同时给出水平和垂直方向的位置。

解释：

2D 位置初始值为 `0% 0%`，但在只有一个方向的值时，另一个方向的值会被解析为 center。为避免理解上的困扰，应同时给出两个方向的值。[background-position 属性值的定义](http://www.w3.org/TR/CSS21/colors.html#propdef-background-position)


示例：

```css
/* good */
body {
    background-position: center top; /* 50% 0% */
}

/* bad */
body {
    background-position: top; /* 50% 0% */
}
```





## 5 文本编排


### 5.1 字体族


#### 〖强制〗 `font-family` 属性中的字体族名称应使用字体的英文 `Family Name`，其中如有空格，须放置在引号中。

解释：

所谓英文 Family Name，为字体文件的一个元数据，常见名称如下：

字体 | 操作系统 | Family Name
-----|----------|------------
宋体 （中易宋体） | Windows | SimSun
黑体 （中易黑体） | Windows | SimHei
微软雅黑 | Windows | Microsoft YaHei
微软正黑 | Windows | Microsoft JhengHei
华文黑体 | Mac/iOS | STHeiti
冬青黑体 | Mac/iOS | Hiragino Sans GB
文泉驿正黑 | Linux | WenQuanYi Zen Hei
文泉驿微米黑 | Linux | WenQuanYi Micro Hei


示例：

```css
h1 {
    font-family: "Microsoft YaHei";
}
```


#### 〖强制〗 `font-family` 按「西文字体在前、中文字体在后」、「效果佳 （质量高/更能满足需求） 的字体在前、效果一般的字体在后」的顺序编写，最后必须指定一个通用字体族( `serif` / `sans-serif` )。

解释：

更详细说明可参考[本文](http://www.zhihu.com/question/19911793/answer/13329819)。

示例：

```css
/* Display according to platform */
.article {
    font-family: Arial, sans-serif;
}

/* Specific for most platforms */
h1 {
    font-family: "Helvetica Neue", Arial, "Hiragino Sans GB", "WenQuanYi Micro Hei", "Microsoft YaHei", sans-serif;
}
```

#### 〖强制〗 `font-family` 不区分大小写，但在同一个项目中，同样的 `Family Name` 大小写必须统一。

示例：

```css
/* good */
body {
    font-family: Arial, sans-serif;
}

h1 {
    font-family: Arial, "Microsoft YaHei", sans-serif;
}

/* bad */
body {
    font-family: arial, sans-serif;
}

h1 {
    font-family: Arial, "Microsoft YaHei", sans-serif;
}
```

### 5.2 字号


#### 〖强制〗 需要在 Windows 平台显示的中文内容，其字号应不小于 `12px`。

解释：

由于 Windows 的字体渲染机制，小于 12px 的文字显示效果极差、难以辨认。


### 5.3 字体风格


#### 〖建议〗 需要在 Windows 平台显示的中文内容，不要使用除 `normal` 外的 `font-style`。其他平台也应慎用。

解释：

由于中文字体没有 italic 风格的实现，所有浏览器下都会 fallback 到 obilique 实现 （自动拟合为斜体），小字号下 （特别是 Windows 下会在小字号下使用点阵字体的情况下） 显示效果差，造成阅读困难。


### 5.4 字重


#### 〖强制〗 `font-weight` 属性必须使用数值方式描述。

解释：

CSS 的字重分 100 – 900 共九档，但目前受字体本身质量和浏览器的限制，实际上支持 400 和 700 两档，分别等价于关键词 normal 和 bold。

浏览器本身使用一系列[启发式规则](http://www.w3.org/TR/CSS21/fonts.html#propdef-font-weight)来进行匹配，在 <700 时一般匹配字体的 Regular 字重，>=700 时匹配 Bold 字重。

但已有浏览器开始支持 =600 时匹配 Semibold 字重 （见[此表](http://justineo.github.io/slideshows/font/#/3/15))，故使用数值描述增加了灵活性，也更简短。

示例：

```css
/* good */
h1 {
    font-weight: 700;
}

/* bad */
h1 {
    font-weight: bold;
}
```

### 5.5 行高


#### 〖建议〗 `line-height` 在定义文本段落时，应使用数值。

解释：

将 line-height 设置为数值，浏览器会基于当前元素设置的 font-size 进行再次计算。在不同字号的文本段落组合中，能达到较为舒适的行间间隔效果，避免在每个设置了 font-size 都需要设置 line-height。

当 line-height 用于控制垂直居中时，还是应该设置成与容器高度一致。


示例：

```css
.container {
    line-height: 1.5;
}
```



## 6 变换与动画



#### 〖强制〗 使用 `transition` 时应指定 `transition-property`。

示例：

```css
/* good */
.box {
    transition: color 1s, border-color 1s;
}

/* bad */
.box {
    transition: all 1s;
}
```

#### 〖建议〗 尽可能在浏览器能高效实现的属性上添加过渡和动画。

解释：

见[本文](http://www.html5rocks.com/en/tutorials/speed/high-performance-animations/)，在可能的情况下应选择这样四种变换：

* `transform: translate(npx, npx);`
* `transform: scale(n);`
* `transform: rotate(ndeg);`
* `opacity: 0..1;`

典型的，可以使用 translate 来代替 left 作为动画属性。

示例：

```css
/* good */
.box {
    transition: transform 1s;
}
.box:hover {
    transform: translate(20px); /* move right for 20px */
}

/* bad */
.box {
    left: 0;
    transition: left 1s;
}
.box:hover {
    left: 20px; /* move right for 20px */
}
```




## 7 响应式



#### 〖强制〗 `Media Query` 不得单独编排，必须与相关的规则一起定义。

示例：

```css
/* Good */
/* header styles */
@media (...) {
    /* header styles */
}

/* main styles */
@media (...) {
    /* main styles */
}

/* footer styles */
@media (...) {
    /* footer styles */
}


/* Bad */
/* header styles */
/* main styles */
/* footer styles */

@media (...) {
    /* header styles */
    /* main styles */
    /* footer styles */
}
```

#### 〖强制〗 `Media Query` 如果有多个逗号分隔的条件时，应将每个条件放在单独一行中。

示例：

```css
@media
(-webkit-min-device-pixel-ratio: 2), /* Webkit-based browsers */
(min--moz-device-pixel-ratio: 2),    /* Older Firefox browsers (prior to Firefox 16) */
(min-resolution: 2dppx),             /* The standard way */
(min-resolution: 192dpi) {           /* dppx fallback */
    /* Retina-specific stuff here */
}
```

#### 〖建议〗 尽可能给出在高分辨率设备 (Retina) 下效果更佳的样式。



## 8 兼容性


### 8.1 属性前缀


#### 〖强制〗 带私有前缀的属性由长到短排列，按冒号位置对齐。

解释：

标准属性放在最后，按冒号对齐方便阅读，也便于在编辑器内进行多行编辑。


示例：

```css
.box {
    -webkit-box-sizing: border-box;
       -moz-box-sizing: border-box;
            box-sizing: border-box;
}
```


### 8.2 Hack


#### 〖建议〗 需要添加 `hack` 时应尽可能考虑是否可以采用其他方式解决。

解释：

如果能通过合理的 HTML 结构或使用其他的 CSS 定义达到理想的样式，则不应该使用 hack 手段解决问题。通常 hack 会导致维护成本的增加。

#### 〖建议〗 尽量使用 `选择器 hack` 处理兼容性，而非 `属性 hack`。

解释：

尽量使用符合 CSS 语法的 selector hack，可以避免一些第三方库无法识别 hack 语法的问题。


示例：

```css
/* IE 7 */
*:first-child + html #header {
    margin-top: 3px;
    padding: 5px;
}

/* IE 6 */
* html #header {
    margin-top: 5px;
    padding: 4px;
}
```


#### 〖建议〗 尽量使用简单的 `属性 hack`。

示例：

```css
.box {
    _display: inline; /* fix double margin */
    float: left;
    margin-left: 20px;
}

.container {
    overflow: hidden;
    *zoom: 1; /* triggering hasLayout */
}
```

### 8.3 Expression


#### 〖强制〗 禁止使用 `Expression`。



text-overflow

If text overflows the available

space, the text-overflow property

defines what happens.

The value “ellipsis” appends an

ellipsis character at the overflow

point.

## @font-face

@font-face

Allows a font file to be associated

with a font name for later use in

font-family declarations.

IE supports only .eot Embedded

OpenType files, while the other

browsers support any TTF and

OTF font files.


@font-face {

font-family: Helvy;

src: local("Helvetica Neue Bold"),

local("HelveticaNeue-Bold"),

url(MgOpenModernaBold.ttf);

font-weight: bold;

}

p.specialFont { font-family: Helvy, sans-serif; }


# References

- https://developer.mozilla.org/en-US/docs/Web/Demos
