# Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
#
# For example, the proper divisors of 220 sum to 284.
#              the proper divisors of 284 sum to 220.
#
# Evaluate the sum of all the amicable numbers under 10000.

def sum_divisors(num)
  sum = 1
  stop = (Math.sqrt(num)).to_i
  2.upto(stop).each {|i| sum += i + num/i if num % i == 0 }
  sum
end

amicables = 0
pairs = []

1.upto(9999).each do |num|
  unless pairs.include?(num)
    m = sum_divisors(num)
    if m < 10000
      n = sum_divisors(m)
      if n == num && n != m
        amicables += m+n
        pairs << m
        pairs << n
      end
    end
  end
end

puts amicables

