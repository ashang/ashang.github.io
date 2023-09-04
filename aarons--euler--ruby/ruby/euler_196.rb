# Build a triangle from all positive integers in the following way:
#
#  1
#  2  3
#  4  5  6
#  7  8  9 10
# 11 12 13 14 15
# 16 17 18 19 20 21
# 22 23 24 25 26 27 28
# 29 30 31 32 33 34 35 36
# 37 38 39 40 41 42 43 44 45
# 46 47 48 49 50 51 52 53 54 55
# 56 57 58 59 60 61 62 63 64 65 66
# . . .
#
# Each positive integer has up to eight neighbours in the triangle.
#
# A set of three primes is called a prime triplet if one of the three primes has the other two as neighbours in the triangle.
#
# For example, in the second row, the prime numbers 2 and 3 are elements of some prime triplet.
#
# If row 8 is considered, it contains two primes which are elements of some prime triplet, i.e. 29 and 31.
# If row 9 is considered, it contains only one prime which is an element of some prime triplet: 37.
#
# Define S(n) as the sum of the primes in row n which are elements of any prime triplet.
# Then S(8)=60 and S(9)=37.
#
# You are given that S(10000)=950007619.
#
# Find  S(5678027) + S(7208785).

require 'math_lib'

def last_in_row(n)
  (n+1)*n/2
end

def numbers_in_row(n)
  q = last_in_row(n)
  set = [(q-n+1).upto(q)] #Array.new(n) {|i| q-i}
end

def nums_around(n, row)
  last_digit = last_in_row(row)
  return [] if n < last_digit-row+1

  # bounds
  row_minus_1_left = last_digit - 2*row+2
  row_minus_1_right = last_digit - row
  row_left = last_digit - row+1
  row_right = last_digit
  row_plus_1_left = last_digit + 1
  row_plus_1_right = last_digit + row

  set = []
  set << n-row   if n-row >= row_minus_1_left    # above left of n
  set << n-row+1 if n-row+1 <= row_minus_1_right # above n
  set << n-row+2 if n-row+2 <= row_minus_1_right # above right of n
  set << n-1     if n-1 >= row_left  # left of n
  # set << n
  set << n+1     if n+1 <= row_right # right of n
  set << n+row-1 if n+row-1 >= row_plus_1_left # below left of n
  set << n+row   # below n
  set << n+row+1 if n+row+1 <= row_plus_1_right # below right of n
  set
end

def sum_triplets_on_row(n)
  sum = 0
  a = last_in_row(n-1)
  b = last_in_row(n)

  numbers_in_row(n)[0].each do |i|
    if probably_prime?(i)
      primes = 1
      nums_around(i, n).each do |j|
        primes += 1 if probably_prime?(j)
        if primes == 2
          row_of_jay = case
                       when j <= a then n-1
                       when j <= b then n
                       else n+1
                       end
          nums_around(j, row_of_jay).each do |k|
            next if k == i
            primes += 1 if probably_prime?(k)
          end
        end
      end
      sum += i if primes >= 3
    end
  end
  sum
end

# puts (2**(783457 % (4 * 5**9)) )

q = 7208785+2
sum = 0
checked = 0

numbers_in_row(q)[0].each do |i|
 checked += 1
 if probably_prime?(i)
   sum += 1
   puts "#{i} is prime #{sum} in the set, checked: #{(checked/q.to_f)*100}%"
 end
 #   print "#{i} " + (probably_prime?(i) ? "is" : "is not") + " prime\n"
end


# puts primes_under(7_000_000).size
#puts nums_around(46, 10)
#puts sum_triplets_on_row(8)
# numbers_in_row(q)[0].each do |i|
#   puts i
# end 79019
