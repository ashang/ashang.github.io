---
layout: default
---

<section class="greeting">
            <!--
    <p>
        Hello <em>world</em>, and,
        Hi, there!
    </p>
            -->
</section>

## Shared topics

- <a  class="extra " href="/share/ai-dev.html">AI and SW engineering</a>

## Notes

  <div class="post">
    <ul class="post-list">
      {% for post in site.notes limit:5 %}
      <li class="post">
        <span class="post-date">{{ post.date | date: "%Y-%m-%d" }}  :  </span>
        <a class="post-link" href="{{ post.url | prepend: site.baseurl }}">{{ post.title }}</a>
      </li>
      {% endfor %}
    </ul>
  </div>

[All notes](/notes)

## Today I learnt

- https://deno.com/blog/intro-to-islands
