# A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
#
# 012   021   102   120   201   210
# 
# 
# What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

=begin
  num   last pushed left 
  1234
  1243  1
  1324  2
  1342  1
  1423  1 and
=end

# 
# def fact(n)
#   n == 0 ? 1 : n * fact(n-1)
# end
# 
# @num = [0, 1, 2]
# @base = @num.max
# 
# def add(n)
#   pos = @num.size
#   while n > 0 && pos > 0
#     pos -= 1
#     @num[pos] += n
#     if @num[pos] > @base
#       n = @num[pos]-@base
#       @num[pos] = @base
#     end
#   end
# end
# 
# a b c
# a c b
# b a c
# b c a
# c a b
# c b a
# 
# 0 1 2   0 0 0   0 1 2   12  last-1 last    last last+1
# 0 2 1   0 1 2   0 2 1   12  last-1 last
# 1 0 2   1 1 1   2 0 1   01  last-2 last-1  last+1 last +2
# 1 2 0   0 2 1   0 2 1   01  last-2 last-1
# 2 0 1   1 1 1   1 2 0   13  last-2 last    last+2 last
# 2 1 0   0 1 2   0 2 1   13  last-2 last
# 
# 0 1 2 3
# 0 1 3 2
# 0 2 1 3
# 0 2 3 1
# 0 3 1 2
# 0 3 2 1
# 1 0 2 3
# 1 0 3 2
# 1 2 0 3
# 1 2 3 0
# 1 3 0 2
# 1 3 2 0
