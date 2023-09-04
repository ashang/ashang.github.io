# Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits. For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904 are reversible. Leading zeroes are not allowed in either n or reverse(n).
#
# There are 120 reversible numbers below one-thousand.
#
# How many reversible numbers are there below one-billion (109)?

found = 0

1.upto(1_000_000_000) do |i|
  j = i + i.to_s.reverse.to_i
  all_odd = true
  j.to_s.each_char do |c|
    if (c.to_i & 1) == 0
      all_odd = false
    end
  end

  if all_odd
    unless i.to_s[-1].chr == "0"
      found += 1
    end
  end
end

puts found
