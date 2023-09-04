# What is the smallest number that's evenly divisable
# by all numbers from 1 to 20

# quick solution, check multiples of highest prime number
# in this case, it's 19

def evenly_divisible_by_20(num)
 20.downto(2) do |i|
   return false if num % (i) != 0
 end
 return true
end

def highest_prime(max)
  primes = []
  max_prime = max
  max.times do |candidate|
    candidate += 1 # fix off by one
    is_prime = true
    (2...candidate).each do |i|
       is_prime = false if candidate % i == 0
    end
    primes << candidate if is_prime
  end
  return primes.max
end

gcd = highest_prime(20)
num = gcd
found = false

while found == false
  num += gcd
  found = evenly_divisible_by_20(num)
end

puts "#{num} is it!"

