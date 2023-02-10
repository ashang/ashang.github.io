---
layout: post
title: "C++ STL extras - random_sample_n"
date: 2003-09-13 22:20
comments: true
categories: 
---

Working on some code for my research tonight, I wasted a lot of time looking for some information on a particlar STL function.  Since I couldn't find the answers elsewhere, I am posting a quick explanation/solution here, to hopefully save someone else the trouble.

I am writing a C++ application, and use the STL in various places. I have been consulting the [SGI Standard Template Library Programmer's Guide](http://www.sgi.com/tech/stl/).  It is quite poorly named; it is really a reference, with not much guidance at all.  And unfortunately I have yet to find a decent book on the STL (I have one but it sucks).

(Note that the below applies to the `g++` compiler version 3.3; I don't know about other compilers or libraries.)

Anyway, I found just the function I was after: `random_sample_n`.  So I added the include for algorithm, and couldn't get the sucker to compile.  It turns out that since it is an *extension* to the STL, it is located in the `ext/algorithm` header, and under the namespace `__gnu_cxx::` instead of `std::`.  This stuff I found the hard way, slugging through header files.

Another thing: I didn't find any decent examples (the one in the SGI docs is trivial) so here is some real code:

{% highlight c++ %}
#include <ext/algorithm>
//...

    vector<fve> cxp(n_samples);
    // fill up cxp with useful stuff

    const unsigned          N = 20;
    std::vector<vectorf>    rs_model(N);

    // Take N random models
    __gnu_cxx::random_sample_n( cxp.begin(), cxp.end(), rs_model.begin(), N );

    // Now process rs_model ...
{% endhighlight %}

## 2013 Update

Nowdays, there is the most excellent http://www.cppreference.com/ which has a comprehensive reference for all the STL and standard C++ library classes, methods and functions.

And the new C++11 standard features e whole module for generating random numbers.
