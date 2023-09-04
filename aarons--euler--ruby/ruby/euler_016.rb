# 2^(15) = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
#
# What is the sum of the digits of the number 2^(1000)?

sum = 0
num = 2**1000
num_string = num.to_s
num_string.each_char do |char|
  sum += char.to_i
end

puts sum
