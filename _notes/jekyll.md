---
title: Jekyll
render_with_liquid: false
date: 2018-05-12
---

_sass 目录存储 Sass/SCSS 的部分文件（partials）。
- 文件通常以 _ 开头，例如 _variables.scss, _mixins.scss。
- **不会生成对应的 CSS 文件**
- 用于被其他 SCSS 文件通过 @import 引入。
- 典型用法是组织样式代码，例如定义变量、函数、混合器和复用样式。

css 目录通常包含主 SCSS 文件。
- 例如 styles.scss
- 用 @import 来引入 _sass 中的部分文件。
- Jekyll 会扫描 _sass 和其他目录中的 .scss 文件
- 使用 Ruby 的 sass 或 sassc 库
- 将 css 目录中的 .scss 文件转换为 .css 文件。
- 生成的 .css 文件会被放在站点的 _site 目录下，路径与原始 .scss 文件一致。

在 _config.yml 中自定义：

sass:
  load_paths:
    - _sass

示例

假设你的文件结构如下：

_sass/
  _variables.scss
  _mixins.scss
  _base.scss
css/
  styles.scss

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

生成后，_site/css/styles.css 的内容为：

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

注意事项

    YAML Front Matter：SCSS 文件需要添加空的 YAML Front Matter (---) 才会被处理为 CSS 文件。
    静态文件：没有被处理的 .scss 文件（如 _sass 中的文件）不会被复制到 _site。
    性能优化：尽量将小的样式拆分为 _sass 中的部分文件，保持主 SCSS 文件清晰易维护


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

---
title: Jekyll
render_with_liquid: false
date: 2018-05-12
---

_sass 目录存储 Sass/SCSS 的部分文件（partials）。
- 文件通常以 _ 开头，例如 _variables.scss, _mixins.scss。
- **不会生成对应的 CSS 文件**
- 用于被其他 SCSS 文件通过 @import 引入。
- 典型用法是组织样式代码，例如定义变量、函数、混合器和复用样式。

css 目录通常包含主 SCSS 文件。
- 例如 styles.scss
- 用 @import 来引入 _sass 中的部分文件。
- Jekyll 会扫描 _sass 和其他目录中的 .scss 文件
- 使用 Ruby 的 sass 或 sassc 库
- 将 css 目录中的 .scss 文件转换为 .css 文件。
- 生成的 .css 文件会被放在站点的 _site 目录下，路径与原始 .scss 文件一致。

在 _config.yml 中自定义：

sass:
  load_paths:
    - _sass

示例

假设你的文件结构如下：

_sass/
  _variables.scss
  _mixins.scss
  _base.scss
css/
  styles.scss

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

生成后，_site/css/styles.css 的内容为：

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

注意事项

    YAML Front Matter：SCSS 文件需要添加空的 YAML Front Matter (---) 才会被处理为 CSS 文件。
    静态文件：没有被处理的 .scss 文件（如 _sass 中的文件）不会被复制到 _site。
    性能优化：尽量将小的样式拆分为 _sass 中的部分文件，保持主 SCSS 文件清晰易维护


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

```sh
$ gem i jekyll

Fetching pathutil-0.16.2.gem
Fetching safe_yaml-1.0.5.gem
Fetching rouge-3.29.0.gem
Fetching liquid-4.0.3.gem
Fetching terminal-table-2.0.0.gem
Fetching mercenary-0.4.0.gem
Fetching forwardable-extended-2.6.0.gem
Fetching unicode-display_width-1.8.0.gem
Fetching rexml-3.2.5.gem
Fetching kramdown-parser-gfm-1.1.0.gem
Fetching ffi-1.15.5.gem
Fetching kramdown-2.4.0.gem
Fetching rb-inotify-0.10.1.gem
Fetching rb-fsevent-0.11.1.gem
Fetching listen-3.7.1.gem
Fetching jekyll-watch-2.2.1.gem
Fetching sassc-2.4.0.gem
Fetching jekyll-sass-converter-2.2.0.gem
Fetching concurrent-ruby-1.1.10.gem
Fetching i18n-1.10.0.gem
Fetching http_parser.rb-0.8.0.gem
Fetching eventmachine-1.2.7.gem
Fetching em-websocket-0.5.3.gem
Fetching colorator-1.1.0.gem
Fetching public_suffix-4.0.7.gem
Fetching addressable-2.8.0.gem
Fetching jekyll-4.2.2.gem
Successfully installed unicode-display_width-1.8.0
Successfully installed terminal-table-2.0.0
ERROR:  While executing gem ... (Gem::FilePermissionError)
    You don't have write permissions for the /usr/bin directory.

$ gem i jekyll
Successfully installed safe_yaml-1.0.5
Successfully installed rouge-3.29.0
Successfully installed forwardable-extended-2.6.0
Successfully installed pathutil-0.16.2
Successfully installed mercenary-0.4.0
Successfully installed liquid-4.0.3
Successfully installed rexml-3.2.5
Successfully installed kramdown-2.4.0
Successfully installed kramdown-parser-gfm-1.1.0
Building native extensions. This could take a while...
Successfully installed ffi-1.15.5
Successfully installed rb-inotify-0.10.1
Successfully installed rb-fsevent-0.11.1
Successfully installed listen-3.7.1
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

