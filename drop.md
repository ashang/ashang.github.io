---
layout: page
title:
permalink: /drop/
---

XX　　古代文化常识XX

{% for note in site.notes %}
{% if note.title != "Template" %}

- [{{ note.title }}]({{ note.url }})

{% endif %}
{% endfor %}
