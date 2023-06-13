---
layout: post
title: "Exploring the Objective-C Runtime"
date: 2014-09-16 08:47
comments: true
categories: [objective-c,mac,ios]
published: false
---

Objective-C features a dynmic object model based on
[Smalltalk](http://en.wikipedia.org/wiki/Smalltak), and is very flexible and
powerful.  Normally we develop an application by writing our classes in
Objective-C, compiling the app, deploying and running the app as it is
written.  However, there is a comprehensive runtime API for Objective-C that
allows us to not only to introspect objects and classes at runtime, but even
dynamically modify existing classes and even create new classes.  Most
applications will never need to use the runtime API, but it is interesting
to learn how it works, and gives a deeper understanding of how the Objective-C
compiler generates code, and how the object system works at runtime.

<!--more-->

# Runtime class information

The [Objective-C Runtime](https://developer.apple.com/library/mac/documentation/cocoa/reference/objcruntimeref/objcruntimeref.pdf)
is a C API that implements the object model and runtime system.  Since it is
a plain C API, it is is available not only to Objective-C modules, but also
to C and C++ code via `/usr/include/objc/runtime.h` - and of course by
extension, other languages that feature an FFI capable of calling C
functions. (More on that in another article!)

The API is elegant and consistent, and functions are named with a set of
common prefixes to indicate their group.  All top-level functions have the
`objc_` prefix, while the `sel_` prefix is for working with selectors,
`class_` is for classes, `ivar_` for instance variables, and so on for
`method_`, and `property_`.

# Key types

The following C types are defined by the runtime and used to query and
provide information:

 - `Class`: the top-level class type, which also contains methods, properties and ivars
 - `Protocol`: defines a named set of methods a class may should implement
 - `Ivar`: instance variable, with a name and type information
 - `Method`: an operation on the class or object, with typed parameters, identified by a selector
 - `SEL`: a unique handle or ID given to a method name
 - `objc_property_t`: a property definition

Our first exercise will be to use the runtime API for introspection to
display the methods supported by a class.  A class is simply identified by
its name as a string, so we can obtain the `Class` definition for `NSString`
thus:

```c
const char* className = "NSString";

Class klass = objc_getClass(className);
```

Using this `klass` variable, we can obtain a complete definition of the
methods, ivars and properties assocated with this type.  Let's start by
looking at methods - we obtain the list by asking for a *copy* of the list
(ie. we are responsible for freeing the memory when done):

```c
unsigned int methodCount = 0;
Method* methods = class_copyMethodList(klass, &methodCount);
```

Simple! Now we have our own array of `methodCount` `Method` instances,
so we can iterate through the list

```c
for (unsigned i = 0; i < methodCount; i++)
{
    Method method = methods[i];
    SEL methodSEL = method_getName(method);
    const char* methodName = sel_getName(methodSEL);

    printf("%s\n", methodName);
}
```

Notice that when we ask a method for its name, we get a `SEL` or selector
back (not a string).  This is because of the way method dispatch works in
Objective-C, and will be covered in more detail in a later article.  For
now, the important point to remember is that *a selector is a unique handle
for a given method name*.  Thus two classes which define a method with the
exact same name will end up with the same selector for those two methods.
(As you can imagine, comparing a unique ID is significantly more efficient
than comparing two arbitrary strings.) So first we must query the selector
for that method, and then use the selector itself to get the name as a
string.

Since we own the copy of the method list, we must `free` the memory when
we are finished:

```c
free(methods);
```

A very similar approach can be used to query all the instance variables
defined in a class:

```c
unsigned int ivarCount = 0;
Ivar* ivars = class_copyIvarList(klass, &ivarCount);
```

And once again, loop through and process each `Ivar` (remembering to free
the memory when we are finished):

```c
for (unsigned i = 0; i < ivarCount; i++)
{
    Ivar ivar = ivars[i];
    printf("    %s\n", ivar_getName(ivar));
}

free(ivars);
```

Running this code and querying the `NSString` class from Cocoa, we see the
following methods are printed like this (only the first few are shown; there
are over 200!):

```
NSString
initWithPasteboardPropertyList:ofType:
writableTypesForPasteboard:
pasteboardPropertyListForType:
_endOfParagraphAtIndex:
rangeOfGraphicalSegmentAtIndex:
stringWithoutAmpersand
boundingRectWithSize:options:attributes:
boundingRectWithSize:options:attributes:context:
drawWithRect:options:attributes:
drawWithRect:options:attributes:context:
_sizeWithSize:attributes:
sizeWithAttributes:
drawInRect:withAttributes:
drawAtPoint:withAttributes:
_NSNavDisplayNameCompare:caseSensitive:
...
```

An important note: methods that begin with an underscore are considered
private, and subject to change. Do *not* call these unpublished methods, as
they could change behaviour, type signature or be removed without warning.
Always stick to the published API (this goes without saying on iOS!).

# Properties

Properties in Objective-C are a relatively recent addition to the language,
and provide the 'dot notation' for accessors and mutators (getting and
setting) instance variables, as well as providing a way to control linkage
(eg. weak binding) and notifications (for KVO support).  For some reason the
type is not `Property` (which would be consistent) but `objc_property_t`.
Each property has a name and a series of attributes, where attribute
consists of a key/value pair of strings (where the value is often empty).

As above, the first step to list the properties is to get a copy of the
properties from the class:

```c
unsigned int propertyCount = 0;
objc_property_t* properties = class_copyPropertyList(klass, &propertyCount);
```

Then we can iterate through each property and display its name and attributes:

```c
for (unsigned i = 0; i < propertyCount; i++)
{
    objc_property_t property = properties[i];
    printf("@property %s\t%s;\n", property_getName(property), property_getAttributes(property));
}

free(properties);
```

These attributes pertain to topics such as `weak` references, and so on.

# Type Encoding

One topic we have not yet covered is type encoding.  This is a technique for
taking an arbitrarily complex type declaration and turning it into a simple
string which is much easier to work with. (In C++ this is also known as name
mangling, where it combines with namespaces, classes, visibility and types.)
Encoding type signatures as strings makes it easier for the runtime to
manage symbol tables, compare types, and interoperate with other languages
(such as C).

Let's look at a simple example. Given the following Objective-C method:

```c
-(int)addNumber:(int)a toNumber:(int)b;
```

This is equivalent to the C function declaration:

```c
int addNumber_toNumber_IMP(id self, SEL _cmd, int a, int b);
```

The return type and two regular parameters are both `int`, which is encoded
as `i`.  But note that first there are implicit `self` and `_cmd`
parameters, which are not shown in the original declaration.  These are
effectively inserted by the compiler for instance methods (much like the
implicit `this` pointer in C++).  These are encoded as `@` and `:`
respectively.

So this method's type encoding is written as `i@:ii`, which can be read as:
"a method that returns an `int` and takes two `int` parameters".

Some other examples of methods and their type encodings:

The encodings get more complex when dealing with structs and so on, but the
idea is the same: for each parameter, generate a string which uniquely
defines the type.

# Source

The complete source for the examples in this series is available on Github
(https://www.github.com/gavinb/objc_runtime.git). Pull requests welcome.
