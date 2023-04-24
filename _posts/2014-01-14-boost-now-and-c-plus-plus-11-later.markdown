---
layout: post
title: "Boost now and C++11 later"
date: 2014-01-14 20:16
comments: true
categories: [c++, c++11, stl, programming, boost]
published: false
---

The C++11 standard has been around for a few years now (with the first draft
published circa in 2009).  We are fortunate that both the `gcc` and `clang`
projects have implemented comprehensive support for the new language and
library features.  And both Visual Studio and the Intel compilers are
catching up fast.  So if you're using the current versions of these tools,
you can take advantage of all the new features right now.

<!--more-->

Unfortunately, some of the larger compiler vendors are still lagging in their
support for the new, shiny C++11 features.  A thorough [summary of major
compiler support](http://cpprocks.com/c11-compiler-support-shootout-visual-studio-gcc-clang-intel/)
shows GCC and Clang are way ahead of the Microsoft and Intel compilers.

Whether your project is constrained by toolchain support, 3rd party library
support, or it isn't currently feasible to upgrade your toolchain to C++11
support, there are ways to get many of the new features 'for free' right
now.

The [Boost project](http://www.boost.org/) provides a comprehensive set of
C++ libraries which provide many essential features and libraries, as well
as acting as an unofficial staging ground for many new C++ library features.
So (for example) most of the new goodness with `unique_ptr` and friends can
be had right now, simply by using Boost.

Modern C++ memory management
                              
| C++11        | Boost        |
|--------------|--------------|
| `unique_ptr` | `scoped_ptr` |
| `shared_ptr` | `shared_ptr` |
| `weak_ptr`   | `weak_ptr`   |

Modern C++
http://channel9.msdn.com/events/TechDays/Techdays-2014-the-Netherlands/Modernizing-Legacy-C-Code
- prefer enumerators for named constants
  - and prefer scoped enumerations where possible
    enum class Color { red, green, blue };
  which doesn't inject the enumerants' symbols into the global scope (avoids name clashing)
  - won't convert to underlying int type
  - use static_cast<> if required

- use inline functions rather than macros
 - avoid side-effects

- avoid heavily nested functions with lots of error handling
  - use RAII wherever possible
  - if you use std::vector<> it can throw on new failure, so beware
  - use unique_ptr<> with std::no_throw
 - RAII frees you from having to worry about resource management
 - functions that use RAII can return at any time
 - single-exit and goto-based cleanup should not be used any more
 - RAII is essential if using exceptions
 - single best way to improve C++ code quality

- const correctness
 - if you're not modifying it, declare it const (variables, methods, etc)
 - by default, declare things as const

- eliminate complexity introduced by the preprocessor
- refactor functions to linearise and shorten them
- update manual resource management to use RAII
- litter code with const qualifier
- convert C casts to C++ casts
- use algorithms (eg STL) instead of loops
- compile C as C++ to get more warnings
