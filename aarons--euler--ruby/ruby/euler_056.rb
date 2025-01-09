# A googol (10^(100)) is a massive number: one followed by one-hundred zeros; 100^(100) is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
#
# Considering natural numbers of the form, a^(b), where a, b < 100, what is the maximum digital sum?

def sum_digits(n)
  sum = 0
  string = n.to_s
  1.upto(9) do |i|
    before = string.size
    string.gsub!("#{i}",'')
    sum += i*(before - string.size)
  end
  sum
end

max = 0
1.upto(99) do |i|
  1.upto(99) do |j|
    max = [max, sum_digits(i**j)].max
  end
end

puts max

