# A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
#
# A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
#
# As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
#
# Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

# find and sum divisors of a number

def abundant?(num)
  sum = 1
  2.upto(Math.sqrt(num)) do |i|
    if num % i == 0
      sum += i
      sum += num/i if num/i != i
    end
  end
  sum > num
end

abundant_nums = []

12.upto(28123) { |i| abundant_nums << i if abundant?(i) }

a = Array.new(28123) {|i| i}
index = -1
abundant_nums.each do |i|
  index += 1
  abundant_nums[index..-1].each do |j|
    i+j < 28123 ? a[i+j] = nil : break
  end
end

a.compact!
puts a
puts "........"
puts a.size
puts a.inject {|sum, n| sum + n}


# two_abundants.uniq!
# puts two_abundants.size


#two_abundants = []
# index = -1
# abundant_nums.each do |i|
#   index += 1
#   abundant_nums[index..-1].each do |j|
#     i+j < 28123 ? two_abundants << (i+j) : break
#   end
# end
