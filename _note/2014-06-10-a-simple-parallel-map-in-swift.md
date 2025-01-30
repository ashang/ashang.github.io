---
layout: post
title: "A simple parallel map in Swift"
date: 2014-06-10
comments: true
categories: swift,mac,ios,concurrency
publish: false
---

One of the most interesting features of Swift is its support for closures;
functions as first-class objects.  When combined with containers, closures
provide a natural and efficent way of iterating over arrays, transforming
data and accumulating results.

The built-in `map` function takes a closure (or function) and applies it to
each element in a container, producing another container with the results.
The `map` function declaration in its most abstract form looks something
like:

    func map<S, E, T>(source: S, transform: (E) -> T) -> Map<S, T>

which can be read as: "`map` takes a `source` of elements and applies a
transform function to each one, giving a map of original elements to their
transformed result".

There are actually several flavours of `map` in Swift's runtime, depending
on just which collection type you are working with.  Containers such as
`Array` has a `map` method of their own, and there are also standalone
functions which can apply to any container at all that implements either the
`Sequence` or `Collection` protocols:

```
func map<S : Sequence, T>(source: S, transform: (S.GeneratorType.Element) -> T) -> MapSequenceView<S, T>

func map<C : Collection, T>(source: C, transform: (C.GeneratorType.Element) -> T) -> MapCollectionView<C, T>
```

Now Swift has all the Mac and iOS frameworks at its disposal, which means it
can use Grand Central Dispatch (GCD) for concurrent programming support.  So
wouldn't it be nice if we could use GCD to implement a concurrent version of
`map`?  We could call it `pmap`, and it would apply a transform to each
element in the container, but use GCD to process each item on a dispatch
queue to take advantage of multiple cores.

First we need to set up a dispatch queue and dispatch group.  The queue is
where we send the tasks to perform, while the group lets us treat all tasks
on that queue as one and wait for all of them to complete at the end.  This
way the queue can be the concurrent (rather than serial) type and the system
can use multiple threads to process work as quickly as possible.

```
    let attrs = DISPATCH_QUEUE_CONCURRENT
    let work_queue = dispatch_queue_create(name.bridgeToObjectiveC().UTF8String, attrs)
    let work_group = dispatch_group_create()
```

With the queue set up, we simply go through all the work items and submit
them to the queue.  A closure is used to apply the transform to the item and
save its result in the results container:

```
    for (i, item) in enumerate(source) {
        dispatch_group_async(work_group, work_queue) {
            objc_sync_enter(results)
            results.append(transform(item))
            objc_sync_exit(results)
        }
    }
```

Once we have submitted all these tasks to be processed, we sit back and wait
for them all to complete:

```
    dispatch_group_wait(work_group, DISPATCH_TIME_FOREVER)
```

By this point, all jobs submitted to this group have completed and we can
return the results container to the caller.

The beauty of this `pmap` construct is that it can be called as if it were
sequential code, but under the covers, it is concurrent.