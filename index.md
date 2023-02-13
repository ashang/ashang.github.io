---
#layout: default
---
<main class="content fade-in-down delay-0_75s">
  <div class="inner">
    <div id="home">
      {%- for note in site.posts -%}
          <ul class="entry-box">
              <li class="entry-item">
                <time datetime="{{ note.date }}" class="entry-time">{{ note.date | date: "%Y-%m-%d" }}</time>
                &raquo;
                <a href="{{ note.url }}" rel="bookmark">
                    {{ note.title }}
                </a>
                <del class="entry-line"></del>
              </li>
          </ul>
      {% endfor %}
    </div>
  </div>
</main>
<div class="entry-container">
      {%- for note in site.note reversed -%}
        <div class="entry-list">
            <a class="entry-title"
              href="{{ site.url }}{{ note.url }}"
              rel="bookmark" >
                    {{ note.title }}
                </a>

            <time datetime="{{ note.date | date_to_xmlschema }}"
              class="entry-time" >
              {{ note.date | date: "%Y-%m-%d" }}
            </time>
        </div>
    {% endfor %}
</div>
