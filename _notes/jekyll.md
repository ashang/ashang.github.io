---
layout: post
render_with_liquid: false
date: 2018-05-12
updated: 2018-08-25
title: Hello Jekyll
jekyll_escape: true
prism_languages: [jekyll, yaml, ruby]
tags:
- jekyll
- liquid
- git
- yaml
toc: true
---

## sass

_sass 目录存储 Sass/SCSS 的部分文件（partials）。

- 文件通常以 \_ 开头，例如 \_variables.scss, \_mixins.scss。
- **不会生成对应的 CSS 文件**
- 用于被其他 SCSS 文件通过 @import 引入。
- 典型用法是组织样式代码，例如定义变量、函数、混合器和复用样式。

css 目录通常包含主 SCSS 文件。

- 例如 styles.scss
- 用 @import 来引入 _sass 中的部分文件。
- Jekyll 会扫描 _sass 和其他目录中的 .scss 文件
- --使用 Ruby 的 sass 或 sassc 库。-- Dart sass ???
- 将 css 目录中的 .scss 文件转换为 .css 文件。其他目录???
- 生成的 .css 文件会被放在站点的 _site 目录下，**路径与原始 .scss 文件一致**。

在 _config.yml 中自定义：

```
sass:
  load_paths:
    - _sass

_sass/
  _variables.scss
  _mixins.scss
  _base.scss
css/
  styles.scss
```

```
    _sass/_variables.scss：

    $primary-color: #3498db;
    $font-stack: 'Arial', sans-serif;

    _sass/_mixins.scss：

    @mixin center {
      display: flex;
      justify-content: center;
      align-items: center;
    }

    _sass/_base.scss：

    body {
      font-family: $font-stack;
      color: $primary-color;
    }

    css/styles.scss：

    ---
    ---
    @import "variables";
    @import "mixins";
    @import "base";

    .button {
      @include center;
      background-color: $primary-color;
    }
```

生成后，_site/css/styles.css 的内容为：

```
body {
  font-family: 'Arial', sans-serif;
  color: #3498db;
}

.button {
  display: flex;
  justify-content: center;
  align-items: center;
  background-color: #3498db;
}
```

Between these triple-dashed lines, you can set predefined variables
or even create custom ones of your own. These variables will
  then be available for you to access using Liquid tags both further down in the
  file and also in any layouts or includes that the page or post in question
  relies on.

## UTF-8 Character Encoding Warning

If you use UTF-8 encoding, make sure that no BOM header characters exist in
  your files or very, very bad things will happen to Jekyll.

## Liquid

Jekyll uses the Liquid templating language to process templates.

In Liquid two curly braces for {{ variable }} and logic statements by surrounding them in a curly brace percentage sign.

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

## serve

```
$ bundle exec jekyll serve --port 1111 --host 10.10.50.50 --trace --unpublished --incremental
Configuration file: /home/aaron/j/agi/_config.yml
            Source: /home/aaron/j/agi
       Destination: /home/aaron/j/agi/_site
 Incremental build: enabled
      Generating...
```

```sh
$ gem i jekyll

Fetching pathutil-0.16.2.gem
Fetching safe_yaml-1.0.5.gem
Fetching rouge-3.29.0.gem
Fetching liquid-4.0.3.gem
...
Successfully installed terminal-table-2.0.0
ERROR:  While executing gem ... (Gem::FilePermissionError)
    You don't have write permissions for the /usr/bin directory.

$ gem i jekyll
Successfully installed safe_yaml-1.0.5
Successfully installed rouge-3.29.0
...
Successfully installed jekyll-watch-2.2.1
Building native extensions. This could take a while...

Successfully installed sassc-2.4.0
Successfully installed jekyll-sass-converter-2.2.0
Successfully installed concurrent-ruby-1.1.10
Successfully installed i18n-1.10.0
Building native extensions. This could take a while...
Successfully installed http_parser.rb-0.8.0
Building native extensions. This could take a while...
Successfully installed eventmachine-1.2.7
Successfully installed em-websocket-0.5.3
Successfully installed colorator-1.1.0
Successfully installed public_suffix-4.0.7
Successfully installed addressable-2.8.0
Successfully installed jekyll-4.2.2
25 gems installed

$ bundle-2.7 exec jekyll s
Could not locate Gemfile or .bundle/ directory

$ jekyll s
Configuration file: /aaron/notes/_config.yml
  Dependency Error: Yikes! It looks like you don't have jekyll-feed or one of its dependencies installed. In order to use Jekyll as currently configured, you'll need to install this gem. If you've run Jekyll with `bundle exec`, ensure that you have included the jekyll-feed gem in your Gemfile as well. The full error message from Ruby is: 'cannot load such file -- jekyll-feed' If you run into trouble, you can find helpful resources at https://jekyllrb.com/help/!
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
/usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:73:in `rescue in block in require_with_graceful_fail': jekyll-feed (Jekyll::Errors::MissingDependencyException)
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:58:in `block in require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:30:in `require_gems'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:22:in `conscientious_require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:131:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:36:in `initialize'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `new'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- jekyll-feed (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:60:in `block in require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:30:in `require_gems'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:22:in `conscientious_require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:131:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:36:in `initialize'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `new'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ gem i jekyll-feed
Fetching jekyll-feed-0.16.0.gem
Successfully installed jekyll-feed-0.16.0
1 gem installed

$ jekyll s
Configuration file: /aaron/notes/_config.yml
            Source: /aaron/notes
       Destination: /aaron/notes/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.493 seconds.
 Auto-regeneration: enabled for '/aaron/notes'
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- webrick (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve/servlet.rb:3:in `<top (required)>'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `require_relative'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:100:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ gem i webrick
Fetching webrick-1.7.0.gem
Successfully installed webrick-1.7.0
1 gem installed

$ jekyll s
Configuration file: /aaron/notes/_config.yml
            Source: /aaron/notes
       Destination: /aaron/notes/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.44 seconds.
 Auto-regeneration: enabled for '/aaron/notes'
    Server address: http://127.0.0.1:4000
  Server running... press ctrl-c to stop.
```

## Serve with specific path

```sh
bundle update --bundler
bundle install
bundle exec jekyll clean
exec jekyll serve -w -s /home/rstudio --incremental -d $XDG_RUNTIME_DIR/_site --host 0.0.0.0
```

## Trouble shooting

### Using the last argument as keyword parameters is deprecated

```sh
$ bundle exec jekyll serve
Configuration file: /home/aaron/notes/_config.yml
            Source: /home/aaron/notes
       Destination: /home/aaron/notes/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.612 seconds.
/home/aaron/.gem/ruby/gems/pathutil-0.16.2/lib/pathutil.rb:502:
warning: Using the last argument as keyword parameters is deprecated
 Auto-regeneration: enabled for '/home/aaron/notes'
    Server address: http://127.0.0.1:4000/
  Server running... press ctrl-c to stop.
[2022-07-11 13:45:31] ERROR `/favicon.ico' not found.
```

When a hash is the last argument in a method as keyword arguments, Ruby 2 converts this argument into keyword arguments.

This behavior is prone to be confusing, Ruby 2.7 will warn about this, and Ruby 3 requires hash splat.

Bump jekyll to `gem "jekyll", "~> 4.2.2"` in Gemfile, the warning disappears.

```sh
$ bundle exec jekyll serve --incremental
Configuration file: /home/aaron/notes/_config.yml
            Source: /home/aaron/notes
       Destination: /home/aaron/notes/_site
 Incremental build: enabled
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 1.4 seconds.
 Auto-regeneration: enabled for '/home/aaron/notes'
    Server address: http://127.0.0.1:4000
  Server running... press ctrl-c to stop.
```

## Layout

show_excerpts: true        # show article excerpts on the home page
show_frame: true           # adds a gray frame to the site
show_sidebar: false        # show a sidebar instead of the usual header

# Menu

navigation:                # accepts {file, title, url, icon, sidebaricon}
  - {file: "index.html"}
  - {file: "README.md"}

external:                  # shows a footer with social links - for available icons see fontawesome.com/icons
  - {title: Mail, icon: envelope, url: "mailto:niklasbuschmann@users.noreply.github.com"}
  - {title: Github, icon: github, url: "https://github.com/niklasbuschmann/contrast"}
  - {title: Subscribe, icon: rss, url: "/feed.xml"}

comments:
#  disqus_shortname: ""    # see https://disqus.com/
#  isso_domain: ""         # see https://posativ.org/isso/

## .jekyll-metadata

## .jekyll-cache

```sh
.jekyll-cache/Jekyll/Cache:

drwxrwxr-x 1 aaron aaron  4 Jul 21 13:57 Jekyll--Cache
drwxrwxr-x 1 aaron aaron 96 Jul 21 14:04 Jekyll--Converters--Markdown

.jekyll-cache/Jekyll/Cache/Jekyll--Cache:

-rw-rw-r-- 1 aaron aaron 2767 Jul 21 13:57 9606fb3afea5bd1609ed40b622142f1c98125abcfe89a76a661b0e8e343910

.jekyll-cache/Jekyll/Cache/Jekyll--Converters--Markdown/02:
-rw-rw-r-- 1 aaron aaron 942 Jul 21 13:58 2cc54274c07b4c86c0492f68c1f6958ea6b4a1d8ce07f3a3ef7e592a83cbe8
```

```sh
$ bundle exec jekyll serve --incremental --trace --watch --verbose --destination $XDG_RUNTIME_DIR/_site
  Logging at level: debug
    Jekyll Version: 4.2.2
Configuration file: /home/aaron/notes/_config.yml
  Logging at level: debug
    Jekyll Version: 4.2.2
            Source: /home/aaron/notes
       Destination: /run/user/1000/_site
 Incremental build: enabled
      Generating...
           Reading: /_layouts/default.html
           Reading: /_layouts/page.html
           Reading: /_layouts/post.html
       EntryFilter: excluded /Gemfile
       EntryFilter: excluded /Gemfile.lock
       EntryFilter: excluded /.jekyll-cache
           Reading: _posts/2010-01-22-nvm.md
           Reading: _posts/2010-02-19-armel.md
...
           Reading: assets/css/classes.sass
           Reading: assets/css/index.sass
           Reading: assets/css/minimal.sass
           Reading: assets/css/sidebar.sass
           Reading: assets/fontawesome/icons.svg
           Reading: archive.html
           Reading: readme.md
           Reading: index.md
           Reading: 404.md
           Reading: _data/font-awesome/icons.json
       Jekyll Feed: Generating feed for posts
        Generating: JekyllFeed::Generator finished in 0.00086884 seconds.
        Generating: Jekyll::JekyllSitemap finished in 0.002780563 seconds.
         Rendering: _posts/2014-11-03-rsync.md
  Pre-Render Hooks: _posts/2014-11-03-rsync.md
  Rendering Markup: _posts/2014-11-03-rsync.md
Post-Convert Hooks: _posts/2014-11-03-rsync.md
  Rendering Layout: _posts/2014-11-03-rsync.md
         Rendering: _posts/2014-11-03-rsync.md/#excerpt
  Pre-Render Hooks: _posts/2014-11-03-rsync.md/#excerpt
  Rendering Markup: _posts/2014-11-03-rsync.md/#excerpt
Post-Convert Hooks: _posts/2014-11-03-rsync.md/#excerpt

         Rendering: 404.md
  Pre-Render Hooks: 404.md
  Rendering Markup: 404.md
Post-Convert Hooks: 404.md
  Rendering Layout: 404.md
         Rendering: archive.html
  Pre-Render Hooks: archive.html
  Rendering Liquid: archive.html
  Rendering Markup: archive.html
Post-Convert Hooks: archive.html
  Rendering Layout: archive.html
         Rendering: assets/css/classes.sass
  Pre-Render Hooks: assets/css/classes.sass
  Rendering Liquid: assets/css/classes.sass
  Rendering Markup: assets/css/classes.sass
Post-Convert Hooks: assets/css/classes.sass
         Rendering: assets/fontawesome/icons.svg
  Pre-Render Hooks: assets/fontawesome/icons.svg
  Rendering Liquid: assets/fontawesome/icons.svg
  Rendering Markup: assets/fontawesome/icons.svg
Post-Convert Hooks: assets/fontawesome/icons.svg
  Rendering Layout: assets/fontawesome/icons.svg
         Rendering: index.md
  Pre-Render Hooks: index.md
  Rendering Liquid: index.md
  Rendering Markup: index.md
Post-Convert Hooks: index.md
  Rendering Layout: index.md
         Rendering: assets/css/index.sass
  Pre-Render Hooks: assets/css/index.sass
  Rendering Liquid: assets/css/index.sass
  Rendering Markup: assets/css/index.sass
Post-Convert Hooks: assets/css/index.sass
         Rendering: assets/css/minimal.sass
  Pre-Render Hooks: assets/css/minimal.sass
  Rendering Markup: assets/css/minimal.sass
Post-Convert Hooks: assets/css/minimal.sass
         Rendering: feed.xml
  Pre-Render Hooks: feed.xml
  Rendering Liquid: feed.xml
  Rendering Markup: feed.xml
Post-Convert Hooks: feed.xml
  Rendering Layout: feed.xml
         Rendering: sitemap.xml
  Pre-Render Hooks: sitemap.xml
  Rendering Liquid: sitemap.xml
  Rendering Markup: sitemap.xml
Post-Convert Hooks: sitemap.xml
  Rendering Layout: sitemap.xml
         Rendering: robots.txt
  Pre-Render Hooks: robots.txt
  Rendering Liquid: robots.txt
  Rendering Markup: robots.txt
Post-Convert Hooks: robots.txt
  Rendering Layout: robots.txt
         Rendering: assets/css/classes.css.map
  Pre-Render Hooks: assets/css/classes.css.map
  Rendering Markup: assets/css/classes.css.map
Post-Convert Hooks: assets/css/classes.css.map
         Rendering: assets/css/index.css.map
  Pre-Render Hooks: assets/css/index.css.map
  Rendering Markup: assets/css/index.css.map
Post-Convert Hooks: assets/css/index.css.map
         Rendering: assets/css/minimal.css.map
  Pre-Render Hooks: assets/css/minimal.css.map
  Rendering Markup: assets/css/minimal.css.map
Post-Convert Hooks: assets/css/minimal.css.map
         Rendering: assets/css/sidebar.css.map
  Pre-Render Hooks: assets/css/sidebar.css.map
  Rendering Markup: assets/css/sidebar.css.map
Post-Convert Hooks: assets/css/sidebar.css.map
           Writing: /run/user/1000/_site/404.html
           Writing: /run/user/1000/_site/archive/index.html
           Writing: /run/user/1000/_site/assets/css/classes.css
           Writing: /run/user/1000/_site/assets/fontawesome/icons.svg
           Writing: /run/user/1000/_site/index.html
           Writing: /run/user/1000/_site/assets/css/index.css
           Writing: /run/user/1000/_site/assets/css/minimal.css
           Writing: /run/user/1000/_site/about/index.html
           Writing: /run/user/1000/_site/assets/css/sidebar.css
           Writing: /run/user/1000/_site/feed.xml
           Writing: /run/user/1000/_site/sitemap.xml
           Writing: /run/user/1000/_site/robots.txt
           Writing: /run/user/1000/_site/assets/css/classes.css.map
           Writing: /run/user/1000/_site/assets/css/index.css.map
           Writing: /run/user/1000/_site/assets/css/minimal.css.map
           Writing: /run/user/1000/_site/assets/css/sidebar.css.map
           Writing: /run/user/1000/_site/nvm/index.html
...
           Writing: /run/user/1000/_site/sonic/index.html
  Writing Metadata: .jekyll-metadata
                    done in 8.687 seconds.
         Requiring: jekyll-watch
           Watcher: Ignoring (?-mix:^_config\.yml)
           Watcher: Ignoring (?-mix:^\.jekyll\-cache\/)
           Watcher: Ignoring (?-mix:^Gemfile)
           Watcher: Ignoring (?-mix:^Gemfile\.lock)
 Auto-regeneration: enabled for '/home/aaron/notes'
[2022-07-21 17:35:28] INFO  WEBrick 1.7.0
[2022-07-21 17:35:28] INFO  ruby 3.0.2 (2021-07-07) [x86_64-linux-gnu]
[2022-07-21 17:35:28] DEBUG WEBrick::HTTPServlet::FileHandler is mounted on /.
[2022-07-21 17:35:28] DEBUG unmount .
[2022-07-21 17:35:28] DEBUG Jekyll::Commands::Serve::Servlet is mounted on .
    Server address: http://127.0.0.1:4000/
[2022-07-21 17:35:28] INFO  WEBrick::HTTPServer#start: pid=11442 port=4000
  Server running... press ctrl-c to stop.
```

$ jekyll s
Configuration file: /aaron/notes/_config.yml
  Dependency Error: Yikes! It looks like you don't have jekyll-feed or one of its dependencies installed. In order to use Jekyll as currently configured, you'll need to install this gem. If you've run Jekyll with `bundle exec`, ensure that you have included the jekyll-feed gem in your Gemfile as well. The full error message from Ruby is: 'cannot load such file -- jekyll-feed' If you run into trouble, you can find helpful resources at https://jekyllrb.com/help/!
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
/usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:73:in `rescue in block in require_with_graceful_fail': jekyll-feed (Jekyll::Errors::MissingDependencyException)
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:58:in `block in require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:30:in `require_gems'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:22:in `conscientious_require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:131:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:36:in `initialize'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `new'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- jekyll-feed (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:60:in `block in require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:30:in `require_gems'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:22:in `conscientious_require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:131:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:36:in `initialize'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `new'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ gem i jekyll-feed
Fetching jekyll-feed-0.16.0.gem
Successfully installed jekyll-feed-0.16.0
1 gem installed

$ jekyll s
Configuration file: /aaron/notes/_config.yml
            Source: /aaron/notes
       Destination: /aaron/notes/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.493 seconds.
 Auto-regeneration: enabled for '/aaron/notes'
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- webrick (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve/servlet.rb:3:in `<top (required)>'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `require_relative'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:100:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ gem i webrick
Fetching webrick-1.7.0.gem
Successfully installed webrick-1.7.0
1 gem installed

$ jekyll s
Configuration file: /aaron/notes/_config.yml
            Source: /aaron/notes
       Destination: /aaron/notes/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.44 seconds.
 Auto-regeneration: enabled for '/aaron/notes'
    Server address: http://127.0.0.1:4000
  Server running... press ctrl-c to stop.
```

## Serve with specific path

```sh
bundle update --bundler
bundle install
bundle exec jekyll clean
exec jekyll serve -w -s /home/rstudio --incremental -d $XDG_RUNTIME_DIR/_site --host 0.0.0.0
```

## Trouble shooting

### Using the last argument as keyword parameters is deprecated

```sh
$ bundle exec jekyll serve
Configuration file: /home/aaron/notes/_config.yml
            Source: /home/aaron/notes
       Destination: /home/aaron/notes/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.612 seconds.
/home/aaron/.gem/ruby/gems/pathutil-0.16.2/lib/pathutil.rb:502:
warning: Using the last argument as keyword parameters is deprecated
 Auto-regeneration: enabled for '/home/aaron/notes'
    Server address: http://127.0.0.1:4000/
  Server running... press ctrl-c to stop.
[2022-07-11 13:45:31] ERROR `/favicon.ico' not found.
```

When a hash is the last argument in a method as keyword arguments, Ruby 2 converts this argument into keyword arguments.

This behavior is prone to be confusing, Ruby 2.7 will warn about this, and Ruby 3 requires hash splat.

Bump jekyll to `gem "jekyll", "~> 4.2.2"` in Gemfile, the warning disappears.

```sh
$ bundle exec jekyll serve --incremental
Configuration file: /home/aaron/notes/_config.yml
            Source: /home/aaron/notes
       Destination: /home/aaron/notes/_site
 Incremental build: enabled
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 1.4 seconds.
 Auto-regeneration: enabled for '/home/aaron/notes'
    Server address: http://127.0.0.1:4000
  Server running... press ctrl-c to stop.
```

## Layout

show_excerpts: true        # show article excerpts on the home page
show_frame: true           # adds a gray frame to the site
show_sidebar: false        # show a sidebar instead of the usual header

# Menu

navigation:                # accepts {file, title, url, icon, sidebaricon}
  - {file: "index.html"}
  - {file: "README.md"}

external:                  # shows a footer with social links - for available icons see fontawesome.com/icons
  - {title: Mail, icon: envelope, url: "mailto:niklasbuschmann@users.noreply.github.com"}
  - {title: Github, icon: github, url: "https://github.com/niklasbuschmann/contrast"}
  - {title: Subscribe, icon: rss, url: "/feed.xml"}

comments:
#  disqus_shortname: ""    # see https://disqus.com/
#  isso_domain: ""         # see https://posativ.org/isso/

## .jekyll-metadata

## .jekyll-cache

```sh
.jekyll-cache/Jekyll/Cache:

drwxrwxr-x 1 aaron aaron  4 Jul 21 13:57 Jekyll--Cache
drwxrwxr-x 1 aaron aaron 96 Jul 21 14:04 Jekyll--Converters--Markdown

.jekyll-cache/Jekyll/Cache/Jekyll--Cache:

-rw-rw-r-- 1 aaron aaron 2767 Jul 21 13:57 9606fb3afea5bd1609ed40b622142f1c98125abcfe89a76a661b0e8e343910

.jekyll-cache/Jekyll/Cache/Jekyll--Converters--Markdown/02:
-rw-rw-r-- 1 aaron aaron 942 Jul 21 13:58 2cc54274c07b4c86c0492f68c1f6958ea6b4a1d8ce07f3a3ef7e592a83cbe8
```

```sh
$ bundle exec jekyll serve --incremental --trace --watch --verbose --destination $XDG_RUNTIME_DIR/_site
  Logging at level: debug
    Jekyll Version: 4.2.2
Configuration file: /home/aaron/notes/_config.yml
  Logging at level: debug
    Jekyll Version: 4.2.2
            Source: /home/aaron/notes
       Destination: /run/user/1000/_site
 Incremental build: enabled
      Generating...
           Reading: /_layouts/default.html
           Reading: /_layouts/page.html
           Reading: /_layouts/post.html
       EntryFilter: excluded /Gemfile
       EntryFilter: excluded /Gemfile.lock
       EntryFilter: excluded /.jekyll-cache
           Reading: _posts/2010-01-22-nvm.md
           Reading: _posts/2010-02-19-armel.md
...
           Reading: assets/css/classes.sass
           Reading: assets/css/index.sass
           Reading: assets/css/minimal.sass
           Reading: assets/css/sidebar.sass
           Reading: assets/fontawesome/icons.svg
           Reading: archive.html
           Reading: readme.md
           Reading: index.md
           Reading: 404.md
           Reading: _data/font-awesome/icons.json
       Jekyll Feed: Generating feed for posts
        Generating: JekyllFeed::Generator finished in 0.00086884 seconds.
        Generating: Jekyll::JekyllSitemap finished in 0.002780563 seconds.
         Rendering: _posts/2014-11-03-rsync.md
  Pre-Render Hooks: _posts/2014-11-03-rsync.md
  Rendering Markup: _posts/2014-11-03-rsync.md
Post-Convert Hooks: _posts/2014-11-03-rsync.md
  Rendering Layout: _posts/2014-11-03-rsync.md
         Rendering: _posts/2014-11-03-rsync.md/#excerpt
  Pre-Render Hooks: _posts/2014-11-03-rsync.md/#excerpt
  Rendering Markup: _posts/2014-11-03-rsync.md/#excerpt
Post-Convert Hooks: _posts/2014-11-03-rsync.md/#excerpt

         Rendering: 404.md
  Pre-Render Hooks: 404.md
  Rendering Markup: 404.md
Post-Convert Hooks: 404.md
  Rendering Layout: 404.md
         Rendering: archive.html
  Pre-Render Hooks: archive.html
  Rendering Liquid: archive.html
  Rendering Markup: archive.html
Post-Convert Hooks: archive.html
  Rendering Layout: archive.html
         Rendering: assets/css/classes.sass
  Pre-Render Hooks: assets/css/classes.sass
  Rendering Liquid: assets/css/classes.sass
  Rendering Markup: assets/css/classes.sass
Post-Convert Hooks: assets/css/classes.sass
         Rendering: assets/fontawesome/icons.svg
  Pre-Render Hooks: assets/fontawesome/icons.svg
  Rendering Liquid: assets/fontawesome/icons.svg
  Rendering Markup: assets/fontawesome/icons.svg
Post-Convert Hooks: assets/fontawesome/icons.svg
  Rendering Layout: assets/fontawesome/icons.svg
         Rendering: index.md
  Pre-Render Hooks: index.md
  Rendering Liquid: index.md
  Rendering Markup: index.md
Post-Convert Hooks: index.md
  Rendering Layout: index.md
         Rendering: assets/css/index.sass
  Pre-Render Hooks: assets/css/index.sass
  Rendering Liquid: assets/css/index.sass
  Rendering Markup: assets/css/index.sass
Post-Convert Hooks: assets/css/index.sass
         Rendering: assets/css/minimal.sass
  Pre-Render Hooks: assets/css/minimal.sass
  Rendering Markup: assets/css/minimal.sass
Post-Convert Hooks: assets/css/minimal.sass
         Rendering: feed.xml
  Pre-Render Hooks: feed.xml
  Rendering Liquid: feed.xml
  Rendering Markup: feed.xml
Post-Convert Hooks: feed.xml
  Rendering Layout: feed.xml
         Rendering: sitemap.xml
  Pre-Render Hooks: sitemap.xml
  Rendering Liquid: sitemap.xml
  Rendering Markup: sitemap.xml
Post-Convert Hooks: sitemap.xml
  Rendering Layout: sitemap.xml
         Rendering: robots.txt
  Pre-Render Hooks: robots.txt
  Rendering Liquid: robots.txt
  Rendering Markup: robots.txt
Post-Convert Hooks: robots.txt
  Rendering Layout: robots.txt
         Rendering: assets/css/classes.css.map
  Pre-Render Hooks: assets/css/classes.css.map
  Rendering Markup: assets/css/classes.css.map
Post-Convert Hooks: assets/css/classes.css.map
         Rendering: assets/css/index.css.map
  Pre-Render Hooks: assets/css/index.css.map
  Rendering Markup: assets/css/index.css.map
Post-Convert Hooks: assets/css/index.css.map
         Rendering: assets/css/minimal.css.map
  Pre-Render Hooks: assets/css/minimal.css.map
  Rendering Markup: assets/css/minimal.css.map
Post-Convert Hooks: assets/css/minimal.css.map
         Rendering: assets/css/sidebar.css.map
  Pre-Render Hooks: assets/css/sidebar.css.map
  Rendering Markup: assets/css/sidebar.css.map
Post-Convert Hooks: assets/css/sidebar.css.map
           Writing: /run/user/1000/_site/404.html
           Writing: /run/user/1000/_site/archive/index.html
           Writing: /run/user/1000/_site/assets/css/classes.css
           Writing: /run/user/1000/_site/assets/fontawesome/icons.svg
           Writing: /run/user/1000/_site/index.html
           Writing: /run/user/1000/_site/assets/css/index.css
           Writing: /run/user/1000/_site/assets/css/minimal.css
           Writing: /run/user/1000/_site/about/index.html
           Writing: /run/user/1000/_site/assets/css/sidebar.css
           Writing: /run/user/1000/_site/feed.xml
           Writing: /run/user/1000/_site/sitemap.xml
           Writing: /run/user/1000/_site/robots.txt
           Writing: /run/user/1000/_site/assets/css/classes.css.map
           Writing: /run/user/1000/_site/assets/css/index.css.map
           Writing: /run/user/1000/_site/assets/css/minimal.css.map
           Writing: /run/user/1000/_site/assets/css/sidebar.css.map
           Writing: /run/user/1000/_site/nvm/index.html
...
           Writing: /run/user/1000/_site/sonic/index.html
  Writing Metadata: .jekyll-metadata
                    done in 8.687 seconds.
         Requiring: jekyll-watch
           Watcher: Ignoring (?-mix:^_config\.yml)
           Watcher: Ignoring (?-mix:^\.jekyll\-cache\/)
           Watcher: Ignoring (?-mix:^Gemfile)
           Watcher: Ignoring (?-mix:^Gemfile\.lock)
 Auto-regeneration: enabled for '/home/aaron/notes'
[2022-07-21 17:35:28] INFO  WEBrick 1.7.0
[2022-07-21 17:35:28] INFO  ruby 3.0.2 (2021-07-07) [x86_64-linux-gnu]
[2022-07-21 17:35:28] DEBUG WEBrick::HTTPServlet::FileHandler is mounted on /.
[2022-07-21 17:35:28] DEBUG unmount .
[2022-07-21 17:35:28] DEBUG Jekyll::Commands::Serve::Servlet is mounted on .
    Server address: http://127.0.0.1:4000/
[2022-07-21 17:35:28] INFO  WEBrick::HTTPServer#start: pid=11442 port=4000
  Server running... press ctrl-c to stop.
```

$ jekyll s
Configuration file: /aaron/notes/_config.yml
  Dependency Error: Yikes! It looks like you don't have jekyll-feed or one of its dependencies installed. In order to use Jekyll as currently configured, you'll need to install this gem. If you've run Jekyll with `bundle exec`, ensure that you have included the jekyll-feed gem in your Gemfile as well. The full error message from Ruby is: 'cannot load such file -- jekyll-feed' If you run into trouble, you can find helpful resources at https://jekyllrb.com/help/!
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
/usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:73:in `rescue in block in require_with_graceful_fail': jekyll-feed (Jekyll::Errors::MissingDependencyException)
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:58:in `block in require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:30:in `require_gems'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:22:in `conscientious_require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:131:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:36:in `initialize'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `new'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- jekyll-feed (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:60:in `block in require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:30:in `require_gems'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:22:in `conscientious_require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:131:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:36:in `initialize'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `new'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ gem i jekyll-feed
Fetching jekyll-feed-0.16.0.gem
Successfully installed jekyll-feed-0.16.0
1 gem installed

$ jekyll s
Configuration file: /aaron/notes/_config.yml
            Source: /aaron/notes
       Destination: /aaron/notes/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.493 seconds.
 Auto-regeneration: enabled for '/aaron/notes'
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- webrick (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve/servlet.rb:3:in `<top (required)>'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `require_relative'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:100:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ gem i webrick
Fetching webrick-1.7.0.gem
Successfully installed webrick-1.7.0
1 gem installed

$ jekyll s
Configuration file: /aaron/notes/_config.yml
            Source: /aaron/notes
       Destination: /aaron/notes/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.44 seconds.
 Auto-regeneration: enabled for '/aaron/notes'
    Server address: http://127.0.0.1:4000
  Server running... press ctrl-c to stop.
```

## Layout

show_excerpts: true        # show article excerpts on the home page
show_frame: true           # adds a gray frame to the site
show_sidebar: false        # show a sidebar instead of the usual header

# Menu

navigation:                # accepts {file, title, url, icon, sidebaricon}
  - {file: "index.html"}
  - {file: "README.md"}

external:                  # shows a footer with social links - for available icons see fontawesome.com/icons
  - {title: Mail, icon: envelope, url: "mailto:niklasbuschmann@users.noreply.github.com"}
  - {title: Github, icon: github, url: "https://github.com/niklasbuschmann/contrast"}
  - {title: Subscribe, icon: rss, url: "/feed.xml"}

comments:
#  disqus_shortname: ""    # see https://disqus.com/
#  isso_domain: ""         # see https://posativ.org/isso/

## .jekyll-metadata

## .jekyll-cache

```sh
.jekyll-cache/Jekyll/Cache:

drwxrwxr-x 1 aaron aaron  4 Jul 21 13:57 Jekyll--Cache
drwxrwxr-x 1 aaron aaron 96 Jul 21 14:04 Jekyll--Converters--Markdown

.jekyll-cache/Jekyll/Cache/Jekyll--Cache:

-rw-rw-r-- 1 aaron aaron 2767 Jul 21 13:57 9606fb3afea5bd1609ed40b622142f1c98125abcfe89a76a661b0e8e343910

.jekyll-cache/Jekyll/Cache/Jekyll--Converters--Markdown/02:
-rw-rw-r-- 1 aaron aaron 942 Jul 21 13:58 2cc54274c07b4c86c0492f68c1f6958ea6b4a1d8ce07f3a3ef7e592a83cbe8
```

```sh
$ bundle exec jekyll serve --incremental --trace --watch --verbose --destination $XDG_RUNTIME_DIR/_site
  Logging at level: debug
    Jekyll Version: 4.2.2
Configuration file: /home/aaron/notes/_config.yml
  Logging at level: debug
    Jekyll Version: 4.2.2
            Source: /home/aaron/notes
       Destination: /run/user/1000/_site
 Incremental build: enabled
      Generating...
           Reading: /_layouts/default.html
           Reading: /_layouts/page.html
           Reading: /_layouts/post.html
       EntryFilter: excluded /Gemfile
       EntryFilter: excluded /Gemfile.lock
       EntryFilter: excluded /.jekyll-cache
           Reading: _posts/2010-01-22-nvm.md
           Reading: _posts/2010-02-19-armel.md
...
           Reading: assets/css/classes.sass
           Reading: assets/css/index.sass
           Reading: assets/css/minimal.sass
           Reading: assets/css/sidebar.sass
           Reading: assets/fontawesome/icons.svg
           Reading: archive.html
           Reading: readme.md
           Reading: index.md
           Reading: 404.md
           Reading: _data/font-awesome/icons.json
       Jekyll Feed: Generating feed for posts
        Generating: JekyllFeed::Generator finished in 0.00086884 seconds.
        Generating: Jekyll::JekyllSitemap finished in 0.002780563 seconds.
         Rendering: _posts/2014-11-03-rsync.md
  Pre-Render Hooks: _posts/2014-11-03-rsync.md
  Rendering Markup: _posts/2014-11-03-rsync.md
Post-Convert Hooks: _posts/2014-11-03-rsync.md
  Rendering Layout: _posts/2014-11-03-rsync.md
         Rendering: _posts/2014-11-03-rsync.md/#excerpt
  Pre-Render Hooks: _posts/2014-11-03-rsync.md/#excerpt
  Rendering Markup: _posts/2014-11-03-rsync.md/#excerpt
Post-Convert Hooks: _posts/2014-11-03-rsync.md/#excerpt

         Rendering: 404.md
  Pre-Render Hooks: 404.md
  Rendering Markup: 404.md
Post-Convert Hooks: 404.md
  Rendering Layout: 404.md
         Rendering: archive.html
  Pre-Render Hooks: archive.html
  Rendering Liquid: archive.html
  Rendering Markup: archive.html
Post-Convert Hooks: archive.html
  Rendering Layout: archive.html
         Rendering: assets/css/classes.sass
  Pre-Render Hooks: assets/css/classes.sass
  Rendering Liquid: assets/css/classes.sass
  Rendering Markup: assets/css/classes.sass
Post-Convert Hooks: assets/css/classes.sass
         Rendering: assets/fontawesome/icons.svg
  Pre-Render Hooks: assets/fontawesome/icons.svg
  Rendering Liquid: assets/fontawesome/icons.svg
  Rendering Markup: assets/fontawesome/icons.svg
Post-Convert Hooks: assets/fontawesome/icons.svg
  Rendering Layout: assets/fontawesome/icons.svg
         Rendering: index.md
  Pre-Render Hooks: index.md
  Rendering Liquid: index.md
  Rendering Markup: index.md
Post-Convert Hooks: index.md
  Rendering Layout: index.md
         Rendering: assets/css/index.sass
  Pre-Render Hooks: assets/css/index.sass
  Rendering Liquid: assets/css/index.sass
  Rendering Markup: assets/css/index.sass
Post-Convert Hooks: assets/css/index.sass
         Rendering: assets/css/minimal.sass
  Pre-Render Hooks: assets/css/minimal.sass
  Rendering Markup: assets/css/minimal.sass
Post-Convert Hooks: assets/css/minimal.sass
         Rendering: feed.xml
  Pre-Render Hooks: feed.xml
  Rendering Liquid: feed.xml
  Rendering Markup: feed.xml
Post-Convert Hooks: feed.xml
  Rendering Layout: feed.xml
         Rendering: sitemap.xml
  Pre-Render Hooks: sitemap.xml
  Rendering Liquid: sitemap.xml
  Rendering Markup: sitemap.xml
Post-Convert Hooks: sitemap.xml
  Rendering Layout: sitemap.xml
         Rendering: robots.txt
  Pre-Render Hooks: robots.txt
  Rendering Liquid: robots.txt
  Rendering Markup: robots.txt
Post-Convert Hooks: robots.txt
  Rendering Layout: robots.txt
         Rendering: assets/css/classes.css.map
  Pre-Render Hooks: assets/css/classes.css.map
  Rendering Markup: assets/css/classes.css.map
Post-Convert Hooks: assets/css/classes.css.map
         Rendering: assets/css/index.css.map
  Pre-Render Hooks: assets/css/index.css.map
  Rendering Markup: assets/css/index.css.map
Post-Convert Hooks: assets/css/index.css.map
         Rendering: assets/css/minimal.css.map
  Pre-Render Hooks: assets/css/minimal.css.map
  Rendering Markup: assets/css/minimal.css.map
Post-Convert Hooks: assets/css/minimal.css.map
         Rendering: assets/css/sidebar.css.map
  Pre-Render Hooks: assets/css/sidebar.css.map
  Rendering Markup: assets/css/sidebar.css.map
Post-Convert Hooks: assets/css/sidebar.css.map
           Writing: /run/user/1000/_site/404.html
           Writing: /run/user/1000/_site/archive/index.html
           Writing: /run/user/1000/_site/assets/css/classes.css
           Writing: /run/user/1000/_site/assets/fontawesome/icons.svg
           Writing: /run/user/1000/_site/index.html
           Writing: /run/user/1000/_site/assets/css/index.css
           Writing: /run/user/1000/_site/assets/css/minimal.css
           Writing: /run/user/1000/_site/about/index.html
           Writing: /run/user/1000/_site/assets/css/sidebar.css
           Writing: /run/user/1000/_site/feed.xml
           Writing: /run/user/1000/_site/sitemap.xml
           Writing: /run/user/1000/_site/robots.txt
           Writing: /run/user/1000/_site/assets/css/classes.css.map
           Writing: /run/user/1000/_site/assets/css/index.css.map
           Writing: /run/user/1000/_site/assets/css/minimal.css.map
           Writing: /run/user/1000/_site/assets/css/sidebar.css.map
           Writing: /run/user/1000/_site/nvm/index.html
...
           Writing: /run/user/1000/_site/sonic/index.html
  Writing Metadata: .jekyll-metadata
                    done in 8.687 seconds.
         Requiring: jekyll-watch
           Watcher: Ignoring (?-mix:^_config\.yml)
           Watcher: Ignoring (?-mix:^\.jekyll\-cache\/)
           Watcher: Ignoring (?-mix:^Gemfile)
           Watcher: Ignoring (?-mix:^Gemfile\.lock)
 Auto-regeneration: enabled for '/home/aaron/notes'
[2022-07-21 17:35:28] INFO  WEBrick 1.7.0
[2022-07-21 17:35:28] INFO  ruby 3.0.2 (2021-07-07) [x86_64-linux-gnu]
[2022-07-21 17:35:28] DEBUG WEBrick::HTTPServlet::FileHandler is mounted on /.
[2022-07-21 17:35:28] DEBUG unmount .
[2022-07-21 17:35:28] DEBUG Jekyll::Commands::Serve::Servlet is mounted on .
    Server address: http://127.0.0.1:4000/
[2022-07-21 17:35:28] INFO  WEBrick::HTTPServer#start: pid=11442 port=4000
  Server running... press ctrl-c to stop.
```

$ jekyll s
Configuration file: /aaron/nb/_config.yml
  Dependency Error: Yikes! It looks like you don't have jekyll-feed or one of its dependencies installed. In order to use Jekyll as currently configured, you'll need to install this gem. If you've run Jekyll with `bundle exec`, ensure that you have included the jekyll-feed gem in your Gemfile as well. The full error message from Ruby is: 'cannot load such file -- jekyll-feed' If you run into trouble, you can find helpful resources at https://jekyllrb.com/help/!
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
/usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:73:in `rescue in block in require_with_graceful_fail': jekyll-feed (Jekyll::Errors::MissingDependencyException)
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:58:in `block in require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:30:in `require_gems'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:22:in `conscientious_require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:131:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:36:in `initialize'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `new'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- jekyll-feed (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:60:in `block in require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:30:in `require_gems'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:22:in `conscientious_require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:131:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:36:in `initialize'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `new'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ gem i jekyll-feed
Fetching jekyll-feed-0.16.0.gem
Successfully installed jekyll-feed-0.16.0
1 gem installed

$ jekyll s
Configuration file: /aaron/nb/_config.yml
            Source: /aaron/nb
       Destination: /aaron/nb/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.493 seconds.
 Auto-regeneration: enabled for '/aaron/nb'
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- webrick (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve/servlet.rb:3:in `<top (required)>'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `require_relative'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:100:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ gem i webrick
Fetching webrick-1.7.0.gem
Successfully installed webrick-1.7.0
1 gem installed

$ jekyll s
Configuration file: /aaron/nb/_config.yml
            Source: /aaron/nb
       Destination: /aaron/nb/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.44 seconds.
 Auto-regeneration: enabled for '/aaron/nb'
    Server address: http://127.0.0.1:4000
  Server running... press ctrl-c to stop.
```

## Jekyll 2.0.0

1. [Collections](/docs/collections/) - Collections allow you to define an unlimited number of custom document types (beyond just posts and pages) for different types of content you may want to author in Jekyll such as API documentation or a cookbook!
2. [Brand new site template](https://github.com/jekyll/jekyll/pull/2050#issuecomment-35938016) (thanks [@jglovier][]!) - Getting started with Jekyll just got a lot easier and a lot more beautiful. Just run `jekyll new <path>` and you're good to go.
3. [Native Sass & CoffeeScript support](/docs/assets/) - We love CSS and JavaScript as much as the next guy, but there will always be a special place in our hearts for Sass and CoffeeScript. We now offer native support for these file types &mdash; no more messing around with Rake or Grunt!
4. [Front Matter defaults](/docs/configuration/front-matter-defaults/) - If you've set `layout: post` more than once in your life, you'll love this new feature: set front matter defaults for a given directory or type.
5. [Custom markdown processors](/docs/configuration/markdown/) - Always wanted to use your favourite home-grown Markdown converter, but couldn't with Jekyll? Now you can. Simply specify `markdown: MyConverterClass` and you're on your way.
6. [Addition of `where` and `group_by` Liquid filters](/docs/liquid/filters/) - Simplifying your Liquid templates one filter at a time. The `where` filter selects from an array all items within which have a given value for a property. The `group_by` filter groups all items in an array which have the same value for a given property.
7. [Switch from Maruku to Kramdown as default markdown converter](https://github.com/jekyll/jekyll/pull/1988) - Maruku is dead. We've replaced it with the converter which has the closest feature parity: Kramdown!


Happy developing!

[changelog]: /docs/history/
[@jglovier]: https://github.com/jglovier
```
[jekyll-1]: {% post_url 2013-05-06-jekyll-1-0-0-released %}
```
---

# 4.1.0

## number of words

* Jekyll's `number-of-words-filter` can now take an optional argument to better count words
of text containing Chinese, Japanese or Korean characters.

* One may now use `:slugified_categories` in their permalink configurations to generate a more apt URL (categories are
downcased and non-alphanumeric characters replaced by dashes) for their for posts and documents.

* The logic for *slugifying* a given string has been enhanced to support more Unicode characters.

* If you face issues from Jekyll's disk-caching feature, you can now disable the mechanism without opting to build in
`safe` mode, by either setting `disable_disk_cache: true` in your configuration file or by passing the CLI switch
`--disable-disk-cache` to `jekyll build` or `jekyll serve` commands.

* When you build a site with the `--profile` switch, Jekyll will now additionally output a small table showing the amount
of time taken during various stages of the *build process*.

## gem-based theme

* From `v4.1.0` onwards, a newly generated theme workspace (via `jekyll new-theme ...`) will have the gemspec configured
to bundle a `_config.yml` at the root of the workspace. If you don't wish to include the configuration file in the
released gem, please remove `|_config\.yml` from the regular expression in the gemspec.


```
{% comment %}
Might you have an include in your theme? Why not try it here!
{% include my-themes-great-include.html %}
{% endcomment %}


           Cleaner: Nothing to do for /aaron/pop-os/ashang.github.io/.jekyll-metadata.

 Incremental build: disabled. Enable with --incremental


with --incremental

           Cleaner: Removing /aaron/agi/.jekyll-metadata...

# jekyll

> A simple, blog-aware, static site generator.
> More information: <https://jekyllrb.com/docs/usage/>.

- Generate a development server that will run at http://localhost:4000/:

`jekyll serve`

- Enable incremental regeneration:

`jekyll serve --incremental`

```

$ jekyll s
Configuration file: /aaron/nb/_config.yml
  Dependency Error: Yikes! It looks like you don't have jekyll-feed or one of its dependencies installed. In order to use Jekyll as currently configured, you'll need to install this gem. If you've run Jekyll with `bundle exec`, ensure that you have included the jekyll-feed gem in your Gemfile as well. The full error message from Ruby is: 'cannot load such file -- jekyll-feed' If you run into trouble, you can find helpful resources at https://jekyllrb.com/help/!
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
/usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:73:in `rescue in block in require_with_graceful_fail': jekyll-feed (Jekyll::Errors::MissingDependencyException)
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:58:in `block in require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:30:in `require_gems'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:22:in `conscientious_require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:131:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:36:in `initialize'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `new'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- jekyll-feed (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:60:in `block in require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/external.rb:57:in `require_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:30:in `require_gems'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/plugin_manager.rb:22:in `conscientious_require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:131:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/site.rb:36:in `initialize'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `new'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/build.rb:30:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ gem i jekyll-feed
Fetching jekyll-feed-0.16.0.gem
Successfully installed jekyll-feed-0.16.0
1 gem installed

$ jekyll s
Configuration file: /aaron/nb/_config.yml
            Source: /aaron/nb
       Destination: /aaron/nb/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.493 seconds.
 Auto-regeneration: enabled for '/aaron/nb'
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- webrick (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve/servlet.rb:3:in `<top (required)>'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `require_relative'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:100:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ gem i webrick
Fetching webrick-1.7.0.gem
Successfully installed webrick-1.7.0
1 gem installed

$ jekyll s
Configuration file: /aaron/nb/_config.yml
            Source: /aaron/nb
       Destination: /aaron/nb/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.44 seconds.
 Auto-regeneration: enabled for '/aaron/nb'
    Server address: http://127.0.0.1:4000
  Server running... press ctrl-c to stop.
```

## Serve with specific path

```sh
bundle update --bundler
bundle install
bundle exec jekyll clean
exec jekyll serve -w -s /home/rstudio --incremental -d $XDG_RUNTIME_DIR/_site --host 0.0.0.0
```

## Trouble shooting

### Using the last argument as keyword parameters is deprecated

```sh
$ bundle exec jekyll serve
Configuration file: /home/aaron/notes/_config.yml
            Source: /home/aaron/notes
       Destination: /home/aaron/notes/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.612 seconds.
/home/aaron/.gem/ruby/gems/pathutil-0.16.2/lib/pathutil.rb:502:
warning: Using the last argument as keyword parameters is deprecated
 Auto-regeneration: enabled for '/home/aaron/notes'
    Server address: http://127.0.0.1:4000/
  Server running... press ctrl-c to stop.
[2022-07-11 13:45:31] ERROR `/favicon.ico' not found.
```

When a hash is the last argument in a method as keyword arguments, Ruby 2 converts this argument into keyword arguments.

This behavior is prone to be confusing, Ruby 2.7 will warn about this, and Ruby 3 requires hash splat.

Bump jekyll to `gem "jekyll", "~> 4.2.2"` in Gemfile, the warning disappears.

```sh
$ bundle exec jekyll serve --incremental
Configuration file: /home/aaron/notes/_config.yml
            Source: /home/aaron/notes
       Destination: /home/aaron/notes/_site
 Incremental build: enabled
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 1.4 seconds.
 Auto-regeneration: enabled for '/home/aaron/notes'
    Server address: http://127.0.0.1:4000
  Server running... press ctrl-c to stop.
```

## Layout

show_excerpts: true        # show article excerpts on the home page
show_frame: true           # adds a gray frame to the site
show_sidebar: false        # show a sidebar instead of the usual header

# Menu

navigation:                # accepts {file, title, url, icon, sidebaricon}
  - {file: "index.html"}
  - {file: "README.md"}

external:                  # shows a footer with social links - for available icons see fontawesome.com/icons
  - {title: Mail, icon: envelope, url: "mailto:niklasbuschmann@users.noreply.github.com"}
  - {title: Github, icon: github, url: "https://github.com/niklasbuschmann/contrast"}
  - {title: Subscribe, icon: rss, url: "/feed.xml"}

comments:
#  disqus_shortname: ""    # see https://disqus.com/
#  isso_domain: ""         # see https://posativ.org/isso/

## .jekyll-metadata

## .jekyll-cache

```sh
.jekyll-cache/Jekyll/Cache:

drwxrwxr-x 1 aaron aaron  4 Jul 21 13:57 Jekyll--Cache
drwxrwxr-x 1 aaron aaron 96 Jul 21 14:04 Jekyll--Converters--Markdown

.jekyll-cache/Jekyll/Cache/Jekyll--Cache:

-rw-rw-r-- 1 aaron aaron 2767 Jul 21 13:57 9606fb3afea5bd1609ed40b622142f1c98125abcfe89a76a661b0e8e343910

.jekyll-cache/Jekyll/Cache/Jekyll--Converters--Markdown/02:
-rw-rw-r-- 1 aaron aaron 942 Jul 21 13:58 2cc54274c07b4c86c0492f68c1f6958ea6b4a1d8ce07f3a3ef7e592a83cbe8
```

```sh
$ bundle exec jekyll serve --incremental --trace --watch --verbose --destination $XDG_RUNTIME_DIR/_site
  Logging at level: debug
    Jekyll Version: 4.2.2
Configuration file: /home/aaron/notes/_config.yml
  Logging at level: debug
    Jekyll Version: 4.2.2
            Source: /home/aaron/notes
       Destination: /run/user/1000/_site
 Incremental build: enabled
      Generating...
           Reading: /_layouts/default.html
           Reading: /_layouts/page.html
           Reading: /_layouts/post.html
       EntryFilter: excluded /Gemfile
       EntryFilter: excluded /Gemfile.lock
       EntryFilter: excluded /.jekyll-cache
           Reading: _posts/2010-01-22-nvm.md
           Reading: _posts/2010-02-19-armel.md
...
           Reading: assets/css/classes.sass
           Reading: assets/css/index.sass
           Reading: assets/css/minimal.sass
           Reading: assets/css/sidebar.sass
           Reading: assets/fontawesome/icons.svg
           Reading: archive.html
           Reading: readme.md
           Reading: index.md
           Reading: 404.md
           Reading: _data/font-awesome/icons.json
       Jekyll Feed: Generating feed for posts
        Generating: JekyllFeed::Generator finished in 0.00086884 seconds.
        Generating: Jekyll::JekyllSitemap finished in 0.002780563 seconds.
         Rendering: _posts/2014-11-03-rsync.md
  Pre-Render Hooks: _posts/2014-11-03-rsync.md
  Rendering Markup: _posts/2014-11-03-rsync.md
Post-Convert Hooks: _posts/2014-11-03-rsync.md
  Rendering Layout: _posts/2014-11-03-rsync.md
         Rendering: _posts/2014-11-03-rsync.md/#excerpt
  Pre-Render Hooks: _posts/2014-11-03-rsync.md/#excerpt
  Rendering Markup: _posts/2014-11-03-rsync.md/#excerpt
Post-Convert Hooks: _posts/2014-11-03-rsync.md/#excerpt

         Rendering: 404.md
  Pre-Render Hooks: 404.md
  Rendering Markup: 404.md
Post-Convert Hooks: 404.md
  Rendering Layout: 404.md
         Rendering: archive.html
  Pre-Render Hooks: archive.html
  Rendering Liquid: archive.html
  Rendering Markup: archive.html
Post-Convert Hooks: archive.html
  Rendering Layout: archive.html
         Rendering: assets/css/classes.sass
  Pre-Render Hooks: assets/css/classes.sass
  Rendering Liquid: assets/css/classes.sass
  Rendering Markup: assets/css/classes.sass
Post-Convert Hooks: assets/css/classes.sass
         Rendering: assets/fontawesome/icons.svg
  Pre-Render Hooks: assets/fontawesome/icons.svg
  Rendering Liquid: assets/fontawesome/icons.svg
  Rendering Markup: assets/fontawesome/icons.svg
Post-Convert Hooks: assets/fontawesome/icons.svg
  Rendering Layout: assets/fontawesome/icons.svg
         Rendering: index.md
  Pre-Render Hooks: index.md
  Rendering Liquid: index.md
  Rendering Markup: index.md
Post-Convert Hooks: index.md
  Rendering Layout: index.md
         Rendering: assets/css/index.sass
  Pre-Render Hooks: assets/css/index.sass
  Rendering Liquid: assets/css/index.sass
  Rendering Markup: assets/css/index.sass
Post-Convert Hooks: assets/css/index.sass
         Rendering: assets/css/minimal.sass
  Pre-Render Hooks: assets/css/minimal.sass
  Rendering Markup: assets/css/minimal.sass
Post-Convert Hooks: assets/css/minimal.sass
         Rendering: feed.xml
  Pre-Render Hooks: feed.xml
  Rendering Liquid: feed.xml
  Rendering Markup: feed.xml
Post-Convert Hooks: feed.xml
  Rendering Layout: feed.xml
         Rendering: sitemap.xml
  Pre-Render Hooks: sitemap.xml
  Rendering Liquid: sitemap.xml
  Rendering Markup: sitemap.xml
Post-Convert Hooks: sitemap.xml
  Rendering Layout: sitemap.xml
         Rendering: robots.txt
  Pre-Render Hooks: robots.txt
  Rendering Liquid: robots.txt
  Rendering Markup: robots.txt
Post-Convert Hooks: robots.txt
  Rendering Layout: robots.txt
         Rendering: assets/css/classes.css.map
  Pre-Render Hooks: assets/css/classes.css.map
  Rendering Markup: assets/css/classes.css.map
Post-Convert Hooks: assets/css/classes.css.map
         Rendering: assets/css/index.css.map
  Pre-Render Hooks: assets/css/index.css.map
  Rendering Markup: assets/css/index.css.map
Post-Convert Hooks: assets/css/index.css.map
         Rendering: assets/css/minimal.css.map
  Pre-Render Hooks: assets/css/minimal.css.map
  Rendering Markup: assets/css/minimal.css.map
Post-Convert Hooks: assets/css/minimal.css.map
         Rendering: assets/css/sidebar.css.map
  Pre-Render Hooks: assets/css/sidebar.css.map
  Rendering Markup: assets/css/sidebar.css.map
Post-Convert Hooks: assets/css/sidebar.css.map
           Writing: /run/user/1000/_site/404.html
           Writing: /run/user/1000/_site/archive/index.html
           Writing: /run/user/1000/_site/assets/css/classes.css
           Writing: /run/user/1000/_site/assets/fontawesome/icons.svg
           Writing: /run/user/1000/_site/index.html
           Writing: /run/user/1000/_site/assets/css/index.css
           Writing: /run/user/1000/_site/assets/css/minimal.css
           Writing: /run/user/1000/_site/about/index.html
           Writing: /run/user/1000/_site/assets/css/sidebar.css
           Writing: /run/user/1000/_site/feed.xml
           Writing: /run/user/1000/_site/sitemap.xml
           Writing: /run/user/1000/_site/robots.txt
           Writing: /run/user/1000/_site/assets/css/classes.css.map
           Writing: /run/user/1000/_site/assets/css/index.css.map
           Writing: /run/user/1000/_site/assets/css/minimal.css.map
           Writing: /run/user/1000/_site/assets/css/sidebar.css.map
           Writing: /run/user/1000/_site/nvm/index.html
...
           Writing: /run/user/1000/_site/sonic/index.html
  Writing Metadata: .jekyll-metadata
                    done in 8.687 seconds.
         Requiring: jekyll-watch
           Watcher: Ignoring (?-mix:^_config\.yml)
           Watcher: Ignoring (?-mix:^\.jekyll\-cache\/)
           Watcher: Ignoring (?-mix:^Gemfile)
           Watcher: Ignoring (?-mix:^Gemfile\.lock)
 Auto-regeneration: enabled for '/home/aaron/notes'
[2022-07-21 17:35:28] INFO  WEBrick 1.7.0
[2022-07-21 17:35:28] INFO  ruby 3.0.2 (2021-07-07) [x86_64-linux-gnu]
[2022-07-21 17:35:28] DEBUG WEBrick::HTTPServlet::FileHandler is mounted on /.
[2022-07-21 17:35:28] DEBUG unmount .
[2022-07-21 17:35:28] DEBUG Jekyll::Commands::Serve::Servlet is mounted on .
    Server address: http://127.0.0.1:4000/
[2022-07-21 17:35:28] INFO  WEBrick::HTTPServer#start: pid=11442 port=4000
  Server running... press ctrl-c to stop.
```

## Move static content to `static`
Jekyll has a rule that any directory not starting with `_` will be copied as-is to the `_site` output. Hugo keeps all static content under `static`. You should therefore move it all there.
With Jekyll, something that looked like

    ▾ <root>/
        ▾ images/
            logo.png

should become

    ▾ <root>/
        ▾ static/
            ▾ images/
                logo.png

Additionally, you'll want any files that should reside at the root (such as `CNAME`) to be moved to `static`.

## Create your Hugo configuration file
Hugo can read your configuration as JSON, YAML or TOML. Hugo supports parameters custom configuration too. Refer to the [Hugo configuration documentation](/overview/configuration/) for details.

## Set your configuration publish folder to `_site`
The default is for Jekyll to publish to `_site` and for Hugo to publish to `public`. If, like me, you have [`_site` mapped to a git submodule on the `gh-pages` branch](http://blog.blindgaenger.net/generate_github_pages_in_a_submodule.html), you'll want to do one of two alternatives:

1. Change your submodule to point to map `gh-pages` to public instead of `_site` (recommended).

        git submodule deinit _site
        git rm _site
        git submodule add -b gh-pages git@github.com:your-username/your-repo.git public

2. Or, change the Hugo configuration to use `_site` instead of `public`.

        {
            ..
            "publishdir": "_site",
            ..
        }

## Convert Jekyll templates to Hugo templates
That's the bulk of the work right here. The documentation is your friend. You should refer to [Jekyll's template documentation](http://jekyllrb.com/docs/templates/) if you need to refresh your memory on how you built your blog and [Hugo's template](/layout/templates/) to learn Hugo's way.

As a single reference data point, converting my templates for [heyitsalex.net](http://heyitsalex.net/) took me no more than a few hours.

## Convert Jekyll plugins to Hugo shortcodes
Jekyll has [plugins](http://jekyllrb.com/docs/plugins/); Hugo has [shortcodes](/doc/shortcodes/). It's fairly trivial to do a port.

### Implementation
As an example, I was using a custom [`image_tag`](https://github.com/alexandre-normand/alexandre-normand/blob/74bb12036a71334fdb7dba84e073382fc06908ec/_plugins/image_tag.rb) plugin to generate figures with caption when running Jekyll. As I read about shortcodes, I found Hugo had a nice built-in shortcode that does exactly the same thing.

Jekyll's plugin:

    module Jekyll
      class ImageTag < Liquid::Tag
        @url = nil
        @caption = nil
        @class = nil
        @link = nil
        // Patterns
        IMAGE_URL_WITH_CLASS_AND_CAPTION =
        IMAGE_URL_WITH_CLASS_AND_CAPTION_AND_LINK = /(\w+)(\s+)((https?:\/\/|\/)(\S+))(\s+)"(.*?)"(\s+)->((https?:\/\/|\/)(\S+))(\s*)/i
        IMAGE_URL_WITH_CAPTION = /((https?:\/\/|\/)(\S+))(\s+)"(.*?)"/i
        IMAGE_URL_WITH_CLASS = /(\w+)(\s+)((https?:\/\/|\/)(\S+))/i
        IMAGE_URL = /((https?:\/\/|\/)(\S+))/i
        def initialize(tag_name, markup, tokens)
          super
          if markup =~ IMAGE_URL_WITH_CLASS_AND_CAPTION_AND_LINK
            @class   = $1
            @url     = $3
            @caption = $7
            @link = $9
          elsif markup =~ IMAGE_URL_WITH_CLASS_AND_CAPTION
            @class   = $1
            @url     = $3
            @caption = $7
          elsif markup =~ IMAGE_URL_WITH_CAPTION
            @url     = $1
            @caption = $5
          elsif markup =~ IMAGE_URL_WITH_CLASS
            @class = $1
            @url   = $3
          elsif markup =~ IMAGE_URL
            @url = $1
          end
        end
        def render(context)
          if @class
            source = "<figure class='#{@class}'>"
          else
            source = "<figure>"
          end
          if @link
            source += "<a href=\"#{@link}\">"
          end
          source += "<img src=\"#{@url}\">"
          if @link
            source += "</a>"
          end
          source += "<figcaption>#{@caption}</figcaption>" if @caption
          source += "</figure>"
          source
        end
      end
    end
    Liquid::Template.register_tag('image', Jekyll::ImageTag)

is written as this Hugo shortcode:

    <!-- image -->
    <figure {{ with .Get "class" }}class="{{.}}"{{ end }}>
        {{ with .Get "link"}}<a href="{{.}}">{{ end }}
            <img src="{{ .Get "src" }}" {{ if or (.Get "alt") (.Get "caption") }}alt="{{ with .Get "alt"}}{{.}}{{else}}{{ .Get "caption" }}{{ end }}"{{ end }} />
        {{ if .Get "link"}}</a>{{ end }}
        {{ if or (or (.Get "title") (.Get "caption")) (.Get "attr")}}
        <figcaption>{{ if isset .Params "title" }}
            {{ .Get "title" }}{{ end }}
            {{ if or (.Get "caption") (.Get "attr")}}<p>
            {{ .Get "caption" }}
            {{ with .Get "attrlink"}}<a href="{{.}}"> {{ end }}
                {{ .Get "attr" }}
            {{ if .Get "attrlink"}}</a> {{ end }}
            </p> {{ end }}
        </figcaption>
        {{ end }}
    </figure>
    <!-- image -->

### Usage
I simply changed:

    {% image full http://farm5.staticflickr.com/4136/4829260124_57712e570a_o_d.jpg "One of my favorite touristy-type photos. I secretly waited for the good light while we were "having fun" and took this. Only regret: a stupid pole in the top-left corner of the frame I had to clumsily get rid of at post-processing." ->http://www.flickr.com/photos/alexnormand/4829260124/in/set-72157624547713078/ %}

to this (this example uses a slightly extended version named `fig`, different than the built-in `figure`):

    {{%/* fig class="full" src="http://farm5.staticflickr.com/4136/4829260124_57712e570a_o_d.jpg" title="One of my favorite touristy-type photos. I secretly waited for the good light while we were having fun and took this. Only regret: a stupid pole in the top-left corner of the frame I had to clumsily get rid of at post-processing." link="http://www.flickr.com/photos/alexnormand/4829260124/in/set-72157624547713078/" */%}}

As a bonus, the shortcode named parameters are, arguably, more readable.

## Finishing touches
### Fix content
Depending on the amount of customization that was done with each post with Jekyll, this step will require more or less effort. There are no hard and fast rules here except that `hugo server --watch` is your friend. Test your changes and fix errors as needed.

### Clean up
You'll want to remove the Jekyll configuration at this point. If you have anything else that isn't used, delete it.

## A practical example in a diff
[Hey, it's Alex](http://heyitsalex.net/) was migrated in less than a _father-with-kids day_ from Jekyll to Hugo. You can see all the changes (and screw-ups) by looking at this [diff](https://github.com/alexandre-normand/alexandre-normand/compare/869d69435bd2665c3fbf5b5c78d4c22759d7613a...b7f6605b1265e83b4b81495423294208cc74d610).


4.0.0:
`link` and `post_url` tags no longer need `site.baseurl` prepended every time they’re used, `relative_url` filter included.





If your code contains chars starting with `$\{\{` then you need to add `raw` block.

Below is not working example, the secrets.TOKEN won't display on the page:

{% highlight yml %}
echo ::set-env name=TOKEN::${{ secrets.TOKEN }}
{% endhighlight %}

Working example with `raw` block:

{% highlight yml %}
{% raw %}
echo ::set-env name=TOKEN::${{ secrets.TOKEN }}
{% endraw %}
{% endhighlight %}



bundle exec jekyll clean && bundle exec jekyll s -twDVI -H 10.10.50.14

Front Matter Defaults
Using front matter is one way that you can specify configuration in the pages and posts for your site. Setting things like a default layout, or customizing the title, or specifying a more precise date/time for the post can all be added to your page or post front matter.

Often times, you will find that you are repeating a lot of configuration options. Setting the same layout in each file, adding the same category - or categories - to a post, etc. You can even add custom variables like author names, which might be the same for the majority of posts on your blog.

Instead of repeating this configuration each time you create a new post or page, Jekyll provides a way to set these defaults in the site configuration. To do this, you can specify site-wide defaults using the defaults key in the _config.yml file in your project’s root directory.

The defaults key holds an array of scope/values pairs that define what defaults should be set for a particular file path, and optionally, a file type in that path.

Let’s say that you want to add a default layout to all pages and posts in your site. You would add this to your _config.yml file:

defaults:
  -
    scope:
      path: "" # an empty string here means all files in the project
    values:
      layout: "default"
Stop and rerun `jekyll serve` command.
The _config.yml master configuration file contains global configurations and variable definitions that are read once at execution time. Changes made to _config.yml during automatic regeneration are not loaded until the next execution.

Note Data Files are included and reloaded during automatic regeneration.

Here, we are scoping the values to any file that exists in the path scope. Since the path is set as an empty string, it will apply to all files in your project. You probably don’t want to set a layout on every file in your project - like css files, for example - so you can also specify a type value under the scope key.

defaults:
  -
    scope:
      path: "" # an empty string here means all files in the project
      type: "posts" # previously `post` in Jekyll 2.2.
    values:
      layout: "default"
Now, this will only set the layout for files where the type is posts. The different types that are available to you are pages, posts, drafts or any collection in your site. While type is optional, you must specify a value for path when creating a scope/values pair.

As mentioned earlier, you can set multiple scope/values pairs for defaults.

defaults:
  -
    scope:
      path: ""
      type: "pages"
    values:
      layout: "my-site"
  -
    scope:
      path: "projects"
      type: "pages" # previously `page` in Jekyll 2.2.
    values:
      layout: "project" # overrides previous default layout
      author: "Mr. Hyde"
With these defaults, all pages would use the my-site layout. Any html files that exist in the projects/ folder will use the project layout, if it exists. Those files will also have the page.author liquid variable set to Mr. Hyde.

collections:
  my_collection:
    output: true

defaults:
  -
    scope:
      path: ""
      type: "my_collection" # a collection in your site, in plural form
    values:
      layout: "default"
In this example, the layout is set to default inside the collection with the name my_collection.

Glob patterns in Front Matter defaultsPermalink
It is also possible to use glob patterns (currently limited to patterns that contain *) when matching defaults. For example, it is possible to set specific layout for each special-page.html in any subfolder of section folder.3.7.0

collections:
  my_collection:
    output: true

defaults:
  -
    scope:
      path: "section/*/special-page.html"
    values:
      layout: "specific-layout"
Globbing and Performance
Please note that globbing a path is known to have a negative effect on performance and is currently not optimized, especially on Windows. Globbing a path will increase your build times in proportion to the size of the associated collection directory.

PrecedencePermalink
Jekyll will apply all of the configuration settings you specify in the defaults section of your _config.yml file. You can choose to override settings from other scope/values pair by specifying a more specific path for the scope.

You can see that in the second to last example above. First, we set the default page layout to my-site. Then, using a more specific path, we set the default layout for pages in the projects/ path to project. This can be done with any value that you would set in the page or post front matter.

Finally, if you set defaults in the site configuration by adding a defaults section to your _config.yml file, you can override those settings in a post or page file. All you need to do is specify the settings in the post or page front matter. For example:

# In _config.yml
...
defaults:
  -
    scope:
      path: "projects"
      type: "pages"
    values:
      layout: "project"
      author: "Mr. Hyde"
      category: "project"
...
# In projects/foo_project.md
---
author: "John Smith"
layout: "foobar"
---
The post text goes here...
The projects/foo_project.md would have the layout set to foobar instead of project and the author set to John Smith instead of Mr. Hyde when the site is built.

GETTING STARTED
Quickstart
Installation
Ruby 101
Community
Step by Step Tutorial
BUILD
Command Line Usage
Configuration
Rendering Process
CONTENT
Pages
Posts
Front Matter
Collections
Data Files
Assets
Static Files
SITE STRUCTURE
Directory Structure
Liquid
Variables
Includes
Layouts
Permalinks
Themes
Pagination
GUIDES
Plugins
Blog Migrations
Upgrading
Deployment
Jekyll is lovingly maintained by the core team of volunteers.

The contents of this website are
© 2023 under the terms of the MIT License.

Proudly hosted by GitHub • Social codingJekyll is funded thanks to its sponsors!


----

How to loop through and render collections in Jekyll
30 May 2020
·
jekyll
Edit this post
{% for collection in site.collections %}
    {% if collection.label != 'posts' %}
        <h2>{{ collection.label }}</h2>
        {% for item in site[collection.label] %}
            <br><a href="{{ item.url }}">{{ item.title }}</a>
        {% endfor %}
    {% endif %}
{% endfor %}
Posts will count as a collection even if it's empty, so I have taken the step of filtering it out above.



Book Notes


View all 6 book notes





----
{% for themes in site.themes %}

<a href="{{ themes.url | prepend: site.baseurl }}">
  <h2>{{ themes.title }}</h2>
</a>

<p class="post-excerpt">{{ themes.description | truncate: 160 }}</p>

{% endfor %}



----

If you specify a directory to store all your collections in the same place with collections_dir: my_collections, then you will need to move your _drafts and _posts directory to my_collections/_drafts and my_collections/_posts. Note that, the name of your collections directory cannot start with an underscore (`_`).




 the posts collection is hard-coded into Jekyll. It exists whether you have a _posts directory or not. This is something to note when iterating through site.collections as you may need to filter it out.

You may wish to use filters to find your collection: {{ site.collections | where: "label", "myCollection" | first }}

----

## Move static content to `static`
Jekyll has a rule that any directory not starting with `_` will be copied as-is to the `_site` output. Hugo keeps all static content under `static`. You should therefore move it all there.
With Jekyll, something that looked like

    ▾ <root>/
        ▾ images/
            logo.png

should become

    ▾ <root>/
        ▾ static/
            ▾ images/
                logo.png

Additionally, you'll want any files that should reside at the root (such as `CNAME`) to be moved to `static`.

## Create your Hugo configuration file
Hugo can read your configuration as JSON, YAML or TOML. Hugo supports parameters custom configuration too. Refer to the [Hugo configuration documentation](/overview/configuration/) for details.

## Set your configuration publish folder to `_site`
The default is for Jekyll to publish to `_site` and for Hugo to publish to `public`. If, like me, you have [`_site` mapped to a git submodule on the `gh-pages` branch](http://blog.blindgaenger.net/generate_github_pages_in_a_submodule.html), you'll want to do one of two alternatives:

1. Change your submodule to point to map `gh-pages` to public instead of `_site` (recommended).

        git submodule deinit _site
        git rm _site
        git submodule add -b gh-pages git@github.com:your-username/your-repo.git public

2. Or, change the Hugo configuration to use `_site` instead of `public`.

        {
            ..
            "publishdir": "_site",
            ..
        }

## Convert Jekyll templates to Hugo templates
That's the bulk of the work right here. The documentation is your friend. You should refer to [Jekyll's template documentation](http://jekyllrb.com/docs/templates/) if you need to refresh your memory on how you built your blog and [Hugo's template](/layout/templates/) to learn Hugo's way.

As a single reference data point, converting my templates for [heyitsalex.net](http://heyitsalex.net/) took me no more than a few hours.

## Convert Jekyll plugins to Hugo shortcodes
Jekyll has [plugins](http://jekyllrb.com/docs/plugins/); Hugo has [shortcodes](/doc/shortcodes/). It's fairly trivial to do a port.

### Implementation
As an example, I was using a custom [`image_tag`](https://github.com/alexandre-normand/alexandre-normand/blob/74bb12036a71334fdb7dba84e073382fc06908ec/_plugins/image_tag.rb) plugin to generate figures with caption when running Jekyll. As I read about shortcodes, I found Hugo had a nice built-in shortcode that does exactly the same thing.

Jekyll's plugin:

    module Jekyll
      class ImageTag < Liquid::Tag
        @url = nil
        @caption = nil
        @class = nil
        @link = nil
        // Patterns
        IMAGE_URL_WITH_CLASS_AND_CAPTION =
        IMAGE_URL_WITH_CLASS_AND_CAPTION_AND_LINK = /(\w+)(\s+)((https?:\/\/|\/)(\S+))(\s+)"(.*?)"(\s+)->((https?:\/\/|\/)(\S+))(\s*)/i
        IMAGE_URL_WITH_CAPTION = /((https?:\/\/|\/)(\S+))(\s+)"(.*?)"/i
        IMAGE_URL_WITH_CLASS = /(\w+)(\s+)((https?:\/\/|\/)(\S+))/i
        IMAGE_URL = /((https?:\/\/|\/)(\S+))/i
        def initialize(tag_name, markup, tokens)
          super
          if markup =~ IMAGE_URL_WITH_CLASS_AND_CAPTION_AND_LINK
            @class   = $1
            @url     = $3
            @caption = $7
            @link = $9
          elsif markup =~ IMAGE_URL_WITH_CLASS_AND_CAPTION
            @class   = $1
            @url     = $3
            @caption = $7
          elsif markup =~ IMAGE_URL_WITH_CAPTION
            @url     = $1
            @caption = $5
          elsif markup =~ IMAGE_URL_WITH_CLASS
            @class = $1
            @url   = $3
          elsif markup =~ IMAGE_URL
            @url = $1
          end
        end
        def render(context)
          if @class
            source = "<figure class='#{@class}'>"
          else
            source = "<figure>"
          end
          if @link
            source += "<a href=\"#{@link}\">"
          end
          source += "<img src=\"#{@url}\">"
          if @link
            source += "</a>"
          end
          source += "<figcaption>#{@caption}</figcaption>" if @caption
          source += "</figure>"
          source
        end
      end
    end
    Liquid::Template.register_tag('image', Jekyll::ImageTag)

is written as this Hugo shortcode:

    <!-- image -->
    <figure {{ with .Get "class" }}class="{{.}}"{{ end }}>
        {{ with .Get "link"}}<a href="{{.}}">{{ end }}
            <img src="{{ .Get "src" }}" {{ if or (.Get "alt") (.Get "caption") }}alt="{{ with .Get "alt"}}{{.}}{{else}}{{ .Get "caption" }}{{ end }}"{{ end }} />
        {{ if .Get "link"}}</a>{{ end }}
        {{ if or (or (.Get "title") (.Get "caption")) (.Get "attr")}}
        <figcaption>{{ if isset .Params "title" }}
            {{ .Get "title" }}{{ end }}
            {{ if or (.Get "caption") (.Get "attr")}}<p>
            {{ .Get "caption" }}
            {{ with .Get "attrlink"}}<a href="{{.}}"> {{ end }}
                {{ .Get "attr" }}
            {{ if .Get "attrlink"}}</a> {{ end }}
            </p> {{ end }}
        </figcaption>
        {{ end }}
    </figure>
    <!-- image -->

### Usage
I simply changed:

    {% image full http://farm5.staticflickr.com/4136/4829260124_57712e570a_o_d.jpg "One of my favorite touristy-type photos. I secretly waited for the good light while we were "having fun" and took this. Only regret: a stupid pole in the top-left corner of the frame I had to clumsily get rid of at post-processing." ->http://www.flickr.com/photos/alexnormand/4829260124/in/set-72157624547713078/ %}

to this (this example uses a slightly extended version named `fig`, different than the built-in `figure`):

    {{</* fig class="full" src="http://farm5.staticflickr.com/4136/4829260124_57712e570a_o_d.jpg" title="One of my favorite touristy-type photos. I secretly waited for the good light while we were having fun and took this. Only regret: a stupid pole in the top-left corner of the frame I had to clumsily get rid of at post-processing." link="http://www.flickr.com/photos/alexnormand/4829260124/in/set-72157624547713078/" */>}}

As a bonus, the shortcode named parameters are, arguably, more readable.

## Finishing touches
### Fix content
Depending on the amount of customization that was done with each post with Jekyll, this step will require more or less effort. There are no hard and fast rules here except that `hugo server --watch` is your friend. Test your changes and fix errors as needed.

### Clean up
You'll want to remove the Jekyll configuration at this point. If you have anything else that isn't used, delete it.

## A practical example in a diff
[Hey, it's Alex](http://heyitsalex.net/) was migrated in less than a _father-with-kids day_ from Jekyll to Hugo. You can see all the changes (and screw-ups) by looking at this [diff](https://github.com/alexandre-normand/alexandre-normand/compare/869d69435bd2665c3fbf5b5c78d4c22759d7613a...b7f6605b1265e83b4b81495423294208cc74d610).

----
unpublished

----

    --disable-disk-cache

----

            <a title="{%- if site.description -%}{{ site.description }}{%- endif -%}" href="{{ __return }}">{{ site.title }}</a>

## absolute_url vs "prepend: site.baseurl | prepend: site.url"

```js
  <link rel="alternate" type="application/rss+xml" title="RSS" href="{{ '/atom.xml' | absolute_url }}">
  <link rel="alternate" type="application/rss+xml" title="{{ site.title }} Feed" href="{{ "/feed.xml" | prepend: site.baseurl | prepend: site.url }}">
```

```js
  <link rel="canonical" href="{{ page.url | replace:'/index.html','/' | prepend: site.baseurl | prepend: site.url }}">
  {% if page.url and site.baseurl %}
  <link rel="canonical" href="{{ page.url | absolute_url }}">
  {% endif %}
```


The main SCSS file must be with name "main.scss".

## Jekyll

Jekyll takes your content, renders Markdown and Liquid templates, and spits out a complete, static website.

```
jekyll command [argument] [option] [argument_to_option]
```

Examples:

```
#Outputs any deprecation or configuration issue
$ jekyll doctor

$ jekyll new site/ --blank
$ jekyll serve --config _alternative_config.yml
```

## Major changes

* `link` tag now comes with the `relative_url` filter incorporated into it.
  Hurray no more need to prepend `{% raw %}{{ site.baseurl }}{% endraw %}`.

* `post_url` tag now comes with the `relative_url` filter incorporated into it.
    You shouldn't prepend `{{ site.baseurl }}`.


```liquid
{% if post.content contains '<!--more-->' %}
    {{ post.content | split:'<!--more-->' | first }}
    <p class="read-more"><a href="{{ site.baseurl }}{{ post.url }}" class="more-link">Read More</a></p>
{% else %}
    {{ post.content }}
{% endif %}

<time class="post-date" datetime="{{ post.date | date: "%Y-%m-%d" }}">
</time>

<a href="{{ note.url | absolute_url }}">{{ note.title }}</a>


    {% include entry.html sticky='true' %}

In includede entry.html

    {% if include.sticky == 'true' %}
      <span class="entry">Pinned &middot;</span>
    {% endif %}
    <h1 class="title">{{ post.title }}</h1>
    <time datetime="{{ post.date }}" class="time">{{ post.date | date: "%B %d, %Y" }}</time>
    <div class="line"></div>

```

## Directories

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

- `_site`

Any files such as CSS, JS, and images will also end up here in an assets folder.

### Options

source: DIR

disable_disk_cache: BOOL

### How a Jekyll site works

Jekyll build order — setting up plugins, reading source files, running generators, rendering templates, and finally writing files to disk.

* The `_config.yml` file contains settings that Jekyll uses as it processes your site. An empty config file will use default values for building a Jekyll site. For example, to convert [Markdown](https://learnxinyminutes.com/docs/markdown/) to HTML, Jekyll will automatically use the [kramdown Markdown filter](https://rubygems.org/gems/kramdown/), without any need to specify it.
* Jekyll looks for files with [front matter tags]({% link _docs/front-matter.md %}) (the two sets of dashed lines `---` like those in `index.md`) and processes the files (populating site variables, rendering any [Liquid](https://shopify.github.io/liquid/), and converting Markdown to HTML).
* Jekyll pushes the content from all pages and posts into the {% raw %}`{{ content }}`{% endraw %} variable in the layout specified (`default`) in the front matter tags.
* The processed files get written as `.html` files in the `_site` directory.

The `_layouts` folder will be the template for your pages and posts.

[Liquid](https://shopify.github.io/liquid/) is [Jekyll templating system](/docs/liquid/) to retrieve dynamic content.

You will likely need to adjust CSS, JS, and image paths so they work.

{% raw %}
```liquid
{{ "/assets/style.css" | relative_url }}
```
{% endraw %}

The `relative_url` filter will prepend the [`baseurl`](https://byparker.com/blog/2014/clearing-up-confusion-around-baseurl/) value from your config file.

You can also use an `absolute_url` filter. This filter will prepend the `url` *and* `baseurl` value to the input:

{% raw %}
```liquid
{{ "/assets/style.css" | absolute_url }}
```
{% endraw %}

Note that the `url` property of any page begins with a forward slash (`/`), so omit this at the end of your `url` or `baseurl` property.

If you don't specify a layout in your pages, Jekyll will simply render that page as an unstyled basic HTML page.

Pages also have a [`title`](https://moz.com/learn/seo/title-tag) tag that appears in the browser tab or window. Typically you put the page title followed by the site title here.

{% raw %}
```liquid
<title>{{ page.title }} | {{ site.title }}</title>
```
{% endraw %}

## Incremental regeneration

Incremental regeneration helps shorten build times by only generating documents and pages that were updated since the previous build. It does this by keeping track of both file modification times and inter-document dependencies in the .jekyll-metadata file.

Under the current implementation, incremental regeneration will only generate a document or page if either it, or one of its dependencies, is modified. Currently, the only types of dependencies tracked are includes (using the {% include %} tag) and layouts. This means that plain references to other documents (for example, the common case of iterating over site.posts in a post listings page) will not be detected as a dependency.

## Filters

```html
<p>
  {{ page.description | truncate_words: 20 }}
</p>
```

## Case

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

## Includes (partials)

```
{% include header %}
```

Includes are created under the _includes/ directory. An include file is simply an HTML or Markdown file like any other. The only difference is that an include file has access to a special variable named include. The arguments (“props”) that you pass in to an include are then accessible under include.nameOfVariable.

For example, let’s say you want to use tooltips on your site but don’t want to have to copy-paste the same HTML each time you want to use one on a page. This is a perfect use case for includes:

```html
<!-- Including local vars -->
<div class="tooltip tooltip-{{ include.position }}">
    <div class="tooltip-text">
        {{ include.text }}
    </div>
</div>
```

Here’s how we might include a tooltip in another file:

```html
{% include tooltip.html position="top" text="This is a tooltip!" %}
```

Note that if var is not provided, include.var will default to nil (undefined).

## Comments

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

## Dates

```ruby
{{ site.time | date: "%Y %m %d" }}
```

| `date_to_xmlschema` | → `2008-11-07T13:07:54-08:00` |
| `date_to_rfc822` | → `Mon, 07 Nov 2008 13:07:54 -0800` |
| `date_to_string` | → `07 Nov 2008` |
| `date_to_long_string` | → `07 November 2008` |
| `date:` _'%Y %m %d'_ | → `2017 Nov  7` |

## Preprocessors

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

## Array filters

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

## String filters

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

## Highlightering

Jekyll offers powerful support for highlighting.

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

```html
{% highlight ruby linenos %}
def show
  ...
end
{% endhighlight %}
```

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


## Compass

* [Compass](https://gist.github.com/parkr/2874934)
* [Asset pipeline](https://github.com/matthodan/jekyll-asset-pipeline)
* [CloudCannon Jekyll cheatsheet](https://learn.cloudcannon.com/jekyll-cheat-sheet/) _cloudcannon.com_
* [Liquid: output](https://docs.shopify.com/themes/liquid-basics/output) _shopify.com_
* [Liquid: logic](https://docs.shopify.com/themes/liquid-basics/logic) _shopify.com_
* [Liquid: filters](https://docs.shopify.com/themes/liquid-documentation/filters) _shopify.com_
* [Liquid for designers](https://github.com/Shopify/liquid/wiki/Liquid-for-Designers) _github.com/Shopify_

## Theme

You can also package your layouts, includes and assets into a Ruby `gem` and make it a Jekyll theme.

## Tags

```
tags:
    - something
    - here
    - three
```

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

## Serve with specific path

```sh
bundle update --bundler
bundle install
bundle exec jekyll clean
exec jekyll serve -w -s /home/rstudio --incremental -d $XDG_RUNTIME_DIR/_site --host 0.0.0.0
```

# Menu

navigation:                # accepts {file, title, url, icon, sidebaricon}
  - {file: "index.html"}
  - {file: "README.md"}

external:                  # shows a footer with social links - for available icons see fontawesome.com/icons
  - {title: Mail, icon: envelope, url: "mailto:niklasbuschmann@users.noreply.github.com"}
  - {title: Github, icon: github, url: "https://github.com/niklasbuschmann/contrast"}
  - {title: Subscribe, icon: rss, url: "/feed.xml"}

comments:
#  disqus_shortname: ""    # see https://disqus.com/
#  isso_domain: ""         # see https://posativ.org/isso/

## .jekyll-metadata

## .jekyll-cache

```sh
.jekyll-cache/Jekyll/Cache:

drwxrwxr-x 1 aaron aaron  4 Jul 21 13:57 Jekyll--Cache
drwxrwxr-x 1 aaron aaron 96 Jul 21 14:04 Jekyll--Converters--Markdown

.jekyll-cache/Jekyll/Cache/Jekyll--Cache:

-rw-rw-r-- 1 aaron aaron 2767 Jul 21 13:57 9606fb3afea5bd1609ed40b622142f1c98125abcfe89a76a661b0e8e343910

.jekyll-cache/Jekyll/Cache/Jekyll--Converters--Markdown/02:
-rw-rw-r-- 1 aaron aaron 942 Jul 21 13:58 2cc54274c07b4c86c0492f68c1f6958ea6b4a1d8ce07f3a3ef7e592a83cbe8
```

## Liquid

### Liquid tags

For outputting content into a page, use two curly brackets on each side:{{ content }}
For logic/code, use a curly brackets and % sign on each side: {% if condition == true %}
Importantly, logic/code blocks must also have an “end” statement, for example {% endif %}, {% endfor %}

You can also set variables on pages:

{% assign myVariableName = Content of my variable; %}

https://jekyllrb.com/docs/liquid/filters/

### Linking to pages

To link to a post, a page, collection item, or file, the link tag will generate the correct permalink URL for the path you specify. For example, if you use the link tag to link to mypage.html, even if you change your permalink style to include the file extension or omit it, the URL formed by the link tag will always be valid.

You must include the file’s original extension when using the link tag. Here are some examples:

```
{% link _collection/name-of-document.md %}
{% link _posts/2016-07-26-name-of-post.md %}
{% link news/index.html %}
{% link /assets/files/doc.pdf %}
```

You can also use the link tag to create a link in Markdown as follows:

```
[Link to a document]({% link _collection/name-of-document.md %})
[Link to a post]({% link _posts/2016-07-26-name-of-post.md %})
[Link to a page]({% link news/index.html %})
[Link to a file]({% link /assets/files/doc.pdf %})
```

The path to the post, page, or collection is defined as the path relative to the root directory (where your config file is) to the file, not the path from your existing page to the other page.

One major benefit of using the link or post_url tag is link validation.
If the link doesn’t exist, Jekyll won’t build your site.

## Bundle and Bundler

### Bundler default

In `_plugins/bundler.rb`:

```ruby
require "bunder/setup"
Bundler.require :default
```

## Liquid

Jekyll uses the Liquid templating language to process templates.

Generally in Liquid you output content using two curly braces e.g. {{ variable }} and perform logic statements by surrounding them in a curly brace percentage sign.

- It needs to be non-evaling and secure. Liquid templates are made so that users can edit them. You don't want your server running code that your users wrote.
- It has to be stateless. The compile and render steps have to be separate, so that the expensive parsing and compiling can be done once; later on, you can just render it by passing in a hash with local variables and objects.

```ruby
@template = Liquid::Template.parse("hi {{name}}") # Parses and compiles the template
@template.render('name' => 'tobi')                # => "hi tobi"
```

### Filters

{{ "hi" | capitalize }}

<h1>{{ "Hello World!" | downcase }}</h1>

Where

Select all the objects in an array where the key has the given value.

```
{{ site.members | where:"graduation_year","2014" }}
```

Where Expression

Select all the objects in an array where the expression is true. 3.2.0

```
{{ site.members | where_exp:"item", "item.graduation_year == 2014" }}

{{ site.members | where_exp:"item", "item.graduation_year < 2014" }}

{{ site.members | where_exp:"item", "item.projects contains 'foo'" }}
```

```
...
Liquid Warning: Liquid syntax error (line 523): [:dot, "."] is not a valid expression in "{{.IPAddress}}" in .../k8s.md
Liquid Warning: Liquid syntax error (line 526): [:dot, "."] is not a valid expression in "{{ .NetworkSettings.IPAddress }}" in .../k8s.md
Liquid Warning: Liquid syntax error (line 529): Unexpected character $ in "{{ .NetworkSettings.Networks.$network.IPAddress }}" in .../k8s.md
Liquid Warning: Liquid syntax error (line 543): [:dot, "."] is not a valid expression in "{{ .NetworkSettings.IPAddress }}" in .../k8s.md
Liquid Warning: Liquid syntax error (line 550): [:dot, "."] is not a valid expression in "{{.Names}}" in .../k8s.md
Liquid Warning: Liquid syntax error (line 557): Unexpected character $ in "{{ .NetworkSettings.Networks.$network.IPAddress }}" in .../k8s.md
Liquid Warning: Liquid syntax error (line 579): [:dot, "."] is not a valid expression in "{{.IPAddress}}" in .../k8s.md
Liquid Warning: Liquid syntax error (line 584): [:dot, "."] is not a valid expression in "{{.Subnet}}" in .../k8s.md
Liquid Warning: Liquid syntax error (line 38): Unexpected character ` in "{{ trimPrefix `/` .Name }}" in .../apm.md
                    done in 0.433 seconds.
...
```

## Include

The include tag allows you to include the content from another file stored in the `_includes` folder:

{% include footer.html %}

The liquid tag {{ content }} is used to inject content into the web page.

You can choose to include file fragments relative to the current file by using the include_relative tag:

{% include_relative somedir/footer.html %}

the included file must be within the _posts directory or one of its subdirectories.

Note that you cannot use the ../ syntax to specify an include location that refers to a higher-level directory.

### Include variable

Create youtube.html in your _includes folder and paste this code into it:

```html
<div class="spacing youtube">
  <iframe width="560" height="315"
    src="https://www.youtube.com/embed/{{ include.youtube_id }}"
    frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
    allowfullscreen>
  </iframe>
</div>
```

Notice the placeholder for a YouTube video ID. Now, all we need to do is include our YouTube component in our page, with our unique code. Let’s add two to our

page to show how easily we can now display different videos:

```html
<p class="featured">Featured posts</p>
<h2 class="heading-secondary dark-blue">Latest videos</h2>
<div class="includes-grid">
  {% include youtube.html youtube_id="7W7hEUGtv4U" %>
  {% include youtube.html youtube_id="E3a88_SjJR0" %}
</div>
```

## Collections

```yaml
# /_authors/a-n-roquelaire.md
---
name: A. N. Roquelaire
real_name: Anne Rice
---
```

```yml
# _config.yml
collections:
  authors:
    output: true
```

## JEKYLL_ENV

JEKYLL_ENV=production bundle exec jekyll build

By default JEKYLL_ENV is development. The JEKYLL_ENV is available to you in liquid using jekyll.environment. So to only output the analytics script on production you would do the following:

```
{% if jekyll.environment == "production" %}
  <script src="my-analytics-script.js"></script>
{% endif %}
```

## Variable

content

In layout files, the rendered content of the Post or Page being wrapped. Not defined in Post or Page files.

site.static_files

A list of all static files (i.e. files not processed by Jekyll's converters or the Liquid renderer). Each file has five properties: path, modified_time, name, basename and extname.

site.html_pages

A subset of site.pages listing those which end in .html.

site.html_files

A subset of site.static_files listing those which end in .html.

site.collections

A list of all the collections (including posts).

site.documents

A list of all the documents in every collection.

site.tags.TAG

The list of all Posts with tag TAG.

page.url

The URL of the Post without the domain, but with a leading slash, e.g. /2008/12/14/my-post.html

page.tags

The list of tags to which this post belongs. These can be specified in the front matter.

page.dir

The path between the source directory and the file of the post or page, e.g. /pages/. This can be overridden by permalink in the front matter.

page.name

The filename of the post or page, e.g. about.md

page.path

The path to the raw post or page. Example usage: Linking back to the page or post’s source on GitHub. This can be overridden in the front matter.

page.next

The next post relative to the position of the current post in site.posts. Returns nil for the last entry.

page.previous

The previous post relative to the position of the current post in site.posts. Returns nil for the first entry.

## Data Files

```
_data/members.yml
```

```
{% for member in site.data.members %}
  ...
{% endfor %}
```

Jekyll will autoload all data files (using either the .yml, .yaml, .json, .csv or .tsv formats and extensions) in `_data` directory, and they will be accessible via `site.data`.

If there's a file members.yml under the directory, then you can access contents of the file through site.data.members.

Note that CSV and TSV files must contain a header row.

`_sass` partials that can be imported into your main.scss which will then be processed into a single stylesheet main.css that defines the styles to be used by your site.

Every file or directory beginning with the following characters: ., _ , # or ~ in the source directory will not be included in the destination folder. Such paths will have to be explicitly specified via the config file in the include directive to make sure they’re copied over:

This powerful feature allows you to avoid repetition in your templates and to set site specific options without changing _config.yml.

These files must be YAML, JSON, TSV or CSV files (using either the .yml, .yaml, .json, .tsv, or .csv extension), and they will be accessible via site.data.

Example: List of membersPermalink
Here is a basic example of using Data Files to avoid copy-pasting large chunks of code in your Jekyll templates:

In _data/members.yml:

- name: Eric Mill
  github: konklone

- name: Parker Moore
  github: parkr

- name: Liu Fengyun
  github: liufengyun


This data can be accessed via site.data.members (notice that the file’s basename determines the variable name and therefore one should avoid having data files with the same basename but different extensions, in the same directory).

You can now render the list of members in a template:

<ul>
{% for member in site.data.members %}
  <li>
    <a href="https://github.com/{{ member.github }}">
      {{ member.name }}
    </a>
  </li>
{% endfor %}
</ul>
SubfoldersPermalink
Data files can also be placed in sub-folders of the _data folder. Each folder level will be added to a variable’s namespace. The example below shows how GitHub organizations could be defined separately in a file under the orgs folder:

In _data/orgs/jekyll.yml:

username: jekyll
name: Jekyll
members:
  - name: Tom Preston-Werner
    github: mojombo

  - name: Parker Moore
    github: parkr


The organizations can then be accessed via site.data.orgs, followed by the file name:

<ul>
{% for org_hash in site.data.orgs %}
{% assign org = org_hash[1] %}
  <li>
    <a href="https://github.com/{{ org.username }}">
      {{ org.name }}
    </a>
    ({{ org.members | size }} members)
  </li>
{% endfor %}
</ul>


Data files can also be placed in sub-folders of the _data folder. Each folder level will be added to a variable’s namespace. The example below shows how GitHub organizations could be defined separately in a file under the orgs folder:

In _data/orgs/jekyll.yml:

username: jekyll
name: Jekyll
members:
  - name: Tom Preston-Werner
    github: mojombo

  - name: Parker Moore
    github: parkr


The organizations can then be accessed via site.data.orgs, followed by the file name:

<ul>
{% for org_hash in site.data.orgs %}
{% assign org = org_hash[1] %}
  <li>
    <a href="https://github.com/{{ org.username }}">
      {{ org.name }}
    </a>
    ({{ org.members | size }} members)
  </li>
{% endfor %}
</ul>

## UTF-8 Character Encoding Warning

If you use UTF-8 encoding, make sure that no BOM header characters exist in
  your files or very, very bad things will happen to Jekyll.

## assets

Sass is a fantastic extension to CSS

From your assets folder, create folders called css, images and js. Additionally, directly under the root create another folder called ‘_sass’,

First create a Sass file at assets/css/styles.scss with the following content:

```sass
---
---
@import "main";
```

The empty front matter at the top tells Jekyll it needs to process the file. The @import "main" tells Sass to look for a file called main.scss in the sass directory (_sass/) by default which you already created directly under the root folder of your website).

Create a Sass file at `_sass/main.scss` with the following content:

```sass
.current {
  color: green;
}
```

## Jekyll SASS

You have two kinds of Sass files:

1. Main files, which you wish to be output as CSS files
2. Partials, which are used by main files in `@import` statements

Main files are like pages – they go where you want them to be output, and they contain the YAML front matter (`---` lines) at the top. Partials are like hidden Jekyll data, so they go in an underscored directory, which defaults to `_sass`. You site might look like this:

    .
    | - _sass
      | - _typography.scss
      | - _layout.scss
      | - _colors.scss
    | - stylesheets
      | - screen.scss
      | - print.scss

And so on.

The output, in your `_site` directory, would look like this:

    .
    | - stylesheets
      | - screen.css
      | - print.css

### dart-sass

```sh
# Compiles style.scss to style.css.
$ sass style.scss:style.css

# Compiles light.scss and dark.scss to light.css and dark.css.
$ sass light.scss:light.css dark.scss:dark.css

# Compiles all Sass files in themes/ to CSS files in public/css/.
$ sass themes:public/css
```
Dart Sass supports two output styles:

- expanded (the default) writes each selector and declaration on its own line.
- compressed removes as many extra characters as possible, and writes the entire stylesheet on a single line.

```
$ sass --style=expanded style.scss
h1 {
  font-size: 40px;
}

$ sass --style=compressed style.scss
h1{font-size:40px}
```

### Sass Partials

By default, Sass transpiles all the .scss files directly. However, when you want to import a file, you do not need the file to be transpiled directly.

Sass has a mechanism for this: If you start the filename with an underscore, Sass will not transpile it. Files named this way are called partials in Sass.

So, a partial Sass file is named with a leading underscore:

Sass Partial Syntax:

 _filename;

The following example shows a partial Sass file named "_colors.scss". (This file will not be transpiled directly to "colors.css"):

Now, if you import the partial file, omit the underscore. Sass understands that it should import the file "_colors.scss":

@import "colors";

### jekyll-sass-converter

the Converter will by default generate a _source map_ file along with
the `.css` output file. The _source map_ is useful when we use the web developers tools of
[Chrome](https://developers.google.com/web/tools/chrome-devtools/) or
[Firefox](https://developer.mozilla.org/en-US/docs/Tools) to debug our `.sass` or `.scss`
stylesheets.

The _source map_ is a file that maps from the output `.css` file to the original source
`.sass` or `.scss` style sheets. Thus enabling the browser to reconstruct the original source
and present the reconstructed original in the debugger.


### Sass/SCSS

- <https://sass-lang.com/blog/libsass-is-deprecated>

## Front Matter

### Custom Front Matter

Between these triple-dashed lines, you can set predefined variables
or even create custom ones of your own. These variables will
  then be available for you to access using Liquid tags both further down in the
  file and also in any layouts or includes that the page or post in question
  relies on.

If you specify front matter in a layout, access that via layout. For example, if you specify class: full_page in a layout’s front matter, that value will be available as layout.class in the layout and its parents.

page.next

The next post relative to the position of the current post in site.posts. Returns nil for the last entry.

page.previous

The previous post relative to the position of the current post in site.posts. Returns nil for the first entry.


# JekyllImport::Importers::WordpressDotCom.run

```
$ ruby -rubygems -e 'require "jekyll-import";
    JekyllImport::Importers::WordpressDotCom.run({
      "source" => "wordpress.xml",
      "no_fetch_images" => false,
      "assets_folder" => "assets"
    })'


```

For pages or posts you need no front matter at all. You create a file, name it and Jekyll uses the file name automatically if you don’t add title to front matter.

## coderay syntax highlighter

## Initialize Bundler

The first thing to do is create a new directory for your project and run
`bundle init`. This creates a new Bundler project (by creating an empty
Gemfile).

```sh
mkdir my-jekyll-website
cd my-jekyll-website
bundle init
```

## Configure Bundler Install Path

This step is optional. In this step, we're going to configure Bundler to install
gems in the `./vendor/bundle/` project subdirectory. The advantage of doing this
is that bundler will install gems within your project folder instead of the
location used by `gem install`. This can help you avoid permissions errors you
might otherwise get during gem installation, depending how you installed Ruby.
If you skip this step, Bundler will install your dependencies to the location
used by `gem install`.


```sh
bundle config set --local path 'vendor/bundle'
```

<div class="note info">
  <h5>Bundler Config is Persistent</h5>
  <p>
    This step is only required once per project. Bundler saves your config in
    <code>./.bundle/config</code>, so future gems will be installed to the same
    location.
  </p>
</div>

## Add Jekyll

Now, we're going to use Bundler to add Jekyll as a dependency of our new
project. This command will add the Jekyll gem to our Gemfile and install it to
the `./vendor/bundle/` folder (or your default gem installation directory if you
didn't set a custom path).

```sh
bundle add jekyll
```

## Create A Jekyll Scaffold

Now that Jekyll is installed, we can use it to create the scaffolding for our
site. We need the `--force` parameter because our folder isn't empty - it
already has some Bundler files in it. We run the `bundle install` separately
because Jekyll gets confused if the Gemfile already exists.

```sh
bundle exec jekyll new --force --skip-bundle .
bundle install
```

* Detect non-existent variables and filters specified in a template by enabling `strict_variables` and `strict_filters` under the `liquid` key in your config file.

## `slugify` filter with `latin` option

I18n lib

### How layouts work

When a layout specifies another layout, it means the content of the first layout will be stuffed into the {% raw %}`{{ content }}`{% endraw %} tag of the second layout.

In general, it's common to define one layout for pages and another layout for posts, but for both of these layouts to inherit the `default` template (which usually defines the top and bottom parts of the site).

A layout should contain {% raw %}`{{ content }}`{% endraw %}, which acts as a receiver for the *content* to be rendered.

### For loops

You could do so by adding a `categories` property to your post's front matter and then look in those categories. Further, you could limit the number of results by adding a `limit` property. Here's an example:

{% raw %}
```liquid
<ul class="myposts">
{% for post in site.categories.podcasts limit:3 %}
    <li><a href="{{ post.url }}">{{ post.title}}</a>
    <span class="postDate">{{ post.date | date: "%b %-d, %Y" }}</span>
    </li>
{% endfor %}
</ul>
```
{% endraw %}

{% raw %}
```liquid
<ul>
  {% assign mypages = site.pages | sort: "order" %}
    {% for page in mypages %}
    <li><a href="{{ page.url | absolute_url }}">{{ page.title }}</a></li>
    {% endfor %}
</ul>
```
{% endraw %}

```yaml
---
title: My page
order: 2
---
```

Here the `order` property will define how the pages get sorted, with `1` appearing first in the list.

You could also iterate through a list of pages that you maintain in a separate data file. This might be more appropriate if you have a lot of pages, or you have other properties about the pages you want to store.

To manage page links this way, create a folder in your Jekyll project called `_data`. In this folder, create a file called e.g. `navigation.yml` with this content:

```yaml
- title: Sample page 1
  url: /page-1-permalink/

- title: Sample page 2
  url: /page-2-permalink/

- title: Sample page 3
  url: /page-3-permalink/
```

Arrange the list items in the order you want them to appear.

To print the list of pages from the data file, use code like this:

{% raw %}
```liquid
<ul>
    {% for link in site.data.navigation %}
    <li><a href="{{ link.url }}">{{ link.title }}</a></li>
    {% endfor %}
</ul>
```
{% endraw %}

## feed

[RSS feed syntax](http://www.w3schools.com/xml/xml_rss.asp)

{% raw %}
```liquid
---
layout: null
---

<?xml version="1.0" encoding="UTF-8" ?>
<rss version="2.0">

    <channel>
        <title>{{ site.title }}</title>
        <link>{{ site.url }}</link>
        <atom:link href="{{ page.url | prepend: site.url }}" rel="self" type="application/rss+xml" />
        <description>{{ site.description }}</description>
        <lastBuildDate>{{ site.time | date_to_rfc822 }}</lastBuildDate>
        {% for post in site.posts %}
        <item>
            <title>{{ post.title }}</title>
            <link>
                {{ post.url | prepend: site.url }}
            </link>
            <description>
                {{ post.content | escape | truncate: '400' }}
            </description>
            <pubDate>{{ post.date | date_to_rfc822 }}</pubDate>
            <guid>
                {{ post.url | prepend: site.url }}
            </guid>
        </item>
        {% endfor %}
    </channel>
</rss>
```
{% endraw %}

## Sitemap

Finally, add a [site map](https://www.sitemaps.org/protocol.html).

Create a `sitemap.xml` file in your root directory and add this code:

{% raw %}
```liquid
---
layout: null
search: exclude
---

<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">

    {% for page in site.pages %}
    <url>
        <loc>{{page.url}}</loc>
        <lastmod>{{site.time | date: '%Y-%m-%d' }}</lastmod>
        <changefreq>daily</changefreq>
        <priority>0.5</priority>
    </url>
    {% endfor %}

    {% for post in site.posts %}
    <url>
        <loc>{{post.url}}</loc>
        <lastmod>{{site.time | date: '%Y-%m-%d' }}</lastmod>
        <changefreq>daily</changefreq>
        <priority>0.5</priority>
    </url>
    {% endfor %}

</urlset>
```
{% endraw %}


You can also auto-generate your sitemap by adding a gem called [`jekyll-sitemap`](https://help.github.com/articles/sitemaps-for-github-pages/).

## 12. Add external services

For other services you might need (such as contact forms, search, comments, and more), [look for third-party services](https://serverless.css-tricks.com/services/major). We listed some [integrations on our resources page](/resources/#integrations) but in todays's world of SaaS and APis the list is endless.

Your Jekyll pages consist of HTML, CSS, and JavaScript, so pretty much any code you need to embed will work without a problem.

As you integrate code for these services, note that **if a page in your Jekyll site doesn't have front matter tags, Jekyll won't process any of the content in that page.** The page will just be passed to the `_site` folder when you build your site.

If you do want Jekyll to process some page content (for example, to populate a variable that you define in your site's config file), just add front matter tags to the page. If you don't want any layout applied to the page, specify `layout: null` like this:

```yaml
---
layout: null
---
```

## Deploy

* [GitHub Pages](https://pages.github.com/)
- [Netlify](https://www.netlify.com/)
- [Vercel](https://vercel.com)
- [Render](https://render.com)
- [Amazon AWS S3](https://aws.amazon.com/s3/) using the [s3_website plugin](https://github.com/laurilehmijoki/s3_website)
- To rsync files to web server.

## Additional resources

* <https://docs.github.com/en/pages>
* [Convert a static site to Jekyll](http://jekyll.tips/jekyll-casts/converting-a-static-site-to-jekyll/)
* [Building a Jekyll Site – Part 1 of 3: Converting a Static Website To Jekyll](https://css-tricks.com/building-a-jekyll-site-part-1-of-3/)

## Pygments

## RedCarpet

## rdiscount

## kramdown

- v2

## Trouble shooting

### webrick not ruby built-in

```
...
                    ------------------------------------------------
      Jekyll 4.2.2   Please append `--trace` to the `serve` command
                     for any additional information or backtrace.
                    ------------------------------------------------
<internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require': cannot load such file -- webrick (LoadError)
        from <internal:/usr/lib/ruby/3.0.0/rubygems/core_ext/kernel_require.rb>:85:in `require'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve/servlet.rb:3:in `<top (required)>'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `require_relative'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:179:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:100:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.2/exe/jekyll:15:in `<top (required)>'
        from /aaron/.gem/ruby/bin/jekyll:25:in `load'
        from /aaron/.gem/ruby/bin/jekyll:25:in `<main>'

$ bundle add webrick
$ bundle exec jekyll serve --incremental --trace --livereload
...
 Auto-regeneration: enabled for '.'
    Server address: http://127.0.0.1:4000/
LiveReload address: http://127.0.0.1:35729
  Server running... press ctrl-c to stop.
        LiveReload: Browser connected

$ bundle exec jekyll serve --incremental --trace --watch --verbose --destination $XDG_RUNTIME_DIR/_site
  Logging at level: debug
    Jekyll Version: 4.2.2
Configuration file: /home/aaron/notes/_config.yml
  Logging at level: debug
    Jekyll Version: 4.2.2
            Source: /home/aaron/notes
       Destination: /run/user/1000/_site
 Incremental build: enabled
      Generating...
           Reading: /_layouts/default.html
           Reading: /_layouts/page.html
           Reading: /_layouts/post.html
       EntryFilter: excluded /Gemfile
       EntryFilter: excluded /Gemfile.lock
       EntryFilter: excluded /.jekyll-cache
           Reading: _posts/2010-01-22-nvm.md
           Reading: _posts/2010-02-19-armel.md
...
           Reading: assets/fontawesome/icons.svg
           Reading: archive.html
           Reading: readme.md
           Reading: index.md
           Reading: 404.md
           Reading: _data/font-awesome/icons.json
       Jekyll Feed: Generating feed for posts
        Generating: JekyllFeed::Generator finished in 0.00086884 seconds.
        Generating: Jekyll::JekyllSitemap finished in 0.002780563 seconds.
         Rendering: _posts/2014-11-03-rsync.md
  Pre-Render Hooks: _posts/2014-11-03-rsync.md
  Rendering Markup: _posts/2014-11-03-rsync.md
Post-Convert Hooks: _posts/2014-11-03-rsync.md
  Rendering Layout: _posts/2014-11-03-rsync.md
         Rendering: _posts/2014-11-03-rsync.md/#excerpt
  Pre-Render Hooks: _posts/2014-11-03-rsync.md/#excerpt
  Rendering Markup: _posts/2014-11-03-rsync.md/#excerpt
Post-Convert Hooks: _posts/2014-11-03-rsync.md/#excerpt

         Rendering: 404.md
  Pre-Render Hooks: 404.md
  Rendering Markup: 404.md
Post-Convert Hooks: 404.md
  Rendering Layout: 404.md
         Rendering: archive.html
  Pre-Render Hooks: archive.html
  Rendering Liquid: archive.html
  Rendering Markup: archive.html
Post-Convert Hooks: archive.html
  Rendering Layout: archive.html
Post-Convert Hooks: assets/css/minimal.sass
         Rendering: feed.xml
  Rendering Layout: sitemap.xml
         Rendering: robots.txt
         Rendering: assets/css/classes.css.map
           Writing: /run/user/1000/_site/404.html
           Writing: /run/user/1000/_site/assets/css/minimal.css.map
           Writing: /run/user/1000/_site/nvm/index.html
...
           Writing: /run/user/1000/_site/sonic/index.html
  Writing Metadata: .jekyll-metadata
                    done in 8.687 seconds.
         Requiring: jekyll-watch
           Watcher: Ignoring (?-mix:^_config\.yml)
           Watcher: Ignoring (?-mix:^\.jekyll\-cache\/)
           Watcher: Ignoring (?-mix:^Gemfile)
           Watcher: Ignoring (?-mix:^Gemfile\.lock)
 Auto-regeneration: enabled for '/home/aaron/notes'
[2022-07-21 17:35:28] INFO  WEBrick 1.7.0
[2022-07-21 17:35:28] INFO  ruby 3.0.2 (2021-07-07) [x86_64-linux-gnu]
[2022-07-21 17:35:28] DEBUG WEBrick::HTTPServlet::FileHandler is mounted on /.
[2022-07-21 17:35:28] DEBUG unmount .
[2022-07-21 17:35:28] DEBUG Jekyll::Commands::Serve::Servlet is mounted on .
    Server address: http://127.0.0.1:4000/
[2022-07-21 17:35:28] INFO  WEBrick::HTTPServer#start: pid=11442 port=4000
  Server running... press ctrl-c to stop.
```

### Using the last argument as keyword parameters is deprecated

```sh
$ bundle exec jekyll serve
Configuration file: /home/aaron/notes/_config.yml
            Source: /home/aaron/notes
       Destination: /home/aaron/notes/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 0.612 seconds.
/home/aaron/.gem/ruby/gems/pathutil-0.16.2/lib/pathutil.rb:502:
warning: Using the last argument as keyword parameters is deprecated
 Auto-regeneration: enabled for '/home/aaron/notes'
    Server address: http://127.0.0.1:4000/
  Server running... press ctrl-c to stop.
[2022-07-11 13:45:31] ERROR `/favicon.ico' not found.
```

When a hash is the last argument in a method as keyword arguments, Ruby 2 converts this argument into keyword arguments.

This behavior is prone to be confusing, Ruby 2.7 will warn about this, and Ruby 3 requires hash splat.

Bump jekyll to `gem "jekyll", "~> 4.2.2"` in Gemfile, the warning disappears.

```sh
$ bundle exec jekyll serve --incremental
Configuration file: /home/aaron/notes/_config.yml
            Source: /home/aaron/notes
       Destination: /home/aaron/notes/_site
 Incremental build: enabled
      Generating...
       Jekyll Feed: Generating feed for posts
                    done in 1.4 seconds.
 Auto-regeneration: enabled for '/home/aaron/notes'
    Server address: http://127.0.0.1:4000
  Server running... press ctrl-c to stop.
```

- <https://docs.github.com/en/pages/setting-up-a-github-pages-site-with-jekyll/troubleshooting-jekyll-build-errors-for-github-pages-sites#file-does-not-exist-in-includes-directory>
- <https://docs.github.com/en/pages/configuring-a-custom-domain-for-your-github-pages-site/troubleshooting-custom-domains-and-github-pages>


icon: jekyll.png
website: https://jekyllrb.com
syntax:
  - id: headings
    available: y
  - id: paragraphs
    available: y
  - id: line-breaks
    available: y
  - id: bold
    available: y
  - id: italic
    available: y
  - id: blockquotes
    available: y
  - id: ordered-lists
    available: y
  - id: unordered-lists
    available: y
  - id: code
    available: y
  - id: horizontal-rules
    available: y
  - id: links
    available: y
  - id: images
    available: y
  - id: tables
    available: y
  - id: fenced-code-blocks
    available: y
  - id: syntax-highlighting
    available: y
    notes: "Make sure that `syntax_highlighter: rouge` is in the `kramdown` section of the `_config.yml` file."
  - id: footnotes
    available: y
  - id: heading-ids
    available: y
  - id: definition-lists
    available: y
  - id: strikethrough
    available: y
    notes: "You can use two tildes (`~~word~~`) or one tilde (`~word~`) — both work."
  - id: task-lists
    available: y
  - id: emoji-cp
    available: y
  - id: emoji-sc
    available: n
    notes: "Not supported by default, but you can use the [jemoji](https://github.com/jekyll/jemoji) plugin to enable support."
  - id: highlight
    available: n
  - id: subscript
    available: n
  - id: superscript
    available: n
  - id: auto-url-linking
    available: y
  - id: disabling-auto-url
    available: y
  - id: html
    available: y
see-also:
  - name: Jekyll Markdown configuration options
    link: https://jekyllrb.com/docs/configuration/markdown/
  - name: kramdown documentation
    link: https://kramdown.gettalong.org/
---


Smartify

Convert "quotes" into “smart quotes.”

{{ page.title | smartify }}


[Jekyll](https://jekyllrb.com) is a static site generator that takes Markdown files and converts them to a website. Jekyll is a free and open-source application written in the Ruby programming language. Thousands of websites, including the *Markdown Guide*, rely on Jekyll to convert Markdown source files to HTML output. [GitHub Pages](/tools/github-pages/) uses Jekyll as the backend for its free website creation service.

By default, Jekyll uses the [kramdown](https://kramdown.gettalong.org/) Markdown processor with stock settings, but you can enable other kramdown options or even switch Jekyll to another Markdown processor. See the [Jekyll Markdown configuration options](https://jekyllrb.com/docs/configuration/markdown/) documentation for more information. You can change Jekyll's kramdown settings in the `_config.yml` file. The settings for the *Markdown Guide* are shown below.

```yaml
kramdown:
  syntax_highlighter: rouge
  input: GFM
  auto_ids:       true
  toc_levels:     1..3
```

{% include tool-syntax-table.html %}

### Support for Additional Syntax Elements

As an added bonus, Jekyll provides support for several obscure elements.

<table class="table table-bordered" style="font-size: 14px">
  <thead class="thead-light">
    <tr>
      <th>Element</th>
      <th>Markdown</th>
      <th>Rendered Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Abbreviation</td>
      <td><code>*[HTML]: Hyper Text Markup Language</code><br>
      <code>The HTML specification is maintained by the W3C.</code></td>
      <td>The <abbr title="Hyper Text Markup Language">HTML</abbr> specification
is maintained by the W3C.</td>
    </tr>
  </tbody>
</table>





```liquid
<script type="math/tex; mode=display">f^{(n)}(z) = \frac{n !}{2 \pi i} \int_{C}\! \frac{f(\zeta)}{(\zeta - z)^{n+1}} \mathrm{d}\zeta</script>
```

Can this be rendered?

<script type="math/tex; mode=display">f^{(n)}(z) = \frac{n !}{2 \pi i} \int_{C}\! \frac{f(\zeta)}{(\zeta - z)^{n+1}} \mathrm{d}\zeta</script>

```txt
         1         2         3         4         5         6         7         8
12345678901234567890123456789012345678901234567890123456789012345678901234567890
```

0         1         2         3         4         5         6         7         8

012345678901234567890123456789012345678901234567890123456789012345678901234567890

- <https://www.kernel.org/finger_banner>

## Features

- supports dark mode on macOS Mojave
- optional sidebar
- MathJax support
- no external ressources
- included archive page
- supports pagination
- Feed.xml generation
- responsive
- syntax highlighting
- supports comments via [disqus](https://disqus.com/) or [isso](http://posativ.org/isso/)

*(Note: An update to the version of Jekyll/Kramdown used by github.io broke
this feature a bit.  [I raised an issue on Contrast's GitHub.][5])*

[5]: https://github.com/niklasbuschmann/contrast/issues/28

I'll mention this uses the [Liquid][6] templating system so I can find the
documentation later when I need it.

[6]: https://shopify.dev/docs/themes/liquid/reference

Note: to enable icons you also need to copy over the `_data` folder.

## MathJax leightweight alternative [KaTeX](https://katex.org/).

A leightweight alternative to MathJax called [KaTeX](https://katex.org/).

Enable MathJax by setting `mathjax: true` on a page or globally in the `_config.yml`.

[Euler's formula](https://en.wikipedia.org/wiki/Euler%27s_formula) relates the  complex exponential function to the trigonometric functions.

$$ e^{i\theta}=\cos(\theta)+i\sin(\theta) $$

The [Euler-Lagrange](https://en.wikipedia.org/wiki/Lagrangian_mechanics) differential equation is the fundamental equation of calculus of variations.

$$ \frac{\mathrm{d}}{\mathrm{d}t} \left ( \frac{\partial L}{\partial \dot{q}} \right ) = \frac{\partial L}{\partial q} $$

The [Schrödinger equation](https://en.wikipedia.org/wiki/Schr%C3%B6dinger_equation) describes how the quantum state of a quantum system changes with time.

$$ i\hbar\frac{\partial}{\partial t} \Psi(\mathbf{r},t) = \left [ \frac{-\hbar^2}{2\mu}\nabla^2 + V(\mathbf{r},t)\right ] \Psi(\mathbf{r},t) $$

## Code

Embed code by putting `{{ "{% highlight language " }}%}` `{{ "{% endhighlight " }}%}` blocks around it. Adding the parameter `linenos` will show source lines besides the code.

{% highlight c linenos %}
static void asyncEnabled(Dict* args, void* vAdmin, String* txid, struct Allocator* requestAlloc)
{
    struct Admin* admin = Identity_check((struct Admin*) vAdmin);
    int64_t enabled = admin->asyncEnabled;
    Dict d = Dict_CONST(String_CONST("asyncEnabled"), Int_OBJ(enabled), NULL);
    Admin_sendMessage(&d, txid, admin);
}
{% endhighlight %}

**`linenos` not working with the 3-backtttt code block style.**

```c
static void asyncEnabled(Dict* args, void* vAdmin, String* txid, struct Allocator* requestAlloc)
{
    struct Admin* admin = Identity_check((struct Admin*) vAdmin);
    int64_t enabled = admin->asyncEnabled;
    Dict d = Dict_CONST(String_CONST("asyncEnabled"), Int_OBJ(enabled), NULL);
    Admin_sendMessage(&d, txid, admin);
}
```


```
$ jekyll new-theme jekyll-thepro
             create /aaron/public/jekyll-thepro/assets
             create /aaron/public/jekyll-thepro/_data
             create /aaron/public/jekyll-thepro/_layouts
             create /aaron/public/jekyll-thepro/_includes
             create /aaron/public/jekyll-thepro/_sass
             create /aaron/public/jekyll-thepro/_layouts/page.html
             create /aaron/public/jekyll-thepro/_layouts/post.html
             create /aaron/public/jekyll-thepro/_layouts/default.html
             create /aaron/public/jekyll-thepro/Gemfile
             create /aaron/public/jekyll-thepro/jekyll-thepro.gemspec
             create /aaron/public/jekyll-thepro/README.md
             create /aaron/public/jekyll-thepro/LICENSE.txt
         initialize /aaron/public/jekyll-thepro/.git
             create /aaron/public/jekyll-thepro/.gitignore
Your new Jekyll theme, jekyll-thepro, is ready for you in /aaron/public/jekyll-thepro!
```

```
$ jekyll new jekyll
Running bundle install in /aaron/public/jekyll...
  Bundler: Fetching source index from https://mirrors.tuna.tsinghua.edu.cn/rubygems/
  Bundler: Resolving dependencies...
  Bundler: Using public_suffix 5.0.1
  Bundler: Using bundler 2.4.2
  Bundler: Using colorator 1.1.0
  Bundler: Using concurrent-ruby 1.2.2
  Bundler: Using eventmachine 1.2.7
  Bundler: Using http_parser.rb 0.8.0
  Bundler: Using ffi 1.15.5
  Bundler: Using forwardable-extended 2.6.0
  Bundler: Using google-protobuf 3.22.0 (x86_64-linux)
  Bundler: Using rb-fsevent 0.11.2
  Bundler: Using rexml 3.2.5
  Bundler: Using liquid 4.0.4
  Bundler: Using mercenary 0.4.0
  Bundler: Using rouge 4.1.0
  Bundler: Using safe_yaml 1.0.5
  Bundler: Using unicode-display_width 2.4.2
  Bundler: Using webrick 1.8.1
  Bundler: Using addressable 2.8.1
  Bundler: Using em-websocket 0.5.3
  Bundler: Using i18n 1.12.0
  Bundler: Using sass-embedded 1.58.3 (x86_64-linux-gnu)
  Bundler: Using rb-inotify 0.10.1
  Bundler: Using kramdown 2.4.0
  Bundler: Using pathutil 0.16.2
  Bundler: Using terminal-table 3.0.2
  Bundler: Using jekyll-sass-converter 3.0.0
  Bundler: Using listen 3.8.0
  Bundler: Using kramdown-parser-gfm 1.1.0
  Bundler: Using jekyll-watch 2.2.1
  Bundler: Using jekyll 4.3.2
  Bundler: Using jekyll-feed 0.17.0
  Bundler: Using jekyll-seo-tag 2.8.0
  Bundler: Using minima 2.5.1
  Bundler: Bundle complete! 7 Gemfile dependencies, 33 gems now installed.
  Bundler: Use `bundle info [gemname]` to see where a bundled gem is installed.
New jekyll site installed in /aaron/public/jekyll.
```

```
$ tree jekyll
jekyll
├── 404.html
├── about.markdown
├── _config.yml
├── Gemfile
├── Gemfile.lock
├── index.markdown
└── _posts
    └── 2023-03-04-welcome-to-jekyll.markdown
```

```
        ** ERROR: directory is already being watched! **

        Directory: /aaron/site/content/_posts

        is already being watched through: /aaron/site/content/_posts

        MORE INFO: https://github.com/guard/listen/blob/master/README.md
[2023-03-04 21:35:04] INFO  WEBrick 1.8.1
[2023-03-04 21:35:04] INFO  ruby 3.0.5 (2022-11-24) [x86_64-linux]
[2023-03-04 21:35:04] DEBUG WEBrick::HTTPServlet::FileHandler is mounted on /.
[2023-03-04 21:35:04] DEBUG unmount .
[2023-03-04 21:35:04] DEBUG Jekyll::Commands::Serve::Servlet is mounted on .
    Server address: http://127.0.0.1:1125
[2023-03-04 21:35:04] INFO  WEBrick::HTTPServer#start: pid=1493777 port=1125
  Server running... press ctrl-c to stop.
[2023-03-04 21:35:09] DEBUG accept: 127.0.0.1:40816
[2023-03-04 21:35:09] DEBUG Jekyll::Commands::Serve::Servlet is invoked.
[2023-03-04 21:35:09] DEBUG Jekyll::Commands::Serve::Servlet is invoked.
[2023-03-04 21:35:09] ERROR `/favicon.ico' not found.
[2023-03-04 21:35:09] DEBUG close: 127.0.0.1:40816
```

# Hugo

```
.
./resources
./resources/_gen
./resources/_gen/assets
./resources/_gen/images
./aaron
./aaron/config.toml
./aaron/assets
./aaron/static
./aaron/themes
./aaron/content
./aaron/public
./aaron/data
./aaron/layouts
./aaron/archetypes
./aaron/archetypes/default.md
./themes
./themes/thepro
./themes/thepro/theme.toml
./themes/thepro/static
./themes/thepro/static/css
./themes/thepro/static/js
./themes/thepro/LICENSE
./themes/thepro/layouts
./themes/thepro/layouts/_default
./themes/thepro/layouts/_default/baseof.html
./themes/thepro/layouts/_default/single.html
./themes/thepro/layouts/_default/list.html
./themes/thepro/layouts/404.html
./themes/thepro/layouts/partials
./themes/thepro/layouts/partials/head.html
./themes/thepro/layouts/partials/footer.html
./themes/thepro/layouts/partials/header.html
./themes/thepro/layouts/index.html
./themes/thepro/archetypes
./themes/thepro/archetypes/default.md
```

# Zola

```
Listening for changes in /aaron/public/zol/{zola-config.toml,content,sass,static,templates}
```

```
├── content
├── sass
├── static
├── templates
├── themes
└── zola-config.toml
```

## Trouble shooting

### liquid only tags
...

```
  \{\{page.date | date_to_string \}\}
```

`date_to_string` is liquid only, should not appear in md src file.

### Error: Reason: YAML deserialize error: Error("failed to parse datetime", line: 2, column: 1)

```
$ ~/zola/target/debug/zola -c zola-config.toml serve
Building site...
Error: Failed to serve the site
Error: Error when parsing front matter of section `/aaron/site/content/_posts/2023-03-04-welcome-to-jekyll.md`
Error: Reason: YAML deserialize error: Error("failed to parse datetime", line: 2, column: 1)
```

    date:   2023-03-04 20:45:06 +0800

    Change it to

    date:   2023-03-04T21:49:42+08:00

Generated by

    $ date -Is

```
    <link rel="preload" href={{ config.extra.cdn.font_awesome }} as="style" onload="this.onload=null;this.rel='stylesheet'">
    <noscript><link rel="stylesheet" href={{ config.extra.cdn.font_awesome }}></noscript>
```
##Ref

- https://www.getzola.org/documentation/templates/pages-sections/#section-variables

https://www.getzola.org/documentation/getting-started/cli-usage/
