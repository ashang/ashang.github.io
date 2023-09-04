## HOME

```liquid
---
layout: page
---

{{ content }}

<div class="entries-{{ page.entries_layout | default: 'list' }}">
  {%- if site.plugins contains 'jekyll-paginate' and page.paginate or site.gems contains 'jekyll-paginate' and page.paginate -%}
    {%- comment -%}
      Add paginator.posts loop if jekyll-paginate plugin is enabled
      and page.paginate == true
    {%- endcomment -%}
    {% include posts-paginated.html %}
  {%- else -%}
    {% include posts-limit.html %}
  {%- endif -%}
</div>
```


```liquid
---
---

{% capture liquidstring %}
Liquid is not rendered.
{% endcapture %}
{{ liquidstring | replace:'not ','' }}
```
