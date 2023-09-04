# We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
#
# What is the largest n-digit pandigital prime that exists?
#

require 'math_lib'

# set = primes_under(1_000_000_000)
# set.reverse!
#
# set.each do |prime|
#   array = []
#   prime.to_s.each_char {|c| array << c}
#   if array.size == array.uniq.size
#     puts prime
#     break
#   end
# end

puts probably_prime?(9876413)
