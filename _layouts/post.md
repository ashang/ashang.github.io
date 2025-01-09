---
layout: default
---
<main class="content fade-in-down delay-0_5s">
  <div class="inner">
    <article class="post">
      <div class="entry-box">
        <header class="entry-header post-header mb2">
          <h1 class="entry-title">{{ page.title }}</h1>
          <div class="entry-meta">
            <span class="post-meta small">
              <time class="post-date" datetime="{{ page.date | date: "%Y-%m-%d" }}">{{ page.date | date: site.date_format }}</time>
<!--
              <time class="post-date" datetime="{{ page.date | date: "%Y-%m-%d" }}">{{ page.date | date_to_xmlschema }}</time>
-->
<!--
-->
              {% if page.update_date %}
                <time class="post-date">{{ site.text.post.updated | default: "Updated" }}: {{ page.update_date | date: site.date_format }}</time>
              {% endif %}
            </span>
          </div><!-- .entry-meta -->
        </header><!-- .entry-header -->

        <div class="entry-content post">
          {{content}}
        </div><!-- .entry-content -->

      <div class="share">
        {% include share_buttons.html %}
      </div>
      <div class="clearfix"></div>

    </article>

    <nav class="post-nav">
      {% if page.previous.url %}
      <a href="{{ site.baseurl }}{{page.previous.url}}" class="nav-previous">Previous Post</a>
      {% endif %}
      <br/>
      {% if page.next.url %}
      <a href="{{ site.baseurl }}{{page.next.url}}">Next Post</a>
      {% endif %}
    </nav><!-- .post-nav -->

    <footer class="entry-footer">
      {% if page.tags.size > 0 %}
      <div class="post-tags">
        Tags:
        {% for tag in page.tags %}
        <a href="{{ site.baseurl }}/tags/#{{ tag }}" rel="tag">#{{ tag }}</a>
        {% unless forloop.last %}, {% endunless %}
        {% endfor %}
      </div>
      {% endif %}

      <div class="share-post">
        <span>Share this:</span>
        <a class="btn-twitter" target="_blank" href="https://twitter.com/intent/tweet?text={{ page.title }}&amp;url={{ site.url }}{{ page.url }}"><i class="fa fa-twitter" aria-hidden="true"></i><span class="screen-reader-text">Twitter</span></a>
      </div><!-- .share-post -->
    </footer><!-- .entry-footer -->
  </div><!-- .entry-box -->

    {% if site.related_posts.size >= 1 %}
    <section class="related">
      <h3 class="related-post-title">{{ site.text.post.related_posts | default: "Related Posts" }}</h3>
      <ul class="related-posts">
        {% for post in site.related_posts limit:3 %}
          <li>
            - <span><time datetime="{{ post.date | date: "%Y-%m-%d" }}">{{ post.date | date: "%Y-%m-%d" }}</time></span>
            &mdash;
            <a href="{{ post.url }}">{{post.title}} </a>
          </li>
        {% endfor %}
      </ul>
    </section>
    {% endif %}

    <div class="site-footer-links right mobile-hidden">
      <a href="javascript:window.scrollTo(0,0)" >Top</a>
    </div>
    <!--
    -->

    {{ site.description | escape }}
    <div class="mode" id="mode-switcher" onclick="toggleNightMode();">
      <span></span>
    </div>

    <div class="site-info mt-2">
        {%- include snippets/get-locale-string.html key='COPYRIGHT_DATES' -%}
        {%- assign _locale_copyright_dates = __return -%}
        <a href="https://creativecommons.org/licenses/by-nc/4.0/deed.en">
          <span>
            <b>{{ site.owner}}</b>
          </span>
          CC-BY-SA 4.0 &copy;
          <!--
          -->
          <!--
          {% capture currentyear %}{{ 'now' | date: "%Y" }}{% endcapture %}
          <span> {{ currentyear }}</span>
          -->
        </a>

        {% if site.author %}
        <a href="{{ "/about/" | relative_url }}">
          <img src="/img/icon/me.svg" class="social-icon">
          <span>
            <b>{{ site.author | escape }}</b>
          </span>
        </a>
        {% endif %}

	<time datetime="{{ site.time }}">{{ site.time | date: '%Y' }}</time> {{ site.author }}.
        <ul class="contact-list">
          <li>
            Any questions, comments, and corrections are welcome
            {% if site.email %}
              ,
              <a href="mailto:{{ site.email }}">{{ site.email }}</a>
            {% endif %}
	  </li>
        </ul>
      </div>
  </div>


  </div><!-- .inner -->
</main><!-- .content -->
