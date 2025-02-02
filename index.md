---
#
# By default, content added below the "---" mark will appear in the home page
# between the top bar and the list of recent posts.
# To change the home page layout, edit the _layouts/home.html file.
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
#
#layout: default
layout: base
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
