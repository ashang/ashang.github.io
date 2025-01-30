---
layout: post
title: "The Happy Coder's Toolkit Part I: mtrace"
date: 2007-01-02 20:32
comments: true
categories: 
---

I have been doing some serious hacking, fixing and refactoring on a codebase for genetics analysis.  And I've needed tools to go beyond just sprinkling the usual calls to `printf` around the place to see what's going on.  Hell, I've even fired up `gdb` once - but just to get a stack trace!  This is the first of a sporadically released series on tools I've found useful.  Hopefully they will distill the essential steps of using these tools, as well as expose some extremely useful but lesser known tricks to a wider audience (like the huge number of readers of this blog).

## mtrace: Debugging malloc

The memory management provided by the standard `libc` library with GCC provides a very useful debugging mode, which can be used to detect memory leaks.

To start with, add:

{% highlight c %}
#include <mtrace.h>
{% endhighlight %}

to the includes list at the top of your main module.  Then add a call to `mtrace()` right at the very top of main, conditionally compiled, like:

{% highlight c %}
int main( int argc, char* argv[], char* envp[] )
{
    /* locals etc ... */

#ifdef MYAPP_DEBUG_ALLOC
    mtrace();
#endif /* MYAPP_DEBUG_ALLOC */

    /* do something funky... */
    return 0;
}
{% endhighlight %}

This will install special handlers to intercept calls to `malloc/free` et al.  Then you can enable this feature as required.

At runtime, the `MALLOC_TRACE` environment variable must be set to the name of the output file to store the extra trace data.  If this is not set, `mtrace` will do **nothing**!

You can run your program like this:

    % MALLOC_TRACE=myapp.mtrace ./myapp -f 123 foo.dat

Once your program has terminated, you can then go ahead and analyse the output using the supplied `mtrace` tool.  You point it to your binary (so it can pull out the symbol table) and to the saved `.mtrace` file (from above) and - behold! - a big list of all your leakage.

Now all you have to do is tidy up those calls to `free`!

Stay tuned for the next exciting installments on:

 - gcov
 - gprof
 - cflow
 - Valgrind
 - and probably not many more...
