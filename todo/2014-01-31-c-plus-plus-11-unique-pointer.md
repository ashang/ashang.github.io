---
layout: post
title: "C++11 Smart Pointers: Unique Pointer"
date: 2014-01-31
comments: true
categories: [c++,c++11,memory,smart pointers]
published: true
---

- single owner smart pointer
- shared pointers
- weak pointers


C++11 introduces many significant improvements to the language and runtime. One
of the most important is to do with memory management - specifically, smart
pointers.  The `unique_ptr` makes managing dynamically allocated memory safe and
simple.

<!--more-->

Instead of using a bare pointer type in C++, the modern C++11 style is now to
use `std::unique_ptr`.  This class will automatically free the allocated memory
once the variable goes out of scope.  This is the simplest of the new smart
pointer types in C++11.

Whereas before, you might write:

{% highlight c++ %}
Foo* obj = new Foo;

obj->process();

delete obj;
{% endhighlight %}

you can now write:

{% highlight c++ %}
std::unique_ptr<Foo> obj(new Foo);

obj->process();

// obj will be automatically deleted
{% endhighlight %}

## Properties

The `std::unique_ptr` class enforces several useful properties:

 - only a single reference to the allocated object can be active at any given time
 - the object will be deleted when the smart pointer goes out of scope
 - the object will be deleted if an exception is thrown

It bears spelling this out: when used correctly, `std::unique_ptr` can virtually
eliminate memory leaks.  This makes the cost of the conversion process
worthwhile!

The `unique_ptr` type is templated over the pointer type, and its constructor
takes the allocated pointer returned from the `new` operator.  And because the
pointer `operator->()` is overloaded, the smart pointer object can be used just
like a regular pointer.

**Note 1:** For Boost users, this is almost the same as the `boost::scoped_ptr`
class.

**Note 2:** This class supercedes the `std::auto_ptr`, which was deprecated in C++11.

**Note 3:** When invoking `std::unique_ptr` methods on the smart pointer itself,
remember to use the dot `.` operator. When invoking methods on the object pointer,
use the arrow `->` operator as you normally would (since it is overloaded to return the underlying object pointer).

## Sample

Once the variable goes out of scope, `delete` will be called to release the memory,
and the destructor will be invoked as usual, as this simple example shows:

{% highlight c++ %}
#include <memory>
#include <iostream>

class Foo
{
public:
    Foo() { std::cout << "+++ Foo::Foo()\n"; }
    ~Foo() { std::cout << "--- Foo::~Foo()\n"; }
    void process() { std::cout << "... Foo::process()\n"; }
};

int main(int argc, char* argv[])
{
    std::cout << "+++ main()\n";

    std::unique_ptr<Foo> obj(new Foo);
    obj->process();

    std::cout << "--- main()\n";

    return 0;
}
{% endhighlight %}

The output is:

    +++ main()
    +++ Foo::Foo()
    ... Foo::process()
    --- main()
    --- Foo::~Foo()

## Explcit release

If you wish to delete the object before the holding pointer goes out of scope,
you can use the `reset()` method on the smart pointer:

{% highlight c++ %}
std::unique_ptr<Foo> obj(new Foo);

obj->process();
obj.reset();
{% endhighlight %}

(Notice that methods invoked on the smart pointer itself use `.` whereas
methods on the target object use the overloaded dereference operator `->`).

This results in the trace:

    +++ main()
    +++ Foo::Foo()
    ... Foo::process()
    ... obj: 0x7fb733c047c0
    --- Foo::~Foo()
    --- main()

The simple difference here is that the object's destructor is called *before*
the end of `main`, since we invoke `reset()` explicitly.  Above, the destructor
is invoked *after* the end of `main`, since the smart pointer is going out of
scope.  This is a subtle but important point.

## Uniqueness

What happens if we try to assign this pointer to another smart pointer?

{% highlight c++ %}
std::unique_ptr<Foo> obj(new Foo);

std::unique_ptr<Foo> obj2;

obj2 = obj;
{% endhighlight %}

We get a meaningful compiler error:

    cpp11_unique_ptr_ex2.cpp:27:10: error: object of type 'std::__1::unique_ptr<Foo,
          std::__1::default_delete<Foo> >' cannot be assigned because its copy
          assignment operator is implicitly deleted
        obj2 = obj;

The compiler is enforcing the unique ownership semantics, so we can't
accidentally do the wrong thing.

But if we can't assign these unique pointers, how do we move them around? Using
the new explicit *move* support in C++11 (which is itself a large and complex
topic). This transfers ownership of the pointer from one `unique_ptr` instance
to another:

{% highlight c++ %}
std::unique_ptr<Foo> obj1(new Foo);
std::unique_ptr<Foo> obj2;

obj2 = std::move(obj1);
{% endhighlight %}

The output of the test program shows the result (we can access the enclosed pointer
using the `get()` method):

    +++ main()
    +++ Foo::Foo()
    Before move:
         obj1:0x7fa8b9d00000
         obj2:0x0
    After move:
         obj1:0x0
         obj2:0x7fa8b9d00000
    --- main()
    --- Foo::~Foo()

Notice how only one `Foo` instance was created, and that its pointer value moved
from `obj1` to `obj2`? After the `move` operation, the pointer in `obj1` is null.
Thus move semantics preserve the single owner invariant.

## Arrays

The `std::unique_ptr` class also has explicit support for handling arrays of
pointers. It is not a replacement for `std::vector`, but depending on your
requirements, this array support can be very useful.

{% highlight c++ %}
const unsigned N = 10;

std::unique_ptr<Foo[]> objarray(new Foo [N]);

for (unsigned i = 0; i < N; i++)
{
    std::cout << i << " ";
    objarray[i].process();
}
{% endhighlight %}

## Returning objects from functions

The `unique_ptr` idiom is especially useful when you need to return an allocated
resource from a function or method, but don't want to worry about having to free
the object later.  This sample function returns a unique pointer to the caller,
transferring ownership by implicitly moving the result:

{% highlight c++ %}
std::unique_ptr<Foo> make_foo()
{
    std::unique_ptr<Foo> obj(new Foo);

    // prepare obj

    return obj;
}
{% endhighlight %}

The object will be freed when the caller stops referencing it.

## Containers

The *move* support enables efficient storage of `unique_ptr` managed objects in
containers (one of the limitations of the deprecated `std::auto_ptr`).  If you
have a vector of pointers to objects, you need to carefully manage ownership
(eg. does the creator or the container own the allocations?) and manually free
them. But with `unique_ptr`, instead of:

{% highlight c++ %}
std::vector<Foo*> v;
{% endhighlight %}

we can write:

{% highlight c++ %}
std::vector< std::unique_ptr<Foo> > v;
{% endhighlight %}

then when creating the object, we use the explicit *move* support to pass
ownership of the object to the container (and avoid any reallocations or
temporaries):

{% highlight c++ %}
std::unique_ptr<Foo> q(new Foo(i));
v.push_back(std::move(q));
{% endhighlight %}

When the `vector` goes out of scope, its destructor will in turn release all
the `unique_ptr` instances it owns.  This automatic releasing of resources
can save a great deal of debugging pain and potential memory leaks.

## Overhead

The benefits of using `std::unique_ptr` are many.  And fortunately, the cost of
using this support is minimal (though for embedded systems, needs to be
carefully considered).  The is a memory overhead of one word per instance (eg. 8
bytes on a 64-bit architecture).

The code generated for a method invocation involves an extra pointer
indirection, the overhead which seems to be in the order of 2-3% (based on some
simplistic tests; see the repo for full source).

## Upgrading

The process to convert existing code which uses manual memory management to
using smart pointers may not be trivial, but the long-term benefits of more
maintainable and reliable code are frequently worth the investment of time.
Going through the process may well highlight complex memory management
strategies or error-prone code, and eliminate even more problems.

- Search for allocations using `new`
- Remove calls to `delete`

