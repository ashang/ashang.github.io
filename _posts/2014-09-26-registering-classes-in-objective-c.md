---
layout: post
title: "Registering Classes in Objective-C"
date: 2014-09-26 08:20
comments: true
categories: [objective-c,mac,ios]
published: false
---

The first article in this series looked at post_url 2014-09-16-exploring-the-objective-c-runtime.markdown
how to introspect Objective-C classes using the runtime API.  Now that we've
seen how to query all sorts of information about classes, their methods and
ivars, let's register a new class of our own at runtime.

<!--more-->

# Registering a new class

Every class has a metaclass, so we must first have a metaclass reference
(ie. a `Class` instance that we query using the name of the class as a
string).  For top-level classes, this is almost always `NSObject`, which
provides a great deal of common behaviour for all ObjC classes.  For derived
classes, this would be the parent class.

Then we can register the new class name, such as our `Sample` class below.
The "class pair" is the tuple of `(class, metaClass)` that we supply to
register the new class, hence the function name.  The final parameter allows
us to allocate some additional memory beyond that used for `Ivar`s.  In most
cases, this is not needed, so you pass 0.

{% highlight c %}
    // Metaclass and Class

    Class NSObjectClass = objc_getClass("NSObject");
    Class SampleClass = objc_allocateClassPair(NSObjectClass, "Sample", 0);
{% endhighlight %}

At this point, we have only allocated the `Sample` class, but it is not yet
registered.  First, we need to populate it with methods, ivars, and
properties.

# Registering instance variables

The simplest to register is an instance variable.  We pass in the `Class` we
just allocated, the name of the variable, its size and type:

{% highlight c %}
    class_addIvar(SampleClass, "_", 8, 8, "@\"NSWindow\"");
{% endhighlight %}

# Registering a property


{% highlight c %}
    // Ivars

    class_addIvar(SampleClass, "_window", 8, 8, "@\"NSWindow\"");

    // Property

    const objc_property_attribute_t windowAttrs =
    {
        .name = "window",
        .value = "T@\"NSWindow\",V_window",
    };

    class_addProperty(SampleClass, "window", &windowAttrs, 1);
{% endhighlight %}

# Registering methods

Given two simple Objective-C methods that would be declared like this:

{% highlight c %}
-(void)test;

-(int)addNumber:(int) toNumber:(int);
{% endhighlight %}

They are equivalent to the following C functions (with the implicit
parameters given):

{% highlight c %}
void testIMP(id self, SEL _cmd);

int addNumber_toNumber_IMP(id self, SEL _cmd, int a, int b);
{% endhighlight %}

As discussed in the previous article, a method is referred to by a
*selector*, which is a unique handle (number) for efficiency's sake.  So
first, we must get a selector for the method names which we want to
register.  The existing selector ID will be returned if it is already
registered, or it will be created and returned transparently.


{% highlight c %}
    // Method selectors

    SEL testSEL = sel_registerName("test");
    SEL addNumber_toNumber_SEL = sel_registerName("addNumber:toNumber:");
{% endhighlight %}
{% highlight c %}
    // Method implementations

    class_addMethod(SampleClass, testSEL, (IMP)testIMP, "v@:");
    class_addMethod(SampleClass, addNumber_toNumber_SEL, (IMP)addNumber_toNumber_IMP, "i@:ii");
{% endhighlight %}
