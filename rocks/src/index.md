---
layout: base.njk
title: Hello World
templateEngineOverride: njk,md
---

- https://app.netlify.com/sites/sunny-fudge-534491/deploys/6728e1967c40deb0ef814a1d

- https://www.industrialempathy.com/posts/eleventy-high-performance-blog/

- https://webextension.org/listing/useragent-switcher.html
-https://github.com/11ty/eleventy-plugin-rss
-https://github.com/11ty/eleventy-plugin-syntaxhighlight

- https://www.11ty.dev/docs/config/#configuration-options

-https://11ty.rocks/
- https://learneleventyfromscratch.com/

- # eleventy-high-performance-blog

- https://egghead.io/lessons/11ty-create-an-eleventy-11ty-site-from-scratch

https://www.11ty.dev/docs/languages/

https://11ty.rocks/posts/create-your-first-basic-11ty-website/

https://www.tatianamac.com/posts/beginner-eleventy-tutorial-parti/

https://blog.logrocket.com/going-serverless-eleventy/

{% include "postlist.njk" %}

## posts

<img src="{{ catpic }}" />

{% for post in collections.pages -%}
- [{{ post.data.title }}]({{ post.url }})
{% endfor %}
