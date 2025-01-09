---
layout: default
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
