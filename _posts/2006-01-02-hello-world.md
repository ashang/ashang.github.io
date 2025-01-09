---
layout:     post
title: "Hєllo World!"
header-style: text
#layout: page
#permalink: "/about/"
#permalink: "/hello/"
mathjax: true
date: 2006-01-02
---

Thanks for stopping by! ** » Discussion on reddit.com **


Styles are written in LESS and minified with lessc. JavaScript is minified using yui-compressor. I'm using entr to automatically re-minify them when their sources change:

find assets/ ./*.* \
    | entr sh -xc "cat assets/js/plugins/*.js assets/js/_main.js \
        | yui-compressor --type js -o assets/js/scripts.min.js ; \
        lessc assets/less/main.less > assets/css/main.min.css" &

F5 triggers a standard reload.
Ctrl + F5 triggers a forced reload, causes the browser to re-download the page from the web server, ensuring that it always has the latest copy.
A forced reload does not display a cached copy of the page.

---

> Then we have The Festival of Insignificance: a complete embrace of the lightness Kundera once seemed to reject.

> Life, the new characters contend, is insignificant, so we might as well make it a spectacle.

> Instead of forging meaning through layered memories, relationships, and objects, these Parisians find solace in what Hegel called `unendliche Wohlgemutheit` -- an infinite good mood in which even the worst atrocities seem hilarious.

> 然后我们有了微不足道的节日：完全拥抱昆德拉曾经似乎拒绝的轻。

> 新角色争辩说，生命是微不足道的，所以我们不妨把它变成一个奇观。

> 这些巴黎人并没有通过层层叠叠的记忆、关系和物品来塑造意义，而是在黑格尔所谓的`unendliche Wohlgemutheit`中寻找慰藉，-- 一种无限美好的心情，即使是最糟糕的暴行也显得很滑稽。

---

> Hegel dice que el verdadero humor es impensable sin el infinito buen humor, escúchalo bien, eso es lo que dice literalmente: «infinito buen humor»; «unendliche Wohlgemutheit!».

> No la burla, no la sátira, no el sarcasmo. Sólo desde lo alto del infinito buen humor puedes observar debajo de ti la eterna estupidez de los hombres, y reírte de ella.”

> 黑格尔说，如果没有无限好的幽默，真正的幽默是不可想象的，好好听他说，这就是他的字面意思：«无限好的幽默»； «unendliche Wohlgemutheit!».

> 不是嘲讽，不是讽刺，不是讽刺。

---

> 只有从无限好的幽默的高度，你才能观察到你下面人类永恒的愚蠢，并嘲笑它。”
