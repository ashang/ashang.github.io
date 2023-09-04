---
layout: page
title: WILT
description: 人越学越觉得自己无知
keywords: 维基, Wiki
comments: false
menu: 维基
permalink: /notes/
---

<ul class="listing">
  {% for n in site.note %}
    {% if n.title != "Wiki Template" %}
      <li class="listing-item"><a href="{{ n.url }}">{{ n.title }}</a></li>
    {% endif %}
    {% endfor %}
</ul>