# frozen_string_literal: true

source "https://rubygems.org"

gem "jekyll", "~> 3.9.0"
#gem "jekyll", "~> 4.3.2"
gem "webrick"

ruby RUBY_VERSION

#gemspec
#Deprecation: You appear to have pagination turned on, but you haven't included the `jekyll-paginate` gem. Ensure you have `plugins: [jekyll-paginate]` in your configuration file.
#gemspec

# If you want to use GitHub Pages, remove the "gem "jekyll"" above and
# uncomment the line below. To upgrade, run `bundle update github-pages`.
# gem "github-pages", group: :jekyll_plugins
#gem 'github-pages', '>=104', group: :jekyll_plugins
#gem 'type-on-strap', ">= 2.3.3", "< 3.0"
#gem 'asciidoctor-revealjs', git: 'https://github.com/asciidoctor/asciidoctor-reveal.js.git', tag: 'v5.0.0-rc.1'

# Lock `http_parser.rb` gem to `v0.6.x` on JRuby builds since newer versions of the gem
# do not have a Java counterpart.
#gem "http_parser.rb", "~> 0.6.0", :platforms => [:jruby]

# Built-in
#gem 'jekyll-sass-converter'

# Feed had been built in; From 4.4??
group :jekyll_plugins do
  gem 'jekyll-archives'
  gem 'jekyll-babel'
  gem 'jekyll-feed'                 # automatically generate an Atom feed at /feed.xml
  #- jekyll-html-pipeline
  gem 'kramdown-parser-gfm'
  #- jekyll-paginate
  gem 'jekyll-relative-links'
  gem 'jekyll-redirect-from'
  gem 'jekyll-seo-tag'
  gem 'jekyll-sitemap'
  gem 'jemoji'
  gem "just-the-docs"
end

# kramdown v2 ships without the gfm parser by default. If you're using
# kramdown v1, comment out this line.
#gem "kramdown-parser-gfm"

## Windows and JRuby does not include zoneinfo files, so bundle the tzinfo-data gem
## and associated library.
#platforms :mingw, :x64_mingw, :mswin, :jruby do
  #gem "tzinfo", ">= 1", "< 3"
  #gem "tzinfo-data"
#end

### Performance-booster for watching directories on Windows
##gem "wdm", "~> 0.1.1", :platforms => [:mingw, :x64_mingw, :mswin]
