def find_primes_under(num)
  numberline = []
  primes = []
  numberline.fill(0, num-1) {|i| i+2}

  until numberline.empty?
    prime = numberline.shift
    numberline.delete_if {|i| i % prime == 0} if prime < (Math.sqrt(num)+1)
    primes << prime
  end

  return primes
end

def find_primes_under_old(num)
  primes_found = @known_primes.size
  check_num = @known_primes.max

  if check_num > num
    set = []
    @known_primes.each {|p| set << p if p < num }
    return set
  end

  while check_num < num
    break if (check_num += 2) >= num
    if is_prime?(check_num)
      primes_found += 1
      @known_primes << check_num
      print "#{check_num}, "
    end

    break if (check_num += 4) >= num
    if is_prime?(check_num)
      primes_found += 1
      @known_primes << check_num
      print "#{check_num}, "
    end
  end

  return @known_primes
end

# find the nth prime
def find_prime(num)
  primes_found = 3
  check_num = 5

  while primes_found < num
    if is_prime?(check_num+=2)
      primes_found += 1
      @known_primes << check_num
    end

    break if primes_found >= num

    if is_prime?(check_num+=4)
      primes_found += 1
      @known_primes << check_num
    end
  end

  return check_num
end


def is_prime?(num)
  @known_primes.each do |i|
    break if i > num/2
    return false if num % i == 0
  end
  true
end

# def is_prime?(num)
#   (2...num).each do |i|
#     return false if num % i == 0
#   end
#   true
# end

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

@known_primes = [2,3,5]
