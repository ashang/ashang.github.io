---
# By default, content added below the "---" mark will appear in the home page
# between the top bar and the list of recent posts.
# To change the home page layout, edit the _layouts/home.html file.
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: default
author: dave
---

{% for post in paginator.posts %}
## [{{ post.title }}]({{ post.url | absolute_url }})
{{ post.date | date_to_string }}
{{ post.content }}
{% endfor %}

{% if paginator.next_page %}
[ Older ]({{ paginator.next_page_path | absolute_url }})
{% endif %}

{% if paginator.previous_page %}
  {% if paginator.page == 2 %}
[ Newer ]({{ '/' | absolute_url }})
  {% else %}
[ Newer ]({{ paginator.previous_page_path | absolute_url }} | absolute_url }})
  {% endif %}
{% endif %}

{% if site.posts.size > 0 %}
## {{ page.list_title | default: "What I Learnt Today" }}

  {% if site.paginate %}
    {% assign posts = paginator.posts %}
  {% else %}
    {% assign posts = site.posts %}
  {% endif %}

  {% for p in site.posts limit:5 %}

    {%- assign date_format = site.thepro.date_format | default: "%b %d, %Y" -%}
    {{ p.date | date: date_format }} &mdash;  [{{ p.title | escape }}]({{ p.url | relative_url }})

  {% endfor %}
{%- endif -%}

----

{% if site.notes.size > 0 %}
  {% for p in site.notes limit:60 %}
    {%- assign date_format = site.thepro.date_format | default: "%Y%m%d" -%}
    {{ p.date | date: date_format }} &mdash;  [{{ p.title | escape }}]({{ p.url | relative_url }})

  {% endfor %}
{%- endif -%}

{% if site.tags.size > 0 %}

## Tags

{%- for t in site.tags -%}
- {{ t[0] }}
  {% for p in t[1] %}
  - {{ p.date | date: "%Y%m%d" }}  &mdash;  [{{ p.title | escape }}]({{ p.url | relative_url }})
  {% endfor %}
{%- endfor -%}

{% endif %}

    {% if site.paginate %}
        {%- if paginator.previous_page %}
          <li><a href="{{ paginator.previous_page_path | relative_url }}" class="previous-page">{{ paginator.previous_page }}</a></li>
        {%- else %}
          <li><div class="pager-edge">•</div></li>
        {%- endif %}
          <li><div class="current-page">{{ paginator.page }}</div></li>
        {%- if paginator.next_page %}
          <li><a href="{{ paginator.next_page_path | relative_url }}" class="next-page">{{ paginator.next_page }}</a></li>
        {%- else %}
          <li><div class="pager-edge">•</div></li>
        {%- endif %}
    {%- endif %}

Collecting stars...
[![Star This Project](https://img.shields.io/github/stars/ashang/ashang.svg?label=Stars&style=social)](https://github.com/ashang/ashang/)

https://www.reddit.com/r/gnome/comments/8sh7oa/a_nice_trick_to_create_a_mojavelike_time_shifting/
