# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
# Find the largest palindrome made from the product of two 3-digit numbers.

def is_palindrome?(test)
  string = test.to_s
  check = string.size/2

  check.times do |i|
    return false if string[i] != string[-i-1]
  end
  true
end

def check(num)
  palindromes = []
  num.downto(1) do |i|
    num.downto(1) do |j|
      palindromes << i*j if is_palindrome?(i*j)
    end
  end
  palindromes.max
end

  # left = num
  # right = num
  # left * right
  # left * right - 1
  # left - 1 * right - 1
  # left - 1 * right - 2
  # left - 2 * right - 2

