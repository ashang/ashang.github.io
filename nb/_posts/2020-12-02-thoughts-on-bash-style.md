---
title: "Thoughts on Bash Style"
layout: post
---

I try to do as little shell scripting as I can get away with.  But I thought
I'd put a little set of notes together for my own reference.  My bias here
tends toward trying to minimize clutter, so I have a better shot at actually
seeing what's going on.


**DO use [[ ]] in conditions, so `>` is greater (not redirect) and $X is "$X"**

As far as I can tell, basically any `if` statement should use the double
bracket form.

<http://mywiki.wooledge.org/BashFAQ/031>


**DON'T put variable *values* in quotes that don't need it (FOO=x not FOO="x")**

Bash's medium is strings, and it's willing to delimit those strings for you
implicitly when they don't have spaces.  Might as well use that.


**DO put variable *substitutions* in quotes ("$X" not $X), EXCEPT in [[ ]]**

Seeing `[[ ]]` as a whole separate universe seems to be the way to go.  So I
figure why not take advantage of the feature of the implicit quoting.

<https://unix.stackexchange.com/q/131766/>


**DON'T use curly braces on variables unless needed ("$FOO" not "${FOO}")**

The $ calls enough attention to the fact that it's a variable.  So if you
aren't splicing a variable into a place where it abuts other characters that
would be mistaken as part of the variable name, avoid the `{}`.

<https://unix.stackexchange.com/a/4910>


**DO use = in [[ ]] conditions for lexical comparison (= not ==)**

<https://unix.stackexchange.com/a/16110>


**DON'T put space between x=y when doing variable assignments**

A good reason not to do this is because you can't! :-/

<https://unix.stackexchange.com/a/297217>


**DON'T use superfluous semicolons at end of lines of shell commands**

<https://stackoverflow.com/a/7507242/>


**DO use `$(...)` vs. `` `...` `` for shell execution**

To me, it just seems more obvious that the $ means "substitute".  But also,
I kind of like special-purposing `` `...` `` for calling out code in comments.

(Plus, as I write this, backticks are a pain to escape in MarkDown.  Best if
you just leave them out of your code.)


<https://stackoverflow.com/a/9406350/>


**"$foo 123" -> substitutes foo contents to get `foocontents 123`**

This one I tend to remember.


**'$foo 123' -> takes it literally, so you get `$foo 123`**

This one I forget about.


**`xargs` may be a useful command when dealing with the shell**

Something to look at:

<http://man7.org/linux/man-pages/man1/xargs.1.html>  (e.g. `... | xargs cat`)
