<!DOCTYPE html>
<html lang="{{ page.lang | default: site.lang | default: "en-US" | default: "en" }}">
  {%- include head.html -%}

    <!--
  {% include meta.html %}
    -->
    <!--
    -->
  <!-- hack iOS CSS :active style -->
  <body class="fixed-nav" ontouchstart="">
    {% include nav.html %}
    {%- include header.html -%}
    <div id="page" class="site">
      <!-- xxxx Wrap is the content to shift when toggling the sidebar. We wrap the
         content to avoid any CSS collisions with our real content. -->
      <main class="masthead wrap" aria-label="Content">
        <div class="container">
          <h3 class="masthead-title">
            <a href="{{ site.baseurl }}/" title="Home">{{ site.title }}</a>
            <small>{{ site.tagline }}</small>
          </h3>
        </div>
        <div class="page-content container content">
          {{ content }}
        </div>
      </main>
    </div><!-- .site -->

<!--
-->

  <div class="profile">
    <a href="{{ site.url }}"><img src="{{site.author.picture}}" class="profile-image"></a>
    <div class="profile-about">
      <h2 style="margin-bottom: 0; font-weight: 700;">{{site.author.name}}</h2>
      {% if site.author.twitter %}
        <a href="https://twitter.com/{{site.author.twitter}}" target="_blank"><img src="/images/icon/twitter.svg" class="social-icon"></a>
      {% endif %}
      {% if site.author.youtube %}
        <a href="{{site.author.youtube}}" target="_blank"><img src="/images/icon/youtube.svg" class="social-icon"></a>
      {% endif %}
      {% if site.author.github %}
        <a href="https://github.com/{{site.author.github}}" target="_blank"><img src="/images/icon/github.svg" class="social-icon"></a>
      {% endif %}
      {% if site.author.linkedin %}
        <a href="https://linkedin.com/in/{{site.author.linkedin}}" target="_blank"><img src="/images/icon/linkedin.svg" class="social-icon"></a>
      {% endif %}

      <div class="mode" id="mode-switcher" onclick="toggleNightMode();">
        <span></span>
      </div>
    </div>
  </div>

    {% include sidebar.html %}
    <label for="sidebar-checkbox" class="sidebar-toggle"></label>

    <script src='{{ site.baseurl }}/js/script.js'></script>

    <div class="wrap">
      <div class="masthead">
<!--
-->
          {% for item in site.data.nav %}
            <a href="{{ item.link }}" {% if page.url == item.link %}style="color: red;"{% endif %}>
            <a href="{{ item.link }}" {% if page.url == item.link %}class="Current" class="align-right"{% endif %}>
              {{ item.name }}
            </a>
          {% endfor %}

      <nav class="align-right">
        <ul>
          {% assign url = page.url|remove:'index.html' %}
          {% for link in site.navigation %}
          {% if page.path contains '_posts' and link.url == '/' %}
            {% assign item_class = 'active' %}
          {% else %}
            {% if link.url == url %}
              {% assign item_class = 'active' %}
            {% else %}
              {% assign item_class = 'inactive' %}
            {% endif %}
          {% endif %}
          <li class="{{ item_class }}">
            <a href="{{ link.url }}" {% if link.target %}target="{{ link.target }}" {% endif %}>
              {{ link.text }}
            </a>
          </li>
          {% endfor %}
          <span></span>
        </ul>
      </nav>
<!--
-->
      </div>
    </div>

    {% include footer.html %}
  </body>
  <script>
    window.simpleJekyllSearch = new SimpleJekyllSearch({
      searchInput: document.getElementById('search-field'),
      resultsContainer: document.getElementById('search-results'),
      json: '{{ site.baseurl }}/search.json',
      searchResultTemplate: '<li><a href="{url}" title="{desc}">{title}</a> <span class="entry-meta"><time class="post-date" datetime="{date}">{date}</time></span></li>',
      noResultsText: 'No results found',
      limit: 15,
      fuzzy: false,
      exclude: ['Welcome']
    })
  </script>
</html>
