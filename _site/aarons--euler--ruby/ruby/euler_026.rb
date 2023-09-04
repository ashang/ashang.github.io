# A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
#
#     ^(1)/_(2) =   0.5
#     ^(1)/_(3) =   0.(3)
#     ^(1)/_(4) =   0.25
#     ^(1)/_(5) =   0.2
#     ^(1)/_(6) =   0.1(6)
#     ^(1)/_(7) =   0.(142857)
#     ^(1)/_(8) =   0.125
#     ^(1)/_(9) =   0.(1)
#     ^(1)/_(10)  =   0.1
#
# Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that ^(1)/_(7) has a 6-digit recurring cycle.
#
# Find the value of d < 1000 for which ^(1)/_(d) contains the longest recurring cycle in its decimal fraction part.

# Look for the largest cyclic number below 1000
#
# *  1⁄7 = 0.142857  ; 6 repeating digits
# * 1⁄17 = 0.0588235294117647  ; 16 repeating digits
# * 1⁄19 = 0.052631578947368421  ; 18 repeating digits
# * 1⁄23 = 0.0434782608695652173913  ; 22 repeating digits
# * 1⁄29 = 0.0344827586206896551724137931  ; 28 repeating digits
# * 1⁄97 = 0.01030927 83505154 63917525 77319587 62886597 93814432 98969072 16494845 36082474 22680412 37113402 06185567  ; 96 repeating digits

require 'math_lib'
#primes = primes_under(100)
#puts primes_between(5, 100)
# cyclic = 0
# primes.each do |p|
#   cyclic = [(10**(p-1)-1)/p, cyclic].max
# end
# puts cyclic

highest_order = 0
highest_prime = 0
sum_of_orders = 0

primes_between(5,1000).each do |p|
  multiplicative_order = 0
  1.upto(p-1) do |pow|
    if (10**(pow)-1)%p == 0
      multiplicative_order = pow
      sum_of_orders += multiplicative_order
      break
    end
  end

  if multiplicative_order > highest_order
     highest_order = multiplicative_order
     highest_prime = p
   end
end

puts "#{highest_prime} #{highest_order}"
puts sum_of_orders
