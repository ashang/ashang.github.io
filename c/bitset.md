%title bitset标准库

[首页](../../../index "wikilink") - [C/C++](../index "wikilink") -
[C++](index "wikilink")

## bitset标准库

-----

标准库头文件：\`\#include <bitset>\`，命名空间：\`using
std::bitset;\`

-----

和\`vector\`一样，\`bitset\`也是一种类模板，在定义\`bitset\`时要明确其含有多少位

以\`0\`开始的位串称为\`低阶位\`，以\`最后一位\`结束的位串称为\`高阶位\`

给\`bitset\`赋值时，不足补\`0\`，多余丢弃

当使用\`string\`类型给\`bitset\`初始化时，赋值是翻转的，\`string\`的最右边的字符对应\`bitset\`下标为\`0\`的位

\`bitset\`的存储顺序是与数组相反的，下标为\`0\`的元素在最后，下标最大的元素在最前

\`bitset\`可以直接整个从标准输出流输出：\`std::cout \<\< bi \<\< std::endl;\`

典型的\`bitset\`初始化示例

1.  \`bitset\<16\> bi(0xffff);\`：初始化为\`unsigned\`值
2.  \`bitset\<32\> bi(str);\`：用\`string\`对象初始化，翻转赋值
3.  \`bitset\<4\> bi(str, 5,
    4);\`：截取\`string\`对象从下标\`5\`开始的\`4\`个字符，翻转赋值
4.  \`bitset\<4\> bi(str, str.size() -
    4);\`：截取\`string\`对象的最后\`4\`个字符，翻转赋值

-----

\`bitset\`对象常用操作

1.  \`bi\[3\]\`：访问指定下标的二进制位
2.  \`bi.size()\`：返回\`bitset\`的位数
3.  \`bi.count()\`：返回\`bitset\`中值为\`1\`的位数
4.  \`bi.any()\`：是否存在值为\`1\`的位
5.  \`bi.none()\`：是否不存在值为\`1\`的位，与\`any()\`相反
6.  \`bi.test(3)\`：指定下标的值是否为\`1\`
7.  \`bi.set()\`：将所有二进制位置\`1\`
8.  \`bi.set(3)\`：将指定下标的值置\`1\`
9.  \`bi.reset()\`：将所有二进制位置\`0\`
10. \`bi.reset(3)\`：将指定下标的值置\`0\`
11. \`bi.flip()\`：将所有二进制位翻转
12. \`bi.flip(3)\`：将指定下标的值翻转
13. \`bi.to\_ulong()\`：使用\`bi\`中同样的二进制位，返回一个\`unsigned
long\`值

与\`string\`类型类似，\`size()\`、\`count()\`的返回值类型不是普通的\`int\`型，而是\`size\_t\`类型，该类型定义在头文件\`cstddef\`中

\`flip()\`支持\`bi\[3\].flip()\`这样的用法，但\`set()\`和\`reset()\`不支持，只能写成\`bi.set(3)\`，而不能写成\`bi\[3\].set()\`

-----

<red>date</red> : 2012-04-03

-----
