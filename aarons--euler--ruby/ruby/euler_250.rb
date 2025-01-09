# Find the number of non-empty subsets of {1^(1), 2^(2), 3^(3),..., 250250^(250250)}, the sum of whose elements is divisible by 250. Enter the rightmost 16 digits as your answer.

#a = 250250**250250
#puts a%250

# sum = 0
# 1.upto(250250) do |i|
#    sum += i**i
#  end
# sum

a = Thread.new do
  sum = 0
  1.upto(150000) do |i|
     sum += i**i
   end
  sum
end

b = Thread.new do
  sum = 0
  150001.upto(250250) do |i|
     sum += i**i
   end
  sum
end

# c = Thread.new do
#   sum = 0
#   1.upto(250250) do |i|
#      sum += i**i
#    end
#   sum
# end

c = a.value + b.value
puts c.size
