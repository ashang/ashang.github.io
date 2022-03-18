---
title: ama
permalink: /ashang/
weight: 2
date: 2010-10-18 07:48:03+00:00
update: 2016-01-06
update: 2016-11-11 11:00:00 CST
update: Wed Dec 19 22:52:19 CST 2018
update:   2021-12-12 22:15:21 +0800
---

## {{ page.title }} by jekyll

The site is hosted at [{{site.url}}]({{site.url}}) by [GitHub Pages](https://pages.github.com/).

The pages were created using [Kramdown](https://kramdown.gettalong.org/quickref.html), a flavour of Markdown

The site is &copy; {{ site.time | date: '%Y' }} {{ site.name }}, released in public domain.

You can find the source code for the Jekyll new theme at:
[jekyll-new](https://github.com/jglovier/jekyll-new)

jekyll is a Ruby Gem that can be installed on most systems.

    $ gem install jekyll

Bundler is a gem that installs all gems in your Gemfile.

    $ gem install bundler

To install gems in your Gemfile using Bundler, run the following in the directory that has the Gemfile:

    $ bundle init

    $ bundle add jekyll
    $ bundle add webrick
    $ bundle config set --local path 'vendor/bundle'

### Create A Jekyll Scaffold.

Now that Jekyll is installed, we can use it to create the scaffolding for our site. We need the --force parameter because our folder isn’t empty - it already has some Bundler files in it. We run the bundle install separately because Jekyll gets confused if the Gemfile already exists.

```
$ bundle exec jekyll new --force --skip-bundle .
$ bundle install
$ bundle exec jekyll serve --incremental --drafts --future --livereload
```

All of the normal Jekyll commands are available to you, but you should prefix them with bundle exec so that Bundler runs the version of Jekyll that is installed in your project folder.

To bypass Bundler if you aren’t using a Gemfile, run

```
$ jekyll serve # Launches web server and auto-regenerates when file updated.
$ jekyll clean # Removes generated files: destination, metadata, caches.
$ jekyll new-theme # Creates a new Jekyll theme scaffold.
$ jekyll doctor # Outputs any deprecation or configuration issues.
```

## Jekyll `_config.yml`

```
defaults:
  -
    scope:
      path: "projects"
      type: "pages"
    values:
      layout: "project"
      author: "Mr. Hyde"
      category: "project"
```

To switch part of your config settings depending on the environment, use the build command option, for example

```
--config _config.yml,_config_development.yml
```

Settings in later files override settings in earlier files.

## Bundle and Bundler

[Bundler](http://bundler.io/) is a tool to install all the needed Gems (programs, modules).

### update

```
jekyll command [argument] [option] [argument_to_option]
```

Examples:

```
jekyll new site/ --blank
jekyll serve --config _alternative_config.yml
```
## collections

    collections:
      - staff_members

>In this case collections is defined as a sequence (i.e., array) with no additional metadata defined for each collection. You can optionally specify metadata for your collection by defining collections as a mapping (i.e., hashmap) instead of sequence, and then defining additional fields in it:

    collections:
      staff_members:
        people: true

>When defining a collection as a sequence, its pages will not be rendered by default. To enable this, output: true must be specified on the collection, which requires defining the collection as a mapping.
>
> You can optionally specify a directory to store all your collections in the same place with collections_dir: my_collections.
>
>Then Jekyll will look in my_collections/_books for the books collection, and in my_collections/_recipes for the recipes collection.
>
>If you specify a directory to store all your collections in the same place with collections_dir: my_collections, then you will need to move your _drafts and _posts directory to my_collections/_drafts and my_collections/_posts. Note that, the name of your collections directory cannot start with an underscore (`_`).
>

Front matter is processed if the front matter exists, and everything after the front matter is pushed into the document’s content attribute. If no front matter is provided, Jekyll will consider it to be a static file and the contents will not undergo further processing.

Regardless of whether front matter exists or not, Jekyll will write to the destination directory (e.g. _site) only if output: true has been set in the collection’s metadata.

 Posts with a valid filename format will be marked for processing even if they do not contain front matter.

Iterate over site.staff_members using the content variable:
```
{% for staff_member in site.staff_members %}
  <h2>{{ staff_member.name }} - {{ staff_member.position }}</h2>
  <p>{{ staff_member.content | markdownify }}</p>
{% endfor %}
```

If you’d like Jekyll to create a rendered page for each document in your collection, you can set the output key to true in your collection metadata in _config.yml:

```
collections:
  staff_members:
    output: true
```

You can link to the generated page using the url attribute:

```
\{% for staff_member in site.staff_members %}
  <h2>
    <a href="\{{ staff_member.url }}">
      \{{ staff_member.name }} - \{{ staff_member.position }}
    </a>
  </h2>
  <p>\{{ staff_member.content | markdownify }}</p>
\{% endfor %}
```

## Sort By Front Matter Key

```
collections:
  tutorials:
    sort_by: lesson
```

The documents are arranged in the increasing order of the key’s value. If a document does not have the front matter key defined then that document is placed immediately after sorted documents. When multiple documents do not have the front matter key defined, those documents are sorted by their dates or paths and then placed immediately after the sorted documents.

## Manually Ordering Documents

You can also manually order the documents by setting an order metadata with the filenames listed in the desired order. For example, a collection of tutorials would be configured as:

```
collections:
  tutorials:
    order:
      - hello-world.md
      - introduction.md
      - basic-concepts.md
      - advanced-concepts.md
```

Any documents with filenames that do not match the list entry simply gets placed after the rearranged documents. If a document is nested under subdirectories, include them in entries as well:

```
collections:
  tutorials:
    order:
      - hello-world.md
      - introduction.md
      - concepts/basics.md
      - concepts/advanced.md
```

If both metadata keys have been defined properly, order list takes precedence.

## Static files

This assumes that your Jekyll site has a folder path of assets/img where you have images (static files) stored. When Jekyll builds the site, it will treat each image as if it had the front matter value of image: true.

Suppose you want to list all your image assets as contained in assets/img. You could use this for loop to look in the static_files object and get all static files that have this front matter property:

```
\{% assign image_files = site.static_files | where: "image", true %}
\{% for myimage in image_files %}
  \{{ myimage.path }}
\{% endfor %}
```


## File structure

```
.
├── _config.yml
├── _data
│   └── members.yml
├── _drafts
│   ├── begin-with-the-crazy-ideas.md
│   └── on-simplicity-in-technology.md
├── _includes
│   ├── footer.html
│   └── header.html
├── _layouts
│   ├── 404.html
│   ├── default.html
│   ├── page.html
│   └── post.html
├── _posts
│   ├── 2007-10-29-why-every-programmer-should-play-nethack.md
│   └── 2009-04-26-barcamp-boston-4-roundup.md
├── _sass
│   ├── _base.scss
│   ├── _layout.scss
|   └── _syntax-highlighting.scss
├── _site
├── .jekyll-cache
│   └── Jekyll
│       └── Cache
│           └── [...]
├── .jekyll-metadata
├── about.md          # => <http://example.com/about>
├── documentation     # folder containing pages
│   └── doc1.md       # => <http://example.com/documentation/doc1>
│   └── doc2.md
├── notes
│   └── draft.md      # => <http://example.com/notes/draft>
├── css
|   └── main.scss
├── feed.xml
└── index.html # can also be an 'index.md' with valid front matter
```

## Jekyll support for code snippets.

Using built-in support.

    ```ruby
    def print_hi(name)
      puts "Hi, #{name}"
    end
    print_hi('Tom')
    #=> prints 'Hi, Tom' to STDOUT.
    ```

```ruby
def print_hi(name)
  puts "Hi, #{name}"
end
print_hi('Tom')
#=> prints 'Hi, Tom' to STDOUT.
```

And using `highlight ruby`.

    {% highlight ruby %}
    def print_hi(name)
      puts "Hi, #{name}"
    end
    print_hi('Tom')
    #=> prints 'Hi, Tom' to STDOUT.
    {% endhighlight %}

{% highlight ruby %}
def print_hi(name)
  puts "Hi, #{name}"
end
print_hi('Tom')
#=> prints 'Hi, Tom' to STDOUT.
{% endhighlight %}

## Trouble shooting

```
$ jekyll serve
/usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/runtime.rb:309:in `check_for_activated_spec!': You have already activated i18n 1.8.11, but your Gemfile requires i18n 0.9.5. Prepending `bundle exec` to your command may solve this. (Gem::LoadError)
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/runtime.rb:25:in `block in setup'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/spec_set.rb:136:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/spec_set.rb:136:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/runtime.rb:24:in `map'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/runtime.rb:24:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler.rb:150:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/lib/jekyll/plugin_manager.rb:52:in `require_from_bundler'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/exe/jekyll:11:in `<top (required)>'
        from /usr/bin/jekyll:25:in `load'
        from /usr/bin/jekyll:25:in `<main>'
```

```
$ bundle exec jekyll serve --trace
...
bundler: failed to load command: jekyll (/usr/bin/jekyll)
/usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/lib/jekyll/commands/serve/servlet.rb:3:in `require': cannot load such file -- webrick (LoadError)
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/lib/jekyll/commands/serve/servlet.rb:3:in `<top (required)>'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/lib/jekyll/commands/serve.rb:179:in `require_relative'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/lib/jekyll/commands/serve.rb:179:in `setup'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/lib/jekyll/commands/serve.rb:100:in `process'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/lib/jekyll/command.rb:91:in `block in process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/lib/jekyll/command.rb:91:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/lib/jekyll/command.rb:91:in `process_with_graceful_fail'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/lib/jekyll/commands/serve.rb:86:in `block (2 levels) in init_with_program'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `block in execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `each'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/command.rb:221:in `execute'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary/program.rb:44:in `go'
        from /usr/lib/ruby/gems/3.0.0/gems/mercenary-0.4.0/lib/mercenary.rb:21:in `program'
        from /usr/lib/ruby/gems/3.0.0/gems/jekyll-4.2.1/exe/jekyll:15:in `<top (required)>'
        from /usr/bin/jekyll:25:in `load'
        from /usr/bin/jekyll:25:in `<top (required)>'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/cli/exec.rb:58:in `load'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/cli/exec.rb:58:in `kernel_load'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/cli/exec.rb:23:in `run'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/cli.rb:479:in `exec'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/vendor/thor/lib/thor/command.rb:27:in `run'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/vendor/thor/lib/thor/invocation.rb:127:in `invoke_command'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/vendor/thor/lib/thor.rb:392:in `dispatch'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/cli.rb:31:in `dispatch'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/vendor/thor/lib/thor/base.rb:485:in `start'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/cli.rb:25:in `start'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/exe/bundle:49:in `block in <top (required)>'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/lib/bundler/friendly_errors.rb:103:in `with_friendly_errors'
        from /usr/lib/ruby/gems/3.0.0/gems/bundler-2.2.33/exe/bundle:37:in `<top (required)>'
        from /usr/bin/bundle:23:in `load'
        from /usr/bin/bundle:23:in `<main>'
```

Add gem webrick to Gemfile.

```
$ bundle exec jekyll serve --trace
Could not find gem 'webrick' in locally installed gems.
Run `bundle install` to install missing gems.
$ bundle install
```

OK

## Links

- <https://jekyllrb.com/docs/step-by-step/01-setup/>
- <https://jekyllrb.com/tutorials/convert-site-to-jekyll/>
- <https://github.com/jekyll/jekyll/tree/master/docs>
- <https://github.com/jekyll/jekyll/blob/master/docs/_docs/rendering-process.md>
- <https://jekyllrb.com/docs/posts/>
- <https://www.sonerezh.bzh/>
- <https://sigpipe.macromates.com/2018/creating-a-faster-jekyll/>
- <https://www.bridgetownrb.com/news/time-to-visit-bridgetown/>
- <https://docs.github.com/en/pages/configuring-a-custom-domain-for-your-github-pages-site/about-custom-domains-and-github-pages>
- <https://pages.github.com/>
- <https://dev.twitch.tv/>
- <https://github.com/DirtyF>
- <https://github.com/jekyll/jekyll/issues/6437>
- <https://github.com/jekyll/jekyll/issues/6438>
- <https://github.com/apps/first-timers>
- <https://byparker.com/blog/2021/the-power-of-bashrc-d/>
- <https://en.wikipedia.org/wiki/Mantra>
- <https://zh.wikipedia.org/wiki/%E6%8B%89%E5%AE%BE-%E5%8D%A1%E6%99%AE%E7%AE%97%E6%B3%95>

## Contents in markdown

### Blockquotes

> This is a blockquote

 > This is a blockquote even if the angle bracket is not at the beginning of the line

> This is a single
> blockquote even if it
> spans a few lines

> This is a single
blockquote, you can put the angle bracket
jnly at the first line of the paragraph and
the all the paragraph is a blockquote

<https://blog.gerv.net/category/death-and-dying/>

### Nested blockquotes

> First level blockquote
>> Second level blockquote
>>
>> Second level blockquote
>>> Third level blockquote
>>>
>>> This quote will *change* your life. It will reveal the <i>secrets</i> of the universe, and all the wonders of humanity. Don't <em>misuse</em> it.


## The Practice

> Do What Works, Not What's Fashionable: Don't adopt a development method or technique just because other companies are doing it. Adopt what works for your team, in your context.
- The Pragmatic Programmer

```
<link rel="stylesheet" href="http://localhost:1313//css/style.css">
<link href="//maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet" integrity="sha384-wvfXpqpZZVQGK6TAh5PVlGOfQNHSoD2xbE+QkPxCAFlNEevoEH3Sl0sibVcOQVnN" crossorigin="anonymous">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/9.12.0/styles/default.min.css" integrity="sha256-Zd1icfZ72UBmsId/mUcagrmN7IN5Qkrvh75ICHIQVTk=" crossorigin="anonymous" />
```

>> Paul Graham
>
>The greatest dangers to liberty lurk in insidious encroachment by men of zeal, well-meaning but without understanding.

>> Arnold Toynbee, Experiences

>Americans spend an average of four hours a day watching TV, an hour of that enduring ads. That adds up to an astounding 10% of total leisure time; at current rates, a typical viewer fritters away three years of his life getting bombarded with commercials.

> Scott Woolley, Forbes

>The best writing is rewriting.

> E. B. White

>Modern invention has been a great leveller. A machine may operate far more quickly than a political or economic measure to abolish privilege and wipe out the distinctions of class or finance.

> Ivor Brown, The Heart of England

>If our goal is to write poetry, the only way we are likely to be any good is to try to be as great as the best.

> Donald Hall, Poetry and Ambition


>Premature optimization is the root of all evil (or at least most of it) in programming.
> Donald Knuth

>In France those absurd perversions of the art of war which covered themselves under the name of chivalry were more omnipotent than in any other country of Europe. The strength of the armies of Philip and John of Valois was composed of a fiery and undisciplined aristocracy which imagined itself to be the most efficient military force in the world, but which was in reality little removed from an armed mob.

> C. W. C. Oman, The Art of War in the Middle Ages


>We act as though comfort and luxury were the chief requirements of life, when all that we need to make us happy is something to be enthusiastic about.

> Einstein

>The path from good to evil goes through bogus.

> Tara Ploughman

>Lisp has jokingly been called "the most intelligent way to misuse a computer". I think that description is a great compliment because it transmits the full flavor of liberation: it has assisted a number of our most gifted fellow humans in thinking previously impossible thoughts.

> Edsger Dijkstra, CACM, 15:10

>Many who burnt heretics in the ordinary way of their business were otherwise excellent people.

> G. M. Trevelyan, "Bias in History

>He became an object of ridicule in 1993 when a paper published an intercepted phone call in which he told his lover Camilla Parker Bowles he wanted to be reincarnated as her tampon.

> Reuters story, on Prince Charles

>We're even wrong about which mistakes we're making.

> Carl Winfeld

>From this place she sent into the world those novels, which by many have been placed on the same shelf as the works of a D'Arblay and an Edgeworth.

> Henry Austen on his sister Jane, in a preface to Persuasion

>The key to performance is elegance, not battalions of special cases.

> Jon Bentley and Doug McIlroy

>The economic depression that struck Europe in the fourteenth century was followed ultimately by economic and technological recovery. But the depression we have moved into will have no end. We can anticipate centuries of decline and exhaustion.

> Jean Gimpel, The Medieval Machine, 1975

>Politics is not the art of the possible. It consists in choosing between the disastrous and the unpalatable.

> J. K. Galbraith, Letter to Kennedy, 1962

>A typical dinner from the ape menu would be tofu bake with ratatouille of aubergine, onions and sweet peppers, with pearled barley and vegetable side dishes, says the team.

> New Scientist

>Guy Steele leads a small team of researchers in Burlington, Massachusetts, who are taking on an enormous challenge-- create a programming language better than Java.

> Sun.Com (my italics)

>I had my own reactions to Paul's essay-- on the whole I liked it but when I connected some dots I found some suggestions of things I strongly disliked-- not so much in the essay as suggested by it.

> reaction to What You Can't Say in a blog

>Your twenties are always an apprenticeship, but you don't always know what for.

> Jan Houtema

>In addition, the board rewrote the definition of science, so that it is no longer limited to the search for natural explanations of phenomena.

> AP story on Kansas Board of Education

>A danger sign that fellow-obsessionals will at once recognize is the tendency to regard the happiest moments of your life as those that occur when someone who has an appointment to see you is prevented from coming.

> Peter Medawar, Memoirs of a Thinking Radish

>Never offer what you'd hate someone for accepting.

> Tara Ploughman

>The pagans were incensed at the rashness of a recent and obscure sect, which presumed to accuse their countrymen of error, and to devote their ancestors to eternal misery.

> Gibbon, The Decline and Fall of the Roman Empire

>Simultaneously reifying and challenging hegemonic codes of race, class, gender and regional or national identity, his characters explore the complex and changing postmodern cultural landscape.

> Robert Bennett, English professor at Montana State, announcing a panel discussion about Brad Pitt

>In the councils of government, we must guard against the acquisition of unwarranted influence, whether sought or unsought, by the military-industrial complex. The potential for the disastrous rise of misplaced power exists and will persist.

> Eisenhower, Farewell Address

>Keep away from people who try to belittle your ambitions. Small people always do that, but the really great make you feel that you, too, can become great.

> Mark Twain

>However little television you watch, watch less.

> David McCullough

>Any word you have to hunt for in a thesaurus is the wrong word.

> Stephen King

>The people can always be brought to the bidding of the leaders. That is easy. All you have to do is tell them they are being attacked, and denounce the pacifists for lack of patriotism, and exposing the country to greater danger.

> Goering at the Nuremberg Trials

>As all these results were obtained, not by any heroic method, but by patient and detailed reasoning, I began to think it probable that philosophy had erred in adopting heroic remedies for intellectual difficulties, and that solutions were to be found merely by greater care and accuracy. This view I have come to hold more and more strongly as time went on, and it has led me to doubt whether philosophy, as a study distinct from science and possessed of a method of its own, is anything more than an unfortunate legacy from theology.

> Bertrand Russell, "Logical Atomism

>Get the important things right.

> N. P. Collingwood

>When schoolchildren start paying union dues, that's when I'll start representing the interests of schoolchildren.

> Albert Shanker, president of the American Federation of Teachers, 1985

>The power of instruction is seldom of much efficacy except in those happy dispositions where it is almost superfluous.

> Gibbon

>I do not know what the Lord's anointed, his Vicegerent upon earth, divinely appointed by him, and accountable to none but him for his actions, will either think or do, upon these symptoms of reason and good sense which seem to be breaking out all over France: but this I foresee, that, before the end of this century, the trade of both King and Priest will not be half so good a one as it has been.

> Chesterfield, letter to his son, 13 Apr 1752

>filter(P, S) is almost always written clearer as [x for x in S if P(x)]

> Guido van Rossum on Python

>I'm surrounded by postmodern idiots and blatherers. Your writings give me hope.

> email from a reader

>In the last analysis, productivity of labour is the most important, the principal thing for the victory of the new social system.

> Lenin, quoted in First Five-Year Plan for the Development of the National Economy of the People's Republic of China in 1953-1957

>Most interesting phenomena have multiple causes.

> N. P. Collingwood

>From 1911 to 1920, the mood of the city varied between utter dullness and tremendous excitement.

> Arthur Coffman, An Illustrated History of Palo Alto

>People don't change their minds. They die, and are replaced by people with different opinions.

> Arturo Albergati

>No man who ever held the office of President would congratulate a friend on obtaining it.

> John Adams

>PowerPoint makes us stupid.

> General James N. Mattis, USMC

>The best way to do something 'lean' is to gather a tight group of people, give them very little money, and very little time.

> Bob Klein, chief engineer of the F-14 program

>But camels, though odious to view and endowed with the offensive spirit, did not enjoy the blessing of pachydermaty.

> F. E. Adcock, The Greek and Macedonian Art of War

>As it turned out, the obvious clearly stated, and combined with new observations, was sometimes close to revolutionary.

> Wallace Stegner on John Wesley Powell

>Focusing is about saying no.

> Steve Jobs


>The condition of man is already close to satiety and arrogance, and there is danger of destruction of everything in existence.

> a Brahmin to Onesicritus, 327 BC, reported in Strabo's Geography

>Change breaks the brittle.

> Jan Houtema

>The sons of Hermes love to play,
And only do their best when they
Are told they oughtn't;
Apollo's children never shrink
From boring jobs but have to think
Their work important.

> W. H. Auden, Under Which Lyre

>Programs must be written for people to read, and only incidentally for machines to execute.

> Abelson & Sussman, SICP, preface to the first edition

>That language is an instrument of human reason, and not merely a medium for the expression of thought, is a truth generally admitted.

> George Boole, quoted in Iverson's Turing Award Lecture

>Short words are best and the old words when short are best of all.

> Winston Churchill

>Many big people were chasing me. I didn't know what to do. So I thought I would surprise them and throw it.

> Garo Yepremian, Miami placekicker, after a disastrous attempt to throw a pass in the Super Bowl.

>That book is good in vain which the reader throws away. He only is the master who keeps the mind in pleasing captivity; whose pages are perused with eagerness, and in hope of new pleasure are perused again; and whose conclusion is perceived with an eye of sorrow, such as the traveller casts upon departing day.

> Johnson, Lives of the Poets: Dryden

>Don't worry about what anybody else is going to do. The best way to predict the future is to invent it.

> Alan Kay

>But the audience is right. They're always, always right. You hear directors complain that the advertising was lousy, the distribution is no good, the date was wrong to open the film. I don't believe that. The audience is never wrong. Never.

> William Friedkin, in a NYT interview

>Dealing with failure is easy: Work hard to improve. Success is also easy to handle: You've solved the wrong problem. Work hard to improve.

> Alan Perlis

>Frankly, I don't think you could have driven a needle up my sphincter using a sledgehammer.

> Col. Barry Horne, F-117 pilot, on first mission over Baghdad

>Two centuries later a most clear-sighted historian of the Second Crusade can find space in a short narrative to record on many occasions the flattery, perjury, perfidy, blasphemy, heresy, arrogance, servility, deceit, pride, cunning and infidelity of the Greeks.

> R. W. Southern, The Making of the Middle Ages

## Apps
  - <http://opengapps.org>

## Integrated
  - https://www.algolia.com/

## Switching
  - https://github.com/p4lang


## Networking Controller
  - https://wiki.onosproject.org/

## Networking Utilities
  - https://stackshare.io/stackups
  - https://stackshare.io/stackshare
  - https://packagecloud.io

## Startup
  - https://angel.co/
  - https://software.opensuse.org/download.html?project=home:vtrefny&package=blivet-gui

https://github.com/storaged-project/blivet-gui/wiki
https://camo.githubusercontent.com/d1f737120d879117d9f4cdd2f808a936b898621b/68747470733a2f2f6665646f726170656f706c652e6f72672f67726f7570732f73746f726167655f617069732f73746174757365732f626c697665742d6775692d6d61737465722e737667

## Categories

Unlike tags, categories for posts can also be defined by a post’s file path. Any directory above _post will be read-in as a category. For example, if a post is at path movies/horror/_posts/2019-05-21-bride-of-chucky.markdown, then movies and horror are automatically registered as categories for that post.

## Post excerpts

You can access a snippet of a posts’s content by using excerpt variable on a post. By default this is the first paragraph of content in the post, however it can be customized by setting a excerpt_separator variable in front matter or _config.yml.

```
---
excerpt_separator: <!--more-->
---

Excerpt with multiple paragraphs

Here's another paragraph in the excerpt.
<!--more-->
Out-of-excerpt
```

---

## Netlify Jekyll website

```
$ git clone https://
info: detecting host provider for 'https:///'...
warning: auto-detection of host provider took too long (>2000ms)
warning: see https://aka.ms/gcmcore-autodetect for more information.

remote: Enumerating objects: 31, done.
remote: Total 31 (delta 0), reused 0 (delta 0), pack-reused 31
Receiving objects: 100% (31/31), 11.11 KiB | 1.39 MiB/s, done.
Resolving deltas: 100% (1/1), done.
```

In order to build this site with Netlify, simply log in or register at
https://app.netlify.com/, then select "New site from Git" from the top
right. Select GitLab, authenticate if needed, and then select this
project from the list. Netlify will handle the rest.

In the meantime, you can take advantage of all the great GitLab features
like merge requests, issue tracking, epics, and everything else GitLab has
to offer.

## Using Jekyll locally

To work locally with this project, you'll have to follow the steps below:

1. Fork, clone or download this project
1. [Install][] Jekyll
1. Download dependencies: `bundle`
1. Build and preview: `bundle exec jekyll serve`
1. Add content

The above commands should be executed from the root directory of this project.

Read more at Jekyll's [documentation][].

## Did you fork this project?

If you forked this project for your own use, please go to your project's
**Settings** and remove the forking relationship, which won't be necessary
unless you want to contribute back to the upstream project.

## Troubleshooting

1. CSS is missing! That means two things:
    * Either that you have wrongly set up the CSS URL in your templates, or
    * your static generator has a configuration option that needs to be explicitly
    set in order to serve static assets under a relative URL.

[Jekyll]: http://jekyllrb.com/
[install]: https://jekyllrb.com/docs/installation/
[documentation]: https://jekyllrb.com/docs/home/


---

## Netlify Jekyll website

```
$ git clone https://
info: detecting host provider for 'https:///'...
warning: auto-detection of host provider took too long (>2000ms)
warning: see https://aka.ms/gcmcore-autodetect for more information.

remote: Enumerating objects: 31, done.
remote: Total 31 (delta 0), reused 0 (delta 0), pack-reused 31
Receiving objects: 100% (31/31), 11.11 KiB | 1.39 MiB/s, done.
Resolving deltas: 100% (1/1), done.
```

In order to build this site with Netlify, simply log in or register at
https://app.netlify.com/, then select "New site from Git" from the top
right. Select GitLab, authenticate if needed, and then select this
project from the list. Netlify will handle the rest.

In the meantime, you can take advantage of all the great GitLab features
like merge requests, issue tracking, epics, and everything else GitLab has
to offer.

## Using Jekyll locally

To work locally with this project, you'll have to follow the steps below:

1. Fork, clone or download this project
1. [Install][] Jekyll
1. Download dependencies: `bundle`
1. Build and preview: `bundle exec jekyll serve`
1. Add content

The above commands should be executed from the root directory of this project.

{% comment %}

Read more at Jekyll's [documentation][].

Might you have an include in your theme? Why not try it here!
{% include my-themes-great-include.html %}
{% endcomment %}


## Did you fork this project?

If you forked this project for your own use, please go to your project's
**Settings** and remove the forking relationship, which won't be necessary
unless you want to contribute back to the upstream project.

## Troubleshooting

1. CSS is missing! That means two things:
    * Either that you have wrongly set up the CSS URL in your templates, or
    * your static generator has a configuration option that needs to be explicitly
    set in order to serve static assets under a relative URL.

## features

**Settings (⚙)** > is capable to **"Remove fork relationship"** .

## G P Je

### Start from a local Jekyll project

1. Shared runners.

Pages are built by [GitLab CI][ci], following the steps
defined in [`.gitlab-ci.yml`](.gitlab-ci.yml):

```
image: ruby:latest

variables:
  JEKYLL_ENV: production

pages:
  script:
  - bundle install
  - bundle exec jekyll build -d public
  artifacts:
    paths:
    - public
  only:
  - master
```

## User or Group Pages

Read more about [user/group Pages][userpages] and [project Pages][projpages].

* [jekyll-branched](https://gitlab.com/pages/jekyll-branched) demonstrates how you can keep your GitLab Pages site in one branch and your project's source code in another.

## Troubleshooting

1. CSS is missing! That means two things:
    * Either that you have wrongly set up the CSS URL in your templates, or
    * your static generator has a configuration option that needs to be explicitly
    set in order to serve static assets under a relative URL.

[ci]: https://about.gitlab.com/gitlab-ci/
[projpages]: https://docs.gitlab.com/ce/user/project/pages/introduction.html#project-pages
[documentation]: https://jekyllrb.com/docs/home/


Get $100 using my special Referral

https://www.vultr.com/?ref=9028737-8H

## Trouble shooting

Starting Jekyll with bundler and overwrites some settings in `\_config.yml` with the second configuration file `\_config\_dev.yml`.

```
bundle exec jekyll serve --config _config.yml,_config_dev.yml
```

Start tracing.

```
bundle exec jekyll serve --trace --config _config.yml
```

### Preview

```
bundle config set --local without 'test _test legacy benchmark'
bundle install
bundle exec rake site:preview
```

### In case SSL warning is reported, build first before serving

```
/var/lib/gems/2.7.0/gems/jekyll-gist-1.5.0/lib/jekyll-gist/gist_tag.rb:98: warning: constant ::TimeoutError is deprecated
Liquid Exception: Connection reset by peer - SSL_connect
```

```
bundle exec jekyll clean && bundle exec jekyll build && bundle exec jekyll serve
```

## Inline HTML elements

HTML defines a long list of available inline tags, a complete list of which can be found on the [Mozilla Developer Network](https://developer.mozilla.org/en-US/docs/Web/HTML/Element).

- **To bold text**, use `<strong>`.
- *To italicize text*, use `<em>`.
- Abbreviations, like <abbr title="HyperText Markup Langage">HTML</abbr> should use `<abbr>`, with an optional `title` attribute for the full phrase.
- Citations, like <cite>&mdash; Mark otto</cite>, should use `<cite>`.
- <del>Deleted</del> text should use `<del>` and <ins>inserted</ins> text should use `<ins>`.
- Superscript <sup>text</sup> uses `<sup>` and subscript <sub>text</sub> uses `<sub>`.

## Code

Cum sociis natoque penatibus et magnis dis `code element` montes, nascetur ridiculus mus.

{% highlight js %}
// Example can be run directly in your JavaScript console

// Create a function that takes two arguments and returns the sum of those arguments
var adder = new Function("a", "b", "return a + b");

// Call the function
adder(2, 6);
// > 8
{% endhighlight %}

## Lists

<dl>
  <dt>HyperText Markup Language (HTML)</dt>
  <dd>The language used to describe and define the content of a Web page</dd>

  <dt>Cascading Style Sheets (CSS)</dt>
  <dd>Used to describe the appearance of Web content</dd>

  <dt>JavaScript (JS)</dt>
  <dd>The programming language used to build advanced Web sites and applications</dd>
</dl>

kramdown
: A Markdown-superset converter

Maruku
:     Another Markdown-superset converter

## Links

- http://www.lagom.nl/lcd-test/

Collecting stars...
[![Star This Project](https://img.shields.io/github/stars/ashang/ashang.svg?label=Stars&style=social)](https://github.com/ashang/ashang/)

https://www.reddit.com/r/gnome/comments/8sh7oa/a_nice_trick_to_create_a_mojavelike_time_shifting/
