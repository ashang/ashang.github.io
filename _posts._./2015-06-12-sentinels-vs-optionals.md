---
layout: post
title: "Sentinels vs Optionals"
date: 2015-06-12 09:49
published: false
comments: true
categories: [c++,c++11,boost]
---

A sentinel value is often used to initialise variables to indicate that the
value is unset or unknown.  Whereby sentinel values are used to easily
corrected.

<!--more-->

# Special values

A long-standing and frequently used convention in C family languages is to
reserve special sentinel values within the range of valid values to indicate
that a variable is unset, unknown, not yet available, default or otherwise.

For example, when valid values are positive numbers, negative numbers may be
reserved to indicate an error condition.  When unsigned variables are used,
the maximum value (eg. `INT_MAX`) is typically reserved to indicate an unset
value.

For example, imagine we need to ask the user for their choice from a menu.
Before the user is prompted, the `choice` is unknown.

We might have the following code:

{% highlight c++ %}
int choice = -1;

// ...

if (choice != -1)
{
    process(choice);
}
{% endhighlight %}

This is a form of 'in-band' signalling, whereby the same mechanism for
returning valid values is used to return a special value.

# Alternatives

There are several alternative methods to manually solve this issue.  One
common way is to have a boolean flag associated with each variable, as an
'out-of-band' signalling mechanism. The simple sample above would become:

{% highlight c++ %}
int choice = 1;
bool choice_valid = false;

// ...

if (choice_valid)
{
    process(choice);
}
{% endhighlight %}

This tends to be clumsy and error-prone, as it requires remembering to check
the valid flag before using the value, and nothing requires or enforces
this discipline.

An ideal solution would provide a way to unambiguously represent any value
and wrap the value in such a way that we can also flag whether or not it is
valid or initalised.

# Boost Optional

To address this problem in a syntactically clean fashion, Boost provides the
`optional` type.  It is a header-only class, which means there are no
additional libraries to link.  The `optional` class is templated so it can
wrap any object type, and records the validity state of the value.

An `optional` is a clever wrapper around a value (similar in concept to a
smart pointer). An optional variable is either uninitialized, or represents
a valid value.  If uninitialized, it is an error to attempt to use the
variable.

# Synopsis


{% highlight c++ %}
template <class T>
class optional
{
    public:
        optional();
        optional(T);
        
        bool is_initialized() const;
        
        reference_const_type value() const&;
        T& value_or(T& alternative);
        
        optional& operator= (Expr const& expr);
        pointer_type operator->();
        reference_const_type operator*() const&;
        
        // ...
};
optional<T> make_optional ( T const& v  );
{% endhighlight %}

# Declaring Optionals

An optional instance is declared with its value type, and can be created in
an initialised or uninitialised state.  Leaving out an intial value in the
constructor means it is uninitialised.  To initialise in the declaration,
pass the constructor the same parameters as the wrapped `T` value type:

{% highlight c++ %}
// Uninitialised
boost::optional<T>            number;

// Initialised using T's constructor form
boost::optional<T>            number(123);
{% endhighlight %}

# Validity and Access

The `optional` class provides an interface that allows the optional instance
to be treated in a similar manner to a smart pointer. To test for a valid
instance, you can be implicit or explicit:

{% highlight c++ %}
if (number)
    // ....

if (number.is_initialized())
    // ....
{% endhighlight %}

To access the wrapped value, you can either use one of the overloaded
operators, call `value()` to unconditionally retrieve the value, or
`value_or()` with a default to return if the optional is uninitialised.
This is particularly convenient as it combines the validity test and value
retrieval with default into a single construct.

{% highlight c++ %}
// Unconditionally use value
process(number.value());

// Use value or default
process(number.value_or(500));
{% endhighlight %}

# A simple example

The source for this example can be found in [foo](http://bitbucket.org/).

Let's say we have a few optional variables of different types, such as:

{% highlight c++ %}
boost::optional<int>            number;
boost::optional<float>          ratio(1.1312f);
boost::optional<std::string>    name;
{% endhighlight %}

If we attempt to refer to an uninitialised variable:

{% highlight c++ %}
std::cout << "number: " << number.get() << std::endl;
{% endhighlight %}

we will get an error at runtime:

    Assertion failed: (this->is_initialized()), function get,
        file /usr/local/include/boost/optional/optional.hpp, line 992.
        number: abort trap: 6

{% highlight c++ %}
    if (number)
        std::cout << "number: " << number.get() << std::endl;
    else
        std::cout << "number: unset" << std::endl;
{% endhighlight %}

{% highlight c++ %}
    std::cout << "name: " << name.value_or("Anonymous") << std::endl;

    name = "Citizen Kane";

    std::cout << "name: " << name.value_or("Anonymous") << std::endl;
{% endhighlight %}

{% highlight c++ %}
{% endhighlight %}
