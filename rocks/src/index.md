---
layout: base.njk
title: Hello World
templateEngineOverride: njk,md
---

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
