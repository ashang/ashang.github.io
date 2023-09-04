# 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
#
# Find the sum of all numbers which are equal to the sum of the factorial of their digits.
#
# Note: as 1! = 1 and 2! = 2 are not sums they are not included.
require 'math_lib'
#1.upto(9) {|i| puts fact(i)}

total_sum = 0
3.upto(50000) do |i|
  sum = 0
  i.to_s.each_char {|c| sum += fact(c.to_i)}
  if i == sum
    total_sum += sum
    puts "#{i} == #{sum}, total_sum = #{total_sum}"
  end
end

puts "....."
puts total_sum

