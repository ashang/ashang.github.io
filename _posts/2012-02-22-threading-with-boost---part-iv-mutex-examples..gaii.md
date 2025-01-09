---
layout: post
title: "Threading with Boost - Part IV: Mutex Examples"
comments: true
category: Boost
tags: [Boost, C++, Threading]
published: true
---

This article continues the series on threading with Boost, by looking in
depth at several sample programs which illustrate different aspects of
mutexes.  We look at the code, and discuss how it is implemented, including
how to avoid common problems.

<!--more-->

Mutex Examples
==============

The full source for the sample applications is provided below.  It is
designed to be fully portable, and has been tested on Mac OS X and Linux.
It should work fine on Windows (please send a patch if it doesn't!).

You can browse all the sources in the [Boost Samples repository](http://bitbucket.org/gavinb/boost_samples)
for the latest, or use [Mercurial](http://www.selenic.com/mercurial/)
to clone your own copy with this shell command:

    hg clone http://hg.antonym.org/src/boost_mutex

Running `bjam` or `make` will build all the examples for you, which you can
run from the appropriate subdirectory (depending on your toolchain and
architecture).

Duelling Threads
================

Source module: [`duel.cpp`](http://bitbucket.org/gavinb/boost_samples/src/tip/mutexes/duel.cpp)

This example shows how threads are sensitive to timing and scheduling.
There is a global counter which starts at 0.  Two threads are created which
both try to modify the same counter; one incrementing and the other
decrementing.  The program runs for a fixed time, then the counter is
printed.

What would you expect to happen?  (It is worth thinking about this before
reading on...!)  Assuming the threads get equal time to run, you would think
that their effects would cancel each other out - that the same number of
increments and decrements would occur, and the result would be 0, or at
least very close to 0. Right?

Here's the result of running the test 10 times for 5 seconds each:

    Final counter = -1
    Final counter = -3
    Final counter = 1
    Final counter = -1
    Final counter = 0
    Final counter = 3
    Final counter = -57
    Final counter = -8
    Final counter = 7
    Final counter = -5

Often the result is quite close to zero, but there are several runs which
are significantly above or below 0. And there's one huge outlier where one
of the counter threads (quiz: which one?) was starved of some time while the
other kept working (answer: the incrementing thread, since the counter is
negative, indicating that the decrementing thread was scheduled for longer).

So even on a machine with very few other processes running, even small
variations in timing and scheduling can lead to a significant variation in
the result.

The moral of this story: *the interaction between threads is time-sensitive
and non-deterministic* (in the absence of synchronisation).

Trylock with Queueing Threads
=============================

Source module: [`trylock.cpp`](http://bitbucket.org/gavinb/boost_samples/src/tip/mutexes/trylock.cpp)

This sample illustrates two cooperating threads: a *producer* which places
work items in a queue, and a *consumer* which removes work items from the
queue.  The shared queue is protected by a mutex.

Each thread locks the mutex when pushing or pulling work items, to protect
against concurrent access.  Work items are arbitrarily represented by random
numbers.  Each thread holds the lock for a random time delay to simulate
processing.

Since the producer may be holding the lock when the consumer wants to access
the queue (or vice versa), the consumer performs a `try_lock` on the mutex.
So instead of blocking until the mutex is free (as a regular call to
`lock()` would), the call fails immediately if the mutex is already locked,
and the thread resumes.  This contention is reported separately, as it is
important to be able to see how often the threads collide.

Each thread prints out the stage it is executing, to enable analysis of the
interaction.

Note that this technique is **not** a good model for real world use - it is
specifically designed to illustrate one aspect of using mutexes.  For a much
better implementation of the Producer-Consumer pattern, see the article on
Boost Condition variables later in this series.

Takehome message: *thread contention for shared resources wastes processor
cycles and can erase performance improvements gained from concurrent code*.

Mutex Locking with Timeout
==========================

Source module: [`timedlock.cpp`](http://bitbucket.org/gavinb/boost_samples/src/tip/mutexes/timedlock.cpp)

Shows how to use `try_lock` on a mutex.  A 'holding' thread idles for a
short time, then grabs the mutex and holds it for another short time before
unlocking it.  The second thread is the 'trying' thread, in that it idles
and then *tries* to acquire a lock on the mutex.  But it specifies a timeout
by calling the `timed_lock()` method, and can fail if the holding thread
hasn't released the mutex in time.  If it manages to grab the mutex, it
holds it for a short time also.  The idle and holding times are different,
to ensure the threads don't run in lockstep.  Note that `unlock()` is only
called if the lock succeeds!

Recommended Usage: *Use a timeout when trying to lock a mutex if you can
easily do some other useful work, or if you cannot guarantee you can acquire
the resource within a reasonable timeframe.*

Recursive Lock
==============

Source module: [`reclock.cpp`](http://bitbucket.org/gavinb/boost_samples/src/tip/mutexes/reclock.cpp)

Illustrates recursively locking a mutex.  A singleton class,
ResourceManager, can register and unregister clients.  Since this may be
called from the context of any worker thread, it uses a mutex when accessing
the dictionary of client information.  Since retain/release management also
requires the mutex be held during updates, this serves as an illustration of
recursive locking.  These methods can be called individually, or from within
the register/unregister methods, which also hold the mutex.  For example:

    registerClient()                  lockCount = 0
        mMutex.lock()                 lockCount = 1
        retainClient()                lockCount = 1
            mMutex.lock()             lockCount = 2
            mMutex.unlock()           lockCount = 1
        mMutex.unlock()               lockCount = 0

Note: *Recursive mutexes should be used rarely, if at all. If you think you
need a recursive mutex, it may be a sign that you have a structural problem
with the code and you should reconsider the design.*

Fun fact: *The person who implemented recursive mutexes in `pthreads` did it
as a bit of a joke, just to prove it was possible - not really intending for
them to be used in real programs.*

Deadlock
========

Source module: [`deadlock.cpp`](http://bitbucket.org/gavinb/boost_samples/src/tip/mutexes/deadlock.cpp)

Imagine you have multiple co-operating threads as well as multiple shared
resources.  Each shared resource is dutifully protected by its own mutex.
So provided each thread locks the mutex before accessing the resource,
everything should run smoothly, right? What could possibly go wrong?

A [**deadlock**](http://en.wikipedia.org/wiki/Deadlock) is what could go
wrong, and appears as if the program has simply hung.  It's relatively easy
for these situations to occur, but it is also relatively easy to prevent
deadlocks with some care and thought.

A deadlock occurs when thread one is holding lock A while waiting for lock
B, which itself is held by thread two which is waiting for lock A.  In other
words, the two threads are both waiting for each other to do something that
can never happen.  An *impasse*!

Now this example is *intentionally* written to fall into a deadlock.  So
whatever you do, don't copy the code from this example into your own code.
Study it and make sure you understand *why* it is wrong.

In the source, thread one wants to lock both mutex A and mutex B, and it
does so in that order.  It will then perform some processing, and unlock the
two mutexes.  Thread two is similar, in that it wants to lock mutex A and
mutex B before it can safely do its work.  However, the poor programmer who
wrote this code hadn't had their second cup of coffee that morning, and
wrote the code such that it first locks mutex B, *then* mutex A.  No big
deal, right?

The program prints information about its progress, including which thread is
in what state, such as processing, waiting for a lock, and so on.  This
makes it easier for us to analyse what is going on.  (When debugging
multithreaded code, `printf` is your friend!)

Each thread holds both locks while they work, which can take a random length
of time.  This setup can work ok for a little while, provided the timing is
just right.  This can be seen in the trace below, which shows the normal
output of the program:

    ONE idle
    TWO idle
    ONE wait_A
    ONE wait_B
    ONE processing
    TWO wait_B
    ONE unlock_B
    ONE unlock_A
    ONE idle
    TWO wait_A
    TWO processing
    TWO unlock_A
    TWO unlock_B
    TWO idle
    TWO wait_B
    TWO wait_A
    TWO processing
    ONE wait_A
    TWO unlock_A
    TWO unlock_B
    TWO idle
    ONE wait_B
    ONE processing
    ONE unlock_B
    ONE unlock_A
    ONE idle
    TWO wait_B
    TWO wait_A
    TWO processing
    TWO unlock_A
    TWO unlock_B
    TWO idle
    TWO wait_B
    TWO wait_A
    TWO processing
    TWO unlock_A
    TWO unlock_B
    TWO idle
    ...

but before long at all, the program will invariably hang.  At this point,
you will have to use `Control-C` (or your platform's equivalent) to kill the
program.  And if you run it a few times, you will notice the same two
patterns always appearing at the end of the trace; either:

    ...
    ONE wait_A
    TWO wait_B
    ONE wait_B
    TWO wait_A

or:

    ...
    TWO wait_B
    ONE wait_A
    TWO wait_A
    ONE wait_B

Reflecting back to the trace when everything seemed to be working, we see
that the threads ran smoothly when they managed to lock both locks at once.
But notice how these telltale signs, these skidmarks leading up to the
moment of the crash, show thread one and two locking are always
*interleaved* when they acquire these locks?

In the first example, thread one acquires mutex A, and before it can lock
mutex B, thread two is scheduled, and comes along and locks mutex B. Then
thread one tries to acquire mutex B and blocks since it is already locked by
thread two, waiting forever, being a patient worker thread.  At this point,
thread two can run again, and tries to acquire mutex A.  Unfortunately, this
lock is held by thread one which is not coming back until it gets mutex B -
which will never happen.  Because thread two is now blocked forever, waiting
on mutex A.  Your only consolation is that they probably won't consume any
CPU cycles while they remain in this deadlock.  But the program certainly
isn't going anywhere!

So how can this be avoided?  Fortunately, the fix is simple - always acquire
the mutexes in the same order, and (ideally) release them in the reverse
order.  This fix is an exercise left for the reader, but verify for yourself
that the program will run as long as you like once the locks are acquired in
the same order.

Why does this work?  Because it prevents the possibility of holding a
contested mutex while blocking on another.

Remember: *Always acquire multiple mutexes in the same order to avoid
deadlocks.*

Exclusive Shared Mutex with Access Semantics
============================================

Source module: [`sharedlock.cpp`](http://bitbucket.org/gavinb/boost_samples/src/tip/mutexes/sharedlock.cpp)

This example shows how three worker threads can co-operate accessing a
shared resource, where two are reading and the third is writing.  It is
frequently important to manage access in this way, and can drastically
improve performance by increasing concurrency.

If a thread is only reading from a shared resource, it does not require
exclusive access.  Thus many threads can safely obtain read-only access to a
resource.  It is only if a thread needs to write to the resource to update
it that it will need exclusive access, to ensure the data is updated
atomically (as seen by any worker threads) and remain consistent.

Thus by granting multiple threads concurrent read access, concurrency is
increased in proportion to the number of read-only threads.  The only
disadvantage is that any thread wishing to modify the shared resource
(ie. use an exclusive lock) must wait until *all* reading threads have
finished.  This provides a good incentive to have the scope of the locks as
short as possible, to reduce the time a writing thread would need to wait
for exclusive access.

In this example, A network thread simulates producing data by ading random
numbers to a container.  A display thread shows the data on screen, and a
database thread writes the numbers to a file.  The network thread uses an
exclusive write lock to update the shared data container, while the other
two threads use a shared read-only lock, which means they can both
concurrently access the data safely.  If the network thread tries to access
the data while either of the other two have a read-lock, it has to wait
until all threads release their shared locks.

(Normally a producer-consumer setup such as this would use a Condition
variable to signal when more data is ready, but we're saving that for a
future installment.)
