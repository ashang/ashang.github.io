# By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
#
#    3      // 3
#   7 5     // 2
#  2 4 6    // 1
# 8 5 9 3
#
# That is, 3 + 7 + 4 + 9 = 23.
#
# Find the maximum total from top to bottom of the triangle below:
#
#               75
#              95 64
#             17 47 82
#            18 35 87 10
#           20 04 82 47 65
#          19 01 23 75 03 34
#         88 02 77 73 07 63 67
#        99 65 04 28 06 16 70 92
#       41 41 26 56 83 40 80 70 33
#      41 48 72 33 47 32 37 16 94 29
#     53 71 44 65 25 43 91 52 97 51 14
#    70 11 33 28 77 73 17 78 39 68 17 57
#   91 71 52 38 17 14 91 43 58 50 27 29 48
#  63 66 04 68 89 53 67 30 73 16 69 87 40 31
# 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
#
# NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)

@set = []
@set << [[75], [0]]
@set << [[95], [64], [0]]
@set << [[17], [47], [82], [0]]
@set << [[18], [35], [87], [10], [0]]
@set << [[20], [4], [82], [47], [65], [0]]
@set << [[19], [1], [23], [75], [3], [34], [0]]
@set << [[88], [2], [77], [73], [7], [63], [67], [0]]
@set << [[99], [65], [4], [28], [6], [16], [70], [92], [0]]
@set << [[41], [41], [26], [56], [83], [40], [80], [70], [33], [0]]
@set << [[41], [48], [72], [33], [47], [32], [37], [16], [94], [29], [0]]
@set << [[53], [71], [44], [65], [25], [43], [91], [52], [97], [51], [14], [0]]
@set << [[70], [11], [33], [28], [77], [73], [17], [78], [39], [68], [17], [57], [0]]
@set << [[91], [71], [52], [38], [17], [14], [91], [43], [58], [50], [27], [29], [48], [0]]
@set << [[63], [66], [4], [68], [89], [53], [67], [30], [73], [16], [69], [87], [40], [31], [0]]
@set << [[4], [62], [98], [27], [23], [9], [70], [98], [73], [93], [38], [53], [60], [4], [23], [0]]

def mda(w, h)
  a = Array.new(w)
  a.map! { Array.new(h)}
  a
end

@length = mda(16, 14)

@length[0][0] = 75

def get_length(i, j)
  return @length[i][j] if @length[i][j] != nil && @length[i][j] != 0
  ml, mr = 0, 0
  mr = get_length(i-1, j) if j < i + 1
  ml = get_length(i-1, j-1) if j > 0
  @length[i][j] = ([ml, mr].max + @set[i][j][0])
  get_length(i, j)
end

def check(row)
  m = 0
  (0..row).each {|i| m = [m, get_length(row,i)].max }
  m
end

puts check(14)
#puts check(15)


# 01               75               75
# 02              95 64             170 (75 + 95)
# 03             17 47 82           221 (75+64+82)
# 04            18 35 87 10         308 (75+64+82+87)
# 05           20 04 82 47 65       390 (75+64+82+87+82)
# 06          19 01 23 75 03 34     465 (75+64+82+87+82+75)
# 07         88 02 77 73 07 63 67   538 (75+64+82+87+82+75+73) (-15) (check until worse than -15)
# 08        99 65 04 28 06 16 70 92      566  (75+64+82+87+82+75+73+28) (-86) (check until worse than -86)
# 09       41 41 26 56 83 40 80 70 33    649  (75+64+82+87+82+75+73+28+83) (-83) (check until worse than -83)
# 10      41 48 72 33 47 32 37 16 94 29       696 (75+64+82+87+82+75+73+28+83+47) (-130)
# 11     53 71 44 65 25 43 91 52 97 51 14     772
# 12    70 11 33 28 77 73 17 78 39 68 17 57     850
# 13   91 71 52 38 17 14 91 43 58 50 27 29 48     908
# 14  63 66 04 68 89 53 67 30 73 16 69 87 40 31
# 15 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

# on each row - check the highest value, treat this as optimum
# if my best option is less than optimum, keep track of difference
# see if there are any paths with a smaller total difference?


# answer in maple

Here's the maple code, it also has the funny arrays because i was too lazy to remove the extra brackets. option remember is what does the caching:

weights := [[[75], [0]],
[[95], [64], [0]],
[[17], [47], [82], [0]],
[[18], [35], [87], [10], [0]],
[[20], [4], [82], [47], [65], [0]],
[[19], [1], [23], [75], [3], [34], [0]],
[[88], [2], [77], [73], [7], [63], [67], [0]],
[[99], [65], [4], [28], [6], [16], [70], [92], [0]],
[[41], [41], [26], [56], [83], [40], [80], [70], [33], [0]],
[[41], [48], [72], [33], [47], [32], [37], [16], [94], [29], [0]],
[[53], [71], [44], [65], [25], [43], [91], [52], [97], [51], [14], [0]],
[[70], [11], [33], [28], [77], [73], [17], [78], [39], [68], [17], [57], [0]],
[[91], [71], [52], [38], [17], [14], [91], [43], [58], [50], [27], [29], [48], [0]],
[[63], [66], [4], [68], [89], [53], [67], [30], [73], [16], [69], [87], [40], [31], [0]],
[[4], [62], [98], [27], [23], [9], [70], [98], [73], [93], [38], [53], [60], [4], [23], [0]] ]:

get_length := proc(i, j)
  global weights:
  local mr, ml:
  option remember:

  mr := 0:
  ml := 0:
  if j < i+1 and i > 1 and j > 0 then
    mr := get_length(i-1,j):
  end if:
  if j > 1 and i > 1 then
    ml := get_length(i-1, j-1):
  end if:
  return max(mr, ml) + weights[i,j,1]:
end proc:

max(map(i->get_length(15,i), [$1..15])):
print(%):


