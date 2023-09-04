@primes = []

def primes_under(n) # Sieve of Eratosthenes, optimized pretty well
  if @primes[0] && @primes[0] == n
    return @primes.slice(1..-1)
  elsif @primes[0] && @primes[0] < n
    @primes.each_with_index do |prime, index|
      return @primes[1..index-1] if prime > n
    end
  end

  array_size = n/2-1#+n%2
  numberline = Array.new(array_size, true) # array positions represent ODD numbers
  final_test = (Math.sqrt(n)/2).to_i

  0.step(final_test, 1) do |i|
    next if !numberline[i]
    i2 = (2*i*(i + 3)) + 3 # numberline position that represents i**2
    iterate = ((i*2)+3)    # mark off every 2i number after i**2
    i2.step(array_size, iterate) do |j|
      numberline[j] = false
    end
  end

  @primes = [n,2] # number that was checked up to
  numberline.each_with_index {|num, i| @primes << 2*i+3 if num }
  return @primes.slice(1..-1)
end

def next_prime_after(n)
  weight = 3
  logn = Math.log(n)
  loglogn = Math.log(logn)
  set = []
  while set.empty?
    next_prime = (n+weight*(logn + loglogn - 1 + 1.8 * loglogn / logn))
    set = primes_between(n, next_prime)
    weight += 3
  end
  set[0]
end

def nth_prime(n)
  logn = Math.log(n)
  loglogn = Math.log(logn)
  max = n * (logn + loglogn - 1 + 1.8 * loglogn / logn)
  set = primes_under(max)
  set[n-1] # set[0] = 1st prime, set[n-1] = nth prime
end

def last_prime_before(n)
  set = primes_under(n)
  set[-1]
end

def primes_between(min, max, deterministic = true)
  if deterministic
    set = primes_under(max)
    n = set.shift until set[0] == nil || set[0] > min
    set.insert(0, n) if n && n > min
  else
    set = []
    min.upto(max).each {|n| set << n if probably_prime?(n) }
  end
  set
end

def is_prime?(n, probability = 100) #probability 10 == 99.9999%
  if probability >= 100 # deterministic, could be slow!
    primes_between(n-1, n+1).empty? ? false : true
  else
    probably_prime?(n, accuracy)
  end
end

def power(n, p)
  # 16119992467360
  # 503,749,764,605
  # 7,830,457
  return 1 if p == 0
  return 0 if n == 0
  p%2 == 0 ? power(n*n, p/2) : n*power(n*n, p/2)
end

def probably_prime?(n, k=10)
  # k determines accuracy, 10 >= 99.9999% accurate

  # first do deterministic checks
  return false if n < 2 || (n > 2 && n&1 == 0)
  return false if n > 4 && !(n%6 == 1 || n%6 == 5)
  set = primes_under([n+1, 1000].min)
  set.each {|p| return false if n % p == 0 && n != p}
  return true if n <= set[-1]

  # now do probability checks
  m = n-1
  d = m
  s = 0

  while d&1 == 0
    d /= 2
    s += 1
  end

  # a = case
  #     when n < 1_373_653 then [2, 3]
  #     when n < 9_080_191 then [31, 73]
  #     when n < 25_326_001 then [2, 3, 5]
  #     when n < 4_759_123_141 then [2, 7, 61]
  #     when n < 2_152_302_898_747 then [2, 3, 5, 7, 11]
  #     when n < 3_474_749_660_383 then [2, 3, 5, 7, 11, 13]
  #     when n < 341_550_071_728_321 then [2, 3, 5, 7, 11, 13, 17]
  #     else primes_under[50]
  #     end

  a = primes_under(20)
  k.times do
    (a.size).times do |i|
      # puts d%n
      x = a[i]**(d%n) # '()???
      # print "#{x}\n"
      next if (x == 1 || x == m)

      1.upto(s-1) do |j|
        # puts 2%n
        # x = power(x,2%n)
        x = x**(2%n)
        # print "#{x}\n"
        break if (x == 1 || x == m)
        return false if j == (s-1)
      end
    end
  end

  return true
end

def cyclic_numbers_under(n)
  cyclics = []
  primes_between(6, n).each do |p|

    # t = 0
    # r = 1
    # n = 0
    # while r != 1
    #   t += 1
    #   x = r*10
    #   d = (x/p).to_i
    #   r = x%p
    #   n = n*10+d
    #   cyclics << p if t == p-1
    # end
    cyclics << p if 10**(p-1)%p == 1
  end
  cyclics
end

def fact(n)
  n == 0 ? 1 : n * fact(n-1)
end

