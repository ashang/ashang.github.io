---
title: Jekyll
render_with_liquid: false
date: 2018-05-12
---

Jekyll takes your content, renders Markdown and Liquid templates, and spits out a complete, static website.

Between these triple-dashed lines, you can set predefined variables (see below
for a reference) or even create custom ones of your own. These variables will
  then be available for you to access using Liquid tags both further down in the
  file and also in any layouts or includes that the page or post in question
  relies on.

# UTF-8 Character Encoding Warning

If you use UTF-8 encoding, make sure that no BOM header characters exist in
  your files or very, very bad things will happen to Jekyll.

# Liquid

Jekyll uses the Liquid templating language to process templates.

Generally in Liquid you output content using two curly braces e.g. {{ variable }} and perform logic statements by surrounding them in a curly brace percentage sign.

## Filters

```
Where

Select all the objects in an array where the key has the given value.

{{ site.members | where:"graduation_year","2014" }}

Where Expression

Select all the objects in an array where the expression is true. 3.2.0

{{ site.members | where_exp:"item", "item.graduation_year == 2014" }}

{{ site.members | where_exp:"item", "item.graduation_year < 2014" }}

{{ site.members | where_exp:"item", "item.projects contains 'foo'" }}
```

## Notes

If you want to use Liquid tags and variables but don’t need anything in your front matter, just leave it empty! The set of triple-dashed lines with nothing in between will still get Jekyll to process your file. (This is useful for things like CSS and RSS feeds!)

## Excerpt

    {{ p.excerpt }}

## Running

```
$ bundle-2.7 exec jekyll serve --trace --incremental --livereload
Configuration file: /home/aaron/neo/_config.yml
            Source: .
       Destination: ./_site
 Incremental build: enabled
      Generating...
                    done in 0.29 seconds.
/home/aaron/.gem/ruby/2.7.0/gems/pathutil-0.16.2/lib/pathutil.rb:502: warning: Using the last argument as keyword parameters is deprecated
 Auto-regeneration: enabled for '.'
    Server address: http://127.0.0.1:4000/
LiveReload address: http://127.0.0.1:35729
  Server running... press ctrl-c to stop.
        LiveReload: Browser connected
```

## Liquid syntax error

Add `render_with_liquid: false` to front matter to not report liquid warnings.

```log
Unexpected character ` in "{{ trimPrefix `/` .Name }}"
[:dot, "."] is not a valid expression in "{{.State.Pid}}"
[:dot, "."] is not a valid expression in "{{.LogPath}}"
[:dot, "."] is not a valid expression in "{{ .NetworkSettings.Networks.$network.IPAddress }}"
[:dot, "."] is not a valid expression in "{{range .IPAM.Config}}"
```

