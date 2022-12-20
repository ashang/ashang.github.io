---
layout: post
title: python range
tags: [python2, python3, range, xrange]
date: 2020-03-09
---

   range() – This returns a range object (a type of iterable).
    xrange() – This function returns the generator object that can be used to display numbers only by looping. The only particular range is displayed on demand and hence called “lazy evaluation“.





CPython implementation detail: xrange() is intended to be simple and fast. Implementations may impose restrictions to achieve this. The C implementation of Python restricts all arguments to native C longs (“short” Python integers), and also requires that the number of elements fit in a native C long. If a larger range is needed, an alternate version can be crafted using the itertools module: islice(count(start, step), (stop-start+step-1+2*(step<0))//step).
Remarks

This function is very similar to range(), but returns an xrange object instead of a list. This is an opaque sequence type which yields the same values as the corresponding list, without actually storing them all simultaneously. The advantage of xrange() over range() is minimal (since xrange() still has to create the values when asked for them) except when a very large range is used on a memory-starved machine or when all of the range’s elements are never used (such as when the loop is usually terminated with break). For more information on xrange objects, see XRange Type and Sequence Types — str, unicode, list, tuple, bytearray, buffer, xrange.
Example




n Python 2.x:

    range creates a list, so if you do range(1, 10000000) it creates a list in memory with 9999999 elements.

    xrange is a sequence object that evaluates lazily.

In Python 3:

    range does the equivalent of Python 2's xrange. To get the list, you have to explicitly use list(range(...)).



 in Python 3, range() will be implemented by the Python 2 xrange(). If you need to actually generate the list, you will need to do:

list(range(1,100))


lazy
means that each i is evaluated on demand rather than on initialization.



se the timeit module to test which of small snippets of code is faster!

$ python -m timeit 'for i in range(1000000):' ' pass'
10 loops, best of 3: 90.5 msec per loop
$ python -m timeit 'for i in xrange(1000000):' ' pass'
10 loops, best of 3: 51.1 msec per loop




Note: to run in windows cmd it is needed to use double quote, i.e. ". So code will be python -m timeit "for i in xrange(1000000):" " pass"





xrange returns XXXX NONO an iterator and only keeps one number in memory at a time. range keeps the entire list of numbers in memory.


This function is very similar to range(), but returns an xrange object instead of a list. This is an opaque sequence type which yields the same values as the corresponding list, without actually storing them all simultaneously. The advantage of xrange() over range() is minimal (since xrange() still has to create the values when asked for them) except when a very large range is used on a memory-starved machine or when all of the range’s elements are never used (such as when the loop is usually terminated with break).




With range, it already creates a list from 0 to 100000000(time consuming), but xrange is a generator and it only generates numbers based on the need, that is, if the iteration continues.





  
import sys
  
# initializing a with range()
a = range(1,10000)
  
# initializing a with xrange()
x = xrange(1,10000)
  
# testing the size of a
# range() takes more memory
print ("The size allotted using range() is : ")
print (sys.getsizeof(a))
  
# testing the size of x
# xrange() takes less memory
print ("The size allotted using xrange() is : ")
print (sys.getsizeof(x))



As range() returns the list, all the operations that can be applied on the list can be used on it. On the other hand, as xrange() returns the xrange object, operations associated to list cannot be applied on them, hence a disadvantage.



As range() returns the list, all the operations that can be applied on the list can be used on it. On the other hand, as xrange() returns the xrange object, operations associated to list cannot be applied on them, hence a disadvantage.


As range() returns the list, all the operations that can be applied on the list can be used on it. On the other hand, as xrange() returns the xrange object, operations associated to list cannot be applied on them, hence a disadvantage.

print("Specify end position only\n")
end=5
print("end position:",end)
x = xrange(end)#create a sequence of numbers from 0 to 4
print(x)
for n in x:#print the elements using a for loop
  print(n)




import sys

PY3 = sys.version_info[0] == 3
if PY3:
    binary_type = bytes
    text_type = str
else:
    binary_type = str
    text_type = unicode

def ensure_binary(s, encoding='utf-8', errors='strict'):
    if isinstance(s, binary_type):
        return s
    if isinstance(s, text_type):
        return s.encode(encoding, errors)
    raise TypeError("not expecting type '%s'" % type(s))





PY3 = sys.version_info[0] == 3
if PY3:
    xrange = range

## future

>>> from past.builtins import (str as oldstr, range, reduce,
                               raw_input, xrange)

>>> philosopher = oldstr(u'孔子'.encode('utf-8'))
>>> # This now behaves like a Py2 byte-string on both Py2 and Py3.
>>> # For example, indexing returns a Python 2-like string object, not
>>> # an integer:
>>> philosopher[0]
'å'
>>> type(philosopher[0])
<past.builtins.oldstr>

>>> # The div() function behaves like Python 2's / operator
>>> # without "from __future__ import division"
>>> from past.utils import div
>>> div(3, 2)    # like 3/2 in Py2
0
>>> div(3, 2.0)  # like 3/2.0 in Py2
1.5

>>> # List-producing versions of range, reduce, map, filter
>>> from past.builtins import range, reduce
>>> range(10)
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>> reduce(lambda x, y: x+y, [1, 2, 3, 4, 5])
15

>>> # Other functions removed in Python 3 are resurrected ...
>>> from past.builtins import execfile
>>> execfile('myfile.py')

>>> from past.builtins import raw_input
>>> name = raw_input('What is your name? ')
What is your name? [cursor]

>>> from past.builtins import reload
>>> reload(mymodule)   # equivalent to imp.reload(mymodule) in Python 3

>>> from past.builtins import xrange
>>> for i in xrange(10):
...     pass


