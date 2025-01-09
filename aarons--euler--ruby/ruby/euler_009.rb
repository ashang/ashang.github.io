# A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
# a^(2) + b^(2) = c^(2)
#
# For example, 3^(2) + 4^(2) = 9 + 16 = 25 = 5^(2).
#
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.

# a2 + b2 = c2
# c2 - b2 = a2

def is_triple(b, c)
  a2 = c**2 - b**2
  a = Math.sqrt(a2)
  return false if a != a.to_i || a.to_i > b
  return a.to_i
end

def find_triples
  b = 2
  c = 997
  while c > b
    while b < c
      a = is_triple(b, c)
      puts "#{a*b*c}" if a && a + b + c == 1000
      b += 1
    end
    c -= 1
    b = 2
  end
end

find_triples

def valid(a, b, c)
  a**2 + b**2 == c**2
end

def sum(a, b, c)
  a + b + c
end

def product(a, b, c)
  a * b * c
end
