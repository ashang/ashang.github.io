# Starting in the top left corner of a 2×2 grid, there are 6 routes (without backtracking) to the bottom right corner.
#
# How many routes are there through a 20×20 grid?

# binomial function
# look at coefficients of x on (x+1)^40  (20th function)
# (x+1)^2n (only check even powers for even sets of squares)
# so pow(2) = 1 square, pow(4) = 2 squares
