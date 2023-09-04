# A triplet of positive integers (a,b,c) is called a Cardano Triplet if it satisfies the condition:
#
# For example, (2,1,5) is a Cardano Triplet.
#
# There exist 149 Cardano Triplets for which a+b+c ≤ 1000.
#
# Find how many Cardano Triplets exist such that a+b+c ≤ 100,000,000.

set_size = 100
count = 0

1.upto(set_size) do |a|
  1.upto(set_size) do |b|
    1.upto(set_size) do |c|

    end
  end
end

puts count
a = 2
b = 1
c = 5
puts (a+b*c**(1/2.0))**(1/3.0) + (a-b*c**(1/2.0))**(1/3.0)
