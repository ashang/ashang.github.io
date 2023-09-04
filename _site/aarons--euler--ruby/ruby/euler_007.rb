# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6^(th) prime is 13.
#
# What is the 10001^(st) prime number?
#
# 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
#   * * *   *   * * *     *     *  *  *     *     *  *  *
#

def find_prime(num)
  primes_found = 3
  check_num = 5
  @known_primes = [2, 3, 5]

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

  puts "Prime ##{num} is: #{check_num}"
end

def is_prime?(num)
  @known_primes.each do |i|
    return false if num % i == 0
  end
  true
end

