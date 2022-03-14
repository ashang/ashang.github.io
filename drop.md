---
layout: page
title:
permalink: /drop/
---

{% for note in site.notes %}
{% if note.title != "Template" %}

- [{{ note.title }}]({{ note.url }})

{% endif %}
{% endfor %}
