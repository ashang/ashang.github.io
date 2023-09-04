# If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
#
# Not all numbers produce palindromes so quickly. For example,
#
# 349 + 943 = 1292,
# 1292 + 2921 = 4213
# 4213 + 3124 = 7337
#
# That is, 349 took three iterations to arrive at a palindrome.
#/opt/local/bin/ruby1.9
# Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).
#
# Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
#
# How many Lychrel numbers are there below ten-thousand?
#

def pal(n)
  n.to_s == n.to_s.reverse
end

found = 0
step = 10

while step < 10_000
  n = step
  step_j = 0
  is_palindrome = false

  while step_j < 50
    is_palindrome ||= pal(n)
    n += n.to_s.reverse.to_i
    step_j += 1
  end

  if !is_palindrome
    found += 1
    # puts "#{step} is lychrel after #{step_j} iterations"
    # puts "#{step} is palindrome at #{step_j} iterations of #{n}"
  end
  step += 1
end

puts "#{found} lychrels under #{step}"



