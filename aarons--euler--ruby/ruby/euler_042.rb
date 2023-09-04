# The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
#
# 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
#
# By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
#
# Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

def triangle(x)
  0.5*x*(x+1)
end

def is_triangle(x)
  y = 0.5*(Math.sqrt(8*x + 1)-1)
  y == y.to_i
end

# alpha hash
alpha = Hash.new(false)
n = 1
"A".upto("Z") { |l| alpha[l] = n; n+=1 }

# total triangle numbers
triangle_nums = 0

words = File.read("words.txt")
words.gsub!(/\"/,"")

words.split(",").each do |w|
  sum = 0
  w.each_char {|c| sum += alpha[c] }
  triangle_nums += 1 if is_triangle(sum)
end

puts triangle_nums

