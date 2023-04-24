---
layout: post
title: "C++11 and override"
date: 2014-06-26 18:57
comments: true
categories: [c++,c++11]
---

The new `override` modifier can be applied to a virtual method in C++11, and
instructs the compiler that the method is intended to override a virtual
method defined in the parent class.  The primary advantage is that typos and
mismatched method signatures that would have resulted in subtle bugs and
unintended runtime bheaviour before can now be detected at build time and
easily corrected.

<!--more-->

# Without `override`

Imagine we have the following code:

{% highlight c++ %}
// Base class with virtual method
class Base0
{
public:
    virtual void foo(int num)
    {
        std::cout << "Base0::foo(int)" << std::endl;
    }
};

// Derived class with mismatched type.
// This error will not be caught.
class Derived0 : public Base0
{
public:
    virtual void foo(float num)
    {
        std::cout << "Derived0::foo(float)" << std::endl;
    }
};
{% endhighlight %}

The intent was for `Derived0` to implement its own `foo()` method to
override the `Base0::foo(int)` method.  However, the developer made a
mistake in the type signature and the parameter type does not match (`float`
here versus `int` above).  The result is that `Derived0::foo(float)` is a
distinct method from `Base0::foo(int)` and will not necessarily be called on
all the occasions the developer intended.  Typically this would be when a
polymorphic call on a `Base0` pointer type to a `Derived0` instance was
expected to call the derived implementation.  In other words, given some
test code which exercises the `foo` method for each class, if we write:

{% highlight c++ %}
std::unique_ptr<Base0>   b0(new Base0);
std::unique_ptr<Base0>   d0(new Derived0);

b0->foo(123);
d0->foo(123);
{% endhighlight %}

then the output we see is not what we might expect:

{% highlight c++ %}
Base0::foo(int)
Base0::foo(int)
{% endhighlight %}

The developer had intended that `Derived0` be invoked in the second call,
but the `Base0` version was called instead, since it matches the type
signature of the method in the base class and `foo(float)` is not considered
an overriding method.

# With `override`

The fix is to add the `override` modifier to the method declaration in the
derived class to make our intentions explicit.

{% highlight c++ %}
// Base class with virtual method
class Base1
{
public:
    virtual void foo(int num)
    {
        std::cout << "Base1::foo(int)" << std::endl;
    }
};

// Derived class intends to override.
// Since parent type signature doesn't match,
// this error will be caught
class Derived1 : public Base1
{
public:
    virtual void foo(float num) override
    {
        std::cout << "Derived1::foo(int)" << std::endl;
    }
};
{% endhighlight %}

Now if we attempt to compile this code, we will receive the following error:

{% highlight bash %}
override1.cpp:28:18: error: 'foo' marked 'override' but does not override any member functions
    virtual void foo(float num) override;
                 ^
1 error generated.
{% endhighlight %}

The fix is simple; update the type signature to match the parent.  The code
then compiles, and the following test code:

{% highlight c++ %}
std::unique_ptr<Base1>   b1(new Base1);
std::unique_ptr<Base1>   d1(new Derived1);

b1->foo(123);
d1->foo(123);
{% endhighlight %}

works correctly, producing the following expected result:

{% highlight c++ %}
Base1::foo(int)
Derived1::foo(int)
{% endhighlight %}

# When to use `override`

The `override` modifier should be used in modern C++ code whenever a virtual
function is overridden in a derived class.  The use of `override` can catch
some subtle bugs that would be otherwise be time-consuming and difficult to
detect and correct.

The `override` modifier only has a compile-time impact, so there is no
runtime cost whatsoever to using it.

There is one consideration - since `override` is a C++11 feature, care must
be taken to ensure that the target toolchain is compatible with modern
features.  Older compilers would need a compatability mode to ignore this
modifier in order to build.

# Sample Code

THe sample code can be otained from Github:

- [Override sample code](https://github.com/gavinb/cplusplus11/blob/master/override/override1.cpp)

# Final vs Override

In addition to the `override` modifier, there is support for expressing the
opposite sense; the `final` declaration instructs the compiler that the
method cannot be overridden by a dervied class.  The `final` modifier is
explained in its own article, [C++11 and final](/2014/06/c-plus-plus-11-and-final.html).
