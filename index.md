---
---
<main class="content fade-in-down delay-0_75s">
  <div class="inner">
    <div id="home">
      {%- for note in site.note reversed -%}
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
