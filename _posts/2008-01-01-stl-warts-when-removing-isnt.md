---
layout: post
title: "STL warts - when removing isn't"
date: 2008-01-01 17:33
comments: true
categories: 
---

Pop quiz: what does the `remove` function provided in the C++ STL algorithm package do?

{% highlight c++ %}
std::remove(list<T>::iterator begin, list<T>::iterator end, T& t);
{% endhighlight %}

Simple question, surely... Your answer?

If you said "it removes the value t from the list between the two iterators" then -- bzzzzt, thank you for playing.  It doesn't actually remove anything.  Quoting from the description:

    Reorders the range [first,last) to prepare for erasing all elements of equal value.

So the way to <i>actually</i> erase something from a `std::vector`:

{% highlight c++ %}
v.erase(remove(v.begin(), v.end(), item));
{% endhighlight %}

So all it does is shuffle the items to be deleted to the end, and return an iterator to them.  Then the `erase` method from the vector snips them off the end.

The above `erase/remove` line is a standard idiom for actually removing an item by value from a container.

This is one of several poorly named methods in the STL.  There are other design warts which I'll discuss in future articles.
