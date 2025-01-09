---
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