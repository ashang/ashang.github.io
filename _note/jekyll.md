---
title: Hello Jekyll
date: 2017-07-11
layout: post
jekyll_escape: true
prism_languages: [jekyll, yaml, ruby]
tags: [jekyll, yaml, ruby]
updated: 2018-08-25
render_with_liquid: false
---

Jekyll offers powerful support for code snippets:

{% highlight ruby %}
def print_hi(name)
puts "Hi, #{name}"
end
print_hi('Tom')
#=> prints 'Hi, Tom' to STDOUT.
{% endhighlight %}

```ruby
def print_hi(name)
  puts "Hi, #{name}"
end
print_hi('Tom')
#=> prints 'Hi, Tom' to STDOUT.
```

# major changes

* `link` tag now comes with the `relative_url` filter incorporated into it.
    You should no longer prepend `{{ site.baseurl }}`.

* `post_url` tag now comes with the `relative_url` filter incorporated into it.
    You shouldn't prepend `{{ site.baseurl }}`.


$ a \* b = c ^ b $

$ 2^{\frac{n-1}{3}} $

$ \int_a^b f(x)\,dx. $

```cpp
#include <iostream>
using namespace std;

int main() {
  cout << "Hello World!";
  return 0;
}
// prints 'Hi, Tom' to STDOUT.
```

```python
class Person:
  def __init__(self, name, age):
    self.name = name
    self.age = age

p1 = Person("John", 36)

print(p1.name)
print(p1.age)
```

### Directories

```
./
├── _config.yml
│
├── _data/
│   └── ...
│
├── _layouts/
│   ├── default.html
│   └── post.html
│
├── _includes/             - partials
│   ├── header.html
│   └── footer.html
```

```yaml
source: .
destination: _site
exclude:
- Gemfile
- Gemfile.lock
include: ['.htaccess']
```

### Filters

```html
<p>
  {{ page.description | truncate_words: 20 }}
</p>
```

### Case

```html
{% case shipping.title %}
  {% when 'international' %}
     Arriving in 2-3 weeks
  {% when 'Domestic' %}
     Arriving in 2-3 days
  {% else %}
     Thank you for your order!
{% endcase %}
```

### Includes (partials)

```
{% include header.html %}
```

```html
<!-- Including local vars -->
{% include header.html page=page %}
```

### Comments

```html
{% comment %}
  This is a comment!
{% endcomment %}
```

## Variables

### Top-level variables

| `{{ site }}` | Data from `config.yml` |
| `{{ page }}` | From frontmatter, and page-specific info |
| `{{ content }}` | HTML content (use in layouts) |
| `{{ paginator }}` | Paginator |

### Site

```html
{{ site.time }}
```

| `site.time` | Current time |
| `site.pages` | List of pages |
| `site.posts` | List of blog posts |
| `site.related_posts` | List of posts related to current |
| `site.categories.CATEGORY` | List |
| `site.tags.TAG` | List |
| `site.static_files` | List |

### Page

```html
{{ page.content }}  - un-rendered content
{{ page.title }}
{{ page.excerpt }}  - un-rendered excerpt
{{ page.url }}
{{ page.date }}
{{ page.id }}       - unique id for RSS feeds
{{ page.categories }}
{{ page.tags }}
{{ page.path }}
{{ page.dir }}
{{ page.excerpt | remove: '<p>' | remove: '</p>' }}
{{ page.excerpt | strip_html }}
```

### Dates

```ruby
{{ site.time | date: "%Y %m %d" }}
```

| `date_to_xmlschema` | → `2008-11-07T13:07:54-08:00` |
| `date_to_rfc822` | → `Mon, 07 Nov 2008 13:07:54 -0800` |
| `date_to_string` | → `07 Nov 2008` |
| `date_to_long_string` | → `07 November 2008` |
| `date:` _'%Y %m %d'_ | → `2017 Nov  7` |

### Preprocessors

```ruby
{{ page.description | markdownify }}
```

| Filter | Description |
| --- | --- |
| `textilize` | Textile |
| `markdownify` | Markdown |
| `jsonify` | JSON |
| `sassify` | Sass |
| `scssify` | SCSS |
| `smartify` | Smartypants |

### Array filters

```ruby
{{ site.pages | where: "year", "2014" }}
```

| Filter | Description |
| --- | --- |
| `where:` _"year", "2014"_ | |
| `where_exp:` _"item", "item.year >= 2014"_ | |
| --- | --- |
| `group_by:` _"genre"_   | → `{name, items}` |
| `group_by_exp:` _"item", "item.genre"_   | → `{name, items}` |
| --- | --- |
| `sort` | |
| `sort:` _'author'_ | |
| --- | --- |
| `uniq` | |
| --- | --- |
| `first` | |
| `last` | |
| `join:` _','_ | |
| `array_to_sentence_string` | → `"X, Y and Z"` |
| --- | --- |
| `map:` _'post'_ | Works like 'pluck' |
| --- | --- |
| `size` | |
| `push:` _'xxx'_ | Adds an item |

### String filters

```ruby
{{ page.title | default: "xxx" }}
```

| Filter                             | Description |
| ---                                | ---         |
| `default:` _'xxx'_                 |             |
| ---                                | ---         |
| `upcase`                           |             |
| `downcase`                         |             |
| ---                                | ---         |
| `remove:` _'p'_                    |             |
| `replace:` _'super', 'mega'_       |             |
| `remove_first:` _'p'_              |             |
| `replace_first:` _'super', 'mega'_ |             |
| ---                                | ---         |
| `truncate:` _5_                    |             |
| `truncatewords:` _20_              |             |
| ---                                | ---         |
| `prepend:` _'Mr. '_                |             |
| `append:` _'Jr.'_                  |             |
| ---                                | ---         |
| `camelize`                         |             |
| `capitalize`                       |             |
| `strip_html`                       |             |
| `strip_newlines`                   |             |
| `newlines_to_br`                   |             |
| ---                                | ---         |
| `split:` _','_                     |             |
| ---                                | ---         |
| `escape`                           |             |
| `escape_once`                      |             |
| ---                                | ---         |
| `slice:` _-3, 3_                   |             |

### String filters (Jekyll-only)

```ruby
{{ page.excerpt | number_of_words }}
```

| Filter | Description |
| --- | --- |
| `number_of_words` | |
| `slugify` | |
| --- | --- |
| `xml_escape` | → `CDATA` |
| `cgi_escape` | → `foo%2Cbar` |
| `uri_escape` | → `foo,%20bar` |

### Numbers

```
{{ site.posts.size | minus: 2 }}
```

| Filter | Description |
| --- | --- |
| `minus:` _2_ | |
| `plus:` _2_ | |
| `times:` _2_ | |
| `divided_by:` _2_ | |
| `modulo:` _2_ | |
| --- | --- |
| `ceil` | |
| `floor` | |
| `round` | |

### Image paths

    ![My helpful screenshot]({{ site.url }}/assets/screenshot.jpg)

### Data

```
_data/members.yml
```

```
{% for member in site.data.members %}
  ...
{% endfor %}
```

### Collections

```yml
# _config.yml
collections:
  - authors
```

```yml
# _/authors/a-n-roquelaire.md
---
name: A. N. Roquelaire
real_name: Anne Rice
---
```

### Code highlighter

```html
{% highlight ruby linenos %}
def show
  ...
end
{% endhighlight %}
```

### Bundler

In `_plugins/bundler.rb`:

```ruby
require "bunder/setup"
Bundler.require :default
```

### Compass

  * [Compass](https://gist.github.com/parkr/2874934)
  * [Asset pipeline](https://github.com/matthodan/jekyll-asset-pipeline)

Also see

* [CloudCannon Jekyll cheatsheet](https://learn.cloudcannon.com/jekyll-cheat-sheet/) _cloudcannon.com_
* [Liquid: output](https://docs.shopify.com/themes/liquid-basics/output) _shopify.com_
* [Liquid: logic](https://docs.shopify.com/themes/liquid-basics/logic) _shopify.com_
* [Liquid: filters](https://docs.shopify.com/themes/liquid-documentation/filters) _shopify.com_
* [Liquid for designers](https://github.com/Shopify/liquid/wiki/Liquid-for-Designers) _github.com/Shopify_

## Liquid

```html
$ cat news.html

<div class="news-container">
  <div class="news-inner">
    <div class="news-line">
      <span class="news-highlight">{{i18n.site_news_important}}:</span> {{i18n.site_news_docs_cover_v1}}
    </div>
    <div class="news-line">
      {{i18n.site_news_see_v2_docs}}
    </div>
  </div>
</div>
```

## Tags

tags:
    - something
    - here
    - three

```
<ul>
  {{ "{% assign sorted_tags = site.tags | sort %}" }}
  {{ "{% for tag in sorted_tags %}" }}
    {{ "{% assign t = tag | first %}" }}
    {{ "{% assign posts = tag | last %}" }}
    <li>
      <a href="/tags/# {{ "{{ t | downcase | replace:' ','-'" }}}}">
        {{ "{{t | downcase | replace:' ','-' " }}}}
        <span>({{ "{{ posts | size " }}}})</span>
      </a>
    </li>
  {{ "{% endfor " }}%}
</ul>
```

```
{% assign sorted = site.projects | sort: 'date' | reverse  %}
```

