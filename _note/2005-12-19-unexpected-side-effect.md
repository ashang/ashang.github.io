---
layout: post
title: "Unexpected side-effect"
date: 2005-12-19 18:54
comments: true
categories: 
---

I discovered a strange bug in my Python code recently.  It took me a few minutes worth of digging to uncover something somewhat surprising, a side-effect to do with default parameters that is not obvious at first blush.
<!--more-->
Consider the following code:

{% highlight python %}
import sys

class Group:

    def __init__(self, name, desc='', questions=[]):
      self.name = name
      self.desc = desc
      self.questions = questions

    def__repr__(self):
        return'''Group:
        Name:        %s
        Description: %s
        Questions:   %s
        ''' % (self.name, self.desc, ', '.join(self.questions))

deftest():
    g1 = Group('foo')
    g2 = Group('baz', 'a really bazzy group')
    g3 = Group('bar', 'some barry groups', ['first q', 'secundo', 'tri'])

    g4 = Group('vroom')

    if len(sys.argv) > 1:
        g4.questions.append('This is not a question')

    print g1
    print g2
    print g3
    print g4

if __name__ == '__main__':
    test()
{% endhighlight %}

If run with no parameters, it appears to have the expected and desired behaviour.  Give it a parameter, and the line that appends a question will cause *all* instances to have the same question added.  Obviously a bug, but why?

What's happening is the default value for the `question` parameter is evaluated at compile time to be an instance of an empty list.  All instances then refer to this same empty list, so when one gets something appended, they all appear to get it.  The solution is of course to have it default to `None` and then construct a list when required.

Even when the default parameter is a function, it is still evaluated only the once, so its return value becomes a constant default value.  It turns out that this is clearly documented (thanks Fred!) in the <a href="http://www.python.org/doc/2.4.2/ref/function.html">Python Language Reference: Section 7.5 Function definitions.

For someone used to doing funky stuff in C++ constructors (like yours truly), this might be a subtle gotcha.
