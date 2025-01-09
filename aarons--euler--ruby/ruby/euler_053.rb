# There are exactly ten ways of selecting three from five, 12345:
#
# 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
#
# In combinatorics, we use the notation, ^(5)C_(3) = 10.
#
# In general,
# ^(n)C_(r) =
# n!
#
# r!(n−r)!
#   ,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
#
# It is not until n = 23, that a value exceeds one-million: ^(23)C_(10) = 1144066.
#
# How many, not necessarily distinct, values of  ^(n)C_(r), for 1 ≤ n ≤ 100, are greater than one-million?

require 'math_lib'

count = 0

1.upto(100) do |n|
  1.upto(n) do |r|
    ways_to_select_r = fact(n)/(fact(r)*fact(n-r))
    count += 1 if ways_to_select_r > 1_000_000
  end
end

puts count

# euler   (PHP)  euler is from England
# You can significantly simplify this problem...
#
# First of all we note that C(n,r) are the terms in Pascal's triangle. So C(n,r)=C(n-1,r-1)+C(n-1,r).
#
# 1
# 1 1
# 1 2 1
# 1 3 3 1
# 1 4 6 4 1
# 1 5 10 10 5 1
#
# For example, C(5,3)=10, and C(4,2)+C(4,3)=4+6=10
#
# Next we realise that we don't need to keep track of the actual sum of each value. Once a value has reached one million, we can set it back so that it never exceeds it again. It won't give that actual values of C(n,r), but it will allow us to count the number of elements that exceed one million.
#
# The following code complete the task in a jiffy...
#
# PHP
# [hide code]
#
# Dim a, b(100, 100), c, x, y As Integer
# For a = 0 To 100
#   b(a, 0) = 1
#   b(a, a) = 1
# Next a
# c = 0
# For x = 1 To 100
#   For y = 1 To x - 1
#     b(x, y) = b(x - 1, y) + b(x - 1, y - 1)
#     If b(x, y) > 1000000 Then
#       b(x, y) = 1000000
#       c += 1
#     End If
#   Next y
# Next x
# MsgBox(c)
#
# bishwa   (C/C++)  bishwa is from Nepal
# Further to post by Euler,
# also for any other methods that use pascal triangle,
# An optimization to the code/method would be to,
# 1. Count the number of coefficients (k) associated with test number (r) where coefficient is less than 1 million, until 1 million is hit or test combination exhausted.
# 2.Increment running counter of answer (ans) by (r-(2*k))
# 3. move onto next test number of r+1
#
# This way once you hit the million mark do not proceed further with that sequence.
# This depends on the fact that, when considering
# nCr=n!/(r!*(n-r)!)
# once r! and (n-r)! provide a symmetry along the median path where r=n/2.
# Visually it maybe simpler to look at the Pascal triangle to spot the symmetry.
# modified code segment from euler's post follows
#
# C/C++
# [hide code]
#
# For x = 1 To 100
#   k=0
#   For y = 1 To (x + 1)/2
#     b = x!/((y!)*(x-y)!)
#     If b < 1000000 Then
#       k=k+1
#     else
#       y=x
#     End If
#   Next y
#   ans=ans+x-(2*k)
# Next x
#
#
# This should at the least cut down computing time by approximately 50% per number.
# However as the test numbers get bigger the time saved also get bigger.
#
# bishwa.
#
# 25 Jan 2005 12:28 pm
# euler   (PHP)  euler is from England
# Very clever, bishwa! I hadn't thought of using the symmetry of Pascal's triangle. And as you say, although you're now only checking up to a maximum of half the elements in a given row, you are likely to stop that search some time before for larger values, and save yourself a great deal of computing time. Bravo!
