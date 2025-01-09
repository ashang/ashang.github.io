# The decimal number, 585 = 1001001001_(2) (binary), is palindromic in both bases.
#
# Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
#
# (Please note that the palindromic number, in either base, may not include leading zeros.)

sum = 0
1.upto(1000000) do |i|
  palindrome = (i.to_s == i.to_s.reverse)
  palindrome = (i.to_s(2) == i.to_s(2).reverse) if palindrome
  sum += i if palindrome
end
puts sum
