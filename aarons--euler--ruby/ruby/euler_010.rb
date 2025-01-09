# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.

require "prime_lib.rb"

set = find_primes_under(2000000)
puts set[-1]
sum = 0
set.each {|i| sum += i}
puts sum
