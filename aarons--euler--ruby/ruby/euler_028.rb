# Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
#
# 21 22 23 24 25
# 20  7  8  9 10
# 19  6  1  2 11
# 18  5  4  3 12
# 17 16 15 14 13
#
# It can be verified that the sum of both diagonals is 101.
#
# What is the sum of both diagonals in a 1001 by 1001 spiral formed in the same way?

sum = 1
1.upto(500) { |i| sum += (2*i+1)**2 *4 - 12*i }
puts sum

puts 3**3*4-6*2


# Korben's solution:

# interesting...the first one you take the numbers directly 
# left of 1 sum those multiply by 4 and then add the 1
# 4*(19+6)+1=101
# sm := 1:
# pt := 1:
# for i from 2 to 501 do
#   pt := pt+4*(2*i-3)+2:
#   sm := 4*pt + sm:
# end do:
# print(sm):