# If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
#
# If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
#
# NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "00" => "and" when writing out numbers is in compliance with British usage.

@names = {
  "1" => "one",
  "2" => "two",
  "3" => "three",
  "4" => "four",
  "5" => "five",
  "6" => "six",
  "7" => "seven",
  "8" => "eight",
  "9" => "nine",
  "10" => "ten",
  "11" => "eleven",
  "12" => "twelve",
  "13" => "thirteen",
  "14" => "fourteen",
  "15" => "fifteen",
  "16" => "sixteen",
  "17" => "seventeen",
  "18" => "eighteen",
  "19" => "nineteen",
  "20" => "twenty",
  "30" => "thirty",
  "40" => "forty",
  "50" => "fifty",
  "60" => "sixty",
  "70" => "seventy",
  "80" => "eighty",
  "90" => "ninety",
  "100" => "hundred",
  "1000" => "thousand"}

def wordify_num(num)
  num_string = num.to_s
  string = ""
  additional = ""

  if num_string.size == 4
    return "one thousand"
  end

  if num_string.size == 3
    string += @names[num_string[-3].chr] + " hundred"
    additional += "and"
    num_string.slice!(0)
  end

  if num_string.size == 2
    if @names[num_string[-2..-1]]
      string += additional + @names[num.to_s[-2..-1]]
      additional = ""
      num_string.slice!(0..1)
    elsif @names[(num_string[-2].chr.to_i*10).to_s]
      string += additional + @names[(num_string[-2].chr.to_i*10).to_s]
      additional = ""
      num_string.slice!(0)
    else
      num_string.slice!(0) # remove 0 in tens position
    end
  end

  if num_string.size == 1 && @names[num_string[-1].chr]
    string += additional + @names[num_string[-1].chr]
  end

  string
end

def count_to(num)
  count = 0
  num.times do |i|
    word = wordify_num(i+1).gsub(' ', '')
    count += word.size
  end
  count
end

puts count_to(1000)
