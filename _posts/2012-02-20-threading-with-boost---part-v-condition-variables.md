---
layout: post
title: "Threading with Boost - Part V: Condition Variables"
comments: true
category: Boost
tags: [Boost, C++, Threading]
published: true
---

In multithreaded programs, mutexes are used as a lock to protect shared
resources and enforce atomic operations.  This is useful to manage
concurrent access, but what about when one thread needs to asynchronously
signal to another thread that an event has occured or a condition is true?

<!--more-->

One possible solution would be to continuously poll a variable to detect a
change in state.  This is incredibly inefficient (not to mention
error-prone) since the vast majority of the CPU time scheduled will be
wasted simply checking the state and not performing any useful work.
Polling for state changes is almost always a bad idea!

So then, one might be then tempted to introduce a delay in the polling loop,
to reduce wasted cycles. The problem then becomes how long to sleep in
between polling?  Too short, and CPU cycles will still be wasted.  Too long,
and the program becomes unresponsive. Clearly this is not an ideal solution
either.

# What is a condition?

The preferred solution is a *condition variable*, which acts like a flag or
signal that can be used to safely and efficiently notify one or more other
threads asynchronously that a condition is true.

The code which manages the state creates the condition variable and updates
it, using the condition to *notify* others of the change in state.  The code
which is interested in monitoring the state can *wait* (a blocking call) on
the condition (which means it needs to be in a separate thread) where it
will consume no cycles until the condition is raised.

# When to use conditions

A condition variable is most often used to signal between threads, to
indicate a state change has occured, data is ready, a job has been complete,
a new job is ready to process, and so on.  The actual meaning is
context-dependent, but typically represents a binary state.  Use a
*condition variable* when you need to asynchronously notify other threads of
an event or condition.

# Example: Producer/Consumer

The classic condition example is the producer/consumer model.  One (or more)
thread produces data, and one or more threads consume the data.  The data
are typically stored in a shared queue (which itself doesn't need to be
thread-safe, as atomic access is enforced by the mutex and condition
constructs).

In our trivial example, a producer generates numbers and adds them to a
queue for processing.  A consumer takes numbers off the queue and prints
them out.  The consumer will *wait* on the condition until work is
available, and the producer will only *notify* consumers when data is
available to process.

# Implementation details

There are two important details relating to how condition variables are
implemented (both in POSIX `pthreads` in Linux and Mac, and in Win32, which
covers most systems these days) that affect their use:

1. A condition variable must be protected by a mutex, and
2. A condition variable needs an actual variable to be used as a flag

This can be confusing at first, but a condition variable itself needs to be
protected by a mutex.  This is not because a condition variable isn't
atomic, but rather to avoid data race when multiple threads waiting on the
one condition wake up.

Also, there is a very rare sitaution known as
[spurious wakeup](http://en.wikipedia.org/wiki/Spurious_wakeup),
which is where a thread is awoken from waiting on a condition variable *even
when nothing has called `notify()`*.  The full details are arcane, but
essentially condition variables are unpredictable on some multiprocessor
systems (the norm these days) to optimize overall responsiveness.  There
would be a significant performance penalty for making the behaviour
perfectly predictable.

So to mitigate against a spurious wakeup, you use *another* variable to
represent the actual state (atomially updated!) and check that variable in a
loop.

In light of the above, a condition variable can be seen as an indication
that something *probably* happened, and you should really check for it
yourself to be certain. :)

# Declaring a Condition variable

Creating a condition varaible is as simple as declaring one, though here we
show the complete set: condition variable, its mutex and the actual state
variable:

{% highlight c++ %}
#include <boost/thread.hpp>

// ...

boost::condition_variable   data_ready_cond;
boost::mutex                data_ready_mutex;
bool                        data_ready = false;
{% endhighlight %}

To raise a condition, the code controlling the state can notify other
threads by either notifying waiting *all* threads, or just *one* waiting
thread.  In the case of notifying *one* waiting thread, which one gets
notified is indeterminate. Here we see how to notify *all* waiting threads:

{% highlight c++ %}
boost::unique_lock<boost::mutex> lock(data_ready_mutex);

data_ready = true;
data_ready_cond.notify_all();
{% endhighlight %}

Threads interested in being notified of the state change must use a loop
to wait for the condition variable:

{% highlight c++ %}
boost::unique_lock<boost::mutex> lock(data_ready_mutex);
while (!data_ready)
{
    data_ready_cond.wait(lock);
}
{% endhighlight %}

The *lock* is used to prevent data races when multiple threads awaken (see
above), and is passed to the `wait()` method where the condition actually
releases the mutex (so multiplt threads can wait).  When a thread is awoken,
the mutex is reacquired, and the data can safely be accessed.

The *loop* which tests for the *actual* state change solves the *spurious
wakeup* problem, as even if the thread awakes, if the data is not ready, it
will simply go back to waiting.

# Sample run

The [`many_wait.cpp` variable sample code](http://bitbucket.org/gavinb/boost_samples/src/tip/condition/many_wait.cpp)
shows this in action.  Trace of a sample run is shown below, in which four
slave threads are spawned, all waiting on the master to signal the
condition. The master starts up, waits for a short while pretending to work,
and then calls `notify_all()`. At this point, all the slaves wake up and
terminate.

{% highlight bash %}
Spawning threads...
+++ slave thread: 1
+++ slave thread: 4
Waiting for threads to complete...
+++ slave thread: 3
+++ slave thread: 2
+++ master thread
    master sleeping...
    master notifying...
--- master thread
--- slave thread: 4
--- slave thread: 1
--- slave thread: 2
--- slave thread: 3
Done
{% endhighlight %}
