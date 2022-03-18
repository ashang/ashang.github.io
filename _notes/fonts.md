---
title: Fonts
date: 2014-12-07
---

# Font notes

## Coding font preferences

- InconsolataDz
- AnonymousPro
- FiraCode
- Cascadia-code                            2102.03-1                           all          monospaced font designed to enhance appearance of Windows Terminal

## Using system fonts

[previous post]: /2018/05/extramaze-llc-using-racket-postgresql-aws-but-no-ads-or-js.html
[deals.extramaze.com]: https://deals.extramaze.com

Google-hosted fonts might not be the best idea:

[privacy]: /2018/05/extramaze-llc-using-racket-postgresql-aws-but-no-ads-or-js.html#trying-to-do-the-right-thing-privacy

[Josh Bronson]: https://twitter.com/jab_______

[Recurse Center's]: https://www.recurse.com/

[Zulip]: https://zulipchat.com

- Privacy: Using `fonts.googleapis.com` tells Google what sites the
  user is visiting. It doesn't make much sense to avoid Google
  Analytics but keep using Google Fonts.

- Performance: Downloading custom fonts takes time. This can be
  especially annoying on slower mobile connections.

Often these are two sides of the same coin: Leaking information to a
third party usually consumes extra time and bandwidth to make extra
connections and transfer data.

Instead host the font files locally? That would address privacy. But
it could make performance worse not better. Using fonts hosted by
Google _does_ have the advantage that the user might already have
downloaded them, as a result of some other web site using them.

Josh asked if I'd considered using system fonts, and shared
[two](https://furbo.org/2018/03/28/system-fonts-in-css/)
[links](http://markdotto.com/2018/02/07/github-system-fonts/).
Initially I was reluctant -- but but but... my carefully chosen fonts!
And yes, it changed the look and feel of the site, somewhat. But after
living with it for about half an hour, I thought it was just fine.

# Accessibility

At the same time I was looking at fonts, I'd been starting to review
accessibility issues. Such as making sure that:

- `img` elements have `alt` attributes
- `svg` elements have child `title` elements
- the `html` element has a `lang=en` attribute
- all `id` attributes on a page are unique

Another item on this list: Ensuring that font colors have sufficient
contrast. So I did that while I had the hood open.

(I have more work to do for accessibility: I've only just started to
use the site with the macOS screen reader. Maybe this should be
another blog post.)

# Content Security Policy

Dropping Google hosted fonts let me simplify the content security
policy. Indeed it seems to have cut down on the number of violation
reports.

Since my last blog post, I had temporarily switched from
`Content-Security-Policy` to `Content-Security-Policy-Report-Only`. I
was nervous because I didn't understand all the violations.
[report-uri.com] helps by filtering things like violations caused by
browser extensions. But even after such filtering, I had violations
that made no sense to me.

[report-uri.com]: https://report-uri.com

Using system fonts, that situation improved significantly. I feel good
about cranking it back up again to be enforced instead of
report-only.[^footnote-about-using-both]

[^footnote-about-using-both]: Of course you can use both headers. `Content-Security-Policy` is what you're enforcing, and `Content-Security-Policy-Report-Only` can be used to dry-run changes.

I suppose this illustrates a concern using any third-party service.
Effectively it mutates your web site with various scripts or fonts or
styles. What are all its mutations? You may think you know from
observation: Oh it needs a script from a certain URI. But oops, in a
certain scenario it turns out that it also needs a style from another
URI. Surprise. And that's just today. What if the service changes in
the future?

Really, every service ought to state exactly what content security
policy settings it needs to work.
* lang, charset 和 font-family 都会对默认字体产生影响，规律很复杂。
* 浏览器偏好里的字体设置，对默认字体有直接影响，比如 WebKit 内核的 Chrome 浏览器。
* 宋体转成 “\5b8b\4f53” 也不能通吃所有浏览器。比如在 Mac OS 的 Chrome 中，只认识 simsun.
* <del>宋体其实是 serif 有衬线字体，后面跟 sans-serif, 逻辑上是错的。</del>
  （修正：并没有规定前面的 font name 要和最后的 general family 保持一致）
* 不同操作系统下，各个浏览器默认的 sans-serif 中文字体，一般都是最佳选择或用户已调整为最佳，不能强制用户都用宋体。

在以 12px+ 大小为主的网页设计中，**最佳的中文默认字体方案是雅黑等无衬线字体**。

* 在 Mac Chrome 等环境下，用 font-family: times, sans-serif 时，
  中文字体并不会根据 sans-serif 渲染，而是会根据 times 的 serif 属性，
  选择默认的 serif 中文字体来渲染。
  比如在 Mac Chrome 下，默认 serif 中文字体是很接近宋体的一个字体，比较难看。
* 在 Firefox 中，只要 font-family 中有宋体，中文必然就用宋体展现。
  所以 font-family 中不能有宋体。
* 当 lang=“zh-CN”, charset=“utf-8” 时，
  font: arial 在 Mac Firefox 等环境下，默认中文字体是宋体。
* 在英文 Win7 下，只要 charset=“gbk”, 当 font-family 为 arial, sans-serif 时，
  <del>默认中文字体是很难看的 Microsoft Sans Serif Regular.</del>
  （修正：是 fallback 到了韩文字体 Dotum/Gulim（gulim.ttc）来显示，
  Dotum/Gulim 没有的字符最终会 fallback 到 SimSun，暂时不知道日文字体是否夹在中间。
  和 Microsoft Sans Serif 没有一点关系。）

可以总结出：

1. 如果页面 charset 是 utf-8, 完美的默认字体方案是：

```css
font-family: arial, sans-serif;
```

无论省略 lang 还是设置为 zh-CN, 在各种环境下都满足预期。

2. 如果页面 charset 是 gbk, 推荐默认字体方案为：

```css
font-family: arial;
```

最后，个人推荐简体中文页面的最佳实践为：

```html
html lang=zh-CN
charset=utf-8
font-family: arial, sans-serif;
```

1. 关于字体的默认大小和行高等信息，推荐博文：[默认 Web 字体样式][1]
2. 关于字体的 fallback 等文本渲染信息，推荐博文：[浏览器如何渲染文本][2]

[1]: http://justjavac.com/web/2012/04/13/default-web-font-style.html
[2]: http://justjavac.com/web/2012/04/13/how-do-browsers-render-text.html

## Punction symbols

符号`′` 是 prime，比single quote sign ’好看，但是不如 '  apostrophe 符号，因为prime符号过于远离字母，比较：

```shell
r′r     prime
r’r     single quote
r'r     apostrophe
```

双的。

符号″ (double prime 双撇号,英寸，秒等单位)不如 two apostrophe '' 好看，符号” double right quote （即半角双引号，非中文全角双引号”），也存在符号距离字母较远问题。例如：

```shell
r″r     double prime
r”r     double right quote
r''r    two apostrophe
```

## Current practice

- 一个引号用一个apostrophe，双撇号用two apostrophes
- 用prime和double prime，这样符号和含义一致了。

# Recursive Mono & Sans, by Arrow Type

Recursive is a typographic palette for code & UI. It includes sans-serif & mono fonts designed specifically for use in interactive applications and code editors. See https://recursive.design for more information.

Recursive is an open-source project. Follow along and contribute at https://github.com/arrowtype/recursive. It is licensed under the OFL, so (in summary) you are free to make derivative versions, but these must also adopt the same OFL license (e.g. you cannot sell proprietary licenses for derivative fonts). See `LICENSE.txt` for full details.

Do you have a question or have you found a bug? Please file an issue at https://github.com/arrowtype/recursive/issues. Thanks!

## Recommendations

For design & usage recommendations, please see the project README at https://github.com/arrowtype/recursive.

Fonts in `Recursive_Desktop` and `Recursive_Code` are made so that it is possible to install all of these without experiencing conflicts in font menus. However, you may want to pick-and-choose which font files you wish to install, based on your needs.

### General Desktop use (Word, PowerPoint, Keynote, InDesign, Illustrator, PhotoShop, Figma, etc)

- On Windows, install `Recursive_Desktop/recursive-statics.ttc` (This is a collection of all 64 static instances in TTF format)
- On Mac, install `Recursive_Desktop/recursive-statics.otc` (This is a collection of all 64 static instances in OTF format)

### Desktop web design (Sketch) & experimental use in Adobe apps

- Install `Recursive_Desktop/Recursive_VF_1.0XX.ttf` (this is the full Recursive variable font)
- It may also be beneficial to install static fonts, as OS & app support of variable fonts is still growing

### Code (code editors such as VS Code, Atom, Sublime, etc etc)

- Install fonts in `Recursive_Code` (These are specifically simplified families for use in code editors. See README in that directory for further advice)

### Web

- Use the woff2 font files in `Recursive_Web`. This includes a few useful subsets for variable fonts, along with some starter `@font-face` CSS for the `woff2_variable_subsets`.
- If you only need a style or two on a site, it may be practical to just use static instances, but you may want to figure out subsetting with `pyftsubset` to make those even smaller.

字体类型
现今计算机使用的绝大多数字体，都是属于点阵字体或者轮廓字体二者之一。

点阵字体
每种字形的每种形式和每种尺寸的图像都由点或者像素组成的矩阵构成。由于位图的原故，点阵字体很难进行缩放，特定的点阵字体只能清晰地显示在相应的字号下。但对于 12-16 px 的小号汉字来说，点阵字体往往比其它类型的字体在屏幕上有更好的显示效果。
轮廓字体或称矢量字体
使用贝塞尔曲线、绘图指令和数学公式来描述每种字形，使得字体可以适应各种尺寸。
点阵格式
Bitmap Distribution Format (BDF) - 来自 Adobe
Portable Compiled Format (PCF) - 来自 Xorg
PC Screen Font (PSF) 内核终端字体，Xorg 不支持此格式 (Unicode PSF 文件的扩展是 psfu)
此格式可以通过 gzip 压缩。

轮廓格式
PostScript 字体 - 来自，包含打印机 ASCII 字体 (PFA) 和打印机二进制字体 (PFB)
TrueType - Apple 和 Microsoft 定义(ttf)
OpenType - 基于 TrueType，Microsoft 定义(otf, ttf)
大部分情况下，TrueType 和 OpenType 之间的差异可以忽略.

其它格式
排版程序 TeX 和配套的字体软件 Metafont 用它们自己的方法渲染字体。部分用于这两个程序的字体的文件后缀有 *pk, *gf, mf 与 vf。新的版本现在也支持 TrueType 和 OpenType.

FontForge (fontforge)是字体编辑程序，可以用自己的格式来储存字体，例如 sfd （spline font database）。

SVG 格式也有自己的字体描述方法。

## 中英文字体差别真大！

下面的符号，在中文中变形厉害，非常宽。


几个符号
单的。

符号′ 是 prime，比single quote sign ’好看，但是不如 '  apostrophe 符号，因为prime符号过于远离字母，比较：
r′r		prime
r’r		single quote
r'r		apostrophe

双的。

符号″ (double prime 双撇号,英寸，秒等单位)不如 two apostrophe '' 好看，符号” double right quote （即半角双引号，非中文全角双引号”），也存在符号距离字母较远问题。例如：
r″r		double prime
r”r		double right quote
r''r		two apostrophe

建议，一个引号用一个apostrophe，双撇号用two apostrophes
或者，用prime和double prime，这样符号和含义一致了。

```shell
fc-list -f '%{family}\n' | awk '!x[$0]++'
```

fc-list :lang="双字母的语言代码" 枚举系统安装了哪些可对应该语言的字体

```
fc-list : file
fc-match serif
fc-match sans
fc-match mono
fc-match monospace
fc-list -f '%{file}\n' :lang=ar
fc-list -f '%{file}\n' :lang=cn
fc-list -f '%{file}\n' :lang=zh
fc-list -f '%{file}\n' :lang=tw
fc-list -f '%{file}\n' :lang=jp
fc-list -f '%{file}\n' :lang=hk
fc-list -f '%{file}\n' :lang=ja
```

## fc-match

```shell
fc-match
```

```shell
$ fc-match monospace
inconsolata.woff2: "Inconsolata" "Regular"
```

## X11中的字体选择顺序

Fontconfig 会自动选择一个满足当前显示需求的字体。如果浏览一个既有英文又有中文的窗口，而默认的字体不支持中文，它会自动用另外的字体显示中文。通过$XDG_CONFIG_HOME/fontconfig/fonts.conf 可以调整字体的选择顺序。

如果要优先使用 Serif 字体，遇到显示不了的字再使用某个特定的中文字体，配置文件会是这样：

```xml
<?xml version="1.0"?>
<!DOCTYPE fontconfig SYSTEM "fonts.dtd">
<fontconfig>
<alias>
   <family>serif</family>
   <prefer>
     <family>你喜欢的拉丁衬线字体名称</family>
     <family>你的中文衬线字体名称</family>
   </prefer>
 </alias>
</fontconfig>
```

如果系统的 Locale 是中文，请将 LC_LANG 设置为 und，否则中英文文字都会使用中文字体渲染。

修改字体配置后可以用 fc-match -a monospace | head 检查字体选择设置是否正确.

## Noto CJK

In font filenames, JP, KR, SC, TC represent Japanese, Korean, Simplified Chinese and Traditional Chinese respectively.

Noto CJK comprehensively cover Simplified Chinese, Traditional Chinese, Japanese, and Korean in a unified font family. This includes the full coverage of CJK Ideographs with variation support for 4 regions, Kangxi radicals, Japanese Kana, Korean Hangul, and other CJK symbols and letters in the Basic Multilingual Plane of Unicode. It also provides limited coverage of CJK Ideographs in Plane 2 of Unicode as necessary to support standards from China and Japan.
- Simplified Chinese
Supports GB 18030 and China’s latest standard Table of General Chinese Characters (通用规范汉字表) published in 2013.
- Traditional Chinese
Supports BIG5. Traditional Chinese glyphs comply with the glyph standard of the Taiwan Ministry of Education (教育部國字標準字體).
- Japanese
Supports all of the kanji in JIS X 0208, JIS X 0213, and JIS X 0212 to include all kanji in Adobe-Japan1-6.
- Korean

The best font for typesetting classic Korean documents in Hangul and Hanja such as Humninjeongeum manuscript, a UNESCO World Heritage.

Supports over 1.5 million archaic Hangul syllables and 11,172 modern syllables as well as all CJK ideographs in KS X 1001 and KS X 1002.

Both Noto Sans CJK and Noto Serif CJK are offered in 7 weights and include 65,535 glyphs (the maximum number of glyphs that can be included in a single font).

## Emoji
- NotoColorEmoji.ttf

# Font conf

## Fontconfig
Fontconfig is a font configuration and customization library, which
 does not depend on the X Window System. It is designed to locate
 fonts within the system and select them according to requirements
 specified by applications.

Fontconfig is not a rasterization library, nor does it impose a
 particular rasterization library on the application. The X-specific
 library 'Xft' uses fontconfig along with freetype to specify and
 rasterize fonts.

Fontconfig contains a program to maintain the fontconfig cache
 (fc-cache), a sample program to list installed fonts (fc-list), a program
 to test the matching rules (fc-match) and a program to dump the binary
 cache files in string form (fc-cat). It no longer makes fonts managed by defoma
 available to fontconfig applications.

## Weights

- ExtraLight
- Light
- Regular
- Medium
- SemiBold
- Bold
- Black

## Reference font weights from FIRA SANS

- Two       (2 units / CSS 100)
- Four      (4 units / CSS 100)
- Six       (6 units / CSS 100)
- Eight     (8 units / CSS 100)
- Hair      (14 units / CSS 100)
- Thin      (22 units / CSS 100)
- UltraLight  (34 units / CSS 200)
- ExtraLight  (46 units / CSS 250)
- Light     (58 units / CSS 300)
- Book      (84 units / CSS 350)
- Regular     (92 units / CSS 400)
- Medium    (128 units / CSS 500)
- SemiBold    (142 units / CSS 600)
- Bold      (158 units / CSS 700)
- ExtraBold   (178 units / CSS 800)
- Heavy     (198 units / CSS 900)

**Note on thin weight fractional coordinates**

All weights below `Thin` use fractional coordinates which is an optical decision. Rendering engines might not be able to deal with that correctly. As for that, these weights should be seen as an experiment by now. If you notice any problems in smaller sizes please consider to use weights from Thin.

## Font weights

* Regular     (84em / CSS 400)
* Medium    (112em / CSS 500)
* Bold      (158em / CSS 700)

## 测试文本

- 視野無限廣，窗外有藍天 （Win98）
- 興國安邦，巨擘八方！ （WinXP）
- 微風迎客，軟語伴茶 （Vista、Win7、Win10）
- 다람쥐 헌 쳇바퀴에 타고파. 1234567890
- 가 지원하는 한글 글꼴 1234567890
- でコンピュータの世界が広がります。 1234567890
- 我能吞下玻璃而不伤身体。
- 我能吞下玻璃而不傷身體
- Grumpy wizards make toxic brew for the evil Queen and Jack.
- The quick brown fox jumps over the lazy dog.
- 東方文字傳情之美
- 渺渺茫茫墨泼天，飘飘拂拂雨如烟。
- 知其白，守其黑，為天下式。
- 常計白以當黑，奇趣乃出。
- 春の日の夕暮は静かです
- 별을 노래하는 마음으로 모든 죽어가는 것을
- 源源不絕，栩栩如生。
- https://kermitproject.org/utf8.html

## OpenType

## OpenType Collection (OTC)

OpenType，是一種可縮放字型（scalable font）電腦字体类型，採用PostScript格式，是美國微軟公司與Adobe公司聯合开发，用来替代TrueType字型的新字型。这类字体的文件扩展名有.otf、.ttf、.ttc，类型代码是OTTO

OpenType类型字体中，可以选择PostScript或TrueType作为记述方式。

OpenType最初发表于1996年，并在2000年之后出现大量字体。它源於微軟公司的TrueType Open字型，TrueType Open字型又源於TrueType字型。OpenType font包括了Adobe CID-Keyed font技術。Adobe公司已经在2002年末将其字体库全部改用OpenType格式。到2005年大概有一万多种OpenType字体，Adobe产品占了三分之一。

OpenType使用TrueType字体通用的sfnt架构，但其加入若干“智能字体”（smartfont）选项，可以加强字体的字形和语言支持能力。OpenType字体中的字形（glyph）、轮廓数据可以在两种格式中任选其一：一个是在'glyf'表中TrueType格式轮廓，另一个是在'CFF '表中的CFF（压缩字体格式，Compact Font Format）格式轮廓。CFF轮廓数据是基于PostScript语言Type 2字体格式。表格名'CFF '长度为四个字符，并且以一个空格字符结尾。

在如版式等大多数情况下，轮廓数据格式是什么类型并不重要，但这两种格式的区别在图元光栅化（rasterisation）的时候就有区别。而单从「OpenType」一词中看不出来使用的是哪种数据格式，所以有时候使用OpenType (PostScript flavor)、OpenType CFF、或者OpenType (TrueType flavor)等称呼加以区别。

OpenType的主要特征有：

字体编码基于万国码（Unicode），可以支持任何文本，或者同时支持多种文本。
一个OpenType字体可以带有最多65,536个字形。对于中文字库而言，最基本的字汇应该包含Big5的13,060個漢字或是GB2312-80标准的6763个常用字型，这些字应该能满足一般用户的使用，对于户籍管理、银行系统和出版社等用户而言需要2万多字甚至7万多字的支持。
字体有高级字形功能，可以进行对复杂文本进行充分的字形处理，并能通过更简单的文字施加更复杂的字形效果，比如用罗马字母脚本书写英文。
字体文件可以拓展到跨平台，能够在Mac OS，Windows和一些Unix系统中进行设置。
若不含变体字等拓展字形和拓展文字性能，OpenType CFF字体比Type 1要小
与其他类型比较
與苹果公司的Apple Advanced Typography（简称AAT，旧名GX Typography）比较，OpenType在字形选项上更不灵活，但是在语言相关的选项和支持略胜一筹。OpenType比AAT更为成功，它现在有大量的字体和支持的应用程序，使AAT成为过时的技术。AAT的单平台性能使其缺乏苹果以外的大厂商的支持。

从开发者的角度来说，在一般情况下OpenType比AAT更容易开发。首先，简单声明替换和OpenType的定位比AAT的状态表更简单易懂。其次，Adobe的认证策略不需要改变源代码，运行第三方字体编辑应用程序，如FontLab、FontMaster去添加有关性能支持。虽然Adobe的文本驱动代码支持不如微软的单独开发工具更为直观，但是它的VOLT（视觉开放字体版式工具，Visual OpenType Layout Tool），一个制作字体的工具集成软件还是比较受欢迎的。

另一个区别是，OpenType支持framework（如微软的Uniscribe），若要处理阿拉伯语等语言的时候只需要提供一些特殊的语言处理知识。而在AAT中，ATT字体开发者需要对该语言字体的全面认识。这意味着AAT可以处理任何特殊语言，但是需要字体开发者的相当高度的语言知识。另外，OpenType字体更容易制作，但只能支持应用程序和操作系统能够识别的复杂文字。 在支持OpenType之前，Adobe针对高级文字处理中曾推出“multiple master fonts”，但其缺乏OpenType的异体字和语言控制，在字体形状上有更多的控制参数。

OpenType支持
OpenType支持有以下几个方面：所有应用程序和多数操作系统能在使用旧字体的同时使用OpenType字体；特别要注意的是，万国码的拓展语言支持；支持阿拉伯语、印度语言等“复杂文本”；以及英语等拉丁文本的高级字形支持等。

在微软的操作系统中，OpenType TT字体（.TTF）能向后兼容，因此其支持所有Windows系統。OpenType PS字体（.OTF）支持Windows 2000或以後的版本。在Windows 95／98／NT／Me系统中需要安装Adobe Type Manager才能使用基本的罗马字符支持。

通过万国码（Unicode）的拓展语言，可以在大多数的视窗应用程序中同时对OpenType和TrueType支持，包括Publisher，大多数的Adobe应用程序，微软Office 2003（但Word 2002不行），以及多数的Mac OS应用程序，包括苹果自己开发的TextEdit和Keynote。在Mac OS X中，通过文字处理Mellel，OpenType得到了全面支持。

OpenType通过微软的Office和Publisher等软件支持复杂书写文本，Adobe InDesign也提供日文的拓展OpenType功能，但是不直接支持中东和印度文本——Adobe为支持阿拉伯语、希伯来语等中东语言，单独发行另外的InDesign版本。

拉丁语言文本的高级字形支持主要是通过Adobe的应用程序，如Adobe InDesign、Adobe Photoshop和Adobe Illustrator来支持。QuarkXPress 6.5及其以下版本不支持万国码，因此含有WinANSI/MacRoman字符表外的文字在OpenType字体中将无法正常显示（同理，在其他使用万国码的字体格式也不行）。Corel公司的CorelDRAW不支持OpenType字形功能。尽管如此，Quark公司在2006年5月发布的QuarkXPress 7中开始支持OpenType，和Adobe程序达到类似的效果。

另外，Windows Presentation Foundation管理代码执行支持OpenType CFF字体和一些高级字形功能，如连写、旧体数字、花体字形、拐点、超文本和次文本，小型大写字母、字形替换、多重基线、前后／风格化字间距调整、行间调整、注释字符等等。

Mac OS X v10.4及其之后系统中的Apple Advanced Typography也支持OpenType拉丁文本语言的高级字形功能，如小型大写字母，旧体数字和多种连写。但是它不支持前后字母间距调整、定位格式、字形倒序等，因此Mac OS X v10.4不能通过OpenType支持阿拉伯语、印度的文字——这些文本通过苹果自己的AAT字体来支持。

在自由软件环境，如Linux中，OpenType支持是通过FreeType项目来支持的

\

SING外字解决方案
2005年Adobe在其创意软件套装Adobe Creative Suite中发表了一个新的技术“外字”（Gaiji）解决方案。

所谓“外字”，源自日语的“表外汉字”（日语：表外漢字，hyōgai kanji）。与拉丁语言不同，在东亚表意文字系统如中文、日文中，没有固定数量的字符集。一般字符集只含有8,000到15,000的常用字，另外数万个非常用字、生僻字，往往没有在各国的标准中给予编码。另外一个情况是异体字：一个表意文字（汉字）在不同的历史时期、地域产生了不同的字形，而一些地名人名等专有名字必须要使用传统的写法，需要使用这些冷僻字形，造成了生僻字问题，日语中称为“外字”问题。

为了处理这些冷僻字，先前已经出现过很多方案，比如在万国码中的私用区域（Private use area）增加编码等。这样的处理方法无法在制定环境以外的地方使用，基于私用区域编码的万国码制作的文档无法通用。另外一个办法就是将其处理成图像，这又导致文字排版的麻烦，因为版面指令无法作用于图像，无法被当成文本搜索，而且由于机器从字体描绘字形和描绘图像的机制完全不同，这样的处理导致插入的冷僻字看起来很突兀。

SING技术是和Adobe Creative Suite 2一起发布的，它允许用户创建新字形，每个新字形作为一个独立的字体打包。这样打包出来的字形称为字形包（glyphlet）。这种格式通过Adobe公开的，且基于OpenType。这个包的内容包括字形的TrueType或CFF轮廓样式，标准OpenType表格，声明字形的尺寸和组合行为，以及元数据，附加信息，如字形包的认证、所属，还有读音或者部首分类等语言方面的分类等。SING字形包也可以使用Fontlab公司的SigMaker3程序创建。

SING（Smart INdependent Glyphlets，智能独立字形包）的规范允许字形包随同文件一起传送，这样包含SING字符的文件也是可携带的，而又不会字符乱码、异常显示。由于字形包的基础是OpenType字体，标准字体机制可以对其进行正常描画。SING规范也可以表述成XML格式，包括在二进制格式中重建字形的所有必要数据。一般情况下，一个字形包需要1-2 kB大小的容量。

## WOFF本质上是包含了基于SFNT的字体（如TrueType、OpenType或其他开放字体格式），且这些字体均经过WOFF的编码工具压缩，以便嵌入网页中。[3]WOFF 1.0使用zlib压缩，[3]文件大小一般比TTF小40%。[11]而WOFF 2.0使用Brotli压缩，文件大小比上一版小30%。


Brotli是一个Jyrki Alakuijala和Zoltán Szabadka开发的开源数据压缩程序库。[4][5]Brotli基于LZ77算法的一个现代变体、霍夫曼编码和二阶上下文建模。

在Chrome、Opera和Firefox中，它已被用于加速万维网的传输速度。[6]类似Google的压缩算法zopfli，brotli这个名字来自瑞士的烘培产品brötli。


与常见的通用压缩算法不同，Brotli使用一个预定义的120千字节字典。该字典包含超过13000个常用单词、短语和其他子字符串，这些来自一个文本和HTML文档的大型语料库。[9][10]预定义的算法可以提升较小文件的压缩密度。

使用brotli取代deflate来对文本文件压缩通常可以增加20%的压缩密度，而压缩与解压缩速度则大致不变。使用Brotli进行流压缩的内容编码类型已被提议使用“br”


app.py

        full_git_sha_string = gitpy.rev_list('--abbrev-commit', '--max-count=1', '--format="%h"', 'HEAD')
        sha_string_list = full_git_sha_string.split(os.linesep)


[Font Manager](http://code.google.com/p/font-manager/)
是一个字体管理程序，它适合那些对字体管理有简单需求的桌面用户。Font
Manager

目前包括安装/移除字体、启用/停用已安装字体、预览/比较字体、对字体进行分组/备份等功能。

[![font-manager](http://i.linuxtoy.org/images/2010/05/thumb-font-manager.png)](http//i.linuxtoy.org/images/2010/05/font-manager.png)

Font Manager 提供有源码包和 DEB

二进制包，可从其[项目主页下载](http://code.google.com/p/font-manager/downloads/)。


Fontconfig
A fontconfig file to `~/.config/fontconfig/conf.d` and re-run `fc-cache -vf`.


Ariel 字体的小写l与大写I基本分不清，r和n连接的时候就成乐m。

Helvetica也是如此。

Courier的数字1和小写l分不清。

Apple Color Emoji的数字宽度过大，数字0和大写O不易区分。

Monaco的单引号和双引号也容易区分。





apt-get install fonts-liberation



http://en.wikipedia.org/wiki/Liberation_fonts




如果你安裝的是類似於Arial Unicode MS這種多語系集成版本的話，
第一預設語言多半是日語，所以、也會這樣。
請下載散裝語系的OTF版本、或者OTC版本。



# 从 Adobe 的 Github 的页面上可以下载到 Source Han Sans 专用的 CMap 文件，如简体中文是 UniSourceHanSansCN-UTF32-H。直接拿它给 dvipdfmx 用是不成的，因为 dvipdfmx 要求输入的是 UTF-16 编码的 CMap 文件。其实只要把原来 UTF-32 的 CMap 文件中所有 <数字> 从 UTF-32BE 改为 UTF-16BE 编码即可，因此可以写一个糙快猛的脚本完成这一转换。单纯为了手头方便我是用一两条 VIM 替换命令做的，这条是处理大于 0xFFFF 的部分：

    :%s@<\x\{8}>@printf("<%08x>", (str2nr(submatch(1),16)-0x10000)/0x400*0x10000 + 0xD8000000 + (str2nr(submatch(1),16)-0x10000)%0x400 + 0xDC00)@g



## Noto

We're releasing new fonts to support Music and the following scripts: Ahom,
Bassa Vah, Bhaiksuki, Caucasian Albanian, Duployan, Grantha, Gurmukhi,
Hatran, Khudawadi, Linear A, Mahajani, Manichaean, Marchen, Mende Kikakui,
Miao, Modi, Mro, Multani, Nabataean, Newa, Old Hungarian, Old North Arabian,
Old Permic, Pahawh Hmong, Palmyrene, Pau Cin Hau, Psalter Pahlavi, Sharada,
Sora Sompeng, Takri, Tamil Slanted, Tibetan, Tirhuta, and Warang Citi.

We're releasing updated versions of about 108 Noto families for about 90 scripts,
built from sources using our open source pipeline.  Many of these have
additional weights, and some have multiple widths as well: Sans Kannada,
Sans Malayalam and Serif Sinhala now have 36 styles, Serif Kannada now has 9 styles.
A single font family Noto Sans Syriac replaced all three existing Syriac fonts.

Some number of families have not yet been updated, we will get to those as the
phase 3 work continues.  Others are obsoleted by newer designs.  We will
eventually move the fonts that will not get new updates to a new location to
more clearly distinguish them.

The new fonts, although .ttf, are built on a 1000 upem grid.  This means they
cannot be merged with the older fonts built with the standard ttf 2048 upem.
This is a problem for those who wish to build a single font file from multiple
Noto fonts.  Eventually this will improve, for now our apologies.  We are also
looking at other packaging to make using the fonts easier.

September 19, 2017

Phase 3 font update
===================

We're releasing updated versions of about 75 Noto families, built from sources
using our open source pipeline.  Many of these have additional weights, and some
have multiple widths as well.  The result is the number of font files has
increased about 10x over the previous set.

Most of the new fonts follow the original designs, but a few are new designs.

A number of families have not yet been updated, we will get to those as the
phase 3 work progresses.  Others are obsoleted by newer designs.  We will
eventually move the fonts that will not get new updates to a new location to
more clearly distinguish them.

The new fonts, although .ttf, are built on a 1000 upem grid.  This means they
cannot be merged with the older fonts built with the standard ttf 2048 upem.
This is a problem for those who wish to build a single font file from multiple
Noto fonts.  Eventually this will improve, for now our apologies.  We are also
looking at other packaging to make using the fonts easier.


September 29, 2015

All Noto fonts now licensed under Open Font License 1.1

=======================================================
# Noto fonts

Noto’s goal is to provide a beautiful reading experience for all languages. It is a free, professionally-designed, open-source collection of fonts with a harmonious look and feel in multiple weights and styles. All Noto fonts are published under the [SIL Open Font License (OFL) v1.1](http://scripts.sil.org/OFL), which allows you to copy, modify, and redistribute them if you need to.

To easily preview and download Noto fonts, visit http://www.google.com/get/noto. For background, technical details, and how to contribute, see the [FAQ](FAQ.md).

=======================================================
# Frequently Asked Questions

### What does Noto mean?

When text is rendered by a computer, sometimes characters display as little boxes because your device doesn't have a font that has images for them— these boxes are known as “tofu.”  The name Noto is to convey Google’s goal that users see “**no** more **to**fu.”


### How do I file a bug?

Visit our project’s [bug list](https://github.com/googlefonts/noto-fonts/issues). Please be sure to give as much detail as possible. If it’s a technical issue then list the software and operating system being used as well as versions. If it’s a design issue then images and diagrams are very helpful.


### How do I contribute?

Clone the repositories, try out the fonts, and report bugs. If you wish to contribute tools, please fill out the contributor's agreement which you'll find in the tools repositories.  See below for the various repositories.


### Where are the fonts?

The fonts are in multiple repositories.

* Most of the Noto fonts are in [this GitHub repository](https://github.com/googlefonts/noto-fonts).
* Noto CJK fonts are in [noto-cjk](https://github.com/googlefonts/noto-cjk).
* Noto Emoji and Noto Color Emoji are in [noto-emoji](https://github.com/googlefonts/noto-emoji).

The comprehensive set of Noto fonts and tools are available in [these GitHub repositories](https://github.com/googlefonts?query=noto).


### Is there a discussion group?

Development and user discussions happen on the [noto-font Google Group](https://groups.google.com/d/forum/noto-font).


### What writing systems does Noto support?

As of September 2016, Noto fonts support all scripts/writing systems defined in Unicode 6.1.
* For all major living scripts, Noto provides two weights (regular and bold) and both UI and non-UI fonts. UI fonts are for text display in UI elements (e.g. buttons, menus) that have a height limit.
* For many major living scripts, Noto provides multiple typeface styles. For example, there are sans-serif and serif styles for Latin, Greek, Cyrillic, Indic (Devanagari, Tamil, Telugu etc), Armenian, Georgian, Thai, Khmer, and Lao; Naskh and Kufi styles for Arabic; and Eastern, Western, Estrangela styles for Syriac.
* For many major living scripts, Noto includes both hinted and unhinted fonts: hinted fonts for Windows and Linux, and unhinted fonts for Android and Mac. (Note however that NotoSansSymbols is unhinted).
* For historical scripts, Noto has unhinted fonts with one weight (regular).


### The hinted version of the font is missing

If your favorite font is in the Noto's unhinted directory, but is missing from the [hinted directory](https://github.com/googlefonts/noto-fonts/tree/master/hinted), first please check [noto-hinted](https://github.com/lemzwerg/noto-hinted). It might be already there. If it is not there, then you can help to make it by running the hinting process using [ttfautohint](https://www.freetype.org/ttfautohint/). The process is described in the [noto-hinted README](https://github.com/lemzwerg/noto-hinted/blob/master/README.md). Note however that this tool does not work on all scripts, and in particular, we do not provide hinted versions for many of the living scripts.  Please see [extending ttfautohint with new scripts](https://www.freetype.org/ttfautohint/doc/ttfautohint.html#extending-ttfautohint-with-new-scripts) on the freetype website if you are so inclined.


### What are Google's plans for Noto (so called "Phase 3")?
* We plan to extend character/script coverage to cover 100% of Unicode 9.0 except for CJK. For CJK, we plan to cover Plane 0 (BMP) CJK characters in Unicode 9.0
* We plan to extend Noto from two weights (regular and bold) and one width to a number of weights (thin to heavy) and a number of widths (condensed to normal).
* we plan to open source glyph and other source data for all Noto fonts (except CJK fonts whose source is owned by Adobe), and provide a pipeline to build binary fonts from these sources. With the font sources and pipeline, everyone can build their own fonts and use Noto as the base font for free.


### When will language or script X be supported by Noto?

We do intend to support all scripts encoded by Unicode. That takes time and the ordering is based on a complex changing mix of factors including but not limited to: complexity of the script, product and project needs, availability of script experts and designers, and number and responsiveness of language reviewers.


### Why did you do a font for script X before script Y?

No matter what order you choose to develop the fonts some scripts will come before others. Think of it like serving a banquet meal for 1000 people. You can either serve the meals as they are ready which means that some will get served before others or you can wait until all the meals are ready before you serve anybody. We’ve taken the approach of serving as each is ready.


### What is the Noto design?

Noto provides pan-language harmony, yet maintains authenticity. The goal is great online readability across languages without losing the character that makes each script special. The intention is to create the equivalent of the stylish yet conservative item of clothing that you can keep in your wardrobe forever rather than the highly stylish item that goes out of style in a single season.


### Who designs Noto?

Google provides the direction, planning, and final aesthetic decisions. We employ and collaborate with “native speakers” with type and design experience and some of the best talent in the font industry to develop fonts for each script to meet the Noto design goals.


### How is a Noto font developed?

Noto fonts for each script are developed in a collaborative approach. We work together with font foundries, design houses, and talented designers to develop requirements for each script and for the languages that use that script. Those requirements then lead to design proposals. We then work with reviewers who are native readers of the languages (for living languages) for which the fonts are being designed (often they are experts in the language or its typography) to refine the design proposals. Sometimes this requires working through conflicting design reviews and the careful tweezing out of personal preference. Once the design proposal has been fully vetted, a cycle of font development along with review at each step goes on. How long this takes will vary for each script based on a range of factors including the complexity, number and responsiveness of reviewers, number of glyphs required, and conflicting resource allocation. At the end of all this a technical review of the font is made to hopefully catch any issues. This isn’t foolproof and just like every shipping software system on the planet there will be issues. If you find one then file a bug and we’ll look after it.


### Is Noto just a copy of font X?

Noto Sans for Latin was designed by the same person, Steve Matteson, who has worked with us on other Latin script fonts before. Noto Sans for Latin and these earlier designs have some of the same design goals and with the same designer working on them they do share some resemblance.


### What’s the difference between the UI and non-UI versions?

The UI fonts were initially prepared for use in Android’s UI. They have tighter vertical metrics, and some glyphs that would be clipped are redrawn to fit within the constrained space. They can be used anywhere that has limited vertical space. There are no UI verions of scripts that do not need such adjustment, and the non-UI versions should be preferred for use in body text.


### What about Han unification?

Whether or not Han unification is a good thing is really a moot point at this time. It’s a fact of life that needs to be worked with when designing fonts or text processing systems for the CJK languages. We are building fonts to be used in systems that exist now and that means working within the frameworks that exist. If somebody would like to change those frameworks then they should get involved with the standards bodies and contribute to the development of the standard and change the direction they are going.


### When will Google support Klingon / Elvish / etc.?

Once Klingon / Elvish / etc. is included in Unicode :). Please [contact the Unicode consortium](http://www.unicode.org/contacts.html) to encourage them to support your favourite invented language.


### How does Noto relate to Droid?

Google’s Droid fonts have been superseded by Noto. Noto began as Droid, and all updates are now made to the Noto fonts. Today, Noto gives better support to all languages covered by Droid, with more characters and fewer bugs, and it covers many more languages.  Both Android and ChromeOS have switched to Noto, and we strongly recommend everyone to replace Droid with Noto. Similarly, the Droid Sans Fallback font is superseded by Noto Sans CJK, available from [noto-cjk](https://github.com/googlefonts/noto-cjk).


### Could you provide a single font file that covers every language (or at least as many scripts as possible)?

A single file is not possible, because there are many more glyphs in Noto than can fit into a single font. CJK alone is as large as it can get. In addition, different scripts prefer different line metrics. Noto tries to provide suitable line metrics for each script rather than forcing all scripts to fit one. The UI fonts are an exception to this, however, so using them we could generate a single font sharing a single line height. However, we are working on a possible repackaging of the fonts into a few files. We can probably get one for CJK, one for common scripts in living languages, and one for obscure scripts-- depends if Tangut pushes us over the limit of what non-CJK we can fit into a single font. There are tools that can be used to merge fonts but the devil is in the details-- some common characters are in a few source fonts and if they behave differently we'd have to work that out.


### Are there any Noto YouTube videos I could share with others?

Some of the videos on Noto which one can find on YouTube are
* [Creating Noto for Google](https://www.youtube.com/watch?v=16_NYHUZ1kM)
* [Google’s International Fonts Noto — One Font to Rule Them All](https://www.youtube.com/watch?v=AAzvk9HSi84)

Fonty Python 允许你在 Linux 中对收集的各种字体进行管理。使用 Fonty
Python，你不仅可以安装新字体和预览已安装的字体，而且能够按 Pogs
方式对字体归类。目前，Fonty Python 支持 TTF、OTF、Type1、TTC
等格式的字体文件。

![Fonty Python](http://i.linuxtoy.org/images/2009/02/fonty.jpg)

Fonty Python 需要 wxPython、wxGTK
等使用依赖，可通过所用发行版的包管理器安装或从其项目主页下载。

替代的，在 Linux 下，你也可以选择 [Gnome
Specimen](http://linuxtoy.org/archives/gnome_specimen.html)、[Fontmatrix](http://linuxtoy.org/archives/fontmatrix.html)
等其他字体管理工具。

[Fonty Python](https://savannah.nongnu.org/projects/fontypython/) [via
[Debian Package of the
Day](http://debaday.debian.net/2009/02/22/fonty-python-manage-your-fonts/)]
Pickyfont 是一个使用 Perl 语言写成的小程序，通过它你可以实时更改 X
终端的字体。你无需重新启动 X
终端程序，更改是立即生效的。目前，Pickyfont 支持 Xterm 和 (U)Rxvt 终端。

![pickyfont](http://i.linuxtoy.org/images/2010/05/pickyfont.png)

首先，利用 `pickyfont list`
列出可用的字体列表，之后即可执行形如以下的命令来更改字体：

pickyfont set ter1

该命令将终端的字体设置为 Terminus 12px。

Pickyfont 的源代码可通过 [github](http://github.com/trapd00r/pickyfont)
获取。
This is the first line.

    我们的历史。

下面引用。

    这是空格两个。

继续引用

    空格四个

看来不需要空行。
    空格4个。上面空行。

但是，4个空格是必须。

> 忘记了，这才是引用。
> 字体呢。

缩进代码格式。

引用是需要空行的。
> 试试这个。
> 竟然也不需要。
>     test what

太不严格了


- list
- second
- third

OK了。

继续缩进。
  两个空格

再次
    四个空格

还不错。
要是以前在 Linux 下编辑字体，我通常会使用 [FontForge][f]，而现在则有了新的选择——TruFont。TruFont 是开源的 ufo3 字体编辑器，它支持 .otf、.ttf、.ttx、.pfa、.pfb、.woff 等字体格式。

<!-- PELICAN_END_SUMMARY -->

[![trufont]({filename}/images/trufont.thumb.png)]({filename}/images/trufont.png)

TruFont 能够在 Linux、Mac OS X、以及 Windows 上运行。Linux 用户只要下载其提供的 zip 包即可安装：

    unzip TruFont.zip
    ./TruFont

[f]: http://fontforge.github.io/

```
$ fc-list : family style | grep Mono
Liberation Mono:style=Regular
Bitstream Vera Sans Mono:style=Bold
DejaVu Sans Mono:style=Bold Oblique
FreeMono:style=Oblique,наклонен,cursiva,kurzíva,kursiv,Πλάγια,Kursivoitu,Italique,Dőlt,Corsivo,Cursief,Kursywa,Itálico,oblic,Курсив,İtalik,huruf miring,похилий,ležeče,slīpraksts,pasvirasis,nghiêng,Etzana,तिरछा
Tlwg Mono:style=Bold Oblique
Tlwg Mono:style=Regular
Latin Modern Mono Light Cond,LM Mono Light Cond 10:style=10 Oblique,Italic
WenQuanYi Micro Hei Mono, 文泉驛等寬微米黑，文泉驿等宽微米黑：style=Regular
Latin Modern Mono Light,LM Mono Light 10:style=10 Bold,Bold
Latin Modern Mono Prop Light,LM Mono Prop Light 10:style=10 Oblique,Italic
Latin Modern Mono Prop Light,LM Mono Prop Light 10:style=10 Bold,Bold
Liberation Mono:style=Bold Italic
Tlwg Mono:style=Bold
Latin Modern Mono,LM Mono 12:style=12 Regular,Regular
Nimbus Mono L:style=Bold Oblique
FreeMono:style=Regular,нормален,normal,obyčejné,Standard,µεσαία,Normaali,Normál,Normale,Standaard,Normalny,Обычный,Normálne,menengah,прямій,navadno,vidējs,normalusis,thường,Arrunta,सामान्य
Noto Sans Mono CJK KR:style=Regular
Noto Sans Mono CJK HK:style=Regular
Noto Sans Mono CJK JP:style=Regular
Bitstream Vera Sans Mono:style=Oblique
Nimbus Mono PS:style=Regular
Noto Sans Mono CJK TC:style=Regular
Noto Sans Mono:style=Bold
Noto Sans Mono CJK SC:style=Regular
Latin Modern Mono,LM Mono 10:style=10 Regular,Regular
Latin Modern Mono Slanted,LM Mono Slanted 10:style=10 Regular,Regular
Nimbus Mono L:style=Regular
Latin Modern Mono Prop,LM Mono Prop 10:style=10 Regular,Regular
Latin Modern Mono Prop Light,LM Mono Prop Light 10:style=10 BoldOblique,Bold Italic
Mitra Mono,\\u09ae\\u09bf\\u09a4\\u09cd\\u09b0:style=Regular
Latin Modern Mono,LM Mono 10:style=10 Italic,Italic
DejaVu Sans Mono:style=Oblique
Latin Modern Mono Prop Light,LM Mono Prop Light 10:style=10 Regular,Regular
Noto Sans Mono CJK JP:style=Bold
Noto Sans Mono CJK KR:style=Bold
Noto Sans Mono CJK HK:style=Bold
Bitstream Vera Sans Mono:style=Bold Oblique
Noto Sans Mono CJK SC:style=Bold
Noto Sans Mono CJK TC:style=Bold
Latin Modern Mono,LM Mono 8:style=8 Regular,Regular
Latin Modern Mono Light Cond,LM Mono Light Cond 10:style=10 Regular,Regular
Bitstream Vera Sans Mono:style=Roman
FreeMono:style=Bold,получерен,negreta,tučné,fed,Fett,Έντονα,Negrita,Lihavoitu,Gras,Félkövér,Grassetto,Vet,Halvfet,Pogrubiony,Negrito,gros,Полужирный,Fet,Kalın,huruf tebal,жирний,polkrepko,treknraksts,pusjuodis,đậm,Lodia,धृष्ट
Nimbus Mono PS:style=Bold
Latin Modern Mono,LM Mono 9:style=9 Regular,Regular
Liberation Mono:style=Bold
Noto Mono:style=Regular
Noto Sans Mono:style=Regular
Latin Modern Mono Light,LM Mono Light 10:style=10 Regular,Regular
FreeMono:style=Bold Oblique,получерен наклонен,Negreta cursiva,tučné kurzíva,fed kursiv,Fett-Kursiv,Έντονα Πλάγια,Negrita Cursiva,Lihavoitu Kursivoi,Gras Italique,Félkövér dőlt,Grassetto Corsivo,Vet Cursief,Halvfet Kursiv,Pogrubiona kursywa,Negrito Itálico,gros oblic,Полужирный Курсив,Tučná kurzíva,Fet Kursiv,Kalın İtalik,huruf tebal miring,жирний похилий,polkrepko ležeče,treknais slīpraksts,pusjuodis pasvirasis,Lodi etzana,धृष्ट-तिरछा
Nimbus Mono L:style=Regular Oblique
Latin Modern Mono Prop,LM Mono Prop 10:style=10 Oblique,Italic
Latin Modern Mono Caps,LM Mono Caps 10:style=10 Oblique,Italic
WenQuanYi Zen Hei Mono, 文泉驛等寬正黑，文泉驿等宽正黑：style=Regular
Tlwg Mono:style=Oblique
DejaVu Sans Mono:style=Book
DejaVu Sans Mono:style=Bold
Latin Modern Mono Light,LM Mono Light 10:style=10 Bold Oblique,Bold Italic
Nimbus Mono L:style=Bold
Nimbus Mono PS:style=Bold Italic
Liberation Mono:style=Italic
Nimbus Mono PS:style=Italic
Latin Modern Mono Caps,LM Mono Caps 10:style=10 Regular,Regular
```
Latin Modern Mono Light,LM Mono Light 10:style=10 Oblique,Italic

这算是一篇旧闻。Red Hat 于上周在 Red Hat 峰会上宣布了以 LIBERATION
为商标的字体。这些字体包括三个字体集：无衬线字体、衬线字体以及等宽字体。其中，无衬线字体用于取代
Arial、Albany、Helvetica、Nimbus Sans L 和 Bitstream Vera
Sans；衬线字体用于取代 Times New Roman、Thorndale、Nimbus Roman 和
Bitstream Vera Serif；等宽字体用于取代 Courier
New、Cumberland、Courier、Nimbus Mono L 和 Bitstream Vera Sans Mono。

制作这些字体的起因是为了 Linux 向桌面普及，需要取代微软版权所有的字体
Times New Roman®、Arial® 和 Courier New®，必须制作能够在度量上（metric
equivalents）、水平间隔上（horizontal
spacing）相同的替代字体，以避免相应的法律问题，因为微软不会同意别人重新发布这些字体。

Red Hat 联系了 Ascender
公司，这家业界领先的商用字体设计商同意设计替代字体，并特别授权 Red Hat
以 GPL
版权发布这些字体。这些字体分两个阶段开发，第一阶段实现完全可用的字体，但缺乏
hinting 能力，目前可下载的字体就是这个阶段的成果；第二阶段将开发完全
hinting 能力的字体，计划在年末完成。

关于此字体的更为详细的信息，可参考
[[1](http://www.press.redhat.com/2007/05/09/liberation-fonts/)]
[[2](https://www.redhat.com/promo/fonts/)]。

- [Download Liberation fonts](https://www.redhat.com/promo/fonts/) (RPM
＆ TTF)

[Thanks cabrio!]


ii  fonts-anonymous-pro                      1.003-4                                                              all          fixed width font designed for coders
ii  fonts-arphic-ukai                        0.2.20080216.2-5                                                     all          "AR PL UKai" Chinese Unicode TrueType font collection Kaiti style
ii  fonts-dejavu-core                        2.37-2build1                                                         all          Vera font family derivate with additional characters
ii  fonts-hack                               3.003-3                                                              all          Typeface designed for source code
ii  fonts-inconsolata                        001.010-6build1                                                      all          monospace font for pretty code listings and for the terminal
ii  fonts-noto-cjk                           1:20201206-cjk+repack1-1                                             all          "No Tofu" font families with large Unicode coverage (CJK regular and bold)
ii  fonts-noto-cjk-extra                     1:20201206-cjk+repack1-1                                             all          "No Tofu" font families with large Unicode coverage (CJK all weight)
ii  fonts-noto-color-emoji                   0~20200916-1                                                         all          color emoji font from Google
ii  fonts-noto-mono                          20201225-1build1                                                     all          "No Tofu" monospaced font family with large Unicode coverage
ii  fonts-open-sans                          1.11-1.1                                                             all          humanist sans serif typeface by Steve Matteson
ii  fonts-urw-base35                         20200910-1                                                           all          font set metric-compatible with the 35 PostScript Level 2 Base Fonts
ii  fonts-wqy-microhei                       0.2.0-beta-3.1                                                       all          Sans-serif style CJK font derived from Droid
ii  fonts-wqy-zenhei                         0.9.45-8                                                             all          "WenQuanYi Zen Hei" A Hei-Ti Style (sans-serif) Chinese font
ii  xfonts-base                              1:1.0.5                                                              all          standard fonts for X
ii  xfonts-encodings                         1:1.0.5-0ubuntu1                                                     all          Encodings for X.Org fonts
ii  xfonts-utils                             1:7.7+6                                                              amd64        X Window System font utility programs


## PostScript Type 1
Type 1轮廓可以出色地输出任何大小的文字。轮廓字体通过一套描绘曲线的算式来创建每个字符或“字形”。使用算式，计算机可以绘制出一个“轮廓”形状，然后再“填充”进颜色（例如：黑色）从而打印出字符。这些算式可以按照比例进行缩放到任意大小，而与显示器和打印机的解析度无关。无论是打印到胶片，还是显示在屏幕上都具有同样的质量。

Type 1字体是加密过的


## 兼容
”兼容”意味着两层含义：第一，相兼容字体外观非常相似；第二，也是很重要的，字体含有同样的字符宽度，以便可以用来替代相同文档的内容而不需要重新排版调整。


## hinting technology）来解决字体在低解析度的显示模糊问题。原先的技术是在小字号时改用点阵字体。后来的技术改进首先引入了抗锯齿效果，可以平滑字体边缘；现在常用的是“次像素补偿”（微软使用这个技术，并称为ClearType），使用液晶显示器像素结构，以提高实际能显示的解析度。


ClearType主要是針對LCD液晶顯示器設計，可提高文字的清晰度。基本原理是，将显示器的R, G, B各个次像素也发光，让其色调进行微妙调整，可以达到实际分辨率以上（横方向分辨率的三倍）的纤细文字的显示效果。

依靠ClearType技术提高字体的可读性，相当程度上依赖于使用的字体，所以和原有的标准抗锯齿技术不能进行单纯比较。


如果顯示器不具有適用於ClearType的像素組合特性，以ClearType顯示文字的實際效果會比使用前還要差。部分平面顯示器面板使用不常見的像素排列方式，例如可能有不同的顏色排列順序，或不同軸向的子像素位置（三條水平線等），所以需要為特定的顯示器手動調整ClearType的顯示效果。不具有固定排列組合的顯示器，如CRT，將難以閱讀ClearType所顯示的文字。




大多Windows默认的中文字型在显示小文字时使用点阵来显示，不使用ClearType。微软在Windows Vista裡， 新發佈了两个ClearType中文字型：微软雅黑和微軟正黑體。





## FreeType项目期望创建一个独立执行的TrueType标准（如同Freetype 2其他字体标准）。FreeType包含很多Linux提供者。

在FreeType中有一些专利问题因为一部分TrueType字体提示虚拟机是苹果的专利保护的，并没有在TrueType标准中提及。FreeType 2包括一个自动提示器可以分析字形形状，并自动生成提示，从而跳过这些受专利保护的技术。


## Converting

TrueType字体中的字符（或字形）轮廓由直线和二次貝塞爾曲線（bézier）片段构成。这些构建在数学上比平面设计界PostScript使用的三次贝塞尔曲线（也被Type 1字体所使用）更容易处理。尽管如此，对于多数形状，二次要比三次贝塞尔曲线需要更多的点来描述。这个差异也意味着它不能将Type 1无损地转换为TrueType格式，可是你可以无损地将TrueType转换为Type 1。

## Hints

TrueType系統包含一個虛擬機在字體內部執行程序，處理字形的"提示"（hints）。這些定義輪廓的控制點最主要目的是在字型顯示時減少模糊現象。每個字形的提示程序能算出顯示字形的像素大小，以及顯示環境中其他次要參數。

雖然和普通程序中的接受輸入和產品輸出一同，TrueType提示語言的確具備一些程序語言的特性：條件分支（IF聲明），控制循環一個時間的算法（FOR- 和WHILE-型聲明），變量（雖然這些只是內存中分給字體的一個區域中的簡單編號的槽），並將代碼封裝到函數中。特別結構delta hints是最低級的控制，用來移動一個控制點或一個像素大小。

好的TrueType字形程序技術需要在一個字體中盡可能的使用一次參數定義（例如：字符頸寬、大寫字母高度、x字高）。這意味著盡量避免delta結構。這可以幫助字體開發者做一些重要修改（例如：要統一將字符主高改到1-2像素寬的時候）。

制作一个良好提示的TrueType字体需要大量的工作。1990年代以来，大量的添加字體提示的程序被開發出來給用戶使用；但是，很多TrueType字体只有一些很不完善的提示，或者只有根据字体编辑器自动提示，导致各种不同结果。

## 点阵字体(Dot-matrix-fonts)也叫位图字体(Bitmap-fonts)，其中每个字形都以一组二维像素信息表示。這種文字顯示方式於較早前的電腦系統（例如未有圖形介面時的 DOS 操作系統）被普遍採用。由于位图的緣故，点阵字体很难进行缩放，特定的点阵字体只能清晰地显示在相应的字号下，否則文字只被強行放大而失真字形，產生成馬賽克式的鋸齒邊緣。但對於字型大小 8-14px 的尺寸較小的漢字字體（即現今操作系統大多採用的預設字型大小）現今亦仍然被使用於熒幕顯示上，能夠提供更高的顯示效果；不過現今該種點陣字體主要只作為「輔助」的部分，當使用者設定的字體尺寸並無擁有點陣圖像時，字體便會以向量圖方式顯示；而當列印時，印有字體無論大小亦會使用向量字型打印。

现在的一些字体渲染系统直接抛弃了点阵字体，而使用一些算法进行带抗锯齿的矢量渲染。

ᴄʜᴇᴀᴘᴇʀ hᴇᴀʟth ɪnsᴜʀᴀnᴄᴇ is ʜᴇʀᴇ!

CHEAPER hEALth InSURAnCE is HERE!  <-- ascii

ᴀɴᴀᴜBMsAᴇᴛHᴏɪ
ANAUBMsAETHoI

## gconf-editor

    \`/apps/gnome-terminal/profiles/Default\`，找到配置项 \`font\`

## fc-cache -vf

Install fonts

```
find "$powerline_fonts_dir" \( -name "$prefix*.[ot]tf" -or -name "$prefix*.pcf.gz" \) -type f -print0 | xargs -0 -n1 -I % cp "%" "$font_dir/"
```

Removing fonts

```
find "$powerline_fonts_dir" \( -name "$prefix*.[ot]tf" -or -name "$prefix*.pcf.gz" \) -type f -print0 | xargs -n1 -0 -I % sh -c "rm -f \"\$0/\${1##*/}\"" "$font_dir" %
```


# Reset font cache on Linux
if which fc-cache >/dev/null 2>&1 ; then
    echo "Resetting font cache, this may take a moment..."
    fc-cache -f "$font_dir"
fi


# Hack

https://github.com/source-foundry/Hack#quick-installation

# Add Hack to HTML
Include one of the following in the <head> section of your HTML file:

Subset web fonts

<link rel="stylesheet" href="//cdn.jsdelivr.net/npm/hack-font@3/build/web/hack-subset.css">

Full character set web fonts

<link rel="stylesheet" href="//cdn.jsdelivr.net/npm/hack-font@3/build/web/hack.css">

## TrueType
## OpenType

## cf. font in css

generic-family - The name of a generic-family, like "serif", "sans-serif", "cursive", "fantasy", "monospace".


" Test Fonts. Size: 12. Mono: equal width
" !1lIoO0`'"rnmgq97j[{(,.:;/|\
" Better choice: DejaVu Sans Mono

xlsfonts说明core X11 font system找到字体，

fc-list fontconfig找到font

让core font system找到的办法是首先保证正确生成fonts.dir/fonts.scale文件，并且把字体目录添加在X的FontPath列表中

安装好后，重启X，然后打xset -q，会看到这个目录的。

## wqy

The Wen Quan Yi bitmap font is a manually fine-tuned
multi-strike bitmap font for on-screen display of Chinese
(traditional and simplified). It has arguably the most complete
coverage for Chinese characters among all known open-source
fonts, including CJK Unified Ideograph (U4E00 - U9FA5) and
CJK Unified Ideograph Extension A (U3400 - U4DB5) glyphs
at four different sizes (9pt-12X12 pixel, 10pt-13X13 pixel,
11pt-15X15 pixel, 12pt-16x16 pixel) and two weights
(medium and bold). Use this font in web pages and elsewhere
eliminates the annoying "blurring" problems caused by
the high stroke density of many Chinese characters and
insufficient "hinting" of anti-aliased Chinese fonts.
This font also provides bitmap glyphs for Basic Latin,
Japanese Hiragana (U3040 - U309F) and Katakana (U30A0 - U30FF).

This font was built upon the previous works by firefly
(firefly[at]firefly(dot)idv(dot)tw)[2]. The 12pt bitmap
glyphs between U3400-U9FA5 were derived from Chinese
national standard GB19966-2005




fc-cache -fv


衬线指的是字形笔画末端的装饰细节部分。
无衬线字体在西文中习惯称sans-serif，其中sans为法语的“无”的意思
另外一些人习惯称grotesque（德语作grotesk）或“哥特体”，把衬线体称为“罗馬体”
“无衬线体”（中文惯用“黑体”


衬线体（即“白体”），中國大陸地區和港臺的印刷界稱之為宋体，港臺的繁体中文電腦系統称之为明體，日文稱明朝体，韩国语稱바탕(Batang)体，常用于正文排版。这些名称起源于中国历史上的宋朝和明朝，当时中国的活字印刷术已经广泛传播，而用于制造活字的木纹多为水平方向，因此造成在刻字时横画细，竖画粗；而且为了防止边缘破损，横画在两端也被加粗，根据运笔习惯而形成三角形的装饰。这种方式一直沿用至今，现在白体类字体多数都是横细竖粗。


无衬线体在中文通常称为黑体，在日文称为ゴシック体（Goshikku-tai，即“哥特体”），韩国语中稱Dotum体，这类字体笔画粗细基本一致，没有衬线装饰，較為醒目，常用于标题、导语、标志等。


为了更好解决衬线字体的显示问题，新的反锯齿和次像素显示（如ClearType）等技术开始广泛运用。但是目前最一般的显示器解析度也不过每英寸100像素，这是屏幕显示衬线体可读性的瓶颈所在。




/etc/fonts/conf.d/65-nonlatin.conf






====
DEBDIFF="http://archive.ubuntu.com/ubuntu/pool/universe/x/xfonts-wqy/xfonts-wqy_0.7.0-6-1ubuntu1.diff.gz"
NBDLURL="http://wenq.org/daily/"
ROOTDIR=$(dirname $0)
cd $ROOTDIR

echo //////////////////////////////////////////////////////////////
echo // Please run "apt-get build-dep xfonts-wqy" to get
echo // build-depend packages. You also need dpkg-dev and
echo // fakeroot.
echo "Do you have them? (y/n)"
if [[ $1 = "--default" ]]; then
REQ=Y
else
read REQ
fi

case "$REQ" in
"Y" | "y" )
echo Continue...
;;
* )
echo Sorry.
exit 1
;;
esac

echo //////////////////////////////////////////////////////////////
echo // Cleaning last build...
rm -rf ./wqy_temp
mkdir wqy_temp
cd wqy_temp

echo // Getting info from ubuntu.com ...
if wget --quiet $DEBDIFF -O wqy_deb_diff.gz; then
zcat wqy_deb_diff.gz | patch --quiet -p1
rm wqy_deb_diff.gz
else
echo // Found error
exit 1
fi

DEBVER=$(head -1 debian/changelog | sed 's/.*(//g' | sed 's/).*//g')
WQYVER=$(echo $DEBVER | sed 's/-[a-z0-9.]*$//g')
NBVER=$DEBVER.nightly$(date -u +%Y%m%d)

echo // src pkg is ./wqy_temp/xfonts-wqy_$WQYVER.orig.tar.gz
echo // nightly build deb version is $NBVER
echo // Downloading source tarball...
if wget $NBDLURL -O xfonts-wqy_$WQYVER.orig.tar.gz; then
tar zxf xfonts-wqy_$WQYVER.orig.tar.gz
else
echo // Found error
exit 1
fi


echo // Generating new version entry...
mv debian wqy-bitmapfont/
cd wqy-bitmapfont
dch -v $NBVER "New nightly build"
chmod +x debian/rules

echo // Building nightly deb package...
if dpkg-buildpackage -rfakeroot -i -us -uc ; then
echo //////////////////////////////////////////////////////////////
echo // Please run "sudo dpkg -i ./wqy_temp/xfonts-wqy_"$NBVER"_all.deb"
echo // Thanks for testing!
else
echo // Found error
exit 1
fi

exit 0

* . 给脚本增加运行权限

chmod +x build_wqy_for_ubuntu.sh

* . 安装脚本运行环境

# apt-get build-dep xfonts-wqy
# apt-get install dpkg-dev fakeroot

* . 运行脚本,将生成wqy的deb安装包

./build_wqy_for_ubuntu.sh

* . 安装wqy

# dpkg -i ./wqy_temp/*.deb

====
CJK Unified Ideograph (U4E00 - U9FA5)
CJK Unified Ideograph Extension A (U3400 - U4DB5)
glyph

sizes (9pt-12x12 pixel, 10pt-13x13 pixel, 11pt-15x15 pixel, 12pt-16x16 pixel)
weights (medium and bold).

"blurring" problems caused by the high stroke density of many Chinese characters
insufficient "hinting" of anti-aliased Chinese fonts.

This font also provides bitmap glyphs for Basic Latin, Japanese Hiragana (U3040 - U309F) and Katakana (U30A0 - U30FF).

====
Sans-Serif style,
 also known as Hei, Gothic or Dotum among the Chinese/Japanese/Korean users
====

"Micro Hei" and "Micro Hei Mono", in form of a True-Type Collection (ttc) file.

All the unified CJK Han glyphs, i.e.  GBK Hanzi, in the range of U+4E00-U+9FC3 defined in Unicode Standard 5.1 are covered,
with additional support to many other international languages such as Latin, Extended Latin, Hanguls and Kanas.

both font faces carry hinting and kerning instructions for Latin glyphs,
====
文泉驿点阵宋体包含了所有常用简体中文、繁体中文，日文及韩文所需要的汉字(最新版本包含超过27842个汉字，完整覆盖GB2312/Big5/GBK /GB18030标准字符集)。该字体同时还包含了英文、日文、韩文和其他多种语言符号。该点阵字体包含四个屏幕常用字号(9pt-12pt)，逾11万汉字点阵，这些点阵都经过参与者和组织者的精心设计和调整，手工优化后的汉字点阵显示清晰锐利，特别易于屏幕阅读使用。

文泉驿正黑体 嵌入了所有GBK汉字点阵，在9-12pt范围内，将自动使用点阵宋体显示。
====

内含dejavusansyuanti, dejavusansyuanticondensed, dejavusansyuantimono三种字体族。个人推荐condensed作为日常使用，其英文占地少，但仍然很清晰。

====

# 字体合并脚本 1.0 merge.pe
# zhuqin <zhuqin83@gmail.com>
# 请先安装好fontforge，并将所需合并的两个字体放在本脚本的同一目录下。
# 然后按需要修改本脚本的各项参数，如字体名等。
# 最后运行 fontforge -script merge.pe
# 脚本的修改请参照 http://fontforge.sourceforge.net/scripting.html

# 中文字体
Open("VeraSansYuanTi-Italic.ttf")
SelectAll()
#ScaleToEm(2048)
Generate("temp.ttf")
Close()

# 非中文字体，如英文等。
Open("DejaVuSans-Oblique.ttf")
SelectAll()
#ScaleToEm(2048)

MergeFonts("temp.ttf")
SetFontNames("DejaVuSansYuanTi-Oblique", "DejaVu Sans YuanTi", "DejaVu Sans YuanTi Oblique", "Oblique", "Copyleft 2008")
Generate("DejaVuSansYuanTi-Oblique.ttf")
Close()

====

# cp /etc/fonts/fonts.conf.old /etc/fonts/fonts.conf
# gedit /etc/fonts/language-selector.conf

添加圆体字为首选项
（参考配置）
引用
<fontconfig>

<alias>

<family>serif</family>

<prefer>

<family>Bitstream Vera Serif</family>
<family>Vera Sans YuanTi Mono</family>

<family>DejaVu Serif</family>

<family>AR PL ShanHeiSun Uni</family>

<family>WenQuanYi Bitmap Song</family>

<family>AR PL ZenKai Uni</family>

</prefer>

</alias>

<alias>

<family>sans-serif</family>

<prefer>

<family>Bitstream Vera Sans</family>
<family>Vera Sans YuanTi Mono</family>
<family>Vera Sans YuanTi Mono</family>

<family>DejaVu Sans</family>

<family>AR PL ShanHeiSun Uni</family>

<family>WenQuanYi Bitmap Song</family>

<family>AR PL ZenKai Uni</family>

</prefer>

</alias>

<alias>

<family>monospace</family>

<prefer>

<family>Bitstream Vera Sans Mono</family>
<family>Vera Sans YuanTi Mono</family>

<family>DejaVu Sans Mono</family>

<family>AR PL ShanHeiSun Uni</family>

<family>WenQuanYi Bitmap Song</family>

<family>AR PL ZenKai Uni</family>

</prefer>

</alias>

<match target="font" >

<test name="family" compare="contains" >

<string>Song</string>

<string>Sun</string>

<string>Kai</string>

<string>Ming</string>

</test>

<test compare="more_eq" target="pattern" name="weight" >

<int>180</int>

</test>

<edit mode="assign" name="embolden" >

<bool>true</bool>

</edit>

</match>

<match target="font" >

<test name="family" compare="contains" >

<string>Song</string>

<string>Sun</string>

<string>Kai</string>

<string>Ming</string>

</test>

<edit name="globaladvance">

<bool>false</bool>

</edit>

<edit name="spacing">

<int>0</int>

</edit>

<edit name="hinting">

<bool>true</bool>

</edit>

<edit name="autohint">

<bool>false</bool>

</edit>

<edit name="antialias" mode="assign">

<bool>true</bool>

</edit>

<test name="pixelsize" compare="less_eq">

<int>18</int>

</test>

<edit name="antialias" mode="assign" >

<bool>false</bool>

</edit>

</match>

</fontconfig>

重启X
这下正常了
进入 X 后，在字体设置里选择 Vera Sans YuanTi，大小为 xx 即可
如果你想要类似 mac OS X 的那种粗粗黑黑的效果就编辑 /etc/fonts/fonts.conf
把以下内容加入（</FONTCONFIG> 前面）
代码
<match target="font">
<test name="family"><string>Vera Sans YuanTi</string></test>
<edit name="globaladvance"><bool>false</bool></edit>
</match>

<match target="font">
<test name="family"><string>Vera Sans YuanTi Mono</string></test>
<edit name="globaladvance"><bool>false</bool></edit>
</match>

<match target="font">
<edit name="antialias"><bool>true</bool></edit>
<edit name="hinting"><bool>false</bool></edit>
<edit name="autohint"><bool>false</bool></edit>
</match>

如果你想要类似 windows 的那种清晰细腻的的效果就编辑 /etc/fonts/fonts.conf
把以下内容加入（</FONTCONFIG> 前面）
代码
<match target="font">
<test name="family"><string>Vera Sans YuanTi</string></test>
<edit name="globaladvance"><bool>false</bool></edit>
</match>

<match target="font">
<test name="family"><string>Vera Sans YuanTi Mono</string></test>
<edit name="globaladvance"><bool>false</bool></edit>
</match>

<match target="font">
<edit name="antialias"><bool>true</bool></edit>
<edit name="hinting"><bool>false</bool></edit>
<edit name="autohint"><bool>false</bool></edit>
</match>

<match target="font">
<test name="pixelsize" compare="more_eq"><double>12</double></test>
<test name="pixelsize" compare="less_eq"><double>16</double></test>
<edit name="antialias"><bool>false</bool></edit>
<edit name="hinting"><bool>true</bool></edit>
<edit name="autohint"><bool>false</bool></edit>
</match>


====

问题的缘由是: 我想使用英文字体显示英文, 中文字体只应用在中文.

局部的意思是:
1. fluxbox控制的字体部分, 例如窗口标题
2. conky显示的字体, 例如mpd的播放信息
3. flash部分字体显示为空白

不好的解决办法: 全部使用中文字体
理想的解决办法: 使用~/.fonts.conf设置字体替换解决
暴力的解决办法: 使用fontforge合成字体

其中暴力的办法应该能根本解决问题, 但是在此之前最好再给理想一个机会.

$ fc-list | egrep 'FZ|ITC|Parisine' Vintage ITC:style=Regular Parisine:style=Italic ParisineClair:style=Italic Parisine:style=Regular ParisineClair:style=BoldItalic ParisineClair:style=Bold ParisineClair:style=Regular Parisine:style=Bold FZLiBian\-S02,方正隶变_GBK:style=Regular Parisine:style=BoldItalic Parisine:style=BoldAlternate Parisine:style=BoldItalicAlternate

~/.fonts.conf

<?xml version="1.0"?>
<!DOCTYPE fontconfig SYSTEM "fonts.dtd">

<fontconfig>

 <match target="font" >
    <edit mode="assign" name="rgba" >
     <const>none</const>
    </edit>
 </match>
 <match target="font" >
    <edit mode="assign" name="hinting">
     <bool>true</bool>
    </edit>
 </match>
 <match target="font" >
    <edit mode="assign" name="hintstyle">
     <const>hintfull</const>
    </edit>
 </match>

 <match target="font" >
    <edit mode="assign" name="antialias">
     <bool>true</bool>
    </edit>
 </match>

<!-- Autohinter is not turned on automatically.
 Only disable this if you have recompiled Freetype with the bytecode interpreter,
 which is run automatically.<br />  -->
 <match target="pattern" >
    <edit mode="assign" name="autohint">
     <bool>true</bool>
    </edit>
 </match>
 <match target="font">
         <test name="weight" compare="more">
                 <const>medium</const>
         </test>
         <edit name="autohint" mode="assign">
                 <bool>false</bool>
         </edit>
 </match>

<!--让字体引擎(FreeType)取消CJK字体的指定宽度-->
 <match target="font">
                <test target="pattern" name="lang" compare="contains">
                        <string>zh</string>
                        <string>ja</string>
                        <string>ko</string>
                </test>
                <edit name="spacing">
                        <const>proportional</const>
                </edit>
                <edit name="globaladvance">
                        <bool>false</bool>
                </edit>
 </match>

<!--设定当默认字体不存在时,用以下字体替换-->
<alias>
 <family>serif</family>
  <prefer>
   <family>Bitstream Vera Serif</family>
   <family>DejaVu Serif</family>
   <family>方正隶变_GBK</family>
   <family>DejaVu Sans YuanTi</family>
  </prefer>
</alias>
<alias>
 <family>sans-serif</family>
  <prefer>
   <family>DejaVu Sans</family>
   <family>Bitstream Vera Sans</family>
   <family>方正隶变_GBK</family>
   <family>DejaVu Sans YuanTi</family>
  </prefer>
</alias>
<alias>
 <family>monospace</family>
  <prefer>
   <family>DejaVu Sans Mono</family>
   <family>Bitstream Vera Sans Mono</family>
   <family>方正隶变_GBK</family>
   <family>DejaVu Sans YuanTi</family>
  </prefer>
</alias>
<alias>
 <family>Parisine</family>
  <prefer>
   <family>DejaVu Sans Mono</family>
   <family>Bitstream Vera Sans Mono</family>
   <family>方正隶变_GBK</family>
   <family>DejaVu Sans YuanTi</family>
  </prefer>
</alias>
<alias>
 <family>Vintage ITC</family>
  <prefer>
   <family>DejaVu Sans Mono</family>
   <family>Bitstream Vera Sans Mono</family>
   <family>方正隶变_GBK</family>
   <family>DejaVu Sans YuanTi</family>
  </prefer>
</alias>

<dir>~/.fonts</dir>

</fontconfig>


<!--设定当默认字体不存在时,用以下字体替换-->后面的alias部分就是对字体替换顺序的设置, 我试过在方正隶变_GBK前面加SimSum一行, 重新打开pcmanfm可以看到中文字体按照设置更换了. 也就是说, 这个设置方法可以在gtk程序中生效了.
[照理对Parisine和Vintage ITC字体的alias设置应该是没有必要的, serif, sans-serif, monospace应该包含所有字体了, 不过我不晓得啦...以防万一]

我的~/.gtkrc-2.0

代码:

include "/usr/share/themes/Mist/gtk-2.0/gtkrc" style "user-font" { font_name = "ParisineClair Bold 10" } widget_class "*" style "user-font" gtk-font-name="ParisineClair Bold 10"

2. ~/.fluxbox/overlay

代码:

menu.title.font: Mercury-12 menu.frame.font: TheSans-12 window.font: ParisineClair-10:bold toolbar.iconbar.focused.font: Mercury-8:bold toolbar.iconbar.unfocused.font: Mercury-8 toolbar.clock.font: Terminus-10:bold toolbar.workspace.font: Vintage ITC-10:bold

这个设置确实可以取代flux主题的字体设置, reload config后在窗口标题栏中立即生效, 但是中文字体是不显示的, 例如现在firefox的标题栏, 显示成
引用:
LinuxSir.Org - 五个小空格 - Mozilla Firefox
对,中文不是框框, 而是空白(linuxsir的多个连续空格总是被处理成一个...所以只好写字占位)
也试过 window.font: ParisineClair-10:bold|方正隶变_GBK-10, 一样没效果.
这让我觉得可能fluxbox读字体的方式不遵循~/.fonts.conf的规则?
但是就一个不行还勉强接受, 但是conky也不行, 就很可疑了~

3. ~/.conkyrc
有关字体设置的就两行
代码:

use_xft yes xftfont Vintage ITC:size=9:bold

对, 就一个英文字体 Vintage ITC, 这个字体本身显示的好好的, 但是候补中文字体却没有露脸的机会. 情况同fluxbox的窗口标题, 中文显示为空白. 但是你从前面可以看到, 我的~/fonts.conf已经对 Vintage ITC 进行过字体替换设置了.

====
文泉驿字体与GB18030没有直接的关系.

如上所述, GB18030是一个编码的强制性国家标准. 这个标准规定了Unicode所收录的符号的一种与GBK/GB2312编码兼容的编码形式(也就是说某个unicode符号对应的编码值是多少.). 对GB18030的支持是通过一个unicode<->gb18030编码映射表实现的. 也就是说, Linux之后中只要locale信息中包含了这个映射表, 并且glibc中定义了相应的编码registry之后,gb18030标准的支持已经实现, 与系统上使用的字体没有关系 (微软Windows GB18030补丁中真正起作用的也只是一个编码转换表和转换函数, 以及GB18030的系统registry,与附带的字体没有直接关系).

文泉驿字体与其他大多数国际通用字体一样, 使用ISO10646编码(unicode)作为字体内部编码, 字体内部编码与操作系统支持的语言编码没有直接的关系. 直接采用GB18030作为字体编码的通用字体也非常少见.

另外,GB18030对应的字符集是全部Unicode符号, 即包括CJK Basic, CJK扩展A区和B区的所有汉字以及非汉字符号. GB18030并没有对字体对该字符集覆盖的完备性上做任何规定. 事实上, 不可能也完全没有必要要求字体必须全部覆盖GB18030字符集. 据本人所知, 迄今还尚未有完全覆盖GB18030字符集的字体.

我们在一些文档中提到文泉驿字体将支持GB18030字符集的说法只是一种简化的说法, 并不准确. 这里的"GB18030字符集"只是CJK Basic+CJK ExtA的一个替换称呼, 与真正的GB18030字符集不同.




====
    FILE *fin, *fout;
    char *encFrom, *encTo;
    char bufin[1024], bufout[1024], *sin, *sout;
    int mode, lenin, lenout, ret, nline;
    iconv_t c_pt;
    encFrom = "utf-8";
    encTo   = "gbk";
    if ((c_pt = iconv_open(encTo, encFrom)) == (iconv_t)-1) {
        printf("iconv_open false: %s ==> %s\n", encFrom, encTo);
        return -1;
    }
    iconv(c_pt, NULL, NULL, NULL, NULL);
    strcpy(bufin,"姝ｅ父");
    lenin  = strlen(bufin) + 1;
    lenout = 1024;
    sin    = bufin;
    sout   = bufout;
    iconv(c_pt,
                &sin,
                (size_t*)&lenin,
                &sout,
                (size_t*)&lenout);
    printf("%s -> %s: ret=%d, len_in=%d, len_out=%d\n",
            encFrom, encTo, ret, lenin, lenout);
    iconv_close(c_pt);
    printf("out= %s\n",&sout);

更详细的用法请man 3 iconv


====
perl程序中如何转换GB2312/GBK/GB18030编码为utf-8编码？如何反向转换？
=====作者： Yourway 答：从Perl5.8开始，可以使用Encode模块来完成这个操作。 use Encode;

$str_ust8 = encode("utf-8",decode("gbk",$str_gbk)); $str_gbk = encode("gbk", decode('utf-8',$str_utf8));
====
 mount -t ntfs -o iocharset=utf8 /dev/hdxx /path/to/mount_point
====
 mount -o iocharset=utf8 /dev/hdxx /path/to/mount_point
 mount -o utf8 /dev/hdxx /path/to/mount_point

====
the Kana glyphs change but the Kanji remain the same.



【 在 thepro (All Things Bright and Beautiful) 的大作中提到: 】
: 自己做就行，写6k个字，一天100个，2月over了
: 详情可以见文泉驿


--
7月13日 dota。
7月14日 dota。
7月15日 dota。
7月16日 贾君鹏啊贾君鹏！你怎么能如此堕落！先前订下的学习计划你都忘了吗？子曰：“吾日三省吾身。”…不能再这样下去了！
7月17日 dota。
7 月18日 dota。


※ 来源:·BBS 科苑星空站 kyxk.net·[FROM: 210.76.202.*]

[本篇全文] [本篇作者：xdSu] [进入讨论区] [返回顶部]
9
发信人: xdSu (你们不是特警！特警干嘛喝我的王老吉！), 信区: Test
标  题: Re: test字体
发信站: BBS 科苑星空站 (Mon Nov 30 08:26:44 2009), 站内

温泉的黑体很耐看 宋体丑了点 =.=

【 在 thepro (All Things Bright and Beautiful) 的大作中提到: 】
: 他那个当然复杂了，因为要做很专业的字体，玩的话，应该只要每个编码对应1个字即可，最小的gb编码不到7k个应该不难
: 没玩过，觉得有个手写板更好
: 老徐的字体刚上市的时候，方正收费10元下载一次。撇开这个不说，方正在字体上的收入老大了


--
3.追求一种清闲也是一种追求


※ 来源:·BBS 科苑星空站 kyxk.net·[FROM: 222.222.70.*]

[本篇全文] [本篇作者：xdSu] [进入讨论区] [返回顶部]
10
发信人: xdSu (你们不是特警！特警干嘛喝我的王老吉！), 信区: Test
标  题: Re: test字体
发信站: BBS 科苑星空站 (Mon Nov 30 13:06:16 2009), 站内

教一下怎么把wqy黑弄到win下面来

以前研究过，都没搞定

有没有等宽字体推荐，最近看Courier New有点审美疲劳了快

【 在 thepro (All Things Bright and Beautiful) 的大作中提到: 】
: 以前也搞过中文处理，了解一点点多语文字排版中的字体渲染，所以用过几百种中文字体，有专门的文档测试字体的合格率，目前wqy的黑体得分是最高的，比雅黑和苹果、adobe的其他字体都好得多，对于液晶显示器来说，无称线（在中文即黑体部分圆体）是最适合人眼的，
: 而且，这是唯一合法的免费的黑体，除此之外合法的最佳选择基本上就是文鼎和uming/ukai等了


--
4. 开始怀念无忧无虑的生活，有快乐，有忧伤，但是没有烦恼。


※ 来源:·BBS 科苑星空站 kyxk.net·[FROM: 222.222.70.*]

[本篇全文] [本篇作者：xdSu] [进入讨论区] [返回顶部]
11
发信人: xdSu (你们不是特警！特警干嘛喝我的王老吉！), 信区: Test
标  题: Re: test字体
发信站: BBS 科苑星空站 (Mon Nov 30 14:21:08 2009), 站内

囧 那不折腾了 ttc我试过

【 在 thepro (All Things Bright and Beautiful) 的大作中提到: 】
: 哦，补充一个，由于win字体render设计的原因，其系统无法正常使用文泉字体（常用字号部分）



# cf. font in css

generic-family - The name of a generic-family, like "serif", "sans-serif", "cursive", "fantasy", "monospace".


" Test Fonts. Size: 12. Mono: equal width
" !1lIoO0`'"rnmgq97j[{(,.:;/|\
" Better choice: DejaVu Sans Mono

xlsfonts说明core X11 font system找到字体，

fc-list fontconfig找到font

让core font system找到的办法是首先保证正确生成fonts.dir/fonts.scale文件，并且把字体目录添加在X的FontPath列表中

安装好后，重启X，然后打xset -q，会看到这个目录的。

wqy

The Wen Quan Yi bitmap font is a manually fine-tuned
multi-strike bitmap font for on-screen display of Chinese
(traditional and simplified). It has arguably the most complete
coverage for Chinese characters among all known open-source
fonts, including CJK Unified Ideograph (U4E00 - U9FA5) and
CJK Unified Ideograph Extension A (U3400 - U4DB5) glyphs
at four different sizes (9pt-12X12 pixel, 10pt-13X13 pixel,
11pt-15X15 pixel, 12pt-16x16 pixel) and two weights
(medium and bold). Use this font in web pages and elsewhere
eliminates the annoying "blurring" problems caused by
the high stroke density of many Chinese characters and
insufficient "hinting" of anti-aliased Chinese fonts.
This font also provides bitmap glyphs for Basic Latin,
Japanese Hiragana (U3040 - U309F) and Katakana (U30A0 - U30FF).

This font was built upon the previous works by firefly
(firefly[at]firefly(dot)idv(dot)tw)[2]. The 12pt bitmap
glyphs between U3400-U9FA5 were derived from Chinese
national standard GB19966-2005




fc-cache -fv


衬线指的是字形笔画末端的装饰细节部分。
无衬线字体在西文中习惯称sans-serif，其中sans为法语的“无”的意思
另外一些人习惯称grotesque（德语作grotesk）或“哥特体”，把衬线体称为“罗馬体”
“无衬线体”（中文惯用“黑体”


衬线体（即“白体”），中國大陸地區和港臺的印刷界稱之為宋体，港臺的繁体中文電腦系統称之为明體，日文稱明朝体，韩国语稱바탕(Batang)体，常用于正文排版。这些名称起源于中国历史上的宋朝和明朝，当时中国的活字印刷术已经广泛传播，而用于制造活字的木纹多为水平方向，因此造成在刻字时横画细，竖画粗；而且为了防止边缘破损，横画在两端也被加粗，根据运笔习惯而形成三角形的装饰。这种方式一直沿用至今，现在白体类字体多数都是横细竖粗。


无衬线体在中文通常称为黑体，在日文称为ゴシック体（Goshikku-tai，即“哥特体”），韩国语中稱Dotum体，这类字体笔画粗细基本一致，没有衬线装饰，較為醒目，常用于标题、导语、标志等。


为了更好解决衬线字体的显示问题，新的反锯齿和次像素显示（如ClearType）等技术开始广泛运用。但是目前最一般的显示器解析度也不过每英寸100像素，这是屏幕显示衬线体可读性的瓶颈所在。




/etc/fonts/conf.d/65-nonlatin.conf






====
DEBDIFF="http://archive.ubuntu.com/ubuntu/pool/universe/x/xfonts-wqy/xfonts-wqy_0.7.0-6-1ubuntu1.diff.gz"
NBDLURL="http://wenq.org/daily/"
ROOTDIR=$(dirname $0)
cd $ROOTDIR

echo //////////////////////////////////////////////////////////////
echo // Please run "apt-get build-dep xfonts-wqy" to get
echo // build-depend packages. You also need dpkg-dev and
echo // fakeroot.
echo "Do you have them? (y/n)"
if [[ $1 = "--default" ]]; then
REQ=Y
else
read REQ
fi

case "$REQ" in
"Y" | "y" )
echo Continue...
;;
* )
echo Sorry.
exit 1
;;
esac

echo //////////////////////////////////////////////////////////////
echo // Cleaning last build...
rm -rf ./wqy_temp
mkdir wqy_temp
cd wqy_temp

echo // Getting info from ubuntu.com ...
if wget --quiet $DEBDIFF -O wqy_deb_diff.gz; then
zcat wqy_deb_diff.gz | patch --quiet -p1
rm wqy_deb_diff.gz
else
echo // Found error
exit 1
fi

DEBVER=$(head -1 debian/changelog | sed 's/.*(//g' | sed 's/).*//g')
WQYVER=$(echo $DEBVER | sed 's/-[a-z0-9.]*$//g')
NBVER=$DEBVER.nightly$(date -u +%Y%m%d)

echo // src pkg is ./wqy_temp/xfonts-wqy_$WQYVER.orig.tar.gz
echo // nightly build deb version is $NBVER
echo // Downloading source tarball...
if wget $NBDLURL -O xfonts-wqy_$WQYVER.orig.tar.gz; then
tar zxf xfonts-wqy_$WQYVER.orig.tar.gz
else
echo // Found error
exit 1
fi


echo // Generating new version entry...
mv debian wqy-bitmapfont/
cd wqy-bitmapfont
dch -v $NBVER "New nightly build"
chmod +x debian/rules

echo // Building nightly deb package...
if dpkg-buildpackage -rfakeroot -i -us -uc ; then
echo //////////////////////////////////////////////////////////////
echo // Please run "sudo dpkg -i ./wqy_temp/xfonts-wqy_"$NBVER"_all.deb"
echo // Thanks for testing!
else
echo // Found error
exit 1
fi

exit 0

* . 给脚本增加运行权限

chmod +x build_wqy_for_ubuntu.sh

* . 安装脚本运行环境

# apt-get build-dep xfonts-wqy
# apt-get install dpkg-dev fakeroot

* . 运行脚本,将生成wqy的deb安装包

./build_wqy_for_ubuntu.sh

* . 安装wqy

# dpkg -i ./wqy_temp/*.deb

====
CJK Unified Ideograph (U4E00 - U9FA5)
CJK Unified Ideograph Extension A (U3400 - U4DB5)
glyph

sizes (9pt-12x12 pixel, 10pt-13x13 pixel, 11pt-15x15 pixel, 12pt-16x16 pixel)
weights (medium and bold).

"blurring" problems caused by the high stroke density of many Chinese characters
insufficient "hinting" of anti-aliased Chinese fonts.

This font also provides bitmap glyphs for Basic Latin, Japanese Hiragana (U3040 - U309F) and Katakana (U30A0 - U30FF).

====
Sans-Serif style,
 also known as Hei, Gothic or Dotum among the Chinese/Japanese/Korean users
====

"Micro Hei" and "Micro Hei Mono", in form of a True-Type Collection (ttc) file.

All the unified CJK Han glyphs, i.e.  GBK Hanzi, in the range of U+4E00-U+9FC3 defined in Unicode Standard 5.1 are covered,
with additional support to many other international languages such as Latin, Extended Latin, Hanguls and Kanas.

both font faces carry hinting and kerning instructions for Latin glyphs,
====
文泉驿点阵宋体包含了所有常用简体中文、繁体中文，日文及韩文所需要的汉字(最新版本包含超过27842个汉字，完整覆盖GB2312/Big5/GBK /GB18030标准字符集)。该字体同时还包含了英文、日文、韩文和其他多种语言符号。该点阵字体包含四个屏幕常用字号(9pt-12pt)，逾11万汉字点阵，这些点阵都经过参与者和组织者的精心设计和调整，手工优化后的汉字点阵显示清晰锐利，特别易于屏幕阅读使用。

文泉驿正黑体 嵌入了所有GBK汉字点阵，在9-12pt范围内，将自动使用点阵宋体显示。
====

内含dejavusansyuanti, dejavusansyuanticondensed, dejavusansyuantimono三种字体族。个人推荐condensed作为日常使用，其英文占地少，但仍然很清晰。

====

# 字体合并脚本 1.0 merge.pe
# zhuqin <zhuqin83@gmail.com>
# 请先安装好fontforge，并将所需合并的两个字体放在本脚本的同一目录下。
# 然后按需要修改本脚本的各项参数，如字体名等。
# 最后运行 fontforge -script merge.pe
# 脚本的修改请参照 http://fontforge.sourceforge.net/scripting.html

# 中文字体
Open("VeraSansYuanTi-Italic.ttf")
SelectAll()
#ScaleToEm(2048)
Generate("temp.ttf")
Close()

# 非中文字体，如英文等。
Open("DejaVuSans-Oblique.ttf")
SelectAll()
#ScaleToEm(2048)

MergeFonts("temp.ttf")
SetFontNames("DejaVuSansYuanTi-Oblique", "DejaVu Sans YuanTi", "DejaVu Sans YuanTi Oblique", "Oblique", "Copyleft 2008")
Generate("DejaVuSansYuanTi-Oblique.ttf")
Close()

====

# cp /etc/fonts/fonts.conf.old /etc/fonts/fonts.conf
# gedit /etc/fonts/language-selector.conf

添加圆体字为首选项
（参考配置）
引用
<fontconfig>

<alias>

<family>serif</family>

<prefer>

<family>Bitstream Vera Serif</family>
<family>Vera Sans YuanTi Mono</family>

<family>DejaVu Serif</family>

<family>AR PL ShanHeiSun Uni</family>

<family>WenQuanYi Bitmap Song</family>

<family>AR PL ZenKai Uni</family>

</prefer>

</alias>

<alias>

<family>sans-serif</family>

<prefer>

<family>Bitstream Vera Sans</family>
<family>Vera Sans YuanTi Mono</family>
<family>Vera Sans YuanTi Mono</family>

<family>DejaVu Sans</family>

<family>AR PL ShanHeiSun Uni</family>

<family>WenQuanYi Bitmap Song</family>

<family>AR PL ZenKai Uni</family>

</prefer>

</alias>

<alias>

<family>monospace</family>

<prefer>

<family>Bitstream Vera Sans Mono</family>
<family>Vera Sans YuanTi Mono</family>

<family>DejaVu Sans Mono</family>

<family>AR PL ShanHeiSun Uni</family>

<family>WenQuanYi Bitmap Song</family>

<family>AR PL ZenKai Uni</family>

</prefer>

</alias>

<match target="font" >

<test name="family" compare="contains" >

<string>Song</string>

<string>Sun</string>

<string>Kai</string>

<string>Ming</string>

</test>

<test compare="more_eq" target="pattern" name="weight" >

<int>180</int>

</test>

<edit mode="assign" name="embolden" >

<bool>true</bool>

</edit>

</match>

<match target="font" >

<test name="family" compare="contains" >

<string>Song</string>

<string>Sun</string>

<string>Kai</string>

<string>Ming</string>

</test>

<edit name="globaladvance">

<bool>false</bool>

</edit>

<edit name="spacing">

<int>0</int>

</edit>

<edit name="hinting">

<bool>true</bool>

</edit>

<edit name="autohint">

<bool>false</bool>

</edit>

<edit name="antialias" mode="assign">

<bool>true</bool>

</edit>

<test name="pixelsize" compare="less_eq">

<int>18</int>

</test>

<edit name="antialias" mode="assign" >

<bool>false</bool>

</edit>

</match>

</fontconfig>

重启X
这下正常了
进入 X 后，在字体设置里选择 Vera Sans YuanTi，大小为 xx 即可
如果你想要类似 mac OS X 的那种粗粗黑黑的效果就编辑 /etc/fonts/fonts.conf
把以下内容加入（</FONTCONFIG> 前面）
代码
<match target="font">
<test name="family"><string>Vera Sans YuanTi</string></test>
<edit name="globaladvance"><bool>false</bool></edit>
</match>

<match target="font">
<test name="family"><string>Vera Sans YuanTi Mono</string></test>
<edit name="globaladvance"><bool>false</bool></edit>
</match>

<match target="font">
<edit name="antialias"><bool>true</bool></edit>
<edit name="hinting"><bool>false</bool></edit>
<edit name="autohint"><bool>false</bool></edit>
</match>

如果你想要类似 windows 的那种清晰细腻的的效果就编辑 /etc/fonts/fonts.conf
把以下内容加入（</FONTCONFIG> 前面）
代码
<match target="font">
<test name="family"><string>Vera Sans YuanTi</string></test>
<edit name="globaladvance"><bool>false</bool></edit>
</match>

<match target="font">
<test name="family"><string>Vera Sans YuanTi Mono</string></test>
<edit name="globaladvance"><bool>false</bool></edit>
</match>

<match target="font">
<edit name="antialias"><bool>true</bool></edit>
<edit name="hinting"><bool>false</bool></edit>
<edit name="autohint"><bool>false</bool></edit>
</match>

<match target="font">
<test name="pixelsize" compare="more_eq"><double>12</double></test>
<test name="pixelsize" compare="less_eq"><double>16</double></test>
<edit name="antialias"><bool>false</bool></edit>
<edit name="hinting"><bool>true</bool></edit>
<edit name="autohint"><bool>false</bool></edit>
</match>


====

问题的缘由是: 我想使用英文字体显示英文, 中文字体只应用在中文.

局部的意思是:
1. fluxbox控制的字体部分, 例如窗口标题
2. conky显示的字体, 例如mpd的播放信息
3. flash部分字体显示为空白

不好的解决办法: 全部使用中文字体
理想的解决办法: 使用~/.fonts.conf设置字体替换解决
暴力的解决办法: 使用fontforge合成字体

其中暴力的办法应该能根本解决问题, 但是在此之前最好再给理想一个机会.

下面要提及的几个字体:
代码:

$ fc-list | egrep 'FZ|ITC|Parisine' Vintage ITC:style=Regular Parisine:style=Italic ParisineClair:style=Italic Parisine:style=Regular ParisineClair:style=BoldItalic ParisineClair:style=Bold ParisineClair:style=Regular Parisine:style=Bold FZLiBian\-S02,方正隶变_GBK:style=Regular Parisine:style=BoldItalic Parisine:style=BoldAlternate Parisine:style=BoldItalicAlternate

另外我的 locale 是 "en_US.utf8"

我目前的设置如下, 大家看看有哪里没有照顾到的.

1. fonts.conf
我没有在/etc/fonts下做任何设置, 只是在~/.fonts.conf里面加入所有需要的设置

代码:



<?xml version="1.0"?>
<!DOCTYPE fontconfig SYSTEM "fonts.dtd">

<fontconfig>

 <match target="font" >
    <edit mode="assign" name="rgba" >
     <const>none</const>
    </edit>
 </match>
 <match target="font" >
    <edit mode="assign" name="hinting">
     <bool>true</bool>
    </edit>
 </match>
 <match target="font" >
    <edit mode="assign" name="hintstyle">
     <const>hintfull</const>
    </edit>
 </match>

 <match target="font" >
    <edit mode="assign" name="antialias">
     <bool>true</bool>
    </edit>
 </match>

<!-- Autohinter is not turned on automatically.
 Only disable this if you have recompiled Freetype with the bytecode interpreter,
 which is run automatically.<br />  -->
 <match target="pattern" >
    <edit mode="assign" name="autohint">
     <bool>true</bool>
    </edit>
 </match>
 <match target="font">
         <test name="weight" compare="more">
                 <const>medium</const>
         </test>
         <edit name="autohint" mode="assign">
                 <bool>false</bool>
         </edit>
 </match>

<!--让字体引擎(FreeType)取消CJK字体的指定宽度-->
 <match target="font">
                <test target="pattern" name="lang" compare="contains">
                        <string>zh</string>
                        <string>ja</string>
                        <string>ko</string>
                </test>
                <edit name="spacing">
                        <const>proportional</const>
                </edit>
                <edit name="globaladvance">
                        <bool>false</bool>
                </edit>
 </match>

<!--设定当默认字体不存在时,用以下字体替换-->
<alias>
 <family>serif</family>
  <prefer>
   <family>Bitstream Vera Serif</family>
   <family>DejaVu Serif</family>
   <family>方正隶变_GBK</family>
   <family>DejaVu Sans YuanTi</family>
  </prefer>
</alias>
<alias>
 <family>sans-serif</family>
  <prefer>
   <family>DejaVu Sans</family>
   <family>Bitstream Vera Sans</family>
   <family>方正隶变_GBK</family>
   <family>DejaVu Sans YuanTi</family>
  </prefer>
</alias>
<alias>
 <family>monospace</family>
  <prefer>
   <family>DejaVu Sans Mono</family>
   <family>Bitstream Vera Sans Mono</family>
   <family>方正隶变_GBK</family>
   <family>DejaVu Sans YuanTi</family>
  </prefer>
</alias>
<alias>
 <family>Parisine</family>
  <prefer>
   <family>DejaVu Sans Mono</family>
   <family>Bitstream Vera Sans Mono</family>
   <family>方正隶变_GBK</family>
   <family>DejaVu Sans YuanTi</family>
  </prefer>
</alias>
<alias>
 <family>Vintage ITC</family>
  <prefer>
   <family>DejaVu Sans Mono</family>
   <family>Bitstream Vera Sans Mono</family>
   <family>方正隶变_GBK</family>
   <family>DejaVu Sans YuanTi</family>
  </prefer>
</alias>

<dir>~/.fonts</dir>

</fontconfig>


<!--设定当默认字体不存在时,用以下字体替换-->后面的alias部分就是对字体替换顺序的设置, 我试过在方正隶变_GBK前面加SimSum一行, 重新打开pcmanfm可以看到中文字体按照设置更换了. 也就是说, 这个设置方法可以在gtk程序中生效了.
[照理对Parisine和Vintage ITC字体的alias设置应该是没有必要的, serif, sans-serif, monospace应该包含所有字体了, 不过我不晓得啦...以防万一]

我的~/.gtkrc-2.0

代码:

include "/usr/share/themes/Mist/gtk-2.0/gtkrc" style "user-font" { font_name = "ParisineClair Bold 10" } widget_class "*" style "user-font" gtk-font-name="ParisineClair Bold 10"

2. ~/.fluxbox/overlay

代码:

menu.title.font: Mercury-12 menu.frame.font: TheSans-12 window.font: ParisineClair-10:bold toolbar.iconbar.focused.font: Mercury-8:bold toolbar.iconbar.unfocused.font: Mercury-8 toolbar.clock.font: Terminus-10:bold toolbar.workspace.font: Vintage ITC-10:bold

这个设置确实可以取代flux主题的字体设置, reload config后在窗口标题栏中立即生效, 但是中文字体是不显示的, 例如现在firefox的标题栏, 显示成
引用:
LinuxSir.Org - 五个小空格 - Mozilla Firefox
对,中文不是框框, 而是空白(linuxsir的多个连续空格总是被处理成一个...所以只好写字占位)
也试过 window.font: ParisineClair-10:bold|方正隶变_GBK-10, 一样没效果.
这让我觉得可能fluxbox读字体的方式不遵循~/.fonts.conf的规则?
但是就一个不行还勉强接受, 但是conky也不行, 就很可疑了~

3. ~/.conkyrc
有关字体设置的就两行
代码:

use_xft yes xftfont Vintage ITC:size=9:bold

对, 就一个英文字体 Vintage ITC, 这个字体本身显示的好好的, 但是候补中文字体却没有露脸的机会. 情况同fluxbox的窗口标题, 中文显示为空白. 但是你从前面可以看到, 我的~/fonts.conf已经对 Vintage ITC 进行过字体替换设置了.

====
文泉驿字体与GB18030没有直接的关系.

如上所述, GB18030是一个编码的强制性国家标准. 这个标准规定了Unicode所收录的符号的一种与GBK/GB2312编码兼容的编码形式(也就是说某个unicode符号对应的编码值是多少.). 对GB18030的支持是通过一个unicode<->gb18030编码映射表实现的. 也就是说, Linux之后中只要locale信息中包含了这个映射表, 并且glibc中定义了相应的编码registry之后,gb18030标准的支持已经实现, 与系统上使用的字体没有关系 (微软Windows GB18030补丁中真正起作用的也只是一个编码转换表和转换函数, 以及GB18030的系统registry,与附带的字体没有直接关系).

文泉驿字体与其他大多数国际通用字体一样, 使用ISO10646编码(unicode)作为字体内部编码, 字体内部编码与操作系统支持的语言编码没有直接的关系. 直接采用GB18030作为字体编码的通用字体也非常少见.

另外,GB18030对应的字符集是全部Unicode符号, 即包括CJK Basic, CJK扩展A区和B区的所有汉字以及非汉字符号. GB18030并没有对字体对该字符集覆盖的完备性上做任何规定. 事实上, 不可能也完全没有必要要求字体必须全部覆盖GB18030字符集. 据本人所知, 迄今还尚未有完全覆盖GB18030字符集的字体.

我们在一些文档中提到文泉驿字体将支持GB18030字符集的说法只是一种简化的说法, 并不准确. 这里的"GB18030字符集"只是CJK Basic+CJK ExtA的一个替换称呼, 与真正的GB18030字符集不同.




====
    FILE *fin, *fout;
    char *encFrom, *encTo;
    char bufin[1024], bufout[1024], *sin, *sout;
    int mode, lenin, lenout, ret, nline;
    iconv_t c_pt;
    encFrom = "utf-8";
    encTo   = "gbk";
    if ((c_pt = iconv_open(encTo, encFrom)) == (iconv_t)-1) {
        printf("iconv_open false: %s ==> %s\n", encFrom, encTo);
        return -1;
    }
    iconv(c_pt, NULL, NULL, NULL, NULL);
    strcpy(bufin,"姝ｅ父");
    lenin  = strlen(bufin) + 1;
    lenout = 1024;
    sin    = bufin;
    sout   = bufout;
    iconv(c_pt,
                &sin,
                (size_t*)&lenin,
                &sout,
                (size_t*)&lenout);
    printf("%s -> %s: ret=%d, len_in=%d, len_out=%d\n",
            encFrom, encTo, ret, lenin, lenout);
    iconv_close(c_pt);
    printf("out= %s\n",&sout);

更详细的用法请man 3 iconv


====
perl程序中如何转换GB2312/GBK/GB18030编码为utf-8编码？如何反向转换？
=====作者： Yourway 答：从Perl5.8开始，可以使用Encode模块来完成这个操作。 use Encode;

$str_ust8 = encode("utf-8",decode("gbk",$str_gbk)); $str_gbk = encode("gbk", decode('utf-8',$str_utf8));
====
 mount -t ntfs -o iocharset=utf8 /dev/hdxx /path/to/mount_point
====
 mount -o iocharset=utf8 /dev/hdxx /path/to/mount_point
 mount -o utf8 /dev/hdxx /path/to/mount_point

====
the Kana glyphs change but the Kanji remain the same.

====

--
7月13日 dota。
7月14日 dota。
7月15日 dota。
7月16日 贾君鹏啊贾君鹏！你怎么能如此堕落！先前订下的学习计划你都忘了吗？子曰：“吾日三省吾身。”…不能再这样下去了！
7月17日 dota。
7月18日 dota。



【 在 thepro (All Things Bright and Beautiful) 的大作中提到: 】
: 他那个当然复杂了，因为要做很专业的字体，玩的话，应该只要每个编码对应1个字即可，最小的gb编码不到7k个应该不难
: 没玩过，觉得有个手写板更好
--
4. 开始怀念无忧无虑的生活，有快乐，有忧伤，但是没有烦恼。

<http://lifesinger.github.com/lab/2011/default-fonts/>

* lang, charset 和 font-family 都会对默认字体产生影响。
* 浏览器偏好里的字体设置，对默认字体有直接影响。
* 宋体转成 “\5b8b\4f53” 也不能通吃所有浏览器。比如在 Mac OS 的 Chrome 中，只认识 simsun.
* <del>宋体其实是 serif 有衬线字体，后面跟 sans-serif, 逻辑上是错的。</del>
  （修正：并没有规定前面的 font name 要和最后的 general family 保持一致）
* 不同操作系统下，各个浏览器默认的 sans-serif 中文字体，一般都是最佳选择或用户已调整为最佳，不能强制用户都用宋体。

从目前用户反馈的情况来看，在以 12px 大小为主的网页设计中，**最佳的中文默认字体方案是：Windows 下用宋体，其他操作系统下用雅黑等无衬线字体**。未来随着电脑屏幕的变大和分辨率的提高，当字体的默认大小提高到 14px 以上时，或许所有操作系统下，最佳中文默认字体会统一为雅黑等无衬线字体。

为了让所有网页在尽可能多的情况下，都用最佳中文字体渲染，需要特别考虑以下几点：

* 在 Mac Chrome 等环境下，用 font-family: times, sans-serif 时，
  中文字体并不会根据 sans-serif 渲染，而是会根据 times 的 serif 属性，
  选择默认的 serif 中文字体来渲染。
  比如在 Mac Chrome 下，默认 serif 中文字体是很接近宋体的一个字体，比较难看。
  （修正：实际情况更为复杂，请参考评论中的讨论）
* 在 Firefox 中，只要 font-family 中有宋体，中文必然就用宋体展现。
  所以 font-family 中不能有宋体。
* 当 lang=“zh-CN”, charset=“utf-8” 时，
  font: arial 在 Mac Firefox 等环境下，默认中文字体是宋体。
* 在英文 Win7 下，只要 charset=“gbk”, 当 font-family 为 arial, sans-serif 时，
  <del>默认中文字体是很难看的 Microsoft Sans Serif Regular.</del>
  （修正：是 fallback 到了韩文字体 Dotum/Gulim（gulim.ttc）来显示，
  Dotum/Gulim 没有的字符最终会 fallback 到 SimSun，暂时不知道日文字体是否夹在中间。
  和 Microsoft Sans Serif 没有一点关系。）
* Opera 是个恐怖的世界，不要尝试分析其规律，最后测试一下就好。

可以总结出：

1. 如果页面 charset 是 utf-8, 完美的默认字体方案是：

	```css
	font-family: arial, sans-serif;
	```

  无论省略 lang 还是设置为 zh-CN, 在各种环境下都满足预期。

2. 如果页面 charset 是 gbk, 推荐默认字体方案为：

	```css
	font-family: arial;
	```

  Chrome OS 下未测试，根据陈成博客上的反馈，
  好像会因为没有 sans-serif 而导致中文字体很难看。
  不过考虑 Chrome OS 还未正式发布，目前可以先忽略。

最后，个人推荐简体中文页面的最佳实践为：

    html lang=zh-CN
    charset=utf-8
    font-family: arial, sans-serif;

测试环境说明：

    Mac OS X 10.6.7
    Chrome 10.0.648.204
    Firefox 4.0
    Safari 5.0.4
    Opera 11.01

    Win7 Ultimate
    IE 9.0.8080.16413

补充：

1. 关于字体的默认大小和行高等信息，推荐博文：[默认 Web 字体样式][1]
2. 关于字体的 fallback 等文本渲染信息，推荐博文：[浏览器如何渲染文本][2]

[1]: http://justjavac.com/web/2012/04/13/default-web-font-style.html
[2]: http://justjavac.com/web/2012/04/13/how-do-browsers-render-text.html


----

## font family

- 无衬线字体
  - Albany
  - Arial -- Microsoft
  - Bitstream Vera Sans
  - Helvetica
  - Nimbus Sans L
- 衬线字体
  - Bitstream Vera Serif
  - Nimbus Roman
  - Thorndale
  - Times New Roman -- Microsoft
- 等宽字体
  - Courier
  - Courier New -- Microsoft
  - Cumberland
  - Bitstream Vera Sans Mono
  - Nimbus Mono L

[[1](http://www.press.redhat.com/2007/05/09/liberation-fonts/)]
[[2](https://www.redhat.com/promo/fonts/)]。

----
参考自 [Wiki](http://en.wikipedia.org/wiki/Luxi\_(fonts))

{ [Source](http://kwanlife.yo2.cn/articles/luxi.html). Thanks Yunkwan. }
----
[github](http://github.com/trapd00r/pickyfont)
----

Title: 解决英文环境 Opera 中文字体问题
Date: 2009-10-18 09:12
Author: Yunkwan
Category: Tips
Tags: Opera
Slug: opera-chinese-font

{ 撰文/[Yunkwan](http://kwanlife.yo2.cn) }

这是我遇到的问题，具体情况

[ClickHere](http://forum.ubuntu.org.cn/viewtopic.php?f=73&t=232306)，看看截图。这问题缠绕我几天了~
今天 @Thruth 在 Gtalk 技术支持~ 终于解决问题~

**解决方法:**

修改 /usr/share/opera/defaults/font.ini

找到 `; Chinese fonts` 这项，然后把字体改为你要的中文字体。

family:WenQuanYi Micro Hei=chinese-s excellent try-first  
 (只需要修改这个)

下面这两行都在开头，加 ";" 来注释掉

;family:WenQuanYi Zen Hei=chinese-s verygood try-first
;family:文鼎ＰＬ简报宋|AR PL UMing*|AR PL SungtiL GB=chinese-s good
try-first

然后，还有一件必需要做的事!!!就是把下面的日文、韩文都用" ; "注释掉。

;Japanese fonts
;family:IPA*=japanese excellent try-first
;family:kochi*=japanese good try-first
;family:VL*=japanese verygood try-first
;Korean fonts
;family:baekmuk gulim|undotum=korean sans-serif excellent try-first
;family:baekmuk batang|unbatang=korean serif verygood
;family:baekmuk dotum=korean sans-serif good
;family:ungungseo|unshinmun=korean serif good
;family:baekmuk*|un*=korean

然后，保存，重启 Opera 就可以了。

**现象的原因:**

Opera 把中文用韩日字体显示出来，那么字体当然会怪怪的喇~ Opera
本身的缺憾是分不出中日韩字体，所以，如果没有注释掉韩日字体，
即便你设置好了中文字体，字体奇怪的问题也会照样出现。

我 Google 了一下，没有什么人在 Opera 9
以后，遇到中文字体的问题，是因为，Opera
默认是能够使用系统的中文字体。

但为什么我却会遇到这个问题呢? 原因说不清，但可能性有以下几个:

1. 英文环境

2. 系统默认字体使用英文字体。

3. 系统默认字体为 Sans，然后，通过 ~/.fonts.conf
来调配字体使用的优先级~
首选是纯英文字体，次选才是中文字体

再次感谢 @Thruth。

{ [Source](http://kwanlife.yo2.cn/articles/operachinesefont.html).
Thanks
Yunkwan. }
----
Via: TruFont|http://trufont.github.io/

要是以前在 Linux 下编辑字体，我通常会使用 [FontForge][f]，而现在则有了新的选择——TruFont。TruFont 是开源的 ufo3 字体编辑器，它支持 .otf、.ttf、.ttx、.pfa、.pfb、.woff 等字体格式。

[![trufont]({filename}/images/trufont.thumb.png)]({filename}/images/trufont.png)

TruFont 能够在 Linux、Mac OS X、以及 Windows 上运行。Linux 用户只要下载其提供的 zip 包即可安装：

    unzip TruFont.zip
    ./TruFont

[f]: http://fontforge.github.io/
----

## Adobe 开源字体
- 思源黑体
- 思源宋体
- Source Code Pro

从 Adobe 的 Github 的页面上可以下载到 Source Han Sans 专用的 CMap 文件，如简体中文是 UniSourceHanSansCN-UTF32-H。直接拿它给 dvipdfmx 用是不成的，因为 dvipdfmx 要求输入的是 UTF-16 编码的 CMap 文件。其实只要把原来 UTF-32 的 CMap 文件中所有 <数字> 从 UTF-32BE 改为 UTF-16BE 编码即可，因此可以写一个糙快猛的脚本完成这一转换。单纯为了手头方便我是用一两条 VIM 替换命令做的，这条是处理大于 0xFFFF 的部分：

    :%s@<\x\{8}>@printf("<%08x>", (str2nr(submatch(1),16)-0x10000)/0x400*0x10000 + 0xD8000000 + (str2nr(submatch(1),16)-0x10000)%0x400 + 0xDC00)@g


发信站: BBS 科苑星空站 (Mon Nov 30 14:21:08 2009), 站内
【 在 thepro (All Things Bright and Beautiful) 的大作中提到: 】
: 哦，补充一个，由于win字体render设计的原因，其系统无法正常使用文泉字体（常用字号部分）

## Issues
Ariel 字体的小写 l 与大写 I 区分度低，r 和 n 相邻的时候与 m 很相似。

Helvetica也是如此。

Courier的数字 1 和小写 l 分不清。

Apple Color Emoji 的数字宽度过大，数字 0 和大写 O 不易区分。

Monaco的单引号和双引号也容易区分。

http://en.wikipedia.org/wiki/Liberation_fonts

如果你安裝的是類似於Arial Unicode MS這種多語系集成版本的話，
第一預設語言多半是日語，所以、也會這樣。
請下載散裝語系的OTF版本、或者OTC版本。

# INPUT

Input is a font family designed for computer programming, data, and text composition. It was designed by David Jonathan Ross between 2012 and 2014. It contains a mulititude of styles so you can select what works best for you and fine-tune your coding environment. It includes Sans, Serif, and Monospaced families, each with four widths, seven weights, and italics. It also includes inputCustomize.py, a command line tool that you can use to further customize the fonts.

You can find more information about the fonts, as well as some examples of them in use, at <http://input.fontbureau.com>.

The entire Input font family is freely available for use on your own computer in plaintext and code. You must purchase inexpensive publishing licenses to use Input in print, on the web, or in any publishing context. Read the enclosed LICENSE.txt for more information, or learn more here: <http://input.fontbureau.com/download>

## FAMILIES

Input Mono is a monospaced typeface, where all characters occupy a fixed width. Input Sans and Serif are proportional typefaces that are designed with all of the features of a good monospace — generous spacing, large punctuation, and easily distinguishable characters — but without the limitations of a fixed width.

## WIDTHS

Input comes in four widths: Normal, Narrow, Condensed, and Compressed.

I generally tend towards the wider widths, though the narrower widths can be handy if you use a smaller screen, have multiple files side-by-side, or if your code tends to have many characters per line.

Input Mono Narrow approximates the copyfit of a 10-pitch font, and can be used as an alternative to Courier at the same size.

## WEIGHTS

Input comes in seven weights: Thin, Extra Light, Light, Regular, Medium, Bold, Black.

The Light and Medium weights were designed to be only slightly lighter than Regular and Bold, so that they can appear to be a similar weight when used with light text on a dark background. However, on some operating systems (like Mac OS), a dark background color can cause such significant haloing that the Extra Light or Thin weights may be a better approximation.

In Input’s proportional styles, the Thin, Extra Light, Light, and Regular weights all share the same setwidths, as do the Medium and Bold.

## ITALICS

Input’s Italics are always drawn on the same widths as the correspoding upright style. Input Serif’s Italics have an alternative serif arrangement, which makes them especially distinctive and useful when setting apart blocks of text.

## SIZE

These fonts are primarily intended for small sizes in subpixel-rendered environments. The design’s target size is 11px, but the core weights (Light, Regular, Medium, and Bold) can go anywhere from 9px to 16px, and are manually hinted to improve performance at small sizes across operating systems. The extreme weights (Thin, Extra Light, and Black) styles are intended for 16px+. For use at display sizes, I recommend applying negative tracking and reducing the wordspace.

## COMBINING STYLES

Input’s styles are designed to mix and match, so you can  I can’t predict which styles will work best for you in which combinations, which is why I offer them all. There are plenty of ways that you can mix and match these styles. I have been experimenting with setting my code as follows:

	- Sans for keywords, variables, and text
	- Serif for strings, tags, and values
	- Mono for working in a Terminal, or while editing code that uses wordspaces/tabs for alignment
	- Bold for class and function definitions
	- Italic for comments, special words (like ‘this’ or ‘self’), and secondary languages (like CSS within an HTML document)

## ALTERNATES

Input allows you to use OpenType features or a command-line interface to select your preferred form of easily confusable characters:

	* Stylistic Set 01: Schoolbook a
	* Stylistic Set 02: Schoolbook g

	* Stylistic Set 03: i with top serif (Sans and Mono only)
	* Stylistic Set 04: l with top serif (Sans and Mono only)

	* Stylistic Set 05: i with top and bottom serif (Sans and Mono only)
	* Stylistic Set 06: l with top and bottom serif (Sans and Mono only)

	* Stylistic Set 07: i with full serif (Sans only)
	* Stylistic Set 08: l with full serif (Sans only)

	* Stylistic Set 09: i with top serif and tail (Sans and Mono only)
	* Stylistic Set 10: l with top serif and tail (Sans and Mono only)

	* Stylistic Set 11: Mid-height asterisk
	* Slashed Zero

Here are some examples of how you can customize Input to mimic the arrangement of these characters in common fonts:

	* Monaco
		* OpenType features: ss01, ss02, ss05, ss06, zero
		* inputCustomize.py: --a=ss --g=ss --i=serifs --l=serifs --zero=slash
	* Menlo
		* OpenType features: ss02, ss07, ss10, ss11, zero
		* inputCustomize.py: --g=ss --i=serif --l=serifs_round --asterisk=height --zero=slash
	* Andale Mono
		* OpenType features: ss03, ss06
		* inputCustomize.py: --i=topserif --l=serifs
	* Consolas
		* OpenType features: ss07, ss08, zero
		* inputCustomize.py: --i=serif --l=serif --zero=slash
	* Source Code Pro:
		* OpenType features: ss03, ss10
		* inputCustomize.py: --i=topserif --l=serifs_round --asterisk=height

## CUSTOMIZATION

inputCustomize.py is a command-line python script that allows you to easily make adjustments to your fonts. It requires TTX/FontTools <http://sourceforge.net/projects/fonttools/>.

My hope is that Input will encourage developers of source code editors to include better typographic support, so that these issues don’t need to be addressed in such a hacky way.

### Alternates

Since most coding applications don’t offer support of OpenType features, this tool will swap out default glyphs for their alternate forms. See description of the alternates above.

### Hack for line-spacing

Since many coding applications don’t include the option to adjust line-spacing, you can modify the built-in linespacing of the fonts.

### Hack for four-style families

Since most coding applications don’t allow you to use more than one four-style family, Input allows you to assemble arbitrary four-style families. I use this in order to combine Sans and Serif, by slotting InputSerif–Regular into the Bold Italic position.

Input Sans Hack
	Regular: Input Sans Regular
	Italic: Input Sans Italic
	Bold: Input Sans Bold
	Bold Italic: Input Serif Regular

### Examples

You can use inputCustomize.py like this to work on all fonts in the current working directory:

	$ cd /path/to/the/fonts/you/want/to/edit
	$ python /path/to/inputCustomize.py --dest=/path/to/output  --lineHeight=1.5 --fourStyleFamily --a --g --i=topserif --l=serifs_round --zero --asterisk

Or like this, to create a family out of any four styles:

	$ python /path/to/inputCustomize.py InputSans-Regular.ttf InputSans-Italic.ttf InputSans-Bold.ttf InputSerif-Regular.ttf --suffix=Hack --fourStyleFamily --a

For more details, see the script’s help:

	$ python /path/to/inputCustomize.py -h

## xset

```
$ xset q
Keyboard Control:
  auto repeat:  on    key click percent:  0    LED mask:  00000000
  XKB indicators:
    00: Caps Lock:   off    01: Num Lock:    off    02: Scroll Lock: off
    03: Compose:     off    04: Kana:        off    05: Sleep:       off
    06: Suspend:     off    07: Mute:        off    08: Misc:        off
    09: Mail:        off    10: Charging:    off    11: Shift Lock:  off
    12: Group 2:     off    13: Mouse Keys:  off
  auto repeat delay:  500    repeat rate:  33
  auto repeating keys:  00ffffffdffffbbf
                        fadfffefffedffff
                        9fffffffffffffff
                        fff7ffffffffffff
  bell percent:  50    bell pitch:  400    bell duration:  100
Pointer Control:
  acceleration:  2/1    threshold:  4
Screen Saver:
  prefer blanking:  yes    allow exposures:  yes
  timeout:  0    cycle:  0
Colors:
  default colormap:  0x3c    BlackPixel:  0x0    WhitePixel:  0xffffff
Font Path:
  /usr/share/fonts/TTF,/usr/share/fonts/OTF,built-ins
DPMS (Energy Star):
  Server does not have the DPMS Extension
```

## Variable Font

This means all the styles are contained in a single file:
  ReadexPro-VariableFont_wght.ttf

If your app fully supports variable fonts, you can now pick intermediate styles
that aren’t available as static fonts. Not all apps support variable fonts, and
in those cases you can use the static font files for Readex Pro:
  static/ReadexPro-ExtraLight.ttf
  static/ReadexPro-Light.ttf
  static/ReadexPro-Regular.ttf
  static/ReadexPro-Medium.ttf
  static/ReadexPro-SemiBold.ttf
  static/ReadexPro-Bold.ttf

Get started
-----------

1. Install the font files you want to use

2. Use your app's font picker to view the font family and all the
available styles

Learn more about variable fonts
-------------------------------

  https://developers.google.com/web/fundamentals/design-and-ux/typography/variable-fonts
  https://variablefonts.typenetwork.com
  https://medium.com/variable-fonts

In desktop apps

  https://theblog.adobe.com/can-variable-fonts-illustrator-cc
  https://helpx.adobe.com/nz/photoshop/using/fonts.html#variable_fonts

Online

  https://developers.google.com/fonts/docs/getting_started
  https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Fonts/Variable_Fonts_Guide
  https://developer.microsoft.com/en-us/microsoft-edge/testdrive/demos/variable-fonts

Installing fonts

  MacOS: https://support.apple.com/en-us/HT201749
  Linux: https://www.google.com/search?q=how+to+install+a+font+on+gnu%2Blinux
  Windows: https://support.microsoft.com/en-us/help/314960/how-to-install-or-remove-a-font-in-windows

Android Apps

- https://developers.google.com/fonts/docs/android
- https://developer.android.com/guide/topics/ui/look-and-feel/downloadable-fonts

## Coding fonts

+ Fira Code
+ Source Code Pro
+ Inconsolata-g
+ Anonymous Pro
+ M+ 1m
+ Iosevka
+ Envy Code R

## Malgun Gothic

Malgun Gothic 是一款適用於螢幕顯示的韓文黑體，由Sandoll Communications開發。其名稱“맑은”有“清晰、澄澈”之意

## Myungjo font

    동해물과 백두산이 마르고
    닳도록 하느님이 보우하사
    天地玄黃宇宙洪荒日月盈仄
    ㉠⒝⑶❹あア※♥♪⅜‘”

## Yuppy

壹貳參肆伍陸柒捌玖拾
一二三四五六七八九十卄卅
ㄅㄆㄇㄈㄉㄊㄋㄌㄍㄎㄏㄐ
ㄑㄒㄓㄔㄕㄖㄗㄘㄙㄚㄛ
ㄜㄝㄞㄟㄠㄡㄢㄣㄤㄥㄦㄧㄨㄩ
兙兛兞兝兡兣嗧瓩糎

## YuMincho

あのイーハトーヴォの
すきとおった風、
夏でも底に冷たさをもつ青いそら、
うつくしい森で飾られたモリーオ市、
郊外のぎらぎらひかる草の波。
祇辻飴葛蛸鯖鰯噌庖箸

那段童话里，吹动我心意的风，
即使这夏天感受到惬意的蓝天，
被森林拥抱的莫丽尔市，
还有郊外不断闪耀发光的草的波浪。

Tsukushi

## Comic sans

Gill sans
Hiragino Mincho
Hiragino Sans
Palatino

## Symbol

(  ) / [ \  ] _ {  } ˆ ˇ ˜ ˷
̌ ̰ ̲ ̸ ‾ ⃐ ⃑ ⃖ ⃗ ⃬ ⃭ ⃮ ⃯ √ ∛ ∜
⌈ ⌉ ⌊ ⌋ ⎴ ⎵ ⏜ ⏝ ⏞ ⏟ ⏠ ⏡ ❲ ❳ ⟦ ⟧
⟨ ⟩ ⟪ ⟫ ⦃ ⦄ ⦅ ⦆ ⫼ ⫿

A Á Â B C D E É È Ê Ë F
G H I Î Ï J K L M N O Ô
Ö P Q R S T U Û V W X Y
Z
a  â b c d e é è ê ë f
g h i
 j k l m n o ô
 ö p q r s t u û v w x y
 z

∫ ∬ ∭ ∮ ∯ ∰ ∱ ∲ ∳ ⨋ ⨌ ⨍ ⨎ ⨏ ⨐ ⨑
⨒ ⨓ ⨔ ⨕ ⨖ ⨗ ⨘ ⨙ ⨚ ⨛ ⨜

