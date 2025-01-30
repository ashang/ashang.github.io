---
title:  Possibly Undefined Macro
layout: post
---

    configure.ac:34: error: possibly undefined macro: AC_MSG_ERROR
        If this token and others are legitimate, please use m4_pattern_allow.
        See the Autoconf documentation.
    configure.ac:143: error: possibly undefined macro: AC_DEFINE
    autoreconf: /usr/bin/autoconf failed with exit status: 1

Last: install package **autoconf-archive**, which is an auxiliary set of macros
that aren't in the standard distribution.

## pkg-config

**sudo apt install pkg-config**

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

[13]: https://stackoverflow.com/questions/48093804/how-to-troubleshoot-possibly-undefined-macro-ac-msg-error
