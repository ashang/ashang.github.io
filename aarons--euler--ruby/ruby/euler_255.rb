def f(x)
  steps = 1
  x1 = @odd_m
  x2 = ((x1 + (x/x1.to_f).ceil)/2.0).floor

  while x1 != x2
    x1 = x2
    x2 = ((x1 + (x/x1.to_f).ceil)/2.0).floor
    steps += 1
  end
  steps
end

def g(num)
  a = num
  @odd_m = 2*10**((a.to_s.size-1)/2)
  count = 0
  0.upto(9) do |i|
    count += f(a + a*i + i/100.0)
  end
  puts count / 10.0
end

g(10_000)
