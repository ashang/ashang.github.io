$ bundle config mirror.https://rubygems.org https://mirrors.tuna.tsinghua.edu.cn/rubygems

$ bundle config list
Settings are listed in order of priority. The top value will be used.
mirror.https://rubygems.org/
Set for your local app (/home/thpr/.bundle/config): "https://mirrors.tuna.tsinghua.edu.cn/rubygems"
Set for the current user (/home/thpr/.bundle/config): "https://mirrors.tuna.tsinghua.edu.cn/rubygems"


$ more .bundle/
cache/  config  

$ cat .bundle/config 
---
BUNDLE_MIRROR__HTTPS://RUBYGEMS__ORG/: "https://mirrors.tuna.tsinghua.edu.cn/rubygems"



Bundler is a tool to help you install all the needed Gems.

    bundle info minima
    bundle info --path minima


starts Jekyll with bundler and overwrites with the second configuration file _config_dev.yml some settings in _config.yml 

http://bundler.io/

Bundler provides a consistent environment for Ruby projects by tracking and installing the exact gems and versions that are needed. 

Bundler is an exit from dependency hell, and ensures that the gems you need are present in development, staging, and production. Starting work on a project is as simple as bundle install.


$ gem install bundler

$ bundle gem gothonweb
/Library/Ruby/Gems/2.0.0/gems/bundler-1.7.12/lib/bundler/cli/gem.rb:26: warning: Insecure world writable dir /jing in PATH, mode 040777
      create  gothonweb/Gemfile
      create  gothonweb/Rakefile
      create  gothonweb/LICENSE.txt
      create  gothonweb/README.md
      create  gothonweb/.gitignore
      create  gothonweb/gothonweb.gemspec
      create  gothonweb/lib/gothonweb.rb
      create  gothonweb/lib/gothonweb/version.rb
Initializing git repo in /jing/bench/dot/proj/gothonweb


#開發 Bundler

Fork Bundler

造訪 Bundler 的 Github 主頁 https://github.com/bundler/bundler

按下 fork 按鈕。

Fork Bundler ，才能將妳的修改發 pull requests 回去。

 
下載一份妳 fork 的 Bundler

$ git clone https://github.com/your_user_name/bundler.git

切換至 Bundler 目錄

$ cd bundler

設定一下原項目的網址

$ git remote add upstream https://github.com/bundler/bundler.git

這將妳本機的 repo 與上游 repo 連結起來。

安裝 Bundler 開發所依賴的軟體

$ rake spec:deps

rake 是什麼？ http://rake.rubyforge.org/

執行 Bundler 的測試套裝

$ rake spec


# Gemfile.lock


The instructions are probably a bit confusing. It's saying that you've modified your Gemfile on your development machine and just pushed those changes rather than running bundle install BEFORE committing the changes.

By running bundle install you will update your Gemfile.lock file. This should be pushed to your server as it's more important than Gemfile. Consider the Gemfile the plans for the Gemfile.lock file.

Always remember to:

    Run bundle install if you change your Gemfile, even just to make sure. If it's too slow, pass --local through which forces it to only use local gems to resolve its dependencies.
    Commit both the Gemfile and Gemfile.lock file to your repository
    Deploy both the Gemfile and Gemfile.lock to your production servers to ensure that they're running the exact same dependencies as your development environment.

Running bundle update by itself can be construed as dangerous that will update all the dependencies of your application. It's mainly dangerous if you don't have solid version numbers specified in the Gemfile



# FWIW I had this problem and fixed it by removing some conditional statements from my Gemfile (conditionals on OS) and rerunning bundle.


bundler - Manage Ruby application dependencies
carton - Perl module dependency manager (aka Bundler for Perl)
libfelix-bundlerepository-java - Felix OSGi bundle repository service
libfelix-bundlerepository-java-doc - Documentation for Felix OSGi bundle repository service
librarian-puppet - bundler for your puppet modules
libjs-inherits - Exposes inherits function from Node.js environment
node-inherits - Exposes inherits function from Node.js environment
ruby-appraisal - Find out what your Ruby gems are worth
ruby-librarian - framework for writing bundlers
rubygems-integration - integration of Debian Ruby packages with Rubygems
ruby-molinillo - generic dependency resolution algorithm



```
$ bundle install
Fetching gem metadata from https://rubygems.org/...........
Fetching gem metadata from https://rubygems.org/.
Resolving dependencies...
Following files may not be writable, so sudo is needed:
  /var/lib/gems/2.7.0
Fetching public_suffix 4.0.5


Your user account isn't allowed to install to the system RubyGems.
  You can cancel this installation and run:

      bundle install --path vendor/bundle

  to install the gems into ./vendor/bundle/, or you can enter your password
  and install the bundled gems to RubyGems using sudo.

```



```
$ bundle exec jekyll serve --port 1111 --host --trace --unpublished
/Users/aaron/.gem/ruby/3.4.0/gems/safe_yaml-1.0.5/lib/safe_yaml/transform.rb:1: warning: base64 was loaded from the standard library, but is not part of the default gems starting from Ruby 3.4.0.
You can add base64 to your Gemfile or gemspec to silence this warning.

```

```

$ bundle exec jekyll serve --port 1111 --host --trace --unpublished
Configuration file: /Users/aaron/Documents/a/minima-/_config.yml
 Theme Config file: /Users/aaron/Documents/a/minima-/_config.yml
            Source: /Users/aaron/Documents/a/minima-
       Destination: /Users/aaron/Documents/a/minima-/_site
 Incremental build: disabled. Enable with --incremental
      Generating...
       Jekyll Feed: Generating feed for posts
Deprecation Warning [import]: Sass @import rules are deprecated and will be removed in Dart Sass 3.0.0.

More info and automated migrator: https://sass-lang.com/d/import

  ╷
2 │   "minima/skins/classic",
  │   ^^^^^^^^^^^^^^^^^^^^^^
  ╵
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [import]: Sass @import rules are deprecated and will be removed in Dart Sass 3.0.0.

More info and automated migrator: https://sass-lang.com/d/import

  ╷
3 │   "minima/initialize";
  │   ^^^^^^^^^^^^^^^^^^^
  ╵
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 3:3  root stylesheet
Deprecation Warning [import]: Sass @import rules are deprecated and will be removed in Dart Sass 3.0.0.

More info and automated migrator: https://sass-lang.com/d/import

  ╷
5 │ @import "minima/skins/auto";
  │         ^^^^^^^^^^^^^^^^^^^
  ╵
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [global-builtin]: Global built-in functions are deprecated and will be removed in Dart Sass 3.0.0.
Use color.adjust instead.

More info and automated migrator: https://sass-lang.com/d/import

   ╷
14 │ $lm-brand-color-light:     lighten($lm-brand-color, 40%) !default;
   │                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/skins/auto.scss 14:28                                @import
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [color-functions]: lighten() is deprecated. Suggestions:

color.scale($color, $lightness: 81.6%)
color.adjust($color, $lightness: 40%)

More info: https://sass-lang.com/d/color-functions

   ╷
14 │ $lm-brand-color-light:     lighten($lm-brand-color, 40%) !default;
   │                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/skins/auto.scss 14:28                                @import
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [global-builtin]: Global built-in functions are deprecated and will be removed in Dart Sass 3.0.0.
Use color.adjust instead.

More info and automated migrator: https://sass-lang.com/d/import

   ╷
15 │ $lm-brand-color-dark:      darken($lm-brand-color, 25%) !default;
   │                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/skins/auto.scss 15:28                                @import
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [color-functions]: darken() is deprecated. Suggestions:

color.scale($color, $lightness: -49.0384615385%)
color.adjust($color, $lightness: -25%)

More info: https://sass-lang.com/d/color-functions

   ╷
15 │ $lm-brand-color-dark:      darken($lm-brand-color, 25%) !default;
   │                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/skins/auto.scss 15:28                                @import
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [global-builtin]: Global built-in functions are deprecated and will be removed in Dart Sass 3.0.0.
Use color.adjust instead.

More info and automated migrator: https://sass-lang.com/d/import

   ╷
24 │ $lm-link-visited-color:    darken($lm-link-base-color, 15%) !default;
   │                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/skins/auto.scss 24:28                                @import
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [color-functions]: darken() is deprecated. Suggestions:

color.scale($color, $lightness: -28.5447761194%)
color.adjust($color, $lightness: -15%)

More info: https://sass-lang.com/d/color-functions

   ╷
24 │ $lm-link-visited-color:    darken($lm-link-base-color, 15%) !default;
   │                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/skins/auto.scss 24:28                                @import
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [global-builtin]: Global built-in functions are deprecated and will be removed in Dart Sass 3.0.0.
Use color.adjust instead.

More info and automated migrator: https://sass-lang.com/d/import

   ╷
28 │ $lm-border-color-02:       lighten($lm-brand-color, 35%) !default;
   │                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/skins/auto.scss 28:28                                @import
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [color-functions]: lighten() is deprecated. Suggestions:

color.scale($color, $lightness: 71.4%)
color.adjust($color, $lightness: 35%)

More info: https://sass-lang.com/d/color-functions

   ╷
28 │ $lm-border-color-02:       lighten($lm-brand-color, 35%) !default;
   │                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/skins/auto.scss 28:28                                @import
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [global-builtin]: Global built-in functions are deprecated and will be removed in Dart Sass 3.0.0.
Use color.adjust instead.

More info and automated migrator: https://sass-lang.com/d/import

   ╷
31 │ $lm-table-text-color:      lighten($lm-text-color, 18%) !default;
   │                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/skins/auto.scss 31:28                                @import
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [color-functions]: lighten() is deprecated. Suggestions:

color.scale($color, $lightness: 19.2857142857%)
color.adjust($color, $lightness: 18%)

More info: https://sass-lang.com/d/color-functions

   ╷
31 │ $lm-table-text-color:      lighten($lm-text-color, 18%) !default;
   │                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/skins/auto.scss 31:28                                @import
    minima/skins/classic.scss 5:9                               @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 2:3  root stylesheet
Deprecation Warning [import]: Sass @import rules are deprecated and will be removed in Dart Sass 3.0.0.

More info and automated migrator: https://sass-lang.com/d/import

   ╷
46 │   "minima/custom-variables", // Hook to override predefined variables.
   │   ^^^^^^^^^^^^^^^^^^^^^^^^^
   ╵
    minima/initialize.scss 46:3                                 @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 3:3  root stylesheet
Deprecation Warning [import]: Sass @import rules are deprecated and will be removed in Dart Sass 3.0.0.

More info and automated migrator: https://sass-lang.com/d/import

   ╷
47 │   "minima/base",             // Defines element resets.
   │   ^^^^^^^^^^^^^
   ╵
    minima/initialize.scss 47:3                                 @import
    /Users/aaron/Documents/a/minima-/assets/css/style.scss 3:3  root stylesheet
Warning: 18 repetitive deprecation warnings omitted.
Run in verbose mode to see all warnings.
                    done in 1.598 seconds.
 Auto-regeneration: enabled for '/Users/aaron/Documents/a/minima-'
    Server address: http://127.0.0.1:1111
  Server running... press ctrl-c to stop.


```
