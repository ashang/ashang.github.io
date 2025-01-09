---
layout: default
#layout: page
#title: Archive
titles:
  # @start locale config
  en      : &EN       Archive
  en-GB   : *EN
  en-US   : *EN
  en-CA   : *EN
  en-AU   : *EN
  zh-Hans : &ZH_HANS  归档
  zh      : *ZH_HANS
  zh-CN   : *ZH_HANS
  zh-SG   : *ZH_HANS
  zh-Hant : &ZH_HANT  歸檔
  zh-TW   : *ZH_HANT
  zh-HK   : *ZH_HANT
  ko      : &KO       아카이브
  ko-KR   : *KO
  fr      : &FR       Archives
  fr-BE   : *FR
  fr-CA   : *FR
  fr-CH   : *FR
  fr-FR   : *FR
  fr-LU   : *FR
  # @end locale config
---

<div class="layout--archive js-all">
  <div class="js-result layout--archive__result d-none">
    {%- include article-list.html articles=site.posts type='brief' show_info=true reverse=true group_by='year' -%}
  </div>
</div>

<script>
  {%- include scripts/archieve.js -%}
</script>

## Archives by tags

{% capture site_tags %}{% for tag in site.tags %}{{ tag | first }}{% unless forloop.last %},{% endunless %}{% endfor %}{% endcapture %}
{% assign sortedTags = site_tags | split:',' | sort %}
{% for tag in sortedTags %}
  <span><a href="#{{ tag | cgi_escape }}">{{ tag }}</a></span>
{% endfor %}
<!--
How to remove line breaks here.
-->

{% for tag in sortedTags %}
<h3 id="{{ tag | cgi_escape }}">{{ tag }}</h3>
  <ul class="archive-posts-list">
    {% for post in site.tags[tag] %}
      <li>
        <time datetime="{{ post.date | date: "%Y-%m-%d" }}">{{ post.date | date: "%Y-%m-%d" }}</time>
        &mdash;
        <a href="{{ site.baseurl }}{{ post.url }}" rel="bookmark">{{ post.title }}</a>
      </li>
    {% endfor %}
  </ul>
{% endfor %}

<!--
## Archives by Year-Month

{% assign postsByYearMonth = site.posts | group_by_exp: "post", "post.date | date: '%Y-%m'" %}
{% for yearMonth in postsByYearMonth %}
### {{ yearMonth.name }}
  <ul>
    {% for post in yearMonth.items %}
      <li>
        <time datetime="{{ post.date | date: "%Y-%m-%d" }}">{{ post.date | date: "%Y-%m-%d" }}</time>
        &mdash;
        <a href="{{ post.url }}">{{post.title}} </a>
      </li>
    {% endfor %}
  </ul>
{% endfor %}
-->

## Archives by Year

{% capture postByYear %}{{ post.date | date: '%Y' }}{% endcapture %}
{% assign post_Year = postByYear %}
{% for post in site.posts %}
### {{ post_Year }}
- <span><time datetime="{{ post.date | date: "%Y-%m-%d" }}">{{ post.date | date: "%Y-%m-%d" }}</time></span>
  &mdash;
  <a href="{{ post.url }}">{{post.title}} </a>
{% endfor %}
