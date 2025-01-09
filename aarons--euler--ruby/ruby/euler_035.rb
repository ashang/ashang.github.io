# The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
#
# There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
#
# How many circular primes are there below one million?
require 'math_lib'

primes = primes_under(1_000_000)
circular_primes = [2]

primes.each do |p|
  next if circular_primes.include?(p)

  prime = p.to_s
  next if prime.match(/2|4|5|6|8/)

  circular = true
  mini_set = []

  1.upto(prime.size) do
    prime << prime.slice!(0)
    if primes.include?(prime.to_i)
      mini_set << prime.to_i
    else
      circular = false
      break
    end
  end
  mini_set.uniq!
  circular_primes += mini_set if circular
end

puts circular_primes
puts circular_primes.size


