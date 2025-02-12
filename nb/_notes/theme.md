---
title: "Hєllo theme"
permalink: "/contrast/"
layout: post
mathjax: true
---

The theme is called ["Contrast"][3] and it is by [Niklaus Buschmann][4]. It was
simple and looked good. Also it comes with support for equations, which you can
enable with just `mathjax: true` in the page.

<script type="math/tex; mode=display">f^{(n)}(z) = \frac{n !}{2 \pi i} \int_{C}\! \frac{f(\zeta)}{(\zeta - z)^{n+1}} \mathrm{d}\zeta</script>

Features

- Responsive
- Pagination
- Archive page
- Feed.xml generation
- Syntax highlighting
- Comments (disqus / isso)
- MathJax
- optional sidebar
- no external ressources


*(Note: An update to the version of Jekyll/Kramdown used by github.io broke
this feature a bit.  [I raised an issue on Contrast's GitHub.][5])*

[3]: https://jekyllthemes.io/theme/contrast
[4]: https://github.com/niklasbuschmann
[5]: https://github.com/niklasbuschmann/contrast/issues/28

The instructions suggest forking the repo, but I just cloned it and then pushed
to an empty repository. That way I can search it in the web UI (since at time of
writing GitHub does not search forks).

I'll mention this uses the [Liquid][6] templating system so I can find the
documentation later when I need it.

[6]: https://shopify.dev/docs/themes/liquid/reference

{% comment %}
         1         2         3         4         5         6         7         8
12345678901234567890123456789012345678901234567890123456789012345678901234567890
{% endcomment %}

- <https://www.kernel.org/finger_banner>

## Built on Poole

Poole is the Jekyll Butler, serving as an upstanding and effective foundation for Jekyll themes by [@mdo](https://twitter.com/mdo). Poole, and every theme built on it (like Lanyon here) includes the following:

* Complete Jekyll setup included (layouts, config, [404](/404), [RSS feed](/atom.xml), posts, and [example page](/about))
* Mobile friendly design and development
* Easily scalable text and component sizing with `rem` units in the CSS
* Support for a wide gamut of HTML elements
* Related posts (time-based, because Jekyll) below each post
* Syntax highlighting, courtesy Pygments (the Python-based code snippet highlighter)

### Lanyon features

In addition to the features of Poole, Lanyon adds the following:

* Toggleable sliding sidebar (built with only CSS) via **☰** link in top corner
* Sidebar includes support for textual modules and a dynamically generated navigation with active link support
* Two orientations for content and sidebar, default (left sidebar) and [reverse](https://github.com/poole/lanyon#reverse-layout) (right sidebar), available via `<body>` classes
* [Eight optional color schemes](https://github.com/poole/lanyon#themes), available via `<body>` classes

[Head to the readme](https://github.com/poole/lanyon#readme) to learn more.

### Browser support

Lanyon is by preference a forward-thinking project. In addition to the latest versions of Chrome, Safari (mobile and desktop), and Firefox, it is only compatible with Internet Explorer 9 and above.

### Download

Lanyon is developed on and hosted with GitHub. Head to the <a href="https://github.com/poole/lanyon">GitHub repository</a> for downloads, bug reports, and features requests.

Thanks!
