---
layout: post
title: "Modern C++11 Memory Management"
date: 2014-01-31 09:41
comments: true
categories: [c++,boost]
published: true
---

By using the correct smart pointer according to the desired semantics, you
can virtually eliminate leaks and other common memory problems.

Memory management in low level code has changed slowly over the years.  In
traditional C code, you would allocate memory with `malloc()` and release it
with `free()`.

<!--more-->

{% highlight c %}
char* buffer = malloc(BUFFER_SIZE);

fill_buffer(buffer, BUFFER_SIZE);
process_buffer(buffer, BUFFER_SIZE);

free(buffer);
{% endhighlight %}

Some of the problems with this approach were:

* `malloc()` might fail if the system is running low on memory, so you would
have to check for a `NULL` return and handle the error appropriately.
* you might forget to call `free()`, thus leaking memory. This is especially
common when there are multiple code paths, early returns and so on.
* the memory might be referred to *after* its release, causing subtle bugs
or crashes.
* sharing the memory between threads was error-prone and relied on complex
systems to avoid leaking or trashing memory.

The above code is also perfectly valid C++, albeit not exactly idiomatic.
Rather than rely on the C runtime, C++ introduced heap management into the
language itself, with the `new` and `delete` operators:

{% highlight c++ %}
Buffer* buffer = new Buffer(BUFFER_SIZE);

buffer->fill(0xaa);
buffer->process();

delete buffer;
{% endhighlight %}

This too is not without its issues:

* If the system is low on memory, `new` could fail and throw an exception
(the default behaviour). This would require a `try/catch` block to handle
the failure, otherwise the program would abort.
* `new` could also be configured to return `NULL`, requiring an entirely
different error handling strategy.
* It is generally inadvisable to mix memory allocated with `new` with memory
allocated using `malloc()` (as they could potentially be allocated in
different heap areanas, and cause corruption).

## Modern Memory Management

To drastically simplify memory management and reduce the potential for bugs,
C++11 introduces several types of *smart pointers*:

* `std::unique_ptr`: a pointer which is automatically freed when the pointer
goes out of scope, and has a single owner at all times
* `std::shared_ptr`: a reference-counting pointer which can be shared among
multiple threads, and deletes the object when the last reference is released
* `std::weak_ptr`: a handle which does not hold a reference, but can be
materialised into a `std::shared_ptr` on demand

These three smart pointer types should be able to cover the vast majority of
memory management needs in a typcail application.  (There will always be
exceptions which need custom allocation strategies, such as high performance
games, numerical processing, etc).

