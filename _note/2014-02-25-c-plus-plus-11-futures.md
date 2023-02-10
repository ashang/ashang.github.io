---
layout: post
title: "C++11 Futures"
date: 2014-02-25 08:44
comments: true
categories: [c++, c++11, threads, asynchronous, async, multithreading, futures]
published: true
---

Concurrency is one of the most significant challenges facing software
development today.  As the gains in processor performance diminish year over
year, additional cores have become the norm.  For some years now, multicore
processors have become the norm.

Taking advantage of multiple cores has usually required writing multithreaded
code, which can be complex to design and debug.  One of my favourite new
features in the C++11 standard library is the `future` module.  This provides
an extra layer of abstraction over threads, providing a simple mechanism
for asynchronous (ie. concurrent) processing.

## What is a 'future'?

A `std::future` is an object that represents the future return value of a
function; it is the result of a computation which you need but do not yet have.
A `std::future` object also represents the current processing state of this
computation; whether or not it has completed, for example.

An asynchronous task (which is generally created on its own thread) makes a
*promise* that it will process a result at some time in the *future* and
eventually return this result to the caller.

## When are futures useful?

If your application needs to perform a non-trivial computation which could take
quite some time to complete, it is frequently preferrable to perform this
computation asynchronously; that is, in another thread, so the calling or main
function can continue processing, perform other tasks, remain responsive to the
user, and so on.

Futures can also be very useful when there are multiple computations to perform,
and it is not known which will complete first.  They can all be initiated at the
same time, and the results picked up as each finishes.

## How do I perform an async call?

Imagine we have a boring function which will take an undetermined but long time
to complete:

{% highlight c++ %}
unsigned boring()
{
    // Consume many CPU cycles...
    // ...then eventually...
    return boring_result;
}
{% endhighlight %}

Rather than calling this function directly and waiting for its result, we can
invoke it asynchronously:

{% highlight c++ %}
std::future<unsigned> ans = std::async(boring);
{% endhighlight %}

What is returned *immediately* is a `future` object or token (templated over the
return type of the function we are calling), which allows us to query the status
of the computation, and (once complete) retrieve the result of the `boring()`
function.

Processing in the calling thread (in this case, `main`) continues, as the
`boring` function is spun off into its own thread (an implementation detail) to
be scheduled independently.  In this way, we can continue to perform other
processing while this boring work is being done in the background.

To retrieve the answer, we simply call `get()` on the `future` object when we
need to access the result:

{% highlight c++ %}
unsigned result = ans.get();
{% endhighlight %}

This will block until the result of the `future` is ready, and then return
the value from `boring()`.

To avoid blocking on the result, you can use the `wait_for()` or `wait_until()`
methods to check on the status of the `future`.

## How do I monitor the future's status?

While the calling process is performing other work, it might be useful to check
if the asynchronous processing has completed yet.  We can either wait for
a certain time to elapse (`wait_for()`) or wait until a clock time is reached
(`wait_until()`).  This fragment shows how you can wait 5ms for a result,
retrieving it if available, and continuing if not:

{% highlight c++ %}
std::chrono::milliseconds wait_time_ms(5);

std::future_status status = ans.wait_for(wait_time_ms);

if (status == std::future_status::ready)
{
    unsigned result = ans.get();
}
{% endhighlight %}

A more complete example shows monitoring the status of multiple `async` calls,
displaying the result as each finishes is available in the
[C++11 async sample code](https://github.com/gavinb/cplusplus11/tree/master/future/)
on Github.
