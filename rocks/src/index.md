---
layout: base.njk
title: Hello World
templateEngineOverride: njk,md
---

{% include "postlist.njk" %}

## Cat of the Day

<img src="{{ catpic }}" />

{% for post in collections.pages -%}
- [{{ post.data.title }}]({{ post.url }})
{% endfor %}