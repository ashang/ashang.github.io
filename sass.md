+++
title = "Sass"
date = "2017-05-31"
weight = 110
+++

Don't forget that most people are short on time: reading a spec of 50 pages is just about possible, although 15 would have been better, but who is going to read 385 pages? The typical programmer will read the first 20 pages, look at a few more examples, and then start programming right away. He will fill in what he didn't read with what he thinks would be the logical extension... Unfortunately, specs aren't always logical; all too often they are the result of compromises between the committee members. Maybe that shouldn't be the case, but that's how it is.

杰出工程师的职位定义是“您应该是您所在领域的世界领先专家，因此您可以自由决定对于公司而言最重要的工作。”

With HTML, for example, rather than <font color="red">, a careful author writes <em class="warning"> and puts the rule that warnings are displayed in red in a style sheet. This way somebody who has no means to display (or see) red at least has a chance to substitute something else that alerts him (such as a nasty sound).

使用 HTML 而不是<font color="red">，细心的作者编写<em class="warning">并放置了警告在样式表中以红色显示的规则。这样，无法显示（或看到）红色的人至少有机会用其他东西来提醒他（例如讨厌的声音）。

CSS stops short of even more powerful features that programmers use in their programming languages: macros, variables, symbolic constants, conditionals, expressions over variables, etc. That is because these things give power-users a lot of rope, but less experienced users will unwittingly hang themselves; or, more likely, be so scared that they won't even touch CSS. It's a balance. And for CSS the balance is different than for some other things.

https://www.w3.org/People/Bos/DesignGuide/maintainability.html

模块化

人们在任何时候都只能有意识地使用有限数量的概念。解决智力问题时使用的短期记忆只能保存六到七个项目。因此，为了解决具有多个变量的复杂问题，我们将问题最多分为六个块，并以这些块作为构建块来构建解决方案。每个块都是一个局部问题，必须依次解决，但我们可以将其委托给其他人。当块小到可以指定朗朗上口的名字时，我们称它们为“模块”。

你怎么知道你把问题分成了正确的块？基本上是通过反复试验，虽然我们有一些主要基于我们的语言技能的直觉。

在定义模块时，我们试图找到“逻辑单元”，即看起来属于一起的东西。它与逻辑无关，而是与我们将这些事物归为一个共同名词的能力有关。因为，如果我们可以用一个简称来命名一个组，那可能意味着它是一个已知问题。本质上我们依赖隐喻，因为我们从其他问题领域获得名称。




Sass is a stylesheet language that’s compiled to CSS. It allows you to use variables, nested rules, mixins, functions, and more, all with a fully CSS-compatible syntax. Sass helps keep large stylesheets well-organized and makes it easy to share design within and across projects.

Sass is a popular CSS preprocessor that adds special features (e.g., variables, nested rules) to facilitate the
maintenance of large sets of CSS rules. If you're curious about what Sass
is and why it might be useful for styling your static site, the following links
may be of interest:


It currently uses a wrapper around LibSass 3.6.4.

See examples from [Why Sass?](https://alistapart.com/article/why-sass), by Dan Cederholm

```css
$brand-color: #fc3;
a {
color: $brand-color;
}
nav {
	background-color: $brand-color;
}
```

```css
@mixin default-type {
	margin-bottom: 20px;
	font-size: 14px;
	line-height: 1.5;
}
p {
@include default-type;
}
footer {
	@include default-type;
}
```

From an essay by CSS co-inventor, Bert Bos:

> CSS stops short of even more powerful features that programmers use in their programming languages: macros, variables, symbolic constants, conditionals, expressions over variables, etc. That is because these things give power-users a lot of rope, but less experienced users will unwittingly hang themselves; or, more likely, be so scared that they won’t even touch CSS. It’s a balance. And for CSS the balance is different than for some other things.

Sass is a CSS preprocessor—a layer between the stylesheets you author and the .css files you serve to the browser. Sass (short for Syntactically Awesome Stylesheets) plugs the holes in CSS as a language, allowing you to write DRY code that’ll be faster, more efficient, and easier to maintain.

The Sass website (http://bkaprt.com/sass/4/) describes itself succinctly:

    Sass is a meta-language on top of CSS that’s used to describe the style of a document cleanly and structurally, with more power than flat CSS allows. Sass both provides a simpler, more elegant syntax for CSS and implements various features that are useful for creating manageable stylesheets.

So while normal CSS doesn’t yet allow things like variables, mixins (reusable blocks of styles), and other goodies, Sass provides a syntax that does all of that and more—enabling “super functionality” in addition to your normal CSS. It then translates (or compiles) that syntax into regular ol’ CSS files via a command-line program or web-framework plugin.

More specifically, Sass is an extension of CSS3, and its SCSS (“Sassy CSS”) syntax—which we’ll talk about in just a moment—is a superset of CSS3. Meaning, any valid CSS3 document is a valid SCSS document as well. This is integral to Sass being something you can “ease into.” Getting started with Sass syntax is painless, and you can use as little or as much as you’d like. Which also means converting an existing stylesheet from CSS to SCSS can be done in stages, as you learn and pick up more of Sass’s functionality.



## Guide


    ## Preprocessing

    CSS on its own can be fun, but stylesheets are getting larger, more
    complex, and harder to maintain. This is where a preprocessor can help.
    Sass has features that don't exist in CSS yet like nesting, mixins,
    inheritance, and other nifty goodies that help you write robust,
    maintainable CSS.

    Once you start tinkering with Sass, it will take your preprocessed Sass
    file and save it as a normal CSS file that you can use in your website.

    The most direct way to make this happen is in your terminal. Once Sass is
    installed, you can compile your Sass to CSS using the `sass` command.
    You'll need to tell Sass which file to build from, and where to output CSS
    to. For example, running `sass input.scss output.css` from your terminal
    would take a single Sass file, `input.scss`, and compile that file to
    `output.css`.

    You can also watch individual files or directories with the `--watch`
    flag. The watch flag tells Sass to watch your source files for changes,
    and re-compile CSS each time you save your Sass. If you wanted to watch
    (instead of manually build) your `input.scss` file, you'd just add the
    watch flag to your command, like so:

        sass --watch input.scss output.css

    You can watch and output to directories by using folder paths as your
    input and output, and separating them with a colon. In this example:

  = partial 'code-snippets/homepage-sass-watch'

  :markdown
    Sass would watch all files in the `app/sass` folder for changes, and
    compile CSS to the `public/stylesheets` folder.

  .sl-c-callout.sl-c-callout--fun-fact
    :markdown
      ### 💡 Fun fact:

      Sass has two syntaxes! The SCSS syntax (`.scss`) is used most commonly. It's
      a superset of CSS, which means all valid CSS is also valid SCSS. The
      indented syntax (`.sass`) is more unusual: it uses indentation rather than
      curly braces to nest statements, and newlines instead of semicolons to
      separate them. All our examples are available in both syntaxes.

  %hr

%section#topic-2
  :markdown
    ## Variables

    Think of variables as a way to store information that you want to reuse
    throughout your stylesheet. You can store things like colors, font stacks,
    or any CSS value you think you'll want to reuse. Sass uses the `$` symbol
    to make something a variable. Here's an example:

  - example do
    :plain
      $font-stack: Helvetica, sans-serif;
      $primary-color: #333;

      body {
        font: 100% $font-stack;
        color: $primary-color;
      }
      ===
      $font-stack: Helvetica, sans-serif
      $primary-color: #333

      body
        font: 100% $font-stack
        color: $primary-color

  :markdown
    When the Sass is processed, it takes the variables we define for the
    `$font-stack` and `$primary-color` and outputs normal CSS with our
    variable values placed in the CSS. This can be extremely powerful when
    working with brand colors and keeping them consistent throughout the site.

    ---

%section#topic-3
  :markdown
    ## Nesting

    When writing HTML you've probably noticed that it has a clear nested and
    visual hierarchy. CSS, on the other hand, doesn't.

    Sass will let you nest your CSS selectors in a way that follows the same
    visual hierarchy of your HTML. Be aware that overly nested rules will
    result in over-qualified CSS that could prove hard to maintain and is
    generally considered bad practice.

    With that in mind, here's an example of some typical styles for a site's
    navigation:

  - example do
    :plain
      nav {
        ul {
          margin: 0;
          padding: 0;
          list-style: none;
        }

        li { display: inline-block; }

        a {
          display: block;
          padding: 6px 12px;
          text-decoration: none;
        }
      }
      ===
      nav
        ul
          margin: 0
          padding: 0
          list-style: none

        li
          display: inline-block

        a
          display: block
          padding: 6px 12px
          text-decoration: none

  :markdown
    You'll notice that the `ul`, `li`, and `a` selectors are nested inside the
    `nav` selector. This is a great way to organize your CSS and make it more
    readable.

    ---

%section#topic-4
  :markdown
    ## Partials

    You can create partial Sass files that contain little snippets of CSS that
    you can include in other Sass files. This is a great way to modularize
    your CSS and help keep things easier to maintain. A partial is a
    Sass file named with a leading underscore. You might name it something
    like `_partial.scss`. The underscore lets Sass know that the file is only
    a partial file and that it should not be generated into a CSS file. Sass
    partials are used with the `@use` rule.

    ---

%section#topic-5
  %h2 Modules
  = partial 'documentation/snippets/module-system-status'

  :markdown
    You don't have to write all your Sass in a single file. You can split it up
    however you want with the `@use` rule. This rule loads another Sass file as
    a *module*, which means you can refer to its variables, [mixins][], and
    [functions][] in your Sass file with a namespace based on the filename.
    Using a file will also include the CSS it generates in your compiled output!

    [mixins]: #topic-6
    [functions]: documentation/at-rules/function

  - example do
    :plain
      // _base.scss
      $font-stack: Helvetica, sans-serif;
      $primary-color: #333;

      body {
        font: 100% $font-stack;
        color: $primary-color;
      }
      ---
      // styles.scss
      @use 'base';

      .inverse {
        background-color: base.$primary-color;
        color: white;
      }
      ===
      // _base.sass
      $font-stack: Helvetica, sans-serif
      $primary-color: #333

      body
        font: 100% $font-stack
        color: $primary-color
      ---
      // styles.sass
      @use 'base'

      .inverse
        background-color: base.$primary-color
        color: white
      ===
      body {
        font: 100% Helvetica, sans-serif;
        color: #333;
      }

      .inverse {
        background-color: #333;
        color: white;
      }

  :markdown
    Notice we're using `@use 'base';` in the `styles.scss` file. When you use a
    file you don't need to include the file extension. Sass is smart and will
    figure it out for you.

    ---

%section#topic-6
  :markdown
    ## Mixins

    Some things in CSS are a bit tedious to write, especially with CSS3 and
    the many vendor prefixes that exist. A mixin lets you make groups of CSS
    declarations that you want to reuse throughout your site. It helps keep your
    Sass very DRY. You can even pass in values to make your mixin more flexible.
    Here's an example for `theme`.

  - example do
    :plain
      @mixin theme($theme: DarkGray) {
        background: $theme;
        box-shadow: 0 0 1px rgba($theme, .25);
        color: #fff;
      }

      .info {
        @include theme;
      }
      .alert {
        @include theme($theme: DarkRed);
      }
      .success {
        @include theme($theme: DarkGreen);
      }
      ===
      @mixin theme($theme: DarkGray)
        background: $theme
        box-shadow: 0 0 1px rgba($theme, .25)
        color: #fff


      .info
        @include theme

      .alert
        @include theme($theme: DarkRed)

      .success
        @include theme($theme: DarkGreen)

  :markdown
    To create a mixin you use the `@mixin` directive and give it a name. We've
    named our mixin `theme`. We're also using the variable `$theme`
    inside the parentheses so we can pass in a `theme` of whatever we want.
    After you create your mixin, you can then use it as a CSS declaration
    starting with `@include` followed by the name of the mixin.

    ---

%section#topic-7
  :markdown
    ## Extend/Inheritance

    Using `@extend` lets you share a set of CSS properties from one selector to
    another. In our example we're going to create a simple series of messaging
    for errors, warnings and successes using another feature which goes hand in
    hand with extend, placeholder classes. A placeholder class is a special type
    of class that only prints when it is extended, and can help keep your
    compiled CSS neat and clean.

  - example do
    :plain
      /* This CSS will print because %message-shared is extended. */
      %message-shared {
        border: 1px solid #ccc;
        padding: 10px;
        color: #333;
      }

      // This CSS won't print because %equal-heights is never extended.
      %equal-heights {
        display: flex;
        flex-wrap: wrap;
      }

      .message {
        @extend %message-shared;
      }

      .success {
        @extend %message-shared;
        border-color: green;
      }

      .error {
        @extend %message-shared;
        border-color: red;
      }

      .warning {
        @extend %message-shared;
        border-color: yellow;
      }
      ===
      /* This CSS will print because %message-shared is extended. */
      %message-shared
        border: 1px solid #ccc
        padding: 10px
        color: #333


      // This CSS won't print because %equal-heights is never extended.
      %equal-heights
        display: flex
        flex-wrap: wrap


      .message
        @extend %message-shared


      .success
        @extend %message-shared
        border-color: green


      .error
        @extend %message-shared
        border-color: red


      .warning
        @extend %message-shared
        border-color: yellow

  :markdown
    What the above code does is tells `.message`, `.success`, `.error`, and
    `.warning` to behave just like `%message-shared`. That means anywhere that
    `%message-shared` shows up, `.message`, `.success`, `.error`, & `.warning`
    will too. The magic happens in the generated CSS, where each of these
    classes will get the same CSS properties as `%message-shared`. This helps
    you avoid having to write multiple class names on HTML elements.

    You can extend most simple CSS selectors in addition to placeholder
    classes in Sass, but using placeholders is the easiest way to make sure
    you aren't extending a class that's nested elsewhere in your styles, which
    can result in unintended selectors in your CSS.

    Note that the CSS in `%equal-heights` isn't generated, because
    `%equal-heights` is never extended.

    ---

%section#topic-8
  :markdown
    ## Operators

    Doing math in your CSS is very helpful. Sass has a handful of standard
    math operators like `+`, `-`, `*`, `math.div()`, and `%`. In our example
    we're going to do some simple math to calculate widths for an `article` and
    `aside`.

  - example do
    :plain
      @use "sass:math";

      .container {
        display: flex;
      }

      article[role="main"] {
        width: math.div(600px, 960px) * 100%;
      }

      aside[role="complementary"] {
        width: math.div(300px, 960px) * 100%;
        margin-left: auto;
      }
      ===
      @use "sass:math"

      .container
        display: flex

      article[role="main"]
        width: math.div(600px, 960px) * 100%

      aside[role="complementary"]
        width: math.div(300px, 960px) * 100%
        margin-left: auto
      ===
      .container {
        display: flex;
      }

      article[role="main"] {
        width: 62.5%;
      }

      aside[role="complementary"] {
        width: 31.25%;
        margin-left: auto;
      }

  :markdown
    We've created a very simple fluid grid, based on 960px. Operations in Sass
    let us do something like take pixel values and convert them to percentages
    without much hassle.


## Modules

### Built-In Modules

introduction: >
  Sass provides many built-in modules which contain useful functions (and the
  occasional mixin). These modules can be loaded with the
  [`@use` rule](at-rules/use) like any user-defined stylesheet, and their
  functions can be called [like any other module
  member](at-rules/use#loading-members). All built-in module URLs begin with
  `sass:` to indicate that they're part of Sass itself.

<% heads_up do %>
  Before the Sass module system was introduced, all Sass functions were globally
  available at all times. Many functions still have global aliases (these are
  listed in their documentation). The Sass team discourages their use and will
  eventually deprecate them, but for now they remain available for compatibility
  with older Sass versions and with LibSass (which doesn't support the module
  system yet).

  [A few functions][] are *only* available globally even in the new module
  system, either because they have special evaluation behavior ([`if()`][]) or
  because they add extra behavior on top of built-in CSS functions ([`rgb()`][]
  and [`hsl()`][]). These will not be deprecated and can be used freely.


<% end %>

<% example do %>
  @use "sass:color";

  .button {
    $primary-color: #6b717f;
    color: $primary-color;
    border: 1px solid color.scale($primary-color, $lightness: 20%);
  }
  ===
  @use "sass:color"

  .button
    $primary-color: #6b717f
    color: $primary-color
    border: 1px solid color.scale($primary-color, $lightness: 20%)
  ===
  .button {
    color: #6b717f;
    border: 1px solid #878d9a;
  }
<% end %>

Sass provides the following built-in modules:

* The [`sass:math` module][] provides functions that operate on [numbers][].

* The [`sass:string` module][] makes it easy to combine, search, or split apart
  [strings][].

* The [`sass:color` module][] generates new [colors][] based on existing ones,
  making it easy to build color themes.

* The [`sass:list` module][] lets you access and modify values in [lists][].

* The [`sass:map` module][] makes it possible to look up the value associated
  with a key in a [map][], and much more.

* The [`sass:selector` module][] provides access to Sass's powerful selector
  engine.

* The [`sass:meta` module][] exposes the details of Sass's inner workings.

[`sass:math` module]: modules/math
[numbers]: values/numbers
[`sass:string` module]: modules/string
[strings]: values/strings
[`sass:color` module]: modules/color
[colors]: values/colors
[`sass:list` module]: modules/list
[lists]: values/lists
[`sass:map` module]: modules/map
[map]: values/maps
[`sass:selector` module]: modules/selector
[`sass:meta` module]: modules/meta

## style rules

introduction: >
  Style rules are the foundation of Sass, just like they are for CSS. And they
  work the same way: you choose which elements to style with a selector, and
  [declare properties](style-rules/declarations) that affect how those elements
  look.

<% example do %>
  .button {
    padding: 3px 10px;
    font-size: 12px;
    border-radius: 3px;
    border: 1px solid #e1e4e8;
  }
  ===
  .button
    padding: 3px 10px
    font-size: 12px
    border-radius: 3px
    border: 1px solid #e1e4e8
<% end %>

### Property Declarations

introduction: >
  In Sass as in CSS, property declarations define how elements that match a
  selector are styled. But Sass adds extra features to make them easier to write
  and to automate. First and foremost, a declaration's value can be any
  [SassScript expression](../syntax/structure#expressions), which will be
  evaluated and included in the result.

<% example do %>
  .circle {
    $size: 100px;
    width: $size;
    height: $size;
    border-radius: $size * 0.5;
  }
  ===
  .circle
    $size: 100px
    width: $size
    height: $size
    border-radius: $size * 0.5
<% end %>


## at-rules/use

title: "@use"
table_of_contents: true
introduction: >
  The `@use` rule loads [mixins](mixin), [functions](function), and
  [variables](../variables) from other Sass stylesheets, and combines CSS from
  multiple stylesheets together. Stylesheets loaded by `@use` are called
  "modules". Sass also provides [built-in modules](../modules) full of useful
  functions.

The simplest `@use` rule is written `@use "<url>"`, which loads the module at
the given URL. Any styles loaded this way will be included exactly once in the
compiled CSS output, no matter how many times those styles are loaded.

<% heads_up do %>
  A stylesheet's `@use` rules must come before any rules other than `@forward`,
  including [style rules][]. However, you can declare variables before `@use`
  rules to use when [configuring modules][].

  [style rules]: ../style-rules

<% end %>

<% example do %>
  // foundation/_code.scss
  code {
    padding: .25em;
    line-height: 0;
  }
  ---
  // foundation/_lists.scss
  ul, ol {
    text-align: left;

    & & {
      padding: {
        bottom: 0;
        left: 0;
      }
    }
  }
  ---
  // style.scss
  @use 'foundation/code';
  @use 'foundation/lists';
  ===
  // foundation/_code.sass
  code
    padding: .25em
    line-height: 0
  ---
  // foundation/_lists.sass
  ul, ol
    text-align: left

    & &
      padding:
        bottom: 0
        left: 0
  ---
  // style.sass
  @use 'foundation/code'
  @use 'foundation/lists'
  ===
  code {
    padding: .25em;
    line-height: 0;
  }

  ul, ol {
    text-align: left;
  }
  ul ul, ol ol {
    padding-bottom: 0;
    padding-left: 0;
  }
<% end %>

## Using Sass in Zola

Zola processes any files with the `sass` or `scss` extension in the `sass`
folder, and places the processed output into a `css` file with the same folder
structure and base name into the `public` folder:

```bash
.
└── sass
    ├── style.scss // -> ./public/style.css
    ├── indented_style.sass // -> ./public/indented_style.css
    ├── _include.scss # This file won't get put into the `public` folder, but other files can @import it.
    ├── assets
    │   ├── fancy.scss // -> ./public/assets/fancy.css
    │   ├── same_name.scss // -> ./public/assets/same_name.css
    │   ├── same_name.sass # CONFLICT! This has the same base name as the file above, so Zola will return an error.
    │   └── _common_mixins.scss # This file won't get put into the `public` folder, but other files can @import it.
    └── secret-side-project
        └── style.scss // -> ./public/secret-side-project/style.css
```

Files with a leading underscore in the name are not placed into the `public`
folder, but can still be used as `@import` dependencies. For more information, see the "Partials" section of
[Sass Basics](https://sass-lang.com/guide).

Files with the `scss` extension use "Sassy CSS" syntax,
while files with the `sass` extension use the "indented" syntax: <https://sass-lang.com/documentation/syntax>.
Zola will return an error if `scss` and `sass` files with the same
base name exist in the same folder to avoid confusion -- see the example above.


```
Post-install message from dnsruby:
Installing dnsruby...
  For issues and source code: https://github.com/alexdalitz/dnsruby
  For general discussion (please tell us how you use dnsruby): https://groups.google.com/forum/#!forum/dnsruby
```

```
Post-install message from rubyzip:
RubyZip 3.0 is coming!
**********************

The public API of some Rubyzip classes has been modernized to use named
parameters for optional arguments. Please check your usage of the
following classes:
  * `Zip::File`
  * `Zip::Entry`
  * `Zip::InputStream`
  * `Zip::OutputStream`

Please ensure that your Gemfiles and .gemspecs are suitably restrictive
to avoid an unexpected breakage when 3.0 is released (e.g. ~> 2.3.0).
See https://github.com/rubyzip/rubyzip for details. The Changelog also
lists other enhancements and bugfixes that have been implemented since
version 2.3.0.
```

## Introduction

This is a quick reference to [Sass stylesheets](https://sass-lang.com).

- [Sass documentation](https://sass-lang.com/documentation) _(sass-lang.com)_

### Variables

```scss
$red: #833;
```

```scss
body {
  color: $red;
}
```

### Nesting

```scss
.markdown-body {
  a {
    color: blue;
    &:hover {
      color: red;
    }
  }
}
```

#### to properties
```scss
text: {
  align: center;          // like text-align: center
  transform: uppercase;   // like text-transform: uppercase
}
```

### Comments

```scss
/* Block comments */
// Line comments
```

### Mixins

```scss
@mixin heading-font {
  font-family: sans-serif;
  font-weight: bold;
}
```

```scss
h1 {
  @include heading-font;
}
```

#### with parameters

```scss
@mixin font-size($n) {
  font-size: $n * 1.2em;
}
```

```scss
body {
  @include font-size(2);
}
```

#### with default values

```scss
@mixin pad($n: 10px) {
  padding: $n;
}
```

```scss
body {
  @include pad(15px);
}
```

#### with a default variable

```scss
// Set a default value
$default-padding: 10px;
```

```scss
@mixin pad($n: $default-padding) {
  padding: $n;
}
```

```scss
body {
  @include pad(15px);
}
```

### Extend

```scss
.button {
  ···
}
```

```scss
.push-button {
  @extend .button;
}
```

### Composing

```scss
@import './other_sass_file';
@use './other_sass_file';
```

The `@import` rule is discouraged because will get eventually [removed from the language](https://sass-lang.com/documentation/at-rules/import).

Instead, we should use the [`@use` rule](https://sass-lang.com/documentation/at-rules/use).

The `.scss` or `.sass` extension is optional.

## Color functions

### rgba

```scss
rgb(100, 120, 140)
rgba(100, 120, 140, .5)
rgba($color, .5)
```

### Mixing

```scss
mix($a, $b, 10%)   // 10% a, 90% b
```

### Modifying HSLA

```scss
darken($color, 5%)
lighten($color, 5%)
```

```scss
saturate($color, 5%)
desaturate($color, 5%)
grayscale($color)
```

```scss
adjust-hue($color, 15deg)
complement($color)    // like adjust-hue(_, 180deg)
invert($color)
```

```scss
fade-in($color, .5)   // aka opacify()
fade-out($color, .5)  // aka transparentize() - halves the opacity
rgba($color, .5)      // sets alpha to .5
```

### Getting individual values

#### HSLA

```scss
hue($color)         // → 0deg..360deg
saturation($color)  // → 0%..100%
lightness($color)   // → 0%..100%
alpha($color)       // → 0..1 (aka opacity())
```

#### RGB

```scss
red($color)         // → 0..255
green($color)
blue($color)
```

See: [hue()](http://sass-lang.com/documentation/Sass/Script/Functions.html#hue-instance_method), [red()](http://sass-lang.com/documentation/Sass/Script/Functions.html#red-instance_method)

### Adjustments

```scss
// Changes by fixed amounts
adjust-color($color, $blue: 5)
adjust-color($color, $lightness: -30%)   // like darken(_, 30%)
adjust-color($color, $alpha: -0.4)       // like fade-out(_, .4)
adjust-color($color, $hue: 30deg)        // like adjust-hue(_, 15deg)
```

```scss
// Changes via percentage
scale-color($color, $lightness: 50%)
```

```scss
// Changes one property completely
change-color($color, $hue: 180deg)
change-color($color, $blue: 250)
```

Supported: `$red` `$green` `$blue` `$hue` `$saturation` `$lightness` `$alpha`

## Other functions

### Strings

```scss
unquote('hello')
quote(hello)
```

```scss
to-upper-case(hello)
to-lower-case(hello)
```

```scss
str-length(hello world)
str-slice(hello, 2, 5)      // "ello" - it's 1-based, not 0-based
str-insert("abcd", "X", 1)  // "Xabcd"
```

### Units

```scss
unit(3em)        // 'em'
unitless(100px)  // false
```

### Numbers

```scss
floor(3.5)
ceil(3.5)
round(3.5)
abs(3.5)
```

```scss
min(1, 2, 3)
max(1, 2, 3)
```

```scss
percentage(.5)   // 50%
random(3)        // 0..3
```

### Misc

```scss
variable-exists(red)    // checks for $red
mixin-exists(red-text)  // checks for @mixin red-text
function-exists(redify)
```

```scss
global-variable-exists(red)
```

```scss
selector-append('.menu', 'li', 'a')   // .menu li a
selector-nest('.menu', '&:hover li')  // .menu:hover li
selector-extend(...)
selector-parse(...)
selector-replace(...)
selector-unify(...)
```

## Feature checks

### Feature check

```scss
feature-exists(global-variable-shadowing)
```

### Features

* global-variable-shadowing
* extend-selector-pseudoclass
* units-level-3
* at-error

## Loops

### For loops

```scss
@for $i from 1 through 4 {
  .item-#{$i} { left: 20px * $i; }
}
```

### Each loops (simple)

```scss
$menu-items: home about services contact;

@each $item in $menu-items {
  .photo-#{$item} {
    background: url('images/#{$item}.jpg');
  }
}
```

### Each loops (nested)
```scss
$backgrounds: (home, 'home.jpg'), (about, 'about.jpg');

@each $id, $image in $backgrounds {
  .photo-#{$id} {
    background: url($image);
  }
}
```

### While loops

```scss
$i: 6;
@while $i > 0 {
  .item-#{$i} { width: 2em * $i; }
  $i: $i - 2;
}
```

## Other features

### Conditionals

```scss
@if $position == 'left' {
   position: absolute;
   left: 0;
}
@else if $position == 'right' {
   position: absolute;
   right: 0;
}
@else {
   position: static;
}
```

### Interpolation

```scss
.#{$klass} { ... }      // Class
call($function-name)    // Functions

@media #{$tablet}
font: #{$size}/#{$line-height}
url("#{$background}.jpg")
```

### Lists

```scss
$list: (a b c);

nth($list, 1)  // starts with 1
length($list)

@each $item in $list { ... }
```

### Maps

```scss
$map: (key1: value1, key2: value2, key3: value3);

map-get($map, key1)
```

## See also

- <http://sass-lang.com/documentation/Sass/Script/Functions.html>
- <http://sass-lang.com/documentation/file.SASS_REFERENCE.html#sassscript>


## Ruby sass end of life

```sh
$ bundle install
Fetching source index from https://mirrors
Using addressable 2.7.0
Using bundler 2.1.4
...
Fetching sass 3.7.4
Downloading sass-3.7.4 revealed dependencies not in the API or the lockfile (sass-listen (~> 4.0.0)).
Either installing with `--full-index` or running `bundle update sass` should fix the problem.

$ bundle update sass
Fetching source index from https://mirrors
Resolving dependencies....
Using addressable 2.7.0
Using bundler 2.1.4
...
Using sass-listen 4.0.0
Fetching sass 3.7.4
Installing sass 3.7.4
...
Bundler attempted to update sass but its version stayed the same
Bundle updated!
Post-install message from sass:

Ruby Sass has reached end-of-life and should no longer be used.

* If you use Sass as a command-line tool, we recommend using Dart Sass, the new
  primary implementation: https://sass-lang.com/install

* If you use Sass as a plug-in for a Ruby web framework, we recommend using the
  sassc gem: https://github.com/sass/sassc-ruby#readme

* For more details, please refer to the Sass blog:
  https://sass-lang.com/blog/posts/7828841
```

## Hugo Pipes allows the processing of Sass and SCSS files.

Any Sass or SCSS file can be transformed into a CSS file using `resources.ToCSS` which takes two arguments, the resource object and a map of options listed below.

```go
{{ $sass := resources.Get "sass/main.scss" }}
{{ $style := $sass | resources.ToCSS }}
```

### Options

transpiler [string]

: The `transpiler` to use, valid values are `libsass` (default) and `dartsass`. If you want to use Hugo with Dart Sass you need to download a release binary from [Embedded Dart Sass](https://github.com/sass/dart-sass-embedded/releases) and make sure it's in your PC's `$PATH` (or `%PATH%` on Windows).

targetPath [string]
: If not set, the resource's target path will be the asset file original path with its extension replaced by `.css`.

outputStyle [string]
: Default is `nested` (LibSass) and `expanded` (Dart Sass). Other available output styles for LibSass are `expanded`, `compact` and `compressed`. Dart Sass only supports `expanded` and `compressed`.

precision [int]
: Precision of floating point math. **Note:** This option is not supported by Dart Sass.

enableSourceMap [bool]
: When enabled, a source map will be generated.

sourceMapIncludeSources [bool]
: When enabled, sources will be embedded in the generated source map. (Dart Sass only). {{< new-in "0.108.0" >}}

includePaths [string slice]
: Additional SCSS/Sass include paths. Paths must be relative to the project directory.

```go
{{ $options := (dict "targetPath" "style.css" "outputStyle" "compressed" "enableSourceMap" (not hugo.IsProduction) "includePaths" (slice "node_modules/myscss")) }}
{{ $style := resources.Get "sass/main.scss" | resources.ToCSS $options }}
```

{{% note %}}
Setting `outputStyle` to `compressed` will handle Sass/SCSS files minification better than the more generic [`resources.Minify`]({{< ref "minification">}}).
{{% /note %}}
