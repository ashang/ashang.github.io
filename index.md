---
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: default
---

{% if site.posts.size > 0 %}
## {{ page.list_title | default: "What I Learnt Today" }}

  {% if site.paginate %}
    {% assign posts = paginator.posts %}
  {% else %}
    {% assign posts = site.posts %}
  {% endif %}

  {% for p in site.posts limit:10 %}

    {%- assign date_format = site.minima.date_format | default: "%Y%m%d" -%}
    - {{ p.date | date: date_format }} &mdash;  [{{ p.title | escape }}]({{ p.url | relative_url }})

  {% endfor %}

{%- endif -%}

  {%- if page.title -%}
    <h1 class="page-heading">{{ page.title }}</h1>
  {%- endif -%}

{% if site.notes.size > 0 %}
## {{ page.list_title | default: "What I Learnt Today" }}

  {% for p in site.notes limit:10 %}

    {%- assign date_format = site.minima.date_format | default: "%Y%m%d" -%}
    - {{ p.date | date: date_format }} &mdash;  [{{ p.title | escape }}]({{ p.url | relative_url }})

  {% endfor %}

{%- endif -%}

{% if site.tags.size > 0 %}

## Tags

{%- for t in site.tags -%}
- {{ t[0] }}
    {% for p in t[1] %}
    - {{ p.date | date: "%Y%m%d" }}  &mdash;  [{{ p.title | escape }}]({{ p.url | relative_url }})
    {% endfor %}
{%- endfor -%}
{% endif %}


    {% if site.paginate %}
        {%- if paginator.previous_page %}
          <li><a href="{{ paginator.previous_page_path | relative_url }}" class="previous-page">{{ paginator.previous_page }}</a></li>
        {%- else %}
          <li><div class="pager-edge">•</div></li>
        {%- endif %}
          <li><div class="current-page">{{ paginator.page }}</div></li>
        {%- if paginator.next_page %}
          <li><a href="{{ paginator.next_page_path | relative_url }}" class="next-page">{{ paginator.next_page }}</a></li>
        {%- else %}
          <li><div class="pager-edge">•</div></li>
        {%- endif %}
    {%- endif %}


- https://github.com/jekyll/minima

https://globalimmerse.org/

https://raw.githubusercontent.com/jglovier/jglovier/main/README.md

https://pjw.io/articles/2018/05/18/jaeger-tutorial/

https://pjw.io/articles/2018/05/08/opentracing-explanations/

http://www.piedpiper.com/

https://www.youtube.com/user/LowballJim

https://youtu.be/H9_pg-gTOR8

https://medium.com/@timanglade/how-hbos-silicon-valley-built-not-hotdog-with-mobile-tensorflow-keras-react-native-ef03260747f3

https://pjw.io/articles/2018/04/25/access-to-the-container-network-of-docker-for-mac/

https://pjw.io/articles/2016/07/01/mac-os-x-terminal-mouse-reporting-mark-bookmark/

https://zh.wikipedia.org/wiki/GoAgent

https://wiki.archlinux.org/title/Multiboot_USB_drive#Hybrid_UEFI_GPT_.2B_BIOS_GPT.2FMBR_boot

https://github.com/aguslr/multibootusb/blob/master/docs/isos.md

https://github.com/aguslr/multibootusb/tree/master/docs
