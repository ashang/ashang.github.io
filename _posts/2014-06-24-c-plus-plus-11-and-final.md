---
layout: post
title: "C++11 and final"
date: 2014-06-24 17:50
comments: true
categories: [c++,c++11]
---

One of the lesser known - but still very useful - enhancements to C++11 is
the addition of the `final` keyword.  This essentially mirrors the `final`
feature in Java, which has existed since its inception.

<!--more-->

The `final` keyword in C++11 can be applied to either an entire class or a
method.  When applied to a class, it signifies that the class is *closed to
derivation*; that is, you cannot create a class derived from a `final`
class.

The second way is when applying `final` to a method, which prevents the
method from being overridden by a derived class (though it is still possible
to create subclasses).

# How do you declare a `final` class?

Given a base class and a derived class, you would normally write:

{% highlight c++ %}
class Base0
{
};

class Derived0 : Base0
{
};
{% endhighlight %}

However, if you wish to prevent the base class from being subclassed, simply
add `final` after the classname, thus:

{% highlight c++ %}
class Base1 final
{
};

// Error!
class Derived1 : Base1
{
};
{% endhighlight %}

If you try to compile this code, you will get the error:

{% highlight bash %}
finalclass.cpp:16:18: error: base 'Base1' is marked 'final'
class Derived1 : Base1
                 ^
finalclass.cpp:12:7: note: 'Base1' declared here
class Base1 final
      ^
1 error generated.
{% endhighlight %}

The compiler specifically prevents any subclassing of `Base1` with a hard
error.

# How do you declare a `final` method?

It is also possible to mark an indvidual method as `final`.  The method must
be `virtual` to begin with, and making it `final` prevents it from being
overriden in a derived class.

(If the method isn't virtual, you would be effectively creating a shadow
method that overrides the base method.)

Take the following simple example of a derived class overriding a virtual
function declared in the base:

{% highlight c++ %}
class Base0
{
    virtual void foo();
};

class Derived0 : Base0
{
    void foo();
};
{% endhighlight %}

This compiles and works just fine.  But if we wanted to ensure that the
method was not reimplmented in any derived classes (For example, to preserve
important behaviour), simply adding the `final` modifier at the end of the
method declaration.  So given the following example:

{% highlight c++ %}
class Base1
{
    virtual void foo() final;
};

class Derived1 : Base1
{
    // Error!
    void foo();
};
{% endhighlight %}

the compiler gives us the following error:

{% highlight bash %}
finalmethod.cpp:21:10: error: declaration of 'foo' overrides a 'final' function
    void foo();
         ^
finalmethod.cpp:16:18: note: overridden virtual function is here
    virtual void foo() final;
                 ^
1 error generated.
{% endhighlight %}

# Why is `final` useful?

Marking a method or entire class as `final` could be useful if you need to
prevent client code from modifying the behaviour of your base class.  This
may be to enforce 'contractual' behaviour (as in Eiffel; not in a legal
sense!), or it may be to prevent resource management problems.

It should be noted that this is in *no way* a security measure.  This is
purely a compile-time directive to the compiler to enforce the policy, and
has no other effect than to generate an error and stop compiling.  In
attacking any real-world application, a determined cracker would have any
number of mechanisms at their disposal to bypass restrictions that this
might impose.

This information about finality can also be exploited by the compiler to
optimize code, using a technique known as *devirtualisation*. If the
compiler knows it doesn't have to use the vtable (virtual method table) to
dispatch the method call, it can potentially generate more efficient code.

# Sample Code

THe sample code can be otained from:

 * [https://github.com/gavinb/cplusplus11/blob/master/final/](https://github.com/gavinb/cplusplus11/tree/master/final/)

# Final vs Override

In addition to the `final` modifier, there is support for expressing the
opposite sense; the `override` declaration makes it explicit to the compiler
that you are intentionally overriding a virtual method from a base class.
This is explained in its own article, [C++11 and
override](/2014/06/c-plus-plus-11-and-override.html).
