# It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
#
# Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

def checknum(n)
  a = [n.to_s, (n*2).to_s, (n*3).to_s, (n*4).to_s, (n*5).to_s, (n*6).to_s]
  return false if a[0].size != a[-1].size
  s0 = count_digits(a[0])
  s1 = count_digits(a[1])
  s2 = count_digits(a[2])
  s3 = count_digits(a[3])
  s4 = count_digits(a[4])
  s5 = count_digits(a[5])
  s0 == s1 && s0 == s2 && s0 == s3 && s0 == s4 && s0 == s5
end

def count_digits(str)
  hash = {
    "0" => 0,
    "1" => 0,
    "2" => 0,
    "3" => 0,
    "4" => 0,
    "5" => 0,
    "6" => 0,
    "7" => 0,
    "8" => 0,
    "9" => 0,
  }
  str.each_char do |c|
    hash[c] += 1
  end
  return hash
end

1.upto(16666) do |i|
  if checknum(i)
    puts i
    break
  end
end
# 142857
# 1428570
# 1429857

#
# The first number in x must be 1. If it were 2, then the number would be:
#
# 2abcd
#
# And the number multiplied by 6 would be:
#
# 12efgh
#
# This means that the two numbers cannot possibly contain the same digits. Also, the number cannot be less than 100. If it were, there could not possibly be 6 different combinations of it digits, only 2 (ab, ba). Also, the second digit has to be less than or equal to 6, as does the 3rd, 4th, 5th, etc. So you only have to search for numbers in the ranges:
#
# 100 - 166
# 1000 - 1666
# 10000 - 16666
