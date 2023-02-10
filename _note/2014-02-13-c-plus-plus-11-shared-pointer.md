---
layout: post
title: "C++11 Smart Pointers: Shared Pointer"
date: 2014-02-13 18:45
comments: true
categories: [c++, c++11, memory, smart pointers]
published: true
---

In the last article on smart pointers, we looked at `std::unique_ptr`, which
provides a simple and safe smart pointer to wrap heap allocations.  As the name
implies, this smart pointer type cannot be shared between multiple threads.

So then how can you ensure that the memory is freed once all referring threads
have finished with the resource?  This is especially difficult when the thread
lifecycle is non-deterministic.

<!--more-->

The solution to sharing heap-allocated memory between threads is the
`std::shared_ptr`. While it does **not** address race conditions (see mutexes et
al), it does solve the problem of managing the lifecycle of a shared resource
between multiple threads.

## Reference Counting

The `shared_ptr` implementation uses reference counting to keep track of how
many references to the object exist. Each time the smart pointer is replicated,
the reference count is increased. Each time a smart pointer goes out of scope,
the reference count is decreased. Once the final reference is gone (ie. the
reference count reaches zero), the object is deleted (and the destructor
called).

## Example

Imagine we have a worker thread function which needs to use a shared resource.
We can pass the worker thread a shared pointer:

{% highlight c++ %}
void worker(std::shared_ptr<Foo>& obj)
{
    printf("tid %p worker: running, obj %p use_count %ld\n",
        std::this_thread::get_id(),
        obj.get(),
        obj.use_count());

    // Do something useful with obj
    obj->process();
}
{% endhighlight %}

We can use the object in as many threads as we need, and they can all terminate
at an arbitrary time. The object will stay alive until the last thread has
finished, and releases its reference.

In this example, the `main()` function creates an instance, then passes the
smart pointer to several worker threads:

{% highlight c++ %}
std::shared_ptr<Foo> obj(new Foo);

std::thread w1(std::bind(worker, obj));
std::thread w2(std::bind(worker, obj));

w1.join();
w2.join();
{% endhighlight %}

Note the use of `std::bind` to pass the `obj` pointer as a reference parameter
to the thread function;  normally thread function parameters are passed by
value.

The output will resemble something like:

    +++ main()
    +++ Foo::Foo()
    main:   spawning, obj use_count 1
    main:   joining,  obj use_count 3
    worker: running,  obj use_count 3
    worker: running,  obj use_count 2
    main:   leaving,  obj use_count 1
    --- main()
    --- Foo::~Foo()

We clearly see the lifecycle of the `Foo` instance.  In `main`, it is created
and thus the `use_count` is 1 (before the threads are spawned).  Then two
threads are spawned, increasing the `use_count` to 3, which remains while the
threads are running. Main joins (or waits) to block on each thread terminating,
so once `main` continues, both threads have completed, thus the `use_count` is
back down to 1. Finally, the smart pointer goes out of scope at the end of main,
and is destroyed after main completes.

The new `std::shared_ptr` support makes it easy to share heap-allocated memory
between threads, or throughout code that has complex lifetime requirements.
