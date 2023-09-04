# n! means n × (n − 1) × ... × 3 × 2 × 1
#
# Find the sum of the digits in the number 100!

sum = 0
product = 1
num = 100
num.downto(2).each do |i|
  product *= i
end

num_string = product.to_s
num_string.each_char do |char|
  sum += char.to_i
end

puts sum

