---
layout: post
title: "What is Rust?"
date: 2013-10-08 20:50
comments: true
categories: [rust, software, languages]
---

[Rust](http://www.rust-lang.org/) is a compiled, hybrid imperative/object-
oriented/functional language. It appeals directly to any C++ developer who has
battled with memory management, and Python developers who long for faster code.
So why might you be interested in learning Rust?
<!--more-->
It's **compiled**, so it's fast. Rust uses [LLVM](http://www.llvm.org/) as the
compilation engine, and benefits from all its optimisation and native code
generation support that targets ARM and Intel processors.

Rust uses **type inference**, so you can write cleaner, simpler code while
retaining the benefits of strong static typing. It also supports **generic** and
**algebraic types**, which offers a far richer type system than C++.

There are no `NULL` pointers, thus rendering an entire class of bugs impossible.
This alone is worth a serious look, as the security and reliability implications
are huge.

Rust is a brace-oriented like C/C++, so many aspects of the syntax will be
immediately familiar to existing developers.

Memory ownership semantics are rich, strict and enforced. There are owned
pointers, shared pointers and _optional_ garbage-collection.

Rust has first-class **concurrency** support, featuring lightweight tasks
and message passing.

What does it look like? I would describe it as terse - or rather, minimalist.

{% highlight rust %}
fn main() {
    println!("Hello, world");
}
{% endhighlight %}

Ok, that's not very useful. How about a naïve Fibonacci function:

{% highlight rust %}
fn fib(n: uint) -> uint {
    match n {
        0..1    => 1,
        _       => fib(n-1) + fib(n-2)
    }
}
{% endhighlight %}

Yes, Rust has **pattern matching** just like Haskell. Forget about the simple
`switch` statement - `match` is super-powerful and flexible, supporting ranges,
options and destructuring fields from `struct`s.

What about some tasks:

{% highlight rust %}
fn test_tasks() {
    println("About to spawn...");

    do spawn {
        println("Hello from the first subtask!");
    }

    do spawn {
        println("Hello from another subtask!");
    }
}
{% endhighlight %}

Despite having spent years working in C++, I have often lamented its
shortcomings. Yet until recently, no other language seems to have come close to
competing with C++ as a systems language.

The [D programming language](http://dlang.org) looks very interesting, and aims
to provide a worthy alternative to C++.  However, last time I looked, there was
a schism over the runtime libraries which made adoption difficult. Uncertainty
about such a fundamental aspect is not reassuring for potential users.

The [Go programming language](http://www.go-lang.org/) from Google is fantastic,
and I have already used it on a number of small projects. The only shortcoming I
see here is the garbage collection, which makes real-time systems impractical.

Rust has great promise, and also has both Mozilla and Samsung backing its
progress. There is a vibrant, friendly and smart community behind it, and a
growing number of third-party libraries are supported. I am very optimistic
about the future of Rust, and look forward to contributing.
