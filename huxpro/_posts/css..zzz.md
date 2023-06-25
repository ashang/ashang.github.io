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


