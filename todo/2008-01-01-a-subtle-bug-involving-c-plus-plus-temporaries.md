---
layout: post
title: "A subtle bug involving C++ temporaries"
date: 2008-01-01 17:26
comments: true
categories: 
---

I tracked down a subtle little bug the other day.  My code was crashing on a line that should never crash (and we've all heard that one before!).  It arose from doing two quite innocuous things, but when combined - disaster!  I decided to write it up as an example to my 3 readers and Google.

## The Setup

Say you have a Master-Detail relationship between two classes, whereby the master object has a 1:N relationship with the detail objects, and thus has a collection of them.  Let's say it's a vector of pointers (or even better, <a href="http://www.boost.org/">smart ones</a>!).

And as a convenience, the master class has a method which returns a copy of the list <i>by value</i>.  This is quite a reasonable thing to do, especially since the container holds references to the detail objects, and not actual instances.  So we have something like this:

{% highlight c++ %}
class Detail
{
    public:
        typedef std::vector<Detail*> List;
    // ...
};
class Master
{
  public:
    // ...
    Detail::List getAllDetailedObjects()
    {
        return _details;
    }
    // ...
  private:
    Detail::List _details;
};
{% endhighlight %}

So far, so good...

## The Bug

And say some chunk of code wants to do something with all those detail objects, so we might reasonably iterate over the list like so:

{% highlight c++ %}
// You probably don't actually want to do it this way...
Detail::List::iterator it;
for ( it = master.getAllDetailedObjects().begin();
      it != master.getAllDetailedObjects().end();
      ++it )
{
    Detail* d = *it;
    // do something useful with d
}
{% endhighlight %}

And of course, this code crashes, right around the dereferencing of the iterator.  Spotted the bug yet?  Take your time, I'll wait here...

Well, it's a pretty basic error when you know what it is, of course.  Each time `getAllDetailedObjects()` is being called, a temporary copy of the list is being returned.  So assigning the iterator it to the temporary list's `begin()` works just fine, except that the temporary list is then destroyed while the iterator is still pointing to its first element.  And so you get to the body of the loop, and you've got a bad pointer because the temporary list has been thrown away!

## The Solution

The obvious solution is to avoid temporaries and get only one copy of the list, thus:

{% highlight c++ %}
// The corrected version...
Detail::List details;
Detail::List::iterator it;
for ( it = details.begin();
      it != details.end();
      ++it )
{
    Detail* d = *it;
    // do something with d
}
{% endhighlight %}

This just goes to show how easy it is to be bitten by side-effects and temporaries in C++.  The compiler provides no help or warning, and there's no proper C++ version of lint that I know of.  This is the sort of thing you just have to pick apart, review all assumptions ("the list is valid <b>here</b>!") and beware any time you get a result by value.

## Boost to the rescue! (again)

The <a href="http://www.boost.org/doc/html/foreach.html">Boost foreach</a> module provides some syntactic sugar to replace all the boilerplate code in iterator loops.  

So instead of having to write:

{% highlight c++ %}
container_type::iterator it;
for ( it = container.begin(); it != container.end(); ++it )
{
    inner_type val = *it;
    // do something interesting with val
}
{% endhighlight %}

you can avoid all the boilerplate code and simply write:

{% highlight c++ %}
foreach ( inner_type val, container )
{
    // do something interesting with val
}
{% endhighlight %}

which is more concise, readable and less typing (or typo-ing!).

And interestingly, it ensures the collection term is evaluated only once, which means it would be safe to iterate over an expression that returns a sequence by value (example from the docs):

{% highlight c++ %}
extern std::vector<float> get_vector_float();
foreach( float f, get_vector_float() )
{
  // safe: the collection will only be retrieved once
}
{% endhighlight %}

So using the Boost foreach module would have actually avoided the above bug.  Though it wouldn't be nearly as satisfying, as I wouldn't have been able to blog about it.
