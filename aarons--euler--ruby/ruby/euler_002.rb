def fibonacci(last_term, current_sum)
  last_sum = current_sum
  current_sum += last_term
  return last_sum, current_sum
end

current_term = 1
sum = 0
total = 0

while sum < 4000000
  current_term, sum = fibonacci(current_term, sum)
  total += sum if sum & 1 == 0
end

puts total
