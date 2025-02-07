---
layout: page
title:
permalink: /drop/
---

XX　　古代文化常识XX
<section class="container content">
<div class="columns">
  <div class="column three-fourths" >
    <article class="article-content markdown-body">
    {{ content }}
    </article>
    <div class="comment">
      {% include comments.html %}
    </div>
  </div>
  <div class="column one-fourth">
  </div>
</div>
</section>
<!-- /section.content -->

{% for note in site.notes %}
{% if note.title != "Template" %}

- [{{ note.title }}]({{ note.url }})

{% endif %}
{% endfor %}
