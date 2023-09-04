def sum_of_squares(count)
  sum = 0
  count.times do |i|
    sum += (i+1)**2
  end
  return sum
end

def square_of_sums(count)
  sum = 0
  count.times do |i|
    sum += i+1
  end
  return sum**2
end

puts (square_of_sums(100) - sum_of_squares(100))

