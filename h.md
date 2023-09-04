---
#layout: default
---
<main class="content fade-in-down delay-0_75s">
  <div class="inner">
    <div class="entry-container">
      <ul class="entry-box">
        {%- for note in site.posts -%}
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

        {%- for note in site.note reversed -%}
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
</main>
