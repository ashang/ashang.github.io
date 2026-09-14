---
layout: default
---

## notes

{% for post in site.notes %}
- <span class="post-date">{{ post.date | date: "%Y-%m-%d" }}  :  </span>
  <a class="post-link" href="{{ post.url | prepend: site.baseurl }}">{{ post.title }}</a>
{% endfor %}
