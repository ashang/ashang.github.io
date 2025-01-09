---
#layout: default
---
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
