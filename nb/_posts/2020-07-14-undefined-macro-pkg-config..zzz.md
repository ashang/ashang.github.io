---
title:  "Why 'Possibly Undefined Macro' Means Install pkg-config"
layout: post
---

GNU Autotools has always seemed like voodoo to me. When a package has a
`configure.ac` and `Makefile.am` or `aclocal.m4`, I know they're three file
extensions used nowhere else in the programming universe. It never seemed
productive to study something from before my time that apparently merited no
broader use in software engineering. So I just try typing every command that
starts with "auto"...search the Internet for error messages I get...and blindly
try the guesses people offer in message threads until a working **configure**
script and **Makefile** magically appear.

This weekend I was trying to build the RedHat Package Manager (RPM), and it was
the same old story. After fumbling on through whatever autoconf/autoreconf
or aclocal got me to the next **sudo apt install**, I got this:

    configure.ac:34: error: possibly undefined macro: AC_MSG_ERROR
        If this token and others are legitimate, please use m4_pattern_allow.
        See the Autoconf documentation.
    configure.ac:143: error: possibly undefined macro: AC_DEFINE
    autoreconf: /usr/bin/autoconf failed with exit status: 1

There were a couple of pieces of failed advice. One person on a mailing list
suggested installing **autoconf-archive**, which is an auxiliary set of macros
that aren't in the standard distribution. It didn't work for the person asking
the question, and it didn't work for me.

But why *would* it work? These aren't esoteric macro contributions from the
community. They're [in the manual][3], and you can edit simple tutorial files
which use them freely.

[3]: http://www.gnu.org/software/autoconf/manual/html_node/Autoconf-Macro-Index.html#Autoconf-Macro-Index

What could RedHat Package Manager be doing to make them *seem* undefined?


## Problem...Solved?

The advice that actually worked was **sudo apt install pkg-config**.  While
I had to try a couple of unhelpful steps before that, it isn't like it took
*long* to get a resolution. Just another few-minute voodoo speed-bump to forget
until the next time.

But...something about this case got to me. *No one* explained it. I tried just
about every search I could to see if there was a reasoned rationale, but the
best I mustered were sympathetic voices saying "yeah, sometimes autoconf error
mesages are really bad". Yet this seemed like a complaint coming from the macro
processor itself about missing definitions. How was autoconf screwing this up,
and why hadn't anyone fixed it?

I found a [whole page for "demystifying" the error][4], which was just an echo
of every other place on the Internet: *this happens because you need
`pkg-config`, since without `pkg-config` you will get the error.*

[4]: https://ahelpme.com/linux/compiling/missing-pkg-config-results-in-configure-error-possibly-undefined-macro/

It was glaringly obvious that a globe full of programmers were steadfast in the
same attitude I'd had about autotools. No one wanted to take any time to look
into it.

So I caved, and I looked.


## A Simple, Failing, Heuristic

What is happening is not that the macros are undefined. They're just winding up
as part of a context where they are not being expanded...hence left as strings
in the output file that start with `AC_`. A piece of autoconf called
**autom4te** (written in perl) notices that the output still has such patterns
after expansion, and wrongly guesses that implies a missing definition.

The actual regular expressions that are being looked for in the post-expansion
text are a little hard to find. But a few are in [autoconf/general.m4][5]:

    m4_pattern_forbid([^_?A[CHUM]_])
    m4_pattern_forbid([_AC_])
    m4_pattern_forbid([^LIBOBJS$],
		  [do not use LIBOBJS directly, use AC_LIBOBJ (see section `AC_LIBOBJ vs LIBOBJS'])

[5]: https://github.com/autotools-mirror/autoconf/blob/ff47b2ea8d53dd4dc7536775e4a222dc18837fcb/lib/autoconf/general.m4#L1414

That first regular expression `^_?A[CHUM]_` when translated into English is:

> "Match any pattern at the beginning of a line (`^`) which may or may not
> begin with an underscore (`_?`) that is followed by `AC_`, `AH_`, `AU_`,
> or `AM_`."

*(The abbreviations are for AutoConfig, AutoHeader, AutoUpdate, and AutoMake.)*

That looks like a smoking gun! But for thoroughness, we can dig up a couple
more forbidden patterns in [autoconf/m4sugar.m4][6]:

    m4_pattern_forbid([^_?m4_])
    m4_pattern_forbid([^dnl$])

[6]: https://github.com/autotools-mirror/autoconf/blob/ff47b2ea8d53dd4dc7536775e4a222dc18837fcb/lib/autoconf/general.m4#L1415

Then one from [autoconf/m4sh.m4][7]:

    m4_pattern_forbid([^_?AS_])

*(This abbreviates AutoShell macros...helpers for basic shell constructs.)*

[7]: https://github.com/autotools-mirror/autoconf/blob/c6daae41276a49b52a9d5e2f70c95651364ed619/lib/m4sugar/m4sh.m4#L2139

In the case I was looking at, it used "libtool" which added another from its
[m4/libtool.m4][8]:

    m4_pattern_forbid([^_?LT_[A-Z_]+$])dnl

[8]: https://github.com/autotools-mirror/libtool/blob/b9b44533fbf7c7752ffd255c3d09cc360e24183b/m4/libtool.m4#L70

The point of listing all of these is to explain how in the case of RPM, the
variable `$forbidden` comes to be assigned in autom4te to the complete
expression of possibilities:

    ^_?A[CHUM]_|_AC_|^LIBOBJS$|^_?m4_|^dnl$|^_?AS_|^_?LT_[A-Z_]+$

If it sees anything in that list of alternate patterns, it assumes a mistake,
and [warns you about the residue][9] it believes should have vaporized in the
m4 expansion process.

[9]: https://github.com/autotools-mirror/autoconf/blob/ff47b2ea8d53dd4dc7536775e4a222dc18837fcb/bin/autom4te.in#L616


## Examining a Trivial Case

Let's try a very simple step with just `autoconf`. The only thing we will
write is the **configure.ac**:

    # configure.ac
    AC_INIT([Basic Case], 1.0)
    AM_INIT_AUTOMAKE
    AC_PROG_CC
    AC_CONFIG_FILES(Makefile)
    AC_OUTPUT

    MAKE_ME_A_SANDWICH

On that last line, I threw in something we're pretty sure that autoconf isn't
going to recognize. Let's try it.

    $ autoconf

This generates a nearly 5,000 lines long **configure** shell script. But at
the bottom of it, the last line is still MAKE_ME_A_SANDWICH. It isn't a macro,
so it's passed through as part of what it imagines is plain shell script code.

Now let's try something a little different:

    # configure.ac
    AC_INIT([Forbidden Case], 1.0)
    AM_INIT_AUTOMAKE
    AC_PROG_CC
    AC_CONFIG_FILES(Makefile)
    AC_OUTPUT

    AC_MAKE_ME_A_SANDWICH

This time we've used something that matches one of the forbidden patterns, that
has no definition in effect. So autom4te is going to complain:

    $ autocconf
    configure.ac:7: error: possibly undefined macro: AC_MAKE_ME_A_SANDWICH
        If this token and others are legitimate, please use m4_pattern_allow.
        See the Autoconf documentation.

But if we remember our patterns it had to be at the start of a line to be a
problem. Let's try a twist:

    # configure.ac
    AC_INIT([Not Start Of Line Case], 1.0)
    AM_INIT_AUTOMAKE
    AC_PROG_CC
    AC_CONFIG_FILES(Makefile)
    AC_OUTPUT

    if [ $AC_MAKE_ME_A_SANDWICH == abcdef ] ; then echo yes ; else echo no ; fi

That looks like passable bash code. And the `AC_` isn't at the start of a line.
So what does autoconf say?

    $ autoconf
    configure.ac:7: error: possibly undefined macro: AC_MAKE_ME_A_SANDWICH
      If this token and others are legitimate, please use m4_pattern_allow.
      See the Autoconf documentation.

Whoops. What we missed is that autom4te is actually breaking the output up in
terms of its idea of "words", which [runs a gauntlet of substitutions][10]
before doing that start-of-line test:

      s/\s+$//;
      s/__oline__/$./g;
      s/\@<:\@/[/g;
      s/\@:>\@/]/g;
      s/\@\{:\@/(/g;
      s/\@:\}\@/)/g;
      s/\@S\|\@/\$/g;
      s/\@%:\@/#/g;

      $res = $_;

      # Don't complain in comments.  Well, until we have something
      # better, don't consider '#include' etc. are comments.
      s/\#.*//
	unless /^\#\s*(if|include|endif|ifdef|ifndef|define)\b/;
      foreach (split (/\W+/))
	{
	  $prohibited{$_} = $.
	    if !/^$/ && /$forbidden/o && !/$allowed/o && ! exists $prohibited{$_};
	}

[10]: https://github.com/autotools-mirror/autoconf/blob/ff47b2ea8d53dd4dc7536775e4a222dc18837fcb/bin/autom4te.in#L564

So our `$forbidden` patterns become actually more of a start-of-word test, and
the violators are collected in `$prohibited` and reported to us.


## Without Further Ado: The pkg-config Debacle

The previous section seems like it "worked"...in the sense that we tried to
use AC_MAKE_ME_A_SANDWICH, which looks like an autoconfig macro but had no
definition. So the warning helps us know we either made a typo or need to
get the dependency where it's defined.

But the errors I was getting in RPM were for AC_DEFINE and AC_MSG_ERROR, that
do have definitions. Digging in I find [it comes from this code][11] in the
configure.ac file for RPM:

    PKG_CHECK_MODULES([LUA],
      [lua >= 5.1],
      [AC_DEFINE(WITH_LUA, 1, [Build with lua support?])],
      [AC_MSG_ERROR([lua not present (--without-lua to disable)])])

[11]: https://github.com/rpm-software-management/rpm/blob/16d9074e1a3020f8844ed4a213fb92e844d8f9ad/configure.ac#L763

We have a macro being parameterized with other macros. If you don't have
PKG_CHECK_MODULES pulled into your definitions, it might as well have been
MAKE_ME_A_SANDWICH...it's left as-is. So the macro processor thinks the only
work it has to do in this case is to vaporize the brackets (which are m4's
means of "quoting" the contained material to pass through verbatim).

To make the point, let's try an AC_DEFINE call when the call itself is not
enclosed in brackets:

    # configure.ac
    AC_INIT([No Outer Brackets], 1.0)
    AM_INIT_AUTOMAKE
    AC_PROG_CC
    AC_CONFIG_FILES(Makefile)
    AC_OUTPUT

    AC_DEFINE(WITH_LUA, 1, [Build with lua support?])

When we run that through autoconf, the last line of the long configure file
that is generated looks like:

    $as_echo "#define WITH_LUA 1" >>confdefs.h

Convoluted though this is, we see what's happening. It's making a shell script
that makes a header file with a #define in it.  But what if we had tried the
same thing with surrounding brackets?

    # configure.ac
    AC_INIT([Outer Brackets], 1.0)
    AM_INIT_AUTOMAKE
    AC_PROG_CC
    AC_CONFIG_FILES(Makefile)
    AC_OUTPUT

    [AC_DEFINE(WITH_LUA, 1, [Build with lua support?])]

We now see a different last line of our configure file:

    AC_DEFINE(WITH_LUA, 1, [Build with lua support?])

This reveals the problem that arises when PKG_CHECK_MODULES isn't defined.
It's a macro whose job it is to take quoted macro material and pick a branch
to run (either a definition branch or an erroring branch). But without that
defined, the quoted material simply becomes unquoted and triggers the forbidden
pattern.

Hence: if you `sudo apt install pkg-info`, you get a definition for
PKG_CHECK_MODULES. That means at autoconf time there'll be an active macro that
ensures that either the AC_DEFINE or AC_MSG_ERROR will be expanded.


## How Might This Get Better?

A simple-minded improvement would be if you convinced the autotools maintainers
to add an m4_pattern_forbid() like:

    m4_pattern_forbid([^_?PKG_[A-Z_]+$])

(Another option would be if you could go back in time and tell the pkg-info
people to name their macros according to an existing pattern of what's
already forbidden in output, e.g. `AC_PKG_CHECK_MODULES`.)

That would bring up an added error as the first hit which would be at least a
slightly more informative. Your result would look like:

    $ autoreconf
    configure.ac:33: error: possibly undefined macro: PKG_CHECK_MODULES
        If this token and others are legitimate, please use m4_pattern_allow.
        See the Autoconf documentation.
    configure.ac:34: error: possibly undefined macro: AC_MSG_ERROR
    configure.ac:143: error: possibly undefined macro: AC_DEFINE
    autoreconf: /usr/bin/autoconf failed with exit status: 1


This is still suboptimal, because it's not pinpointing the real culprit. What
we'd really like to do is exploit the m4 processor's inherent knowledge of
whether a macro is defined or not, so it could distinguish the "undefined"
case of PKG_CHECK_MODULES from the "passed by quote" cases of AC_MSG_ERROR
and AC_DEFINE.

But there's a problem: *by the time we execute autom4te, it's just a perl
script, and m4 is not running*. Perl can't take a token and retroactively
use the finished m4 session's [`ifdef()`][12] to test the `$prohibited`
cases for bona fide undefinedness.

[12]: https://www.gnu.org/software/m4/manual/m4-1.4.15/html_node/Ifdef.html

Given the fluidity of definitions in effect at any given time (with defines
and undefines spanning different ranges in a file), it seems this may motivate
making the forbidden outputs filtering a feature of m4 itself. Then it could
reliably tell you what the cause was.

But bringing the ambition level down a notch, I'll go back to what people were
saying about autoconf's messages being bad. We are programmers here, so why not
be honest?

    configure.ac:34: error: unexpanded AC_XXX macro: AC_MSG_ERROR
        A token that looks like an autoconf macro was residual in the output.
        It may be undefined -or- passed by quote to another macro that should
        have invoked it but isn't installed to do so. If this token and others
        are legitimate, please use m4_pattern_allow.
    configure.ac:143: error: unexpanded AC_XXX macro: AC_DEFINE
    autoreconf: /usr/bin/autoconf failed with exit status: 1

Error messages that report what they actually checked have a chance of making
people more educated. This would have been a great opportunity to bring all
the voodoo-fearers into the loop so they could be involved instead of afraid.

But the messages as written are now the gateway to finding the usual solution.
If that led you here, I hope this write-up gives you the knowledge to figure
out whether installing `pkg-config` is the right answer or not!  Look at the
generated output at the line where the first error occurs for anything that
looks like a macro that takes `[AC_WHATEVER_CAUSED_THE_ERROR(...)]`. If it
is `PKG_CHECK_MODULES()` then installing `pkg-config` is your ticket. But if
it's something else, you might need to look elsewhere.


## Acknowledgements

The only actionable information I found on the Internet to write this came
from the following thread on Stack Overflow:

[How to troubleshoot "Possibly undefined macro: AC_MSG_ERROR"][13]

[13]: https://stackoverflow.com/questions/48093804/how-to-troubleshoot-possibly-undefined-macro-ac-msg-error
