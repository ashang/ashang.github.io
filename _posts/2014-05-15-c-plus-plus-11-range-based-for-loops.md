---
layout: post
title: "C++11 Range-based for loops"
date: 2014-02-25 08:44
comments: true
categories: [c++, c++11, for, range]
published: true
---

The humble `for` loop is one of the oldest control flow control constructs
in the Algol family of languages.  Yet while other languages have extended
their syntax to allow `for` loops to do all sorts of crazy and useful things
beyond iterate over a range of numbers, C and C++ have remained steadfast -
until now.

The `for` loop finally has a new syntax to better support iterators and
ranges, just two great new features in C++11.  So you can now easily iterate
over much more than just numbers.

<!--more-->

The C++ container classes in the Standard Template Library (STL) provide
iterators, but the familiar looping syntax is the rather unwieldly pattern:

{% highlight c++ %}
#include <vector>

std::vector<int> vec;
// ...
std::vector<int>::iter it;
for (it = vec.begin(); it != vec.end(); ++it)
{
    int& n = *it;
    total += n;
}
{% endhighlight %}

For some time, the [Boost++ project](http://www.boost.org/) has provided
some syntactic sugar to reduce the complexity of this code considerably.  By
using the [Boost `foreach`](http://www.boost.org/libs/foreach/) library, you
can replace the above loop with the much simpler:

{% highlight c++ %}
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

std::vector<int> vec;
// ...
foreach (int& num, vec)
{
    total += n;
}
{% endhighlight %}

But now the C++11 specification finally has this style of syntax built in to
the language (with a slight change of punctuation; it uses `:` rather than
`,`). So now you can write:

{% highlight c++ %}
#include <vector>

std::vector<int> vec;
// ...
for (auto n : vec)
{
    total += n;
}
{% endhighlight %}

This is obviously much cleaner and clearer than the explicit iterator-based
code shown above.  If all you need to do is iterate over an STL container,
you can start using this syntax straight away.

(Aside: if you are actually going to sum the contents of a vector as in this
example, using the `reduce` algorithm is even better.)

## The new `for` loop in detail

So how does this new [range-based `for`](http://en.cppreference.com/w/cpp/language/range-for)
loop actually work?  Well, given the simple expression:

{% highlight c++ %}
for ( range_declaration : range_expression ) loop_statement
{% endhighlight %}

this loop is equivalent to the following expanded code:

{% highlight c++ %}
{
    auto && __range = range_expression;
    for (auto __begin = __range.begin(),
        __end = __range.end();
        __begin != __end; ++__begin)
    {
        range_declaration = *__begin;
        loop_statement
    }
}
{% endhighlight %}

Stepping through line by line, we see that the `for` loop lives inside its
own block. First, `__range` is evaluated to determine the sequence over
which to iterate.  Then (as in the traditional container case) the `_begin`
and `__end` variables are used to control the loop, incrementing `__begin`
until it reaches `__end` (which is one past the last entry).  The loop body
dereferences the iterator to get the item value at the current position, and
then the code in `loop_statement` is executed.

This construct also works naturally with plain arrays, where the bound is
added to the beginning to determine the range.

Finally, this works with the new `begin()/end()` range functions in the
C++11 standard library, described next.

## Ranges

Iterators defined by containers in the STL have `begin()` and `end()`
methods to control iteration loops.  New in C++11 are `begin()` and `end()`
*functions* (in the `std` namespace), which can be used to work with ranges.
So what is a range?  Essentially a `begin()/end()` pair which define the
extents of an iteration over a container.  By making `begin()/end()` common
functions, generic algorithms can more easily work with user-defined
containers that live outside the STL.

The simple form of their declarations are as follows:

{% highlight c++ %}
template< class C > 
auto begin( C& c ) -> decltype(c.begin());

template< class C > 
auto end( C& c ) -> decltype(c.end());
{% endhighlight %}

This uses some new C++11 features to basically say that, for whatever type
you pass to these functions, they will return you something of the same type
as the `begin()` or `end()` methods they define within the class.  This
works with C style arrays, initialiser lists, STL containers and any
user-defined types.  In short, it is a much more flexible form of the
original STL pattern.

## Custom classes and ranges

To add range support to your own class, you must provide the following support:

* `begin()` and `end()`, either as methods or overloaded functions, that
  return the appropriate iterators

and then you need an iterator class with the following features:

* dereferencing to access the current item (`operator*`)
* inequality to compare iterators (`operator!=`)
* pre-increment to advance the iterator to the next item (`operator++`)

Given a container class, you could define your iterator class something like
this, for example:

{% highlight c++ %}
class MyIterator
{
public:

    MyIterator(const MyContainer& c, unsigned idx = 0)
            : m_container(c),
              m_index(idx)
    {}

    // Required
    bool operator!=(const MyIterator& other)
    {
        return (m_index != other.m_index);
    }

    // Required
    const MyIterator& operator++()
    {
        m_index++;
        return *this;
    }

    // Required
    MyObject& operator*() const;

private:
    const MyContainer&      m_container;
    unsigned                m_index;
};

MyObject& MyIterator::operator*() const
{
    return m_container.get(m_index);
}
{% endhighlight %}

Its responsibilities are primarily to keep a reference to its container
proper, and maintain the index of the current item.  The methods marked
`required` are the minimum interface to participate in the range-based `for`
loop support.  The implementation is very straightforward.

The container class must provide methods to generate iterator classes;
something like this:

{% highlight c++ %}
class MyContainer
{
public:
    MyContainer(unsigned capacity);
    //...

    // Required
    MyIterator begin () const
    {
        return MyIterator(*this, 0);
    }

    // Required
    MyIterator end () const
    {
        return MyIterator(*this, m_currentIndex);
    }

    //...
};
{% endhighlight %}

This allows your own custom classes to be used in a very natural way with
the new `for` loop, such as this example:

{% highlight c++ %}
MyContainer     cont(10);

cont.add(MyObject(9, "IX"));
cont.add(MyObject(56, "LVI"));
cont.add(MyObject(43, "XLIII"));
cont.add(MyObject(1984, "MCMXXCIV"));

for ( auto obj : cont)
{
    std::cout << obj.number() << ": " << obj.description() << std::endl;
}
{% endhighlight %}

The full source to the examples is available in my [Github C++11 samples](https://github.com/gavinb/cplusplus11/tree/master/rangefor/).
