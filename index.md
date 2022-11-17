---
layout: default
title: Home
---
<main class="content fade-in-down delay-0_75s">
  <div class="inner">
    {% include loop.html %}
    <div id="home">
        <h1>Posts</h1>
        <ul class="posts">
          {% for post in site.posts limit:42 %}
            <li><span>{{ post.date | date_to_string }}</span> &raquo; <a href="{{ post.url | absolute_url }}">{{ post.title }}</a></li>
          {% endfor %}
        </ul>
    </div>
    </div>
</main>