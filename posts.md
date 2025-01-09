---
layout: default
title: "posts"
#permalink: /posts/
---

<main class="content fade-in-down delay-0_5s">
  <div class="inner">
    <article class="post">
      <div class="entry-box">
        <header class="entry-header">
          <h1 class="entry-title">{{ page.title }}</h1>
          <div class="entry-meta">
            <time class="post-date" datetime="{{ page.date | date: "%Y-%m-%d" }}">{{ page.date | date: "%B %-d, %Y" }}</time> by {{ site.author.name }}
          </div><!-- .entry-meta -->
        </header><!-- .entry-header -->

        <div class="entry-content">
          {{content}}
        </div><!-- .entry-content -->

      <div class="share">
        {% include share_buttons.html %}
      </div>
      <div class="clearfix"></div>

    </article>

        <nav class="post-nav">
            <h2 class="screen-reader-text">Post navigation</h2>
            {% if page.previous.url %}
            <a href="{{ site.baseurl }}{{page.previous.url}}" class="nav-previous">Previous Post</a>
            {% endif %}
            {% if page.next.url %}
            <a href="{{ site.baseurl }}{{page.next.url}}">Next Post</a>
            {% endif %}
        </nav><!-- .post-nav -->


            </div><!-- .entry-box -->
                <footer class="entry-footer">
                    {% if page.tags.size > 0 %}
                    <div class="post-tags">
                        Tags: {% for tag in page.tags %}<a href="{{ site.baseurl }}/tags/index.html#{{ tag | cgi_escape }}" rel="tag">{{ tag }}</a>{% unless forloop.last %}, {% endunless %}{% endfor %}
                    </div>
                    {% endif %}
                    <div class="share-post">
                        <!--
                        <span>Share this:</span>
                        <a class="btn-twitter" target="_blank" href="https://twitter.com/intent/tweet?text={{ page.title | uri_escape }}&amp;url={{ site.url }}{{ page.url }}"><i class="fa fa-twitter" aria-hidden="true"></i><span class="screen-reader-text">Twitter</span></a>
                        -->
                    </div><!-- .share-post -->
                </footer><!-- .entry-footer -->


            <div class="author-box">
                <div class="author-info">
                    <div class="author-details">
                        <!--
                        <h2 class="author-title">About {{ site.author.name }}</h2>
                        <p class="author-bio">{{ site.author_bio }}</p>
                        <p class="author-links">
                            {% if site.author_location %}
                            <span class="author-location"><i class="fa-map-marker" aria-hidden="true"></i> {{ site.author_location }}</span>
                            {% endif %}
                            {% if site.author_url %}
                            <span class="author-website"><a href="{{ site.author_url }}" target="_blank"><i class="fa-chain" aria-hidden="true"></i> {{ site.author_url }}</a></span>
                            {% endif %}
                        </p>
                        -->
                    </div><!-- .author-details -->
                </div><!-- .author-info -->
            </div><!-- .author-box -->



  </div><!-- .inner -->
</main><!-- .content -->

https://www.v2ex.com/rework

https://github.com/thoughtbot/rcm

https://www.instagram.com/zekrotja/

https://jamesclark.dev/context-managers/

https://jamesclark.dev/2023-python-workflow/

https://www.sohu.com/a/442631373_115300

https://page.iesdouyin.com/traffic-aggregation/249600

<div class="tags">
  <div class="tags-header">
    <h2 class="tags-header-title">{{ page.title }}</h2>
    <div class="tags-header-line"></div>
  </div>
  <div class="tags-clouds">
    {% for tag in site.tags %}
      <a href="#{{ tag[0] }}">{{ tag[0] }}</a>
    {% endfor %}
  </div>
  {% for tag in site.tags %}
  <div class="tags-item" id="{{ tag[0] }}">
    <svg
      class="tags-item-icon"
      xmlns="http://www.w3.org/2000/svg"
      width="20"
      height="20"
      viewBox="0 0 24 24"
      fill="none"
      stroke="currentColor"
      stroke-width="2"
      stroke-linecap="round"
      stroke-linejoin="round"
      class="feather feather-tag"
    >
      <path
        d="M20.59 13.41l-7.17 7.17a2 2 0 0 1-2.83 0L2 12V2h10l8.59 8.59a2 2 0 0 1 0 2.82z"
      ></path>
      <line x1="7" y1="7" x2="7.01" y2="7"></line>
    </svg>
    <h2 class="tags-item-label">{{ tag[0] }}</h2>
    {% for post in tag[1] %}
    <a class="tags-post" href="{{ post.url }}">
      <div>
        <span class="tags-post-title">{{ post.title }}</span>
        <div class="tags-post-line"></div>
      </div>
      <span class="tags-post-meta">
        <time datetime="{{ post.date }}">
          {{ post.date | date:"%Y-%m-%d" }}
        </time>
      </span>
    </a>
    {% endfor %}
  </div>
  {% endfor %}
</div>

{% capture site_tags %}{% for tag in site.tags %}{{ tag | first }}{% unless forloop.last %},{% endunless %}{% endfor %}{% endcapture %}
{% assign tag_words = site_tags | split:',' | sort %}

<h1>Tags</h1>
<div class="tags">
  <div class="entry-container">
    {% for item in (0..site.tags.size) %}{% unless forloop.last %}
      {% capture this_word %}{{ tag_words[item] | strip_newlines }}{% endcapture %}

      <a href="tags/#{{ this_word | cgi_escape }}" class="tag">{{ this_word }} <span>({{ site.tags[this_word].size }})</span></a>

      <h2 id="{{ this_word | cgi_escape }}">{{ this_word }}</h2>
      {% for post in site.tags[this_word] %}
        {% if post.title != null %}
          <div class="entry-list">
            <a class="entry-title" href="{{ site.url }}{{ post.url }}">{{ post.title }}</a>
            <time datetime="{{ post.date | date_to_xmlschema }}" class="entry-time">{{ post.date | date: "%d.%m.%Y" }}</time>
          </div>
        {% endif %}
      {% endfor %}
    {% endunless %}{% endfor %}
  </div>
</div>

----

<ul class="listing">
  {% for n in site.note %}
    {% if n.title != "Wiki Template" %}
      <li class="listing-item"><a href="{{ n.url }}">{{ n.title }}</a></li>
    {% endif %}
    {% endfor %}
</ul>

<div class="post">
  <h1 class="post-title">{{ page.title }}</h1>
  <span class="post-date">{{ page.date | date_to_string }}</span>
  {{ content }}
</div>

{% if site.related_posts.size >= 1 %}
<div class="related">
  <h2>Related posts</h2>
  <ul class="related-posts">
    {% for post in site.related_posts limit:4 %}
      <li>
        <h3>
          <a href="{{ site.baseurl }}{{ post.url }}"> {{ post.title }}</a>
          <small>{{ post.date | date_to_string }}</small>
        </h3>
      </li>
    {% endfor %}
  </ul>
</div>
{% endif %}
