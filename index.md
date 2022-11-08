---
layout: default
#title: Home
---
<!--
-->
<main class="content fade-in-down delay-0_75s">
    <div class="inner">
        {% include loop.html %}
        {% if paginator.total_pages > 1 %}
        <nav class="pagination">
            <h2 class="screen-reader-text">Posts navigation</h2>
            {% if paginator.previous_page %}
            <a href="{{ paginator.previous_page_path | prepend: site.baseurl }}" class="newer-posts"><i class="fa fa-angle-left" aria-hidden="true"></i> Newer Posts</a>
            {% endif %}
            <span class="page-number">Page {{ paginator.page }} of {{ paginator.total_pages }}</span>
            {% if paginator.next_page %}
            <a href="{{ paginator.next_page_path | prepend: site.baseurl }}" class="older-posts">Older Posts <i class="fa fa-angle-right" aria-hidden="true"></i></a>
            {% endif %}
        </nav><!-- .pagination -->
        {% endif %}
    </div><!-- .inner -->
</main><!-- .content -->

<div class="posts">
  {% for post in paginator.posts %}
  <div class="post">
    <h1 class="post-title">
      <a href="{{ post.url | absolute_url }}">
        {{ post.title }}
      </a>
    </h1>

    <span class="post-date">{{ post.date | date_to_string }}</span>

    {{ post.content }}
  </div>
  {% endfor %}
</div>

<div class="pagination">
  {% if paginator.next_page %}
    <a class="pagination-item older" href="{{ paginator.next_page_path | absolute_url }}">Older</a>
  {% else %}
    <span class="pagination-item older">Older</span>
  {% endif %}

  {% if paginator.previous_page %}
    {% if paginator.page == 2 %}
      <a class="pagination-item newer" href="{{ '/' | absolute_url }}">Newer</a>
    {% else %}
      <a class="pagination-item newer" href="{{ paginator.previous_page_path | absolute_url }}">Newer</a>
    {% endif %}
  {% else %}
    <span class="pagination-item newer">Newer</span>
  {% endif %}
</div>
