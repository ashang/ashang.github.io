---
#
# By default, content added below the "---" mark will appear in the home page
# between the top bar and the list of recent posts.
# To change the home page layout, edit the _layouts/home.html file.
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
#
layout: home
#layout: default
---
<main class="content fade-in-down delay-0_75s">
  <div class="inner">
    <div class="entry-container">

# Posts
      {%- for note in site.posts -%}
        <div class="entry-list">
          <time datetime="{{ note.date }}" class="entry-time">{{ note.date | date: "%Y-%m-%d" }}</time>
          &raquo;
          <a href="{{ note.url }}" rel="bookmark">
            {{ note.title }}
          </a>
        </div>
      {% endfor %}

# Notes
      {%- for note in site.note reversed -%}
        <div class="entry-list">
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
        </div>
      {% endfor %}
    </div>
  </div>
</main>
