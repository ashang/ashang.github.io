# The prime factors of 13195 are 5, 7, 13 and 29.

# What is the largest prime factor of the number 600851475143 ?

def prime_factors_of(num)
  set = []
  (2...num).each do |i|
    if num % i == 0 && is_prime?(i)
      set << i
      num /= i
    end
    break if i > num  # super important :p
  end
  set
end

def is_prime?(num)
  (2...num).each do |i|
    return false if num % i == 0
  end
  true
end

puts prime_factors_of(600851475143)

# a quick way to optimize prime finder
# just pass in odd numbers
# i & 1 == 0 for even numbers
# useful function for something else
def primes_in(num)
  primes = []
  max_prime = num
  num.times do |candidate|
    candidate += 1 # fix off by one
    is_prime = true
    (2...candidate).each do |i|
       is_prime = false if candidate % i == 0
    end
    primes << candidate if is_prime
  end
  return primes
end




