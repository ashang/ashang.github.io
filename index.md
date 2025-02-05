---
#
# By default, content added below the "---" mark will appear in the home page
# between the top bar and the list of recent posts.
# To change the home page layout, edit the _layouts/home.html file.
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
#
#layout: default
layout: base
author: dave
---

  <div class="inner">
    <div class="entry-container">

      {%- assign date_format = site.minima.date_format | default: "%b %d, %Y" -%}

# Posts

      {%- for note in site.posts -%}
        <div class="post-list">
          <time class="entry-time" datetime="{{ note.date | date_to_xmlschema }}">
            {{ note.date | date: date_format }}
          </time>
          &raquo;
          <a class="post-link" 
            href="{{ note.url | relative_url }}" rel="bookmark" style="display: inline;">
            {{ note.title | escape }}
          </a>
        </div>
      {% endfor %}

# Notes

      <ul class="entry-box">
        {%- for note in site.notes reversed -%}
          <li class="entry-item">
            <time datetime="{{ note.date | date_to_xmlschema }}"
              class="entry-time" >
              {{ note.date | date: "%Y-%m-%d" }}
            </time>
            &raquo;
            <a class="entry-title"
              href="{{ site.url }}{{ note.url }}"
              rel="bookmark" >
              {{ note.title }}
            </a>
            <del class="entry-line"></del>
          </li>
        {% endfor %}
      </ul>
    </div>
  </div>


  {%- if page.title -%}
    <h1 class="page-heading">{{ page.title }}</h1>
  {%- endif -%}

  {% if site.paginate %}
    {% assign posts = paginator.posts %}
  {% else %}
    {% assign posts = site.posts %}
  {% endif %}

---+++---

  {%- if posts.size > 0 -%}
    {%- if page.list_title -%}
      <h2 class="post-list-heading">{{ page.list_title }}</h2>
    {%- endif -%}

    {% if site.paginate %}
      <div class="pager">
        <ul class="pagination">
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
        </ul>
      </div>
    {%- endif %}

  {%- endif -%}

----====


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

----

{% if site.posts.size > 0 %}
## {{ page.list_title | default: "What I Learnt Today" }}

  {% if site.paginate %}
    {% assign posts = paginator.posts %}
  {% else %}
    {% assign posts = site.posts %}
  {% endif %}

  {% for p in site.posts limit:420 %}

    {%- assign date_format = site.thepro.date_format | default: "%b %d, %Y" -%}
    {{ p.date | date: date_format }} &mdash;  [{{ p.title | escape }}]({{ p.url | relative_url }})

  {% endfor %}
{%- endif -%}

----

{% if site.notes.size > 0 %}
  {% for p in site.notes limit:60 %}

  > [{{ p.title | escape }}]({{ p.url | relative_url }})

  {% endfor %}
{%- endif -%}

{% if site.tags.size > 0 %}

## Tags

{%- for t in site.tags -%}
- {{ t[0] }}
  {% for p in t[1] %}
  - {{ p.date | date: "%Y%m%d" }} &mdash; [{{ p.title | escape }}]({{ p.url | relative_url }})
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
----==== ----====


<main class="content fade-in-down delay-0_75s">
  <div class="inner">
    <div class="entry-container">
      Posts
      <ul class="entry-box">
        {%- for note in site.posts -%}
          <li class="entry-item">
            <time datetime="{{ note.date | date_to_xmlschema }}"
              class="entry-time" >
              {{ note.date | date: "%Y-%m-%d" }}
            </time>
            &raquo;
            <a
              href="{{ note.url }}"
              rel="bookmark" >
              {{ note.title }}
            </a>
            <del class="entry-line"></del>
          </li>
        {% endfor %}
      </ul>
      Notes
      <ul class="entry-box">
        {%- for note in site.note reversed -%}
          <li class="entry-item">
            <time datetime="{{ note.date | date_to_xmlschema }}"
              class="entry-time" >
              {{ note.date | date: "%Y-%m-%d" }}
            </time>
            &raquo;
            <a
              href="{{ note.url }}"
              rel="bookmark" >
              {{ note.title }}
            </a>
            <del class="entry-line"></del>
          </li>
        {% endfor %}
      </ul>
    </div>
  </div>
</main>



====----

{% assign posts_count = paginator.posts | size %}

<div class="home">
  {% if posts_count > 0 %}
    <div class="posts">
      {% for post in paginator.posts %}
        <div class="post py3">
          <p class="post-meta">
	    {% if site.date_format %}
	      {{ post.date | date: site.date_format }}
	    {% else %}
	      {{ post.date | date: "%b %-d, %Y" }}
	    {% endif %}
	  </p>
          <a href="{{ post.url | relative_url }}" class="post-link"><h3 class="h1 post-title">{{ post.title }}</h3></a>
          <span class="post-summary">
            {% if post.summary %}
              {{ post.summary }}
            {% else %}
              {{ post.excerpt }}
            {% endif %}
          </span>
        </div>
      {% endfor %}
    </div>

    {% include pagination.html %}
  {% else %}
    <h1 class='center'>{{ site.text.index.coming_soon }}</h1>
  {% endif %}
</div>



--- --- ---

  {% for post in paginator.posts %}

## [{{ post.title }}]({{ post.url | absolute_url }})

{{ post.date | date_to_string }}

{{ post.content }}

  {% endfor %}

  {% if paginator.next_page %}
[ Older ]({{ paginator.next_page_path | absolute_url }})
  {% else %}
Older
  {% endif %}

  {% if paginator.previous_page %}
    {% if paginator.page == 2 %}
[ Newer ]({{ '/' | absolute_url }})
    {% else %}
[ Newer ]({{ paginator.previous_page_path | absolute_url }} | absolute_url }})
    {% endif %}
  {% endif %}

----

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
😂🤣👽👻



https://www.reddit.com/r/gnome/comments/8sh7oa/a_nice_trick_to_create_a_mojavelike_time_shifting/


http://chapeaulinux.org/forums/topic/timed-background-image-change/

https://opensource.com/article/17/12/create-your-own-wallpaper-slideshow-gnome
