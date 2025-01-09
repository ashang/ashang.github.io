---
layout: page
title: About CSS
permalink: /css/
tags: css
---

### 样式表的优先级

- 标签内样式：`<p style="text-align: center; color: red"> </p>`

- 内部样式：`<style type="text/css"> CSS代码 </style>`

- 外部样式（`rel`属性）：
`<link rel="stylesheet" type="text/css" href="test.css">`

- 浏览器默认规则

### `CSS`基本组成

`选择器`、`属性`、`值`，如 `body {color: black}`

如果值由多个单词组成，则需要用双引号括起，如 `p {font-family: "sans serif"}`

多个属性使用分号间隔（可以每个属性一行，但分号不能省略），如 `p {text-align: center; color: red}`

### `类选择器`

通过 `.` 号来选择性渲染有`class`标识的元素，每一个`HTML`元素最多只能有一个`class`属性，如
`p.cat {text-align: center}`

`类选择器`可以没有标签名，这将匹配所有`class`属性和选择器名一致的元素，如 `.cat {text-align:
center}`

### `id选择器`

通过 `#` 号来选择性渲染有`id`标识的元素，通常在每一个`HTML`页面中不应有重复的`id`，如 `p#cat
{color: red}`

`id选择器`同样也可以没有标签名，这将匹配所有`id`属性和选择器名一致的元素，如 `#cat {color: red}`

### `链接样式`

1.  `a:link`：链接还没有任何操作的时候
2.  `a:hover`：鼠标放在链接上面的时候
3.  `a:active`：鼠标点击了链接，但还没有松开的时候
4.  `a:visited`：链接已经被访问过的时候

## Tools

- https://cssstats.com/

